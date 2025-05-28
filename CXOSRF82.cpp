//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%63FEFF8701EC.cm preserve=no
//## end module%63FEFF8701EC.cm

//## begin module%63FEFF8701EC.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%63FEFF8701EC.cp

//## Module: CXOSRF82%63FEFF8701EC; Package body
//## Subsystem: RFDLL%439873F400EA
//## Source file: C:\Repos\datanavigatorserver\Windows\Build\Dn\Server\Library\Rfdll\CXOSRF82.cpp

//## begin module%63FEFF8701EC.additionalIncludes preserve=no
//## end module%63FEFF8701EC.additionalIncludes

//## begin module%63FEFF8701EC.includes preserve=yes
#define STS_DUPLICATE_RECORD 35
#include <stddef.h>
#include <math.h>
#include "CXODRF50.hpp"
#include "CXODIF03.hpp"
#include "CXODRU40.hpp"
#include "CXODUS21.hpp"
//## end module%63FEFF8701EC.includes

#ifndef CXOSRU12_h
#include "CXODRU12.hpp"
#endif
#ifndef CXOSRU54_h
#include "CXODRU54.hpp"
#endif
#ifndef CXOSDB02_h
#include "CXODDB02.hpp"
#endif
#ifndef CXOSDB24_h
#include "CXODDB24.hpp"
#endif
#ifndef CXOSTM06_h
#include "CXODTM06.hpp"
#endif
#ifndef CXOSNS40_h
#include "CXODNS40.hpp"
#endif
#ifndef CXOSRF73_h
#include "CXODRF73.hpp"
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
#ifndef CXOSIF16_h
#include "CXODIF16.hpp"
#endif
#ifndef CXOSDB01_h
#include "CXODDB01.hpp"
#endif
#ifndef CXOSRU08_h
#include "CXODRU08.hpp"
#endif
#ifndef CXOSTM04_h
#include "CXODTM04.hpp"
#endif
#ifndef CXOSDB25_h
#include "CXODDB25.hpp"
#endif
#ifndef CXOSRF82_h
#include "CXODRF82.hpp"
#endif


//## begin module%63FEFF8701EC.declarations preserve=no
//## end module%63FEFF8701EC.declarations

//## begin module%63FEFF8701EC.additionalDeclarations preserve=yes
//## end module%63FEFF8701EC.additionalDeclarations


