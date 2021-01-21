#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  fstream expected_file, out_file;

  expected_file.open(argv[2], ios::in);
  out_file.open(argv[3], ios::in);

  vector<int> expected;
  while (expected_file >> n) {
    expected.push_back(n);
  }
  sort(expected.begin(), expected.end());

  vector<int> out;
  while (out_file >> n) {
    out.push_back(n);
  }
  sort(out.begin(), out.end());

  if (out.size() != expected.size()) {
    cout << "0.0";
  } else {
    for (int i = 0; i < expected.size(); ++i) {
      if (expected[i] != out[i]) {
        cout << "0.0";
        return 0;
      }
    }
    cout << "1.0";
  }
  return 0;
}