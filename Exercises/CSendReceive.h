/*
* CSCI 290 - Event Driver Programming
* Chuck Nelson, Associate Professor
*
* Student Information (please complete ? below)
*    Name:         Myracle Jackson
*    School Email: mj148182@rockford.edu
* Class Information
*    Section:      290.01
* Assignment Information
*                  Exercise4.5
*                  CSendReceive App
*---------------------------------------------------------------------
*/
// CSendReceive App

class CSendReceiveDialog : public CDialog
{
   public:
      CSendReceiveDialog(wchar_t *lpszName ) : CDialog( lpszName ) {}
      BOOL OnInitDialog();
      // STUDENT CODE BEGINS
	  afx_msg void OnBnClickedOk();
	  afx_msg void OnReceive();
	  afx_msg void OnSend();

	  afx_msg void OnExit();
	  afx_msg void OnClose();
	  afx_msg void OnCancel();
	  afx_msg void OnClear();
      // STUDENT CODE ENDS
   private:
      // STUDENT CODE BEGINS
	static wchar_t *s_alpszChoices[];
	wchar_t buf[81];
	DECLARE_MESSAGE_MAP()
      // STUDENT CODE ENDS
};
