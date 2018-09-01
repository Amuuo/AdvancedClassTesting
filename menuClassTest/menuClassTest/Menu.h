#pragma once
#include<memory>
#include<vector>
#include<functional>
#include<string>
#include<iostream>
#include"userIO.h"

using std::shared_ptr;
using std::function;
using std::vector;
using std::string;
using std::cout;
using std::make_shared;

using optionsVec = vector<function<void()>>;
using functionPtr = shared_ptr<function<void()>>;






class Menu {

public:  
  
  static struct MenuFunctions {
    
    MenuFunctions(string, functionPtr);
    
    string      description;
    functionPtr menuFunction;
  };
  
  using menuFunctionsPtr = shared_ptr<MenuFunctions>;
  using optionsVecPtr = shared_ptr<vector<menuFunctionsPtr>>;
  
  Menu();
  Menu(optionsVecPtr);
  
  virtual ~Menu();  
  virtual void displayMenu(string="",string="");
  

  
  
private:
  
  
  optionsVecPtr optionsPtr;

};

