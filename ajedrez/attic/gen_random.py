import random
import sys

random.seed(str(sys.argv[1:]))

N = int(sys.argv[2])
P = int(sys.argv[3])

assert(P <= (N * (N - 1)) / 2)


def pairs_iter(N):
    for a in range(N):
        for b in range(a + 1, N):
            yield (a, b)


print(N, P)

for (a, b) in random.sample(list(pairs_iter(N)), P):
    w = random.choice([a, b, -1])
    print(a, b, w)
