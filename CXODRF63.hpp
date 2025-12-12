//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%59BAA50900D4.cm preserve=no
//## end module%59BAA50900D4.cm

//## begin module%59BAA50900D4.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%59BAA50900D4.cp

//## Module: CXOSRF63%59BAA50900D4; Package specification
//## Subsystem: RFDLL%439873F400EA
//## Source file: C:\Repos\DataNavigatorServer\Windows\Build\Dn\Server\Library\Rfdll\CXODRF63.hpp

#ifndef CXOSRF63_h
#define CXOSRF63_h 1

//## begin module%59BAA50900D4.additionalIncludes preserve=no
//## end module%59BAA50900D4.additionalIncludes

//## begin module%59BAA50900D4.includes preserve=yes
//## end module%59BAA50900D4.includes

#ifndef CXOSRF73_h
#include "CXODRF73.hpp"
#endif

//## Modelname: DataNavigator Foundation::EntitySegment_CAT%394E275103DB
namespace entitysegment {
class SwitchBusinessDay;
} // namespace entitysegment

//## Modelname: DataNavigator Foundation::RepositorySegment_CAT%394E273800F0
namespace repositorysegment {
class TransactionActivitySegment;
} // namespace repositorysegment

//## Modelname: DataNavigator Foundation::Configuration_CAT%390F33ED01BC
namespace configuration {
class ConfigurationRepository;
class NetworkInstitution;
} // namespace configuration

//## Modelname: Connex Library::Reusable_CAT%3453F15C01AA
namespace reusable {
class KeyRing;
} // namespace reusable

//## Modelname: Connex Library::IF_CAT%3451F55F009E
namespace IF {
class Timestamp;
class CodeTable;
class Memory;
} // namespace IF

//## Modelname: Connex Library::Monitor_CAT%3451FA660166
namespace monitor {
class UseCase;
} // namespace monitor

//## Modelname: Connex Library::Timer_CAT%3451F2410231
namespace timer {
class Clock;
} // namespace timer

//## Modelname: Reconciliation::ReconciliationFile_CAT%439754C1037A
namespace reconciliationfile {
class NetworkSegment;

} // namespace reconciliationfile

//## begin module%59BAA50900D4.declarations preserve=no
//## end module%59BAA50900D4.declarations

//## begin module%59BAA50900D4.additionalDeclarations preserve=yes
//## end module%59BAA50900D4.additionalDeclarations


namespace reconciliationfile {
//## begin reconciliationfile%439754C1037A.initialDeclarations preserve=yes
//## end reconciliationfile%439754C1037A.initialDeclarations

//## begin reconciliationfile::NYCENetworkEDF%59BAA4570128.preface preserve=yes
//## end reconciliationfile::NYCENetworkEDF%59BAA4570128.preface

//## Class: NYCENetworkEDF%59BAA4570128; protected
//	<body>
//	<title>CG
//	<h1>AX
//	<h2>FI
//	<h5>Reconcile Transaction NYCE Network EDF
//	<h6>Reconcile : Transaction : NYCE Network EDF
//	<!- NYCENetworkEDF : General -->
//	<p>
//	Auto Conversion accepts a transaction log in the NYCE
//	Network EDF (NYCEDF)  file format.
//	<p>
//	The transactions are sorted by the following data
//	elements:
//	<ul>
//	<li>Bit 2 - First 6 digits of the primary account number
//	(PAN)
//	<li>Bit 37 - Retrieval reference number
//	<li>Bit 12 - Date and time local transaction
//	<li>Bit 41 - Card acceptor terminal identification
//	<li>Transaction disposition
//	<li>Bit 5 - Value amount reconciliation
//	</ul>
//	<p>
//	This set of data elements is used to match the
//	transactions between the log and the data repository.
//	</body>
//## Category: Reconciliation::ReconciliationFile_CAT%439754C1037A
//## Subsystem: RFDLL%439873F400EA
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%59BAA497037D;IF::Memory { -> F}
//## Uses: <unnamed>%59BAA49901B4;repositorysegment::TransactionActivitySegment { -> F}
//## Uses: <unnamed>%59BAA49B001D;monitor::UseCase { -> F}
//## Uses: <unnamed>%59BAA49C0355;NetworkSegment { -> F}
//## Uses: <unnamed>%59BAA49E039C;timer::Clock { -> F}
//## Uses: <unnamed>%59BAA4A102EC;IF::Timestamp { -> F}
//## Uses: <unnamed>%5C1955BE029A;entitysegment::SwitchBusinessDay { -> F}
//## Uses: <unnamed>%62507D4C0105;configuration::ConfigurationRepository { -> F}
//## Uses: <unnamed>%62507D6C0163;IF::CodeTable { -> F}
//## Uses: <unnamed>%652D345B00B7;reusable::KeyRing { -> F}
//## Uses: <unnamed>%652D3483005C;configuration::NetworkInstitution { -> F}

class DllExport NYCENetworkEDF : public TransactionReportFile  //## Inherits: <unnamed>%669E4BCB01E8
{
  //## begin reconciliationfile::NYCENetworkEDF%59BAA4570128.initialDeclarations preserve=yes
   enum Column
   {
      PAN,
      RETRIEVAL_REF_NO,
      TSTAMP_LOCAL,
      CARD_ACPT_TERM_ID,
      TRAN_DISPOSITION,
      AMT_RECON_NET,
      TSTAMP_TRANS,
      UNIQUENESS_KEY,
      TRAN_TYPE_ID,
      CUR_RECON_NET,
      F_AMTcb,
      F_AMT90,
      ROLE_IND
   };
  //## end reconciliationfile::NYCENetworkEDF%59BAA4570128.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: NYCENetworkEDF%651C26EB00A6
      NYCENetworkEDF (const reusable::string& strClass);

