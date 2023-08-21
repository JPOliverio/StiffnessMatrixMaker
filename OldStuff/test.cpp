#include <iostream>
#include <vector>
#include <list>
#include <variant>

using namespace std;

int main(){


      vector<variant<string, double>> vec {'c', 0};

      cout<<vec[0]<<endl;


  


 return 0;   
}


