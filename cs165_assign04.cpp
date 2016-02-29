/***********************************************************************
* Program:
*    Assignment 04, Student Database Part 2    
*    Brother Burton, CS165
* Author:
*    Tyler Scott
* Summary: 
*    This program opens up a file and reads in student records. Then asks
*    to search for specific student record.
*
*    Estimated:  5.0 hrs  
*    Actual:     9.0 hrs
*      The hardest part was getting the structures to work, and
*      comparing the strings.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;

struct StuData
{
   int stuNumber;
   char firstName[20];
   char lastName[20];
};

void getFile(char fileName[]);
int readFile(StuData * &stuData, char fileName[]);
void display(const StuData &stuData);

void nameSearch(const StuData stuData[], int &numStu);
int compLines(const StuData stuData[], char search[], int &numStu);

/**********************************************************************
 * Main calls the functions.
 ***********************************************************************/
int main()
{
   int numStu;
   char fileName[256];
   StuData * stuData = NULL;
   getFile(fileName);
   bool failure1;

   do
   {
      failure1 = false;      

      try
      {
         numStu = readFile(stuData, fileName);
      }
      catch (const char * ex1)
      {
         cout << ex1 << endl;
         failure1 = true;
         
         cin.clear();
         cin.ignore(256, '\n');
         getFile(fileName);
      }          
   }while (failure1);
   
   nameSearch(stuData, numStu);
   
   delete[] stuData;
   stuData = NULL;
   
   return 0;
}

/**********************************************************************
 * Get file gets the filename
 ***********************************************************************/
void getFile(char fileName[])
{
   cout << "Please enter the data file: ";
   cin >> fileName; 
}

/**********************************************************************
 * readFile opens the file input above. and puts it into an array
 ************************************************************************/
int readFile(StuData * &stuData, char fileName[])
{
   ifstream fin;
   int numStu;
   
   fin.open(fileName);
   // check to make sure it opened correctly
   if (fin.fail())
   {
      throw  "Error opening file.\n";
   }

   else
   {
      cout << "Loading File...\n";
   
      // if we made it here...there was not a problem
      fin >> numStu;
      fin.ignore(30, '\n');

      stuData = new StuData[numStu];
      int i = 0;

      while (!fin.eof())
      {                 
         if (i >= numStu)
         {
//            throw "Error: file ended before numStu";
            break;
         }

         try
         {
            char line[256];
            fin.getline(line, 256);
            
            stringstream ss(line);
            
            ss >> stuData[i].firstName;
            ss >> stuData[i].lastName;
            ss >> stuData[i].stuNumber;
                       
            if (ss.fail())
            {
               throw line;
            }

         }
         catch (const char * ex2)
         {
            cout << "Error parsing the following record: '" << ex2
                 << "'. It will be skipped.\n";        
         }
 
         i++;
      }
      cout << "Done loading file.\n";
   }

   fin.close();
   return numStu;
}

/**********************************************************************
 * name search gets an input name and then checks the file if it is in
 * there
 ***********************************************************************/
void nameSearch(const StuData  stuData[], int &numStu)
{
   bool loopAgain = true;
   char search[30];
   do
   {
      cout << "\nEnter last name: ";
      cin >> search;
     
      if (strcmp(search, "quit") == 0)
      {
         cout << "Goodbye\n";
         loopAgain = false;
      }
      else
      {
         compLines(stuData, search, numStu);
      }
      
   } while (loopAgain);
   
   return;  
}

/**********************************************************************
 * compLines loops through the file array
 ***********************************************************************/
int compLines(const StuData stuData[], char search[], int &numStu)
{
   bool foundStu = false;
   for (int i = 0; i < numStu; i++)
   {
      if (strcmp(stuData[i].lastName, search) == 0)
      {
         foundStu = true;
         display(stuData[i]);            
      }
      else
      {        

      }
   }
   
   if (!foundStu)
   {
      cout << "No match found.\n";
   }
}

/**********************************************************************
 * displays the name searched and found in the file.
 ***********************************************************************/
void display(const StuData &stuData)          
{
   cout << stuData.stuNumber << " - " << stuData.lastName
        << ", " << stuData.firstName << endl;
  
}
