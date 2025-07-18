//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%62610BE60007.cm preserve=no
//## end module%62610BE60007.cm

//## begin module%62610BE60007.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%62610BE60007.cp

//## Module: CXOSRX28%62610BE60007; Package body
//## Subsystem: RXDLL%5C47391001FD
//## Source file: C:\Repos\datanavigatorserver\Windows\Build\Dn\Server\Library\Rxdll\CXOSRX28.cpp

//## begin module%62610BE60007.additionalIncludes preserve=no
//## end module%62610BE60007.additionalIncludes

//## begin module%62610BE60007.includes preserve=yes
#include "CXODDB02.hpp"
#include "CXODRU12.hpp"
#include "CXODDB49.hpp"
//## end module%62610BE60007.includes

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
#ifndef CXOSRX28_h
#include "CXODRX28.hpp"
#endif


//## begin module%62610BE60007.declarations preserve=no
//## end module%62610BE60007.declarations

//## begin module%62610BE60007.additionalDeclarations preserve=yes
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

namespace
{
   database::ExportFile* createISTTC57TransactionFile()
   {
      return new report::ISTTC57TransactionFile();
   }
   const bool registered = database::ReportFactory::instance()->registerReport("ISTTC57TransactionFile", createISTTC57TransactionFile);
}
//## end module%62610BE60007.additionalDeclarations


//## Modelname: Data Distribution::Report_CAT%5C473883000E
namespace report {
//## begin report%5C473883000E.initialDeclarations preserve=yes
//## end report%5C473883000E.initialDeclarations

// Class report::ISTTC57TransactionFile 

ISTTC57TransactionFile::ISTTC57TransactionFile()
  //## begin ISTTC57TransactionFile::ISTTC57TransactionFile%6809C3C000B8_const.hasinit preserve=no
      : m_iBatchNo(0),
        m_siIntrMerchBatchKey(0),
        m_siBatchTxnCount(0),
        m_dBatchNetAmt(0),
        m_dBatchGrossAmt(0),
        m_iNoOfTcrs(0),
        m_iTotNoOfTcrs(0),
        m_iTotNoOfTxns(0),
        m_dTotNetAmt(0),
        m_bVariableBlockFile(false),
        m_iFilmLocator(0),
        m_pContext(0)
  //## end ISTTC57TransactionFile::ISTTC57TransactionFile%6809C3C000B8_const.hasinit
  //## begin ISTTC57TransactionFile::ISTTC57TransactionFile%6809C3C000B8_const.initialization preserve=yes
   , m_bAdvRevTran(false)
   , m_bPrevAuth(false)
   , m_iSeqNo(100)
   , m_pUnMatchFile(0)
   , m_iFieldMaxLen(0)
   , m_bDF09Presence(false)
  //## end ISTTC57TransactionFile::ISTTC57TransactionFile%6809C3C000B8_const.initialization
{
  //## begin report::ISTTC57TransactionFile::ISTTC57TransactionFile%6809C3C000B8_const.body preserve=yes
   memcpy(m_sID, "RX28", 4);
   setDX_FILE_TYPE("TC57");
   memset(m_szSpaces, ' ', sizeof(m_szSpaces) - 1);
   std::fill(&m_iField[0][0], &m_iField[0][0] + (sizeof(m_iField) / sizeof(m_iField[0][0])), 0);
   m_pContext = new Context(Application::instance()->image(), Application::instance()->name());
#ifdef MVS
   string strValue;
   Extract::instance()->getSpec("RX28", "VB", strValue);
   transform(strValue.begin(), strValue.end(), strValue.begin(), ::toupper);
   m_bVariableBlockFile = (strValue == "YES" || strValue == "Y" ? true : false);
#endif
  //## end report::ISTTC57TransactionFile::ISTTC57TransactionFile%6809C3C000B8_const.body
}


ISTTC57TransactionFile::~ISTTC57TransactionFile()
{
  //## begin report::ISTTC57TransactionFile::~ISTTC57TransactionFile%6809C3C000B8_dest.body preserve=yes
   delete m_pUnMatchFile;
   delete m_pContext;
  //## end report::ISTTC57TransactionFile::~ISTTC57TransactionFile%6809C3C000B8_dest.body
}



//## Other Operations (implementation)
bool ISTTC57TransactionFile::distribute (string& strDATA_BUFFER, IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::distribute%6809C3C000C6.body preserve=yes
   UseCase hUseCase("DIST", "## RX28 WRITE ISTTC57");
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
   Date hDate(m_hGenericSegment[0].get("DATE_RECON_NET").data());
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
      if (Extract::instance()->getCustomCode() != "COLES")
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
   return UseCase::setSuccess(true);
  //## end report::ISTTC57TransactionFile::distribute%6809C3C000C6.body
}

bool ISTTC57TransactionFile::finish (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::finish%6809C3C000C9.body preserve=yes
   char szTemp[PERCENTD];
   snprintf(szTemp, sizeof(szTemp), "%d", m_iFilmLocator);
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
   return ExportFile::finish(hFlatFile);
  //## end report::ISTTC57TransactionFile::finish%6809C3C000C9.body
}

bool ISTTC57TransactionFile::initialize ()
{
  //## begin report::ISTTC57TransactionFile::initialize%6809C3C000CB.body preserve=yes
   return true;
  //## end report::ISTTC57TransactionFile::initialize%6809C3C000CB.body
}

void ISTTC57TransactionFile::setOrderByClause (reusable::Query& hQuery)
{
  //## begin report::ISTTC57TransactionFile::setOrderByClause%6809C3C000CC.body preserve=yes
   ReportFile::setOrderByClause(hQuery, "RPT_LVL_ID_B,NET_TERM_ID,PAN,RETRIEVAL_REF_NO,APPROVAL_CODE,MTI");
  //## end report::ISTTC57TransactionFile::setOrderByClause%6809C3C000CC.body
}

bool ISTTC57TransactionFile::write_TCR90_FileHeader (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR90_FileHeader%6809C3C000CE.body preserve=yes
   Date hDate(m_hGenericSegment[0].get("DATE_RECON_NET").data());
   m_iTotNoOfTcrs++;
   m_iTotNoOfTxns++;
   struct hTCR90_FileHeader* pTCR90_FileHeader = (struct hTCR90_FileHeader*)getDATA_BUFFER();
   memset(pTCR90_FileHeader, ' ', sizeof(hTCR90_FileHeader));
   memcpy(pTCR90_FileHeader->sTransCode, "90", sizeof(pTCR90_FileHeader->sTransCode));
   memcpy(pTCR90_FileHeader->sProcessingBIN, Extract::instance()->getCustomCode().data(), min(sizeof(pTCR90_FileHeader->sProcessingBIN), Extract::instance()->getCustomCode().length()));
   memcpy(pTCR90_FileHeader->sProcessingDate, hDate.asString("%y%j").data(), sizeof(pTCR90_FileHeader->sProcessingDate));
   memcpy(pTCR90_FileHeader->sTestOption, "TEST", sizeof(pTCR90_FileHeader->sTestOption));
   memcpy(pTCR90_FileHeader->sSecurityCode, "SECURITY", sizeof(pTCR90_FileHeader->sSecurityCode));
   memset(pTCR90_FileHeader->sOutGoingFileID, '0', sizeof(pTCR90_FileHeader->sOutGoingFileID));
   return (write(sizeof(hTCR90_FileHeader), hFlatFile));
  //## end report::ISTTC57TransactionFile::write_TCR90_FileHeader%6809C3C000CE.body
}

bool ISTTC57TransactionFile::write_TCR0_BatchHeader (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR0_BatchHeader%6809C3C000D0.body preserve=yes
   Date hDate(m_hGenericSegment[0].get("DATE_RECON_NET").data());
   char szTemp[PERCENTD + PERCENTHD];
   m_iNoOfTcrs++;
   m_iTotNoOfTcrs++;
   m_iTotNoOfTxns++;
   m_iBatchNo++;

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
   struct hTC57_TCR0_BatchHeader* pTC57_TCR0_BatchHeader = (struct hTC57_TCR0_BatchHeader*)getDATA_BUFFER();
   memset(pTC57_TCR0_BatchHeader, ' ', sizeof(hTC57_TCR0_BatchHeader));
   memcpy(pTC57_TCR0_BatchHeader->sTransCode, "57", sizeof(pTC57_TCR0_BatchHeader->sTransCode));
   pTC57_TCR0_BatchHeader->cTransCodeQualifier = '0';
   pTC57_TCR0_BatchHeader->cTransComponentSeqNumber = '0';
   memcpy(pTC57_TCR0_BatchHeader->sDestBIN, m_strBatchToValue.data(), m_strBatchToValue.length());
   memcpy(pTC57_TCR0_BatchHeader->sSourceBIN, m_strBatchToValue.data(), m_strBatchToValue.length());
   memset(pTC57_TCR0_BatchHeader->sTransactionAmt, '0', sizeof(pTC57_TCR0_BatchHeader->sTransactionAmt));
   if (Extract::instance()->getCustomCode() == "COLES")
   {
      Date hDateAction(m_hGenericSegment[0].get("DATE_ACTION").c_str());
      memcpy(pTC57_TCR0_BatchHeader->sCentralProcDate, hDateAction.asString("%y%j").data() + 1, sizeof(pTC57_TCR0_BatchHeader->sCentralProcDate));
   }
   else
      memcpy(pTC57_TCR0_BatchHeader->sCentralProcDate, hDate.asString("%y%j").data() + 1, sizeof(pTC57_TCR0_BatchHeader->sCentralProcDate));
   memcpy(pTC57_TCR0_BatchHeader->sRcdFormatCode, "DC", sizeof(pTC57_TCR0_BatchHeader->sRcdFormatCode));
   memcpy(pTC57_TCR0_BatchHeader->sIssInst, m_strBatchToValue.data(), m_strBatchToValue.length());
   memcpy(pTC57_TCR0_BatchHeader->sDataCapProcDate, hDate.asString("%y%j").data() + 1, sizeof(pTC57_TCR0_BatchHeader->sDataCapProcDate));
   memset(pTC57_TCR0_BatchHeader->sAgent, '0', sizeof(pTC57_TCR0_BatchHeader->sAgent));
   memset(pTC57_TCR0_BatchHeader->sChain, '0', sizeof(pTC57_TCR0_BatchHeader->sChain));
   memcpy(pTC57_TCR0_BatchHeader->sMerchNo, strMerchNo.data(), strMerchNo.length());
   memcpy(pTC57_TCR0_BatchHeader->sTerminalNo, strTerminalNo.data(), strTerminalNo.length());
   if (Extract::instance()->getCustomCode() == "COLES" && !m_hGenericSegment[0].get("{InSrcNode|").empty())
      memcpy(pTC57_TCR0_BatchHeader->sTerminalNo, m_hGenericSegment[0].get("CARD_ACPT_TERM_ID").data(), m_hGenericSegment[0].get("CARD_ACPT_TERM_ID").length());
   snprintf(szTemp, sizeof(szTemp), "%05d", m_iBatchNo);
   memcpy(pTC57_TCR0_BatchHeader->sMerchBatchNo, szTemp, sizeof(pTC57_TCR0_BatchHeader->sMerchBatchNo));
   memcpy(pTC57_TCR0_BatchHeader->sMerchBatchDate, hDate.asString("%y%j").data() + 1, sizeof(pTC57_TCR0_BatchHeader->sMerchBatchDate));
   memcpy(pTC57_TCR0_BatchHeader->sBatchTransmitTime, Clock::instance()->getYYYYMMDDHHMMSS(1).data() + 8, sizeof(pTC57_TCR0_BatchHeader->sBatchTransmitTime));
   memcpy(pTC57_TCR0_BatchHeader->sTimeZone, "GMT", sizeof(pTC57_TCR0_BatchHeader->sTimeZone));
   snprintf(szTemp, sizeof(szTemp), " %02d", (int)Clock::instance()->getGMTOffset());
   memcpy(pTC57_TCR0_BatchHeader->sGMTOffset, szTemp, sizeof(pTC57_TCR0_BatchHeader->sGMTOffset));
   m_siIntrMerchBatchKey++;
   snprintf(szTemp, sizeof(szTemp), "%08d%05hd", m_iBatchNo, m_siIntrMerchBatchKey);
   memcpy(pTC57_TCR0_BatchHeader->sInternalMerchBatchKey, szTemp, sizeof(pTC57_TCR0_BatchHeader->sInternalMerchBatchKey));
   pTC57_TCR0_BatchHeader->cRecordType = '1';
   return (write(sizeof(hTC57_TCR0_BatchHeader), hFlatFile));
  //## end report::ISTTC57TransactionFile::write_TCR0_BatchHeader%6809C3C000D0.body
}

bool ISTTC57TransactionFile::write_TCR1_BatchHeader (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR1_BatchHeader%6809C3C000D2.body preserve=yes
   char szTemp[PERCENTD + PERCENTHD];
   m_iNoOfTcrs++;
   m_iTotNoOfTcrs++;
   m_iTotNoOfTxns++;
   struct hTC57_TCR1_BatchHeader* pTC57_TCR1_BatchHeader = (struct hTC57_TCR1_BatchHeader*)getDATA_BUFFER();
   memset(pTC57_TCR1_BatchHeader, ' ', sizeof(hTC57_TCR1_BatchHeader));
   memcpy(pTC57_TCR1_BatchHeader->sTransCode, "57", sizeof(pTC57_TCR1_BatchHeader->sTransCode));
   pTC57_TCR1_BatchHeader->cTransCodeQualifier = '0';
   pTC57_TCR1_BatchHeader->cTransComponentSeqNumber = '1';
   pTC57_TCR1_BatchHeader->cDeviceCode = 'K';
   memcpy(pTC57_TCR1_BatchHeader->sMerchCategoryCode, m_hGenericSegment[0].get("MERCH_TYPE").data(), m_hGenericSegment[0].get("MERCH_TYPE").length());
   if (!m_hGenericSegment[0].get("CARD_ACPT_NAME_LOC").empty())
   {
      memcpy(pTC57_TCR1_BatchHeader->sMerchName, m_hGenericSegment[0].get("CARD_ACPT_NAME_LOC").data(), min(sizeof(pTC57_TCR1_BatchHeader->sMerchName), m_hGenericSegment[0].get("CARD_ACPT_NAME_LOC").length()));
      if (m_hGenericSegment[0].get("CARD_ACPT_NAME_LOC").length() > 55)
      {
         string strMerchantCity(m_hGenericSegment[0].get("CARD_ACPT_NAME_LOC").data() + 55, min(size_t(13), m_hGenericSegment[0].get("CARD_ACPT_NAME_LOC").length() - 55));
         trim(strMerchantCity);
         memcpy(pTC57_TCR1_BatchHeader->sMerchCity, strMerchantCity.data(), strMerchantCity.length());
      }
   }
   memcpy(pTC57_TCR1_BatchHeader->sMerchStateCode, m_hGenericSegment[0].get("CARD_ACPT_REGION").data(), m_hGenericSegment[0].get("CARD_ACPT_REGION").length());
   memcpy(pTC57_TCR1_BatchHeader->sMerchCountryCode, m_hGenericSegment[0].get("CARD_ACPT_COUNTRY").data(), m_hGenericSegment[0].get("CARD_ACPT_COUNTRY").length());
   if (!m_hGenericSegment[0].get("CARD_ACPT_PST_CODE").empty())
      memcpy(pTC57_TCR1_BatchHeader->sMerchZipCode, m_hGenericSegment[0].get("CARD_ACPT_PST_CODE").data(), min(size_t(5), m_hGenericSegment[0].get("CARD_ACPT_PST_CODE").length()));
   memcpy(pTC57_TCR1_BatchHeader->sMerchPostalCode, m_hGenericSegment[0].get("CARD_ACPT_PST_CODE").data(), m_hGenericSegment[0].get("CARD_ACPT_PST_CODE").length());
   memcpy(pTC57_TCR1_BatchHeader->sMerchantCntrySubCode, m_hGenericSegment[0].get("CARD_ACPT_REGION").data(), m_hGenericSegment[0].get("CARD_ACPT_REGION").length());
   memcpy(pTC57_TCR1_BatchHeader->sMerchantStreetAddress, m_hGenericSegment[0].get("SEG24_528^A1").data(), min(size_t(50),m_hGenericSegment[0].get("SEG24_528^A1").length()));
   pTC57_TCR1_BatchHeader->cTransmissionRoute = 'K';
   m_siIntrMerchBatchKey++;
   snprintf(szTemp, sizeof(szTemp), "%08d%05hd", m_iBatchNo, m_siIntrMerchBatchKey);
   memcpy(pTC57_TCR1_BatchHeader->sInternalMerchBatchKey, szTemp, sizeof(pTC57_TCR1_BatchHeader->sInternalMerchBatchKey));
   pTC57_TCR1_BatchHeader->cRecordType = '1';
   return (write(sizeof(hTC57_TCR1_BatchHeader), hFlatFile));
  //## end report::ISTTC57TransactionFile::write_TCR1_BatchHeader%6809C3C000D2.body
}

bool ISTTC57TransactionFile::write_TCR0_TxnDetail (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR0_TxnDetail%6809C3C000D4.body preserve=yes
   Date hDate(m_hGenericSegment[0].get("DATE_RECON_NET").data());
   char szTemp[PERCENTD + PERCENTHD];
   m_iNoOfTcrs++;
   m_iTotNoOfTcrs++;
   m_iTotNoOfTxns++;
   m_siBatchTxnCount++;
   m_siIntrMerchBatchKey++;
   m_iFilmLocator++;
   //Storing back the Connex Segment1 AmtTran to AMT_TRAN to cater the Connex Transaction loading code
   if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "A"
      && m_hGenericSegment[0].get("ACT_CODE") > "099"
      && atof(m_hGenericSegment[0].get("AMT_TRAN").data()) == 0)
      m_hGenericSegment[0].set("AMT_TRAN", m_hGenericSegment[0].get("AMT_RECON_NET"));

   m_dTotNetAmt += atof(m_hGenericSegment[0].get("AMT_TRAN").data());
   string strToValue;
   struct hTC57_TCR0_TxnDetail* pTC57_TCR0_TxnDetail = (struct hTC57_TCR0_TxnDetail*)getDATA_BUFFER();
   memset(pTC57_TCR0_TxnDetail, ' ', sizeof(hTC57_TCR0_TxnDetail));
   memcpy(pTC57_TCR0_TxnDetail->sTransCode, "57", sizeof(pTC57_TCR0_TxnDetail->sTransCode));
   pTC57_TCR0_TxnDetail->cTransCodeQualifier = '0';
   pTC57_TCR0_TxnDetail->cTransComponentSeqNumber = '0';
   memcpy(pTC57_TCR0_TxnDetail->sDestBIN, m_strBatchToValue.data(), m_strBatchToValue.length());
   memcpy(pTC57_TCR0_TxnDetail->sSourceBIN, m_strBatchToValue.data(), m_strBatchToValue.length());
   memcpy(pTC57_TCR0_TxnDetail->sTransactionAmt, m_hGenericSegment[0].get("AMT_TRAN").data() + 6, sizeof(pTC57_TCR0_TxnDetail->sTransactionAmt));
   memcpy(pTC57_TCR0_TxnDetail->sTransactionCurrCode, m_hGenericSegment[0].get("CUR_RECON_NET").data(), m_hGenericSegment[0].get("CUR_RECON_NET").length());
   if (Extract::instance()->getCustomCode() == "COLES")
   {
      Date hDateAction(m_hGenericSegment[0].get("DATE_ACTION").c_str());
      memcpy(pTC57_TCR0_TxnDetail->sCentralProcDate, hDateAction.asString("%y%j").data() + 1, sizeof(pTC57_TCR0_TxnDetail->sCentralProcDate));
   }
   else
      memcpy(pTC57_TCR0_TxnDetail->sCentralProcDate, hDate.asString("%y%j").data() + 1, sizeof(pTC57_TCR0_TxnDetail->sCentralProcDate));
   memcpy(pTC57_TCR0_TxnDetail->sRcdFormatCode, "DC", sizeof(pTC57_TCR0_TxnDetail->sRcdFormatCode));
   string strMTI(m_hGenericSegment[0].get("MTI"));
   if (strMTI.length() > 1 && strMTI[1] == '4')
      pTC57_TCR0_TxnDetail->cReversalFlag = 'R';
   string strPAN = m_hGenericSegment[0].get("PAN");
   KeyRing::instance()->detokenize(strPAN);
   memcpy(pTC57_TCR0_TxnDetail->sAccountNumber, strPAN.data(), strPAN.length());
   memcpy(pTC57_TCR0_TxnDetail->sPurchaseDate, m_hGenericSegment[0].get("TSTAMP_TRANS").data() + 4, sizeof(pTC57_TCR0_TxnDetail->sPurchaseDate));
   memcpy(pTC57_TCR0_TxnDetail->sTransactionTimeHHMM, m_hGenericSegment[0].get("TSTAMP_TRANS").data() + 8, sizeof(pTC57_TCR0_TxnDetail->sTransactionTimeHHMM));
   pTC57_TCR0_TxnDetail->cTransactionVoidInd = '0';
   if (getGenericValue("TC57_ENTRY_METH", m_hGenericSegment[0].get("POS_CRD_DAT_IN_CAP"), strToValue))
      pTC57_TCR0_TxnDetail->cCardEntryMethod = strToValue[0];
   else
      pTC57_TCR0_TxnDetail->cCardEntryMethod = m_hGenericSegment[0].get("POS_CRD_DAT_IN_CAP")[0];
   if (m_hGenericSegment[0].get("POS_CARD_PRES") == "0")
      pTC57_TCR0_TxnDetail->cCardholderIDMethod = '4';
   else
      pTC57_TCR0_TxnDetail->cCardholderIDMethod = m_hGenericSegment[0].get("POS_CARD_PRES")[0];
   memcpy(pTC57_TCR0_TxnDetail->sAuthorizationCode, m_hGenericSegment[0].get("APPROVAL_CODE").data(), m_hGenericSegment[0].get("APPROVAL_CODE").length());
   memcpy(pTC57_TCR0_TxnDetail->sTipOrCashback, m_hGenericSegment[0].get("ADL_RQST_AMT40").data() + 6, sizeof(pTC57_TCR0_TxnDetail->sTipOrCashback));
   memcpy(pTC57_TCR0_TxnDetail->sDebitTraceAuditNo, m_hGenericSegment[0].get("SYS_TRACE_AUDIT_NO").data(), min(sizeof(pTC57_TCR0_TxnDetail->sDebitTraceAuditNo), m_hGenericSegment[0].get("SYS_TRACE_AUDIT_NO").length()));
   memcpy(pTC57_TCR0_TxnDetail->sDebitTransDate, m_hGenericSegment[0].get("TSTAMP_TRANS").data() + 4, sizeof(pTC57_TCR0_TxnDetail->sDebitTransDate));
   memcpy(pTC57_TCR0_TxnDetail->sDebitTransTime, m_hGenericSegment[0].get("TSTAMP_TRANS").data() + 8, sizeof(pTC57_TCR0_TxnDetail->sDebitTransTime));
   memcpy(pTC57_TCR0_TxnDetail->sRetrievalRefNo, m_hGenericSegment[0].get("RETRIEVAL_REF_NO").data(), m_hGenericSegment[0].get("RETRIEVAL_REF_NO").length());
   string strACCT_TYPE(m_hGenericSegment[0].get("TRAN_TYPE_ID"), 2, 2);
   if (Extract::instance()->getCustomCode() == "CBA" && !memcmp(m_hGenericSegment[0].get("TRAN_TYPE_ID").data(), "20", 2))
      strACCT_TYPE.assign(m_hGenericSegment[0].get("TRAN_TYPE_ID").data() + 4, 2);
   char szAcctType = '0';
   if (strACCT_TYPE == "10")
      szAcctType = '1';
   else if (strACCT_TYPE == "20")
      szAcctType = '2';
   else if (strACCT_TYPE == "30")
      szAcctType = '3';
   pTC57_TCR0_TxnDetail->cAcctType = szAcctType;
   snprintf(szTemp, sizeof(szTemp), "%08d%05hd", m_iBatchNo, m_siIntrMerchBatchKey);
   memcpy(pTC57_TCR0_TxnDetail->sInternalMerchBatchKey, szTemp, sizeof(pTC57_TCR0_TxnDetail->sInternalMerchBatchKey));
   pTC57_TCR0_TxnDetail->cRecordType = '2';
   memcpy(pTC57_TCR0_TxnDetail->sTransMCC, m_hGenericSegment[0].get("MERCH_TYPE").data(), m_hGenericSegment[0].get("MERCH_TYPE").length());
   memcpy(pTC57_TCR0_TxnDetail->sSettlementDate, hDate.asString("%y%j").data(), sizeof(pTC57_TCR0_TxnDetail->sSettlementDate));
   memcpy(pTC57_TCR0_TxnDetail->sCrdHldrBillCurrCode, m_hGenericSegment[0].get("CUR_CARD_BILL").data(), m_hGenericSegment[0].get("CUR_CARD_BILL").length());
   memcpy(pTC57_TCR0_TxnDetail->sTranTimeInSeconds, m_hGenericSegment[0].get("TSTAMP_TRANS").data() + 8, sizeof(pTC57_TCR0_TxnDetail->sTranTimeInSeconds));
   memcpy(pTC57_TCR0_TxnDetail->sExpiryDate, m_hGenericSegment[0].get("DATE_EXP").data(), m_hGenericSegment[0].get("DATE_EXP").length());
   pTC57_TCR0_TxnDetail->cAuthCharInd = 'N';
   if (Extract::instance()->getCustomCode() == "CBA")
   {
      database::UniquenessKey::oatHash((const unsigned char*)m_hGenericSegment[0].get("TSTAMP_TRANS").data(), 14);
      string strPAN = m_hGenericSegment[0].get("PAN");
      KeyRing::instance()->detokenize(strPAN);
      database::UniquenessKey::oatHash((const unsigned char*)strPAN.data(), min(size_t(28), strPAN.length()));
      database::UniquenessKey::oatHash((const unsigned char*)m_hGenericSegment[0].get("RETRIEVAL_REF_NO").data(),
         min(m_hGenericSegment[0].get("RETRIEVAL_REF_NO").length(), size_t(12)));
      database::UniquenessKey::oatHash((const unsigned char*)m_hGenericSegment[0].get("TRAN_TYPE_ID").data(),
         min(m_hGenericSegment[0].get("TRAN_TYPE_ID").length(), size_t(6)));
      snprintf(szTemp, sizeof(szTemp), "%011u", database::UniquenessKey::getOatHash());
      memcpy(pTC57_TCR0_TxnDetail->sFilmLocator, szTemp, sizeof(pTC57_TCR0_TxnDetail->sFilmLocator));
   }
   else
   {
      if (m_iFilmLocator > 999999999)
         m_iFilmLocator = 1;
      snprintf(szTemp, sizeof(szTemp), "%2s%09d", Application::instance()->name().substr(4, 2).c_str(), m_iFilmLocator);
      memcpy(pTC57_TCR0_TxnDetail->sFilmLocator, szTemp, sizeof(pTC57_TCR0_TxnDetail->sFilmLocator));
   }
   m_bAdvRevTran = false;
   if (m_hGenericSegment[0].get("MTI") == "1240" || m_hGenericSegment[0].get("MTI")[1] == '4'
      || m_hGenericSegment[0].get("TRAN_DISPOSITION") == "2")
      m_bAdvRevTran = true;

