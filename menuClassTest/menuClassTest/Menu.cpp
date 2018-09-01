#include "Menu.h"



Menu::Menu() {}

Menu::Menu(optionsVecPtr optionsPtr, 
           string spaceBeforeMenu,
           string spaceBeforeMenuOptions) : optionsPtr{move(optionsPtr)} {

  displayMenu(spaceBeforeMenu, spaceBeforeMenuOptions);
}


Menu::~Menu() {}





void Menu::displayMenu(string spaceBeforeMenu, string spaceBeforeMenuOption) {
  using std::cout;
  
  int i{1};
  
  cout << spaceBeforeMenu;      
  for (auto option : *optionsPtr) {
    cout << spaceBeforeMenuOption 
         << i++ << " - " << option.description << endl;
  } 
  cout << spaceBeforeMenuOption << i << " - Exit" << endl;
  
  
  // minus 1 for vector selection  
  int choice = getUserInput<int>("Selection");

  if (choice > optionsPtr->size()) {
    cout << "\n\nChoice is out of range";
  }
  else if (choice == i) {
    exit(1);
  } 
  else {
    (*optionsPtr.get()->at(choice).menuFunction.get())();
  }
}





Menu::MenuFunction::
MenuFunction(string description, functionPtr menuFunction) : 
  description{description}, menuFunction{menuFunction} {}
