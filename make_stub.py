import glob
import re
import shutil
import os
import sys
import make_typedef_parser
import make_enum_parser
import make_struct_parser

MAX_CALLBACK_COUNT = 100

"""
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
"""

"""
def hasParseFunc(parse_func, parse_func_list):
    for func_name in parse_func_list:
        if func_name == parse_func:
            return True
    return False
"""

"""
def getParamText(in_out_param, variable_type, variable_name, parse_func_list, structs, types, pfname):
    variable_type = variable_type.replace("const ", "") # const除去
    primitiveType = make_typedef_parser.getPrimitiveType(variable_type, types)
    variable_type = variable_type.replace("unsigned ", "unsigned_")
    # ポインタ型の場合、アスタリスクを除去してから型判定
    asterisk = ''
    if "*" in variable_type:
        variable_type = variable_type.replace("*", "")
        asterisk += '*'
    keyword = 'parse_' + variable_type

    text = ""

    if '_cb_t' in variable_type:
        text += '\\\"&{}\\\": ");\n'.format(variable_name)
        text += '    if(len > max_len - 1){\n'
        text += '        return max_len - 1;\n'
        text += '    }\n\n'
        text += ('    len += parse_apiMonitor_addr({} + len, max_len - len, {});\n'
            .format(in_out_param, variable_name))
    elif primitiveType == 'unsigned char*':
        text += '\\\"{}\\\": ");\n'.format(variable_name)
        text += '    if(len > max_len - 1){\n'
        text += '        return max_len - 1;\n'
        text += '    }\n\n'
        text += ('    len += parse_unsigned_char_p_ascii({} + len, max_len - len, {}, strlen((char *){}));\n'
            .format(in_out_param, variable_name, variable_name))
    elif primitiveType == 'char*':
        text += '\\\"{}\\\": ");\n'.format(variable_name)
        text += '    if(len > max_len - 1){\n'
        text += '        return max_len - 1;\n'
        text += '    }\n\n'
        text += ('    len += parse_char_p_ascii({} + len, max_len - len, {}, strlen({}));\n'
            .format(in_out_param, variable_name, variable_name))
    elif '[' in variable_name:
        array_parts = re.match("(.+)\[(.+)\]", variable_name)
        if array_parts is None:
            text += '\\\"{}\\\": \\\"unsupported\\\"");\n'.format(variable_name)
        else:
            array_name = array_parts.group(1)
            array_size = array_parts.group(2)
            if primitiveType == 'char':
                text += '\\\"{}\\\": ");\n'.format(array_name)
                text += '    if(len > max_len - 1){\n'
                text += '        return max_len - 1;\n'
                text += '    }\n\n'
                text += ('    len += parse_char_p_ascii({} + len, max_len - len, {}, {});\n'
                    .format(in_out_param, array_name, array_size))
            elif primitiveType == 'unsigned char':
                array_name = array_parts.group(1)
                array_size = array_parts.group(2)
                text += '\\\"{}\\\": ");\n'.format(array_name)
                text += '    if(len > max_len - 1){\n'
                text += '        return max_len - 1;\n'
                text += '    }\n\n'
                text += ('    len += parse_unsigned_char_p_hex({} + len, max_len - len, {}, {});\n'
                    .format(in_out_param, array_name, array_size))
            else:
                text += '\\\"{}\\\": \\\"unsupported\\\"");\n'.format(variable_name)
    elif pfname + '_handle_t' in variable_type:
        text += '\\\"&{}\\\": ");\n'.format(variable_name)
        text += '    if(len > max_len - 1){\n'
        text += '        return max_len - 1;\n'
        text += '    }\n\n'
        if "*" in asterisk:
            text += ('    len += parse_apiMonitor_addr({} + len, max_len - len, *{});\n'
                .format(in_out_param, variable_name))
        else:
            text += ('    len += parse_apiMonitor_addr({} + len, max_len - len, {});\n'
                .format(in_out_param, variable_name))
    elif hasParseFunc(keyword, parse_func_list):
        text += '\\\"{}\\\": ");\n'.format(variable_name)
        text += '    if(len > max_len - 1){\n'
        text += '        return max_len - 1;\n'
        text += '    }\n\n'
        if "*" in asterisk:
            text += ('    len += {}({} + len, max_len - len, *{});\n'
                .format(keyword, in_out_param, variable_name))
        else:
            text += ('    len += {}({} + len, max_len - len, {});\n'
                .format(keyword, in_out_param, variable_name))
    elif make_struct_parser.isStruct(variable_type, structs):
        text += '\\\"{}\\\": ");\n'.format(variable_name)
        text += '    if(len > max_len - 1){\n'
        text += '        return max_len - 1;\n'
        text += '    }\n\n'
        if "*" in asterisk:
            text += ('    len += parse_{}({} + len, max_len - len, {});\n'
                .format(variable_type, in_out_param, variable_name))
        else:
            text += ('    len += parse_{}({} + len, max_len - len, &{});\n'
                .format(variable_type, in_out_param, variable_name))
    else:
        if "*" in asterisk:
            text += '\\\"&{}\\\": ");\n'.format(variable_name)
            text += '    if(len > max_len - 1){\n'
            text += '        return max_len - 1;\n'
            text += '    }\n\n'
            text += ('    len += parse_apiMonitor_addr({} + len, max_len - len, {});\n'
                .format(in_out_param, variable_name))
        else:
            text += '\\\"{}\\\": \\\"<...>\\\"");\n'.format(variable_name)
    text += '    if(len > max_len - 1){\n'
    text += '        return max_len - 1;\n'
    text += '    }\n\n'
    return text
"""


