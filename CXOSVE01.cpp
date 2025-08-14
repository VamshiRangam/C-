//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%4097A670036B.cm preserve=no
//	$Date:   May 26 2020 19:24:58  $ $Author:   e1009510  $
//	$Revision:   1.84  $
//## end module%4097A670036B.cm

//## begin module%4097A670036B.cp preserve=no
//	Copyright (c) 1997 - 2012
//	FIS
//## end module%4097A670036B.cp

//## Module: CXOSVE01%4097A670036B; Package body
//## Subsystem: VEDLL%4097A62502BF
//## Source file: C:\devel\Dn\Server\Library\Vedll\CXOSVE01.cpp

//## begin module%4097A670036B.additionalIncludes preserve=no
//## end module%4097A670036B.additionalIncludes

//## begin module%4097A670036B.includes preserve=yes
// This product includes software developed by the Apache Software Foundation (http://www.apache.org/).
#ifdef _WIN32
#include "xercesc\framework\MemBufInputSource.hpp"
#include "xercesc\util\PlatformUtils.hpp"
#include "xercesc\parsers\SAXParser.hpp"
#else
#include "xercesc/framework/MemBufInputSource.hpp"
#include "xercesc/util/PlatformUtils.hpp"
#include "xercesc/parsers/SAXParser.hpp"
#endif
#include "CXODIF05.hpp"
#include "CXODEX01.hpp"
#include "CXODRU10.hpp"
#include "CXODTM02.hpp"
#include "CXODRU37.hpp"
#include "CXODES66.hpp"
#include "CXODES67.hpp"
#include "CXODGE58.hpp"
#include "CXODGE08.hpp"  //Case
#include "CXODIF15.hpp"
#include "CXODIF16.hpp"
#include "CXODRS97.hpp"
#ifndef CXOSCF01_h
#include "CXODCF01.hpp"
#endif
#ifndef CXOSGE52_h
#include "CXODGE52.hpp"
#endif
//## end module%4097A670036B.includes

#ifndef CXOSIF04_h
#include "CXODIF04.hpp"
#endif
#ifndef CXOSIF03_h
#include "CXODIF03.hpp"
#endif
#ifndef CXOSDB04_h
#include "CXODDB04.hpp"
#endif
#ifndef CXOSPS01_h
#include "CXODPS01.hpp"
#endif
#ifndef CXOSDB01_h
#include "CXODDB01.hpp"
#endif
#ifndef CXOSMN05_h
#include "CXODMN05.hpp"
#endif
#ifndef CXOSIF10_h
#include "CXODIF10.hpp"
#endif
#ifndef CXOSIF44_h
#include "CXODIF44.hpp"
#endif
#ifndef CXOSIF01_h
#include "CXODIF01.hpp"
#endif
#ifndef CXOSVE07_h
#include "CXODVE07.hpp"
#endif
#ifndef CXOSVE08_h
#include "CXODVE08.hpp"
#endif
#ifndef CXOSEX17_h
#include "CXODEX17.hpp"
#endif
#ifndef CXOSEX28_h
#include "CXODEX28.hpp"
#endif
#ifndef CXOSTM04_h
#include "CXODTM04.hpp"
#endif
#ifndef CXOSGE02_h
#include "CXODGE02.hpp"
#endif
#ifndef CXOSDB02_h
#include "CXODDB02.hpp"
#endif
#ifndef CXOSRU08_h
#include "CXODRU08.hpp"
#endif
#ifndef CXOSVE02_h
#include "CXODVE02.hpp"
#endif
#ifndef CXOSVE17_h
#include "CXODVE17.hpp"
#endif
#ifndef CXOSVE01_h
#include "CXODVE01.hpp"
#endif


//## begin module%4097A670036B.declarations preserve=no
//## end module%4097A670036B.declarations

//## begin module%4097A670036B.additionalDeclarations preserve=yes
//## end module%4097A670036B.additionalDeclarations


