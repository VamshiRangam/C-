//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%59684E8D00B5.cm preserve=no
//	$Date:   Nov 08 2017 09:19:52  $ $Author:   E5350313  $
//	$Revision:   1.5  $
//## end module%59684E8D00B5.cm

//## begin module%59684E8D00B5.cp preserve=no
//	Copyright (c) 1997 - 2012
//	FIS
//## end module%59684E8D00B5.cp

//## Module: CXOSSX25%59684E8D00B5; Package body
//## Subsystem: SXDLL%4DC063A90266
//## Source file: C:\Devel.May\Dn\Server\Library\Sxdll\CXOSSX25.cpp

//## begin module%59684E8D00B5.additionalIncludes preserve=no
//## end module%59684E8D00B5.additionalIncludes

//## begin module%59684E8D00B5.includes preserve=yes
#include "CXODBC41.hpp"
#include "CXODTM04.hpp"
//## end module%59684E8D00B5.includes

#ifndef CXOSSX26_h
#include "CXODSX26.hpp"
#endif
#ifndef CXOSRU12_h
#include "CXODRU12.hpp"
#endif
#ifndef CXOSDB02_h
#include "CXODDB02.hpp"
#endif
#ifndef CXOSMN05_h
#include "CXODMN05.hpp"
#endif
#ifndef CXOSBS26_h
#include "CXODBS26.hpp"
#endif
#ifndef CXOSES85_h
#include "CXODES85.hpp"
#endif
#ifndef CXOSDB01_h
#include "CXODDB01.hpp"
#endif
#ifndef CXOSBS06_h
#include "CXODBS06.hpp"
#endif
#ifndef CXOSRU19_h
#include "CXODRU19.hpp"
#endif
#ifndef CXOSSX25_h
#include "CXODSX25.hpp"
#endif


//## begin module%59684E8D00B5.declarations preserve=no
//## end module%59684E8D00B5.declarations

//## begin module%59684E8D00B5.additionalDeclarations preserve=yes
//## end module%59684E8D00B5.additionalDeclarations


