//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%4097B74F0109.cm preserve=no
//   $Date:   Jul 29 2021 12:43:48  $ $Author:   e5549623  $
//   $Revision:   1.137  $
//## end module%4097B74F0109.cm

//## begin module%4097B74F0109.cp preserve=no
//   Copyright (c) 1997 - 2012
//   FIS
//## end module%4097B74F0109.cp

//## Module: CXOSVE02%4097B74F0109; Package body
//## Subsystem: VEDLL%4097A62502BF
//## Source file: C:\bV02.8A.R005\Windows\Build\Dn\Server\Library\Vedll\CXOSVE02.cpp

//## begin module%4097B74F0109.additionalIncludes preserve=no
//## end module%4097B74F0109.additionalIncludes

//## begin module%4097B74F0109.includes preserve=yes
// This product includes software developed by the Apache Software Foundation (http://www.apache.org/).
#ifdef _WIN32
//#include "windows.h"
#include "xercesc\sax\AttributeList.hpp"
#else
#include "xercesc/sax/AttributeList.hpp"
#endif
#include "CXODIF16.hpp"
#include "CXODRU05.hpp"
#ifndef CXOSDB05_h
#include "CXODDB05.hpp"
#endif
#ifndef CXOSPS01_h
#include "CXODPS01.hpp"
#endif
#include "CXODCF01.hpp"
#include "CXODDB70.hpp"
//## end module%4097B74F0109.includes

#ifndef CXOSIF03_h
#include "CXODIF03.hpp"
#endif
#ifndef CXOSIF04_h
#include "CXODIF04.hpp"
#endif
#ifndef CXOSMN05_h
#include "CXODMN05.hpp"
#endif
#ifndef CXOSDB01_h
#include "CXODDB01.hpp"
#endif
#ifndef CXOSRU10_h
#include "CXODRU10.hpp"
#endif
#ifndef CXOSTM04_h
#include "CXODTM04.hpp"
#endif
#ifndef CXOSNS29_h
#include "CXODNS29.hpp"
#endif
#ifndef CXOSIF28_h
#include "CXODIF28.hpp"
#endif
#ifndef CXOSGE02_h
#include "CXODGE02.hpp"
#endif
#ifndef CXOSES65_h
#include "CXODES65.hpp"
#endif
#ifndef CXOSGE08_h
#include "CXODGE08.hpp"
#endif
#ifndef CXOSIF44_h
#include "CXODIF44.hpp"
#endif
#ifndef CXOSVE07_h
#include "CXODVE07.hpp"
#endif
#ifndef CXOSRU37_h
#include "CXODRU37.hpp"
#endif
#ifndef CXOSES67_h
#include "CXODES67.hpp"
#endif
#ifndef CXOSES66_h
#include "CXODES66.hpp"
#endif
#ifndef CXOSGE58_h
#include "CXODGE58.hpp"
#endif
#ifndef CXOSGE59_h
#include "CXODGE59.hpp"
#endif
#ifndef CXOSGE03_h
#include "CXODGE03.hpp"
#endif
#ifndef CXOSGE70_h
#include "CXODGE70.hpp"
#endif
#ifndef CXOSGE85_h
#include "CXODGE85.hpp"
#endif
#ifndef CXOSVE02_h
#include "CXODVE02.hpp"
#endif


//## begin module%4097B74F0109.declarations preserve=no
//## end module%4097B74F0109.declarations

//## begin module%4097B74F0109.additionalDeclarations preserve=yes
//## end module%4097B74F0109.additionalDeclarations


