//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%6809B6A00083.cm preserve=no
//## end module%6809B6A00083.cm

//## begin module%6809B6A00083.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%6809B6A00083.cp

//## Module: CXOSRX71%6809B6A00083; Package body
//## Subsystem: RXDLL%5C47391001FD
//## Source file: C:\Repos\datanavigatorserver\Windows\Build\Dn\Server\Library\Rxdll\CXOSRX71.cpp

//## begin module%6809B6A00083.additionalIncludes preserve=no
//## end module%6809B6A00083.additionalIncludes

//## begin module%6809B6A00083.includes preserve=yes
#ifndef CXOSRS62_h
#include "CXODRS62.hpp"
#endif
#ifndef CXOSRS63_h
#include "CXODRS63.hpp"
#endif
#ifndef CXOSRS64_h
#include "CXODRS64.hpp"
#endif
#ifndef CXOSRS66_h
#include "CXODRS66.hpp"
#endif
#ifndef CXOSVP15_h
#include "CXODVP15.hpp"
#endif
#ifndef CXOSMP07_h
#include "CXODMP07.hpp"
#endif
#define CUSTOM_FIELDS 1
#define OFFSET        0
#define LENGTH        1
//## end module%6809B6A00083.includes

#ifndef CXOSCF01_h
#include "CXODCF01.hpp"
#endif
#ifndef CXOSIF10_h
#include "CXODIF10.hpp"
#endif
#ifndef CXOSTM06_h
#include "CXODTM06.hpp"
#endif
#ifndef CXOSTM04_h
#include "CXODTM04.hpp"
#endif
#ifndef CXOSMN05_h
#include "CXODMN05.hpp"
#endif
#ifndef CXOSDB63_h
#include "CXODDB63.hpp"
#endif
#ifndef CXOSBS23_h
#include "CXODBS23.hpp"
#endif
#ifndef CXOSIF16_h
#include "CXODIF16.hpp"
#endif
#ifndef CXOSRU40_h
#include "CXODRU40.hpp"
#endif
#ifndef CXOSPS01_h
#include "CXODPS01.hpp"
#endif
#ifndef CXOSDB49_h
#include "CXODDB49.hpp"
#endif
#ifndef CXOSDB02_h
#include "CXODDB02.hpp"
#endif
#ifndef CXOSRU12_h
#include "CXODRU12.hpp"
#endif
#ifndef CXOSRX70_h
#include "CXODRX70.hpp"
#endif
#ifndef CXOSDB05_h
#include "CXODDB05.hpp"
#endif
#ifndef CXOSRX71_h
#include "CXODRX71.hpp"
#endif


//## begin module%6809B6A00083.declarations preserve=no
//## end module%6809B6A00083.declarations

//## begin module%6809B6A00083.additionalDeclarations preserve=yes
namespace
{
   database::ExportFile* createTC57TransactionFile()
   {
      return new report::TC57TransactionFile("TC57TransactionFile");
   }
   const bool registered = database::ReportFactory::instance()->registerReport("TC57TransactionFile", createTC57TransactionFile);
}
//## end module%6809B6A00083.additionalDeclarations


