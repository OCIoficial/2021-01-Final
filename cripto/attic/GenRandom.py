import random
import sys

random.seed(str(sys.argv[1:]))
N = int(sys.argv[2])

a = random.randint(0, N)
b = random.randint(0, N)

print(str(a) + " " + str(b))