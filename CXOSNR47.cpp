//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%605D32D10055.cm preserve=no
//	$Date:   Sep 03 2013 11:31:44  $ $Author:   e1009839  $
//	$Revision:   1.27  $
//## end module%605D32D10055.cm

//## begin module%605D32D10055.cp preserve=no
//	Copyright (c) 1997 - 2012
//	FIS
//## end module%605D32D10055.cp

//## Module: CXOSNR47%605D32D10055; Package body
//## Subsystem: NRDLL%5637980B0094
//## Source file: C:\Repos\DataNavigatorServer\Windows\Build\Dn\Server\Library\Nrdll\CXOSNR47.cpp

//## begin module%605D32D10055.additionalIncludes preserve=no
//## end module%605D32D10055.additionalIncludes

//## begin module%605D32D10055.includes preserve=yes
#include "CXODTM06.hpp"
//## end module%605D32D10055.includes

#ifndef CXOSDB01_h
#include "CXODDB01.hpp"
#endif
#ifndef CXOSTM04_h
#include "CXODTM04.hpp"
#endif
#ifndef CXOSNR12_h
#include "CXODNR12.hpp"
#endif
#ifndef CXOSRU10_h
#include "CXODRU10.hpp"
#endif
#ifndef CXOSCF01_h
#include "CXODCF01.hpp"
#endif
#ifndef CXOSCF61_h
#include "CXODCF61.hpp"
#endif
#ifndef CXOSNS40_h
#include "CXODNS40.hpp"
#endif
#ifndef CXOSDB02_h
#include "CXODDB02.hpp"
#endif
#ifndef CXOSRU08_h
#include "CXODRU08.hpp"
#endif
#ifndef CXOSDB25_h
#include "CXODDB25.hpp"
#endif
#ifndef CXOSNR34_h
#include "CXODNR34.hpp"
#endif
#ifndef CXOSNR36_h
#include "CXODNR36.hpp"
#endif
#ifndef CXOSNR47_h
#include "CXODNR47.hpp"
#endif


//## begin module%605D32D10055.declarations preserve=no
#ifndef CXOSRF66_h
#include "CXODRF66.hpp"
#endif
//## end module%605D32D10055.declarations

//## begin module%605D32D10055.additionalDeclarations preserve=yes
//## end module%605D32D10055.additionalDeclarations


