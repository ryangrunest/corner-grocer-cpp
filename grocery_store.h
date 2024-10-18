#include <list>
#include <string>
#include "grocery_item.h"

#ifndef GROCERY_STORE_H
#define GROCERY_STORE_H

class GroceryStore
{
  public: 
    GroceryStore();
    void DisplayMainMenu();
    void DisplayAddItem();
    void DisplaySingleItem(std::string itemName);
    void DisplayList();
    void DisplayHistogram();
    void AddItem(std::string itemName, bool isInitialLoad = false);

    std::list<GroceryItem> items;
  private: 
};

#endif