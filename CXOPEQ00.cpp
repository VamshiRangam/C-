//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%41B5436B0236.cm preserve=no
//## end module%41B5436B0236.cm

//## begin module%41B5436B0236.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%41B5436B0236.cp

//## Module: CXOPEQ00%41B5436B0236; Package body
//## Subsystem: EQ%41B5425900F2
//## Source file: C:\Repos\datanavigatorserver\Windows\Build\Dn\Server\Application\Eq\CXOPEQ00.cpp

//## begin module%41B5436B0236.additionalIncludes preserve=no
//## end module%41B5436B0236.additionalIncludes

//## begin module%41B5436B0236.includes preserve=yes
#ifdef MVS
#pragma runopts(STACK(128K,128K,ANY,KEEP),TRAP(ON,NOSPIE),POSIX(ON),ENVAR('TASK=EQ'))
#endif
#include "CXODDB16.hpp"
#include "CXODDB50.hpp"
#include "CXODDZ06.hpp"
#include "CXODES95.hpp"
#include "CXODES97.hpp"
#include "CXODES98.hpp"
//## end module%41B5436B0236.includes

#ifndef CXOSIF22_h
#include "CXODIF22.hpp"
#endif
#ifndef CXOSIF11_h
#include "CXODIF11.hpp"
#endif
#ifndef CXOSDB01_h
#include "CXODDB01.hpp"
#endif
#ifndef CXOSRU10_h
#include "CXODRU10.hpp"
#endif
#ifndef CXOSES08_h
#include "CXODES08.hpp"
#endif
#ifndef CXOSES09_h
#include "CXODES09.hpp"
#endif
#ifndef CXOSES10_h
#include "CXODES10.hpp"
#endif
#ifndef CXOSES11_h
#include "CXODES11.hpp"
#endif
#ifndef CXOSES13_h
#include "CXODES13.hpp"
#endif
#ifndef CXOSES21_h
#include "CXODES21.hpp"
#endif
#ifndef CXOSES24_h
#include "CXODES24.hpp"
#endif
#ifndef CXOSES25_h
#include "CXODES25.hpp"
#endif
#ifndef CXOSES18_h
#include "CXODES18.hpp"
#endif
#ifndef CXOSES27_h
#include "CXODES27.hpp"
#endif
#ifndef CXOSES14_h
#include "CXODES14.hpp"
#endif
#ifndef CXOSES15_h
#include "CXODES15.hpp"
#endif
#ifndef CXOSES16_h
#include "CXODES16.hpp"
#endif
#ifndef CXOSES03_h
#include "CXODES03.hpp"
#endif
#ifndef CXOSES17_h
#include "CXODES17.hpp"
#endif
#ifndef CXOSES01_h
#include "CXODES01.hpp"
#endif
#ifndef CXOSES06_h
#include "CXODES06.hpp"
#endif
#ifndef CXOSES19_h
#include "CXODES19.hpp"
#endif
#ifndef CXOSEX01_h
#include "CXODEX01.hpp"
#endif
#ifndef CXOSES26_h
#include "CXODES26.hpp"
#endif
#ifndef CXOSES12_h
#include "CXODES12.hpp"
#endif
#ifndef CXOSES23_h
#include "CXODES23.hpp"
#endif
#ifndef CXOSES22_h
#include "CXODES22.hpp"
#endif
#ifndef CXOSES20_h
#include "CXODES20.hpp"
#endif
#ifndef CXOSMN05_h
#include "CXODMN05.hpp"
#endif
#ifndef CXOSES30_h
#include "CXODES30.hpp"
#endif
#ifndef CXOSTM04_h
#include "CXODTM04.hpp"
#endif
#ifndef CXOSIF16_h
#include "CXODIF16.hpp"
#endif
#ifndef CXOSIF36_h
#include "CXODIF36.hpp"
#endif
#ifndef CXOSES07_h
#include "CXODES07.hpp"
#endif
#ifndef CXOSEX17_h
#include "CXODEX17.hpp"
#endif
#ifndef CXOSEC19_h
#include "CXODEC19.hpp"
#endif
#ifndef CXOSDZ01_h
#include "CXODDZ01.hpp"
#endif
#ifndef CXOSRA03_h
#include "CXODRA03.hpp"
#endif
#ifndef CXOSDB06_h
#include "CXODDB06.hpp"
#endif
#ifndef CXOSFX01_h
#include "CXODFX01.hpp"
#endif
#ifndef CXOSBS06_h
#include "CXODBS06.hpp"
#endif
#ifndef CXOSZE01_h
#include "CXODZE01.hpp"
#endif
#ifndef CXOSIF03_h
#include "CXODIF03.hpp"
#endif
#ifndef CXOSRU29_h
#include "CXODRU29.hpp"
#endif
#ifndef CXOSBS27_h
#include "CXODBS27.hpp"
#endif
#ifndef CXOSES73_h
#include "CXODES73.hpp"
#endif
#ifndef CXOSRS13_h
#include "CXODRS13.hpp"
#endif
#ifndef CXOSDZ02_h
#include "CXODDZ02.hpp"
#endif
#ifndef CXOSSX10_h
#include "CXODSX10.hpp"
#endif
#ifndef CXOSES81_h
#include "CXODES81.hpp"
#endif
#ifndef CXOSES87_h
#include "CXODES87.hpp"
#endif
#ifndef CXOSDZ04_h
#include "CXODDZ04.hpp"
#endif
#ifndef CXOSDZ03_h
#include "CXODDZ03.hpp"
#endif
#ifndef CXOSSX21_h
#include "CXODSX21.hpp"
#endif
#ifndef CXOSEC03_h
#include "CXODEC03.hpp"
#endif
#ifndef CXOSEC04_h
#include "CXODEC04.hpp"
#endif
#ifndef CXOSEC05_h
#include "CXODEC05.hpp"
#endif
#ifndef CXOSEC06_h
#include "CXODEC06.hpp"
#endif
#ifndef CXOSEC08_h
#include "CXODEC08.hpp"
#endif
#ifndef CXOSEC07_h
#include "CXODEC07.hpp"
#endif
#ifndef CXOSRC05_h
#include "CXODRC05.hpp"
#endif
#ifndef CXOSEC09_h
#include "CXODEC09.hpp"
#endif
#ifndef CXOSEC12_h
#include "CXODEC12.hpp"
#endif
#ifndef CXOSEC14_h
#include "CXODEC14.hpp"
#endif
#ifndef CXOSEC11_h
#include "CXODEC11.hpp"
#endif
#ifndef CXOSEC13_h
#include "CXODEC13.hpp"
#endif
#ifndef CXOSEC15_h
#include "CXODEC15.hpp"
#endif
#ifndef CXOSEC16_h
#include "CXODEC16.hpp"
#endif
#ifndef CXOSEC17_h
#include "CXODEC17.hpp"
#endif
#ifndef CXOSEC18_h
#include "CXODEC18.hpp"
#endif
#ifndef CXOSEC20_h
#include "CXODEC20.hpp"
#endif
#ifndef CXOSEC23_h
#include "CXODEC23.hpp"
#endif
#ifndef CXOSEC27_h
#include "CXODEC27.hpp"
#endif
#ifndef CXOSEC28_h
#include "CXODEC28.hpp"
#endif
#ifndef CXOSEC30_h
#include "CXODEC30.hpp"
#endif
#ifndef CXOSSX13_h
#include "CXODSX13.hpp"
#endif
#ifndef CXOSSX17_h
#include "CXODSX17.hpp"
#endif
#ifndef CXOSJX07_h
#include "CXODJX07.hpp"
#endif
#ifndef CXOSJX11_h
#include "CXODJX11.hpp"
#endif
#ifndef CXOSJX08_h
#include "CXODJX08.hpp"
#endif
#ifndef CXOSJX09_h
#include "CXODJX09.hpp"
#endif
#ifndef CXOSJX14_h
#include "CXODJX14.hpp"
#endif
#ifndef CXOSJX10_h
#include "CXODJX10.hpp"
#endif
#ifndef CXOSJX25_h
#include "CXODJX25.hpp"
#endif
#ifndef CXOSJX26_h
#include "CXODJX26.hpp"
#endif
#ifndef CXOSJX27_h
#include "CXODJX27.hpp"
#endif
#ifndef CXOSJX29_h
#include "CXODJX29.hpp"
#endif
#ifndef CXOSJX30_h
#include "CXODJX30.hpp"
#endif
#ifndef CXOSJX32_h
#include "CXODJX32.hpp"
#endif
#ifndef CXOSJX42_h
#include "CXODJX42.hpp"
#endif
#ifndef CXOSJX43_h
#include "CXODJX43.hpp"
#endif
#ifndef CXOPEQ00_h
#include "CXODEQ00.hpp"
#endif


