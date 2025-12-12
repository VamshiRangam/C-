//  Copyright (c) 1998 - 2024
//  FIS

#ifndef CXODRF64_HPP
#define CXODRF64_HPP

// NYCE Network EDF

struct hEDF0
{
   char cRecordPart;                   // 0000 - '0'
   char cFormatCode;                   // 0001
   char sDATE_RECON_NET[8];            // 0002 DATE_RECON
   char sCreateDate[4];                // 0010
   char sCreateTime[6];                // 0014
   char sPROC_ID[8];                   // 0020
};

struct hEDF1
{
   char cRecordPart;                   // 0000 - '1'
   char sMTI[4];                       // 0001 MTI
   char sAcquirerProcessor[8];         // 0005
   char sTermOwningFRDABA[9];          // 0013
   char sSwitchTerminalNumber[8];      // 0022 NET_TERM_ID
   char sSwitchSequenceNumber[8];      // 0030 SYS_TRACE_AUDIT_NO
   char sSwitchDate[4];                // 0038
   char sSwitchTime[6];                // 0042
   char sTerminalTime[6];              // 0048 TSTAMP_LOCAL
   char sTerminalDate[4];              // 0054 TSTAMP_LOCAL
   char sCARD_ACPT_TERM_ID[8];         // 0058 CARD_ACPT_TERM_ID
   char sRETRIEVAL_REF_NO[12];         // 0066 RETRIEVAL_REF_NO
   char sCardAcceptorIDCode[15];       // 0078 CARD_ACPT_ID
   char sTerminalNameLocation[74];     // 0093
   char sTerminalDetails[3];           // 0167
   char sMerchantType[4];              // 0170 CARD_ACPT_BUS_CODE
   char sTerminalICHAmount[7];         // 0174 F_AMT90 999.9999
   char cTerminalICHSign;              // 0181
   char sTerminalCurrency[3];          // 0182 CUR_TRAN
   char sAcquirerNetwork[3];           // 0185
   char sTRAN_TYPE_ID[2];              // 0188 TRAN_TYPE_ID
   char sAMT_RECON_NET[13];            // 0190 AMT_RECON_NET
   char cAmountSign;                   // 0203
   char sSettleCurrencyCode[3];        // 0204 CUR_RECON_NET
   char sSurchargeRebateAmount[7];     // 0207 F_AMTcb
   char cSurchargeRebateSign;          // 0214
   char sCashbackAmount[13];           // 0215
   char cCashbackSign;                 // 0228
   char cResponseCode;                 // 0229 TRAN_DISPOSITION
   char sRejectReason[2];              // 0230
   char sAuthorizerCode[6];            // 0232
   char sAdviceReversalReasonCode[2];  // 0238
   char sAuthorizationProcessor[8];    // 0240
   char sCardOwningFRDABA[9];          // 0248
   char sPAN[28];                      // 0257 PAN
   char sMemberNumber[5];              // 0285
   char sAccount1[28];                 // 0290
   char sAccount2[28];                 // 0318
   char sAccountQualifier1[3];         // 0346
   char sAccountQualifier2[3];         // 0349
   char sIssuerICHAmount[7];           // 0352 F_AMT90 999.9999
   char cIssuerICHSign;                // 0359
   char sIssuerCurrencyCode[3];        // 0360
   char sIssuerNetwork[3];             // 0363
   char cROLE_IND;                     // 0366 ROLE_IND
   char sTargetInstitutionFRDABA[9];   // 0367
   char cAmountImpact;                 // 0376
   char cSurchargeRebateImpact;        // 0377
   char cInterchangeImpact;            // 0378
};

struct hEDF9
{
   char cRecordPart;                   // 0000 - '9'
   char sAmounts[139];                 // 0001
};

#endif
