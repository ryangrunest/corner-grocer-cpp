#include <iostream>
#include <iomanip>
#include <string>

#include "grocery_item.h"

/* 
  Grocery Item is used to track an individual item and it's count.
  It is used by the GroceryStore class
*/
GroceryItem::GroceryItem() {
  itemName = "";
  itemCount = 0;
}

// retrieve item name
std::string GroceryItem::GetItemName() {
  return itemName;
}

// set item name
std::string GroceryItem::SetItemName(std::string name) {
  itemName = name;

  return itemName;
}

// retrieve item count
int GroceryItem::GetItemCount() {
  return itemCount;
}

// increment item count
int GroceryItem::AddOneItemCount() {
  itemCount++;

  return itemCount;
}