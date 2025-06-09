//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%3E79DEDE0138.cm preserve=no
//	$Date:   18 Jan 2018 14:49:06  $ $Author:   e1009839  $
//	$Revision:   1.15  $
//## end module%3E79DEDE0138.cm

//## begin module%3E79DEDE0138.cp preserve=no
//	Copyright (c) 1997 - 2012
//	FIS
//## end module%3E79DEDE0138.cp

//## Module: CXOSEC11%3E79DEDE0138; Package body
//## Subsystem: ECDLL%394E1F94006B
//## Source file: C:\Devel.V02.8B.R001\Windows\Build\Dn\Server\Library\Ecdll\CXOSEC11.cpp

//## begin module%3E79DEDE0138.additionalIncludes preserve=no
//## end module%3E79DEDE0138.additionalIncludes

//## begin module%3E79DEDE0138.includes preserve=yes
#include "CXODPS01.hpp"
#include "CXODPS03.hpp"
#ifndef CXOSDB02_h
#include "CXODDB02.hpp"
#endif
#ifndef CXOSRU19_h
#include "CXODRU19.hpp"
#endif
#ifndef CXOSES01_h
#include "CXODES01.hpp"
#endif
#ifndef CXOSDB01_h
#include "CXODDB01.hpp"
#endif
#ifndef CXOSDNS29_h
#include "CXODNS29.hpp"
#endif
//## end module%3E79DEDE0138.includes

#ifndef CXOSMN05_h
#include "CXODMN05.hpp"
#endif
#ifndef CXOSBS12_h
#include "CXODBS12.hpp"
#endif
#ifndef CXOSBS02_h
#include "CXODBS02.hpp"
#endif
#ifndef CXOSBS09_h
#include "CXODBS09.hpp"
#endif
#ifndef CXOSBS11_h
#include "CXODBS11.hpp"
#endif
#ifndef CXOSRS51_h
#include "CXODRS51.hpp"
#endif
#ifndef CXOSBS06_h
#include "CXODBS06.hpp"
#endif
#ifndef CXOSIF11_h
#include "CXODIF11.hpp"
#endif
#ifndef CXOSRU11_h
#include "CXODRU11.hpp"
#endif
#ifndef CXOSRU12_h
#include "CXODRU12.hpp"
#endif
#ifndef CXOSEC11_h
#include "CXODEC11.hpp"
#endif


//## begin module%3E79DEDE0138.declarations preserve=no
//## end module%3E79DEDE0138.declarations

//## begin module%3E79DEDE0138.additionalDeclarations preserve=yes
//## end module%3E79DEDE0138.additionalDeclarations