//## Modelname: Transaction Research and Adjustments::VisaException_CAT%4097A16101D4
namespace visaexception {
//## begin visaexception%4097A16101D4.initialDeclarations preserve=yes
//## end visaexception%4097A16101D4.initialDeclarations

// Class visaexception::BulkQuestionnaireImport 

BulkQuestionnaireImport::BulkQuestionnaireImport()
  //## begin BulkQuestionnaireImport::BulkQuestionnaireImport%4097A5B20128_const.hasinit preserve=no
      : m_bBilling(true),
        m_pBulkQuestionnaireHandler(0),
        m_pResponseHandler(0)
  //## end BulkQuestionnaireImport::BulkQuestionnaireImport%4097A5B20128_const.hasinit
  //## begin BulkQuestionnaireImport::BulkQuestionnaireImport%4097A5B20128_const.initialization preserve=yes
  //## end BulkQuestionnaireImport::BulkQuestionnaireImport%4097A5B20128_const.initialization
{
  //## begin visaexception::BulkQuestionnaireImport::BulkQuestionnaireImport%4097A5B20128_const.body preserve=yes
   memcpy(m_sID,"VE01",4);
   XMLPlatformUtils::Initialize();
   m_pBulkQuestionnaireHandler = new BulkQuestionnaireHandler();
   m_pResponseHandler = new ResponseHandler();
   MinuteTimer::instance()->attach(this);
  //## end visaexception::BulkQuestionnaireImport::BulkQuestionnaireImport%4097A5B20128_const.body
}


BulkQuestionnaireImport::~BulkQuestionnaireImport()
{
  //## begin visaexception::BulkQuestionnaireImport::~BulkQuestionnaireImport%4097A5B20128_dest.body preserve=yes
   MinuteTimer::instance()->detach(this);
   delete m_pResponseHandler;
   delete m_pBulkQuestionnaireHandler;
   XMLPlatformUtils::Terminate();
  //## end visaexception::BulkQuestionnaireImport::~BulkQuestionnaireImport%4097A5B20128_dest.body
}



//## Other Operations (implementation)
bool BulkQuestionnaireImport::execute (const char* pszBatch, const char* pszResponse, visaexception::DNHandlerBase* pDNHandlerBase)
{
  //## begin visaexception::BulkQuestionnaireImport::execute%4097E68503C8.body preserve=yes
   UseCase hUseCase("DR","## DR40 IMPORT VISA BQI",true,true);
   ems::Case::resetSegments();
   GenerationDataGroup hGenerationDataGroup1(Application::instance()->image(),Application::instance()->name(),pszBatch);
   GenerationDataGroup hGenerationDataGroup2(Application::instance()->image(),Application::instance()->name(),pszResponse);	
   string strYYYYMMDD(Clock::instance()->getYYYYMMDDHHMMSS().data(),8);
   bool bReturn = true;
   if (parseFile(BatchDescriptorHandler::instance(),hGenerationDataGroup1,false))
   {      
      string strName(hGenerationDataGroup1.datasetName());
      Trace::put("strName");
      Trace::put(strName.c_str());
      string strKey("DFILES  ");
      strKey.append(pszResponse);
      strKey.resize(16,' ');
      strName.insert(0, strKey);
      size_t pos = strName.find(BatchDescriptorHandler::instance()->getFileName());
      for (int i = 0; i < BatchDescriptorHandler::instance()->getPackageCount(); ++i)
      {
         if (pos != string::npos)
            strName.replace(pos,8,BatchDescriptorHandler::instance()->getPackageName(i));
#ifndef MVS
         Trace::put(strName.c_str());
         IF::Extract::instance()->setRecord(strKey.c_str(), strName);         
#endif
         bReturn = hGenerationDataGroup2.open(FlatFile::CX_OPEN_INPUT);
         if (strcmp(pszResponse, "DNRDM5") == 0 || strcmp(pszResponse, "VRRDM5") == 0)
         {
            pDNHandlerBase->setSchemaCheck(true);    
            if (genericexception::Extract::instance()->haveBillableEntities() &&
               strcmp(pszResponse,"DNRDM5") == 0 && m_bBilling &&
               genericexception::Extract::instance()->isBillableEntity(emssegment::BatchDescriptorSegment::instance()->getPROC_ID()))
               writeFeeBilling(hGenerationDataGroup2.datasetName());
            if (bReturn == false || parseFile(pDNHandlerBase,hGenerationDataGroup2,true) == false)
            {               
               int lGMTOffset = 6; // !!!
               char szTIMESTAMP[7 * PERCENTD];
               Object::snprintf(szTIMESTAMP,sizeof(szTIMESTAMP),"%d-%02d-%02dT%02d:%02d:%02d-%02d:00",
                  Clock::instance()->getYear(),Clock::instance()->getMonth(),Clock::instance()->getDay(),
                  Clock::instance()->getHour(),Clock::instance()->getMinute(),Clock::instance()->getSecond(),
                  lGMTOffset);
               emssegment::BatchDescriptorSegment::instance()->setTIMESTAMP(szTIMESTAMP);
               genericexception::CaseManifest::instance()->beginImportAudit("AUDRM5");
               genericexception::CaseManifest::instance()->getAudit()->report('E');
               genericexception::CaseManifest::instance()->endAudit();
               if (BatchDescriptorSegment::instance()->getMESSAGE().empty())
               {
                  BatchDescriptorSegment::instance()->setCODE("E-00000001");
                  BatchDescriptorSegment::instance()->setMESSAGE("XML content error or no RDM5 file");
               }
               if (strcmp(pszResponse, "DNRDM5") == 0)
               {
                  genericexception::ProcessingReportDownloadResponseDescriptor *pProcessingReportDownloadResponseDescriptor;
                  pProcessingReportDownloadResponseDescriptor = new genericexception::ProcessingReportDownloadResponseDescriptor;
                  Clock::instance()->setHundredths(99);
                  string strTime = Clock::instance()->getYYYYMMDDHHMMSSHN(true).substr(8,6);
                  pProcessingReportDownloadResponseDescriptor->deport(strYYYYMMDD,strTime);
                  delete pProcessingReportDownloadResponseDescriptor;
                  BatchDescriptorSegment::instance()->setMESSAGE("");
                  hGenerationDataGroup1.commit();
                  if (bReturn) //had a RDM5 file so need to update task context for when customer sends in a new DM5 to us
                     hGenerationDataGroup2.commit();
                  return true;
               }
               BatchDescriptorSegment::instance()->setMESSAGE("");
               return false;
            }
         }
         hGenerationDataGroup2.close();
         pDNHandlerBase->setSchemaCheck(false);
         GenerationDataGroup hGenerationDataGroup3(Application::instance()->image(),Application::instance()->name(),pszResponse);	
         if (!parseFile(pDNHandlerBase,hGenerationDataGroup3,true))
         {            
            if (BatchDescriptorSegment::instance()->getMESSAGE() == "INTERNAL")
               Console::display("ST545", "VRRDM5"); // ST545 - PROCESSING NOT COMPLETE FOR @@@ IMPORT FILE.
            if (CaseManifestSegment::instance()->getFile() == "DNRDM5" && BatchDescriptorSegment::instance()->getMESSAGE() != "INTERNAL")
            {
               BatchDescriptorSegment::instance()->setCODE("E-00000001");
               genericexception::ProcessingReportDownloadResponseDescriptor *pProcessingReportDownloadResponseDescriptor;
               pProcessingReportDownloadResponseDescriptor = new genericexception::ProcessingReportDownloadResponseDescriptor;
               Clock::instance()->setHundredths(99);
               string strTime = Clock::instance()->getYYYYMMDDHHMMSSHN(true).substr(8,6);
               pProcessingReportDownloadResponseDescriptor->deport(strYYYYMMDD,strTime);
               delete pProcessingReportDownloadResponseDescriptor;
#ifndef MVS
               if (!hGenerationDataGroup3.commit())
                  return false;
            }
            int j = i;
            if (++j >= BatchDescriptorHandler::instance()->getPackageCount())
            {
               if (hGenerationDataGroup1.commit())
                  bReturn = hGenerationDataGroup3.commit();
               else
                  return false;
               return bReturn;
            }
#else
            }
            return false;
#endif
         }
         hGenerationDataGroup3.commit();
      }
   }
   else
      return false;

