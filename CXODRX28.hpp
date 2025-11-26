//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%62610BB90155.cm preserve=no
//## end module%62610BB90155.cm

//## begin module%62610BB90155.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%62610BB90155.cp

//## Module: CXOSRX28%62610BB90155; Package specification
//## Subsystem: RXDLL%5C47391001FD
//## Source file: C:\Repos\datanavigatorserver\Windows\Build\Dn\Server\Library\Rxdll\CXODRX28.hpp

#ifndef CXOSRX28_h
#define CXOSRX28_h 1

//## begin module%62610BB90155.additionalIncludes preserve=no
//## end module%62610BB90155.additionalIncludes

//## begin module%62610BB90155.includes preserve=yes
//## end module%62610BB90155.includes

#ifndef CXOSDB05_h
#include "CXODDB05.hpp"
#endif
#ifndef CXOSPF34_h
#include "CXODPF34.hpp"
#endif

//## Modelname: DataNavigator Foundation::Configuration_CAT%390F33ED01BC
namespace configuration {
class ConfigurationRepository;
} // namespace configuration

//## Modelname: Connex Library::Reusable_CAT%3453F15C01AA
namespace reusable {
class Token;
class KeyRing;
} // namespace reusable

//## Modelname: Connex Library::IF_CAT%3451F55F009E
namespace IF {
class FlatFile;
class Extract;
} // namespace IF

//## Modelname: Connex Library::Monitor_CAT%3451FA660166
namespace monitor {
class UseCase;
} // namespace monitor

//## Modelname: Connex Library::Timer_CAT%3451F2410231
namespace timer {
class Date;
class Clock;
} // namespace timer

//## Modelname: Connex Library::Process_CAT%3453F1510045
namespace process {
class Application;
} // namespace process

//## Modelname: Connex Library::Database_CAT%3451F34D0218
namespace database {
class ReportFactory;
} // namespace database

//## Modelname: Connex Library::Segment_CAT%3471F0BE0219
namespace segment {
class GenericSegment;

} // namespace segment

//## begin module%62610BB90155.declarations preserve=no
//## end module%62610BB90155.declarations

//## begin module%62610BB90155.additionalDeclarations preserve=yes
//## end module%62610BB90155.additionalDeclarations


//## Modelname: Data Distribution::Report_CAT%5C473883000E
namespace report {
//## begin report%5C473883000E.initialDeclarations preserve=yes
   struct hTCR90_FileHeader
   {
      // record layout for TC90 file header (outgoing CTF)
      char sTransCode[2];       // '90'
      char sProcessingBIN[6];
      char sProcessingDate[5];  // 'DATE_RECON_NET' YYDDD format
      char sFiller1[16];
      char sTestOption[4];      // 'TEST'
      char sFiller2[29];
      char sSecurityCode[8];    // 'SECURITY'
      char sFiller3[6];
      char sOutGoingFileID[3];  // '000'
      char sFiller4[89];
   };

   struct hTC57_TCR0_BatchHeader
   {
      // record layout for TC57 TCR0 Batch Header
      char sTransCode[2];                //0   ----- '57'
      char cTransCodeQualifier;          //2   ----- '0'
      char cTransComponentSeqNumber;     //3 -----   '0'
      char sDestBIN[6];                  //4  ----  use X_GENERIC and configure the Proc_id_iss and find the 6 bytes AIIC
      char sSourceBIN[6];                //10 ---  same value as above
      char sFiller1[6];                  //16
      char sTransactionAmt[12];          //22 ---- zeros
      char sFiller2[3];                  //34
      char cDraftFlag;                   //37  
      char sCentralProcDate[4];          //38  --- DATE_RECON_NET - YDDD format julian
      char sRcdFormatCode[2];            //42  ---- 'DC'
      char cReversalFlag;                //44
      char sAcqInst[11];                 //45  
      char sIssInst[11];                 //56  ----- use X_GENERIC and configure the Proc_id_iss and find the 6 bytes AIIC
      char cFiller3;                     //67
      char sDataCapProcDate[4];          //68  --- DATE_RECON_NET - YDDD format julian
      char sFiller4[2];                  //72
      char sAgent[6];                    //74
      char sChain[6];                    //80
      char sMerchNo[16];                 //86  ------- RPT_LVL_ID_B
      char sTerminalNo[8];               //106  ------ NET_TERM_ID
      char sMerchBatchNo[5];             //110  ------ Need to generate a unique number for each batch
      char sMerchBatchDate[4];           //115  --- DATE_RECON_NET - YDDD format julian
      char sDiscoverMerchID[15];         //119
      char sBatchTransmitTime[6];        //134   ---- current time HHMMSS
      char sTimeZone[3];                 //140   --- 'GMT'
      char sGMTOffset[3];                //143 ---  ' 10'
      char sMerchSecCode[5];             //146
      char sFiller5[2];                  //151
      char sInternalMerchBatchKey[13];   //153  ------ Need to generate a unique number for each batch
      char cRecordType;                  //166  ---- '1'
      char cReimbAttr;                   //167
   };

   struct hTC57_TCR1_BatchHeader
   {
      // record layout for TC57 TCR1 Batch Header 
      char sTransCode[2];                //0    '57'
      char cTransCodeQualifier;          //2    '0'
      char cTransComponentSeqNumber;     //3    '1'
      char sFiller1[12];                 //4
      char cDeviceCode;                  //16   'K'
      char sFiller2[4];                  //17
      char sIntTerminalSerialNo[8];      //21 
      char sMerchCategoryCode[4];        //29    MERCH_TYPE
      char sMerchName[25];               //33    from CARD_ACPT_NAME_LOC
      char sMerchCity[13];               //58    from CARD_ACPT_NAME_LOC
      char sMerchStateCode[3];           //71    from CARD_ACPT_NAME_LOC
      char sMerchCountryCode[3];         //74    from CARD_ACPT_NAME_LOC
      char sMerchZipCode[5];             //77    from CARD_ACPT_NAME_LOC
      char sMerchantCntrySubCode[3];     //82    from CARD_ACPT_REGION
      char cFiller3;                     //85
      char cTransmissionRoute;           //86    'K'
      char sTermLocatorNo[5];            //87  
      char sMerchPostalCode[11];         //      from CARD_ACPT_NAME_LOC
      char sMerchantStreetAddress[50];   //92
      char sInternalMerchBatchKey[13];   //153   Need to generate a unique number for each batch
      char cRecordType;                  //166   '1'
      char cFiller5;                     //167
   };

