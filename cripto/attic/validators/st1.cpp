#include "testlib.h"

using namespace std;

int main() {
  registerValidation();

  int N = inf.readInt(50, 1000, "LENGTH");
  inf.readEoln();

  for (int i = 0; i < N; ++i) {
    char c = inf.readChar();
    ensuref(c == ' ' || ('A' <= c && c <= 'Z'), "Invalid caracter");
  }
  inf.readEoln();
  inf.readEof();
}
