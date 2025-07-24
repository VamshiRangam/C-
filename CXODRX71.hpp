//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%6809B69F0097.cm preserve=no
//## end module%6809B69F0097.cm

//## begin module%6809B69F0097.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%6809B69F0097.cp

//## Module: CXOSRX71%6809B69F0097; Package specification
//## Subsystem: RXDLL%5C47391001FD
//## Source file: C:\Repos\datanavigatorserver\Windows\Build\Dn\Server\Library\Rxdll\CXODRX71.hpp

#ifndef CXOSRX71_h
#define CXOSRX71_h 1

//## begin module%6809B69F0097.additionalIncludes preserve=no
//## end module%6809B69F0097.additionalIncludes

//## begin module%6809B69F0097.includes preserve=yes
//## end module%6809B69F0097.includes

#ifndef CXOSDB25_h
#include "CXODDB25.hpp"
#endif
#ifndef CXOSRU11_h
#include "CXODRU11.hpp"
#endif
#ifndef CXOSPF34_h
#include "CXODPF34.hpp"
#endif
#ifndef CXOSRX04_h
#include "CXODRX04.hpp"
#endif

//## Modelname: DataNavigator Foundation::Configuration_CAT%390F33ED01BC
namespace configuration {
class ConfigurationRepository;
} // namespace configuration

//## Modelname: Connex Library::Reusable_CAT%3453F15C01AA
namespace reusable {
class SelectStatement;
} // namespace reusable

//## Modelname: Connex Library::IF_CAT%3451F55F009E
namespace IF {
class Extract;
} // namespace IF

namespace reusable {
class KeyRing;
} // namespace reusable

namespace IF {
class FlatFile;
} // namespace IF

//## Modelname: Connex Library::Monitor_CAT%3451FA660166
namespace monitor {
class UseCase;
} // namespace monitor

//## Modelname: Connex Library::Timer_CAT%3451F2410231
namespace timer {
class Date;
class Clock;
} // namespace timer

//## Modelname: Connex Library::Database_CAT%3451F34D0218
namespace database {
class Context;
class DatabaseFactory;
class ReportFactory;
class UniquenessKey;
} // namespace database

//## Modelname: Connex Library::Process_CAT%3453F1510045
namespace process {
class Application;
} // namespace process

//## Modelname: Connex Library::Segment_CAT%3471F0BE0219
namespace segment {
class GenericSegment;
} // namespace segment

//## Modelname: Data Distribution::Report_CAT%5C473883000E
namespace report {
class Report;

} // namespace report

//## begin module%6809B69F0097.declarations preserve=no
//## end module%6809B69F0097.declarations

//## begin module%6809B69F0097.additionalDeclarations preserve=yes
//## end module%6809B69F0097.additionalDeclarations


