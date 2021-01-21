#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int N, P;
  scanf("%d%d", &N, &P);

  vector<int> points(N);

  for (int i = 0; i < P; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (c == -1) {
      points[a] += 1;
      points[b] += 1;
    } else {
      points[c] += 2;
    }
  }
  int vmax = 0;
  for (int i = 0; i < N; ++i) {
    vmax = max(vmax, points[i]);
  }

  for (int i = 0; i < N; ++i) {
    if (points[i] == vmax) {
      printf("%d\n", i);
    }
  }

  return 0;
}