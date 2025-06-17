//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%67BEEF5E029A.cm preserve=no
//## end module%67BEEF5E029A.cm

//## begin module%67BEEF5E029A.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%67BEEF5E029A.cp

//## Module: CXOSJX39%67BEEF5E029A; Package specification
//## Subsystem: JXDLL%645AEC9A0298
//## Source file: C:\Repos\datanavigatorserver\Windows\Build\Dn\Server\Library\Jxdll\CXODJX39.hpp

#ifndef CXOSJX39_h
#define CXOSJX39_h 1

//## begin module%67BEEF5E029A.additionalIncludes preserve=no
//## end module%67BEEF5E029A.additionalIncludes

//## begin module%67BEEF5E029A.includes preserve=yes
//## end module%67BEEF5E029A.includes

#ifndef CXOSRU11_h
#include "CXODRU11.hpp"
#endif
#ifndef CXOSBC65_h
#include "CXODBC65.hpp"
#endif
#ifndef CXOSBS23_h
#include "CXODBS23.hpp"
#endif


//## Modelname: DataNavigator Foundation::EntitySegment_CAT%394E275103DB
namespace entitysegment {
class ContactSegment;
} // namespace entitysegment

//## Modelname: Connex Library::Reusable_CAT%3453F15C01AA
namespace reusable {
class SelectStatement;
} // namespace reusable

//## Modelname: Connex Library::IF_CAT%3451F55F009E
namespace IF {
class Extract;
} // namespace IF

//## Modelname: Connex Library::Database_CAT%3451F34D0218
namespace database {
class DatabaseFactory;
} // namespace database

//## Modelname: Connex Library::Monitor_CAT%3451FA660166
namespace monitor {
class UseCase;
} // namespace monitor

//## Modelname: Connex Library::Segment_CAT%3471F0BE0219
namespace segment {
class SOAPSegment;

} // namespace segment

//## begin module%67BEEF5E029A.declarations preserve=no
//## end module%67BEEF5E029A.declarations

//## begin module%67BEEF5E029A.additionalDeclarations preserve=yes
//## end module%67BEEF5E029A.additionalDeclarations


//## Modelname: DataNavigator Foundation::RESTCommand_CAT%645AEC55037E
namespace restcommand {
//## begin restcommand%645AEC55037E.initialDeclarations preserve=yes
//## end restcommand%645AEC55037E.initialDeclarations

//## begin restcommand::RelatedCaseCommand%67BEF0690257.preface preserve=yes
//## end restcommand::RelatedCaseCommand%67BEF0690257.preface

//## Class: RelatedCaseCommand%67BEF0690257
//	<body>
//	<title>CG
//	<h1>QE
//	<h2>AB
//	<h5>Resolve REST Contacts
//	<h6>Resolve : REST : Contacts
//	<p>
//	Returns a list of contact information.
//	<p>
//	<ul>
//	<li>
										<a href="../../REST/configure/contacts.yaml">YAML</a>
//	</ul>
//	</body>
//## Category: DataNavigator Foundation::RESTCommand_CAT%645AEC55037E
//## Subsystem: JXDLL%645AEC9A0298
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%67BEF10A00E3;monitor::UseCase { -> F}
//## Uses: <unnamed>%67BEF10D01FD;reusable::SelectStatement { -> F}
//## Uses: <unnamed>%67BEF1100394;segment::SOAPSegment { -> F}
//## Uses: <unnamed>%67BEF32A0176;database::DatabaseFactory { -> F}
//## Uses: <unnamed>%67C186CF0200;IF::Extract { -> F}
//## Uses: <unnamed>%67C1B31903B1;entitysegment::ContactSegment { -> F}

class DllExport RelatedCaseCommand : public command::RESTCommand  //## Inherits: <unnamed>%67BEF106012A
{
  //## begin restcommand::RelatedCaseCommand%67BEF0690257.initialDeclarations preserve=yes
  //## end restcommand::RelatedCaseCommand%67BEF0690257.initialDeclarations

  public:
    //## Constructors (generated)
     RelatedCaseCommand();

    //## Constructors (specified)
      //## Operation: RelatedCaseCommand%67BEF23001AA
     RelatedCaseCommand(Handler* pSuccessor);

    //## Destructor (generated)
      virtual ~RelatedCaseCommand();


    //## Other Operations (specified)
      //## Operation: execute%67BEF260020A
      virtual bool execute ();

      //## Operation: update%67BEF287027D
      virtual void update (Subject* pSubject);