namespace report {
//## begin report%5C473883000E.initialDeclarations preserve=yes
//## end report%5C473883000E.initialDeclarations

//## begin report::TC57TransactionFile%6260E53402B5.preface preserve=yes
   enum CmpFields
   {
      PAN,
      RETRIEVAL_REF_NO,
      APPROVAL_CODE,
      MTI,
      TSTAMP_TRANS,
      REF_DATA_ISS,
      PROC_ID_ISS_B,
      NET_ID_ISS
   };
//## end report::TC57TransactionFile%6260E53402B5.preface

//## Class: TC57TransactionFile%6260E53402B5
//## Category: Data Distribution::Report_CAT%5C473883000E
//## Subsystem: RXDLL%5C47391001FD
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%6260E854029A;configuration::ConfigurationRepository { -> F}
//## Uses: <unnamed>%6260E86903E6;IF::FlatFile { -> F}
//## Uses: <unnamed>%6260E89E0206;timer::Date { -> F}
//## Uses: <unnamed>%6260E8A402B8;timer::Clock { -> F}
//## Uses: <unnamed>%6260E8AA01FB;monitor::UseCase { -> F}
//## Uses: <unnamed>%6260E8B10242;database::ReportFactory { -> F}
//## Uses: <unnamed>%6260E8B6037D;segment::GenericSegment { -> F}
//## Uses: <unnamed>%626124BE03B2;IF::Extract { -> F}
//## Uses: <unnamed>%626126C001FC;reusable::KeyRing { -> F}
//## Uses: <unnamed>%66A23CC40055;process::Application { -> F}
//## Uses: <unnamed>%67DD9CD1028D;database::UniquenessKey { -> F}
//## Uses: <unnamed>%67DD9CE702BB;database::DatabaseFactory { -> F}
//## Uses: <unnamed>%67DD9D0001A3;reusable::SelectStatement { -> F}
//## Uses: <unnamed>%680A932F0346;Report { -> F}

class DllExport TC57TransactionFile : public postingfile::ReportFile  //## Inherits: <unnamed>%6260E6A702FF
{
  //## begin report::TC57TransactionFile%6260E53402B5.initialDeclarations preserve=yes
  //## end report::TC57TransactionFile%6260E53402B5.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: TC57TransactionFile%6811780801BD
      TC57TransactionFile (const char* pszClass);

    //## Destructor (generated)
      virtual ~TC57TransactionFile();


    //## Other Operations (specified)
      //## Operation: distribute%6261014A0217
      virtual bool distribute (string& strDATA_BUFFER, IF::FlatFile& hFlatFile);

      //## Operation: finish%626102170265
      virtual bool finish (IF::FlatFile& hFlatFile);

      //## Operation: initialize%6261024703D8
      virtual bool initialize ();

      //## Operation: mapToken%67F3F1930299
      virtual bool mapToken (reusable::string& strToken, const map<char,reusable::Object*, less<char> >& hSegment, string& strValue);

      //## Operation: setAcctType%67F3F02603AC
      void setAcctType (string& strValue);

      //## Operation: setCardHolderFlags%67F3F08F0276
      void setCardHolderFlags (string& strValue);

      //## Operation: setCardholderIDMethod%67F3EF88018F
      void setCardholderIDMethod (string& strValue);

      //## Operation: setCardType%67F3EF6B00B8
      void setCardType (string& strValue);

      //## Operation: setCATLevelInd%67F3EF2803CD
      void setCATLevelInd (string& strValue);

      //## Operation: setChannelInd%67F3F0F3031D
      void setChannelInd (string& strValue);

      //## Operation: setECommerceInd%67F3EFE70129
      void setECommerceInd (string& strValue);

      //## Operation: setFilmLocator%67F3EFC80076
      void setFilmLocator (string& strValue);

      //## Operation: setIsfcCode%67F3F0D50232
      void setIsfcCode (string& strValue);

      //## Operation: setLocationName%67F3F0AE0382
      void setLocationName (string& strValue);

      //## Operation: setOrderByClause%6261026500FF
      virtual void setOrderByClause (reusable::Query& hQuery);

      //## Operation: setPOSDebitReimbAttr%67F3F00800D2
      void setPOSDebitReimbAttr (string& strValue);

      //## Operation: setPOSEntryMode%67F3F04F0265
      void setPOSEntryMode (string& strValue);
      void setAVSresponseCode(string& strValue);

      //## Operation: setPrepaidCardInd%67F3EF4C0040
      void setPrepaidCardInd (string& strValue);

      //## Operation: setRecurringPaymentIndicator%67F3EEED021E
      void setRecurringPaymentIndicator (string& strValue);

      //## Operation: setTokenRequestorId%67F3F06E03D5
      void setTokenRequestorId (string& strValue);

      //## Operation: setTransactionType%67F3EFA80110
      void setTransactionType (string& strValue);

      //## Operation: start%67DD90DA01E6
      bool start (IF::FlatFile& hFlatFile);

