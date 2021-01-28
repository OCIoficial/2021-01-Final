#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int get_min_cost(vector<vector<int>> grid, int h, int w, int m, int n) {
    vector<vector<int>> min_col_z(h - m + 1, vector<int>(w));
    vector<vector<int>> max_col_z(h - m + 1, vector<int>(w));
    multiset<int> min_window, max_window;
    int min_cost = 1000;

    for (int j = 0; j < w; j++) {
        // Fill window with subgrid (0, j) -> (m, j + 1)
        for (int i = 0; i < m; i++) {
            min_window.insert(grid[i][j]);
        }

        min_col_z[0][j] = *min_window.cbegin();
        max_col_z[0][j] = *min_window.crbegin();

        for (int i = 0; i < h - m; i++) {
            // Shift window: replace (i, j) with (m + i, j)
            min_window.erase(min_window.find(grid[i][j]));
            min_window.insert(grid[m + i][j]);
            min_col_z[i + 1][j] = *min_window.cbegin();
            max_col_z[i + 1][j] = *min_window.crbegin();
        }

        min_window.clear();
    }

    for (int i = 0; i < h - m + 1; i++) {
        for (int j = 0; j < n; j++) {
            // Fill windows with (i, 0) -> (i + 1, n) (representing subgrid (i, 0) -> (i + m, n))
            min_window.insert(min_col_z[i][j]);
            max_window.insert(max_col_z[i][j]);
        }

        min_cost = min(min_cost, *max_window.crbegin() - *min_window.cbegin());

        for (int j = 0; j < w - n; j++) {
            // Shift windows: replace (i, j) with (i, n + j) (representing subgrid (i, j) -> (i + m, j + n))
            min_window.erase(min_window.find(min_col_z[i][j]));
            min_window.insert(min_col_z[i][n + j]);
            max_window.erase(max_window.find(max_col_z[i][j]));
            max_window.insert(max_col_z[i][n + j]);

            min_cost = min(min_cost, *max_window.crbegin() - *min_window.cbegin());
        }

        min_window.clear();
        max_window.clear();
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
