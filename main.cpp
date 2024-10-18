/*
  Ryan Grunest
  10/17/2024
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>

#include "helpers.h"
#include "grocery_store.h"
#include "grocery_item.h"

using namespace std;

int main() {
  ifstream inFS;
  ofstream oFS;
  int userInput;
  GroceryStore store;
  string currWord;

  // create data file if it doesn't exist for whatever reason
  oFS.open("frequency.dat", fstream::app);
  oFS.close();

  // Read data file of all items on load
  inFS.open("frequency.dat");

  while (!inFS.eof()) { // for each line in the db
    int itemAdded = false; 

    inFS >> currWord; // get the item name

    if (!inFS.fail()) {
      store.AddItem(currWord, true); // add the item to memory
    }
  }
  // End -> Read data file of all items on load

  cin >> userInput; // get user input

  /*
    main program form loop. This loop houses the various functions:
    1. adding and displaying a single item
    2. displaying the list of all items in the db
    3. displaying the list of all items as a histogram (ex. Cheese ****)
    4. exiting the program
  */
  while (userInput == 1 || userInput == 2 || userInput == 3 || userInput == 4) {
    if (userInput == 1) {
      // Add Item
      store.DisplayAddItem();
    } else if (userInput == 2) {
      // Print item list
      store.DisplayList();
    } else if (userInput == 3) {
      // Print item histogram
      store.DisplayHistogram();
    } else if (userInput == 4) {
      cout << "Goodbye!" << endl;
      break;
    }

    store.DisplayMainMenu(); // after the user has entered their input and functionality has been ran, display main menu again
    cin >> userInput; // get user input
  }

  return 0;
}