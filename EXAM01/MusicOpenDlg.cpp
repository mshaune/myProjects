#include <afxwin.h>
#include <afxdlgs.h>              // for GetOpenFileName()
#include <afx.h>                  // CFile, CString


#include "MusicOpenDlg_ids.h"
#include "MusicOpenDlg.h"

//  preprocessor directives
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

/* OnInitDialog()
   set up the dialog gui for display
*/
BOOL MusicOpenDlg::OnInitDialog()
{
   CDialog::OnInitDialog();

   // (OUTPUT) get address of multiline edit box (read only)
   CEdit *pOutput = reinterpret_cast< CEdit* >(GetDlgItem(IDC_TEXT));

   // set initial text
   pOutput->SetWindowTextW(L"Open a file!" );
   pOutput->SetFocus();    // turn focus off!

   // set counts to 0
   SetCountsToZero();

   //
   return TRUE;
}


/* constructor
   -pass menu name to base class CDialog
   -terminate buffer with null byte
*/
MusicOpenDlg::MusicOpenDlg(wchar_t *lpszName )
   : CDialog( lpszName )   // base class constructor
{
   m_szText[ 0 ] = '\0';
}




/* event handler
   Exit button handler
   User presses Exit button & this code is then executed
   Notify user app is destroyed
*/

afx_msg void MusicOpenDlg::OnExit()
{
   unsigned status = 0;

   status = MessageBox(L"Terminate the program(OnExit)?",
      L"Music Common Dialog", MB_YESNO | MB_ICONQUESTION);

   if( status == IDYES )
   {
      // Exit the dialog
      OnOK();
   }

}

/* event handler
System close icon or ALT + F4
*/
afx_msg void MusicOpenDlg::OnClose ()
{
   unsigned status = 0;

   status = MessageBox(L"Terminate the program(OnClose)?",
      L"Music Common Dialog", MB_YESNO | MB_ICONQUESTION);

   if( status == IDYES )
   {
      // Exit the dialog
      OnOK();
   }
}

/* event handler
   OnFileClose
*/
afx_msg void MusicOpenDlg::OnFileClose ()
{
   // clear all text from output edit box
   CEdit *pOutput = reinterpret_cast< CEdit* >(GetDlgItem(IDC_TEXT));
   pOutput->Clear();

   // set back to initial text
   pOutput->SetWindowTextW(L"Open a file!" );
   pOutput->SetFocus();    // turn focus off!

   // reset counts to 0
   SetCountsToZero();
}