//## Modelname: Data Distribution::Report_CAT%5C473883000E
namespace report {
//## begin report%5C473883000E.initialDeclarations preserve=yes
   typedef void (TC57TransactionFile::* mapTokenMethod)(string& strValue);
   map<string, mapTokenMethod, less<string> > m_hFunction;
//## end report%5C473883000E.initialDeclarations

// Class report::TC57TransactionFile 

TC57TransactionFile::TC57TransactionFile (const char* pszClass)
  //## begin report::TC57TransactionFile::TC57TransactionFile%6811780801BD.hasinit preserve=no
      : m_bAdvRevTran(false),
        m_dBatchGrossAmt(0),
        m_iBatchNo(0),
        m_dBatchNetAmt(0),
        m_bDF09Presence(false),
        m_iFieldMaxLen(0),
        m_bPrevAuth(false),
        m_iSeqNo(100),
        m_dTotNetAmt(0),
        m_pUnMatchFile(0),
        m_pGenericSegment(0),
        m_pReport(0),
        m_pContext(0)
  //## end report::TC57TransactionFile::TC57TransactionFile%6811780801BD.hasinit
  //## begin report::TC57TransactionFile::TC57TransactionFile%6811780801BD.initialization preserve=yes
  //## end report::TC57TransactionFile::TC57TransactionFile%6811780801BD.initialization
{
  //## begin report::TC57TransactionFile::TC57TransactionFile%6811780801BD.body preserve=yes
   memcpy(m_sID, "RX71", 4);
   setDX_FILE_TYPE("TC57");
   m_pReport = new report::Report(1266);
   m_pReport->setClass(pszClass);
   std::fill(&m_iField[0][0], &m_iField[0][0] + (sizeof(m_iField) / sizeof(m_iField[0][0])), 0);
   m_pContext = new Context(Application::instance()->image(), Application::instance()->name());
#ifdef MVS
   string strValue;
   Extract::instance()->getSpec("RX71", "VB", strValue);
   transform(strValue.begin(), strValue.end(), strValue.begin(), ::toupper);
   m_pReport->setVariableBlockFile(strValue == "YES" || strValue == "Y" ? true : false);
#endif
   m_hFunction["RecurringPaymentIndicator"] = &TC57TransactionFile::setRecurringPaymentIndicator;
   m_hFunction["CATLevelInd"] = &TC57TransactionFile::setCATLevelInd;
   m_hFunction["PrepaidCardInd"] = &TC57TransactionFile::setPrepaidCardInd;
   m_hFunction["CardType"] = &TC57TransactionFile::setCardType;
   m_hFunction["CardholderIDMethod"] = &TC57TransactionFile::setCardholderIDMethod;
   m_hFunction["TransactionType"] = &TC57TransactionFile::setTransactionType;
   m_hFunction["FilmLocator"] = &TC57TransactionFile::setFilmLocator;
   m_hFunction["ECommerceInd"] = &TC57TransactionFile::setECommerceInd;
   m_hFunction["POSDebitReimbAttr"] = &TC57TransactionFile::setPOSDebitReimbAttr;
   m_hFunction["AcctType"] = &TC57TransactionFile::setAcctType;
   m_hFunction["POSEntryMode"] = &TC57TransactionFile::setPOSEntryMode;
   m_hFunction["TokenRequestorId"] = &TC57TransactionFile::setTokenRequestorId;
   m_hFunction["MCICardHolderFlags"] = &TC57TransactionFile::setCardHolderFlags;
   m_hFunction["AMXCardHolderFlags"] = &TC57TransactionFile::setCardHolderFlags;
   m_hFunction["LocationName"] = &TC57TransactionFile::setLocationName;
   m_hFunction["IsfcCode"] = &TC57TransactionFile::setIsfcCode;
   m_hFunction["ChannelInd"] = &TC57TransactionFile::setChannelInd;
   m_hFunction["NetworkTransportChannel"] = &TC57TransactionFile::setNetworkTransportChannel;
   //m_hFunction["AVSresponseCode"] = &TC57TransactionFile::setAVSresponseCode;
  //## end report::TC57TransactionFile::TC57TransactionFile%6811780801BD.body
}


TC57TransactionFile::~TC57TransactionFile()
{
  //## begin report::TC57TransactionFile::~TC57TransactionFile%6260E53402B5_dest.body preserve=yes
   delete m_pUnMatchFile;
   delete m_pContext;
   delete m_pGenericSegment;
   delete m_pReport;
  //## end report::TC57TransactionFile::~TC57TransactionFile%6260E53402B5_dest.body
}



//## Other Operations (implementation)
bool TC57TransactionFile::distribute (string& strDATA_BUFFER, IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::distribute%6261014A0217.body preserve=yes
   UseCase hUseCase("DIST", "## RX71 WRITE TC57");
   int iLength = strDATA_BUFFER.length();
   char* pDATA_BUFFER = new char[iLength];
   memcpy(pDATA_BUFFER, strDATA_BUFFER.data(), iLength);
   KeyRing::instance()->unmask(iLength, pDATA_BUFFER);
   strDATA_BUFFER.assign(pDATA_BUFFER, iLength);
   delete[] pDATA_BUFFER;
   m_hGenericSegment[0].reset();
   m_bDF09Presence = false;
   if (!populate(strDATA_BUFFER, m_hGenericSegment[0]))
      return UseCase::setSuccess(false);
   if (Extract::instance()->getCustomCode() != "CBA")
   {
      if (strDATA_BUFFER.length() >= m_iFieldMaxLen && memcmp(strDATA_BUFFER.data() + m_iField[MTI][OFFSET] + 1, "1", 1) == 0)
      {
         if (memcmp(strDATA_BUFFER.data() + m_iField[PROC_ID_ISS_B][OFFSET], "VISA", 4) != 0 &&
            memcmp(strDATA_BUFFER.data() + m_iField[NET_ID_ISS][OFFSET], "VNT", 3) != 0)
            return true;
         if (m_bPrevAuth)
            writeUnMatchedAuth();
         m_bPrevAuth = true;
         m_strAuthBuffer = strDATA_BUFFER;
         m_strAuthAltRecKey = getALT_REC_KEY();
         m_strAuthREF_DATA_ISS.assign(m_strAuthBuffer.data() + m_iField[REF_DATA_ISS][OFFSET], m_iField[REF_DATA_ISS][LENGTH]);
         return true;
      }
      if (m_bPrevAuth)
      {
         if (strDATA_BUFFER.length() >= m_iFieldMaxLen &&
            m_strAuthBuffer.length() >= m_iFieldMaxLen &&
            memcmp(strDATA_BUFFER.data() + m_iField[PAN][OFFSET], m_strAuthBuffer.data() + m_iField[PAN][OFFSET], m_iField[PAN][LENGTH]) == 0 &&
            memcmp(strDATA_BUFFER.data() + m_iField[RETRIEVAL_REF_NO][OFFSET], m_strAuthBuffer.data() + m_iField[RETRIEVAL_REF_NO][OFFSET], m_iField[RETRIEVAL_REF_NO][LENGTH]) == 0 &&
            memcmp(strDATA_BUFFER.data() + m_iField[APPROVAL_CODE][OFFSET], m_strAuthBuffer.data() + m_iField[APPROVAL_CODE][OFFSET], m_iField[APPROVAL_CODE][LENGTH]) == 0)
         {
            // save MOTO Indicator from Advice if present
            if (memcmp(strDATA_BUFFER.data() + m_iField[REF_DATA_ISS][OFFSET] + 80, " ", 1) != 0)
               m_strAuthREF_DATA_ISS[80] = strDATA_BUFFER[m_iField[REF_DATA_ISS][OFFSET] + 80];
            m_hGenericSegment[0].set("REF_DATA_ISS", m_strAuthREF_DATA_ISS);
         }
         else
            writeUnMatchedAuth();
      }
      m_bPrevAuth = false;
      m_strAuthBuffer.clear();
      m_strAuthAltRecKey.clear();
      m_strAuthREF_DATA_ISS.clear();
   }
   string strToValue, strToValue1;
   getGenericValue("IST_TC57_MTI", m_hGenericSegment[0].get("MTI"), strToValue);
   getGenericValue("IST_TC57_PCODE", m_hGenericSegment[0].get("TRAN_TYPE_ID").substr(0, 2), strToValue1);
   if (strToValue == "900" || strToValue1 == "900" || m_hGenericSegment[0].get("PROC_ID_ISS_B").substr(0, 3) == "DNA")
      return UseCase::setSuccess(true);
   if (m_hGenericSegment[0].get("INST_ID_RECON_ACQ") == "56022001000" && m_hGenericSegment[0].get("ODE_MTI") == "1140")
      return UseCase::setSuccess(true);
   memset(m_szREF_DATA_ISS, ' ', sizeof(m_szREF_DATA_ISS) - 1);
   m_szREF_DATA_ISS[sizeof(m_szREF_DATA_ISS) - 1] = '\0';
   memcpy(m_szREF_DATA_ISS, m_hGenericSegment[0].get("REF_DATA_ISS").data(), m_hGenericSegment[0].get("REF_DATA_ISS").length());
   memset(m_szADL_DATA_PRIV_ACQ, ' ', sizeof(m_szADL_DATA_PRIV_ACQ) - 1);
   m_szADL_DATA_PRIV_ACQ[sizeof(m_szADL_DATA_PRIV_ACQ) - 1] = '\0';
   memcpy(m_szADL_DATA_PRIV_ACQ, m_hGenericSegment[0].get("ADL_DATA_PRIV_ACQ").data(), m_hGenericSegment[0].get("ADL_DATA_PRIV_ACQ").length());
   memset(m_szADL_DATA_PRIV_ISS, ' ', sizeof(m_szADL_DATA_PRIV_ISS) - 1);
   m_szADL_DATA_PRIV_ISS[sizeof(m_szADL_DATA_PRIV_ISS) - 1] = '\0';
   memcpy(m_szADL_DATA_PRIV_ISS, m_hGenericSegment[0].get("ADL_DATA_PRIV_ISS").data(), m_hGenericSegment[0].get("ADL_DATA_PRIV_ISS").length());
   memset(m_szADL_RESP_DATA, ' ', sizeof(m_szADL_RESP_DATA) - 1);
   m_szADL_RESP_DATA[sizeof(m_szADL_RESP_DATA) - 1] = '\0';
   memcpy(m_szADL_RESP_DATA, m_hGenericSegment[0].get("ADL_RESP_DATA").data(), m_hGenericSegment[0].get("ADL_RESP_DATA").length());
   memset(m_szDATA_PRIV_ACQ, ' ', sizeof(m_szDATA_PRIV_ACQ) - 1);
   m_szDATA_PRIV_ACQ[sizeof(m_szDATA_PRIV_ACQ) - 1] = '\0';
   memcpy(m_szDATA_PRIV_ACQ, m_hGenericSegment[0].get("DATA_PRIV_ACQ").data(), m_hGenericSegment[0].get("DATA_PRIV_ACQ").length());
   memset(m_szEXTENSION_DATA_ADJ, ' ', sizeof(m_szEXTENSION_DATA_ADJ) - 1);
   m_szEXTENSION_DATA_ADJ[sizeof(m_szEXTENSION_DATA_ADJ) - 1] = '\0';
   memcpy(m_szEXTENSION_DATA_ADJ, m_hGenericSegment[0].get("EXTENSION_DATA_ADJ").data(), m_hGenericSegment[0].get("EXTENSION_DATA_ADJ").length());
   memset(m_szDATA_PRIV_ISS, ' ', sizeof(m_szDATA_PRIV_ISS) - 1);
   m_szDATA_PRIV_ISS[sizeof(m_szDATA_PRIV_ISS) - 1] = '\0';
   memcpy(m_szDATA_PRIV_ISS, m_hGenericSegment[0].get("DATA_PRIV_ISS").data(), m_hGenericSegment[0].get("DATA_PRIV_ISS").length());
   string strValue;
   for (int i = 0; i < CUSTOM_FIELDS; i++)
   {
      strValue.assign(m_hGenericSegment[0].get(m_hConstants[CUSTOM_FIELDS + i].data()));
      char szIndex[PERCENTD];
      for (int k = 0; k < 6; k++)
      {
         m_hConstants[i].resize(6);
         snprintf(szIndex, sizeof(szIndex), "%d", k);
         m_hConstants[i].append(szIndex);
         m_hGenericSegment[0].set(m_hConstants[i].data(), strValue.substr(3, 18));
         string strCurrency(m_hConstants[i]);
         strCurrency.replace(5, 1, "C", 1);
         m_hGenericSegment[0].set(strCurrency.data(), strValue.substr(25, 3));
         string strType(m_hConstants[i]);
         strType.replace(5, 1, "T", 1);
         m_hGenericSegment[0].set(strType.data(), strValue.substr(0, 2));
         strValue.erase(0, 29);
      }
   }
   string strBatchKey = m_hGenericSegment[0].get("RPT_LVL_ID_B") + m_hGenericSegment[0].get("NET_TERM_ID");
   if (m_strBatchKey != strBatchKey)
   {
      if (m_strBatchKey.empty())
      {
         if (!write_TCR90_FileHeader(hFlatFile))
            return UseCase::setSuccess(false);
      }
      else
      {
         if (!write_TCR0_BatchTrailer(hFlatFile))
            return UseCase::setSuccess(false);
         if (!write_TCR91_BatchTrailer(hFlatFile))
            return UseCase::setSuccess(false);
      }
      m_strBatchKey = strBatchKey;
      if (!write_TCR0_BatchHeader(hFlatFile))
         return UseCase::setSuccess(false);
      if (!write_TCR1_BatchHeader(hFlatFile))
         return UseCase::setSuccess(false);
      if (!write_TCR2_AmexCAPNBatchHeader(hFlatFile))
         return UseCase::setSuccess(false);
   }
   write_TCR0_TxnDetail(hFlatFile);
   write_TCR1_TxnDetail_Common(hFlatFile);
   write_TCR7_Chip_All(hFlatFile);
   if (m_hGenericSegment[0].get("PROC_ID_ISS_B") == "MCI"
      || m_hGenericSegment[0].get("NET_ID_ISS") == "MCI")
      write_TCR5_TxnDetail_MC(hFlatFile);
   else if (m_hGenericSegment[0].get("PROC_ID_ISS_B") == "VISA"
      || m_hGenericSegment[0].get("NET_ID_ISS") == "VNT")
   {
      write_TCR3_TxnDetail_PaymentServiceData(hFlatFile);
      write_TCR4_TxnDetail_VISA(hFlatFile);
   }
   else if (m_hGenericSegment[0].get("NET_ID_ISS") == "AMX"
      || (Extract::instance()->getCustomCode() == "CBA" && m_hGenericSegment[0].get("NET_ID_ISS") == "JCB"))
   {
      write_TCR1_AmexTxnDetailAdviceBasic(hFlatFile);
      write_TCR4_AmexTxnDetailLocation(hFlatFile);
   }
   else if (m_hGenericSegment[0].get("NET_ID_ISS") == "DCC")
   {
      write_TCR1_DinersIntlChargeDetailRecord(hFlatFile);
      if (!m_bDF09Presence)
         write_TCR3_DinersIntlChipAddtlRecord(hFlatFile);
   }
   else if (m_hGenericSegment[0].get("NET_ID_ISS") == "CUP")
   {
      write_TCR1_TxnDetail_UPI(hFlatFile);
   }
   if (Extract::instance()->getCustomCode() == "COLES")
      write_TCR99_Coles(hFlatFile);
   else if (Extract::instance()->getCustomCode() == "CBA"
      || Extract::instance()->getCustomCode() == "PAAS")
      write_TCR99_CustomRecord(hFlatFile);
   return UseCase::setSuccess(m_pReport->write(hFlatFile));
  //## end report::TC57TransactionFile::distribute%6261014A0217.body
}

bool TC57TransactionFile::finish (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::finish%626102170265.body preserve=yes
   char szTemp[PERCENTD];
   snprintf(szTemp, sizeof(szTemp), "%d", atoi(m_hActivitySegment[1].get("FCNT").c_str()));
   m_pContext->put("FILM LOCATOR", szTemp);
   if (m_strBatchKey.length() > 0)
   {
      m_strBatchKey.erase();
      if (!write_TCR0_BatchTrailer(hFlatFile))
         return false;
      if (!write_TCR91_BatchTrailer(hFlatFile))
         return false;
      if (!write_TCR92_FileTrailer(hFlatFile))
         return false;
   }
   if (m_bPrevAuth)
      writeUnMatchedAuth();
   if (m_pUnMatchFile != 0)
      m_pUnMatchFile->complete();
   return m_pReport->write(hFlatFile);
  //## end report::TC57TransactionFile::finish%626102170265.body
}

bool TC57TransactionFile::getGenericValue (const string& strType, const string& strFromValue, string& strToValue)
{
  //## begin report::TC57TransactionFile::getGenericValue%626104E903D0.body preserve=yes
   return ConfigurationRepository::instance()->translate(strType.data(), strFromValue, strToValue, " ", " ", -1, false);
  //## end report::TC57TransactionFile::getGenericValue%626104E903D0.body
}

bool TC57TransactionFile::initialize ()
{
  //## begin report::TC57TransactionFile::initialize%6261024703D8.body preserve=yes
   m_pReport->setVariableRecordLength(true);
   m_pReport->setDX_REPORT_ID(getDX_REPORT_ID());
#ifdef MVS
   m_pReport->readTemplate("DNDNRX71");
   m_pReport->readTemplate("DNOVRX71", true);
#else
   m_pReport->readTemplate("CXOXRX71");
   m_pReport->readTemplate("CXOVRX71", true);
#endif
   m_pReport->setPageSize(0);
   return true;
  //## end report::TC57TransactionFile::initialize%6261024703D8.body
}

bool TC57TransactionFile::mapToken (reusable::string& strToken, const map<char,reusable::Object*, less<char> >& hSegment, string& strValue)
{
  //## begin report::TC57TransactionFile::mapToken%67F3F1930299.body preserve=yes
   const map<char, reusable::Object*, less<char> >::const_iterator pSegment = hSegment.find('Z');
   if (pSegment == hSegment.end())
      return false;
   m_pGenericSegment = (GenericSegment*)(*pSegment).second;
   m_strToken.assign(strToken.data(), strToken.length());
   setAdvRevTran(false);
   if (m_pGenericSegment->get("MTI") == "1240" || m_pGenericSegment->get("MTI")[1] == '4'
      || m_pGenericSegment->get("TRAN_DISPOSITION") == "2")
      setAdvRevTran(true);
   map<string, mapTokenMethod, less<string> >::iterator p = m_hFunction.find(strToken);
   if (p == m_hFunction.end())
      return false;
   (*this.*(*p).second)(strValue);
   return true;
  //## end report::TC57TransactionFile::mapToken%67F3F1930299.body
}

void TC57TransactionFile::setAcctType (string& strValue)
{
  //## begin report::TC57TransactionFile::setAcctType%67F3F02603AC.body preserve=yes
   string strAcctType(m_pGenericSegment->get("TRAN_TYPE_ID").data() + 2, 2);
   if (Extract::instance()->getCustomCode() == "CBA" && !memcmp(m_pGenericSegment->get("TRAN_TYPE_ID").data(), "20", 2))
      strAcctType.assign(m_pGenericSegment->get("TRAN_TYPE_ID").data() + 4, 2);
   if (getGenericValue("TC57_ACCT_TYPE", strAcctType, strValue) == false)
      strValue.assign("0", 1);
  //## end report::TC57TransactionFile::setAcctType%67F3F02603AC.body
}

/*void TC57TransactionFile::setAVSresponseCode(string& strValue)
{
   //## begin report::TC57TransactionFile::setAVSresponseCode%6890A2BC01F8.body preserve=yes
   string strTRAN_UNIQUE_DATA(m_pGenericSegment->get("TRAN_UNIQUE_DATA"));
   strTRAN_UNIQUE_DATA.resize(50, ' ');
   strValue.assign(1, strTRAN_UNIQUE_DATA[29]);
   //## end report::TC57TransactionFile::setAVSresponseCode%6890A2BC01F8.body
} */

void TC57TransactionFile::setCardHolderFlags (string& strValue)
{
  //## begin report::TC57TransactionFile::setCardHolderFlags%67F3F08F0276.body preserve=yes
   char szCardFlgs[13];
   memset(szCardFlgs, ' ', 12);
   szCardFlgs[12] = '\0';
   string strToValue;
   if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") != "A")
   {
      if (memcmp(m_strToken.data(), "MCI", 3) == 0)
      {
         getGenericValue("TC57_IN_CAP", m_pGenericSegment->get("POS_CRD_DAT_IN_CAP"), strToValue);
         szCardFlgs[0] = strToValue[0];
         getGenericValue("TC57_AUTH_C", m_pGenericSegment->get("POS_CRDHLDR_AUTH_C"), strToValue);
         szCardFlgs[1] = strToValue[0];
         szCardFlgs[2] = m_pGenericSegment->get("POS_CARD_CAPT_CAP")[0];
         getGenericValue("TC57_OPER_ENV", m_pGenericSegment->get("POS_OPER_ENV"), strToValue);
         szCardFlgs[3] = strToValue[0];
         getGenericValue("TC57_CRDHLDR_PT", m_pGenericSegment->get("POS_CRDHLDR_PRESNT"), strToValue);
         szCardFlgs[4] = strToValue[0];
         szCardFlgs[5] = m_pGenericSegment->get("POS_CARD_PRES")[0];
         if (szCardFlgs[4] == '5')
            szCardFlgs[6] = 'S';
         else
         {
            getGenericValue("TC57_IN_MOD", m_pGenericSegment->get("POS_CRD_DAT_IN_MOD"), strToValue);
            szCardFlgs[6] = strToValue[0];
         }
         if (Extract::instance()->getCustomCode() == "COLES")
         {
            if (szCardFlgs[6] == '2' && m_pGenericSegment->get("POS_ENTRY_MODE").substr(0, 2) == "80")
               szCardFlgs[6] = 'B';
            if (szCardFlgs[6] == '0' && m_pGenericSegment->get("POS_ENTRY_MODE").substr(0, 2) == "01")
               szCardFlgs[6] = '1';
            if (szCardFlgs[6] == 'C' && m_pGenericSegment->get("{CvmResults|").substr(0, 2) == "01")
               szCardFlgs[6] = 'F';
         }
         getGenericValue("TC57_A_METH", m_pGenericSegment->get("POS_CRDHLDR_A_METH"), strToValue);
         szCardFlgs[7] = strToValue[0];
         if (Extract::instance()->getCustomCode() == "COLES")
            szCardFlgs[8] = m_pGenericSegment->get("POS_CRDHLDR_AUTH")[0];
         else
         {
            getGenericValue("TC57_CH_AUTHENT", m_pGenericSegment->get("POS_CRDHLDR_AUTH"), strToValue);
            szCardFlgs[8] = strToValue[0];
         }
         szCardFlgs[9] = m_pGenericSegment->get("POS_CRD_DAT_OT_CAP")[0];
         szCardFlgs[10] = m_pGenericSegment->get("POS_TERM_OUT_CAP")[0];
         getGenericValue("TC57_CAPT_CAP", m_pGenericSegment->get("POS_PIN_CAPT_CAP"), strToValue);
         szCardFlgs[11] = strToValue[0];
      }
      else if (memcmp(m_strToken.data(), "AMX", 3) == 0)
      {
         string strToValue;
         getGenericValue("TC57_AMX_IN_CAP", m_pGenericSegment->get("POS_CRD_DAT_IN_CAP"), strToValue);
         szCardFlgs[0] = strToValue[0];
         getGenericValue("TC57_AMX_AUTH_C", m_pGenericSegment->get("POS_CRDHLDR_AUTH_C"), strToValue);
         szCardFlgs[1] = strToValue[0];
         szCardFlgs[2] = m_pGenericSegment->get("POS_CARD_CAPT_CAP")[0];
         getGenericValue("TC57_AMX_OP_ENV", m_pGenericSegment->get("POS_OPER_ENV"), strToValue);
         szCardFlgs[3] = strToValue[0];
         getGenericValue("TC57_AMX_CH_PT", m_pGenericSegment->get("POS_CRDHLDR_PRESNT"), strToValue);
         szCardFlgs[4] = strToValue[0];
         getGenericValue("TC57_AMX_CRD_PT", m_pGenericSegment->get("POS_CARD_PRES"), strToValue);
         szCardFlgs[5] = strToValue[0];
         getGenericValue("TC57_AMX_IN_MOD", m_pGenericSegment->get("POS_CRD_DAT_IN_MOD"), strToValue);
         szCardFlgs[6] = strToValue[0];
         getGenericValue("TC57_AMX_A_METH", m_pGenericSegment->get("POS_CRDHLDR_A_METH"), strToValue);
         szCardFlgs[7] = strToValue[0];
         getGenericValue("TC57_AMX_CH_ENT", m_pGenericSegment->get("POS_CRDHLDR_AUTH"), strToValue);
         szCardFlgs[8] = strToValue[0];
         getGenericValue("TC57_AMX_OT_CAP", m_pGenericSegment->get("POS_CRD_DAT_OT_CAP"), strToValue);
         szCardFlgs[9] = strToValue[0];
         szCardFlgs[10] = m_pGenericSegment->get("POS_TERM_OUT_CAP")[0];
         getGenericValue("TC57_AMX_PN_CAP", m_pGenericSegment->get("POS_PIN_CAPT_CAP"), strToValue);
         szCardFlgs[11] = strToValue[0];
      }
   }
   if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "A")
   {
      if (m_bAdvRevTran)
      {
         if (memcmp(m_strToken.data(), "MCI", 3) == 0)
         {
            string strTemp;
            if (getGenericValue("TC57_REV_AD_MOD", m_pGenericSegment->get("TERM_CLASS"), strToValue)
               || getGenericValue("TC57_REV_AD_MOD", m_pGenericSegment->get("POS_CRD_DAT_IN_MOD"), strToValue))
               strTemp = strToValue;
            if (getGenericValue("TC57_IN_MOD", strTemp, strToValue))
               szCardFlgs[6] = strToValue[0];  // DE22,s7
            else
               szCardFlgs[6] = '0';
            if (strTemp == "04")
               szCardFlgs[1] = '6';  // DE22,s2
            else if (getGenericValue("TC57_AUTH_C", strTemp.substr(1, 1), strToValue))
               szCardFlgs[1] = strToValue[0];
            else
               szCardFlgs[1] = '0';
            if (getGenericValue("TC57_REV_AD_PIN", m_pGenericSegment->get("POS_CRDHLDR_AUTH_C"), strToValue)
               || getGenericValue("TC57_REV_AD_PIN", m_pGenericSegment->get("POS_PIN_CAPT_CAP"), strToValue))
               strTemp = strToValue;
            else
               strTemp = "1";
            if ((strTemp == "0") || (strTemp == "2") || (strTemp == "8"))
               szCardFlgs[11] = '0';   // DE22,s12
            else if (getGenericValue("TC57_CAPT_CAP", m_pGenericSegment->get("POS_PIN_CAPT_CAP"), strToValue))
               szCardFlgs[11] = strToValue[0];
            getGenericValue("TC57_REV_MC_CDI", m_pGenericSegment->get("POS_CRD_DAT_IN_CAP"), strTemp);
            if (getGenericValue("TC57_IN_CAP", strTemp, strToValue))
               szCardFlgs[0] = strToValue[0];  // // DE22,s1
            else
               szCardFlgs[0] = '9';
            if (m_pGenericSegment->get("POS_CARD_CAPT_CAP")[0] != ' ')
               szCardFlgs[2] = m_pGenericSegment->get("POS_CARD_CAPT_CAP")[0]; // DE22,s3
            else
               szCardFlgs[2] = '9';
            if (m_pGenericSegment->get("POS_OPER_ENV")[0] != ' ')
               szCardFlgs[3] = m_pGenericSegment->get("POS_OPER_ENV")[0]; // DE22,s4
            else
               szCardFlgs[3] = '9';
            if (m_pGenericSegment->get("POS_OPER_ENV")[0] == '5')
               szCardFlgs[4] = m_pGenericSegment->get("POS_OPER_ENV")[0]; // DE22,s5
            else if (m_pGenericSegment->get("POS_CRDHLDR_PRESNT")[0] == 'S')
               szCardFlgs[4] = '4';
            else if (getGenericValue("TC57_CRDHLDR_PT", m_pGenericSegment->get("POS_CRDHLDR_PRESNT"), strToValue))
               szCardFlgs[4] = strToValue[0];
            else
               szCardFlgs[4] = '9';
            if (getGenericValue("TC57_REV_CPT", m_pGenericSegment->get("POS_CARD_PRES"), strToValue))
               szCardFlgs[5] = strToValue[0];  // DE22,s6
            else
               szCardFlgs[5] = '9';
            if (Extract::instance()->getCustomCode() == "CBA")
            {
               strTemp.erase();
               if (m_pGenericSegment->get("REF_DATA_ISS_FMT") != "4")
               {
                  setCardholderIDMethod(strTemp);
                  szCardFlgs[7] = strTemp[0];
               }
               else
                  szCardFlgs[7] = '9';
            }
            else
               szCardFlgs[7] = '9';  // DE22,s8
            szCardFlgs[8] = '9';  // DE22,s9
            szCardFlgs[9] = '0';  // DE22,s10
            szCardFlgs[10] = '0'; // DE22,s11
         }
         else if (memcmp(m_strToken.data(), "AMX", 3) == 0)
         {
            if (Extract::instance()->getCustomCode() == "CBA")
            {
               szCardFlgs[0] = m_pGenericSegment->get("REF_DATA_ISS")[80];
               szCardFlgs[1] = m_pGenericSegment->get("REF_DATA_ISS")[81];
               szCardFlgs[2] = m_pGenericSegment->get("REF_DATA_ISS")[82];
               szCardFlgs[3] = m_pGenericSegment->get("REF_DATA_ISS")[83];
               szCardFlgs[4] = m_pGenericSegment->get("REF_DATA_ISS")[84];
               szCardFlgs[5] = m_pGenericSegment->get("REF_DATA_ISS")[85];
               szCardFlgs[6] = m_pGenericSegment->get("REF_DATA_ISS")[86];
               szCardFlgs[7] = m_pGenericSegment->get("REF_DATA_ISS")[87];
               szCardFlgs[8] = m_pGenericSegment->get("REF_DATA_ISS")[88];
               szCardFlgs[9] = m_pGenericSegment->get("REF_DATA_ISS")[89];
               szCardFlgs[10] = m_pGenericSegment->get("REF_DATA_ISS")[90];
               szCardFlgs[11] = m_pGenericSegment->get("REF_DATA_ISS")[91];
            }
            else
            {
               if (getGenericValue("TC57_AMX_IN_CAP", m_pGenericSegment->get("POS_CRD_DAT_IN_CAP"), strToValue))
                  szCardFlgs[0] = strToValue[0];
               else
                  szCardFlgs[0] = '0';
               if (getGenericValue("TC57_AMX_AUTH_C", m_pGenericSegment->get("POS_CRDHLDR_AUTH_C"), strToValue))
                  szCardFlgs[1] = strToValue[0];
               else if (atoi(m_pGenericSegment->get("PIN_DATA_FMT").data()) > -1)
                  szCardFlgs[1] = '1';
               else
                  szCardFlgs[1] = '0';
               if (m_pGenericSegment->get("POS_CARD_CAPT_CAP")[0] == '1')
                  szCardFlgs[2] = '1';
               else
                  szCardFlgs[2] = '0';
               if (getGenericValue("TC57_AMX_OP_ENV", m_pGenericSegment->get("POS_OPER_ENV"), strToValue))
                  szCardFlgs[3] = strToValue[0];
               else
                  szCardFlgs[3] = '0';
               if (getGenericValue("TC57_AMX_CH_PT", m_pGenericSegment->get("POS_CRDHLDR_PRESNT"), strToValue)
                  || getGenericValue("TC57_AMX_CH_PT", m_pGenericSegment->get("TERM_CLASS"), strToValue))
                  szCardFlgs[4] = strToValue[0];
               else
                  szCardFlgs[4] = '1';
               if (m_pGenericSegment->get("POS_CRD_DAT_IN_MOD")[0] == 'M'
                  && m_pGenericSegment->get("POS_CRDHLDR_AUTH_C")[0] == 'W')
                  szCardFlgs[5] = 'X';
               else if (getGenericValue("TC57_AMX_CRD_PT", m_pGenericSegment->get("POS_CARD_PRES"), strToValue)
                  || getGenericValue("TC57_AMX_CRD_PT", m_pGenericSegment->get("POS_CRDHLDR_AUTH_C"), strToValue))
                  szCardFlgs[5] = strToValue[0];
               else
                  szCardFlgs[5] = '0';
               if (getGenericValue("TC57_AMX_IN_MOD", m_pGenericSegment->get("POS_CRD_DAT_IN_MOD"), strToValue))
                  szCardFlgs[6] = strToValue[0];
               else if (!m_pGenericSegment->get("CVV2_CVC2_RESULT").empty())
               {
                  if (m_pGenericSegment->get("POS_CRD_DAT_IN_MOD")[0] == '1'
                     || m_pGenericSegment->get("POS_CRD_DAT_IN_MOD")[0] == '6')
                     szCardFlgs[6] = 'S';
                  else if (m_pGenericSegment->get("POS_CRD_DAT_IN_MOD")[0] == '2')
                     szCardFlgs[6] = 'S';
               }
               else
                  szCardFlgs[6] = '0';
               if (atoi(m_pGenericSegment->get("PIN_DATA_FMT").data()) > -1)
                  szCardFlgs[7] = '1';
               else
                  szCardFlgs[7] = '0';
               if (getGenericValue("TC57_AMX_CH_ENT", m_pGenericSegment->get("POS_CRDHLDR_AUTH"), strToValue))
                  szCardFlgs[8] = strToValue[0];
               else if (atoi(m_pGenericSegment->get("PIN_DATA_FMT").data()) > -1)
                  szCardFlgs[8] = '5';
               else
                  szCardFlgs[8] = '0';
               if (m_pGenericSegment->get("POS_CRD_DAT_OT_CAP")[0] == '1')
                  szCardFlgs[9] = '1';
               else
                  szCardFlgs[9] = '0';
               if (getGenericValue("TC57_AMX_OT_CAP", m_pGenericSegment->get("POS_TERM_OUT_CAP"), strToValue))
                  szCardFlgs[10] = strToValue[0];
               else
                  szCardFlgs[10] = '0';
               if (m_pGenericSegment->get("POS_PIN_CAPT_CAP")[0] == '0')
                  szCardFlgs[11] = '0';
               else
                  szCardFlgs[11] = '1';
            }
         }
      }
      else
      {
         if (memcmp(m_strToken.data(), "MCI", 3) == 0)
         {
            getGenericValue("TC57_IN_CAP", string(m_pGenericSegment->get("REF_DATA_ISS").data() + 68, 1), strToValue);
            if (strToValue.empty())
               szCardFlgs[0] = '9';
            else
               szCardFlgs[0] = strToValue[0];
            if (memcmp(m_pGenericSegment->get("DATA_PRIV_ISS").data() + 34, "04", 2) == 0)
               szCardFlgs[1] = '6';
            else if (getGenericValue("TC57_AUTH_C", string(m_pGenericSegment->get("DATA_PRIV_ISS").data() + 35, 1), strToValue))
               szCardFlgs[1] = strToValue[0];
            else
               szCardFlgs[1] = '0';
            if (m_pGenericSegment->get("REF_DATA_ISS")[63] != ' ')
               szCardFlgs[2] = m_pGenericSegment->get("REF_DATA_ISS")[63];
            else
               szCardFlgs[2] = '9';
            if (m_pGenericSegment->get("REF_DATA_ISS")[60] == '8')
               szCardFlgs[3] = m_pGenericSegment->get("REF_DATA_ISS")[60];
            else if (getGenericValue("TC57_OPER_ENV", string(m_pGenericSegment->get("REF_DATA_ISS").data() + 58, 1) + string(m_pGenericSegment->get("REF_DATA_ISS").data() + 60, 1), strToValue))
               szCardFlgs[3] = strToValue[0];
            else
               szCardFlgs[3] = '9';
            if (getGenericValue("TC57_CRDHLDR_PT", string(m_pGenericSegment->get("REF_DATA_ISS").data() + 61, 1), strToValue))
               szCardFlgs[4] = strToValue[0];
            else
               szCardFlgs[4] = '9';
            if (getGenericValue("TC57_CARD_PT", string(m_pGenericSegment->get("REF_DATA_ISS").data() + 62, 1), strToValue))
               szCardFlgs[5] = strToValue[0];
            else
               szCardFlgs[5] = '9';
            if (getGenericValue("TC57_IN_MOD", string(m_pGenericSegment->get("DATA_PRIV_ISS").data() + 34, 2), strToValue))
               szCardFlgs[6] = strToValue[0];
            else
               szCardFlgs[6] = '0';
            if (Extract::instance()->getCustomCode() == "CBA")
            {
               if (m_pGenericSegment->get("REF_DATA_ISS_FMT") != "4")
               {
                  string strTemp;
                  setCardholderIDMethod(strTemp);
                  szCardFlgs[7] = strTemp[0];
               }
               else
                  szCardFlgs[7] = '9';
            }
            else
            {
               if (memcmp(m_pGenericSegment->get("DATA_PRIV_ISS").data() + 28, "PV", 2) == 0
                  || memcmp(m_pGenericSegment->get("DATA_PRIV_ISS").data() + 28, "TV", 2) == 0)
                  szCardFlgs[7] = '1';
               else
                  szCardFlgs[7] = '9';
            }
            szCardFlgs[8] = '9';
            szCardFlgs[9] = '0';
            szCardFlgs[10] = '0';
            if (memcmp(m_pGenericSegment->get("DATA_PRIV_ISS").data() + 36, "0", 1) == 0
               || memcmp(m_pGenericSegment->get("DATA_PRIV_ISS").data() + 36, "2", 1) == 0
               || memcmp(m_pGenericSegment->get("DATA_PRIV_ISS").data() + 36, "8", 1) == 0)
               szCardFlgs[11] = '0';
            else if (getGenericValue("TC57_CAPT_CAP", m_pGenericSegment->get("POS_PIN_CAPT_CAP"), strToValue))
               szCardFlgs[11] = strToValue[0];
            else
               szCardFlgs[11] = '1';
         }
         else if (memcmp(m_strToken.data(), "AMX", 3) == 0)
         {
            szCardFlgs[0] = m_pGenericSegment->get("DATA_PRIV_ISS")[4];
            szCardFlgs[1] = m_pGenericSegment->get("DATA_PRIV_ISS")[5];
            szCardFlgs[2] = m_pGenericSegment->get("DATA_PRIV_ISS")[6];
            szCardFlgs[3] = m_pGenericSegment->get("DATA_PRIV_ISS")[7];
            szCardFlgs[4] = m_pGenericSegment->get("DATA_PRIV_ISS")[8];
            szCardFlgs[5] = m_pGenericSegment->get("DATA_PRIV_ISS")[9];
            szCardFlgs[6] = m_pGenericSegment->get("DATA_PRIV_ISS")[10];
            szCardFlgs[7] = m_pGenericSegment->get("DATA_PRIV_ISS")[11];
            szCardFlgs[8] = m_pGenericSegment->get("DATA_PRIV_ISS")[12];
            szCardFlgs[9] = m_pGenericSegment->get("DATA_PRIV_ISS")[13];
            szCardFlgs[10] = m_pGenericSegment->get("DATA_PRIV_ISS")[14];
            szCardFlgs[11] = m_pGenericSegment->get("DATA_PRIV_ISS")[15];
         }
      }
   }
   else if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "G")
   {
      if (memcmp(m_strToken.data(), "MCI", 3) == 0)
      {
         if (Extract::instance()->getCustomCode() == "CBA")
         {
            szCardFlgs[0] = m_pGenericSegment->get("POS_CRD_DAT_IN_CAP")[0];
            szCardFlgs[1] = m_pGenericSegment->get("POS_CRDHLDR_AUTH_C")[0];
            szCardFlgs[2] = m_pGenericSegment->get("POS_CARD_CAPT_CAP")[0];
            szCardFlgs[3] = m_pGenericSegment->get("POS_OPER_ENV")[0];
            szCardFlgs[4] = m_pGenericSegment->get("POS_CRDHLDR_PRESNT")[0];
            szCardFlgs[5] = m_pGenericSegment->get("POS_CARD_PRES")[0];
            szCardFlgs[6] = m_pGenericSegment->get("POS_CRD_DAT_IN_MOD")[0];
            szCardFlgs[7] = m_pGenericSegment->get("POS_CRDHLDR_A_METH")[0];
            szCardFlgs[11] = m_pGenericSegment->get("POS_PIN_CAPT_CAP")[0];
         }
      }
   }
   else if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "T")
   {
      if (memcmp(m_strToken.data(), "MCI", 3) == 0)
      {
         visabaseIImessageprocessor::hDATA_PRIV_ACQ* pDATA_PRIV_ACQ;
         pDATA_PRIV_ACQ = (struct visabaseIImessageprocessor::hDATA_PRIV_ACQ*)m_pGenericSegment->get("DATA_PRIV_ACQ").data();
         szCardFlgs[6] = pDATA_PRIV_ACQ->sPOSEntryMode[0];
      }
   }
   strValue.assign(szCardFlgs, 12);
  //## end report::TC57TransactionFile::setCardHolderFlags%67F3F08F0276.body
}