#============================================================================
# isHeaderFileToIgnore
#   スタブ関数を生成するために参照すべきヘッダファイルかどうかの判定を行う
#   戻り値
#     True:     無視すべきヘッダファイル
#     False:    参照すべきヘッダファイル
#============================================================================
def isHeaderFileToIgnore(pfname, header):
    if pfname == 'dcepf':
        if header.endswith("lib" + pfname + "_error.h") or header.endswith("lib" + pfname + "_type.h"):
            return True
    elif pfname == 'dcmpf':
        if header.endswith("lib" + pfname + "_error.h") or header.endswith("lib" + pfname + "_type.h") or header.endswith("lib" + pfname + "_macro.h"):
            return True
        elif header.endswith("lib" + pfname + "_stdtype_compat.h"):
            return True
        elif header.endswith("_c.h") or header.endswith("_s.h"):
            return True
            
    return False
    
#============================================================================
#============================================================================
def getApiStatus(pfname, status):
    if pfname == 'dcepf':
        if status == "META_API_STATUS_SUCCESS":
            return "DCEPF_API_STATUS_SUCCESS"
        elif status == "META_API_STATUS_FAILED":
            return "DCEPF_API_STATUS_FAILED"
        elif status == "META_API_STATUS_INVALID_PARAM":
            return "DCEPF_API_STATUS_INVALID_PARAM"
        else:
            return "ERROR"
    elif pfname == 'dcmpf':
        if status == "META_API_STATUS_SUCCESS":
            return "DCMPF_API_STATUS_SUCCESS"
        elif status == "META_API_STATUS_FAILED":
            return "DCMPF_API_STATUS_FAILED"
        elif status == "META_API_STATUS_INVALID_PARAM":
            return "DCMPF_API_STATUS_INVALID_PARAM"
        else:
            return "ERROR"
    else:
        return "0"



#============================================================================
# makeSrcStub
#   スタブ関数を生成する
#   戻り値
#     なし
#============================================================================
def makeSrcStub():
    print ("start make src_stub")

    OutStubSourceFolder = 'stub_src'
    OutStubHeaderFolder = 'stub_include'

    # Stub Source Folder の create
    try:
        if os.path.isdir(OutStubSourceFolder):
            shutil.rmtree(OutStubSourceFolder)
        os.makedirs(OutStubSourceFolder)
    except:
        print(OutStubSourceFolder + " フォルダ消去/作成失敗")
        print(OutStubSourceFolder + " 配下のファイルを閉じてください")
        sys.exit()

    # Stub Include Folder の create
    try:
        if os.path.isdir(OutStubHeaderFolder):
            shutil.rmtree(OutStubHeaderFolder)
        os.makedirs(OutStubHeaderFolder)
    except:
        print(OutStubHeaderFolder + " フォルダ消去/作成失敗")
        print(OutStubHeaderFolder + " 配下のファイルを閉じてください")
        sys.exit()

    PfNames = ["dcmpf", "dcepf"]
    HeaderFolder = {"dcmpf":"./include/dcmpf/**/*.h", "dcepf":"./include/dcepf/**/*.h"}
    makefile_txt = ""

    for pfname in PfNames:
        Types = make_typedef_parser.makeTypedefParser(HeaderFolder[pfname], OutStubSourceFolder, OutStubHeaderFolder, pfname)
        Enums = make_enum_parser.makeEnumParser(HeaderFolder[pfname], OutStubSourceFolder, OutStubHeaderFolder, pfname)
        Structs = make_struct_parser.makeStructParser(HeaderFolder[pfname], OutStubSourceFolder, OutStubHeaderFolder, pfname, Enums, Types)
#        parse_func_list = getParseFuncList(OutStubHeaderFolder, pfname)

        OutPfStubFolder = OutStubSourceFolder + "/" + pfname

        # 参照するヘッダファイルを配列化する。
        #   参照のベースフォルダは、HeaderFolder に記述したフォルダ
        header_files = glob.glob(HeaderFolder[pfname], recursive=True)
        
        #
        OutSubFolders =  {}

        # callbackの型と引数のリスト作成
        #   Callbacks は、次のように callback の型を key とし、引数の配列を value とした辞書型配列となる。
        #   また、value は引数の型とその変数名をスペースで連結した文字列を１要素とする。
        #     Callbacks = {'dcmpf_operation_result_cb_t' : ['dcmpf_handle_t handle, 'dcmpf_result_t result'], ... }
        Callbacks = {}
        
        cb_ptn = re.compile("typedef.*(" + pfname + "_[a-zA-Z0-9_]+_cb_t)[\s\)]*\([\s]*([^\)]*)[\)\s;]*$")
        for header in header_files:
            with open(header, 'r', encoding="utf-8") as f:
                line = f.readline()
                while line:
                    result = cb_ptn.match(line)
                    if result is not None:
                        f_param = result.group(2)
                        if f_param is not None:
                            if len(f_param) == 0:
                                while line:
                                    line = f.readline()
                                    s_b = line.find(')')
                                    if s_b >= 0:
                                        f_param += line[0:s_b]
                                        break
                                    f_param += line
                        f_param = f_param.strip() # 前後の空白削除
                        f_param = f_param.replace("\n", "") # 改行削除
                        f_param = re.sub("\s{2,}", " ", f_param) # 連続した空白置き換え
                        f_param = re.sub(',\s+', ',', f_param) # ,後の空白を削除
                        f_param = re.sub(" \* *", "* ", f_param) # ポインタ左寄せ
                        f_param_array = f_param.split(",")
                        Callbacks[result.group(1)] = f_param_array
                    line = f.readline()