/* event handler
   OnFileOpen handler

*/
afx_msg void MusicOpenDlg::OnFileOpen()
{
   // constants
   const int CATEGORY_WIDTH = 18;
   const int LABEL_WIDTH    = 25;
   const int MEDIUM_WIDTH   = 10;
   const int HEADING_1      = 20;
   const int HEADING_2      = 29;
   const int HEADING_3      = 10;
   const int HYPHENS        = 64;


   // File field variables
   char categoryCode;                  // input
   int labelCode;
   int mediumCode;

   // output strings
   string strCategory;                 // processing & output
   string strLabel;
   string strMedium;

   // file variables
   string choice;                      // program loop variabale
   ifstream inMusic;

   // record counts
   unsigned int totalCount = 0;
   unsigned int goodCount = 0;
   unsigned int badCount = 0;
   bool isError = false;

   // szFilters is a text string that includes two file name filters:
   // "*.my" for "MyType Files" and "*.*' for "All Files."
   TCHAR szFilters[]= _T("MyType Files (*.txt)|*.txt|All Files (*.*)|*.*||");

   // Create an Open dialog; the default file name extension is ".my".
   CFileDialog fileDlg(TRUE, _T("txt"), _T("*.txt"),
      OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);

   // Display the file dialog. When user clicks OK, fileDlg.DoModal()
   // returns IDOK.
   if(fileDlg.DoModal() == IDOK)
   {
      CString pathName = fileDlg.GetPathName();
      ostringstream oStream;

      // Implement opening and reading file in here.
      // open the data file
      inMusic.open(pathName/*L"MusicInventory.txt"*/, ios::in);

      // check if file open failure or OK
      if ( inMusic.is_open() )
      {
         // display report headings (center on a 55 character line)
         oStream << right << setw(48) << "Music That Swings Super Inventory System" << "\r\n";
         oStream << right << setw(28) << "by" << "\r\n";
         oStream << right << setw(33) << "Joe Blough" << "\r\n" << "\r\n";

         // separator
         for (int i = 0; i < HYPHENS; i++)
         {
            oStream << "-";
         }
         oStream << "\r\n";

         // display column headings
         oStream << left << setw(HEADING_1) << "Category";      // column 1 heading

         oStream << left << setw(HEADING_2) << "Label";         // column 2 heading

         oStream << left << setw(HEADING_3) << "Medium";        // column 3 heading
         oStream << "\r\n";

         // separator
         for (int i = 0; i < HYPHENS; i++)
         {
            oStream << "-";
         }
         oStream << "\r\n";

         // priming read: read only the first row from the file
         // --note: read all three fields
         inMusic >> categoryCode;
         inMusic >> labelCode;
         inMusic >> mediumCode;

         // while not end of file
         while ( !inMusic.eof() )
         {
            // total record count
            totalCount++;
            // processing: category
            // category selection
            if (categoryCode == 'J' || categoryCode == 'j')
               strCategory = "JAZZ";
            else if (categoryCode == 'P' || categoryCode == 'p')
               strCategory =  "POP";
            else if (categoryCode == 'S' || categoryCode == 's')
               strCategory = "SOUL/RB";
            else if (categoryCode == 'R' || categoryCode == 'r')
               strCategory =  "REGGAE";
            else if (categoryCode == 'C' || categoryCode == 'c')
               strCategory = "CLASSICAL";
            else
            {
               strCategory = "**Invalid**";
               isError = true;
            }

            // processing: label
            // labels
            if(labelCode == 100)
               strLabel = "EPIC" ;
            else if(labelCode == 130)
               strLabel = "VIRGIN RECORDS" ;
            else if(labelCode == 400)
               strLabel = "ELEKTRA" ;
            else if(labelCode == 240)
               strLabel = "WARNER BROS" ;
            else if(labelCode == 310)
               strLabel = "A&M" ;
            else if(labelCode == 560)
               strLabel = "MOTOWN" ;
            else if(labelCode == 630)
               strLabel = "ARISTA" ;
            else if(labelCode == 800)
               strLabel = "FLY/SIRE" ;
            else
            {
               strLabel = "**Invalid**";
               isError = true;
            }

            // processing: medium
            // mediums
            if(mediumCode == 1)
               strMedium = "ALBUM" ;
            else if(mediumCode == 2)
               strMedium = "CASSETTE";
            else if(mediumCode == 3)
               strMedium = "COMPACT DISK";
            else
            {
               strMedium = "**Invalid**";
               isError = true;
            }

            /* display report detail line*/
            // output: category
            oStream << left << setw(1) << categoryCode
               << "-"
               << left << setw(CATEGORY_WIDTH) << strCategory;

            // output: label
            oStream << left << setw(3) << labelCode
               << "-"
               << left << setw(LABEL_WIDTH) << strLabel;

            // output: medium
            oStream << left << setw(1) << mediumCode
               << "-"
               << left << setw(MEDIUM_WIDTH) << strMedium
               << "\r\n";

            // adjust counts
            if (isError)
               badCount++;
            else
               goodCount++;

            // reset input
            categoryCode = labelCode = mediumCode = 0;
            strCategory = strLabel = strMedium = "";

            // read the next line (record) from the file
            // --note: read all three fields
            inMusic >> categoryCode;
            inMusic >> labelCode;
            inMusic >> mediumCode;

            // reset error flag
            isError = false;

         }  // end while ( !inMusic.eof() )

         inMusic.clear();
         inMusic.close();
      }
      else  // if ( inMusic.is_open() )
      {
         oStream << "ERROR: file open failure.\n";
         oStream << "Press ENTER to continue.\n";
         cin.get();
      }  // end if ( inMusic.is_open() )

      // (OUTPUT) get address of multiline edit box (read only)
      CEdit *pOutput = reinterpret_cast< CEdit* >(GetDlgItem(IDC_TEXT));
      pOutput->Clear();

      // display file contents
      string str(oStream.str() );
      wstring ws;
      ws.assign(str.begin(), str.end() );
      int length = ws.length();
      wchar_t * pC = new wchar_t[length];
      wcscpy( pC, ws.c_str() );
      pOutput->SetWindowText(pC);

      // display counts
      SetCounts(totalCount, goodCount, badCount);

   }  // end if(fileDlg.DoModal() == IDOK)
}