//## Modelname: Reconciliation::ReconciliationFile_CAT%439754C1037A
namespace reconciliationfile {
//## begin reconciliationfile%439754C1037A.initialDeclarations preserve=yes
//## end reconciliationfile%439754C1037A.initialDeclarations

// Class reconciliationfile::InterchangeFile 

InterchangeFile::InterchangeFile()
  //## begin InterchangeFile::InterchangeFile%63FF0039038C_const.hasinit preserve=no
      : m_dADL_RQST_AMT0(0),
        m_bEntityDetail(false),
        m_bFullReconciliation(false),
        m_bIntializeAudit(true)
  //## end InterchangeFile::InterchangeFile%63FF0039038C_const.hasinit
  //## begin InterchangeFile::InterchangeFile%63FF0039038C_const.initialization preserve=yes
  //## end InterchangeFile::InterchangeFile%63FF0039038C_const.initialization
{
  //## begin reconciliationfile::InterchangeFile::InterchangeFile%63FF0039038C_const.body preserve=yes
   for (int i = 0; i < 2; i++)
      m_pPostingFile[i] = 0;
  //## end reconciliationfile::InterchangeFile::InterchangeFile%63FF0039038C_const.body
}

InterchangeFile::InterchangeFile (const string& strClass)
  //## begin reconciliationfile::InterchangeFile::InterchangeFile%64F1EDAE0085.hasinit preserve=no
      : m_dADL_RQST_AMT0(0),
        m_bEntityDetail(false),
        m_bFullReconciliation(false),
        m_bIntializeAudit(true)
  //## end reconciliationfile::InterchangeFile::InterchangeFile%64F1EDAE0085.hasinit
  //## begin reconciliationfile::InterchangeFile::InterchangeFile%64F1EDAE0085.initialization preserve=yes
  //## end reconciliationfile::InterchangeFile::InterchangeFile%64F1EDAE0085.initialization
{
  //## begin reconciliationfile::InterchangeFile::InterchangeFile%64F1EDAE0085.body preserve=yes
   for (int i = 0; i < 2; i++)
      m_pPostingFile[i] = 0;
   setClassName(strClass);
   string strKey("DSPEC   ", 8);
   strKey.append(getClassName());
   strKey.resize(16, ' ');
   strKey.append("ENTITY_DETAIL~YES", 17);
   string strRecord;
   m_bEntityDetail = (IF::Extract::instance()->getRecord(strKey.c_str(), strRecord));
   string strKey1("DSPEC   ", 8);
   strKey1.append(getClassName());
   strKey1.resize(16, ' ');
   strKey1.append("FULL_RECON~YES", 14);
   m_bFullReconciliation = (IF::Extract::instance()->getRecord(strKey1.c_str(), strRecord));
   string strKey2("DSPEC   ", 8);
   strKey2.append(getClassName());
   strKey2.resize(16, ' ');
   strKey2.append("AUDIT~NO", 8);
   m_bIntializeAudit = !(IF::Extract::instance()->getRecord(strKey2.c_str(), strRecord));
  //## end reconciliationfile::InterchangeFile::InterchangeFile%64F1EDAE0085.body
}


InterchangeFile::~InterchangeFile()
{
  //## begin reconciliationfile::InterchangeFile::~InterchangeFile%63FF0039038C_dest.body preserve=yes
   for (int i = 0; i < 2; i++)
      delete m_pPostingFile[i];
  //## end reconciliationfile::InterchangeFile::~InterchangeFile%63FF0039038C_dest.body
}



//## Other Operations (implementation)
bool InterchangeFile::apply ()
{
  //## begin reconciliationfile::InterchangeFile::apply%63FF01ED012A.body preserve=yes
   post(m_hRepository);
   return ReconciliationDataset::apply();
  //## end reconciliationfile::InterchangeFile::apply%63FF01ED012A.body
}

bool InterchangeFile::applyExtra ()
{
  //## begin reconciliationfile::InterchangeFile::applyExtra%63FF021901D4.body preserve=yes
   if (m_bFullReconciliation)
   {
      if (!ReconciliationDataset::applyExtra())
         return false;
      if (m_bPriorException)
         return post(m_hPrior);
   }
   string strTSTAMP_LOCAL(m_hFile.getTSTAMP_LOCAL());
   string strDATE_RECON(FileControl::instance()->getDATE_RECON(),0,6);
   Date hDate(strTSTAMP_LOCAL.c_str());
   vector<string> hMonths;
   vector<string>::iterator p;
   hMonths.push_back(strTSTAMP_LOCAL.substr(0, 6));
   hDate.incrementMonth(-1);
   hMonths.push_back(hDate.asString("%Y%m"));
   hDate.incrementMonth(2);
   hMonths.push_back(hDate.asString("%Y%m"));
   p = find(hMonths.begin(), hMonths.end(), strDATE_RECON);
   if (p == hMonths.end())
      hMonths.push_back(strDATE_RECON);
   settlement::ReconciliationSegment x(m_hRepository);
   bool bFound = false;
   for (int i = 0; i < hMonths.size(); i++)
   {
      string strLocator("FIN_L");
      strLocator.append(hMonths[i]);
      string strAmount("FIN_AMOUNT");
      strAmount.append(hMonths[i]);
      if (DataModel::instance()->isPresent(strLocator))
      {
         Query hQuery;
         getRepository().bindLocator(hQuery, strLocator.c_str());
         if (m_bIncludeSurcharge)
         {
            hQuery.join(strLocator.c_str(), "INNER", "FIN_RECORD", "TSTAMP_TRANS");
            hQuery.join(strLocator.c_str(), "INNER", "FIN_RECORD", "UNIQUENESS_KEY");
            getRepository().bindFee(hQuery, strLocator.c_str());
         }
         hQuery.join(strLocator.c_str(), "LEFT OUTER", strAmount.c_str(), "TSTAMP_TRANS");
         hQuery.join(strLocator.c_str(), "LEFT OUTER", strAmount.c_str(), "UNIQUENESS_KEY");
         hQuery.join(0, "LEFT OUTER", strAmount.c_str(), "FE01", "TOTAL_TYPE");
         for (int j = 0; j < m_hFile.getMatch().size(); j++)
         {
            if (m_bIncludeSurcharge
               && strcmp(m_hFile.getMatch()[j].getColumn().c_str(), "F_AMT0") == 0)
               continue;
            if (strcmp(m_hFile.getMatch()[j].getColumn().c_str(), "PAN") == 0
               && m_hFile.getMaskedPAN())
            {
               hQuery.setBasicPredicate(strLocator.c_str(), "PAN_PREFIX", "=", m_hFile.getPAN_PREFIX().c_str());
            }
            else
            {
               string strValue;
               m_hFile.getFieldByIndex(m_hFile.getMatch()[j].getIndex(), strValue);
               if (m_bIncludeSurcharge
                  && strcmp(m_hFile.getMatch()[j].getColumn().c_str(), "AMT_RECON_NET") == 0)
               {
                  if (hQuery.getSearchCondition().length() > 0)
                     hQuery.getSearchCondition().append(" AND ", 5);
                  string strTemp("(", 1);
                  strTemp.append(strLocator.data(), strLocator.length());
                  strTemp.append(".AMT_RECON_NET ", 15);
                  strTemp.append(m_hFile.getTRAN_DISPOSITION() == "3" ? "- " : "+ " ,2);
                  strTemp.append("CASE ", 5);
                  for (int i = 0; i < 6; i++)
                  {
                     char szIndex[2];
                     snprintf(szIndex, sizeof(szIndex), "%d", i);
                     strTemp.append("WHEN ", 5);
                     strTemp.append(strLocator.data(), strLocator.length());
                     strTemp.append(".CUR_RECON_NET = FIN_RECORD.F_CUR_CODE", 38);
                     strTemp.append(szIndex, 1);
                     strTemp.append(" AND FIN_RECORD.F_TYPE", 22);
                     strTemp.append(szIndex, 1);
                     strTemp.append(" = '70' ", 8);
                     strTemp.append("THEN FIN_RECORD.F_AMT", 21);
                     strTemp.append(szIndex, 1);
                     strTemp.append(" ", 1);
                     strTemp.append("WHEN ", 5);
                     strTemp.append(strLocator.data(), strLocator.length());
                     strTemp.append(".CUR_RECON_NET != FIN_RECORD.F_CUR_CODE", 39);
                     strTemp.append(szIndex, 1);
                     strTemp.append(" AND FIN_RECORD.F_TYPE", 22);
                     strTemp.append(szIndex, 1);
                     strTemp.append(" = '70' ", 8);
                     strTemp.append("THEN FIN_RECORD.F_AMT_RECON_NET", 31);
                     strTemp.append(szIndex, 1);
                     strTemp.append(" ", 1);
                  }
                  strTemp.append("ELSE 0 END ", 11);
                  strTemp.append("= ", 2);
                  strTemp.append(strValue.data(), strValue.length());
                  strTemp.append(")", 1);
                  hQuery.getSearchCondition().append(strTemp.data(), strTemp.length());
               }
               else
                  hQuery.setBasicPredicate(strLocator.c_str(), m_hFile.getMatch()[j].getColumn().c_str(), "=", strValue.c_str());
            }
         }
         hQuery.setBasicPredicate(strLocator.c_str(), "FUNC_CODE", "NOT LIKE", "1%");
         hQuery.setBasicPredicate(strAmount.c_str(), "TSTAMP_TRANS", "IS NULL");
         auto_ptr<reusable::SelectStatement> pSelectStatement((reusable::SelectStatement*)database::DatabaseFactory::instance()->create("SelectStatement"));
         if (pSelectStatement->execute(hQuery) == true
            && pSelectStatement->getRows() == 1)
         {
            bFound = true;
            if (m_bIncludeSurcharge)
               m_hRepository.setAmountsWithSurcharge();
            post(m_hRepository);
            break;
         }
      }
   }
   m_hRepository = x;
   if (bFound == false)
   {
      post(m_hFile, 1);
   }
   return true;
  //## end reconciliationfile::InterchangeFile::applyExtra%63FF021901D4.body
}

bool InterchangeFile::applyFees (ReconciliationSegment& hRepository)
{
  //## begin reconciliationfile::InterchangeFile::applyFees%63FF04820352.body preserve=yes
   string strName("FIN_AMOUNTyyyymm");
   strName.replace(10, 6, hRepository.getTSTAMP_TRANS().data(), 6);
   Table hTable(strName.c_str());
   hTable.set("TSTAMP_TRANS", hRepository.getTSTAMP_TRANS(), false, true);
   hTable.set("UNIQUENESS_KEY", hRepository.getUNIQUENESS_KEY(), true);
   hTable.set("TSTAMP_TRAIL", Clock::instance()->getYYYYMMDDHHMMSSHN());
   hTable.set("TOTAL_TYPE","FE01",false,true);
   hTable.set("INSERT_SEQUENCE_NO", (int)0);
   hTable.set("DATE_RECON_NET", m_hFile.getDATE_RECON_NET());
   hTable.set("DATE_RECON_ACQ", hRepository.getDATE_RECON_ACQ());
   hTable.set("DATE_RECON_ISS", hRepository.getDATE_RECON_ISS());
   hTable.set("TRAN_DISPOSITION", hRepository.getTRAN_DISPOSITION());
   hTable.set("CUR_TRAN", m_hFile.getCUR_RECON_NET());
   hTable.set("CUR_RECON_NET", m_hFile.getCUR_RECON_NET());
   hTable.set("CUR_CARD_BILL", m_hFile.getCUR_RECON_NET());
   hTable.set("CUR_RECON_ACQ", m_hFile.getCUR_RECON_NET());
   hTable.set("CUR_RECON_ISS", m_hFile.getCUR_RECON_NET());
   hTable.set("OCS_TRANSACTION", " ");
   string strIMPACT_TO_ACQ("1", 1);
   if (hRepository.getTRAN_DISPOSITION() == "3")
      strIMPACT_TO_ACQ.assign("2", 1);
   hTable.set("IMPACT_TO_ACQ", strIMPACT_TO_ACQ);
   hTable.set("IMPACT_TO_ISS", (strIMPACT_TO_ACQ == "1") ? "2" : "1");
   double dADL_RQST_AMT0 = m_dADL_RQST_AMT0 * pow((double)10,6);
   hTable.set("AMT_TRAN", dADL_RQST_AMT0);
   hTable.set("AMT_CARD_BILL", dADL_RQST_AMT0);
   hTable.set("AMT_RECON_ACQ", dADL_RQST_AMT0);
   hTable.set("AMT_RECON_ISS", dADL_RQST_AMT0);
   hTable.set("AMT_RECON_NET", dADL_RQST_AMT0);
   hTable.set("AMT_INITIATOR", (dADL_RQST_AMT0 < 0) ? (m_hFile.getRole() == "A" ? "I" : "A") : m_hFile.getRole());
   auto_ptr<Statement> pMergeStatement((Statement*)DatabaseFactory::instance()->create("MergeStatement"));
   return pMergeStatement->execute(hTable);
  //## end reconciliationfile::InterchangeFile::applyFees%63FF04820352.body
}

bool InterchangeFile::applyMissing ()
{
  //## begin reconciliationfile::InterchangeFile::applyMissing%63FF023E01C4.body preserve=yes
   if (m_bFullReconciliation)
      return ReconciliationDataset::applyMissing();
   return true;
  //## end reconciliationfile::InterchangeFile::applyMissing%63FF023E01C4.body
}

void InterchangeFile::formatAmount (char* psAmount, int iLength)
{
  //## begin reconciliationfile::InterchangeFile::formatAmount%63FF026302E0.body preserve=yes
   int i = iLength - 1;
#ifdef MVS
   psAmount[i] |= 0xF0;
#else
   char* pszAlpha = { "{ABCDEFGHI}JKLMNOPQR" };
   char* pszDigit = { "01234567890123456789" };
   char* a = strchr(pszAlpha, psAmount[i]);
   if (a)
      psAmount[i] = pszDigit[a - pszAlpha];
#endif
  //## end reconciliationfile::InterchangeFile::formatAmount%63FF026302E0.body
}

bool InterchangeFile::initializeAudit (const string& strDX_FILE_TYPE, const string& strDATE_RECON_NET)
{
  //## begin reconciliationfile::InterchangeFile::initializeAudit%64B625100344.body preserve=yes
   m_pReformatAudit = new Audit(strDX_FILE_TYPE, getENTITY_TYPE()[0], getENTITY_ID(0), strDATE_RECON_NET, "235959");
   const char* pszAudit[] =
   {
      "HDataNavigator Auto Conversion Audit",
      "HInput File: ~Z.INPUT_FILE.",
      "HDate Recon: ~T.DATE_RECON_NET.",
      "HRun Time: ~Z.TIMESTAMP.",
      "H",
      "HStatus,PAN,Retrieval Reference No,Tstamp Local,Acquirer Inst Id,Issuer Inst Id",
      "AAcquirer not found,~T.PAN.,~T.RETRIEVAL_REF_NO.,~T.TSTAMP_LOCAL.,~T.INST_ID_ACQ.,~T.INST_ID_ISS.",
      "IIssuer not found,~T.PAN.,~T.RETRIEVAL_REF_NO.,~T.TSTAMP_LOCAL.,~T.INST_ID_ACQ.,~T.INST_ID_ISS.",
      "PParticipant Id not found,~T.FILE.,~T.PARTICIPANT_ID.",
      0
   };
   m_pReformatAudit->setTemplate(&pszAudit[0]);
   m_pReformatAudit->add('T', &m_hGenericSegment);
   m_pReformatAudit->add('Z', usersegment::EmailSegment::instance());
   usersegment::EmailSegment::instance()->setField("INPUT_FILE", m_pGenerationDataGroup->datasetName());
   if (!m_pReformatAudit->report('H'))
   {
      Database::instance()->rollback();
      return false;
   }
   Database::instance()->commit();
   m_bIntializeAudit = false;
   return true;
  //## end reconciliationfile::InterchangeFile::initializeAudit%64B625100344.body
}

void InterchangeFile::join (Query& hQuery, const char* pszTable)
{
  //## begin reconciliationfile::InterchangeFile::join%63FF02AC03D6.body preserve=yes
   getRepository().bindLocator(hQuery, pszTable);
   if (m_bIncludeSurcharge || m_hNetwork->size() > 0)
   {
      hQuery.join(pszTable, "INNER", "FIN_RECORD", "TSTAMP_TRANS");
      hQuery.join(pszTable, "INNER", "FIN_RECORD", "UNIQUENESS_KEY");
      if(m_bIncludeSurcharge)
         getRepository().bindFee(hQuery, pszTable);
   }
  //## end reconciliationfile::InterchangeFile::join%63FF02AC03D6.body
}

bool InterchangeFile::post (ReconciliationSegment& hReconciliationSegment, int iExtra)
{
  //## begin reconciliationfile::InterchangeFile::post%63FF02EB003F.body preserve=yes
   string strADL_RQST_AMT0;
   m_hFile.getFieldByIndex(9, strADL_RQST_AMT0);
   m_dADL_RQST_AMT0 = m_bMergeRecon ? m_hFile.m_dTotalInterchangeAmount : atof(strADL_RQST_AMT0.c_str());
   if (m_dADL_RQST_AMT0 == 0)
      return true;
   if (!m_pPostingFile[iExtra])
      writeHeader(iExtra);
   char szTemp[PERCENTF];
   struct hNETIXF *x = (struct hNETIXF*)m_pPostingFile[iExtra]->getDATA_BUFFER();
   memset(x,' ',sizeof(struct hNETIXF));
   if(!iExtra)
      memcpy(x->sPRIMARY_KEY,szTemp,snprintf(szTemp,sizeof(szTemp),"%-16.16s:%08hd",hReconciliationSegment.getTSTAMP_TRANS().c_str(),hReconciliationSegment.getUNIQUENESS_KEY()));
   m_dADL_RQST_AMT0 = m_dADL_RQST_AMT0 / pow((double)10,6);
   memcpy(x->sF_AMT90,szTemp,snprintf(szTemp,sizeof(szTemp),"%018.6f",m_dADL_RQST_AMT0));
   memcpy(x->sCUR_RECON_NET,hReconciliationSegment.getCUR_RECON_NET().data(),hReconciliationSegment.getCUR_RECON_NET().length());
   memcpy(x->sAMT_RECON_NET,szTemp,snprintf(szTemp,sizeof(szTemp),"%018.0f",hReconciliationSegment.getAMT_RECON_NET()));
   memcpy(x->sPAN,hReconciliationSegment.getPAN().data(),hReconciliationSegment.getPAN().length());
   int iSize = sizeof(struct hNETIXF);
   KeyRing::instance()->mask(iSize,m_pPostingFile[iExtra]->getDATA_BUFFER(),offsetof(hNETIXF,sPAN),sizeof(x->sPAN));
   memcpy(x->sRETRIEVAL_REF_NO,hReconciliationSegment.getRETRIEVAL_REF_NO().data(),hReconciliationSegment.getRETRIEVAL_REF_NO().length());
   memcpy(x->sTSTAMP_LOCAL,hReconciliationSegment.getTSTAMP_LOCAL().data(),hReconciliationSegment.getTSTAMP_LOCAL().length());
   bool bSuccess = m_pPostingFile[iExtra]->write(iSize,-1,false,false);
   if (bSuccess && !iExtra)
      bSuccess = applyFees(hReconciliationSegment);
   return  bSuccess ;
  //## end reconciliationfile::InterchangeFile::post%63FF02EB003F.body
}

void InterchangeFile::postProcess ()
{
  //## begin reconciliationfile::InterchangeFile::postProcess%63FF031F0232.body preserve=yes
   for (int i = 0; i < 2; i++)
   {
      if (!m_pPostingFile[i])
         writeHeader(i);
      Database::instance()->commit();
      snprintf(m_pPostingFile[i]->getDATA_BUFFER(), 11, "FT%08d", m_pPostingFile[i]->getCount() - 1);
      m_pPostingFile[i]->write(10);
      m_pPostingFile[i]->close();
   }
  //## end reconciliationfile::InterchangeFile::postProcess%63FF031F0232.body
}

void InterchangeFile::setBasicPredicate (Query& hQuery, const string& strTable, int iBegin, int iEnd, int iEntity)
{
  //## begin reconciliationfile::InterchangeFile::setBasicPredicate%63FF036A00F3.body preserve=yes
   hQuery.setBasicPredicate(strTable.c_str(), "FUNC_CODE", "NOT LIKE", "1%");
   TransactionReportFile::setBasicPredicate(hQuery, strTable, iBegin, iEnd, iEntity);
  //## end reconciliationfile::InterchangeFile::setBasicPredicate%63FF036A00F3.body
}

void InterchangeFile::setMatch ()
{
  //## begin reconciliationfile::InterchangeFile::setMatch%63FF03ED002D.body preserve=yes
   ReconciliationDataset::setMatch();
   m_hFile.setSortByBIN(false);
   if (m_hFile.getMatch().empty())
   {
      m_hFile.setMatch("PAN");
      m_hFile.setMatch("RETRIEVAL_REF_NO");
      m_hFile.setMatch("TRAN_DISPOSITION");
      m_hFile.setMatch("AMT_RECON_NET");
   }
  //## end reconciliationfile::InterchangeFile::setMatch%63FF03ED002D.body
}

void InterchangeFile::setOrderByClause (Query& hQuery)
{
  //## begin reconciliationfile::InterchangeFile::setOrderByClause%63FF0410032C.body preserve=yes
   if (m_hFile.setOrderByClause(hQuery))
   {
      string strOrderByClause(hQuery.getOrderByClause());
      size_t pos = strOrderByClause.find("PAN_PREFIX");
      if (pos != string::npos)
         strOrderByClause.erase(pos + 3, 7);
      if (strOrderByClause.find("AMT_RECON_NET") == string::npos)
         strOrderByClause.append(",AMT_RECON_NET");
      pos = strOrderByClause.find(",F_AMT0");
      if (pos != string::npos)
         strOrderByClause.replace(pos, 7, ",F_AMT_RECON_NET0");
      hQuery.setOrderByClause(strOrderByClause);
   }
  //## end reconciliationfile::InterchangeFile::setOrderByClause%63FF0410032C.body
}

void InterchangeFile::setRole (ReconciliationSegment& hReconciliationSegment)
{
  //## begin reconciliationfile::InterchangeFile::setRole%63FF044B021A.body preserve=yes
   if (&hReconciliationSegment == &m_hRepository)
      ReconciliationDataset::setRole(hReconciliationSegment);
  //## end reconciliationfile::InterchangeFile::setRole%63FF044B021A.body
}

bool InterchangeFile::writeException (ReconciliationSegment& hReconciliationSegment, const char* pszRecordStatus)
{
  //## begin reconciliationfile::InterchangeFile::writeException%643C2A6603AD.body preserve=yes
   return true;
  //## end reconciliationfile::InterchangeFile::writeException%643C2A6603AD.body
}

void InterchangeFile::writeHeader (int iExtra)
{
  //## begin reconciliationfile::InterchangeFile::writeHeader%63FF0AE30290.body preserve=yes
   for (int i = 0; i < 2; i++)
   {
      m_strDX_FILE_TYPE = (i == 0) ? m_strDX_FILE_TYPE : "IXFARE";
      m_pPostingFile[i] = new ExportFile(m_strDX_FILE_TYPE, getENTITY_TYPE()[0], getENTITY_ID(0), FileControl::instance()->getDATE_RECON(), FileControl::instance()->getTSTAMP_CREATED().substr(8,6));
      if (m_pPostingFile[i]->isPresent() == false)
      {
         snprintf(m_pPostingFile[i]->getDATA_BUFFER(), 56, "%-8s,%-8s,%-8s,%4s,%-14s,%-8s", "FH", "DN", Extract::instance()->getName().c_str(), "0100",
            FileControl::instance()->getDATE_RECON().c_str(), m_strDX_FILE_TYPE.c_str());
         m_pPostingFile[i]->write(55);
      }
   }
  //## end reconciliationfile::InterchangeFile::writeHeader%63FF0AE30290.body
}

// Additional Declarations
  //## begin reconciliationfile::InterchangeFile%63FF0039038C.declarations preserve=yes
  //## end reconciliationfile::InterchangeFile%63FF0039038C.declarations

} // namespace reconciliationfile

//## begin module%63FEFF8701EC.epilog preserve=yes
//## end module%63FEFF8701EC.epilog
