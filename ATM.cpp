#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

/* Mini Project - ATM
   -> Check Balance
   -> Cash withdraw
   -> User Details
   -> Update Mobile No.
   -> Update PIN No.
   -> Exit
*/


class atm{										// class atm 
private:										// private member varibles
	long int account_No;
	string name;
	int PIN;
	double balance;
	string mobile_No;

public:											// public member functions

	// setData function is setting the Data into the private member variables
	void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a){
		account_No = account_No_a;	 // assigning the formal arguments to the private member var's
		name = name_a;
		PIN = PIN_a;
		balance = balance_a;
		mobile_No = mobile_No_a;
	}

	//getAccountNo function is returning the user's account no.
	long int getAccountNo(){
		return account_No;
	}
	
	//getName function is returning the user's Name
	string getName(){
		return name;
	}

	//getPIN function is returning the user's PIN
	int getPIN(){
		return PIN;
	}

	//getBalance is returning the user's Bank Balance
	double getBalance(){
		return balance;
	}

	//getMobileNo is returning the user's Mobile No.
	string getMobileNo(){
		return mobile_No;
	}

	//setMobile function is Updating the user mobile no
	void setMobile(string mob_prev, string mob_new)		{
		if (mob_prev == mobile_No){						// it will check old Mobile no
			mobile_No = mob_new;						// and Update with new, if old matches
			cout << endl << " \t \t \t Sucessfully Updated Mobile no :) ";
			_getch();				//getch is to hold the screen ( untill user press any key )																			
		} 
		else{							// Does not update if old mobile no. does not matches
		
			cout << endl << " \t \t \t Incorrect !!! Old Mobile no :( ";
			_getch();			  //getch is to hold the screen ( untill user press any key )
		}
	}

	// serPIN function is Updating the user PIN no
	void setPIN(int PIN_prev, int PIN_new){
		if (PIN_prev == PIN){						// it will check old PIN no
			PIN = PIN_new;						// and Update with new, if old matches
			cout << endl << " \t \t \t Sucessfully Updated PIN no :)";
			_getch();				//getch is to hold the screen ( untill user press any key )																			
		}
		else{							// Does not update if old PIN no. does not matches
			cout << endl << " \t \t \t Incorrect !!! Old PIN no :( ";
			_getch();			  //getch is to hold the screen ( untill user press any key )
		}
	}

	//cashWithDraw function is used to withdraw money from ATM
	void cashWithDraw(int amount_a){	
		if (amount_a > 0 && amount_a < balance){		// check entered amount validity
			balance -= amount_a;		// balance = balance - amount_a
			cout << endl << " \t \t \t Please Collect Your Cash :)";
			cout << endl << " \t \t \t Available Balance Rs. " << balance;
			_getch();				//getch is to hold the screen(untill user press any key )
		}
		else{

			cout << endl << " \t \t \t Invalid Input or Insufficient Balance :( "; 
			_getch();				//getch is to hold the screen ( untill user press any key )
		}
	}

};


