import random
import sys

random.seed(str(sys.argv[1:]))

h = int(sys.argv[2])
w = int(sys.argv[3])
m = int(sys.argv[4])
n = int(sys.argv[5])

lower = int(sys.argv[6])
upper = int(sys.argv[7])

maxlim = 1000000

values = ((random.randint(lower, upper) for i in range(w)) for j in range(h))

print(h, w, m, n)

for row in values:
    print(" ".join(map(str, row)))
