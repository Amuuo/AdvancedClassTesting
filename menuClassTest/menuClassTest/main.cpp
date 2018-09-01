#include<iostream>
#include<stack>
#include"Menu.h"
#include"Test.h"


using MenuFunction      = Menu::MenuFunction;
using MenuFunctionsVec  = vector<MenuFunction>;



MenuFunctionsVec menuList{    
  {"run test 1", make_shared<function<void()>>([](){cout << "\n\n\ttest1!";})},    
  {"run test 2", make_shared<function<void()>>([](){cout << "\n\n\ttest2!";})}
};


void runMenu() {
    
  Menu mainMen {
    make_unique<MenuFunctionsVec>(menuList),"\n\n","\t"
  };

}


int main() {

  runMenu();
  
  cout << "\n\n\n\t";  
  system("PAUSE");

  Test test{};

  cout << "\n\n\n\t";  
  system("PAUSE");
  return 0;
}