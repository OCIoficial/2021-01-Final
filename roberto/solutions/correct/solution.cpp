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
    elements.erase(arr[i - 1]);
    elements.insert(arr[i + w - 1]);
    mins[i] = *elements.begin();
    maxs[i] = *elements.rbegin();
  }

  return {mins, maxs};
}

int main() {
  int M, N, A, B;
  scanf("%d%d%d%d", &M, &N, &A, &B);

  vector<vector<int>> terrain(M, vector<int>(N));

  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      scanf("%d", &terrain[i][j]);
    }
  }

  vector<vector<int>> mins_for_row(M);
  vector<vector<int>> maxs_for_row(M);
  for (int i = 0; i < M; ++i) {
    tie(mins_for_row[i], maxs_for_row[i]) = compute_min_max_arrs(terrain[i], B);
  }

  int best = INT_MAX;
  for (int j = 0; j + B - 1 < N; ++j) {
    multiset<int> elements_min;
    multiset<int> elements_max;

    for (int i = 0; i < A; ++i) {
      elements_min.insert(mins_for_row[i][j]);
      elements_max.insert(maxs_for_row[i][j]);
    }
    best = min(best, *elements_max.rbegin() - *elements_min.begin());
    for (int i = 1; i + A - 1 < M; ++i) {
      elements_min.erase(mins_for_row[i - 1][j]);
      elements_min.insert(mins_for_row[i + A - 1][j]);
      elements_max.erase(maxs_for_row[i - 1][j]);
      elements_max.insert(maxs_for_row[i + A - 1][j]);

      best = min(best, *elements_max.rbegin() - *elements_min.begin());
    }
  }
  printf("%d\n", best);
}