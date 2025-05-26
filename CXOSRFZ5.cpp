//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%62EA6D57020F.cm preserve=no
//## end module%62EA6D57020F.cm

//## begin module%62EA6D57020F.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%62EA6D57020F.cp

//## Module: CXOSRF79%62EA6D57020F; Package body
//## Subsystem: RFDLL%439873F400EA
//## Source file: C:\Repos\DataNavigatorServer\Windows\Build\Dn\Server\Library\Rfdll\CXOSRF79.cpp

//## begin module%62EA6D57020F.additionalIncludes preserve=no
//## end module%62EA6D57020F.additionalIncludes

//## begin module%62EA6D57020F.includes preserve=yes
#include "CXODRF57.hpp"
#include "CXODIF26.hpp"
#include "CXODRU40.hpp"
#include "CXODCF61.hpp"
#include "CXODBS23.hpp"
//## end module%62EA6D57020F.includes

#ifndef CXOSNS40_h
#include "CXODNS40.hpp"
#endif
#ifndef CXOSTM06_h
#include "CXODTM06.hpp"
#endif
#ifndef CXOSCF01_h
#include "CXODCF01.hpp"
#endif
#ifndef CXOSEX17_h
#include "CXODEX17.hpp"
#endif
#ifndef CXOSES48_h
#include "CXODES48.hpp"
#endif
#ifndef CXOSDB24_h
#include "CXODDB24.hpp"
#endif
#ifndef CXOSDB02_h
#include "CXODDB02.hpp"
#endif
#ifndef CXOSRU54_h
#include "CXODRU54.hpp"
#endif
#ifndef CXOSRU12_h
#include "CXODRU12.hpp"
#endif
#ifndef CXOSRFZ5_h
#include "CXODRFZ5.hpp"
#endif


//## begin module%62EA6D57020F.declarations preserve=no
//## end module%62EA6D57020F.declarations

//## begin module%62EA6D57020F.additionalDeclarations preserve=yes
//## end module%62EA6D57020F.additionalDeclarations


//## Modelname: Reconciliation::ReconciliationFile_CAT%439754C1037A
namespace reconciliationfile {
//## begin reconciliationfile%439754C1037A.initialDeclarations preserve=yes
//## end reconciliationfile%439754C1037A.initialDeclarations

// Class reconciliationfile::VisaSMSInterchangeFile 

VisaSMSInterchangeFile::VisaSMSInterchangeFile (const string& strClass)
  //## begin reconciliationfile::VisaSMSInterchangeFile::VisaSMSInterchangeFile%64F1EA9F0063.hasinit preserve=no
  //## end reconciliationfile::VisaSMSInterchangeFile::VisaSMSInterchangeFile%64F1EA9F0063.hasinit
  //## begin reconciliationfile::VisaSMSInterchangeFile::VisaSMSInterchangeFile%64F1EA9F0063.initialization preserve=yes
   :InterchangeFile(strClass)
  //## end reconciliationfile::VisaSMSInterchangeFile::VisaSMSInterchangeFile%64F1EA9F0063.initialization
{
  //## begin reconciliationfile::VisaSMSInterchangeFile::VisaSMSInterchangeFile%64F1EA9F0063.body preserve=yes
   memcpy(m_sID, "RFZ5", 4);
   m_strDX_FILE_TYPE.assign("VNTIXE", 6);
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
      ",SYS_TRACE_AUDIT_NO"
      ",ROLE_IND"
      ",F_TYPE0"
   );
   m_bIncludeSurcharge = true;
  //## end reconciliationfile::VisaSMSInterchangeFile::VisaSMSInterchangeFile%64F1EA9F0063.body
}


VisaSMSInterchangeFile::~VisaSMSInterchangeFile()
{
  //## begin reconciliationfile::VisaSMSInterchangeFile::~VisaSMSInterchangeFile%62EA6C6C0280_dest.body preserve=yes
  //## end reconciliationfile::VisaSMSInterchangeFile::~VisaSMSInterchangeFile%62EA6C6C0280_dest.body
}



