#pragma once

#include<memory>
#include<vector>
#include<functional>
#include<string>
#include<iostream>
#include<stack>
#include<algorithm>
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
using std::stack;
using std::transform;





class Menu
{


  public:  
  

    static struct MenuFunction 
    {
      using functionPtr = shared_ptr<function<void()>>;
  
      MenuFunction(string,functionPtr);
      string       description;
      functionPtr  menuFunction;
    };
    
    using optionsVecPtr = unique_ptr<vector<MenuFunction>>;
  

    Menu();
    Menu(optionsVecPtr, string="", string="\n\n", string="\t");
    ~Menu();  
  

    inline bool getMenuSelection(int, int);
    bool        displayMenu(int=0);
    void        setTitle(string);




  private:
  

    optionsVecPtr  optionsPtr{};
    string         title;
    string         spaceBeforeMenu;
    string         spaceBeforeMenuOptions;

};

