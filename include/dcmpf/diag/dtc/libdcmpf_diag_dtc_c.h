/**
 * @file libdcmpf_diag_dtc_c.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese DTC機能モジュール(定数宣言)
 * @brief \~english Diagnostic Trouble Code feature module (constant definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_DTC_C_H
#define LIBDCMPF_DIAG_DTC_C_H
/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_dtc DTC機能モジュール
 * \~english  @addtogroup dcmpf_diag_dtc Diagnostic Trouble Code feature module
 * \~ @{
 */
#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief \~japanese DTC種別
 * @brief \~english DTC
 */
typedef enum {
    /**
     * @brief \~japanese TEL MAINアンテナ異常（断線）:B15CB13
     * @brief \~english TEL Main Antenna malfunction (Disconnection):B15CB13
     */
    DCMPF_DIAG_DTC_TEL_MAIN_ANTENNA_MALFUNCTON_DISCONNECT = 0x95cb13,
    /**
     * @brief \~japanese TEL MAINアンテナ異常（ショート）:B15CB11
     * @brief \~english TEL Main Antenna malfunction (Short):B15CB11
     */
    DCMPF_DIAG_DTC_TEL_MAIN_ANTENNA_MALFUNCTON_SHORT = 0x95cb11,
    /**
     * @brief \~japanese GNSSアンテナ異常（断線）:B15C113
     * @brief \~english GNSS Antenna malfunction (Disconnection):B15C113
     */
    DCMPF_DIAG_DTC_GNSS_ANTENNA_MALFUNCTON_DISCONNECT = 0x95c113,
    /**
     * @brief \~japanese GNSSアンテナ異常（ショート）:B15C111
     * @brief \~english GNSS Antenna malfunction (Short):B15C111
     */
    DCMPF_DIAG_DTC_GNSS_ANTENNA_MALFUNCTON_SHORT = 0x95c111,
    /**
     * @brief \~japanese TEL SUBアンテナ異常（断線）:B153713
     * @brief \~english TEL Sub Antenna malfunction (Disconnection):B153713
     */
    DCMPF_DIAG_DTC_TEL_SUB_ANTENNA_MALFUNCTON_DISCONNECT = 0x953713,
    /**
     * @brief \~japanese TEL SUBアンテナ異常（ショート）:B153711
     * @brief \~english TEL Sub Antenna malfunction (Short):B153711
     */
    DCMPF_DIAG_DTC_TEL_SUB_ANTENNA_MALFUNCTON_SHORT = 0x953711,
    /**
     * @brief \~japanese Button異常（オープン）:B15C513
     * @brief \~english Button malfunction (Open):B15C513
     */
    DCMPF_DIAG_DTC_BUTTON_MULFUNCTION_OPEN = 0x95c513,
    /**
     * @brief \~japanese Button異常（ショート）:B15C511
     * @brief \~english Button malfunction (Short):B15C511
     */
    DCMPF_DIAG_DTC_BUTTON_MALFUNCTON_SHORT = 0x95c511,
    /**
     * @brief \~japanese 赤LED異常（オープン）:B157013
     * @brief \~english Red LED malfunction (Open):B157013
     */
    DCMPF_DIAG_DTC_RED_LED_MULFUNCTION_OPEN = 0x957013,
    /**
     * @brief \~japanese 赤LED異常（ショート）:B157011
     * @brief \~english Red LED malfunction (Short):B157011
     */
    DCMPF_DIAG_DTC_RED_LED_MALFUNCTON_SHORT = 0x957011,
    /**
     * @brief \~japanese バックグラウンドLED異常（オープン）:TBD
     * @brief \~english Background LED malfunction (Open):TBD
     */
    DCMPF_DIAG_DTC_BACKGROUND_LED_MULFUNCTION_OPEN = 0x000001,
    /**
     * @brief \~japanese バックグラウンドLED異常（ショート）:TBD
     * @brief \~english Background LED malfunction (Short):TBD
     */
    DCMPF_DIAG_DTC_BACKGROUND_LED_MALFUNCTON_SHORT = 0x000002,
    /**
     * @brief \~japanese エアバッグ信号異常:B15C464
     * @brief \~english Airbag signal abnormal:B15C464
     */
    DCMPF_DIAG_DTC_BACKGROUND_AIRBAG_SIGNAL_ABNORMAL = 0x95c464,
    /**
     * @brief \~japanese バックアップバッテリ異常:B15CC49
     * @brief \~english BUB malfanction:B15CC49
     */
    DCMPF_DIAG_DTC_BUB_MALFUNCTION = 0x95cc49,
    /**
     * @brief \~japanese スピーカケーブル接続異常:B1AC07F
     * @brief \~english Disconnect speaker cables:B1AC07F
     */
    DCMPF_DIAG_DTC_DISCONNECT_SPEAKER_CABLES = 0x9ac07f,
    /**
     * @brief \~japanese マイク異常、未接続:B157213
     * @brief \~english Microphone malfunction:B157213
     */
    DCMPF_DIAG_DTC_MICROPHONE_MALFUNCTION = 0x957213,
    /**
     * @brief \~japanese DCM異常:B15A804
     * @brief \~english DCM malfunction:B15A804
     */
    DCMPF_DIAG_DTC_DCM_MALFUNCTION = 0x95a804,
    /**
     * @brief \~japanese DCM異常(保存データ異常):B15A846
     * @brief \~english DCM malfunction(Abnormal stored data):B15A846
     */
    DCMPF_DIAG_DTC_DCM_MALFUNCTION_ABNORMAL_STORED_DATA = 0x95a846,
    /**
     * @brief \~japanese DCM異常(内部Gセンサ異常):B152F31
     * @brief \~english DCM malfunction(Internal accelerometer malfunction):B152F31
     */
    DCMPF_DIAG_DTC_DCM_MALFUNCTION_INTERNAL_ACCELEROMETER_MALFUNCTION = 0x952f31,
    /**
     * @brief \~japanese DCM異常(Wi-Fi Chip HW異常):B15A8(TBD)
     * @brief \~english DCM malfunction(Wi-Fi Chip Hardware malfunction):B15A8(TBD)
     */
    DCMPF_DIAG_DTC_DCM_MALFUNCTION_WIFI_CHIP_HARDWARE_MALFUNCTION = 0x95a800,
    /**
     * @brief \~japanese メインボデー通信途絶:U014087
     * @brief \~english Communication blackout from BDB :U014087
     */
    DCMPF_DIAG_DTC_COMMUNICATION_BLACKOUT_FROM_BDB = 0xC14087,
    /**
     * @brief \~japanese H/U通信途絶:U016387
     * @brief \~english Communication blackout from AVN :U016387
     */
    DCMPF_DIAG_DTC_COMMUNICATION_BLACKOUT_FROM_AVN = 0xC16387,
    /**
     * @brief \~japanese メータ通信途絶:U015587
     * @brief \~english Communication blackout from MET :U015587
     */
    DCMPF_DIAG_DTC_COMMUNICATION_BLACKOUT_FROM_MET = 0xC15587,
    /**
     * @brief \~japanese Wi-Fi ANT2断線:TBD
     * @brief \~english Wi-Fi ANT2 Disconnection:TBD
     */
    DCMPF_DIAG_DTC_WIFI_ANT2_DISCONNECTION = 0x000003,
    /**
     * @brief \~japanese Wi-Fi ANT2ショート:TBD
     * @brief \~english Wi-Fi ANT2 Short:TBD
     */
    DCMPF_DIAG_DTC_WIFI_ANT2_SHORT = 0x000004,
    /**
     * @brief \~japanese CODEC/DSP異常:TBD
     * @brief \~english CODEC/DSP malfunction:TBD
     */
    DCMPF_DIAG_DTC_CODEC_DSP_MALFUNCTION = 0x000005,
} dcmpf_diag_dtc_code_t;