   hGenerationDataGroup1.commit();
   if (Database::instance()->transactionState() == Database::ROLLBACKREQUIRED)
	   Database::instance()->rollback();
   else
	   Database::instance()->commit();

   reusable::Transaction::instance()->setQualifier("CUSTQUAL");
   if (strcmp(pszBatch,"VRBDM5") == 0)
   {
      string strScript("VRDDM5");
#ifdef MVS
      string strTemplate("JCL");
      string strMember("DN##DDM5");
      string strJob("DN##XDM5");
#else
      string strTemplate("SOURCE");
      string strMember("CXOXVE01");
      string strJob("CXOXVE05");
#endif
      submit(strTemplate,strMember,strScript,strJob,1);
      // eFunds data center second script to handle images for WTS
      IString strBuffer;
      IF::Extract::instance()->get("DFILES  VRDDM5C ",strBuffer);
      if (strBuffer.length() > 0)
      {
         strScript = "VRDDM5C";
         strTemplate = "TEMPLATE";
         strMember = "DNDNDDM5";
         strJob = "DNDNXDM5";
         submit(strTemplate,strMember,strScript,strJob,0);
      }
   }
   delete genericexception::CaseManifest::instance();
   return true;
  //## end visaexception::BulkQuestionnaireImport::execute%4097E68503C8.body
}