void TC57TransactionFile::setCardholderIDMethod (string& strValue)
{
  //## begin report::TC57TransactionFile::setCardholderIDMethod%67F3EF88018F.body preserve=yes
   if (m_pGenericSegment->get("POS_CARD_PRES") == "0")
      strValue = "4";
   else
      strValue.assign(m_pGenericSegment->get("POS_CARD_PRES").data(), m_pGenericSegment->get("POS_CARD_PRES").length());
   if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "A")
   {
      if (Extract::instance()->getCustomCode() == "CBA" || Extract::instance()->getCustomCode() == "PAAS")
      {
         string strTemp;
         if (m_pGenericSegment->get("NET_ID_ISS") == "MCI")
         {
            if (m_pGenericSegment->get("PROC_BILLING_FLGS2")[7] == 'N')
            {
               strValue = "5";
               if (m_pGenericSegment->get("TERM_CLASS") == "17")
                  strValue = "3";
            }
            else if (m_pGenericSegment->get("PROC_BILLING_FLGS2")[7] == 'Y')
               strValue = "1";
            setECommerceInd(strTemp);
            if (strTemp[0] != ' ')
               strValue = "4";
         }
         else if (m_pGenericSegment->get("REF_DATA_ISS_FMT") == "4")
         {
            visabaseii::segREF_DATA_ISS_EVES_AUS* pREF_DATA_ISS_EVES_AUS = (visabaseii::segREF_DATA_ISS_EVES_AUS*)m_pGenericSegment->get("REF_DATA_ISS").data();
            strValue.assign(pREF_DATA_ISS_EVES_AUS->sDE60field[10], 1);
         }
      }
   }
  //## end report::TC57TransactionFile::setCardholderIDMethod%67F3EF88018F.body
}

void TC57TransactionFile::setCardType (string& strValue)
{
  //## begin report::TC57TransactionFile::setCardType%67F3EF6B00B8.body preserve=yes
   if (Extract::instance()->getCustomCode() == "CBA")
      getGenericValue("TC57_CARD_TYPE", m_pGenericSegment->get("NET_ID_ISS"), strValue);
   else
      getGenericValue("TC57_CARD_TYPE", m_pGenericSegment->get("PROC_ID_ISS_B"), strValue);
  //## end report::TC57TransactionFile::setCardType%67F3EF6B00B8.body
}

void TC57TransactionFile::setCATLevelInd (string& strValue)
{
  //## begin report::TC57TransactionFile::setCATLevelInd%67F3EF2803CD.body preserve=yes
   if (Extract::instance()->getCustomCode() == "COLES"
      && m_pGenericSegment->get("POS_COND_CODE") == "48")//Ecom Txn
      strValue = "6";
   else
   {
      if (m_pGenericSegment->get("TERM_CLASS") == "25")
         strValue = "6";
   }
   if (!memcmp(m_pGenericSegment->get("ADL_DATA_PRIV_ACQ").data(), "MC", 2))
   {
      mastercardcis::segADL_DATA_PRIV_ACQ_Advantage* pADL_DATA_PRIV_ACQ;
      pADL_DATA_PRIV_ACQ = (struct mastercardcis::segADL_DATA_PRIV_ACQ_Advantage*)m_pGenericSegment->get("ADL_DATA_PRIV_ACQ").data();
      if (pADL_DATA_PRIV_ACQ->cCardActivatedTerminalLevel != ' ')
         strValue = pADL_DATA_PRIV_ACQ->cCardActivatedTerminalLevel;
   }
   else if (!memcmp(m_pGenericSegment->get("ADL_DATA_PRIV_ACQ").data(), "MD", 2))
   {
      mastercardmds::segADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
      pADL_DATA_PRIV_ACQ = (struct mastercardmds::segADL_DATA_PRIV_ACQ*)m_pGenericSegment->get("ADL_DATA_PRIV_ACQ").data();
      if (pADL_DATA_PRIV_ACQ->cCardActivatedTerminalLevel != ' ')
         strValue = pADL_DATA_PRIV_ACQ->cCardActivatedTerminalLevel;
   }
   else if (!memcmp(m_pGenericSegment->get("ADL_DATA_PRIV_ACQ").data(), "VE", 2))
   {
      visabaseii::segADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
      pADL_DATA_PRIV_ACQ = (struct visabaseii::segADL_DATA_PRIV_ACQ*)m_pGenericSegment->get("ADL_DATA_PRIV_ACQ").data();
      if (pADL_DATA_PRIV_ACQ->cCardholderIDMethod != ' ')
         strValue = pADL_DATA_PRIV_ACQ->cCardholderIDMethod;
   }
  //## end report::TC57TransactionFile::setCATLevelInd%67F3EF2803CD.body
}

void TC57TransactionFile::setChannelInd (string& strValue)
{
  //## begin report::TC57TransactionFile::setChannelInd%67F3F0F3031D.body preserve=yes
   string strToValue;
   if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "A")
   {
      if (Extract::instance()->getCustomCode() == "CBA")
      {
         string strChannel;
         if (ConfigurationRepository::instance()->mapItem("X_INST_ID_RECON", m_pGenericSegment->get("INST_ID_RECON_ACQ"), "", "A", strChannel))
            getGenericValue("TC57_CHANNEL_ID", strChannel, strValue);
      }
      else
      {
         if (m_pGenericSegment->get("DATA_PRIV_ACQ_FMT") == "30")
            strValue = "3";
         else
         {
            strValue = "1";
            if (getGenericValue("TC57_UN_ATTEND", m_pGenericSegment->get("TERM_CLASS"), strToValue))
               strValue.assign(strToValue.data(), strToValue.length());//2- unattended Terminal
         }
      }
   }
   else if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "T")
      strValue = "4";
   else if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "G")
      strValue = "3";
   if (Extract::instance()->getCustomCode() == "CBA")
   {
      if (m_pGenericSegment->get("INST_ID_RECN_ISS_B") == "EFNCS" &&
         ConfigurationRepository::instance()->mapItem("X_INST_ID_RECON", m_pGenericSegment->get("BRANCH_ID_ACQ"), "", "A", strToValue))
         getGenericValue("TC57_CHANNEL_ID", strToValue, strValue);
   }
  //## end report::TC57TransactionFile::setChannelInd%67F3F0F3031D.body
}

void TC57TransactionFile::setECommerceInd (string& strValue)
{
  //## begin report::TC57TransactionFile::setECommerceInd%67F3EFE70129.body preserve=yes
   if (Extract::instance()->getCustomCode() == "COLES")
   {
      if (m_pGenericSegment->get("POS_COND_CODE") == "48") //Ecom Txn
      {
         if (m_pGenericSegment->get("MTI") == "1210" && (!m_pGenericSegment->get("{SLI|").empty()))
            strValue = m_pGenericSegment->get("{SLI|").substr(2, 1)[0];
         else
            strValue = "5";
      }
      else if (m_pGenericSegment->get("POS_COND_CODE") == "08") //MOTO Txn
         strValue = "1";
   }
   if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "A")
   {
      if (!memcmp(m_pGenericSegment->get("ADL_DATA_PRIV_ACQ").data(), "VE", 2))
      {
         visabaseii::segADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
         pADL_DATA_PRIV_ACQ = (struct visabaseii::segADL_DATA_PRIV_ACQ*)m_pGenericSegment->get("ADL_DATA_PRIV_ACQ").data();
         if (Extract::instance()->getCustomCode() == "CBA"
            || Extract::instance()->getCustomCode() == "PAAS")
            getGenericValue("TC57_MOTO_EC_ID", string(&pADL_DATA_PRIV_ACQ->cPOSEnvironment, 1), strValue);
      }
      if (Extract::instance()->getCustomCode() != "CBA")
      {
         string strToValue = m_pGenericSegment->get("POS_CRDHLDR_A_METH");
         if (strToValue == "6" || strToValue == "7" || strToValue == "8" || strToValue == "9")
            getGenericValue("TC57_MOTO_PCAM", m_pGenericSegment->get("POS_CRDHLDR_A_METH"), strToValue);
         else
         {
            getGenericValue("TC57_MOTO_PCP", m_pGenericSegment->get("POS_CRDHLDR_PRESNT"), strToValue);
            if (strToValue.empty())
               getGenericValue("TC57_MOTO_PCAM", m_pGenericSegment->get("POS_CRDHLDR_A_METH"), strToValue);
         }
         if (m_pGenericSegment->get("REF_DATA_ISS")[80] == ' ')
            strValue.assign(strToValue.data(), strToValue.length());
         else
            strValue.assign(m_pGenericSegment->get("REF_DATA_ISS")[80], 1);
      }
      else if (strValue[0] == ' ')
      {
         string strToValue;
         if (m_pGenericSegment->get("POS_CRDHLDR_A_METH") != "0")
            getGenericValue("TC57_MOTO_PCAM", m_pGenericSegment->get("POS_CRDHLDR_A_METH"), strToValue);
         else if (m_pGenericSegment->get("POS_CRDHLDR_AUTH_C") != " ")
         {
            if (getGenericValue("TC57_MOTO_PCP", m_pGenericSegment->get("POS_CRDHLDR_PRESNT"), strToValue) && m_pGenericSegment->get("POS_CRDHLDR_AUTH_C") == "7")
               ; //POS_CRDHLDR_PRESNT == 3 AND POS_CRDHLDR_AUTH_C == 7 -> MOTOorElecCommerceInd = 1(MOTO)
            else
               getGenericValue("TC57_MOTO_PCAC", m_pGenericSegment->get("POS_CRDHLDR_AUTH_C"), strToValue);
         }
         strValue.assign(strToValue.data(), strToValue.length());
      }
   }
   else if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "G")
   {
      mastercardipmmessageprocessor::hDATA_PRIV_ACQ* pDATA_PRIV_ACQ;
      pDATA_PRIV_ACQ = (struct mastercardipmmessageprocessor::hDATA_PRIV_ACQ*)m_pGenericSegment->get("DATA_PRIV_ACQ").data();
      getGenericValue("TC57_MOTO_EC_ID", string(pDATA_PRIV_ACQ->sPOSCondCode, 2), strValue);
   }
   else if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "T")
   {
      visabaseIImessageprocessor::hDATA_PRIV_ACQ* pDATA_PRIV_ACQ;
      pDATA_PRIV_ACQ = (struct visabaseIImessageprocessor::hDATA_PRIV_ACQ*)m_pGenericSegment->get("DATA_PRIV_ACQ").data();
      string strPOSCondCode(pDATA_PRIV_ACQ->sPOSConditionCode, sizeof(pDATA_PRIV_ACQ->sPOSConditionCode));
      getGenericValue("TC57_MOTO_EC_ID", strPOSCondCode, strValue);
   }
  //## end report::TC57TransactionFile::setECommerceInd%67F3EFE70129.body
}

