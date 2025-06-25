//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%40B3A90B009C.cm preserve=no
//## end module%40B3A90B009C.cm

//## begin module%40B3A90B009C.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%40B3A90B009C.cp

//## Module: CXOSBC15%40B3A90B009C; Package body
//## Subsystem: Connex Library::BCDLL%394E1F84004A
//## Source file: C:\Repos\DataNavigatorServer\Windows\Build\ConnexPlatform\Server\Library\Bcdll\CXOSBC15.cpp

//## begin module%40B3A90B009C.additionalIncludes preserve=no
//## end module%40B3A90B009C.additionalIncludes

//## begin module%40B3A90B009C.includes preserve=yes
#include <algorithm>
//## end module%40B3A90B009C.includes

#ifndef CXOSRU20_h
#include "CXODRU20.hpp"
#endif
#ifndef CXOSIF03_h
#include "CXODIF03.hpp"
#endif
#ifndef CXOSBC16_h
#include "CXODBC16.hpp"
#endif
#ifndef CXOSIF10_h
#include "CXODIF10.hpp"
#endif
#ifndef CXOSMN05_h
#include "CXODMN05.hpp"
#endif
#ifndef CXOSBC15_h
#include "CXODBC15.hpp"
#endif


//## begin module%40B3A90B009C.declarations preserve=no
//## end module%40B3A90B009C.declarations

//## begin module%40B3A90B009C.additionalDeclarations preserve=yes
//## end module%40B3A90B009C.additionalDeclarations