#        for cb_type, cb_args in Callbacks.items():
#            print("{} : {}".format(cb_type, cb_args))
 
        # ヘッダファイル名を解析し、生成するソースファイル名、出力フォルダ、ライブラリ名を決定するための
        # 材料となる文字列をグループ化するためのパターンを決める
        #   例えば、libdcepf_dev_euicc.h の場合は、
        #     group(1) = libdcepf_dev_euicc
        #     group(2) = dev
        header_ptn = re.compile(".*(lib" + pfname + "_([^_]+).*)\.h")
        
        # ヘッダファイルに記載されている API のプロトタイプ宣言より、
        # API の戻り値の型、API 名、API の引数 にグループ化するための正規表現を設定する。
        # API の戻り値の型から API 名 および API 名に続く '(' が検出できれば、結果は None ではなくなる。
        #   例えば、"dcepf_api_status_t dcepf_dev_euicc_get_sim_info("
        api_ptn = re.compile(".*(" + pfname + "_api_status_t)\s+([^\s\(]+)\s*\((.*)")
        
        # API の引数全体に対する正規表現
        #   API のプロトタイプの API 名に続く '(' の後から ')' の前まで
        f_param_ptn = re.compile("(.*)\)")
        
        # 引数の型と引数の変数名がスペース連結されていることを検出するための正規表現
        param_ptn = re.compile("(.*)\s+(.*)")

        # すでに取得したヘッダファイルから、生成するソースファイル名、出力フォルダ名、ライブラリ名などを生成する
        #
        for header in header_files:
        
            # ソースファイルを生成するために必要なヘッダファイルかどうかをチェックする
            #   次のようなヘッダファイルは対象外とする
            #     dcepf
            #     └common
            #       └libdcepf_error.h, libdcepf_type.h
            #     dcmpf
            #     └common
            #       └libdcmpf_error.h, libdcmpf_type.h, ...
            if isHeaderFileToIgnore(pfname, header) == True:
                continue
                
            # ヘッダファイル名をパターンマッチによって解析し、文字列のグループ化などを行う
            m_file = header_ptn.match(header)
            
            # 生成するソースファイル(.c)名を決定する。
            #   例えば libdcepf_dev.h に対しては apiMonitor_dcepf_dev.h など
            out_file = m_file.group(1).replace("lib" + pfname, "stub_" + pfname) + '.c'
            
            # 上で決定したソースファイルを出力するフォルダ名を決定する
            #   例えば libdcepf_dev.h に対しては dcepf_dev、libdcepf_dev_euicc.h に対しては dcepf_dev
            in_folder = m_file.group(2)
            out_folder = pfname + "_" + in_folder
            
            # 上で決定したソースファイルを含むライブラリ名を決定する
            #   例えば libdcepf_dev.h に対しては dcepf_dev 、libdcepf_dev_euicc.h に対しては dcepf_dev
            lib_name = pfname + "_" + m_file.group(2)
            
            # 出力するデータを生成する
            source = "/* Copyright (c) 2023 DENSO CORPORATION All Rights Reserved. */\n" \
                + "#include <sys/resource.h>\n" \
                + "#include <sys/types.h>\n" \
                + "#include <dlfcn.h>\n" \
                + "#include <stdio.h>\n" \
                + "#include <stdlib.h>\n" \
                + "#include <unistd.h>\n" \
                + "#include <string.h>\n" \
                + "#include <syslog.h>\n" \
                + "#include <sys/time.h>\n" \
                + "#include <pthread.h>\n" \
                + "#include \"apiStub_common.h\"\n" \
                + "#include <" + pfname + "/" + in_folder + "/lib" + pfname + "_" + in_folder + ".h>\n" \
                + "\n"
                
            # ヘッダファイルをオープンして解析を行う。
            with open(header, 'r', encoding="utf-8") as f:
                line = f.readline()
                while line:
                
                    # API のプロトタイプを読み込む。
                    #   戻り値と API 名と API 名に続く '(' が取り込めれば m_func は None ではなくなる。
                    #   引数の情報は複数行に渡って記述されているはずなので、')' が出るまで読み込みを続ける。
                    m_func = api_ptn.match(line)
                    if m_func is not None:
                        f_ret = m_func.group(1)
                        f_name = m_func.group(2)
                        f_param = m_func.group(3)
                        m_param = f_param_ptn.match(f_param)
                        if m_param is not None:
                            f_param = m_param.group(1)
                        else :
                            line = f.readline()
                            while line:
                                p_b = line.find(")")
                                if p_b >= 0:
                                    f_param += line[0:p_b]
                                    break
                                f_param += line
                                line = f.readline()
                        
                        # API のプロトタイプの読み込み完了
                        #   この時点で、f_ret にはAPI の戻り値の型、f_name には API 名、f_param には引数の全体が取り込まれている。
                        #   次の処理で、f_param の各引数（型と変数名）を整形。
                        #   さらに f_param_array に引数毎に分解して配列として格納する。
                        f_param = f_param.strip() # 前後の空白削除
                        f_param = re.sub("\s{2,}", " ", f_param) # 連続した空白置き換え
                        f_param = re.sub(',\s+', ',', f_param) # ,後の空白を削除
                        f_param = re.sub(" \* *", "* ", f_param) # ポインタ左寄せ
                        f_param_array = f_param.split(",")

                        # API の中で使われる callback の型と変数名を cb_types[] と cb_names[] に格納する
                        cb_types = []
                        cb_names = []
                        
                        # API の引数に callback が含まれている場合の処理(1APIで複数のcallbackもある).
                        for f_param in f_param_array:
                        
                            # 引数の callback が含まれている場合の処理
                            #   判定方法は考慮が必要**************************************
                            if f_param.find("_cb_t ") >= 0:
                            
                                # callback はスレッドからコールする設計とし、
                                # API からスレッドへの情報の受け渡しは、グローバル変数（テーブル）で行うものとする。
                                # 受け渡す必要がある情報は構造体として定義する。
                                #   必要な情報は、
                                #     bool used（テーブルの該当する要素がすでに使用されているかどうか）
                                #     callback のポインタ
                                #     callback の引数のうち、API の引数で渡されるものを使用する必要があるもの
                                #
                                # まず、f_param には callback の型と変数名が入っているはずなので、f_param を
                                # 解析して、type と name を抽出する。
                                #   callback_type : コールバックの型
                                #   callback_name : コールバックの変数名
                                # また、抽出した type と name を後で使用するために、cb_type[] と cb_name[] に
                                # append する。
                                #     
                                cb_param_match = param_ptn.match(f_param)
                                if cb_param_match is None:
                                    continue
                                callback_type = cb_param_match.group(1)
                                cb_types.append(callback_type)
                                callback_name = cb_param_match.group(2)
                                cb_names.append(callback_name)
                                
                                # API の引数のうち、callback を呼ぶときに必要なものを抽出する。
                                # Callbacks には予め全ての使われる callback の型と引数の情報を格納している。
                                # Callbacks から抽出した callback_type を key として callback が使用する
                                # 引数の情報を読み出す。
                                # それと API の引数と比較して同じものがあれば needed_args に append する。
                                # この needed_args に格納された引数は、API からスレッドにグローバル変数経由で
                                # 引き渡せるようにする。   
                                if callback_type in Callbacks.keys():
                                    callback_args = Callbacks[callback_type]
                                else:
                                    print("???????")
                                needed_args = []
                                for arg in callback_args:
                                    if arg in f_param_array:
                                        needed_args.append(arg)
                                            
                                # API 名に _stop_ も _unregister_ も含まれない場合
                                if f_name.find("_stop_") < 0 and f_name.find("_unregister_") < 0:
                                    
                                    # API からスレッドに値を引き渡すためのテーブルで使用する構造体を定義する。
                                    #   構造体の型は次のようになる
                                    #     typedef struct {
                                    #         bool used;
                                    #         callback_type callback_name;
                                    #         callback が使用する API から渡される引数の type と name
                                    #     } ...;
                                    #
                                    cb_thread_prop_type     = "stub_" + f_name + "_" + callback_name + "_thread_prop_t"
                                    cb_thread_prop_tbl_name = "Stub_" + f_name + "_" + callback_name + "_thread_prop"
                                    source += "typedef struct {\n" \
                                           +  "    bool used;\n" \
                                           +  "    " + callback_type + " " + "callback" + ";\n"
