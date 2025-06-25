//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%5A53C60B0379.cm preserve=no
//	$Date:   May 12 2020 23:58:12  $ $Author:   e3028298  $
//	$Revision:   1.14  $
//## end module%5A53C60B0379.cm

//## begin module%5A53C60B0379.cp preserve=no
//	Copyright (c) 1997 - 2012
//	FIS
//## end module%5A53C60B0379.cp

//## Module: CXOSSX27%5A53C60B0379; Package body
//## Subsystem: SXDLL%4DC063A90266
//## Source file: D:\Devel\V03.1A.R002\Dn\Server\Library\Sxdll\CXOSSX27.cpp

//## begin module%5A53C60B0379.additionalIncludes preserve=no
//## end module%5A53C60B0379.additionalIncludes

//## begin module%5A53C60B0379.includes preserve=yes
//## end module%5A53C60B0379.includes

#ifndef CXOSMN05_h
#include "CXODMN05.hpp"
#endif
#ifndef CXOSBC34_h
#include "CXODBC34.hpp"
#endif
#ifndef CXOSBS26_h
#include "CXODBS26.hpp"
#endif
#ifndef CXOSDB01_h
#include "CXODDB01.hpp"
#endif
#ifndef CXOSRU20_h
#include "CXODRU20.hpp"
#endif
#ifndef CXOSSX27_h
#include "CXODSX27.hpp"
#endif
#ifndef CXOSSX28_h
#include "CXODSX28.hpp"
#endif
#ifndef CXOSRS72_h
#include "CXODRS72.hpp"
#endif
#ifndef CXOSTM06_h
#include "CXODTM06.hpp"
#endif
#ifndef CXOSRS13_h
#include "CXODRS13.hpp"
#endif
#ifndef CXOSUC22_h
#include "CXODUC22.hpp"
#endif


//## begin module%5A53C60B0379.declarations preserve=no
//## end module%5A53C60B0379.declarations

//## begin module%5A53C60B0379.additionalDeclarations preserve=yes
//## end module%5A53C60B0379.additionalDeclarations


