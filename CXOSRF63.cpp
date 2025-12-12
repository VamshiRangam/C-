//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%59BAA50A03CC.cm preserve=no
//## end module%59BAA50A03CC.cm

//## begin module%59BAA50A03CC.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%59BAA50A03CC.cp

//## Module: CXOSRF63%59BAA50A03CC; Package body
//## Subsystem: RFDLL%439873F400EA
//## Source file: C:\Repos\DataNavigatorServer\Windows\Build\Dn\Server\Library\Rfdll\CXOSRF63.cpp

//## begin module%59BAA50A03CC.additionalIncludes preserve=no
//## end module%59BAA50A03CC.additionalIncludes

//## begin module%59BAA50A03CC.includes preserve=yes
#include "CXODRF64.hpp"
#include "CXODRU37.hpp"
//## end module%59BAA50A03CC.includes

#ifndef CXOSIF05_h
#include "CXODIF05.hpp"
#endif
#ifndef CXOSRS78_h
#include "CXODRS78.hpp"
#endif
#ifndef CXOSMN05_h
#include "CXODMN05.hpp"
#endif
#ifndef CXOSRF48_h
#include "CXODRF48.hpp"
#endif
#ifndef CXOSTM04_h
#include "CXODTM04.hpp"
#endif
#ifndef CXOSIF28_h
#include "CXODIF28.hpp"
#endif
#ifndef CXOSNS40_h
#include "CXODNS40.hpp"
#endif
#ifndef CXOSCF01_h
#include "CXODCF01.hpp"
#endif
#ifndef CXOSIF04_h
#include "CXODIF04.hpp"
#endif
#ifndef CXOSRU40_h
#include "CXODRU40.hpp"
#endif
#ifndef CXOSCF61_h
#include "CXODCF61.hpp"
#endif
#ifndef CXOSRF63_h
#include "CXODRF63.hpp"
#endif


//## begin module%59BAA50A03CC.declarations preserve=no
//## end module%59BAA50A03CC.declarations

//## begin module%59BAA50A03CC.additionalDeclarations preserve=yes
//## end module%59BAA50A03CC.additionalDeclarations