   string strPROC_ID_ISS_B = m_hGenericSegment[0].get("PROC_ID_ISS_B");
   if (Extract::instance()->getCustomCode() == "CBA")
      getGenericValue("TC57_CARD_TYPE", m_hGenericSegment[0].get("NET_ID_ISS"), strToValue);
   else
      getGenericValue("TC57_CARD_TYPE", strPROC_ID_ISS_B, strToValue);
   pTC57_TCR0_TxnDetail->cCardType = strToValue[0];

   if (Extract::instance()->getCustomCode() == "COLES")
   {
      if (m_hGenericSegment[0].get("INST_ID_RECN_ISS_B") == "VIIAU"
         || m_hGenericSegment[0].get("INST_ID_RECN_ISS_B") == "VIINZ")
         pTC57_TCR0_TxnDetail->cPrepaidCardInd = 'P';

      char szTransactionType = '5';
      string strTRAN_TYPE_ID = m_hGenericSegment[0].get("TRAN_TYPE_ID").substr(0, 2);
      if (strTRAN_TYPE_ID == "20" || strTRAN_TYPE_ID == "18")
         szTransactionType = '6';
      else if (strTRAN_TYPE_ID == "09")
         szTransactionType = '3';
      else if (strTRAN_TYPE_ID == "01")
         szTransactionType = '7';
      pTC57_TCR0_TxnDetail->cTransactionType = szTransactionType;

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


      string strPOSEntryMode(m_hGenericSegment[0].get("POS_ENTRY_MODE"));
      if (strPOSEntryMode == "021" && strPROC_ID_ISS_B == "VISA")
      {
         if (strMTI == "1210" || strMTI == "1430" || (strMTI == "1230" && (m_hGenericSegment[0].get("APPROVAL_CODE").length() == 0)))
            strPOSEntryMode = "901";
      }
      memcpy(pTC57_TCR0_TxnDetail->sPOSEntryMode, strPOSEntryMode.data(), min(size_t(2), m_hGenericSegment[0].get("POS_ENTRY_MODE").length()));
      memcpy(pTC57_TCR0_TxnDetail->sPOSInputMode, m_hGenericSegment[0].get("POS_ENTRY_MODE").data(), m_hGenericSegment[0].get("POS_ENTRY_MODE").length());
      pTC57_TCR0_TxnDetail->cPOSDebitReimbAttr = m_hGenericSegment[0].get("{ReimburseAttr|")[0];
      pTC57_TCR0_TxnDetail->cReimbAttr = m_hGenericSegment[0].get("{ReimburseAttr|")[0];
      memcpy(pTC57_TCR0_TxnDetail->sTokenAssurance, m_hGenericSegment[0].get("{TokenAssuranceLevel|").data(), m_hGenericSegment[0].get("{TokenAssuranceLevel|").length());
      if ((m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").length() > 0) && (memcmp(m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").data(), "801", 3)))
         memcpy(pTC57_TCR0_TxnDetail->sTokenRequestorId, m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").data(), min(size_t(11), m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").length()));
      string strPosCondCode = m_hGenericSegment[0].get("POS_COND_CODE");
      if (strPosCondCode == "48") //Ecom Txn
      {
         pTC57_TCR0_TxnDetail->cCATLevelInd = '6';
         if (strMTI == "1210" && (!m_hGenericSegment[0].get("{SLI|").empty()))
            pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd = m_hGenericSegment[0].get("{SLI|").substr(2, 1)[0];
         else
            pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd = '5';
      }
      else if (strPosCondCode == "08") //MOTO Txn
         pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd = '1';
   }
   else
   {
      memcpy(pTC57_TCR0_TxnDetail->sTransactionCurrCode, m_hGenericSegment[0].get("CUR_TRAN").data(), m_hGenericSegment[0].get("CUR_TRAN").length());
      if (m_hGenericSegment[0].get("TERM_CLASS") == "25")
         pTC57_TCR0_TxnDetail->cCATLevelInd = '6';

      if (Extract::instance()->getCustomCode() == "CBA"
         && m_hGenericSegment[0].get("REF_DATA_ISS_FMT") == "4")
      {
         visabaseii::segREF_DATA_ISS_EVES_AUS* pREF_DATA_ISS_EVES_AUS = (visabaseii::segREF_DATA_ISS_EVES_AUS*)m_szREF_DATA_ISS;
         pTC57_TCR0_TxnDetail->cPOSDebitReimbAttr = pREF_DATA_ISS_EVES_AUS->cREIMBURSEMENT_ATTR;
      }
      else
         pTC57_TCR0_TxnDetail->cPOSDebitReimbAttr = m_hGenericSegment[0].get("REIMBURSEMENT_ATTR")[0];
      pTC57_TCR0_TxnDetail->cAVSResponseCode = m_hGenericSegment[0].get("TRAN_UNIQUE_DATA")[29];
      pTC57_TCR0_TxnDetail->cReimbAttr = pTC57_TCR0_TxnDetail->cPOSDebitReimbAttr;
      memcpy(pTC57_TCR0_TxnDetail->sTokenAssurance, m_hGenericSegment[0].get("TOKEN_ASSURANCE").data(), m_hGenericSegment[0].get("TOKEN_ASSURANCE").length());
      memcpy(pTC57_TCR0_TxnDetail->sTokenRequestorId, m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").data(), m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").length());
      memcpy(pTC57_TCR0_TxnDetail->sAccountRange, m_hGenericSegment[0].get("PAN_RANGE").data(), m_hGenericSegment[0].get("PAN_RANGE").length());

      char szTransactionType = '5';
      string strTRAN_TYPE_ID(m_hGenericSegment[0].get("TRAN_TYPE_ID"), 0, 2);
      if (getGenericValue("TC57_TXNTYPE", strTRAN_TYPE_ID, strToValue))
         szTransactionType = strToValue[0];
      pTC57_TCR0_TxnDetail->cTransactionType = szTransactionType;

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
      if (m_hGenericSegment[0].get("EXT_POS_ENTRY_MODE").length() == 3)
         memcpy(pTC57_TCR0_TxnDetail->sPOSInputMode, m_hGenericSegment[0].get("EXT_POS_ENTRY_MODE").data(), sizeof(pTC57_TCR0_TxnDetail->sPOSInputMode));
      else
         memset(pTC57_TCR0_TxnDetail->sPOSInputMode, '0', sizeof(pTC57_TCR0_TxnDetail->sPOSInputMode));
      memset(pTC57_TCR0_TxnDetail->sUID, '0', sizeof(pTC57_TCR0_TxnDetail->sUID));
      memset(pTC57_TCR0_TxnDetail->sNationalReimbFee, '0', sizeof(pTC57_TCR0_TxnDetail->sNationalReimbFee));
      memset(pTC57_TCR0_TxnDetail->sSettleAmtUSD, '0', sizeof(pTC57_TCR0_TxnDetail->sSettleAmtUSD));
      memcpy(pTC57_TCR0_TxnDetail->sUniqueId, m_hGenericSegment[0].get("TRANSACTION_ID").data(), min(sizeof(pTC57_TCR0_TxnDetail->sUniqueId), m_hGenericSegment[0].get("TRANSACTION_ID").length()));
   }

   if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "A")
   {
      if (Extract::instance()->getCustomCode() != "CBA"
         && Extract::instance()->getCustomCode() != "PAAS")
      {
         if (m_hGenericSegment[0].get("POS_CRDHLDR_PRESNT") == "4")
            pTC57_TCR0_TxnDetail->cRecurringPaymentIndicator = '4';
         else if (m_hGenericSegment[0].get("POS_CRDHLDR_PRESNT") == "S")
            pTC57_TCR0_TxnDetail->cRecurringPaymentIndicator = 'I';
         else if (m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD") == "9")
            pTC57_TCR0_TxnDetail->cRecurringPaymentIndicator = 'C';
      }

      if (!memcmp(m_szADL_DATA_PRIV_ACQ, "MC", 2))
      {
         mastercardcis::segADL_DATA_PRIV_ACQ_Advantage* pADL_DATA_PRIV_ACQ;
         pADL_DATA_PRIV_ACQ = (struct mastercardcis::segADL_DATA_PRIV_ACQ_Advantage*)m_szADL_DATA_PRIV_ACQ;
         if (pADL_DATA_PRIV_ACQ->cCardActivatedTerminalLevel != ' ')
            pTC57_TCR0_TxnDetail->cCATLevelInd = pADL_DATA_PRIV_ACQ->cCardActivatedTerminalLevel;
         memcpy(pTC57_TCR0_TxnDetail->sSubMerchantID, pADL_DATA_PRIV_ACQ->sMERCHANT_ID, sizeof(pTC57_TCR0_TxnDetail->sSubMerchantID));
         memcpy(pTC57_TCR0_TxnDetail->sPymtFacilitatorId, pADL_DATA_PRIV_ACQ->sPAYMENT_FID, sizeof(pTC57_TCR0_TxnDetail->sPymtFacilitatorId));
      }
      else if (!memcmp(m_szADL_DATA_PRIV_ACQ, "MD", 2))
      {
         mastercardmds::segADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
         pADL_DATA_PRIV_ACQ = (struct mastercardmds::segADL_DATA_PRIV_ACQ*)m_szADL_DATA_PRIV_ACQ;
         if (pADL_DATA_PRIV_ACQ->cCardActivatedTerminalLevel != ' ')
            pTC57_TCR0_TxnDetail->cCATLevelInd = pADL_DATA_PRIV_ACQ->cCardActivatedTerminalLevel;
         memcpy(pTC57_TCR0_TxnDetail->sSubMerchantID, pADL_DATA_PRIV_ACQ->sMERCHANT_ID, sizeof(pTC57_TCR0_TxnDetail->sSubMerchantID));
         memcpy(pTC57_TCR0_TxnDetail->sPymtFacilitatorId, pADL_DATA_PRIV_ACQ->sPAYMENT_FID, sizeof(pTC57_TCR0_TxnDetail->sPymtFacilitatorId));
      }
      else if (!memcmp(m_szADL_DATA_PRIV_ACQ, "VE", 2))
      {
         visabaseii::segADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
         pADL_DATA_PRIV_ACQ = (struct visabaseii::segADL_DATA_PRIV_ACQ*)m_szADL_DATA_PRIV_ACQ;
         if (pADL_DATA_PRIV_ACQ->cAUTH_CHAR_FLAG != ' ')
            pTC57_TCR0_TxnDetail->cAuthCharInd = pADL_DATA_PRIV_ACQ->cAUTH_CHAR_FLAG;
         memcpy(pTC57_TCR0_TxnDetail->sSubMerchantID, pADL_DATA_PRIV_ACQ->sSubMerchantID, sizeof(pTC57_TCR0_TxnDetail->sSubMerchantID));
         memcpy(pTC57_TCR0_TxnDetail->sPymtFacilitatorId, pADL_DATA_PRIV_ACQ->sMarketplaceID, sizeof(pTC57_TCR0_TxnDetail->sPymtFacilitatorId));
         if (pADL_DATA_PRIV_ACQ->cCardholderIDMethod != ' ')
            pTC57_TCR0_TxnDetail->cCATLevelInd = pADL_DATA_PRIV_ACQ->cCardholderIDMethod;
         if (Extract::instance()->getCustomCode() == "CBA"
            || Extract::instance()->getCustomCode() == "PAAS")
         {
            if (pADL_DATA_PRIV_ACQ->cPOSEnvironment == 'I')
               pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd = '3';
            else if (pADL_DATA_PRIV_ACQ->cPOSEnvironment == 'R')
               pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd = '2';
            pTC57_TCR0_TxnDetail->cRecurringPaymentIndicator = pADL_DATA_PRIV_ACQ->cPOSEnvironment;
         }
      }
      if (strPROC_ID_ISS_B == "VISA")
      {
         getGenericValue("TC57_VI_P_E_MOD", m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD"), strToValue);
         memcpy(pTC57_TCR0_TxnDetail->sPOSEntryMode, strToValue.data(), min(sizeof(pTC57_TCR0_TxnDetail->sPOSEntryMode), strToValue.length()));
         visabaseii::segREF_DATA_ISS_EVES* pREF_DATA_ISS_baseii = (struct visabaseii::segREF_DATA_ISS_EVES*)m_szREF_DATA_ISS;
         pTC57_TCR0_TxnDetail->cAuthorizationSourceCode = pREF_DATA_ISS_baseii->cReasoncode;
      }
      else if (strPROC_ID_ISS_B == "EFTPOS" && m_bAdvRevTran)
      {
         getGenericValue("TC57_EHB_PE_MOD", m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD"), strToValue);
         memcpy(pTC57_TCR0_TxnDetail->sPOSEntryMode, strToValue.data(), min(sizeof(pTC57_TCR0_TxnDetail->sPOSEntryMode), strToValue.length()));
      }
      else
         memcpy(pTC57_TCR0_TxnDetail->sPOSEntryMode, m_hGenericSegment[0].get("AS2805_DE22").data(), min(sizeof(pTC57_TCR0_TxnDetail->sPOSEntryMode), m_hGenericSegment[0].get("AS2805_DE22").length()));
      memcpy(pTC57_TCR0_TxnDetail->sPurchaseDate, m_hGenericSegment[0].get("TSTAMP_LOCAL").data() + 4, sizeof(pTC57_TCR0_TxnDetail->sPurchaseDate));
      memcpy(pTC57_TCR0_TxnDetail->sTransactionTimeHHMM, m_hGenericSegment[0].get("TSTAMP_LOCAL").data() + 8, sizeof(pTC57_TCR0_TxnDetail->sTransactionTimeHHMM));
      string strTstampLocalAdj = m_hGenericSegment[0].get("TSTAMP_LOCAL_ADJ");
      if (strTstampLocalAdj.length() == 14)
      {
         memcpy(pTC57_TCR0_TxnDetail->sDebitTransDate, strTstampLocalAdj.data() + 4, sizeof(pTC57_TCR0_TxnDetail->sDebitTransDate));
         memcpy(pTC57_TCR0_TxnDetail->sDebitTransTime, strTstampLocalAdj.data() + 8, sizeof(pTC57_TCR0_TxnDetail->sDebitTransTime));
      }
      string strToValue = m_hGenericSegment[0].get("POS_CRDHLDR_A_METH");
      if (Extract::instance()->getCustomCode() != "CBA")
      {
         if (strToValue == "6" || strToValue == "7" || strToValue == "8" || strToValue == "9")
            getGenericValue("TC57_MOTO_PCAM", m_hGenericSegment[0].get("POS_CRDHLDR_A_METH"), strToValue);
         else
         {
            getGenericValue("TC57_MOTO_PCP", m_hGenericSegment[0].get("POS_CRDHLDR_PRESNT"), strToValue);
            if (strToValue.empty())
               getGenericValue("TC57_MOTO_PCAM", m_hGenericSegment[0].get("POS_CRDHLDR_A_METH"), strToValue);
         }
         pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd = m_szREF_DATA_ISS[80] == ' ' ? strToValue[0] : m_szREF_DATA_ISS[80];
         m_hGenericSegment[0].set("MOTO_ECOM", string(sizeof(pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd), pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd));
      }
      else if (pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd == ' ')
      {
         if (m_hGenericSegment[0].get("POS_CRDHLDR_A_METH") != "0")
            getGenericValue("TC57_MOTO_PCAM", m_hGenericSegment[0].get("POS_CRDHLDR_A_METH"), strToValue);
         else if (m_hGenericSegment[0].get("POS_CRDHLDR_AUTH_C") != " ")
         {
            if (getGenericValue("TC57_MOTO_PCP", m_hGenericSegment[0].get("POS_CRDHLDR_PRESNT"), strToValue) && m_hGenericSegment[0].get("POS_CRDHLDR_AUTH_C") == "7"); //POS_CRDHLDR_PRESNT == 3 AND POS_CRDHLDR_AUTH_C == 7 -> MOTOorElecCommerceInd = 1(MOTO)
            else
               getGenericValue("TC57_MOTO_PCAC", m_hGenericSegment[0].get("POS_CRDHLDR_AUTH_C"), strToValue);
         }
         pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd = strToValue[0];
         m_hGenericSegment[0].set("MOTO_ECOM", string(sizeof(pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd), pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd));
      }
      memcpy(pTC57_TCR0_TxnDetail->sCardSeqNo, m_hGenericSegment[0].get("CARD_SEQ_NO").data(), min(sizeof(pTC57_TCR0_TxnDetail->sCardSeqNo), m_hGenericSegment[0].get("CARD_SEQ_NO").length()));
      memcpy(pTC57_TCR0_TxnDetail->sPOSCondCode, m_hGenericSegment[0].get("AS2805_DE25").data(), min(sizeof(pTC57_TCR0_TxnDetail->sPOSCondCode), m_hGenericSegment[0].get("AS2805_DE25").length()));
      pTC57_TCR0_TxnDetail->cSRV_GRP_INTCHG_IND = m_hGenericSegment[0].get("SRV_GRP_INTCHG_IND")[0];
      memcpy(pTC57_TCR0_TxnDetail->sSRV_GRP_SERV_CODE, m_hGenericSegment[0].get("SRV_GRP_SERV_CODE").data(), m_hGenericSegment[0].get("SRV_GRP_SERV_CODE").length());
      if (Extract::instance()->getCustomCode() == "CBA" || Extract::instance()->getCustomCode() == "PAAS")
      {
         if (m_hGenericSegment[0].get("NET_ID_ISS") == "MCI")
         {
            string strProcBillFlag2 = m_hGenericSegment[0].get("PROC_BILLING_FLGS2");
            if (strProcBillFlag2[7] == 'N')
            {
               pTC57_TCR0_TxnDetail->cCardholderIDMethod = '5';
               if (m_hGenericSegment[0].get("TERM_CLASS") == "17")
                  pTC57_TCR0_TxnDetail->cCardholderIDMethod = '3';
            }
            else if (strProcBillFlag2[7] == 'Y')
               pTC57_TCR0_TxnDetail->cCardholderIDMethod = '1';
            if (pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd != ' ')
               pTC57_TCR0_TxnDetail->cCardholderIDMethod = '4';
            m_hGenericSegment[0].set("CARDHOLDER_ID_METHOD", string(sizeof(pTC57_TCR0_TxnDetail->cCardholderIDMethod), pTC57_TCR0_TxnDetail->cCardholderIDMethod));
         }
         else if (m_hGenericSegment[0].get("REF_DATA_ISS_FMT") == "4")
         {
            visabaseii::segREF_DATA_ISS_EVES_AUS* pREF_DATA_ISS_EVES_AUS = (visabaseii::segREF_DATA_ISS_EVES_AUS*)m_szREF_DATA_ISS;
            pTC57_TCR0_TxnDetail->cCardholderIDMethod = pREF_DATA_ISS_EVES_AUS->sDE60field[10];
         }
      }
      getGenericValue("TC57_TP_CHANNEL", m_hGenericSegment[0].get("TERM_CLASS") + m_hGenericSegment[0].get("POS_OPER_ENV"), strToValue);
      if (strToValue.empty())
         strToValue.assign("00");
      memcpy(pTC57_TCR0_TxnDetail->sTransportChannel, strToValue.data(), sizeof(pTC57_TCR0_TxnDetail->sTransportChannel));
   }
   else if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "G")
   {
      mastercardipmmessageprocessor::hDATA_PRIV_ACQ* pDATA_PRIV_ACQ;
      pDATA_PRIV_ACQ = (struct mastercardipmmessageprocessor::hDATA_PRIV_ACQ*)m_szDATA_PRIV_ACQ;

      mastercardipmmessageprocessor::hEXTENSION_DATA_ADJ* pEXTENSION_DATA_ADJ;
      pEXTENSION_DATA_ADJ = (struct mastercardipmmessageprocessor::hEXTENSION_DATA_ADJ*)m_szEXTENSION_DATA_ADJ;

      if (m_hGenericSegment[0].get("POS_CRDHLDR_PRESNT") == "4")
         pTC57_TCR0_TxnDetail->cRecurringPaymentIndicator = '4';

      memcpy(pTC57_TCR0_TxnDetail->sPurchaseDate, m_hGenericSegment[0].get("TSTAMP_LOCAL").data() + 4, sizeof(pTC57_TCR0_TxnDetail->sPurchaseDate));
      memcpy(pTC57_TCR0_TxnDetail->sTransactionTimeHHMM, m_hGenericSegment[0].get("TSTAMP_LOCAL").data() + 8, sizeof(pTC57_TCR0_TxnDetail->sTransactionTimeHHMM));
      pTC57_TCR0_TxnDetail->cAuthorizationSourceCode = '5';

      string strPOSCondCode(pDATA_PRIV_ACQ->sPOSCondCode, sizeof(pDATA_PRIV_ACQ->sPOSCondCode));
      if (strPOSCondCode == "08")
         pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd = '1';
      else if (strPOSCondCode == "59")
         pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd = '5';

      if (m_hGenericSegment[0].get("NET_ID_ISS") == "VNT")
      {
         mastercardipmmessageprocessor::hADL_RESP_DATA* pADL_RESP_DATA;
         pADL_RESP_DATA = (struct mastercardipmmessageprocessor::hADL_RESP_DATA*)m_szADL_RESP_DATA;
         pTC57_TCR0_TxnDetail->cAuthCharInd = pADL_RESP_DATA->cACIInd;
         visasms::segADL_DATA_PRIV_ISS* pADL_DATA_PRIV_ISSsms = (visasms::segADL_DATA_PRIV_ISS*)m_szADL_DATA_PRIV_ISS;
         pTC57_TCR0_TxnDetail->cAdditionalTknRespInfo = pADL_DATA_PRIV_ISSsms->cAdd_Token_Resp_Info;
      }
      memcpy(pTC57_TCR0_TxnDetail->sPOSEntryMode, pDATA_PRIV_ACQ->sPOSEntryMode, sizeof(pTC57_TCR0_TxnDetail->sPOSEntryMode));
      memcpy(pTC57_TCR0_TxnDetail->sSubMerchantID, pEXTENSION_DATA_ADJ->sSub_Merchant_ID, sizeof(pTC57_TCR0_TxnDetail->sSubMerchantID));
      memcpy(pTC57_TCR0_TxnDetail->sCapReqMsgInd, "10", sizeof(pTC57_TCR0_TxnDetail->sCapReqMsgInd));
      memcpy(pTC57_TCR0_TxnDetail->sPOSCondCode, strPOSCondCode.data(), strPOSCondCode.length());
      memcpy(pTC57_TCR0_TxnDetail->sPymtFacilitatorId, pEXTENSION_DATA_ADJ->sPayment_Facilitator_ID, sizeof(pTC57_TCR0_TxnDetail->sPymtFacilitatorId));
   }
   else if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "T")
   {
      visabaseIImessageprocessor::hDATA_PRIV_ACQ* pDATA_PRIV_ACQ;
      pDATA_PRIV_ACQ = (struct visabaseIImessageprocessor::hDATA_PRIV_ACQ*)m_szDATA_PRIV_ACQ;

      if (pDATA_PRIV_ACQ->cPOS_OPER_ENV == 'R')
         pTC57_TCR0_TxnDetail->cRecurringPaymentIndicator = '4';

      pTC57_TCR0_TxnDetail->cAuthorizationSourceCode = m_hGenericSegment[0].get("AUTH_BY")[0];

      string strPOSCondCode(pDATA_PRIV_ACQ->sPOSConditionCode, sizeof(pDATA_PRIV_ACQ->sPOSConditionCode));
      if (strPOSCondCode == "08")
         pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd = '1';
      else if (strPOSCondCode == "59")
         pTC57_TCR0_TxnDetail->cMOTOorElecCommerceInd = '5';

      memcpy(pTC57_TCR0_TxnDetail->sDebitTransDate, m_hGenericSegment[0].get("DATE_RECON_ISS").data() + 4, sizeof(pTC57_TCR0_TxnDetail->sDebitTransDate));
      memset(pTC57_TCR0_TxnDetail->sDebitTransTime, '0', sizeof(pTC57_TCR0_TxnDetail->sDebitTransTime));

      memcpy(pTC57_TCR0_TxnDetail->sPOSEntryMode, pDATA_PRIV_ACQ->sPOSEntryMode, sizeof(pTC57_TCR0_TxnDetail->sPOSEntryMode));
      memcpy(pTC57_TCR0_TxnDetail->sReasonCode, m_hGenericSegment[0].get("MSG_RESON_CODE_ACQ").data(), m_hGenericSegment[0].get("MSG_RESON_CODE_ACQ").length());
      memset(pTC57_TCR0_TxnDetail->sCardSeqNo, '0', sizeof(pTC57_TCR0_TxnDetail->sCardSeqNo));
      memcpy(pTC57_TCR0_TxnDetail->sCapReqMsgInd, "10", sizeof(pTC57_TCR0_TxnDetail->sCapReqMsgInd));
      memcpy(pTC57_TCR0_TxnDetail->sPOSCondCode, strPOSCondCode.data(), strPOSCondCode.length());
      if (m_hGenericSegment[0].get("NET_ID_ISS") == "MCI")
      {
         mastercardmds::segADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
         pADL_DATA_PRIV_ACQ = (struct mastercardmds::segADL_DATA_PRIV_ACQ*)m_szADL_DATA_PRIV_ACQ;
         memcpy(pTC57_TCR0_TxnDetail->sPymtFacilitatorId, pADL_DATA_PRIV_ACQ->sPAYMENT_FID, sizeof(pTC57_TCR0_TxnDetail->sPymtFacilitatorId));
      }
   }
   return (write(sizeof(hTC57_TCR0_TxnDetail), hFlatFile));
  //## end report::ISTTC57TransactionFile::write_TCR0_TxnDetail%6809C3C000D4.body
}