//## Modelname: DataNavigator Foundation::SOAPCommand_CAT%4DC0633D0140
namespace soapcommand {
//## begin soapcommand%4DC0633D0140.initialDeclarations preserve=yes
//## end soapcommand%4DC0633D0140.initialDeclarations

// Class soapcommand::ExternalAdjustmentListCommand 

ExternalAdjustmentListCommand::ExternalAdjustmentListCommand()
  //## begin ExternalAdjustmentListCommand::ExternalAdjustmentListCommand%58ED085001E4_const.hasinit preserve=no
  //## end ExternalAdjustmentListCommand::ExternalAdjustmentListCommand%58ED085001E4_const.hasinit
  //## begin ExternalAdjustmentListCommand::ExternalAdjustmentListCommand%58ED085001E4_const.initialization preserve=yes
  : SOAPCommand("S0003D","@##XLWADJ ")
  //## end ExternalAdjustmentListCommand::ExternalAdjustmentListCommand%58ED085001E4_const.initialization
{
  //## begin soapcommand::ExternalAdjustmentListCommand::ExternalAdjustmentListCommand%58ED085001E4_const.body preserve=yes
   memcpy(m_sID,"SX25",4);
   m_hQuery.attach(this);
   m_hRow.attach(this);
   emssegment::SettlementWebAdjustment::instance()->addSegments(m_hXMLText);
   m_hXMLText.add('X',segment::SOAPSegment::instance());
   m_hXMLText.setMask(false);
   m_pXMLItem = new XMLItem();
   m_pXMLHandler = new ExternalAdjustmentListHandler(m_pXMLItem,this);
  //## end soapcommand::ExternalAdjustmentListCommand::ExternalAdjustmentListCommand%58ED085001E4_const.body
}

ExternalAdjustmentListCommand::ExternalAdjustmentListCommand (ClientCommand* pSuccessor)
  //## begin soapcommand::ExternalAdjustmentListCommand::ExternalAdjustmentListCommand%58EE34A402DE.hasinit preserve=no
  //## end soapcommand::ExternalAdjustmentListCommand::ExternalAdjustmentListCommand%58EE34A402DE.hasinit
  //## begin soapcommand::ExternalAdjustmentListCommand::ExternalAdjustmentListCommand%58EE34A402DE.initialization preserve=yes
  : SOAPCommand("S0003D","@##XLWADJ ")
  //## end soapcommand::ExternalAdjustmentListCommand::ExternalAdjustmentListCommand%58EE34A402DE.initialization
{
  //## begin soapcommand::ExternalAdjustmentListCommand::ExternalAdjustmentListCommand%58EE34A402DE.body preserve=yes
   memcpy(m_sID,"SX25",4);
   m_pSuccessor = pSuccessor;
   m_hQuery.attach(this);
   m_hRow.attach(this);
   emssegment::SettlementWebAdjustment::instance()->addSegments(m_hXMLText);
   m_hXMLText.add('X',segment::SOAPSegment::instance());
   m_hXMLText.setMask(false);
   m_pXMLItem = new XMLItem();
   m_pXMLHandler = new ExternalAdjustmentListHandler(m_pXMLItem,this);
  //## end soapcommand::ExternalAdjustmentListCommand::ExternalAdjustmentListCommand%58EE34A402DE.body
}


ExternalAdjustmentListCommand::~ExternalAdjustmentListCommand()
{
  //## begin soapcommand::ExternalAdjustmentListCommand::~ExternalAdjustmentListCommand%58ED085001E4_dest.body preserve=yes
  //## end soapcommand::ExternalAdjustmentListCommand::~ExternalAdjustmentListCommand%58ED085001E4_dest.body
}



//## Other Operations (implementation)
bool ExternalAdjustmentListCommand::execute ()
{
  //## begin soapcommand::ExternalAdjustmentListCommand::execute%58EE34DA0162.body preserve=yes
   UseCase hUseCase("CLIENT","## CL165 LIST EXTERNAL ADJ");
   if (!m_pXMLDocument)
#ifdef MVS
      m_pXMLDocument = new XMLDocument("JCL", "RXLSWA", &m_hRow, &m_hXMLText);
#else
      m_pXMLDocument = new XMLDocument("SOURCE", "CXORLSWA", &m_hRow, &m_hXMLText);
#endif
   m_pXMLDocument->reset();
   emssegment::SettlementWebAdjustment::instance()->join(m_hQuery);
   int i = parse();
   m_pXMLDocument->add("FinancialExceptionListRsp");
   if (i != 0)
   {
      reply();
      return true;
   }
   if (!emssegment::SettlementWebAdjustment::instance()->getStartDateTime().empty())
   {
      secure(m_hQuery,"SM_WEB_ADJ");
      if (SOAPSegment::instance()->getRtnCde() == "4")
      {
         reply();
         return true;
      }
      string strDateTime("'");
	  if (emssegment::SettlementWebAdjustment::instance()->getStartDateTime() < emssegment::SettlementWebAdjustment::instance()->getEndDateTime())
      {
		 strDateTime += emssegment::SettlementWebAdjustment::instance()->getStartDateTime();
         strDateTime += "' AND '";
		 strDateTime += emssegment::SettlementWebAdjustment::instance()->getEndDateTime();
      }
      else
      {
		 strDateTime += emssegment::SettlementWebAdjustment::instance()->getEndDateTime();
         strDateTime += "' AND '";
		 strDateTime += emssegment::SettlementWebAdjustment::instance()->getStartDateTime();
      }
      strDateTime += "'";
      m_hQuery.setBasicPredicate("SM_WEB_ADJ","TSTAMP_TRANS","BETWEEN",strDateTime.c_str());
      m_hQuery.setOrderByClause("TSTAMP_TRANS DESC,UNIQUENESS_KEY DESC");
   }
   auto_ptr<SelectStatement> pSelectStatement((SelectStatement*) DatabaseFactory::instance()->create("SelectStatement"));
   if (!pSelectStatement->execute(m_hQuery))
      SOAPSegment::instance()->setRtnCde('5');
   else
      SOAPSegment::instance()->setRtnCde(m_iRows == 0 ? '2' : m_hQuery.getAbort() ? '1' : '0');
   reply();
   m_hRow.getBuffer().erase();
   Database::instance()->commit();
   return true;
  //## end soapcommand::ExternalAdjustmentListCommand::execute%58EE34DA0162.body
}

int ExternalAdjustmentListCommand::parse ()
{
  //## begin soapcommand::ExternalAdjustmentListCommand::parse%58EE3AA10146.body preserve=yes
   int iRC = SOAPCommand::parse();
   if (iRC != 0)
      return iRC;
   return 0;
  //## end soapcommand::ExternalAdjustmentListCommand::parse%58EE3AA10146.body
}

void ExternalAdjustmentListCommand::secure (Query& hQuery, const char* pszTable)
{
  //## begin soapcommand::ExternalAdjustmentListCommand::secure%5968512A0084.body preserve=yes
   Query q;
   auto_ptr<reusable::FormatSelectVisitor>pFormatSelectVisitor((reusable::FormatSelectVisitor*)database::DatabaseFactory::instance()->create("FormatSelectVisitor"));
   q.reset();
   q.setDistinct(true);
   q.setSubSelect(true);
   q.setQualifier("QUALIFY","AS_USER_PROFILE");
   q.setQualifier("QUALIFY","AS_ENTITY_ROLE");
   q.setQualifier("QUALIFY","AS_ROLE_RELATION");
   q.join("AS_USER_PROFILE","INNER","AS_ENTITY_ROLE","ENTITY_ID");
   q.join("AS_ENTITY_ROLE","INNER","AS_ROLE_RELATION","ROLE_ID");
   q.bind("AS_ENTITY_ROLE","ONLINE_ENTITY_ID",reusable::Column::STRING, 0);
   q.setBasicPredicate("AS_USER_PROFILE","USER_ID","=",CommonHeaderSegment::instance()->getUserID().c_str());
   q.setBasicPredicate("AS_USER_PROFILE","CUST_ID","=",CommonHeaderSegment::instance()->getCUST_ID().c_str());
   q.setBasicPredicate("AS_ROLE_RELATION","STS_TRAN_COL_NAME","LIKE","INST%");
   q.accept(*pFormatSelectVisitor);
   string strSubSelect = "(" + pFormatSelectVisitor->SQLText() + ")";
   if (!hQuery.getSearchCondition().empty())
      hQuery.getSearchCondition().append(" AND");
   hQuery.getSearchCondition().append(" (");
   hQuery.setBasicPredicate(pszTable,"INST_ID_RECON_ACQ","IN",strSubSelect.c_str(),false,false);
   hQuery.setBasicPredicate(pszTable,"INST_ID_RECON_ISS","IN",strSubSelect.c_str(),false,false);
   q.reset();
   q.setDistinct(true);
   q.setSubSelect(true);
   q.setQualifier("QUALIFY","AS_USER_PROFILE");
   q.setQualifier("QUALIFY","AS_ENTITY_ROLE");
   q.setQualifier("QUALIFY","AS_ROLE_RELATION");
   q.join("AS_USER_PROFILE","INNER","AS_ENTITY_ROLE","ENTITY_ID");
   q.join("AS_ENTITY_ROLE","INNER","AS_ROLE_RELATION","ROLE_ID");
   q.bind("AS_ENTITY_ROLE","ONLINE_ENTITY_ID", reusable::Column::STRING, 0);
   q.setBasicPredicate("AS_USER_PROFILE","USER_ID","=",CommonHeaderSegment::instance()->getUserID().c_str());
   q.setBasicPredicate("AS_USER_PROFILE","CUST_ID","=",CommonHeaderSegment::instance()->getCUST_ID().c_str());
   q.setBasicPredicate("AS_ROLE_RELATION","STS_TRAN_COL_NAME","=","*");
   q.accept(*pFormatSelectVisitor);
   strSubSelect = "(" + pFormatSelectVisitor->SQLText() + ")";
   hQuery.setBasicPredicate(0,"'*'","IN",strSubSelect.c_str(),false,false);
   hQuery.getSearchCondition().append(")");
  //## end soapcommand::ExternalAdjustmentListCommand::secure%5968512A0084.body
}

void ExternalAdjustmentListCommand::update (Subject* pSubject)
{
  //## begin soapcommand::ExternalAdjustmentListCommand::update%58EE34DA0163.body preserve=yes
   if (pSubject == &m_hQuery)
   {
      if(!emssegment::SettlementWebAdjustment::instance()->skip())
      {
         ++m_iRows;
         if(m_iRows > m_iMaxRows)
         {
            m_hQuery.setAbort(true);
            return;
         }
         m_pXMLDocument->save();
         map<string,set<string,less<string> >,less<string> >::const_iterator q = emssegment::SettlementWebAdjustment::instance()->getChild().begin();
         if(m_pXMLDocument->add(emssegment::SettlementWebAdjustment::instance()->getParent().begin(),emssegment::SettlementWebAdjustment::instance()->getParent().end()) == false
            || m_pXMLDocument->add((*q).second.begin(),(*q).second.end()) == false)
         {
            m_pXMLDocument->revert();
            m_hQuery.setAbort(true);
            return;
         }
         m_pXMLDocument->write("FinancialException");
      }
      return;
   } 
   SOAPCommand::update(pSubject);
  //## end soapcommand::ExternalAdjustmentListCommand::update%58EE34DA0163.body
}

// Additional Declarations
  //## begin soapcommand::ExternalAdjustmentListCommand%58ED085001E4.declarations preserve=yes
  //## end soapcommand::ExternalAdjustmentListCommand%58ED085001E4.declarations

} // namespace soapcommand

//## begin module%59684E8D00B5.epilog preserve=yes
//## end module%59684E8D00B5.epilog
