#include "Test.h"



Test::Test() {
  cout << "\n\n";
  cout << "\ttest1value: " << test1value << endl;
  cout << "\ttest2value: " << test2value << endl;
  runMenu();
}

Test::~Test() {}


void Test::runMenu() {
  
  Menu testMenu{make_unique<MenuFunctionsVec>(MenuOptions), "\n\n", "\t"};
  

  cout << "\n\n";
  cout << "\ttest1value: " << test1value << endl;
  cout << "\ttest2value: " << test2value << endl;
}
