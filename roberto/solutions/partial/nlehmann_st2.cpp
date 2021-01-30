#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;

int main() {
  int H, W, M, N;
  scanf("%d%d%d%d", &H, &W, &M, &N);

  int terrain[H][W];
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      scanf("%d", &terrain[i][j]);
    }
  }

  int best = INT_MAX;
  for (int i = 0; i < H - M + 1; ++i) {
    for (int j = 0; j < W - N + 1; ++j) {
      int vmax = -1;
      int vmin = INT_MAX;
      for (int y = 0; y < M; ++y) {
        for (int x = 0; x < N; ++x) {
          vmax = max(vmax, terrain[i + y][j + x]);
          vmin = min(vmin, terrain[i + y][j + x]);
        }
      }
      best = min(best, vmax - vmin);
    }
  }

  printf("%d\n", best);
}
