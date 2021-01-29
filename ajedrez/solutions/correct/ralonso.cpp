#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n, p;

  scanf("%d%d", &n, &p);

  vector<int> scores(n, 0);

  for (int i = 0; i < p; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if (c == -1) {
      scores[a]++;
      scores[b]++;
    } else {
      scores[c] += 2;
    }
  }
  int max_score = *max_element(begin(scores), end(scores));

  // Print in descending order to verify the checker is working properly.
  for (int i = n - 1; i >= 0; i--) {
    if (scores[i] == max_score) {
      printf("%d\n", i);
    }
  }
  return 0;
}
