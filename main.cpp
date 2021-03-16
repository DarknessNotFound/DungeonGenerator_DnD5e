// Programmer: DarknessNotFound
// File:       main.cpp
// Date:       2/1/2021
// Purpose:    This is going to house the main loop for the overall program.
//	       This will also include the basic text output for the end user.
#include <iostream>
#include "header.h"
using namespace std;

int main()
{
  dungeon dung1;
  bool cont_progr = true; //Continue the current program
  string menu_displ = "\t\tMenu\n" //Holds menu display
		      "1. New Generation\n"
		      "2. Display Current Generation\n"
		      "3. Settings\n"
		      "4. Quit\n";
  short menu_choice;				
  do
  {
    cout << menu_displ << endl;
    cout << "Your Choice: ";
    cin >> menu_choice;
    cout << endl;
    switch (menu_choice)
    {
      case 1://New Generation
	generate_dungeon(dung1);
        break;
      case 2: //Display Current Generation
        dung1.print_dung_data();
	break;
      case 3: //Settings
	break;
      case 4: //Quit
	cout << "Thanks for using the dungeon generator! Bye!" << endl;
  	cont_progr = false;
    }
  } while (cont_progr);
  return 0;
}
