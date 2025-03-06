//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%6525EE040092.cm preserve=no
//## end module%6525EE040092.cm

//## begin module%6525EE040092.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%6525EE040092.cp

//## Module: CXOSJX11%6525EE040092; Package body
//## Subsystem: JXDLL%645AEC9A0298
//## Source file: C:\Repos\DataNavigatorServer\Windows\Build\Dn\Server\Library\Jxdll\CXOSJX11.cpp

//## begin module%6525EE040092.additionalIncludes preserve=no
//## end module%6525EE040092.additionalIncludes

//## begin module%6525EE040092.includes preserve=yes
#include "CXODES01.hpp"
//## end module%6525EE040092.includes

#ifndef CXOSBS26_h
#include "CXODBS26.hpp"
#endif
#ifndef CXOSMN05_h
#include "CXODMN05.hpp"
#endif
#ifndef CXOSRU12_h
#include "CXODRU12.hpp"
#endif
#ifndef CXOSDB02_h
#include "CXODDB02.hpp"
#endif
#ifndef CXOSES75_h
#include "CXODES75.hpp"
#endif
#ifndef CXOSRU34_h
#include "CXODRU34.hpp"
#endif
#ifndef CXOSJX11_h
#include "CXODJX11.hpp"
#endif


//## begin module%6525EE040092.declarations preserve=no
//## end module%6525EE040092.declarations

//## begin module%6525EE040092.additionalDeclarations preserve=yes
//## end module%6525EE040092.additionalDeclarations


