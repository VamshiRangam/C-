//## begin module%1.5%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.5%.codegen_version

//## begin module%4999B7790242.cm preserve=no
//	$Date:   Mar 16 2009 17:26:26  $ $Author:   D93482  $
//	$Revision:   1.0  $
//## end module%4999B7790242.cm

//## begin module%4999B7790242.cp preserve=no
//	Copyright (c) 1998 - 2007
//	EFD | eFunds Corporation
//## end module%4999B7790242.cp

//## Module: CXOSES62%4999B7790242; Package body
//## Subsystem: ESDLL%394E1FA20238
//## Source file: C:\Devel\Dn\Server\Library\Esdll\CXOSES62.cpp

//## begin module%4999B7790242.additionalIncludes preserve=no
//## end module%4999B7790242.additionalIncludes

//## begin module%4999B7790242.includes preserve=yes
//## end module%4999B7790242.includes

#ifndef CXOSRU11_h
#include "CXODRU11.hpp"
#endif
#ifndef CXOSES62_h
#include "CXODES62.hpp"
#endif


//## begin module%4999B7790242.declarations preserve=no
//## end module%4999B7790242.declarations

//## begin module%4999B7790242.additionalDeclarations preserve=yes
struct segRelatedCaseSegment
{
   char sSegmentID[4];
   char sSegmentVersion[4];
   char sLengthOfSegment[8];
   char sCASE_NO[14];
   char sCASE_TYPE_IND[2];
   char sStateDescription[50];
   char sCUR_TRAN[3];
   char sAMT_TRAN[18];
   char sCUR_ADJUSTMENT[3];
   char sAMT_ADJUSTMENT[18];              
};
struct segRelatedCaseSegment* pRelatedCaseSegment = 0;
#define FIELDS 7
Fields RelatedCaseSegment_Fields[FIELDS + 1] = 
{
   "a         ","CASE_NO",offsetof(segRelatedCaseSegment,sCASE_NO),sizeof(pRelatedCaseSegment->sCASE_NO),   
   "a         ","CASE_TYPE_IND",offsetof(segRelatedCaseSegment,sCASE_TYPE_IND),sizeof(pRelatedCaseSegment->sCASE_TYPE_IND),   
   "a         ","StateDescription",offsetof(segRelatedCaseSegment,sStateDescription),sizeof(pRelatedCaseSegment->sStateDescription),   
   "a         ","CUR_TRAN",offsetof(segRelatedCaseSegment,sCUR_TRAN),sizeof(pRelatedCaseSegment->sCUR_TRAN),   
   "d%-18.0f  ","AMT_TRAN",offsetof(segRelatedCaseSegment,sAMT_TRAN),sizeof(pRelatedCaseSegment->sAMT_TRAN),   
   "a         ","CUR_ADJUSTMENT",offsetof(segRelatedCaseSegment,sCUR_ADJUSTMENT),sizeof(pRelatedCaseSegment->sCUR_ADJUSTMENT),   
   "d%-18.0f  ","AMT_ADJUSTMENT",offsetof(segRelatedCaseSegment,sAMT_ADJUSTMENT),sizeof(pRelatedCaseSegment->sAMT_ADJUSTMENT),   
   "~","~",0,sizeof(segRelatedCaseSegment),
};
//## end module%4999B7790242.additionalDeclarations