   struct hTC57_TCR0_TxnDetail
   {
      //  record layout TCR0 - Transaction Detail
      char sTransCode[2];                 // 0    57
      char cTransCodeQualifier;           // 2    0
      char cTransComponentSeqNumber;      // 3    0
      char sDestBIN[6];                   // 4    use X_GENERIC and configure the Proc_id_iss and find the 6 bytes AIIC
      char sSourceBIN[6];                 // 10   use X_GENERIC and configure the Proc_id_iss and find the 6 bytes AIIC
      char cRiskIdentificationInd;        // 16 
      char cMerchTransactionInd;          // 17
      char cVISABaseIITransCodeQualifier; // 18
      char cRecurringPaymentIndicator;    // 19
      char sYearInfoTransactionDate[2];   // 20
      char sTransactionAmt[12];           // 22   AMT_TRAN
      char sTransactionCurrCode[3];       // 34   CUR_RECON_NET
      char cDraftSentFlag;                // 37
      char sCentralProcDate[4];           // 38   DATE_RECON_NET - YDDD format julian
      char sRcdFormatCode[2];             // 42  'DC'
      char cReversalFlag;                 // 44
      char cCATLevelInd;                  // 45   POS = 1, Ecom = 6 (Ipg source),Wallet = 9 (MP_WALLET)
      char cPrepaidCardInd;               // 46   If issuer is VII  place P or. Will have to derive the other options based on testing later -- if not VII ,then space
      char cChipCondCode;                 // 47
      char cCardType;                     // 48   Using the issuer processor and derive this value. Default is V .. Contains the Card Type.
      //      The valid values for this field are : V -> 04 VISA M -> 05 MasterCard S -> 03 Amex N -> 07 Diners R -> 08 Discover J -> 09 JCB U -> 33 UP D -> 20 DINA G -> 12 GIM
      char sAccountNumber[19];            // 49 -- PAN
      char sPurchaseDate[4];              // 68 -- Date from TSTAMP_TRANS
      char sTransactionTimeHHMM[4];       // 72 -- Time from TSTAMP_TRANS
      char cTransactionType;              // 76 -- 5 or 6 are applicable - 5 is the default -- TRAN_TYPE_IND ( use the first two bytes and set the values) -- '5' for message type = '0200': and Transaction Type = '000000'.   '6' for message type = '0200': and Transaction Type = '200000'.
      char cTransactionVoidInd;           // 77 - '0'
      char cCardEntryMethod;              // 78 -- POS_CRD_DAT_IN_CAP
      char cCardholderIDMethod;           // 79 -- POS_CRDHLDR_AUTH
      char sAuthorizationCode[6];         // 80 -- APPROVAL_CODE
      char cAuthorizationSourceCode;      // 86  
      char sFilmLocator[11];              // 87
      char sTipOrCashback[12];            // 98 -- ADL_RQST_AMT40
      char cMOTOorElecCommerceInd;        // 110 -- Term_class -- Indicates transaction performed by mail order, telephone, or electronic commerce.
      // The valid values for this field are 0 – 9; 1 -> Mail / Phone Order(MO / TO) 2 -> Recurring transaction(valid only for U.S.acquired transactions). 3 ->Installment payment. 4 ->Unknown classification / other mail order. 5 ->Secure Electronic Commerce Transaction. 6 ->Non - Authenticated Security Transaction at a 3 - D - Secure - capable merchant, and merchant attempted to authenticate the cardholder using 3 - D secure. 7 -> Non - Authenticated Security Transaction 8 ->Non - secure transaction. 9 ->For optional regional use only.
      char cDebitInd;                     // 111 
      char cResearchCode;                 // 112
      char cNetworkIdentifier;            // 113
      char sFiller1[4];                   // 114
      char sDebitTraceAuditNo[6];         // 118  -- SYS_TRACE_AUDIT_NO
      char cPOSDebitReimbAttr;            // 124  -- F1:TOKEN:ReimburseAttr
      char sDebitTransDate[4];            // 125  -- Date from TSTAMP_TRANS
      char sDebitTransTime[6];            // 129  -- Time from TSTAMP_TRANS
      char sRetrievalRefNo[12];           // 135  -- RETRIEVAL_REF_NO
      char cAVSResponseCode;              // 147
      char cCRBIndicator;                 // 148
      char cAcctType;                     // 149  -- TRAN_TYPE_IND ( uset the 4 and 5th two bytes and set the values)
      char cAuthCharInd;                  // 150
      char sPOSEntryMode[2];              // 151 -- FIN_COLES.POS_ENTRY_MODE
      char sInternalMerchBatchKey[13];    // 153 -- Need to generate a unique number for each batch
      char cRecordType;                   // 166 -- '2'
      char cReimbAttr;                    // 167 -- F1:TOKEN:ReimburseAttr
      char sTransportChannel[2];          // 168
      char sPOSInputMode[3];              // 170 -- POS_ENTRY_MODE
      char sFiller2[2];                   // 173
      char cNumberOfPaymentForms;         // 175 
      char sTransMCC[4];                  // 176 -- MERCH_TYPE
      char sSettlementDate[5];            // 180  --- DATE_RECON_NET
      char sTokenAssurance[2];            // 185 -- F1:TOKEN:TokenAssuranceLevel
      char sTokenRequestorId[11];         // 187 -- F1:TOKEN:TokenRequestID 
      char sAccountRange[19];             // 198  
      char sReasonCode[4];                // 217 -- MSG_RESON_CODE_ISS
      char sPymtFacilitatorId[8];         // 221
      char sCrdHldrBillCurrCode[3];       // 229 -- CUR_CARD_BILL
      char sExpiryDate[4];                // 232 YYMM -- DATE_EXP
      char sCardSeqNo[3];                 // 236
      char sTranTimeInSeconds[6];         // 239 HHMMSS -- Tran time from TSTAMP_TRANS
      char sForeignRetailInd[3];          // 245
      char sSubMerchantID[15];            // 248
      char sRupayPOSEntryMode[3];         // 263
      char sRupayPOSCondCode[2];          // 266
      char sRupayPOSDataCode[41];         // 268
      char cSRV_GRP_INTCHG_IND;           // 309
      char sSRV_GRP_SERV_CODE[2];         // 310
      char sActionCode[2];                // 312
      char sInternalTrackingNo[20];       // 314
      char sCaseNo[14];                   // 334
      char cFullOrPartInd;                // 348
      char sControlNo[15];                // 349
      char sAdditionalAmount[12];         // 364
      char sUID[12];                      // 376
      char sChIncomeTaxPAN[10];           // 388
      char sAdditionalData[256];          // 398
      char sAdditionalTxnData[16];        // 654
      char cPersistentFxInd;              // 670
      char sRateTableId[5];               // 671
      char sCapReqMsgInd[2];              // 676
      char sPOSCondCode[2];               // 678
      char sMemberMsgText[50];            // 680
      char sNationalReimbFee[12];         // 730
      char cAdditionalTknRespInfo;        // 742
      char sCommChoicePrgm[4];            // 743
      char sSettleAmtUSD[12];             // 747
      char sUniqueId[36];                 // 759
      char cResubmitInd;                  // 795
      char sGatewayID[2];                 // 796
      char csettlementFlag;               // 798
      char sSettlementInfo[29];           // 799
   };

   struct hTC57_TCR1_TxnDetail_Common
   {
      //  record layout TCR1 - Transaction Detail - Common Data Addendum
      char sTransCode[2];                 // 0   57
      char cTransCodeQualifier;           // 2   0
      char cTransComponentSeqNumber;      // 3   1
      char sFiller1[12];                  // 4 
      char sFormatCode[2];                // 16
      char sDynamicDescriptor[25];        // 18
      char sCustomerServicePhoneNum[13];  // 43
      char sFiller2[110];                 // 56
      char cRecordType;                   // 166
      char cReimbursementAttribute;       // 167
      char cCardAcceptorId;               // 168
   };

   struct hTC57_TCR99_Coles
   {
      // record layout for TC57 TCR99 Coles Entry
      char sTransCode[2];                 // 0    57
      char cTransCodeQualifier;           // 2    9
      char sTransComponentSeqNumber[3];   // 3    9B1
      char sMaskedPan[19];                // 6
      char sTermClass[2];                 // 25
      char sCardProduct[20];              // 27
      char cCardLocation;                 // 47
      char sTRID[11];                     // 48
      char sRespCode[3];                  // 59
      char sAcqMerchantBrand[20];         // 62
      char sProcessingType[2];            // 82
      char sTranNumber[18];               // 84
      char cWalletInd;                    // 102
      char sMappedDupData[30];            // 103
      char sDNTxnLink[50];                // 133
      char sHashPan1[40];                 // 183
      char sHashPan2[40];                 // 223
      char sDATE_RECON_ACQ[8];            // 263
      char sDATE_RECON_ISS[8];            // 271
      char sISFCCode[12];                 // 279
      char sInternalMerchBatchKey[13];    // 291
      char cRecordType;                   // 304
      // 305
   };