void TC57TransactionFile::setFilmLocator (string& strValue)
{
  //## begin report::TC57TransactionFile::setFilmLocator%67F3EFC80076.body preserve=yes
   char szTemp[12];
   if (Extract::instance()->getCustomCode() == "CBA")
   {
      database::UniquenessKey::oatHash((const unsigned char*)m_pGenericSegment->get("TSTAMP_TRANS").data(), 14);
      database::UniquenessKey::oatHash((const unsigned char*)m_pGenericSegment->get("PAN").data(), min(size_t(28), m_pGenericSegment->get("PAN").length()));
      database::UniquenessKey::oatHash((const unsigned char*)m_pGenericSegment->get("RETRIEVAL_REF_NO").data(), min(m_pGenericSegment->get("RETRIEVAL_REF_NO").length(), size_t(12)));
      database::UniquenessKey::oatHash((const unsigned char*)m_pGenericSegment->get("TRAN_TYPE_ID").data(), min(m_pGenericSegment->get("TRAN_TYPE_ID").length(), size_t(6)));
      snprintf(szTemp, sizeof(szTemp), "%011u", database::UniquenessKey::getOatHash());
      strValue.assign(szTemp, 11);
   }
   else
   {
      if (atoi(m_hActivitySegment[0].get("FCNT").c_str()) > 999999999)
         m_hActivitySegment[1].set("FCNT", 1);
      snprintf(szTemp, sizeof(szTemp), "%2s%09d", Application::instance()->name().substr(4, 2).c_str(), atoi(m_hActivitySegment[1].get("FCNT").c_str()));
      strValue.assign(szTemp, 11);
   }
  //## end report::TC57TransactionFile::setFilmLocator%67F3EFC80076.body
}

void TC57TransactionFile::setIsfcCode (string& strValue)
{
  //## begin report::TC57TransactionFile::setIsfcCode%67F3F0D50232.body preserve=yes
   string strTemp(m_pGenericSegment->get("ADL_DATA_NATIONAL"));
   string strISFCCode;
   size_t nPosBegin = 0, nPosEnd = 0;
   if (Extract::instance()->getCustomCode() == "CBA")
      strISFCCode.append(m_pGenericSegment->get("ISFC_CODE"));
   else
   {
      if ((nPosBegin = strTemp.rfind("EFC")) != string::npos
         && (nPosEnd = strTemp.find("\\", nPosBegin)) != string::npos
         && nPosEnd - nPosBegin == 11)
         strISFCCode.assign(strTemp.data() + nPosBegin + 3, 8);
   }
   strISFCCode.append(m_pGenericSegment->get("TRAN_TYPE_ID").data(), 2);
   strISFCCode += '0';
   strISFCCode += m_pGenericSegment->get("TRAN_DISPOSITION");
   if (strISFCCode.length() == 12)
      strValue.assign(strISFCCode.data(), strISFCCode.length());
  //## end report::TC57TransactionFile::setIsfcCode%67F3F0D50232.body
}

void TC57TransactionFile::setLocationName (string& strValue)
{
  //## begin report::TC57TransactionFile::setLocationName%67F3F0AE0382.body preserve=yes
   if (Extract::instance()->getCustomCode() == "PAAS"
      && m_pGenericSegment->get("SELLER_ID").length() > 0)
      strValue.assign("TILL PAYMENTS*", 14);
  //## end report::TC57TransactionFile::setLocationName%67F3F0AE0382.body
}

void TC57TransactionFile::setOrderByClause (reusable::Query& hQuery)
{
  //## begin report::TC57TransactionFile::setOrderByClause%6261026500FF.body preserve=yes
   ReportFile::setOrderByClause(hQuery, "RPT_LVL_ID_B,NET_TERM_ID,PAN,RETRIEVAL_REF_NO,APPROVAL_CODE,MTI");
  //## end report::TC57TransactionFile::setOrderByClause%6261026500FF.body
}

void TC57TransactionFile::setPOSDebitReimbAttr (string& strValue)
{
  //## begin report::TC57TransactionFile::setPOSDebitReimbAttr%67F3F00800D2.body preserve=yes
   if (Extract::instance()->getCustomCode() == "CBA"
      && m_pGenericSegment->get("REF_DATA_ISS_FMT") == "4")
   {
      visabaseii::segREF_DATA_ISS_EVES_AUS* pREF_DATA_ISS_EVES_AUS = (visabaseii::segREF_DATA_ISS_EVES_AUS*)m_pGenericSegment->get("REF_DATA_ISS").data();
      strValue = pREF_DATA_ISS_EVES_AUS->cREIMBURSEMENT_ATTR;
   }
  //## end report::TC57TransactionFile::setPOSDebitReimbAttr%67F3F00800D2.body
}

void TC57TransactionFile::setPOSEntryMode (string& strValue)
{
  //## begin report::TC57TransactionFile::setPOSEntryMode%67F3F04F0265.body preserve=yes
   string strPROC_ID_ISS_B(m_pGenericSegment->get("PROC_ID_ISS_B").data(), m_pGenericSegment->get("PROC_ID_ISS_B").length());
   if (Extract::instance()->getCustomCode() == "COLES")
   {
      string strMTI(m_pGenericSegment->get("MTI").data(), m_pGenericSegment->get("MTI").length());
      if (m_pGenericSegment->get("POS_ENTRY_MODE") == "021" && strPROC_ID_ISS_B == "VISA")
      {
         if (strMTI == "1210" || strMTI == "1430" || (strMTI == "1230" && (m_pGenericSegment->get("APPROVAL_CODE").length() == 0)))
            strValue.assign("901", 2);
      }
   }
   if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "A")
   {
      if (strPROC_ID_ISS_B == "VISA")
         getGenericValue("TC57_VI_P_E_MOD", m_pGenericSegment->get("POS_CRD_DAT_IN_MOD"), strValue);
      else if (strPROC_ID_ISS_B == "EFTPOS" && m_bAdvRevTran)
         getGenericValue("TC57_EHB_PE_MOD", m_pGenericSegment->get("POS_CRD_DAT_IN_MOD"), strValue);
      else
         strValue.assign(m_pGenericSegment->get("AS2805_DE22").data(), min(size_t(2), m_pGenericSegment->get("AS2805_DE22").length()));
   }
   else if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "G")
   {
      mastercardipmmessageprocessor::hDATA_PRIV_ACQ* pDATA_PRIV_ACQ;
      pDATA_PRIV_ACQ = (struct mastercardipmmessageprocessor::hDATA_PRIV_ACQ*)m_pGenericSegment->get("DATA_PRIV_ACQ").data();
      strValue.assign(pDATA_PRIV_ACQ->sPOSEntryMode, 2);
   }
   else if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "T")
   {
      visabaseIImessageprocessor::hDATA_PRIV_ACQ* pDATA_PRIV_ACQ;
      pDATA_PRIV_ACQ = (struct visabaseIImessageprocessor::hDATA_PRIV_ACQ*)m_pGenericSegment->get("DATA_PRIV_ACQ").data();
      strValue.assign(pDATA_PRIV_ACQ->sPOSEntryMode, 2);
   }
  //## end report::TC57TransactionFile::setPOSEntryMode%67F3F04F0265.body
}

void TC57TransactionFile::setPrepaidCardInd (string& strValue)
{
  //## begin report::TC57TransactionFile::setPrepaidCardInd%67F3EF4C0040.body preserve=yes
   if (Extract::instance()->getCustomCode() == "COLES")
      getGenericValue("TC57_PREPAID_I", m_pGenericSegment->get("INST_ID_RECN_ISS_B"), strValue);
  //## end report::TC57TransactionFile::setPrepaidCardInd%67F3EF4C0040.body
}

void TC57TransactionFile::setRecurringPaymentIndicator (string& strValue)
{
  //## begin report::TC57TransactionFile::setRecurringPaymentIndicator%67F3EEED021E.body preserve=yes
   if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "A")
   {
      if (Extract::instance()->getCustomCode() != "CBA"
         || Extract::instance()->getCustomCode() != "PAAS")
      {
         if (getGenericValue("TC57_RPAY_IND", m_pGenericSegment->get("POS_CRDHLDR_PRESNT"), strValue) == false)
            getGenericValue("TC57_RPAY_IND", m_pGenericSegment->get("POS_CRD_DAT_IN_MOD"), strValue);
      }
      else
      {
         if (!memcmp(m_pGenericSegment->get("ADL_DATA_PRIV_ACQ").data(), "VE", 2))
         {
            visabaseii::segADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
            pADL_DATA_PRIV_ACQ = (struct visabaseii::segADL_DATA_PRIV_ACQ*)m_pGenericSegment->get("ADL_DATA_PRIV_ACQ").data();
            strValue = pADL_DATA_PRIV_ACQ->cPOSEnvironment;
         }
      }
   }
   else if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "G"
      && m_pGenericSegment->get("POS_CRDHLDR_PRESNT") == "4")
      strValue = "4";
   else if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "T")
   {
      visabaseIImessageprocessor::hDATA_PRIV_ACQ* pDATA_PRIV_ACQ;
      pDATA_PRIV_ACQ = (struct visabaseIImessageprocessor::hDATA_PRIV_ACQ*)m_pGenericSegment->get("DATA_PRIV_ACQ").data();
      getGenericValue("TC57_RPAY_IND", string(&pDATA_PRIV_ACQ->cPOS_OPER_ENV, 1), strValue);
   }
  //## end report::TC57TransactionFile::setRecurringPaymentIndicator%67F3EEED021E.body
}

void TC57TransactionFile::setTokenRequestorId (string& strValue)
{
  //## begin report::TC57TransactionFile::setTokenRequestorId%67F3F06E03D5.body preserve=yes
   if (Extract::instance()->getCustomCode() == "COLES")
   {
      if ((m_pGenericSegment->get("TOKEN_REQUESTOR_ID").length() > 0) && (memcmp(m_pGenericSegment->get("TOKEN_REQUESTOR_ID").data(), "801", 3)))
         strValue.assign(m_pGenericSegment->get("TOKEN_REQUESTOR_ID").data(), m_pGenericSegment->get("TOKEN_REQUESTOR_ID").length());
   }
   else
      strValue.assign(m_pGenericSegment->get("TOKEN_REQUESTOR_ID").data(), m_pGenericSegment->get("TOKEN_REQUESTOR_ID").length());
  //## end report::TC57TransactionFile::setTokenRequestorId%67F3F06E03D5.body
}

void TC57TransactionFile::setTransactionType (string& strValue)
{
  //## begin report::TC57TransactionFile::setTransactionType%67F3EFA80110.body preserve=yes
   bool bReturn;
   string strTRAN_TYPE_ID(m_pGenericSegment->get("TRAN_TYPE_ID").data(), 2);
   if (Extract::instance()->getCustomCode() == "COLES")
      bReturn = getGenericValue("TC57_TTYP_COLES", strTRAN_TYPE_ID, strValue);
   else
      bReturn = getGenericValue("TC57_TXNTYPE", strTRAN_TYPE_ID, strValue);
   if (!bReturn)
      strValue.assign("5", 1);
  //## end report::TC57TransactionFile::setTransactionType%67F3EFA80110.body
}

bool TC57TransactionFile::start (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::start%67DD90DA01E6.body preserve=yes
   postingfile::Report* pReport;
   pReport = postingfile::Reports::instance()->getReport(getDX_REPORT_ID());
   if (!pReport)
      return UseCase::setSuccess(false);
   m_pReport->addSegment('Z', &m_hGenericSegment[0]);
   m_pReport->addSegment('A', &m_hActivitySegment[0]);
   m_pReport->addSegment('B', &m_hActivitySegment[1]);
   m_pReport->addSegment('C', &m_hActivitySegment[2]);
   string strCONTEXT_DATA;
   m_pContext->get("FILM LOCATOR", strCONTEXT_DATA);
   m_hActivitySegment[1].set("FCNT", atoi(strCONTEXT_DATA.c_str()));
   const char* sKeys[CUSTOM_FIELDS] = { "RQST_A" };
   const char* sValues[CUSTOM_FIELDS] = { "ADDITIONAL_AMT" };
   m_hConstants.reserve(CUSTOM_FIELDS * 2);
   for (int i = 0; i < (CUSTOM_FIELDS * 2); i++)
      m_hConstants.push_back(string("", 20));
   for (int k = 0; k < CUSTOM_FIELDS; k++)
   {
      m_hConstants[k].assign(sKeys[k]);
      m_hConstants[CUSTOM_FIELDS + k].assign(sValues[k]);
   }
   map<string, pair<int, short>, less<string> >  hOffsetWidth = pReport->getOffsetWidth();
   map<string, pair<int, short>, less<string> >::iterator q;
   if ((q = hOffsetWidth.find("PAN")) != hOffsetWidth.end())
   {
      m_iField[PAN][OFFSET] = (*q).second.first;
      m_iField[PAN][LENGTH] = (*q).second.second;
      m_iFieldMaxLen = max((*q).second.first + (*q).second.second, m_iFieldMaxLen);
   }
   if ((q = hOffsetWidth.find("RETRIEVAL_REF_NO")) != hOffsetWidth.end())
   {
      m_iField[RETRIEVAL_REF_NO][OFFSET] = (*q).second.first;
      m_iField[RETRIEVAL_REF_NO][LENGTH] = (*q).second.second;
      m_iFieldMaxLen = max((*q).second.first + (*q).second.second, m_iFieldMaxLen);
   }
   if ((q = hOffsetWidth.find("APPROVAL_CODE")) != hOffsetWidth.end())
   {
      m_iField[APPROVAL_CODE][OFFSET] = (*q).second.first;
      m_iField[APPROVAL_CODE][LENGTH] = (*q).second.second;
      m_iFieldMaxLen = max((*q).second.first + (*q).second.second, m_iFieldMaxLen);
   }
   if ((q = hOffsetWidth.find("MTI")) != hOffsetWidth.end())
   {
      m_iField[MTI][OFFSET] = (*q).second.first;
      m_iField[MTI][LENGTH] = (*q).second.second;
      m_iFieldMaxLen = max((*q).second.first + (*q).second.second, m_iFieldMaxLen);
   }
   if ((q = hOffsetWidth.find("TSTAMP_TRANS")) != hOffsetWidth.end())
   {
      m_iField[TSTAMP_TRANS][OFFSET] = (*q).second.first;
      m_iField[TSTAMP_TRANS][LENGTH] = (*q).second.second;
      m_iFieldMaxLen = max((*q).second.first + (*q).second.second, m_iFieldMaxLen);
   }
   if ((q = hOffsetWidth.find("REF_DATA_ISS")) != hOffsetWidth.end())
   {
      m_iField[REF_DATA_ISS][OFFSET] = (*q).second.first;
      m_iField[REF_DATA_ISS][LENGTH] = (*q).second.second;
      m_iFieldMaxLen = max((*q).second.first + (*q).second.second, m_iFieldMaxLen);
   }
   if ((q = hOffsetWidth.find("PROC_ID_ISS_B")) != hOffsetWidth.end())
   {
      m_iField[PROC_ID_ISS_B][OFFSET] = (*q).second.first;
      m_iField[PROC_ID_ISS_B][LENGTH] = (*q).second.second;
      m_iFieldMaxLen = max((*q).second.first + (*q).second.second, m_iFieldMaxLen);
   }
   if ((q = hOffsetWidth.find("NET_ID_ISS")) != hOffsetWidth.end())
   {
      m_iField[NET_ID_ISS][OFFSET] = (*q).second.first;
      m_iField[NET_ID_ISS][LENGTH] = (*q).second.second;
      m_iFieldMaxLen = max((*q).second.first + (*q).second.second, m_iFieldMaxLen);
   }
   return true;
  //## end report::TC57TransactionFile::start%67DD90DA01E6.body
}

