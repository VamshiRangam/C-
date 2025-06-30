//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%6853CB700382.cm preserve=no
//## end module%6853CB700382.cm

//## begin module%6853CB700382.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%6853CB700382.cp

//## Module: CXOSJX44%6853CB700382; Package specification
//## Subsystem: JXDLL%645AEC9A0298
//## Source file: C:\Repos\datanavigatorserver\Windows\Build\Dn\Server\Library\Jxdll\CXODJX44.hpp

#ifndef CXOSJX44_h
#define CXOSJX44_h 1

//## begin module%6853CB700382.additionalIncludes preserve=no
//## end module%6853CB700382.additionalIncludes

//## begin module%6853CB700382.includes preserve=yes
//## end module%6853CB700382.includes

#ifndef CXOSRU11_h
#include "CXODRU11.hpp"
#endif
#ifndef CXOSBS23_h
#include "CXODBS23.hpp"
#endif
#ifndef CXOSBC65_h
#include "CXODBC65.hpp"
#endif
#ifndef CXOSES46_h
#include "CXODES46.hpp"
#endif

//## Modelname: Transaction Research and Adjustments::EMSSegment_CAT%394E27A9030F
namespace emssegment {
class CaseSegment;
} // namespace emssegment

//## Modelname: Connex Library::Reusable_CAT%3453F15C01AA
namespace reusable {
class SelectStatement;
} // namespace reusable

//## Modelname: Connex Library::Monitor_CAT%3451FA660166
namespace monitor {
class UseCase;
} // namespace monitor

//## Modelname: Connex Library::Database_CAT%3451F34D0218
namespace database {
class DatabaseFactory;
} // namespace database

//## Modelname: Connex Library::Segment_CAT%3471F0BE0219
namespace segment {
class SOAPSegment;
} // namespace segment

//## Modelname: Connex Library::Rules_CAT (RLDLL)%3EB810F40157
namespace rules {
class RulesEngine;

} // namespace rules

//## begin module%6853CB700382.declarations preserve=no
//## end module%6853CB700382.declarations

//## begin module%6853CB700382.additionalDeclarations preserve=yes
//## end module%6853CB700382.additionalDeclarations


//## Modelname: DataNavigator Foundation::RESTCommand_CAT%645AEC55037E
namespace restcommand {
//## begin restcommand%645AEC55037E.initialDeclarations preserve=yes
//## end restcommand%645AEC55037E.initialDeclarations

//## begin restcommand::RelatedCasesCommand%6853CE640095.preface preserve=yes
//## end restcommand::RelatedCasesCommand%6853CE640095.preface

//## Class: RelatedCasesCommand%6853CE640095
//	<body>
//	<title>CG
//	<h1>QE
//	<h2>AB
//	<h5>Resolve REST Relatedcases
//	<h6>Resolve : REST : Relatedcases
//	<p>
//	Returns Related cases associated with the TSTAMPTRANS
//	<p>
//	<ul>
//	<li><a
//	href="../../REST/resolve/relatedcases.yaml">YAML</a>
//	</ul>
//	</body>
//## Category: DataNavigator Foundation::RESTCommand_CAT%645AEC55037E
//## Subsystem: JXDLL%645AEC9A0298
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%6853EA1703CE;monitor::UseCase { -> F}
//## Uses: <unnamed>%6853EA67020B;reusable::Query { -> F}
//## Uses: <unnamed>%6853EA870175;reusable::SelectStatement { -> F}
//## Uses: <unnamed>%6853F1540076;database::DatabaseFactory { -> F}
//## Uses: <unnamed>%6853F15903E4;rules::RulesEngine { -> F}
//## Uses: <unnamed>%6853F15F028D;segment::SOAPSegment { -> F}
//## Uses: <unnamed>%6853F16402EC;emssegment::CaseSegment { -> F}

class DllExport CaseSummaryCommand : public command::RESTCommand  //## Inherits: <unnamed>%6853D3D1027C
{
  //## begin restcommand::RelatedCasesCommand%6853CE640095.initialDeclarations preserve=yes
  //## end restcommand::RelatedCasesCommand%6853CE640095.initialDeclarations

  public:
    //## Constructors (generated)
     CaseSummaryCommand();

    //## Constructors (specified)
      //## Operation: RelatedCasesCommand%6853D2530341
     CaseSummaryCommand(Handler* pSuccessor);

    //## Destructor (generated)
      virtual ~CaseSummaryCommand();


    //## Other Operations (specified)
      //## Operation: execute%6853D2BF015B
      virtual bool execute ();

      //## Operation: update%6853D2F802A2
      virtual void update (Subject* pSubject);

    // Additional Public Declarations
      //## begin restcommand::RelatedCasesCommand%6853CE640095.public preserve=yes
      //## end restcommand::RelatedCasesCommand%6853CE640095.public

  protected:
    // Additional Protected Declarations
      //## begin restcommand::RelatedCasesCommand%6853CE640095.protected preserve=yes
      //## end restcommand::RelatedCasesCommand%6853CE640095.protected

  private:
    // Additional Private Declarations
      //## begin restcommand::RelatedCasesCommand%6853CE640095.private preserve=yes
      //## end restcommand::RelatedCasesCommand%6853CE640095.private

