// Fig. 2.11: menus.cpp
// create menus with MFC


#include <afxwin.h>        // MFC application framework
#include "menus_ids.h"     // application message ID symbols
#include "CMenusWin.h"
#include "login_ids.h"
#include "CLogInDialog.h"

#include <string>
#include <sstream>      // string stream
#include <iomanip>       // I/O manipulators
#include <cstring>
using namespace std;

/****************************************
* CMenusWin constructor initializes frame
* 1- initializes output string
* 2- creates main window
* 3- initializes menu items
****************************************/
CMenusDialog::CMenusDialog(wchar_t * lpszName) : CDialog(lpszName)
{
   // Original title bar text: Menus Example
   // Menu name (see .rc file): Food
   //Create(NULL, _T("Menus Example"), WS_OVERLAPPEDWINDOW,
   //   CRect(0, 0, 600, 200), NULL, _T("Food"));

   m_nChicken = 0;
   m_nFish = 0;

   m_nGingerale = 0;
   m_nRootbeer = 0;

   m_dTotal = 0.0;

}

// count each type of item ordered, compute total bill
void CMenusDialog::tally( int &nCount, double dAmount )
{
   nCount++;
   m_dTotal += dAmount;
}

// afx_msg precedes each message handler function
afx_msg void CMenusDialog::OnExit()
{
   if (MessageBox(L"Terminate the program(OnExit)?",
      L"Menus Example", MB_YESNO | MB_ICONQUESTION) == IDYES)
   {
      // Use either of the following two close methods
      //DestroyWindow();
      SendMessage(WM_CLOSE);
   }
   
}

/* event handler
OnDoFood button handler
User selects entree or beverage
As each item is selected, this handler adds cost
 of the item selected
*/
afx_msg void CMenusDialog::OnDoFood(UINT nFood)
{
   switch (nFood)
   {
   case IDM_CHICKEN:
	   tally(m_nChicken, 2.25);
	   break;
   case IDM_FISH:
	   tally(m_nFish, 1.80);
	   break;
   case IDM_CHEESEBURGER:
	   tally(m_nFish, 1.80);
	   break;
   case IDM_GINGERALE:
	   tally(m_nGingerale, .80);
	   break;
   case IDM_ROOTBEER:
	   tally(m_nRootbeer, .80);
	   break;
   case IDM_ORANGESODA:
	   tally(m_nOrangeSoda, .95);
	   break;

   }
}


/* event handler
   OnSurcharge button handler
   afx_msg void CMenusDialog::OnSurcharge()
   User selects bill surcharge
   TODO: code this event handler method
*/


afx_msg void CMenusDialog::OnSurcharge()
{
	m_dSurcharge = true;
}

/* event handler
   OnShowTotal button handler
   User selects to view bill total 
   NOTE: total is reset to 0!
*/
afx_msg void CMenusDialog::OnShowTotal()
{
   // output buffer
   wchar_t msg[81];

   if (m_dSurcharge == true)
   {
	   m_dTotal - m_dTotal * 1.01;
   }

   // format output
   swprintf(msg, TEXT_SIZE, L"Your total is: $%.2f", m_dTotal);

   // display output
   CEdit * pOutput = (CEdit *)(GetDlgItem(IDC_BILL));
   pOutput->SetWindowTextW(msg);
   
   // reset total for next entry
   m_dTotal = 0.0;
}

/* event handler
   OnClearTotal button handler
   User selects to clear bill total
*/
afx_msg void CMenusDialog::OnClearTotal()
{
   m_dTotal = 0.0;

   // reset output
   CEdit * pOutput = (CEdit *)(GetDlgItem(IDC_BILL));
   pOutput->SetWindowTextW(L"Your total is: $0.00");
}

/* message map
   ON_COMMAND_RANGE : how does this work?
*/
BEGIN_MESSAGE_MAP(CMenusDialog, CDialog )
   
   ON_COMMAND( IDM_EXIT, OnExit )

   ON_COMMAND_RANGE(IDM_CHICKEN, IDM_ROOTBEER, OnDoFood)

   ON_COMMAND( IDM_SHOW_TOTAL, OnShowTotal )
   ON_COMMAND( IDM_CLEAR_TOTAL, OnClearTotal )

END_MESSAGE_MAP()

/*************************************************
* Program Entry Point (indirectly invokes main() )
* Derive class:  CMenusApp
* Base class:    CWinApp  (invisible)
*
* 1- Override InitInstance() method
* 2- Make main frame window visible
*************************************************/
class CMenusApp : public CWinApp
{
public:
   BOOL InitInstance()        // called by CWinApp::CWinApp
   {
	   int status = 0;
	   
	   CLoginDialog  loginDialog(L"Login");           // create window
	   status = loginDialog.DoModal();
	   if (status == IDOK)
	   {
		   CMenusDialog  menuDialog(L"MENUDIALOG");           // create window
		   menuDialog.DoModal();
	   }
      return TRUE;                          // report success
   }

} menusDialog;                   // calls CWinApp::CWinApp