   struct hTC57_TCR0_BatchTrailer
   {
      // record layout for TC57 TCR0 Batch Trailer
      char sTransCode[2];                 // 0    57
      char cTransCodeQualifier;           // 2    0
      char cTransComponentSeqNumber;      // 3    0
      char sDestBIN[6];                   // 4
      char sSourceBIN[6];                 // 10
      char sFiller1[21];                  // 16
      char cDraftFlag;                    // 37   'N'
      char sCentralProcDate[4];           // 38   DATE_RECON_NET - YDDD format julian
      char sRcdFormatCode[2];             // 42   'DC'
      char cReversalFlag;                 // 44
      char sFiller2[23];                  // 45
      char sBatchTransactionCount[7];     // 68
      char sBatchNetAmt[15];              // 75
      char sBatchNetAmtSign[2];           // 90
      char sBatchRcdCountTCR[7];          // 92
      char sBatchGrossAmt[15];            // 99
      char sSecondaryAmt[16];             // 114
      char sFiller3[23];                  // 130
      char sInternalMerchBatchKey[13];    // 153
      char cRecordType;                   // 166
      char cReimbAttr;                    // 167
   };

   struct hTCR91_BatchTrailer
   {
      // record layout for TC91 Batch Trailer
      char sTransCode[2];                 // 0    91
      char cTransCodeQualifier;           // 2    0
      char cTransComponentSeqNumber;      // 3    0
      char sBIN[6];                       // 4
      char cDecade;                       // 10
      char sProcessingDate[4];            // 11
      char sDestinationAmount[15];        // 15
      char sNumMonetaryTrans[12];         // 30
      char sBatchNumber[6];               // 42
      char sNumTCRs[12];                  // 48
      char sFiller1[6];                   // 60
      char sCentreBatchID[8];             // 66
      char sNumTrans[9];                  // 74
      char sFiller2[18];                  // 83
      char sSourceAmount[15];             // 101
      char sFiller3[52];                  // 116
   };

   // TC 92 File Trailer

   struct hTCR92_FileTrailer
   {
      // Record Layout for TC 92 File Trailer
      char sTransCode[2];                 // 0    92
      char cTransCodeQualifier;           // 2    0
      char cTransComponentSeqNumber;      // 3    0
      char sBIN[6];                       // 4
      char cDecade;                       // 10
      char sProcessingDate[4];            // 11
      char sDestinationAmount[15];        // 15
      char sNumMonetaryTrans[12];         // 30
      char sBatchNumber[6];               // 42
      char sNumTCRs[12];                  // 48
      char sFiller1[6];                   // 60
      char sCentreBatchID[8];             // 66
      char sNumTrans[9];                  // 74
      char sFiller2[18];                  // 83
      char sSourceAmount[15];             // 101
      char sFiller3[52];                  // 116
   };

   struct hTC57_TCR7_Chip
   {
      // record layout for TC57 - TCR7 - Chip Card Transaction data
      char sTransCode[2];                 // 0    57
      char cTransCodeQualifier;           // 2    0
      char cTransComponentSeqNumber;      // 3    7
      char sTransactionType[2];           // 4
      char sCardSeqNumber[3];             // 6
      char sTermTranDate[6];              // 9
      char sTermCapProf[6];               // 15
      char sTermCountryCode[3];           // 21
      char sTermSerialNo[8];              // 24
      char sUnpredictableNumber[8];       // 32
      char sApplTranCounter[4];           // 40
      char sApplIntrProf[4];              // 44
      char sCryptogram[16];               // 48
      char sIssrApplData1[4];             // 64
      char sTermVerResults[10];           // 68
      char sIssrApplData2[8];             // 78
      char sCryptogramAmt[12];            // 86
      char sIssrApplData3[22];            // 98
      char sFiller1[23];                  // 120
      char sIssrScript1Results[10];       // 143
      char sInternalMerchBatchKey[13];    // 153
      char cRecordType;                   // 166
      char cFiller2;                      // 167
   };

   struct hTC57_TCR7_ChipExt
   {
      // record layout for TC57 - TCR7 - Extension Chip Card Transaction data
      char sTransCode[2];                 // 0    57
      char cTransCodeQualifier;           // 2    0
      char cTransComponentSeqNumber;      // 3    7
      char sIssuerAppData[64];            // 4
      char sCryptoInfoData[2];            // 68
      char sFormFactorInd[8];             // 70
      char cAppPanSeqNum;                 // 78
      char sThirdPartyData[32];           // 79
      char sFiller[42];                   // 111
      char sInternalMerchBatchKey[13];    // 153
      char cRecordType;                   // 166
      char cExtensionFlag;                // 167
      char sAppSelectionRegProgData[255]; // 168
   };

