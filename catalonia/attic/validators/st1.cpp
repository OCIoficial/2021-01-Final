#include "testlib.h"

using namespace std;

int main() {
  registerValidation();

  int a = inf.readInt(0, 0, "a");
  inf.readSpace();
  int b = inf.readInt(a + 1, 36, "b");
  inf.readEoln();
  inf.readEof();
}
