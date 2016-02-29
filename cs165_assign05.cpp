/***********************************************************************
* Program:
*    Assignment 05, Contacts  
*    Brother Burton, CS165
* Author:
*    Tyler Scott
* Summary: 
*    This program is supposed to take the contacts from a file and
*    and use class methods to process the data.
*
*    Estimated:  6.0 hrs   
*    Actual:     4.0 hrs
*      Comprehension of what to do.
************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*********************************************************************
 * Declaring The class to be used
 ********************************************************************/
class Contact
{
private:
   string name;
   string address;
   string city;
   string state;
   string zip;
   string phone;

public:
   //Default Constructor is declared, sets everything to blank.
   // Allows for display to still work if nothing is read in or
   // user input.
   Contact()
   {
      name = "";
      address = "";
      city = "";
      state = "";
      zip = "";
      phone = "";
   }
   //Constructor allows the data inside the class to be changed by data
   //passed in from outside functions. 
   Contact(string name, string address, string city, string state,
           string zip, string phone)
   {
      this-> name = name;
      this -> address = address;
      this -> city = city;
      this -> state = state;
      this -> zip = zip;
      this-> phone = phone;
   }
   //Declaring getters.
   string getName() const { return name; }
   string getAddress() const { return address; }
   string getCity() const { return city; }
   string getState() const { return state; }
   string getZip() const { return zip; }
   string getPhone() const { return phone; }

   //Declaring setters.   
   void setName(string name)// const
   {
      this -> name = name;
   }
   void setAddress(string address)// const
   {
      this -> address = address;
   }
   void setCity(string city)// const
   {
      this -> city = city;
   }
   void setState(string state)// const
   {
      this -> state = state;
   }
   void setZip(string zip)// const
   {
      this -> zip = zip;
   }
   void setPhone(string phone)// const
   {
      this -> phone = phone;
   }
   
   void prompt(); 
   void display() const;  
};

   // prompt function is supposed to get input
   // values from the user.
void Contact :: prompt()
{  
   cout << "Name: ";
   getline(cin,name);
   
   cout << "Address: ";
   getline(cin,address);

   cout << "City: ";
   getline(cin,city);
   
   cout << "State: ";
   getline(cin,state);
   
   cout << "Zip: ";
   getline(cin,zip);
   
   cout << "Phone: ";
   getline(cin,phone);

   cout << "\n   ";
}
   //Display does exactly what it says. Displays 
void Contact :: display() const
{   
   cout << name << endl
        << address << endl
        << city << ", " << state << "  "
        << zip << endl
        << phone << endl;
}

   
/**********************************************************************
 * Main
 *    Declares a new Contact (me) using the default constructor, then
 *    calls prompt to fill it with values.
 *    Declares a new Contact (teacher) using default constructor, then
 *    hard code sets the values.
 *    Makes an array for 5 contacts
 *    Opens the designated file
 *       Loops through 5 times, each time reading in the values needed
 *       for the contact info.
 *       Then puts these values into a new constructor (contactFile)
 *       Sets contactFile equal to the Array
 *    Closes the file
 *    Calls display for (teacher) and (me).
 *    Then Loops through the array again displaying each line.
 ***********************************************************************/
int main()
{
   Contact me;
   me.prompt();
   
   Contact teacher;
   teacher.setName("Brother Burton");
   teacher.setAddress("AUS 216F");
   teacher.setCity("Rexburg");
   teacher.setState("ID");
   teacher.setZip("83460");
   teacher.setPhone("208-496-7614");
   
   string name;
   string address;
   string city;
   string state;
   string zip;
   string phone;
   Contact contactArray[5];

   ifstream fin("/home/cs165sb/contacts.txt");
//   if (fin.fail())
   // {
   // cout << "Error reading file\n";
   //}
   
   for(int i = 0; i < 5; i++)
   {
      getline(fin, name);
      getline(fin, address);
      getline(fin, city);
      getline(fin, state);
      getline(fin, zip);
      getline(fin, phone);
      
      Contact contactFile(name, address, city, state, zip,
                          phone);
      contactArray[i] = contactFile;
   }
   fin.close();
   

   teacher.display();
   cout << "\n";
   me.display();
   cout << "\n";
   for (int i = 0; i < 5; i++)
   {
      contactArray[i].display();
      if (i < 4)
      {
         cout << endl;
      }
   }
      return 0;
}
