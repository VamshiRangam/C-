//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%65D57E3C0357.cm preserve=no
//## end module%65D57E3C0357.cm

//## begin module%65D57E3C0357.cp preserve=no
//	Copyright (c) 1997 - 2022
//	FIS
//## end module%65D57E3C0357.cp

//## Module: CXOSRX50%65D57E3C0357; Package body
//## Subsystem: RXDLL%5C47391001FD
//## Source file: C:\Repos\DataNavigatorServer\Windows\Build\Dn\Server\Library\Rxdll\CXOSRX50.cpp

//## begin module%65D57E3C0357.additionalIncludes preserve=no
//## end module%65D57E3C0357.additionalIncludes

//## begin module%65D57E3C0357.includes preserve=yes
#include "CXODRF64.hpp"
//## end module%65D57E3C0357.includes

#ifndef CXOSIF10_h
#include "CXODIF10.hpp"
#endif
#ifndef CXOSDB63_h
#include "CXODDB63.hpp"
#endif
#ifndef CXOSRU34_h
#include "CXODRU34.hpp"
#endif
#ifndef CXOSRX50_h
#include "CXODRX50.hpp"
#endif


//## begin module%65D57E3C0357.declarations preserve=no
//## end module%65D57E3C0357.declarations

//## begin module%65D57E3C0357.additionalDeclarations preserve=yes
namespace
{
   database::ExportFile* createNYCENetworkEDF()
   {
      return new report::NYCENetworkEDF();
   }
   const bool registered = database::ReportFactory::instance()->registerReport("NYCENetworkEDF",createNYCENetworkEDF);
}
//## end module%65D57E3C0357.additionalDeclarations


