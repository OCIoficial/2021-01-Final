#include "testlib.h"

using namespace std;

int main() {
  registerValidation();

  long long a = inf.readInt(0, 0, "a");
  inf.readSpace();
  long long b = inf.readLong(a + 1, 1000000000000000000, "b");
  inf.readEoln();
  inf.readEof();
}