bool BulkQuestionnaireImport::parseFile (visaexception::DNHandlerBase* pDNHandlerBase, database::GenerationDataGroup& hGenerationDataGroup, bool bAudit)
{
  //## begin visaexception::BulkQuestionnaireImport::parseFile%420D1F9A0261.body preserve=yes
   int lRecordCount = 0;
   size_t lByteCount = 0;
   size_t lMaxRecordLength = 0;
   if (!hGenerationDataGroup.getSize(&lRecordCount, &lByteCount, &lMaxRecordLength, true) )
      return UseCase::setSuccess(false);
   if (lByteCount > INT_MAX - 4097)
      return UseCase::setSuccess(false);
   char* psMemBufInputSource = new char[lByteCount + 1 + 4096];
   if (!psMemBufInputSource)
      return UseCase::setSuccess(false);
   char* p = psMemBufInputSource;
   char* q = 0;
   size_t m = 0;
   int n = lByteCount + 1;
   while (n > 1 && hGenerationDataGroup.read(p,n,&m,false,true))
   {
      p += m;
      n -= m;
   }
   *p = '\0';
   char escChar[6][7] = {"&quot;","&apos;","&amp;","&gt;","&lt;","&"};
   int cmpLen[6] = {6,6,5,4,4,1};
   int repLen[6] = {6,6,0,0,0,1};
   unsigned char substituteChar[5][2] = {'|',' ','[','(',']',')',0xBA,'(',0xBB,')'};
   for(int i = 0; i < lByteCount; i++)
   {
      if(memcmp(psMemBufInputSource+i,"<QuestionnaireData",18) == 0  && hGenerationDataGroup.getCONTEXT_KEY() == "DNRDM5")
      {  //convert questionnaire data into a single element
         int k = 18;
         while(psMemBufInputSource[i+k] != '>') //handle spaces before ending >
            k++;
         k++;
         while(memcmp(psMemBufInputSource+i+k,"</QuestionnaireData>",20) != 0 && 
               (i+k) < lByteCount) 
         {
            if(psMemBufInputSource[i+k] == '<')
               psMemBufInputSource[i+k] = '{';
            if(psMemBufInputSource[i+k] == '>')
               psMemBufInputSource[i+k] = '}';
            k++;
         }
         i += k+19;
      }
      else if(memcmp(psMemBufInputSource+i,"&#",2) == 0)
      {  //examples: &#39; &#x27; &#x01cd;
         for(int j = 3; j < 12; j++)
         {
            if(psMemBufInputSource[i+j] == ';')
            {
               memset(psMemBufInputSource+i,' ',j+1);
               i += j;
               break;
            }
         }
      }
      else if(psMemBufInputSource[i] == '&')
      {  //blank out or skip over unwanted escape sequences
         for(int j = 0; j < 6; j++)
         {
            if(memcmp(psMemBufInputSource+i,&escChar[j][0],cmpLen[j]) == 0)
            {
               memcpy(psMemBufInputSource+i,psMemBufInputSource+i+repLen[j],strlen(psMemBufInputSource+i+repLen[j]));
               if (repLen[j] > 0)
                  lByteCount -= repLen[j];
               else
                  i += cmpLen[j]-1;
               break;
            }
         }
      }
      else
      {
         for(int j = 0; j < 5; j++)
         {  //replace characters
            if(psMemBufInputSource[i] == substituteChar[j][0])
            {
               psMemBufInputSource[i] = substituteChar[j][1];
               break;
            }
         }
      }
   }
   psMemBufInputSource[lByteCount] = '\0';
#ifdef MVS
   CodeTable::translate(psMemBufInputSource,lByteCount,CodeTable::CX_EBCDIC_TO_ASCII);
#endif
   for(int i = 0; i < lByteCount; i++)
   {
      if ((psMemBufInputSource[i] < 0x20) || (psMemBufInputSource[i] > 0x7E))
         psMemBufInputSource[i] = 0x20;
   }
   XMLCh sBufld[2] = {1,0};
   if (bAudit)
      pDNHandlerBase->initializeAudit(hGenerationDataGroup.getCONTEXT_KEY(),hGenerationDataGroup.datasetName());
   MemBufInputSource hMemBufInputSource((XMLByte*)psMemBufInputSource,(unsigned int)lByteCount,&sBufld[0]);
   SAXParser hSAXParser;
   hSAXParser.setDocumentHandler(pDNHandlerBase);
   hSAXParser.setErrorHandler(pDNHandlerBase);
   hSAXParser.parse(hMemBufInputSource);
   delete [] psMemBufInputSource;
   if (pDNHandlerBase->getAbort())
      return UseCase::setSuccess(false);
   return true;
  //## end visaexception::BulkQuestionnaireImport::parseFile%420D1F9A0261.body
}

