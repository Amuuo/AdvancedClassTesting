#include<iostream>
#include"Menu.h"



int main() {

  auto test1 = []() { std::cout << "\n\ntest 1"; };
  auto test2 = []() { std::cout << "\n\ntest 2"; };
  
  Menu::MenuFunctions menu1{"Run test 1", make_shared<function<void()>>(test1)};
  Menu::MenuFunctions menu2{"Run test 2", make_shared<function<void()>>(test2)};

  vector<shared_ptr<Menu::MenuFunctions>> menuList{
    make_shared<Menu::MenuFunctions>(menu1), 
    make_shared<Menu::MenuFunctions>(menu2)};

  Menu mainMenu{make_shared<vector<shared_ptr<Menu::MenuFunctions>>>(menuList)};


  return 0;
}