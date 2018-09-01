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



using optionsVec = vector<function<void()>>;
using functionPtr = shared_ptr<function<void()>>;


class Menu {

public:  
  

  struct MenuFunctions {
    
    MenuFunctions(string, functionPtr);
    
    string      description;
    functionPtr menuFunction;
  };
  
  using optionsVecPtr = shared_ptr<vector<shared_ptr<MenuFunctions>>>;
  
  Menu();
  Menu(optionsVecPtr);
  
  virtual ~Menu();  
  virtual void displayMenu(string="",string="");
  

  
  
private:
  
  
  optionsVecPtr optionsPtr;

};

