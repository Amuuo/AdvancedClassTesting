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
using std::make_unique;
using std::unique_ptr;
using std::move;


using functionPtr = shared_ptr<function<void()>>;




class Menu {

public:  
  
  static struct MenuFunctions {
    
    MenuFunctions(string,functionPtr);
    string       description;
    functionPtr  menuFunction;
  };
  
  using menuFunctionsPtr  = shared_ptr<MenuFunctions>;
  using optionsVecPtr     = unique_ptr<vector<menuFunctionsPtr>>;
  
  Menu();
  Menu(optionsVecPtr, string="", string="");
  
  virtual ~Menu();  
  virtual void displayMenu(string="",string="");
  

private:
  
  
  optionsVecPtr optionsPtr;

};

