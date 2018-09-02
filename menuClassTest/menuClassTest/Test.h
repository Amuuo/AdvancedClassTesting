#pragma once
#include"Menu.h"

using std::make_shared;
using std::function;
using std::cout;
using std::vector;
using std::make_unique;


class Test 
{

  public:
  
    using MenuFunction     = Menu::MenuFunction;
    using MenuFunctionsVec = vector<MenuFunction>;

    Test();
    Test(string);
    Test(const Test&);
    ~Test();
    void runMenu();
    void deleteTest();


  private:

    MenuFunctionsVec MenuOptions
    {   
      {"First option from test class", 
        make_shared<function<void()>>([this](){
          this->test1value++; 
          cout << "\n\tFirst test successfully ran...\n\n";        
        })
      },
    
      {
        "Second option from test class",
        make_shared<function<void()>>([this](){
          this->test2value++; 
          cout << "\n\tSecond test successfully ran...\n\n";        
        })
      },      
    };
  

    string title{};
    bool   firstRun{true};
    int    test1value{10};
    int    test2value{20};
    
    //function<void(Test*)> funcPtr{&Test::deleteTest};
    Menu   menu{make_unique<MenuFunctionsVec>(MenuOptions), title};
};