bool BulkQuestionnaireImport::submit (const string& strTemplate, const string& strMember, const string& strScript, const string& strJob, int iPath)
{
  //## begin visaexception::BulkQuestionnaireImport::submit%413DDF20003E.body preserve=yes
   IF::FlatFile hTemplate(strTemplate.c_str(),strMember.c_str());
   IF::FlatFile hScript(strScript.c_str());
   string strBuffer;
   Memory hMemory(260);
   memset((char*)hMemory,0x00,4);
   short int* pi = (short int*)(char*)hMemory;
   size_t m = 0;
   while (hTemplate.read(((char*)hMemory) + 4,256,&m))
   {
      strBuffer.assign(((char*)hMemory) + 4,m);
      size_t n = strBuffer.find_last_not_of(' ');
      strBuffer.erase(n + 1);
      SiteSpecification::instance()->substitute(strBuffer);
      size_t pos;
      if (strBuffer.find("del ") != string::npos
         && (pos = strBuffer.find("TDM5nnnn.tif")) != string::npos)
      {
         int i = 0;
         string strDOC_PATH;
         while (genericexception::CaseManifest::instance()->getDOC_PATH(iPath,i++,strDOC_PATH))
         {
            strBuffer.replace(pos,12,strDOC_PATH);
            *pi = strBuffer.length() + 4;
            memcpy(((char*)hMemory) + 4,strBuffer.data(),strBuffer.length());
#ifdef MVS
            hScript.write((char*)hMemory,strBuffer.length() + 4);
#else
            hScript.write((char*)hMemory + 4,strBuffer.length());
#endif
         }
      }
      if (strBuffer.find("ren ") != string::npos
         && (pos = strBuffer.find("TDM5")) != string::npos)
      {
         string strDOC_PATH;
         int i = 0;
         int iPath1 = (iPath == 0 ? 1 : 0);
         while (genericexception::CaseManifest::instance()->getDOC_PATH(iPath1,i++,strDOC_PATH))
         {
            strBuffer.resize(pos);
            size_t pos1 = strDOC_PATH.find(".");
            strBuffer.append(strDOC_PATH,0,pos1);
            strBuffer.append(" ");
            strBuffer.append(strDOC_PATH);
            *pi = strBuffer.length() + 4;
            memcpy(((char*)hMemory) + 4,strBuffer.data(),strBuffer.length());
#ifdef MVS
            hScript.write((char*)hMemory,strBuffer.length() + 4);
#else
            hScript.write((char*)hMemory + 4,strBuffer.length());
#endif
         }
      }
      else
      {
         *pi = strBuffer.length() + 4;
         memcpy(((char*)hMemory) + 4,strBuffer.data(),strBuffer.length());
#ifdef MVS
         hScript.write((char*)hMemory,strBuffer.length() + 4);
#else
         hScript.write((char*)hMemory + 4,strBuffer.length());
#endif
	  }
   }
   string strBATCH("&BATCH.");
   if (!SiteSpecification::instance()->substitute(strBATCH))
      return false;
   string strDOCPKG("&DOCPKG.");
   if (!SiteSpecification::instance()->substitute(strDOCPKG))
      return false;
   string strNetID("&NETID.");
   if (!SiteSpecification::instance()->substitute(strNetID))
      return false;
   string strDOCNET("&DOCNET.");
   if (!SiteSpecification::instance()->substitute(strDOCNET))
      return false;   
   Job::submit(strJob.c_str(),"&BATCH  ",strBATCH.c_str(),"&DOCPKG ",strDOCPKG.c_str(),"&NETID  ",strNetID.c_str(),"&DOCNET ",strDOCNET.c_str());   
   return true;
  //## end visaexception::BulkQuestionnaireImport::submit%413DDF20003E.body
}