//## Modelname: DataNavigator Foundation::RESTCommand_CAT%645AEC55037E
namespace restcommand {
//## begin restcommand%645AEC55037E.initialDeclarations preserve=yes
//## end restcommand%645AEC55037E.initialDeclarations

// Class restcommand::CasesCommand 

CasesCommand::CasesCommand()
  //## begin CasesCommand::CasesCommand%6525C12F0364_const.hasinit preserve=no
  //## end CasesCommand::CasesCommand%6525C12F0364_const.hasinit
  //## begin CasesCommand::CasesCommand%6525C12F0364_const.initialization preserve=yes
   : RESTCommand("/rest/datanavigator/resolve/cases/v1.0.0","S0003D","@##JLCASE ")
  //## end CasesCommand::CasesCommand%6525C12F0364_const.initialization
{
  //## begin restcommand::CasesCommand::CasesCommand%6525C12F0364_const.body preserve=yes
   memcpy(m_sID,"JX11",4);
  //## end restcommand::CasesCommand::CasesCommand%6525C12F0364_const.body
}

CasesCommand::CasesCommand (reusable::Handler* pSuccessor)
  //## begin restcommand::CasesCommand::CasesCommand%6525C28B021E.hasinit preserve=no
  //## end restcommand::CasesCommand::CasesCommand%6525C28B021E.hasinit
  //## begin restcommand::CasesCommand::CasesCommand%6525C28B021E.initialization preserve=yes
   : RESTCommand("/rest/datanavigator/resolve/cases/v1.0.0","S0003D","@##JLCASE ")
  //## end restcommand::CasesCommand::CasesCommand%6525C28B021E.initialization
{
  //## begin restcommand::CasesCommand::CasesCommand%6525C28B021E.body preserve=yes
   memcpy(m_sID,"JX11",4);
   m_pSuccessor = pSuccessor;
   m_hXMLText.add('C',&m_hGenericSegment);
   m_hXMLText.add('X',segment::SOAPSegment::instance());
   m_pXMLItem = new XMLItem();
   m_hQuery.attach(this);
  //## end restcommand::CasesCommand::CasesCommand%6525C28B021E.body
}


CasesCommand::~CasesCommand()
{
  //## begin restcommand::CasesCommand::~CasesCommand%6525C12F0364_dest.body preserve=yes
  //## end restcommand::CasesCommand::~CasesCommand%6525C12F0364_dest.body
}



//## Other Operations (implementation)
bool CasesCommand::endElement (const string& strTag)
{
  //## begin restcommand::CasesCommand::endElement%6525C26D03C0.body preserve=yes
   string strValue(m_pXMLItem->get("value"));
   if (strTag == "filter")
   {
      if (m_pXMLItem->get("column") == "rows")
         setMaxRows(atoi(strValue.c_str()));
      else
      {
         vector<string> hTag;
         Buffer::parse(m_pXMLItem->get("column"),".",hTag);
         if (hTag.size() == 1)
            hTag.insert(hTag.begin(),"Case");
         if (hTag.size() == 2)
         {
            string strValue(m_pXMLItem->get("value"));
            std::replace(strValue.begin(),strValue.end(),'*','%');
            std::replace(strValue.begin(),strValue.end(),'~',',');
            if (!emssegment::Case::instance()->setBasicPredicate(m_hQuery,hTag[0],hTag[1],m_pXMLItem->get("operator"),strValue))
            {
               string strTxt("Undefined column: ");
               strTxt += hTag[0];
               strTxt.append(".",1);
               strTxt += hTag[1];
               SOAPSegment::instance()->setMsg("JX11.1","Validation error",strTxt);
               SOAPSegment::instance()->setTxt("Invalid request (parse failure)");
               SOAPSegment::instance()->setRtnCde('3');
            }
         }
      }
      m_pXMLItem->resetToken();
   }
   return true;
  //## end restcommand::CasesCommand::endElement%6525C26D03C0.body
}

bool CasesCommand::execute ()
{
  //## begin restcommand::CasesCommand::execute%6525C1EC009E.body preserve=yes
   UseCase hUseCase("CLIENT","## JX11 LIST CASES");
   if (!m_pXMLDocument)
#ifdef MVS
      m_pXMLDocument = new XMLDocument("JCL","RJLCASE",&m_hRow,&m_hXMLText);
#else
      m_pXMLDocument = new XMLDocument("SOURCE","CXORJX11",&m_hRow,&m_hXMLText);
#endif
   m_pXMLDocument->reset();
   m_pXMLItem->reset();
   m_hQuery.reset();
   m_hIndex.erase(m_hIndex.begin(),m_hIndex.end());
   m_hTag.erase(m_hTag.begin(),m_hTag.end());
   emssegment::Case::instance()->join(m_hQuery);
   m_pXMLDocument->setMaximumSize(64000);
   m_pXMLDocument->setSuppressEmptyTags(false);
   int iRC = parse();
   m_iCount = 0;
   m_bUpdateDetails = true;
   if (iRC != 0)
      return reply();
   m_pXMLDocument->add("tab");
   vector<string> hToken;
   Buffer::parse(m_pXMLItem->get("column"),",",hToken);
   for (vector<string>::iterator p = hToken.begin();p != hToken.end();++p)
   {
      m_hGenericSegment.set("Name",(*p));
      vector<string> hTag;
      Buffer::parse((*p),".",hTag);
      if (hTag.size() == 1)
         hTag.insert(hTag.begin(),"Case");
      if (hTag.size() == 2)
      {
         m_hTag.push_back(make_pair(hTag[0],hTag[1]));
         segment::GenericSegment* q = emssegment::Case::instance()->getGenericSegment(hTag[0]);
         if (!q)
         {
            m_pXMLDocument->revert();
            string strTxt("Undefined table: ");
            strTxt += hTag[0];
            SOAPSegment::instance()->setMsg("JX11.2","Validation error",strTxt);
            SOAPSegment::instance()->setRtnCde('3');
            return reply();
         }
         int i = q->getValue().size();
         if (!emssegment::Case::instance()->bind(m_hQuery,hTag[0],hTag[1]))
         {
            m_pXMLDocument->revert();
            SOAPSegment::instance()->setRtnCde('3');
            return reply();
         }
         m_hIndex.push_back(make_pair(i,q->getValue().size() - 1));
         m_pXMLDocument->add("column");
      }
   }
   if (m_hQuery.getSearchCondition().find("EMS_TRANSITION") == string::npos)
      m_hQuery.join("EMS_CASE","INNER","EMS_TRANSITION","STATE_TSTAMP","TSTAMP_CREATED");
   secure(m_hQuery,"EMS_CASE");
   string strOrderByclause(m_hQuery.getOrderByClause());
   if (strOrderByclause.empty())
      strOrderByclause.assign("CASE_NO DESC",12);
   for (int i = 0; i < m_hQuery.getTable().size(); i++)
   {
      if (m_hQuery.getTable()[i].getTableName() == "EMS_CASE" && strOrderByclause.find("CASE_NO ",0,8) == string::npos)
         strOrderByclause.insert(0,"CASE_NO DESC,",13);
      if (m_hQuery.getTable()[i].getTableName() == "EMS_COMMENT" && strOrderByclause.find("EMS_COMMENT.TSTAMP_CREATED DESC",0,31) == string::npos)
         strOrderByclause.append(",EMS_COMMENT.TSTAMP_CREATED DESC",32);
   }
   m_hQuery.setOrderByClause(strOrderByclause);
   auto_ptr<reusable::SelectStatement> pSelectStatement((reusable::SelectStatement*)database::DatabaseFactory::instance()->create("SelectStatement"));
   bool b = pSelectStatement->execute(m_hQuery);
   if (b == false
      || pSelectStatement->getRows() == 0)
   {
      m_pXMLDocument->revert();
      SOAPSegment::instance()->setRtnCde(b ? '2' : '5');
      return reply();
   }
   m_pXMLDocument->write("tab");
   SOAPSegment::instance()->setRtnCde(m_hQuery.getAbort() ? '1' : '0');
   return reply();
  //## end restcommand::CasesCommand::execute%6525C1EC009E.body
}

void CasesCommand::update (Subject* pSubject)
{
  //## begin restcommand::CasesCommand::update%6525C1EE02D8.body preserve=yes
   if (pSubject == &m_hQuery)
   {
      map<string,emssegment::GenericSegment*,less<string> >::const_iterator q = Case::instance()->getGenericSegment().find("Case");
      string strTemp;
      (*q).second->_field("CASE_NO",strTemp,false,false);
      if (CaseSegment::instance()->getCASE_NO().length() == 0)
         CaseSegment::instance()->setCASE_NO(strTemp);
      else
         if (CaseSegment::instance()->getCASE_NO() != strTemp)
         {
            CaseSegment::instance()->setCASE_NO(strTemp);
            m_iCount = 0;
         }
      if (!emssegment::Case::instance()->skip())
      {
         m_iCount++;
         if (++m_iTotalRows <= m_iMaxRows)
         {
            ++m_iRows;
            if (m_pXMLDocument->add("row") == false)
            {
               m_pXMLDocument->revert();
               m_hQuery.setAbort(true);
               return;
            }
            for (int i = 0;i < m_hTag.size();++i)
            {
               string strValue;
               segment::GenericSegment* q = emssegment::Case::instance()->getGenericSegment(m_hTag[i].first);
               for (int j = m_hIndex[i].first;j <= m_hIndex[i].second;++j)
               {
                  string strTemp;
                  q->getFieldByIndex(j,strTemp);
                  if (j > m_hIndex[i].first)
                     strValue.append("~",1);
                  strValue += strTemp;
               }
               m_hGenericSegment.set("Value",strValue);
               if (m_pXMLDocument->add("value") == false)
               {
                  m_pXMLDocument->revert();
                  m_hQuery.setAbort(true);
                  return;
               }
            }
            m_pXMLDocument->write("row");
         }
         if (getMaxRows() == UseCase::getItems())
            m_hQuery.setAbort(true);
      }
      UseCase::addItem();
      return;
   }
   RESTCommand::update(pSubject);
  //## end restcommand::CasesCommand::update%6525C1EE02D8.body
}

// Additional Declarations
  //## begin restcommand::CasesCommand%6525C12F0364.declarations preserve=yes
  //## end restcommand::CasesCommand%6525C12F0364.declarations

} // namespace restcommand

//## begin module%6525EE040092.epilog preserve=yes
//## end module%6525EE040092.epilog