//## begin module%41B5436B0236.declarations preserve=no
//## end module%41B5436B0236.declarations

//## begin module%41B5436B0236.additionalDeclarations preserve=yes
#include "CXODPS06.hpp"
   pApplication = new ExceptionQuery();
   pApplication->parseCommandLine(argc,argv);
   if (pApplication->initialize() == 0)
      pApplication->run();
#include "CXODPS07.hpp"
//## end module%41B5436B0236.additionalDeclarations


// Class ExceptionQuery 

ExceptionQuery::ExceptionQuery()
  //## begin ExceptionQuery::ExceptionQuery%41B5214D00E3_const.hasinit preserve=no
      : m_pCaseListCommand(0),
        m_pCaseChangeListCommand(0),
        m_pCaseRulesDescriptionListCommand(0),
        m_pCasePhaseListCommand(0),
        m_pCaseCommentListCommand(0),
        m_pCaseCommentCreateCommand(0),
        m_pFinancialUpdateFinTypeCommand(0),
        m_pCaseWorkQueueListCommand(0),
        m_pCaseAvailablePhaseListCommand(0),
        m_pActionDetailListCommand(0),
        m_pCaseCardholderInfoCommand(0),
        m_pCaseAvailableReasonCodeListCommand(0),
        m_pCaseMMTListCommand(0),
        m_pRechainCaseCommand(0),
        m_pCaseFeeControlNumberCommand(0),
        m_pCaseRetrieveRuleSetCommand(0),
        m_pCaseHighlightCommand(0),
        m_pCaseClientAccountingListCommand(0),
        m_pRelatedCasesCommand(0),
        m_pNetworkAvailableReasonCodeListCommand(0),
        m_pCaseCardholderUpdateCommand(0),
        m_pCaseDocumentListCommand(0),
        m_pClaimStatusCommand(0),
        m_pCaseCommentsListCommand(0),
        m_pCaseDocumentsListCommand(0),
        m_pTransitionsCommand(0),
        m_pCasesCommand(0),
        m_pReasonCodesCommand(0),
        m_pClaimCommand(0),
        m_pMmtsCommand(0),
        m_pRESTClaimStatusCommand(0),
        m_pRESTCaseDetailCommand(0),
        m_pRESTActionsCommand(0),
        m_pRESTCardholderCommand(0),
        m_pRESTDescriptionsCommand(0),
        m_RESTRulesetCommand(0),
        m_pRESTWorkqueueCommand(0),
        m_pRESTNetworkReasonCodeCommand(0),
        m_pRESTCaseChangesCommand(0)
  //## end ExceptionQuery::ExceptionQuery%41B5214D00E3_const.hasinit
  //## begin ExceptionQuery::ExceptionQuery%41B5214D00E3_const.initialization preserve=yes
  //## end ExceptionQuery::ExceptionQuery%41B5214D00E3_const.initialization
{
  //## begin ExceptionQuery::ExceptionQuery%41B5214D00E3_const.body preserve=yes
   memcpy(m_sID,"EQ00",4);
  //## end ExceptionQuery::ExceptionQuery%41B5214D00E3_const.body
}


