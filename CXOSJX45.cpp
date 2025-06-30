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
#ifndef CXOSES46_h
#include "CXODES46.hpp"
#endif
#ifndef CXOSJX44_h
#include "CXODJX45.hpp"
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

   CaseSummaryCommand::CaseSummaryCommand()
  //## begin RelatedCasesCommand::RelatedCasesCommand%6853CE640095_const.hasinit preserve=no
  //## end RelatedCasesCommand::RelatedCasesCommand%6853CE640095_const.hasinit
  //## begin RelatedCasesCommand::RelatedCasesCommand%6853CE640095_const.initialization preserve=yes
  //## end RelatedCasesCommand::RelatedCasesCommand%6853CE640095_const.initialization
{
  //## begin restcommand::RelatedCasesCommand::RelatedCasesCommand%6853CE640095_const.body preserve=yes

  //## end restcommand::RelatedCasesCommand::RelatedCasesCommand%6853CE640095_const.body
}

   CaseSummaryCommand::CaseSummaryCommand(Handler* pSuccessor)
  //## begin restcommand::RelatedCasesCommand::RelatedCasesCommand%6853D2530341.hasinit preserve=no
  //## end restcommand::RelatedCasesCommand::RelatedCasesCommand%6853D2530341.hasinit
  //## begin restcommand::RelatedCasesCommand::RelatedCasesCommand%6853D2530341.initialization preserve=yes
  //## end restcommand::RelatedCasesCommand::RelatedCasesCommand%6853D2530341.initialization
{
  //## begin restcommand::RelatedCasesCommand::RelatedCasesCommand%6853D2530341.body preserve=yes
   memcpy(m_sID, "JX45", 4);
   m_pSuccessor = pSuccessor;
   m_hXMLText.add('R', &m_hGenericSegment);
   m_hXMLText.add('X', segment::SOAPSegment::instance());
   m_pXMLItem = new XMLItem();
   m_hQuery.attach(this);
  //## end restcommand::RelatedCasesCommand::RelatedCasesCommand%6853D2530341.body
}


   CaseSummaryCommand::~CaseSummaryCommand()
{
  //## begin restcommand::RelatedCasesCommand::~RelatedCasesCommand%6853CE640095_dest.body preserve=yes
  //## end restcommand::RelatedCasesCommand::~RelatedCasesCommand%6853CE640095_dest.body
}



//## Other Operations (implementation)
bool CaseSummaryCommand::execute ()
{
  //## begin restcommand::RelatedCasesCommand::execute%6853D2BF015B.body preserve=yes
   if (!m_pXMLDocument)
#ifdef MVS
      m_pXMLDocument = new XMLDocument("JCL", "RJLHIGH", &m_hRow, &m_hXMLText);
#else
      m_pXMLDocument = new XMLDocument("SOURCE", "CXORJX45", &m_hRow, &m_hXMLText);
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
   save();
   m_pXMLDocument->add("root");
   auto_ptr<SelectStatement> pSelectStatement((SelectStatement*)DatabaseFactory::instance()->create("SelectStatement"));
   



  //## end restcommand::RelatedCasesCommand::execute%6853D2BF015B.body
}

void CaseSummaryCommand::update (Subject* pSubject)
{
  //## begin restcommand::RelatedCasesCommand::update%6853D2F802A2.body preserve=yes
   if (pSubject == &m_hQuery)
   {
      segCaseHighlightSegment* p  = (segCaseHighlightSegment*)m_pszBuffer;
      if (m_hCaseHighlightSegment.getSide()[1].length() > 0
         && (m_hCaseHighlightSegment.getSide()[0] != m_hCaseHighlightSegment.getSide()[1]
            || m_hCaseHighlightSegment.getNET_ID_EMS()[0] != m_hCaseHighlightSegment.getNET_ID_EMS()[1]))
      {
         m_hGenericSegment.set("Institution", m_hCaseHighlightSegment.);
         m_hGenericSegment.set("Role", m_hCaseHighlightSegment.getSide()[0]);
         m_hGenericSegment.set("Network", m_hCaseHighlightSegment.getNET_ID_EMS()[1]);
         m_hGenericSegment.set("open",m_hCaseHighlightSegment.
      }
   }
  //## end restcommand::RelatedCasesCommand::update%6853D2F802A2.body
}

// Additional Declarations
  //## begin restcommand::RelatedCasesCommand%6853CE640095.declarations preserve=yes
  //## end restcommand::RelatedCasesCommand%6853CE640095.declarations

} // namespace restcommand

//## begin module%6853CB7303A2.epilog preserve=yes
//## end module%6853CB7303A2.epilog
