#include <string>

#ifndef GROCERY_ITEM_H
#define GROCERY_ITEM_H

class GroceryItem
{
  public: 
    GroceryItem();
    std::string GetItemName();
    std::string SetItemName(std::string name);
    int GetItemCount();
    int AddOneItemCount();
  private:
    int itemCount;
    std::string itemName;
};

#endif