/**
 * @brief \~japanese UserDefMemoryDTC種別
 * @brief \~english UserDefMemoryDTC
 */
typedef enum {
    /**
     * @brief \~japanese DCMバックアップバッテリ寿命 :U2210(TBD)
     * @brief \~english DCM backup battery end of life :U2210(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_BUB_EOF = 0xE21000,
    /**
     * @brief \~japanese DCMバックアップバッテリ充電量低下 :U2211(TBD)
     * @brief \~english DCM backup battery low charge :U2211(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_BUB_LOW_CHARGE = 0xE21100,
    /**
     * @brief \~japanese VIN不一致 :U2601(TBD)
     * @brief \~english VIN discrepancy abnormality detection :U2601(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_VIN_UNMATCH = 0xE60100,
    /**
     * @brief \~japanese DCM SOSボタン Stuck ON :U2213(TBD)
     * @brief \~english DCM SOS button Stuck ON :U2213(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_SOS_BUTTON_STUCK = 0xE21300,
    /**
     * @brief \~japanese PDC通信途絶 :U2214(TBD)
     * @brief \~english Communication disruption from PDC :U2214(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_PDC_DISRUPT = 0xE21400,
    /**
     * @brief \~japanese BDB通信途絶 :U2218(TBD)
     * @brief \~english Communication disruption from BDB :U2218(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_BDB_DISRUPT = 0xE21800,
    /**
     * @brief \~japanese Eth通信途絶 :U2219(TBD)
     * @brief \~english Ethernet communication disruption :U2219(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_ETH_DISRUPT = 0xE21900,
    /**
     * @brief \~japanese 積算電流閾値到達 :U221B(TBD)
     * @brief \~english Accumulated current counter threshold reached :U221B(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_ACCUMELATED_CURRENT_COUNTER_THRESHOLD_REACHED = 0xE21B00,
    /**
     * @brief \~japanese DCM異常挙動 :U21D3(TBD)
     * @brief \~english DCM Abnormal behavior :U21D3(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_DCM_ABNORMAL_BEHAVIOR = 0xE1D300,
    /**
     * @brief \~japanese PLG ECU途絶 :U21D4(TBD)
     * @brief \~english PLG ECU Disrupted :U21D4(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_PLG_DISRUPT = 0xE1D400,
    /**
     * @brief \~japanese ローカルCAN途絶 :U21D5(TBD)
     * @brief \~english Local CAN Disrupted :U21D5(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_LOCAL_CAN_DISRUPT = 0xE1D500,
    /**
     * @brief \~japanese DCM NAD（サーマルシャットダウン） :U21D6(TBD)
     * @brief \~english DCM NAD(Thermal shutdown) :U21D6(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_THERMAL_SHUTDOWN = 0xE1D600,
    /**
     * @brief \~japanese 書き込み失敗 :U2216(TBD)
     * @brief \~english Failure to write :U2216(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_FAILURE_TO_WRITE = 0xE21600,
    /**
     * @brief \~japanese 起動ソフト不整合 :U2217(TBD)
     * @brief \~english Inconsistent startup software :U2217(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_INCONSISTENT_STARTUP_SOFTWARE = 0xE21700,
    /**
     * @brief \~japanese OTAソフト書き換え開始・終了 :U21D7(TBD)
     * @brief \~english OTA software rewriting started/completed :U21D7(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_OTA_SOFTWARE_REWITING_START_COMPLETED = 0xE1D700,
    /**
     * @brief \~japanese NMダイアグ : 過剰ウェイクアップ検出（自ECU内の異常） :U2A16
     * @brief \~english NM diagnostics : Detection of excessive wakeup(Detection in Global-ECU itself) :U2A16
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_EXCESSIVE_BUS_WAKEUP_MYSELF = 0xEA1600,
    /**
     * @brief \~japanese NMダイアグ : スリープNG継続検出（自ECU内の異常） :U2A17
     * @brief \~english NM diagnostics : Detection of Sleep NG continuation(Detection in Global-ECU itself) :U2A17
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_BUS_SLEEP_NG_CONTINUATION_MYSELF = 0xEA1700,
    /**
     * @brief \~japanese NMダイアグ : 過剰ウェイクアップ検出（Ethernet通信バス上の異常ECUの検出） :U2A14
     * @brief \~english NM diagnostics : Detection of excessive wakeup(Detection in Ethernet-ECU) :U2A14
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_EXCESSIVE_BUS_WAKEUP_OTHER_ECU = 0xEA1400,
    /**
     * @brief \~japanese NMダイアグ : スリープNG継続検出（Ethernet通信バス上の異常ECUの検出） :U2A15
     * @brief \~english NM diagnostics : Detection of Sleep NG continuation(Detection in Ethernet-ECU) :U2A15
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_BUS_SLEEP_NG_CONTINUATION_OTHER_ECU = 0xEA1500,
    /**
     * @brief \~japanese スリープダイアグ : 過剰ウェイクアップ検出 :U2A00
     * @brief \~english Sleep diagnostics : Detection of excessive ECU wakeup :U2A00
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_EXCESSIVE_ECU_WAKEUP = 0xEA0000,
    /**
     * @brief \~japanese スリープダイアグ : ECUスリープNG継続検出 :U2A01
     * @brief \~english Sleep diagnostics : Detection of ECU Sleep NG continuation :U2A01
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_ECU_SLEEP_NG_CONTINUATION = 0xEA0100,
    /**
     * @brief \~japanese Wi-Fi通信エラー :U21D8(TBD)
     * @brief \~english Wi-Fi communication error :U21D8(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_ROB_WIFI_COMMUNICATION_ERROR = 0xE1D800,

    /**
     * @brief \~japanese GNSS : GNSS未受信検出 : U0101(TBD)
     * @brief \~english GNSS : Unreceived GNSS signal detected : U0101(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_GNSS_UNRECEIVE = 0xC10100,
    /**
     * @brief \~japanese GNSS : GNSS未受信状態からの復帰 : U0102(TBD)
     * @brief \~english GNSS : Recovery from unreceived GNSS signal  status : U0102(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_GNSS_RECOVERY_FROM_UNRECEIVE = 0xC10200,
    /**
     * @brief \~japanese 衝突検知信号 : 衝突検出 : U0301(TBD)
     * @brief \~english Collision detection signal : Collision detection : U0301(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_COLLISION_DETECT = 0xC30100,
    /**
     * @brief \~japanese NAD電源制御 : 起動失敗 : U0401(TBD)
     * @brief \~english NAD power supply control : Start-up failure : U0401(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_NAD_STARTUP_FAILURE = 0xC40100,
    /**
     * @brief \~japanese NAD電源制御 : 積算電流閾値超過 : U0402(TBD)
     * @brief \~english NAD power supply control : Excessive threshold value of accumulated current : U0402(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_NAD_EXCESSIVE_THRESHOLD_VALUE_OF_ACCUMULATED_CURRENT = 0xC40200,
    /**
     * @brief \~japanese NAD電源制御 : 異常電源OFF検出 : U0403(TBD)
     * @brief \~english NAD power supply control : Abnormal power supply OFF detection : U0402(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_NAD_ABNORMAL_POWER_OFF = 0xC40300,
    /**
     * @brief \~japanese NAD電源制御 : 異常リセット検出 : U0404(TBD)
     * @brief \~english NAD power supply control : Reset abnormality detection : U0404(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_NAD_ABNORMAL_RESET = 0xC40400,
    /**
     * @brief \~japanese NAD電源制御 : 待ち受け完了による電源OFF : U0405(TBD)
     * @brief \~english NAD power supply control : Power off after standby completion : U0405(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_NAD_POWER_OFF_AFTER_STANDBY_COMPLETION = 0xC40500,
    /**
     * @brief \~japanese MQTT : 不正MQTT検出 : U0501(TBD)
     * @brief \~english MQTT : Invalid MQTT detection : U0501(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_MQTT_INVALID = 0xC50100,
    /**
     * @brief \~japanese MQTT : 受信応答の転送エラー検出 : U0502(TBD)
     * @brief \~english MQTT : Forward error detection of received response : U0502(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_MQTT_TRANSMIT_ERROR_OF_RECV_RESP = 0xC50200,
    /**
     * @brief \~japanese MQTT : アプリへの受信MQTTメッセージ転送失敗検出 : U0503(TBD)
     * @brief \~english MQTT : Detect failure to forward receive MQTT messages to the Application : U0503(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_MQTT_FAILURE_FORWARD_RECV_MQTT_MSG_TO_APP = 0xC50300,
    /**
     * @brief \~japanese Provisioning : 重複MQTTメッセージの受信 : U0601(TBD)
     * @brief \~english Provisioning : Receive duplicate MQTT messages : U0601(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_PROV_RECV_DUPLICATE_MQTT_MSG = 0xC60100,
    /**
     * @brief \~japanese Provisioning : 期限切れMQTTメッセージの受信 : U0602(TBD)
     * @brief \~english Provisioning : Receiving Expired MQTT Messages : U0602(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_PROV_RECV_EXPIRED_MQTT_MSG = 0xC60200,
    /**
     * @brief \~japanese Operation support : 重複MQTTメッセージの受信 : U0701(TBD)
     * @brief \~english Operation support : Receive duplicate MQTT messages : U0701(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_OPESUPP_RECV_DUPLICATE_MQTT_MSG = 0xC70100,
    /**
     * @brief \~japanese Operation support : 期限切れMQTTメッセージの受信 : U0702(TBD)
     * @brief \~english Operation support : Receiving Expired MQTT Messages : U0702(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_OPESUPP_RECV_EXPIRED_MQTT_MSG = 0xC70200,
    /**
     * @brief \~japanese 契約機能 : フラグ破損検出 : U5501(TBD)
     * @brief \~english Contract function : Flag corruption detected : U5501(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_CONT_FLAG_CORRUPTION_DETECTED = 0x000006,
    /**
     * @brief \~japanese 契約機能 : フラグ取得成功 : U5510(TBD)
     * @brief \~english Contract function : Successful acquisition of flag : U5510(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_CONT_SUCCESSFUL_ACQUISITION_OF_FLAG = 0x000007,
    /**
     * @brief \~japanese 契約機能 : フラグ取得失敗 : U5511(TBD)
     * @brief \~english Contract function : Failure of flag acquisition : U5511(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_CONT_FAILURE_OF_FLAG_ACQUISITION = 0x000008,
    /**
     * @brief \~japanese 契約機能 : フラグダウンロード結果送信失敗 : U5520(TBD)
     * @brief \~english Contract function : Failure to send flag download result : U5520(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_CONT_FAILURE_TO_SEND_FLAG_DL_RESULT = 0x000009,
    /**
     * @brief \~japanese 緊急通報/ACN/SOS : 音声通話 圏外 : U1101(TBD)
     * @brief \~english Emergency call/ACN/SOS : Voice call out of service area : U1101(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_ECALL_VOICE_CALL_OUT_OF_AREA = 0xD10100,
    /**
     * @brief \~japanese 緊急通報/ACN/SOS : データ通信 圏外 : U1102(TBD)
     * @brief \~english Emergency call/ACN/SOS : Data communication out od service area : U1102(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_ECALL_DATA_COMM_OUT_OF_AREA = 0xD10200,
    /**
     * @brief \~japanese 緊急通報/ACN/SOS : データ通信 センタ無応答 : U1103(TBD)
     * @brief \~english Emergency call/ACN/SOS : No response from Center during data communication : U1103(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_ECALL_DATA_COMM_NO_RESP = 0xD10300,
    /**
     * @brief \~japanese 緊急通報/ACN/SOS : その他要因による緊急通報失敗 : U1104(TBD)
     * @brief \~english Emergency call/ACN/SOS : Emergency call failure due to other factors : U1104(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_ECALL_FAILURE_OTHER_FACTORS = 0xD10400,
    /**
     * @brief \~japanese 自動保守点検 : データ通信 圏外 : U1201(TBD)
     * @brief \~english Automatic maintenance inspection : Data communication out of service area : U1201(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_AMI_DATA_COMM_OUT_OF_AREA = 0xD20100,
    /**
     * @brief \~japanese 自動保守点検 : データ通信 センタ無応答 : U1202(TBD)
     * @brief \~english Automatic maintenance inspection : No response from Center during data communication : U1202(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_AMI_DATA_COMM_NO_RESP = 0xD20200,
    /**
     * @brief \~japanese 自動保守点検 : その他要因による自動保守点検失敗 : U1203(TBD)
     * @brief \~english Automatic maintenance inspection : Automatic maintenance inspection failure due to other factors : U1203(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_AMI_FAILURE_OTHER_FACTORS = 0xD20300,
    /**
     * @brief \~japanese 手動保守点検 : データ通信 圏外 : U1301(TBD)
     * @brief \~english Manual maintenance inspection : Data communication out of service area : U1301(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_MMI_DATA_COMM_OUT_OF_AREA = 0xD30100,
    /**
     * @brief \~japanese 手動保守点検 : データ通信 センタ無応答 : U1302(TBD)
     * @brief \~english Manual maintenance inspection : No response from Center during data communication : U1302(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_MMI_DATA_COMM_NO_RESP = 0xD30200,
    /**
     * @brief \~japanese 手動保守点検 : その他要因による手動保守点検失敗 : U1303(TBD)
     * @brief \~english Manual maintenance inspection : Manual maintenance inspection failure due to other factors : U1303(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_MMI_FAILURE_OTHER_FACTORS = 0xD30300,
    /**
     * @brief \~japanese VLS(TSP) : VLSフラグOFF : U4301(TBD)
     * @brief \~english VLS(TSP) : VLS falg OFF : U4301(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_VLS_FLAG_OFF = 0x00000A,
    /**
     * @brief \~japanese VLS(TSP) : データ通信 圏外 : U4302(TBD)
     * @brief \~english VLS(TSP) : Data communication out of service area : U4302(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_VLS_DATA_COMM_OUT_OF_AREA = 0x00000B,
    /**
     * @brief \~japanese VLS(TSP) : データ通信 センタ無応答 : U4303(TBD)
     * @brief \~english VLS(TSP) : No response from Center during data communication : U4303(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_VLS_DATA_COMM_NO_RESP = 0x00000C,
    /**
     * @brief \~japanese SVT : SVT Reportリトライアウト発生 : U4401(TBD)
     * @brief \~english SVT : Occurrence of SVT Report retry out : U4401(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_SVT_REPORT_RETRY_OUT = 0x00000D,
    /**
     * @brief \~japanese SVT : SVT Start Request上書き発生 : U4402(TBD)
     * @brief \~english SVT : Occurrence of SVT Start Request overwriting : U4402(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_SVT_START_REQ_OVERWRITING = 0x00000E,
    /**
     * @brief \~japanese SVT : SVT Stop Responseリトライアウト発生 : U4403(TBD)
     * @brief \~english SVT : Occurrence of SVT Stop Response retry out : U4403(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_SVT_STOP_RESP_RETRY_OUT = 0x00000F,
    /**
     * @brief \~japanese SVT : 重複MQTTメッセージの受信 : U4404(TBD)
     * @brief \~english SVT : Receive duplicate MQTT messages : U4404(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_SVT_RECV_DUPLICATE_MQTT_MSG = 0x000010,
    /**
     * @brief \~japanese SVT : 期限切れMQTTメッセージの受信 : U4405(TBD)
     * @brief \~english SVT : Receiving Expired MQTT Messages : U4405(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_SVT_RECV_EXPIRED_MQTT_MSG = 0x000011,
    /**
     * @brief \~japanese RVT : RVT Reportリトライアウト発生 : U4501(TBD)
     * @brief \~english RVT : Occurrence of RVT Report retry out : U4501(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_RVT_REPORT_RETRY_OUT = 0x000012,
    /**
     * @brief \~japanese RVT : RVT位置情報取得失敗 : U4502(TBD)
     * @brief \~english RVT : RVT position information acquisition failure : U4502(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_RVT_POSITION_ACQ_FAILURE = 0x000013,
    /**
     * @brief \~japanese Air Data Feed : 圏外による失敗 : U8101(TBD)
     * @brief \~english Air Data Feed : Failure due to out of service area : U8101(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_OUT_OF_AREA = 0x000014,
    /**
     * @brief \~japanese Air Data Feed : 名前解決失敗 : U8102(TBD)
     * @brief \~english Air Data Feed : Failure in name resolution : U8102(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_FAILURE_NAME_RESOLV = 0x000015,
    /**
     * @brief \~japanese Air Data Feed : センタ無応答 : U8103(TBD)
     * @brief \~english Air Data Feed : No response from Center : U8103(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_CENTER_NO_RESP = 0x000016,
    /**
     * @brief \~japanese Air Data Feed : センタ認証失敗 : U8104(TBD)
     * @brief \~english Air Data Feed : Failure of Center authentication : U8104(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_FAILURE_CENTER_AUTH = 0x000017,
    /**
     * @brief \~japanese Air Data Feed : センタ否定応答（成功ではない応答の場合） : U8105(TBD)
     * @brief \~english Air Data Feed : Negative response from Center (response in case of not successful) : U8105(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_NEGATIVE_RESP_FROM_CENTER = 0x000018,
    /**
     * @brief \~japanese Air Data Feed : 重複MQTTメッセージの受信 : U8106(TBD)
     * @brief \~english Air Data Feed : Receive duplicate MQTT messages : U8106(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_RECV_DUPLICATE_MQTT_MSG = 0x000019,
    /**
     * @brief \~japanese Air Data Feed : 期限切れMQTTメッセージの受信 : U8107(TBD)
     * @brief \~english Air Data Feed : Receiving Expired MQTT Messages : U8107(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_RECV_EXPIRED_MQTT_MSG = 0x00001A,
    /**
     * @brief \~japanese APN selection : MNO情報(PLMN or ICCID)読出し失敗 : U8201(TBD)
     * @brief \~english APN selection : Failure to read MNO information (PLMN or ICCID) : U8201(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_APN_FAILURE_READ_INFO = 0x00001B,
    /**
     * @brief \~japanese APN selection : 適切なAPN set不保持 : U8202(TBD)
     * @brief \~english APN selection : Failure to possess proper APN set : U8202(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_APN_FAILURE_APN_SET = 0x00001C,
    /**
     * @brief \~japanese TSCクライアント認証 : eUICC ID読み出し失敗 : U8301(TBD)
     * @brief \~english TSC client authentication : Failure to read eUICC ID : U8301(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_TSCCA_FAILURE_READ_EUICCID = 0x00001D,
    /**
     * @brief \~japanese TSCクライアント認証 : eUICCから不正応答 : U8302(TBD)
     * @brief \~english TSC client authentication : Invalid response from eUICC : U8302(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_TSCCA_INVALID_RESP_FROM_EUICC = 0x00001E,
    /**
     * @brief \~japanese TSCクライアント認証 : センタ無応答 : U8303(TBD)
     * @brief \~english TSC client authentication : No response from Center : U8303(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_TSCCA_CENTER_NO_RESP = 0x00001F,
    /**
     * @brief \~japanese TSCクライアント認証 : センタ認証失敗 : U8304(TBD)
     * @brief \~english TSC client authentication : Failure of Center verification : U8304(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_TSCCA_FAILURE_CENTER_AUTH = 0x000020,
    /**
     * @brief \~japanese TSCクライアント認証 : センタ不正応答（定義外の応答） : U8305(TBD)
     * @brief \~english TSC client authentication : Invalid response of Center (response outside of definition) : U8305(TBD)
     */
    DCMPF_DIAG_DTC_USER_DEF_OPE_TSCCA_INVALID_RESP_FROM_CENTER = 0x000021,

} dcmpf_diag_dtc_user_def_code_t;

