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
 *                  MusicOpenDlg
 *---------------------------------------------------------------------
 */
#ifndef MUSICOPENDLG__H
#define MUSICOPENDLG__H

#define DEBUG 0


const int MAX_TEXT = 128;

class MusicOpenDlg : public CDialog
{
   public:
      BOOL MusicOpenDlg::OnInitDialog();
      MusicOpenDlg( wchar_t *lpszName );
      afx_msg void OnFileOpen();    // ON_COMMAND ( IDM_OPEN, OnFileOpen )
      afx_msg void OnExit();        // ON_COMMAND ( IDM_EXIT, OnExit )
      afx_msg void OnFileClose();   // ON_COMMAND ( IDM_CLOSE, OnFileClose )
      afx_msg void OnClose();       // ON_WM_CLOSE ()

   private:


      wchar_t m_szText[ MAX_TEXT + 1 ];
      // sets gui counts based on input file
      afx_msg void SetCounts(int, int, int);

      /*
         code the prototype for the SetCountsToZero() function
      */
      afx_msg void SetCountsToZero();     // sets gui counts to 0


      DECLARE_MESSAGE_MAP()
};


#endif

