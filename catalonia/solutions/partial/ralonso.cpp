#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<array>
#include<algorithm>

using namespace std;

array<pair<int, int>, 6> directions = {{{0, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, 0}, {1, 1}}};

pair<int, int> locate(long long n) {
    int r, x, y;
    
    // #anillo de n es r tal que 6 * r * (r - 1) / 2 < n <= 6 * r * (r + 1) / 2

    // secuencial es muy lento para 1e18, es mejor búsqueda binaria o resolución exacta
    // if (n == 0LL) return make_pair(0, 0);
    // for (r = 0; n > 3LL * r * (r + 1); r++);

    r = (int) ceil(sqrt(n / 3.0 + 0.25) - 0.5);

    // contamos lo que hay que moverse en el anillo r para llegar a la posición n
    n -= 3LL * r * (r - 1);

    x = r;
    y = 0;

    for (auto d: directions) {
        if (n > r) {
            x += r * get<0>(d);
            y += r * get<1>(d);
            n -= r;
        } else {
            x += n * get<0>(d);
            y += n * get<1>(d);
            break;
        }
    }
    return make_pair(x, y);
}

int dist(pair<int, int> s, pair<int, int> t) {
    int dx = get<0>(t) - get<0>(s);
    int dy = get<1>(t) - get<1>(s);
    int dz = dx - dy;
    return min(min(abs(dx) + abs(dy), abs(dy) + abs(dz)), abs(dz) + abs(dx));
}

int main() {
    long long a, b;

    scanf("%lld%lld", &a, &b);

    pair<int, int> ca = locate(a);
    pair<int, int> cb = locate(b);
    
    printf("%d\n", dist(ca, cb));

    return 0;
}
