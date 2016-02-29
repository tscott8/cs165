/***********************************************************************
* Program:
*    Assignment 00, Averages     
*    Brother Burton, CS165
* Author:
*    Tyler Scott
* Summary: 
*    This program is designed to take a number input by the user,
*    Check if its valid, and then calculate an Average.
*
*    Estimated:  4.0 hrs   
*    Actual:     7.0 hrs
*      
************************************************************************/

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

float getNumber();
int findAverage(/*float &number*/);

/**********************************************************************
 * Main in this function is supposed to call getNumber and findAverage
 ***********************************************************************/
int main()
{
   findAverage();
   return 0;
}

/**********************************************************************
 * getNumber gets and input number from the user, checks to make sure
 * that it is valid, if it is not it prompts again.
 ***********************************************************************/
float getNumber(/*float &number*/)
{
   float number;
   bool good = true;

   do
   {
      good = true;
      cout << "Enter a number: ";
      cin >> number;

      if (cin.fail())
      {
         cin.clear();
         char c;
         cin >> c;

         if (cin.fail() == false && c == 'q')
         {           
            exit(0);          
         }
         else
         {
            cout << "Invalid input, please try again.\n";
            cin.clear();
            cin.ignore(256, '\n');

            good = false;
         }
      }
   } while (!good);

   return number;
   
}
      
/**********************************************************************
 * findAverage is supposed to call int getNumber  and calculates its
 * average and the displays them
 * //get number
 * // add it to sum
 * // increment totalEntries TE++
 * // divide sum / total Entries
 ***********************************************************************/
int findAverage(/*float &number*/)
{

   float sum;
   sum = 0;
   float totalEntries;
   totalEntries = 0;
   float number;
   
   do
   {
      
      number = getNumber();
      sum += number;
      totalEntries++;
      float average;
      average = sum / totalEntries;

      cout.setf(ios::fixed);
      cout.setf(ios::showpoint);
      cout.precision(2);

      cout << "Average: " << average << "\n" << endl;
   
   }
   while (true);

   return 0;
   
}
   

