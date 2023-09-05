import glob
import re
import make_typedef_parser
import make_enum_parser

def isStruct(struct_name, structs):
    for s in structs:
        if s == struct_name:
            return True
    return False

def getParseFuncList(header_folder, pf_name):
    parse_func_list = []
    # 指定ファイルからparse関数のみを抽出し、リストに格納
    with open('./include/apiMonitor_parse_primitive.h', 'r', encoding='utf-8') as f:
        for line in f:
            if 'extern' in line:
                l = line.split(' ')
                l = l[2].split('(')
                parse_func_list.append(l[0])

    with open('./' + header_folder + '/apiMonitor_' + pf_name + '_parse_typedef.h', 'r', encoding='utf-8') as f:
        for line in f:
            if 'extern' in line:
                l = line.split(' ')
                l = l[2].split('(')
                parse_func_list.append(l[0])

    with open('./' + header_folder + '/apiMonitor_' + pf_name + '_parse_enum.h', 'r', encoding='utf-8') as f:
        for line in f:
            if 'extern' in line:
                l = line.split(' ')
                l = l[2].split('(')
                parse_func_list.append(l[0])
    return parse_func_list

def hasParseFunc(parse_func, parse_func_list):
    for func_name in parse_func_list:
        if func_name == parse_func:
            return True
    return False

