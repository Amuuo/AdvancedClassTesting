#pragma once
#include"Menu.h"

using std::make_shared;
using std::function;
using std::cout;
using std::vector;
using std::make_unique;


class Test {

public:
  
  using MenuFunction     = Menu::MenuFunction;
  using MenuFunctionsVec = vector<MenuFunction>;

  Test();
  ~Test();
  void runMenu();


private:

  MenuFunctionsVec MenuOptions{ 
  
    {"First option from test class", 
      make_shared<function<void()>>([this](){
        this->test1value++; 
        cout << "\n\tFirst test successfully ran...";})},
    
    {"Second option from test class",
      make_shared<function<void()>>([this](){
        this->test2value++; 
        cout << "\n\tSecond test successfully ran...";})}  
  };
  
  int test1value{10};
  int test2value{20};
};

