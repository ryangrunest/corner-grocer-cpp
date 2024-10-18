#include <iostream>
#include <iomanip>
#include <fstream>

#include "helpers.h"
#include "grocery_store.h"

// initial constructor
GroceryStore::GroceryStore() {
  CLEAR_CONSOLE(); // clear the console

  std::cout << "Initializing Grocery Store" << std::endl;

  this->DisplayMainMenu();
}

// Display Main Menu
void GroceryStore::DisplayMainMenu() {
  CLEAR_CONSOLE();

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

void GroceryStore::DisplayAddItem() {
  std::string newItemName;

  CLEAR_CONSOLE();

  std::cout << "Enter the name of an item you would like to add:" << std::endl;

  std::cin >> newItemName;

  this->AddItem(newItemName);
  this->DisplaySingleItem(newItemName);

  return;
}

void GroceryStore::DisplaySingleItem(std::string itemName) {
  std::list<GroceryItem>::iterator it;

  for (it = this->items.begin(); it != this->items.end(); ++it) {
    if (it->GetItemName() == itemName) {
      std::cout << it->GetItemName() << " total: " << it->GetItemCount() << std::endl;
      SLEEP(3);

      break;
    }
  }
}

void GroceryStore::DisplayList() {
  std::list<GroceryItem>::iterator it;

  CLEAR_CONSOLE();

  for (it = this->items.begin(); it != this->items.end(); ++it) {
    std::cout << it->GetItemName() << ": " << it->GetItemCount() << "." << std::endl; 
  }

  std::cout << "Press enter to return to main form." << std::endl;
  std::cin.ignore(2);

  return;
}

void GroceryStore::DisplayHistogram() {
  std::list<GroceryItem>::iterator it;

  CLEAR_CONSOLE();

  for (it = this->items.begin(); it != this->items.end(); ++it) {
    std::cout << it->GetItemName() << " ";

    for (int i = 0; i < it->GetItemCount(); i++) {
      std::cout << "*";
    };

    std::cout << std::endl;
  }

  std::cout << "Press enter to return to main form." << std::endl;
  std::cin.ignore(2);

  return;
}

void GroceryStore::AddItem(std::string itemName, bool isInitialLoad) {
  std::ofstream outFS; // output file stream

  std::list<GroceryItem>::iterator it;
  int itemAdded = false;

  if (this->items.size() > 1) {
    for (it = this->items.begin(); it != this->items.end(); ++it) {
      if (it->GetItemName() == itemName) {
        it->AddOneItemCount();

        itemAdded = true;
      }
    }

    if (itemAdded == false) {
      GroceryItem currentItem;

      currentItem.SetItemName(itemName);
      currentItem.AddOneItemCount();

      this->items.push_back(currentItem);
    }
  } else {
    GroceryItem currentItem;

    currentItem.SetItemName(itemName);
    currentItem.AddOneItemCount();

    this->items.push_back(currentItem);
  }

  if (isInitialLoad) {
    return;
  } else {
    // need to add to data file
    outFS.open("frequency.dat", std::ios_base::app); // append instead of overwrite

    if (!outFS.is_open()) {
      std::cout << "Could not open data file to write new item." << std::endl;
      return;
    } else {
      outFS << itemName << std::endl;
    }
  }
}