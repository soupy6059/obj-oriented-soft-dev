// string streams
// argument parsing
// overloading
// * default values
// * overloading function with types and number of params
//
// There's no overloading in c.
// function names cannot be differentiated by
//   type alone. ==> uniq function names required
// C++ allows overloading
// ==> function names can be unique.
// ==> but the parameter numbers have to be
//     unique
//     or the types have to be unique,
//     or some combination
// NOTE: the return type isn't taken 
//       into consideration.
import <iostream>;
import <fstream>;
using namespace std;

bool neg(bool b) { return !b; }
int neg(int i) { return -i; }

// we could use default parameters
//void printSuite() {
//  ifstream in{"suite.txt"};
//  string s;
//  while(in >> s) {
//    cout << s << endl;
//  }
//  // printSuite(string{"suite.txt"});
//}

// RULES
// 1. all default values have to groups together at the end of the param list
// 2. default values can only be specified in the interface (header file)
void printSuite(string fname = "suite.txt") {
  ifstream in{fname};
  string s;
  while(in >> s) {
    cout << s << endl;
  }
}

int main(int argc, char *argv[]) {
  if(argc == 2) printSuite(string{argv[1]});
  else printSuite();
}