   struct hTC57_TCR7_Chip_All
   {
      // record layout for TC57 - TCR7 - MC Chip Card Transaction data
      char sTransCode[2];                 // 0    57
      char cTransCodeQualifier;           // 2    0
      char cTransComponentSeqNumber;      // 3    7
      char sAddendsTypeCode[2];           // 4
      char sAPPL_INTRCHG_PROF[4];         // 6
      char sAPPL_TRAN_COUNTER[4];         // 10
      char sAPPL_CRYPTOGRAM[16];          // 14
      char sAuthorizationAmount[12];      // 30
      char sCRYPT_INFO_DATA[2];           // 42
      char sTERM_COUNTRY_CODE[3];         // 44
      char sTERM_CAPABILITIES[6];         // 47
      char sTERMINAL_TYPE[2];             // 53
      char sTERM_VERIFY_RESULT[10];       // 55
      char sTRAN_DATE[6];                 // 65
      char sTRAN_TYPE[2];                 // 71
      char sTRAN_CURRENCY_CODE[3];        // 73
      char sAMOUNT_OTHER[12];             // 76
      char sISS_APPL_DATA[64];            // 88
      char sUNPREDICTABLE_NO[8];          // 152
      char sCARDH_VER_RESULT[6];          // 160
      char sDEDICATED_FILE_NAM[32];       // 166
      char sAPPL_VERSION_NO[4];           // 198
      char sTERM_SERIAL_NO[16];           // 202
      char sTRAN_SEQ_COUNTER[8];          // 218
      char cAppPanSeqNum;                 // 226
      char sThirdPartyData[32];           // 227
      char sAppSelectionRegProgDatap[255];// 259
      char sCardSeqNo[3];                 // 514
      char sPARTNER_DISCRETIONARY[32];    // 517
      char sTRAN_CATEGORY_CODE[4];        // 549
      char sISS_AUTH_DATA[32];            // 553
      char sCRYPTOGRAM_AMOUNT[12];        // 585
      char sIssrScript1Results[10];       // 597
      char sFormFactorInd[8];             // 607
      char sAPPL_ID[32];                  // 615
      char sApplUsageControl[4];          // 647
      char sISSUER_SCRIPT_RESULTS1[42];   // 651
      char cISSUER_SCRIPT_RESULTS2;       // 693  
   };
   struct hTC57_TCR5_TxnDetail_MC
   {
      //  record layout TCR5 - Transaction Detail
      char sTransCode[2];                 //0000  //    57
      char cTransCodeQualifier;           //0002  //    0 
      char cTransComponentSeqNumber;      //0003  //    5
      char sFiller1[11];                  //0004
      char sBanknetSettlementNumber[9];   //0015  //DE63,s2
      char sBanknetSettlementDate[4];     //0024  //DE63,s3
      char sValidationCode[4];            //0028
      char sUcafEcsLvlInd[3];             //0032  // DE48,s42.1
      char sTxnCategoryIndicator[2];      //0035
      char sProgramRegistrationId[3];     //0037 
      char sAuthorizationAmount[12];      //0040
      char cSrvGrpIntchgInd;              //0052  // DE40
      char sSrvGrpServCode[2];            //0053
      char cCardDataInputCap;             //0055  // DE22,s1
      char cCardholderAuthCap;            //0056  // DE22,s2
      char cCardCaptureCap;               //0057  // DE22,s3
      char cTerminalOperEnv;              //0058  // DE22,s4
      char cCardholderPresentData;        //0059  // DE22,s5
      char cCardPresentData;              //0060  // DE22,s6
      char cCardDataInputMode;            //0061  // DE22,s7
      char cCardholderAuthMeth;           //0062  // DE22,s8
      char cCardholderAuthEntity;         //0063  // DE22,s9
      char cCardDataOutCap;               //0064  // DE22,s10
      char cTerminalDataOutCap;           //0065  // DE22,s11
      char cPINCaptureCap;                //0066  // DE22,s12
      char sFiller2[17];                  //0067
      char sMastercardAssignedId[6];      //0084
      char cRemotePaymentProgData;        //0090
      char sTransitTranTypeInd[2];        //0091
      char sTransportModeInd[2];          //0093
      char sPPOLProgData[3];              //0095
      char sFiller3[42];                  //0098
      char sBusinessActIntRateDes[2];     //0140
      char sRiskManagementAppCode[11];    //0142
      char sInternalMerchBatchKey[13];    //0153
      char cRecordType;                   //0166
      char cReimbAttr;                    //0167
      char sAdditionalAmountType[2];      //0168
      char sAdditionalAmount[12];         //0170
      char sAdditionalAmountCur[3];       //0182
      char sAdditionalAmountType1[2];     //0185
      char sAdditionalAmount1[12];        //0187
      char sAdditionalAmountCur1[3];      //0199
      char sAdditionalAmountType2[2];     //0202
      char sAdditionalAmount2[12];        //0204
      char sAdditionalAmountCur2[3];      //0216
      char sAdditionalAmountType3[2];     //0219
      char sAdditionalAmount3[12];        //0221
      char sAdditionalAmountCur3[3];      //0233
      char sAdditionalAmountType4[2];     //0236
      char sAdditionalAmount4[12];        //0238
      char sAdditionalAmountCur4[3];      //0250
      char sAdditionalAmountType5[2];     //0253
      char sAdditionalAmount5[12];        //0255
      char sAdditionalAmountCur5[3];      //0267
      char sTypeOfInstallment[2];         //0270
      char sNumInstallments[2];           //0272
      char sInterestRate[5];              //0274
      char sFirstInstallmentAmt[12];      //0279
      char sNextInstallmentAmt[12];       //0291
      char cTLEComplaint;                 //0303
      char cUKPTCompliant;                //0304
      char sPaymentFacilitatorID[11];     //0305
      char sSubMerchantID[15];            //0316
      char sIndependentSalesOrgID[11];    //0331
      char sAnnualPercentRate[5];         //0342
      char sInstallmentFee[12];           //0347
      char sTransitIntClass[2];           //0359
      char sFiller4[3];                   //0361
      char sFiller5[12];                  //0364
      char sPostServiceCode[2];           //0376
      char cNumofInstallment;             //0378
      char cGuarantee;                    //0379
      char sGuaranteeAmt[8];              //0380
      char sPostSettlementDate[6];        //0388
      char sOrigAuthReqDate[6];           //0394
      char sOrigBanknetRefNum[9];         //0400
      char sAuthorizationCode[6];         //0409
      char sATMServiceFee[12];            //0415
      char sFundingSource[2];             //0427
      char sSenderAcctNum[34];            //0429
      char sAuthCurrencyCode[3];          //0463
      char sCommissionRate[5];            //0466
      char cCommissionSign;               //0471
      char sCommisionAmt[12];             //0472
      char sDigitalAcctRefNum[19];        //0484
      char sDirectoryServerTranId[36];    //0503
      char sAcctHolderAuthValue[32];      //0539
      char cProgramProtocol;              //0571
      char cMposAcceptDeviceType;         //0572
      char sMCPassQRRecvAcctNum[34];      //0573
      char sQRDynamicCodData[237];        //0607
      char sAdditionalTraceNum[19];       //0844
      char cTrasactionTypeInd;            //0863
      char cAdditionalTermOperEnv;        //0864
      char sCustomerCode[25];             //0865
      char sPromotionCode[6];             //0890
      char sDomesticMerchantTaxId[11];    //0896
      char sFiller6[2];                   //0907
      char sCountryOfOrigin[3];           //0909
      char sFiller7[13];                  //0912
      char sCitMitCategory[2];            //0925
      char sCitMitSubcategory[2];         //0927
      char sALMServiceCode[5];            //0929
      char sALMProductCode[3];            //0934
      char sALMProductClass[3];           //0937
      char sALMRateType[3];               //0940
      char cALMDataSource;                //0943
      char sMobilePhoneNumber[17];        //0944
      char sMobilePhoneSrvProvider[30];   //0961
      char sDeviceTypeIndicator[2];       //0991  //DE48 S23.1
      char sBrzMerchTaxId[14];            //0993
      char sMcAssIncInd[3];               //1007
      char cRecPayManType;                //1010
      char cRecPayTrxType;                //1011
      char cValidationFlag;               //1012
      char sMaxRecPayAmt[10];             //1013
      char sRegTrxIdn[10];                //1023
      char sNoRecPay[2];                  //1033
      char cRecPayFreq;                   //1035
      char sServiceLocCity[13];           //1036
      char sServiceLocCountrySubCode[3];  //1049
      char sServiceLocCountryCode[3];     //1052
      char sServiceLocPostalCode[10];     //1055
      char sPartnerIDCode[6];             //1065
      char sTransactionLinkID[22];        //1071
      char sGovtSubsidyProgram[2];        //1093
      char sAccptGeoCoordinate[20];       //1095
      char sServLocGeoCoordinate[20];     //1115
      char sJapanCMC[4];                  //1135
      char sFlexCode[3];                  //1139
      char cVDCUTokUpdateInd;             //1142
      char cDigcomident;                  //1143
      char cDigcomprotype;                //1144
      char sDigcometype[15];              //1145
      char sDigcomchkmtd[40];             //1160
      char cMasOneCredExcInd;             //1200
      char sMasOneCredAcceBrand[3];       //1201
      char cMasOneCredIntchgInd;          //1204
      char sMasOneCredIssAcctRnge[19];    //1205
   };

   struct hTC57_TCR4_TxnDetail_VISA
   {
      // record layout for TC57 - TCR4 - SMS data
      char sTransCode[2];                     // 0   57
      char cTransCodeQualifier;               // 2   0
      char cTransComponentSeqNumber;          // 3   4
      char sAgentUniqueData[5];               // 4
      char sFiller1[7];                       // 9
      char sBusinessFormatCode[2];            // 16
      char sDebitProductCode[4];              // 18
      char sContactForInformation[25];        // 22
      char cAdjustmentProcessingIndicator;    // 47
      char sMessageReasonCode[4];             // 48
      char sSurchargeAmount[8];               // 52
      char sSurchargeCreditDebitIndicator[2]; // 60
      char sFiller2[16];                      // 62
      char sSurchargeBillingAmount[8];        // 78
      char sForeignExchangeFee[8];            // 86
      char sPaymentAccountReference[29];      // 94
      char sTokenRequestorId[11];             // 123
      char sFiller3[32];                      // 134
      char cRecordType;                       // 166
      char cFiller;                           // 167
      // 168
   };

   struct hTC57_TCR99_CustomRecord
   {
      // record layout for TC57 TCR99 Custom Entry
      char sTransCode[2];                 // 0    57
      char cTransCodeQualifier;           // 2    9
      char sTransComponentSeqNumber[3];   // 3    9B1
      char sMaskedPan[19];                // 6
      char sTERM_CLASS[2];                // 25
      char sProcessingType[2];            // 27
      char sACT_CODE[3];                  // 29
      char sWLT_ID[3];                    // 32
      char sIsfcCode[12];                 // 35
      char cChannelInd;                   // 47
      char sDATE_RECON_ACQ[8];            // 48
      char sDATE_RECON_ISS[8];            // 56
      char cChargeType;                   // 64
      char sTxnIndustryApplInfo[2];       // 65
      char sTgiReference[36];             // 67
      char sOrigTxnCode[3];               // 103
      char sOrigTxnDateTime[10];          // 106
      char sOrigIssStan[6];               // 116
      char sOrigIssRRN[12];               // 122
      char sOrigAuthSettDate[4];          // 134
      char sOrigFiller[5];                // 138
      char sCOFInd[2];                    // 143
      char sAltPymtMeth[2];               // 145
      char cLCRIndicator;                 // 147
      char sOriginalUUID[36];             // 148
      char sGroupUUID[36];                // 184
      char sMerchantWebsiteURL[99];       // 220
      char cOnUsBinIND;                   // 319
      char sFraudSubClassCode[2];         // 320
      char sTransactionAcceptMethod[2];   // 322
      char sCardholderAuthValue[20];      // 324
      char sEMV_3D_TRAN_ID[36];           // 344
   };