//## Modelname: Connex Library::Command_CAT%3459269903E2
namespace command {
//## begin command%3459269903E2.initialDeclarations preserve=yes
//## end command%3459269903E2.initialDeclarations

// Class command::XMLDocument 

XMLDocument::XMLDocument()
  //## begin XMLDocument::XMLDocument%40B3A82E0280_const.hasinit preserve=no
      : m_bFull(false),
        m_iMaximumSize(0),
        m_iSize(0),
        m_bSuppressEmptyTags(true),
        m_pXMLText(0),
        m_pRow(0)
  //## end XMLDocument::XMLDocument%40B3A82E0280_const.hasinit
  //## begin XMLDocument::XMLDocument%40B3A82E0280_const.initialization preserve=yes
  //## end XMLDocument::XMLDocument%40B3A82E0280_const.initialization
{
  //## begin command::XMLDocument::XMLDocument%40B3A82E0280_const.body preserve=yes
   memcpy(m_sID,"BC15",4);
  //## end command::XMLDocument::XMLDocument%40B3A82E0280_const.body
}

XMLDocument::XMLDocument (const char* pszInFile, const char* pszTemplate, reusable::Row* pRow, command::XMLText* pXMLText)
  //## begin command::XMLDocument::XMLDocument%40B4F1400271.hasinit preserve=no
      : m_bFull(false),
        m_iMaximumSize(0),
        m_iSize(0),
        m_bSuppressEmptyTags(true),
        m_pXMLText(0),
        m_pRow(0)
  //## end command::XMLDocument::XMLDocument%40B4F1400271.hasinit
  //## begin command::XMLDocument::XMLDocument%40B4F1400271.initialization preserve=yes
  //## end command::XMLDocument::XMLDocument%40B4F1400271.initialization
{
  //## begin command::XMLDocument::XMLDocument%40B4F1400271.body preserve=yes
   memcpy(m_sID,"BC15",4);
   m_pRow = pRow;
   m_pXMLText = pXMLText;
   bool bContinue = false;
   map<string,vector<string>,less<string> >::iterator p = m_hMember.end();
   vector<string> x;
   string strBuffer;
   FlatFile hFlatFile(pszInFile,pszTemplate);
   char sBuffer[256];
   size_t m = 0;
   while (hFlatFile.read(sBuffer,256,&m))
   {
      strBuffer.assign(sBuffer,m);
      size_t pos = strBuffer.find_last_not_of(" ");
      if (pos != string::npos)
         strBuffer.erase(pos + 1);
      pos = strBuffer.find_first_not_of(" ");
      if (pos != string::npos)
         strBuffer.erase(0,pos);
      if (!strBuffer.empty())
      {
         if (strBuffer[0] == '&')
         {
            strBuffer.erase(0,1);
            m_hMember[strBuffer] = x;
            p = m_hMember.find(strBuffer);
         }
         else
         if (p != m_hMember.end())
         {
            if (bContinue)
            {
               if (strBuffer[strBuffer.length() - 1] == '\\')
                  strBuffer.resize(strBuffer.length() - 1);
               else
                  bContinue = false;
               (*p).second.back() += strBuffer;
            }
            else
            {
               if (strBuffer[strBuffer.length() - 1] == '\\')
               {
                  strBuffer.resize(strBuffer.length() - 1);
                  bContinue = true;
               }
               if (strBuffer == "<session>~session</session>")
                  strBuffer = "<session>xxxxxxxxxxxxxxxxxxxxxxxxx</session>";
               (*p).second.push_back(strBuffer);
            }
         }
      }
   }
  //## end command::XMLDocument::XMLDocument%40B4F1400271.body
}


XMLDocument::~XMLDocument()
{
  //## begin command::XMLDocument::~XMLDocument%40B3A82E0280_dest.body preserve=yes
   write("");
   reset();
  //## end command::XMLDocument::~XMLDocument%40B3A82E0280_dest.body
}



//## Other Operations (implementation)
bool XMLDocument::add (const char* pszElement)
{
  //## begin command::XMLDocument::add%40B4E792004E.body preserve=yes
   set<string> s;
   s.insert(string(pszElement));
   return add(s.begin(),s.end());
  //## end command::XMLDocument::add%40B4E792004E.body
}

bool XMLDocument::add (const char* pszLocation, const char* pszElement)
{
  //## begin command::XMLDocument::add%5C58636D01EF.body preserve=yes
   string strTemp(pszLocation);
   reusable::Deque<string>::Iterator q = m_hFile.find(m_hFile.begin(), m_hFile.end(), strTemp);
   if (q == m_hFile.end())
      return false;
   string strText("+",1);
   strText.append(pszElement);
   m_hFile.insert(q,strText);
   if (add(pszElement))
   {
      q = m_hFile.find(m_hFile.begin(), m_hFile.end(), strText);
      if (q == m_hFile.end())
         return false;
      m_hFile.erase(q);
      return true;
   }
   return false;
  //## end command::XMLDocument::add%5C58636D01EF.body
}

bool XMLDocument::add (set<reusable::string>::const_iterator first, set<reusable::string>::const_iterator last)
{
  //## begin command::XMLDocument::add%52BC66640069.body preserve=yes
   Trace::put("**** XMLDocument::add");
   for (set<string,less<string> >::const_iterator s = first;s != last;++s)
   {
      Trace::put((*s).c_str());
      string strKey("+");
      strKey.append((*s));
      reusable::Deque<string> hElement;
      reusable::Deque<string>::Iterator q;
      map<string,vector<string>,less<string> >::iterator p = m_hMember.find((*s));
      if (p == m_hMember.end())
      {
         Trace::put("Warning! XMLDocument::add cannot find element: ");
         Trace::put((*s).c_str());
      }
      else
      {
         //hElement.insert(hElement.begin(),(*p).second.begin(),(*p).second.end());
         vector<string>::iterator v;
         q = hElement.begin();
         for (v = (*p).second.begin(); v != (*p).second.end(); v++)
            hElement.insert(q, (*v));
         while ((q = findInclude(hElement)) != hElement.end())
         {
            p = m_hMember.find((*q).substr(9));
            (*q).assign("+REPLACED",9);
            if (p != m_hMember.end())
               //hElement.insert(q,(*p).second.begin(),(*p).second.end());
               for (v = (*p).second.begin(); v != (*p).second.end(); v++)
                  hElement.insert(q, (*v));
         }
         for (q = hElement.begin();q != hElement.end();q++)
            m_pXMLText->substitute(*q,m_bSuppressEmptyTags,m_bSuppressEmptyTags);
         if (m_iMaximumSize > 0)
         {
            int i = 0;
            for (q = m_hFile.begin();q != m_hFile.end();q++)
               i += (*q).length();
            for (q = hElement.begin();q != hElement.end();q++)
               if ((*q)[0] != '+'
                  && (*q).find("></") == string::npos)
                  i += (*q).length();
            if ((m_iSize + i) > m_iMaximumSize)
            {
               char szTemp[256];
               Trace::put(szTemp, snprintf(szTemp, sizeof(szTemp),
                  "Size limit exceeded : %d of %d", m_iSize + i, m_iMaximumSize),true);
               m_bFull = true;
               return false;
            }
         }
         reusable::Deque<string>::Iterator h;
         reusable::Deque<string> hFinal;
         size_t pos;
         for (h = hElement.begin();h != hElement.end();h++)
         {
            pos = (*h).find("</");
            if (( pos != string::npos
               && (*h).find("</",pos+2) != string::npos)
               || ((*h).find("></") == string::npos
               && (*h).find(">:</") == string::npos
               && (*h).length() > 0))
               hFinal.push_back((*h));
         }
         q = m_hFile.find(m_hFile.begin(),m_hFile.end(),strKey);
         m_hFile.insert(q,hFinal.begin(),hFinal.end());
      }
   }
   Trace::put("**** XMLDocument::add end");
   return true;
  //## end command::XMLDocument::add%52BC66640069.body
}

void XMLDocument::dump ()
{
  //## begin command::XMLDocument::dump%5225EE3200EB.body preserve=yes
   reusable::Deque<string>::Iterator q;
   cout << "************** start dump *************" << endl;
   for (q = m_hFile.begin();q != m_hFile.end();q++)
      cout << (*q).c_str() << endl;
   cout << "************** end dump ***************" << endl;
  //## end command::XMLDocument::dump%5225EE3200EB.body
}

reusable::Deque<reusable::string>::Iterator XMLDocument::findInclude (reusable::Deque<reusable::string>& hElement)
{
  //## begin command::XMLDocument::findInclude%4418859000D0.body preserve=yes
   reusable::Deque<string>::Iterator q;
   for (q = hElement.begin();q != hElement.end();q++)
   {
      if ((*q).length() > 9 && (*q).substr(0,9) == "+INCLUDE ")
         return q;
   }
   return q;
  //## end command::XMLDocument::findInclude%4418859000D0.body
}

bool XMLDocument::isEndTag (reusable::string& strXML, const char* pszElement)
{
  //## begin command::XMLDocument::isEndTag%44183EDC03C3.body preserve=yes
   //three formats of endtags must be considered:
   // #1) end tag on separate line      ==> </NAME>
   // #2) end tag on same line          ==> <NAME>some name</NAME>
   // #3) end tag included in start tag ==> <NAME id="some name" />
   //construct conventional endtag
   string strEndTag("</",2);
   strEndTag.append(pszElement);
   strEndTag.append(">",1);
   //test for #1 and #2
   if (strXML.find(strEndTag) != string::npos)
      return true;
   else
   {
      string strStartTag("<",1);
      strStartTag.append(pszElement);
      strStartTag.append(" ");
      size_t pos = strXML.find(strStartTag);
      if (pos != string::npos && strXML.substr(strXML.find_last_not_of(" ") - 1,2) == "/>")
         return true;
   }
   return false;
  //## end command::XMLDocument::isEndTag%44183EDC03C3.body
}

int XMLDocument::recordCount ()
{
  //## begin command::XMLDocument::recordCount%443EBF6A00A2.body preserve=yes
   return m_hMember.size();
  //## end command::XMLDocument::recordCount%443EBF6A00A2.body
}

void XMLDocument::reset ()
{
  //## begin command::XMLDocument::reset%56E1D3100067.body preserve=yes
   m_hFile.erase(m_hFile.begin(),m_hFile.end());
   m_bFull = false;
   m_hSave.erase(m_hSave.begin(),m_hSave.end());
   m_iSize = 0;
  //## end command::XMLDocument::reset%56E1D3100067.body
}

void XMLDocument::revert ()
{
  //## begin command::XMLDocument::revert%52FD35120325.body preserve=yes
   m_hFile = m_hSave;
  //## end command::XMLDocument::revert%52FD35120325.body
}

void XMLDocument::save ()
{
  //## begin command::XMLDocument::save%52FD35070282.body preserve=yes
   m_hSave = m_hFile;
  //## end command::XMLDocument::save%52FD35070282.body
}

void XMLDocument::setTagValue (const char* pszTagName, const char* pszValue)
{
  //## begin command::XMLDocument::setTagValue%5225EE5A0165.body preserve=yes
   string strTagName("<");
   strTagName.append(pszTagName);
   strTagName.append(">");
   reusable::Deque<string>::Iterator q;
   for (q = m_hFile.begin();q != m_hFile.end();q++)
   {
      size_t i = (*q).find(strTagName);
      if (i != string::npos)
      {
         i += strTagName.length();
         (*q).insert(i,pszValue);
         i += strlen(pszValue);
         size_t j = (*q).find("</") - i;
         (*q).erase(i,j);
         break;
      }
   }
  //## end command::XMLDocument::setTagValue%5225EE5A0165.body
}

short XMLDocument::size (const char* pszElement)
{
  //## begin command::XMLDocument::size%4EAF0AC90299.body preserve=yes
   short szSizeOfSegment = 0;
   map<string,vector<string>,less<string> >::iterator p = m_hMember.find(pszElement);
   if (p == m_hMember.end())
   {
      Trace::put("Warning! Cannot find element: ");
      Trace::put(pszElement);
      return 0;
   }
   vector<string>::iterator q;
   for (q = (*p).second.begin();q != (*p).second.end();q++)
      szSizeOfSegment += m_pXMLText->sizeOfEntry(*q);
   return szSizeOfSegment;
  //## end command::XMLDocument::size%4EAF0AC90299.body
}

short XMLDocument::size (const char* pszElement, const reusable::string& strTag)
{
  //## begin command::XMLDocument::size%4EAF0AF80328.body preserve=yes
   map<string,vector<string>,less<string> >::iterator p = m_hMember.find(pszElement);
   if (p == m_hMember.end())
   {
      Trace::put("Warning! Cannot find element: ");
      Trace::put(pszElement);
      return 0;
   }
   vector<string>::iterator q;
   for (q = (*p).second.begin();q != (*p).second.end();q++)
   {
      int n1 = (*q).find("<");
      int n2 = (*q).find(">");
      string strTagName;
      if (n1 != string::npos && n2 != string::npos)
      {
         strTagName.assign((*q),n1+1,n2-n1-1);
         strTagName = strTagName.substr(0,strTagName.find_first_of(' '));
      }
      if (strTagName == strTag)
         return m_pXMLText->sizeOfEntry(*q);
   }
   return 0;
  //## end command::XMLDocument::size%4EAF0AF80328.body
}

void XMLDocument::write (const char* pszElement)
{
  //## begin command::XMLDocument::write%5DD48F1300C3.body preserve=yes
   Trace::put("XMLDocument::write");
   size_t pos = string::npos;
   string strTemp;
   bool b = true;
   while (b && m_hFile.size() > 0)
   {
      b = false;
      reusable::Deque<string>::Iterator p1 = m_hFile.begin();
      reusable::Deque<string>::Iterator p2 = p1;
      ++p2;
      while (p2 != m_hFile.end())
      {
         strTemp = (*p1);
         strTemp.insert(1,"/",1);
         if (strTemp == (*p2))
         {
            m_hFile.erase(p1,++p2);
            b = true;
            break;
         }
         else
         {
            ++p1;
            ++p2;
         }
      }

   }
   if (strlen(pszElement) > 0)
   {
      b = false;
      for (reusable::Deque<string>::Iterator p = m_hFile.begin();p != m_hFile.end();++p)
      {
         if (isEndTag((*p),pszElement))
         {
            b = true;
            break;
         }
      }
      if (!b)
         return;
   }
   while (m_hFile.size() > 0)
   {
      string strXML(m_hFile.front());
      pos = strXML.find_first_not_of(" ");
      if (pos != string::npos && strXML[pos] != '+')
      {
         pos = strXML.find("</");
         if ((pos != string::npos
            && strXML.find("</",pos+2) != string::npos)
            || strXML.find("></") == string::npos) // !!! is this OK ???
         {
            Trace::put(strXML.c_str());
            m_pRow->getBuffer().assign(strXML.data(),strXML.length());
            m_pRow->notify();
            m_iSize += strXML.length();
         }
      }
      m_hFile.pop_front();
      if (m_hFile.size() > 0 && isEndTag(strXML,pszElement))
         break;
   }
   Trace::put("XMLDocument::write end");
  //## end command::XMLDocument::write%5DD48F1300C3.body
}

// Additional Declarations
  //## begin command::XMLDocument%40B3A82E0280.declarations preserve=yes
  //## end command::XMLDocument%40B3A82E0280.declarations

} // namespace command

//## begin module%40B3A90B009C.epilog preserve=yes
//## end module%40B3A90B009C.epilog
