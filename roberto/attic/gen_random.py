import random
import sys

random.seed(str(sys.argv[1:]))

h = int(sys.argv[2])
w = int(sys.argv[3])
m = int(sys.argv[4])
n = int(sys.argv[5])

modo = int(sys.argv[6])
aux1 = int(sys.argv[7])
aux2 = int(sys.argv[8])

maxlim = 1000

print(h, w, m, n)

for i in range(h):
	for j in range(w):

		if modo == 1:
			if j == w - 1:
				print(random.randint(1, maxlim))
			else:
				print(random.randint(1, maxlim), end = " ")

		if modo == 2:
			if j == w - 1:
				print(random.randint(max(0, aux1 - aux2), min(aux1 + aux2, maxlim)))
			else:
				print(random.randint(max(0, aux1 - aux2), min(aux1 + aux2, maxlim)), end = " ")
