#include "Menu.h"



Menu::Menu() {}


Menu::Menu(optionsVecPtr optionsPtr,           
           string spaceBeforeMenu,
           string spaceBeforeMenuOptions) : optionsPtr{move(optionsPtr)}
{                                              
  //menuStackPtr->push(*this);
  displayMenu(spaceBeforeMenu, spaceBeforeMenuOptions);
}


Menu::Menu(optionsVecPtr optionsPtr,
           shared_ptr<stack<Menu>> menuStack_Ptr,
           string spaceBeforeMenu,
           string spaceBeforeMenuOptions) : optionsPtr{move(optionsPtr)}
                                            //menuStackPtr{menuStack_Ptr} 
{
  //menuStackPtr->push(*this);
  displayMenu(spaceBeforeMenu, spaceBeforeMenuOptions);
}


Menu::~Menu() {
  //menuStackPtr->pop();
}





void Menu::displayMenu(string spaceBeforeMenu, string spaceBeforeMenuOption) {

  int functionNum{0};
  
  cout << spaceBeforeMenu;      
  for (auto option : *optionsPtr) {
    cout << spaceBeforeMenuOption 
         << (functionNum++) + 1 << " - " 
         << option.description  << endl;
  } 
  int previousMenuOption = functionNum+1;
  int exitOption         = functionNum+2;

  cout << spaceBeforeMenuOption << previousMenuOption 
                                << " - Previous Menu"      << endl;
  cout << spaceBeforeMenuOption << exitOption << " - Exit" << endl;
  
  
  // minus 1 for vector selection  
  int choice = getUserInput<int>("Selection") - 1;


  if (choice > exitOption) 
    cout << "\n\nChoice is out of range";  
  
  else if (choice == exitOption)  
    exit(1); 
  
  //else if (choice == previousMenuOption) 
          
  else    
    (*optionsPtr.get()->at(choice).menuFunction.get())();
  
}

/*shared_ptr<stack<Menu>> Menu::getMenuStackPtr() {
  return menuStackPtr;
}*/





Menu::MenuFunction::
MenuFunction(string description, functionPtr menuFunction) : 
  description{description}, menuFunction{menuFunction} {}