bool TC57TransactionFile::unionAll (Query& hQuery)
{
  //## begin report::TC57TransactionFile::unionAll%67DD910C0057.body preserve=yes
   int iDX_FILE_ID = 0;
   Query hQuery1;
   hQuery1.bind("DX_DATA_CONTROL", "DX_FILE_ID", Column::LONG, &iDX_FILE_ID);
   hQuery1.setBasicPredicate("DX_DATA_CONTROL", "DX_FILE_TYPE", "=", "UMAUTH");
   hQuery1.setBasicPredicate("DX_DATA_CONTROL", "DATE_RECON", "=", getDATE_RECON().c_str());
   auto_ptr<SelectStatement> pSelectStatement((SelectStatement*)DatabaseFactory::instance()->create("SelectStatement"));
   if (!pSelectStatement->execute(hQuery1))
      return false;
   if (pSelectStatement->getRows() == 1)
   {
      m_hQuery[0].setSubSelect(true);
      m_hQuery[0] = hQuery;
      m_hQuery[0].getSearchCondition().erase();
      string strTableName("DX_DATA_");
      strTableName.append(getDATE_RECON());
      strTableName.append(" DX");
      m_hQuery[0].setBasicPredicate(strTableName.c_str(), "DX_FILE_ID", "=", iDX_FILE_ID);
      hQuery.setQuery(&m_hQuery[0]);
   }
   return true;
  //## end report::TC57TransactionFile::unionAll%67DD910C0057.body
}

bool TC57TransactionFile::write_TCR0_BatchHeader (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR0_BatchHeader%626103D50392.body preserve=yes
   string strMerchNo;
   string strTerminalNo;
   switch (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID")[0])
   {
   case 'A':
      getGenericValue("IST_TC57_AIIC", m_hGenericSegment[0].get("INST_ID_RECN_ISS_B"), m_strBatchToValue);
      strMerchNo = m_hGenericSegment[0].get("RPT_LVL_ID_B");
      strTerminalNo = m_hGenericSegment[0].get("CARD_ACPT_TERM_ID");
      break;
   case 'G':
      getGenericValue("IST_TC57_AIIC", m_hGenericSegment[0].get("INST_ID_RECN_ISS_B"), m_strBatchToValue);
      strMerchNo = m_hGenericSegment[0].get("CARD_ACPT_ID");
      strTerminalNo = m_hGenericSegment[0].get("CARD_ACPT_TERM_ID");
      break;
   case 'T':
      m_strBatchToValue = m_hGenericSegment[0].get("INST_ID_ISS");
      strMerchNo = m_hGenericSegment[0].get("CARD_ACPT_ID");
      strTerminalNo = m_hGenericSegment[0].get("CARD_ACPT_TERM_ID");
      break;
   default:
      getGenericValue("IST_TC57_AIIC", m_hGenericSegment[0].get("INST_ID_RECN_ISS_B"), m_strBatchToValue);
      strMerchNo = m_hGenericSegment[0].get("RPT_LVL_ID_B");
      strTerminalNo = m_hGenericSegment[0].get("NET_TERM_ID");
   }
   if (m_strBatchToValue.length() > 6)
      m_strBatchToValue.erase(0, m_strBatchToValue.length() - 6);
   m_hActivitySegment[1].set("ZBIN", m_strBatchToValue);
   Date hDate(m_hGenericSegment[0].get("DATE_RECON_NET").data());
   m_hActivitySegment[1].set("ZJDATE", hDate.asString("%y%j").data() + 1);
   hDate = m_hGenericSegment[0].get("DATE_ACTION").c_str();
   m_hActivitySegment[1].set("ZJADATE", hDate.asString("%y%j").data() + 1);
   m_hActivitySegment[1].set("ZMERCHNO", strMerchNo);
   m_hActivitySegment[1].set("ZTERMNO", strTerminalNo);
   if (Extract::instance()->getCustomCode() == "COLES" && !m_hGenericSegment[0].get("{InSrcNode|").empty())
      m_hActivitySegment[0].set("ZTERMNO", m_hGenericSegment[0].get("CARD_ACPT_TERM_ID"));
   m_hActivitySegment[1].set("ZBTIME", Clock::instance()->getYYYYMMDDHHMMSS(1).data() + 8);
   char szGMTOffset[3];
   snprintf(szGMTOffset, sizeof(szGMTOffset), "%02d", (int)Clock::instance()->getGMTOffset());
   m_hActivitySegment[1].set("OFFSET", szGMTOffset);
   m_hActivitySegment[2].reset();
   m_hActivitySegment[1].set("BATCH_NO", ++m_iBatchNo);
   m_hActivitySegment[2].set("BKEY", 1);
   m_hActivitySegment[2].set("TCR", 1);
   m_hActivitySegment[2].set("TTCR", 1);
   m_hActivitySegment[2].set("TTCNT", 1);
   m_hActivitySegment[0] += m_hActivitySegment[2];
   return m_pReport->report("R0");
  //## end report::TC57TransactionFile::write_TCR0_BatchHeader%626103D50392.body
}

bool TC57TransactionFile::write_TCR0_BatchTrailer (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR0_BatchTrailer%6261041003C3.body preserve=yes
   m_hActivitySegment[2].reset();
   m_hActivitySegment[2].set("BKEY", 1);
   m_hActivitySegment[2].set("TCR", 1);
   m_hActivitySegment[2].set("TTCR", 1);
   m_hActivitySegment[2].set("TTCNT", 1);
   m_hActivitySegment[0] += m_hActivitySegment[2];
   if (m_dBatchNetAmt < 0)
   {
      m_dBatchNetAmt = -1 * m_dBatchNetAmt;
      m_hActivitySegment[0].set("BASIGN", "CR");
   }
   m_hActivitySegment[0].set("BNETAMT", m_dBatchNetAmt);
   m_hActivitySegment[0].set("BGROSSAMT", m_dBatchGrossAmt);
   return m_pReport->report("T0");
  //## end report::TC57TransactionFile::write_TCR0_BatchTrailer%6261041003C3.body
}

bool TC57TransactionFile::write_TCR0_TxnDetail (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR0_TxnDetail%626103F00319.body preserve=yes
   m_hActivitySegment[2].reset();
   m_hActivitySegment[2].set("BKEY", 1);
   m_hActivitySegment[2].set("TCR", 1);
   m_hActivitySegment[2].set("TTCR", 1);
   m_hActivitySegment[2].set("TTCNT", 1);
   m_hActivitySegment[2].set("BCNT", 1);
   m_hActivitySegment[2].set("FCNT", 1);
   m_hActivitySegment[0] += m_hActivitySegment[2];
   //Storing back the Connex Segment1 AmtTran to AMT_TRAN to cater the Connex Transaction loading code
   if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "A"
      && m_hGenericSegment[0].get("ACT_CODE") > "099"
      && atof(m_hGenericSegment[0].get("AMT_TRAN").data()) == 0)
      m_hGenericSegment[0].set("AMT_TRAN", m_hGenericSegment[0].get("AMT_RECON_NET"));
   m_dTotNetAmt += atof(m_hGenericSegment[0].get("AMT_TRAN").data());
   string strMTI(m_hGenericSegment[0].get("MTI"));
   if (strMTI.length() > 1 && strMTI[1] == '4')
      m_hGenericSegment[0].set("ZREVFLAG", "R");
   m_hGenericSegment[0].set("ZTRAN_VOID_IND", "0");
   string strToValue, strValue;
   if (getGenericValue("TC57_ENTRY_METH", m_hGenericSegment[0].get("POS_CRD_DAT_IN_CAP"), strToValue))
      m_hGenericSegment[0].set("ZCARD_ENTRY", strToValue);
   else
      m_hGenericSegment[0].set("ZCARD_ENTRY", m_hGenericSegment[0].get("POS_CRD_DAT_IN_CAP"));
   m_hGenericSegment[0].set("ZAUTHIND", "N");
   m_hGenericSegment[0].set("ZDATE", m_hGenericSegment[0].get("TSTAMP_TRANS").data() + 4);
   m_hGenericSegment[0].set("ZTIME", m_hGenericSegment[0].get("TSTAMP_TRANS").data() + 8);
   m_bAdvRevTran = false;
   if (m_hGenericSegment[0].get("MTI") == "1240" || m_hGenericSegment[0].get("MTI")[1] == '4'
      || m_hGenericSegment[0].get("TRAN_DISPOSITION") == "2")
      m_bAdvRevTran = true;
   string strPROC_ID_ISS_B = m_hGenericSegment[0].get("PROC_ID_ISS_B");
   if (Extract::instance()->getCustomCode() == "COLES")
   {
      string strTRAN_TYPE_ID(m_hGenericSegment[0].get("TRAN_TYPE_ID"), 2);
      if (strTRAN_TYPE_ID == "18" || strTRAN_TYPE_ID == "20" || strTRAN_TYPE_ID == "26" || strTRAN_TYPE_ID == "28")
      {
         if (strMTI == "1430")
            m_dBatchNetAmt += atof(m_hGenericSegment[0].get("AMT_TRAN").substr(6).data());
         else
            m_dBatchNetAmt -= atof(m_hGenericSegment[0].get("AMT_TRAN").substr(6).data());
      }
      else
      {
         if (strMTI == "1430")
            m_dBatchNetAmt -= atof(m_hGenericSegment[0].get("AMT_TRAN").substr(6).data());
         else
            m_dBatchNetAmt += atof(m_hGenericSegment[0].get("AMT_TRAN").substr(6).data());
      }
      m_dBatchGrossAmt += atof(m_hGenericSegment[0].get("AMT_TRAN").substr(6).data());
   }
   else
   {
      string strTRAN_TYPE_ID(m_hGenericSegment[0].get("TRAN_TYPE_ID"), 0, 2);
      if (strTRAN_TYPE_ID == "18" || strTRAN_TYPE_ID == "20"
         || strTRAN_TYPE_ID == "26" || strTRAN_TYPE_ID == "28")
      {
         if (strMTI.length() > 1 && strMTI[1] == '4')
            m_dBatchNetAmt += atof(m_hGenericSegment[0].get("AMT_TRAN").data());
         else
            m_dBatchNetAmt -= atof(m_hGenericSegment[0].get("AMT_TRAN").data());
      }
      else
      {
         if (strMTI.length() > 1 && strMTI[1] == '4')
            m_dBatchNetAmt -= atof(m_hGenericSegment[0].get("AMT_TRAN").data());
         else
            m_dBatchNetAmt += atof(m_hGenericSegment[0].get("AMT_TRAN").data());
      }
      m_dBatchGrossAmt += atof(m_hGenericSegment[0].get("AMT_TRAN").data());
   }
   if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "A")
   {
      if (!memcmp(m_szADL_DATA_PRIV_ACQ, "MC", 2))
      {
         mastercardcis::segADL_DATA_PRIV_ACQ_Advantage* pADL_DATA_PRIV_ACQ;
         pADL_DATA_PRIV_ACQ = (struct mastercardcis::segADL_DATA_PRIV_ACQ_Advantage*)m_szADL_DATA_PRIV_ACQ;
         m_hGenericSegment[0].set("ZSMERCHID", pADL_DATA_PRIV_ACQ->sMERCHANT_ID);
         m_hGenericSegment[0].set("ZPAYMENT_FID", pADL_DATA_PRIV_ACQ->sPAYMENT_FID);
      }
      else if (!memcmp(m_szADL_DATA_PRIV_ACQ, "MD", 2))
      {
         mastercardmds::segADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
         pADL_DATA_PRIV_ACQ = (struct mastercardmds::segADL_DATA_PRIV_ACQ*)m_szADL_DATA_PRIV_ACQ;
         m_hGenericSegment[0].set("ZSMERCHID", pADL_DATA_PRIV_ACQ->sMERCHANT_ID);
         m_hGenericSegment[0].set("ZPAYMENT_FID", pADL_DATA_PRIV_ACQ->sPAYMENT_FID);
      }
      else if (!memcmp(m_szADL_DATA_PRIV_ACQ, "VE", 2))
      {
         visabaseii::segADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
         pADL_DATA_PRIV_ACQ = (struct visabaseii::segADL_DATA_PRIV_ACQ*)m_szADL_DATA_PRIV_ACQ;
         if (pADL_DATA_PRIV_ACQ->cAUTH_CHAR_FLAG != ' ')
            m_hGenericSegment[0].set("ZAUTHIND", string(&pADL_DATA_PRIV_ACQ->cAUTH_CHAR_FLAG, 1));
         m_hGenericSegment[0].set("ZSMERCHID", pADL_DATA_PRIV_ACQ->sSubMerchantID);
         m_hGenericSegment[0].set("ZPAYMENT_FID", pADL_DATA_PRIV_ACQ->sMarketplaceID);
      }
      if (strPROC_ID_ISS_B == "VISA")
      {
         visabaseii::segREF_DATA_ISS_EVES* pREF_DATA_ISS_baseii = (struct visabaseii::segREF_DATA_ISS_EVES*)m_szREF_DATA_ISS;
         strValue = pREF_DATA_ISS_baseii->cReasoncode;
         m_hGenericSegment[0].set("ZAUTH_SOURCE_CODE", strValue);
      }
      string strTstampLocalAdj = m_hGenericSegment[0].get("TSTAMP_LOCAL_ADJ");
      if (strTstampLocalAdj.length() == 14)
      {
         m_hGenericSegment[0].set("ZDATE", strTstampLocalAdj + 4);
         m_hGenericSegment[0].set("ZTIME", strTstampLocalAdj + 8);
      }
      m_hGenericSegment[0].set("ZCSEQ_NO", m_hGenericSegment[0].get("CARD_SEQ_NO"));
      m_hGenericSegment[0].set("ZCCODE", m_hGenericSegment[0].get("AS2805_DE25"));
      char szSRV_CODE[3];
      memset(szSRV_CODE, ' ', 3);
      szSRV_CODE[0] = m_hGenericSegment[0].get("SRV_GRP_INTCHG_IND")[0];
      memcpy(szSRV_CODE + 1, m_hGenericSegment[0].get("SRV_GRP_SERV_CODE").data(), 2);
      m_hGenericSegment[0].set("ZSRV_GRP_SERV_CODE", szSRV_CODE);
      m_hGenericSegment[0].set("ZPDATE", string(m_hGenericSegment[0].get("TSTAMP_LOCAL").data() + 4, 4));
      m_hGenericSegment[0].set("ZTRANTIME", string(m_hGenericSegment[0].get("TSTAMP_LOCAL").data() + 8, 4));
   }
   else if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "G")
   {
      mastercardipmmessageprocessor::hDATA_PRIV_ACQ* pDATA_PRIV_ACQ;
      pDATA_PRIV_ACQ = (struct mastercardipmmessageprocessor::hDATA_PRIV_ACQ*)m_szDATA_PRIV_ACQ;
      mastercardipmmessageprocessor::hEXTENSION_DATA_ADJ* pEXTENSION_DATA_ADJ;
      pEXTENSION_DATA_ADJ = (struct mastercardipmmessageprocessor::hEXTENSION_DATA_ADJ*)m_szEXTENSION_DATA_ADJ;
      m_hGenericSegment[0].set("ZAUTH_SOURCE_CODE", "5");
      if (m_hGenericSegment[0].get("NET_ID_ISS") == "VNT")
      {
         mastercardipmmessageprocessor::hADL_RESP_DATA* pADL_RESP_DATA;
         pADL_RESP_DATA = (struct mastercardipmmessageprocessor::hADL_RESP_DATA*)m_szADL_RESP_DATA;
         m_hGenericSegment[0].set("ZAUTHIND", string(&pADL_RESP_DATA->cACIInd, 1));
         visasms::segADL_DATA_PRIV_ISS* pADL_DATA_PRIV_ISSsms = (visasms::segADL_DATA_PRIV_ISS*)m_szADL_DATA_PRIV_ISS;
         m_hGenericSegment[0].set("ZTOKENRESPINFO", string(&pADL_DATA_PRIV_ISSsms->cAdd_Token_Resp_Info, 1));
      }
      m_hGenericSegment[0].set("ZSMERCHID", pEXTENSION_DATA_ADJ->sSub_Merchant_ID);
      m_hGenericSegment[0].set("ZMSGID", "10");
      m_hGenericSegment[0].set("ZCCODE", pDATA_PRIV_ACQ->sPOSCondCode);
      m_hGenericSegment[0].set("ZPAYMENT_FID", pEXTENSION_DATA_ADJ->sPayment_Facilitator_ID);
      m_hGenericSegment[0].set("ZPDATE", string(m_hGenericSegment[0].get("TSTAMP_LOCAL").data() + 4, 4));
      m_hGenericSegment[0].set("ZTRANTIME", string(m_hGenericSegment[0].get("TSTAMP_LOCAL").data() + 8, 4));
   }
   else if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "T")
   {
      visabaseIImessageprocessor::hDATA_PRIV_ACQ* pDATA_PRIV_ACQ;
      pDATA_PRIV_ACQ = (struct visabaseIImessageprocessor::hDATA_PRIV_ACQ*)m_szDATA_PRIV_ACQ;
      m_hGenericSegment[0].set("ZAUTH_SOURCE_CODE", m_hGenericSegment[0].get("AUTH_BY"));
      m_hGenericSegment[0].set("ZDATE", m_hGenericSegment[0].get("DATE_RECON_ISS").data() + 4);
      m_hGenericSegment[0].set("ZTIME", "000000");
      m_hGenericSegment[0].set("ZCSEQ_NO", "000");
      m_hGenericSegment[0].set("ZMSGID", "10");
      m_hGenericSegment[0].set("ZCCODE", pDATA_PRIV_ACQ->sPOSConditionCode);
      m_hGenericSegment[0].set("ZMSG_RESON_CODE_ACQ", m_hGenericSegment[0].get("MSG_RESON_CODE_ACQ"));
      m_hGenericSegment[0].set("ZPDATE", string(m_hGenericSegment[0].get("TSTAMP_TRANS") + 4, 4));
      m_hGenericSegment[0].set("ZTRANTIME", string(m_hGenericSegment[0].get("TSTAMP_TRANS").data() + 8, 4));
      if (m_hGenericSegment[0].get("NET_ID_ISS") == "MCI")
      {
         mastercardmds::segADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
         pADL_DATA_PRIV_ACQ = (struct mastercardmds::segADL_DATA_PRIV_ACQ*)m_szADL_DATA_PRIV_ACQ;
         m_hGenericSegment[0].set("ZPAYMENT_FID", pADL_DATA_PRIV_ACQ->sPAYMENT_FID);
      }
   }
   return m_pReport->report("D0");
  //## end report::TC57TransactionFile::write_TCR0_TxnDetail%626103F00319.body
}