//## Modelname: Transaction Research and Adjustments::VisaException_CAT%4097A16101D4
namespace visaexception {
//## begin visaexception%4097A16101D4.initialDeclarations preserve=yes
//## end visaexception%4097A16101D4.initialDeclarations

// Class visaexception::BulkQuestionnaireHandler 

BulkQuestionnaireHandler::BulkQuestionnaireHandler()
  //## begin BulkQuestionnaireHandler::BulkQuestionnaireHandler%4097AF8203A9_const.hasinit preserve=no
       :m_pImage(0),
        m_pProcessingReportDownloadResponseDescriptor(0),
        m_pProcessingReportDownloadResponsePackage(0),
        m_pLineItem(0),
        m_pAssociatedTran(0)
  //## end BulkQuestionnaireHandler::BulkQuestionnaireHandler%4097AF8203A9_const.hasinit
  //## begin BulkQuestionnaireHandler::BulkQuestionnaireHandler%4097AF8203A9_const.initialization preserve=yes
  //## end BulkQuestionnaireHandler::BulkQuestionnaireHandler%4097AF8203A9_const.initialization
{
  //## begin visaexception::BulkQuestionnaireHandler::BulkQuestionnaireHandler%4097AF8203A9_const.body preserve=yes
   IF::Extract::instance()->getSpec("CUSTQUAL", m_strControllingSwitch);
  //## end visaexception::BulkQuestionnaireHandler::BulkQuestionnaireHandler%4097AF8203A9_const.body
}


BulkQuestionnaireHandler::~BulkQuestionnaireHandler()
{
  //## begin visaexception::BulkQuestionnaireHandler::~BulkQuestionnaireHandler%4097AF8203A9_dest.body preserve=yes
  //## end visaexception::BulkQuestionnaireHandler::~BulkQuestionnaireHandler%4097AF8203A9_dest.body
}



//## Other Operations (implementation)
void BulkQuestionnaireHandler::endDocument ()
{
  //## begin visaexception::BulkQuestionnaireHandler::endDocument%4BBA51BB02B6.body preserve=yes
   if (m_bSchemaCheck)
      return;

   Trace::put("in end doc");
   genericexception::CaseManifest::instance()->endAudit();
   string strTemp;
   if ((CaseManifestSegment::instance()->getFile() == "VRRDM5"
      || CaseManifestSegment::instance()->getFile() == "DNRDM5")
      && IF::Extract::instance()->getSpec("DM5EMAIL", strTemp))
      genericexception::CaseManifest::instance()->email();

  //## end visaexception::BulkQuestionnaireHandler::endDocument%4BBA51BB02B6.body
}

void BulkQuestionnaireHandler::endElement (const XMLCh* const name)
{
  //## begin visaexception::BulkQuestionnaireHandler::endElement%409BCA4F034B.body preserve=yes
   if (getAbort())
      return;
   if (m_bSchemaCheck)
      return;

   m_strData = getCharacters();

   string strElement(m_hElement.back().c_str()); // need null terminated char* ... Solaris sometimes returns trailing x'00' character
   UnmatchedMessageSegment::instance()->appendACTUAL_MSG(m_strData);
   UnmatchedMessageSegment::instance()->appendACTUAL_MSG("</");
   UnmatchedMessageSegment::instance()->appendACTUAL_MSG(strElement);
   UnmatchedMessageSegment::instance()->appendACTUAL_MSG(">");
   if (strElement == "Name")
      m_strMemberName = m_strData;
   if (strElement == "NetworkID" && CaseManifestSegment::instance()->getFile() == "VRRDM5"
      && m_strData == "0006")
      m_strData = "0004";
   if (strElement == "AccountNumber")
   {
      m_strDM5AccountNumber = m_strData; //save original PAN from DM5
      string strIssuerInstID;
      genericexception::CaseManifest::instance()->get("IssuerInstID", strIssuerInstID);
      if (database::PenkoToken::instance()->isToken(m_strData.data(),m_strData.length()) && strIssuerInstID.length() >= 9)
         database::PenkoToken::instance()->detokenize(m_strData, strIssuerInstID, "*I");
   }
   if (strElement == "MemberMsgEditText")
   {
      string strValue;
      CaseManifest::instance()->get("NetworkID", strValue);
      if (strValue == "0018")
         genericexception::CaseManifest::instance()->add("NYCMemberMsgText", m_strData);
      if (strValue == "0002" || strValue == "0003" || strValue == "0004")
         strElement = "VisaMMT";
   }

   if (strElement == "VROLFinancialSentInd")
      m_strData = (m_strData == "true") ? "Y" : "N";

   if (strElement == "Amount"
      || strElement == "CAmount"
      || strElement == "CashbackAmount"
      || strElement == "DestAmount"
      || strElement == "DisputeAmt"
      || strElement == "MiscFeeAmount"
      || strElement == "NetworkReconAmount"
      || strElement == "SettlementAmount"
      || strElement == "TransactionAmount"
      || strElement == "DisputeAmount")
   {
      size_t pos = m_strData.find(",");
      if (pos != string::npos)
         m_strData.erase(pos, 1);
   }
   if (m_hElement.size() > 2
      && m_hElement[m_hElement.size() - 2] == "Image")
   {
      if (strElement == "DocType" && (CaseManifestSegment::instance()->getFile() == "DNRDM5"
         || CaseManifestSegment::instance()->getFile() == "DNBXML"))
      {
         if (m_pImage->getQuestionnaireData().length() > 0)
         {
            setQtnWrapper(m_strData);
            m_pImage->add("RemoteFileName", m_pImage->getQuestionnaireData());
         }
      }
      else if (strElement == "QuestionnaireData" && (CaseManifestSegment::instance()->getFile() == "DNRDM5"
         || CaseManifestSegment::instance()->getFile() == "DNBXML"))
         m_pImage->setQuestionnaireData(m_strData);
      m_pImage->add(strElement, m_strData);
   }
   else
   if (m_hElement.size() > 2
      && m_hElement[m_hElement.size() - 2] == "Lineitem")
      m_pLineItem->add(strElement, m_strData);
   else
   if (m_hElement.size() > 2
      && m_hElement[m_hElement.size() - 2] == "AssociatedTran")
      m_pAssociatedTran->add(strElement, m_strData);
   else
   if (strElement == "PrimaryKey")
   {
      size_t nPos = m_strData.find(":");
      if (nPos != string::npos)
      {
         string strTemp1(m_strData, 0, nPos);
         strTemp1.resize(16, '0');
         genericexception::CaseManifest::instance()->add("TransactionDateTime", strTemp1);
         strTemp1.assign(m_strData, nPos + 1, m_strData.length() - nPos);
         genericexception::CaseManifest::instance()->add("UniquenessKey", strTemp1);
      }
   }
   if (m_strData.length() > 0)
   {
      if (strElement == "ToBIN")
      {
         string strValue;
         CaseManifest::instance()->get("CaseManifest memberRole", strValue);
         if ((CaseManifestSegment::instance()->getFile() == "VRRDM5" && strValue == "A")
            || (CaseManifestSegment::instance()->getFile() == "DNRDM5" && strValue == "I"))
            genericexception::CaseManifest::instance()->add("FromBIN", m_strData);
      }
      else if (strElement == "FromBIN")
      {
         string strValue;
         CaseManifest::instance()->get("CaseManifest memberRole", strValue);
         if ((CaseManifestSegment::instance()->getFile() == "VRRDM5" && strValue == "A")
            || (CaseManifestSegment::instance()->getFile() == "DNRDM5" && strValue == "I"))
            genericexception::CaseManifest::instance()->add("ToBIN", m_strData);
      }
      else
      if (CaseManifestSegment::instance()->getFile() == "VRRDM5"
         && strElement == "TransactionID"
         && m_hElement.size() > 2
         && m_hElement[m_hElement.size() - 2] != "Case");
      else
         genericexception::CaseManifest::instance()->add(strElement, m_strData);
   }
   if (strElement == "ProcessingDate" && m_strData.length() > 7)
   {
      m_strData.erase(7, 1);
      m_strData.erase(4, 1);
      CaseManifestSegment::instance()->setDATE_RECEIVED(m_strData);
   }

   if (strElement == "RecallInd" && m_strData == "true")
   {
      string strClass = CaseManifest::instance()->getClass();
      if (strClass == "ChargebackFinancial")
         genericexception::CaseManifest::instance()->setClass("ChargebackReversal");
      else if (strClass == "RepresentmentFinancial")
         genericexception::CaseManifest::instance()->setClass("RepresentmentReversal");
   }

   if (strElement == "DisputeResponse" && m_strData == "FULL")
   {
      genericexception::CaseManifest::instance()->setClass("UpdateStatus");
      genericexception::CaseManifest::instance()->add("Status", "Acceptance");
      return;
   }
   if (strElement == "DM5Documentation"
      || strElement == "DM5Comments")
      genericexception::CaseManifest::instance()->setClass(strElement);
   if (m_hElement.size() > 2
      && m_hElement[m_hElement.size() - 2] == "Discover")
   {
      string strQuestionarrie;
      strQuestionarrie += "<";
      strQuestionarrie += strElement;
      strQuestionarrie += ">";
      strQuestionarrie += m_strData;
      strQuestionarrie += "</";
      strQuestionarrie += strElement;
      strQuestionarrie += ">";
      m_strDISData.append(strQuestionarrie);
   }
   if (strElement == "Discover"
      && m_strDISData.length() > 0)
   {
      string strDISQuest("<Discover>", 10);
      strDISQuest += m_strDISData;
      strDISQuest += "</Discover>";
      string strRole;
      CaseManifest::instance()->get("CaseManifest memberRole", strRole);
      m_pImage = genericexception::CaseManifest::instance()->addImage();
      m_pImage->add("DocType", "REQ_DISQ_" + strRole);
      m_pImage->add("RemoteFileName", strDISQuest);
      m_strDISData.erase();
   }
   if (strElement == "PreArb"
      || strElement == "Arbitration"
      || strElement == "PreComp"
      || strElement == "Compliance"
      || strElement == "PreCompResp"
      || strElement == "CompResp")
   {
      string strValue;
      if ((CaseManifest::instance()->get("changeReasonCodeFlag",strValue)
         || CaseManifest::instance()->get("changeReasonCodeReason",strValue)
         || CaseManifest::instance()->get("memo",strValue)
         || CaseManifest::instance()->get("chargebackRefNum", strValue)
         || CaseManifest::instance()->get("ruleViolated", strValue)))
      {
         string strTemp,strRole;
         CaseManifest::instance()->get("DisputeReasonCode",strTemp);
         genericexception::CaseManifest::instance()->add("disputeReasonCode",strTemp);
         CaseManifest::instance()->get("NetworkID", strTemp);
         m_pImage = genericexception::CaseManifest::instance()->addImage(strTemp);
         CaseManifest::instance()->get("CaseManifest memberRole", strRole);
         if (strElement == "PreArb")
            m_pImage->add("DocType","REQ_PARB_"+ strRole);
         else if(strElement == "Arbitration")
            m_pImage->add("DocType","REQ_ARB_"+ strRole);
         else if(strElement == "PreComp")
            m_pImage->add("DocType","REQ_PCMP_"+ strRole);
         else if (strElement == "Compliance")
            m_pImage->add("DocType","REQ_COMP_"+ strRole);
         else if (strElement == "PreCompResp")
            m_pImage->add("DocType","REQ_PRSP_"+ strRole);
         else if (strElement == "CompResp")
            m_pImage->add("DocType","REQ_CRSP_"+ strRole);
         const char* sTags[8] = { "changeReasonCodeFlag", "changeReasonCodeReason", "memo", "ReasonCode", "disputeReasonCode", "MemberMsgEditText", "chargebackRefNum", "ruleViolated"};
         strTemp = (strRole == "I") ? "<?xml version='1.0' encoding='UTF-8'?><IssuerCaseFilingInfo><" : "<?xml version='1.0' encoding='UTF-8'?><AcquirerCaseFilingInfo><";
         for (int i = 0; i < 8; i++)
         {
            if (CaseManifest::instance()->get(sTags[i], strValue))
            {
               strTemp.append(sTags[i]);
               strTemp.append(">");
               strTemp.append(strValue);
               strTemp.append("</");
               strTemp.append(sTags[i]);
               strTemp.append("><");
            }
         }
         strTemp += (strRole == "I") ? "/IssuerCaseFilingInfo>" : "/AcquirerCaseFilingInfo>";
         m_pImage->add("RemoteFileName",strTemp);
      }
   }
   if (strElement == "CollaborationResponse")
   {
      string strTemp;
      CaseManifest::instance()->get("NetworkID", strTemp);
      string strValue;
      CaseManifest::instance()->get("DisputeReasonCode", strTemp);
      genericexception::CaseManifest::instance()->add("disputeReasonCode", strTemp);
      m_pImage = genericexception::CaseManifest::instance()->addImage(strTemp);
      m_pImage->add("DocType", "REQ_CBRS");
      const char* sTags[9] = { "ReasonCode", "acquirerResponseCd", "memo", "ReasonCode", "refundReversalType", "refundReversalDate" ,"refundReversalReferenceId","refundReversalAmount","refundReversalCurrency" };
      vector<string> hTokens;
      strTemp.assign("<?xml version='1.0' encoding='UTF-8'?><CollaborationResponseInfo><");
      for (int i = 0; i < 7; i++)
      {
         strTemp.append(sTags[i]);
         strTemp.append(">");
         CaseManifest::instance()->get(sTags[i], strValue);
         if (sTags[i] == "refundReversalCurrency")
         {
            string strCurrency;
            if (!ConfigurationRepository::instance()->translate("~CURRENCY_CODE", strValue, strCurrency, " ", " ", -1, false))
               strCurrency = "???";
            strValue = strCurrency;
         }
         strTemp.append(strValue);
         strTemp.append("</");
         strTemp.append(sTags[i]);
         strTemp.append("><");
      }
      strTemp.append("/CollaborationResponseInfo>");
      m_pImage->add("RemoteFileName", strTemp);
   }
   if (strElement == "CaseManifest")
   {
      string strValue, strTemp;
      CaseManifestSegment::instance()->setClass(genericexception::CaseManifest::instance()->getClass());
      if (CaseManifestSegment::instance()->getFile() == "VRRDM5" 
         && (CaseManifest::instance()->getClass() == "FeeCollection" 
            || CaseManifest::instance()->getClass() == "FundDisbursement")
         && CaseManifest::instance()->get("MiscFeeReasonCode", strValue)
         && (strValue >= "5000" && strValue <= "5300"))
      {
         CaseManifestSegment::instance()->setRecordNo((CaseManifestSegment::instance()->getRecordNo() + 1));
         CaseManifestSegment::instance()->setFailedCaseCount((CaseManifestSegment::instance()->getFailedCaseCount()) + 1);
         CaseManifestSegment::instance()->setErrorText("Fee Case Dropped: Reason Code " + strValue);
         genericexception::CaseManifest::instance()->getAudit()->report('F');
      }
      else if (!CaseManifest::instance()->getBadTokens().empty())
      {
         map<string, string, less<string> >::iterator pBadToken;
         string strError = "XML Field(s) are too long: ";
         for (pBadToken = CaseManifest::instance()->getBadTokens().begin(); pBadToken != CaseManifest::instance()->getBadTokens().end(); pBadToken++)
         {
            strError += (*pBadToken).first;
            strError += ",";
            strError += (*pBadToken).second;
            strError += ";";
         }
         BatchDescriptorSegment::instance()->setCODE("E-00000015");
         CaseManifestSegment::instance()->setRecordNo((CaseManifestSegment::instance()->getRecordNo() + 1));
         CaseManifestSegment::instance()->setFailedCaseCount((CaseManifestSegment::instance()->getFailedCaseCount()) + 1);
         CaseManifestSegment::instance()->setErrorText(strError);
         genericexception::CaseManifest::instance()->getAudit()->report('F');
      }
      else 
         genericexception::CaseManifest::instance()->import();
      if (BatchDescriptorSegment::instance()->getCODE()[0] == 'E'
         && CaseSegment::instance()->getAMT_RECON_NET() == 0)
         CaseSegment::instance()->setAMT_RECON_NET(CaseSegment::instance()->getAMT_TRAN());
      if (CaseManifestSegment::instance()->getFile() == "DNRDM5")
      {
         if(!m_strDM5AccountNumber.empty())
            CaseSegment::instance()->setPAN(m_strDM5AccountNumber); //restore from DM5 (in case of tokenization)
         m_pProcessingReportDownloadResponsePackage->addCase();
         m_strDM5AccountNumber.erase();
      }
      if (CaseManifestSegment::instance()->getFile() != "DNBXML")
         genericexception::CaseManifest::instance()->reset();
      UseCase::addItem();
   }
   if (strElement == "ResponsePackage" &&
      CaseManifestSegment::instance()->getFile() == "DNRDM5")
   {
      delete m_pProcessingReportDownloadResponseDescriptor;
      delete m_pProcessingReportDownloadResponsePackage;
      m_pProcessingReportDownloadResponseDescriptor = 0;
      m_pProcessingReportDownloadResponsePackage = 0;
   }
   m_hElement.pop_back();
  //## end visaexception::BulkQuestionnaireHandler::endElement%409BCA4F034B.body
}

void BulkQuestionnaireHandler::setQtnWrapper (string& strToken)
{
  //## begin visaexception::BulkQuestionnaireHandler::setQtnWrapper%53FCDE710199.body preserve=yes
   string strQtnData = m_pImage->getQuestionnaireData();
   size_t pos;
   if (strQtnData.find("{Chargeback ") != string::npos || 
      strQtnData.find("{Representment ") != string::npos)
   {
      pos = strQtnData.find_first_of('}');
      strQtnData.erase(0, pos + 1);
      pos = strQtnData.find_last_of('{');
      strQtnData.erase(pos);
   }
   Object hObject;
   hObject.trim(strQtnData); //get rid of leading and trailing spaces
   for (int i = 0; i<strQtnData.length(); i++)
   {
      if (strQtnData[i] == '<')
         strQtnData.replace(i, 1, "&lt;");
      if (strQtnData[i] == '>')
         strQtnData.replace(i, 1, "&gt;");
      if (strQtnData[i] == '\'')
         strQtnData.replace(i, 1, "&apos;");
      if ((strQtnData[i] == '\"') && strQtnData[i - 1] != '=')
      {
         size_t temp = 0;
         for (int j = 1; j < 6; j++)
         {
            if (strQtnData[i - j] == '\"')
               temp = strQtnData[i - j];
         }
         if (((pos = strQtnData[i]) - temp) > 6)
            strQtnData.replace(i, 1, "&quot;");
      }
      if (strQtnData[i] == '{')
         strQtnData[i] = '<';
      if (strQtnData[i] == '}')
         strQtnData[i] = '>';
   }
   strQtnData.insert(0, "<PASSTHRU>");
   strQtnData.append("</PASSTHRU>");
   m_pImage->setQuestionnaireData(strQtnData);
  //## end visaexception::BulkQuestionnaireHandler::setQtnWrapper%53FCDE710199.body
}

void BulkQuestionnaireHandler::startElement (const XMLCh* const name, AttributeList& attributes)
{
  //## begin visaexception::BulkQuestionnaireHandler::startElement%409A292F0261.body preserve=yes
   if (getAbort())
      return;
   m_strCharacters.erase();
   getToken("BulkQuestionnaireHandler::startElement ", name, XMLString::stringLen(name));
   if (!m_bSchemaCheck)
      m_hElement.push_back(m_strToken);
   const XMLCh* pType = 0;
   if (m_strToken == "ResponsePackage")
   {
      pType = attributes.getValue("name");
      if (XMLString::stringLen(pType) == 0)
      {
         m_strName = " ";
         return;
      }
      else
      {
         getToken("BulkQuestionnaireHandler::startElement name= ", pType, XMLString::stringLen(pType));
         m_strName = m_strToken;
      }
      pType = attributes.getValue("seq");
      if (XMLString::stringLen(pType) == 0)
      {
         m_strseq = " ";
         return;
      }
      else
      {
         getToken("BulkQuestionnaireHandler::startElement seq= ", pType, XMLString::stringLen(pType));
         m_strseq = m_strToken;
      }
      pType = attributes.getValue("batchID");
      if (XMLString::stringLen(pType) == 0)
      {
         m_strBatchID = " ";
         return;
      }
      else
      {
         getToken("BulkQuestionnaireHandler::startElement batchID= ", pType, XMLString::stringLen(pType));
         m_strBatchID = m_strToken;
      }
      return;
   }
   if (m_bSchemaCheck)
      return;
   if (m_strToken == "BQIDownloadResponse")
   {
      if (CaseManifestSegment::instance()->getFile() == "VRRDM5")
         CaseManifestSegment::instance()->setTitle("VROL DM5 Download");
      else
         CaseManifestSegment::instance()->setTitle("DM5 Download");
      int lGMTOffset = 6;
      char szTIMESTAMP[26] = { "" };
      Object::snprintf(szTIMESTAMP,sizeof(szTIMESTAMP), "%d-%02d-%02dT%02d:%02d:%02d-%02d:00",
         Clock::instance()->getYear(), Clock::instance()->getMonth(), Clock::instance()->getDay(),
         Clock::instance()->getHour(), Clock::instance()->getMinute(), Clock::instance()->getSecond(),
         lGMTOffset);
      emssegment::BatchDescriptorSegment::instance()->setTIMESTAMP(szTIMESTAMP);
      genericexception::CaseManifest::instance()->beginImportAudit("AUDRM5");
      string strRequestBatchID = BatchDescriptorSegment::instance()->getREQUESTBATCHID();
      if (m_strBatchID != strRequestBatchID)
      {
         string strErrorMSG = "Error: Batch Descriptor batch id " + strRequestBatchID + " does not match Request Descriptor batch id " + m_strBatchID + ".";
         CaseManifestSegment::instance()->setErrorText(strErrorMSG);
         genericexception::CaseManifest::instance()->getAudit()->report('E');
         BatchDescriptorSegment::instance()->setMESSAGE(strErrorMSG);
         m_bAbort = true;
         return;
      }
      int seq = atoi(m_strseq.c_str());
      string strName = BatchDescriptorHandler::instance()->getPackageName(seq);
      if (m_strName.length() < 8
         || strName.length() < 8
         || m_strName != strName)
      {
         string strErrorMSG = "Error: Batch Descriptor name " + strName + " does not match Request Descriptor name " + m_strName + ".";
         CaseManifestSegment::instance()->setErrorText(strErrorMSG);
         genericexception::CaseManifest::instance()->getAudit()->report('E');
         BatchDescriptorSegment::instance()->setMESSAGE(strErrorMSG);
         m_bAbort = true;
      }
      else
      {
         if ((m_pProcessingReportDownloadResponseDescriptor == 0) &&
            (CaseManifestSegment::instance()->getFile() == "DNRDM5"))
         {
            Clock::instance()->setHundredths(99);
            string strYYYYMMDD(Clock::instance()->getYYYYMMDDHHMMSSHN(true).data(), 8);
            m_pProcessingReportDownloadResponseDescriptor = new genericexception::ProcessingReportDownloadResponseDescriptor;
            string strTime = Clock::instance()->getYYYYMMDDHHMMSS().substr(8, 6);
            m_pProcessingReportDownloadResponseDescriptor->deport(strYYYYMMDD, strTime);
            m_pProcessingReportDownloadResponsePackage = new genericexception::ProcessingReportDownloadResponsePackage;
            m_pProcessingReportDownloadResponsePackage->deport(strYYYYMMDD, strTime);
         }
         string strNetID;
         string strValue;
         IF::Extract::instance()->getSpec("FBDNBDM5", strValue);
         if (CaseManifestSegment::instance()->getFile() == "VRRDM5")
            strNetID = "VNT";
         else if (strValue == "USPS")
         {
            string strRecord;
            if (IF::Extract::instance()->getRecord("DFILES  DNBDM5  ", strRecord)
               && strRecord.length() > 16)
            {
               string strFilename("DSPEC   " + strRecord.substr(16));
               strFilename.resize(16, ' ');
               if (IF::Extract::instance()->getRecord(strFilename.c_str(), strRecord)
                  && strRecord.length() > 16)
               {
                  strNetID.assign(strRecord, 16, 8);
                  size_t pos = strNetID.find_last_not_of(' ');
                  if (pos != string::npos)
                     strNetID.erase(pos + 1);
               }
            }
         }
         else
            strNetID = m_strMemberName;
         if (strNetID.length() == 0)
            strNetID == "UNKNOWN";
         string strKey("NETID");
         SiteSpecification::instance()->add(strKey, strNetID);
         strKey = "VROLPKG";
         string strTemp(m_strName.data() + 1, 7);
         SiteSpecification::instance()->add(strKey, strTemp);
         int iYear = Clock::instance()->getYear();
         int iMonth = Clock::instance()->getMonth();
         char szMonth[13] = { "123456789ABC" };
         char* p = strchr(szMonth, m_strName[4]);
         if (p)
         {
            int i = (p - szMonth) + 1;
            if (i > iMonth)
               --iYear;
            iMonth = i;
         }
         char szYYYYMM[7];
         Object::snprintf(szYYYYMM,sizeof(szYYYYMM), "%04d%02d", iYear, iMonth);
         strKey = "YYYYMM";
         strTemp.assign(szYYYYMM, 6);
         SiteSpecification::instance()->add(strKey, strTemp);
         strKey = "YYYYMMDD";
         string strDate = Clock::instance()->getYYYYMMDDHHMMSS().substr(0, 8);
         strDate.insert(4, "-", 1);
         strDate.insert(7, "-", 1);
         SiteSpecification::instance()->add(strKey, strDate);
      }
      return;
   }
   if (m_strToken == "CaseManifest")
   {
      UnmatchedMessageSegment::instance()->setACTUAL_MSG("              :<CaseManifest memberRole=");
      pType = attributes.getValue("memberRole");
      getToken("BulkQuestionnaireHandler::startElement name= ", pType, XMLString::stringLen(pType));
      genericexception::CaseManifest::instance()->add("CaseManifest memberRole", m_strToken);
      UnmatchedMessageSegment::instance()->appendACTUAL_MSG(m_strToken);
      UnmatchedMessageSegment::instance()->appendACTUAL_MSG(">");
      return;
   }
   if (m_strToken == "User")
   {
      UnmatchedMessageSegment::instance()->setACTUAL_MSG("              :<User Id=");
      pType = attributes.getValue("Id");
      getToken("BulkQuestionnaireHandler::startElement name= ", pType, XMLString::stringLen(pType));
      genericexception::CaseManifest::instance()->add("User Id", m_strToken);
      UnmatchedMessageSegment::instance()->appendACTUAL_MSG(m_strToken);
      UnmatchedMessageSegment::instance()->appendACTUAL_MSG(">");
      return;
   }
   UnmatchedMessageSegment::instance()->appendACTUAL_MSG("<");
   UnmatchedMessageSegment::instance()->appendACTUAL_MSG(m_strToken);
   UnmatchedMessageSegment::instance()->appendACTUAL_MSG(">");
   if (m_strToken == "Image")
   {
      string strTemp;
      CaseManifest::instance()->get("NetworkID", strTemp);
      m_pImage = genericexception::CaseManifest::instance()->addImage(strTemp);
      CaseManifestSegment::instance()->setImageCount((CaseManifestSegment::instance()->getImageCount()) + 1);
      return;
   }
   if (m_strToken == "Lineitem")
   {
      m_pLineItem = genericexception::CaseManifest::instance()->addLineItem();
      return;
   }
   if (m_strToken == "AssociatedTran")
   {
      m_pAssociatedTran = genericexception::CaseManifest::instance()->addAssociatedTran();
      return;
   }

   if (m_strToken == "Amount"
      || m_strToken == "CAmount"
      || m_strToken == "CashbackAmount"
      || m_strToken == "DestAmount"
      || m_strToken == "DisputeAmt"
      || m_strToken == "MiscFeeAmount"
      || m_strToken == "NetworkReconAmount"
      || m_strToken == "SettlementAmount"
      || m_strToken == "TransactionAmount"
      || m_strToken == "DisputeAmount")
   {
      string strName(m_strToken);
      strName += " currency";
      pType = attributes.getValue("currency");
      getToken("BulkQuestionnaireHandler::startElement ", pType, XMLString::stringLen(pType));
      genericexception::CaseManifest::instance()->add(strName, m_strToken);
      return;
   }
   // Copy Requests and Fulfillments
   if (m_strToken == "RFCAdvice"
      || m_strToken == "RFCFulfillment"
      || m_strToken == "RFCNonFulfillment"
      || m_strToken == "RFCRejectReturn")
   {
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   // Questionnaires
   if (m_strToken == "Chargeback"
      || m_strToken == "Representment"
      || m_strToken == "PreArbResp"
      || m_strToken == "PreCompResp"
      || m_strToken == "Compliance"
      || m_strToken == "Recall"
      || m_strToken == "PreArbRecall"
      || m_strToken == "ArbRecall"
      || m_strToken == "PreCompRecall"
      || m_strToken == "CompRecall")
   {
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   //Collaboration
   if (m_strToken == "Collaboration"
      || m_strToken == "CollaborationResponse"
      || m_strToken == "CollaborationRequest")
   {
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   // Financials
   if (m_strToken == "Financial")
   {
      pType = attributes.getValue("type");
      getToken("BulkQuestionnaireHandler::startElement name= ", pType, XMLString::stringLen(pType));
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   if (m_strToken == "ChargebackAdvice"
      || m_strToken == "RepresentmentAdvice")
   {
      if (CaseManifestSegment::instance()->getFile() == "VRRDM5")
         genericexception::CaseManifest::instance()->setClass("Visa" + m_strToken);
      else
         genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   if (m_strToken == "ChargebackHold"
      || m_strToken == "ChargebackDocumentation"
      || m_strToken == "SecondChargebackDocumentation"
      || m_strToken == "DocumentAdd"
      || m_strToken == "UpdateStatus"
      || m_strToken == "AcceptDispute"
      || m_strToken == "ExtendDispute")
   {
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   // Adjustments
   if (m_strToken == "Adjustment")
   {
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   // GoodFaith
   if (m_strToken == "GoodFaith" || m_strToken == "GoodFaithResp")
   {
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   // Associated Transactions from DNRDM5
   if (m_strToken == "AssociateTransactions")
   {
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   // Multiple Transactions from DNRDM5
   if (m_strToken == "SelectTransaction")
   {
      genericexception::CaseManifest::instance()->setClass("TranInquiryResponse");
      return;
   }
   if (m_strToken == "Dispute")
   {
      genericexception::CaseManifest::instance()->setClass("ChargebackFinancial");
      return;
   }
   if (m_strToken == "DisputeResponse")
   {
      genericexception::CaseManifest::instance()->setClass("RepresentmentFinancial");
      return;
   }
   if (m_strToken == "ExceptionReview")
   {
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   if (m_strToken == "AcceptanceNotification")
   {
      genericexception::CaseManifest::instance()->setClass("UpdateStatus");
      genericexception::CaseManifest::instance()->add("Status", "Acceptance");
      return;
   }

   if (m_strToken == "DisputeFinancialAdvice"
      || m_strToken == "DisputeFinancial")
   {
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }

   // Pre-Filings
   if (m_strToken == "PreArb"
      || m_strToken == "DisputePreArb"
      || m_strToken == "PreArbResp"
      || m_strToken == "PartialPreArbResp"
      || m_strToken == "DisputePreArbResponse"
      || m_strToken == "PreComp"
      || m_strToken == "DisputePreComp"
      || m_strToken == "PreCompResp"
      || m_strToken == "DisputePreCompResponse")
   {
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   // Case Filings
   if (m_strToken == "Arbitration"
      || m_strToken == "ArbResp"
      || m_strToken == "Compliance"
      || m_strToken == "CompResp"
      || m_strToken == "CaseFilingRuling"
      || m_strToken == "NetworkRuling"
      || m_strToken == "Appeal")
   {
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   //voucher
   if (m_strToken == "VoucherResponse")
   {
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   if (m_strToken == "Letter")
   {
      pType = attributes.getValue("type");
      getToken("BulkQuestionnaireHandler::startElement ", pType, XMLString::stringLen(pType));
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   if (m_strToken == "FilingResp")
   {
      pType = attributes.getValue("type");
      getToken("BulkQuestionnaireHandler::startElement name= ", pType, XMLString::stringLen(pType));
      if (m_strToken == "Arbitration")
         genericexception::CaseManifest::instance()->setClass("ArbResp");
      else if (m_strToken == "Compliance")
         genericexception::CaseManifest::instance()->setClass("CompResp");
      else
         genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   if (m_strToken == "ContactMessage" || m_strToken == "AddComment" || m_strToken == "ProvCreditReview")
   {
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   // Miscellaneous Fees
   if (m_strToken == "MiscellaneousFee")
   {
      pType = attributes.getValue("type");
      getToken("BulkQuestionnaireHandler::startElement name= ", pType, XMLString::stringLen(pType));
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   // Fraud Reporting
   if (m_strToken == "FraudReport"
      || m_strToken == "FraudRejectReturn")
   {
      if (genericexception::CaseManifest::instance()->getClass() != "FraudRejectReturn")
         genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   // RepresenmentDocReject
   if (m_strToken == "RepresentmentDocReject")
   {
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
   if (m_strToken == "RepresentmentResponse")
   {
      genericexception::CaseManifest::instance()->setClass(m_strToken);
      return;
   }
  //## end visaexception::BulkQuestionnaireHandler::startElement%409A292F0261.body
}

// Additional Declarations
  //## begin visaexception::BulkQuestionnaireHandler%4097AF8203A9.declarations preserve=yes
  //## end visaexception::BulkQuestionnaireHandler%4097AF8203A9.declarations

} // namespace visaexception

//## begin module%4097B74F0109.epilog preserve=yes
//## end module%4097B74F0109.epilog
