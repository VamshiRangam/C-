//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%607F23C702E1.cm preserve=no
//## end module%607F23C702E1.cm

//## begin module%607F23C702E1.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%607F23C702E1.cp

//## Module: CXOSRF74%607F23C702E1; Package body
//## Subsystem: RFDLL%439873F400EA
//## Source file: C:\Repos\DataNavigatorServer\Windows\Build\Dn\Server\Library\Rfdll\CXOSRF74.cpp

//## begin module%607F23C702E1.additionalIncludes preserve=no
//## end module%607F23C702E1.additionalIncludes

//## begin module%607F23C702E1.includes preserve=yes
#include "CXODRF66.hpp"
#include "CXODRS58.hpp"
#include "CXODRU37.hpp"
//## end module%607F23C702E1.includes

#ifndef CXOSIF05_h
#include "CXODIF05.hpp"
#endif 
#ifndef CXOSRS78_h
#include "CXODRS78.hpp"
#endif
#ifndef CXOSMN05_h
#include "CXODMN05.hpp"
#endif
#ifndef CXOSRF48_h
#include "CXODRF48.hpp"
#endif
#ifndef CXOSTM04_h
#include "CXODTM04.hpp"
#endif
#ifndef CXOSIF28_h
#include "CXODIF28.hpp"
#endif
#ifndef CXOSTM06_h
#include "CXODTM06.hpp"
#endif
#ifndef CXOSRF74_h
#include "CXODRF74.hpp"
#endif


//## begin module%607F23C702E1.declarations preserve=no
//## end module%607F23C702E1.declarations

//## begin module%607F23C702E1.additionalDeclarations preserve=yes
//## end module%607F23C702E1.additionalDeclarations


//## Modelname: Reconciliation::ReconciliationFile_CAT%439754C1037A
namespace reconciliationfile {
//## begin reconciliationfile%439754C1037A.initialDeclarations preserve=yes
//## end reconciliationfile%439754C1037A.initialDeclarations

// Class reconciliationfile::AmericanExpressGRRCN 

AmericanExpressGRRCN::AmericanExpressGRRCN()
  //## begin AmericanExpressGRRCN::AmericanExpressGRRCN%607F231003E5_const.hasinit preserve=no
  //## end AmericanExpressGRRCN::AmericanExpressGRRCN%607F231003E5_const.hasinit
  //## begin AmericanExpressGRRCN::AmericanExpressGRRCN%607F231003E5_const.initialization preserve=yes
  //## end AmericanExpressGRRCN::AmericanExpressGRRCN%607F231003E5_const.initialization
{
  //## begin reconciliationfile::AmericanExpressGRRCN::AmericanExpressGRRCN%607F231003E5_const.body preserve=yes
   memcpy(m_sID,"RF74",4);
   setClassName("AMXTLR");
   m_hFile.setMatch("PAN_PREFIX");
   m_hFile.setMatch("ACQ_REF_NO");
   m_hFile.setMatch("TRAN_DISPOSITION");
   m_hFile.setMatch("AMT_RECON_NET");
   ReconciliationDataset::setMatch();
   // external file (from American Express GRRCN)
   setColumns("MASKPAN"
      ",ACQ_REF_NO~32"
      ",TRAN_DISPOSITION"
      ",AMT_RECON_NET"
      ",TSTAMP_TRANS"
      ",UNIQUENESS_KEY~5"
      ",TRAN_TYPE_ID"
      ",CUR_RECON_NET",0
   );
   // internal file (custom TXNACT 6074)
   setColumns("MASKPAN"
      ",ACQ_REF_NO~32"
      ",TRAN_DISPOSITION"
      ",AMT_RECON_NET"
      ",TSTAMP_TRANS"
      ",UNIQUENESS_KEY~5"
      ",TRAN_TYPE_ID"
      ",CUR_RECON_NET"
      ",RETRIEVAL_REF_NO"
      ",TSTAMP_LOCAL"
      ",CARD_ACPT_TERM_ID"
      ",PROC_ID_ACQ_B"
      ",PROC_ID_ISS_B"
      ",ROLE_IND",1
   );
  //## end reconciliationfile::AmericanExpressGRRCN::AmericanExpressGRRCN%607F231003E5_const.body
}


AmericanExpressGRRCN::~AmericanExpressGRRCN()
{
  //## begin reconciliationfile::AmericanExpressGRRCN::~AmericanExpressGRRCN%607F231003E5_dest.body preserve=yes
  //## end reconciliationfile::AmericanExpressGRRCN::~AmericanExpressGRRCN%607F231003E5_dest.body
}



//## Other Operations (implementation)
bool AmericanExpressGRRCN::reFormat ()
{
  //## begin reconciliationfile::AmericanExpressGRRCN::reFormat%607F236E0066.body preserve=yes
   if (!TransactionActivityFile::initReFormat())
      return false;
   NetworkSegment x;
   char szTemp[PERCENTF];
   bool bSplit = false;
   while (m_pGenerationDataGroup->read(m_pBuffer,1024,&m_lBufferLength))
   {
      if (memcmp(m_pBuffer,"FH      ",8) == 0)
      {
         m_strDATE_RECON.assign(m_pBuffer + 8,8);
         continue;
      }
      if (m_pBuffer[28] == ',')
         bSplit = true;
      if (bSplit)
      {
         write(m_pBuffer,m_lBufferLength);
         continue;
      }
      if (memcmp(m_pBuffer,"HEADER    ",10) == 0)
      {
         struct hHeaderRecord* p = (struct hHeaderRecord*)m_pBuffer;
         Date hDate(p->sDate);
         hDate -= 1;
         m_strDATE_RECON = hDate.asString("%Y%m%d");
      }
      if (memcmp(m_pBuffer,"TRANSACTN ",10) == 0)
      {
         struct hTransactionRecord* p = (struct hTransactionRecord*)m_pBuffer;
         double d = x.asDouble(p->sROCAmount,16);
         if (d < 0)
         {
            setColumn(TRAN_TYPE_ID,"2000002000",10);
            d = 0 - d;
         }
         else
            setColumn(TRAN_TYPE_ID,"0000002000",10);
         setColumn(AMT_RECON_NET,szTemp,sprintf(szTemp,"%018.0f",d));
         int j = memcmp(p->sPAN + 16,"000",3) == 0 || memcmp(p->sPAN + 16,"   ",3) == 0 ? 16 : 19;
         Mask::maskPan(p->sPAN,j,6);
         setColumn(PAN,p->sPAN,19);
         setColumn(ACQ_REF_NO,p->sInvoiceReferenceNumber,23);
         setColumn(TRAN_DISPOSITION,(memcmp(p->sTranRejectedInd,"REJ",3) == 0) ? "2" : "1",1);
         setColumn(CUR_RECON_NET,"840",3);
         if (!TransactionReportFile::write())
            return UseCase::setSuccess(false);
      }
   }
   return TransactionActivityFile::reFormat();
  //## end reconciliationfile::AmericanExpressGRRCN::reFormat%607F236E0066.body
}

// Additional Declarations
  //## begin reconciliationfile::AmericanExpressGRRCN%607F231003E5.declarations preserve=yes
  //## end reconciliationfile::AmericanExpressGRRCN%607F231003E5.declarations

} // namespace reconciliationfile

//## begin module%607F23C702E1.epilog preserve=yes
//## end module%607F23C702E1.epilog
