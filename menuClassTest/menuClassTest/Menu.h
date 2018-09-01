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
using std::endl;




class Menu {

public:  
  
  using functionPtr = shared_ptr<function<void()>>;
  
  static struct MenuFunction {
    
    MenuFunction(string,functionPtr);
    string       description;
    functionPtr  menuFunction;
  };
    
  using optionsVecPtr = unique_ptr<vector<MenuFunction>>;
  
  Menu();
  Menu(optionsVecPtr, string="", string="");
  
  
  virtual ~Menu();  
  virtual void displayMenu(string="",string="");
  

private:
  
  
  optionsVecPtr optionsPtr;
  optionsVecPtr previousMenuPtr;
};

