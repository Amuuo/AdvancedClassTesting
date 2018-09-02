#include<iostream>
#include<stack>
#include"Menu.h"
#include"Test.h"


using MenuFunction      = Menu::MenuFunction;
using MenuFunctionsVec  = vector<MenuFunction>;

Test test1{"test 1"};
Test test2{"test 2"};

MenuFunctionsVec mainMenuOptionsList
{     
  {
    "run test 1", 
    make_shared<function<void()>>([]()
    { 
      test1.runMenu();
    })
  },    
  
  {
    "run test 2", 
    make_shared<function<void()>>([]()
    { 
      test2.runMenu();
    })
  }
};


int main() 
{

  Menu menu{ make_unique<MenuFunctionsVec>(mainMenuOptionsList), "Main"};
  
  do 
  {
    system("clear");  
  } 
  while(menu.displayMenu());
      

  return 0;
}