/**
 * @brief \~japanese DCM異常検出状態
 * @brief \~english DCM malfunction detection status
 */
typedef enum {
    /**
     * @brief \~japanese 正常
     * @brief \~english Normal
     */
    DCMPF_DIAG_DTC_DCM_NORMAL,
    /**
     * @brief \~japanese 異常
     * @brief \~english Abnormal
     */
    DCMPF_DIAG_DTC_DCM_ABNORMAL,
} dcmpf_diag_dtc_dcm_malfunction_state_t;

/**
 * @brief \~japanese DTC状態: TestFailed
 * @brief \~english DTC Status: TestFailed
 */
#define DCMPF_DIAG_DTC_STATUS_TEST_FAILED (0x01)

/**
 * @brief \~japanese DTC状態: TestFailedThisOperationCycle
 * @brief \~english DTC Status: TestFailedThisOperationCycle
 */
#define DCMPF_DIAG_DTC_STATUS_TEST_FAILED_THIS_OPERATION_CYCLE (0x02)

/**
 * @brief \~japanese DTC状態: PendingDTC
 * @brief \~english DTC Status: PendingDTC
 */
#define DCMPF_DIAG_DTC_STATUS_PENDING_DTC (0x04)

/**
 * @brief \~japanese DTC状態: ConfirmedDTC
 * @brief \~english DTC Status: ConfirmedDTC
 */
