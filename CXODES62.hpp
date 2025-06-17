//## begin module%1.5%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.5%.codegen_version

//## begin module%4999B777035B.cm preserve=no
//	$Date:   Mar 16 2009 17:26:22  $ $Author:   D93482  $
//	$Revision:   1.0  $
//## end module%4999B777035B.cm

//## begin module%4999B777035B.cp preserve=no
//	Copyright (c) 1998 - 2007
//	EFD | eFunds Corporation
//## end module%4999B777035B.cp

//## Module: CXOSES62%4999B777035B; Package specification
//## Subsystem: ESDLL%394E1FA20238
//## Source file: C:\Devel\Dn\Server\Library\Esdll\CXODES62.hpp

#ifndef CXOSES62_h
#define CXOSES62_h 1

//## begin module%4999B777035B.additionalIncludes preserve=no
//## end module%4999B777035B.additionalIncludes

//## begin module%4999B777035B.includes preserve=yes
//## end module%4999B777035B.includes

#ifndef CXOSBS02_h
#include "CXODBS02.hpp"
#endif

//## Modelname: Connex Library::Reusable_CAT%3453F15C01AA
namespace reusable {
class Query;

} // namespace reusable

//## begin module%4999B777035B.declarations preserve=no
//## end module%4999B777035B.declarations

//## begin module%4999B777035B.additionalDeclarations preserve=yes
//## end module%4999B777035B.additionalDeclarations


//## Modelname: Transaction Research and Adjustments::EMSSegment_CAT%394E27A9030F
namespace emssegment {
//## begin emssegment%394E27A9030F.initialDeclarations preserve=yes
//## end emssegment%394E27A9030F.initialDeclarations

//## begin emssegment::RelatedCaseSegment%4999B6B7033C.preface preserve=yes
//## end emssegment::RelatedCaseSegment%4999B6B7033C.preface

//## Class: RelatedCaseSegment%4999B6B7033C
//## Category: Transaction Research and Adjustments::EMSSegment_CAT%394E27A9030F
//## Subsystem: ESDLL%394E1FA20238
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%4999BF2500BB;reusable::Query { -> F}

class DllExport RelatedCaseSegment : public segment::PersistentSegment  //## Inherits: <unnamed>%4999B73200AB
{
  //## begin emssegment::RelatedCaseSegment%4999B6B7033C.initialDeclarations preserve=yes
  //## end emssegment::RelatedCaseSegment%4999B6B7033C.initialDeclarations

  public:
    //## Constructors (generated)
      RelatedCaseSegment();

    //## Destructor (generated)
      virtual ~RelatedCaseSegment();


    //## Other Operations (specified)
      //## Operation: bind%4999B872001F
      void bind (reusable::Query& hQuery);

      //## Operation: fields%4999B87B0109
      virtual struct  Fields* fields () const;

      //## Operation: size%4999CDF301B5
      int size ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: CASE_NO%4999BB69003E
      const string& getCASE_NO () const
      {
        //## begin emssegment::RelatedCaseSegment::getCASE_NO%4999BB69003E.get preserve=no
        return m_strCASE_NO;
        //## end emssegment::RelatedCaseSegment::getCASE_NO%4999BB69003E.get
      }

      void setCASE_NO (const string& value)
      {
        //## begin emssegment::RelatedCaseSegment::setCASE_NO%4999BB69003E.set preserve=no
        m_strCASE_NO = value;
        //## end emssegment::RelatedCaseSegment::setCASE_NO%4999BB69003E.set
      }


      //## Attribute: CASE_TYPE_IND%4999BB8E01B5
      const string& getCASE_TYPE_IND () const
      {
        //## begin emssegment::RelatedCaseSegment::getCASE_TYPE_IND%4999BB8E01B5.get preserve=no
        return m_strCASE_TYPE_IND;
        //## end emssegment::RelatedCaseSegment::getCASE_TYPE_IND%4999BB8E01B5.get
      }

      void setCASE_TYPE_IND (const string& value)
      {
        //## begin emssegment::RelatedCaseSegment::setCASE_TYPE_IND%4999BB8E01B5.set preserve=no
        m_strCASE_TYPE_IND = value;
        //## end emssegment::RelatedCaseSegment::setCASE_TYPE_IND%4999BB8E01B5.set
      }


      //## Attribute: StateDescription%4999BBA30128
      const string& getStateDescription () const
      {
        //## begin emssegment::RelatedCaseSegment::getStateDescription%4999BBA30128.get preserve=no
        return m_strStateDescription;
        //## end emssegment::RelatedCaseSegment::getStateDescription%4999BBA30128.get
      }

      void setStateDescription (const string& value)
      {
        //## begin emssegment::RelatedCaseSegment::setStateDescription%4999BBA30128.set preserve=no
        m_strStateDescription = value;
        //## end emssegment::RelatedCaseSegment::setStateDescription%4999BBA30128.set
      }


      //## Attribute: AMT_TRAN%4999BBB6005D
      const double& getAMT_TRAN () const
      {
        //## begin emssegment::RelatedCaseSegment::getAMT_TRAN%4999BBB6005D.get preserve=no
        return m_dAMT_TRAN;
        //## end emssegment::RelatedCaseSegment::getAMT_TRAN%4999BBB6005D.get
      }

      void setAMT_TRAN (const double& value)
      {
        //## begin emssegment::RelatedCaseSegment::setAMT_TRAN%4999BBB6005D.set preserve=no
        m_dAMT_TRAN = value;
        //## end emssegment::RelatedCaseSegment::setAMT_TRAN%4999BBB6005D.set
      }


