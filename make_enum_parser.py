import glob
import re

def isEnum(enum_name, enums):
    for e in enums:
        if e == enum_name:
            return True
    return False

def makeEnumParser(header_path, src_folder, header_folder, pf_name):
    Enums = {}
    header_files = []
    enum_ptn1 = re.compile("\s*([^\s]+)\s*=[^,]*,*$")
    enum_ptn2 = re.compile("\s*([^\s,]+),*$")
    # ファイルからenum情報を抽出し、余分な記号を除去して辞書型配列に格納
    for file in glob.glob(header_path, recursive=True):
        with open(file, 'r', encoding='utf-8') as f:
            for line in f:
                if line.startswith('typedef enum'):
                    enum_value_list = []
                    while line:
                        line = f.readline()
                        if '*' in line:
                            continue
                        enum_match = enum_ptn1.match(line)
                        if enum_match is None:
                            enum_match = enum_ptn2.match(line)
                        if enum_match is not None:
                            enum_value_list.append(enum_match.group(1))
                        elif '}' in line:
                            line = line.strip()
                            line = line.replace('} ', '')
                            line = line.replace(';', '')
                            Enums[line] = enum_value_list
                            if file not in header_files:
                                header_files.append(file)
                            break
    # enum書き出し
    if Enums:
        e_source = '/* Copyright (c) 2023 DENSO CORPORATION All Rights Reserved. */\n\n'
        e_source += '#include <stdio.h>\n'
        e_source += '#include <apiMonitor_' + pf_name + '_parse_enum.h>\n\n'
        for enum_name in Enums:
            enum_part = enum_name.replace('_t', '')
            e_source += ('typedef struct {{\n    {} status;\n    char *str;\n}} {}_enum_info;\n'
                .format(enum_name, enum_part))
            e_source += ('static const {}_enum_info {}_str_table[] = {{\n'
                .format(enum_part, enum_part))

            for enumerator in Enums[enum_name]:
                e_source += ('    {{{},        "{}"}},\n'
                .format(enumerator, enumerator))
            e_source += '};\n\n'

            e_source += ('int parse_{}(char *text, int max_len, {} status){{\n'
                .format(enum_name, enum_name))
            e_source += ('    for (int i = 0;i < sizeof({}_str_table) / sizeof({}_enum_info); i++) {{\n'
                .format(enum_part, enum_part))
            e_source += ('        if ({}_str_table[i].status == status) {{\n'
                .format(enum_part))
            e_source += ('            return snprintf(text, max_len, "\\\"%s(%d)\\\"", {}_str_table[i].str, status);\n'
                .format(enum_part))
            e_source += '        }\n    }\n    return snprintf(text, max_len, "%d", status);\n}\n\n'

        with open(src_folder + '/apiMonitor_' + pf_name + '_parse_enum.c', 'w', encoding='utf-8') as write_f:
            write_f.write(e_source)

        e_header_source = '/**\n * @file apiMonitor_' + pf_name + '_parse_enum.h\n'
        e_header_source +=' * @copyright Copyright (c) 2023 DENSO CORPORATION All Rights Reserved.\n *\n */\n\n'
        e_header_source += '#ifndef APIMONITOR_' + pf_name.upper() + '_PARSE_ENUM_H\n'
        e_header_source += '#define APIMONITOR_' + pf_name.upper() + '_PARSE_ENUM_H\n\n'
        for header_file in header_files:
            header_file = header_file[header_file.find('include/') + 8:]
            e_header_source += '#include <' + header_file + '>\n'

        e_header_source += '\n'

        for enum_name in Enums:
            e_header_source += ('extern int parse_{}(char *text, int max_len, {} status);\n'
                .format(enum_name, enum_name))

        e_header_source += '\n\n'
        e_header_source += '#endif  /* APIMONITOR_' + pf_name.upper() + '_PARSE_ENUM_H */'

        with open(header_folder + '/apiMonitor_' + pf_name + '_parse_enum.h', 'w', encoding='utf-8') as write_hf:
            write_hf.write(e_header_source)
    return Enums
