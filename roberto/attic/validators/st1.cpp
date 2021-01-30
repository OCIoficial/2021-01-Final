#include "testlib.h"

using namespace std;

int main() {
  registerValidation();

  long H = inf.readLong(0LL, 1000000LL, "H");
  inf.readSpace();
  long W = inf.readLong(0LL, 1000000LL, "W");
  inf.readSpace();
  long M = inf.readLong(0LL, H, "M");
  inf.readSpace();
  long N = inf.readLong(0LL, W, "N");
  inf.readEoln();
  ensure(M * N <= 1000000);

  ensure(H == W && W == M && M == N);

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (j > 0) inf.readSpace();
      inf.readInt(0, 1000000);
    }
    inf.readEoln();
  }
  inf.readEof();
}
