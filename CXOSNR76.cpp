//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%639C7CF00173.cm preserve=no
//## end module%639C7CF00173.cm

//## begin module%639C7CF00173.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%639C7CF00173.cp

//## Module: CXOSNR76%639C7CF00173; Package body
//## Subsystem: NRDLL%5637980B0094
//## Source file: C:\Repos\DataNavigatorServer\Windows\Build\Dn\Server\Library\Nrdll\CXOSNR76.cpp

//## begin module%639C7CF00173.additionalIncludes preserve=no
//## end module%639C7CF00173.additionalIncludes

//## begin module%639C7CF00173.includes preserve=yes
//## end module%639C7CF00173.includes

#ifndef CXOSDB68_h
#include "CXODDB68.hpp"
#endif
#ifndef CXOSNR77_h
#include "CXODNR77.hpp"
#endif
#ifndef CXOSNR76_h
#include "CXODNR76.hpp"
#endif


//## begin module%639C7CF00173.declarations preserve=no
//## end module%639C7CF00173.declarations

//## begin module%639C7CF00173.additionalDeclarations preserve=yes
namespace
{
   reusable::Object* createStarActivityReport(const char* sBuffer, int iRecordLength, const string& strFileName)
   {
      if (iRecordLength == 133
         && (!memcmp(sBuffer, "1R-005-003", 10) || !memcmp(sBuffer, "1R-005-002", 10)) && !memcmp(sBuffer + 70, "STAR", 4))
      {
         if(strFileName.find(".RGNLMAC.") != string::npos)
            return new networkreconciliation::StarActivityReport("MAC");
         else if(strFileName.find(".STARSE.") != string::npos)
            return new networkreconciliation::StarActivityReport("HNR");
         else 
            return new networkreconciliation::StarActivityReport("STR");
      }
      return 0;
   }
   const bool registered = database::NetworkReportFactory::instance()->registerReport("StarActivityReport", createStarActivityReport);
}
//## end module%639C7CF00173.additionalDeclarations


