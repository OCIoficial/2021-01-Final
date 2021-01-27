import random
import sys

random.seed(str(sys.argv[1:]))
N = int(sys.argv[2])

print(0, random.randint(50, N))
