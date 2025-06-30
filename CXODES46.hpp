//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%4061FD7F01C5.cm preserve=no
//	$Date:   Aug 16 2017 08:51:38  $ $Author:   e3018367  $
//	$Revision:   1.5  $
//## end module%4061FD7F01C5.cm

//## begin module%4061FD7F01C5.cp preserve=no
//	Copyright (c) 1997 - 2012
//	FIS
//## end module%4061FD7F01C5.cp

//## Module: CXOSES46%4061FD7F01C5; Package specification
//## Subsystem: ESDLL%394E1FA20238
//## Source file: C:\Devel\Dn\Server\Library\Esdll\CXODES46.hpp

#ifndef CXOSES46_h
#define CXOSES46_h 1

//## begin module%4061FD7F01C5.additionalIncludes preserve=no
//## end module%4061FD7F01C5.additionalIncludes

//## begin module%4061FD7F01C5.includes preserve=yes
// $Date:   Aug 16 2017 08:51:38  $ $Author:   e3018367  $ $Revision:   1.5  $
//## end module%4061FD7F01C5.includes

#ifndef CXOSBS02_h
#include "CXODBS02.hpp"
#endif

//## Modelname: Connex Library::Reusable_CAT%3453F15C01AA
namespace reusable {
class Query;
} // namespace reusable

//## Modelname: Connex Library::Timer_CAT%3451F2410231
namespace timer {
class Date;

} // namespace timer

//## begin module%4061FD7F01C5.declarations preserve=no
//## end module%4061FD7F01C5.declarations

//## begin module%4061FD7F01C5.additionalDeclarations preserve=yes
//## end module%4061FD7F01C5.additionalDeclarations


//## Modelname: Transaction Research and Adjustments::EMSSegment_CAT%394E27A9030F
namespace emssegment {
//## begin emssegment%394E27A9030F.initialDeclarations preserve=yes
//## end emssegment%394E27A9030F.initialDeclarations

//## begin emssegment::CaseHighlightSegment%4061FD080196.preface preserve=yes
//## end emssegment::CaseHighlightSegment%4061FD080196.preface

//## Class: CaseHighlightSegment%4061FD080196
//## Category: Transaction Research and Adjustments::EMSSegment_CAT%394E27A9030F
//## Subsystem: ESDLL%394E1FA20238
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%4062EBD002CE;reusable::Query { -> F}
//## Uses: <unnamed>%59943FF601FD;timer::Date { -> F}

class DllExport CaseHighlightSegment : public segment::PersistentSegment  //## Inherits: <unnamed>%40CDD6D503A9
{
  //## begin emssegment::CaseHighlightSegment%4061FD080196.initialDeclarations preserve=yes
  //## end emssegment::CaseHighlightSegment%4061FD080196.initialDeclarations

  public:
    //## Constructors (generated)
      CaseHighlightSegment();

    //## Destructor (generated)
      virtual ~CaseHighlightSegment();


    //## Other Operations (specified)
      //## Operation: bind%4062007F0271
	  void bind(reusable::Query& hQuery, const char* pszSide, const char* pszSTATUS);

      //## Operation: fields%406200DB002E
      virtual struct  Fields* fields () const;

      //## Operation: reset%40CDD68B031C
      virtual void reset ();

      //## Operation: resetCount%4DEF053F03B7
      void resetCount ();

      //## Operation: saveCount%406204B00251
      void saveCount ();

      //## Operation: size%406300DE0261
      int size ();

      //## Operation: addPredicate%59913DD602B1
      void addPredicate (reusable::Query& hQuery, const char* pszSTATUS);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: Institution%40630716035B
      void setInstitution (const string& value)
      {
        //## begin emssegment::CaseHighlightSegment::setInstitution%40630716035B.set preserve=no
        m_strInstitution = value;
        //## end emssegment::CaseHighlightSegment::setInstitution%40630716035B.set
      }


      //## Attribute: NET_ID_EMS%406200120399
      const string* getNET_ID_EMS () const
      {
        //## begin emssegment::CaseHighlightSegment::getNET_ID_EMS%406200120399.get preserve=no
        return m_strNET_ID_EMS;
        //## end emssegment::CaseHighlightSegment::getNET_ID_EMS%406200120399.get
      }


      //## Attribute: Side%406200AB006D
      const string* getSide () const
      {
        //## begin emssegment::CaseHighlightSegment::getSide%406200AB006D.get preserve=no
        return m_strSide;
        //## end emssegment::CaseHighlightSegment::getSide%406200AB006D.get
      }


    // Additional Public Declarations
      //## begin emssegment::CaseHighlightSegment%4061FD080196.public preserve=yes
      //## end emssegment::CaseHighlightSegment%4061FD080196.public

  protected:
    // Additional Protected Declarations
      //## begin emssegment::CaseHighlightSegment%4061FD080196.protected preserve=yes
      //## end emssegment::CaseHighlightSegment%4061FD080196.protected

  private:
    // Additional Private Declarations
      //## begin emssegment::CaseHighlightSegment%4061FD080196.private preserve=yes
      //## end emssegment::CaseHighlightSegment%4061FD080196.private

  private: //## implementation
    // Data Members for Class Attributes

      //## Attribute: Count%40620042004E
      //## begin emssegment::CaseHighlightSegment::Count%40620042004E.attr preserve=no  public: int[4] {V} 
      int m_lCount[4];
      //## end emssegment::CaseHighlightSegment::Count%40620042004E.attr

      //## begin emssegment::CaseHighlightSegment::Institution%40630716035B.attr preserve=no  public: string {V} 
      string m_strInstitution;
      //## end emssegment::CaseHighlightSegment::Institution%40630716035B.attr

      //## begin emssegment::CaseHighlightSegment::NET_ID_EMS%406200120399.attr preserve=no  public: string[2] {V} 
      string m_strNET_ID_EMS[2];
      //## end emssegment::CaseHighlightSegment::NET_ID_EMS%406200120399.attr

      //## begin emssegment::CaseHighlightSegment::Side%406200AB006D.attr preserve=no  public: string[2] {V} 
      string m_strSide[2];
      //## end emssegment::CaseHighlightSegment::Side%406200AB006D.attr

      //## Attribute: STATUS%406200AB0157
      //## begin emssegment::CaseHighlightSegment::STATUS%406200AB0157.attr preserve=no  public: string {V} 
      string m_strSTATUS;
      //## end emssegment::CaseHighlightSegment::STATUS%406200AB0157.attr

    // Additional Implementation Declarations
      //## begin emssegment::CaseHighlightSegment%4061FD080196.implementation preserve=yes
      //## end emssegment::CaseHighlightSegment%4061FD080196.implementation

};

//## begin emssegment::CaseHighlightSegment%4061FD080196.postscript preserve=yes
//## end emssegment::CaseHighlightSegment%4061FD080196.postscript

} // namespace emssegment

//## begin module%4061FD7F01C5.epilog preserve=yes
using namespace emssegment;
//## end module%4061FD7F01C5.epilog


#endif
