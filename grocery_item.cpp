#include <iostream>
#include <iomanip>
#include <string>

#include "grocery_item.h"

GroceryItem::GroceryItem() {
  itemName = "";
  itemCount = 0;
}

std::string GroceryItem::GetItemName() {
  return itemName;
}

std::string GroceryItem::SetItemName(std::string name) {
  itemName = name;

  return itemName;
}

int GroceryItem::GetItemCount() {
  return itemCount;
}

int GroceryItem::AddOneItemCount() {
  itemCount++;

  return itemCount;
}