void BulkQuestionnaireImport::update (Subject* pSubject)
{
  //## begin visaexception::BulkQuestionnaireImport::update%4097A71E03D8.body preserve=yes
   if (pSubject == MinuteTimer::instance()
      || pSubject == 0)
#ifdef MVS
      if (Clock::instance()->getMinute() == 0
         || pSubject == 0)
#endif
      {         
         bool bContinue = true;
         string strRecord;
         string strCustomer;
         IF::Extract::instance()->getSpec("CUSTOMER",strCustomer);
         while (bContinue)
         {
            bContinue = false;
            genericexception::CaseManifest::instance()->reset();
            genericexception::Case::instance()->reset();
            reusable::Transaction::instance()->begin();
            reusable::Transaction::instance()->setTimeStamp(Clock::instance()->getYYYYMMDDHHMMSS(true) += "00");
            BatchDescriptorSegment::instance()->setMESSAGE("");
            EMSRulesEngine::instance()->reset();
            m_pBulkQuestionnaireHandler->reset();
            BatchDescriptorHandler::instance()->reset();
            CaseManifestSegment::instance()->reset();
            NationalException::instance()->setQualifierFromNetwork(strCustomer);
            if (IF::Extract::instance()->getRecord("DFILES  VRBDM5  ",strRecord))
               bContinue = bContinue || execute("VRBDM5","VRRDM5",m_pBulkQuestionnaireHandler);
            if (IF::Extract::instance()->getRecord("DFILES  DNBDM5  ",strRecord))
            {
               CaseManifestSegment::instance()->setFile("DNRDM5");
               bContinue = bContinue || execute("DNBDM5","DNRDM5",m_pBulkQuestionnaireHandler);
               CaseManifestSegment::instance()->setFile("");
            }
            if (IF::Extract::instance()->getRecord("DFILES  VRBDM3  ",strRecord))
               bContinue = bContinue || execute("VRBDM3","VRRDM3",m_pResponseHandler);
            if (IF::Extract::instance()->getRecord("DFILES  DNBDM3  ",strRecord))
               bContinue = bContinue || execute("DNBDM3","DNRDM3",m_pResponseHandler);         
            if (Database::instance()->transactionState() == Database::ROLLBACKREQUIRED)
               Database::instance()->rollback();
            else
               Database::instance()->commit();
            reusable::Transaction::instance()->commit();
            NationalException::instance()->setQualifierFromNetwork(strCustomer);
         }
      }      
  //## end visaexception::BulkQuestionnaireImport::update%4097A71E03D8.body
}

