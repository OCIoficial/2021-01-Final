#include <set>

#include "testlib.h"
using namespace std;

int main() {
  registerValidation();
  int N = inf.readInt(2, 100);
  inf.readSpace();
  int P = inf.readInt(1, 1000);
  inf.readEoln();

  set<pair<int, int>> games;
  for (int i = 0; i < P; ++i) {
    int a = inf.readInt(0, N - 1);
    inf.readSpace();
    int b = inf.readInt(0, N - 1);
    inf.readSpace();
    int c = inf.readInt();
    inf.readEoln();
    ensure(a < b);
    ensure(c == a || c == b || c == -1);

    ensure(!games.count({a, b}));

    games.insert({a, b});
  }

  inf.readEof();
}