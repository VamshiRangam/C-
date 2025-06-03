//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%4999BFC70251.cm preserve=no
//	$Date:   May 31 2019 03:53:34  $ $Author:   e5558744  $
//	$Revision:   1.6  $
//## end module%4999BFC70251.cm

//## begin module%4999BFC70251.cp preserve=no
//	Copyright (c) 1997 - 2012
//	FIS
//## end module%4999BFC70251.cp

//## Module: CXOSEC23%4999BFC70251; Package body
//## Subsystem: ECDLL%394E1F94006B
//## Source file: D:\V02.9D.R001\Dn\Server\Library\Ecdll\CXOSEC23.cpp

//## begin module%4999BFC70251.additionalIncludes preserve=no
//## end module%4999BFC70251.additionalIncludes

//## begin module%4999BFC70251.includes preserve=yes
#include "CXODIF03.hpp"
//## end module%4999BFC70251.includes

#ifndef CXOSRU11_h
#include "CXODRU11.hpp"
#endif
#ifndef CXOSRU12_h
#include "CXODRU12.hpp"
#endif
#ifndef CXOSDB02_h
#include "CXODDB02.hpp"
#endif
#ifndef CXOSRU20_h
#include "CXODRU20.hpp"
#endif
#ifndef CXOSMN05_h
#include "CXODMN05.hpp"
#endif
#ifndef CXOSBS09_h
#include "CXODBS09.hpp"
#endif
#ifndef CXOSRL04_h
#include "CXODRL04.hpp"
#endif
#ifndef CXOSES01_h
#include "CXODES01.hpp"
#endif
#ifndef CXOSBS12_h
#include "CXODBS12.hpp"
#endif
#ifndef CXOSEC23_h
#include "CXODEC23.hpp"
#endif


//## begin module%4999BFC70251.declarations preserve=no
//## end module%4999BFC70251.declarations

//## begin module%4999BFC70251.additionalDeclarations preserve=yes
//## end module%4999BFC70251.additionalDeclarations


