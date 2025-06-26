//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%6853CB7303A2.cm preserve=no
//## end module%6853CB7303A2.cm

//## begin module%6853CB7303A2.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%6853CB7303A2.cp

//## Module: CXOSJX44%6853CB7303A2; Package body
//## Subsystem: JXDLL%645AEC9A0298
//## Source file: C:\Repos\datanavigatorserver\Windows\Build\Dn\Server\Library\Jxdll\CXOSJX44.cpp

//## begin module%6853CB7303A2.additionalIncludes preserve=no
//## end module%6853CB7303A2.additionalIncludes

//## begin module%6853CB7303A2.includes preserve=yes
//## end module%6853CB7303A2.includes

#ifndef CXOSMN05_h
#include "CXODMN05.hpp"
#endif
#ifndef CXOSRU11_h
#include "CXODRU11.hpp"
#endif
#ifndef CXOSRU12_h
#include "CXODRU12.hpp"
#endif
#ifndef CXOSRU34_h
#include "CXODRU34.hpp"
#endif
#ifndef CXOSDB02_h
#include "CXODDB02.hpp"
#endif
#ifndef CXOSRL04_h
#include "CXODRL04.hpp"
#endif
#ifndef CXOSBS26_h
#include "CXODBS26.hpp"
#endif
#ifndef CXOSES01_h
#include "CXODES01.hpp"
#endif
#ifndef CXOSJX44_h
#include "CXODJX44.hpp"
#endif


//## begin module%6853CB7303A2.declarations preserve=no
//## end module%6853CB7303A2.declarations

//## begin module%6853CB7303A2.additionalDeclarations preserve=yes
//## end module%6853CB7303A2.additionalDeclarations


