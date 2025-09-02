//  Copyright (c) 1998 - 2020
//  FIS
// $Date:   Aug 25 2021 10:38:20  $ $Revision:   1.35  $

#ifndef CXODRS64_HPP
#define CXODRS64_HPP

namespace mastercardmds
{

 /* @NET_ID_ACQ IN CRS,MAP,MIP */
 /* @DATA_PRIV_ACQ_FMT = 50 */
struct segDATA_PRIV_ACQ
{
   char PROCESS_CODE[6];               // 0000
   char cSetl_Amt_IND;                 // 0006
   char sInf_Len[3];                   // 0007 DE 62
   char sNet_ID[3];                    // 0010 DE 63
   char sTag_Len[3];                   // 0013 DE 48
   char cErr_Code;                     // 0016 DE 48
   char cStat_Code;                    // 0017 DE 48
   char cAVS_RESULT_CD;                // 0018 DE 48
 /* -AcquirerID */
   char sACQ_ICA[11];                  // 0019 DE 32
   char cAd_Rr_Rcvd;                   // 0030
   char sPOS_Entry_Mode[3];            // 0031 DE 22
   char sSetl_Conv_Rate[8];            // 0034 DE 9
   char sAdvice_Reason_Code[3];        // 0042 DE 60
   char sAdvice_Detail_Code[4];        // 0045 DE 60
   char sTran_FEE[9];                  // 0049 DE 28
   char sSetl_FEE[9];                  // 0058 DE 29
   char sProc_FEE[9];                  // 0067 DE 31
 /* -ElectronicCommerceIndicator */
   char sECOM_SECURITY_IND[2];         // 0076 DE 48.42
   char sFiller1[2];                   // 0078
   char sCntryPan[3];                  // 0080
   char sConvDate[4];                  // 0083
   char sFiller3[13];                  // 0087
};

 /* @REF_DATA_ACQ_FMT = 0 */
 /* @DATA_PRIV_ACQ_FMT = 50 */
struct segREF_DATA_ACQ
{
   char sTrace[6];                     // 0000 DE 11
   char sTSTAMP_TRANS[10];             // 0006 DE 7
   char sSettle_Date[4];               // 0016 DE 15
   char cCategory_Code;                // 0020 DE 48
   char cCurrency_prec;                // 0021 DE 33
   char sNETWORK_REF_NO[9];            // 0022 DE 63
 /* -BanknetReferenceNumber */
   char sBanknet_Ref_Num[9];           // 0031 DE 63
 /* -ARN */
   char sARN[23];                      // 0040 DE 63
   char sReceiving_Inst_ID[11];        // 0063 DE 100
   char sOrigSwitchSerialNo[9];        // 0074 DE 48.59
 /* -MasterCardTraceId */
   char sTraceID[13];                  // 0083 DE 48.69
   char sFiller[3];                    // 0096
};

 /* @ADL_DATA_PRIV_ACQ LIKE MD% */
struct segADL_DATA_PRIV_ACQ
{
   char sIdentifier[2];                // 0000 - 'MD'
   char sLength[3];                    // 0002 - '020'
   char sByteMap[8];                   // 0005 - 'E0000000'
   char sMCAssignedId[6];              // 0013 1 48.32
   char cCrossBorderTransaction;       // 0019 2 126  position 14
   char cCrossBorderCurrency;          // 0020 126  position 15
   char cFiller1;                      // 0021 3
   char sFinancialNetworkCode[2];      // 0022 63.1
   char cCARD_PRESENT_IND;             // 0024 61.5
   char cTERM_OPER_ENVI_IND;           // 0025 61.3
 /* -NetworkPosCardholderVerificationCapability */
   char cPOS_TERM_ATTND_IND;           // 0026 61.1
 /* -NetworkPosCardholderPresent */
   char cPOS_CRDH_PRES_IND;            // 0027 61.4
   char cCardActivatedTerminalLevel;   // 0028 61.10
   char cCARD_INP_CAP_IND;             // 0029 61.11
 /* -PosEntryMode */
   char sPOS_ENTRY_MOD[2];             // 0030 22
   char sPaymentTypeIndicator[3];      // 0032 12 48.77
   char sMCAssignedId_old[6];          // 0035 13 48.32
   char cMCHealthcareIIASExemption;    // 0041 14 48.61.3
   char cPOSTranStatusInd;             // 0042 15 61.7
   char cREMOTE_PGM_IND;               // 0043 16 48.48.1
   char sPymtIntChannelDevType[2];     // 0044 17 48.23.1
   char sTRANSIT_TRAN_IND[2];          // 0046 18 48.64.1
   char sTRANSPORT_MODE_IND[2];        // 0048 19 48.64.2
   char cPinlessProgramInd;            // 0050 20 48.81
 /* -AcquirerID */
   char sACQ_ICA[11];                  // 0051 21 32
   char sCARD_ACPT_ID[15];             // 0062 22 42
   char sPPOL_PGM_DATA[3];             // 0077 23 48.26.1
   char sTerminalCompliantIndicator[2];// 0080 24 48.65
   char sMCOnBehalfService[2];         // 0082 25 48.71.1
   char cMCOnBehalfResult1;            // 0084 26 48.71.2
   char cAllPtSurFreeAllianceInd;      // 0085 27 43 sub2
   char sMerchantFraudScore[4];        // 0086 28 112.28
 /* -PaymentFacilitatorID */
   char sPAYMENT_FID[11];              // 0090 29 48.37.1
   char sSALES_ORG_ID[11];             // 0101 30 48.37.2
 /* -SubMerchantID */
   char sMERCHANT_ID[15];              // 0112 31 48.37.3
   char cPersonPresent;                // 0127 33 48.17
   char sAdviceReasonCode[3];          // 0128 34 60.1
   char sAdviceDetailCode[4];          // 0131 35 60.2
 /* -RiskScore */
   char sAssessmentScore[3];           // 0135 36 48.75.1
 /* -RiskReason */
   char sScoreReasonCode[2];           // 0138 37 48.75.2
   char sRulesScore[3];                // 0140 38 48.75.3
   char sRuleReasonCode1[2];           // 0143 39 48.75.4
   char sRuleReasonCode2[2];           // 0145 40 48.75.5
   char sAirlineTicketNo[15];          // 0147 41 48.93
   char cCVC2ValidationProgramInd;     // 0162 42 48.94.1
   char cQPSContactlessChargebackInd;  // 0163 43 48.94.2
   char cMPOSAcceptanceDevice;         // 0164 44 48.21.1
   char sAdditionalTermCapabilityInd[2];// 0165 45 48.21.2
   char sTraceID[15];                  // 0167 46 48.63
   char sMerchantOriginCountry[3];     // 0182 47 48.37.4
   char sMerchantPaymentGatewayID[11]; // 0185 48 48.37.5
   char sDataVerificationType[2];      // 0196 49 108.07.1
   char sTransactionLinkID[22];        // 0198 50 105.1
   char cTransactionStatusInd;         // 0220 51 61.9
   char sFiller[34];                   // 0221
};

