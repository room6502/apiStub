import glob
import re

def isPrimitiveType(type_name):
    if (type_name == 'char' or type_name == 'short' or type_name == 'long' or type_name == 'int' or
        type_name == 'unsigned char' or type_name == 'unsigned short' or type_name == 'unsigned long' or type_name == 'unsigned int' or
        type_name == 'float' or type_name == 'double' or type_name == 'time_t' or type_name == 'bool'):
        return True
    return False

def getPrimitiveType(type_name, types):
    type_name_n = type_name
    asterisk = ''
    if '*' in type_name_n:
        type_name_n = type_name_n.replace('*', '')
        asterisk += '*'
    if isPrimitiveType(type_name_n):
        return type_name_n + asterisk
    for t in types:
        if t == type_name_n:
            if isPrimitiveType(types[t]):
                return types[t] + asterisk
            primitiveType = getPrimitiveType(types[t], types)
            if primitiveType is not None:
                return primitiveType + asterisk
            return None
    return None

def makeTypedefParser(header_path, src_folder, header_folder, pf_name):
    Types = {}
    header_files = []
    # stdint.hに記載の型をリストに追加
    Types["int8_t"] = "char"
    Types["uint8_t"] = "unsigned char"
    Types["int16_t"] = "short"
    Types["uint16_t"] = "unsigned short"
    Types["int32_t"] = "int"
    Types["uint32_t"] = "unsigned int"
    Types["int64_t"] = "long"
    Types["uint64_t"] = "unsigned long"

    typedef_ptn = re.compile("typedef\s+(.+)\s+(.+);")
    # ファイルから解析対象のtypedef情報のみ抽出し、余分な記号を除去して辞書型配列に格納
    for file in glob.glob(header_path, recursive=True):
        with open(file, 'r', encoding='utf-8') as f:
            for line in f:
                if line.startswith('typedef'):
                    if 'enum' not in line and 'struct' not in line and 'cb_t' not in line:
                        line_str = line.strip() # 前後の空白削除
                        line_str = re.sub("\s{2,}", " ", line_str) # 連続した空白置き換え
                        line_str = re.sub(" \* *", "* ", line_str) # ポインタ左寄せ
                        type_parts = typedef_ptn.match(line_str)
                        if type_parts is None:
                            continue
                        type_name = type_parts.group(2)
                        src_type_name = type_parts.group(1)
                        if type_name not in Types:
                            Types[type_name] = src_type_name
                        if file not in header_files:
                                header_files.append(file)

    # typedefのparse関数書き出し
    source = '/* Copyright (c) 2023 DENSO CORPORATION All Rights Reserved. */\n'
    source += '#include <stdio.h>\n'
    source += '#include <stdint.h>\n'
    source += '#include <stdbool.h>\n'
    source += '#include <time.h>\n'
    source += '#include <apiMonitor_parse_primitive.h>\n\n'
    source += '#include <apiMonitor_' + pf_name + '_parse_typedef.h>\n'
    for type_name in Types:
        primitiveType = getPrimitiveType(type_name, Types)
        if primitiveType is None or '*' in primitiveType:
            continue
        source += ('int parse_{}(char *text, int max_len, {} value){{\n'.format(type_name, type_name))
        source += '    return '
        fname = primitiveType.replace('unsigned ','unsigned_')
        source += ('parse_{}(text, max_len, ({})value);\n'.format(fname, primitiveType))
        source += '}\n\n'

    with open(src_folder + '/apiMonitor_' + pf_name + '_parse_typedef.c', 'w', encoding='utf-8') as write_f:
        write_f.write(source)

    header_source = '/**\n * @file apiMonitor_' + pf_name + '_parse_typedef.h\n'
    header_source +=' * @copyright Copyright (c) 2023 DENSO CORPORATION All Rights Reserved.\n *\n */\n\n'
    header_source += '#ifndef APIMONITOR_' + pf_name.upper() + '_PARSE_TYPEDEF_H\n'
    header_source += '#define APIMONITOR_' + pf_name.upper() + '_PARSE_TYPEDEF_H\n\n'
    header_source += '#include <stdint.h>\n'
    for header_file in header_files:
        header_file = header_file[header_file.find('include/') + 8:]
        header_source += '#include <' + header_file + '>\n'
    header_source += '\n'

    for type_name in Types:
        primitiveType = getPrimitiveType(type_name, Types)
        if primitiveType is None or '*' in primitiveType:
            continue
        header_source += ('extern int parse_{}(char *text, int max_len, {} value);\n'
            .format(type_name, type_name))

    header_source += '\n\n'
    header_source += '#endif  /* APIMONITOR_' + pf_name.upper() + '_PARSE_TYPEDEF_H */'

    with open(header_folder + '/apiMonitor_' + pf_name + '_parse_typedef.h', 'w', encoding='utf-8') as write_hf:
        write_hf.write(header_source)

    return Types