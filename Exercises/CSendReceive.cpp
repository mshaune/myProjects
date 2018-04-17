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
#include <afxwin.h>
#include  <afxole.h>
#include <wchar.h>
#include "CSendReceive_ids.h"
#include "CSendReceive.h"


BOOL CSendReceiveDialog::OnInitDialog()
{
   // call base class initialization first
   CDialog::OnInitDialog();

   return TRUE;
}


/* Event Handler: OnSend()
   clicked the "Send" button
*/
afx_msg void CSendReceiveDialog::OnSend()
{
// STUDENT CODE BEGINS
	int nStart = 0;
	int nEnd = 0;

	CEdit *pText = (CEdit *)GetDlgItem(IDC_SOURCE);

	pText->GetSel(nStart, nEnd);
	pText->Copy();


	wsprintf(buf, L"Start: %i, End:%i", nStart, nEnd);
	
	MessageBox(buf, L"Sending..", MB_OK | MB_ICONINFORMATION);
	

// STUDENT CODE ENDS
}

/* Event Handler: OnReceive()
   clicked the "Receive" button
*/

// STUDENT CODE BEGINS
afx_msg void CSendReceiveDialog::OnReceive()
{
//STUDENT CODE BEGINS
	CEdit *pText = (CEdit *)GetDlgItem(IDC_DESTINATION);

	pText->SetSel(0, -1);
	pText->Paste();
// STUDENT CODE ENDS
}
afx_msg void CSendReceiveDialog::OnCancel()
{
	DestroyWindow();
}

/* Event Handler: :OnClear()
   clicked the "Clear" button
   clear both send and receive edit boxes
*/
afx_msg void CSendReceiveDialog::OnClear()
{
// STUDENT CODE BEGINS
	CEdit *pText = (CEdit *)GetDlgItem(IDC_SOURCE);
	CEdit *pCtext = (CEdit *)GetDlgItem(IDC_DESTINATION);

	pText->SetWindowText(L"");
	pCtext->SetWindowText(L"");

	pText->Clear();
	pCtext->Clear();
// STUDENT CODE ENDS
}

/* Event Handler: :OnBnClickedOk()
   clicked the "OK" button
*/
// STUDENT CODE BEGINS
afx_msg void CSendReceiveDialog::OnBnClickedOk()
{
	DestroyWindow();
}
// STUDENT CODE ENDS

/* Event Handler: :OnExit()
   clicked the "Exit" button
*/
// STUDENT CODE BEGINS
afx_msg void CSendReceiveDialog::OnExit()
{
	MessageBox(L"Exiting the program..",
		L"CSendReceiveDialog", MB_OK | MB_ICONINFORMATION);
		
		DestroyWindow();
	
}




// STUDENT CODE ENDS

/* Event Handler: :OnClose()
   clicked the "System Exit" button or ALT+F4
*/
// STUDENT CODE BEGINS

afx_msg void CSendReceiveDialog::OnClose()
{
	unsigned status = 0;

	status = MessageBox(L"Closing the program..",
		L"CSendReceiveDialog", MB_OK | MB_ICONINFORMATION);
	
	DestroyWindow();
	
}



// STUDENT CODE ENDS

/* Message Map

*/
BEGIN_MESSAGE_MAP( CSendReceiveDialog, CDialog )

   ON_COMMAND( IDC_SEND, OnSend )
   ON_COMMAND( IDC_RECEIVE, OnReceive )
   ON_COMMAND( IDC_CLEAR, OnClear )

   ON_BN_CLICKED(IDOK, &OnBnClickedOk)
   ON_COMMAND( IDC_EXIT, OnExit )     // Exit button
   ON_WM_CLOSE ()                     // ALT+F4 or system close button
END_MESSAGE_MAP()

/* Application class

*/
class CListBoxApp : public CWinApp
{
   public:
      BOOL InitInstance()
      {
         CSendReceiveDialog db( L"CSendReceiveDialog" );
         m_pMainWnd = &db;
         db.DoModal();   // returns IDOK or IDCANCEL
         return FALSE;
      }

} sendreceiveApp;