bool TC57TransactionFile::write_TCR1_AmexTxnDetailAdviceBasic (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR1_AmexTxnDetailAdviceBasic%633EBF2300A1.body preserve=yes
   m_hActivitySegment[2].reset();
   m_hActivitySegment[2].set("BKEY", 1);
   m_hActivitySegment[2].set("TCR", 1);
   m_hActivitySegment[2].set("TTCR", 1);
   m_hActivitySegment[0] += m_hActivitySegment[2];
   if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "A")
      m_hGenericSegment[0].set("ZTRAN_IDE", string(m_szREF_DATA_ISS + 32, 15));
   if (!m_hGenericSegment[0].get("SELLER_PHONE").empty())
      m_hGenericSegment[0].set("ZMERCH_CINFO", m_hGenericSegment[0].get("SELLER_PHONE"));
   else
      m_hGenericSegment[0].set("ZMERCH_CINFO", m_hGenericSegment[0].get("SELLER_EMAIL"));
   string strChannel;
   ConfigurationRepository::instance()->mapItem("X_INST_ID_RECON", m_hGenericSegment[0].get("INST_ID_RECON_ACQ"), "", "A", strChannel);
   if (memcmp(m_hGenericSegment[0].get("ADL_DATA_NATIONAL").data(), "*3D*\\", 5) == 0
      || (strChannel == "CBASSE" && !m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").empty()))
   {
      if (m_hGenericSegment[0].get("POS_CRDHLDR_A_METH") == "7")
         m_hGenericSegment[0].set("ZECOM_IND", "05");
      else if (m_hGenericSegment[0].get("POS_CRDHLDR_A_METH") == "8")
         m_hGenericSegment[0].set("ZECOM_IND", "06");
      else if (m_hGenericSegment[0].get("POS_CRDHLDR_A_METH") == "9")
         m_hGenericSegment[0].set("ZECOM_IND", "07");
      else if (!m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").empty())
         m_hGenericSegment[0].set("ZECOM_IND", "20");
   }
   return m_pReport->report("AB");
  //## end report::TC57TransactionFile::write_TCR1_AmexTxnDetailAdviceBasic%633EBF2300A1.body
}

bool TC57TransactionFile::write_TCR1_BatchHeader (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR1_BatchHeader%626103E9012D.body preserve=yes
   m_hActivitySegment[2].reset();
   m_hActivitySegment[2].set("BKEY", 1);
   m_hActivitySegment[2].set("TCR", 1);
   m_hActivitySegment[2].set("TTCR", 1);
   m_hActivitySegment[2].set("TTCNT", 1);
   m_hActivitySegment[0] += m_hActivitySegment[2];
   return m_pReport->report("R1");
  //## end report::TC57TransactionFile::write_TCR1_BatchHeader%626103E9012D.body
}

bool TC57TransactionFile::write_TCR1_DinersIntlChargeDetailRecord (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR1_DinersIntlChargeDetailRecord%6268B338005A.body preserve=yes
   m_hActivitySegment[2].reset();
   m_hActivitySegment[2].set("BKEY", 1);
   m_hActivitySegment[2].set("TCR", 1);
   m_hActivitySegment[2].set("TTCR", 1);
   m_hActivitySegment[0] += m_hActivitySegment[2];
   string strValue;
   string strCardDataInputMode(m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD").data(), m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD").length());
   string strMTI(m_hGenericSegment[0].get("MTI").data(), m_hGenericSegment[0].get("MTI").length());
   string strTTID(m_hGenericSegment[0].get("TRAN_TYPE_ID").substr(0, 2), 2);
   switch (strCardDataInputMode[0])
   {
   case '5':
      if (strTTID == "20")
         strValue = (strMTI[1] == '4') ? "TK" : "TL";
      else
         strValue = (strMTI[1] != '4') ? "TK" : "TL";
      break;
   case 'R':
      if (strTTID == "20")
         strValue = (strMTI[1] == '4') ? "TI" : "TJ";
      else
         strValue = (strMTI[1] != '4') ? "TI" : "TJ";
      break;
   case 'A':
   case 'B':
   case 'C':
   case 'M':
      if (strTTID == "20")
         strValue = (strMTI[1] == '4') ? "TE" : "TG";
      else
         strValue = (strMTI[1] != '4') ? "TE" : "TG";
      break;
   default:
      if (strTTID == "20")
         strValue = (strMTI[1] == '4') ? "TD" : "TF";
      else
         strValue = (strMTI[1] != '4') ? "TD" : "TF";
      break;
   }
   m_hGenericSegment[0].set("ZCTYPE", strValue);
   char szAdtlDataNatl[100];
   memset(szAdtlDataNatl, ' ', sizeof(szAdtlDataNatl) - 1);
   szAdtlDataNatl[sizeof(szAdtlDataNatl) - 1] = '\0';
   memcpy(szAdtlDataNatl, m_hGenericSegment[0].get("ADL_DATA_NATIONAL").data(), 100);
   const string& strEXTENSION_DATA_ADJ = m_hGenericSegment[0].get("EXTENSION_DATA_ADJ");
   size_t pos = strEXTENSION_DATA_ADJ.find("{DF09|01");
   if (pos != string::npos)
      m_bDF09Presence = true;
   if (memcmp(szAdtlDataNatl, "*3D*\\", 5) == 0
      && memcmp(szAdtlDataNatl + 9, "CA", 2) == 0)
   {
      string strTemp;
      if (m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD") == "R")
         strTemp = "34";
      else if (m_hGenericSegment[0].get("POS_CRDHLDR_A_METH") == "7")
         strTemp = "25";
      else if (m_hGenericSegment[0].get("POS_CRDHLDR_A_METH") == "8")
         strTemp = "26";
      if (strTemp.length() > 0)
      {
         if (m_bDF09Presence)
         {
            m_hGenericSegment[0].set("ZAUTH_TYPE", " ");
            m_hGenericSegment[0].set("ZECOM_PAY_IND", "4");
         }
         else
         {
            m_hGenericSegment[0].set("ZAUTH_TYPE", string(strTemp[0], 1));
            m_hGenericSegment[0].set("ZECOM_PAY_IND", string(strTemp[1], 1));
         }
      }
      strTemp.assign(szAdtlDataNatl + 21, 4);
      m_hGenericSegment[0].set("ZECOMIND", strTemp);
      strTemp.assign(szAdtlDataNatl + 15, 2);
      m_hGenericSegment[0].set("ZPAUTH", strTemp);
      strTemp.assign(szAdtlDataNatl + 17, 2);
      m_hGenericSegment[0].set("ZSFRESP_CODE", strTemp);
      strTemp.assign(szAdtlDataNatl + 19, 2);
      m_hGenericSegment[0].set("ZCAVVIND", strTemp);
      strTemp.assign(szAdtlDataNatl + 29, 16);
      m_hGenericSegment[0].set("ZATN", strTemp);
      if (m_bDF09Presence)
         m_hGenericSegment[0].set("ZVAUTH", "  ");
      else
      {
         strTemp.assign(szAdtlDataNatl + 45, 2);
         m_hGenericSegment[0].set("ZVAUTH", strTemp);
      }
      strTemp.assign(szAdtlDataNatl + 47, 8);
      m_hGenericSegment[0].set("ZIPADD", strTemp);
   }
   strValue.erase();
   if (strMTI[1] == '4')
      strValue.assign("000", 3);
   else if (memcmp(m_szDATA_PRIV_ISS + 51, "   ", 3) == 0)
      strValue.assign(m_hGenericSegment[0].get("ACT_CODE").data(), m_hGenericSegment[0].get("ACT_CODE").length());
   else
      strValue.assign(m_szDATA_PRIV_ISS + 51, 3);
   m_hGenericSegment[0].set("ZACT_CODE", strValue);
   char szPOSFLGS[4];
   memset(szPOSFLGS, ' ', 4);
   if (m_bAdvRevTran)
   {
      string strToValue;
      if (m_hGenericSegment[0].get("TERM_CLASS") == "25")
         szPOSFLGS[0] = '9';
      else
         szPOSFLGS[0] = m_hGenericSegment[0].get("POS_CRDHLDR_PRESNT")[0];
      szPOSFLGS[1] = m_hGenericSegment[0].get("POS_CARD_PRES")[0];
      if (getGenericValue("TC57_DC_REV_MOD", m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD"), strToValue))
         szPOSFLGS[2] = strToValue[0];
      else
         szPOSFLGS[2] = m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD")[0];
      if (getGenericValue("TC57_DC_REV_CAP", m_hGenericSegment[0].get("POS_CRD_DAT_IN_CAP"), strToValue))
         szPOSFLGS[3] = strToValue[0];
      else
         szPOSFLGS[3] = m_hGenericSegment[0].get("POS_CRD_DAT_IN_CAP")[0];
   }
   else if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "A")
   {
      szPOSFLGS[0] = m_szDATA_PRIV_ISS[39];
      szPOSFLGS[1] = m_szDATA_PRIV_ISS[40];
      szPOSFLGS[2] = m_szDATA_PRIV_ISS[41];
      szPOSFLGS[3] = m_szDATA_PRIV_ISS[35];
   }
   m_hGenericSegment[0].set("ZPOSFLGS", szPOSFLGS);
   if (getGenericValue("TC57_CAVV_RESLT", m_hGenericSegment[0].get("CAVV_RESULT"), strValue))
      m_hGenericSegment[0].set("ZCAVV_RESULT", strValue);
   return m_pReport->report("DI");
  //## end report::TC57TransactionFile::write_TCR1_DinersIntlChargeDetailRecord%6268B338005A.body
}

bool TC57TransactionFile::write_TCR1_TxnDetail_Common (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR1_TxnDetail_Common%626103F501BF.body preserve=yes
   m_hActivitySegment[2].reset();
   m_hActivitySegment[2].set("BKEY", 1);
   m_hActivitySegment[2].set("TCR", 1);
   m_hActivitySegment[2].set("TTCR", 1);
   m_hActivitySegment[0] += m_hActivitySegment[2];
   return m_pReport->report("D1");
  //## end report::TC57TransactionFile::write_TCR1_TxnDetail_Common%626103F501BF.body
}

bool TC57TransactionFile::write_TCR2_AmexCAPNBatchHeader (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR2_AmexCAPNBatchHeader%633EBEFA0373.body preserve=yes
   if (m_hGenericSegment[0].get("NET_ID_ISS") == "AMX" || m_hGenericSegment[0].get("NET_ID_ISS") == "JCB")
   {
      m_hActivitySegment[2].reset();
      m_hActivitySegment[2].set("BKEY", 1);
      m_hActivitySegment[2].set("TCR", 1);
      m_hActivitySegment[2].set("TTCR", 1);
      m_hActivitySegment[2].set("TTCNT", 1);
      m_hActivitySegment[0] += m_hActivitySegment[2];
      return m_pReport->report("AC");
   }
   return true;
  //## end report::TC57TransactionFile::write_TCR2_AmexCAPNBatchHeader%633EBEFA0373.body
}

bool TC57TransactionFile::write_TCR3_DinersIntlChipAddtlRecord (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR3_DinersIntlChipAddtlRecord%633EBF340378.body preserve=yes
   if (m_hGenericSegment[0].get("APPL_INTRCHG_PROF").empty() == false
      || m_hGenericSegment[0].get("APPL_TRAN_COUNTER").empty() == false
      || m_hGenericSegment[0].get("APPL_CRYPTOGRAM").empty() == false
      || m_hGenericSegment[0].get("CRYPT_INFO_DATA").empty() == false
      || m_hGenericSegment[0].get("TERM_COUNTRY_CODE").empty() == false
      || m_hGenericSegment[0].get("TERM_CAPABILITIES").empty() == false
      || m_hGenericSegment[0].get("TERMINAL_TYPE").empty() == false
      || m_hGenericSegment[0].get("TERM_VERIFY_RESULT").empty() == false
      || m_hGenericSegment[0].get("TRAN_DATE").empty() == false
      || m_hGenericSegment[0].get("TRAN_TYPE").empty() == false
      || m_hGenericSegment[0].get("TRAN_CURRENCY_CODE").empty() == false
      || m_hGenericSegment[0].get("AMOUNT_OTHER").empty() == false
      || m_hGenericSegment[0].get("ISS_APPL_DATA").empty() == false
      || m_hGenericSegment[0].get("UNPREDICTABLE_NO").empty() == false
      || m_hGenericSegment[0].get("CARDH_VER_RESULT").empty() == false
      || m_hGenericSegment[0].get("DEDICATED_FILE_NAM").empty() == false
      || m_hGenericSegment[0].get("APPL_VERSION_NO").empty() == false
      || m_hGenericSegment[0].get("TERM_SERIAL_NO").empty() == false
      || m_hGenericSegment[0].get("ISS_AUTH_DATA").empty() == false
      || m_hGenericSegment[0].get("CRYPTOGRAM_AMOUNT").empty() == false
      || m_hGenericSegment[0].get("ISS_SCRIPT_RESULT").empty() == false
      || m_hGenericSegment[0].get("APPL_ID").empty() == false)
   {
      m_hActivitySegment[2].reset();
      m_hActivitySegment[2].set("BKEY", 1);
      m_hActivitySegment[2].set("TCR", 1);
      m_hActivitySegment[2].set("TTCR", 1);
      m_hActivitySegment[0] += m_hActivitySegment[2];
      return m_pReport->report("IC");
   }
   return false;
  //## end report::TC57TransactionFile::write_TCR3_DinersIntlChipAddtlRecord%633EBF340378.body
}

bool TC57TransactionFile::write_TCR3_PassangerTravelLegRecord (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR3_PassangerTravelLegRecord%6268B2BD01DF.body preserve=yes
   return true;
  //## end report::TC57TransactionFile::write_TCR3_PassangerTravelLegRecord%6268B2BD01DF.body
}

bool TC57TransactionFile::write_TCR3_TxnDetail_PaymentServiceData (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR3_TxnDetail_PaymentServiceData%6268B2160286.body preserve=yes
   m_hActivitySegment[2].reset();
   m_hActivitySegment[2].set("BKEY", 1);
   m_hActivitySegment[2].set("TCR", 1);
   m_hActivitySegment[2].set("TTCR", 1);
   m_hActivitySegment[0] += m_hActivitySegment[2];
   m_hGenericSegment[0].set("ZVALID_CODE", "0000");
   m_hGenericSegment[0].set("ZACT_CODE", m_hGenericSegment[0].get("ACT_CODE"));
   if (m_hGenericSegment[0].get("ACT_CODE") == "400"
      || (m_hGenericSegment[0].get("ACT_CODE") > "000"
         && m_hGenericSegment[0].get("ACT_CODE") < "100"))
      m_hGenericSegment[0].set("ZACT_CODE", "000");
   string strValue(m_hGenericSegment[0].get("MULTI_CLEAR_SEQ_NO"));
   strValue.resize(2, ' ');
   strValue.append(m_hGenericSegment[0].get("MULTI_CLEAR_COUNT"));
   strValue.resize(3, ' ');
   if (strValue[0] == ' ')
      strValue.assign("0000",4);
   m_hGenericSegment[0].set("ZMSEQ_CNT", strValue);
   strValue.erase();
   if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "A")
   {
      m_hGenericSegment[0].set("ZCAVVRESULT", m_hGenericSegment[0].get("CAVV_RESULT"));
      m_hGenericSegment[0].set("ZMERCH", m_hGenericSegment[0].get("{DFA3|"));
      if (!memcmp(m_szADL_DATA_PRIV_ACQ, "VE", 2))
      {
         visabaseii::segADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
         pADL_DATA_PRIV_ACQ = (struct visabaseii::segADL_DATA_PRIV_ACQ*)m_szADL_DATA_PRIV_ACQ;
         strValue = pADL_DATA_PRIV_ACQ->cMARKET_FLAG;
         m_hGenericSegment[0].set("ZMKTIND", strValue);
         if (m_hGenericSegment[0].get("{DFA3|").empty())
         {
            strValue.assign(pADL_DATA_PRIV_ACQ->sMERCH_VERIFY_VALUE, 10);
            m_hGenericSegment[0].set("ZMERCH", strValue);
         }
         strValue = pADL_DATA_PRIV_ACQ->cSpendQualifiedIndicator;
         m_hGenericSegment[0].set("ZSSQUALIND", strValue);
      }
      if (m_hGenericSegment[0].get("REF_DATA_ISS_FMT") == "4")
      {
         visabaseii::segREF_DATA_ISS_EVES* pREF_DATA_ISS_baseii = (struct visabaseii::segREF_DATA_ISS_EVES*)m_szREF_DATA_ISS;
         strValue.assign(pREF_DATA_ISS_baseii->sPRODUCT_ID, 2);
         m_hGenericSegment[0].set("ZCRDRES", strValue);
      }
      if (memcmp(m_szREF_DATA_ISS + 59, "    ", 4))
         m_hGenericSegment[0].set("ZVALID_CODE", m_szREF_DATA_ISS + 59);
   }
   else if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "G")
   {
      visasms::segREF_DATA_ISS* pREF_DATA_ISS;
      pREF_DATA_ISS = (struct visasms::segREF_DATA_ISS*)m_szREF_DATA_ISS;
      mastercardipmmessageprocessor::hADL_RESP_DATA* pADL_RESP_DATA;
      pADL_RESP_DATA = (struct mastercardipmmessageprocessor::hADL_RESP_DATA*)m_szADL_RESP_DATA;
      if (memcmp(pREF_DATA_ISS->sValidationCode, "    ", sizeof(pREF_DATA_ISS->sValidationCode)))
         m_hGenericSegment[0].set("ZVALID_CODE", pREF_DATA_ISS->sValidationCode);
      strValue = pADL_RESP_DATA->cMktSpecificDataId;
      m_hGenericSegment[0].set("ZMKTIND", strValue);
      strValue.assign(pREF_DATA_ISS->sPRODUCT_ID, 2);
      m_hGenericSegment[0].set("ZCRDRES", strValue);
      m_hGenericSegment[0].set("ZCAVVRESULT", m_hGenericSegment[0].get("CAVV_RESULT"));
      strValue.assign(pADL_RESP_DATA->sMerchVerificationValue, 10);
      m_hGenericSegment[0].set("ZMERCH", strValue);
      strValue = pADL_RESP_DATA->cSpendQualifiedIndicator;
      m_hGenericSegment[0].set("ZSSQUALIND", strValue);
   }
   else if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "T")
   {
      visasms::segREF_DATA_ISS* pREF_DATA_ISS;
      pREF_DATA_ISS = (struct visasms::segREF_DATA_ISS*)m_szREF_DATA_ISS;
      visabaseIImessageprocessor::hADL_RESP_DATA* pADL_RESP_DATA;
      pADL_RESP_DATA = (struct visabaseIImessageprocessor::hADL_RESP_DATA*)m_szADL_RESP_DATA;
      visabaseIImessageprocessor::hADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
      pADL_DATA_PRIV_ACQ = (struct visabaseIImessageprocessor::hADL_DATA_PRIV_ACQ*)m_szADL_DATA_PRIV_ACQ;

      if (memcmp(pREF_DATA_ISS->sValidationCode, "    ", sizeof(pREF_DATA_ISS->sValidationCode)))
         m_hGenericSegment[0].set("ZVALID_CODE", pREF_DATA_ISS->sValidationCode);
      strValue = pADL_RESP_DATA->cACIInd;
      m_hGenericSegment[0].set("ZMKTIND", strValue);
      m_hGenericSegment[0].set("ZCAVVRESULT", m_hGenericSegment[0].get("CVV2_CVC2_RESULT"));
      strValue.assign(pADL_DATA_PRIV_ACQ->sElectronicCommerceGoodsInd, 2);
      m_hGenericSegment[0].set("ZECGI", strValue);
   }
   return (m_hGenericSegment[0].get("CRYPTOGRAM_AMOUNT").empty() ? m_pReport->report("PD") : m_pReport->report("DP"));
  //## end report::TC57TransactionFile::write_TCR3_TxnDetail_PaymentServiceData%6268B2160286.body
}