   struct hTC57_TCR3_TxnDetail_PSD
   {
      char sTransCode[2];                 // 0    57
      char cTransCodeQualifier;           // 2    0
      char cTransComponentSeqNumber;      // 3    3
      char sAuthRespCode[2];              // 4
      char sAuthAmount[12];               // 6
      char sTransactionId[15];            // 18
      char sValidationCode[4];            // 33
      char sMULTI_CLEAR_SEQ_NO[2];        // 37
      char sMULTI_CLEAR_COUNT[2];         // 39
      char cMarketSpecificAuthDataId;     // 41
      char sTotalAuthAmount[12];          // 42
      char cSubmittedAuthCharInd;         // 54
      char sMOTOCustServPhNo[11];         // 55
      char cMOTOCustServPhFlg;            // 66
      char sMOTOInstlSeqNo[2];            // 67
      char sMOTOInstlSeqCnt[2];           // 69
      char sECommerceGoodsInd[2];         // 71
      char sRewardsPrgmId[6];             // 73
      char sCardLevelResults[2];          // 79
      char cCVV2ResultCode;               // 81
      char cDCCInd;                       // 82
      char sAccountTypeInd[4];            // 83
      char sFiller1[2];                   // 87
      char cRegulatedInd;                 // 89
      char sFiller2[46];                  // 90
      char sCUR_RECON_NET[3];             // 136
      char sFeePrgmInd[3];                // 139
      char cRequestedPaymentServ;         // 142
      char sMerchVerVal[10];              // 143
      char sInternalMerchBatchKey[13];    // 153
      char cRecordType;                   // 166
      char cSpendQualInd;                 // 167
      char sMerchVolInd[2];               // 168
   };

   struct hTC57_TCR2_AmexCAPNBatchHeader
   {
      char sTransCode[2];                 // 0    57
      char cTransCodeQualifier;           // 2    0
      char cTransComponentSeqNumber;      // 3    2
      char sIndustryCode[2];              // 4
      char sSubIndustryCode[3];           // 6
      char sFiller1[7];                   // 9
      char sCARD_ACPT_ID[15];             // 16
      char sSubmitterID[11];              // 31
      char sFiller2[124];                 // 42
      char cRecordType;                   // 166
      char cCAPNIndicator;                // 167
   };

   struct hTC57_TCR1_AmexTxnDetailAdviceBasic
   {
      char sTransCode[2];                 // 0    57
      char cTransCodeQualifier;           // 2    0
      char cTransComponentSeqNumber;      // 3    1
      char sFiller1[12];                  // 4
      char sFormatCode[2];                // 16
      char sExtendedPaymentData[2];       // 18
      char sDATE_EXP[4];                  // 20
      char sMediaCode[2];                 // 24
      char sFiller2[7];                   // 26
      char sTransactionIdentifier[15];    // 33
      char cCardDataInputCap;             // 48
      char cCardholderAuthCap;            // 49
      char cPOS_CARD_CAPT_CAP;            // 50
      char cTerminalOperEnv;              // 51
      char cCardholderPresentData;        // 52
      char cCardPresentData;              // 53
      char cCardDataInputMode;            // 54
      char cCardholderAuthMeth;           // 55
      char cCardholderAuthEntity;         // 56
      char cCardDataOutCap;               // 57
      char cPOS_TERM_OUT_CAP;             // 58
      char cPINCaptureCap;                // 59
      char sSubmissionMethod[2];          // 60
      char sCARD_ACPT_ID[15];             // 62
      char sMerchantContactInfo[40];      // 77
      char sRETRIEVAL_REF_NO[30];         // 117
      char sSpecialProgramCode[2];        // 147
      char sFiller3[4];                   // 149
      char sInternalMerchBatchKey[13];    // 153
      char cRecordType;                   // 166
      char cCAPNIndicator;                // 167
      char sTABImageSeqNo[8];             // 168
      char sMatchingKeyType[2];           // 176
      char sMatchingKey[21];              // 178
      char sElectronicCommenceInd[2];     // 199
      char cIndModelTypeInd;              // 201
   };

   struct hTC57_TCR4_AmexTxnDetailLocation
   {
      char sTransCode[2];                 // 0    57
      char cTransCodeQualifier;           // 2    0
      char cTransComponentSeqNumber;      // 3    4
      char sFiller1[12];                  // 4
      char sFormatCode[2];                // 16
      char sAddendaTypeCode[2];           // 18
      char sLocationName[38];             // 20
      char sLocationAddress[38];          // 58
      char sLocationCity[21];             // 96
      char sCARD_ACPT_REGION[3];          // 117
      char sCARD_ACPT_COUNTRY[3];         // 120
      char sCARD_ACPT_PST_CODE[15];       // 123
      char sMERCH_TYPE[4];                // 138
      char sSellerID[20];                 // 142
      char sFiller2[10];                  // 162
   };

   struct hTC57_TCR1_DinersIntlChargeDetailRecord
   {
      char sTransCode[2];                 // 0    57
      char cTransCodeQualifier;           // 2    0
      char cTransComponentSeqNumber;      // 3    1
      char sDinersIndicator[2];           // 4
      char sTypeOfCharge[2];              // 6
      char sChargeType[3];                // 8
      char sFiller[8];                    // 11
      char sTax1Amount[15];               // 19
      char sTax2Amount[15];               // 34
      char sOriginalTicketNumber[15];     // 49
      char sCustReferenceNumber1[30];     // 64
      char sCustReferenceNumber2[30];     // 94
      char sCustReferenceNumber3[30];     // 124
      char sCustReferenceNumber4[30];     // 154
      char sCustReferenceNumber5[30];     // 184
      char sCustReferenceNumber6[30];     // 214
      char cECommPaymentIndicator;        // 244
      char sCAVVValue[4];                 // 245
      char sNetworkReferenceID[15];       // 249
      char sACT_CODE[3];                  // 264
      char cPOS_CRDHLDR_PRESNT;           // 267
      char cPOS_CARD_PRES;                // 268
      char cPOS_CRD_DAT_IN_MOD;           // 269
      char cPOS_CRD_DAT_IN_CAP;           // 270
      char sSurchargeAmount[8];           // 271
      char sCAVVValidationResult[2];      // 279
      char cAuthenticationDataType;       // 281
      char sProtectBuyAuthResult[2];      // 282
      char sSecondFactorAuthResCde[2];    // 284
      char sCAVVIndicator[2];             // 286
      char sAuthTrackingNumber[16];       // 288
      char sVersionAndAuthAction[2];      // 304
      char sIPAddressInHexFormat[8];      // 306
      char sSCAExemptionInd[2];           // 314
      char sTransactionIndicator;         // 316
      char sOrigNetworkReferenceID[15];   // 317
      char sSettlementCurrency[3];        // 332
   };

   struct hTC57_TCR3_DinersIntlChipAddtlRecord
   {
      char sTransCode[2];                 // 0    57
      char cTransCodeQualifier;           // 2    0
      char cTransComponentSeqNumber;      // 3    3
      char sFunctionCode[2];              // 4
      char sSendingInstIdCode[3];         // 6
      char sRecapNumber[3];               // 9
      char sReceivingInstIdNumber[2];     // 12
      char sBatchNumber[3];               // 14
      char sSeqNoWithInBatch[3];          // 17
      char sSubSeqNoWithInCharge[3];      // 20
      char sCARD_SEQ_NO[3];               // 23
      char sAPPL_ID[32];                  // 26
      char sAPPL_INTRCHG_PROF[4];         // 58
      char sAPPL_TRAN_COUNTER[4];         // 62
      char sAPPL_CRYPTOGRAM[16];          // 66
      char sApplUsageControl[4];          // 82
      char sCRYPTOGRAM_AMOUNT[12];        // 86
      char sAMOUNT_OTHER[12];             // 98
      char sCRYPT_INFO_DATA[2];           // 110
      char sCARDH_VER_RESULT[6];          // 112
      char sDEDICATED_FILE_NAM[32];       // 118
      char sTERM_SERIAL_NO[8];            // 150
      char sISS_APPL_DATA[64];            // 158
      char sISS_AUTH_DATA[32];            // 222
      char sISS_SCRIPT_RESULT[50];        // 254
      char sTERM_COUNTRY_CODE[3];         // 304
      char sAPPL_VERSION_NO[4];           // 307
      char sTERM_CAPABILITIES[6];         // 311
      char sTERMINAL_TYPE[2];             // 317
      char sTERM_VERIFY_RESULT[10];       // 319
      char sTRAN_DATE[6];                 // 329
      char sTRAN_TYPE[2];                 // 335
      char sTRAN_CURRENCY_CODE[3];        // 337
      char sUNPREDICTABLE_NO[8];          // 340
   };

