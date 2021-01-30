#include<cstdio>
#include<climits>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int get_min_cost(vector<vector<int>> grid, int h, int w, int m, int n) {
    multiset<int> window;
    int min_cost = INT_MAX;

    for (int i = 0; i < h - m + 1; i++) {
        for (int di = 0; di < m; di++) {
            for (int dj = 0; dj < n; dj++) {
                // Fill windows with (i, 0) -> (i + m, n)
                window.insert(grid[i + di][dj]);
            }
        }

        min_cost = min(min_cost, *window.crbegin() - *window.cbegin());

        for (int j = 0; j < w - n; j++) {
            // Shift windows: replace (i + di, j) with (i + di, j + n)
            for (int di = 0; di < m; di++) {
                // Shift window: replace (i + di, j) with (i + di, j + n)
                window.erase(window.find(grid[i + di][j]));
                window.insert(grid[i + di][j + n]);
            }

            min_cost = min(min_cost, *window.crbegin() - *window.cbegin());
        }

        window.clear();
    }

    return min_cost;
}

int main() {
    int h, w, m, n;

    scanf("%d%d%d%d", &h, &w, &m, &n);

    vector<vector<int>> terrain(h, vector<int>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &(terrain[i][j]));
        }
    }

    printf("%d\n", get_min_cost(terrain, h, w, m, n));

    return 0;
}