ExceptionQuery::~ExceptionQuery()
{
  //## begin ExceptionQuery::~ExceptionQuery%41B5214D00E3_dest.body preserve=yes
   delete m_pRESTCaseChangesCommand;
   delete m_pRESTNetworkReasonCodeCommand;
   delete m_pRESTWorkqueueCommand;
   delete m_RESTRulesetCommand;
   delete m_pRESTDescriptionsCommand;
   delete m_pRESTCardholderCommand;
   delete m_pRESTActionsCommand;
   delete m_pRESTCaseDetailCommand;
   delete m_pRESTClaimStatusCommand;
   delete m_pMmtsCommand;
   delete m_pClaimCommand;
   delete m_pCasesCommand;
   delete m_pTransitionsCommand;
   delete m_pReasonCodesCommand;
   delete m_pCaseListCommand;
   delete m_pXMLCaseListCommand;
   delete m_pCaseChangeListCommand;
   delete m_pCaseRulesDescriptionListCommand;
   delete m_pCasePhaseListCommand;
   delete m_pCaseCommentListCommand;
   delete m_pCaseCommentCreateCommand;
   delete m_pFinancialUpdateFinTypeCommand;
   delete m_pCaseWorkQueueListCommand;
   delete m_pCaseAvailablePhaseListCommand;
   delete m_pActionDetailListCommand;
   delete m_pCaseCardholderInfoCommand;
   delete m_pCaseAvailableReasonCodeListCommand;
   delete m_pCaseMMTListCommand;
   delete m_pRechainCaseCommand;
   delete m_pCaseFeeControlNumberCommand;
   delete m_pCaseRetrieveRuleSetCommand;
   delete m_pCaseHighlightCommand;
   delete m_pCaseClientAccountingListCommand;
   delete m_pRelatedCasesCommand;
   delete m_pNetworkAvailableReasonCodeListCommand;
   delete m_pCaseCardholderUpdateCommand;
   delete m_pCaseDocumentListCommand;
   delete m_pCaseCommentsListCommand;
   delete m_pCaseDocumentsListCommand;
   delete ems::Case::instance();
   delete EMSRulesEngine::instance();
   delete CaseSegment::instance();
   delete CaseAccelSegment::instance();
   delete CaseAffnSegment::instance();
   delete CaseAustraliaSegment::instance();
   delete CaseCashStationSegment::instance();
   delete CaseCirrusSegment::instance();
   delete CaseHonorSegment::instance();
   delete CaseInterlinkSegment::instance();
   delete CaseMacSegment::instance();
   delete CaseNyceSegment::instance();
   delete CasePlusSegment::instance();
   delete CasePulseSegment::instance();
   delete CaseStarSegment::instance();
   delete CaseVisaSegment::instance();
   delete CaseShazamSegment::instance();
   delete CasePhaseSegment::instance();
   delete CasePhaseAccelSegment::instance();
   delete CasePhaseAffnSegment::instance();
   delete CasePhaseAustraliaSegment::instance();
   delete CasePhaseCashStationSegment::instance();
   delete CasePhaseCirrusSegment::instance();
   delete CasePhaseInterlinkSegment::instance();
   delete CasePhaseMacSegment::instance();
   delete CasePhaseNyceSegment::instance();
   delete CasePhasePulseSegment::instance();
   delete CasePhaseStarSegment::instance();
   delete CasePhaseVisaSegment::instance();
   delete CaseTransitionSegment::instance();
   delete CreditSegment::instance();
   delete EMailMessage::instance();
   delete FunctionFactory::instance();
   delete CaseEFTPosSegment::instance();
   delete CasePhaseEFTPosSegment::instance();
  //## end ExceptionQuery::~ExceptionQuery%41B5214D00E3_dest.body
}



