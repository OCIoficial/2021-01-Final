#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  char line[N + 1];
  cin.getline(line, 1);
  cin.getline(line, N + 1);

  vector<int> counts(26);
  for (auto c : line) {
    if ('A' <= c && c <= 'Z') {
      counts[c - 'A'] += 1;
    }
  }

  int argmax = -1;
  int valmax = -1;
  for (int i = 0; i < 26; ++i) {
    if (counts[i] > valmax) {
      valmax = counts[i];
      argmax = i;
    }
  }

  cout << (argmax - ('E' - 'A') + 26) % 26 << "\n";

  return 0;
}