//## Modelname: Reconciliation::ReconciliationFile_CAT%439754C1037A
namespace reconciliationfile {
//## begin reconciliationfile%439754C1037A.initialDeclarations preserve=yes
//## end reconciliationfile%439754C1037A.initialDeclarations

// Class reconciliationfile::NYCENetworkEDF 

NYCENetworkEDF::NYCENetworkEDF (const reusable::string& strClass)
  //## begin reconciliationfile::NYCENetworkEDF::NYCENetworkEDF%651C26EB00A6.hasinit preserve=no
  //## end reconciliationfile::NYCENetworkEDF::NYCENetworkEDF%651C26EB00A6.hasinit
  //## begin reconciliationfile::NYCENetworkEDF::NYCENetworkEDF%651C26EB00A6.initialization preserve=yes
  //## end reconciliationfile::NYCENetworkEDF::NYCENetworkEDF%651C26EB00A6.initialization
{
  //## begin reconciliationfile::NYCENetworkEDF::NYCENetworkEDF%651C26EB00A6.body preserve=yes
   memcpy(m_sID,"RF63",4);
   setClassName(strClass);
   m_hFile.setSortByBIN(false);
   m_hFile.setMatch("PAN_PREFIX");
   m_hFile.setMatch("RETRIEVAL_REF_NO");
   m_hFile.setMatch("TSTAMP_LOCAL");
   m_hFile.setMatch("CARD_ACPT_TERM_ID");
   m_hFile.setMatch("TRAN_DISPOSITION");
   m_hFile.setMatch("AMT_RECON_NET");
   ReconciliationDataset::setMatch();
   // external file (from NYCE Network EDF)
   setColumns(
      "MASKPAN"
      ",RETRIEVAL_REF_NO"
      ",TSTAMP_LOCAL"
      ",CARD_ACPT_TERM_ID"
      ",TRAN_DISPOSITION"
      ",AMT_RECON_NET"
      ",TSTAMP_TRANS"
      ",UNIQUENESS_KEY~5"
      ",TRAN_TYPE_ID"
      ",CUR_RECON_NET"
      ",F_AMTcb"
      ",F_AMT90"
      ",ROLE_IND",0
   );
   // internal file (custom TXNACT 6063)
   setColumns(
      "MASKPAN"
      ",RETRIEVAL_REF_NO"
      ",TSTAMP_LOCAL"
      ",CARD_ACPT_TERM_ID"
      ",TRAN_DISPOSITION"
      ",AMT_RECON_NET"
      ",TSTAMP_TRANS"
      ",UNIQUENESS_KEY~5"
      ",TRAN_TYPE_ID"
      ",CUR_RECON_NET"
      ",F_AMTcb"
      ",F_AMT90"
      ",PROC_ID_ACQ_B"
      ",PROC_ID_ISS_B"
      ",ROLE_IND",1
   );
  //## end reconciliationfile::NYCENetworkEDF::NYCENetworkEDF%651C26EB00A6.body
}


NYCENetworkEDF::~NYCENetworkEDF()
{
  //## begin reconciliationfile::NYCENetworkEDF::~NYCENetworkEDF%59BAA4570128_dest.body preserve=yes
  //## end reconciliationfile::NYCENetworkEDF::~NYCENetworkEDF%59BAA4570128_dest.body
}



//## Other Operations (implementation)
void NYCENetworkEDF::join (Query& hQuery, const char* pszTable)
{
  //## begin reconciliationfile::NYCENetworkEDF::join%65605CE40302.body preserve=yes
   hQuery.join(pszTable,"INNER","FIN_RECORD","TSTAMP_TRANS");
   hQuery.join(pszTable,"INNER","FIN_RECORD","UNIQUENESS_KEY");
   getRepository().bind2(hQuery,pszTable);
  //## end reconciliationfile::NYCENetworkEDF::join%65605CE40302.body
}

bool NYCENetworkEDF::reFormat ()
{
  //## begin reconciliationfile::NYCENetworkEDF::reFormat%59BAA4B70315.body preserve=yes
   if (!TransactionActivityFile::initReFormat())
      return false;
   char sPreviousRecord[sizeof(struct hEDF1)]; 
   memset(sPreviousRecord,' ',sizeof(struct hEDF1));
   struct hEDF0* pHeader = (struct hEDF0*)m_pBuffer;
   struct hEDF1* p = (struct hEDF1*)m_pBuffer;
   string strDATE_RECON_NET;
   string strTRAN_TYPE_ID;
   bool bSplit = false;
   int iYear = Clock::instance()->getYear();
   string strYYYYMMDDHHMMSS(Clock::instance()->getYYYYMMDDHHMMSS());
   char szYear[PERCENTD];
   string strTSTAMP_LOCAL;
   string strTRAN_DISPOSITION("1",1);
   string strTemp;
   while (m_pGenerationDataGroup->read(m_pBuffer,1024,&m_lBufferLength))
   {
      if (memcmp(m_pBuffer,"FH      ",8) == 0)
      {
         m_strDATE_RECON.assign(m_pBuffer + 8,8);
         continue;
      }
      if (m_pBuffer[28] == ',')
         bSplit = true;
      if (bSplit)
      {
         write(m_pBuffer,m_lBufferLength);
         continue;
      }
      if (strDATE_RECON_NET.empty()
         && pHeader->cRecordPart == '0'
         && pHeader->cFormatCode == 'Y')
      {
         strDATE_RECON_NET.assign(pHeader->sDATE_RECON_NET,8);
         m_strDATE_RECON.assign(pHeader->sDATE_RECON_NET,8);
         continue;
      }
      if (p->cRecordPart != '1')
         continue;
      if (memcmp(m_pBuffer,sPreviousRecord,174) == 0
         && memcmp(m_pBuffer+229,sPreviousRecord+229,44) == 0)
         continue;
      if (memcmp(p->sMTI,"0211",4) == 0) //exclude adjustments
         continue;
      Mask::maskPan(p->sPAN,sizeof(p->sPAN),6);
      setColumn(PAN,p->sPAN,sizeof(p->sPAN));
      setColumn(RETRIEVAL_REF_NO,p->sRETRIEVAL_REF_NO,12);
      int i = iYear;
      if (strYYYYMMDDHHMMSS.substr(4,2) == "01"
         && memcmp(p->sTerminalDate,"01",2) > 0)
         --i;
      strTSTAMP_LOCAL.assign(szYear,snprintf(szYear,sizeof(szYear),"%04d",i));
      strTSTAMP_LOCAL.append(p->sTerminalDate,4);
      strTSTAMP_LOCAL.append(p->sTerminalTime,6);
      setColumn(TSTAMP_LOCAL,strTSTAMP_LOCAL.c_str(),14);
      setColumn(CARD_ACPT_TERM_ID,p->sCARD_ACPT_TERM_ID,8);
      if (p->cResponseCode == 'D')
         strTRAN_DISPOSITION = '2';
      else
      if (p->cResponseCode == 'F'
         || p->cResponseCode == 'P')
         strTRAN_DISPOSITION = '3';
      else
         strTRAN_DISPOSITION = '1';
      setColumn(TRAN_DISPOSITION,strTRAN_DISPOSITION.c_str(),1);
      strTemp.assign(p->sTRAN_TYPE_ID,2);
      if (!configuration::ConfigurationRepository::instance()->translate("X_NYCE_PROC_CODE",strTemp,strTRAN_TYPE_ID," "," ",0,false))
         continue;
      if (strTRAN_TYPE_ID[6] != '2')
         continue;
      setColumn(TRAN_TYPE_ID,strTRAN_TYPE_ID.data(),10);
      char szTemp[19];
      NetworkSegment x;
      double dAMT_RECON_NET = x.asDouble(p->sAMT_RECON_NET,13);
      double dF_AMT = x.asDouble(p->sSurchargeRebateAmount,7); //9(5)v99
      dAMT_RECON_NET -= dF_AMT;
      snprintf(szTemp,sizeof(szTemp),"%018.0f",dAMT_RECON_NET);
      setColumn(AMT_RECON_NET,szTemp,18);
      snprintf(szTemp,sizeof(szTemp),"%010.0f",dF_AMT);
      setColumn(F_AMTcb,szTemp,10);
      setColumn(CUR_RECON_NET,p->sSettleCurrencyCode,3);
      memset(szTemp,'0',3);
      if (p->cROLE_IND == 'A')
         memcpy(szTemp + 3,p->sTerminalICHAmount,7);
      else
         memcpy(szTemp + 3,p->sIssuerICHAmount,7);
      setColumn(F_AMT90,szTemp,10);
      setColumn(ROLE_IND,&p->cROLE_IND,1);
      memcpy(sPreviousRecord,m_pBuffer,sizeof(struct hEDF1));
      if (!write())
         return false;
   }
   return TransactionActivityFile::reFormat();
  //## end reconciliationfile::NYCENetworkEDF::reFormat%59BAA4B70315.body
}

void NYCENetworkEDF::setBasicPredicate (Query& hQuery, const string& strTable, int iBegin, int iEnd, int iEntity)
{
  //## begin reconciliationfile::NYCENetworkEDF::setBasicPredicate%62AB5D010186.body preserve=yes
   hQuery.setBasicPredicate(strTable.c_str(),"TRAN_TYPE_ID","LIKE","______2___");
   TransactionReportFile::setBasicPredicate(hQuery,strTable,iBegin,iEnd,iEntity);
  //## end reconciliationfile::NYCENetworkEDF::setBasicPredicate%62AB5D010186.body
}

void NYCENetworkEDF::setMatch ()
{
  //## begin reconciliationfile::NYCENetworkEDF::setMatch%62BDE2950093.body preserve=yes
   ReconciliationDataset::setMatch();
  //## end reconciliationfile::NYCENetworkEDF::setMatch%62BDE2950093.body
}

void NYCENetworkEDF::setOrderByClause (Query& hQuery)
{
  //## begin reconciliationfile::NYCENetworkEDF::setOrderByClause%62BDE28103AB.body preserve=yes
   TransactionReportFile::setOrderByClause(hQuery);  //do not override because will not sync with match criteria if overridden with DSPEC
  //## end reconciliationfile::NYCENetworkEDF::setOrderByClause%62BDE28103AB.body
}

// Additional Declarations
  //## begin reconciliationfile::NYCENetworkEDF%59BAA4570128.declarations preserve=yes
  //## end reconciliationfile::NYCENetworkEDF%59BAA4570128.declarations

} // namespace reconciliationfile

//## begin module%59BAA50A03CC.epilog preserve=yes
//## end module%59BAA50A03CC.epilog