//## Modelname: Transaction Research and Adjustments::EMSCommand_CAT%394E266C015B
namespace emscommand {
//## begin emscommand%394E266C015B.initialDeclarations preserve=yes
//## end emscommand%394E266C015B.initialDeclarations

// Class emscommand::CaseCardholderInfoCommand 

CaseCardholderInfoCommand::CaseCardholderInfoCommand()
  //## begin CaseCardholderInfoCommand::CaseCardholderInfoCommand%3E79DB0F0128_const.hasinit preserve=no
      : m_pPrimaryKeySegment(0)
  //## end CaseCardholderInfoCommand::CaseCardholderInfoCommand%3E79DB0F0128_const.hasinit
  //## begin CaseCardholderInfoCommand::CaseCardholderInfoCommand%3E79DB0F0128_const.initialization preserve=yes
  ,ClientCommand("S0003D","@##EMRCHDR")
  //## end CaseCardholderInfoCommand::CaseCardholderInfoCommand%3E79DB0F0128_const.initialization
{
  //## begin emscommand::CaseCardholderInfoCommand::CaseCardholderInfoCommand%3E79DB0F0128_const.body preserve=yes
   memcpy(m_sID,"EC11",4);
   m_pPrimaryKeySegment = new PrimaryKeySegment();
  //## end emscommand::CaseCardholderInfoCommand::CaseCardholderInfoCommand%3E79DB0F0128_const.body
}

CaseCardholderInfoCommand::CaseCardholderInfoCommand (Handler* pSuccessor)
  //## begin emscommand::CaseCardholderInfoCommand::CaseCardholderInfoCommand%3E91BC37029F.hasinit preserve=no
      : m_pPrimaryKeySegment(0)
  //## end emscommand::CaseCardholderInfoCommand::CaseCardholderInfoCommand%3E91BC37029F.hasinit
  //## begin emscommand::CaseCardholderInfoCommand::CaseCardholderInfoCommand%3E91BC37029F.initialization preserve=yes
  ,ClientCommand("S0003D","@##EMRCHDR")
  //## end emscommand::CaseCardholderInfoCommand::CaseCardholderInfoCommand%3E91BC37029F.initialization
{
  //## begin emscommand::CaseCardholderInfoCommand::CaseCardholderInfoCommand%3E91BC37029F.body preserve=yes
   memcpy(m_sID,"EC11",4);
   m_pSuccessor = pSuccessor;
   m_pPrimaryKeySegment = new PrimaryKeySegment();
   m_hSegments.push_back(m_pPrimaryKeySegment);
  //## end emscommand::CaseCardholderInfoCommand::CaseCardholderInfoCommand%3E91BC37029F.body
}


CaseCardholderInfoCommand::~CaseCardholderInfoCommand()
{
  //## begin emscommand::CaseCardholderInfoCommand::~CaseCardholderInfoCommand%3E79DB0F0128_dest.body preserve=yes
   delete m_pPrimaryKeySegment;
  //## end emscommand::CaseCardholderInfoCommand::~CaseCardholderInfoCommand%3E79DB0F0128_dest.body
}



//## Other Operations (implementation)
void CaseCardholderInfoCommand::deleteObsolete ()
{
  //## begin emscommand::CaseCardholderInfoCommand::deleteObsolete%5A05AEAD017D.body preserve=yes
   Query hQuery;
   string strSubSelect;
   string strPAN;
   hQuery.setSubSelect(true);
   hQuery.setQualifier("CUSTQUAL", "EMS_CASE");
   hQuery.bind("EMS_CASE", "PAN", Column::STRING, &strPAN);
   auto_ptr<reusable::FormatSelectVisitor>pFormatSelectVisitor
      ((reusable::FormatSelectVisitor*)database::DatabaseFactory::instance()->create("FormatSelectVisitor"));
   hQuery.accept(*pFormatSelectVisitor);
   strSubSelect = "(" + pFormatSelectVisitor->SQLText() + ")";
   hQuery.reset();
   hQuery.setQualifier("QUALIFY", "CARDHOLDER");
   auto_ptr<SelectStatement> pDeleteStatement((SelectStatement*)DatabaseFactory::instance()->create("DeleteStatement"));
   hQuery.setBasicPredicate("CARDHOLDER", "PAN", "NOT IN", strSubSelect.c_str());
   hQuery.setBasicPredicate("CARDHOLDER", "CUST_ID", "=", Customer::instance()->getCUST_ID().c_str());
   if (!pDeleteStatement->execute(hQuery))
      UseCase::setSuccess(false);
   Database::instance()->commit();
  //## end emscommand::CaseCardholderInfoCommand::deleteObsolete%5A05AEAD017D.body
}

bool CaseCardholderInfoCommand::execute ()
{
  //## begin emscommand::CaseCardholderInfoCommand::execute%3E79E22603D8.body preserve=yes
   UseCase hUseCase("CLIENT","## EC11 READ CARDHOLDER INFO");
   {
      if (parse() == -1)
         return UseCase::setSuccess(false);
      if (!m_pPrimaryKeySegment->presence())
      {
         sendError(STS_PARSE_ERROR,STS_ERROR,STS_MISSING_PRIMARYKEY_SEGMENT);
         return UseCase::setSuccess(false);
      }
      if (search() == 1)
      {
         sendError(STS_QUERY_ERROR,STS_ERROR,m_lInfoIDNumber,false);
         m_pPrimaryKeySegment->clear();//PCI-SSF Certification requirement
         CardholderInformationSegment::instance()->wipe("PAN");
         return UseCase::setSuccess(false);
      }
      reply();
   }
   return true;
  //## end emscommand::CaseCardholderInfoCommand::execute%3E79E22603D8.body
}

int CaseCardholderInfoCommand::reply ()
{
  //## begin emscommand::CaseCardholderInfoCommand::reply%49F61622002E.body preserve=yes
   if (m_lInfoIDNumber == WORK_IN_PROGRESS)
      return 0;
   Message::instance(Message::INBOUND)->reset("EMSCI ","S0003R");
   m_pDataBuffer = Message::instance(Message::INBOUND)->data() + 8;
   CommonHeaderSegment::instance()->deport(&m_pDataBuffer);
   if (m_lInfoIDNumber != 0)
   {
      m_hInformationSegment.setError(STS_WARNING,m_lInfoIDNumber);
      m_hInformationSegment.deport(&m_pDataBuffer);
      getResponseTimeSegment()->deport(&m_pDataBuffer);
      ClientCommand::reply();
      m_pPrimaryKeySegment->clear();//PCI-SSF Certification requirement
      CardholderInformationSegment::instance()->wipe("PAN");
      ServiceApplication* pApplication = (ServiceApplication*)Application::instance();
      pApplication->idle();
      return 0;
   }
   CardholderInformationSegment::instance()->deport(&m_pDataBuffer);
   getResponseTimeSegment()->deport(&m_pDataBuffer);
   ClientCommand::reply();
   m_pPrimaryKeySegment->clear();//PCI-SSF Certification requirement
   CardholderInformationSegment::instance()->wipe("PAN");
   ServiceApplication* pApplication = (ServiceApplication*)Application::instance();
   pApplication->idle();
   return 1;
  //## end emscommand::CaseCardholderInfoCommand::reply%49F61622002E.body
}

int CaseCardholderInfoCommand::search ()
{
  //## begin emscommand::CaseCardholderInfoCommand::search%49F60C18005D.body preserve=yes
   Query hQuery;
   auto_ptr<SelectStatement> pSelectStatement((SelectStatement*)DatabaseFactory::instance()->create("SelectStatement"));
   char szPAN[29];
   memcpy(szPAN,m_pPrimaryKeySegment->getPrimaryKey().data(),28);
   szPAN[28] = '\0';
   CardholderInformationSegment::instance()->bind(hQuery);
   hQuery.setBasicPredicate("CARDHOLDER","PAN","=",szPAN);
   if (pSelectStatement->execute(hQuery) == false)
   {
      m_lInfoIDNumber = pSelectStatement->getInfoIDNumber();
      return 1;
   }
   if (pSelectStatement->getRows() == 0)
      m_lInfoIDNumber = STS_CARDHOLDER_NOT_FOUND;
   return 0;
  //## end emscommand::CaseCardholderInfoCommand::search%49F60C18005D.body
}

// Additional Declarations
  //## begin emscommand::CaseCardholderInfoCommand%3E79DB0F0128.declarations preserve=yes
  //## end emscommand::CaseCardholderInfoCommand%3E79DB0F0128.declarations

} // namespace emscommand

//## begin module%3E79DEDE0138.epilog preserve=yes
//## end module%3E79DEDE0138.epilog