//////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	int choice = 0, enterPIN;		//enterPIN and enterAccountNo. ---> user authentication
	long int enterAccountNo;

	system("cls");

	// created User ( object )
	atm user1;
	// Set User Details ( into object )         ( Setting Default Data )
	user1.setData(12345678, "Yujan Ranjitkar", 1010, 45000.90, "1000000000");

	do{
		system("cls");
		cout << endl << " \t \t \t ****************************************************";
		cout << endl << " \t \t \t ****************************************************";
		cout << endl << " \t \t \t      ******************************************     ";
		cout << endl << " \t \t \t           ********************************          ";
		cout << endl << " \t \t \t                **********************               ";
		cout << endl << " \t \t \t                 ***Welcome to ATM***                ";
		cout << endl << " \t \t \t                                                     ";
		cout << endl << " \t \t \t                  Enter Your Account No : ";	  // asking user to enter account no
		cin >> enterAccountNo;
		cout << endl << " \t \t \t                       Enter PIN : ";  // asking user to enter PIN
		cin >> enterPIN;

		// check whether enter values matches with user details
		if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN())){
			do{
				int amount = 0;
				string oldMobileNo, newMobileNo;
				int oldPINno, newPINno;

				system("cls");
				// user Interface
				cout << endl << " \t \t \t **************************************************";
				cout << endl << " \t \t \t **************************************************";
				cout << endl << " \t \t \t     ******************************************    ";
				cout << endl << " \t \t \t          ********************************         ";
				cout << endl << " \t \t \t               **********************              ";
				cout << endl << " \t \t \t             **** Welcome to ATM *****             ";
				cout << endl << " \t \t \t               *********************                ";
				cout << endl << " \t \t \t                                                    ";
				cout << endl << " \t \t \t               -- Select Options --                 ";
				cout << endl << " \t \t \t                1. Check Balance                    ";
				cout << endl << " \t \t \t                2. Cash withdraw                    ";
				cout << endl << " \t \t \t                3. Show User Details                ";
				cout << endl << " \t \t \t                4. Update Mobile no                 ";
				cout << endl << " \t \t \t                5. Change PIN no                    ";
				cout << endl << " \t \t \t                6. Exit                             ";
				cout << endl << " \t \t \t                                                    ";
				cout << endl << " \t \t \t **************************************************" ;
				cout << endl << " \t \t \t **************************************************";
				cout << endl << " \t \t \t  ";


				cin >> choice;						// taking user choice

				switch (choice){						// switch condition
				
				case 1:								// if user presses 1 
					cout << endl << " \t \t \t Your Bank balance is Rs. " << user1.getBalance();
					cout << endl << " \t \t \t  "; 
													// getBalance is ... printing the users									bank balance
					_getch();
					break;


				case 2:									// if user presses 2
					cout << endl << " \t \t \t Enter the amount Rs. ";		
					cin >> amount;
					user1.cashWithDraw(amount);			// calling cashWithdraw function 
													    // passing the withdraw amount 
					break;

				case 3:										// if user presses 3
				
				cout<< endl << " \t \t \t ##############################################";
				cout<< endl << " \t \t \t ##############################################";
					cout << endl << " \t \t \t # *** User Details are :- ";
					cout << endl << " \t \t \t # -> Account No. " << user1.getAccountNo();
					cout << endl << " \t \t \t # -> Name        " << user1.getName();
					cout << endl << " \t \t \t # -> Balance     " << user1.getBalance();
					cout << endl << " \t \t \t # -> Mobile No.  " << user1.getMobileNo();
					cout << endl << " \t \t \t # -> PIN no.     " << user1.getPIN();
				cout<< endl << " \t \t \t ##############################################";
				cout<< endl << " \t \t \t ##############################################";
				cout << endl << " \t \t \t  ";
													// getting and printing user details
					_getch();
					break;


				case 4:								   //  if user presses 4
					cout << endl << "\t \t \t Enter Old Mobile No. ";
					cin >> oldMobileNo;							// take old mobile no

					cout << endl << "\t \t \t Enter New Mobile No. ";
					cin >> newMobileNo;							// take new mobile no

					user1.setMobile(oldMobileNo, newMobileNo);	// now set new mobile no
					break;
				
				case 5:								     	// if user presses 5
					cout << endl << "\t \t \t Enter Old PIN No. ";
					cin >> oldPINno;

					cout << endl << "\t \t \t Enter new PIN no. ";
					cin >> newPINno;

					user1.setPIN(oldPINno, newPINno);
					break;

				case 6:
					cout << " \t \t \t Bye Bye :) :) " << user1.getName();
					exit(0);						// exit application
					_getch();

				default:							// handle invalid user inputs
					cout << endl << " \t \t \t Enter Valid Data :( !!!";
					_getch();
				} 

			} while (1);				// MENU	   // condition will always TRUE and loop is										capable of running infinite times
		}
		else{
			cout << endl << " \t \t \t User Details are Invalid :( !!! ";
			_getch();
		}
	} while (1);						//LOGIN		// condition will always TRUE and loop is										capable of running infinite times

	return 0;
}