//## Other Operations (implementation)
bool VisaSMSInterchangeFile::reFormat ()
{
  //## begin reconciliationfile::VisaSMSInterchangeFile::reFormat%62EBF3500042.body preserve=yes
   if (!InterchangeFile::initReFormat())
      return false;
   string strTRAN_TYPE_ID;
   string strDATE_RECON_NET("20000000");
   memset(m_pBuffer,' ',168);
   int iOffset = 0;
   string strRecordType("V22000");
   bool bAuthorization = false;
   while (m_pGenerationDataGroup->read(m_pBuffer,170,&m_lBufferLength))
   {
      if (memcmp(m_pBuffer,"90",2) == 0
         || memcmp(m_pBuffer,"91",2) == 0
         || memcmp(m_pBuffer,"92",2) == 0)
         continue;
      if (m_lBufferLength == 168)
         iOffset = 34;
      if (memcmp(m_pBuffer + iOffset,"V2",2) != 0)
         continue;
      if (memcmp(m_pBuffer + iOffset,strRecordType.data(),6) < 0)
      {
         bAuthorization = false;
         if (!write())
            return false;
      }
      strRecordType.assign(m_pBuffer + iOffset,6);
      if (bAuthorization)
         continue;
      if (strRecordType == "V22120")
      {
         struct hV22120* pV22120 = (struct hV22120*)(m_pBuffer + iOffset);
         m_strSRE.assign(pV22120->sSRE, 10);
      }
      else
      if (strRecordType == "V22200")
      {
         struct hV22200* pV22200 = (struct hV22200*)(m_pBuffer + iOffset);
         m_strRole[0] = pV22200->cIssuerAcquirerIndicator;
         setColumn(ROLE_IND, &pV22200->cIssuerAcquirerIndicator, 1);
         m_strProcessingCode.assign(pV22200->sProcessingCode,6);
         if (!ConfigurationRepository::instance()->translate("X_VISA_PROC_CODE",m_strProcessingCode,strTRAN_TYPE_ID,"","",-1,false))
         {
            strTRAN_TYPE_ID = m_strProcessingCode; 
            strTRAN_TYPE_ID.append("2000");
         }
         bAuthorization = strTRAN_TYPE_ID[6] == '1';
         if (bAuthorization)
            continue;
         setColumn(TRAN_TYPE_ID,strTRAN_TYPE_ID.data(),strTRAN_TYPE_ID.length());
         if (memcmp(pV22200->sResponseCode,"00",2) == 0
            || memcmp(pV22200->sResponseCode,"10",2) == 0
            || memcmp(pV22200->sResponseCode,"11",2) == 0
            || memcmp(pV22200->sResponseCode,"76",2) == 0)
            setColumn(TRAN_DISPOSITION,"1",1);
         else
            setColumn(TRAN_DISPOSITION,"2",1);
         formatAmount(pV22200->sTransactionAmount,sizeof(pV22200->sTransactionAmount));
         if (!memcmp(pV22200->sCardNumber,"000000",6))
            continue;
         m_strPAN.assign(pV22200->sCardNumber, 16);
         KeyRing::instance()->tokenize(pV22200->sCardNumber,16);
         setColumn(PAN,pV22200->sCardNumber,16);
         setColumn(RETRIEVAL_REF_NO,pV22200->sRetrievalReferenceNumber,12);
         setColumn(SYS_TRACE_AUDIT_NO,pV22200->sTraceNumber,6);
         strDATE_RECON_NET.replace(2,2,pV22200->sSettlementDate + 4,2);
         strDATE_RECON_NET.replace(4,4,pV22200->sSettlementDate,4);
         Date hDate(strDATE_RECON_NET.c_str());
         hDate -= 1;
         setColumn(DATE_RECON_NET,hDate.asString("%Y%m%d").data(),8);
         setColumn(AMT_RECON_NET,pV22200->sTransactionAmount,12);
         setColumn(CUR_RECON_NET,pV22200->sCurrencyCode,3);
         setColumn(F_AMT0, "00000000", 8);
         setColumn(ADL_RQST_AMT0, "0000000000000000", 16);
      }
      else
      if (strRecordType == "V22210")
      {
         struct hV22210* pV22210 = (struct hV22210*)(m_pBuffer + iOffset);
         Date hDate(getColumn(DATE_RECON_NET).c_str());
         char szTemp[PERCENTD + 5];
         int iYear = hDate.getYear();
         memcpy(szTemp,pV22210->sLocalTransactionDate,2);
         szTemp[2] = '\0';
         int iMonth = atoi(szTemp);
         if (iMonth == 12
            && hDate.getMonth() == 1)
            --iYear;
         else
         if (iMonth == 1 
            && hDate.getMonth() == 12)
            ++iYear;
         snprintf(szTemp,sizeof(szTemp),"%04d",iYear);
         memcpy(szTemp + 4,pV22210->sLocalTransactionDate,4);
         memcpy(szTemp + 8,pV22210->sLocalTransactionTime,6);
         szTemp[14] = '\0';
         setColumn(TSTAMP_LOCAL,szTemp,14);
         if (memcmp(pV22210->sMessageReasonCode,"2502",4) == 0)
            m_strResponseMessageType.assign("0400",4);
         else
            m_strResponseMessageType.assign(pV22210->sResponseMessageType,4);
      }
      else
      if (strRecordType == "V22220")
      {
         struct hV22220* pV22220 = (struct hV22220*)(m_pBuffer + iOffset);
         setColumn(CARD_ACPT_TERM_ID,pV22220->sCardAcceptorTerminalID,8);
         m_strPOSConditionCode.assign(pV22220->sPOSConditionCode,2);
      }
      else
      if (strRecordType == "V22250")
      {
         struct hV22250* pV22250 = (struct hV22250*)(m_pBuffer + iOffset);
         formatAmount(pV22250->sSurchargeAmount, sizeof(pV22250->sSurchargeAmount));
         setColumn(F_AMT0, pV22250->sSurchargeAmount, 8);
         if (memcmp(pV22250->sSurchargeAmount, "00000000", 8) == 0)
            setColumn(F_TYPE0, "00", 2);
         else
            setColumn(F_TYPE0, "70", 2);
      }
      else
      if (strRecordType == "V22261")
      {
         struct hV22261* pV22261 = (struct hV22261*)(m_pBuffer + iOffset);
         if (pV22261->cReimbursementFeeImpact != ' ')
         {
            string strInterChangeFee;
            if (pV22261->cReimbursementFeeImpact == 'C')
               strInterChangeFee.assign("-",1);
            formatAmount(pV22261->sReimbursementFee,sizeof(pV22261->sReimbursementFee));
            strInterChangeFee.append(pV22261->sReimbursementFee,15);
            setColumn(ADL_RQST_AMT0,strInterChangeFee.c_str(),strInterChangeFee.length());
         }
      }
   }
   if (write() == false)
      return false;
   return TransactionActivityFile::reFormat();
  //## end reconciliationfile::VisaSMSInterchangeFile::reFormat%62EBF3500042.body
}