bool TC57TransactionFile::write_TCR4_AmexTxnDetailLocation (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR4_AmexTxnDetailLocation%633EBF2B0204.body preserve=yes
   if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "A")
   {
      m_hActivitySegment[2].reset();
      m_hActivitySegment[2].set("BKEY", 1);
      m_hActivitySegment[2].set("TCR", 1);
      m_hActivitySegment[2].set("TTCR", 1);
      m_hActivitySegment[0] += m_hActivitySegment[2];
      return m_pReport->report("TL");
   }
   return true;
  //## end report::TC57TransactionFile::write_TCR4_AmexTxnDetailLocation%633EBF2B0204.body
}

bool TC57TransactionFile::write_TCR4_TxnDetail_VISA (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR4_TxnDetail_VISA%6261045F024E.body preserve=yes
   m_hActivitySegment[2].reset();
   m_hActivitySegment[2].set("BKEY", 1);
   m_hActivitySegment[2].set("TCR", 1);
   m_hActivitySegment[2].set("TTCR", 1);
   m_hActivitySegment[0] += m_hActivitySegment[2];
   return m_pReport->report("DV");
  //## end report::TC57TransactionFile::write_TCR4_TxnDetail_VISA%6261045F024E.body
}

bool TC57TransactionFile::write_TCR4_VisaSMS (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR4_VisaSMS%67DD9017031C.body preserve=yes
   m_hActivitySegment[2].reset();
   m_hActivitySegment[2].set("BKEY", 1);
   m_hActivitySegment[2].set("TCR", 1);
   m_hActivitySegment[2].set("TTCR", 1);
   m_hActivitySegment[0] += m_hActivitySegment[2];
   return m_pReport->report("VS");
  //## end report::TC57TransactionFile::write_TCR4_VisaSMS%67DD9017031C.body
}

bool TC57TransactionFile::write_TCR5_TxnDetail_MC (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR5_TxnDetail_MC%6261045500ED.body preserve=yes
   m_hActivitySegment[2].reset();
   m_hActivitySegment[2].set("BKEY", 1);
   m_hActivitySegment[2].set("TCR", 1);
   m_hActivitySegment[2].set("TTCR", 1);
   m_hActivitySegment[0] += m_hActivitySegment[2];
   char szTTID[3];
   memset(szTTID, ' ', 3);
   m_hGenericSegment[0].set("ZBSDATE", m_hGenericSegment[0].get("DATE_RECON_NET").substr(4, 4));
   m_hGenericSegment[0].set("ZDIR_SERV_TRAN_ID", m_hGenericSegment[0].get("DIR_SERV_TRAN_ID"));
   if (m_hGenericSegment[0].get("ADL_DATA_PRIV_ACQ").length() >= 186)
      m_hGenericSegment[0].set("ZOCNTRY", m_hGenericSegment[0].get("ADL_DATA_PRIV_ACQ").substr(183, 3));
   if (m_hGenericSegment[0].get("ECOM_DATA").length() >= sizeof(struct mastercardcis::segECOM_DATA))
      m_hGenericSegment[0].set("ZCIMICAT", m_hGenericSegment[0].get("ECOM_DATA").substr(8, 4));
   if (Extract::instance()->getCustomCode() == "COLES")
   {
      if ((m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").length() > 0) && (memcmp(m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").data(), "801", 3)))
         m_hGenericSegment[0].set("ZPPOL_PGM_DATA", "101");
   }
   else
   {
      m_hGenericSegment[0].set("ZECSIND", "000");
      if (m_hGenericSegment[0].get("MCI_ECS_LVL_IND")[0] != ' ')
         m_hGenericSegment[0].set("ZECSIND", m_hGenericSegment[0].get("MCI_ECS_LVL_IND"));
      m_hGenericSegment[0].set("ZPOS_DEVICE_TYPE", "0");
   }
   string strValue1;
   if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "A")
   {
      if (!memcmp(m_szADL_DATA_PRIV_ACQ, "MC", 2))
      {
         mastercardcis::segADL_DATA_PRIV_ACQ_Advantage* pADL_DATA_PRIV_ACQ;
         pADL_DATA_PRIV_ACQ = (struct mastercardcis::segADL_DATA_PRIV_ACQ_Advantage*)m_szADL_DATA_PRIV_ACQ;
         strValue1.assign(pADL_DATA_PRIV_ACQ->sMCAssignedId, sizeof(pADL_DATA_PRIV_ACQ->sMCAssignedId));
         m_hGenericSegment[0].set("ZMCAID", strValue1);
         memcpy(szTTID + 1, pADL_DATA_PRIV_ACQ->sTRANSIT_TRAN_IND, 2);
         m_hGenericSegment[0].set("ZTTID", szTTID);
         strValue1.assign(pADL_DATA_PRIV_ACQ->sTRANSPORT_MODE_IND, sizeof(pADL_DATA_PRIV_ACQ->sTRANSPORT_MODE_IND));
         m_hGenericSegment[0].set("ZTMODIND", strValue1);
         strValue1.assign(pADL_DATA_PRIV_ACQ->sPPOL_PGM_DATA, sizeof(pADL_DATA_PRIV_ACQ->sPPOL_PGM_DATA));
         m_hGenericSegment[0].set("ZPPOL_PGM_DATA", strValue1);
         strValue1.assign(pADL_DATA_PRIV_ACQ->sPAYMENT_FID, sizeof(pADL_DATA_PRIV_ACQ->sPAYMENT_FID));
         m_hGenericSegment[0].set("ZMCPFID", strValue1);
         strValue1.assign(pADL_DATA_PRIV_ACQ->sMERCHANT_ID, sizeof(pADL_DATA_PRIV_ACQ->sMERCHANT_ID));
         m_hGenericSegment[0].set("ZMCSMID", strValue1);
         strValue1.assign(pADL_DATA_PRIV_ACQ->sSALES_ORG_ID, sizeof(pADL_DATA_PRIV_ACQ->sSALES_ORG_ID));
         m_hGenericSegment[0].set("ZINDSID", strValue1);
         strValue1.assign(pADL_DATA_PRIV_ACQ->sTransactionLinkID, sizeof(pADL_DATA_PRIV_ACQ->sTransactionLinkID));
         m_hGenericSegment[0].set("ZTRAN_LINK_ID", strValue1);
      }
      else if (!memcmp(m_szADL_DATA_PRIV_ACQ, "MD", 2))
      {
         mastercardmds::segADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
         pADL_DATA_PRIV_ACQ = (struct mastercardmds::segADL_DATA_PRIV_ACQ*)m_szADL_DATA_PRIV_ACQ;
         mastercardmds::segREF_DATA_ISS* pREF_DATA_ISS;
         pREF_DATA_ISS = (struct mastercardmds::segREF_DATA_ISS*)m_szREF_DATA_ISS;
         strValue1.assign(pADL_DATA_PRIV_ACQ->sMCAssignedId, sizeof(pADL_DATA_PRIV_ACQ->sMCAssignedId));
         m_hGenericSegment[0].set("ZMCAID", strValue1);
         memcpy(szTTID + 1, pADL_DATA_PRIV_ACQ->sTRANSIT_TRAN_IND, 2);
         m_hGenericSegment[0].set("ZTTID", szTTID);
         strValue1.assign(pADL_DATA_PRIV_ACQ->sTRANSPORT_MODE_IND, sizeof(pADL_DATA_PRIV_ACQ->sTRANSPORT_MODE_IND));
         m_hGenericSegment[0].set("ZTMODIND", strValue1);
         strValue1.assign(pADL_DATA_PRIV_ACQ->sPPOL_PGM_DATA, sizeof(pADL_DATA_PRIV_ACQ->sPPOL_PGM_DATA));
         m_hGenericSegment[0].set("ZPPOL_PGM_DATA", strValue1);
         strValue1.assign(pADL_DATA_PRIV_ACQ->sPAYMENT_FID, sizeof(pADL_DATA_PRIV_ACQ->sPAYMENT_FID));
         m_hGenericSegment[0].set("ZMCPFID", strValue1);
         strValue1.assign(pADL_DATA_PRIV_ACQ->sMERCHANT_ID, sizeof(pADL_DATA_PRIV_ACQ->sMERCHANT_ID));
         m_hGenericSegment[0].set("ZMCSMID", strValue1);
         strValue1.assign(pADL_DATA_PRIV_ACQ->sSALES_ORG_ID, sizeof(pADL_DATA_PRIV_ACQ->sSALES_ORG_ID));
         m_hGenericSegment[0].set("ZINDSID", strValue1);
         strValue1.assign(pADL_DATA_PRIV_ACQ->sTransactionLinkID, sizeof(pADL_DATA_PRIV_ACQ->sTransactionLinkID));
         m_hGenericSegment[0].set("ZTRAN_LINK_ID", strValue1);
         strValue1.assign(pREF_DATA_ISS->sSettleDate, sizeof(pREF_DATA_ISS->sSettleDate));
         m_hGenericSegment[0].set("ZBSDATE", strValue1);
         strValue1.assign(pREF_DATA_ISS->sBanknetRef, sizeof(pREF_DATA_ISS->sBanknetRef));
         m_hGenericSegment[0].set("ZBSETNO", strValue1);
      }
      if (m_hGenericSegment[0].get("REF_DATA_ISS_FMT") == "6")
      {
         mastercardcis::segREF_DATA_ISS* pREF_DATA_ISS;
         pREF_DATA_ISS = (struct mastercardcis::segREF_DATA_ISS*)m_szREF_DATA_ISS;
         strValue1.assign(pREF_DATA_ISS->sBanknetDate, sizeof(pREF_DATA_ISS->sBanknetDate));
         m_hGenericSegment[0].set("ZBSDATE", strValue1);
         strValue1.assign(pREF_DATA_ISS->sBanknetRef, sizeof(pREF_DATA_ISS->sBanknetRef));
         m_hGenericSegment[0].set("ZBSETNO", strValue1);
      }
      string strADL_DATA_NATIONAL(m_hGenericSegment[0].get("ADL_DATA_NATIONAL"));
      size_t nPosBegin;
      string strLen, strValue;
      char szADL_DATA_NATIONAL[29];
      memset(szADL_DATA_NATIONAL, ' ', 29);
      nPosBegin = strADL_DATA_NATIONAL.find("\\M9");
      if (nPosBegin != string::npos)
      {
         strLen.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 3, 2);
         strValue.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 5, atoi(strLen.data()));
         memcpy(szADL_DATA_NATIONAL, strValue.data(), strValue.length());
      }
      nPosBegin = strADL_DATA_NATIONAL.find("\\MA");
      if (nPosBegin != string::npos)
      {
         strLen.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 3, 2);
         strValue.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 5, atoi(strLen.data()));
         memcpy(szADL_DATA_NATIONAL + 13, strValue.data(), strValue.length());
      }
      nPosBegin = strADL_DATA_NATIONAL.find("\\MB");
      if (nPosBegin != string::npos)
      {
         strLen.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 3, 2);
         strValue.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 5, atoi(strLen.data()));
         memcpy(szADL_DATA_NATIONAL + 16, strValue.data(), strValue.length());
      }
      nPosBegin = strADL_DATA_NATIONAL.find("\\MC");
      if (nPosBegin != string::npos)
      {
         strLen.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 3, 2);
         strValue.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 5, atoi(strLen.data()));
         memcpy(szADL_DATA_NATIONAL + 19, strValue.data(), strValue.length());
      }
      m_hGenericSegment[0].set("ZADL_NAT_DATA", szADL_DATA_NATIONAL);
      char szGEOLOC[40];
      memset(szGEOLOC, ' ', 40);
      nPosBegin = strADL_DATA_NATIONAL.find("\\MD");
      if (nPosBegin != string::npos)
      {
         strLen.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 3, 2);
         strValue.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 5, atoi(strLen.c_str()));
         memcpy(szGEOLOC, strValue.data(), 20);
      }
      nPosBegin = strADL_DATA_NATIONAL.find("\\ME");
      if (nPosBegin != string::npos)
      {
         strLen.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 3, 2);
         strValue.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 5, atoi(strLen.c_str()));
         memcpy(szGEOLOC + 20, strValue.data(), 20);
      }
      m_hGenericSegment[0].set("ZGEOLOC", szGEOLOC);
      if (m_hGenericSegment[0].get("ZMCAID")[0] == ' ')
         m_hGenericSegment[0].set("ZMCAID", m_hGenericSegment[0].get("{DFA2|"));
   }
   else if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "G")
   {
      mastercardcis::segREF_DATA_ISS* pREF_DATA_ISS;
      pREF_DATA_ISS = (struct mastercardcis::segREF_DATA_ISS*)m_szREF_DATA_ISS;
      mastercardcis::segADL_DATA_PRIV_ISS* pADL_DATA_PRIV_ISS;
      pADL_DATA_PRIV_ISS = (struct mastercardcis::segADL_DATA_PRIV_ISS*)m_szADL_DATA_PRIV_ISS;
      mastercardipmmessageprocessor::hADL_RESP_DATA* pADL_RESP_DATA;
      pADL_RESP_DATA = (struct mastercardipmmessageprocessor::hADL_RESP_DATA*)m_szADL_RESP_DATA;
      mastercardipmmessageprocessor::hEXTENSION_DATA_ADJ* pEXTENSION_DATA_ADJ;
      pEXTENSION_DATA_ADJ = (struct mastercardipmmessageprocessor::hEXTENSION_DATA_ADJ*)m_szEXTENSION_DATA_ADJ;
      memcpy(szTTID + 1, pADL_DATA_PRIV_ISS->sTransitTranTypeInd, 2);
      m_hGenericSegment[0].set("ZTTID", szTTID);
      strValue1.assign(pADL_DATA_PRIV_ISS->sTransportModInd, sizeof(pADL_DATA_PRIV_ISS->sTransportModInd));
      m_hGenericSegment[0].set("ZTMODIND", strValue1);
      strValue1.assign(pADL_RESP_DATA->sWalletProgramData, sizeof(pADL_RESP_DATA->sWalletProgramData));
      m_hGenericSegment[0].set("ZPPOL_PGM_DATA", strValue1);
      strValue1.assign(pEXTENSION_DATA_ADJ->sPayment_Facilitator_ID, sizeof(pEXTENSION_DATA_ADJ->sPayment_Facilitator_ID));
      m_hGenericSegment[0].set("ZMCPFID", strValue1);
      strValue1.assign(pEXTENSION_DATA_ADJ->sSub_Merchant_ID, sizeof(pEXTENSION_DATA_ADJ->sSub_Merchant_ID));
      m_hGenericSegment[0].set("ZMCSMID", strValue1);
      strValue1.assign(pEXTENSION_DATA_ADJ->sIndependent_Sales_Org_ID, sizeof(pEXTENSION_DATA_ADJ->sIndependent_Sales_Org_ID));
      m_hGenericSegment[0].set("ZINDSID", strValue1);
      strValue1.assign(pREF_DATA_ISS->sBanknetDate, sizeof(pREF_DATA_ISS->sBanknetDate));
      m_hGenericSegment[0].set("ZBSDATE", strValue1);
      strValue1.assign(pREF_DATA_ISS->sBanknetRef, sizeof(pREF_DATA_ISS->sBanknetRef));
      m_hGenericSegment[0].set("ZBSETNO", strValue1);
      strValue1.assign(pADL_RESP_DATA->sPaymentTranTypeInd, sizeof(pADL_RESP_DATA->sPaymentTranTypeInd));
      m_hGenericSegment[0].set("ZPRIND", strValue1);
      strValue1.assign(pADL_DATA_PRIV_ISS->sMerchCountryOrigin, sizeof(pADL_DATA_PRIV_ISS->sMerchCountryOrigin));
      m_hGenericSegment[0].set("ZOCNTRY", strValue1);
      strValue1.assign(pADL_RESP_DATA->sDirectoryServerTranId, sizeof(pADL_RESP_DATA->sDirectoryServerTranId));
      m_hGenericSegment[0].set("ZDIR_SERV_TRAN_ID", strValue1);
      strValue1 = pADL_RESP_DATA->cProgramProtocol;
      m_hGenericSegment[0].set("ZPROGRAM_PROTOCOL", strValue1);
      strValue1.assign(pADL_RESP_DATA->sPromotionCode, 6);
      m_hGenericSegment[0].set("ZPROMO_CODE", strValue1);
   }
   else if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "T")
   {
      mastercardcis::segREF_DATA_ISS* pREF_DATA_ISS;
      pREF_DATA_ISS = (struct mastercardcis::segREF_DATA_ISS*)m_szREF_DATA_ISS;
      mastercardmds::segADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
      pADL_DATA_PRIV_ACQ = (struct mastercardmds::segADL_DATA_PRIV_ACQ*)m_szADL_DATA_PRIV_ACQ;
      visabaseIImessageprocessor::hDATA_PRIV_ACQ* pDATA_PRIV_ACQ;
      pDATA_PRIV_ACQ = (struct visabaseIImessageprocessor::hDATA_PRIV_ACQ*)m_szDATA_PRIV_ACQ;
      szTTID[0] = pADL_DATA_PRIV_ACQ->cREMOTE_PGM_IND;
      memcpy(szTTID + 1, pADL_DATA_PRIV_ACQ->sTRANSIT_TRAN_IND, 2);
      m_hGenericSegment[0].set("ZTTID", szTTID);
      strValue1.assign(pADL_DATA_PRIV_ACQ->sMCAssignedId, sizeof(pADL_DATA_PRIV_ACQ->sMCAssignedId));
      m_hGenericSegment[0].set("ZMCAID", strValue1);
      strValue1.assign(pADL_DATA_PRIV_ACQ->sTRANSPORT_MODE_IND, sizeof(pADL_DATA_PRIV_ACQ->sTRANSPORT_MODE_IND));
      m_hGenericSegment[0].set("ZTMODIND", strValue1);
      m_hGenericSegment[0].set("ZPPOL_PGM_DATA", m_hGenericSegment[0].get("WLT_ID"));
      strValue1.assign(pADL_DATA_PRIV_ACQ->sPAYMENT_FID, sizeof(pADL_DATA_PRIV_ACQ->sPAYMENT_FID));
      m_hGenericSegment[0].set("ZMCPFID", strValue1);
      strValue1.assign(pADL_DATA_PRIV_ACQ->sMERCHANT_ID, sizeof(pADL_DATA_PRIV_ACQ->sMERCHANT_ID));
      m_hGenericSegment[0].set("ZMCSMID", strValue1);
      strValue1.assign(pADL_DATA_PRIV_ACQ->sMERCHANT_ID, sizeof(pADL_DATA_PRIV_ACQ->sMERCHANT_ID));
      m_hGenericSegment[0].set("ZINDSID", strValue1);
      strValue1.assign(pREF_DATA_ISS->sBanknetDate, sizeof(pREF_DATA_ISS->sBanknetDate));
      m_hGenericSegment[0].set("ZBSDATE", strValue1);
      strValue1.assign(pREF_DATA_ISS->sBanknetRef, sizeof(pREF_DATA_ISS->sBanknetRef));
      m_hGenericSegment[0].set("ZBSETNO", strValue1);
      strValue1.assign(pADL_DATA_PRIV_ACQ->sTransactionLinkID, sizeof(pADL_DATA_PRIV_ACQ->sTransactionLinkID));
      m_hGenericSegment[0].set("ZTRAN_LINK_ID", strValue1);
   }
   m_hGenericSegment[0].set("WLT_ID", m_hGenericSegment[0].get("ZPPOL_PGM_DATA"));
   m_hGenericSegment[0].set("ZTTID", szTTID);
   return m_pReport->report("DM");
  //## end report::TC57TransactionFile::write_TCR5_TxnDetail_MC%6261045500ED.body
}