//## Modelname: DataNavigator Foundation::RESTCommand_CAT%645AEC55037E
namespace restcommand {
//## begin restcommand%645AEC55037E.initialDeclarations preserve=yes
//## end restcommand%645AEC55037E.initialDeclarations

// Class restcommand::RelatedCasesCommand 

RelatedCasesCommand::RelatedCasesCommand()
  //## begin RelatedCasesCommand::RelatedCasesCommand%6853CE640095_const.hasinit preserve=no
  //## end RelatedCasesCommand::RelatedCasesCommand%6853CE640095_const.hasinit
  //## begin RelatedCasesCommand::RelatedCasesCommand%6853CE640095_const.initialization preserve=yes
   :RESTCommand("/rest/datanavigator/resolve/relatedcases/v1.0.0", "S0003D", "@##JECASE ")
  //## end RelatedCasesCommand::RelatedCasesCommand%6853CE640095_const.initialization
{
  //## begin restcommand::RelatedCasesCommand::RelatedCasesCommand%6853CE640095_const.body preserve=yes
   memcpy(m_sID, "JX44", 4);
  //## end restcommand::RelatedCasesCommand::RelatedCasesCommand%6853CE640095_const.body
}

RelatedCasesCommand::RelatedCasesCommand (Handler* pSuccessor)
  //## begin restcommand::RelatedCasesCommand::RelatedCasesCommand%6853D2530341.hasinit preserve=no
  //## end restcommand::RelatedCasesCommand::RelatedCasesCommand%6853D2530341.hasinit
  //## begin restcommand::RelatedCasesCommand::RelatedCasesCommand%6853D2530341.initialization preserve=yes
   :RESTCommand("/rest/datanavigator/resolve/relatedcases/v1.0.0", "S0003D", "@##JECASE ")
  //## end restcommand::RelatedCasesCommand::RelatedCasesCommand%6853D2530341.initialization
{
  //## begin restcommand::RelatedCasesCommand::RelatedCasesCommand%6853D2530341.body preserve=yes
   memcpy(m_sID, "JX44", 4);
   m_pSuccessor = pSuccessor;
   m_hXMLText.add('R', &m_hGenericSegment);
   m_hXMLText.add('X', segment::SOAPSegment::instance());
   m_pXMLItem = new XMLItem();
   m_hQuery.attach(this);
  //## end restcommand::RelatedCasesCommand::RelatedCasesCommand%6853D2530341.body
}


RelatedCasesCommand::~RelatedCasesCommand()
{
  //## begin restcommand::RelatedCasesCommand::~RelatedCasesCommand%6853CE640095_dest.body preserve=yes
  //## end restcommand::RelatedCasesCommand::~RelatedCasesCommand%6853CE640095_dest.body
}



//## Other Operations (implementation)
bool RelatedCasesCommand::execute ()
{
  //## begin restcommand::RelatedCasesCommand::execute%6853D2BF015B.body preserve=yes
   UseCase hUseCase("CLIENT", "## JX44 READ RELATED CASES");
   if (!m_pXMLDocument)
#ifdef MVS
      m_pXMLDocument = new XMLDocument("JCL", "RJECASE", &m_hRow, &m_hXMLText);
#else
      m_pXMLDocument = new XMLDocument("SOURCE", "CXORJX44", &m_hRow, &m_hXMLText);
#endif
   m_pXMLDocument->reset();
   m_pXMLItem->reset();
   m_pXMLDocument->setMaximumSize(64000);
   m_pXMLDocument->setSuppressEmptyTags(false);
   m_hQuery.reset();
   int i = parse();
   if (i != 0)
   {
      SOAPSegment::instance()->setRtnCde('3');
      m_pXMLDocument->add("details");
      return reply();
   }
   m_pXMLDocument->add("root");
   //save();
   auto_ptr<SelectStatement> pSelectStatement((SelectStatement*)DatabaseFactory::instance()->create("SelectStatement"));
   if (!m_pXMLItem->get("caseNumber").empty() || !m_pXMLItem->get("primaryKey").empty())
   {
      if (!m_pXMLItem->get("caseNumber").empty())
      {
         m_hQuery.setIndex(1);
         m_hQuery.bind("EMS_CASE", "TSTAMP_TRANS", Column::STRING, &m_strTSTAMP_TRANS);
         m_hQuery.bind("EMS_CASE", "UNIQUENESS_KEY", Column::SHORT, &m_siUNIQUENESS_KEY);
         m_hQuery.bind("EMS_CASE", "PAN", Column::STRING, &m_strPAN, 0, 0, 2);
         m_hQuery.bind("EMS_CASE", "RETRIEVAL_REF_NO", Column::STRING, &m_strRETRIEVAL_REF_NO);
         m_hQuery.bind("EMS_CASE", "SYS_TRACE_AUDIT_NO", Column::STRING, &m_strSYS_TRACE_AUDIT_NO);
         m_hQuery.bind("EMS_CASE", "AMT_TRAN", Column::DOUBLE, &m_dAMT_TRAN);
         m_hQuery.setBasicPredicate("EMS_CASE", "CASE_NO", "=", m_pXMLItem->get("caseNumber").c_str());
         bool b = pSelectStatement->execute(m_hQuery);
         if (b == false
            || pSelectStatement->getRows() == 0 || m_strPAN.empty())
         {
            m_pXMLDocument->revert();
            SOAPSegment::instance()->setRtnCde(b ? '2' : '5');
            m_pXMLDocument->add("details");
            return reply();
         }
      }
      m_hQuery.reset();
      m_hQuery.setIndex(2);
      m_hRelatedCaseSegment.bind(m_hQuery);
      m_hQuery.bind("EMS_CASE", "NET_RULES", Column::STRING, &m_strNET_RULES);
      if (!m_pXMLItem->get("primaryKey").empty())
      {
         vector<string> hTokens;
         string strprimaryKey(m_pXMLItem->get("primaryKey"));
         Buffer::parse(strprimaryKey, ":", hTokens);
         if (hTokens.size() == 2)
         {
            m_hQuery.setBasicPredicate("EMS_CASE","TSTAMP_TRANS", "=", hTokens[0].c_str());
            m_hQuery.setBasicPredicate("EMS_CASE","UNIQUENESS_KEY", "=", atoi(hTokens[1].c_str()));
         }
         else
         {
            m_pXMLDocument->revert();
            SOAPSegment::instance()->setRtnCde('3');
            m_pXMLDocument->add("details");
            return reply();
         }
      }
      else
      {
         if (m_strTSTAMP_TRANS.length())
         {
            m_hQuery.setBasicPredicate("EMS_CASE","TSTAMP_TRANS", "=", m_strTSTAMP_TRANS.c_str());
            m_hQuery.setBasicPredicate("EMS_CASE","UNIQUENESS_KEY", "=", m_siUNIQUENESS_KEY);
            m_hQuery.setBasicPredicate("EMS_CASE","CASE_NO", "<>", m_pXMLItem->get("caseNumber").c_str());
         }
         else
         {
            m_hQuery.setBasicPredicate("EMS_CASE", "PAN", "=", m_strPAN.c_str());
            m_hQuery.setBasicPredicate("EMS_CASE", "RETRIEVAL_REF_NO", "=", m_strRETRIEVAL_REF_NO.c_str());
            m_hQuery.setBasicPredicate("EMS_CASE", "SYS_TRACE_AUDIT_NO", "=", m_strSYS_TRACE_AUDIT_NO.c_str());
            m_hQuery.setBasicPredicate("EMS_CASE", "AMT_TRAN", "=", m_dAMT_TRAN);
            m_hQuery.setBasicPredicate("EMS_CASE", "CASE_NO", "<>", m_pXMLItem->get("caseNumber").c_str());
         }
      }
      bool b = pSelectStatement->execute(m_hQuery);
      if (b == false
         || pSelectStatement->getRows() == 0)
      {
         m_pXMLDocument->revert();
         SOAPSegment::instance()->setRtnCde(b ? '2' : '5');
      }
   }
   else
      SOAPSegment::instance()->setRtnCde('3');
   m_pXMLDocument->add("details");
   return reply();
  //## end restcommand::RelatedCasesCommand::execute%6853D2BF015B.body
}

void RelatedCasesCommand::update (Subject* pSubject)
{
  //## begin restcommand::RelatedCasesCommand::update%6853D2F802A2.body preserve=yes
   if (m_hQuery.getIndex() == 2 && pSubject == &m_hQuery)
   {
      ++m_iRows;
      ++m_iTotalRows;
      string strState;
      strState.reserve(30);
      strState = "STATE:";
      strState += m_hRelatedCaseSegment.getREQUEST_TYPE();
      strState += m_hRelatedCaseSegment.getSTATUS();
      CaseSegment::instance()->setNET_RULES(m_strNET_RULES);
      RulesEngine::instance()->getDescription(strState, m_strStateDescription);
      m_hGenericSegment.set("CaseNumber", m_hRelatedCaseSegment.getCASE_NO());
      m_hGenericSegment.set("CaseTypeIndicator", m_hRelatedCaseSegment.getCASE_TYPE_IND());
      m_hGenericSegment.set("StateDescription", m_strStateDescription);
      m_hGenericSegment.set("TransactionAmount", m_hRelatedCaseSegment.getAMT_TRAN());
      m_hGenericSegment.set("AdjustmentAmount", m_hRelatedCaseSegment.getAMT_ADJUSTMENT());
      save();
      if(!m_pXMLDocument->add("row"))
      {
         m_pXMLDocument->revert();
         m_hQuery.setAbort(true);
         return;
      }
      UseCase::addItem();
      return;
   }
   command::RESTCommand::update(pSubject);
  //## end restcommand::RelatedCasesCommand::update%6853D2F802A2.body
}

// Additional Declarations
  //## begin restcommand::RelatedCasesCommand%6853CE640095.declarations preserve=yes
  //## end restcommand::RelatedCasesCommand%6853CE640095.declarations

} // namespace restcommand

//## begin module%6853CB7303A2.epilog preserve=yes
//## end module%6853CB7303A2.epilog
