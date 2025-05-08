import <iostream>;
import <fstream>;
import <string>;

int main() {
  using namespace std;
  ifstream file { "data.txt" };
  if(!file) return -1;
  string word;
  while(getline(file, word)) cout << word << endl;
  return 0;
}
