#include "testlib.h"

using namespace std;

int main() {
  registerValidation();

  long long a = inf.readLong(0LL, 1000000000000000000LL, "a");
  inf.readSpace();
  long long b = inf.readLong(a + 1, 1000000000000000000LL, "b");
  inf.readEoln();
  inf.readEof();
}
