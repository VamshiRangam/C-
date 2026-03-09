//  Copyright (c) 1998 - 2024
//  FIS

// American Express TILR

#ifndef CXODRF66_HPP
#define CXODRF66_HPP

struct hFileHeader
{
   char sRecordType[5];                // 0000
   char sDate[8];                      // 0005
};

struct hSummary
{
   char sPayeeNumber[10];              // 0000
};

struct hROC
{
   char sFill1[42];                    // 0000
   char cRecordType;                   // 0042
   char sDetailRecordType[2];          // 0043
   char sFill2[20];                    // 0045
   char sSOCAmount[13];                // 0065
   char sROCAmount[13];                // 0078
   char sCmNumber[15];                 // 0091
   char sCmRefNo[11];                  // 0106
   char sFill3[36];                    // 0117
   char sSeRefPOA[30];                 // 0153
   char cCAPNNonCompliant;             // 0183
   char sFill4[17];                    // 0184
   char cDataQualityNonCompliant;      // 0201
   char sFill5[26];                    // 0202
   char sCmNumber19[19];               // 0228
};

struct hROCDetail
{
   char sFill1[42];                    // 0000
   char cRecordType;                   // 0042
   char sDetailRecordType[2];          // 0043
   char sFeeCode[2];                   // 0045
   char sFeeDescription[25];           // 0047
   char sDiscountRate[9];              // 0072
   char sDiscountAmount[15];           // 0081
   char sFeeRate[9];                   // 0096
   char sFeeAmount[15];                // 0105
   char sSellerID[20];                 // 0120
};

struct hChargeback
{
   char sFill1[42];                    // 0000
   char cRecordType;                   // 0042
   char sDetailRecordType[2];          // 0043
   char sBusinessDate[7];              // 0045
   char sProcessDate[7];               // 0052
   char sInvoiceNumber[6];             // 0059
   char sSOCAmount[11];                // 0065
   char sChargebackAmount[9];          // 0076
   char sDiscountAmount[9];            // 0085
   char sFeeAmount[7];                 // 0094
   char sFill2[7];                     // 0101
   char sNetChargebackAmount[9];       // 0108
   char sFill3[26];                    // 0117
   char sChargebackReason[280];        // 0143
   char sFill4[6];                     // 0423
   char sSellerID[20];                 // 0429
};

struct hAdjustment
{
   char sFill1[42];                    // 0000
   char cRecordType;                   // 0042
   char sDetailRecordType[2];          // 0043
   char sProcessDate[7];               // 0045
   char sAjustmentNumber[6];           // 0052
   char sAdjustmentAmount[9];          // 0058
   char sDiscountAmount[9];            // 0067
   char sFeeAmount[7];                 // 0076
   char sFill2[7];                     // 0083
   char sNetAdjustmentAmount[9];       // 0090
   char sFill3[26];                    // 0099
   char sCardMemberNumber[17];         // 0125
   char sAdjustmentReason[280];        // 0142
   char sBatchCode[3];                 // 0422
   char sBillCode[3];                  // 0425
   char sSellerID[20];                 // 0428
};

struct hOtherFee
{
   char sFill1[42];                    // 0000
   char cRecordType;                   // 0042
   char sDetailRecordType[2];          // 0043
   char sProcessDate[7];               // 0045
   char sFill2[163];                   // 0052
   char sOtherFeeAmount[9];            // 0215
   char sOtherFeeDescription[80];      // 0224
   char sFill3[16];                    // 0304
   char sSellerID[20];                 // 0320
};

// American Express GRRCN

struct hHeaderRecord
{
   char sRecordType[10];               // 0000
   char sDate[8];                      // 0010
   char sTime[6];                      // 0018
   char sSeqNo[10];                    // 0024
   char sFileID[10];                   // 0034
   char sFileName[20];                 // 0044
   char sVersionNo[4];                 // 0064
   char sFiller[732];                  // 0068
};

