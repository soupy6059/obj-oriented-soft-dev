import <iostream>;
using namespace std;

struct Vector3 {
  double x;
  double y;
  double z;
  Vector3 operator+(const Vector3 &other) const {
    return {
      .x = this->x + other.x,
      .y = this->y + other.y,
      .z = this->z + other.z,
    };
  }
  static double dot_product(const Vector3 &V, const Vector3 &U) {
    return V.x * U.x + V.y * U.y + V.z * U.z;
  }
};

ostream &operator<<(ostream &os, const Vector3 &V) {
  os << '[' << V.x << ' ' << V.y << ' ' << V.z << ']';
  return os;
}

void extra() {
  Vector3 V = { 1, 2, 3 };
  Vector3 U = { 3, 2, 1 };
  Vector3 Z = U + V;
  cout << Z << '\n';
  cout << Vector3::dot_product(V, U) << '\n';
}

int main() {
  extra();
  return 0;

  int x, y;
  // PROTOCALL: read then test
  cin >> x >> y;
  if(cin.good()) cout << x + y << endl;
  return 0;
}

// use CTRL-d (<C-c> is a hard kill)
// input errors??
/*
 * Q: How do we tell if the read failed?
 * A: ask std::cin
 * if(cin.eof()) {
 * //EOF
 * }
 * if(cin.fail()) {
 * // EOF or NOT INT
 * }
 * if(cin.good()) {
 * // succeeded
 * }
 *
 * Q: How do we read integers? and output 1 per line, stopping
 *      at an EOF or error?
 */