bool ISTTC57TransactionFile::write_TCR1_TxnDetail_Common (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR1_TxnDetail_Common%6809C3C000D6.body preserve=yes
   m_iNoOfTcrs++;
   m_iTotNoOfTcrs++;
   m_siIntrMerchBatchKey++;
   struct hTC57_TCR1_TxnDetail_Common* pTC57_TCR1_TxnDetail_Common = (struct hTC57_TCR1_TxnDetail_Common*)getDATA_BUFFER();
   memset(pTC57_TCR1_TxnDetail_Common, ' ', sizeof(hTC57_TCR1_TxnDetail_Common));
   memcpy(pTC57_TCR1_TxnDetail_Common->sTransCode, "57", sizeof(pTC57_TCR1_TxnDetail_Common->sTransCode));
   pTC57_TCR1_TxnDetail_Common->cTransCodeQualifier = '0';
   pTC57_TCR1_TxnDetail_Common->cTransComponentSeqNumber = '1';
   if (!m_hGenericSegment[0].get("CARD_ACPT_NAME_LOC").empty())
   {
      memcpy(pTC57_TCR1_TxnDetail_Common->sDynamicDescriptor, m_hGenericSegment[0].get("CARD_ACPT_NAME_LOC").data(), min((size_t)25, m_hGenericSegment[0].get("CARD_ACPT_NAME_LOC").length()));
      if (m_hGenericSegment[0].get("CARD_ACPT_NAME_LOC").length() > 55)
      {
         string strCustomerServicePhoneNum(m_hGenericSegment[0].get("CARD_ACPT_NAME_LOC").data() + 55, min(size_t(13), m_hGenericSegment[0].get("CARD_ACPT_NAME_LOC").length() - 55));
         trim(strCustomerServicePhoneNum);
         memcpy(pTC57_TCR1_TxnDetail_Common->sCustomerServicePhoneNum, strCustomerServicePhoneNum.data(), strCustomerServicePhoneNum.length());
      }
   }
   pTC57_TCR1_TxnDetail_Common->cRecordType = '9';
   return (write(sizeof(hTC57_TCR1_TxnDetail_Common), hFlatFile));
  //## end report::ISTTC57TransactionFile::write_TCR1_TxnDetail_Common%6809C3C000D6.body
}

bool ISTTC57TransactionFile::write_TCR7_Chip (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR7_Chip%6809C3C000D8.body preserve=yes
   struct hTC57_TCR7_Chip* pTC57_TCR7_Chip = (struct hTC57_TCR7_Chip*)getDATA_BUFFER();
   memset(pTC57_TCR7_Chip, ' ', sizeof(hTC57_TCR7_Chip));
   memcpy(pTC57_TCR7_Chip->sTransactionType, m_hGenericSegment[0].get("TRAN_TYPE").data(), m_hGenericSegment[0].get("TRAN_TYPE").length());
   memcpy(pTC57_TCR7_Chip->sTermTranDate, m_hGenericSegment[0].get("TRAN_DATE").data(), m_hGenericSegment[0].get("TRAN_DATE").length());
   memcpy(pTC57_TCR7_Chip->sTermCapProf, m_hGenericSegment[0].get("TERM_CAPABILITIES").data(), m_hGenericSegment[0].get("TERM_CAPABILITIES").length());
   memcpy(pTC57_TCR7_Chip->sTermCountryCode, m_hGenericSegment[0].get("TERM_COUNTRY_CODE").data(), m_hGenericSegment[0].get("TERM_COUNTRY_CODE").length());
   memcpy(pTC57_TCR7_Chip->sTermSerialNo, m_hGenericSegment[0].get("TERM_SERIAL_NO").data(), m_hGenericSegment[0].get("TERM_SERIAL_NO").length());
   memcpy(pTC57_TCR7_Chip->sUnpredictableNumber, m_hGenericSegment[0].get("UNPREDICTABLE_NO").data(), min(size_t(8), m_hGenericSegment[0].get("UNPREDICTABLE_NO").length()));
   memcpy(pTC57_TCR7_Chip->sApplTranCounter, m_hGenericSegment[0].get("APPL_TRAN_COUNTER").data(), m_hGenericSegment[0].get("APPL_TRAN_COUNTER").length());
   memcpy(pTC57_TCR7_Chip->sApplIntrProf, m_hGenericSegment[0].get("APPL_INTRCHG_PROF").data(), m_hGenericSegment[0].get("APPL_INTRCHG_PROF").length());
   memcpy(pTC57_TCR7_Chip->sCryptogram, m_hGenericSegment[0].get("APPL_CRYPTOGRAM").data(), m_hGenericSegment[0].get("APPL_CRYPTOGRAM").length());
   memcpy(pTC57_TCR7_Chip->sTermVerResults, m_hGenericSegment[0].get("TERM_VERIFY_RESULT").data(), m_hGenericSegment[0].get("TERM_VERIFY_RESULT").length());
   memcpy(pTC57_TCR7_Chip->sCryptogramAmt, m_hGenericSegment[0].get("CRYPTOGRAM_AMOUNT").data(), m_hGenericSegment[0].get("CRYPTOGRAM_AMOUNT").length());
   memcpy(pTC57_TCR7_Chip->sIssrScript1Results, m_hGenericSegment[0].get("ISS_SCRIPT_RESULT").data(), min(size_t(10), m_hGenericSegment[0].get("ISS_SCRIPT_RESULT").length()));
   if (memcmp((char*)pTC57_TCR7_Chip, m_szSpaces, sizeof(hTC57_TCR7_Chip)))
   {
      char szTemp[PERCENTD + PERCENTHD];
      m_iNoOfTcrs++;
      m_iTotNoOfTcrs++;
      m_siIntrMerchBatchKey++;
      memcpy(pTC57_TCR7_Chip->sTransCode, "57", sizeof(pTC57_TCR7_Chip->sTransCode));
      pTC57_TCR7_Chip->cTransCodeQualifier = '0';
      pTC57_TCR7_Chip->cTransComponentSeqNumber = '7';
      memcpy(pTC57_TCR7_Chip->sIssrApplData1, "EMV", 3);
      memcpy(pTC57_TCR7_Chip->sIssrApplData2, "EMV", 3);
      memcpy(pTC57_TCR7_Chip->sIssrApplData3, "EMV", 3);
      snprintf(szTemp, sizeof(szTemp), "%08d%05hd", m_iBatchNo, m_siIntrMerchBatchKey);
      memcpy(pTC57_TCR7_Chip->sInternalMerchBatchKey, szTemp, sizeof(pTC57_TCR7_Chip->sInternalMerchBatchKey));
      pTC57_TCR7_Chip->cRecordType = '2';
      memcpy(pTC57_TCR7_Chip->sCardSeqNumber, m_hGenericSegment[0].get("CARD_SEQ_NO").data(), m_hGenericSegment[0].get("CARD_SEQ_NO").length());
      return (write(sizeof(hTC57_TCR7_Chip), hFlatFile));
   }
   return false;
  //## end report::ISTTC57TransactionFile::write_TCR7_Chip%6809C3C000D8.body
}

bool ISTTC57TransactionFile::write_TCR7_Chip_All (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR7_Chip_All%6809C3C000DA.body preserve=yes
   struct hTC57_TCR7_Chip_All* pTC57_TCR7_Chip_All = (struct hTC57_TCR7_Chip_All*)getDATA_BUFFER();
   memset(pTC57_TCR7_Chip_All, ' ', sizeof(hTC57_TCR7_Chip_All));
   memcpy(pTC57_TCR7_Chip_All->sAPPL_INTRCHG_PROF, m_hGenericSegment[0].get("APPL_INTRCHG_PROF").data(), m_hGenericSegment[0].get("APPL_INTRCHG_PROF").length());
   memcpy(pTC57_TCR7_Chip_All->sAPPL_TRAN_COUNTER, m_hGenericSegment[0].get("APPL_TRAN_COUNTER").data(), m_hGenericSegment[0].get("APPL_TRAN_COUNTER").length());
   memcpy(pTC57_TCR7_Chip_All->sAPPL_CRYPTOGRAM, m_hGenericSegment[0].get("APPL_CRYPTOGRAM").data(), m_hGenericSegment[0].get("APPL_CRYPTOGRAM").length());
   memcpy(pTC57_TCR7_Chip_All->sCRYPT_INFO_DATA, m_hGenericSegment[0].get("CRYPT_INFO_DATA").data(), m_hGenericSegment[0].get("CRYPT_INFO_DATA").length());
   memcpy(pTC57_TCR7_Chip_All->sTERM_COUNTRY_CODE, m_hGenericSegment[0].get("TERM_COUNTRY_CODE").data(), m_hGenericSegment[0].get("TERM_COUNTRY_CODE").length());
   memcpy(pTC57_TCR7_Chip_All->sTERM_CAPABILITIES, m_hGenericSegment[0].get("TERM_CAPABILITIES").data(), m_hGenericSegment[0].get("TERM_CAPABILITIES").length());
   memcpy(pTC57_TCR7_Chip_All->sTERMINAL_TYPE, m_hGenericSegment[0].get("TERMINAL_TYPE").data(), m_hGenericSegment[0].get("TERMINAL_TYPE").length());
   memcpy(pTC57_TCR7_Chip_All->sTERM_VERIFY_RESULT, m_hGenericSegment[0].get("TERM_VERIFY_RESULT").data(), m_hGenericSegment[0].get("TERM_VERIFY_RESULT").length());
   memcpy(pTC57_TCR7_Chip_All->sTRAN_DATE, m_hGenericSegment[0].get("TRAN_DATE").data(), m_hGenericSegment[0].get("TRAN_DATE").length());
   memcpy(pTC57_TCR7_Chip_All->sTRAN_TYPE, m_hGenericSegment[0].get("TRAN_TYPE").data(), m_hGenericSegment[0].get("TRAN_TYPE").length());
   memcpy(pTC57_TCR7_Chip_All->sTRAN_CURRENCY_CODE, m_hGenericSegment[0].get("TRAN_CURRENCY_CODE").data(), m_hGenericSegment[0].get("TRAN_CURRENCY_CODE").length());
   memcpy(pTC57_TCR7_Chip_All->sAMOUNT_OTHER, m_hGenericSegment[0].get("AMOUNT_OTHER").data(), m_hGenericSegment[0].get("AMOUNT_OTHER").length());
   memcpy(pTC57_TCR7_Chip_All->sISS_APPL_DATA, m_hGenericSegment[0].get("ISS_APPL_DATA").data(), m_hGenericSegment[0].get("ISS_APPL_DATA").length());
   memcpy(pTC57_TCR7_Chip_All->sUNPREDICTABLE_NO, m_hGenericSegment[0].get("UNPREDICTABLE_NO").data(), min(size_t(8), m_hGenericSegment[0].get("UNPREDICTABLE_NO").length()));
   memcpy(pTC57_TCR7_Chip_All->sCARDH_VER_RESULT, m_hGenericSegment[0].get("CARDH_VER_RESULT").data(), m_hGenericSegment[0].get("CARDH_VER_RESULT").length());
   memcpy(pTC57_TCR7_Chip_All->sDEDICATED_FILE_NAM, m_hGenericSegment[0].get("DEDICATED_FILE_NAM").data(), m_hGenericSegment[0].get("DEDICATED_FILE_NAM").length());
   memcpy(pTC57_TCR7_Chip_All->sAPPL_VERSION_NO, m_hGenericSegment[0].get("APPL_VERSION_NO").data(), m_hGenericSegment[0].get("APPL_VERSION_NO").length());
   memcpy(pTC57_TCR7_Chip_All->sTERM_SERIAL_NO, m_hGenericSegment[0].get("TERM_SERIAL_NO").data(), m_hGenericSegment[0].get("TERM_SERIAL_NO").length());
   memcpy(pTC57_TCR7_Chip_All->sTRAN_SEQ_COUNTER, m_hGenericSegment[0].get("TRAN_SEQ_COUNTER").data(), m_hGenericSegment[0].get("TRAN_SEQ_COUNTER").length());
   if (m_hGenericSegment[0].get("TRAN_CATEGORY_CODE").length())
      pTC57_TCR7_Chip_All->sTRAN_CATEGORY_CODE[0] = m_hGenericSegment[0].get("TRAN_CATEGORY_CODE").data()[0];
   memcpy(pTC57_TCR7_Chip_All->sISS_AUTH_DATA, m_hGenericSegment[0].get("ISS_AUTH_DATA").data(), m_hGenericSegment[0].get("ISS_AUTH_DATA").length());
   memcpy(pTC57_TCR7_Chip_All->sCRYPTOGRAM_AMOUNT, m_hGenericSegment[0].get("CRYPTOGRAM_AMOUNT").data(), m_hGenericSegment[0].get("CRYPTOGRAM_AMOUNT").length());
   memcpy(pTC57_TCR7_Chip_All->sIssrScript1Results, m_hGenericSegment[0].get("ISS_SCRIPT_RESULT").data(), min(size_t(10), m_hGenericSegment[0].get("ISS_SCRIPT_RESULT").length()));
   memcpy(pTC57_TCR7_Chip_All->sFormFactorInd, m_hGenericSegment[0].get("FORM_FACTOR_IND").data(), min(size_t(8), m_hGenericSegment[0].get("FORM_FACTOR_IND").length()));
   memcpy(pTC57_TCR7_Chip_All->sAPPL_ID, m_hGenericSegment[0].get("APPL_ID").data(), m_hGenericSegment[0].get("APPL_ID").length());
   if (memcmp((char*)pTC57_TCR7_Chip_All, m_szSpaces, sizeof(hTC57_TCR7_Chip_All)))
   {
      m_iNoOfTcrs++;
      m_iTotNoOfTcrs++;
      m_siIntrMerchBatchKey++;
      memcpy(pTC57_TCR7_Chip_All->sTransCode, "57", sizeof(pTC57_TCR7_Chip_All->sTransCode));
      pTC57_TCR7_Chip_All->cTransCodeQualifier = '0';
      pTC57_TCR7_Chip_All->cTransComponentSeqNumber = '7';
      memcpy(pTC57_TCR7_Chip_All->sAddendsTypeCode, "CH", 2);
      memcpy(pTC57_TCR7_Chip_All->sCardSeqNo, m_hGenericSegment[0].get("CARD_SEQ_NO").data(), m_hGenericSegment[0].get("CARD_SEQ_NO").length());
      memcpy(pTC57_TCR7_Chip_All->sAuthorizationAmount, m_hGenericSegment[0].get("AMT_TRAN").data() + 6, sizeof(pTC57_TCR7_Chip_All->sAuthorizationAmount));
      return (write(sizeof(hTC57_TCR7_Chip_All), hFlatFile));
   }
   return false;
  //## end report::ISTTC57TransactionFile::write_TCR7_Chip_All%6809C3C000DA.body
}

bool ISTTC57TransactionFile::write_TCR7_ChipExt (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR7_ChipExt%6809C3C000DC.body preserve=yes
   struct hTC57_TCR7_ChipExt* pTC57_TCR7_ChipExt = (struct hTC57_TCR7_ChipExt*)getDATA_BUFFER();
   memset(pTC57_TCR7_ChipExt, ' ', sizeof(hTC57_TCR7_ChipExt));
   memcpy(pTC57_TCR7_ChipExt->sIssuerAppData, m_hGenericSegment[0].get("ISS_APPL_DATA").data(), m_hGenericSegment[0].get("ISS_APPL_DATA").length());
   memcpy(pTC57_TCR7_ChipExt->sCryptoInfoData, m_hGenericSegment[0].get("CRYPT_INFO_DATA").data(), m_hGenericSegment[0].get("CRYPT_INFO_DATA").length());
   memcpy(pTC57_TCR7_ChipExt->sFormFactorInd, m_hGenericSegment[0].get("FORM_FACTOR_IND").data(), min(size_t(8), m_hGenericSegment[0].get("FORM_FACTOR_IND").length()));
   if (memcmp((char*)pTC57_TCR7_ChipExt, m_szSpaces, sizeof(hTC57_TCR7_ChipExt)))
   {
      char szTemp[PERCENTD + PERCENTHD];
      m_iNoOfTcrs++;
      m_iTotNoOfTcrs++;
      m_siIntrMerchBatchKey++;
      memcpy(pTC57_TCR7_ChipExt->sTransCode, "57", sizeof(pTC57_TCR7_ChipExt->sTransCode));
      pTC57_TCR7_ChipExt->cTransCodeQualifier = '0';
      pTC57_TCR7_ChipExt->cTransComponentSeqNumber = '7';
      pTC57_TCR7_ChipExt->cExtensionFlag = 'E';
      pTC57_TCR7_ChipExt->cRecordType = '7';
      snprintf(szTemp, sizeof(szTemp), "%08d%05hd", m_iBatchNo, m_siIntrMerchBatchKey);
      memcpy(pTC57_TCR7_ChipExt->sInternalMerchBatchKey, szTemp, sizeof(pTC57_TCR7_ChipExt->sInternalMerchBatchKey));
      return (write(sizeof(hTC57_TCR7_ChipExt), hFlatFile));
   }
   return false;
  //## end report::ISTTC57TransactionFile::write_TCR7_ChipExt%6809C3C000DC.body
}

