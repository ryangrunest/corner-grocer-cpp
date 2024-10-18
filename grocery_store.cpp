#include <iostream>
#include <iomanip>
#include <fstream>

#include "helpers.h"
#include "grocery_store.h"

// initial constructor
GroceryStore::GroceryStore() {
  CLEAR_CONSOLE(); // clear the console

  this->DisplayMainMenu(); // display main menu on init
}

// Display Main Menu
void GroceryStore::DisplayMainMenu() {
  CLEAR_CONSOLE(); // clear the console

  // display the main menu
  std::cout << "********************************************************" << std::endl;
  std::cout << "********************** Main Menu ***********************" << std::endl;
  std::cout << "                                                        " << std::endl;
  std::cout << "Please select an option below:                          " << std::endl;
  std::cout << "1. Add item                                             " << std::endl;
  std::cout << "2. Print item list                                      " << std::endl;
  std::cout << "3. Print item histogram                                  " << std::endl;
  std::cout << "4. Exit                                                 " << std::endl;
  std::cout << "                                                        " << std::endl;
  std::cout << "********************************************************" << std::endl;

  return;
}

// display form input for adding an item, gets users input and adds to memory and db.
void GroceryStore::DisplayAddItem() {
  std::string newItemName;

  CLEAR_CONSOLE(); // clear the console

  std::cout << "Enter the name of an item you would like to add:" << std::endl;

  std::cin >> newItemName; // get user input of item they want to add

  this->AddItem(newItemName); // add item
  this->DisplaySingleItem(newItemName); // display count of item from memory

  return;
}

// prints a single item to the console
void GroceryStore::DisplaySingleItem(std::string itemName) {
  std::list<GroceryItem>::iterator it;

  for (it = this->items.begin(); it != this->items.end(); ++it) { // loop through list
    if (it->GetItemName() == itemName) { // if the item name matches the item index
      std::cout << it->GetItemName() << " total: " << it->GetItemCount() << std::endl; // display the total
      SLEEP(3); // allow the user 3 seconds to read the total

      break; // don't need to keep looping. break it.
    }
  }
}

// prints the list of items and their counts to the console
void GroceryStore::DisplayList() {
  std::list<GroceryItem>::iterator it;

  CLEAR_CONSOLE(); // clean up the console

  for (it = this->items.begin(); it != this->items.end(); ++it) { // for each item in memory
    std::cout << it->GetItemName() << ": " << it->GetItemCount() << "." << std::endl; // print the item and item count
  }

  std::cout << "Press enter to return to main form." << std::endl;
  std::cin.ignore(2); // wait for user to press enter before going back to main menu

  return;
}

// prints the list of items as a histogram to the console
void GroceryStore::DisplayHistogram() {
  std::list<GroceryItem>::iterator it;

  CLEAR_CONSOLE(); // clean up the console

  for (it = this->items.begin(); it != this->items.end(); ++it) { // for each item in memory
    std::cout << it->GetItemName() << " "; // print the item name

    for (int i = 0; i < it->GetItemCount(); i++) { // for each item in the item count
      std::cout << "*"; // print a star
    };

    std::cout << std::endl; // end the line
  }

  std::cout << "Press enter to return to main form." << std::endl;
  std::cin.ignore(2); // wait for user to press enter before going back to main menu

  return;
}

// adds an item to the db. isInitalLoad is set to false by default
void GroceryStore::AddItem(std::string itemName, bool isInitialLoad) {
  std::ofstream outFS; // output file stream

  std::list<GroceryItem>::iterator it;
  int itemAdded = false;

  if (this->items.size() > 1) { // if there are any items in memory
    for (it = this->items.begin(); it != this->items.end(); ++it) { // for each item in memory
      if (it->GetItemName() == itemName) { // if the item names match
        it->AddOneItemCount(); // don't add a new list item, just add the count

        itemAdded = true; // item was added
      }
    }

    if (itemAdded == false) { // if item was not added
      GroceryItem currentItem; // create new item

      currentItem.SetItemName(itemName); // set values
      currentItem.AddOneItemCount(); // set values

      this->items.push_back(currentItem); // append it to the list in memory
    }
  } else { // don't need to loop, so add item to memory
    GroceryItem currentItem; // create new item

    currentItem.SetItemName(itemName); // set values
    currentItem.AddOneItemCount(); // set values

    this->items.push_back(currentItem); // append it to the list in memory
  }

  if (isInitialLoad) { // if part of the initial load from the db, don't want to duplicate data so exit
    return;
  } else { // we need to add it to the data file
    outFS.open("frequency.dat", std::ios_base::app); // append instead of overwrite

    if (!outFS.is_open()) { // oops
      std::cout << "Could not open data file to write new item." << std::endl;
      return;
    } else {
      outFS << itemName << std::endl; // write to file
    }
  }
}