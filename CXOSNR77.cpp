//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%63A597740358.cm preserve=no
//## end module%63A597740358.cm

//## begin module%63A597740358.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%63A597740358.cp

//## Module: CXOSNR77%63A597740358; Package body
//## Subsystem: NRDLL%5637980B0094
//## Source file: C:\Repos\DataNavigatorServer\Windows\Build\Dn\Server\Library\Nrdll\CXOSNR77.cpp

//## begin module%63A597740358.additionalIncludes preserve=no
//## end module%63A597740358.additionalIncludes

//## begin module%63A597740358.includes preserve=yes
#ifdef _WIN32
#include <winsock2.h>
#endif
#ifdef _UNIX
#include <sys/types.h>
#include <netinet/in.h>
#include <inttypes.h>
#endif
#include <algorithm>
//## end module%63A597740358.includes

#ifndef CXOSBS01_h
#include "CXODBS01.hpp"
#endif
#ifndef CXOSBC37_h
#include "CXODBC37.hpp"
#endif
#ifndef CXOSIF03_h
#include "CXODIF03.hpp"
#endif
#ifndef CXOSRU34_h
#include "CXODRU34.hpp"
#endif
#ifndef CXOSRS11_h
#include "CXODRS11.hpp"
#endif
#ifndef CXOSIF10_h
#include "CXODIF10.hpp"
#endif
#ifndef CXOSNR82_h
#include "CXODNR82.hpp"
#endif
#ifndef CXOSNR83_h
#include "CXODNR83.hpp"
#endif
#ifndef CXOSNR80_h
#include "CXODNR80.hpp"
#endif
#ifndef CXOSNR79_h
#include "CXODNR79.hpp"
#endif
#ifndef CXOSNR81_h
#include "CXODNR81.hpp"
#endif
#ifndef CXOSNR78_h
#include "CXODNR78.hpp"
#endif
#ifndef CXOSNR85_h
#include "CXODNR85.hpp"
#endif
#ifndef CXOSNR84_h
#include "CXODNR84.hpp"
#endif
#ifndef CXOSNR87_h
#include "CXODNR87.hpp"
#endif
#ifndef CXOSNR88_h
#include "CXODNR88.hpp"
#endif
#ifndef CXOSNR95_h
#include "CXODNR95.hpp"
#endif
#ifndef CXOSNR77_h
#include "CXODNR77.hpp"
#endif


//## begin module%63A597740358.declarations preserve=no
//## end module%63A597740358.declarations

//## begin module%63A597740358.additionalDeclarations preserve=yes
//## end module%63A597740358.additionalDeclarations


