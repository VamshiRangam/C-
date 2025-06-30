//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%4061FD800271.cm preserve=no
//	$Date:   Aug 16 2017 08:52:34  $ $Author:   e3018367  $
//	$Revision:   1.8  $
//## end module%4061FD800271.cm

//## begin module%4061FD800271.cp preserve=no
//	Copyright (c) 1997 - 2012
//	FIS
//## end module%4061FD800271.cp

//## Module: CXOSES46%4061FD800271; Package body
//## Subsystem: ESDLL%394E1FA20238
//## Source file: C:\Devel\Dn\Server\Library\Esdll\CXOSES46.cpp

//## begin module%4061FD800271.additionalIncludes preserve=no
//## end module%4061FD800271.additionalIncludes

//## begin module%4061FD800271.includes preserve=yes
// $Date:   Aug 16 2017 08:52:34  $ $Author:   e3018367  $ $Revision:   1.8  $
//## end module%4061FD800271.includes

#ifndef CXOSRU11_h
#include "CXODRU11.hpp"
#endif
#ifndef CXOSTM06_h
#include "CXODTM06.hpp"
#endif
#ifndef CXOSES46_h
#include "CXODES46.hpp"
#endif


//## begin module%4061FD800271.declarations preserve=no
//## end module%4061FD800271.declarations

//## begin module%4061FD800271.additionalDeclarations preserve=yes
struct segCaseHighlightSegment
{
   char sSegmentID[4];
   char sSegmentVersion[4];
   char sLengthOfSegment[8]; 
   char sInstitution[11];
   char cSide;
   char sNET_ID_EMS[3];
   char sOpen[8];
   char sClosed[8]; 
   char sRejected[8];
   char sReserved[9]; /* 64 bytes */
};
struct segCaseHighlightSegment* pCaseHighlightSegment = 0;
#define FIELDS 6
Fields CaseHighlightSegment_Fields[FIELDS + 1] = 
{
   "a         ","Institution",offsetof(segCaseHighlightSegment,sInstitution),sizeof(pCaseHighlightSegment->sInstitution),   
   "a         ","Side",offsetof(segCaseHighlightSegment,cSide),sizeof(pCaseHighlightSegment->cSide),   
   "a         ","NET_ID_EMS",offsetof(segCaseHighlightSegment,sNET_ID_EMS),sizeof(pCaseHighlightSegment->sNET_ID_EMS),   
   "l%08ld    ","Open",offsetof(segCaseHighlightSegment,sOpen),sizeof(pCaseHighlightSegment->sOpen),   
   "l%08ld    ","Closed",offsetof(segCaseHighlightSegment,sClosed),sizeof(pCaseHighlightSegment->sClosed),   
   "l%08ld    ","Rejected",offsetof(segCaseHighlightSegment,sRejected),sizeof(pCaseHighlightSegment->sRejected),   
   "~","~",0,sizeof(segCaseHighlightSegment),
};
//## end module%4061FD800271.additionalDeclarations