void VisaSMSInterchangeFile::setMatch ()
{
  //## begin reconciliationfile::VisaSMSInterchangeFile::setMatch%63595F9A01AB.body preserve=yes
   ReconciliationDataset::setMatch();
   m_hFile.setSortByBIN(false);
   if (m_hFile.getMatch().empty())
   {
      m_hFile.setMatch("PAN");
      m_hFile.setMatch("RETRIEVAL_REF_NO");
      m_hFile.setMatch("TRAN_DISPOSITION");
      m_hFile.setMatch("AMT_RECON_NET");
      m_hFile.setMatch("F_AMT0");
   }
  //## end reconciliationfile::VisaSMSInterchangeFile::setMatch%63595F9A01AB.body
}

void VisaSMSInterchangeFile::setOrderByClause (Query& hQuery)
{
  //## begin reconciliationfile::VisaSMSInterchangeFile::setOrderByClause%62ED550E002B.body preserve=yes
   if (m_hFile.setOrderByClause(hQuery))
   {
      string strOrderByClause(hQuery.getOrderByClause());
      size_t pos = strOrderByClause.find("PAN_PREFIX");
      if (pos != string::npos)
         strOrderByClause.erase(pos + 3,7);
      if (strOrderByClause.find("AMT_RECON_NET") == string::npos)
         strOrderByClause.append(",AMT_RECON_NET");
      pos = strOrderByClause.find(",F_AMT0");
      if (pos != string::npos)
         strOrderByClause.replace(pos, 7, ",F_AMT_RECON_NET0");
      hQuery.setOrderByClause(strOrderByClause);
   }
  //## end reconciliationfile::VisaSMSInterchangeFile::setOrderByClause%62ED550E002B.body
}