bool ISTTC57TransactionFile::write_TCR5_TxnDetail_MC (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR5_TxnDetail_MC%6809C3C000DE.body preserve=yes
   Date hDate(m_hGenericSegment[0].get("DATE_RECON_NET").data());
   char szTemp[PERCENTD + PERCENTHD];
   m_iNoOfTcrs++;
   m_iTotNoOfTcrs++;
   m_siIntrMerchBatchKey++;
   struct hTC57_TCR5_TxnDetail_MC* pTC57_TCR5_TxnDetail_MC = (struct hTC57_TCR5_TxnDetail_MC*)getDATA_BUFFER();
   memset(pTC57_TCR5_TxnDetail_MC, ' ', sizeof(hTC57_TCR5_TxnDetail_MC));
   memcpy(pTC57_TCR5_TxnDetail_MC->sTransCode, "57", sizeof(pTC57_TCR5_TxnDetail_MC->sTransCode));
   pTC57_TCR5_TxnDetail_MC->cTransCodeQualifier = '0';
   pTC57_TCR5_TxnDetail_MC->cTransComponentSeqNumber = '5';
   memcpy(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementDate, hDate.asString("%m%d").data(), sizeof(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementDate));
   memcpy(pTC57_TCR5_TxnDetail_MC->sAuthorizationAmount, m_hGenericSegment[0].get("AMT_TRAN").data() + 6, sizeof(pTC57_TCR5_TxnDetail_MC->sAuthorizationAmount));
   pTC57_TCR5_TxnDetail_MC->cSrvGrpIntchgInd = m_hGenericSegment[0].get("SRV_GRP_INTCHG_IND")[0];
   memcpy(pTC57_TCR5_TxnDetail_MC->sSrvGrpServCode, m_hGenericSegment[0].get("SRV_GRP_SERV_CODE").data(), m_hGenericSegment[0].get("SRV_GRP_SERV_CODE").length());
   memcpy(pTC57_TCR5_TxnDetail_MC->sAcctHolderAuthValue, m_hGenericSegment[0].get("MCI_UCAF_DATA").data(), m_hGenericSegment[0].get("MCI_UCAF_DATA").length());
   memcpy(pTC57_TCR5_TxnDetail_MC->sDirectoryServerTranId, m_hGenericSegment[0].get("DIR_SERV_TRAN_ID").data(), m_hGenericSegment[0].get("DIR_SERV_TRAN_ID").length());
   if (m_hGenericSegment[0].get("ADL_DATA_PRIV_ACQ").length() >= 186)
      memcpy(pTC57_TCR5_TxnDetail_MC->sCountryOfOrigin, m_hGenericSegment[0].get("ADL_DATA_PRIV_ACQ").data() + 183, sizeof(pTC57_TCR5_TxnDetail_MC->sCountryOfOrigin));
   if (m_hGenericSegment[0].get("ECOM_DATA").length() >= sizeof(struct mastercardcis::segECOM_DATA))
   {
      mastercardcis::segECOM_DATA* pECOM_DATA;
      pECOM_DATA = (struct mastercardcis::segECOM_DATA*)m_hGenericSegment[0].get("ECOM_DATA").data();
      memcpy(pTC57_TCR5_TxnDetail_MC->sCitMitCategory, pECOM_DATA->sCitMitCategory, sizeof(pTC57_TCR5_TxnDetail_MC->sCitMitCategory));
      memcpy(pTC57_TCR5_TxnDetail_MC->sCitMitSubcategory, pECOM_DATA->sCitMitSubcategory, sizeof(pTC57_TCR5_TxnDetail_MC->sCitMitSubcategory));
   }
   string strToValue;
   if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") != "A")
   {
      getGenericValue("TC57_IN_CAP", m_hGenericSegment[0].get("POS_CRD_DAT_IN_CAP"), strToValue);
      pTC57_TCR5_TxnDetail_MC->cCardDataInputCap = strToValue[0];
      getGenericValue("TC57_AUTH_C", m_hGenericSegment[0].get("POS_CRDHLDR_AUTH_C"), strToValue);
      pTC57_TCR5_TxnDetail_MC->cCardholderAuthCap = strToValue[0];
      pTC57_TCR5_TxnDetail_MC->cCardCaptureCap = m_hGenericSegment[0].get("POS_CARD_CAPT_CAP")[0];
      getGenericValue("TC57_OPER_ENV", m_hGenericSegment[0].get("POS_OPER_ENV"), strToValue);
      pTC57_TCR5_TxnDetail_MC->cTerminalOperEnv = strToValue[0];
      getGenericValue("TC57_CRDHLDR_PT", m_hGenericSegment[0].get("POS_CRDHLDR_PRESNT"), strToValue);
      pTC57_TCR5_TxnDetail_MC->cCardholderPresentData = strToValue[0];
      pTC57_TCR5_TxnDetail_MC->cCardPresentData = m_hGenericSegment[0].get("POS_CARD_PRES")[0];
      if (pTC57_TCR5_TxnDetail_MC->cCardholderPresentData == '5')
         pTC57_TCR5_TxnDetail_MC->cCardDataInputMode = 'S';
      else
      {
         getGenericValue("TC57_IN_MOD", m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD"), strToValue);
         pTC57_TCR5_TxnDetail_MC->cCardDataInputMode = strToValue[0];
      }
      getGenericValue("TC57_A_METH", m_hGenericSegment[0].get("POS_CRDHLDR_A_METH"), strToValue);
      pTC57_TCR5_TxnDetail_MC->cCardholderAuthMeth = strToValue[0];
      getGenericValue("TC57_CH_AUTHENT", m_hGenericSegment[0].get("POS_CRDHLDR_AUTH"), strToValue);
      pTC57_TCR5_TxnDetail_MC->cCardholderAuthEntity = strToValue[0];
      pTC57_TCR5_TxnDetail_MC->cCardDataOutCap = m_hGenericSegment[0].get("POS_CRD_DAT_OT_CAP")[0];
      pTC57_TCR5_TxnDetail_MC->cTerminalDataOutCap = m_hGenericSegment[0].get("POS_TERM_OUT_CAP")[0];
      getGenericValue("TC57_CAPT_CAP", m_hGenericSegment[0].get("POS_PIN_CAPT_CAP"), strToValue);
      pTC57_TCR5_TxnDetail_MC->cPINCaptureCap = strToValue[0];
   }
   snprintf(szTemp, sizeof(szTemp), "%08d%05hd", m_iBatchNo, m_siIntrMerchBatchKey);
   memcpy(pTC57_TCR5_TxnDetail_MC->sInternalMerchBatchKey, szTemp, sizeof(pTC57_TCR5_TxnDetail_MC->sInternalMerchBatchKey));
   pTC57_TCR5_TxnDetail_MC->cRecordType = '2';
   if (Extract::instance()->getCustomCode() == "COLES")
   {
      memset(pTC57_TCR5_TxnDetail_MC->sTxnCategoryIndicator, '0', sizeof(pTC57_TCR5_TxnDetail_MC->sTxnCategoryIndicator));
      pTC57_TCR5_TxnDetail_MC->cCardholderAuthEntity = m_hGenericSegment[0].get("POS_CRDHLDR_AUTH")[0];
      if (!m_hGenericSegment[0].get("{BanknetData|").empty())
         memcpy(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementNumber, m_hGenericSegment[0].get("{BanknetData|").substr(0, 9).data(), 9);
      if ((m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").length() > 0) && (memcmp(m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").data(), "801", 3)))
         memcpy(pTC57_TCR5_TxnDetail_MC->sPPOLProgData, "101", 3);
      if (pTC57_TCR5_TxnDetail_MC->cCardDataInputMode == '2' && m_hGenericSegment[0].get("POS_ENTRY_MODE").substr(0, 2) == "80")
         pTC57_TCR5_TxnDetail_MC->cCardDataInputMode = 'B';
      if (pTC57_TCR5_TxnDetail_MC->cCardDataInputMode == '0' && m_hGenericSegment[0].get("POS_ENTRY_MODE").substr(0, 2) == "01")
         pTC57_TCR5_TxnDetail_MC->cCardDataInputMode = '1';
      if (pTC57_TCR5_TxnDetail_MC->cCardDataInputMode == 'C' && m_hGenericSegment[0].get("{CvmResults|").substr(0, 2) == "01")
         pTC57_TCR5_TxnDetail_MC->cCardDataInputMode = 'F';
      memcpy(pTC57_TCR5_TxnDetail_MC->sUcafEcsLvlInd, m_hGenericSegment[0].get("{TagValue|").data(), m_hGenericSegment[0].get("{TagValue|").length());
      pTC57_TCR5_TxnDetail_MC->cReimbAttr = m_hGenericSegment[0].get("{ReimburseAttr|")[0];
      memcpy(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementDate, m_hGenericSegment[0].get("{SettlementDate|").data(), min(sizeof(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementDate), m_hGenericSegment[0].get("{SettlementDate|").length()));
   }
   else
   {
      memset(pTC57_TCR5_TxnDetail_MC->sUcafEcsLvlInd, '0', sizeof(pTC57_TCR5_TxnDetail_MC->sUcafEcsLvlInd));
      memcpy(pTC57_TCR5_TxnDetail_MC->sUcafEcsLvlInd, m_hGenericSegment[0].get("MCI_ECS_LVL_IND").data(), m_hGenericSegment[0].get("MCI_ECS_LVL_IND").length());
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmountType, m_hGenericSegment[0].get("RQST_T0").data(), m_hGenericSegment[0].get("RQST_T0").length());
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmount, m_hGenericSegment[0].get("RQST_A0").data() + 6, sizeof(pTC57_TCR5_TxnDetail_MC->sAdditionalAmount));
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmountCur, m_hGenericSegment[0].get("RQST_C0").data(), m_hGenericSegment[0].get("RQST_C0").length());
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmountType1, m_hGenericSegment[0].get("RQST_T1").data(), m_hGenericSegment[0].get("RQST_T1").length());
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmount1, m_hGenericSegment[0].get("RQST_A1").data() + 6, sizeof(pTC57_TCR5_TxnDetail_MC->sAdditionalAmount1));
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmountCur1, m_hGenericSegment[0].get("RQST_C1").data(), m_hGenericSegment[0].get("RQST_C1").length());
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmountType2, m_hGenericSegment[0].get("RQST_T2").data(), m_hGenericSegment[0].get("RQST_T2").length());
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmount2, m_hGenericSegment[0].get("RQST_A2").data() + 6, sizeof(pTC57_TCR5_TxnDetail_MC->sAdditionalAmount2));
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmountCur2, m_hGenericSegment[0].get("RQST_C2").data(), m_hGenericSegment[0].get("RQST_C2").length());
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmountType3, m_hGenericSegment[0].get("RQST_T3").data(), m_hGenericSegment[0].get("RQST_T3").length());
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmount3, m_hGenericSegment[0].get("RQST_A3").data() + 6, sizeof(pTC57_TCR5_TxnDetail_MC->sAdditionalAmount3));
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmountCur3, m_hGenericSegment[0].get("RQST_C3").data(), m_hGenericSegment[0].get("RQST_C3").length());
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmountType4, m_hGenericSegment[0].get("RQST_T4").data(), m_hGenericSegment[0].get("RQST_T4").length());
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmount4, m_hGenericSegment[0].get("RQST_A4").data() + 6, sizeof(pTC57_TCR5_TxnDetail_MC->sAdditionalAmount4));
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmountCur4, m_hGenericSegment[0].get("RQST_C4").data(), m_hGenericSegment[0].get("RQST_C4").length());
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmountType5, m_hGenericSegment[0].get("RQST_T5").data(), m_hGenericSegment[0].get("RQST_T5").length());
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmount5, m_hGenericSegment[0].get("RQST_A5").data() + 6, sizeof(pTC57_TCR5_TxnDetail_MC->sAdditionalAmount5));
      memcpy(pTC57_TCR5_TxnDetail_MC->sAdditionalAmountCur5, m_hGenericSegment[0].get("RQST_C5").data(), m_hGenericSegment[0].get("RQST_C5").length());
      memset(pTC57_TCR5_TxnDetail_MC->sGuaranteeAmt, ' ', sizeof(pTC57_TCR5_TxnDetail_MC->sGuaranteeAmt));
      memset(pTC57_TCR5_TxnDetail_MC->sPostSettlementDate, ' ', sizeof(pTC57_TCR5_TxnDetail_MC->sPostSettlementDate));
      memset(pTC57_TCR5_TxnDetail_MC->sOrigAuthReqDate, ' ', sizeof(pTC57_TCR5_TxnDetail_MC->sOrigAuthReqDate));
      memset(pTC57_TCR5_TxnDetail_MC->sATMServiceFee, '0', sizeof(pTC57_TCR5_TxnDetail_MC->sATMServiceFee));
      pTC57_TCR5_TxnDetail_MC->cMposAcceptDeviceType = '0';
   }
   if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "A")
   {
      if (!memcmp(m_szADL_DATA_PRIV_ACQ, "MC", 2))
      {
         mastercardcis::segADL_DATA_PRIV_ACQ_Advantage* pADL_DATA_PRIV_ACQ;
         pADL_DATA_PRIV_ACQ = (struct mastercardcis::segADL_DATA_PRIV_ACQ_Advantage*)m_szADL_DATA_PRIV_ACQ;
         memcpy(pTC57_TCR5_TxnDetail_MC->sMastercardAssignedId, pADL_DATA_PRIV_ACQ->sMCAssignedId, sizeof(pTC57_TCR5_TxnDetail_MC->sMastercardAssignedId));
         memcpy(pTC57_TCR5_TxnDetail_MC->sTransitTranTypeInd, pADL_DATA_PRIV_ACQ->sTRANSIT_TRAN_IND, sizeof(pTC57_TCR5_TxnDetail_MC->sTransitTranTypeInd));
         memcpy(pTC57_TCR5_TxnDetail_MC->sTransportModeInd, pADL_DATA_PRIV_ACQ->sTRANSPORT_MODE_IND, sizeof(pTC57_TCR5_TxnDetail_MC->sTransportModeInd));
         memcpy(pTC57_TCR5_TxnDetail_MC->sPPOLProgData, pADL_DATA_PRIV_ACQ->sPPOL_PGM_DATA, sizeof(pTC57_TCR5_TxnDetail_MC->sPPOLProgData));
         memcpy(pTC57_TCR5_TxnDetail_MC->sPaymentFacilitatorID, pADL_DATA_PRIV_ACQ->sPAYMENT_FID, sizeof(pTC57_TCR5_TxnDetail_MC->sPaymentFacilitatorID));
         memcpy(pTC57_TCR5_TxnDetail_MC->sSubMerchantID, pADL_DATA_PRIV_ACQ->sMERCHANT_ID, sizeof(pTC57_TCR5_TxnDetail_MC->sSubMerchantID));
         memcpy(pTC57_TCR5_TxnDetail_MC->sIndependentSalesOrgID, pADL_DATA_PRIV_ACQ->sSALES_ORG_ID, sizeof(pTC57_TCR5_TxnDetail_MC->sIndependentSalesOrgID));
         memcpy(pTC57_TCR5_TxnDetail_MC->sTransactionLinkID, pADL_DATA_PRIV_ACQ->sTransactionLinkID, sizeof(pTC57_TCR5_TxnDetail_MC->sTransactionLinkID));
      }
      else if (!memcmp(m_szADL_DATA_PRIV_ACQ, "MD", 2))
      {
         mastercardmds::segADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
         pADL_DATA_PRIV_ACQ = (struct mastercardmds::segADL_DATA_PRIV_ACQ*)m_szADL_DATA_PRIV_ACQ;
         mastercardmds::segREF_DATA_ISS* pREF_DATA_ISS;
         pREF_DATA_ISS = (struct mastercardmds::segREF_DATA_ISS*)m_szREF_DATA_ISS;
         memcpy(pTC57_TCR5_TxnDetail_MC->sMastercardAssignedId, pADL_DATA_PRIV_ACQ->sMCAssignedId, sizeof(pTC57_TCR5_TxnDetail_MC->sMastercardAssignedId));
         memcpy(pTC57_TCR5_TxnDetail_MC->sTransitTranTypeInd, pADL_DATA_PRIV_ACQ->sTRANSIT_TRAN_IND, sizeof(pTC57_TCR5_TxnDetail_MC->sTransitTranTypeInd));
         memcpy(pTC57_TCR5_TxnDetail_MC->sTransportModeInd, pADL_DATA_PRIV_ACQ->sTRANSPORT_MODE_IND, sizeof(pTC57_TCR5_TxnDetail_MC->sTransportModeInd));
         memcpy(pTC57_TCR5_TxnDetail_MC->sPPOLProgData, pADL_DATA_PRIV_ACQ->sPPOL_PGM_DATA, sizeof(pTC57_TCR5_TxnDetail_MC->sPPOLProgData));
         memcpy(pTC57_TCR5_TxnDetail_MC->sPaymentFacilitatorID, pADL_DATA_PRIV_ACQ->sPAYMENT_FID, sizeof(pTC57_TCR5_TxnDetail_MC->sPaymentFacilitatorID));
         memcpy(pTC57_TCR5_TxnDetail_MC->sSubMerchantID, pADL_DATA_PRIV_ACQ->sMERCHANT_ID, sizeof(pTC57_TCR5_TxnDetail_MC->sSubMerchantID));
         memcpy(pTC57_TCR5_TxnDetail_MC->sIndependentSalesOrgID, pADL_DATA_PRIV_ACQ->sSALES_ORG_ID, sizeof(pTC57_TCR5_TxnDetail_MC->sIndependentSalesOrgID));
         memcpy(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementDate, pREF_DATA_ISS->sSettleDate, sizeof(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementDate));
         memcpy(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementNumber, pREF_DATA_ISS->sBanknetRef, sizeof(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementNumber));
         memcpy(pTC57_TCR5_TxnDetail_MC->sTransactionLinkID, pADL_DATA_PRIV_ACQ->sTransactionLinkID, sizeof(pTC57_TCR5_TxnDetail_MC->sTransactionLinkID));
      }

      if (m_hGenericSegment[0].get("REF_DATA_ISS_FMT") == "6")
      {
         mastercardcis::segREF_DATA_ISS* pREF_DATA_ISS;
         pREF_DATA_ISS = (struct mastercardcis::segREF_DATA_ISS*)m_szREF_DATA_ISS;
         memcpy(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementDate, pREF_DATA_ISS->sBanknetDate, sizeof(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementDate));
         memcpy(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementNumber, pREF_DATA_ISS->sBanknetRef, sizeof(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementNumber));
      }

      string strADL_DATA_NATIONAL(m_hGenericSegment[0].get("ADL_DATA_NATIONAL"));
      size_t nPosBegin;
      string strLen, strValue;
      nPosBegin = strADL_DATA_NATIONAL.find("\\M9");
      if (nPosBegin != string::npos)
      {
         strLen.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 3, 2);
         strValue.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 5, atoi(strLen.data()));
         memcpy(pTC57_TCR5_TxnDetail_MC->sServiceLocCity, strValue.data(), strValue.length());
      }
      nPosBegin = strADL_DATA_NATIONAL.find("\\MA");
      if (nPosBegin != string::npos)
      {
         strLen.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 3, 2);
         strValue.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 5, atoi(strLen.data()));
         memcpy(pTC57_TCR5_TxnDetail_MC->sServiceLocCountrySubCode, strValue.data(), strValue.length());
      }
      nPosBegin = strADL_DATA_NATIONAL.find("\\MB");
      if (nPosBegin != string::npos)
      {
         strLen.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 3, 2);
         strValue.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 5, atoi(strLen.data()));
         memcpy(pTC57_TCR5_TxnDetail_MC->sServiceLocCountryCode, strValue.data(), strValue.length());
      }
      nPosBegin = strADL_DATA_NATIONAL.find("\\MC");
      if (nPosBegin != string::npos)
      {
         strLen.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 3, 2);
         strValue.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 5, atoi(strLen.data()));
         memcpy(pTC57_TCR5_TxnDetail_MC->sServiceLocPostalCode, strValue.data(), strValue.length());
      }
      nPosBegin = strADL_DATA_NATIONAL.find("\\MD");
      if (nPosBegin != string::npos)
      {
         strLen.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 3, 2);
         strValue.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 5, atoi(strLen.c_str()));
         memcpy(pTC57_TCR5_TxnDetail_MC->sAccptGeoCoordinate, strValue.data(), min(strValue.length(), sizeof(pTC57_TCR5_TxnDetail_MC->sAccptGeoCoordinate)));
      }
      nPosBegin = strADL_DATA_NATIONAL.find("\\ME");
      if (nPosBegin != string::npos)
      {
         strLen.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 3, 2);
         strValue.assign(strADL_DATA_NATIONAL.data() + nPosBegin + 5, atoi(strLen.c_str()));
         memcpy(pTC57_TCR5_TxnDetail_MC->sServLocGeoCoordinate, strValue.data(), min(strValue.length(), sizeof(pTC57_TCR5_TxnDetail_MC->sServLocGeoCoordinate)));
      }
      pTC57_TCR5_TxnDetail_MC->cReimbAttr = m_hGenericSegment[0].get("REIMBURSEMENT_ATTR")[0];
      memcpy(pTC57_TCR5_TxnDetail_MC->sMastercardAssignedId, m_hGenericSegment[0].get("{DFA2|").data(), m_hGenericSegment[0].get("{DFA2|").length());
      if (m_bAdvRevTran)
      {
         string strTemp;

         if (getGenericValue("TC57_REV_AD_MOD", m_hGenericSegment[0].get("TERM_CLASS"), strToValue)
            || getGenericValue("TC57_REV_AD_MOD", m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD"), strToValue))
            strTemp = strToValue;

         if (getGenericValue("TC57_IN_MOD", strTemp, strToValue))
            pTC57_TCR5_TxnDetail_MC->cCardDataInputMode = strToValue[0];  // DE22,s7
         else
            pTC57_TCR5_TxnDetail_MC->cCardDataInputMode = '0';

         if (strTemp == "04")
            pTC57_TCR5_TxnDetail_MC->cCardholderAuthCap = '6';  // DE22,s2
         else if (getGenericValue("TC57_AUTH_C", strTemp.substr(1, 1), strToValue))
            pTC57_TCR5_TxnDetail_MC->cCardholderAuthCap = strToValue[0];
         else
            pTC57_TCR5_TxnDetail_MC->cCardholderAuthCap = '0';

         if (getGenericValue("TC57_REV_AD_PIN", m_hGenericSegment[0].get("POS_CRDHLDR_AUTH_C"), strToValue)
            || getGenericValue("TC57_REV_AD_PIN", m_hGenericSegment[0].get("POS_PIN_CAPT_CAP"), strToValue))
            strTemp = strToValue;
         else
            strTemp = "1";

         if ((strTemp == "0") || (strTemp == "2") || (strTemp == "8"))
            pTC57_TCR5_TxnDetail_MC->cPINCaptureCap = '0';   // DE22,s12
         else if (getGenericValue("TC57_CAPT_CAP", m_hGenericSegment[0].get("POS_PIN_CAPT_CAP"), strToValue))
            pTC57_TCR5_TxnDetail_MC->cPINCaptureCap = strToValue[0];

         getGenericValue("TC57_REV_MC_CDI", m_hGenericSegment[0].get("POS_CRD_DAT_IN_CAP"), strTemp);

         if (getGenericValue("TC57_IN_CAP", strTemp, strToValue))
            pTC57_TCR5_TxnDetail_MC->cCardDataInputCap = strToValue[0];  // // DE22,s1
         else
            pTC57_TCR5_TxnDetail_MC->cCardDataInputCap = '9';

         if (m_hGenericSegment[0].get("POS_CARD_CAPT_CAP")[0] != ' ')
            pTC57_TCR5_TxnDetail_MC->cCardCaptureCap = m_hGenericSegment[0].get("POS_CARD_CAPT_CAP")[0]; // DE22,s3
         else
            pTC57_TCR5_TxnDetail_MC->cCardCaptureCap = '9';

         if (m_hGenericSegment[0].get("POS_OPER_ENV")[0] != ' ')
            pTC57_TCR5_TxnDetail_MC->cTerminalOperEnv = m_hGenericSegment[0].get("POS_OPER_ENV")[0]; // DE22,s4
         else
            pTC57_TCR5_TxnDetail_MC->cTerminalOperEnv = '9';

         if (m_hGenericSegment[0].get("POS_OPER_ENV")[0] == '5')
            pTC57_TCR5_TxnDetail_MC->cCardholderPresentData = m_hGenericSegment[0].get("POS_OPER_ENV")[0]; // DE22,s5
         else if (m_hGenericSegment[0].get("POS_CRDHLDR_PRESNT")[0] == 'S')
            pTC57_TCR5_TxnDetail_MC->cCardholderPresentData = '4';
         else if (getGenericValue("TC57_CRDHLDR_PT", m_hGenericSegment[0].get("POS_CRDHLDR_PRESNT"), strToValue))
            pTC57_TCR5_TxnDetail_MC->cCardholderPresentData = strToValue[0];
         else
            pTC57_TCR5_TxnDetail_MC->cCardholderPresentData = '9';

         if (getGenericValue("TC57_REV_CPT", m_hGenericSegment[0].get("POS_CARD_PRES"), strToValue))
            pTC57_TCR5_TxnDetail_MC->cCardPresentData = strToValue[0];  // DE22,s6
         else
            pTC57_TCR5_TxnDetail_MC->cCardPresentData = '9';

         if (Extract::instance()->getCustomCode() == "CBA")
            pTC57_TCR5_TxnDetail_MC->cCardholderAuthMeth = m_hGenericSegment[0].get("CARDHOLDER_ID_METHOD")[0];
         else
            pTC57_TCR5_TxnDetail_MC->cCardholderAuthMeth = '9';   // DE22,s8
         pTC57_TCR5_TxnDetail_MC->cCardholderAuthEntity = '9';  // // DE22,s9
         pTC57_TCR5_TxnDetail_MC->cCardDataOutCap = '0';       // DE22,s10
         pTC57_TCR5_TxnDetail_MC->cTerminalDataOutCap = '0';   // DE22,s11
      }
      else
      {
         getGenericValue("TC57_IN_CAP", string(m_szREF_DATA_ISS + 68, 1), strToValue);
         if (strToValue.empty())
            pTC57_TCR5_TxnDetail_MC->cCardDataInputCap = '9';
         else
            pTC57_TCR5_TxnDetail_MC->cCardDataInputCap = strToValue[0];
         if (memcmp(m_szDATA_PRIV_ISS + 34, "04", 2) == 0)
            pTC57_TCR5_TxnDetail_MC->cCardholderAuthCap = '6';
         else if (getGenericValue("TC57_AUTH_C", string(m_szDATA_PRIV_ISS + 35, 1), strToValue))
            pTC57_TCR5_TxnDetail_MC->cCardholderAuthCap = strToValue[0];
         else
            pTC57_TCR5_TxnDetail_MC->cCardholderAuthCap = '0';
         if (m_szREF_DATA_ISS[63] != ' ')
            pTC57_TCR5_TxnDetail_MC->cCardCaptureCap = m_szREF_DATA_ISS[63];
         else
            pTC57_TCR5_TxnDetail_MC->cCardCaptureCap = '9';
         if (m_szREF_DATA_ISS[60] == '8')
            pTC57_TCR5_TxnDetail_MC->cTerminalOperEnv = m_szREF_DATA_ISS[60];
         else if (getGenericValue("TC57_OPER_ENV", string(m_szREF_DATA_ISS + 58, 1) + string(m_szREF_DATA_ISS + 60, 1), strToValue))
            pTC57_TCR5_TxnDetail_MC->cTerminalOperEnv = strToValue[0];
         else
            pTC57_TCR5_TxnDetail_MC->cTerminalOperEnv = '9';
         if (getGenericValue("TC57_CRDHLDR_PT", string(m_szREF_DATA_ISS + 61, 1), strToValue))
            pTC57_TCR5_TxnDetail_MC->cCardholderPresentData = strToValue[0];
         else
            pTC57_TCR5_TxnDetail_MC->cCardholderPresentData = '9';
         if (getGenericValue("TC57_CARD_PT", string(m_szREF_DATA_ISS + 62, 1), strToValue))
            pTC57_TCR5_TxnDetail_MC->cCardPresentData = strToValue[0];
         else
            pTC57_TCR5_TxnDetail_MC->cCardPresentData = '9';
         if (getGenericValue("TC57_IN_MOD", string(m_szDATA_PRIV_ISS + 34, 2), strToValue))
            pTC57_TCR5_TxnDetail_MC->cCardDataInputMode = strToValue[0];
         else
            pTC57_TCR5_TxnDetail_MC->cCardDataInputMode = '0';
         if (Extract::instance()->getCustomCode() == "CBA")
            pTC57_TCR5_TxnDetail_MC->cCardholderAuthMeth = m_hGenericSegment[0].get("CARDHOLDER_ID_METHOD")[0];
         else
         {
            if (memcmp(m_szDATA_PRIV_ISS + 28, "PV", 2) == 0
               || memcmp(m_szDATA_PRIV_ISS + 28, "TV", 2) == 0)
               pTC57_TCR5_TxnDetail_MC->cCardholderAuthMeth = '1';
            else
               pTC57_TCR5_TxnDetail_MC->cCardholderAuthMeth = '9';
         }
         pTC57_TCR5_TxnDetail_MC->cCardholderAuthEntity = '9';
         pTC57_TCR5_TxnDetail_MC->cCardDataOutCap = '0';
         pTC57_TCR5_TxnDetail_MC->cTerminalDataOutCap = '0';
         if (memcmp(m_szDATA_PRIV_ISS + 36, "0", 1) == 0
            || memcmp(m_szDATA_PRIV_ISS + 36, "2", 1) == 0
            || memcmp(m_szDATA_PRIV_ISS + 36, "8", 1) == 0)
            pTC57_TCR5_TxnDetail_MC->cPINCaptureCap = '0';
         else if (getGenericValue("TC57_CAPT_CAP", m_hGenericSegment[0].get("POS_PIN_CAPT_CAP"), strToValue))
            pTC57_TCR5_TxnDetail_MC->cPINCaptureCap = strToValue[0];
         else
            pTC57_TCR5_TxnDetail_MC->cPINCaptureCap = '1';
      }
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

      memcpy(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementNumber, pREF_DATA_ISS->sBanknetRef, sizeof(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementNumber));
      memcpy(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementDate, pREF_DATA_ISS->sBanknetDate, sizeof(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementDate));
      memcpy(pTC57_TCR5_TxnDetail_MC->sProgramRegistrationId, pADL_RESP_DATA->sPaymentTranTypeInd, sizeof(pTC57_TCR5_TxnDetail_MC->sProgramRegistrationId));
      memcpy(pTC57_TCR5_TxnDetail_MC->sTransitTranTypeInd, pADL_DATA_PRIV_ISS->sTransitTranTypeInd, sizeof(pTC57_TCR5_TxnDetail_MC->sTransitTranTypeInd));
      memcpy(pTC57_TCR5_TxnDetail_MC->sTransportModeInd, pADL_DATA_PRIV_ISS->sTransportModInd, sizeof(pTC57_TCR5_TxnDetail_MC->sTransportModeInd));
      memcpy(pTC57_TCR5_TxnDetail_MC->sPPOLProgData, pADL_RESP_DATA->sWalletProgramData, sizeof(pTC57_TCR5_TxnDetail_MC->sPPOLProgData));
      memcpy(pTC57_TCR5_TxnDetail_MC->sPaymentFacilitatorID, pEXTENSION_DATA_ADJ->sPayment_Facilitator_ID, sizeof(pTC57_TCR5_TxnDetail_MC->sPaymentFacilitatorID));
      memcpy(pTC57_TCR5_TxnDetail_MC->sSubMerchantID, pEXTENSION_DATA_ADJ->sSub_Merchant_ID, sizeof(pTC57_TCR5_TxnDetail_MC->sSubMerchantID));
      memcpy(pTC57_TCR5_TxnDetail_MC->sIndependentSalesOrgID, pEXTENSION_DATA_ADJ->sIndependent_Sales_Org_ID, sizeof(pTC57_TCR5_TxnDetail_MC->sIndependentSalesOrgID));
      memcpy(pTC57_TCR5_TxnDetail_MC->sCountryOfOrigin, pADL_DATA_PRIV_ISS->sMerchCountryOrigin, sizeof(pADL_DATA_PRIV_ISS->sMerchCountryOrigin));
      if (Extract::instance()->getCustomCode() == "CBA")
      {
         pTC57_TCR5_TxnDetail_MC->cCardDataInputCap = m_hGenericSegment[0].get("POS_CRD_DAT_IN_CAP")[0];
         pTC57_TCR5_TxnDetail_MC->cCardholderAuthCap = m_hGenericSegment[0].get("POS_CRDHLDR_AUTH_C")[0];
         pTC57_TCR5_TxnDetail_MC->cCardCaptureCap = m_hGenericSegment[0].get("POS_CARD_CAPT_CAP")[0];
         pTC57_TCR5_TxnDetail_MC->cTerminalOperEnv = m_hGenericSegment[0].get("POS_OPER_ENV")[0];
         pTC57_TCR5_TxnDetail_MC->cCardholderPresentData = m_hGenericSegment[0].get("POS_CRDHLDR_PRESNT")[0];
         pTC57_TCR5_TxnDetail_MC->cCardPresentData = m_hGenericSegment[0].get("POS_CARD_PRES")[0];
         pTC57_TCR5_TxnDetail_MC->cCardDataInputMode = m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD")[0];
         pTC57_TCR5_TxnDetail_MC->cCardholderAuthMeth = m_hGenericSegment[0].get("POS_CRDHLDR_A_METH")[0];
         pTC57_TCR5_TxnDetail_MC->cPINCaptureCap = m_hGenericSegment[0].get("POS_PIN_CAPT_CAP")[0];
      }
      memcpy(pTC57_TCR5_TxnDetail_MC->sDirectoryServerTranId, pADL_RESP_DATA->sDirectoryServerTranId, sizeof(pTC57_TCR5_TxnDetail_MC->sDirectoryServerTranId));
      pTC57_TCR5_TxnDetail_MC->cProgramProtocol = pADL_RESP_DATA->cProgramProtocol;
      memcpy(pTC57_TCR5_TxnDetail_MC->sPromotionCode, pADL_RESP_DATA->sPromotionCode, sizeof(pTC57_TCR5_TxnDetail_MC->sPromotionCode));
   }
   else if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "T")
   {
      mastercardcis::segREF_DATA_ISS* pREF_DATA_ISS;
      pREF_DATA_ISS = (struct mastercardcis::segREF_DATA_ISS*)m_szREF_DATA_ISS;
      mastercardmds::segADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
      pADL_DATA_PRIV_ACQ = (struct mastercardmds::segADL_DATA_PRIV_ACQ*)m_szADL_DATA_PRIV_ACQ;
      visabaseIImessageprocessor::hDATA_PRIV_ACQ* pDATA_PRIV_ACQ;
      pDATA_PRIV_ACQ = (struct visabaseIImessageprocessor::hDATA_PRIV_ACQ*)m_szDATA_PRIV_ACQ;

      memcpy(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementNumber, pREF_DATA_ISS->sBanknetRef, sizeof(pTC57_TCR5_TxnDetail_MC->sBanknetSettlementNumber));
      pTC57_TCR5_TxnDetail_MC->cCardDataInputMode = pDATA_PRIV_ACQ->sPOSEntryMode[0];
      memcpy(pTC57_TCR5_TxnDetail_MC->sPPOLProgData, m_hGenericSegment[0].get("WLT_ID").data(), min(sizeof(pTC57_TCR5_TxnDetail_MC->sPPOLProgData), m_hGenericSegment[0].get("WLT_ID").length()));

      memcpy(pTC57_TCR5_TxnDetail_MC->sMastercardAssignedId, pADL_DATA_PRIV_ACQ->sMCAssignedId, sizeof(pTC57_TCR5_TxnDetail_MC->sMastercardAssignedId));
      pTC57_TCR5_TxnDetail_MC->cRemotePaymentProgData = pADL_DATA_PRIV_ACQ->cREMOTE_PGM_IND;
      memcpy(pTC57_TCR5_TxnDetail_MC->sTransitTranTypeInd, pADL_DATA_PRIV_ACQ->sTRANSIT_TRAN_IND, sizeof(pTC57_TCR5_TxnDetail_MC->sTransitTranTypeInd));
      memcpy(pTC57_TCR5_TxnDetail_MC->sTransportModeInd, pADL_DATA_PRIV_ACQ->sTRANSPORT_MODE_IND, sizeof(pTC57_TCR5_TxnDetail_MC->sTransportModeInd));
      memcpy(pTC57_TCR5_TxnDetail_MC->sPaymentFacilitatorID, pADL_DATA_PRIV_ACQ->sPAYMENT_FID, sizeof(pTC57_TCR5_TxnDetail_MC->sPaymentFacilitatorID));
      memcpy(pTC57_TCR5_TxnDetail_MC->sSubMerchantID, pADL_DATA_PRIV_ACQ->sMERCHANT_ID, sizeof(pTC57_TCR5_TxnDetail_MC->sSubMerchantID));
      memcpy(pTC57_TCR5_TxnDetail_MC->sIndependentSalesOrgID, pADL_DATA_PRIV_ACQ->sSALES_ORG_ID, sizeof(pTC57_TCR5_TxnDetail_MC->sIndependentSalesOrgID));
      memcpy(pTC57_TCR5_TxnDetail_MC->sTransactionLinkID, pADL_DATA_PRIV_ACQ->sTransactionLinkID, sizeof(pTC57_TCR5_TxnDetail_MC->sTransactionLinkID));
   }
   m_hGenericSegment[0].set("WLT_ID", string(pTC57_TCR5_TxnDetail_MC->sPPOLProgData, sizeof(pTC57_TCR5_TxnDetail_MC->sPPOLProgData)));
   string strALMData(m_hGenericSegment[0].get("SEG24_45^AL"));
   strALMData.resize(30,' ');
   memcpy(pTC57_TCR5_TxnDetail_MC->sALMServiceCode,strALMData.data() + 4,5);
   memcpy(pTC57_TCR5_TxnDetail_MC->sALMProductCode,strALMData.data() + 13,3);
   memcpy(pTC57_TCR5_TxnDetail_MC->sALMProductClass,strALMData.data() + 20,3);
   memcpy(pTC57_TCR5_TxnDetail_MC->sALMRateType,strALMData.data() + 27,3);
   if (Extract::instance()->getCustomCode() == "PAAS" || Extract::instance()->getCustomCode() == "CBA")
   {
      struct hTC57_TCR5_TxnDetail_MC_Ext* pTC57_TCR5_TxnDetail_MC_Ext = (struct hTC57_TCR5_TxnDetail_MC_Ext*)(getDATA_BUFFER() + sizeof(hTC57_TCR5_TxnDetail_MC));
      memset(pTC57_TCR5_TxnDetail_MC_Ext, ' ', sizeof(hTC57_TCR5_TxnDetail_MC_Ext));
      return (write((sizeof(hTC57_TCR5_TxnDetail_MC) + sizeof(hTC57_TCR5_TxnDetail_MC_Ext)), hFlatFile));
   }
   else
      return (write(sizeof(hTC57_TCR5_TxnDetail_MC), hFlatFile));
  //## end report::ISTTC57TransactionFile::write_TCR5_TxnDetail_MC%6809C3C000DE.body
}

