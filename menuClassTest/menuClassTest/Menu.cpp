#include "Menu.h"



Menu::Menu() {}

Menu::Menu(optionsVecPtr) {}

Menu::~Menu() {
}

void Menu::displayMenu(string spaceBeforeMenu, string spaceBeforeMenuOption) {
  using std::cout;
  
  int i{1};
  
  cout << spaceBeforeMenu;    
  for (auto option : *optionsPtr) {
    cout << spaceBeforeMenuOption << i++ << " - " << option->description;
  } cout << spaceBeforeMenuOption << i << " - Exit";
  
  
  // minus 1 for vector selection  
  int choice = getUserInput<int>("Selection");

  if (choice > optionsPtr->size()) {
    cout << "\n\nChoice is out of range";
  }
  else if (choice == i) {
    exit(1);
  } 
  else {
    (*optionsPtr.get()->at(choice).get()->menuFunction.get())();
  }
}

Menu::MenuFunctions::
MenuFunctions(string description, functionPtr menuFunction) : 
  description{description}, menuFunction{menuFunction} {}
