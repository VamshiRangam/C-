bool NYCEExport::setDOC_PATH()
{
   //## begin nyceexception::NYCEExport::setDOC_PATH%65D201B70161.body preserve=yes
   Query hQuery;
   short iSEQ_NO = 0;
   short iNull = -1;
   Query hSubQuery;
   string m_strFILE_NAME;
   hSubQuery.setSubSelect(true);
   hSubQuery.bind("EMS_DOCUMENT", "SEQ_NO", Column::SHORT, &iSEQ_NO, &iNull, "MAX");
   hSubQuery.setBasicPredicate("EMS_DOCUMENT", "CASE_ID", "=", CaseSegment::instance()->getCASE_ID());
   auto_ptr<FormatSelectVisitor> pFormatSelectVisitor((FormatSelectVisitor*)DatabaseFactory::instance()->create("FormatSelectVisitor"));
   hSubQuery.accept(*pFormatSelectVisitor);
   string strSubQuery = "(" + pFormatSelectVisitor->SQLText() + ")";
   hQuery.bind("EMS_DOCUMENT", "DOC_PATH", Column::STRING, &m_strFILE_NAME);
   hQuery.setBasicPredicate("EMS_DOCUMENT", "CASE_ID", "=", CaseSegment::instance()->getCASE_ID());
   hQuery.setBasicPredicate("EMS_DOCUMENT", "SEQ_NO", "IN", strSubQuery.c_str());
   auto_ptr<SelectStatement> pSelectStatement((SelectStatement*)DatabaseFactory::instance()->create("SelectStatement"));
   if (!pSelectStatement->execute(hQuery))
      return false;

   size_t pos = m_strFILE_NAME.find_last_of("\\");
   if (pos == string::npos)
      pos = m_strFILE_NAME.find_last_of("//");
   if (pos != string::npos)
      m_strFILE_NAME = m_strFILE_NAME.substr(pos + 1, string::npos);
   return true;
   //## end nyceexception::NYCEExport::setDOC_PATH%65D201B70161.body
}