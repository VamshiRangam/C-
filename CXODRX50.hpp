//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%65D57E3A02E8.cm preserve=no
//## end module%65D57E3A02E8.cm

//## begin module%65D57E3A02E8.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%65D57E3A02E8.cp

//## Module: CXOSRX50%65D57E3A02E8; Package specification
//## Subsystem: RXDLL%5C47391001FD
//## Source file: C:\Repos\DataNavigatorServer\Windows\Build\Dn\Server\Library\Rxdll\CXODRX50.hpp

#ifndef CXOSRX50_h
#define CXOSRX50_h 1

//## begin module%65D57E3A02E8.additionalIncludes preserve=no
//## end module%65D57E3A02E8.additionalIncludes

//## begin module%65D57E3A02E8.includes preserve=yes
//## end module%65D57E3A02E8.includes

#ifndef CXOSDB25_h
#include "CXODDB25.hpp"
#endif

//## Modelname: Connex Library::Reusable_CAT%3453F15C01AA
namespace reusable {
class Buffer;
} // namespace reusable

//## Modelname: Connex Library::IF_CAT%3451F55F009E
namespace IF {
class FlatFile;
} // namespace IF

//## Modelname: Connex Library::Database_CAT%3451F34D0218
namespace database {
class ReportFactory;

} // namespace database

//## begin module%65D57E3A02E8.declarations preserve=no
//## end module%65D57E3A02E8.declarations

//## begin module%65D57E3A02E8.additionalDeclarations preserve=yes
//## end module%65D57E3A02E8.additionalDeclarations


//## Modelname: Data Distribution::Report_CAT%5C473883000E
namespace report {
//## begin report%5C473883000E.initialDeclarations preserve=yes
//## end report%5C473883000E.initialDeclarations

//## begin report::NYCENetworkEDF%65D57DD40100.preface preserve=yes
//## end report::NYCENetworkEDF%65D57DD40100.preface

//## Class: NYCENetworkEDF%65D57DD40100
//## Category: Data Distribution::Report_CAT%5C473883000E
//## Subsystem: RXDLL%5C47391001FD
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%65D7BE2B0335;IF::FlatFile { -> F}
//## Uses: <unnamed>%65D7BE2E01B5;database::ReportFactory { -> F}
//## Uses: <unnamed>%65D7BE3100D5;reusable::Buffer { -> F}

class DllExport NYCENetworkEDF : public database::ExportFile  //## Inherits: <unnamed>%65D7BE2900DD
{
  //## begin report::NYCENetworkEDF%65D57DD40100.initialDeclarations preserve=yes
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
  //## end report::NYCENetworkEDF%65D57DD40100.initialDeclarations

  public:
    //## Constructors (generated)
      NYCENetworkEDF();

    //## Destructor (generated)
      virtual ~NYCENetworkEDF();


    //## Other Operations (specified)
      //## Operation: distribute%65D7BE400172
      virtual bool distribute (string& strDATA_BUFFER, IF::FlatFile& hFlatFile);

      //## Operation: finish%65D7BE5100E8
      virtual bool finish (IF::FlatFile& hFlatFile);

      //## Operation: start%65D7BE540224
      virtual bool start (IF::FlatFile& hFlatFile);

    // Additional Public Declarations
      //## begin report::NYCENetworkEDF%65D57DD40100.public preserve=yes
      //## end report::NYCENetworkEDF%65D57DD40100.public

  protected:
    // Additional Protected Declarations
      //## begin report::NYCENetworkEDF%65D57DD40100.protected preserve=yes
      //## end report::NYCENetworkEDF%65D57DD40100.protected

  private:
    // Additional Private Declarations
      //## begin report::NYCENetworkEDF%65D57DD40100.private preserve=yes
      //## end report::NYCENetworkEDF%65D57DD40100.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin report::NYCENetworkEDF%65D57DD40100.implementation preserve=yes
      //## end report::NYCENetworkEDF%65D57DD40100.implementation

};

//## begin report::NYCENetworkEDF%65D57DD40100.postscript preserve=yes
//## end report::NYCENetworkEDF%65D57DD40100.postscript

} // namespace report

//## begin module%65D57E3A02E8.epilog preserve=yes
//## end module%65D57E3A02E8.epilog


#endif
