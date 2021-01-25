#include <cstdio>
#include <tuple>
#include <array>

using namespace std;

const array<double, 26> FREQUENCIES = {
    0.1216,
    0.0149,
    0.0387,
    0.0467,
    0.1408,
    0.0069,
    0.0100,
    0.0118,
    0.0598,
    0.0052,
    0.0011,
    0.0524,
    0.0308,
    0.0700,
    0.0920,
    0.0289,
    0.0111,
    0.0641,
    0.0720,
    0.0460,
    0.0469,
    0.0105,
    0.0004,
    0.0014,
    0.0109,
    0.0047
};

void print_frequencies(array<int, 26> counts, int k, int total) {
    for (int i = 0; i < 26; i++) {
        fprintf(stderr, "%c: %f\n", 'A' + i, counts[(26 + i - k) % 26] / (double) total);
    }
}

int main() {
    char c;
    int total = 0;
    array<int, 26> counts = {};

    do {
      c = getc(stdin);
      if ('A' <= c && c <= 'Z') {
          counts[c - 'A']++;
          total++;
      }
    } while (c != EOF);

    double min_error = 1e304;
    int argmin_error = -1;

    for (int k = 0; k < 26; k++) {
        double error = 0;
        for (int i = 0; i < 26; i++) {
            double difference = 1.0 * counts[i] / total - FREQUENCIES[(26 + i - k) % 26];
            error += difference * difference;
        }
        if (error < min_error) {
            min_error = error;
            argmin_error = k;
        }
    }

    fprintf(stderr, "%d: %f\n", argmin_error, min_error);
    print_frequencies(counts, argmin_error, total);
    printf("%d\n", argmin_error);

    return 0;
}
