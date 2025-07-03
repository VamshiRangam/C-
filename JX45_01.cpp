void CaseSummaryCommand::update (Subject* pSubject)
{
  //## begin restcommand::RelatedCasesCommand::update%6853D2F802A2.body preserve=yes
   if (pSubject == &m_hQuery)
   {
      ++m_iRows;
      ++m_iTotalRows;
      segCaseHighlightSegment* p = (segCaseHighlightSegment*)m_pszBuffer;
      if (m_hCaseHighlightSegment.getSide()[1].length() > 0
         && (m_hCaseHighlightSegment.getSide()[0] != m_hCaseHighlightSegment.getSide()[1]
            || m_hCaseHighlightSegment.getNET_ID_EMS()[0] != m_hCaseHighlightSegment.getNET_ID_EMS()[1]))
      {
         string strValue(p->sInstitution, sizeof(p->sInstitution));
         m_hGenericSegment.set("Institution", rtrim(strValue));
         m_hGenericSegment.set("Role", m_hCaseHighlightSegment.getSide()[0]);
         m_hGenericSegment.set("Network", m_hCaseHighlightSegment.getNET_ID_EMS()[1]);
         strValue.assign(p->sOpen, sizeof(p->sOpen));
         m_hGenericSegment.set("open", rtrim(strValue));
         strValue.assign(p->sClosed , sizeof(p->sClosed));
         m_hGenericSegment.set("Closed", rtrim(strValue));
         strValue.assign(p->sRejected, sizeof(p->sRejected));
         m_hGenericSegment.set("Rejected", rtrim(strValue));
         save();
         if (!m_pXMLDocument->add("row"))
         {
            m_pXMLDocument->revert();
            m_hQuery.setAbort(true);
            return;
         }
         UseCase::addItem();
         return;
      }
   }
   command::RESTCommand::update(pSubject);
  //## end restcommand::RelatedCasesCommand::update%6853D2F802A2.body
}