//## Modelname: Reconciliation::NetworkReconciliation_CAT%5637978002B1
namespace networkreconciliation {
//## begin networkreconciliation%5637978002B1.initialDeclarations preserve=yes
//## end networkreconciliation%5637978002B1.initialDeclarations

// Class networkreconciliation::AmericanExpressGRRCN

AmericanExpressGRRCN::AmericanExpressGRRCN()
  //## begin AmericanExpressGRRCN::AmericanExpressGRRCN%605D2E81033B_const.hasinit preserve=no
  //## end AmericanExpressGRRCN::AmericanExpressGRRCN%605D2E81033B_const.hasinit
  //## begin AmericanExpressGRRCN::AmericanExpressGRRCN%605D2E81033B_const.initialization preserve=yes
  //## end AmericanExpressGRRCN::AmericanExpressGRRCN%605D2E81033B_const.initialization
{
  //## begin networkreconciliation::AmericanExpressGRRCN::AmericanExpressGRRCN%605D2E81033B_const.body preserve=yes
   memcpy(m_sID,"NR47",4);
   m_strENTITY_ROLE.assign("A",1);
   m_strREPORT_NAME.assign("GRRCN",5);
   m_strREPORT_SOURCE.assign("N",1);
   m_strNETWORK_ID.assign("AMX",3);
   m_strCUR_RECON_NET = entitysegment::Customer::instance()->getCUST_CURRENCY_CODE();
   m_strUSER_ID.assign("SYSTEM",6);
   m_strTSTAMP_CREATED = Transaction::instance()->getTimeStamp();
   m_strDATE_RECON_ACQ = entitysegment::SwitchBusinessDay::instance()->getDATE_RECON(0);
   m_strDATE_RECON_ISS = m_strDATE_RECON_ACQ;
   string strTemp;
   for (int i = 0;i <= 1;++i)
      m_hFROM_VALUE.push_back(strTemp);
  //## end networkreconciliation::AmericanExpressGRRCN::AmericanExpressGRRCN%605D2E81033B_const.body
}


AmericanExpressGRRCN::~AmericanExpressGRRCN()
{
  //## begin networkreconciliation::AmericanExpressGRRCN::~AmericanExpressGRRCN%605D2E81033B_dest.body preserve=yes
   set<string>::iterator p;
   for (p = m_hCreditReport.begin();p != m_hCreditReport.end();++p)
   {
      {
      ExportFile hExportFile("BALAMX","AP",(*p),getDATE_RECON_ISS(),"240000");
      hExportFile.setDX_STATE("FW");
      hExportFile.setTSTAMP_INITIATED(Clock::instance()->getYYYYMMDDHHMMSSHN());
      if (!hExportFile.trigger())
         Database::instance()->setTransactionState(Database::ROLLBACKREQUIRED);
      }
      {
      ExportFile hExportFile("RCNAMX","AP",(*p),getDATE_RECON_ISS(),"240000");
      hExportFile.setDX_STATE("FW");
      hExportFile.setTSTAMP_INITIATED(Clock::instance()->getYYYYMMDDHHMMSSHN());
      if (!hExportFile.trigger())
         Database::instance()->setTransactionState(Database::ROLLBACKREQUIRED);
      }
      {
      ExportFile hExportFile("INTAMX","AP",(*p),getDATE_RECON_ISS(),"240000");
      hExportFile.setDX_STATE("FW");
      hExportFile.setTSTAMP_INITIATED(Clock::instance()->getYYYYMMDDHHMMSSHN());
      if (!hExportFile.trigger())
         Database::instance()->setTransactionState(Database::ROLLBACKREQUIRED);
      }
      {
      ExportFile hExportFile("IPAAMX","AP",(*p),getDATE_RECON_ISS(),"240000");
      hExportFile.setDX_STATE("FW");
      hExportFile.setTSTAMP_INITIATED(Clock::instance()->getYYYYMMDDHHMMSSHN());
      if (!hExportFile.trigger())
         Database::instance()->setTransactionState(Database::ROLLBACKREQUIRED);
      }
      {
      ExportFile hExportFile("FEEAMX","AP",(*p),getDATE_RECON_ISS(),"240000");
      hExportFile.setDX_STATE("FW");
      hExportFile.setTSTAMP_INITIATED(Clock::instance()->getYYYYMMDDHHMMSSHN());
      if (!hExportFile.trigger())
         Database::instance()->setTransactionState(Database::ROLLBACKREQUIRED);
      }
      {
      ExportFile hExportFile("DSPAMX","AP",(*p),getDATE_RECON_ISS(),"240000");
      hExportFile.setDX_STATE("FW");
      hExportFile.setTSTAMP_INITIATED(Clock::instance()->getYYYYMMDDHHMMSSHN());
      if (!hExportFile.trigger())
         Database::instance()->setTransactionState(Database::ROLLBACKREQUIRED);
      }
   }
  //## end networkreconciliation::AmericanExpressGRRCN::~AmericanExpressGRRCN%605D2E81033B_dest.body
}



//## Other Operations (implementation)
bool AmericanExpressGRRCN::scrape (const char* sBuffer, int iRecordLength)
{
  //## begin networkreconciliation::AmericanExpressGRRCN::scrape%605D2EB100C6.body preserve=yes
   {
      if (memcmp(sBuffer, "HEADER", 6) == 0)
      {
         struct hHeaderRecord* p = (struct hHeaderRecord*)sBuffer;
         m_strREPORT_DATE.assign(p->sDate, 8);
         Date hDate(m_strREPORT_DATE.c_str());
         hDate -= 1;
         m_strDATE_RECON_ISS = hDate.asString("%Y%m%d");
         m_strDATE_RECON_ACQ = m_strDATE_RECON_ISS;
         return true;
      }
      if (memcmp(sBuffer, "SUMMARY", 7) == 0)
      {
         struct hSummaryRecord* p = (struct hSummaryRecord*)sBuffer;
         m_strNET_INST_ID_CODE.assign(p->sPayeeMerchantId,11);
         if (NetworkInstitution::getINST_ID("AMX", m_strNET_INST_ID_CODE, "", "", "", m_strINST_ID))
         {
            ConfigurationRepository::instance()->translate("INSTITUTION", m_strINST_ID, m_strPROC_ID, "", "", -1, false);
            m_hCreditReport.insert(m_strPROC_ID);
         }
         else
            return false;
         return true;
      }
      if (memcmp(sBuffer, "TRANSACTN", 9) == 0)
      {
         struct hTransactionRecord* p = (struct hTransactionRecord*)sBuffer;
         m_strFUNC_CODE.assign("200", 3);
         m_strTOTAL_TYPE.assign("TRAN", 4);
         m_strNETWORK_PROGRAM.erase();
         m_strTRAN_DISPOSITION = (memcmp(p->sTranRejectedInd,"REJ",3) == 0) ? "2" : "1";
         m_strTRAN_DISPOSITION.assign("1", 1);
         m_iTRAN_COUNT = 1;
         m_dAMT_RECON_NET = asDouble(p->sROCAmount, 16);
         if (m_dAMT_RECON_NET < 0)
         {
            m_dAMT_RECON_NET = 0 - m_dAMT_RECON_NET;
            m_iROW_NUMBER = 111;
            m_strTRAN_GROUP.assign("RTRN", 4);
            m_strIMPACT_TO_ACQ.assign("1", 1);
         }
         else
         {
            m_iROW_NUMBER = 101;
            m_strTRAN_GROUP.assign("PRCH", 4);
            m_strIMPACT_TO_ACQ.assign("2", 1);
         }
         m_strIMPACT_TO_ISS = (m_strIMPACT_TO_ACQ == "1") ? "2" : "1";
         if (m_dAMT_RECON_NET != 0)
            NetworkSegment::insert();
         m_strPAN.assign(p->sPAN, 19);
         return true;
      }
      if (memcmp(sBuffer, "TXNPRICING", 10) == 0)
      {
         struct hTransactionPricingRecord* p = (struct hTransactionPricingRecord*)sBuffer;
         m_hFROM_VALUE[0].assign(p->sFeeCode, 2);
         m_hFROM_VALUE[1].assign("D", 1);
         string strTO_VALUE;
         if (memcmp(p->sRoundedDiscountAmount + 1,"000000000000000",15) != 0
            && TotalType::instance()->translate("AMEXTILR", m_hFROM_VALUE, strTO_VALUE))
         {
            NetworkFee* f = NetworkFee::instance();
            f->reset();
            m_iROW_NUMBER = atoi(strTO_VALUE.data(), 3);
            m_strTRAN_GROUP.assign(strTO_VALUE.data() + 3, 4);
            m_strFUNC_CODE.assign(strTO_VALUE.data() + 7, 3);
            m_strTOTAL_TYPE.assign(strTO_VALUE.data() + 10, 4);
            m_strIMPACT_TO_ACQ.assign(strTO_VALUE.data() + 14, 1);
            m_strIMPACT_TO_ISS = (m_strIMPACT_TO_ACQ == "1") ? "2" : "1";
            m_strNETWORK_PROGRAM.assign(p->sFeeCode, 2);
            m_dAMT_RECON_NET = asDouble(p->sRoundedDiscountAmount + 1, 15);
            if (p->sDiscountAmount[0] == '-')
            {
               m_dAMT_RECON_NET = 0 - m_dAMT_RECON_NET;
               f->setIMPACT_TO_ACQ(string("2"));
            }
            NetworkSegment::insert();
            if (m_iROW_NUMBER == 511)
            {
               f->setDATE_RECON(entitysegment::SwitchBusinessDay::instance()->getDATE_RECON(0));
               f->setPROC_ID(m_strPROC_ID);
               f->setNETWORK_ID("AMX");
               f->setPAN(m_strPAN);
               f->setSEQ_NO(f->getSEQ_NO() + 1);
               f->setIMPACT_TO_ACQ(string("1"));
               f->setAMT_RECON_NET(m_dAMT_RECON_NET);
               f->setCUR_RECON_NET(entitysegment::Customer::instance()->getCUST_CURRENCY_CODE());
               string strFEE_TYPE(p->sFeeCode, 2);
               f->setFEE_TYPE(strFEE_TYPE);
               string strFEE_DESCRIPTION;
               if (ConfigurationRepository::instance()->translate("AMEX_FEE_CODE", strFEE_TYPE, strFEE_DESCRIPTION, "", "", -1, false))
                  f->setFEE_DESCRIPTION(strFEE_DESCRIPTION);
               else
                  f->setFEE_DESCRIPTION(strFEE_TYPE);
               Table hTable("NETWORK_FEE");
               f->setColumns(hTable);
               auto_ptr<Statement> pInsertStatement((Statement*)DatabaseFactory::instance()->create("InsertStatement"));
               pInsertStatement->execute(hTable);
            }
         }
         m_hFROM_VALUE[1].assign("F", 1);
         if (memcmp(p->sRoundedFeeAmount + 1,"000000000000000",15) != 0
            && TotalType::instance()->translate("AMEXTILR", m_hFROM_VALUE, strTO_VALUE))
         {
            NetworkFee* f = NetworkFee::instance();
            f->reset();
            m_iROW_NUMBER = atoi(strTO_VALUE.data(), 3);
            m_strTRAN_GROUP.assign(strTO_VALUE.data() + 3, 4);
            m_strFUNC_CODE.assign(strTO_VALUE.data() + 7, 3);
            m_strTOTAL_TYPE.assign(strTO_VALUE.data() + 10, 4);
            m_strIMPACT_TO_ACQ.assign(strTO_VALUE.data() + 14, 1);
            m_strIMPACT_TO_ISS = (m_strIMPACT_TO_ACQ == "1") ? "2" : "1";
            m_strNETWORK_PROGRAM.assign(p->sFeeCode, 2);
            m_dAMT_RECON_NET = asDouble(p->sRoundedFeeAmount + 1, 15);
            if (p->sFeeAmount[0] == '-')
            {
               m_dAMT_RECON_NET = 0 - m_dAMT_RECON_NET;
               f->setIMPACT_TO_ACQ(string("2"));
            }
            NetworkSegment::insert();
            if (m_iROW_NUMBER == 511)
            {
               f->setDATE_RECON(entitysegment::SwitchBusinessDay::instance()->getDATE_RECON(0));
               f->setPROC_ID(m_strPROC_ID);
               f->setNETWORK_ID("AMX");
               f->setPAN(m_strPAN);
               f->setSEQ_NO(f->getSEQ_NO() + 1);
               f->setIMPACT_TO_ACQ(string("1"));
               f->setAMT_RECON_NET(m_dAMT_RECON_NET);
               f->setCUR_RECON_NET(entitysegment::Customer::instance()->getCUST_CURRENCY_CODE());
               string strFEE_TYPE(p->sFeeCode, 2);
               f->setFEE_TYPE(strFEE_TYPE);
               string strFEE_DESCRIPTION;
               if (ConfigurationRepository::instance()->translate("AMEX_FEE_CODE", strFEE_TYPE, strFEE_DESCRIPTION, "", "", -1, false))
                  f->setFEE_DESCRIPTION(strFEE_DESCRIPTION);
               else
                  f->setFEE_DESCRIPTION(strFEE_TYPE);
               Table hTable("NETWORK_FEE");
               f->setColumns(hTable);
               auto_ptr<Statement> pInsertStatement((Statement*)DatabaseFactory::instance()->create("InsertStatement"));
               pInsertStatement->execute(hTable);
            }
         }
         return true;
      }
      if (memcmp(sBuffer, "CHARGEBACK", 10) == 0)
      {
         struct hChargebackRecord* p = (struct hChargebackRecord*)sBuffer;
         m_iROW_NUMBER = 699;
         m_strTRAN_GROUP.assign("PRCH", 4);
         m_strFUNC_CODE.assign("200", 3);
         m_strTOTAL_TYPE.assign("TRAN", 4);
         m_strNETWORK_PROGRAM.erase();
         m_iTRAN_COUNT = 1;
         m_strTRAN_DISPOSITION.assign("2", 1);
         m_dAMT_RECON_NET = asDouble(p->sChargebackAmount, 16);
         if (m_dAMT_RECON_NET < 0)
         {
            m_dAMT_RECON_NET = 0 - m_dAMT_RECON_NET;
            m_strIMPACT_TO_ACQ.assign("1", 1);
         }
         else
            m_strIMPACT_TO_ACQ.assign("2", 1);
         m_strIMPACT_TO_ISS = (m_strIMPACT_TO_ACQ == "1") ? "2" : "1";
         if (m_dAMT_RECON_NET != 0)
            NetworkSegment::insert();
         NetworkDispute* d = NetworkDispute::instance();
         d->reset();
         d->setDATE_RECON(entitysegment::SwitchBusinessDay::instance()->getDATE_RECON(0));
         d->setNETWORK_ID("AMX");
         d->setCARD_ACPT_ID(string(p->sSellerID, 20));
         d->setPROC_ID(m_strPROC_ID);
         d->setMTI("1210");
         d->setFUNCTION_CODE("200");
         d->setSEQ_NO(d->getSEQ_NO() + 1);
         d->setIMPACT_TO_ACQ(m_strIMPACT_TO_ACQ);
         d->setAMT_RECON_NET(m_dAMT_RECON_NET);
         d->setCUR_RECON_NET(entitysegment::Customer::instance()->getCUST_CURRENCY_CODE());
         d->setTRAN_DISPOSITION(m_strTRAN_DISPOSITION);
         d->setDESCRIPTION(string(p->sChargebackReason, 280));
         Table hTable("NETWORK_DISPUTE");
         d->setColumns(hTable);
         auto_ptr<Statement> pInsertStatement((Statement*)DatabaseFactory::instance()->create("InsertStatement"));
         pInsertStatement->execute(hTable);
         return true;
      }
      if (memcmp(sBuffer,"ADJUSTMENT",10)==0)
      {
         struct hAdjustmentRecord* p = (struct hAdjustmentRecord*)sBuffer;
         m_strTRAN_GROUP.assign("PRCH", 4);
         m_strFUNC_CODE.assign("450", 3);
         m_strTOTAL_TYPE.assign("CASE", 4);
         m_strNETWORK_PROGRAM.erase();
         m_iTRAN_COUNT = 1;
         m_strTRAN_GROUP.erase();
         m_strTOTAL_TYPE.erase();
         m_strNETWORK_PROGRAM.erase();
         m_dAMT_RECON_NET = asDouble(p->sAdjustmentAmount, 16);
         if (m_dAMT_RECON_NET < 0)
         {
            m_dAMT_RECON_NET = 0 - m_dAMT_RECON_NET;
            m_iROW_NUMBER = 401;
            m_strTRAN_DISPOSITION.assign("1", 1);
            m_strIMPACT_TO_ACQ.assign("1", 1);
         }
         else
         {
            m_iROW_NUMBER = 402;
            m_strTRAN_DISPOSITION.assign("3", 1);
            m_strIMPACT_TO_ACQ.assign("2", 1);
         }
         m_strIMPACT_TO_ISS = (m_strIMPACT_TO_ACQ == "1") ? "2" : "1";
         if (m_dAMT_RECON_NET != 0)
            NetworkSegment::insert();
         NetworkDispute* d = NetworkDispute::instance();
         d->reset();
         d->setDATE_RECON(entitysegment::SwitchBusinessDay::instance()->getDATE_RECON(0));
         d->setPROC_ID(m_strPROC_ID);
         d->setNETWORK_ID("AMX");
         d->setFUNCTION_CODE("450");
         d->setACT_CODE("400");
         d->setMTI("1442");
         d->setSEQ_NO(d->getSEQ_NO() + 1);
         d->setPAN(string(p->sCardMemberNumber, 19));
         d->setIMPACT_TO_ACQ(m_strIMPACT_TO_ACQ);
         d->setTRAN_DISPOSITION(m_strTRAN_DISPOSITION);
         d->setAMT_RECON_NET(m_dAMT_RECON_NET);
         d->setCUR_RECON_NET(entitysegment::Customer::instance()->getCUST_CURRENCY_CODE());
         d->setDESCRIPTION(string(p->sAdjustmentReason, 280));
         d->setCARD_ACPT_ID(string(p->sSellerID, 20));
         Table hTable("NETWORK_DISPUTE");
         d->setColumns(hTable);
         auto_ptr<Statement> pInsertStatement((Statement*)DatabaseFactory::instance()->create("InsertStatement"));
         pInsertStatement->execute(hTable);
         m_dAMT_RECON_NET = asDouble(p->sDiscountAmount, 16);
         if (m_dAMT_RECON_NET > 0)
         {
            m_iROW_NUMBER = 511;
            m_strIMPACT_TO_ACQ.assign("1", 1);
         }
         else
         {
            m_dAMT_RECON_NET = 0 - m_dAMT_RECON_NET;
            m_iROW_NUMBER = 511;
            m_strIMPACT_TO_ACQ.assign("2", 1);
         }
         m_strIMPACT_TO_ISS = (m_strIMPACT_TO_ACQ == "1") ? "2" : "1";
         if (m_dAMT_RECON_NET != 0)
            NetworkSegment::insert();
         m_dAMT_RECON_NET = asDouble(p->sFeeAmount, 16);
         if (m_dAMT_RECON_NET > 0)
         {
            m_iROW_NUMBER = 511;
            m_strIMPACT_TO_ACQ.assign("1", 1);
         }
         else
         {
            m_dAMT_RECON_NET = 0 - m_dAMT_RECON_NET;
            m_iROW_NUMBER = 511;
            m_strIMPACT_TO_ACQ.assign("2", 1);
         }
         m_strIMPACT_TO_ISS = (m_strIMPACT_TO_ACQ == "1") ? "2" : "1";
         if (m_dAMT_RECON_NET != 0)
            NetworkSegment::insert();
         return true;
      }
      if (memcmp(sBuffer, "FEEREVENUE", 10) == 0)
      {
         struct hFeesAndRevenuesRecord* p = (struct hFeesAndRevenuesRecord*)sBuffer;
         m_iROW_NUMBER = 501;
         m_strTRAN_GROUP.erase();
         m_strFUNC_CODE.assign("700", 3);
         m_strTOTAL_TYPE.erase();
         m_strNETWORK_PROGRAM.erase();
         m_strIMPACT_TO_ACQ.assign("2", 1);
         m_dAMT_RECON_NET = asDouble(p->sOtherFeeAmount, 16);
         if (m_dAMT_RECON_NET < 0)
         {
            m_dAMT_RECON_NET = 0 - m_dAMT_RECON_NET;
            m_strIMPACT_TO_ACQ.assign("1", 1);
         }
         m_strIMPACT_TO_ISS = (m_strIMPACT_TO_ACQ == "1") ? "2" : "1";
         NetworkSegment::insert();
         NetworkFee* f = NetworkFee::instance();
         f->reset();
         f->setDATE_RECON(entitysegment::SwitchBusinessDay::instance()->getDATE_RECON(0));
         f->setPROC_ID(m_strPROC_ID);
         f->setNETWORK_ID("AMX");
         f->setSEQ_NO(f->getSEQ_NO() + 1);
         f->setIMPACT_TO_ACQ(m_strIMPACT_TO_ACQ);
         f->setAMT_RECON_NET(m_dAMT_RECON_NET);
         f->setCUR_RECON_NET(entitysegment::Customer::instance()->getCUST_CURRENCY_CODE());
         f->setFEE_TYPE("OTHER");
         f->setFEE_DESCRIPTION(string(p->sOtherFeeDescription, 80));
         f->setCARD_ACPT_ID(string(p->sSellerID, 20));
         Table hTable("NETWORK_FEE");
         f->setColumns(hTable);
         auto_ptr<Statement> pInsertStatement((Statement*)DatabaseFactory::instance()->create("InsertStatement"));
         pInsertStatement->execute(hTable);
         return true;
      }
   }
   return true;
  //## end networkreconciliation::AmericanExpressGRRCN::scrape%605D2EB100C6.body
}

// Additional Declarations

  //## begin networkreconciliation::AmericanExpressGRRCN%605D2E81033B.declarations preserve=yes
  //## end networkreconciliation::AmericanExpressGRRCN%605D2E81033B.declarations

} // namespace networkreconciliation

//## begin module%605D32D10055.epilog preserve=yes
//## end module%605D32D10055.epilog