//## Modelname: Data Distribution::Report_CAT%5C473883000E
namespace report {
//## begin report%5C473883000E.initialDeclarations preserve=yes
//## end report%5C473883000E.initialDeclarations

// Class report::NYCENetworkEDF 

NYCENetworkEDF::NYCENetworkEDF()
  //## begin NYCENetworkEDF::NYCENetworkEDF%65D57DD40100_const.hasinit preserve=no
  //## end NYCENetworkEDF::NYCENetworkEDF%65D57DD40100_const.hasinit
  //## begin NYCENetworkEDF::NYCENetworkEDF%65D57DD40100_const.initialization preserve=yes
  //## end NYCENetworkEDF::NYCENetworkEDF%65D57DD40100_const.initialization
{
  //## begin report::NYCENetworkEDF::NYCENetworkEDF%65D57DD40100_const.body preserve=yes
   memcpy(m_sID,"RX50",4);
   setDX_FILE_TYPE("NYCNDF");
  //## end report::NYCENetworkEDF::NYCENetworkEDF%65D57DD40100_const.body
}


NYCENetworkEDF::~NYCENetworkEDF()
{
  //## begin report::NYCENetworkEDF::~NYCENetworkEDF%65D57DD40100_dest.body preserve=yes
  //## end report::NYCENetworkEDF::~NYCENetworkEDF%65D57DD40100_dest.body
}



//## Other Operations (implementation)
bool NYCENetworkEDF::distribute (string& strDATA_BUFFER, IF::FlatFile& hFlatFile)
{
  //## begin report::NYCENetworkEDF::distribute%65D7BE400172.body preserve=yes
   vector<string> hTokens;
   Buffer::parse(strDATA_BUFFER,",",hTokens);
   char sDATA_BUFFER[sizeof(struct hEDF1)];
   struct hEDF1* pEDF1 = (struct hEDF1*)sDATA_BUFFER;
   memset(sDATA_BUFFER,' ',sizeof(struct hEDF1));
   pEDF1->cRecordPart = '1';
   memcpy(pEDF1->sMTI,"0200",sizeof(pEDF1->sMTI));
   memcpy(pEDF1->sIssuerICHAmount,"0018900",sizeof(pEDF1->sIssuerICHAmount));
   pEDF1->cROLE_IND = 'I';
   memcpy(pEDF1->sPAN,hTokens[PAN].data(),min(sizeof(pEDF1->sPAN),hTokens[PAN].length()));
   memset(pEDF1->sPAN + 6,'9',6);
   memcpy(pEDF1->sRETRIEVAL_REF_NO,hTokens[RETRIEVAL_REF_NO].data(),min(sizeof(pEDF1->sRETRIEVAL_REF_NO),hTokens[RETRIEVAL_REF_NO].length()));
   memcpy(pEDF1->sSurchargeRebateAmount,hTokens[F_AMTcb].data() + 3,7);
   memcpy(pEDF1->sTerminalTime,hTokens[TSTAMP_LOCAL].data() + 8,sizeof(pEDF1->sTerminalTime));
   memcpy(pEDF1->sTerminalDate,hTokens[TSTAMP_LOCAL].data() + 4,sizeof(pEDF1->sTerminalDate));
   memcpy(pEDF1->sCARD_ACPT_TERM_ID,hTokens[CARD_ACPT_TERM_ID].data(),min(sizeof(pEDF1->sCARD_ACPT_TERM_ID),hTokens[CARD_ACPT_TERM_ID].length()));
   memcpy(pEDF1->sSettleCurrencyCode,hTokens[CUR_RECON_NET].data(),min(sizeof(pEDF1->sSettleCurrencyCode),hTokens[CUR_RECON_NET].length()));
   if (hTokens[TRAN_DISPOSITION] == "2")
      pEDF1->cResponseCode = 'D';
   else
   if (hTokens[TRAN_DISPOSITION] == "3")
      pEDF1->cResponseCode = 'F';
   else
      pEDF1->cResponseCode = 'A';
   double dF_AMTcb = atof(hTokens[F_AMTcb].c_str());
   double dAMT_RECON_NET = atof(hTokens[AMT_RECON_NET].c_str()) + dF_AMTcb;
   snprintf(pEDF1->sAMT_RECON_NET,sizeof(pEDF1->sAMT_RECON_NET) + 1,"%013.0f",dAMT_RECON_NET);
   pEDF1->cAmountSign = ' ';
   if (hTokens[TRAN_TYPE_ID] == "01")
      memcpy(pEDF1->sTRAN_TYPE_ID,"77",2);
   else
   if (hTokens[TRAN_TYPE_ID] == "50")
      memcpy(pEDF1->sTRAN_TYPE_ID,"74",2);
   else
   if (hTokens[TRAN_TYPE_ID] == "20")
      memcpy(pEDF1->sTRAN_TYPE_ID,"80",2);
   else
      memcpy(pEDF1->sTRAN_TYPE_ID,"79",2);
   strDATA_BUFFER.assign(sDATA_BUFFER,sizeof(struct hEDF1));
   return ExportFile::distribute(strDATA_BUFFER,hFlatFile);
  //## end report::NYCENetworkEDF::distribute%65D7BE400172.body
}

bool NYCENetworkEDF::finish (IF::FlatFile& hFlatFile)
{
  //## begin report::NYCENetworkEDF::finish%65D7BE5100E8.body preserve=yes
   char sDATA_BUFFER[sizeof(struct hEDF9)];
   struct hEDF9* pEDF9 = (struct hEDF9*)sDATA_BUFFER;
   memset(sDATA_BUFFER,'0',sizeof(struct hEDF9));
   pEDF9->cRecordPart = '9';
   string strDATA_BUFFER(sDATA_BUFFER,sizeof(struct hEDF9));
   return ExportFile::distribute(strDATA_BUFFER,hFlatFile);
  //## end report::NYCENetworkEDF::finish%65D7BE5100E8.body
}

bool NYCENetworkEDF::start (IF::FlatFile& hFlatFile)
{
  //## begin report::NYCENetworkEDF::start%65D7BE540224.body preserve=yes
   char sDATA_BUFFER[sizeof(struct hEDF0)];
   struct hEDF0* pEDF0 = (struct hEDF0*)sDATA_BUFFER;
   memset(sDATA_BUFFER,' ',sizeof(struct hEDF0));
   pEDF0->cRecordPart = '0';
   pEDF0->cFormatCode = 'Y';
   memcpy(pEDF0->sDATE_RECON_NET,getDATE_RECON().data(),8);
   string strDATA_BUFFER(sDATA_BUFFER,sizeof(struct hEDF0));
   return ExportFile::distribute(strDATA_BUFFER,hFlatFile);
  //## end report::NYCENetworkEDF::start%65D7BE540224.body
}

// Additional Declarations
  //## begin report::NYCENetworkEDF%65D57DD40100.declarations preserve=yes
  //## end report::NYCENetworkEDF%65D57DD40100.declarations

} // namespace report

//## begin module%65D57E3C0357.epilog preserve=yes
//## end module%65D57E3C0357.epilog
