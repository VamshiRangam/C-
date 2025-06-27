//## begin module%1.5%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.5%.codegen_version

//## begin module%4061FE8D005D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%4061FE8D005D.cm

//## begin module%4061FE8D005D.cp preserve=no
//	Copyright (c) 1998 - 2004
//	eFunds Corporation
//## end module%4061FE8D005D.cp

//## Module: CXOSEC20%4061FE8D005D; Package body
//## Subsystem: ECDLL%394E1F94006B
//## Source file: C:\Devel\Dn\Server\Library\Ecdll\CXOSEC20.cpp

//## begin module%4061FE8D005D.additionalIncludes preserve=no
//## end module%4061FE8D005D.additionalIncludes

//## begin module%4061FE8D005D.includes preserve=yes
// $Date:   Feb 08 2018 17:59:22  $ $Author:   e1009510  $ $Revision:   1.12  $
//## end module%4061FE8D005D.includes

#ifndef CXOSRU11_h
#include "CXODRU11.hpp"
#endif
#ifndef CXOSDB02_h
#include "CXODDB02.hpp"
#endif
#ifndef CXOSRU12_h
#include "CXODRU12.hpp"
#endif
#ifndef CXOSMN05_h
#include "CXODMN05.hpp"
#endif
#ifndef CXOSRU20_h
#include "CXODRU20.hpp"
#endif
#ifndef CXOSBS09_h
#include "CXODBS09.hpp"
#endif
#ifndef CXOSTM06_h
#include "CXODTM06.hpp"
#endif
#ifndef CXOSBS12_h
#include "CXODBS12.hpp"
#endif
#ifndef CXOSEC20_h
#include "CXODEC20.hpp"
#endif


//## begin module%4061FE8D005D.declarations preserve=no
//## end module%4061FE8D005D.declarations

//## begin module%4061FE8D005D.additionalDeclarations preserve=yes
//## end module%4061FE8D005D.additionalDeclarations


