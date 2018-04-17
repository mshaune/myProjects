// Fig. 3.1: CLogInDialog.h
// login dialog

class CLoginDialog : public CDialog 
{
   public:
      CLoginDialog(wchar_t *lpszName );
      afx_msg void OnLogin();     // message handler for Log in
   private:
      wchar_t m_szUserid[ 17 ];
      wchar_t m_szPassword[ 13 ];

      DECLARE_MESSAGE_MAP()
};


class CMainWin : public CFrameWnd 
{
   public:
      //CMainWin();
      void login();
};
