/*
 * DO NOT ALTER
 * CSCI 290 - Event Driver Programming
 * Chuck Nelson, Associate Professor
 *
 * Student Information (please complete ? below)
 *    Name:         Myracle Jackson
 *    School Email: mj148182@rockford.edu
 * Class Information
 *    Section:      290.01
 * Assignment Information
 *                  Exercise2.7
 *--------------------------------------------------------------------- 
 TODO #1: First, add these four files to an MFC project and run. There should be
 no errors. Try each option so that you know how the program operates
 before you enhance this program.

 TODO #2: Modify the menu program () by adding these features...
   -include one more food item for each menu  (no changes to FILE menu)
   -implement a new menu option to let the manager increase ALL prices
      by a one-percent surcharge each time this option is selected

 */
// Fig. 2.11: CMenusWin.h
// create menus with MFC
const int TEXT_SIZE = 81;

#include <iostream>         // cin, cout
#include <string>           // for string objects
#include <sstream>          // in memory formatting & conversion
using namespace std;

//class CMenusWin : public CFrameWnd
class CMenusDialog : public CDialog
{
   public:
      CMenusDialog(wchar_t *lpszname);
      void tally( int &nCount, double dAmount );
      afx_msg void OnExit(); 
      afx_msg void OnDoFood(UINT nFood); 
      afx_msg void OnShowTotal();
      afx_msg void OnClearTotal();
	  afx_msg void OnSurcharge();
     

   private:
      int m_nChicken; 
      int m_nFish;      // count items ordered
      int m_nSpaghetti;
	  int m_nCheeseburger;
      int m_nGingerale; 
      int m_nRootbeer;
      int m_nDietCoke;
	  int m_nOrangeSoda;
      double m_dTotal;  // tally cost of the order
	  bool m_dSurcharge;


      DECLARE_MESSAGE_MAP()
};
