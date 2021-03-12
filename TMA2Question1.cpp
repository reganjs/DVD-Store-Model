//Regan Setter
//Student ID 3505894
//Computer Science 206
//February 13th, 2021

//Write a program to manage DVD rental in a video rental store. Create an abstract data type that represents a DVD in this store. Consider all the data and operations that may be necessary for the DVD type to work well within a rental management system. Include a print() member function that displays all the information about the DVD. Test your data type by creating an array of ten DVD instances and filling them using information read from a test input file that you create. Display the DVD information.

//Test: Created a file that contains some records, each record represents a movie title, genre, rating, release date, rented date and return date. Then I stored the data taken from the file into an abstract data type and displayed the data read from the file in the proper format. 


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class DVD //abstract data type 
{
private:
  string genre;
  string type;
  string year;
  string daterented;
  string datereturned;
  string title;
public:
  void setname (string z)
  {
    title = z;
  }
  string getname ()
  {
    return title;
  }

  void setmovierating (string w)
  {
    type = w;
  }
  string getmovierating ()
  {
    return type;
  }
  void setyear (string v)
  {
    year = v;
  }
  string getyear ()
  {
    return year;
  }
  void setdaterented (string u)
  {
    daterented = u;
  }

  string getdaterented ()
  {
    return daterented;
  }

  void setdatereturned (string t)
  {
    datereturned = t;
  }

  string getdatereturned ()
  {
    return datereturned;
  }

  void setmoviegenre (string t)
  {
    genre = t;
  }
    
  string getmoviegenre ()
  {
    return genre;
  }
    
  void read(istream &is) //reads from the input stream
  {
    getline(is, title); //take title input from the file
    getline(is, genre); //take genre input from the file
    getline(is, type); //take type input from the file
    getline(is, year); //take year input from the file
    getline(is, daterented); //take date rented input from the file
    getline(is,  datereturned); //take return date input from the file
  }

  void print (ostream & os) const //function to print a record
  {
    os << "Name: " << title << endl;
    os << "Genre: " << genre << endl;
    os << "Rated: " << type << endl;
    os << "Date Released: " << year << endl;
    os << "Date Rented: " << daterented << endl;
    os << "Date Returned: " << datereturned << endl;
    os << endl;
  }
};

int main()
{
  DVD records[5]; //created an array of DVD abstract data 
  int number_of_movies = 5; //assumes that the number of movies is 5
  ifstream dvdfile("dvdfile.txt"); //opens dvdfile.txt 
  if(!dvdfile.is_open()) //if file not found the program will exit
  {
    cout << "Sorry! dvdfile.txt file not found (Program exited)\n";
    return 0;
  }
  int ent; //variable for the menu input
  int is_read = 0; //this is a flag, if the data has been read into the array then this flag will be 1, this is so it does not read from file repeatedly
  do
  {
	    cout << "--------------------------------------";
	    cout << "\nSimple DVD Rental Management System";
	    cout << "\n--------------------------------------";
	    cout << "\nWelcome Customer!";
	    cout << "\n\n\t <1> Display Rental Records";
      cout << "\n\n\t <2> Exit\n\n";
	    cout << "Enter Your Choice: " << "\t";
	    cin >> ent;
	  switch (ent)
	  {
      case 1:
      {
        if(is_read == 0) //if movie data is not stored in an array
        {
          for (int i = 0; i < number_of_movies; i++) //looping until number of movies
          {
            records[i].read(dvdfile); //reads records in the array
          }
          dvdfile.close(); //closes the file
          is_read = 1; //assigns 1 to not read from the file again
        }
        
        for (int i = 0; i < number_of_movies; i++)  //looping until number of movies once again
        {
          cout << "\n\nDisplaying Movie #" << (i + 1) << " Record\n\n"; 
          records[i].print (cout);//displays records in the array
        }

        cout << "These are the required records!" << endl;
        break;
      }
     case 2: //when user enters 2 it shows a goodbye message and exits the program
      cout << "\nThanks for using the program, Goodbye!\n";
      break;
	    default: //on invalid selection in the menu
        cout << "\nInvalid Selection\n";
	      break;
	  }
  }while(ent != 2); //when user the number 2 as an input the program will exit

  return 0;
}