bool TC57TransactionFile::write_TCR7_Chip_All (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR7_Chip_All%65F156F1006E.body preserve=yes
   if (m_hGenericSegment[0].get("APPL_INTRCHG_PROF").empty() == false
      || m_hGenericSegment[0].get("APPL_TRAN_COUNTER").empty() == false
      || m_hGenericSegment[0].get("APPL_CRYPTOGRAM").empty() == false
      || m_hGenericSegment[0].get("CRYPT_INFO_DATA").empty() == false
      || m_hGenericSegment[0].get("TERM_COUNTRY_CODE").empty() == false
      || m_hGenericSegment[0].get("TERM_CAPABILITIES").empty() == false
      || m_hGenericSegment[0].get("TERMINAL_TYPE").empty() == false
      || m_hGenericSegment[0].get("TERM_VERIFY_RESULT").empty() == false
      || m_hGenericSegment[0].get("TRAN_DATE").empty() == false
      || m_hGenericSegment[0].get("TRAN_TYPE").empty() == false
      || m_hGenericSegment[0].get("TRAN_CURRENCY_CODE").empty() == false
      || m_hGenericSegment[0].get("AMOUNT_OTHER").empty() == false
      || m_hGenericSegment[0].get("ISS_APPL_DATA").empty() == false
      || m_hGenericSegment[0].get("UNPREDICTABLE_NO").empty() == false
      || m_hGenericSegment[0].get("CARDH_VER_RESULT").empty() == false
      || m_hGenericSegment[0].get("DEDICATED_FILE_NAM").empty() == false
      || m_hGenericSegment[0].get("APPL_VERSION_NO").empty() == false
      || m_hGenericSegment[0].get("TERM_SERIAL_NO").empty() == false
      || m_hGenericSegment[0].get("TRAN_SEQ_COUNTER").empty() == false
      || m_hGenericSegment[0].get("TRAN_CATEGORY_CODE").empty() == false
      || m_hGenericSegment[0].get("ISS_AUTH_DATA").empty() == false
      || m_hGenericSegment[0].get("CRYPTOGRAM_AMOUNT").empty() == false
      || m_hGenericSegment[0].get("ISS_SCRIPT_RESULT").empty() == false
      || m_hGenericSegment[0].get("FORM_FACTOR_IND").empty() == false
      || m_hGenericSegment[0].get("APPL_ID").empty() == false)
   {
      m_hActivitySegment[2].reset();
      m_hActivitySegment[2].set("BKEY", 1);
      m_hActivitySegment[2].set("TCR", 1);
      m_hActivitySegment[2].set("TTCR", 1);
      m_hActivitySegment[0] += m_hActivitySegment[2];
      return m_pReport->report("CA");
   }
   return false;
  //## end report::TC57TransactionFile::write_TCR7_Chip_All%65F156F1006E.body
}

bool TC57TransactionFile::write_TCR90_FileHeader (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR90_FileHeader%626103A70158.body preserve=yes
   m_hActivitySegment[2].reset();
   m_hActivitySegment[2].set("TTCR", 1);
   m_hActivitySegment[2].set("TTCNT", 1);
   m_hActivitySegment[0] += m_hActivitySegment[2];
   m_hGenericSegment[0].set("PBIN", Extract::instance()->getCustomCode());
   Date hDate(m_hGenericSegment[0].get("DATE_RECON_NET").data());
   m_hActivitySegment[1].set("JDATE", hDate.asString("%y%j"));
   return m_pReport->report("FH");
  //## end report::TC57TransactionFile::write_TCR90_FileHeader%626103A70158.body
}

bool TC57TransactionFile::write_TCR91_BatchTrailer (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR91_BatchTrailer%6261041B03A7.body preserve=yes
   m_hActivitySegment[2].reset();
   m_hActivitySegment[2].set("TCR", 1);
   m_hActivitySegment[2].set("TTCR", 1);
   m_hActivitySegment[2].set("TTCNT", 1);
   m_hActivitySegment[0] += m_hActivitySegment[2];
   m_hActivitySegment[1] += m_hActivitySegment[0];
   m_pReport->report("T1");
   m_hActivitySegment[0].reset();
   m_dBatchNetAmt = 0;
   m_dBatchGrossAmt = 0;
   m_strBatchToValue.erase();
   return true;
  //## end report::TC57TransactionFile::write_TCR91_BatchTrailer%6261041B03A7.body
}

bool TC57TransactionFile::write_TCR92_FileTrailer (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR92_FileTrailer%6261042801AE.body preserve=yes
   m_hGenericSegment[0].set("TNETAMT", m_dTotNetAmt);
   m_pReport->report("T2");
   m_hActivitySegment[1].reset();
   m_dTotNetAmt = 0;
   return true;
  //## end report::TC57TransactionFile::write_TCR92_FileTrailer%6261042801AE.body
}

bool TC57TransactionFile::write_TCR99_Coles (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR99_Coles%62610406021F.body preserve=yes
   m_hActivitySegment[2].reset();
   m_hActivitySegment[2].set("BKEY", 1);
   m_hActivitySegment[2].set("TCR", 1);
   m_hActivitySegment[2].set("TTCR", 1);
   m_hActivitySegment[0] += m_hActivitySegment[2];
   if (m_hGenericSegment[0].get("TRAN_STATE") == "100")
      m_hGenericSegment[0].set("ZRESPCODE", "Z9");
   else if (m_hGenericSegment[0].get("ACT_CODE") == "400" || m_hGenericSegment[0].get("ACT_CODE").substr(0, 2) == "00")
      m_hGenericSegment[0].set("ZRESPCODE", "00");
   else
      m_hGenericSegment[0].set("ZRESPCODE", m_hGenericSegment[0].get("EXT_RSP_CODE"));
   string strToValue;
   if (m_hGenericSegment[0].get("{MP_WALLET|").length() > 0)
      getGenericValue("TC57_WALLET_IND", m_hGenericSegment[0].get("{MP_WALLET|"), strToValue);
   else
      getGenericValue("TC57_WALLET_IND", m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID"), strToValue);
   m_hGenericSegment[0].set("ZWALLET_IND", strToValue);
   if (m_hGenericSegment[0].get("{EFC|").length() > 0)
   {
      string strISFCCode(m_hGenericSegment[0].get("{EFC|").substr(0, 8));
      strISFCCode.append(m_hGenericSegment[0].get("TRAN_TYPE_ID").substr(0, 2));
      strISFCCode.append("0");
      strISFCCode.append(m_hGenericSegment[0].get("TRAN_DISPOSITION"));
      m_hGenericSegment[0].set("ZIFSC", strISFCCode);
   }
   return m_pReport->report("CO");
  //## end report::TC57TransactionFile::write_TCR99_Coles%62610406021F.body
}

bool TC57TransactionFile::write_TCR99_CustomRecord (IF::FlatFile& hFlatFile)
{
  //## begin report::TC57TransactionFile::write_TCR99_CustomRecord%62EBCD260058.body preserve=yes
   m_hActivitySegment[2].reset();
   m_hActivitySegment[2].set("BKEY", 1);
   m_hActivitySegment[2].set("TCR", 1);
   m_hActivitySegment[2].set("TTCR", 1);
   m_hActivitySegment[0] += m_hActivitySegment[2];
   string strValue;
   m_hGenericSegment[0].set("ZCRACT_CODE", m_hGenericSegment[0].get("ACT_CODE"));
   if (m_hGenericSegment[0].get("ACT_CODE") == "400"
      || (m_hGenericSegment[0].get("ACT_CODE") > "000"
         && m_hGenericSegment[0].get("ACT_CODE") < "100"))
      m_hGenericSegment[0].set("ZCRACT_CODE", "000");
   m_hGenericSegment[0].set("ZINDINFO", "00");
   if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "A")
   {
      strValue.assign("X", 1);
      if (m_hGenericSegment[0].get("POS_CRDHLDR_A_METH") == "7"
         || m_hGenericSegment[0].get("POS_CRDHLDR_A_METH") == "8")
         strValue.assign("0", 1);
      else if (m_hGenericSegment[0].get("POS_CRDHLDR_A_METH") == "6"
         || m_hGenericSegment[0].get("POS_CRDHLDR_A_METH") == "9")
         strValue.assign("3", 1);
      if (!m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").empty()
         && strValue == "0")
         strValue.assign("4", 1);
      else if (!m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").empty()
         && strValue == "3")
         strValue.assign("5", 1);
      if (m_hGenericSegment[0].get("{DFA9|") == "01")
         strValue.assign("2", 1);
      m_hGenericSegment[0].set("ZCHARGE_TYPE", strValue);
      if (!m_hGenericSegment[0].get("{DFA9|").empty())
         m_hGenericSegment[0].set("ZINDINFO", m_hGenericSegment[0].get("{DFA9|"));
      else
         m_hGenericSegment[0].set("ZINDINFO", "00");
   }
   size_t pos = m_hGenericSegment[0].get("ADL_DATA_NATIONAL").find("\\M3");
   if (pos != string::npos)
   {
      int iLen = atoi(m_hGenericSegment[0].get("ADL_DATA_NATIONAL").substr(pos + 3, 2).data());
      if (iLen && m_hGenericSegment[0].get("ADL_DATA_NATIONAL").length() >= (pos + 5 + iLen))
         m_hGenericSegment[0].set("ZMERCH_URL", m_hGenericSegment[0].get("ADL_DATA_NATIONAL").substr(pos + 5, iLen));
   }
   return m_pReport->report("CR");
  //## end report::TC57TransactionFile::write_TCR99_CustomRecord%62EBCD260058.body
}

bool TC57TransactionFile::writeUnMatchedAuth ()
{
  //## begin report::TC57TransactionFile::writeUnMatchedAuth%67DD91390009.body preserve=yes
   if (m_pUnMatchFile == 0)
   {
      string strTmp;
      int i = 30;
      if (Extract::instance()->getRecord("DSPEC   RX71    AGEAUTH~", strTmp))
      {
         strTmp.erase(0, 24);
         strTmp.trim();
         i = atoi(strTmp.c_str());
      }
      if (i == 0)
         return true;
      Date hDate(getDATE_RECON().c_str());
      hDate += 1;
      string strDate = hDate.asString("%Y%m%d");
      m_pUnMatchFile = new ExportFile("UMAUTH", getENTITY_TYPE(), getENTITY_ID(), strDate, "240000");
      hDate -= (i + 1);
      m_strMinAuth = hDate.asString("%Y%m%d");
      m_strMinAuth.append("00000000");
   }
   if (memcmp(m_strAuthBuffer.data() + m_iField[TSTAMP_TRANS][OFFSET], m_strMinAuth.data(), 16) > 0 && m_strAuthBuffer.length() >= m_iField[TSTAMP_TRANS][OFFSET] + 16)
   {
      m_pUnMatchFile->setALT_REC_KEY(m_strAuthAltRecKey);
      m_pUnMatchFile->write(m_strAuthBuffer.c_str(), m_strAuthBuffer.length(), ++m_iSeqNo);
   }
   return true;
  //## end report::TC57TransactionFile::writeUnMatchedAuth%67DD91390009.body
}

// Additional Declarations
  //## begin report::TC57TransactionFile%6260E53402B5.declarations preserve=yes
bool TC57TransactionFile::write_TCR1_TxnDetail_UPI(IF::FlatFile& hFlatFile)
{
   m_hActivitySegment[2].reset();
   m_hActivitySegment[2].set("BKEY", 1);
   m_hActivitySegment[2].set("TCR", 1);
   m_hActivitySegment[2].set("TTCR", 1);
   m_hGenericSegment[0].set("ZTRANIM", "0");
   string strToValue;
   getGenericValue("TC57_OPER_ENV", m_hGenericSegment[0].get("POS_OPER_ENV"), strToValue);
   if (!strToValue.empty())
      m_hGenericSegment[0].set("ZTRANIM", strToValue.substr(0,1));
   else if (m_hGenericSegment[0].get("TERM_CLASS") == "02")
      m_hGenericSegment[0].set("ZTRANIM", "2");
   else {
      getGenericValue("TC57_UPI_CH_PT", m_hGenericSegment[0].get("POS_CRDHLDR_PRESNT"), strToValue);
      if (!strToValue.empty())
         m_hGenericSegment[0].set("ZTRANIM", strToValue.substr(0,1));
   }
   return m_pReport->report("UT");
}

void TC57TransactionFile::setNetworkTransportChannel(string& strValue)
{
   if (m_pGenericSegment->get("ACQ_PLAT_PROD_ID") == "A")
   {
      getGenericValue("TC57_TP_CHANNEL", m_pGenericSegment->get("TERM_CLASS") + m_pGenericSegment->get("POS_OPER_ENV"), strValue);
      if (strValue.empty())
         strValue.assign("00");
   }
}
  //## end report::TC57TransactionFile%6260E53402B5.declarations

} // namespace report

//## begin module%6809B6A00083.epilog preserve=yes
//## end module%6809B6A00083.epilog
