#include <iostream>
using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;

  int ring = 0;
  int count = 1;
  while (count <= b) {
    count += 6 * ring;
    ring += 1;
  }
  printf("%d\n", ring - 1);
}