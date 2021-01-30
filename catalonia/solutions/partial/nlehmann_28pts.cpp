#include <iostream>
using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;

  long long left = 0, right = 1000000000;
  while (left < right) {
    long long i = left + (right - left) / 2;
    if (3 * i * (i + 1) + 1 > b) {
      right = i;
    } else {
      left = i + 1;
    }
  }
  printf("%d\n", left);
}