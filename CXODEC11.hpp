//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%3E79DEDF03C8.cm preserve=no
//	$Date:   Dec 05 2017 14:25:48  $ $Author:   e1094689  $
//	$Revision:   1.6  $
//## end module%3E79DEDF03C8.cm

//## begin module%3E79DEDF03C8.cp preserve=no
//	Copyright (c) 1997 - 2012
//	FIS
//## end module%3E79DEDF03C8.cp

//## Module: CXOSEC11%3E79DEDF03C8; Package specification
//## Subsystem: ECDLL%394E1F94006B
//## Source file: C:\Devel.V02.8B.R001\Windows\Build\Dn\Server\Library\Ecdll\CXODEC11.hpp

#ifndef CXOSEC11_h
#define CXOSEC11_h 1

//## begin module%3E79DEDF03C8.additionalIncludes preserve=no
//## end module%3E79DEDF03C8.additionalIncludes

//## begin module%3E79DEDF03C8.includes preserve=yes
#define STS_CARDHOLDER_NOT_FOUND 89
#define WORK_IN_PROGRESS 90

#include "CXODBS09.hpp"
//## end module%3E79DEDF03C8.includes

#ifndef CXOSBC01_h
#include "CXODBC01.hpp"
#endif

//## Modelname: Connex Library::Monitor_CAT%3451FA660166
namespace monitor {
class UseCase;
} // namespace monitor

//## Modelname: Connex Library::Segment_CAT%3471F0BE0219
namespace segment {
class PersistentSegment;
class InformationSegment;
class PrimaryKeySegment;

} // namespace segment

//## begin module%3E79DEDF03C8.declarations preserve=no
//## end module%3E79DEDF03C8.declarations

//## begin module%3E79DEDF03C8.additionalDeclarations preserve=yes
//## end module%3E79DEDF03C8.additionalDeclarations


//## Modelname: Transaction Research and Adjustments::EMSCommand_CAT%394E266C015B
namespace emscommand {
//## begin emscommand%394E266C015B.initialDeclarations preserve=yes
//## end emscommand%394E266C015B.initialDeclarations

//## begin emscommand::CaseCardholderInfoCommand%3E79DB0F0128.preface preserve=yes
//## end emscommand::CaseCardholderInfoCommand%3E79DB0F0128.preface

//## Class: CaseCardholderInfoCommand%3E79DB0F0128
//	EMRCHDR - Retrieve CardholderInformation only.
//## Category: Transaction Research and Adjustments::EMSCommand_CAT%394E266C015B
//## Subsystem: ECDLL%394E1F94006B
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%3E79E32F030D;segment::ResponseTimeSegment { -> F}
//## Uses: <unnamed>%3E79E331029F;repositorysegment::CardholderInformationSegment { -> F}
//## Uses: <unnamed>%3E79E3A9034B;segment::CommonHeaderSegment { -> F}
//## Uses: <unnamed>%3E7F0CBC01A5;monitor::UseCase { -> F}
//## Uses: <unnamed>%3E7F0FA8036B;IF::Message { -> F}
//## Uses: <unnamed>%3E7F0FAB0242;reusable::Query { -> F}
//## Uses: <unnamed>%3E7F1024007D;database::DatabaseFactory { -> F}
//## Uses: <unnamed>%3E7F10B202FD;reusable::SelectStatement { -> F}
//## Uses: <unnamed>%3E7F18D7005D;segment::PrimaryKeySegment { -> F}

class DllExport CaseCardholderInfoCommand : public command::ClientCommand  //## Inherits: <unnamed>%3E79DDD0008C
{
  //## begin emscommand::CaseCardholderInfoCommand%3E79DB0F0128.initialDeclarations preserve=yes
  //## end emscommand::CaseCardholderInfoCommand%3E79DB0F0128.initialDeclarations

  public:
    //## Constructors (generated)
      CaseCardholderInfoCommand();

    //## Constructors (specified)
      //## Operation: CaseCardholderInfoCommand%3E91BC37029F
      CaseCardholderInfoCommand (Handler* pSuccessor);

    //## Destructor (generated)
      virtual ~CaseCardholderInfoCommand();


    //## Other Operations (specified)
      //## Operation: deleteObsolete%5A05AEAD017D
      void deleteObsolete ();

      //## Operation: execute%3E79E22603D8
      //	Perform the functions of this command.
      virtual bool execute ();

      //## Operation: reply%49F61622002E
      virtual int reply ();

      //## Operation: search%49F60C18005D
      virtual int search ();

    // Additional Public Declarations
      //## begin emscommand::CaseCardholderInfoCommand%3E79DB0F0128.public preserve=yes
      //## end emscommand::CaseCardholderInfoCommand%3E79DB0F0128.public

  protected:
    // Data Members for Associations

      //## Association: Transaction Research and Adjustments::EMSCommand_CAT::<unnamed>%3E7F19A503A9
      //## Role: CaseCardholderInfoCommand::<m_pPrimaryKeySegment>%3E7F19A60280
      //## begin emscommand::CaseCardholderInfoCommand::<m_pPrimaryKeySegment>%3E7F19A60280.role preserve=no  public: segment::PrimaryKeySegment { -> RFHgN}
      segment::PrimaryKeySegment *m_pPrimaryKeySegment;
      //## end emscommand::CaseCardholderInfoCommand::<m_pPrimaryKeySegment>%3E7F19A60280.role

      //## Association: Transaction Research and Adjustments::EMSCommand_CAT::<unnamed>%4A368CD9038A
      //## Role: CaseCardholderInfoCommand::<m_hInformationSegment>%4A368CDA033C
      //## begin emscommand::CaseCardholderInfoCommand::<m_hInformationSegment>%4A368CDA033C.role preserve=no  public: segment::InformationSegment { -> VFHgN}
      segment::InformationSegment m_hInformationSegment;
      //## end emscommand::CaseCardholderInfoCommand::<m_hInformationSegment>%4A368CDA033C.role

    // Additional Protected Declarations
      //## begin emscommand::CaseCardholderInfoCommand%3E79DB0F0128.protected preserve=yes
      //## end emscommand::CaseCardholderInfoCommand%3E79DB0F0128.protected

  private:
    // Additional Private Declarations
      //## begin emscommand::CaseCardholderInfoCommand%3E79DB0F0128.private preserve=yes
      //## end emscommand::CaseCardholderInfoCommand%3E79DB0F0128.private

  private: //## implementation
    // Data Members for Associations

      //## Association: Transaction Research and Adjustments::EMSCommand_CAT::<unnamed>%3E7F20F601F4
      //## Role: CaseCardholderInfoCommand::<m_pPersistentSegment>%3E7F20F700AB
      //## begin emscommand::CaseCardholderInfoCommand::<m_pPersistentSegment>%3E7F20F700AB.role preserve=no  public: segment::PersistentSegment { -> RFHgN}
      segment::PersistentSegment *m_pPersistentSegment;
      //## end emscommand::CaseCardholderInfoCommand::<m_pPersistentSegment>%3E7F20F700AB.role

    // Additional Implementation Declarations
      //## begin emscommand::CaseCardholderInfoCommand%3E79DB0F0128.implementation preserve=yes
      //## end emscommand::CaseCardholderInfoCommand%3E79DB0F0128.implementation

};

//## begin emscommand::CaseCardholderInfoCommand%3E79DB0F0128.postscript preserve=yes
//## end emscommand::CaseCardholderInfoCommand%3E79DB0F0128.postscript

} // namespace emscommand

//## begin module%3E79DEDF03C8.epilog preserve=yes
using namespace emscommand;
//## end module%3E79DEDF03C8.epilog


#endif
