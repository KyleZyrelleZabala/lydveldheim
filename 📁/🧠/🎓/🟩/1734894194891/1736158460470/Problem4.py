import itertools

n=input()
r = list(itertools.combinations([c for c in str(n)],int(len(n)/2)))

data=[]
poss=[]

for x in r:
	data += list(itertools.permutations(x))
for x in data:
	poss += [int("".join(x))]
#for x in poss:
#	for y in poss:
#		if x*y == n:
#			print('Yes')
#			break
print(poss)