//## Modelname: Transaction Research and Adjustments::EMSCommand_CAT%394E266C015B
namespace emscommand {
//## begin emscommand%394E266C015B.initialDeclarations preserve=yes
//## end emscommand%394E266C015B.initialDeclarations

// Class emscommand::CaseHighlightCommand 

CaseHighlightCommand::CaseHighlightCommand()
  //## begin CaseHighlightCommand::CaseHighlightCommand%4061FE4102FD_const.hasinit preserve=no
  //## end CaseHighlightCommand::CaseHighlightCommand%4061FE4102FD_const.hasinit
  //## begin CaseHighlightCommand::CaseHighlightCommand%4061FE4102FD_const.initialization preserve=yes
  //## end CaseHighlightCommand::CaseHighlightCommand%4061FE4102FD_const.initialization
{
  //## begin emscommand::CaseHighlightCommand::CaseHighlightCommand%4061FE4102FD_const.body preserve=yes
   memcpy(m_sID,"EC20",4);
   m_pPrimaryKeySegment = new PrimaryKeySegment();
   m_hSegments.push_back(m_pPrimaryKeySegment);
  //## end emscommand::CaseHighlightCommand::CaseHighlightCommand%4061FE4102FD_const.body
}

CaseHighlightCommand::CaseHighlightCommand (Handler* pSuccessor)
  //## begin emscommand::CaseHighlightCommand::CaseHighlightCommand%4063032A001F.hasinit preserve=no
  //## end emscommand::CaseHighlightCommand::CaseHighlightCommand%4063032A001F.hasinit
  //## begin emscommand::CaseHighlightCommand::CaseHighlightCommand%4063032A001F.initialization preserve=yes
   : ClientListCommand("S0003D","@##EMLHIGH")
  //## end emscommand::CaseHighlightCommand::CaseHighlightCommand%4063032A001F.initialization
{
  //## begin emscommand::CaseHighlightCommand::CaseHighlightCommand%4063032A001F.body preserve=yes
   memcpy(m_sID,"EC20",4);
   m_pSuccessor = pSuccessor;
   m_pPrimaryKeySegment = new PrimaryKeySegment();
   m_hSegments.push_back(m_pPrimaryKeySegment);
  //## end emscommand::CaseHighlightCommand::CaseHighlightCommand%4063032A001F.body
}


CaseHighlightCommand::~CaseHighlightCommand()
{
  //## begin emscommand::CaseHighlightCommand::~CaseHighlightCommand%4061FE4102FD_dest.body preserve=yes
   delete m_pPrimaryKeySegment;
  //## end emscommand::CaseHighlightCommand::~CaseHighlightCommand%4061FE4102FD_dest.body
}



//## Other Operations (implementation)
bool CaseHighlightCommand::retrieve ()
{
  //## begin emscommand::CaseHighlightCommand::retrieve%4061FF1F003E.body preserve=yes
   UseCase hUseCase("CLIENT","## EC20 LIST CASE HIGHLIGHTS");
   {
   m_pRow = new Row;
   m_pszBuffer = new char[m_hCaseHighlightSegment.size() + 1];
   m_hCaseHighlightSegment.reset();
   m_hCaseHighlightSegment.setInstitution(m_pPrimaryKeySegment->getPrimaryKey());
   char* pszSide[6] =
   {
      "'A'",
      "'A'",
      "'A'",
      "'I'",
      "'I'",
      "'I'"
   };
   char* pszSTATUS[6] =
   {
      "'ZOPEN____'",
      "'ZCLOSED__'",
      "'ZREJECTED'",
      "'ZOPEN____'",
      "'ZCLOSED__'",
      "'ZREJECTED'"
   };
   int i = 0;
   Query hQuery[6];
   for (i = 0;i <= 5;++i)
   {
      if (i < 5)
         hQuery[i].setQuery(&hQuery[i + 1]);
      m_hCaseHighlightSegment.bind(hQuery[i],pszSide[i],pszSTATUS[i]);
      if (i < 3)
         hQuery[i].setBasicPredicate("EMS_CASE","INST_ID_RECON_ACQ","=",m_pPrimaryKeySegment->getPrimaryKey().c_str());
      else
         hQuery[i].setBasicPredicate("EMS_CASE","INST_ID_RECON_ISS","=",m_pPrimaryKeySegment->getPrimaryKey().c_str());
      if (i == 0 || i == 3)
         addPredicate(hQuery[i],"OPEN");
      else
      if (i == 1 || i == 4)
         addPredicate(hQuery[i],"CLOSED");
      else
         addPredicate(hQuery[i],"REJECTED");
   }
   m_hQuery = hQuery[0];
   hQuery[5].setOrderByClause("4,1");
   m_hQuery.attach(this);
   auto_ptr<SelectStatement>pSelectStatement((SelectStatement*)DatabaseFactory::instance()->create("SelectStatement"));
   if (pSelectStatement->execute(m_hQuery) == false)
   {
      sendError(STS_QUERY_ERROR,STS_ERROR,pSelectStatement->getInfoIDNumber(),false);
      UseCase::setSuccess(false);
   }
   if (pSelectStatement->getRows() > 0)
   {
      char* p = m_pszBuffer;
      m_hCaseHighlightSegment.deport(&p);
      *p = '\0';
      m_pRow->getBuffer() = m_pszBuffer;
      ClientListCommand::update(m_pRow);
      UseCase::addItem();
   }
   delete [] m_pszBuffer;
   m_pszBuffer = 0;
   delete m_pRow;
   m_pRow = 0;
   m_hQuery.reset();
   }
   return UseCase::getSuccess();
  //## end emscommand::CaseHighlightCommand::retrieve%4061FF1F003E.body
}

void CaseHighlightCommand::update (Subject* pSubject)
{
  //## begin emscommand::CaseHighlightCommand::update%4061FF21031C.body preserve=yes
   if (pSubject == &m_hQuery)
   {
      if (m_hCaseHighlightSegment.getSide()[1].length() > 0
         && (m_hCaseHighlightSegment.getSide()[0] != m_hCaseHighlightSegment.getSide()[1]
         || m_hCaseHighlightSegment.getNET_ID_EMS()[0] != m_hCaseHighlightSegment.getNET_ID_EMS()[1]))
      {
         char* p = m_pszBuffer;
         m_hCaseHighlightSegment.deport(&p);
         *p = '\0';
         m_hCaseHighlightSegment.resetCount();
         m_pRow->getBuffer() = m_pszBuffer;
         ClientListCommand::update(m_pRow);
         UseCase::addItem();
      }
      m_hCaseHighlightSegment.saveCount();
      return;
   }
   ClientListCommand::update(pSubject);
  //## end emscommand::CaseHighlightCommand::update%4061FF21031C.body
}

// Additional Declarations
  //## begin emscommand::CaseHighlightCommand%4061FE4102FD.declarations preserve=yes
void CaseHighlightCommand::addPredicate (Query& hQuery,const char* pszSTATUS)
{
   Date hDate(Date::today());
   string strDay(hDate.asString("%A"));
   if (strDay == "Monday")
      hDate -= 3;
   else
   if (strDay == "Sunday")
      hDate -= 2;
   else
      hDate -= 1;
   string strDate(hDate.asString("%Y%m%d00000000"));
   bool bAND = (strcmp(pszSTATUS,"ALL") != 0);
   if (strcmp(pszSTATUS,"ALL") == 0)
      hQuery.getSearchCondition() += "(";
   if (strcmp(pszSTATUS,"OPEN") == 0
      || strcmp(pszSTATUS,"ALL") == 0)
   {
      hQuery.setBasicPredicate("EMS_CASE","STATUS","NOT LIKE","CL__");
      hQuery.setBasicPredicate("EMS_CASE","STATUS","NOT IN",
            "('REJR','REJU','RERU','REVR')");
   }
   if (strcmp(pszSTATUS,"ALL") == 0)
      hQuery.getSearchCondition() += " OR ((";
   if (strcmp(pszSTATUS,"CLOSED") == 0
      || strcmp(pszSTATUS,"ALL") == 0)
   {
      hQuery.setBasicPredicate("EMS_CASE","STATUS","LIKE","CL__");
   }
   if (strcmp(pszSTATUS,"REJECTED") == 0
      || strcmp(pszSTATUS,"ALL") == 0)
   {
      hQuery.setBasicPredicate("EMS_CASE","STATUS","IN",
         "('REJR','REJU','RERU','REVR')",false,bAND);
   }
   if (strcmp(pszSTATUS,"ALL") == 0)
      hQuery.getSearchCondition() += ")";
   if (strcmp(pszSTATUS,"OPEN") != 0)
      hQuery.setBasicPredicate("EMS_CASE","TSTAMP_UPDATED",">",strDate.c_str());
   if (strcmp(pszSTATUS,"ALL") == 0)
      hQuery.getSearchCondition() += "))";
}
  //## end emscommand::CaseHighlightCommand%4061FE4102FD.declarations
} // namespace emscommand

//## begin module%4061FE8D005D.epilog preserve=yes
//## end module%4061FE8D005D.epilog
