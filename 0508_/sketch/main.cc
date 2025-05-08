import <iostream>;
import <iomanip>;
import <string>;
import <fstream>;


using namespace std;

int lecture_streams() {
  // streams are an abstraction of adding output to something and remove
  //   input from something

  // Q: What can be treated like a stream in C++?
  // A: 1) Files 2) stringstreams

  // FILES
  // In C:
  // 1) open file
  // 2) check if successful
  // 3) ...
  // 4) close file

  // Read strings from suite.txt
  ifstream in { "suite.txt" }; // in READ mode
  if(in.fail()) return -1; // closes in
  string word;
  while(in >> word) { cout << word << endl; }

  // ISTREAM ~~ IFSTREAM
  istream *inp = &cin;
  if(true) inp = new ifstream{ "name.txt" };
  else inp = &in;
  *inp >> word;

  return 0; // closes in
}

// std::istream used unary ! as a function that falls fail()

void io_manip() {
  // used to format output
  
  // print in hexadecimal
  int num { 95 };
  cout << hex << num << endl;
  // best practice: reset cout
  cout << dec;

  cout << noskipws;
  cout << skipws;
  cout << setw(10);
  cout << setfill('.');
  cout << showpoint;
  cout << setprecision(2);
  // etc

  return;
}

int lecture_string() {
  // c-style strings were bad.
  // char[] decay to pointers
  // manual memory management is bad.
  // null-termination is bad.

  // COMPILER BUGS:
  // --version <=g++-14 ==> HAS TO BE COMPILED **LAST**

  // string:
  // - handles all memory managements
  // - resizes as needed
  // - handles null terminations
  // - .search
  // - .substring

  string s1; // s1 == ""; 
  if(s1.length() == 0) { }
  if(s1.size()   == 0) { }

  string s2 = "Hello"; // s2 == "Hello";
  string s3 { "World" };
  string s33 = { "Universe" };

  if(s1 == s2 || s2 != s3) { }
  if(s1 <= s3) { }
  s1 = s2 + s3; // s1 == "HelloWorld"
  s2 += s3; // s2 == "HelloWorld"
  cin >> s1; // skips leading whitespace then reads until whitespace
  cout << s1 << endl; // failure??
  getline(cin, s1); // "\n" -> "" if cin is before a newline, returns ""
 
  while(getline(cin, s1)) {
    cout << s1 << endl;
  }

  return 0;
}

int int_reading() {
  int i;

  // I
  while(true) {
    cin >> i;
    if(cin.fail()) break;
    cout << i << endl;
  }

  // II
  // * uses unary ! on cin to call cin.fail() (OPERATOR OVERLOAD)
  while(true) {
    cin >> i;
    if(!cin) break;
    cout << i << endl;
  }

  // std::istream can type coerce the object to a bool to call !fail()
  while(true) {
    cin >> i;
    if(cin) cout << i << endl;
    else break;
  }

  // operator>> returns std::istream
  while(cin >> i) cout << i << endl;
  // 1. cin >> i | -> istream
  // 2. istream -> bool | calls !fail
  // 3.1. !fail => cout << i << endl;
  // 3.2. fail => break;

  // fail => UB 
  // eof  => recover??
  //
  // We want to recover from errors.

  // consider the case where we want to read and output ints until EOF, but 
  //   skip non-ints.

  // ----------------------------------------------------------------------- //

  // fail -> true if EOF or ERROR
  while(true) {
    // error
    if(!cin) {
      if(cin.eof()) break; // cin is a std::basic_istream
      //cin.ignore();
      // by default throws away
      //   1 char's worth of data
      //
      // HOWEVER, the fail bit is set!
      // So reading is "bad", be careful.

      cin.clear(); // pretend there's no failure.
      cin.ignore(); // throw away char

    } else cout << i << endl;
  }

  // 3.14 xy -1
  //
  // 3
  // i = 3
  // => 3\n
  // . | FAIL CLEAR IGNORE 
  // 14
  // i = 14
  // => 14\n
  // xy | FAIL CLEAR IGNORE
  // y | FAIL CLEAR IGNORE
  // -1
  // i = -1
  // => -1\n
  // EOF | FAIL EOF BREAK 


  return 0;
}






int best_int_method() { // works
  int i { 0 };
  while(cin >> i) cout << i << endl;
  return 0;
}

int read_file() {
  ifstream file { "data.txt" };
  string word;
  if(!file) { cerr << "data.txt not found" << endl; return -1; }
  else while(getline(file, word)) cout << word << endl;
  return 0;
}











int main() {
  return read_file();
}