   struct hTC57_TCR5_TxnDetail_MC_Ext
   {
      char sFiller1[121];
   };

   struct hTC57_TCR4_PaymentTransaction0_MC
   {
      // record layout for TC 57 - TCR 4 - MasterCard Transaction - Payment Transaction 0 for MasterCard
      char sTransCode[2];                 // 0   '57' 
      char cTransCodeQualifier;           // 2   '0'
      char cTransComponentSeqNumber;      // 3   '4'
      char sReserved1[12];                // 4
      char sBusinessFormatCode[2];        // 16  'P0'
      char sReserved2[96];                // 18
      char sFundRequestDate[6];           // 114 FIN_L.TSTAMP_LOCAL
      char sReserved3[217];               // 120
   };

   struct hTC57_TCR4_PaymentTransaction1_MC
   {
      // record layout for TC 57 - TCR 4 - MasterCard Transaction - Payment Transaction 1 for MasterCard
      char sTransCode[2];                 // 0   '57' 
      char cTransCodeQualifier;           // 2   '0'
      char cTransComponentSeqNumber;      // 3   '4'
      char sReserved1[12];                // 4
      char sBusinessFormatCode[2];        // 16  'P1'
      char sAdditionalTraceRefNum[19];    // 18   SEG24 Token 527 tag R1
      char sAdditionalTxnDescData[15];    // 37
      char sReserved2[114];               // 52
      char cRecordType;                   // 166  '2'
      char cReserved3;                    // 167
   };

   struct hTC57_TCR3_BusAppDetails_Visa
   {
      // record layout for TC 57 - TCR 3 - Transaction Details – Business Application Details - Visa
      char sTransCode[2];                 // 0   '57'
      char cTransCodeQualifier;           // 2   '1' 
      char cTransComponentSeqNumber;      // 3   '3'
      char sServiceProcessingType[2];     // 4   '00'
      char sReserved1[9];                 // 6
      char cFastFundsIndicator;           // 15
      char sBusinessFormatCode[2];        // 16  'CR'
      char sBusinessAppId[2];             // 18  (VE%)ADL_DATA_PRIV_ACQ->sBusinessApplicationID  value 'FT'
      char cSourceOfFunds;                // 20  '3'
      char sPaymentReversalReason[2];     // 21
      char sSenderRefNumber[16];          // 23
      char sSenderAccountNumber[34];      // 39
      char sSenderName[30];               // 73
      char sSenderAddress[35];            // 103
      char sSenderCity[25];               // 138
      char sSenderState[2];               // 163
      char sSenderCountry[3];             // 165
   };

   struct hTC57_TCR97_CommonMerchantData
   {
       // record layout for TC 57 - TCR 97 - Common Merchant Data Record
       char sTransCode[2];                 // 0   '57'
       char sTransCodeQualifier[2];        // 2   '97'
       char sFormatCode[2];                // 4   'CM'
       char sCardAcceptorId[16];           // 6    FIN_L.RPT_LVL_ID_B
       char sMerchantName[25];             // 22   FIN_RECORD.CARD_ACPT_NAME_LOC.substr(0,25) 
       char sMerchantCity[13];             // 47   FIN_RECORD.CARD_ACPT_NAME_LOC.substr(55,13);
       char sMerchantStateCode[3];         // 60   FIN_RECORD.CARD_ACPT_REGION
       char sMerchantCountryCode[3];       // 63   FIN_RECORD.CARD_ACPT_COUNTRY
       char sMerchantCntryCdNum[3];        // 66 
       char sMerchantZipCode[16];          // 69   FIN_RECORD.CARD_ACPT_PST_CODE
       char sMerchantStreetNum[50];        // 85   FIN_RECORD.CARD_ACPT_NAME_LOC.substr(26,29);
       char sStoreTerminalNum[8];          // 135  FIN_L.CARD_ACPT_TERM_ID
       char sMerchantCategoryCode[4];      // 143  FIN_RECORD.MERCH_TYPE
       char cIncorpStatusCode;             // 147
       char sMerchantRefNum[25];           // 148
       char sMerchantEmail[60];            // 173
       char sMerchantTaxID[20];            // 233
       char sSolePropLastName[30];         // 253
       char sSolePropFirstName[25];        // 283
       char cSolePropMiddleInit;           // 308
       char cGovtCtrlMerchant;             // 309
       char cCustomerNegoMerch;            // 310
       char sMerchantCurrCd[3];            // 311
       char sMerchantRegionCd[3];          // 314
       char sMerchantProcType[5];          // 317
       char sMerchantBillingType[2];       // 322
       char cMerchClearingFlag;            // 324
       char sMerchantTierInd[3];           // 325
       char cMerchantStatus;               // 328
       char sMerchantURL[255];             // 329  SEG24 Token 44 tag M3 [ADL_DATA_NATIONAL]
       char sMerchantPhNum[16];            // 584
       char sCardAcceptAdtlAddr[20];       // 600
       char sBusinessType[4];              // 620
       char sBusinessOwnerType[2];         // 624
       char cCertificationType;            // 626
       char sRaceEthnicType[2];            // 627
       char sAltTaxId[15];                 // 629
       char sDunNum[30];                   // 644
       char sOilCoBrandName[9];            // 674
       char sCorpVATNum[20];               // 683
       char sNetworkMerchId[30];           // 703
       char cSmallMerchInd;                // 733
       char sMerchantCntrySubCode[3];      // 734
   };