//## Modelname: Reconciliation::NetworkReconciliation_CAT%5637978002B1
namespace networkreconciliation {
//## begin networkreconciliation%5637978002B1.initialDeclarations preserve=yes
//## end networkreconciliation%5637978002B1.initialDeclarations

// Class networkreconciliation::Template 

Template::Template()
  //## begin Template::Template%63A5A1F9014F_const.hasinit preserve=no
      : m_siSkipLine(0),
        m_siPageSize(0)
  //## end Template::Template%63A5A1F9014F_const.hasinit
  //## begin Template::Template%63A5A1F9014F_const.initialization preserve=yes
  //## end Template::Template%63A5A1F9014F_const.initialization
{
  //## begin networkreconciliation::Template::Template%63A5A1F9014F_const.body preserve=yes
      memcpy(m_sID, "NR77", 4);
      m_hTransactionFunction["F(NR78)"] = new networkreconciliation::DateRecon;
      m_hTransactionFunction["F(NR79)"] = new networkreconciliation::NetInstId;
      m_hTransactionFunction["F(NR80)"] = new networkreconciliation::RequestType;
      m_hTransactionFunction["F(NR81)"] = new networkreconciliation::NetworkId;
      m_hTransactionFunction["F(NR82)"] = new networkreconciliation::ProcessCode;
      m_hTransactionFunction["F(NR83)"] = new networkreconciliation::ProcId;
      m_hTransactionFunction["F(NR84)"] = new networkreconciliation::TstampLocal;
      m_hTransactionFunction["F(NR85)"] = new networkreconciliation::DateAdjustment;
      m_hTransactionFunction["F(NR87)"] = new networkreconciliation::FinancialImpact;
      m_hTransactionFunction["F(NR88)"] = new networkreconciliation::Role;
      m_hTransactionFunction["F(NR95)"] = new networkreconciliation::ReasonCodeDescription;
  //## end networkreconciliation::Template::Template%63A5A1F9014F_const.body
}


Template::~Template()
{
  //## begin networkreconciliation::Template::~Template%63A5A1F9014F_dest.body preserve=yes
  //## end networkreconciliation::Template::~Template%63A5A1F9014F_dest.body
}



//## Other Operations (implementation)
bool Template::map (const reusable::string& strToken, const char* sBuffer, segment::Segment* pSegment, int iLineNumber, const char *sFileName, int iRecordLength)
{
  //## begin networkreconciliation::Template::map%63A5AAF003C3.body preserve=yes
      if (m_hTemplateToken.empty())
         if (!read(sFileName))
            return false;
      multimap<string, TemplateToken, less <string> >::iterator p = m_hTemplateToken.find(strToken);
      pair<multimap<string, TemplateToken, less<string> >::iterator, multimap<string, TemplateToken, less<string> >::iterator> hRange;
      hRange = m_hTemplateToken.equal_range(strToken);
      if (hRange.first == hRange.second)
      {
         string strBuffer(strToken);
         strBuffer += " not mapped : ";
         IF::Trace::put(strBuffer.data(), strBuffer.length());
         return iLineNumber == m_siPageSize ? 1 : 0;
      }
      if (IF::Trace::getEnable())
      {
         string strBuffer(strToken);
         strBuffer += " is mapped : ";
         IF::Trace::put(strBuffer.data(), strBuffer.length());
      }
      multimap<string, TemplateToken, less<string> >::iterator pRange;
      int r = 0;
      for (pRange = hRange.first; pRange != hRange.second; ++pRange)
         ++r;
      for (pRange = hRange.first; pRange != hRange.second; ++pRange)
      {
         string strBuffer(strToken);
         strBuffer += " -> ";
         strBuffer += (*pRange).second.getName();
         strBuffer += " : ";
         const char* pszValue = sBuffer + (*pRange).second.getOffset();
         if ((*pRange).second.getOffset() > iRecordLength)
            continue;
         int j = (*pRange).second.getLength();
         char szTemp[PERCENTF];
         if ((*pRange).second.getType() == 'd')
         {
            double d = *(double*)pszValue;
            if (d == 0)
               pszValue = 0;
            else
            {
               j = sprintf(szTemp, "%01.0f", d);
               pszValue = szTemp;
            }
         }
         else
            if ((*pRange).second.getType() == 's'
               && (*pRange).second.getSigned() == true)
            {
               short k = ntohs(*(short*)pszValue);
               if ((*pRange).second.getVarChar())
               {
                  j = k;
                  pszValue += 2;
               }
               else
               {
                  if (k == 0)
                     pszValue = 0;
                  else
                  {
                     j = sprintf(szTemp, "%01hd", k);
                     pszValue = szTemp;
                  }
               }
            }
            else
               if ((*pRange).second.getType() == 's'
                  && (*pRange).second.getSigned() == false)
               {
                  unsigned short k = ntohs(*(unsigned short*)pszValue);
                  if ((*pRange).second.getVarChar())
                  {
                     j = k;
                     pszValue += 2;
                  }
                  else
                  {
                     if (k == 0)
                        pszValue = 0;
                     else
                     {
                        j = sprintf(szTemp, "%01hu", k);
                        pszValue = szTemp;
                     }
                  }
               }
               else
                  if ((*pRange).second.getType() == 'i')
                  {
                     j = (*pRange).second.getLength();
                     if (j == 4)
                     {
                        unsigned int k = ntohl(*(unsigned int*)pszValue);
                        if (k == 0)
                           pszValue = 0;
                        else
                        {
                           j = sprintf(szTemp, "%01u", k);
                           pszValue = szTemp;
                        }
                     }
                     else
                     {
                        double k = Segment::lltof(ntohl(*(int*)pszValue), ntohl(*(int*)(pszValue + 4)));
                        if (k == 0)
                           pszValue = 0;
                        else
                        {
                           j = sprintf(szTemp, "%01.0f", k);
                           pszValue = szTemp;
                        }
                     }
                  }
                  else
                  {
                     int k = 0;
                     for (k = 0; k < j; ++k)
                     {
                        if (pszValue[k] != ' ')
                           break;
                     }
                     if (j == k)
                        pszValue = 0;
                  }
         if (pszValue)
         {
            string strFunctionName((*pRange).second.getFunctionName());
            string strColumn((*pRange).second.getName());
            size_t m = strlen(pszValue);
            string strValue;
            strValue.assign(pszValue, j < m ? j : m);
            if(strncmp(strColumn.data(),"AMT_",4) == 0 || strstr(strColumn.c_str(), "IMPACT_TO"))
            {
               size_t pos = strValue.find(".");
               if (pos != string::npos)
                  strValue.erase(pos, 1);
               pos = strValue.find(",");
               if (pos != string::npos)
                  strValue.erase(::remove(strValue.begin(), strValue.end(), ','), strValue.end());
               pos = strValue.find("*");
               if (pos != string::npos)
                  strValue.erase(pos, 1);
               pos = strValue.find("-");
               if (pos != string::npos)
               {
                  strValue.replace(strValue.find_first_not_of(' ') - 1, 1, 1, '-');
                  strValue.replace(pos, 1, 1, ' ');
               }
            }
            else
               trim(strValue);
            if (strncmp(strColumn.data(), "PAN", 3) == 0)
            {
                size_t pos = strValue.find(" ");
                if (pos != string::npos)
                    strValue.erase(pos, 1);
            }
            string strTranslatedValue;
            translate(strToken, strFunctionName.empty() ? strColumn : strFunctionName, strValue, strTranslatedValue);
            m_iIndex = (*pRange).second.getIndex();
            if (m_iIndex  == -1)
            {
               if (pSegment->getFieldIndex(strColumn.c_str(), m_iIndex))
                  (*pRange).second.setIndex(m_iIndex);
               else
                  pSegment->_fillField(strColumn.c_str(), strTranslatedValue);
            }
            if (m_iIndex != -1)
            {
               if ((*pRange).second.getFunctionName() == "APPEND")
               {
                  string strOldValue;
                  pSegment->getFieldByIndex(m_iIndex, strOldValue);
                  strTranslatedValue.insert(0, strOldValue);
               }
               pSegment->setFieldByIndex(m_iIndex, strTranslatedValue);
            }
            if (Trace::getEnable())
            {
               string strText(strColumn);
               strText += " = ";
               j = strlen(strTranslatedValue.c_str());
               if (j)
                  strText.append(strTranslatedValue.c_str(), j);
               Trace::put(strText.data(), strText.length());
            }
         }
      }
      return iLineNumber == m_siPageSize ? 1 : 0;
  //## end networkreconciliation::Template::map%63A5AAF003C3.body
}

bool Template::read (const char* sFileName)
{
  //## begin networkreconciliation::Template::read%63A5B15F0030.body preserve=yes
#ifdef MVS
      FlatFile  hTemplateFile("JCL", sFileName);
#else
      FlatFile hTemplateFile("SOURCE", sFileName);
#endif
      if (!hTemplateFile.open())
         return false;
      char* psBuffer = new char[256];
      memset(psBuffer, ' ', 256);
      size_t m = 0;
      char cSegment = ' ';
      string strTable;
      string strName;
      string strToken;
      string strBuffer;
      while (hTemplateFile.read(psBuffer, 256, &m))
      {
         strBuffer.assign(psBuffer,m);
         size_t pos = strBuffer.find("*/");
         if (pos != string::npos)
            strBuffer.erase(pos, 2);
         strBuffer.rtrim();
         if (strBuffer.length() < 5)
            continue;
         pos = strBuffer.find(" /* +");
         if(pos != string::npos)
            strToken.assign(strBuffer, pos + 5, strBuffer.length() - 5);
         if (strstr(strBuffer.c_str(), " ~"))
         {
            vector<string> hTokens;
            Buffer::parse(strBuffer, " [];,", hTokens);
            int i = (hTokens[3] == "//") ? 3 : 2;
            char cType = 'a';
            int iLength = 1;
            bool bSigned = true;
            if (hTokens[0] == "double")
            {
               cType = 'd';
               iLength = 8;
            }
            else
               if (hTokens[0] == "short")
               {
                  cType = 's';
                  iLength = 2;
               }
               else
                  if (hTokens[0] == "unsigned"
                     && hTokens[1] == "short")
                  {
                     cType = 's';
                     iLength = 2;
                     bSigned = false;
                  }
                  else
                     if (hTokens[0] == "int")
                     {
                        cType = 'i';
                        iLength = (i == 2) ? 4 : 8;
                     }
                     else
                        if (i == 3)
                           iLength = atoi(hTokens[2].c_str());
            int iOffset = atoi(hTokens[i + 1].c_str());
            string strTable(hTokens[i + 2].substr(1));
            string strName(hTokens[i + 3]);
            string strFunctionName;
            if (hTokens.size() > (i + 4))
               strFunctionName.assign(hTokens[i + 4]);
            Segment* pSegment = 0;
            void* pAddress = 0;
            short int iSize = 0;
            if (strToken.find(":") == string::npos)
            {
               TemplateToken hTemplateToken (pSegment, strName, iOffset, iLength, cType, pAddress, iSize, 0, 0, strFunctionName.c_str());
               hTemplateToken.setTable(strTable);
               hTemplateToken.setIndex(-1);
               hTemplateToken.setSigned(bSigned);
               hTemplateToken.setHexToChar(hTokens[hTokens.size() - 1] == "HEXTOCHAR");
               hTemplateToken.setVarChar(hTokens[hTokens.size() - 1] == "VARCHAR");
               m_hTemplateToken.insert(multimap<string, TemplateToken, less<string> >::value_type(strToken, hTemplateToken));
            }
            else
            {
               vector<string> hTokens;
               Buffer::parse(strToken, ":", hTokens);
               int j = atoi(hTokens[1].c_str());
               char sType[9] = { "01234567" };
               string strFirst(hTokens[0]);
               strFirst.append(" ", 1);
               string strColumn(strName);
               strColumn.append(" ", 1);
               for (int i = 0; i < j; ++i)
               {
                  strColumn[strColumn.length() - 1] = sType[i];
                  TemplateToken hTemplateToken(pSegment, strColumn, iOffset, iLength, cType, pAddress, iSize, 0, 0, strFunctionName.c_str());
                  hTemplateToken.setTable(strTable);
                  hTemplateToken.setIndex(-1);
                  hTemplateToken.setSigned(bSigned);
                  hTemplateToken.setHexToChar(hTokens[hTokens.size() - 1] == "HEXTOCHAR");
                  hTemplateToken.setVarChar(hTokens[hTokens.size() - 1] == "VARCHAR");
                  strFirst[strFirst.length() - 1] = sType[i];
                  m_hTemplateToken.insert(multimap<string, TemplateToken, less<string> >::value_type(strFirst, hTemplateToken));
               }
            }
         }
         if (!memcmp(strBuffer.data(), " /* @", 5))
         {
            vector<string> hTokens;
            if (Buffer::parse(strBuffer, "/*@~", hTokens) > 3)
            {
               if (hTokens[2] == "SkipLine")
                  m_siSkipLine = ::atoi(hTokens[3].c_str());
               else if (hTokens[2] == "PageSize")
                  m_siPageSize = ::atoi(hTokens[3].c_str());
               else if (hTokens[2] == "SummaryTitle")
                  m_strSummaryTitle.assign(hTokens[3]);
            }
         }
      }
      delete[] psBuffer;
      return true;
  //## end networkreconciliation::Template::read%63A5B15F0030.body
}

void Template::translate (const reusable::string& strNetwork, const reusable::string& strColumn, const reusable::string& strValue, reusable::string& strTranslatedValue)
{
  //## begin networkreconciliation::Template::translate%63A5AE5203A0.body preserve=yes
      strTranslatedValue = strValue;
      std::map<reusable::string,repositorysegment::TransactionFunction*,less<string> >::iterator p = m_hTransactionFunction.find(strColumn);
      if (p != m_hTransactionFunction.end())
         (*p).second->execute(strNetwork, strValue, strTranslatedValue);
  //## end networkreconciliation::Template::translate%63A5AE5203A0.body
}

// Additional Declarations
  //## begin networkreconciliation::Template%63A5A1F9014F.declarations preserve=yes
  //## end networkreconciliation::Template%63A5A1F9014F.declarations

} // namespace networkreconciliation

//## begin module%63A597740358.epilog preserve=yes
//## end module%63A597740358.epilog
