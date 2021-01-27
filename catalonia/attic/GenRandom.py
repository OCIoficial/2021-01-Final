import random
import sys

random.seed(str(sys.argv[1:]))
N = int(sys.argv[2])

a = random.randint(0, N - 1)
b = random.randint(a + 1, N)

print(a, b)