def makeStructParser(header_path, src_folder, header_folder, pf_name, enums, types):
    Structs = {}
    parse_func_list = []
    header_files = []
    member_ptn = re.compile("(.+)\s+(.+)")
    array_ptn = re.compile("(.+)\[(.+)\]")

    # ファイルから構造体情報を抽出し、余分な記号を除去して辞書型配列に格納
    for file in glob.glob(header_path, recursive=True):
        with open(file, 'r', encoding='utf-8') as f:
            for line in f:
                if line.startswith('typedef struct'):
                    struct_value_list = []
                    while line:
                        line = f.readline()
                        if '}' in line:
                            line = line.strip()
                            line = line.replace('} ', '')
                            line = line.replace(';', '')
                            Structs[line] = struct_value_list
                            if file not in header_files:
                                header_files.append(file)
                            break
                        elif ('/*' in line or '*/' in line or ' * ' in line or
                            '  *' in line or'* @brief' in line or '}' in line):
                            continue
                        else:
                            line = line.strip()
                            line = line.replace(';', '')
                            struct_value_list.append(line)

    parse_func_list = getParseFuncList(header_folder, pf_name)

    # 構造体書き出し
    if Structs:
        s_source = '/* Copyright (c) 2023 DENSO CORPORATION All Rights Reserved. */\n'
        s_source += '#include <stdio.h>\n'
        s_source += '#include <string.h>\n'
        s_source += '#include <apiMonitor_parse_primitive.h>\n'
        s_source += '#include <apiMonitor_' + pf_name + '_parse_typedef.h>\n'
        s_source += '#include <apiMonitor_' + pf_name + '_parse_struct.h>\n'
        s_source += '#include <apiMonitor_' + pf_name + '_parse_enum.h>\n\n'
        for struct_name in Structs:
            s_source += ('int parse_{}(char *text, int max_len, {} *p) {{\n'.format(struct_name, struct_name))
            s_source += '    int len = 0;\n\n'
            for j, member in enumerate(Structs[struct_name]):
                member_parts = member_ptn.match(member)
                variable_type = member_parts.group(1)
                variable_name = member_parts.group(2)
                if j == 0:
                    s_source += '    len = snprintf(text, max_len,\n        "{"\n        "'
                else:
                    s_source += '    len += snprintf(text + len, max_len - len,\n        ",'
                primitiveType = make_typedef_parser.getPrimitiveType(variable_type, types)
                variable_type = variable_type.replace('unsigned ', 'unsigned_')
                # ポインタ型の場合、アスタリスクを除去してから型判定
                asterisk = ''
                if "*" in variable_type:
                    variable_type = variable_type.replace("*", "")
                    asterisk += '*'
                keyword = 'parse_' + variable_type
                if primitiveType == 'unsigned char*':
                    s_source += '\\\"{}\\\": ");\n'.format(variable_name)
                    s_source += '    if(len > max_len - 1){\n'
                    s_source += '        return max_len - 1;\n'
                    s_source += '    }\n\n'
                    s_source += '    len += parse_unsigned_char_p_ascii(text + len, max_len - len, p->{}, strlen((char *)p->{}));\n'.format(variable_name, variable_name)
                elif primitiveType == 'char*':
                    s_source += '\\\"{}\\\": ");\n'.format(variable_name)
                    s_source += '    if(len > max_len - 1){\n'
                    s_source += '        return max_len - 1;\n'
                    s_source += '    }\n\n'
                    s_source += '    len += parse_char_p_ascii(text + len, max_len - len, p->{}, strlen(p->{}));\n'.format(variable_name, variable_name)
                elif '[' in variable_name:
                    array_parts = array_ptn.match(variable_name)
                    if array_parts is None:
                        s_source += '\\\"{}\\\": \\\"unsupported\\\"");\n'.format(variable_name)
                    else:
                        array_name = array_parts.group(1)
                        array_size = array_parts.group(2)
                        if primitiveType == 'char':
                            s_source += '\\\"{}\\\": ");\n'.format(array_name)
                            s_source += '    if(len > max_len - 1){\n'
                            s_source += '        return max_len - 1;\n'
                            s_source += '    }\n\n'
                            s_source += '    len += parse_char_p_ascii(text + len, max_len - len, p->{}, {});\n'.format(array_name, array_size)
                        elif primitiveType == 'unsigned char':
                            array_name = array_parts.group(1)
                            array_size = array_parts.group(2)
                            s_source += '\\\"{}\\\": ");\n'.format(array_name)
                            s_source += '    if(len > max_len - 1){\n'
                            s_source += '        return max_len - 1;\n'
                            s_source += '    }\n\n'
                            s_source += '    len += parse_unsigned_char_p_hex(text + len, max_len - len, p->{}, {});\n'.format(array_name, array_size)
                        else:
                            s_source += '\\\"{}\\\": \\\"unsupported\\\"");\n'.format(variable_name)
                elif 'struct' in variable_type:
                    if "*" in asterisk:
                        s_source += ('\\\"&{}\\\": \\\"%p\\\"", {});\n'.format(variable_name, variable_name))
                    else:
                        s_source += '\\\"{}\\\": \\\"<...>\\\"");\n'.format(variable_name)
                elif hasParseFunc(keyword, parse_func_list):
                    s_source += '\\\"{}\\\": ");\n'.format(variable_name)
                    s_source += '    if(len > max_len - 1){\n'
                    s_source += '        return max_len - 1;\n'
                    s_source += '    }\n\n'
                    s_source += '    len += {}(text + len, max_len - len, p->{});\n'.format(keyword, variable_name)
                elif isStruct(variable_type, Structs):
                    s_source += '\\\"{}\\\": ");\n'.format(variable_name)
                    s_source += '    if(len > max_len - 1){\n'
                    s_source += '        return max_len - 1;\n'
                    s_source += '    }\n\n'
                    s_source += ('    len += parse_{}(text + len, max_len - len, p->{});\n'
                        .format(struct_name, variable_name))
                else:
                    s_source += '\\\"{}\\\": \\\"unsupported\\\"");\n'.format(variable_name)
                s_source += '    if(len > max_len - 1){\n'
                s_source += '        return max_len - 1;\n'
                s_source += '    }\n\n'
            s_source += '    len += snprintf(text + len, max_len - len,\n'
            s_source += '        "}");\n'
            s_source += '    if(len > max_len - 1){\n'
            s_source += '        return max_len - 1;\n'
            s_source += '    }\n\n'
            s_source += '    return len;\n}\n\n'

        with open(src_folder + '/apiMonitor_' + pf_name + '_parse_struct.c', 'w', encoding='utf-8') as write_f:
            write_f.write(s_source)

        s_header_source = '/**\n * @file apiMonitor_' + pf_name + '_parse_struct.h\n'
        s_header_source +=' * @copyright Copyright (c) 2023 DENSO CORPORATION All Rights Reserved.\n *\n */\n\n'
        s_header_source += '#ifndef APIMONITOR_' + pf_name.upper() + '_PARSE_STRUCT_H\n'
        s_header_source += '#define APIMONITOR_' + pf_name.upper() + '_PARSE_STRUCT_H\n\n'
        for header_file in header_files:
            header_file = header_file[header_file.find('include/') + 8:]
            s_header_source += '#include <' + header_file + '>\n'
        for struct_name in Structs:
            s_header_source += ('extern int parse_{}(char *text, int max_len, {} *p);\n'
                .format(struct_name, struct_name))

        s_header_source += '\n\n'
        s_header_source += '#endif  /* APIMONITOR_' + pf_name.upper() + '_PARSE_STRUCT_H */'

        with open(header_folder + '/apiMonitor_' + pf_name + '_parse_struct.h', 'w', encoding='utf-8') as write_hf:
            write_hf.write(s_header_source)
    return Structs