//## Other Operations (implementation)
int ExceptionQuery::initialize ()
{
  //## begin ExceptionQuery::initialize%41B64CA10356.body preserve=yes
   new dnplatform::DNPlatform();
   new segment::AuditEvent;
   int iRC = ServiceApplication::initialize();
   UseCase hUseCase("CLIENT","## CL129 START EQ");
   if (iRC == -1)
   {
      UseCase::setSuccess(false);
      return -1;
   }
   platform::Platform::instance()->createDatabaseFactory();
   database::DataModel::instance();
   database::CRTransactionTypeIndicator::instance();
   Database::instance()->attach(this);
   Database::instance()->connect();
   m_pRESTCaseChangesCommand = new restcommand::CaseChangesCommand(0);
   m_pRESTNetworkReasonCodeCommand = new restcommand::NetworkReasonCodeCommand(m_pRESTCaseChangesCommand);
   m_pRESTWorkqueueCommand = new restcommand::WorkqueueCommand(m_pRESTNetworkReasonCodeCommand);
   m_RESTRulesetCommand = new restcommand::RulesetCommand(m_pRESTWorkqueueCommand);
   m_pRESTDescriptionsCommand = new restcommand::DescriptionsCommand(m_RESTRulesetCommand);
   m_pRESTCardholderCommand = new restcommand::CardholderCommand(m_pRESTDescriptionsCommand);
   m_pRESTActionsCommand = new restcommand::ActionsCommand(m_pRESTCardholderCommand);
   m_pRESTCaseDetailCommand = new restcommand::CaseDetailCommand(m_pRESTActionsCommand);
   m_pRESTClaimStatusCommand = new restcommand::ClaimStatusCommand(m_pRESTCaseDetailCommand);
   m_pMmtsCommand = new restcommand::MmtsCommand(m_pRESTClaimStatusCommand);
   m_pClaimCommand = new restcommand::ClaimCommand(m_pMmtsCommand);
   m_pReasonCodesCommand = new restcommand::ReasonCodesCommand(m_pClaimCommand);
   m_pTransitionsCommand = new restcommand::TransitionsCommand(m_pReasonCodesCommand);
   m_pCasesCommand = new restcommand::CasesCommand(m_pTransitionsCommand);
   m_pCaseDocumentsListCommand = new soapcommand::CaseDocumentsListCommand(m_pCasesCommand);
   m_pCaseCommentsListCommand = new soapcommand::CaseCommentsListCommand(m_pCaseDocumentsListCommand);
   m_pXMLCaseListCommand = new soapcommand::CaseListCommand(m_pCaseCommentsListCommand);
   m_pClaimStatusCommand = new soapcommand::ClaimStatusCommand(m_pXMLCaseListCommand);
   m_pNetworkAvailableReasonCodeListCommand = new NetworkAvailableReasonCodeListCommand(m_pClaimStatusCommand);
   m_pCaseCardholderUpdateCommand = new CaseCardholderUpdateCommand(m_pNetworkAvailableReasonCodeListCommand);
   m_pFinancialUpdateFinTypeCommand = new FinancialUpdateFinTypeCommand(m_pCaseCardholderUpdateCommand);
   m_pCaseFeeControlNumberCommand = new CaseFeeControlNumberCommand(m_pFinancialUpdateFinTypeCommand);
   m_pRechainCaseCommand = new RechainCaseCommand(m_pCaseFeeControlNumberCommand);
   m_pCaseCommentCreateCommand = new CaseCommentCreateCommand(m_pRechainCaseCommand);
   m_pCaseRulesDescriptionListCommand = new CaseRulesDescriptionListCommand(m_pCaseCommentCreateCommand);
   string strTemp;
   if (Extract::instance()->getSpec("CMIQUEUE",strTemp))
   {
      m_pCaseCardholderInfoCommand = new regionsapi::CaseCardholderInfoCommand(m_pCaseRulesDescriptionListCommand);
      ClientCommand::setGlobalContext(ClientCommand::BEGIN,new GlobalContext("##BEGIN"));
      ClientCommand::setGlobalContext(ClientCommand::END,new GlobalContext("##END"));
   }
   else
   if (Extract::instance()->getSpec("CMSE",strTemp) ||
       Extract::instance()->getSpec("EBT",strTemp))
   {
      CriticalSection::setEnable(0);
      m_pCaseCardholderInfoCommand = new fis::CaseCardholderInfoCommand(m_pCaseRulesDescriptionListCommand);
      ClientCommand::setGlobalContext(ClientCommand::BEGIN,new GlobalContext("##BEGIN"));
      ClientCommand::setGlobalContext(ClientCommand::END,new GlobalContext("##END"));
   }
   else
   {
      m_pCaseCardholderInfoCommand = new emscommand::CaseCardholderInfoCommand(m_pCaseRulesDescriptionListCommand);
   }
   m_pCaseRetrieveRuleSetCommand = new CaseRetrieveRuleSetCommand(m_pCaseCardholderInfoCommand);
   m_pCaseCommentListCommand = new CaseCommentListCommand(m_pCaseRetrieveRuleSetCommand);
   m_pCasePhaseListCommand = new CasePhaseListCommand(m_pCaseCommentListCommand);
   m_pCaseDocumentListCommand = new CaseDocumentListCommand(m_pCasePhaseListCommand);
   m_pCaseChangeListCommand = new CaseChangeListCommand(m_pCaseDocumentListCommand);
   if (Extract::instance()->getCustomCode() == "ZAPP")
      m_pCaseListCommand = new zapp::CaseListCommand(m_pCaseChangeListCommand);
   else
      m_pCaseListCommand = new emscommand::CaseListCommand(m_pCaseChangeListCommand);
   m_pCaseWorkQueueListCommand = new CaseWorkQueueListCommand(m_pCaseListCommand);
   m_pCaseAvailablePhaseListCommand = new CaseAvailablePhaseListCommand(m_pCaseWorkQueueListCommand);
   m_pActionDetailListCommand = new ActionDetailListCommand(m_pCaseAvailablePhaseListCommand);
   m_pCaseAvailableReasonCodeListCommand = new CaseAvailableReasonCodeListCommand(m_pActionDetailListCommand);
   m_pCaseHighlightCommand = new CaseHighlightCommand(m_pCaseAvailableReasonCodeListCommand);
   m_pCaseClientAccountingListCommand = new CaseClientAccountingListCommand(m_pCaseHighlightCommand);
   m_pRelatedCasesCommand = new RelatedCasesCommand(m_pCaseClientAccountingListCommand);
   m_pCaseMMTListCommand = new CaseMMTListCommand(m_pRelatedCasesCommand);
   EMSRulesEngine::instance();
   string strCustomer;
   Extract::instance()->getSpec("CUSTOMER",strCustomer);
   Transaction::instance()->setCustomer(strCustomer);
   new ActionFactory();
   new dnplatform::NetworkFactory();
   new ExceptionFactory();
   new dnplatform::APIExportFactory();
   ems::Case::instance();
   return 0;
  //## end ExceptionQuery::initialize%41B64CA10356.body
}