struct hSummaryRecord
{
   char sRecordType[10];               // 0000 - 'SUMMARY'
   char sPayeeMerchantId[15];          // 0010
   char sAccountType[3];               // 0025
   char sPayeeNumber[10];              // 0028
   char sPaymentDate[8];               // 0038 DATE_RECON_NET
   char sPaymentCurrency[3];           // 0046
   char sUniquePaymentRefNo[18];       // 0049
   char sPaymentNetAmt[16];            // 0067
   char sPaymentGrossAmt[16];          // 0083
   char sPaymentDiscountAmt[16];       // 0099
   char sPaymentServiceFeeAmt[16];     // 0115
   char sAdjustmentAmt[16];            // 0131
   char sTaxAmt[16];                   // 0147
   char sOpenDebitBalAmt[16];          // 0163
   char sPayeeDirectDepositNo[17];     // 0179
   char sBankAcctNo[34];               // 0196
   char sInterBankAcctNo[34];          // 0230
   char sBankIdentityCode[15];         // 0264
   char cPaymentStatus;                // 0279
   char sFiller[520];                  // 0280
};

struct hTransactionRecord
{
   char sRecordType[10];               // 0000 - 'TRANSACTN'
   char sFill0[103];                   // 0010
   char sInvoiceReferenceNumber[23];   // 0113
   char sFill1[27];                    // 0136
   char sPAN[19];                      // 0163 PAN
   char sFill2[46];                    // 0182
   char sROCAmount[16];                // 0228 AMT_RECON_NET
   char sFill3[79];                    // 0244
   char sACQ_REF_NO[23];               // 0323 ACQ_REF_NO
   char cDataQualNonCompInd;           // 0346
   char sDataQualNonCompErrCode1[4];   // 0347
   char sDataQualNonCompErrCode2[4];   // 0351
   char sDataQualNonCompErrCode3[4];   // 0355
   char sDataQualNonCompErrCode4[4];   // 0359
   char cNonSwipedInd;                 // 0363
   char sTranRejectedInd[3];           // 0364 TRAN_DISPOSITION
   char sFirstInstAmt[16];             // 0367
   char sSubSeqInstAmt[16];            // 0383
   char sNoOfInstallments[5];          // 0399
   char sInstallmentNo[5];             // 0404
   char sVATInvoiceSeqNo[15];          // 0409
   char sServiceFeeAmt[16];            // 0424
   char sAccelerationAmt[16];          // 0440
   char sMarketRefNo1[45];             // 0456
   char sMarketRefNo2[45];             // 0501
   char sSubBranchID[11];              // 0546
   char cPaymentStatus;                // 0557
   char sTokenizedCardNo[19];          // 0558
   char sPaymentAcctRef[35];           // 0577
   char sFiller[188];                  // 0612
};

struct hTransactionPricingRecord
{
   char sRecordType[10];               // 0000
   char sPayeeMerchID[15];             // 0010
   char sSettleAcctType[3];            // 0025
   char sAMEXPaymentNo[10];            // 0028
   char sPaymentDate[8];               // 0038
   char sPaymentCurrency[3];           // 0046
   char sSubMerchID[15];               // 0049
   char sMerchLocID[15];               // 0064
   char sFiller1[15];                  // 0079
   char sInvoiceRefNo[30];             // 0094
   char sSellerID[20];                 // 0124
   char sCmAcctNo[19];                 // 0144
   char sTranAmt[16];                  // 0163
   char sTranDate[8];                  // 0179
   char sFeeCode[2];                   // 0187
   char sFill2[7];                     // 0189
   char sFeeAmount[22];                // 0196
   char sDiscountRate[7];              // 0218
   char sDiscountAmount[22];           // 0225
   char sRoundedFeeAmount[16];         // 0247
   char sRoundedDiscountAmount[16];    // 0263
   char sFeeAmt[22];                   // 0279 Settlement Currency
   char sDiscountAmt[22];              // 0301 Settlement Currency
   char sSettleTranAmt[16];            // 0323 Settlement Currency
   char sMarketRefNo1[45];             // 0339
   char sMarketRefNo2[45];             // 0384
   char cPaymentStatus;                // 0429
   char sTokenizedCardNo[19];          // 0430
   char sPaymentAcctRef[35];           // 0449
   char sFiller[316];                  // 0484
};