//## Modelname: Transaction Research and Adjustments::EMSSegment_CAT%394E27A9030F
namespace emssegment {
//## begin emssegment%394E27A9030F.initialDeclarations preserve=yes
//## end emssegment%394E27A9030F.initialDeclarations

// Class emssegment::CaseHighlightSegment 

CaseHighlightSegment::CaseHighlightSegment()
  //## begin CaseHighlightSegment::CaseHighlightSegment%4061FD080196_const.hasinit preserve=no
  //## end CaseHighlightSegment::CaseHighlightSegment%4061FD080196_const.hasinit
  //## begin CaseHighlightSegment::CaseHighlightSegment%4061FD080196_const.initialization preserve=yes
   : PersistentSegment("S283")
  //## end CaseHighlightSegment::CaseHighlightSegment%4061FD080196_const.initialization
{
  //## begin emssegment::CaseHighlightSegment::CaseHighlightSegment%4061FD080196_const.body preserve=yes
   memcpy(m_sID,"ES46",4);
   m_lCount[0] = 0;
   m_lCount[1] = 0;
   m_lCount[2] = 0;
   m_lCount[3] = 0;
   m_lNumberOfFields = FIELDS;
   m_pField = new void*[FIELDS];
   m_pField[0] = &m_strInstitution;
   m_pField[1] = &m_strSide[1];
   m_pField[2] = &m_strNET_ID_EMS[1];
   m_pField[3] = &m_lCount[1];
   m_pField[4] = &m_lCount[2];
   m_pField[5] = &m_lCount[3];
  //## end emssegment::CaseHighlightSegment::CaseHighlightSegment%4061FD080196_const.body
}


CaseHighlightSegment::~CaseHighlightSegment()
{
  //## begin emssegment::CaseHighlightSegment::~CaseHighlightSegment%4061FD080196_dest.body preserve=yes
   delete [] m_pField;
  //## end emssegment::CaseHighlightSegment::~CaseHighlightSegment%4061FD080196_dest.body
}



//## Other Operations (implementation)
void CaseHighlightSegment::bind(reusable::Query& hQuery, const char* pszSide, const char* pszSTATUS)
{
  //## begin emssegment::CaseHighlightSegment::bind%4062007F0271.body preserve=yes
   hQuery.bind("",pszSide,Column::STRING,&m_strSide[0]);
   hQuery.bind("EMS_CASE","NET_ID_EMS",Column::STRING,&m_strNET_ID_EMS[0]);
   hQuery.bind("",pszSTATUS,Column::STRING,&m_strSTATUS);
   hQuery.bind("EMS_CASE","*",Column::LONG,&m_lCount[0],0,"COUNT");
  //## end emssegment::CaseHighlightSegment::bind%4062007F0271.body
}

struct  Fields* CaseHighlightSegment::fields () const
{
  //## begin emssegment::CaseHighlightSegment::fields%406200DB002E.body preserve=yes
   return &CaseHighlightSegment_Fields[0];
  //## end emssegment::CaseHighlightSegment::fields%406200DB002E.body
}

void CaseHighlightSegment::reset ()
{
  //## begin emssegment::CaseHighlightSegment::reset%40CDD68B031C.body preserve=yes
   m_strNET_ID_EMS[1].erase();
   m_strSide[1].erase();
   PersistentSegment::reset();
  //## end emssegment::CaseHighlightSegment::reset%40CDD68B031C.body
}

void CaseHighlightSegment::resetCount ()
{
  //## begin emssegment::CaseHighlightSegment::resetCount%4DEF053F03B7.body preserve=yes
   for (int i=1;i<4;i++)
      m_lCount[i]=0;
  //## end emssegment::CaseHighlightSegment::resetCount%4DEF053F03B7.body
}

void CaseHighlightSegment::saveCount ()
{
  //## begin emssegment::CaseHighlightSegment::saveCount%406204B00251.body preserve=yes
   m_strSide[1] = m_strSide[0];
   m_strNET_ID_EMS[1] = m_strNET_ID_EMS[0];
   if (m_strSTATUS == "ZOPEN____")
      m_lCount[1] = m_lCount[0];
   else
   if (m_strSTATUS == "ZCLOSED__")
      m_lCount[2] = m_lCount[0];
   else
      m_lCount[3] = m_lCount[0];
  //## end emssegment::CaseHighlightSegment::saveCount%406204B00251.body
}

int CaseHighlightSegment::size ()
{
  //## begin emssegment::CaseHighlightSegment::size%406300DE0261.body preserve=yes
   return sizeof(segCaseHighlightSegment);
  //## end emssegment::CaseHighlightSegment::size%406300DE0261.body
}

void CaseHighlightSegment::addPredicate (reusable::Query& hQuery, const char* pszSTATUS)
{
  //## begin emssegment::CaseHighlightSegment::addPredicate%59913DD602B1.body preserve=yes
	Date hDate(Date::today());
	string strDay(hDate.asString("%A"));
	if (strDay == "Monday")
		hDate -= 3;
	else
	if (strDay == "Sunday")
		hDate -= 2;
	else
		hDate -= 1;
	string strDate(hDate.asString("%Y%m%d00000000"));
	bool bAND = (strcmp(pszSTATUS, "ALL") != 0);
	if (strcmp(pszSTATUS, "ALL") == 0)
		hQuery.getSearchCondition() += "(";
	if (strcmp(pszSTATUS, "OPEN") == 0
		|| strcmp(pszSTATUS, "ALL") == 0)
	{
		hQuery.setBasicPredicate("EMS_CASE", "STATUS", "NOT LIKE", "CL__");
		hQuery.setBasicPredicate("EMS_CASE", "STATUS", "NOT IN",
			"('REJR','REJU','RERU','REVR')");
	}
	if (strcmp(pszSTATUS, "ALL") == 0)
		hQuery.getSearchCondition() += " OR ((";
	if (strcmp(pszSTATUS, "CLOSED") == 0
		|| strcmp(pszSTATUS, "ALL") == 0)
	{
		hQuery.setBasicPredicate("EMS_CASE", "STATUS", "LIKE", "CL__");
	}
	if (strcmp(pszSTATUS, "REJECTED") == 0
		|| strcmp(pszSTATUS, "ALL") == 0)
	{
		hQuery.setBasicPredicate("EMS_CASE", "STATUS", "IN",
			"('REJR','REJU','RERU','REVR')", false, bAND);
	}
	if (strcmp(pszSTATUS, "ALL") == 0)
		hQuery.getSearchCondition() += ")";
	if (strcmp(pszSTATUS, "OPEN") != 0)
		hQuery.setBasicPredicate("EMS_CASE", "TSTAMP_UPDATED", ">", strDate.c_str());
	if (strcmp(pszSTATUS, "ALL") == 0)
		hQuery.getSearchCondition() += "))";
  //## end emssegment::CaseHighlightSegment::addPredicate%59913DD602B1.body
}

// Additional Declarations
  //## begin emssegment::CaseHighlightSegment%4061FD080196.declarations preserve=yes
  //## end emssegment::CaseHighlightSegment%4061FD080196.declarations

} // namespace emssegment

//## begin module%4061FD800271.epilog preserve=yes
//## end module%4061FD800271.epilog
