//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%641DC320031D.cm preserve=no
//## end module%641DC320031D.cm

//## begin module%641DC320031D.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%641DC320031D.cp

//## Module: CXOSRF81%641DC320031D; Package body
//## Subsystem: RFDLL%439873F400EA
//## Source file: C:\Repos\DataNavigatorServer\Windows\Build\Dn\Server\Library\Rfdll\CXOSRF81.cpp

//## begin module%641DC320031D.additionalIncludes preserve=no
//## end module%641DC320031D.additionalIncludes

//## begin module%641DC320031D.includes preserve=yes
#include "CXODCF61.hpp"
#include "CXODBS23.hpp"
#ifndef CXOSRF57_h
#include "CXODRF57.hpp"
#endif
#include "CXODRF51.hpp"
//## end module%641DC320031D.includes

#ifndef CXOSCF01_h
#include "CXODCF01.hpp"
#endif
#ifndef CXOSRU40_h
#include "CXODRU40.hpp"
#endif
#ifndef CXOSRFZ4_h
#include "CXODRFZ4.hpp"
#endif


//## begin module%641DC320031D.declarations preserve=no
//## end module%641DC320031D.declarations

//## begin module%641DC320031D.additionalDeclarations preserve=yes
//## end module%641DC320031D.additionalDeclarations