bool ISTTC57TransactionFile::write_TCR4_TxnDetail_VISA (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR4_TxnDetail_VISA%6809C3C000E0.body preserve=yes
   m_iNoOfTcrs++;
   m_iTotNoOfTcrs++;
   m_siIntrMerchBatchKey++;
   struct hTC57_TCR4_TxnDetail_VISA* pTC57_TCR4_TxnDetail_VISA = (struct hTC57_TCR4_TxnDetail_VISA*)getDATA_BUFFER();
   memset(pTC57_TCR4_TxnDetail_VISA, ' ', sizeof(hTC57_TCR4_TxnDetail_VISA));
   memcpy(pTC57_TCR4_TxnDetail_VISA->sTransCode, "57", sizeof(pTC57_TCR4_TxnDetail_VISA->sTransCode));
   pTC57_TCR4_TxnDetail_VISA->cTransCodeQualifier = '0';
   pTC57_TCR4_TxnDetail_VISA->cTransComponentSeqNumber = '4';
   memcpy(pTC57_TCR4_TxnDetail_VISA->sBusinessFormatCode, "SD", sizeof(pTC57_TCR4_TxnDetail_VISA->sBusinessFormatCode));
   pTC57_TCR4_TxnDetail_VISA->cRecordType = '2';
   return (write(sizeof(hTC57_TCR4_TxnDetail_VISA), hFlatFile));
  //## end report::ISTTC57TransactionFile::write_TCR4_TxnDetail_VISA%6809C3C000E0.body
}

bool ISTTC57TransactionFile::write_TCR1_DinersIntlChargeDetailRecord (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR1_DinersIntlChargeDetailRecord%6809C3C000E2.body preserve=yes
   m_iNoOfTcrs++;
   m_iTotNoOfTcrs++;
   m_siIntrMerchBatchKey++;
   struct hTC57_TCR1_DinersIntlChargeDetailRecord* pTC57_TCR1_DinersIntlChargeDetailRecord = (struct hTC57_TCR1_DinersIntlChargeDetailRecord*)getDATA_BUFFER();
   memset(pTC57_TCR1_DinersIntlChargeDetailRecord, ' ', sizeof(hTC57_TCR1_DinersIntlChargeDetailRecord));
   memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sTransCode, "57", sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sTransCode));
   pTC57_TCR1_DinersIntlChargeDetailRecord->cTransCodeQualifier = '0';
   pTC57_TCR1_DinersIntlChargeDetailRecord->cTransComponentSeqNumber = '1';
   memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sDinersIndicator, "DI", sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sDinersIndicator));
   memset(pTC57_TCR1_DinersIntlChargeDetailRecord->sSurchargeAmount, '0', sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sSurchargeAmount));

   string strCardDataInputMode = m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD");
   string strMTI = m_hGenericSegment[0].get("MTI");
   if (strCardDataInputMode == "5")
   {
      if (strMTI[1] != '4' && m_hGenericSegment[0].get("TRAN_TYPE_ID").substr(0, 2) == "20")
         memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge, "TL", sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge));
      else if (strMTI[1] == '4' && m_hGenericSegment[0].get("TRAN_TYPE_ID").substr(0, 2) == "20")
         memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge, "TK", sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge));
      else
         memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge, (strMTI[1] != '4' ? "TK" : "TL"), sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge));
   }
   else if (strCardDataInputMode == "R")
   {
      if (strMTI[1] != '4' && m_hGenericSegment[0].get("TRAN_TYPE_ID").substr(0, 2) == "20")
         memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge, "TJ", sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge));
      else if (strMTI[1] == '4' && m_hGenericSegment[0].get("TRAN_TYPE_ID").substr(0, 2) == "20")
         memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge, "TI", sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge));
      else
         memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge, (strMTI[1] != '4' ? "TI" : "TJ"), sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge));
   }
   else if (strCardDataInputMode == "A" || strCardDataInputMode == "B"
      || strCardDataInputMode == "C" || strCardDataInputMode == "M")
   {
      if (strMTI[1] != '4' && m_hGenericSegment[0].get("TRAN_TYPE_ID").substr(0, 2) == "20")
         memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge, "TG", sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge));
      else if (strMTI[1] == '4' && m_hGenericSegment[0].get("TRAN_TYPE_ID").substr(0, 2) == "20")
         memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge, "TE", sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge));
      else
         memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge, (strMTI[1] != '4' ? "TE" : "TG"), sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge));
   }
   else
   {
      if (strMTI[1] != '4' && m_hGenericSegment[0].get("TRAN_TYPE_ID").substr(0, 2) == "20")
         memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge, "TF", sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge));
      else if (strMTI[1] == '4' && m_hGenericSegment[0].get("TRAN_TYPE_ID").substr(0, 2) == "20")
         memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge, "TD", sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge));
      else
         memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge, (strMTI[1] != '4' ? "TD" : "TF"), sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sTypeOfCharge));
   }
   char szAdtlDataNatl[100];
   memset(szAdtlDataNatl, ' ', sizeof(szAdtlDataNatl) - 1);
   szAdtlDataNatl[sizeof(szAdtlDataNatl) - 1] = '\0';
   memcpy(szAdtlDataNatl, m_hGenericSegment[0].get("ADL_DATA_NATIONAL").data(), min(m_hGenericSegment[0].get("ADL_DATA_NATIONAL").length(), sizeof(szAdtlDataNatl)));
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
            pTC57_TCR1_DinersIntlChargeDetailRecord->cAuthenticationDataType = ' ';
            pTC57_TCR1_DinersIntlChargeDetailRecord->cECommPaymentIndicator = '4';
         }
         else
         {
            pTC57_TCR1_DinersIntlChargeDetailRecord->cAuthenticationDataType = strTemp[0];
            pTC57_TCR1_DinersIntlChargeDetailRecord->cECommPaymentIndicator = strTemp[1];
         }
      }
      memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sCAVVValue, szAdtlDataNatl + 21, sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sCAVVValue));
      memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sProtectBuyAuthResult, szAdtlDataNatl + 15, sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sProtectBuyAuthResult));
      memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sSecondFactorAuthResCde, szAdtlDataNatl + 17, sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sSecondFactorAuthResCde));
      memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sCAVVIndicator, szAdtlDataNatl + 19, sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sCAVVIndicator));
      memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sAuthTrackingNumber, szAdtlDataNatl + 29, sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sAuthTrackingNumber));
      if (m_bDF09Presence)
         memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sVersionAndAuthAction, "  ", 2);
      else
         memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sVersionAndAuthAction, szAdtlDataNatl + 45, sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sVersionAndAuthAction));
      memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sIPAddressInHexFormat, szAdtlDataNatl + 47, sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sIPAddressInHexFormat));
   }

   memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sNetworkReferenceID, m_szDATA_PRIV_ISS + 3, sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sNetworkReferenceID));

   if (strMTI[1] == '4')
      memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sACT_CODE, "000", 3);
   else if (memcmp(m_szDATA_PRIV_ISS + 51, "   ", 3) == 0)
      memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sACT_CODE, m_hGenericSegment[0].get("ACT_CODE").data(), min(sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sACT_CODE), m_hGenericSegment[0].get("ACT_CODE").length()));
   else
      memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sACT_CODE, m_szDATA_PRIV_ISS + 51, 3);

   if (m_bAdvRevTran)
   {
      string strToValue;
      if (m_hGenericSegment[0].get("TERM_CLASS") == "25")
         pTC57_TCR1_DinersIntlChargeDetailRecord->cPOS_CRDHLDR_PRESNT = '9';
      else
         pTC57_TCR1_DinersIntlChargeDetailRecord->cPOS_CRDHLDR_PRESNT = m_hGenericSegment[0].get("POS_CRDHLDR_PRESNT")[0];

      pTC57_TCR1_DinersIntlChargeDetailRecord->cPOS_CARD_PRES = m_hGenericSegment[0].get("POS_CARD_PRES")[0];
      if (getGenericValue("TC57_DC_REV_MOD", m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD"), strToValue))
         pTC57_TCR1_DinersIntlChargeDetailRecord->cPOS_CRD_DAT_IN_MOD = strToValue[0];
      else
         pTC57_TCR1_DinersIntlChargeDetailRecord->cPOS_CRD_DAT_IN_MOD = m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD")[0];

      if (getGenericValue("TC57_DC_REV_CAP", m_hGenericSegment[0].get("POS_CRD_DAT_IN_CAP"), strToValue))
         pTC57_TCR1_DinersIntlChargeDetailRecord->cPOS_CRD_DAT_IN_CAP = strToValue[0];
      else
         pTC57_TCR1_DinersIntlChargeDetailRecord->cPOS_CRD_DAT_IN_CAP = m_hGenericSegment[0].get("POS_CRD_DAT_IN_CAP")[0];

   }
   else if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "A")
   {
      pTC57_TCR1_DinersIntlChargeDetailRecord->cPOS_CRDHLDR_PRESNT = m_szDATA_PRIV_ISS[39];
      pTC57_TCR1_DinersIntlChargeDetailRecord->cPOS_CARD_PRES = m_szDATA_PRIV_ISS[40];
      pTC57_TCR1_DinersIntlChargeDetailRecord->cPOS_CRD_DAT_IN_MOD = m_szDATA_PRIV_ISS[41];
      pTC57_TCR1_DinersIntlChargeDetailRecord->cPOS_CRD_DAT_IN_CAP = m_szDATA_PRIV_ISS[35];
   }

   string strCAVV_RESULT;
   if (getGenericValue("TC57_CAVV_RESLT", m_hGenericSegment[0].get("CAVV_RESULT"), strCAVV_RESULT))
      memcpy(pTC57_TCR1_DinersIntlChargeDetailRecord->sCAVVValidationResult, strCAVV_RESULT.data(), min(sizeof(pTC57_TCR1_DinersIntlChargeDetailRecord->sCAVVValidationResult), strCAVV_RESULT.length()));

   return (write(sizeof(hTC57_TCR1_DinersIntlChargeDetailRecord), hFlatFile));
  //## end report::ISTTC57TransactionFile::write_TCR1_DinersIntlChargeDetailRecord%6809C3C000E2.body
}