      //## Attribute: AMT_ADJUSTMENT%4999BBF0004E
      const double& getAMT_ADJUSTMENT () const
      {
        //## begin emssegment::RelatedCaseSegment::getAMT_ADJUSTMENT%4999BBF0004E.get preserve=no
        return m_dAMT_ADJUSTMENT;
        //## end emssegment::RelatedCaseSegment::getAMT_ADJUSTMENT%4999BBF0004E.get
      }

      void setAMT_ADJUSTMENT (const double& value)
      {
        //## begin emssegment::RelatedCaseSegment::setAMT_ADJUSTMENT%4999BBF0004E.set preserve=no
        m_dAMT_ADJUSTMENT = value;
        //## end emssegment::RelatedCaseSegment::setAMT_ADJUSTMENT%4999BBF0004E.set
      }


      //## Attribute: REQUEST_TYPE%4999D6BB0148
      const string& getREQUEST_TYPE () const
      {
        //## begin emssegment::RelatedCaseSegment::getREQUEST_TYPE%4999D6BB0148.get preserve=no
        return m_strREQUEST_TYPE;
        //## end emssegment::RelatedCaseSegment::getREQUEST_TYPE%4999D6BB0148.get
      }

      void setREQUEST_TYPE (const string& value)
      {
        //## begin emssegment::RelatedCaseSegment::setREQUEST_TYPE%4999D6BB0148.set preserve=no
        m_strREQUEST_TYPE = value;
        //## end emssegment::RelatedCaseSegment::setREQUEST_TYPE%4999D6BB0148.set
      }


      //## Attribute: STATUS%4999D6BF009C
      const string& getSTATUS () const
      {
        //## begin emssegment::RelatedCaseSegment::getSTATUS%4999D6BF009C.get preserve=no
        return m_strSTATUS;
        //## end emssegment::RelatedCaseSegment::getSTATUS%4999D6BF009C.get
      }

      void setSTATUS (const string& value)
      {
        //## begin emssegment::RelatedCaseSegment::setSTATUS%4999D6BF009C.set preserve=no
        m_strSTATUS = value;
        //## end emssegment::RelatedCaseSegment::setSTATUS%4999D6BF009C.set
      }


    // Additional Public Declarations
      //## begin emssegment::RelatedCaseSegment%4999B6B7033C.public preserve=yes
      const string& getCUR_TRAN () const
      {
        return m_strCUR_TRAN;
      }
      void setCUR_TRAN (const string& value)
      {
        m_strCUR_TRAN = value;
      }

      const string& getCUR_ADJUSTMENT () const
      {
        return m_strCUR_ADJUSTMENT;
      }
      void setCUR_ADJUSTMENT (const string& value)
      {
        m_strCUR_ADJUSTMENT = value;
      }

      //## end emssegment::RelatedCaseSegment%4999B6B7033C.public

  protected:
    // Additional Protected Declarations
      //## begin emssegment::RelatedCaseSegment%4999B6B7033C.protected preserve=yes
      //## end emssegment::RelatedCaseSegment%4999B6B7033C.protected

  private:
    // Additional Private Declarations
      //## begin emssegment::RelatedCaseSegment%4999B6B7033C.private preserve=yes
      //## end emssegment::RelatedCaseSegment%4999B6B7033C.private

  private: //## implementation
    // Data Members for Class Attributes

      //## begin emssegment::RelatedCaseSegment::CASE_NO%4999BB69003E.attr preserve=no  public: string {U} 
      string m_strCASE_NO;
      //## end emssegment::RelatedCaseSegment::CASE_NO%4999BB69003E.attr

      //## begin emssegment::RelatedCaseSegment::CASE_TYPE_IND%4999BB8E01B5.attr preserve=no  public: string {U} 
      string m_strCASE_TYPE_IND;
      //## end emssegment::RelatedCaseSegment::CASE_TYPE_IND%4999BB8E01B5.attr

      //## begin emssegment::RelatedCaseSegment::StateDescription%4999BBA30128.attr preserve=no  public: string {U} 
      string m_strStateDescription;
      //## end emssegment::RelatedCaseSegment::StateDescription%4999BBA30128.attr

      //## begin emssegment::RelatedCaseSegment::AMT_TRAN%4999BBB6005D.attr preserve=no  public: double {U} 0
      double m_dAMT_TRAN;
      //## end emssegment::RelatedCaseSegment::AMT_TRAN%4999BBB6005D.attr

      //## begin emssegment::RelatedCaseSegment::AMT_ADJUSTMENT%4999BBF0004E.attr preserve=no  public: double {U} 0
      double m_dAMT_ADJUSTMENT;
      //## end emssegment::RelatedCaseSegment::AMT_ADJUSTMENT%4999BBF0004E.attr

      //## begin emssegment::RelatedCaseSegment::REQUEST_TYPE%4999D6BB0148.attr preserve=no  public: string {U} 
      string m_strREQUEST_TYPE;
      //## end emssegment::RelatedCaseSegment::REQUEST_TYPE%4999D6BB0148.attr

      //## begin emssegment::RelatedCaseSegment::STATUS%4999D6BF009C.attr preserve=no  public: string {U} 
      string m_strSTATUS;
      //## end emssegment::RelatedCaseSegment::STATUS%4999D6BF009C.attr

    // Additional Implementation Declarations
      //## begin emssegment::RelatedCaseSegment%4999B6B7033C.implementation preserve=yes
      string m_strCUR_TRAN;
      string m_strCUR_ADJUSTMENT;
      //## end emssegment::RelatedCaseSegment%4999B6B7033C.implementation

};

//## begin emssegment::RelatedCaseSegment%4999B6B7033C.postscript preserve=yes
//## end emssegment::RelatedCaseSegment%4999B6B7033C.postscript

} // namespace emssegment

//## begin module%4999B777035B.epilog preserve=yes
//## end module%4999B777035B.epilog


#endif
