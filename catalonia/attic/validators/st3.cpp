#include "testlib.h"

using namespace std;

int main() {
  registerValidation();

  int a = inf.readInt(0, 100000, "a");
  inf.readSpace();
  int b = inf.readInt(a + 1, 100000, "b");
  inf.readEoln();
  inf.readEof();
}