//## Modelname: Reconciliation::NetworkReconciliation_CAT%5637978002B1
namespace networkreconciliation {
//## begin networkreconciliation%5637978002B1.initialDeclarations preserve=yes
//## end networkreconciliation%5637978002B1.initialDeclarations

// Class networkreconciliation::StarActivityReport 

StarActivityReport::StarActivityReport()
  //## begin StarActivityReport::StarActivityReport%639C7C870387_const.hasinit preserve=no
  //## end StarActivityReport::StarActivityReport%639C7C870387_const.hasinit
  //## begin StarActivityReport::StarActivityReport%639C7C870387_const.initialization preserve=yes
  //## end StarActivityReport::StarActivityReport%639C7C870387_const.initialization
{
  //## begin networkreconciliation::StarActivityReport::StarActivityReport%639C7C870387_const.body preserve=yes
   memcpy(m_sID, "NR76", 4);
  //## end networkreconciliation::StarActivityReport::StarActivityReport%639C7C870387_const.body
}

StarActivityReport::StarActivityReport (const string& strNetworkId)
  //## begin networkreconciliation::StarActivityReport::StarActivityReport%6407C378017F.hasinit preserve=no
  //## end networkreconciliation::StarActivityReport::StarActivityReport%6407C378017F.hasinit
  //## begin networkreconciliation::StarActivityReport::StarActivityReport%6407C378017F.initialization preserve=yes
  //## end networkreconciliation::StarActivityReport::StarActivityReport%6407C378017F.initialization
{
  //## begin networkreconciliation::StarActivityReport::StarActivityReport%6407C378017F.body preserve=yes
   m_bEndOfReport = false;
   setNETWORK_ID(strNetworkId);
#ifdef MVS
   m_strFileName.assign("DNDNNR76");
#else
   m_strFileName.assign("CXOXNR76");
#endif 
  //## end networkreconciliation::StarActivityReport::StarActivityReport%6407C378017F.body
}


StarActivityReport::~StarActivityReport()
{
  //## begin networkreconciliation::StarActivityReport::~StarActivityReport%639C7C870387_dest.body preserve=yes
  //## end networkreconciliation::StarActivityReport::~StarActivityReport%639C7C870387_dest.body
}



//## Other Operations (implementation)
void StarActivityReport::advance (const char* sBuffer)
{
  //## begin networkreconciliation::StarActivityReport::advance%63A327CF00E4.body preserve=yes
   NetworkDispute::advance();
   if (m_iLineNumber - 1 == m_hTemplate.getPageSize() + (getROLE() == "I" ? 0 : 1))
   {
      if (sBuffer[1] != ' ')
      {
         if (sBuffer[0] == '1')
            m_iLineNumber = 0;
         else
            m_iLineNumber = getROLE() == "I" ? 11 : 12;
         m_bEndOfReport = true;
      }
      else
         m_iLineNumber = 0;
   }
   else if (m_iLineNumber - 1 == m_hTemplate.getSkipLine()
      && !strncmp(sBuffer + 1, m_hTemplate.getSummaryTitle().c_str(), m_hTemplate.getSummaryTitle().length()))
      m_iLineNumber = 0;
   if (m_iLineNumber > 11 && ((sBuffer[1] == ' ' && !memcmp(sBuffer+90,"_____________",13)) || !memcmp(sBuffer + 24, "TOTALS", 6)))
      m_iLineNumber = 0;
  //## end networkreconciliation::StarActivityReport::advance%63A327CF00E4.body
}

bool StarActivityReport::preview (const char* sBuffer)
{
  //## begin networkreconciliation::StarActivityReport::preview%63A600980361.body preserve=yes
   return false;
  //## end networkreconciliation::StarActivityReport::preview%63A600980361.body
}

bool StarActivityReport::scrape (const char* sBuffer, int iRecordLength)
{
  //## begin networkreconciliation::StarActivityReport::scrape%63A3160F01AA.body preserve=yes
   if (sBuffer[0] == '1' && iRecordLength == 133
      && (!memcmp(sBuffer, "1R-005-003", 10) || !memcmp(sBuffer, "1R-005-002", 10)))
   {
      m_strReportIdentifier = "STAR";
      m_strReportIdentifier.append(sBuffer, 10);
      setROLE(sBuffer[9] == '3' ? "I" : "A");
      if (m_iLineNumber != m_hTemplate.getPageSize() || !m_iLineNumber)
         NetworkDispute::advance();
   }
   if (!m_iLineNumber)
      return true; 
   if (m_bEndOfReport)
      m_bEndOfReport = false;
   string strToken(m_strReportIdentifier);
   char szTemp[9];
   strToken.append(szTemp,snprintf(szTemp, sizeof(szTemp), "LINE%04d", m_iLineNumber));
   if (m_hTemplate.map(strToken, sBuffer, this, m_iLineNumber, m_strFileName.c_str(), iRecordLength))
   {
      vector<string> hTokens;
      if (Buffer::parse(getREASON_CODE_DESC(), "-", hTokens) >= 2 && getREASON_CODE().empty())
      {
         setREASON_CODE(rtrim(hTokens[0]));
         if ((ltrim(hTokens[1]).find("FRAU") != string::npos) && (ltrim(hTokens[1]).find("FRAUD") == string::npos))
            hTokens[1] += 'D';
         setREASON_CODE_DESC(ltrim(hTokens[1]));
      }
      save();
      reset2();
      m_strREQUEST_TYPE.erase();
   }
   advance(sBuffer);
   if (m_bEndOfReport)
      scrape(sBuffer, iRecordLength);
   return true;
  //## end networkreconciliation::StarActivityReport::scrape%63A3160F01AA.body
}

// Additional Declarations
  //## begin networkreconciliation::StarActivityReport%639C7C870387.declarations preserve=yes
  //## end networkreconciliation::StarActivityReport%639C7C870387.declarations

} // namespace networkreconciliation

//## begin module%639C7CF00173.epilog preserve=yes
//## end module%639C7CF00173.epilog
