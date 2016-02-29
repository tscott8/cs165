/***********************************************************************
* Program:
*    Assignment 02, Mortgage             
*    Brother Burton, CS165
* Author:
*    Tyler Scott 
* Summary: 
*    This program is supposed to get some data from the user and
*    calculate a monthly mortgage payment. And display an Amortization
*    table outlining a payment schedule.
*
*    Estimated:  6.0 hrs 
*    Actual:     8.0 hrs
*      Most difficult part was getting the display to work and calculate
*      correctly
************************************************************************/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int interact();//declaring global variable interact
void display(double &mLoanPay, int &pmt, double &principal,
             double &interest, double &cumPrin, double &cumInt,
             double &prinBal, double &m, double &loanAmt,
             double &apr, double &loanTerm, double &mIntRate); 
             //declaring global variable display

float calculate(double &mLoanPay, int &pmt, double &principal,
                double &interest, double &cumPrin, double &cumInt,
                double &prinBal, double &m, double &loanAmt,
                double &apr, double &loanTerm, double &mIntRate);
                //declaring global variable calculate

/**********************************************************************
 * MAIN
 *  CALL interact
 *  END
 ***********************************************************************/
int main()
{   
   interact();//main calls interact function
   return 0;
}

/**********************************************************************
 * INTERACT
 *  PUT passing variables.
 *  PROMPTS for option
 *  CALLS corresponding function and passes neccessary data
 *  END
 ***********************************************************************/
int interact()
{
   
//The following declared Variables are for the monthly loan payment
// calculation in calculate.

   double loanAmt;//declaring Loaned amount
   double apr;//declaring %APR
   double loanTerm;//declaring Loan Term (years)
   double mIntRate;//declaring Monthly Interest Rate
   double mLoanPay;//declaring Monthly Loan Payment
   double m;//declaring months

//The following declared Variables are for the Amortization table in Display.
   int pmt;//declaring payment number
   double principal;//declaring principal amount integer
   double interest;//declaring interest
   double cumPrin;//declaring cumalitve principal
   double cumInt;//declaring cumalitive interest
   double prinBal;//declaring principal balance remaining
 
   char option;//declaring option as a character
   bool displayMenu = true;//declaring displayMenu as a true

   while (option != 'x')//as long as 'x' is not input, keep looping
   {
      if (displayMenu)//if display menu is true do output:
      {
         cout << "Options:\n";
         cout << "   (?)  Show these instructions\n"
              << "   (c)  Calculate Mortgage Monthly Payment\n"
              << "   (s)  Show specific payment\n"
              << "   (d)  Display Amortization Table\n"
              << "   (x)  Exit\n";
         if (option != '?')//as long as '?' is not input output and endl 
         {
            cout << "\n";
         }
         else
            cout << endl;
      }
      cout << "\n> ";
      cin >> option;//input option
      switch (option)//depending on input option, do the following
      {
         case '?'://if option is '?' 
            displayMenu = true;
            //set displayMenu as true. (ie show options again)
            break;//get out of loop
         case 'c'://if option is 'c'
            calculate(mLoanPay, pmt, principal, interest, cumPrin,
                      cumInt, prinBal, m, loanAmt, apr, loanTerm, mIntRate);
                      //call calculate function with data
            displayMenu = false;
            //set displayMenu as false (ie dont show options)
            break;//get out of loop
         case 's'://if option is 's' 
            cout << "showing specific payment.(!)This section is incomplete!\n"
                 << "(i do intend to finish it later.)\n";
            displayMenu = false;
            //set displayMenu as false (ie dont display options)
            break;//get out of loop
         case 'd'://if option is 'd' 
            display(mLoanPay,pmt, principal, interest, cumPrin,
                    cumInt, prinBal, m, loanAmt, apr, loanTerm, mIntRate);
                    //call display function with data
            displayMenu = false;
            //set displayMenu as false (is dont display options)
            break;//get out of loop
         case 'x'://if option is 'x'
            break;//get out of loop
         default://if none of the above options (something else) are input
            cout << "Invalid option. Please try again\n";
                 //state error message and reloop
            displayMenu = false;
            //set displayMenu as false (ie dont display options)
            break;//get out of loop
      }
   }
   return option;//send back option input
}

