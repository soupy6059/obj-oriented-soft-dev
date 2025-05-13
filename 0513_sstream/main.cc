import <iostream>;
import <sstream>;
import <string>;
using namespace std;

int string_streams() {
  // istringstream
  // - read data as characters from (internal) string
  // - type conversion, parsing a string into words
  //
  // ostringstream
  // - send data as chars to (internal) string
  // - add mulpiple types to string
  // - convert to string

  // readIntsSS.cc
  string n;
  while(cin >> n) { // ONLY FAILS ON EOF
    istringstream iss { n };
    int i;
    if(iss >> i) cout << i << endl;
  }

  return 0;
}

int string_streams2() {
  string n, extra;
  int i;
  while(cin >> n) {
    if(istringstream iss {n}; iss >> i) {
      if(iss >> extra) cerr << "Warning " << n << endl;
      else cout << i << endl;
    }
  }
  return 0;
}

int string_streams3() {
  string n; int i;
  while(cin >> n) {
    if(istringstream {n} >> i) cout << i << endl;
  }
  return 0;
}

int get_num() {
  int i;
  while(true) {
    string s;
    cout << "Enter a number: ";
    cin >> s; // get string
    if(istringstream{s} >> i) break; // good int => break
    cout << "I said, ";
  }
  cout << i << endl;
  return 0;
}

// X11 |||||| A4
// Xwindow xw;
// int score { 0 };
// ...
// ++score;
// ...
// ostringstream oss;
// oss << "Score: " << score;
// xw.draw_string(10,10,oss.str().c_str()); // extracts c++ string from oss
//                                          // AND gets the c string 


// command line arguements
// c++ uses c approach:
int main_old(int argc, char *argv[]) {
  // argc := array size + 1
  // argv := c-style string array

  // $PATHTOPROG/a.out 123 pgm
  // ==> arg c == 3
  // 0 -> "./a.out\0" | COMMNAD
  // 1 -> "123\0"     | argv[1]
  // 2 -> "pgm\0"     | argv[2]
  // 3 -> nullptr     | END
  //
  // assert(argv[argc] == nullptr);
  // if(argc >= 2) ARGUMENTS
  // if(argc == 1) NO ARGS

  if(argc < 2) { 
    cerr << "ARGC IS LESS THAN 2!" << endl;
    return -1;
  }
  for(int i = 1; i < argc; ++i) {
    string myarg { argv[i] }; 
    // HANDLE ARGUMENTS W/ C++ STRING
  }

  return 0;
}

// args-sum.cc
int main(int argc, char *argv[]) {
  if(argc < 2) return -1;
  int total { 0 }, n { 0 };
  for(int i = 1; i < argc; ++i) {
    string a { argv[i] };
    if(istringstream{a} >> n) total += n;
    /*
     * if(istringstream{string{argv}} >> n)
     *   total += n;
     */
  }
  cout << total << endl;
  return 0;
}