//## Modelname: Reconciliation::ReconciliationFile_CAT%439754C1037A
namespace reconciliationfile {
//## begin reconciliationfile%439754C1037A.initialDeclarations preserve=yes
//## end reconciliationfile%439754C1037A.initialDeclarations

// Class reconciliationfile::MCDebitPINInterchangeFile 

MCDebitPINInterchangeFile::MCDebitPINInterchangeFile (const string& strClass)
  //## begin reconciliationfile::MCDebitPINInterchangeFile::MCDebitPINInterchangeFile%64F1F1620329.hasinit preserve=no
  //## end reconciliationfile::MCDebitPINInterchangeFile::MCDebitPINInterchangeFile%64F1F1620329.hasinit
  //## begin reconciliationfile::MCDebitPINInterchangeFile::MCDebitPINInterchangeFile%64F1F1620329.initialization preserve=yes
   :InterchangeFile(strClass)
  //## end reconciliationfile::MCDebitPINInterchangeFile::MCDebitPINInterchangeFile%64F1F1620329.initialization
{
  //## begin reconciliationfile::MCDebitPINInterchangeFile::MCDebitPINInterchangeFile%64F1F1620329.body preserve=yes
   memcpy(m_sID, "RFZ4", 4);
   setColumns("PAN"
      ",RETRIEVAL_REF_NO"
      ",TSTAMP_LOCAL"
      ",CARD_ACPT_TERM_ID"
      ",TRAN_DISPOSITION"
      ",AMT_RECON_NET"
      ",ADL_RQST_AMT0"
      ",TRAN_TYPE_ID"
      ",DATE_RECON_NET"
      ",CUR_RECON_NET"
      ",F_AMT0"
      ",ROLE_IND"
      ",F_TYPE0"
   );
   m_strDX_FILE_TYPE.assign("MCIIXE", 6);
   m_bIncludeSurcharge = true;
  //## end reconciliationfile::MCDebitPINInterchangeFile::MCDebitPINInterchangeFile%64F1F1620329.body
}


MCDebitPINInterchangeFile::~MCDebitPINInterchangeFile()
{
  //## begin reconciliationfile::MCDebitPINInterchangeFile::~MCDebitPINInterchangeFile%641DC0020137_dest.body preserve=yes
  //## end reconciliationfile::MCDebitPINInterchangeFile::~MCDebitPINInterchangeFile%641DC0020137_dest.body
}



//## Other Operations (implementation)
void MCDebitPINInterchangeFile::join (Query& hQuery, const char* pszTable)
{
  //## begin reconciliationfile::MCDebitPINInterchangeFile::join%641DC0D80339.body preserve=yes
   hQuery.join(pszTable, "INNER", "FIN_RECORD", "TSTAMP_TRANS");
   hQuery.join(pszTable, "INNER", "FIN_RECORD", "UNIQUENESS_KEY");
   getRepository().bind2(hQuery, pszTable);
  //## end reconciliationfile::MCDebitPINInterchangeFile::join%641DC0D80339.body
}

bool MCDebitPINInterchangeFile::lookupEntity (const string& strINST_ID)
{
  //## begin reconciliationfile::MCDebitPINInterchangeFile::lookupEntity%641DCED80337.body preserve=yes
   string strPROC_ID,strINST_ID_1;
   int i = 0;
   if (ConfigurationRepository::instance()->translate("INSTITUTION", strINST_ID, strPROC_ID, "", "", -1, false) == false)
   {
      if (NetworkInstitution::getINST_ID("MCI", strINST_ID, "", "", "", strINST_ID_1))
      {
         if (ConfigurationRepository::instance()->translate("INSTITUTION", strINST_ID_1, strPROC_ID, "", "", -1, false) == false)
         {
            if (m_pReformatAudit)
               m_pReformatAudit->report(m_strProcType[0]);
            return false;
         }
      }
      else
      {
         if (m_pReformatAudit)
            m_pReformatAudit->report(m_strProcType[0]);
         return false;
      }
   }
   return true;
  //## end reconciliationfile::MCDebitPINInterchangeFile::lookupEntity%641DCED80337.body
}

bool MCDebitPINInterchangeFile::reFormat ()
{
  //## begin reconciliationfile::MCDebitPINInterchangeFile::reFormat%641DCF2603A1.body preserve=yes
   if (!InterchangeFile::initReFormat())
      return false;
   memset(m_pBuffer,' ',250);
   string strRecordType;
   bool bSkipRecord = false;
   while (m_pGenerationDataGroup->read(m_pBuffer,250,&m_lBufferLength))
   {
      strRecordType.assign(m_pBuffer,4);
      if (strRecordType == "EREC")
         bSkipRecord = true;
      if (bSkipRecord && strRecordType != "FREC" && strRecordType != "NREC")
         continue;
      if (strRecordType == "FHDR")
      {
         struct hFHDR* pFHDR = (struct hFHDR*)(m_pBuffer);
         char szTemp[9];
         memcpy(szTemp,pFHDR->sSettlementDate + 4,2); //Format: MMDDYY to YYYYMMDD
         szTemp[2] = '\0';
         int iYear = atoi(szTemp) + 2000;
         snprintf(szTemp,sizeof(szTemp),"%04d",iYear);
         memcpy(szTemp + 4,pFHDR->sSettlementDate,4);
         szTemp[8] = '\0';
         m_strDATE_RECON_NET.assign(szTemp); 
      }
      else if (strRecordType == "FREC" || strRecordType == "NREC")
      {
         bSkipRecord = false;
         if (!getColumn(PAN).empty() && !write())
            return false;
         struct hFREC_NREC* pFREC_NREC = (struct hFREC_NREC*)(m_pBuffer);
         m_strProcType[0] = pFREC_NREC->cProcessorType;
         setColumn(ROLE_IND, &pFREC_NREC->cProcessorType, 1);
         m_strAcqInstID.assign(pFREC_NREC->sAcqInstID,1,9);

         char szTemp[15];
         memcpy(szTemp,pFREC_NREC->sTransactionDate + 4,2); //Format: MMDDYY to YYYYMMDD
         szTemp[2] = '\0';
         int iYear = atoi(szTemp) + 2000;
         snprintf(szTemp,sizeof(szTemp),"%04d",iYear);
         memcpy(szTemp + 4,pFREC_NREC->sTransactionDate,4);
         memcpy(szTemp + 8,pFREC_NREC->sTransactionTime,6);
         szTemp[14] = '\0';
         setColumn(TSTAMP_LOCAL,szTemp,14);

         m_strPAN.assign(pFREC_NREC->sPAN,sizeof(pFREC_NREC->sPAN));
         KeyRing::instance()->tokenize(pFREC_NREC->sPAN,sizeof(pFREC_NREC->sPAN));
         setColumn(PAN,pFREC_NREC->sPAN,sizeof(pFREC_NREC->sPAN));

         string strTRAN_TYPE_ID;
         string strProcessCode;
         strProcessCode.assign(pFREC_NREC->sProcessCode,6);
         if (!ConfigurationRepository::instance()->translate("X_MC_PROC_CODE",strProcessCode,strTRAN_TYPE_ID,"","",-1,false))
            strTRAN_TYPE_ID = strProcessCode + "2000";
         setColumn(TRAN_TYPE_ID,strTRAN_TYPE_ID.c_str(),10);

         setColumn(RETRIEVAL_REF_NO,pFREC_NREC->sReferenceNumber,sizeof(pFREC_NREC->sReferenceNumber));
         setColumn(CARD_ACPT_TERM_ID,pFREC_NREC->sTerminalID,sizeof(pFREC_NREC->sTerminalID));
         setColumn(F_AMT0,pFREC_NREC->sAccessFee,sizeof(pFREC_NREC->sAccessFee));
         if(memcmp(pFREC_NREC->sAccessFee, "00000000", 8) == 0)
            setColumn(F_TYPE0, "00", 2);
         else
            setColumn(F_TYPE0, "70", 2);
         setColumn(CUR_RECON_NET,pFREC_NREC->sCurSettlement,sizeof(pFREC_NREC->sCurSettlement));
         setColumn(AMT_RECON_NET,pFREC_NREC->sAmtSettlement,sizeof(pFREC_NREC->sAmtSettlement));
         setColumn(ADL_RQST_AMT0, "00000000000000", 14);

         memset(szTemp,' ',15);
         memcpy(szTemp,pFREC_NREC->sAmtSettlement,12);
         szTemp[12] = '\0';
         double dAMT_RECON_NET = atof(szTemp);
         memcpy(szTemp,pFREC_NREC->sProcessCode,6);
         szTemp[6] = '\0';
         int iProcessCode = atoi(szTemp);
         memcpy(szTemp,pFREC_NREC->sResponseCode,2);
         szTemp[2] = '\0';
         int iResponseCode = atoi(szTemp);
         char cTranDisp = '1';
         if (strRecordType == "NREC")
         {
            if (iProcessCode == 0
               && memcmp(pFREC_NREC->sAdviceReasonCode,"45",2) != 0)
            {
               if (iResponseCode == 0
                  && memcmp(pFREC_NREC->sAdviceReasonCode,"       ",7) == 0)
                  cTranDisp = '1';
               if (iResponseCode > 0)
                  cTranDisp = '2';
            }
            if (memcmp(pFREC_NREC->sProcessCode,"30",2) == 0
               && memcmp(pFREC_NREC->sBrand + 2,"2",1) == 0)
               cTranDisp = '2';
            if (memcmp(pFREC_NREC->sProcessCode,"30",2) == 0
               && memcmp(pFREC_NREC->sBrand + 2,"2",1) != 0
               && iResponseCode == 0)
               cTranDisp = '1';
         }
         if (memcmp(pFREC_NREC->sResponseCode,"  ",2) == 0
            || memcmp(pFREC_NREC->sResponseCode,"10",2) == 0
            || memcmp(pFREC_NREC->sResponseCode,"87",2) == 0)
            cTranDisp = '1';
         if (iResponseCode > 0)
            cTranDisp = '2';
         if (iResponseCode == 0
            && memcmp(pFREC_NREC->sAdviceReasonCode,"       ",7) == 0)
            cTranDisp = '1';
         if (memcmp(pFREC_NREC->sAdviceReasonCode,"2",1) == 0)
         {
            if (memcmp(pFREC_NREC->sAdviceReasonCode + 3,"0010",4) == 0
               || memcmp(pFREC_NREC->sAdviceReasonCode + 3,"1010",4) == 0)
               cTranDisp = '3';
            else
               cTranDisp = '1';
         }
         if (memcmp(pFREC_NREC->sAdviceReasonCode + 3,"0010",4) == 0
            || memcmp(pFREC_NREC->sAdviceReasonCode + 3,"1010",4) == 0)
            cTranDisp = '3';
         if (strRecordType == "FREC")
            cTranDisp = '1';
         if (dAMT_RECON_NET == 0
            && memcmp(pFREC_NREC->sBrand + 2,"2",1) != 0
            && memcmp(pFREC_NREC->sAdviceReasonCode,"45",2) == 0)
            cTranDisp = '2';
         if (dAMT_RECON_NET == 0
            && memcmp(pFREC_NREC->sAdviceReasonCode,"45",2) == 0)
            cTranDisp = '3';
         if (iResponseCode == 0
            && memcmp(pFREC_NREC->sAdviceReasonCode,"400",3) == 0)
            cTranDisp = '3';
         setColumn(TRAN_DISPOSITION,&cTranDisp,1);
      }
      else if (strRecordType == "FPST")
      {
         struct hFPST* pFPST = (struct hFPST*)(m_pBuffer);
         m_strIssInstID.assign(pFPST->sIssInstID,1,9);
      }
      else if (strRecordType == "FEER")
      {
         struct hFEER* pFEER = (struct hFEER*)(m_pBuffer);
         string strInterChangeFee;
         if (pFEER->cExtdPrecisedItxFeeInd == 'C')
            strInterChangeFee.assign("-",1);
         strInterChangeFee.append(pFEER->sExtdPrecisedItxFee,sizeof(pFEER->sExtdPrecisedItxFee));
         setColumn(ADL_RQST_AMT0,strInterChangeFee.c_str(),strInterChangeFee.length());
      }
   }
   if (!write())
      return false;
   return TransactionActivityFile::reFormat();
  //## end reconciliationfile::MCDebitPINInterchangeFile::reFormat%641DCF2603A1.body
}

void MCDebitPINInterchangeFile::setMatch ()
{
  //## begin reconciliationfile::MCDebitPINInterchangeFile::setMatch%641DCF7A00DF.body preserve=yes
   ReconciliationDataset::setMatch();
   m_hFile.setSortByBIN(false);
   if (m_hFile.getMatch().empty())
   {
      m_hFile.setMatch("PAN");
      m_hFile.setMatch("RETRIEVAL_REF_NO");
      m_hFile.setMatch("TSTAMP_LOCAL");
      m_hFile.setMatch("TRAN_DISPOSITION");
      m_hFile.setMatch("AMT_RECON_NET");
      m_hFile.setMatch("F_AMT0");
   }
  //## end reconciliationfile::MCDebitPINInterchangeFile::setMatch%641DCF7A00DF.body
}

bool MCDebitPINInterchangeFile::write ()
{
  //## begin reconciliationfile::MCDebitPINInterchangeFile::write%641DCF9A000F.body preserve=yes
   if (!m_bFullReconciliation
      && (atof(getColumn(ADL_RQST_AMT0).c_str()) == 0) || getColumn(TRAN_TYPE_ID)[6] == '1')
      return true;
   setColumn(DATE_RECON_NET,m_strDATE_RECON_NET.c_str(),8);
   bool bFound = true;
   if (m_bEntityDetail)
   {
      m_hGenericSegment.reset();
      m_hGenericSegment.set("DATE_RECON_NET", m_strDATE_RECON_NET);
      m_hGenericSegment.set("INST_ID_ACQ", m_strAcqInstID);
      m_hGenericSegment.set("INST_ID_ISS", m_strIssInstID);
      m_hGenericSegment.set("PAN", m_strPAN);
      m_hGenericSegment.set("RETRIEVAL_REF_NO", getColumn(RETRIEVAL_REF_NO));
      m_hGenericSegment.set("TSTAMP_LOCAL", getColumn(TSTAMP_LOCAL));
      if (!m_pReformatAudit && m_bIntializeAudit)
         InterchangeFile::initializeAudit("MCIRFA", m_strDATE_RECON_NET);
      bFound = (m_strProcType == "A") ? lookupEntity(m_strAcqInstID) : lookupEntity(m_strIssInstID);
      m_hGenericSegment.reset();
   }
   if (bFound
      && getColumn(PAN) != "zzzzzzzzzzzzzzzz"
      && getColumn(PAN) != "ZZZZZZZZZZZZZZZZ")
   {
      if (!TransactionReportFile::write())
         return false;
   }
   string strPAN;
#ifdef MVS
   strPAN.resize(16,'Z');
#else
   strPAN.resize(16,'z');
#endif
   setColumn(PAN,strPAN.data(),16);//to omit records,if FEER comes along with any RecordType other than FREC/NREC
   m_strProcType.erase();
   m_strAcqInstID.erase();
   m_strIssInstID.erase();
   m_strPAN.wipe();
   return true;
  //## end reconciliationfile::MCDebitPINInterchangeFile::write%641DCF9A000F.body
}

// Additional Declarations
  //## begin reconciliationfile::MCDebitPINInterchangeFile%641DC0020137.declarations preserve=yes
  //## end reconciliationfile::MCDebitPINInterchangeFile%641DC0020137.declarations

} // namespace reconciliationfile

//## begin module%641DC320031D.epilog preserve=yes
//## end module%641DC320031D.epilog
