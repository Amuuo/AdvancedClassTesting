#pragma once
#include"Menu.h"

using namespace std;

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


    Menu   menu{make_unique<MenuFunctionsVec>(MenuOptions), title};
};