#define DCMPF_DIAG_DTC_STATUS_CONFIRMED_DTC (0x08)

/**
 * @brief \~japanese DTC状態: TestNotCompletedSinceLastClear
 * @brief \~english DTC Status: TestNotCompletedSinceLastClear
 */
#define DCMPF_DIAG_DTC_STATUS_TEST_NOT_COMPLETED_SINCE_LAST_CLEAR (0x10)

/**
 * @brief \~japanese DTC状態: TestFailedSinceLastClear
 * @brief \~english DTC Status: TestFailedSinceLastClear
 */
#define DCMPF_DIAG_DTC_STATUS_TEST_FAILED_SINCE_LAST_CLEAR (0x20)

/**
 * @brief \~japanese DTC状態: TestNotCompletedThisOperationCycle
 * @brief \~english DTC Status: TestNotCompletedThisOperationCycle
 */
#define DCMPF_DIAG_DTC_STATUS_TEST_NOT_COMPLETED_THIS_OPERATION_CYCLE (0x40)

/**
 * @brief \~japanese DTC状態: WarningIndicatorRequested
 * @brief \~english DTC Status: WarningIndicatorRequested
 */
#define DCMPF_DIAG_DTC_STATUS_WARNING_INDICATOR_REQUESTED (0x80)

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_DTC_C_H */