   struct hTC57_TCR4_VisaSMS
   {
      char sTransCode[2];                 // 0    57
      char cTransCodeQualifier;           // 2    0
      char cTransComponentSeqNumber;      // 3    4
      char sAgentUniqueID[5];             // 4
      char sFiller1[7];                   // 9
      char sBusinessFormatCode[2];        // 16
      char sDebitProductCode[4];          // 18
      char sContactInformation[25];       // 22
      char cAdjProcInd;                   // 47
      char sMessageReasonCode[4];         // 48
      char sSurchargeAmount[8];           // 52
      char sSurchargeCrDbInd[2];          // 60
      char sVISAInternalUseOnly[16];      // 62
      char sSurchargeBillingAmount[8];    // 78
      char sForeignExchangeFee[8];        // 86
      char sPaymentAccountReference[29];  // 94
      char sTokenRequestorID[11];         // 123
      char sFiller2[32];                  // 134
      char cRecordType;                   // 166
      char cFiller3;                      // 167
   };
//## end report%5C473883000E.initialDeclarations

//## begin report::ISTTC57TransactionFile%6809C3C000B8.preface preserve=yes
   struct hTC57_TCR1_TxnDetail_UPI
   {
      char sTransCode[2];                 // 0    57
      char cTransCodeQualifier;           // 2    0
      char cTransComponentSeqNumber;      // 3    1
      char sUPIIndicator[2];              // 4
      char cTransInitMethod;              // 6
      char sAuthType[3];                  // 7
      char cCardLevelIndicator;           // 10
      char sPOSCondCode[2];               // 11
      char sEcomIndicator[2];             // 13
      char sCardProduct[2];               // 15
      char sAcctAttribute[2];             // 17
      char sQRCVoucherNumber[20];         // 19
      char sB2BBusinessType[2];           // 39
      char cB2BPaymentMedium;             // 41
      char sSpecPricingIndicator[2];      // 42
      char sTransScenarioIndicator[3];    // 44
   };
//## end report::ISTTC57TransactionFile%6809C3C000B8.preface

//## Class: ISTTC57TransactionFile%6809C3C000B8
//## Category: Data Distribution::Report_CAT%5C473883000E
//## Subsystem: RXDLL%5C47391001FD
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%6809C3C000BC;configuration::ConfigurationRepository { -> F}
//## Uses: <unnamed>%6809C3C000BD;IF::FlatFile { -> F}
//## Uses: <unnamed>%6809C3C000BE;timer::Date { -> F}
//## Uses: <unnamed>%6809C3C000BF;timer::Clock { -> F}
//## Uses: <unnamed>%6809C3C000C0;monitor::UseCase { -> F}
//## Uses: <unnamed>%6809C3C000C1;database::ReportFactory { -> F}
//## Uses: <unnamed>%6809C3C000C2;segment::GenericSegment { -> F}
//## Uses: <unnamed>%6809C3C000C3;IF::Extract { -> F}
//## Uses: <unnamed>%6809C3C000C4;reusable::KeyRing { -> F}
//## Uses: <unnamed>%6809C3C000C5;process::Application { -> F}
//## Uses: <unnamed>%6809C3E90102;configuration::ConfigurationRepository { -> F}
//## Uses: <unnamed>%6809C3E90108;IF::FlatFile { -> F}
//## Uses: <unnamed>%6809C3E9010D;timer::Date { -> F}
//## Uses: <unnamed>%6809C3E90112;timer::Clock { -> F}
//## Uses: <unnamed>%6809C3E90118;monitor::UseCase { -> F}
//## Uses: <unnamed>%6809C3E9011D;database::ReportFactory { -> F}
//## Uses: <unnamed>%6809C3E90124;segment::GenericSegment { -> F}
//## Uses: <unnamed>%6809C3E9012A;IF::Extract { -> F}
//## Uses: <unnamed>%6809C3E9012F;reusable::KeyRing { -> F}
//## Uses: <unnamed>%6809C40502F7;process::Application { -> F}
//## Uses: <unnamed>%68B0B64D01EF;reusable::Token { -> F}

class DllExport ISTTC57TransactionFile : public postingfile::ReportFile  //## Inherits: <unnamed>%6809C3C000BB
{
  //## begin report::ISTTC57TransactionFile%6809C3C000B8.initialDeclarations preserve=yes
  //## end report::ISTTC57TransactionFile%6809C3C000B8.initialDeclarations

  public:
    //## Constructors (generated)
      ISTTC57TransactionFile();

    //## Destructor (generated)
      virtual ~ISTTC57TransactionFile();


    //## Other Operations (specified)
      //## Operation: distribute%6809C3C000C6
      virtual bool distribute (string& strDATA_BUFFER, IF::FlatFile& hFlatFile);

      //## Operation: finish%6809C3C000C9
      virtual bool finish (IF::FlatFile& hFlatFile);

      //## Operation: initialize%6809C3C000CB
      virtual bool initialize ();

      //## Operation: setOrderByClause%6809C3C000CC
      virtual void setOrderByClause (reusable::Query& hQuery);

    // Additional Public Declarations
      //## begin report::ISTTC57TransactionFile%6809C3C000B8.public preserve=yes
      string m_strAuthREF_DATA_ISS;
      virtual bool start(IF::FlatFile& hFlatFile);
      virtual bool unionAll(Query& hQuery);
      bool writeUnMatchedAuth();
      int m_iFieldMaxLen;
      int m_iField[8][2];
      enum CmpFields
      {
         PAN,
         RETRIEVAL_REF_NO,
         APPROVAL_CODE,
         MTI,
         TSTAMP_TRANS,
         REF_DATA_ISS,
         PROC_ID_ISS_B,
         NET_ID_ISS
      };
      //## end report::ISTTC57TransactionFile%6809C3C000B8.public
  protected:
    // Additional Protected Declarations
      //## begin report::ISTTC57TransactionFile%6809C3C000B8.protected preserve=yes
      //## end report::ISTTC57TransactionFile%6809C3C000B8.protected

  private:

    //## Other Operations (specified)
      //## Operation: write_TCR90_FileHeader%6809C3C000CE
      bool write_TCR90_FileHeader (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR0_BatchHeader%6809C3C000D0
      bool write_TCR0_BatchHeader (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR1_BatchHeader%6809C3C000D2
      bool write_TCR1_BatchHeader (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR0_TxnDetail%6809C3C000D4
      bool write_TCR0_TxnDetail (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR1_TxnDetail_Common%6809C3C000D6
      bool write_TCR1_TxnDetail_Common (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR7_Chip%6809C3C000D8
      bool write_TCR7_Chip (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR7_Chip_All%6809C3C000DA
      bool write_TCR7_Chip_All (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR7_ChipExt%6809C3C000DC
      bool write_TCR7_ChipExt (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR5_TxnDetail_MC%6809C3C000DE
      bool write_TCR5_TxnDetail_MC (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR4_TxnDetail_VISA%6809C3C000E0
      bool write_TCR4_TxnDetail_VISA (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR1_DinersIntlChargeDetailRecord%6809C3C000E2
      bool write_TCR1_DinersIntlChargeDetailRecord (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR3_TxnDetail_PaymentServiceData%6809C3C000E4
      bool write_TCR3_TxnDetail_PaymentServiceData (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR3_PassangerTravelLegRecord%6809C3C000E6
      bool write_TCR3_PassangerTravelLegRecord (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR99_Coles%6809C3C000E8
      bool write_TCR99_Coles (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR99_CustomRecord%6809C3C000EA
      bool write_TCR99_CustomRecord (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR2_AmexCAPNBatchHeader%6809C3C000EC
      bool write_TCR2_AmexCAPNBatchHeader (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR1_AmexTxnDetailAdviceBasic%6809C3C000EE
      bool write_TCR1_AmexTxnDetailAdviceBasic (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR4_AmexTxnDetailLocation%6809C3C000F0
      bool write_TCR4_AmexTxnDetailLocation (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR3_DinersIntlChipAddtlRecord%6809C3C000F2
      bool write_TCR3_DinersIntlChipAddtlRecord (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR0_BatchTrailer%6809C3C000F4
      bool write_TCR0_BatchTrailer (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR91_BatchTrailer%6809C3C000F6
      bool write_TCR91_BatchTrailer (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR92_FileTrailer%6809C3C000F8
      bool write_TCR92_FileTrailer (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR4_PaymentTransaction1_MC%68B56BC100EB
      bool write_TCR4_PaymentTransaction1_MC (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR4_PaymentTransaction0_MC%68E35DFA00BB
      bool write_TCR4_PaymentTransaction0_MC (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR3_BusAppDetails_Visa%68B56BF101DB
      bool write_TCR3_BusAppDetails_Visa (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR97_CommonMerchantData%68B56C1D00AB
      bool write_TCR97_CommonMerchantData (IF::FlatFile& hFlatFile);

      //## Operation: getGenericValue%6809C3C000FA
      bool getGenericValue (const string& strType, const string& strFromValue, string& strToValue);

      //## Operation: write%6809C3C000FE
      bool write (const int &iLength, IF::FlatFile& hFlatFile);

    // Additional Private Declarations
      //## begin report::ISTTC57TransactionFile%6809C3C000B8.private preserve=yes
      bool write_TCR4_VisaSMS(IF::FlatFile& hFlatFile);
      bool write_TCR1_TxnDetail_UPI(IF::FlatFile& hFlatFile);
      //## end report::ISTTC57TransactionFile%6809C3C000B8.private
  private: //## implementation
    // Data Members for Class Attributes

      //## Attribute: BatchKey%6809C3C00101
      //## begin report::ISTTC57TransactionFile::BatchKey%6809C3C00101.attr preserve=no  private: string {U} 
      string m_strBatchKey;
      //## end report::ISTTC57TransactionFile::BatchKey%6809C3C00101.attr

      //## Attribute: BatchToValue%6809C3C00102
      //## begin report::ISTTC57TransactionFile::BatchToValue%6809C3C00102.attr preserve=no  private: string {U} 
      string m_strBatchToValue;
      //## end report::ISTTC57TransactionFile::BatchToValue%6809C3C00102.attr

      //## Attribute: BatchNo%6809C3C00103
      //## begin report::ISTTC57TransactionFile::BatchNo%6809C3C00103.attr preserve=no  private: int {U} 0
      int m_iBatchNo;
      //## end report::ISTTC57TransactionFile::BatchNo%6809C3C00103.attr

      //## Attribute: IntrMerchBatchKey%6809C3C00104
      //## begin report::ISTTC57TransactionFile::IntrMerchBatchKey%6809C3C00104.attr preserve=no  private: short {U} 0
      short m_siIntrMerchBatchKey;
      //## end report::ISTTC57TransactionFile::IntrMerchBatchKey%6809C3C00104.attr

      //## Attribute: BatchTxnCount%6809C3C00105
      //## begin report::ISTTC57TransactionFile::BatchTxnCount%6809C3C00105.attr preserve=no  private: short {U} 0
      short m_siBatchTxnCount;
      //## end report::ISTTC57TransactionFile::BatchTxnCount%6809C3C00105.attr

      //## Attribute: BatchNetAmt%6809C3C00106
      //## begin report::ISTTC57TransactionFile::BatchNetAmt%6809C3C00106.attr preserve=no  private: double {U} 0
      double m_dBatchNetAmt;
      //## end report::ISTTC57TransactionFile::BatchNetAmt%6809C3C00106.attr

      //## Attribute: BatchGrossAmt%6809C3C00107
      //## begin report::ISTTC57TransactionFile::BatchGrossAmt%6809C3C00107.attr preserve=no  private: double {U} 0
      double m_dBatchGrossAmt;
      //## end report::ISTTC57TransactionFile::BatchGrossAmt%6809C3C00107.attr

      //## Attribute: NoOfTcrs%6809C3C00108
      //## begin report::ISTTC57TransactionFile::NoOfTcrs%6809C3C00108.attr preserve=no  private: int {U} 0
      int m_iNoOfTcrs;
      //## end report::ISTTC57TransactionFile::NoOfTcrs%6809C3C00108.attr

      //## Attribute: TotNoOfTcrs%6809C3C00109
      //## begin report::ISTTC57TransactionFile::TotNoOfTcrs%6809C3C00109.attr preserve=no  private: int {U} 0
      int m_iTotNoOfTcrs;
      //## end report::ISTTC57TransactionFile::TotNoOfTcrs%6809C3C00109.attr

      //## Attribute: TotNoOfTxns%6809C3C0010A
      //## begin report::ISTTC57TransactionFile::TotNoOfTxns%6809C3C0010A.attr preserve=no  private: int {U} 0
      int m_iTotNoOfTxns;
      //## end report::ISTTC57TransactionFile::TotNoOfTxns%6809C3C0010A.attr

      //## Attribute: TotNetAmt%6809C3C0010B
      //## begin report::ISTTC57TransactionFile::TotNetAmt%6809C3C0010B.attr preserve=no  private: double {U} 0
      double m_dTotNetAmt;
      //## end report::ISTTC57TransactionFile::TotNetAmt%6809C3C0010B.attr

      //## Attribute: VariableBlockFile%6809C3C0010C
      //## begin report::ISTTC57TransactionFile::VariableBlockFile%6809C3C0010C.attr preserve=no  private: bool {U} false
      bool m_bVariableBlockFile;
      //## end report::ISTTC57TransactionFile::VariableBlockFile%6809C3C0010C.attr

      //## Attribute: zREF_DATA_ISS%6809C3C0010D
      //## begin report::ISTTC57TransactionFile::zREF_DATA_ISS%6809C3C0010D.attr preserve=no  private: char[100] {U} 
      char m_szREF_DATA_ISS[100];
      //## end report::ISTTC57TransactionFile::zREF_DATA_ISS%6809C3C0010D.attr

      //## Attribute: zADL_DATA_PRIV_ACQ%6809C3C0010E
      //## begin report::ISTTC57TransactionFile::zADL_DATA_PRIV_ACQ%6809C3C0010E.attr preserve=no  private: char[256] {U} 
      char m_szADL_DATA_PRIV_ACQ[256];
      //## end report::ISTTC57TransactionFile::zADL_DATA_PRIV_ACQ%6809C3C0010E.attr

      //## Attribute: zADL_DATA_PRIV_ISS%6809C3C0010F
      //## begin report::ISTTC57TransactionFile::zADL_DATA_PRIV_ISS%6809C3C0010F.attr preserve=no  private: char[256] {U} 
      char m_szADL_DATA_PRIV_ISS[256];
      //## end report::ISTTC57TransactionFile::zADL_DATA_PRIV_ISS%6809C3C0010F.attr

      //## Attribute: zADL_RESP_DATA%6809C3C00110
      //## begin report::ISTTC57TransactionFile::zADL_RESP_DATA%6809C3C00110.attr preserve=no  private: char[100] {U} 
      char m_szADL_RESP_DATA[100];
      //## end report::ISTTC57TransactionFile::zADL_RESP_DATA%6809C3C00110.attr

      //## Attribute: zDATA_PRIV_ACQ%6809C3C00111
      //## begin report::ISTTC57TransactionFile::zDATA_PRIV_ACQ%6809C3C00111.attr preserve=no  private: char[101] {U} 
      char m_szDATA_PRIV_ACQ[101];
      //## end report::ISTTC57TransactionFile::zDATA_PRIV_ACQ%6809C3C00111.attr

      //## Attribute: zEXTENSION_DATA_ADJ%6809C3C00112
      //## begin report::ISTTC57TransactionFile::zEXTENSION_DATA_ADJ%6809C3C00112.attr preserve=no  private: char[401] {U} 
      char m_szEXTENSION_DATA_ADJ[401];
      //## end report::ISTTC57TransactionFile::zEXTENSION_DATA_ADJ%6809C3C00112.attr

      //## Attribute: FilmLocator%6809C3C00113
      //## begin report::ISTTC57TransactionFile::FilmLocator%6809C3C00113.attr preserve=no  private: int {U} 0
      int m_iFilmLocator;
      //## end report::ISTTC57TransactionFile::FilmLocator%6809C3C00113.attr

    // Data Members for Associations

      //## Association: Data Distribution::Report_CAT::<unnamed>%6809D18A0110
      //## Role: ISTTC57TransactionFile::<m_pContext>%6809D18A03AC
      //## begin report::ISTTC57TransactionFile::<m_pContext>%6809D18A03AC.role preserve=no  public: database::Context { -> RHgN}
      database::Context *m_pContext;
      //## end report::ISTTC57TransactionFile::<m_pContext>%6809D18A03AC.role

    // Additional Implementation Declarations
      //## begin report::ISTTC57TransactionFile%6809C3C000B8.implementation preserve=yes
      char m_szDATA_PRIV_ISS[101];
      vector<string> m_hConstants;
      bool m_bAdvRevTran;
      char m_szSpaces[695];
      Query m_hQuery[2];
      bool m_bPrevAuth;
      string m_strAuthBuffer;
      string m_strAuthAltRecKey;
      database::ExportFile* m_pUnMatchFile;
      int m_iSeqNo;
      string m_strMinAuth;
      bool m_bDF09Presence;
      //## end report::ISTTC57TransactionFile%6809C3C000B8.implementation
};

//## begin report::ISTTC57TransactionFile%6809C3C000B8.postscript preserve=yes
//## end report::ISTTC57TransactionFile%6809C3C000B8.postscript

} // namespace report

//## begin module%62610BB90155.epilog preserve=yes
//## end module%62610BB90155.epilog


#endif