      //## Operation: unionAll%67DD910C0057
      bool unionAll (Query& hQuery);

    // Data Members for Class Attributes

      //## Attribute: AuthREF_DATA_ISS%67DD92B30167
      //## begin report::TC57TransactionFile::AuthREF_DATA_ISS%67DD92B30167.attr preserve=no  public: string {V} 
      string m_strAuthREF_DATA_ISS;
      //## end report::TC57TransactionFile::AuthREF_DATA_ISS%67DD92B30167.attr

      //## Attribute: Field%67DD931901C5
      //## begin report::TC57TransactionFile::Field%67DD931901C5.attr preserve=no  public: int[8][2] {U} 
      int m_iField[8][2];
      //## end report::TC57TransactionFile::Field%67DD931901C5.attr

      //## Attribute: FieldMaxLen%67DD92D50200
      //## begin report::TC57TransactionFile::FieldMaxLen%67DD92D50200.attr preserve=no  public: int {V} 0
      int m_iFieldMaxLen;
      //## end report::TC57TransactionFile::FieldMaxLen%67DD92D50200.attr

    // Additional Public Declarations
      //## begin report::TC57TransactionFile%6260E53402B5.public preserve=yes
      void setNetworkTransportChannel(string& strValue);
      //## end report::TC57TransactionFile%6260E53402B5.public

  protected:
    // Additional Protected Declarations
      //## begin report::TC57TransactionFile%6260E53402B5.protected preserve=yes
      //## end report::TC57TransactionFile%6260E53402B5.protected

  private:

    //## Other Operations (specified)
      //## Operation: getGenericValue%626104E903D0
      bool getGenericValue (const string& strType, const string& strFromValue, string& strToValue);