 /* @NET_ID_ISS IN CRS,MAP,MIP */
 /* @DATA_PRIV_ISS_FMT = 50 */
struct segDATA_PRIV_ISS
{
   char sNetId[3];                     // 0000
   char sRespCd[2];                    // 0003
   char cErrCd;                        // 0005
   char cStatCode;                     // 0006
   char cCVCCode;                      // 0007
   char sMCCia[11];                    // 0008
   char sPreathAmt[12];                // 0019
   char sErrorElement[3];              // 0031
   char sFiller[66];                   // 0034
};

 /* @REF_DATA_ISS_FMT = 0 */
 /* @DATA_PRIV_ISS_FMT = 50 */
struct segREF_DATA_ISS
{
   char sTraceNbr[6];                  // 0000
   char sTransDt[10];                  // 0006
   char sSettleDate[4];                // 0016
   char sNETWORK_REF_NO[9];            // 0020 DE63
   char sBanknetRef[9];                // 0029
 /* -ARN */
   char sACQ_REF_NO[23];               // 0038
   char sRecvInst[11];                 // 0061
   char sFiller[27];                   // 0072
};

 /* @ADL_DATA_PRIV_ISS LIKE MD% */
struct segADL_DATA_PRIV_ISS
{
   char sIdentifier[2];                // 0000 - 'MD'
   char sLength[3];                    // 0002 - '043'
   char sByteMap[8];                   // 0005 - 'F8000000'
   char sMCAssignedId[6];              // 0013 1 48.32
   char cCrossBorderTransaction;       // 0019 2 DE126s
   char cCrossBorderCurrency;          // 0020 2 DE126
   char cMPIAccoutNumInd;              // 0021 3 48.33.1
   char sMPIAccountNumber[19];         // 0022 4 48.33.2
   char sMPIExpDate[4];                // 0041 5 48.33.3
   char cPersonPresent;                // 0045 6 48.17
   char sSecurityUCAFCollectionInd[3]; // 0046 7 48.42.2
   char cUCAFDowngradeInd;             // 0049 8 48.42.3
   char sProductID[3];                 // 0050 9 DE 126 SE 05
   char sMAC_VALUE[2];                 // 0053 10 48.84
   char cReceiverServiceResponse;      // 0055 11 108.08.01
   char cSenderServiceResponse;        // 0056 12 108.08.02
   char sTransactionLinkID[22];        // 0057 13 105.1
   char sFiller[176];                  // 0079
};

 /* @ADL_DATA_PRIV_ACQ LIKE MG% */
struct segADL_DATA_PRIV_ACQ_MG
{
   char sData_Identifier[2];           // 0000 - 'MG'
   char sData_Len[3];                  // 0002 - '172'
   char sData_Byte_Map[8];             // 0005
   char sBanknetReferenceNumber[9];    // 0013
   char sAirlineTicketNumber[15];      // 0022
   char sAirlinePassengerName[25];     // 0037
   char sAirlineTravelDate[6];         // 0062
   char sAirlineCityOrigin[5];         // 0068
   char sAirlineCityDestination[5];    // 0073
   char sVehicleAgreementNumber[9];    // 0078
   char sVehicleReturnCity[18];        // 0087
   char sArrivalDate[6];               // 0105
   char sFolioNumber[10];              // 0111
   char cCrossBorderTransaction;       // 0121
   char cCrossBorderCurrency;          // 0122
   char sFunctionCode[3];              // 0123
   char sNetworkReferenceID[15];       // 0126
   char sInterchangeRateQualifier[8];  // 0141
   char sAcquirerReferenceNumber[23];  // 0149
   char sFiller[129];                  // 0172
};

}

#endif