#                                           +  "    " + callback_type + " " + callback_name + ";\n"
                                    for arg in needed_args:
                                        source += "    " + arg + ";\n"
                                    source += "} " + cb_thread_prop_type + ";\n\n"
                                    
                                    # callback に必要な情報を格納する領域（テーブル）の確保
                                    source += cb_thread_prop_type + " " + cb_thread_prop_tbl_name + "[API_STUB_MAX_CALLBACK_NUM] = {0};\n\n"
                                    
                                    # Thread の生成
                                    cb_thread_name = "stub_" + f_name + "_" + callback_name + "_thread"
                                    source += "void* " + cb_thread_name + "(void* pArg)\n" \
                                           +  "{\n" \
                                           +  "    int index;\n" \
                                           +  "    unsigned int sleep_time = 5;\n" \
                                           +  "    " + callback_type + " callback;\n"
                                    for arg in callback_args:
                                        source += "    " + arg + ";\n"
#                                    for arg in needed_args:
#                                        source += "    " + arg + ";\n"
                                    source += "\n" \
                                           +  "    if (pArg != NULL)\n" \
                                           +  "    {\n" \
                                           +  "        index = *(int *)pArg;\n" \
                                           +  "\n"
                                    for arg in needed_args:
                                        arg_name = arg.split(" ")[1]
                                        source += "        " + arg_name + " = " + cb_thread_prop_tbl_name + "[index]." + arg_name + ";\n"
                                    source += "\n" \
                                           +  "        do\n" \
                                           +  "        {\n" \
                                           +  "            sleep(sleep_time);\n" \
                                           +  "            callback = " + cb_thread_prop_tbl_name + "[index].callback;\n" \
                                           +  "            if (callback != NULL)\n" \
                                           +  "            {\n" \
                                           +  "                callback("
                                    for i, arg in enumerate(callback_args):
                                        arg_name = arg.split(" ")[len(arg.split(" "))-1]
                                        if i == len(callback_args) - 1:
                                            source += arg_name + ");\n"
                                        else:
                                            source += arg_name + ", "
                                    source += "            }\n" \
                                           +  "            else\n" \
                                           +  "            {\n" \
                                           +  "                break;\n" \
                                           +  "            }\n"
                                    if "_start_" in f_name or "_register_" in f_name:
                                        source += "        } while(true);\n\n"
                                    else:
                                        source += "        } while(false);\n\n"
                                    source += "        " + cb_thread_prop_tbl_name + "[index].callback = NULL;\n" \
                                           +  "        " + cb_thread_prop_tbl_name + "[index].used = false;\n" \
                                           +  "    }\n" \
                                           +  "}\n" \
                                           +  "\n"
                                    
                        #====================================================
                        # API の stub を生成
                        #   まずは API の I/F の部分を生成
                        source += "/*\n" \
                               +  " *\n" \
                               +  " */\n" \
                               +  f_ret + " " + f_name + "(\n"
                        for i, f_param in enumerate(f_param_array):
                            source += "    " + f_param
                            if i == len(f_param_array) - 1:
                                source += "\n)\n"
                            else:
                                source += ",\n"
                        source += "{\n"
                        
                        #====================================================
                        # ここからは API の stub の実体を生成
                        if f_name.find("_stop_") < 0 and f_name.find("_unregister_") < 0:
                            if len(cb_names) != 0:
                                source += "    int i[" + str(len(cb_names)) + "];\n" \
                                       +  "    pthread_t pthread;\n" \
                                       +  "\n" \
                                       +  "    if ( ("
                                for i, cb_name in enumerate(cb_names):
                                    source += cb_name + " ==  NULL)"
                                    if i == len(cb_names) - 1:
                                        source += " )\n"
                                    else:
                                        source += " || ("
                                source += "    {\n" \
                                       +  "        return " + getApiStatus(pfname, "META_API_STATUS_INVALID_PARAM") + ";\n" \
                                       +  "    }\n" \
                                       +  "\n"
                                for i, cb_name in enumerate(cb_names):
                                    cb_thread_prop_tbl_name = "Stub_" + f_name + "_" + cb_name + "_thread_prop[i[" + str(i) + "]]"
                                    cb_thread_name = "stub_" + f_name + "_" + callback_name + "_thread"
                                    source += "    for (i[" + str(i) + "] = 0; i[" + str(i) + "] < API_STUB_MAX_CALLBACK_NUM; i[" + str(i) + "]++)\n" \
                                           +  "    {\n" \
                                           +  "        if (" + cb_thread_prop_tbl_name + ".used == false)\n" \
                                           +  "        {\n" \
                                           +  "                " + cb_thread_prop_tbl_name + ".used = true;\n" \
                                           +  "                break;\n" \
                                           +  "        }\n" \
                                           +  "    }\n" \
                                           +  "    if (i[" + str(i) + "] == " + "API_STUB_MAX_CALLBACK_NUM" + ")\n" \
                                           +  "    {\n" \
                                           +  "        return " + getApiStatus(pfname, "META_API_STATUS_FAILED") + ";\n" \
                                           +  "    }\n" \
                                           +  "\n" \
                                           +  "    // callback のポインタをテーブルにセットする\n" \
                                           +  "    " + cb_thread_prop_tbl_name + ".callback = " + cb_name + ";\n" \
                                           +  "\n" \
                                           +  "    // 必要なバラメータをテーブルにセットする\n"
                                    for arg in needed_args:
                                        arg_name = arg.split(" ")[1]
                                        source += "    " + cb_thread_prop_tbl_name + "." + arg_name + " = " + arg_name + ";\n"
                                    source += "\n" \
                                           +  "    // スレッドをクリエートする\n" \
                                           +  "    pthread_create(&pthread, NULL, " + cb_thread_name + ", &i[" + str(i) + "]);\n" \
                                           +  "    if (pthread == 0)\n" \
                                           +  "    {\n" \
                                           +  "        // スレッドのクリエートに失敗した場合、used と callback をクリアする\n" \
                                           +  "        " + cb_thread_prop_tbl_name + ".callback = NULL;\n" \
                                           +  "        " + cb_thread_prop_tbl_name + ".used = false;\n" \
                                           +  "        return " + getApiStatus(pfname, "META_API_STATUS_FAILED") + ";\n" \
                                           +  "    }\n" \
                                           +  "\n"
                        else:
                            if len(cb_names) != 0:
                                source += "    int i[" + str(len(cb_names)) + "];\n" \
                                       +  "\n" \
                                       +  "    if ( ("
                                for i, cb_name in enumerate(cb_names):
                                    source += cb_name + " ==  NULL)"
                                    if i == len(cb_names) - 1:
                                        source += " )\n"
                                    else:
                                        source += " || ("
                                source += "    {\n" \
                                       +  "        return " + getApiStatus(pfname, "META_API_STATUS_INVALID_PARAM") + ";\n" \
                                       +  "    }\n" \
                                       +  "\n"
                                for i, cb_name in enumerate(cb_names):
                                    f_temp = f_name.replace("_stop_", "_start_").replace("_unregister_", "_register_")
                                    cb_thread_prop_tbl_name = "Stub_" + f_temp + "_" + cb_name + "_thread_prop[i[" + str(i) + "]]"
                                    source += "    for (i[" + str(i) + "] = 0; i[" + str(i) + "] < API_STUB_MAX_CALLBACK_NUM; i[" + str(i) + "]++)\n" \
                                           +  "    {\n" \
                                           +  "        if (" + cb_thread_prop_tbl_name + ".handle == handle)\n" \
                                           +  "        {\n" \
                                           +  "                break;\n" \
                                           +  "        }\n" \
                                           +  "    }\n" \
                                           +  "    if (i[" + str(i) + "] == " + "API_STUB_MAX_CALLBACK_NUM" + ")\n" \
                                           +  "    {\n" \
                                           +  "        return " + getApiStatus(pfname, "META_API_STATUS_FAILED") + ";\n" \
                                           +  "    }\n" \
                                           +  "\n" \
                                           +  "    // callback のポインタをテーブルにセットする\n" \
                                           +  "    " + cb_thread_prop_tbl_name + ".callback = NULL;\n" \
                                           +  "\n"
                        source += "    return " + getApiStatus(pfname, "META_API_STATUS_SUCCESS") + ";\n"
                        source += "}\n"
                        source += "\n"
                                    
                        """
                                    source_tbl_name = "apiMonitor_" + f_name + "_" + callback_name + "_source_callbacks"
                                    tbl_name = "apiMonitor_" + f_name + "_" + callback_name + "_callbacks"
                                    cb_name = "apiMonitor_" + f_name + "_" + callback_name + "_cb"

                                    source += callback_type + " " + source_tbl_name + "[API_MONITOR_MAX_CALLBACK_COUNT] = {0};\n\n"
                        """

                        """
                                    cb_params_str = ""
                                    cb_param_names_str = ""
                                    for i, cb_param in enumerate(Callbacks[callback_type]):
                                        cb_p = cb_param.split(" ")
                                        if i == len(Callbacks[callback_type]) - 1:
                                            cb_params_str += "    " + cb_param
                                            cb_param_names_str += cb_p[len(cb_p) - 1]
                                        else :
                                            cb_params_str += "    " + cb_param + ",\n"
                                            cb_param_names_str += cb_p[len(cb_p) - 1] + ", "

                                    # メインcallback関数プロトタイプ宣言
                                    source += "void " + cb_name + "(\n" + cb_params_str + ",\n int callback_index);\n\n"

                                    # callback関数
                                    for i in range(MAX_CALLBACK_COUNT):
                                        source += "void " + cb_name + str(i) + "(\n" + cb_params_str + "){\n"
                                        source += "    " + cb_name + "(\n        " + cb_param_names_str + ", " + str(i) + ");\n}\n"

                                    source += "\n"

                                    # callback関数配列
                                    source += callback_type + " " + tbl_name + "[API_MONITOR_MAX_CALLBACK_COUNT] = {\n"
                                    for i in range(MAX_CALLBACK_COUNT):
                                        if i==MAX_CALLBACK_COUNT-1:
                                            source += "    " + cb_name + str(i) + "\n"
                                        else :
                                            source += "    " + cb_name + str(i) + ",\n"

                                    source += "};\n"

                                    # callback関数用 in_paramのパース関数
                                    parse_func_name = "parse_" + f_name + "_cb_param"
                                    source += "int " + parse_func_name + "(\n"
                                    source += "    char* in_param,\n"
                                    source += "    const int max_len,\n"
                                    source +=  cb_params_str + "){\n"

                                    source += "    int len = 0;\n\n"
                                    for j, cb_param in enumerate(Callbacks[callback_type]):
                                        param_match = param_ptn.match(cb_param)
                                        if param_match is None:
                                            continue
                                        variable_type = param_match.group(1)
                                        variable_name = param_match.group(2)
                                        if j == 0:
                                            source += '    len = snprintf(in_param, max_len,\n        "{"\n        "'
                                        else:
                                            source += '    len += snprintf(in_param + len, max_len - len,\n        ",'

                                        source += getParamText('in_param', variable_type, variable_name, parse_func_list, Structs, Types, pfname)
                                    source += '    len += snprintf(in_param + len, max_len - len,\n'
                                    source += '        "}");\n'
                                    source += '    if(len > max_len - 1){\n'
                                    source += '        return max_len - 1;\n'
                                    source += '    }\n\n'
                                    source += '    return len;\n'
                                    source += '}\n\n'

                                    # メインcallback関数
                                    source += "void " + cb_name + "(\n"
                                    source +=  cb_params_str + ", int callback_index){\n"
                                    source +=  "    char in_param[API_MONITOR_IN_PARAM_MAX_SIZE];\n\n"

                                    source += "    parse_" + f_name + "_cb_param(in_param, API_MONITOR_IN_PARAM_MAX_SIZE, "
                                    source += cb_param_names_str
                                    source += ");\n\n"

                                    source +=  "    apiMonitor_add_cb_log(\n"
                                    source +=  "        \"" + lib_name + "\",\n"
                                    source +=  "        \"" + f_name + "\",\n"
                                    source +=  "        \"callback\",\n"
                                    source +=  "        in_param);\n\n"

                                    source +=  "    if (" + source_tbl_name + "[callback_index] != NULL) {\n"
                                    source +=  "        " + source_tbl_name + "[callback_index](" + cb_param_names_str + ");\n"
                                    if f_name.find("_invoke_") >=0 or f_name.find("_apply_") >=0 or f_name.find("_query_") >=0:
                                        source +=  "        " + source_tbl_name + "[callback_index] = NULL;\n"

                                    source +=  "    }\n"
                                    source +=  "}\n"

                        # in_paramのパース関数
                        if 'void' not in f_param_array and "control_context_create" not in f_name:
                            parse_func_name = "parse_" + f_name + "_in_param"
                            source += "int " + parse_func_name + "(\n"
                            source += "            char* in_param,\n"
                            source += "            const int max_len"
                            for f_param in f_param_array:
                                source += (",\n            {}".format(f_param))
                            source += ")\n{\n"
                            source += "    int len = 0;\n\n"
                            for j, f_param in enumerate(f_param_array):
                                param_match = param_ptn.match(f_param)
                                if param_match is None:
                                    continue
                                variable_type = param_match.group(1)
                                variable_name = param_match.group(2)
                                if j == 0:
                                    source += '    len = snprintf(in_param, max_len,\n        "{"\n        "'
                                else:
                                    source += '    len += snprintf(in_param + len, max_len - len,\n        ",'

                                source += getParamText('in_param', variable_type, variable_name, parse_func_list, Structs, Types, pfname)

                            source += '    len += snprintf(in_param + len, max_len - len,\n'
                            source += '        "}");\n'
                            source += '    if(len > max_len - 1){\n'
                            source += '        return max_len - 1;\n'
                            source += '    }\n\n'
                            source += '    return len;\n'
                            source += '}\n\n'

                        # out_param用 引数のパース関数
                        if "control_context_create" in f_name or "_get_" in f_name:
                            parse_func_name = "parse_" + f_name + "_out_param"
                            source += "int " + parse_func_name + "(\n"
                            source += "            char* out_param,\n"
                            source += "            const int max_len"
                            for f_param in f_param_array:
                                if "_cb_t" in f_param:
                                    continue
                                else:
                                    source += (",\n            {}".format(f_param))
                            source += ")\n{\n"
                            source += "    int len = 0;\n\n"
                            for j, f_param in enumerate(f_param_array):
                                param_match = param_ptn.match(f_param)
                                if param_match is None:
                                    continue
                                variable_type = param_match.group(1)
                                variable_name = param_match.group(2)
                                if '_cb_t' in variable_type:
                                    continue
                                if j == 0:
                                    source += '    len = snprintf(out_param, max_len,\n        "{"\n        "'
                                else:
                                    source += '    len += snprintf(out_param + len, max_len - len,\n        ",'

                                source += getParamText('out_param', variable_type, variable_name, parse_func_list, Structs, Types, pfname)

                            source += '    len += snprintf(out_param + len, max_len - len,\n'
                            source += '        "}");\n'
                            source += '    if(len > max_len - 1){\n'
                            source += '        return max_len - 1;\n'
                            source += '    }\n\n'
                            source += '    return len;\n'
                            source += '}\n\n'

                        paramstr = "            " +  ",\n            ".join(f_param_array)
                        # 関数
                        source += "\n" + f_ret + " " + f_name + "(\n" + paramstr + ")\n{\n"
                        # 関数内変数宣言
                        source += "    struct timeval start_timeval;\n"
                        source += "    struct rusage start, end;\n"
                        source += "    char ret_value[API_MONITOR_RET_VALUE_MAX_SIZE];\n"
                        if 'void' not in f_param_array and 'control_context_create' not in f_name:
                            source += "    char in_param[API_MONITOR_IN_PARAM_MAX_SIZE];\n"

                        # callback用ポインタ宣言
                        callback_count = 0
                        for f_param in f_param_array:
                            if f_param.find("_cb_t ") >= 0:
                                callback_count += 1
                                p = f_param.split(" ")
                                source += "    " + p[0] + " p_" + p[len(p) - 1] + ";\n"

                        # callback用リストインデックス
                        if callback_count > 0:
                            source += "    int callback_index[" + str(callback_count) + "];\n"

                        if f_name.find('control_context_create') >= 0 or f_name.find('_get_') >= 0:
                            source += "    char out_param[API_MONITOR_OUT_PARAM_MAX_SIZE];\n"

                        # 実体関数のアドレス取得
                        source += "\n    void* libhandle = dlopen(\"lib" + pfname + "_" + in_folder + ".so\", RTLD_NOW);\n"
                        source += "    if (libhandle == NULL) {\n"
                        source += "        syslog(LOG_ERR, \"%s: dlopen error. %s\", __func__, dlerror());\n"
                        source += "        return " + pfname.upper() + "_API_STATUS_FAILED;\n"
                        source += "    }\n"
                        source += "\n"
                        source += "    void* symaddr = dlsym(libhandle, \"" + f_name + "\");\n"
                        source += "    if (symaddr == NULL) {\n"
                        source += "        syslog(LOG_ERR, \"%s: dlsym error.  %s\", __func__, dlerror());\n"
                        source += "        return " + pfname.upper() + "_API_STATUS_FAILED;\n"
                        source += "    }\n"

                        cb_count = 0
                        for f_param in f_param_array:
                            p = f_param.split(" ")
                            if f_param.find("_cb_t ") >=0:
                                if f_name.find("_stop_") >=0 or f_name.find("_unregister_") >=0:
                                    # stop,unregisterでのapiMonitor内callback解除
                                    cb_f_name = f_name
                                    cb_f_name = cb_f_name.replace("_stop_", "_start_")
                                    cb_f_name = cb_f_name.replace("_unregister_", "_register_")
                                    source_tbl_name = "apiMonitor_" + cb_f_name + "_" + p[len(p) - 1] + "_source_callbacks"
                                    source += "\n    for(callback_index[" + str(cb_count) + "] = 0; callback_index[" + str(cb_count) + "] < API_MONITOR_MAX_CALLBACK_COUNT; callback_index[" + str(cb_count) + "] ++) {\n"
                                    source += "        if (" + source_tbl_name + "[callback_index[" + str(cb_count) + "]] == " + p[len(p) - 1] + ") {\n"
                                    source += "            " + source_tbl_name + "[callback_index[" + str(cb_count) + "]] = NULL;\n"
                                    source += "            break;\n"
                                    source += "        }\n"
                                    source += "    }\n"

                                    # callbackがリストに無かった場合は呼び出し元から指定されたcallbackをそのまま実体関数に渡す
                                    source += "    if (callback_index[" + str(cb_count) + "] == API_MONITOR_MAX_CALLBACK_COUNT) {\n"
                                    source += "        syslog(LOG_ERR, \"apiMonitor %s callback not found.\", __func__);\n"
                                    source += "        p_" + p[len(p) - 1] + " = " + p[len(p) - 1] + ";\n"
                                    source += "    } else {\n"
                                    source += "        p_" + p[len(p) - 1] + " = apiMonitor_" + cb_f_name + "_" + p[len(p) - 1] + "_callbacks[callback_index[" + str(cb_count) + "]];\n"
                                    source += "    }\n"
                                else:
                                    # apiMonitor内callback登録
                                    source_tbl_name = "apiMonitor_" + f_name + "_" + p[len(p) - 1] + "_source_callbacks"
                                    source += "\n    for(callback_index[" + str(cb_count) + "] = 0; callback_index[" + str(cb_count) + "] < API_MONITOR_MAX_CALLBACK_COUNT; callback_index[" + str(cb_count) + "] ++) {\n"
                                    source += "        if (" + source_tbl_name + "[callback_index[" + str(cb_count) + "]] == NULL) {\n"
                                    source += "            " + source_tbl_name + "[callback_index[" + str(cb_count) + "]] = " + p[len(p) - 1] + ";\n"
                                    source += "            break;\n"
                                    source += "        }\n"
                                    source += "    }\n"

                                    # callbackリスト最大数を越えた場合は呼び出し元から指定されたcallbackをそのまま実体関数に渡す
                                    source += "    if (callback_index[" + str(cb_count) + "] == API_MONITOR_MAX_CALLBACK_COUNT) {\n"
                                    source += "        syslog(LOG_ERR, \"apiMonitor %s Maximum number of callbacks exceeded.\", __func__);\n"
                                    source += "        p_" + p[len(p) - 1] + " = " + p[len(p) - 1] + ";\n"
                                    source += "    } else {\n"
                                    source += "        p_" + p[len(p) - 1] + " = apiMonitor_" + f_name + "_" + p[len(p) - 1] + "_callbacks[callback_index[" + str(cb_count) + "]];\n"
                                    source += "    }\n"
                                cb_count += 1

                        paramstr = "\n            " + ",\n            ".join(f_param_array)
                        source += "\n    " + f_ret + " (*symfunc)(" + paramstr + ") =\n        (" + f_ret+ " (*)(" + paramstr + "))symaddr;\n"
                        source += "\n"
                        source += "    getrusage(RUSAGE_SELF, &start);\n"
                        source += "    gettimeofday(&start_timeval, NULL);\n\n"
                        if 'void' in f_param_array or 'control_context_create' in f_name:
                            source += "    apiMonitor_add_in_log(&start_timeval, \"" + lib_name + "\", \"" + f_name + "\", &start, NULL);\n"
                        else:
                            source += "    parse_" + f_name + "_in_param(in_param, API_MONITOR_IN_PARAM_MAX_SIZE"
                            for f_param in f_param_array:
                                p = f_param.split(" ")
                                if '[' in p[len(p)-1]:
                                    l = p[len(p)-1].split('[')
                                    source += (", {}".format(l[0]))
                                else:
                                    source += (", {}".format(p[len(p)-1]))
                            source += ");\n"
                            source += "    apiMonitor_add_in_log(&start_timeval, \"" + lib_name + "\", \"" + f_name + "\", &start, in_param);\n"
                        # 実体関数の呼び出し
                        source += "\n"
                        source += "    " + f_ret + " ret = symfunc(\n"
                        cb_count = 0
                        for i, f_param in enumerate(f_param_array):
                            p = f_param.split(" ")
                            if f_param.find("_cb_t ") >=0:
                                cb_f_name = f_name
                                cb_f_name = cb_f_name.replace("_stop_", "_start_")
                                cb_f_name = cb_f_name.replace("_unregister_", "_register_")
                                source += "        p_" + p[len(p) - 1]
                                cb_count += 1
                            else:
                                if len(p) >= 2:
                                    param_name = p[len(p) - 1]
                                    param_name = re.sub("\[.*\]", "", param_name)
                                    source += "        " + param_name
                            if i != len(f_param_array) - 1:
                                source += ",\n"
                        source += ");\n"
                        source += "\n"
                        source += "    getrusage(RUSAGE_SELF, &end);\n"
                        source += "    dlclose(libhandle);\n"
                        source += "\n"
                        source += "    parse_" + pfname + "_api_status_t(ret_value, API_MONITOR_RET_VALUE_MAX_SIZE, ret);\n"

                        source += "\n"

                        if "_get_" in f_name or "control_context_create" in f_name:
                            source += "    parse_" + f_name + "_out_param(out_param, API_MONITOR_OUT_PARAM_MAX_SIZE"
                            for f_param in f_param_array:
                                p = f_param.split(" ")
                                if '[' in p[len(p)-1]:
                                    l = p[len(p)-1].split('[')
                                    source += (", {}".format(l[0]))
                                else:
                                    source += (", {}".format(p[len(p)-1]))
                            source += ");\n"
                            source += "    apiMonitor_add_out_log(&start_timeval, \"" + lib_name + "\", \"" + f_name + "\", &start, &end, ret_value, out_param);\n"
                        else :
                            source += "    apiMonitor_add_out_log(&start_timeval, \"" + lib_name + "\", \"" + f_name + "\", &start, &end, ret_value, NULL);\n"

                        source += "\n"
                        source += "    return ret;\n"
                        source += "}\n"
                        """
                    line = f.readline()

            out_files = OutSubFolders.get(out_folder)
            if out_files is None:
                OutSubFolders[out_folder] = []
                os.makedirs(OutPfStubFolder + "/" + out_folder)
            OutSubFolders[out_folder].append(out_file)
            with open(OutPfStubFolder + '/' + out_folder + '/' + out_file, 'w', encoding="utf-8") as write_f:
                write_f.write(source)

        """
        makefile_txt += "lib_LTLIBRARIES +="

        for out_folder in OutSubFolders:
            makefile_txt += "\\\n                  libapiMonitor_" + out_folder + ".la"

        for out_folder in OutSubFolders:
            makefile_txt += "\n\n# " + out_folder + "\n"
            makefile_txt += "libapiMonitor_" + out_folder + "_la_SOURCES = \\\n"
            for out_file in OutSubFolders[out_folder]:
                makefile_txt += "                                     " + OutPfStubFolder + "/" + out_folder + "/" + out_file + " \\\n"
            makefile_txt += "                                     src/apiMonitor_common.c\\\n"
            makefile_txt += "                                     src/apiMonitor_parse_primitive.c\\\n"
            makefile_txt += "                                     src_stub/apiMonitor_" + pfname + "_parse_enum.c\\\n"
            makefile_txt += "                                     src_stub/apiMonitor_" + pfname + "_parse_typedef.c\\\n"
            makefile_txt += "                                     src_stub/apiMonitor_" + pfname + "_parse_struct.c\n"
            makefile_txt += "libapiMonitor_" + out_folder + "_la_LIBADD = -ldl\n"

        makefile_txt += "\n\n"

    with open('./Makefile_stub.am', 'w', encoding="utf-8") as rootCMake_f:
        rootCMake_f.write(makefile_txt)
    """

makeSrcStub()