      //## Operation: write_TCR0_BatchHeader%626103D50392
      bool write_TCR0_BatchHeader (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR0_BatchTrailer%6261041003C3
      bool write_TCR0_BatchTrailer (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR0_TxnDetail%626103F00319
      bool write_TCR0_TxnDetail (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR1_AmexTxnDetailAdviceBasic%633EBF2300A1
      bool write_TCR1_AmexTxnDetailAdviceBasic (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR1_BatchHeader%626103E9012D
      bool write_TCR1_BatchHeader (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR1_DinersIntlChargeDetailRecord%6268B338005A
      bool write_TCR1_DinersIntlChargeDetailRecord (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR1_TxnDetail_Common%626103F501BF
      bool write_TCR1_TxnDetail_Common (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR2_AmexCAPNBatchHeader%633EBEFA0373
      bool write_TCR2_AmexCAPNBatchHeader (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR3_DinersIntlChipAddtlRecord%633EBF340378
      bool write_TCR3_DinersIntlChipAddtlRecord (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR3_PassangerTravelLegRecord%6268B2BD01DF
      bool write_TCR3_PassangerTravelLegRecord (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR3_TxnDetail_PaymentServiceData%6268B2160286
      bool write_TCR3_TxnDetail_PaymentServiceData (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR4_AmexTxnDetailLocation%633EBF2B0204
      bool write_TCR4_AmexTxnDetailLocation (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR4_TxnDetail_VISA%6261045F024E
      bool write_TCR4_TxnDetail_VISA (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR4_VisaSMS%67DD9017031C
      bool write_TCR4_VisaSMS (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR5_TxnDetail_MC%6261045500ED
      bool write_TCR5_TxnDetail_MC (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR7_Chip_All%65F156F1006E
      bool write_TCR7_Chip_All (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR90_FileHeader%626103A70158
      bool write_TCR90_FileHeader (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR91_BatchTrailer%6261041B03A7
      bool write_TCR91_BatchTrailer (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR92_FileTrailer%6261042801AE
      bool write_TCR92_FileTrailer (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR99_Coles%62610406021F
      bool write_TCR99_Coles (IF::FlatFile& hFlatFile);

      //## Operation: write_TCR99_CustomRecord%62EBCD260058
      bool write_TCR99_CustomRecord (IF::FlatFile& hFlatFile);

      //## Operation: writeUnMatchedAuth%67DD91390009
      bool writeUnMatchedAuth ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: AdvRevTran%67DD955902C1
      const bool& getAdvRevTran () const
      {
        //## begin report::TC57TransactionFile::getAdvRevTran%67DD955902C1.get preserve=no
        return m_bAdvRevTran;
        //## end report::TC57TransactionFile::getAdvRevTran%67DD955902C1.get
      }

      void setAdvRevTran (const bool& value)
      {
        //## begin report::TC57TransactionFile::setAdvRevTran%67DD955902C1.set preserve=no
        m_bAdvRevTran = value;
        //## end report::TC57TransactionFile::setAdvRevTran%67DD955902C1.set
      }


    // Additional Private Declarations
      //## begin report::TC57TransactionFile%6260E53402B5.private preserve=yes
      bool write_TCR1_TxnDetail_UPI(IF::FlatFile& hFlatFile);
      //## end report::TC57TransactionFile%6260E53402B5.private

  private: //## implementation
    // Data Members for Class Attributes

      //## Attribute: ADL_DATA_PRIV_ACQ%635F7B4E01E1
      //## begin report::TC57TransactionFile::ADL_DATA_PRIV_ACQ%635F7B4E01E1.attr preserve=no  private: char[256] {U} 
      char m_szADL_DATA_PRIV_ACQ[256];
      //## end report::TC57TransactionFile::ADL_DATA_PRIV_ACQ%635F7B4E01E1.attr

      //## Attribute: ADL_DATA_PRIV_ISS%635F7B6202B3
      //## begin report::TC57TransactionFile::ADL_DATA_PRIV_ISS%635F7B6202B3.attr preserve=no  private: char[256] {U} 
      char m_szADL_DATA_PRIV_ISS[256];
      //## end report::TC57TransactionFile::ADL_DATA_PRIV_ISS%635F7B6202B3.attr

      //## Attribute: ADL_RESP_DATA%635F7B710066
      //## begin report::TC57TransactionFile::ADL_RESP_DATA%635F7B710066.attr preserve=no  private: char[100] {U} 
      char m_szADL_RESP_DATA[100];
      //## end report::TC57TransactionFile::ADL_RESP_DATA%635F7B710066.attr

      //## begin report::TC57TransactionFile::AdvRevTran%67DD955902C1.attr preserve=no  private: bool {U} false
      bool m_bAdvRevTran;
      //## end report::TC57TransactionFile::AdvRevTran%67DD955902C1.attr

      //## Attribute: AuthAltRecKey%67DD95CF01CF
      //## begin report::TC57TransactionFile::AuthAltRecKey%67DD95CF01CF.attr preserve=no  private: string {U} 
      string m_strAuthAltRecKey;
      //## end report::TC57TransactionFile::AuthAltRecKey%67DD95CF01CF.attr

      //## Attribute: AuthBuffer%67DD95B300F9
      //## begin report::TC57TransactionFile::AuthBuffer%67DD95B300F9.attr preserve=no  private: string {U} 
      string m_strAuthBuffer;
      //## end report::TC57TransactionFile::AuthBuffer%67DD95B300F9.attr

      //## Attribute: BatchGrossAmt%626108430130
      //## begin report::TC57TransactionFile::BatchGrossAmt%626108430130.attr preserve=no  private: double {U} 0
      double m_dBatchGrossAmt;
      //## end report::TC57TransactionFile::BatchGrossAmt%626108430130.attr

      //## Attribute: BatchKey%67DD9D93023F
      //## begin report::TC57TransactionFile::BatchKey%67DD9D93023F.attr preserve=no  private: string {V} 
      string m_strBatchKey;
      //## end report::TC57TransactionFile::BatchKey%67DD9D93023F.attr

      //## Attribute: BatchNo%6811C1510188
      //## begin report::TC57TransactionFile::BatchNo%6811C1510188.attr preserve=no  private: int {U} 0
      int m_iBatchNo;
      //## end report::TC57TransactionFile::BatchNo%6811C1510188.attr

      //## Attribute: BatchNetAmt%6261081401EF
      //## begin report::TC57TransactionFile::BatchNetAmt%6261081401EF.attr preserve=no  private: double {U} 0
      double m_dBatchNetAmt;
      //## end report::TC57TransactionFile::BatchNetAmt%6261081401EF.attr

      //## Attribute: BatchToValue%6261076D03DA
      //## begin report::TC57TransactionFile::BatchToValue%6261076D03DA.attr preserve=no  private: string {U} 
      string m_strBatchToValue;
      //## end report::TC57TransactionFile::BatchToValue%6261076D03DA.attr

      //## Attribute: Constants%67DD9530007C
      //## begin report::TC57TransactionFile::Constants%67DD9530007C.attr preserve=no  private: vector<string> {U} 
      vector<string> m_hConstants;
      //## end report::TC57TransactionFile::Constants%67DD9530007C.attr

      //## Attribute: DATA_PRIV_ACQ%635F7B7F03B0
      //## begin report::TC57TransactionFile::DATA_PRIV_ACQ%635F7B7F03B0.attr preserve=no  private: char[101] {U} 
      char m_szDATA_PRIV_ACQ[101];
      //## end report::TC57TransactionFile::DATA_PRIV_ACQ%635F7B7F03B0.attr

      //## Attribute: DATA_PRIV_ISS%67DD945E03A5
      //## begin report::TC57TransactionFile::DATA_PRIV_ISS%67DD945E03A5.attr preserve=no  private: char[101] {U} 
      char m_szDATA_PRIV_ISS[101];
      //## end report::TC57TransactionFile::DATA_PRIV_ISS%67DD945E03A5.attr

      //## Attribute: DF09Presence%67DD96610040
      //## begin report::TC57TransactionFile::DF09Presence%67DD96610040.attr preserve=no  private: bool {U} false
      bool m_bDF09Presence;
      //## end report::TC57TransactionFile::DF09Presence%67DD96610040.attr

      //## Attribute: EXTENSION_DATA_ADJ%635F7B95000B
      //## begin report::TC57TransactionFile::EXTENSION_DATA_ADJ%635F7B95000B.attr preserve=no  private: char[401] {U} 
      char m_szEXTENSION_DATA_ADJ[401];
      //## end report::TC57TransactionFile::EXTENSION_DATA_ADJ%635F7B95000B.attr

      //## Attribute: MinAuth%67DD963F0351
      //## begin report::TC57TransactionFile::MinAuth%67DD963F0351.attr preserve=no  private: string {U} 
      string m_strMinAuth;
      //## end report::TC57TransactionFile::MinAuth%67DD963F0351.attr

      //## Attribute: PrevAuth%67DD95730113
      //## begin report::TC57TransactionFile::PrevAuth%67DD95730113.attr preserve=no  private: bool {U} false
      bool m_bPrevAuth;
      //## end report::TC57TransactionFile::PrevAuth%67DD95730113.attr

      //## Attribute: REF_DATA_ISS%635F7AB3020A
      //## begin report::TC57TransactionFile::REF_DATA_ISS%635F7AB3020A.attr preserve=no  private: char[100] {U} 
      char m_szREF_DATA_ISS[100];
      //## end report::TC57TransactionFile::REF_DATA_ISS%635F7AB3020A.attr

      //## Attribute: SeqNo%67DD960D022E
      //## begin report::TC57TransactionFile::SeqNo%67DD960D022E.attr preserve=no  private: int {U} 100
      int m_iSeqNo;
      //## end report::TC57TransactionFile::SeqNo%67DD960D022E.attr

      //## Attribute: Token%67F72090038F
      //## begin report::TC57TransactionFile::Token%67F72090038F.attr preserve=no  private: string {U} 
      string m_strToken;
      //## end report::TC57TransactionFile::Token%67F72090038F.attr

      //## Attribute: TotNetAmt%6261089A0286
      //## begin report::TC57TransactionFile::TotNetAmt%6261089A0286.attr preserve=no  private: double {U} 0
      double m_dTotNetAmt;
      //## end report::TC57TransactionFile::TotNetAmt%6261089A0286.attr

    // Data Members for Associations

      //## Association: Data Distribution::Report_CAT::<unnamed>%67DD972D02D8
      //## Role: TC57TransactionFile::<m_hQuery>%67DD972E028F
      //## begin report::TC57TransactionFile::<m_hQuery>%67DD972E028F.role preserve=no  public: reusable::Query { -> 2VHgN}
      reusable::Query m_hQuery[2];
      //## end report::TC57TransactionFile::<m_hQuery>%67DD972E028F.role

      //## Association: Data Distribution::Report_CAT::<unnamed>%67DD98CD02F8
      //## Role: TC57TransactionFile::<m_hActivitySegment>%67DD98CE0238
      //## begin report::TC57TransactionFile::<m_hActivitySegment>%67DD98CE0238.role preserve=no  public: report::ActivitySegment { -> 3VHgN}
      ActivitySegment m_hActivitySegment[3];
      //## end report::TC57TransactionFile::<m_hActivitySegment>%67DD98CE0238.role

      //## Association: Data Distribution::Report_CAT::<unnamed>%67DD9977038A
      //## Role: TC57TransactionFile::<m_pUnMatchFile>%67DD9978021A
      //## begin report::TC57TransactionFile::<m_pUnMatchFile>%67DD9978021A.role preserve=no  public: database::ExportFile { -> RHgN}
      database::ExportFile *m_pUnMatchFile;
      //## end report::TC57TransactionFile::<m_pUnMatchFile>%67DD9978021A.role

      //## Association: Data Distribution::Report_CAT::<unnamed>%67F3FC130310
      //## Role: TC57TransactionFile::<m_pGenericSegment>%67F3FC14020D
      //## begin report::TC57TransactionFile::<m_pGenericSegment>%67F3FC14020D.role preserve=no  public: segment::GenericSegment { -> RFHgN}
      segment::GenericSegment *m_pGenericSegment;
      //## end report::TC57TransactionFile::<m_pGenericSegment>%67F3FC14020D.role

      //## Association: Data Distribution::Report_CAT::<unnamed>%67F923AE00E8
      //## Role: TC57TransactionFile::<m_pReport>%67F923AE03A0
      //## begin report::TC57TransactionFile::<m_pReport>%67F923AE03A0.role preserve=no  public: report::Report { -> RFHgN}
      Report *m_pReport;
      //## end report::TC57TransactionFile::<m_pReport>%67F923AE03A0.role

      //## Association: Data Distribution::Report_CAT::<unnamed>%680A92240111
      //## Role: TC57TransactionFile::<m_pContext>%680A92260060
      //## begin report::TC57TransactionFile::<m_pContext>%680A92260060.role preserve=no  public: database::Context { -> RFHgN}
      database::Context *m_pContext;
      //## end report::TC57TransactionFile::<m_pContext>%680A92260060.role

    // Additional Implementation Declarations
      //## begin report::TC57TransactionFile%6260E53402B5.implementation preserve=yes
      //## end report::TC57TransactionFile%6260E53402B5.implementation

};

//## begin report::TC57TransactionFile%6260E53402B5.postscript preserve=yes
//## end report::TC57TransactionFile%6260E53402B5.postscript

} // namespace report

//## begin module%6809B69F0097.epilog preserve=yes
//## end module%6809B69F0097.epilog


#endif