int ExceptionQuery::onMessage (Message& hMessage)
{
  //## begin ExceptionQuery::onMessage%41B64BFE02A7.body preserve=yes
   if (hMessage.messageID() != "S0003D"
      && hMessage.messageID() != "S0003R"
      && hMessage.messageID() != "S0004D")
      return 0;
   Transaction::instance()->begin();
   string strTimeStamp = Clock::instance()->getYYYYMMDDHHMMSS(true);
   Transaction::instance()->setTimeStamp(strTimeStamp += "00");
   EMSRulesEngine::instance()->reset();
   ems::Case::resetSegments();
   FinancialBaseSegment::instance()->reset();
   m_pCaseMMTListCommand->update(Message::instance(Message::INBOUND));
   if (Database::instance()->transactionState() == Database::ROLLBACKREQUIRED)
      Database::instance()->rollback();
   else
      Database::instance()->commit();
   Transaction::instance()->commit();
   if (CommonHeaderSegment::instance()->getServiceName().find("EMRCHDR") == string::npos)
      idle();
   return 0;
  //## end ExceptionQuery::onMessage%41B64BFE02A7.body
}

int ExceptionQuery::onReset (Message& hMessage)
{
  //## begin ExceptionQuery::onReset%41B64C090343.body preserve=yes
   return 0;
  //## end ExceptionQuery::onReset%41B64C090343.body
}

void ExceptionQuery::update (Subject* pSubject)
{
  //## begin ExceptionQuery::update%41B64C1D007B.body preserve=yes
   if (pSubject == Database::instance())
   {
      if (Database::instance()->state() == Database::CONNECTED)
         Queue::attach("@##SERVER",Queue::CX_DISTRIBUTION_QUEUE);
      return;
   }
   ServiceApplication::update(pSubject);
  //## end ExceptionQuery::update%41B64C1D007B.body
}

// Additional Declarations
  //## begin ExceptionQuery%41B5214D00E3.declarations preserve=yes
  //## end ExceptionQuery%41B5214D00E3.declarations

//## begin module%41B5436B0236.epilog preserve=yes
//## end module%41B5436B0236.epilog
