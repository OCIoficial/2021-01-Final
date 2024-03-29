#include<cstdio>
#include<climits>
#include<algorithm>

using namespace std;

int main() {
    int h, w, z;
    int minz = INT_MAX, maxz = 0;

    scanf("%d%d%d%d", &h, &w, &z, &z);

    for (int _ = 0; _ < w * h; _++) {
        scanf("%d", &z);
        minz = min(minz, z);
        maxz = max(maxz, z);
    }

    printf("%d\n", maxz - minz);

    return 0;
}