    // Additional Public Declarations
      //## begin restcommand::RelatedCaseCommand%67BEF0690257.public preserve=yes
      //## end restcommand::RelatedCaseCommand%67BEF0690257.public
  protected:
    // Additional Protected Declarations
      //## begin restcommand::RelatedCaseCommand%67BEF0690257.protected preserve=yes
      //## end restcommand::RelatedCaseCommand%67BEF0690257.protected

  private:
    // Additional Private Declarations
      //## begin restcommand::RelatedCaseCommand%67BEF0690257.private preserve=yes
      //## end restcommand::RelatedCaseCommand%67BEF0690257.private

  private: //## implementation
    // Data Members for Class Attributes

      //## Attribute: INST_ID%67D408B90121
      //## begin restcommand::RelatedCaseCommand::INST_ID%67D408B90121.attr preserve=no  private: string {U} 
      string m_strCaseNumber;
      //## end restcommand::RelatedCaseCommand::INST_ID%67D408B90121.attr

      //## Attribute: BIN%67D4090F016C
      //## begin restcommand::RelatedCaseCommand::BIN%67D4090F016C.attr preserve=no  private: string {U} 
      string m_strCaseTypeIndicator;
      //## end restcommand::RelatedCaseCommand::BIN%67D4090F016C.attr

      //## Attribute: PROC_ID%67D4094003DF
      //## begin restcommand::RelatedCaseCommand::PROC_ID%67D4094003DF.attr preserve=no  private: string {U} 
      string m_strStateDescription;
      //## end restcommand::RelatedCaseCommand::PROC_ID%67D4094003DF.attr

      //## Attribute: PROC_GRP_ID%67D4095800A7
      //## begin restcommand::RelatedCaseCommand::PROC_GRP_ID%67D4095800A7.attr preserve=no  private: string {U} 
      double m_dTransactionAmount;
      //## end restcommand::RelatedCaseCommand::PROC_GRP_ID%67D4095800A7.attr

      //## Attribute: DEVICE_ID%67D40A530107
      //## begin restcommand::RelatedCaseCommand::DEVICE_ID%67D40A530107.attr preserve=no  private: string {U} 
      double m_dAdjustmentAmount;
      //## end restcommand::RelatedCaseCommand::DEVICE_ID%67D40A530107.attr

      //## Attribute: RPT_LVL_ID%67D40A8C023E
      //## begin restcommand::RelatedCaseCommand::RPT_LVL_ID%67D40A8C023E.attr preserve=no  private: string {U} 
      string m_strRPT_LVL_ID;

      string m_strTSTAMP_TRANS;
      string m_strPAN;
      string m_strRETRIEVAL_REF_NO;
      string m_strSYS_TRACE_AUDIT_NO;

      double m_dAMT_TRAN;
      short m_siUNIQUENESS_KEY;
      string m_strNET_RULES;
      int m_iQuery;
      //## end restcommand::RelatedCaseCommand::RPT_LVL_ID%67D40A8C023E.attr

    // Data Members for Associations

      //## Association: DataNavigator Foundation::RESTCommand_CAT::<unnamed>%67C1764D035B
      //## Role: RelatedCaseCommand::<m_hQuery>%67C1764E0242
      //## begin restcommand::RelatedCaseCommand::<m_hQuery>%67C1764E0242.role preserve=no  public: reusable::Query { -> VHgN}
      reusable::Query m_hQuery;
      reusable::Query hQuery;
      //## end restcommand::RelatedCaseCommand::<m_hQuery>%67C1764E0242.role

      //## Association: DataNavigator Foundation::RESTCommand_CAT::<unnamed>%67C1B2BC0334
      //## Role: RelatedCaseCommand::<m_hGenericSegment>%67C1B2BD0338
      //## begin restcommand::RelatedCaseCommand::<m_hGenericSegment>%67C1B2BD0338.role preserve=no  public: segment::GenericSegment { -> VHgN}
      segment::GenericSegment m_hGenericSegment;
      emssegment::RelatedCaseSegment m_hRelatedCaseSegment;
      //## end restcommand::RelatedCaseCommand::<m_hGenericSegment>%67C1B2BD0338.role

    // Additional Implementation Declarations
      //## begin restcommand::RelatedCaseCommand%67BEF0690257.implementation preserve=yes
      //## end restcommand::RelatedCaseCommand%67BEF0690257.implementation

};

//## begin restcommand::RelatedCaseCommand%67BEF0690257.postscript preserve=yes
//## end restcommand::RelatedCaseCommand%67BEF0690257.postscript

} // namespace restcommand

//## begin module%67BEEF5E029A.epilog preserve=yes
//## end module%67BEEF5E029A.epilog


#endif
