#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
const int SIZE 4;


#define MENU1  1              // selection sort asc by product number
#define MENU2  1              // selection sort desc by product number
#define MENU3  1


int main()
{

	int createPop(int num);
	void resizeArray(int DMArr[], int SIZE,
		int num, char input,
		int *inputNum);
	void physReverse(int DMArr[], int num);
   

   
   int DMArr[SIZE];
   int indexArr[inputNum];
   

   int menu(void);
   int pause();
   void displayIntro();

   int choice;
}

int menu(void)
{
   const int MAX = 9;
   int choice = 0;

	cout << "Please make a selection(0-" << MAX << "): ";
   do
   {
      cout << "1. Create and populate list." << endl << endl;
	  cout << "2. Resize list." << endl << endl;
	  cout << "3. Physical Reverse." << endl << endl;
       

   } while (choice < 0 || choice > MAX);

   
   cin >> choice;
   cin.ignore();

   return choice;
}

void displayIntro()
{
   cout << endl;

   cout << "Project/program name: Selection Sort Lab " << endl;
   cout << "by" << endl;
   cout << "Myracle Jackson" << endl;

   cout << endl;
}