bool VisaSMSInterchangeFile::write ()
{
  //## begin reconciliationfile::VisaSMSInterchangeFile::write%62ECBBCF0030.body preserve=yes
   if (!m_bFullReconciliation
      && atof(getColumn(ADL_RQST_AMT0).c_str()) == 0)
      return true;
   if (getColumn(DATE_RECON_NET).empty()
      || getColumn(TRAN_TYPE_ID).empty())
      return true;
   if (m_strResponseMessageType == "0422"
      || m_strResponseMessageType == "0432"
      || m_strResponseMessageType == "0480"
      || m_strResponseMessageType == "0490")
      return true;
   if (m_strResponseMessageType == "0220"
      || m_strResponseMessageType == "0282"
      || m_strResponseMessageType == "0292"
      || (m_strResponseMessageType == "0230" && m_strPOSConditionCode == "13"))
      return true;
   if (m_strProcessingCode.length() >= 2
      && memcmp(m_strProcessingCode.data(),"29",2) == 0)
      return true;
   if (m_strSRE.empty() == false && m_bEntityDetail)
   {
      m_hGenericSegment.reset();
      m_hGenericSegment.set("DATE_RECON_NET", getColumn(DATE_RECON_NET));
      m_hGenericSegment.set("PAN", m_strPAN);
      m_hGenericSegment.set("RETRIEVAL_REF_NO", getColumn(RETRIEVAL_REF_NO));
      m_hGenericSegment.set("TSTAMP_LOCAL", getColumn(TSTAMP_LOCAL));
      if (m_strRole[0] == 'I')
      {
         m_hGenericSegment.set("INST_ID_ISS", m_strSRE);
         m_hGenericSegment.set("INST_ID_ACQ", " ");
      }
      else
      {
         m_hGenericSegment.set("INST_ID_ACQ", m_strSRE);
         m_hGenericSegment.set("INST_ID_ISS", " ");
      }
      if (!m_pReformatAudit && m_bIntializeAudit)
         InterchangeFile::initializeAudit("VNTRFA", getColumn(DATE_RECON_NET));
      if (NetworkInstitution::getINST_ID("VNT", m_strSRE, "", "", "", m_strINST_ID))
      {
         if (ConfigurationRepository::instance()->translate("INSTITUTION", m_strINST_ID, m_strPROC_ID, "", "", -1, false) == false)
         {
            if (m_pReformatAudit)
               m_pReformatAudit->report(m_strRole[0]);
            return false;
         }
      }
      else
      {
         if (m_pReformatAudit)
            m_pReformatAudit->report(m_strRole[0]);
         return true;
      }
      m_hGenericSegment.reset();
   }
   if (m_strResponseMessageType == "0400"
      || m_strResponseMessageType == "0410"
      || m_strResponseMessageType == "0420"
      || m_strResponseMessageType == "0430")
      setColumn(TRAN_DISPOSITION,"3",1);
    if(getColumn(TRAN_DISPOSITION) == "2")
      setColumn(AMT_RECON_NET, "000000000000", 12);
   if (TransactionReportFile::write() == false)
      return false;
   m_strResponseCode.erase();
   m_strResponseMessageType.erase();
   m_strPOSConditionCode.erase();
   m_strProcessingCode.erase();
   m_strRole.erase();
   m_strPAN.wipe();
   return true;
  //## end reconciliationfile::VisaSMSInterchangeFile::write%62ECBBCF0030.body
}

// Additional Declarations
  //## begin reconciliationfile::VisaSMSInterchangeFile%62EA6C6C0280.declarations preserve=yes
void VisaSMSInterchangeFile::join (Query& hQuery, const char* pszTable)
{
   hQuery.join(pszTable, "INNER", "FIN_RECORD", "TSTAMP_TRANS");
   hQuery.join(pszTable, "INNER", "FIN_RECORD", "UNIQUENESS_KEY");
   getRepository().bind2(hQuery, pszTable);
}
  //## end reconciliationfile::VisaSMSInterchangeFile%62EA6C6C0280.declarations

} // namespace reconciliationfile

//## begin module%62EA6D57020F.epilog preserve=yes
//## end module%62EA6D57020F.epilog
