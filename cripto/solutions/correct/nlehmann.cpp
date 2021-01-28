#include <iostream>
#include <vector>
using namespace std;

float freq[] = {0.1224,  0.0147, 0.0361, 0.0532, 0.1397, 0.0046, 0.0105,
                0.0122,  0.0547, 0.0065, 0.0543, 0.0272, 0.0687, 0.0991,
                0.0216,  0.0199, 0.0615, 0.0767, 0.0376, 0.0486, 0.0109,
                0.00001, 0.0002, 0.0153, 0.0040};

int main() {
  int N;
  cin >> N;

  char line[N + 1];
  cin.getline(line, 1);
  cin.getline(line, N + 1);

  vector<int> counts(26);
  int total = 0;
  for (auto c : line) {
    if ('A' <= c && c <= 'Z') {
      counts[c - 'A'] += 1;
      total += 1;
    }
  }

  float valmin = 1e304;
  float argmin = -1;
  for (int k = 0; k < 26; ++k) {
    float err = 0;
    for (int i = 0; i < 26; ++i) {
      err += abs(1.0 * counts[i] / total - freq[(i - k + 26) % 26]);
    }
    if (err < valmin) {
      valmin = err;
      argmin = k;
    }
  }

  cout << argmin << "\n";

  return 0;
}