//## Modelname: DataNavigator Foundation::SOAPCommand_CAT%4DC0633D0140
namespace soapcommand {
//## begin soapcommand%4DC0633D0140.initialDeclarations preserve=yes
//## end soapcommand%4DC0633D0140.initialDeclarations

// Class soapcommand::ATMElectronicJournalCommand 

ATMElectronicJournalCommand::ATMElectronicJournalCommand()
  //## begin ATMElectronicJournalCommand::ATMElectronicJournalCommand%5A53C4C70257_const.hasinit preserve=no
      : m_bDone(false),
        m_bMatch(true),
        m_pElectronicJournal(0)
  //## end ATMElectronicJournalCommand::ATMElectronicJournalCommand%5A53C4C70257_const.hasinit
  //## begin ATMElectronicJournalCommand::ATMElectronicJournalCommand%5A53C4C70257_const.initialization preserve=yes
   ,SOAPCommand("S0003D","@##XLATMJ ")
  //## end ATMElectronicJournalCommand::ATMElectronicJournalCommand%5A53C4C70257_const.initialization
{
  //## begin soapcommand::ATMElectronicJournalCommand::ATMElectronicJournalCommand%5A53C4C70257_const.body preserve=yes
   memcpy(m_sID,"SX27",4);
   m_hRow.attach(this);
   m_hXMLText.add('X',segment::SOAPSegment::instance());
   m_hXMLText.add('A',&m_hGenericSegment);
   m_hXMLText.setMask(false);
   m_pXMLItem = new XMLItem();
   m_pXMLHandler = new ATMElectronicJournalHandler(m_pXMLItem,this);
  //## end soapcommand::ATMElectronicJournalCommand::ATMElectronicJournalCommand%5A53C4C70257_const.body
}

ATMElectronicJournalCommand::ATMElectronicJournalCommand (Handler* pSuccessor)
  //## begin soapcommand::ATMElectronicJournalCommand::ATMElectronicJournalCommand%5A53D56B00A5.hasinit preserve=no
      : m_bDone(false),
        m_bMatch(true),
        m_pElectronicJournal(0)
  //## end soapcommand::ATMElectronicJournalCommand::ATMElectronicJournalCommand%5A53D56B00A5.hasinit
  //## begin soapcommand::ATMElectronicJournalCommand::ATMElectronicJournalCommand%5A53D56B00A5.initialization preserve=yes
   ,SOAPCommand("S0003D","@##XLATMJ ")
  //## end soapcommand::ATMElectronicJournalCommand::ATMElectronicJournalCommand%5A53D56B00A5.initialization
{
  //## begin soapcommand::ATMElectronicJournalCommand::ATMElectronicJournalCommand%5A53D56B00A5.body preserve=yes
   memcpy(m_sID,"SX27",4);
   m_pSuccessor = pSuccessor;
   m_hRow.attach(this);
   m_hXMLText.add('X',segment::SOAPSegment::instance());
   m_hXMLText.add('A',&m_hGenericSegment);
   m_hXMLText.setMask(false);
   m_pXMLItem = new XMLItem();
   m_pXMLHandler = new ATMElectronicJournalHandler(m_pXMLItem,this);
  //## end soapcommand::ATMElectronicJournalCommand::ATMElectronicJournalCommand%5A53D56B00A5.body
}


ATMElectronicJournalCommand::~ATMElectronicJournalCommand()
{
  //## begin soapcommand::ATMElectronicJournalCommand::~ATMElectronicJournalCommand%5A53C4C70257_dest.body preserve=yes
   delete m_pElectronicJournal;
  //## end soapcommand::ATMElectronicJournalCommand::~ATMElectronicJournalCommand%5A53C4C70257_dest.body
}



//## Other Operations (implementation)
void ATMElectronicJournalCommand::abort ()
{
  //## begin soapcommand::ATMElectronicJournalCommand::abort%5A54D7A700F3.body preserve=yes
   SOAPCommand::reset();
   m_pXMLDocument->write("");
   m_hRow.getBuffer().erase();
   m_pXMLDocument->reset();
  //## end soapcommand::ATMElectronicJournalCommand::abort%5A54D7A700F3.body
}

bool ATMElectronicJournalCommand::execute ()
{
  //## begin soapcommand::ATMElectronicJournalCommand::execute%5A54D8B6002B.body preserve=yes
   UseCase hUseCase("CLIENT","## SX27 LIST ATM EJ");
   m_strTSTAMP_TRANS.erase();
   m_strPrimaryKey.erase();
   m_strJOURNAL_TEXT.erase();
   m_bMatch = true;
   m_siUNIQUENESS_KEY = 0;
   if (!m_pElectronicJournal)
      m_pElectronicJournal = new ElectronicJournal();
   if (!m_pXMLDocument)
   {
#ifdef MVS
      m_pXMLDocument = new XMLDocument("JCL","RXLATMJ",&m_hRow,&m_hXMLText);
#else
      m_pXMLDocument = new XMLDocument("SOURCE","CXORLJ01",&m_hRow,&m_hXMLText);
#endif
   }
   m_pXMLDocument->reset();
   int i = parse();
   m_pXMLDocument->add("ATMElectronicJournalRsp");
   if (i != 0)
   {
      reply();
      return false;
   }
   if (m_strTSTAMP_TRANS.length() > 0)
      m_strStartDateTime.assign(m_strTSTAMP_TRANS);
   string strYYYYMM[2];
   strYYYYMM[0] = m_strStartDateTime;
   strYYYYMM[1] = m_strEndDateTime;
   string strDate(m_strEndDateTime.data(),8);
   Date hDate(strDate.c_str());
   hDate += 1;
   strDate = hDate.asString("%Y%m%d");
   string strVALID_OPERATORS("BETWEEN");
   string strTSTAMP_TRANS("'0000000000000000' AND '0000000000000000'");
   strTSTAMP_TRANS.replace(1,16,m_strStartDateTime.data(),16);
   strTSTAMP_TRANS.replace(24,8,strDate.data(),8);
   strTSTAMP_TRANS.replace(32,8,m_strStartDateTime.data() + 8,8);
   m_bDone = false;
   FinancialBaseSegment::instance()->reset();
   if (m_pElectronicJournal->retrieve(strYYYYMM,m_strAcquirerTerminal,strVALID_OPERATORS,strTSTAMP_TRANS,m_bMatch))
   {
      m_pRow = new Row;
      m_pElectronicJournal->setRow(m_pRow);
      m_pRow->attach(this);
      m_pElectronicJournal->process();
      delete m_pRow;
      m_pRow = 0;
   }
   if (m_iRows == 0)
      SOAPSegment::instance()->setRtnCde('2');
   else
   if (m_iRows > m_iMaxRows)
   {
      SOAPSegment::instance()->setRtnCde('1');
      m_hGenericSegment.set("PrimaryKey",m_strPrimaryKey);
      m_hGenericSegment.set("JOURNAL_TEXT",m_strJOURNAL_TEXT);
      if (m_bMatch)
      {
         if (!m_pXMLDocument->add("Journal"))
            m_pXMLDocument->revert();
      }
      else if (!(m_pXMLDocument->add("PrimaryKey") && m_pXMLDocument->add("Journal")))
         m_pXMLDocument->revert();
      m_pXMLDocument->save();
   }
   else
   if (!m_strJOURNAL_TEXT.empty())
   {
      m_hGenericSegment.set("JOURNAL_TEXT",m_strJOURNAL_TEXT);
      if (!m_pXMLDocument->add("Journal"))
         m_pXMLDocument->revert();
      m_pXMLDocument->save();
   }
   m_pXMLDocument->write("");
   reply();
   return true;
  //## end soapcommand::ATMElectronicJournalCommand::execute%5A54D8B6002B.body
}

int ATMElectronicJournalCommand::parse ()
{
  //## begin soapcommand::ATMElectronicJournalCommand::parse%5A54DB5A02E1.body preserve=yes
   return SOAPCommand::parse();
  //## end soapcommand::ATMElectronicJournalCommand::parse%5A54DB5A02E1.body
}

void ATMElectronicJournalCommand::update (Subject* pSubject)
{
  //## begin soapcommand::ATMElectronicJournalCommand::update%5A53D06F0235.body preserve=yes
   if (pSubject == m_pRow)
   {
      if (m_bDone == false
         && m_iRows < m_iMaxRows)
      {
         struct segElectronicJournalSegment* pElectronicJournalSegment = (segElectronicJournalSegment*)m_pRow->getBuffer().data();
         string strTemp(pElectronicJournalSegment->sRETRIEVAL_REF_NO,sizeof(pElectronicJournalSegment->sRETRIEVAL_REF_NO));
         trim(strTemp);
         if (((strTemp.empty() == false
            && strTemp != m_hGenericSegment.get("RETRIEVAL_REF_NO")) || m_bMatch == false)
            && memcmp(m_strStartDateTime.data(),pElectronicJournalSegment->sTSTAMP_TRANS,16) < 0)
         {
            if (memcmp(m_strEndDateTime.data(),pElectronicJournalSegment->sTSTAMP_TRANS,16) < 0)
            {
               m_bDone = true;
               return;
            }
            if (m_iRows == 0)
            {
               m_hGenericSegment.set("AcquirerTerminal",m_strAcquirerTerminal);
               m_hGenericSegment.set("VendorModel",string(pElectronicJournalSegment->sVENDOR_MODEL,sizeof(pElectronicJournalSegment->sVENDOR_MODEL)));
               m_hGenericSegment.set("EmulationModel",string(pElectronicJournalSegment->sEMULATION_MODEL,sizeof(pElectronicJournalSegment->sEMULATION_MODEL)));
               m_pXMLDocument->add("ATM");
            }
            if (m_bMatch)
            {
               if (m_iRows > 0)
               {
                  m_hGenericSegment.set("JOURNAL_TEXT",m_strJOURNAL_TEXT);
                  m_pXMLDocument->save();
                  if (!m_pXMLDocument->add("Journal"))
                  {
                     m_pXMLDocument->revert();
                     m_iRows = m_iMaxRows;
                  }
                  m_pXMLDocument->write("Journal");
               }
               m_hGenericSegment.set("RETRIEVAL_REF_NO",strTemp);
               strTemp.assign(pElectronicJournalSegment->sTSTAMP_TRANS, sizeof(pElectronicJournalSegment->sTSTAMP_TRANS));
               m_hGenericSegment.set("TSTAMP_TRANS", strTemp);
               strTemp.assign(pElectronicJournalSegment->sTSTAMP_LOCAL, sizeof(pElectronicJournalSegment->sTSTAMP_LOCAL));
               m_hGenericSegment.set("TSTAMP_LOCAL", strTemp);
               strTemp.assign(pElectronicJournalSegment->sPAN, sizeof(pElectronicJournalSegment->sPAN));
               m_hGenericSegment.set("PAN", strTemp);
               strTemp.assign(pElectronicJournalSegment->sAMT_RECON_NET, sizeof(pElectronicJournalSegment->sAMT_RECON_NET));
               trim(strTemp);
               m_hGenericSegment.set("AMT_RECON_NET", strTemp);
               strTemp.assign(pElectronicJournalSegment->sCUR_RECON_NET, sizeof(pElectronicJournalSegment->sCUR_RECON_NET));
               m_hGenericSegment.set("CUR_RECON_NET", strTemp);
               strTemp.assign(pElectronicJournalSegment->sTRAN_TYPE_ID, sizeof(pElectronicJournalSegment->sTRAN_TYPE_ID));
               m_hGenericSegment.set("TRAN_TYPE_ID", strTemp);
               m_strJOURNAL_TEXT.erase();
            }
            m_iRows++;
         }
         char szTemp[5] = {"    "};
         memcpy(szTemp,pElectronicJournalSegment->sLengthOfJOURNAL_TEXT,4);
         if (!m_strJOURNAL_TEXT.empty())
            m_strJOURNAL_TEXT.append("\\n",2);
         m_strJOURNAL_TEXT.append(pElectronicJournalSegment->sJOURNAL_TEXT,atoi(szTemp));
         if (!m_bMatch)
         {//To ensure response not excceds 64000
            m_strJOURNAL_TEXT.append("<PrimaryKey>YYYYMMDDHHMMSSHS:00000000</PrimaryKey>");
            m_hGenericSegment.set("JOURNAL_TEXT",m_strJOURNAL_TEXT);
            m_pXMLDocument->save();
            if (!m_pXMLDocument->add("Journal"))
            {
               m_strJOURNAL_TEXT.erase(m_strJOURNAL_TEXT.length() - atoi(szTemp));
               m_strPrimaryKey.assign(pElectronicJournalSegment->sTSTAMP_TRANS,sizeof(pElectronicJournalSegment->sTSTAMP_TRANS));
               m_strPrimaryKey.append(":");
               m_strPrimaryKey.append(pElectronicJournalSegment->sUNIQUENESS_KEY,sizeof(pElectronicJournalSegment->sUNIQUENESS_KEY));
               m_iRows = m_iMaxRows+1;
            }
            m_strJOURNAL_TEXT.erase(m_strJOURNAL_TEXT.length() - 50,50);
            m_pXMLDocument->revert();
         }
      }
      else
      if (m_bDone == false
         && m_iRows == m_iMaxRows)
      {
         struct segElectronicJournalSegment* pElectronicJournalSegment = (segElectronicJournalSegment*)m_pRow->getBuffer().data();
         string strTemp(pElectronicJournalSegment->sRETRIEVAL_REF_NO,sizeof(pElectronicJournalSegment->sRETRIEVAL_REF_NO));
         m_strPrimaryKey.assign(pElectronicJournalSegment->sTSTAMP_TRANS, sizeof(pElectronicJournalSegment->sTSTAMP_TRANS));
         m_strPrimaryKey.append(":");
         m_strPrimaryKey.append(pElectronicJournalSegment->sUNIQUENESS_KEY, sizeof(pElectronicJournalSegment->sUNIQUENESS_KEY));
         trim(strTemp);
         if (strTemp.empty() == false
            && strTemp == m_hGenericSegment.get("RETRIEVAL_REF_NO") && m_bMatch == true
            && memcmp(m_strStartDateTime.data(), pElectronicJournalSegment->sTSTAMP_TRANS,16) < 0)
         {
            if (memcmp(m_strEndDateTime.data(), pElectronicJournalSegment->sTSTAMP_TRANS, 16) < 0)
            {
               m_bDone = true;
               return;
            }
            char szTemp[5] = {"    "};
            memcpy(szTemp,pElectronicJournalSegment->sLengthOfJOURNAL_TEXT,4);
            if (!m_strJOURNAL_TEXT.empty())
               m_strJOURNAL_TEXT.append("\\n",2);
            m_strJOURNAL_TEXT.append(pElectronicJournalSegment->sJOURNAL_TEXT,atoi(szTemp));
         }
         else
         {
            ++m_iRows;
            return;
         }
      }
      return;
   }
   SOAPCommand::update(pSubject);
  //## end soapcommand::ATMElectronicJournalCommand::update%5A53D06F0235.body
}

// Additional Declarations
  //## begin soapcommand::ATMElectronicJournalCommand%5A53C4C70257.declarations preserve=yes
  //## end soapcommand::ATMElectronicJournalCommand%5A53C4C70257.declarations

} // namespace soapcommand

//## begin module%5A53C60B0379.epilog preserve=yes
//## end module%5A53C60B0379.epilog