void BulkQuestionnaireImport::writeFeeBilling (const string& strFeeData)
{
  //## begin visaexception::BulkQuestionnaireImport::writeFeeBilling%559D15E1007A.body preserve=yes
   repositorysegment::FeeBillingSegment::instance()->reset();
   Table hTable("FEE_BILLING");
   auto_ptr<Statement> pInsertStatement((Statement*)DatabaseFactory::instance()->create("InsertStatement"));
   repositorysegment::FeeBillingSegment::instance()->setFEE_DATE(Clock::instance()->getYYYYMMDDHHMMSS().substr(0,8));
   repositorysegment::FeeBillingSegment::instance()->setFEE_TIME(Clock::instance()->getYYYYMMDDHHMMSS().substr(8,4));
   repositorysegment::FeeBillingSegment::instance()->setENTITY_ID(emssegment::BatchDescriptorSegment::instance()->getPROC_ID());
   repositorysegment::FeeBillingSegment::instance()->setFEE_TYPE("DNRDM5");
   repositorysegment::FeeBillingSegment::instance()->setFEE_DATA(strFeeData);//GDG NUMBER OR PATH OF THE FILE
   string strApplNo;
   IF::Extract::instance()->getSpec("APPLNO",strApplNo);
   strApplNo.resize(5,' ');
   string strItemNo;
   IF::Extract::instance()->getSpec("ITEMNO",strItemNo);
   strItemNo.resize(5,' ');
   repositorysegment::FeeBillingSegment::instance()->setFEE_BILLING_CODE(strApplNo + strItemNo); 
   string strBANK_ID("UNKNOWN");
   ConfigurationRepository::instance()->translate("INST_BANK_ID",
      emssegment::BatchDescriptorSegment::instance()->getPROC_ID(),strBANK_ID," "," ",0,false);
   repositorysegment::FeeBillingSegment::instance()->setCUST_NO(strBANK_ID);
   repositorysegment::FeeBillingSegment::instance()->setITEM_COUNT(1);
   repositorysegment::FeeBillingSegment::instance()->setColumns(hTable);
   if(!pInsertStatement->execute(hTable))
   {
      Database::instance()->rollback();
      UseCase::setSuccess(false);
   } 
  //## end visaexception::BulkQuestionnaireImport::writeFeeBilling%559D15E1007A.body
}

// Additional Declarations
  //## begin visaexception::BulkQuestionnaireImport%4097A5B20128.declarations preserve=yes
  //## end visaexception::BulkQuestionnaireImport%4097A5B20128.declarations

} // namespace visaexception

//## begin module%4097A670036B.epilog preserve=yes
//## end module%4097A670036B.epilog