struct hChargebackRecord
{
   char sRecordType[10];               // 0000
   char sPayeeMerchID[15];             // 0010
   char sSettleAcctType[3];            // 0025
   char sAMEXPaymentNo[10];            // 0028
   char sPaymentDate[8];               // 0038
   char sPaymentCurrency[3];           // 0046
   char sSubMerchID[15];               // 0049
   char sBusSubDate[8];                // 0064
   char sMerchLocID[15];               // 0072
   char sInvoiceRefNo[30];             // 0087
   char sSellerID[20];                 // 0117
   char sCmAcctNo[19];                 // 0137
   char sIndustryRefNo[30];            // 0156
   char sAMEXProcessDate[8];           // 0186
   char sSubInvoiceNo[15];             // 0194
   char sSubCurrency[3];               // 0209
   char sCHBNo[30];                    // 0212
   char sCHBRsnCode[10];               // 0242
   char sChargebackReason[280];        // 0252
   char sChargebackAmount[16];         // 0532
   char sDiscountAmt[16];              // 0548
   char sServiceFeeAmt[16];            // 0564
   char sTaxAmt[16];                   // 0580
   char sNetAmt[16];                   // 0596
   char sDiscountRate[7];              // 0612
   char sServiceFeeRate[7];            // 0619
   char sBatchCode[3];                 // 0626
   char sBillCode[3];                  // 0629
   char sOrigTranID[15];               // 0632
   char sMarketRefNo1[45];             // 0647
   char sMarketRefNo2[45];             // 0692
   char sAcqRefNo[23];                 // 0737
   char sOrigTranAmt[16];              // 0760 Submission Currency
   char sOrigTranAmount[16];           // 0776 Settlement Currency
   char sOrigTranDate[8];              // 0792
   char sOrigSubInvoiceNo[15];         // 0800
   char sGrossAmtInSubCurrency[16];    // 0815
   char sNetAmtInSubCurrency[16];      // 0831
   char sAMEXDisputeCaseRef[16];       // 0847
   char sCHBRsnCode_iso[4];            // 0863
   char cPaymentStatus;                // 0867
   char sTokenizedCardNo[19];          // 0868
   char sPaymentAcctRef[35];           // 0887
   char sFiller[78];                   // 0922
};

struct hAdjustmentRecord
{
   char sRecordType[10];               // 0000
   char sPayeeMerchID[15];             // 0010
   char sSettleAcctType[3];            // 0025
   char sAMEXPaymentNo[10];            // 0028
   char sPaymentDate[8];               // 0038
   char sPaymentCurrency[3];           // 0046
   char sSubMerchID[15];               // 0049
   char sBusSubDate[8];                // 0064
   char sMerchLocID[15];               // 0072
   char sInvoiceRefNo[30];             // 0087
   char sSellerID[20];                 // 0117
   char sCardMemberNumber[19];         // 0137
   char sIndustryRefNo[30];            // 0156
   char sAMEXProcessDate[8];           // 0186
   char sSubInvoiceNo[15];             // 0194
   char sSubCurrency[3];               // 0209
   char sADJNo[30];                    // 0212
   char sADJRsnCode[10];               // 0242
   char sAdjustmentReason[280];        // 0252
   char sAdjustmentAmount[16];         // 0532
   char sDiscountAmount[16];           // 0548
   char sFeeAmount[16];                // 0564
   char sTaxAmt[16];                   // 0580
   char sNetAmt[16];                   // 0596
   char sDiscountRate[7];              // 0612
   char sServiceFeeRate[7];            // 0619
   char sBatchCode[3];                 // 0626
   char sBillCode[3];                  // 0629
   char cPaymentStatus;                // 0632
   char sTokenizedCardNo[19];          // 0633
   char sPaymentAcctRef[35];           // 0652
   char sFiller[113];                  // 0687
};

struct hFeesAndRevenuesRecord
{
   char sRecordType[10];               // 0000
   char sPayeeMerchID[15];             // 0010
   char sAMEXPaymentNo[10];            // 0025
   char sPaymentDate[8];               // 0035
   char sPaymentCurrency[3];           // 0043
   char sSubmissionID[15];             // 0046
   char sMerchantID[15];               // 0061
   char sOtherFeeAmount[16];           // 0076
   char sOtherFeeDescription[80];      // 0092
   char sAssetBillingAmt[16];          // 0172
   char sAssetBillDesc[65];            // 0188
   char sAssetBillTax[16];             // 0253
   char cPayInGrossInd;                // 0269
   char sBatchCode[3];                 // 0270
   char sBillCode[3];                  // 0273
   char sSellerID[20];                 // 0276
   char sFiller[504];                  // 0296
};

#endif

