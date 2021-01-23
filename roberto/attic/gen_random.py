import random
import sys

random.seed(str(sys.argv[1:]))

h = int(sys.argv[2])
w = int(sys.argv[3])
m = int(sys.argv[4])
n = int(sys.argv[5])

print(h, w, m, n)

for i in range(h):
    for j in range(w):
        if j == w - 1:
            print(random.randint(1, 1000))
        else:
            print(random.randint(1, 1000), end = " ")
