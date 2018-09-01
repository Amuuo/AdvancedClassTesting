#include<iostream>
#include"Menu.h"


  using MenuFunctions        = Menu::MenuFunctions;
  using MenuFunctionsPtr     = shared_ptr<MenuFunctions>;
  using MenuFunctionsPtrVec  = vector<MenuFunctionsPtr>;

  static auto test1 = []() { std::cout << "\n\ntest 1"; };
  static auto test2 = []() { std::cout << "\n\ntest 2"; };
  
  static MenuFunctions menu1{"Run test 1", make_shared<function<void()>>(test1)};
  static MenuFunctions menu2{"Run test 2", make_shared<function<void()>>(test2)};

  static vector<shared_ptr<MenuFunctions>> menuList{
    make_shared<MenuFunctions>(menu1), 
    make_shared<MenuFunctions>(menu2)};

  void runMenu() {

    Menu mainMenu{make_unique<MenuFunctionsPtrVec>(menuList)};

}


int main() {

  runMenu();

  return 0;
}