bool ISTTC57TransactionFile::write_TCR3_TxnDetail_PaymentServiceData (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR3_TxnDetail_PaymentServiceData%6809C3C000E4.body preserve=yes
   m_iNoOfTcrs++;
   m_iTotNoOfTcrs++;
   m_siIntrMerchBatchKey++;
   struct hTC57_TCR3_TxnDetail_PSD* pTC57_TCR3_TxnDetail_PSD = (struct hTC57_TCR3_TxnDetail_PSD*)getDATA_BUFFER();
   memset(pTC57_TCR3_TxnDetail_PSD, ' ', sizeof(hTC57_TCR3_TxnDetail_PSD));
   memset(pTC57_TCR3_TxnDetail_PSD->sMULTI_CLEAR_SEQ_NO, '0', sizeof(pTC57_TCR3_TxnDetail_PSD->sMULTI_CLEAR_SEQ_NO));
   memset(pTC57_TCR3_TxnDetail_PSD->sMULTI_CLEAR_COUNT, '0', sizeof(pTC57_TCR3_TxnDetail_PSD->sMULTI_CLEAR_COUNT));
   memset(pTC57_TCR3_TxnDetail_PSD->sValidationCode, '0', sizeof(pTC57_TCR3_TxnDetail_PSD->sValidationCode));
   memcpy(pTC57_TCR3_TxnDetail_PSD->sTransCode, "57", sizeof(pTC57_TCR3_TxnDetail_PSD->sTransCode));
   pTC57_TCR3_TxnDetail_PSD->cTransCodeQualifier = '0';
   pTC57_TCR3_TxnDetail_PSD->cTransComponentSeqNumber = '3';
   memcpy(pTC57_TCR3_TxnDetail_PSD->sAuthRespCode, m_hGenericSegment[0].get("ACT_CODE").data(), min(sizeof(pTC57_TCR3_TxnDetail_PSD->sAuthRespCode), m_hGenericSegment[0].get("ACT_CODE").length()));
   if (m_hGenericSegment[0].get("ACT_CODE") == "400"
      || (m_hGenericSegment[0].get("ACT_CODE") > "000" && m_hGenericSegment[0].get("ACT_CODE") < "100"))
      memcpy(pTC57_TCR3_TxnDetail_PSD->sAuthRespCode, "00", 2);

   memcpy(pTC57_TCR3_TxnDetail_PSD->sAuthAmount, m_hGenericSegment[0].get("AMT_RECON_NET").data() + 6, sizeof(pTC57_TCR3_TxnDetail_PSD->sAuthAmount));
   string strCryptogramAmount = m_hGenericSegment[0].get("CRYPTOGRAM_AMOUNT");
   if (!strCryptogramAmount.empty())
      memcpy(pTC57_TCR3_TxnDetail_PSD->sAuthAmount, strCryptogramAmount.data(), sizeof(pTC57_TCR3_TxnDetail_PSD->sAuthAmount));
   memcpy(pTC57_TCR3_TxnDetail_PSD->sTotalAuthAmount, pTC57_TCR3_TxnDetail_PSD->sAuthAmount, sizeof(pTC57_TCR3_TxnDetail_PSD->sTotalAuthAmount));
   memcpy(pTC57_TCR3_TxnDetail_PSD->sTransactionId, m_hGenericSegment[0].get("VISA_TRANSACTION_ID").data(), m_hGenericSegment[0].get("VISA_TRANSACTION_ID").length());
   memcpy(pTC57_TCR3_TxnDetail_PSD->sCUR_RECON_NET, m_hGenericSegment[0].get("CUR_RECON_NET").data(), m_hGenericSegment[0].get("CUR_RECON_NET").length());
   memcpy(pTC57_TCR3_TxnDetail_PSD->sMULTI_CLEAR_SEQ_NO, m_hGenericSegment[0].get("MULTI_CLEAR_SEQ_NO").data(), m_hGenericSegment[0].get("MULTI_CLEAR_SEQ_NO").length());
   memcpy(pTC57_TCR3_TxnDetail_PSD->sMULTI_CLEAR_COUNT, m_hGenericSegment[0].get("MULTI_CLEAR_COUNT").data(), m_hGenericSegment[0].get("MULTI_CLEAR_COUNT").length());

   if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "A")
   {
      pTC57_TCR3_TxnDetail_PSD->cCVV2ResultCode = m_hGenericSegment[0].get("CAVV_RESULT")[0];
      string strMerchVerVal = m_hGenericSegment[0].get("{DFA3|");
      memcpy(pTC57_TCR3_TxnDetail_PSD->sMerchVerVal, strMerchVerVal.data(), strMerchVerVal.length());

      if (!memcmp(m_szADL_DATA_PRIV_ACQ, "VE", 2))
      {
         visabaseii::segADL_DATA_PRIV_ACQ* pADL_DATA_PRIV_ACQ;
         pADL_DATA_PRIV_ACQ = (struct visabaseii::segADL_DATA_PRIV_ACQ*)m_szADL_DATA_PRIV_ACQ;
         pTC57_TCR3_TxnDetail_PSD->cMarketSpecificAuthDataId = pADL_DATA_PRIV_ACQ->cMARKET_FLAG;
         if (strMerchVerVal.empty())
            memcpy(pTC57_TCR3_TxnDetail_PSD->sMerchVerVal, pADL_DATA_PRIV_ACQ->sMERCH_VERIFY_VALUE, sizeof(pTC57_TCR3_TxnDetail_PSD->sMerchVerVal));

         pTC57_TCR3_TxnDetail_PSD->cSpendQualInd = pADL_DATA_PRIV_ACQ->cSpendQualifiedIndicator;
      }
      if (m_hGenericSegment[0].get("REF_DATA_ISS_FMT") == "4")
      {
         visabaseii::segREF_DATA_ISS_EVES* pREF_DATA_ISS_baseii = (struct visabaseii::segREF_DATA_ISS_EVES*)m_szREF_DATA_ISS;
         memcpy(pTC57_TCR3_TxnDetail_PSD->sCardLevelResults, pREF_DATA_ISS_baseii->sPRODUCT_ID, sizeof(pTC57_TCR3_TxnDetail_PSD->sCardLevelResults));
      }
      if (memcmp(m_szREF_DATA_ISS + 59, "    ", 4))
         memcpy(pTC57_TCR3_TxnDetail_PSD->sValidationCode, m_szREF_DATA_ISS + 59, sizeof(pTC57_TCR3_TxnDetail_PSD->sValidationCode));
   }
   else if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "G")
   {
      visasms::segREF_DATA_ISS* pREF_DATA_ISS;
      pREF_DATA_ISS = (struct visasms::segREF_DATA_ISS*)m_szREF_DATA_ISS;
      mastercardipmmessageprocessor::hADL_RESP_DATA* pADL_RESP_DATA;
      pADL_RESP_DATA = (struct mastercardipmmessageprocessor::hADL_RESP_DATA*)m_szADL_RESP_DATA;
      if (memcmp(pREF_DATA_ISS->sValidationCode, "    ", sizeof(pREF_DATA_ISS->sValidationCode)))
         memcpy(pTC57_TCR3_TxnDetail_PSD->sValidationCode, pREF_DATA_ISS->sValidationCode, sizeof(pTC57_TCR3_TxnDetail_PSD->sValidationCode));
      pTC57_TCR3_TxnDetail_PSD->cMarketSpecificAuthDataId = pADL_RESP_DATA->cMktSpecificDataId;
      memcpy(pTC57_TCR3_TxnDetail_PSD->sCardLevelResults, pREF_DATA_ISS->sPRODUCT_ID, sizeof(pTC57_TCR3_TxnDetail_PSD->sCardLevelResults));
      pTC57_TCR3_TxnDetail_PSD->cCVV2ResultCode = m_hGenericSegment[0].get("CAVV_RESULT")[0];
      memcpy(pTC57_TCR3_TxnDetail_PSD->sMerchVerVal, pADL_RESP_DATA->sMerchVerificationValue, sizeof(pTC57_TCR3_TxnDetail_PSD->sMerchVerVal));
      pTC57_TCR3_TxnDetail_PSD->cSpendQualInd = pADL_RESP_DATA->cSpendQualifiedIndicator;
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
         memcpy(pTC57_TCR3_TxnDetail_PSD->sValidationCode, pREF_DATA_ISS->sValidationCode, sizeof(pTC57_TCR3_TxnDetail_PSD->sValidationCode));
      pTC57_TCR3_TxnDetail_PSD->cMarketSpecificAuthDataId = pADL_RESP_DATA->cACIInd;
      pTC57_TCR3_TxnDetail_PSD->cCVV2ResultCode = m_hGenericSegment[0].get("CVV2_CVC2_RESULT")[0];
      memcpy(pTC57_TCR3_TxnDetail_PSD->sECommerceGoodsInd, pADL_DATA_PRIV_ACQ->sElectronicCommerceGoodsInd, sizeof(pTC57_TCR3_TxnDetail_PSD->sECommerceGoodsInd));
   }
   pTC57_TCR3_TxnDetail_PSD->cRecordType = '2';
   char szTemp[PERCENTD + PERCENTHD];
   snprintf(szTemp, sizeof(szTemp), "%08d%05hd", m_iBatchNo, m_siIntrMerchBatchKey);
   memcpy(pTC57_TCR3_TxnDetail_PSD->sInternalMerchBatchKey, szTemp, sizeof(pTC57_TCR3_TxnDetail_PSD->sInternalMerchBatchKey));
   return (write(strCryptogramAmount.empty() ? sizeof(hTC57_TCR3_TxnDetail_PSD) : offsetof(hTC57_TCR3_TxnDetail_PSD, sMerchVolInd), hFlatFile));
  //## end report::ISTTC57TransactionFile::write_TCR3_TxnDetail_PaymentServiceData%6809C3C000E4.body
}

bool ISTTC57TransactionFile::write_TCR3_PassangerTravelLegRecord (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR3_PassangerTravelLegRecord%6809C3C000E6.body preserve=yes
   return true;
  //## end report::ISTTC57TransactionFile::write_TCR3_PassangerTravelLegRecord%6809C3C000E6.body
}

bool ISTTC57TransactionFile::write_TCR99_Coles (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR99_Coles%6809C3C000E8.body preserve=yes
   char szTemp[PERCENTD + PERCENTHD];
   m_iNoOfTcrs++;
   m_iTotNoOfTcrs++;
   m_siIntrMerchBatchKey++;
   struct hTC57_TCR99_Coles* pTC57_TCR99_Coles = (struct hTC57_TCR99_Coles*)getDATA_BUFFER();
   memset(pTC57_TCR99_Coles, ' ', sizeof(hTC57_TCR99_Coles));
   memcpy(pTC57_TCR99_Coles->sTransCode, "57", 2);
   pTC57_TCR99_Coles->cTransCodeQualifier = '9';
   memcpy(pTC57_TCR99_Coles->sTransComponentSeqNumber, "9B1", 3);
   memcpy(pTC57_TCR99_Coles->sMaskedPan, m_hGenericSegment[0].get("MASKPAN").data(), m_hGenericSegment[0].get("MASKPAN").length());
   memcpy(pTC57_TCR99_Coles->sTermClass, m_hGenericSegment[0].get("TERM_CLASS").data(), m_hGenericSegment[0].get("TERM_CLASS").length());
   memcpy(pTC57_TCR99_Coles->sCardProduct, m_hGenericSegment[0].get("CARD_PRODUCT").data(), m_hGenericSegment[0].get("CARD_PRODUCT").length());
   memcpy(pTC57_TCR99_Coles->sTRID, m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").data(), min(size_t(11), m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").length()));
   if (m_hGenericSegment[0].get("TRAN_STATE") == "100")
      memcpy(pTC57_TCR99_Coles->sRespCode, "Z9", 2);
   else if (m_hGenericSegment[0].get("ACT_CODE") == "400" || m_hGenericSegment[0].get("ACT_CODE").substr(0, 2) == "00")
      memcpy(pTC57_TCR99_Coles->sRespCode, "00", 2);
   else
      memcpy(pTC57_TCR99_Coles->sRespCode, m_hGenericSegment[0].get("EXT_RSP_CODE").data(), m_hGenericSegment[0].get("EXT_RSP_CODE").length());
   memcpy(pTC57_TCR99_Coles->sAcqMerchantBrand, m_hGenericSegment[0].get("INST_ID_RECN_ACQ_B").data(), m_hGenericSegment[0].get("INST_ID_RECN_ACQ_B").length());
   memcpy(pTC57_TCR99_Coles->sProcessingType, m_hGenericSegment[0].get("TRAN_TYPE_ID").substr(0, 2).data(), 2);
   memcpy(pTC57_TCR99_Coles->sTranNumber, m_hGenericSegment[0].get("TRAN_NUMBER").data(), m_hGenericSegment[0].get("TRAN_NUMBER").length());
   string strToValue;
   if (m_hGenericSegment[0].get("{MP_WALLET|").length() > 0)
      getGenericValue("TC57_WALLET_IND", m_hGenericSegment[0].get("{MP_WALLET|"), strToValue);
   else
      getGenericValue("TC57_WALLET_IND", m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID"), strToValue);
   pTC57_TCR99_Coles->cWalletInd = strToValue[0];
   memcpy(pTC57_TCR99_Coles->sMappedDupData, m_hGenericSegment[0].get("MAPPED_DUP_DATA").data(), m_hGenericSegment[0].get("MAPPED_DUP_DATA").length());
   memcpy(pTC57_TCR99_Coles->sHashPan1, m_hGenericSegment[0].get("HASH_PAN1").data(), m_hGenericSegment[0].get("HASH_PAN1").length());
   memcpy(pTC57_TCR99_Coles->sHashPan2, m_hGenericSegment[0].get("HASH_PAN2").data(), m_hGenericSegment[0].get("HASH_PAN2").length());
   memcpy(pTC57_TCR99_Coles->sDATE_RECON_ACQ, m_hGenericSegment[0].get("DATE_ACTION").data(), min(sizeof(pTC57_TCR99_Coles->sDATE_RECON_ACQ), m_hGenericSegment[0].get("DATE_ACTION").length()));
   memcpy(pTC57_TCR99_Coles->sDATE_RECON_ISS, m_hGenericSegment[0].get("DATE_RECON_ISS").data(), min(sizeof(pTC57_TCR99_Coles->sDATE_RECON_ISS), m_hGenericSegment[0].get("DATE_RECON_ISS").length()));
   if (m_hGenericSegment[0].get("{EFC|").length() > 0)
   {
      string strISFCCode(m_hGenericSegment[0].get("{EFC|").substr(0, 8));
      strISFCCode.append(m_hGenericSegment[0].get("TRAN_TYPE_ID").substr(0, 2));
      strISFCCode.append("0");
      strISFCCode.append(m_hGenericSegment[0].get("TRAN_DISPOSITION"));
      memcpy(pTC57_TCR99_Coles->sISFCCode, strISFCCode.data(), strISFCCode.length());
   }
   snprintf(szTemp, sizeof(szTemp), "%08d%05hd", m_iBatchNo, m_siIntrMerchBatchKey);
   memcpy(pTC57_TCR99_Coles->sInternalMerchBatchKey, szTemp, 13);
   pTC57_TCR99_Coles->cRecordType = '2';
   return (write(sizeof(hTC57_TCR99_Coles), hFlatFile));
  //## end report::ISTTC57TransactionFile::write_TCR99_Coles%6809C3C000E8.body
}

bool ISTTC57TransactionFile::write_TCR99_CustomRecord (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR99_CustomRecord%6809C3C000EA.body preserve=yes
   m_iNoOfTcrs++;
   m_iTotNoOfTcrs++;
   m_siIntrMerchBatchKey++;
   string strToValue;
   struct hTC57_TCR99_CustomRecord* pTC57_TCR99_CustomRecord = (struct hTC57_TCR99_CustomRecord*)getDATA_BUFFER();
   memset(pTC57_TCR99_CustomRecord, ' ', sizeof(hTC57_TCR99_CustomRecord));
   memcpy(pTC57_TCR99_CustomRecord->sTransCode, "57", sizeof(pTC57_TCR99_CustomRecord->sTransCode));
   pTC57_TCR99_CustomRecord->cTransCodeQualifier = '9';
   memcpy(pTC57_TCR99_CustomRecord->sTransComponentSeqNumber, "9B1", sizeof(pTC57_TCR99_CustomRecord->sTransComponentSeqNumber));
   memcpy(pTC57_TCR99_CustomRecord->sMaskedPan, m_hGenericSegment[0].get("MASKPAN").data(), m_hGenericSegment[0].get("MASKPAN").length());
   memcpy(pTC57_TCR99_CustomRecord->sTERM_CLASS, m_hGenericSegment[0].get("TERM_CLASS").data(), m_hGenericSegment[0].get("TERM_CLASS").length());
   memcpy(pTC57_TCR99_CustomRecord->sProcessingType, m_hGenericSegment[0].get("TRAN_TYPE_ID").data(), sizeof(pTC57_TCR99_CustomRecord->sProcessingType));
   memcpy(pTC57_TCR99_CustomRecord->sACT_CODE, m_hGenericSegment[0].get("ACT_CODE").data(), min(sizeof(pTC57_TCR99_CustomRecord->sACT_CODE), m_hGenericSegment[0].get("ACT_CODE").length()));
   if (m_hGenericSegment[0].get("ACT_CODE") == "400"
      || (m_hGenericSegment[0].get("ACT_CODE") > "000" && m_hGenericSegment[0].get("ACT_CODE") < "100"))
      memcpy(pTC57_TCR99_CustomRecord->sACT_CODE, "000", sizeof(pTC57_TCR99_CustomRecord->sACT_CODE));
   if (Extract::instance()->getCustomCode() == "CBA")
      memcpy(pTC57_TCR99_CustomRecord->sWLT_ID, m_hGenericSegment[0].get("TOKEN_WALLET_ID").data(), min(sizeof(pTC57_TCR99_CustomRecord->sWLT_ID), m_hGenericSegment[0].get("TOKEN_WALLET_ID").length()));
   else
      memcpy(pTC57_TCR99_CustomRecord->sWLT_ID, m_hGenericSegment[0].get("WLT_ID").data(), min(sizeof(pTC57_TCR99_CustomRecord->sWLT_ID), m_hGenericSegment[0].get("WLT_ID").length()));
   memset(pTC57_TCR99_CustomRecord->sTxnIndustryApplInfo, '0', sizeof(pTC57_TCR99_CustomRecord->sTxnIndustryApplInfo));
   string strChannel;
   if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "A")
   {
      if (Extract::instance()->getCustomCode() == "CBA"
         && ConfigurationRepository::instance()->mapItem("X_INST_ID_RECON", m_hGenericSegment[0].get("INST_ID_RECON_ACQ"), "", "A", strChannel))
      {
         if (strChannel == "CBACNP")
            pTC57_TCR99_CustomRecord->cChannelInd = '4';
         else if (strChannel == "CBASSE")
            pTC57_TCR99_CustomRecord->cChannelInd = '2';
      }
      else
         if (m_hGenericSegment[0].get("DATA_PRIV_ACQ_FMT") == "30")
            pTC57_TCR99_CustomRecord->cChannelInd = '3';
         else
         {
            pTC57_TCR99_CustomRecord->cChannelInd = '1';
            if (getGenericValue("TC57_UN_ATTEND", m_hGenericSegment[0].get("TERM_CLASS"), strToValue))
               pTC57_TCR99_CustomRecord->cChannelInd = strToValue[0];//2- unattended Terminal
         }
      string strTemp(m_hGenericSegment[0].get("ADL_DATA_NATIONAL"));
      string strISFCCode;
      if (Extract::instance()->getCustomCode() == "CBA")
         strISFCCode.append(m_hGenericSegment[0].get("ISFC_CODE"));
      else
      {
         size_t nPosBegin = 0, nPosEnd = 0;
         if ((nPosBegin = strTemp.rfind("EFC")) != string::npos
            && (nPosEnd = strTemp.find("\\", nPosBegin)) != string::npos
            && nPosEnd - nPosBegin == 11)
            strISFCCode.assign(strTemp.data() + nPosBegin + 3, 8);
      }
      strISFCCode.append(m_hGenericSegment[0].get("TRAN_TYPE_ID").data(), 2);
      strISFCCode += '0';
      strISFCCode += m_hGenericSegment[0].get("TRAN_DISPOSITION");
      if (strISFCCode.length() == 12)
         memcpy(pTC57_TCR99_CustomRecord->sIsfcCode, strISFCCode.data(), 12);

      pTC57_TCR99_CustomRecord->cChargeType = 'X';
      string strCredOnFile = m_hGenericSegment[0].get("{DF08|");
      string strTxnSrcId = m_hGenericSegment[0].get("{DFA9|");
      string strPOS_CRDHLDR_A_METH = m_hGenericSegment[0].get("POS_CRDHLDR_A_METH");
      if (strPOS_CRDHLDR_A_METH == "7" || strPOS_CRDHLDR_A_METH == "8")
         pTC57_TCR99_CustomRecord->cChargeType = '0';
      else if (strPOS_CRDHLDR_A_METH == "6" || strPOS_CRDHLDR_A_METH == "9")
         pTC57_TCR99_CustomRecord->cChargeType = '3';
      if (!m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").empty()
         && pTC57_TCR99_CustomRecord->cChargeType == '0')
         pTC57_TCR99_CustomRecord->cChargeType = '4';
      else if (!m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").empty()
         && pTC57_TCR99_CustomRecord->cChargeType == '3')
         pTC57_TCR99_CustomRecord->cChargeType = '5';
      if (strTxnSrcId == "01")
         pTC57_TCR99_CustomRecord->cChargeType = '2';

      memcpy(pTC57_TCR99_CustomRecord->sTxnIndustryApplInfo, strTxnSrcId.data(), strTxnSrcId.length());
      memcpy(pTC57_TCR99_CustomRecord->sOrigIssStan, m_hGenericSegment[0].get("{DF0B|").data(), m_hGenericSegment[0].get("{DF0B|").length());
      memcpy(pTC57_TCR99_CustomRecord->sOrigIssRRN, m_hGenericSegment[0].get("{DF0C|").data(), m_hGenericSegment[0].get("{DF0C|").length());
      memcpy(pTC57_TCR99_CustomRecord->sOrigAuthSettDate, m_hGenericSegment[0].get("{DF07|").data(), m_hGenericSegment[0].get("{DF07|").length());
      memcpy(pTC57_TCR99_CustomRecord->sCOFInd, strCredOnFile.data(), strCredOnFile.length());
      memcpy(pTC57_TCR99_CustomRecord->sAltPymtMeth, m_hGenericSegment[0].get("{DFA1|").data(), m_hGenericSegment[0].get("{DFA1|").length());
   }
   else if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "T")
      pTC57_TCR99_CustomRecord->cChannelInd = '4';
   else if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "G")
      pTC57_TCR99_CustomRecord->cChannelInd = '3';
   if (Extract::instance()->getCustomCode() == "CBA")
   {
      pTC57_TCR99_CustomRecord->cLCRIndicator = (m_hGenericSegment[0].get("ADL_DATA_NATIONAL").find("\\MCR\\") != string::npos) ? '1' : '0';
      if (m_hGenericSegment[0].get("INST_ID_RECN_ISS_B") == "EFNCS" &&
         ConfigurationRepository::instance()->mapItem("X_INST_ID_RECON", m_hGenericSegment[0].get("BRANCH_ID_ACQ"), "", "A", strChannel)
         && strChannel == "EFNMPGS")
         pTC57_TCR99_CustomRecord->cChannelInd = '3';
      memcpy(pTC57_TCR99_CustomRecord->sDATE_RECON_ACQ, m_hGenericSegment[0].get("DATE_ACTION").data(), min(sizeof(pTC57_TCR99_CustomRecord->sDATE_RECON_ACQ), m_hGenericSegment[0].get("DATE_ACTION").length()));
   }
   else
      memcpy(pTC57_TCR99_CustomRecord->sDATE_RECON_ACQ, m_hGenericSegment[0].get("DATE_RECON_ACQ").data(), min(sizeof(pTC57_TCR99_CustomRecord->sDATE_RECON_ACQ), m_hGenericSegment[0].get("DATE_RECON_ACQ").length()));
   memcpy(pTC57_TCR99_CustomRecord->sDATE_RECON_ISS, m_hGenericSegment[0].get("DATE_RECON_ISS").data(), min(sizeof(pTC57_TCR99_CustomRecord->sDATE_RECON_ISS), m_hGenericSegment[0].get("DATE_RECON_ISS").length()));
   pTC57_TCR99_CustomRecord->cLCRIndicator = ' ';
   memcpy(pTC57_TCR99_CustomRecord->sOriginalUUID, m_hGenericSegment[0].get("TRANSACTION_ID").data(), min(sizeof(pTC57_TCR99_CustomRecord->sOriginalUUID), m_hGenericSegment[0].get("TRANSACTION_ID").length()));
   memcpy(pTC57_TCR99_CustomRecord->sGroupUUID, "                                    ", sizeof(pTC57_TCR99_CustomRecord->sOriginalUUID));
   size_t pos = m_hGenericSegment[0].get("ADL_DATA_NATIONAL").find("\\M3");
   if (pos != string::npos)
   {
      int iLen = atoi(m_hGenericSegment[0].get("ADL_DATA_NATIONAL").substr(pos + 3, 2).data());
      if (iLen && m_hGenericSegment[0].get("ADL_DATA_NATIONAL").length() >= (pos + 5 + iLen))
         memcpy(pTC57_TCR99_CustomRecord->sMerchantWebsiteURL, m_hGenericSegment[0].get("ADL_DATA_NATIONAL").data() + pos + 5, iLen);
   }
   pTC57_TCR99_CustomRecord->cOnUsBinIND = m_hGenericSegment[0].get("ONUS_IND")[0];
   if (Extract::instance()->getCustomCode() == "PAAS")
   {
      memcpy(pTC57_TCR99_CustomRecord->sFraudSubClassCode, m_hGenericSegment[0].get("SEG24_322^FCC^^^\\\\").data(), min(sizeof(pTC57_TCR99_CustomRecord->sFraudSubClassCode), m_hGenericSegment[0].get("SEG24_322^FCC^^^\\\\").length()));
      memcpy(pTC57_TCR99_CustomRecord->sTransactionAcceptMethod, m_hGenericSegment[0].get("SEG24_322^TAM^^^\\\\").data(), min(sizeof(pTC57_TCR99_CustomRecord->sTransactionAcceptMethod), m_hGenericSegment[0].get("SEG24_322^TAM^^^\\\\").length()));
      if (m_hGenericSegment[0].get("AS2805_CAV").length() > 3)
         memcpy(pTC57_TCR99_CustomRecord->sCardholderAuthValue, m_hGenericSegment[0].get("AS2805_CAV").data() + 3, min(sizeof(pTC57_TCR99_CustomRecord->sCardholderAuthValue), m_hGenericSegment[0].get("AS2805_CAV").length() - 3));
      memcpy(pTC57_TCR99_CustomRecord->sEMV_3D_TRAN_ID, m_hGenericSegment[0].get("EMV_3D_TRAN_ID").data(), min(sizeof(pTC57_TCR99_CustomRecord->sEMV_3D_TRAN_ID), m_hGenericSegment[0].get("EMV_3D_TRAN_ID").length()));
   }
   return (write(sizeof(hTC57_TCR99_CustomRecord), hFlatFile));
  //## end report::ISTTC57TransactionFile::write_TCR99_CustomRecord%6809C3C000EA.body
}

