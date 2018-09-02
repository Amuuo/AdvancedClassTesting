#include "Test.h"



Test::
Test() 
{ 
}

Test::
Test(string title) : title{title}
{ 
}

Test::
Test(const Test & test) 
{
  title = test.title;
  test1value = test.test1value;
  test2value = test.test2value;
}

Test::
~Test() {}






void Test::
runMenu() 
{     
  do
  {
    system("clear");
    cout << "\n\n";
    cout << "\ttest1value: " << test1value << endl;
    cout << "\ttest2value: " << test2value << endl;
  
  } while(menu.displayMenu());
}

void Test::deleteTest() {
  delete this;
}