  private: //## implementation
    // Data Members for Class Attributes

      //## Attribute: AMT_TRAN%6853FB45014F
      //## begin restcommand::RelatedCasesCommand::AMT_TRAN%6853FB45014F.attr preserve=no  private: double {U} 
      double m_dAMT_TRAN;
      //## end restcommand::RelatedCasesCommand::AMT_TRAN%6853FB45014F.attr

      //## Attribute: NET_RULES%6853FBFD0034
      //## begin restcommand::RelatedCasesCommand::NET_RULES%6853FBFD0034.attr preserve=no  private: string {U} 
      string m_strNET_RULES;
      //## end restcommand::RelatedCasesCommand::NET_RULES%6853FBFD0034.attr

      //## Attribute: PAN%6853FC370134
      //## begin restcommand::RelatedCasesCommand::PAN%6853FC370134.attr preserve=no  private: string {U} 
      string m_strPAN;
      //## end restcommand::RelatedCasesCommand::PAN%6853FC370134.attr

      //## Attribute: RETRIEVAL_REF_NO%6853FC6E026A
      //## begin restcommand::RelatedCasesCommand::RETRIEVAL_REF_NO%6853FC6E026A.attr preserve=no  private: string {U} 
      string m_strRETRIEVAL_REF_NO;
      //## end restcommand::RelatedCasesCommand::RETRIEVAL_REF_NO%6853FC6E026A.attr

      //## Attribute: StateDescription%6853FC9C0142
      //## begin restcommand::RelatedCasesCommand::StateDescription%6853FC9C0142.attr preserve=no  private: string {U} 
      string m_strStateDescription;
      //## end restcommand::RelatedCasesCommand::StateDescription%6853FC9C0142.attr

      //## Attribute: SYS_TRACE_AUDIT_NO%6853FCCD0388
      //## begin restcommand::RelatedCasesCommand::SYS_TRACE_AUDIT_NO%6853FCCD0388.attr preserve=no  private: string {U} 
      string m_strSYS_TRACE_AUDIT_NO;
      //## end restcommand::RelatedCasesCommand::SYS_TRACE_AUDIT_NO%6853FCCD0388.attr

      //## Attribute: TSTAMP_TRANS%6853FD060291
      //## begin restcommand::RelatedCasesCommand::TSTAMP_TRANS%6853FD060291.attr preserve=no  private: string {U} 
      string m_strTSTAMP_TRANS;
      //## end restcommand::RelatedCasesCommand::TSTAMP_TRANS%6853FD060291.attr

      //## Attribute: UNIQUENESS_KEY%6853FD2A00BC
      //## begin restcommand::RelatedCasesCommand::UNIQUENESS_KEY%6853FD2A00BC.attr preserve=no  private: short {U} 
      short m_siUNIQUENESS_KEY;
      //## end restcommand::RelatedCasesCommand::UNIQUENESS_KEY%6853FD2A00BC.attr

    // Data Members for Associations

      //## Association: DataNavigator Foundation::RESTCommand_CAT::<unnamed>%6853F82403C6
      //## Role: RelatedCasesCommand::<m_hRelatedCaseSegment>%6853F8260039
      //## begin restcommand::RelatedCasesCommand::<m_hRelatedCaseSegment>%6853F8260039.role preserve=no  public: emssegment::RelatedCaseSegment { -> VHgN}
      //emssegment::RelatedCaseSegment m_hRelatedCaseSegment;
      emssegment::CaseHighlightSegment m_hCaseHighlightSegment;
      //## end restcommand::RelatedCasesCommand::<m_hRelatedCaseSegment>%6853F8260039.role

      //## Association: DataNavigator Foundation::RESTCommand_CAT::<unnamed>%6853F8FF0199
      //## Role: RelatedCasesCommand::<m_hGenericSegment>%6853F90001E6
      //## begin restcommand::RelatedCasesCommand::<m_hGenericSegment>%6853F90001E6.role preserve=no  public: segment::GenericSegment { -> VHgN}
      segment::GenericSegment m_hGenericSegment;
      //## end restcommand::RelatedCasesCommand::<m_hGenericSegment>%6853F90001E6.role

      //## Association: DataNavigator Foundation::RESTCommand_CAT::<unnamed>%685422030179
      //## Role: RelatedCasesCommand::<m_hQuery>%685422040309
      //## begin restcommand::RelatedCasesCommand::<m_hQuery>%685422040309.role preserve=no  public: reusable::Query { -> VHgN}
      reusable::Query m_hQuery;
      char* m_pszBuffer;
      //## end restcommand::RelatedCasesCommand::<m_hQuery>%685422040309.role

    // Additional Implementation Declarations
      //## begin restcommand::RelatedCasesCommand%6853CE640095.implementation preserve=yes
      //## end restcommand::RelatedCasesCommand%6853CE640095.implementation

};

//## begin restcommand::RelatedCasesCommand%6853CE640095.postscript preserve=yes
//## end restcommand::RelatedCasesCommand%6853CE640095.postscript

} // namespace restcommand

//## begin module%6853CB700382.epilog preserve=yes
//## end module%6853CB700382.epilog


#endif