bool ISTTC57TransactionFile::write_TCR2_AmexCAPNBatchHeader (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR2_AmexCAPNBatchHeader%6809C3C000EC.body preserve=yes
   if (m_hGenericSegment[0].get("NET_ID_ISS") == "AMX" || m_hGenericSegment[0].get("NET_ID_ISS") == "JCB")
   {
      m_iNoOfTcrs++;
      m_iTotNoOfTcrs++;
      m_iTotNoOfTxns++;
      m_siIntrMerchBatchKey++;
      struct hTC57_TCR2_AmexCAPNBatchHeader* pTC57_TCR2_AmexCAPNBatchHeader = (struct hTC57_TCR2_AmexCAPNBatchHeader*)getDATA_BUFFER();
      memset(pTC57_TCR2_AmexCAPNBatchHeader, ' ', sizeof(hTC57_TCR2_AmexCAPNBatchHeader));
      memcpy(pTC57_TCR2_AmexCAPNBatchHeader->sTransCode, "57", sizeof(pTC57_TCR2_AmexCAPNBatchHeader->sTransCode));
      pTC57_TCR2_AmexCAPNBatchHeader->cTransCodeQualifier = '0';
      pTC57_TCR2_AmexCAPNBatchHeader->cTransComponentSeqNumber = '2';
      memcpy(pTC57_TCR2_AmexCAPNBatchHeader->sCARD_ACPT_ID, m_hGenericSegment[0].get("AMEX_SE_NUMBER").data(), m_hGenericSegment[0].get("AMEX_SE_NUMBER").length());
      pTC57_TCR2_AmexCAPNBatchHeader->cRecordType = '1';
      pTC57_TCR2_AmexCAPNBatchHeader->cCAPNIndicator = 'C';

      return (write(sizeof(hTC57_TCR2_AmexCAPNBatchHeader), hFlatFile));
   }
   return true;
  //## end report::ISTTC57TransactionFile::write_TCR2_AmexCAPNBatchHeader%6809C3C000EC.body
}

bool ISTTC57TransactionFile::write_TCR1_AmexTxnDetailAdviceBasic (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR1_AmexTxnDetailAdviceBasic%6809C3C000EE.body preserve=yes
   m_iNoOfTcrs++;
   m_iTotNoOfTcrs++;
   m_siIntrMerchBatchKey++;
   char szTemp[PERCENTD + PERCENTHD];
   struct hTC57_TCR1_AmexTxnDetailAdviceBasic* pTC57_TCR1_AmexTxnDetailAdviceBasic = (struct hTC57_TCR1_AmexTxnDetailAdviceBasic*)getDATA_BUFFER();
   memset(pTC57_TCR1_AmexTxnDetailAdviceBasic, ' ', sizeof(hTC57_TCR1_AmexTxnDetailAdviceBasic));
   memcpy(pTC57_TCR1_AmexTxnDetailAdviceBasic->sTransCode, "57", sizeof(pTC57_TCR1_AmexTxnDetailAdviceBasic->sTransCode));
   pTC57_TCR1_AmexTxnDetailAdviceBasic->cTransCodeQualifier = '0';
   pTC57_TCR1_AmexTxnDetailAdviceBasic->cTransComponentSeqNumber = '1';
   memcpy(pTC57_TCR1_AmexTxnDetailAdviceBasic->sFormatCode, "02", sizeof(pTC57_TCR1_AmexTxnDetailAdviceBasic->sFormatCode));
   memcpy(pTC57_TCR1_AmexTxnDetailAdviceBasic->sExtendedPaymentData, "01", sizeof(pTC57_TCR1_AmexTxnDetailAdviceBasic->sExtendedPaymentData));
   memcpy(pTC57_TCR1_AmexTxnDetailAdviceBasic->sDATE_EXP, m_hGenericSegment[0].get("DATE_EXP").data(), m_hGenericSegment[0].get("DATE_EXP").length());

   if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "A")
   {
      memcpy(pTC57_TCR1_AmexTxnDetailAdviceBasic->sTransactionIdentifier, m_szREF_DATA_ISS + 32, sizeof(pTC57_TCR1_AmexTxnDetailAdviceBasic->sTransactionIdentifier));
      if (m_bAdvRevTran)
      {
         string strToValue;
         if (Extract::instance()->getCustomCode() == "CBA")
         {
            pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataInputCap = m_szREF_DATA_ISS[80];
            pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthCap = m_szREF_DATA_ISS[81];
            pTC57_TCR1_AmexTxnDetailAdviceBasic->cPOS_CARD_CAPT_CAP = m_szREF_DATA_ISS[82];
            pTC57_TCR1_AmexTxnDetailAdviceBasic->cTerminalOperEnv = m_szREF_DATA_ISS[83];
            pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderPresentData = m_szREF_DATA_ISS[84];
            pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardPresentData = m_szREF_DATA_ISS[85];
            pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataInputMode = m_szREF_DATA_ISS[86];
            pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthMeth = m_szREF_DATA_ISS[87];
            pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthEntity = m_szREF_DATA_ISS[88];
            pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataOutCap = m_szREF_DATA_ISS[89];
            pTC57_TCR1_AmexTxnDetailAdviceBasic->cPOS_TERM_OUT_CAP = m_szREF_DATA_ISS[90];
            pTC57_TCR1_AmexTxnDetailAdviceBasic->cPINCaptureCap = m_szREF_DATA_ISS[91];
         }
         else
         {
            if (getGenericValue("TC57_AMX_IN_CAP", m_hGenericSegment[0].get("POS_CRD_DAT_IN_CAP"), strToValue))
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataInputCap = strToValue[0];
            else
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataInputCap = '0';

            if (getGenericValue("TC57_AMX_AUTH_C", m_hGenericSegment[0].get("POS_CRDHLDR_AUTH_C"), strToValue))
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthCap = strToValue[0];
            else if (atoi(m_hGenericSegment[0].get("PIN_DATA_FMT").data()) > -1)
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthCap = '1';
            else
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthCap = '0';

            if (m_hGenericSegment[0].get("POS_CARD_CAPT_CAP")[0] == '1')
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cPOS_CARD_CAPT_CAP = '1';
            else
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cPOS_CARD_CAPT_CAP = '0';

            if (getGenericValue("TC57_AMX_OP_ENV", m_hGenericSegment[0].get("POS_OPER_ENV"), strToValue))
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cTerminalOperEnv = strToValue[0];
            else
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cTerminalOperEnv = '0';

            if (getGenericValue("TC57_AMX_CH_PT", m_hGenericSegment[0].get("POS_CRDHLDR_PRESNT"), strToValue)
               || getGenericValue("TC57_AMX_CH_PT", m_hGenericSegment[0].get("TERM_CLASS"), strToValue))
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderPresentData = strToValue[0];
            else
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderPresentData = '1';

            if (m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD")[0] == 'M'
               && m_hGenericSegment[0].get("POS_CRDHLDR_AUTH_C")[0] == 'W')
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardPresentData = 'X';
            else if (getGenericValue("TC57_AMX_CRD_PT", m_hGenericSegment[0].get("POS_CARD_PRES"), strToValue)
               || getGenericValue("TC57_AMX_CRD_PT", m_hGenericSegment[0].get("POS_CRDHLDR_AUTH_C"), strToValue))
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardPresentData = strToValue[0];
            else
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardPresentData = '0';

            if (getGenericValue("TC57_AMX_IN_MOD", m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD"), strToValue))
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataInputMode = strToValue[0];
            else if (!m_hGenericSegment[0].get("CVV2_CVC2_RESULT").empty())
            {
               if (m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD")[0] == '1'
                  || m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD")[0] == '6')
                  pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataInputMode = 'S';
               else if (m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD")[0] == '2')
                  pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataInputMode = 'S';
            }
            else
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataInputMode = '0';

            if (atoi(m_hGenericSegment[0].get("PIN_DATA_FMT").data()) > -1)
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthMeth = '1';
            else
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthMeth = '0';

            if (getGenericValue("TC57_AMX_CH_ENT", m_hGenericSegment[0].get("POS_CRDHLDR_AUTH"), strToValue))
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthEntity = strToValue[0];
            else if (atoi(m_hGenericSegment[0].get("PIN_DATA_FMT").data()) > -1)
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthEntity = '5';
            else
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthEntity = '0';

            if (m_hGenericSegment[0].get("POS_CRD_DAT_OT_CAP")[0] == '1')
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataOutCap = '1';
            else
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataOutCap = '0';

            if (getGenericValue("TC57_AMX_OT_CAP", m_hGenericSegment[0].get("POS_TERM_OUT_CAP"), strToValue))
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cPOS_TERM_OUT_CAP = strToValue[0];
            else
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cPOS_TERM_OUT_CAP = '0';

            if (m_hGenericSegment[0].get("POS_PIN_CAPT_CAP")[0] == '0')
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cPINCaptureCap = '0';
            else
               pTC57_TCR1_AmexTxnDetailAdviceBasic->cPINCaptureCap = '1';
         }
      }
      else
      {
         pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataInputCap = m_szDATA_PRIV_ISS[4];
         pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthCap = m_szDATA_PRIV_ISS[5];
         pTC57_TCR1_AmexTxnDetailAdviceBasic->cPOS_CARD_CAPT_CAP = m_szDATA_PRIV_ISS[6];
         pTC57_TCR1_AmexTxnDetailAdviceBasic->cTerminalOperEnv = m_szDATA_PRIV_ISS[7];
         pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderPresentData = m_szDATA_PRIV_ISS[8];
         pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardPresentData = m_szDATA_PRIV_ISS[9];
         pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataInputMode = m_szDATA_PRIV_ISS[10];
         pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthMeth = m_szDATA_PRIV_ISS[11];
         pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthEntity = m_szDATA_PRIV_ISS[12];
         pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataOutCap = m_szDATA_PRIV_ISS[13];
         pTC57_TCR1_AmexTxnDetailAdviceBasic->cPOS_TERM_OUT_CAP = m_szDATA_PRIV_ISS[14];
         pTC57_TCR1_AmexTxnDetailAdviceBasic->cPINCaptureCap = m_szDATA_PRIV_ISS[15];
      }
   }
   else
   {
      string strToValue;
      getGenericValue("TC57_AMX_IN_CAP", m_hGenericSegment[0].get("POS_CRD_DAT_IN_CAP"), strToValue);
      pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataInputCap = strToValue[0];
      getGenericValue("TC57_AMX_AUTH_C", m_hGenericSegment[0].get("POS_CRDHLDR_AUTH_C"), strToValue);
      pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthCap = strToValue[0];
      pTC57_TCR1_AmexTxnDetailAdviceBasic->cPOS_CARD_CAPT_CAP = m_hGenericSegment[0].get("POS_CARD_CAPT_CAP")[0];
      getGenericValue("TC57_AMX_OP_ENV", m_hGenericSegment[0].get("POS_OPER_ENV"), strToValue);
      pTC57_TCR1_AmexTxnDetailAdviceBasic->cTerminalOperEnv = strToValue[0];
      getGenericValue("TC57_AMX_CH_PT", m_hGenericSegment[0].get("POS_CRDHLDR_PRESNT"), strToValue);
      pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderPresentData = strToValue[0];
      getGenericValue("TC57_AMX_CRD_PT", m_hGenericSegment[0].get("POS_CARD_PRES"), strToValue);
      pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardPresentData = strToValue[0];
      getGenericValue("TC57_AMX_IN_MOD", m_hGenericSegment[0].get("POS_CRD_DAT_IN_MOD"), strToValue);
      pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataInputMode = strToValue[0];
      getGenericValue("TC57_AMX_A_METH", m_hGenericSegment[0].get("POS_CRDHLDR_A_METH"), strToValue);
      pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthMeth = strToValue[0];
      getGenericValue("TC57_AMX_CH_ENT", m_hGenericSegment[0].get("POS_CRDHLDR_AUTH"), strToValue);
      pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardholderAuthEntity = strToValue[0];
      getGenericValue("TC57_AMX_OT_CAP", m_hGenericSegment[0].get("POS_CRD_DAT_OT_CAP"), strToValue);
      pTC57_TCR1_AmexTxnDetailAdviceBasic->cCardDataOutCap = strToValue[0];
      pTC57_TCR1_AmexTxnDetailAdviceBasic->cPOS_TERM_OUT_CAP = m_hGenericSegment[0].get("POS_TERM_OUT_CAP")[0];
      getGenericValue("TC57_AMX_PN_CAP", m_hGenericSegment[0].get("POS_PIN_CAPT_CAP"), strToValue);
      pTC57_TCR1_AmexTxnDetailAdviceBasic->cPINCaptureCap = strToValue[0];
   }

   memcpy(pTC57_TCR1_AmexTxnDetailAdviceBasic->sCARD_ACPT_ID, m_hGenericSegment[0].get("CARD_ACPT_ID").data(), m_hGenericSegment[0].get("CARD_ACPT_ID").length());

   if (!m_hGenericSegment[0].get("SELLER_PHONE").empty())
      memcpy(pTC57_TCR1_AmexTxnDetailAdviceBasic->sMerchantContactInfo, m_hGenericSegment[0].get("SELLER_PHONE").data(), min(sizeof(pTC57_TCR1_AmexTxnDetailAdviceBasic->sMerchantContactInfo), m_hGenericSegment[0].get("SELLER_PHONE").length()));
   else
      memcpy(pTC57_TCR1_AmexTxnDetailAdviceBasic->sMerchantContactInfo, m_hGenericSegment[0].get("SELLER_EMAIL").data(), min(sizeof(pTC57_TCR1_AmexTxnDetailAdviceBasic->sMerchantContactInfo), m_hGenericSegment[0].get("SELLER_EMAIL").length()));

   memcpy(pTC57_TCR1_AmexTxnDetailAdviceBasic->sRETRIEVAL_REF_NO, m_hGenericSegment[0].get("RETRIEVAL_REF_NO").data(), m_hGenericSegment[0].get("RETRIEVAL_REF_NO").length());
   snprintf(szTemp, sizeof(szTemp), "%08d%05hd", m_iBatchNo, m_siIntrMerchBatchKey);
   memcpy(pTC57_TCR1_AmexTxnDetailAdviceBasic->sInternalMerchBatchKey, szTemp, sizeof(pTC57_TCR1_AmexTxnDetailAdviceBasic->sInternalMerchBatchKey));
   pTC57_TCR1_AmexTxnDetailAdviceBasic->cRecordType = '2';
   pTC57_TCR1_AmexTxnDetailAdviceBasic->cCAPNIndicator = 'C';
   string strChannel;
   ConfigurationRepository::instance()->mapItem("X_INST_ID_RECON", m_hGenericSegment[0].get("INST_ID_RECON_ACQ"), "", "A", strChannel);
   if (memcmp(m_hGenericSegment[0].get("ADL_DATA_NATIONAL").data(), "*3D*\\", 5) == 0
      || (strChannel == "CBASSE" && !m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").empty()))
   {
      if (m_hGenericSegment[0].get("POS_CRDHLDR_A_METH") == "7")
         memcpy(pTC57_TCR1_AmexTxnDetailAdviceBasic->sElectronicCommenceInd, "05", sizeof(pTC57_TCR1_AmexTxnDetailAdviceBasic->sElectronicCommenceInd));
      else if (m_hGenericSegment[0].get("POS_CRDHLDR_A_METH") == "8")
         memcpy(pTC57_TCR1_AmexTxnDetailAdviceBasic->sElectronicCommenceInd, "06", sizeof(pTC57_TCR1_AmexTxnDetailAdviceBasic->sElectronicCommenceInd));
      else if (m_hGenericSegment[0].get("POS_CRDHLDR_A_METH") == "9")
         memcpy(pTC57_TCR1_AmexTxnDetailAdviceBasic->sElectronicCommenceInd, "07", sizeof(pTC57_TCR1_AmexTxnDetailAdviceBasic->sElectronicCommenceInd));
      else if (!m_hGenericSegment[0].get("TOKEN_REQUESTOR_ID").empty())
         memcpy(pTC57_TCR1_AmexTxnDetailAdviceBasic->sElectronicCommenceInd, "20", sizeof(pTC57_TCR1_AmexTxnDetailAdviceBasic->sElectronicCommenceInd));
   }
   pTC57_TCR1_AmexTxnDetailAdviceBasic->cIndModelTypeInd = ' ';
   return (write(sizeof(hTC57_TCR1_AmexTxnDetailAdviceBasic), hFlatFile));
  //## end report::ISTTC57TransactionFile::write_TCR1_AmexTxnDetailAdviceBasic%6809C3C000EE.body
}

bool ISTTC57TransactionFile::write_TCR4_AmexTxnDetailLocation (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR4_AmexTxnDetailLocation%6809C3C000F0.body preserve=yes
   if (m_hGenericSegment[0].get("ACQ_PLAT_PROD_ID") == "A")
   {
      m_iNoOfTcrs++;
      m_iTotNoOfTcrs++;
      m_siIntrMerchBatchKey++;
      struct hTC57_TCR4_AmexTxnDetailLocation* pTC57_TCR4_AmexTxnDetailLocation = (struct hTC57_TCR4_AmexTxnDetailLocation*)getDATA_BUFFER();
      memset(pTC57_TCR4_AmexTxnDetailLocation, ' ', sizeof(hTC57_TCR4_AmexTxnDetailLocation));
      memcpy(pTC57_TCR4_AmexTxnDetailLocation->sTransCode, "57", sizeof(pTC57_TCR4_AmexTxnDetailLocation->sTransCode));
      pTC57_TCR4_AmexTxnDetailLocation->cTransCodeQualifier = '0';
      pTC57_TCR4_AmexTxnDetailLocation->cTransComponentSeqNumber = '4';
      memcpy(pTC57_TCR4_AmexTxnDetailLocation->sFormatCode, "02", sizeof(pTC57_TCR4_AmexTxnDetailLocation->sFormatCode));
      memcpy(pTC57_TCR4_AmexTxnDetailLocation->sAddendaTypeCode, "99", sizeof(pTC57_TCR4_AmexTxnDetailLocation->sAddendaTypeCode));
      char szCardAcptNameLoc[84];
      memset(szCardAcptNameLoc, ' ', sizeof(szCardAcptNameLoc));
      memcpy(szCardAcptNameLoc, m_hGenericSegment[0].get("CARD_ACPT_NAME_LOC").data(), m_hGenericSegment[0].get("CARD_ACPT_NAME_LOC").length());
      string strLocationName("");
      if (Extract::instance()->getCustomCode() == "PAAS")
      {
         if (m_hGenericSegment[0].get("SELLER_ID").length() > 0)
            strLocationName.assign("TILL PAYMENTS*");
      }
      strLocationName.append(szCardAcptNameLoc, 25);

      memcpy(pTC57_TCR4_AmexTxnDetailLocation->sLocationName, strLocationName.data(), min(sizeof(pTC57_TCR4_AmexTxnDetailLocation->sLocationName), strLocationName.length()));

      memcpy(pTC57_TCR4_AmexTxnDetailLocation->sLocationAddress, szCardAcptNameLoc + 26, 28);
      memcpy(pTC57_TCR4_AmexTxnDetailLocation->sLocationCity, szCardAcptNameLoc + 55, sizeof(pTC57_TCR4_AmexTxnDetailLocation->sLocationCity));
      memcpy(pTC57_TCR4_AmexTxnDetailLocation->sCARD_ACPT_REGION, m_hGenericSegment[0].get("CARD_ACPT_REGION").data(), m_hGenericSegment[0].get("CARD_ACPT_REGION").length());
      memcpy(pTC57_TCR4_AmexTxnDetailLocation->sCARD_ACPT_COUNTRY, m_hGenericSegment[0].get("CARD_ACPT_COUNTRY").data(), m_hGenericSegment[0].get("CARD_ACPT_COUNTRY").length());
      memcpy(pTC57_TCR4_AmexTxnDetailLocation->sCARD_ACPT_PST_CODE, m_hGenericSegment[0].get("CARD_ACPT_PST_CODE").data(), m_hGenericSegment[0].get("CARD_ACPT_PST_CODE").length());
      memcpy(pTC57_TCR4_AmexTxnDetailLocation->sMERCH_TYPE, m_hGenericSegment[0].get("MERCH_TYPE").data(), m_hGenericSegment[0].get("MERCH_TYPE").length());
      memcpy(pTC57_TCR4_AmexTxnDetailLocation->sSellerID, m_hGenericSegment[0].get("SELLER_ID").data(), m_hGenericSegment[0].get("SELLER_ID").length());

      return (write(sizeof(hTC57_TCR4_AmexTxnDetailLocation), hFlatFile));
   }
   return true;
  //## end report::ISTTC57TransactionFile::write_TCR4_AmexTxnDetailLocation%6809C3C000F0.body
}

bool ISTTC57TransactionFile::write_TCR3_DinersIntlChipAddtlRecord (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR3_DinersIntlChipAddtlRecord%6809C3C000F2.body preserve=yes
   struct hTC57_TCR3_DinersIntlChipAddtlRecord* pTC57_TCR3_DinersIntlChipAddtlRecord = (struct hTC57_TCR3_DinersIntlChipAddtlRecord*)getDATA_BUFFER();
   memset(pTC57_TCR3_DinersIntlChipAddtlRecord, ' ', sizeof(hTC57_TCR3_DinersIntlChipAddtlRecord));

   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sAPPL_ID, m_hGenericSegment[0].get("APPL_ID").data(), m_hGenericSegment[0].get("APPL_ID").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sAPPL_INTRCHG_PROF, m_hGenericSegment[0].get("APPL_INTRCHG_PROF").data(), m_hGenericSegment[0].get("APPL_INTRCHG_PROF").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sAPPL_TRAN_COUNTER, m_hGenericSegment[0].get("APPL_TRAN_COUNTER").data(), m_hGenericSegment[0].get("APPL_TRAN_COUNTER").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sUNPREDICTABLE_NO, m_hGenericSegment[0].get("UNPREDICTABLE_NO").data(), m_hGenericSegment[0].get("UNPREDICTABLE_NO").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sAPPL_CRYPTOGRAM, m_hGenericSegment[0].get("APPL_CRYPTOGRAM").data(), m_hGenericSegment[0].get("APPL_CRYPTOGRAM").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sCRYPTOGRAM_AMOUNT, m_hGenericSegment[0].get("CRYPTOGRAM_AMOUNT").data(), m_hGenericSegment[0].get("CRYPTOGRAM_AMOUNT").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sAMOUNT_OTHER, m_hGenericSegment[0].get("AMOUNT_OTHER").data(), m_hGenericSegment[0].get("AMOUNT_OTHER").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sCRYPT_INFO_DATA, m_hGenericSegment[0].get("CRYPT_INFO_DATA").data(), m_hGenericSegment[0].get("CRYPT_INFO_DATA").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sCARDH_VER_RESULT, m_hGenericSegment[0].get("CARDH_VER_RESULT").data(), m_hGenericSegment[0].get("CARDH_VER_RESULT").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sDEDICATED_FILE_NAM, m_hGenericSegment[0].get("DEDICATED_FILE_NAM").data(), m_hGenericSegment[0].get("DEDICATED_FILE_NAM").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sTERM_SERIAL_NO, m_hGenericSegment[0].get("TERM_SERIAL_NO").data(), m_hGenericSegment[0].get("TERM_SERIAL_NO").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sISS_APPL_DATA, m_hGenericSegment[0].get("ISS_APPL_DATA").data(), m_hGenericSegment[0].get("ISS_APPL_DATA").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sISS_AUTH_DATA, m_hGenericSegment[0].get("ISS_AUTH_DATA").data(), m_hGenericSegment[0].get("ISS_AUTH_DATA").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sISS_SCRIPT_RESULT, m_hGenericSegment[0].get("ISS_SCRIPT_RESULT").data(), min(size_t(10), m_hGenericSegment[0].get("ISS_SCRIPT_RESULT").length()));
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sTERM_COUNTRY_CODE, m_hGenericSegment[0].get("TERM_COUNTRY_CODE").data(), m_hGenericSegment[0].get("TERM_COUNTRY_CODE").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sAPPL_VERSION_NO, m_hGenericSegment[0].get("APPL_VERSION_NO").data(), m_hGenericSegment[0].get("APPL_VERSION_NO").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sTERM_CAPABILITIES, m_hGenericSegment[0].get("TERM_CAPABILITIES").data(), m_hGenericSegment[0].get("TERM_CAPABILITIES").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sTERMINAL_TYPE, m_hGenericSegment[0].get("TERMINAL_TYPE").data(), m_hGenericSegment[0].get("TERMINAL_TYPE").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sTERM_VERIFY_RESULT, m_hGenericSegment[0].get("TERM_VERIFY_RESULT").data(), m_hGenericSegment[0].get("TERM_VERIFY_RESULT").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sTRAN_DATE, m_hGenericSegment[0].get("TRAN_DATE").data(), m_hGenericSegment[0].get("TRAN_DATE").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sTRAN_TYPE, m_hGenericSegment[0].get("TRAN_TYPE").data(), m_hGenericSegment[0].get("TRAN_TYPE").length());
   memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sTRAN_CURRENCY_CODE, m_hGenericSegment[0].get("TRAN_CURRENCY_CODE").data(), m_hGenericSegment[0].get("TRAN_CURRENCY_CODE").length());
   if (memcmp((char*)pTC57_TCR3_DinersIntlChipAddtlRecord, m_szSpaces, sizeof(hTC57_TCR3_DinersIntlChipAddtlRecord)))
   {
      m_iNoOfTcrs++;
      m_iTotNoOfTcrs++;
      m_siIntrMerchBatchKey++;
      char szTemp[PERCENTD + PERCENTHD];
      memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sTransCode, "57", sizeof(pTC57_TCR3_DinersIntlChipAddtlRecord->sTransCode));
      pTC57_TCR3_DinersIntlChipAddtlRecord->cTransCodeQualifier = '0';
      pTC57_TCR3_DinersIntlChipAddtlRecord->cTransComponentSeqNumber = '3';
      memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sFunctionCode, "XM", sizeof(pTC57_TCR3_DinersIntlChipAddtlRecord->sFunctionCode));
      memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sCARD_SEQ_NO, m_hGenericSegment[0].get("CARD_SEQ_NO").data(), m_hGenericSegment[0].get("CARD_SEQ_NO").length());
      snprintf(szTemp, sizeof(szTemp), "%03d", m_iBatchNo);
      memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sBatchNumber, szTemp, sizeof(pTC57_TCR3_DinersIntlChipAddtlRecord->sBatchNumber));
      snprintf(szTemp, sizeof(szTemp), "%03d", m_siIntrMerchBatchKey);
      memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sSeqNoWithInBatch, szTemp, sizeof(pTC57_TCR3_DinersIntlChipAddtlRecord->sSeqNoWithInBatch));
      memcpy(pTC57_TCR3_DinersIntlChipAddtlRecord->sSubSeqNoWithInCharge, "001", sizeof(pTC57_TCR3_DinersIntlChipAddtlRecord->sSubSeqNoWithInCharge));
      return (write(sizeof(hTC57_TCR3_DinersIntlChipAddtlRecord), hFlatFile));
   }
   return false;
  //## end report::ISTTC57TransactionFile::write_TCR3_DinersIntlChipAddtlRecord%6809C3C000F2.body
}