/**********************************************************************
 * CALCULATE
 *  GET stuffs
 *  verifies they are valid
 *  calculates monthly interest rate and payment
 *  Displays monthly payment
 *  END
 ***********************************************************************/
float calculate(double &mLoanPay, int &pmt, double &principal,
                double &interest, double &cumPrin, double &cumInt,
                double &prinBal, double &m, double &loanAmt,
                double &apr, double  &loanTerm, double &mIntRate)
{
   bool helpsNoobs = true;//declare error as true
   do
   {
      helpsNoobs = true;//if error is true, do the following
      
      cout << "Enter Loan Amount: $";
      cin >> loanAmt;

      if (cin.fail())//if it doesnt pass (user input a character)
      {
         cin.clear();
         char c;
         cin >> c;
         cout << "Invalid input. Numbers only, please try again.\n";
         //output error message and reprompt
         cin.clear();
         cin.ignore(256, '\n');
         helpsNoobs = false;//set error to false
      }
   } while (!helpsNoobs);
   
   do
   {
      helpsNoobs = true;

      cout << "Enter Annual Percentage Interest Rate(APR): %";
      cin >> apr;

      if (cin.fail())
      {
         cin.clear();
         char c;
         cin >> c;
         cout << "Invalid input. Numbers only, please try again.\n";
         cin.clear();
         cin.ignore(256, '\n');
         helpsNoobs = false;
      }
   } while (!helpsNoobs);        
   
   do
   {
      helpsNoobs = true;
      
      cout << "Enter Loan Term(years): ";
      cin >> loanTerm;

      if (cin.fail())
      {
         cin.clear();
         char c;
         cin >> c;
         cout << "Invalid input. Numbers only, please try again.\n";
         cin.clear();
         cin.ignore(256, '\n');
         helpsNoobs = false;
      }
   } while (!helpsNoobs);        
   
   mIntRate = ((apr / 100.00) / 12.00);
   //calculates the monthly interest rate base on the input APR
   m = loanTerm * 12;
   //calculates the number of months based on the input loan term years
   
   mLoanPay = (loanAmt * mIntRate) / (1 - pow((1 + mIntRate), - m));
   //calculates the monthly loan payment based on previous data given
  
   cout << "Your Monthly Payment: $" << mLoanPay << "\n";
   //outputs the monthly payment for the user
  
   return 0;   
}

/**********************************************************************
 * DISPLAY
 * recieves data from calculate
 * displays part of Amort table
 * Loops for payment numbers
 * calculates each columns values
 * displays their values
 * END
 ***********************************************************************/
void display(double &mLoanPay, int &pmt, double &principal,
             double &interest, double &cumPrin, double &cumInt,
             double &prinBal, double &m, double &loanAmt, double &apr,
             double  &loanTerm, double &mIntRate)
{
   
   cout.setf(ios::fixed);//sets up display stuff
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << "Your Monthly Payment: $" << mLoanPay << " \n"
        << setw(3) <<  "Pmt"
        << setw(12) << "Principal"
        << setw(11) << "Interest"
        << setw(11) << "Cum Prin"
        << setw(10) << "Cum Int"
        << setw(12) << "Prin Bal\n"
      
        << setw(3) <<  "---"
        << setw(12) << "---------"
        << setw(11) << "--------"
        << setw(11) << "--------"
        << setw(10) << "-------"
        << setw(12) << "--------\n";
        //outputs the beginning of the amortization table
   
   prinBal = loanAmt;//set principal balance equal to loaned amount
   
   for (pmt = 1; pmt <= m; pmt++)
   //loop starts when payment number is 1 and stops when it is
   //at the number of months
   {
      
      interest =  (prinBal * mIntRate);
      //calculates interest paid
      principal = mLoanPay - interest;
      //calculates principal paid
      cumPrin += principal;
      //calculates cumalitve principal
      cumInt += interest; 
      //calculates cumalitive interest
      prinBal -= principal;
      //calculates pricipal balance
            
      
      cout << setw(3) << pmt
           << setw(12) << principal
           << setw(11) << interest
           << setw(11) << cumPrin
           << setw(10) << cumInt
           << setw(11) << prinBal
           << endl;
      //outputs the table
      
   }
   
}