/* function: SetCounts()
   set the gui count fields to display counts after reading a file
*/
afx_msg void MusicOpenDlg::SetCounts(int totalCount,
                                     int goodCount,
                                     int badCount)
{
   // declare pointers to gui controls
   CEdit *pTotal;
   CEdit *pGood;
   CEdit *pBad;

   // OUTPUT buffers
   // declare buffers to hold output counts
   const int TEXT_SIZE = 16;
   wchar_t szTotal[TEXT_SIZE + 1]; // buffer for conversions
   wchar_t szGood[TEXT_SIZE + 1]; // buffer for conversions
   wchar_t szBad[TEXT_SIZE + 1]; // buffer for conversions

   // TODO #4 - display the total, good and bad record counts
   // Step #1: get addresses of the three gui counter controls
   // (the address of the three read only edit controls)
   // STUDENT CODE BEGINS
   pTotal = (CEdit *)(GetDlgItem(IDC_TOTAL));
   pGood = (CEdit *)(GetDlgItem(IDC_GOOD));
   pBad = (CEdit *)(GetDlgItem(IDC_BAD));


   // STUDENT CODE ENDS

   // Step #2: store the three counters (see 3 function parameters)
   // into the three output buffers--the three numeric counters
   // are converted to text and stored into the output buffers
   // format output for gui controls
   // STUDENT CODE BEGINS
   swprintf(szTotal, L"%i", totalCount);
   swprintf(szGood, L"%i", goodCount);
   swprintf(szBad, L"%i", badCount);
  

   // STUDENT CODE ENDS

   // Step #3: store the three output buffer text fields
   // in the three gui counter fields
   // output file counts
   // STUDENT CODE BEGINS

   //swprintf( tBuf, szTotal );
   pTotal->SetWindowText( szTotal );
   pTotal->SetFocus();
 
   pGood->SetWindowText( szGood );
   pTotal->SetFocus();

   pBad->SetWindowText( szBad );
   pTotal->SetFocus();

   // STUDENT CODE ENDS
}

/* function: SetCountZero()
   set the gui counts to 0
*/
afx_msg void MusicOpenDlg::SetCountsToZero()
{
   CEdit *pTotal;
   CEdit *pGood;
   CEdit *pBad;

   /* TODO #3: set the three counters to 0 (zero)
   the three counters on the screen should show 0 after this
   function is executed...DO THE following two steps below
   STEP 1 - get the addresses of the three output controls
   STEP 2 - set the three text controls to "0"
   */


   // STEP 1 - get the addresses of the three output controls
   // STUDENT CODE BEGINS
   pTotal = (CEdit *)(GetDlgItem(IDC_TOTAL));
   pGood = (CEdit *)(GetDlgItem(IDC_GOOD));
   pBad = (CEdit *)(GetDlgItem(IDC_BAD));


   // STUDENT CODE ENDS

   // STEP 2 - set the three text controls to "0"
   // STUDENT CODE BEGINS

   pTotal->SetWindowText(L"0");
   pTotal->SetFocus();

   pGood->SetWindowText(L"0");
   pGood->SetFocus();

   pBad->SetWindowText(L"0");
   pBad->SetFocus();

   // STUDENT CODE ENDS
}

/* message mapping

*/
BEGIN_MESSAGE_MAP( MusicOpenDlg, CDialog )
   ON_COMMAND ( IDM_OPEN, OnFileOpen)     // Menu: File, Open
   ON_COMMAND ( IDM_CLOSE, OnFileClose)   // Menu: File, Close
   ON_COMMAND ( IDM_EXIT, OnExit )        // Menu: File, Close
   ON_WM_CLOSE ()                         // ALT + F4 or System close icon
END_MESSAGE_MAP()


/* start dialog-based application

*/
class CMusicApp : public CWinApp
{
   public:
      BOOL InitInstance()
      {
         MusicOpenDlg musicDialog( L"MusicApp" );
         m_pMainWnd = &musicDialog;
         musicDialog.DoModal();  // run dialog
         return FALSE;           // finished
      }

} MusicApp;
