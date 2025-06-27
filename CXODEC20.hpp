//## begin module%1.5%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.5%.codegen_version

//## begin module%4061FE8B000F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%4061FE8B000F.cm

//## begin module%4061FE8B000F.cp preserve=no
//	Copyright (c) 1998 - 2004
//	eFunds Corporation
//## end module%4061FE8B000F.cp

//## Module: CXOSEC20%4061FE8B000F; Package specification
//## Subsystem: ECDLL%394E1F94006B
//## Source file: C:\Devel\Dn\Server\Library\Ecdll\CXODEC20.hpp

#ifndef CXOSEC20_h
#define CXOSEC20_h 1

//## begin module%4061FE8B000F.additionalIncludes preserve=no
//## end module%4061FE8B000F.additionalIncludes

//## begin module%4061FE8B000F.includes preserve=yes
// $Date:   Jun 17 2004 08:32:50  $ $Author:   D02405  $ $Revision:   1.3  $
//## end module%4061FE8B000F.includes

#ifndef CXOSBC02_h
#include "CXODBC02.hpp"
#endif
#ifndef CXOSES46_h
#include "CXODES46.hpp"
#endif

//## Modelname: Connex Library::Reusable_CAT%3453F15C01AA
namespace reusable {
class Query;
} // namespace reusable

//## Modelname: Connex Library::Database_CAT%3451F34D0218
namespace database {
class DatabaseFactory;
} // namespace database

namespace reusable {
class SelectStatement;
class Row;
} // namespace reusable

//## Modelname: Connex Library::Timer_CAT%3451F2410231
namespace timer {
class Date;
} // namespace timer

//## Modelname: Connex Library::Monitor_CAT%3451FA660166
namespace monitor {
class UseCase;
} // namespace monitor

//## Modelname: Connex Library::Segment_CAT%3471F0BE0219
namespace segment {
class InformationSegment;
class PrimaryKeySegment;

} // namespace segment

//## begin module%4061FE8B000F.declarations preserve=no
//## end module%4061FE8B000F.declarations

//## begin module%4061FE8B000F.additionalDeclarations preserve=yes
//## end module%4061FE8B000F.additionalDeclarations


//## Modelname: Transaction Research and Adjustments::EMSCommand_CAT%394E266C015B
namespace emscommand {
//## begin emscommand%394E266C015B.initialDeclarations preserve=yes
//## end emscommand%394E266C015B.initialDeclarations

//## begin emscommand::CaseHighlightCommand%4061FE4102FD.preface preserve=yes
//## end emscommand::CaseHighlightCommand%4061FE4102FD.preface

//## Class: CaseHighlightCommand%4061FE4102FD
//## Category: Transaction Research and Adjustments::EMSCommand_CAT%394E266C015B
//## Subsystem: ECDLL%394E1F94006B
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%4061FF63006D;reusable::Query { -> F}
//## Uses: <unnamed>%4061FF7901D4;database::DatabaseFactory { -> F}
//## Uses: <unnamed>%4061FF7B01C5;reusable::SelectStatement { -> F}
//## Uses: <unnamed>%4061FFBD0222;monitor::UseCase { -> F}
//## Uses: <unnamed>%4061FFBF038A;reusable::Row { -> F}
//## Uses: <unnamed>%40630383001F;segment::InformationSegment { -> F}
//## Uses: <unnamed>%406304300280;timer::Date { -> F}

class DllExport CaseHighlightCommand : public command::ClientListCommand  //## Inherits: <unnamed>%4061FE5E00CB
{
  //## begin emscommand::CaseHighlightCommand%4061FE4102FD.initialDeclarations preserve=yes
  //## end emscommand::CaseHighlightCommand%4061FE4102FD.initialDeclarations

  public:
    //## Constructors (generated)
      CaseHighlightCommand();

    //## Constructors (specified)
      //## Operation: CaseHighlightCommand%4063032A001F
      CaseHighlightCommand (Handler* pSuccessor);

    //## Destructor (generated)
      virtual ~CaseHighlightCommand();


    //## Other Operations (specified)
      //## Operation: update%4061FF21031C
      //	Callback function that is invoked by a subject when its
      //	state changes.
      virtual void update (Subject* pSubject);

    // Additional Public Declarations
      //## begin emscommand::CaseHighlightCommand%4061FE4102FD.public preserve=yes
      //## end emscommand::CaseHighlightCommand%4061FE4102FD.public
  protected:

    //## Other Operations (specified)
      //## Operation: retrieve%4061FF1F003E
      virtual bool retrieve ();

    // Additional Protected Declarations
      //## begin emscommand::CaseHighlightCommand%4061FE4102FD.protected preserve=yes
      //## end emscommand::CaseHighlightCommand%4061FE4102FD.protected

  private:
    // Additional Private Declarations
      //## begin emscommand::CaseHighlightCommand%4061FE4102FD.private preserve=yes
      //## end emscommand::CaseHighlightCommand%4061FE4102FD.private

  private: //## implementation
    // Data Members for Class Attributes

      //## Attribute: Buffer%4062F76B003E
      //## begin emscommand::CaseHighlightCommand::Buffer%4062F76B003E.attr preserve=no  private: char* {U} 
      char* m_pszBuffer;
      //## end emscommand::CaseHighlightCommand::Buffer%4062F76B003E.attr

    // Data Members for Associations

      //## Association: Transaction Research and Adjustments::EMSCommand_CAT::<unnamed>%4062FF6D0213
      //## Role: CaseHighlightCommand::<m_hCaseHighlightSegment>%4062FF6E02EE
      //## begin emscommand::CaseHighlightCommand::<m_hCaseHighlightSegment>%4062FF6E02EE.role preserve=no  public: emssegment::CaseHighlightSegment { -> VHgN}
      emssegment::CaseHighlightSegment m_hCaseHighlightSegment;
      //## end emscommand::CaseHighlightCommand::<m_hCaseHighlightSegment>%4062FF6E02EE.role

      //## Association: Transaction Research and Adjustments::EMSCommand_CAT::<unnamed>%406303E80157
      //## Role: CaseHighlightCommand::<m_pPrimaryKeySegment>%406303E8036B
      //## begin emscommand::CaseHighlightCommand::<m_pPrimaryKeySegment>%406303E8036B.role preserve=no  public: segment::PrimaryKeySegment { -> RFHgN}
      segment::PrimaryKeySegment *m_pPrimaryKeySegment;
      //## end emscommand::CaseHighlightCommand::<m_pPrimaryKeySegment>%406303E8036B.role

    // Additional Implementation Declarations
      //## begin emscommand::CaseHighlightCommand%4061FE4102FD.implementation preserve=yes
  public:
      static void addPredicate (Query& hQuery,const char* pszSTATUS);
      //## end emscommand::CaseHighlightCommand%4061FE4102FD.implementation

};

//## begin emscommand::CaseHighlightCommand%4061FE4102FD.postscript preserve=yes
//## end emscommand::CaseHighlightCommand%4061FE4102FD.postscript

} // namespace emscommand

//## begin module%4061FE8B000F.epilog preserve=yes
using namespace emscommand;
//## end module%4061FE8B000F.epilog


#endif
