#include <algorithm>
#include <climits>
#include <cstdio>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

pair<vector<int>, vector<int>> compute_min_max_arrs(const vector<int> &arr,
                                                    int w) {
  vector<int> mins(arr.size() - w + 1);
  vector<int> maxs(arr.size() - w + 1);
  multiset<int> elements;

  for (int i = 0; i < w; ++i) {
    elements.insert(arr[i]);
  }
  mins[0] = *elements.begin();
  maxs[0] = *elements.rbegin();

  for (int i = 1; i + w - 1 < arr.size(); ++i) {
    elements.erase(elements.find(arr[i - 1]));
    elements.insert(arr[i + w - 1]);
    mins[i] = *elements.begin();
    maxs[i] = *elements.rbegin();
  }

  return {mins, maxs};
}

int main() {
  int H, W, M, N;
  scanf("%d%d%d%d", &H, &W, &M, &N);

  vector<vector<int>> terrain(H, vector<int>(W));

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      scanf("%d", &terrain[i][j]);
    }
  }

  vector<vector<int>> mins_for_row(H);
  vector<vector<int>> maxs_for_row(H);
  for (int i = 0; i < H; ++i) {
    tie(mins_for_row[i], maxs_for_row[i]) = compute_min_max_arrs(terrain[i], N);
  }

  int best = INT_MAX;
  for (int j = 0; j + N - 1 < W; ++j) {
    multiset<int> elements_min;
    multiset<int> elements_max;

    for (int i = 0; i < M; ++i) {
      elements_min.insert(mins_for_row[i][j]);
      elements_max.insert(maxs_for_row[i][j]);
    }
    best = min(best, *elements_max.rbegin() - *elements_min.begin());
    for (int i = 1; i + M - 1 < H; ++i) {
      elements_min.erase(elements_min.find(mins_for_row[i - 1][j]));
      elements_min.insert(mins_for_row[i + M - 1][j]);
      elements_max.erase(elements_max.find(maxs_for_row[i - 1][j]));
      elements_max.insert(maxs_for_row[i + M - 1][j]);

      best = min(best, *elements_max.rbegin() - *elements_min.begin());
    }
  }
  printf("%d\n", best);
}