//## Modelname: Transaction Research and Adjustments::EMSSegment_CAT%394E27A9030F
namespace emssegment {
//## begin emssegment%394E27A9030F.initialDeclarations preserve=yes
//## end emssegment%394E27A9030F.initialDeclarations

// Class emssegment::RelatedCaseSegment 

RelatedCaseSegment::RelatedCaseSegment()
  //## begin RelatedCaseSegment::RelatedCaseSegment%4999B6B7033C_const.hasinit preserve=no
      : m_dAMT_TRAN(0),
        m_dAMT_ADJUSTMENT(0)
  //## end RelatedCaseSegment::RelatedCaseSegment%4999B6B7033C_const.hasinit
  //## begin RelatedCaseSegment::RelatedCaseSegment%4999B6B7033C_const.initialization preserve=yes
   , PersistentSegment("S294")
  //## end RelatedCaseSegment::RelatedCaseSegment%4999B6B7033C_const.initialization
{
  //## begin emssegment::RelatedCaseSegment::RelatedCaseSegment%4999B6B7033C_const.body preserve=yes
   memcpy(m_sID,"ES62",4);
   m_lNumberOfFields = FIELDS;
   m_pField = new void*[FIELDS];
   m_pField[0] = &m_strCASE_NO;
   m_pField[1] = &m_strCASE_TYPE_IND;
   m_pField[2] = &m_strStateDescription;
   m_pField[3] = &m_strCUR_TRAN;
   m_pField[4] = &m_dAMT_TRAN;
   m_pField[5] = &m_strCUR_ADJUSTMENT;
   m_pField[6] = &m_dAMT_ADJUSTMENT;
  //## end emssegment::RelatedCaseSegment::RelatedCaseSegment%4999B6B7033C_const.body
}


RelatedCaseSegment::~RelatedCaseSegment()
{
  //## begin emssegment::RelatedCaseSegment::~RelatedCaseSegment%4999B6B7033C_dest.body preserve=yes
   delete [] m_pField;
  //## end emssegment::RelatedCaseSegment::~RelatedCaseSegment%4999B6B7033C_dest.body
}



//## Other Operations (implementation)
void RelatedCaseSegment::bind (reusable::Query& hQuery)
{
  //## begin emssegment::RelatedCaseSegment::bind%4999B872001F.body preserve=yes
   hQuery.join("EMS_CASE","INNER","EMS_TRANSITION","STATE_TSTAMP","TSTAMP_CREATED");       
   hQuery.join("EMS_CASE","INNER","EMS_TRANSITION","CASE_ID");
   hQuery.join("EMS_TRANSITION","INNER","EMS_PHASE","PHASE_TSTAMP","TSTAMP_CREATED");
   hQuery.join("EMS_TRANSITION","INNER","EMS_PHASE","CASE_ID");
   hQuery.bind("EMS_CASE","CASE_NO",Column::STRING,&m_strCASE_NO);
   hQuery.bind("EMS_CASE","CASE_TYPE_IND",Column::STRING,&m_strCASE_TYPE_IND);
   hQuery.bind("EMS_CASE","CUR_TRAN",Column::STRING,&m_strCUR_TRAN);
   hQuery.bind("EMS_CASE","AMT_TRAN",Column::DOUBLE,&m_dAMT_TRAN);
   hQuery.bind("EMS_CASE","REQUEST_TYPE",Column::STRING,&m_strREQUEST_TYPE);
   hQuery.bind("EMS_CASE","STATUS",Column::STRING,&m_strSTATUS);
   hQuery.bind("EMS_PHASE","CUR_ADJUSTMENT",Column::STRING,&m_strCUR_ADJUSTMENT);
   hQuery.bind("EMS_PHASE","AMT_ADJUSTMENT",Column::DOUBLE,&m_dAMT_ADJUSTMENT);
  //## end emssegment::RelatedCaseSegment::bind%4999B872001F.body
}

struct  Fields* RelatedCaseSegment::fields () const
{
  //## begin emssegment::RelatedCaseSegment::fields%4999B87B0109.body preserve=yes
   return &RelatedCaseSegment_Fields[0];
  //## end emssegment::RelatedCaseSegment::fields%4999B87B0109.body
}

int RelatedCaseSegment::size ()
{
  //## begin emssegment::RelatedCaseSegment::size%4999CDF301B5.body preserve=yes
   return sizeof(segRelatedCaseSegment);
  //## end emssegment::RelatedCaseSegment::size%4999CDF301B5.body
}

// Additional Declarations
  //## begin emssegment::RelatedCaseSegment%4999B6B7033C.declarations preserve=yes
  //## end emssegment::RelatedCaseSegment%4999B6B7033C.declarations

} // namespace emssegment

//## begin module%4999B7790242.epilog preserve=yes
//## end module%4999B7790242.epilog