bool ISTTC57TransactionFile::write_TCR0_BatchTrailer (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR0_BatchTrailer%6809C3C000F4.body preserve=yes
   Date hDate(m_hGenericSegment[0].get("DATE_RECON_NET").data());
   char szTemp[PERCENTD + PERCENTHD];
   m_iNoOfTcrs++;
   m_iTotNoOfTcrs++;
   m_iTotNoOfTxns++;
   m_siIntrMerchBatchKey++;
   struct hTC57_TCR0_BatchTrailer* pTC57_TCR0_BatchTrailer = (struct hTC57_TCR0_BatchTrailer*)getDATA_BUFFER();
   memset(pTC57_TCR0_BatchTrailer, ' ', sizeof(hTC57_TCR0_BatchTrailer));
   memcpy(pTC57_TCR0_BatchTrailer->sTransCode, "57", sizeof(pTC57_TCR0_BatchTrailer->sTransCode));
   pTC57_TCR0_BatchTrailer->cTransCodeQualifier = '0';
   pTC57_TCR0_BatchTrailer->cTransComponentSeqNumber = '0';
   memcpy(pTC57_TCR0_BatchTrailer->sDestBIN, m_strBatchToValue.data(), m_strBatchToValue.length());
   memcpy(pTC57_TCR0_BatchTrailer->sSourceBIN, m_strBatchToValue.data(), m_strBatchToValue.length());
   pTC57_TCR0_BatchTrailer->cDraftFlag = 'N';
   if (Extract::instance()->getCustomCode() == "COLES")
   {
      Date hDateAction(m_hGenericSegment[0].get("DATE_ACTION").c_str());
      memcpy(pTC57_TCR0_BatchTrailer->sCentralProcDate, hDateAction.asString("%y%j").data() + 1, sizeof(pTC57_TCR0_BatchTrailer->sCentralProcDate));
   }
   else
      memcpy(pTC57_TCR0_BatchTrailer->sCentralProcDate, hDate.asString("%y%j").data() + 1, sizeof(pTC57_TCR0_BatchTrailer->sCentralProcDate));
   memcpy(pTC57_TCR0_BatchTrailer->sRcdFormatCode, "DC", sizeof(pTC57_TCR0_BatchTrailer->sRcdFormatCode));
   snprintf(szTemp, sizeof(szTemp), "%07hd", m_siBatchTxnCount);
   memcpy(pTC57_TCR0_BatchTrailer->sBatchTransactionCount, szTemp, sizeof(pTC57_TCR0_BatchTrailer->sBatchTransactionCount));
   if (m_dBatchNetAmt < 0)
   {
      m_dBatchNetAmt = -1 * m_dBatchNetAmt;
      memcpy(pTC57_TCR0_BatchTrailer->sBatchNetAmtSign, "CR", sizeof(pTC57_TCR0_BatchTrailer->sBatchNetAmtSign));
   }
   snprintf(szTemp, sizeof(szTemp), "%015.0f", m_dBatchNetAmt);
   memcpy(pTC57_TCR0_BatchTrailer->sBatchNetAmt, szTemp, sizeof(pTC57_TCR0_BatchTrailer->sBatchNetAmt));
   snprintf(szTemp, sizeof(szTemp), "%015.0f", m_dBatchGrossAmt);
   memcpy(pTC57_TCR0_BatchTrailer->sBatchGrossAmt, szTemp, sizeof(pTC57_TCR0_BatchTrailer->sBatchGrossAmt));
   memset(pTC57_TCR0_BatchTrailer->sSecondaryAmt, '0', sizeof(pTC57_TCR0_BatchTrailer->sSecondaryAmt));
   snprintf(szTemp, sizeof(szTemp), "%07hd", m_siIntrMerchBatchKey);
   memcpy(pTC57_TCR0_BatchTrailer->sBatchRcdCountTCR, szTemp, sizeof(pTC57_TCR0_BatchTrailer->sBatchRcdCountTCR));
   snprintf(szTemp, sizeof(szTemp), "%08d%05hd", m_iBatchNo, m_siIntrMerchBatchKey);
   memcpy(pTC57_TCR0_BatchTrailer->sInternalMerchBatchKey, szTemp, sizeof(pTC57_TCR0_BatchTrailer->sInternalMerchBatchKey));
   pTC57_TCR0_BatchTrailer->cRecordType = '3';
   return (write(sizeof(hTC57_TCR0_BatchTrailer), hFlatFile));
  //## end report::ISTTC57TransactionFile::write_TCR0_BatchTrailer%6809C3C000F4.body
}

bool ISTTC57TransactionFile::write_TCR91_BatchTrailer (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR91_BatchTrailer%6809C3C000F6.body preserve=yes
   Date hDate(m_hGenericSegment[0].get("DATE_RECON_NET").data());
   char szTemp[PERCENTD + PERCENTHD];
   m_iNoOfTcrs++;
   m_iTotNoOfTcrs++;
   m_iTotNoOfTxns++;
   struct hTCR91_BatchTrailer* pTCR91_BatchTrailer = (struct hTCR91_BatchTrailer*)getDATA_BUFFER();
   memset(pTCR91_BatchTrailer, ' ', sizeof(hTCR91_BatchTrailer));
   memcpy(pTCR91_BatchTrailer->sTransCode, "91", sizeof(pTCR91_BatchTrailer->sTransCode));
   pTCR91_BatchTrailer->cTransCodeQualifier = '0';
   pTCR91_BatchTrailer->cTransComponentSeqNumber = '0';
   memcpy(pTCR91_BatchTrailer->sBIN, m_strBatchToValue.data(), m_strBatchToValue.length());
   memcpy(pTCR91_BatchTrailer->sProcessingDate, hDate.asString("%y%j").data() + 1, sizeof(pTCR91_BatchTrailer->sProcessingDate));
   memset(pTCR91_BatchTrailer->sDestinationAmount, '0', sizeof(pTCR91_BatchTrailer->sDestinationAmount));
   memset(pTCR91_BatchTrailer->sNumMonetaryTrans, '0', sizeof(pTCR91_BatchTrailer->sNumMonetaryTrans));
   snprintf(szTemp, sizeof(szTemp), "%06d", m_iBatchNo);
   memcpy(pTCR91_BatchTrailer->sBatchNumber, szTemp, sizeof(pTCR91_BatchTrailer->sBatchNumber));
   snprintf(szTemp, sizeof(szTemp), "%012d", m_iNoOfTcrs);
   memcpy(pTCR91_BatchTrailer->sNumTCRs, szTemp, sizeof(pTCR91_BatchTrailer->sNumTCRs));
   snprintf(szTemp, sizeof(szTemp), "%09d", m_iTotNoOfTxns);
   memcpy(pTCR91_BatchTrailer->sNumTrans, szTemp, sizeof(pTCR91_BatchTrailer->sNumTrans));
   snprintf(szTemp, sizeof(szTemp), "%015.0f", m_dBatchNetAmt);
   memcpy(pTCR91_BatchTrailer->sSourceAmount, szTemp, sizeof(pTCR91_BatchTrailer->sSourceAmount));
   m_siBatchTxnCount = 0;
   m_dBatchNetAmt = 0;
   m_dBatchGrossAmt = 0;
   m_siIntrMerchBatchKey = 0;
   m_iNoOfTcrs = 0;
   m_strBatchToValue.erase();
   return (write(sizeof(hTCR91_BatchTrailer), hFlatFile));
  //## end report::ISTTC57TransactionFile::write_TCR91_BatchTrailer%6809C3C000F6.body
}

bool ISTTC57TransactionFile::write_TCR92_FileTrailer (IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write_TCR92_FileTrailer%6809C3C000F8.body preserve=yes
   Date hDate(m_hGenericSegment[0].get("DATE_RECON_NET").data());
   char szTemp[PERCENTD + PERCENTHD];
   struct hTCR92_FileTrailer* pTCR92_FileTrailer = (struct hTCR92_FileTrailer*)getDATA_BUFFER();
   memset(pTCR92_FileTrailer, ' ', sizeof(hTCR92_FileTrailer));
   memcpy(pTCR92_FileTrailer->sTransCode, "92", sizeof(pTCR92_FileTrailer->sTransCode));
   pTCR92_FileTrailer->cTransCodeQualifier = '0';
   pTCR92_FileTrailer->cTransComponentSeqNumber = '0';
   memcpy(pTCR92_FileTrailer->sProcessingDate, hDate.asString("%y%j").data() + 1, sizeof(pTCR92_FileTrailer->sProcessingDate));
   memset(pTCR92_FileTrailer->sDestinationAmount, '0', sizeof(pTCR92_FileTrailer->sDestinationAmount));
   memset(pTCR92_FileTrailer->sNumMonetaryTrans, '0', sizeof(pTCR92_FileTrailer->sNumMonetaryTrans));
   snprintf(szTemp, sizeof(szTemp), "%06d", m_iBatchNo);
   memcpy(pTCR92_FileTrailer->sBatchNumber, szTemp, sizeof(pTCR92_FileTrailer->sBatchNumber));
   snprintf(szTemp, sizeof(szTemp), "%012d", m_iTotNoOfTcrs);
   memcpy(pTCR92_FileTrailer->sNumTCRs, szTemp, sizeof(pTCR92_FileTrailer->sNumTCRs));
   snprintf(szTemp, sizeof(szTemp), "%09d", m_iTotNoOfTxns);
   memcpy(pTCR92_FileTrailer->sNumTrans, szTemp, sizeof(pTCR92_FileTrailer->sNumTrans));
   snprintf(szTemp, sizeof(szTemp), "%015.0f", m_dTotNetAmt);
   memcpy(pTCR92_FileTrailer->sSourceAmount, szTemp, sizeof(pTCR92_FileTrailer->sSourceAmount));
   m_dTotNetAmt = 0;
   m_iTotNoOfTcrs = 0;
   return (write(sizeof(hTCR92_FileTrailer), hFlatFile));
  //## end report::ISTTC57TransactionFile::write_TCR92_FileTrailer%6809C3C000F8.body
}

bool ISTTC57TransactionFile::getGenericValue (const string& strType, const string& strFromValue, string& strToValue)
{
  //## begin report::ISTTC57TransactionFile::getGenericValue%6809C3C000FA.body preserve=yes
   return ConfigurationRepository::instance()->translate(strType.data(), strFromValue, strToValue, " ", " ", -1, false);
  //## end report::ISTTC57TransactionFile::getGenericValue%6809C3C000FA.body
}

bool ISTTC57TransactionFile::write (const int &iLength, IF::FlatFile& hFlatFile)
{
  //## begin report::ISTTC57TransactionFile::write%6809C3C000FE.body preserve=yes
   string strDATA_BUFFER(getDATA_BUFFER(), iLength);
#ifdef MVS
   if (m_bVariableBlockFile)
      strDATA_BUFFER.insert(0, "~RDW", 4);
#endif
   return (ExportFile::distribute(strDATA_BUFFER, hFlatFile));
  //## end report::ISTTC57TransactionFile::write%6809C3C000FE.body
}

// Additional Declarations
  //## begin report::ISTTC57TransactionFile%6809C3C000B8.declarations preserve=yes
bool ISTTC57TransactionFile::start(IF::FlatFile& hFlatFile)
{
   string strCONTEXT_DATA;
   m_pContext->get("FILM LOCATOR", strCONTEXT_DATA);
   m_iFilmLocator = atoi(strCONTEXT_DATA.c_str());
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
   m_pReport = postingfile::Reports::instance()->getReport(getDX_REPORT_ID());
   if (!m_pReport)
      return UseCase::setSuccess(false);
   map<string, pair<int, short>, less<string> >  hOffsetWidth = m_pReport->getOffsetWidth();
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
}
bool ISTTC57TransactionFile::unionAll(Query& hQuery)
{
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
}
bool ISTTC57TransactionFile::writeUnMatchedAuth()
{
   if (m_pUnMatchFile == 0)
   {
      string strTmp;
      int i = 30;
      if (Extract::instance()->getRecord("DSPEC   RX28    AGEAUTH~", strTmp))
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
}

bool ISTTC57TransactionFile::write_TCR4_VisaSMS(IF::FlatFile& hFlatFile)
{
   m_iNoOfTcrs++;
   m_iTotNoOfTcrs++;
   m_siIntrMerchBatchKey++;
   struct hTC57_TCR4_VisaSMS* phTC57_TCR4_VisaSMS = (struct hTC57_TCR4_VisaSMS*)getDATA_BUFFER();
   memset(phTC57_TCR4_VisaSMS, ' ', sizeof(hTC57_TCR4_VisaSMS));
   memcpy(phTC57_TCR4_VisaSMS->sTransCode, "57", sizeof(phTC57_TCR4_VisaSMS->sTransCode));
   phTC57_TCR4_VisaSMS->cTransCodeQualifier = '0';
   phTC57_TCR4_VisaSMS->cTransComponentSeqNumber = '4';
   memcpy(phTC57_TCR4_VisaSMS->sBusinessFormatCode, "SD", sizeof(phTC57_TCR4_VisaSMS->sBusinessFormatCode));
   return (write(sizeof(hTC57_TCR4_VisaSMS), hFlatFile));
}
  //## end report::ISTTC57TransactionFile%6809C3C000B8.declarations
bool ISTTC57TransactionFile::write_TCR1_TxnDetail_UPI(IF::FlatFile& hFlatFile)
{
   m_iNoOfTcrs++;
   m_iTotNoOfTcrs++;
   m_siIntrMerchBatchKey++;
   struct hTC57_TCR1_TxnDetail_UPI* pTC57_TCR1_TxnDetail_UPI = (struct hTC57_TCR1_TxnDetail_UPI*)getDATA_BUFFER();
   memset(pTC57_TCR1_TxnDetail_UPI, ' ', sizeof(hTC57_TCR1_TxnDetail_UPI));
   memcpy(pTC57_TCR1_TxnDetail_UPI->sTransCode, "57", sizeof(pTC57_TCR1_TxnDetail_UPI->sTransCode));
   pTC57_TCR1_TxnDetail_UPI->cTransCodeQualifier = '0';
   pTC57_TCR1_TxnDetail_UPI->cTransComponentSeqNumber = '1';
   memcpy(pTC57_TCR1_TxnDetail_UPI->sUPIIndicator, "UP", 2);
   pTC57_TCR1_TxnDetail_UPI->cTransInitMethod = '0';
   string strToValue;
   getGenericValue("TC57_OPER_ENV", m_hGenericSegment[0].get("POS_OPER_ENV"), strToValue);
   if (!strToValue.empty())
      pTC57_TCR1_TxnDetail_UPI->cTransInitMethod = strToValue[0];
   else if (m_hGenericSegment[0].get("TERM_CLASS") == "02")
      pTC57_TCR1_TxnDetail_UPI->cTransInitMethod = '2';
   else {
      getGenericValue("TC57_UPI_CH_PT", m_hGenericSegment[0].get("POS_CRDHLDR_PRESNT"), strToValue);
      if (!strToValue.empty())
         pTC57_TCR1_TxnDetail_UPI->cTransInitMethod = strToValue[0];
   }
   memcpy(pTC57_TCR1_TxnDetail_UPI->sPOSCondCode, m_hGenericSegment[0].get("AS2805_DE25").data(), min(sizeof(pTC57_TCR1_TxnDetail_UPI->sPOSCondCode), m_hGenericSegment[0].get("AS2805_DE25").length()));
   memcpy(pTC57_TCR1_TxnDetail_UPI->sCardProduct, "00", sizeof(pTC57_TCR1_TxnDetail_UPI->sCardProduct));
   if (memcmp(m_szDATA_PRIV_ISS + 88, "  ", 2) != 0)
      memcpy(pTC57_TCR1_TxnDetail_UPI->sCardProduct, m_szDATA_PRIV_ISS + 88, sizeof(pTC57_TCR1_TxnDetail_UPI->sCardProduct));
   return (write(sizeof(hTC57_TCR1_TxnDetail_UPI), hFlatFile));
}
} // namespace report

//## begin module%62610BE60007.epilog preserve=yes
//## end module%62610BE60007.epilog