    //## Destructor (generated)
      virtual ~NYCENetworkEDF();


    //## Other Operations (specified)
      //## Operation: join%65605CE40302
      virtual void join (Query& hQuery, const char* pszTable);

      //## Operation: reFormat%59BAA4B70315
      bool reFormat ();

      //## Operation: setBasicPredicate%62AB5D010186
      virtual void setBasicPredicate (Query& hQuery, const string& strTable, int iBegin, int iEnd, int iEntity);

      //## Operation: setMatch%62BDE2950093
      virtual void setMatch ();

      //## Operation: setOrderByClause%62BDE28103AB
      virtual void setOrderByClause (Query& hQuery);

    // Additional Public Declarations
      //## begin reconciliationfile::NYCENetworkEDF%59BAA4570128.public preserve=yes
      //## end reconciliationfile::NYCENetworkEDF%59BAA4570128.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: TRAN_TYPE_ID%65E1D90D0326
      //## begin reconciliationfile::NYCENetworkEDF::TRAN_TYPE_ID%65E1D90D0326.attr preserve=no  protected: reusable::string {UA} 
      reusable::string m_strTRAN_TYPE_ID;
      //## end reconciliationfile::NYCENetworkEDF::TRAN_TYPE_ID%65E1D90D0326.attr

    // Additional Protected Declarations
      //## begin reconciliationfile::NYCENetworkEDF%59BAA4570128.protected preserve=yes
      //## end reconciliationfile::NYCENetworkEDF%59BAA4570128.protected

  private:
    // Additional Private Declarations
      //## begin reconciliationfile::NYCENetworkEDF%59BAA4570128.private preserve=yes
      //## end reconciliationfile::NYCENetworkEDF%59BAA4570128.private

  private: //## implementation
    // Data Members for Class Attributes

      //## Attribute: PAN%652D326C023C
      //## begin reconciliationfile::NYCENetworkEDF::PAN%652D326C023C.attr preserve=no  private: reusable::string {U} 
      reusable::string m_strPAN;
      //## end reconciliationfile::NYCENetworkEDF::PAN%652D326C023C.attr

      //## Attribute: Role%652D32DB000B
      //## begin reconciliationfile::NYCENetworkEDF::Role%652D32DB000B.attr preserve=no  private: reusable::string {U} 
      reusable::string m_strRole;
      //## end reconciliationfile::NYCENetworkEDF::Role%652D32DB000B.attr

    // Additional Implementation Declarations
      //## begin reconciliationfile::NYCENetworkEDF%59BAA4570128.implementation preserve=yes
      //## end reconciliationfile::NYCENetworkEDF%59BAA4570128.implementation

};

//## begin reconciliationfile::NYCENetworkEDF%59BAA4570128.postscript preserve=yes
//## end reconciliationfile::NYCENetworkEDF%59BAA4570128.postscript

} // namespace reconciliationfile

//## begin module%59BAA50900D4.epilog preserve=yes
//## end module%59BAA50900D4.epilog


#endif