//## Modelname: Transaction Research and Adjustments::EMSCommand_CAT%394E266C015B
namespace emscommand {
//## begin emscommand%394E266C015B.initialDeclarations preserve=yes
//## end emscommand%394E266C015B.initialDeclarations

// Class emscommand::RelatedCasesCommand 

RelatedCasesCommand::RelatedCasesCommand()
  //## begin RelatedCasesCommand::RelatedCasesCommand%4999B15C0186_const.hasinit preserve=no
  //## end RelatedCasesCommand::RelatedCasesCommand%4999B15C0186_const.hasinit
  //## begin RelatedCasesCommand::RelatedCasesCommand%4999B15C0186_const.initialization preserve=yes
  //## end RelatedCasesCommand::RelatedCasesCommand%4999B15C0186_const.initialization
{
  //## begin emscommand::RelatedCasesCommand::RelatedCasesCommand%4999B15C0186_const.body preserve=yes
   memcpy(m_sID,"EC23",4);
   m_pPrimaryKeySegment = new PrimaryKeySegment();
   m_hSegments.push_back(m_pPrimaryKeySegment);
  //## end emscommand::RelatedCasesCommand::RelatedCasesCommand%4999B15C0186_const.body
}

RelatedCasesCommand::RelatedCasesCommand (Handler* pSuccessor)
  //## begin emscommand::RelatedCasesCommand::RelatedCasesCommand%4999C1440290.hasinit preserve=no
  //## end emscommand::RelatedCasesCommand::RelatedCasesCommand%4999C1440290.hasinit
  //## begin emscommand::RelatedCasesCommand::RelatedCasesCommand%4999C1440290.initialization preserve=yes
   : ClientListCommand("S0003D","@##RELCASE")
  //## end emscommand::RelatedCasesCommand::RelatedCasesCommand%4999C1440290.initialization
{
  //## begin emscommand::RelatedCasesCommand::RelatedCasesCommand%4999C1440290.body preserve=yes
   memcpy(m_sID,"EC23",4);
   m_pSuccessor = pSuccessor;
   m_pPrimaryKeySegment = new PrimaryKeySegment();
   m_hSegments.push_back(m_pPrimaryKeySegment);
  //## end emscommand::RelatedCasesCommand::RelatedCasesCommand%4999C1440290.body
}


RelatedCasesCommand::~RelatedCasesCommand()
{
  //## begin emscommand::RelatedCasesCommand::~RelatedCasesCommand%4999B15C0186_dest.body preserve=yes
   delete m_pPrimaryKeySegment;
  //## end emscommand::RelatedCasesCommand::~RelatedCasesCommand%4999B15C0186_dest.body
}



//## Other Operations (implementation)
void RelatedCasesCommand::cleanup ()
{
  //## begin emscommand::RelatedCasesCommand::cleanup%5CE39B1B0167.body preserve=yes
   delete[] m_pszBuffer;
   m_pszBuffer = 0;
   delete m_pRow;
   m_pRow = 0;  
  //## end emscommand::RelatedCasesCommand::cleanup%5CE39B1B0167.body
}

bool RelatedCasesCommand::retrieve ()
{
  //## begin emscommand::RelatedCasesCommand::retrieve%4999C11E0128.body preserve=yes
   UseCase hUseCase("CLIENT","## EC23 LIST RELATED CASES");
   {
   m_pRow = new Row;
   m_pszBuffer = new char[m_hRelatedCaseSegment.size() + 1];
   m_hRelatedCaseSegment.reset();
   auto_ptr<SelectStatement>pSelectStatement((SelectStatement*)DatabaseFactory::instance()->create("SelectStatement"));
   if (m_pPrimaryKeySegment->getPrimaryKey().length() == 14) //case number came in
   {
      Query hQuery;
      hQuery.bind("EMS_CASE","TSTAMP_TRANS",Column::STRING,&m_strTSTAMP_TRANS);
      hQuery.bind("EMS_CASE","UNIQUENESS_KEY",Column::SHORT,&m_siUNIQUENESS_KEY);
      hQuery.bind("EMS_CASE","PAN",Column::STRING,&m_strPAN,0,0,2); 
      hQuery.bind("EMS_CASE","RETRIEVAL_REF_NO",Column::STRING,&m_strRETRIEVAL_REF_NO);
      hQuery.bind("EMS_CASE","SYS_TRACE_AUDIT_NO",Column::STRING,&m_strSYS_TRACE_AUDIT_NO);
      hQuery.bind("EMS_CASE","AMT_TRAN",Column::DOUBLE,&m_dAMT_TRAN);
      hQuery.setBasicPredicate("EMS_CASE","CASE_NO","=",m_pPrimaryKeySegment->getPrimaryKey().c_str());
      if (pSelectStatement->execute(hQuery) == false)
      {         
         sendError(STS_QUERY_ERROR,STS_ERROR,pSelectStatement->getInfoIDNumber(),false); 
         cleanup();
         return UseCase::setSuccess(false);
      }
      if (m_strPAN.empty())
      {
         cleanup();
         return true;
      }
   }
   else if (!m_pPrimaryKeySegment->get(m_strTSTAMP_TRANS, m_siUNIQUENESS_KEY))
   {
      sendError(STS_PARSE_ERROR,STS_ERROR,STS_MISSING_PRIMARYKEY_SEGMENT,false);
      cleanup();
      return false;
   }
   m_hRelatedCaseSegment.bind(m_hQuery);
   m_hQuery.bind("EMS_CASE","NET_RULES",Column::STRING,&m_strNET_RULES); 
   if (m_strTSTAMP_TRANS.length())
   {
      m_hQuery.setBasicPredicate("EMS_CASE","TSTAMP_TRANS","=",m_strTSTAMP_TRANS.c_str());
      m_hQuery.setBasicPredicate("EMS_CASE","UNIQUENESS_KEY","=",m_siUNIQUENESS_KEY);
      if (m_pPrimaryKeySegment->getPrimaryKey().length() == 14) //case number came in
         m_hQuery.setBasicPredicate("EMS_CASE","CASE_NO","<>",m_pPrimaryKeySegment->getPrimaryKey().c_str());
   }
   else
   {
      m_hQuery.setBasicPredicate("EMS_CASE","PAN","=",m_strPAN.c_str());
      m_hQuery.setBasicPredicate("EMS_CASE","RETRIEVAL_REF_NO","=",m_strRETRIEVAL_REF_NO.c_str());
      m_hQuery.setBasicPredicate("EMS_CASE","SYS_TRACE_AUDIT_NO","=",m_strSYS_TRACE_AUDIT_NO.c_str());
      m_hQuery.setBasicPredicate("EMS_CASE","AMT_TRAN","=",m_dAMT_TRAN);
      m_hQuery.setBasicPredicate("EMS_CASE","CASE_NO","<>",m_pPrimaryKeySegment->getPrimaryKey().c_str());
   }
   m_hQuery.attach(this);
   if (pSelectStatement->execute(m_hQuery) == false)
   {
      sendError(STS_QUERY_ERROR,STS_ERROR,pSelectStatement->getInfoIDNumber(),false);  
      cleanup();
      m_hQuery.reset();
      m_strPAN.wipe();//PCI-SSF Certification requirement
      return UseCase::setSuccess(false);
   }
   cleanup();
   m_hQuery.reset();
   }
   m_strPAN.wipe();//PCI-SSF Certification requirement
   return true;
  //## end emscommand::RelatedCasesCommand::retrieve%4999C11E0128.body
}

void RelatedCasesCommand::update (Subject* pSubject)
{
  //## begin emscommand::RelatedCasesCommand::update%4999C122035B.body preserve=yes
   if (pSubject == &m_hQuery)
   {
      string strState;
      strState.reserve(30);
      strState  = "STATE:";
      strState += m_hRelatedCaseSegment.getREQUEST_TYPE();
      strState += m_hRelatedCaseSegment.getSTATUS();  
      CaseSegment::instance()->setNET_RULES(m_strNET_RULES);
      RulesEngine::instance()->getDescription(strState,m_strStateDescription);
      m_hRelatedCaseSegment.setStateDescription(m_strStateDescription);
      char* p = m_pszBuffer;
      m_hRelatedCaseSegment.deport(&p);
      *p = '\0';
      m_pRow->getBuffer() = m_pszBuffer;
      ClientListCommand::update(m_pRow);
      UseCase::addItem();
      return;
   }
   ClientListCommand::update(pSubject);
  //## end emscommand::RelatedCasesCommand::update%4999C122035B.body
}

// Additional Declarations
  //## begin emscommand::RelatedCasesCommand%4999B15C0186.declarations preserve=yes
  //## end emscommand::RelatedCasesCommand%4999B15C0186.declarations

} // namespace emscommand

//## begin module%4999BFC70251.epilog preserve=yes
//## end module%4999BFC70251.epilog
