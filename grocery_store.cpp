#include <iostream>
#include <iomanip>

#include "helpers.h"
#include "grocery_store.h"

// initial constructor
GroceryStore::GroceryStore() {
  CLEAR_CONSOLE();

  std::cout << "Initializing Grocery Store" << std::endl;

  // get data from data file, or create one if it doesn't exist

  this->DisplayMainMenu();

}

// Display Main Menu
void GroceryStore::DisplayMainMenu() {
  CLEAR_CONSOLE();

  std::cout << "********************************************************" << std::endl;
  std::cout << "********************** Main Menu ***********************" << std::endl;
  std::cout << "                                                        " << std::endl;
  std::cout << "Please select an option below:                          " << std::endl;
  std::cout << "1. Find item                                            " << std::endl;
  std::cout << "2. Print item list                                      " << std::endl;
  std::cout << "3. Find item histogram                                  " << std::endl;
  std::cout << "4. Exit                                                 " << std::endl;
  std::cout << "                                                        " << std::endl;
  std::cout << "********************************************************" << std::endl;

  return;
}