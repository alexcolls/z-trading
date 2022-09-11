

from itertools import combinations 

ass = 10
apa = 3

def rSubset(arr, r): 
    return list(combinations(arr, r)) 

ret = rSubset(range(ass),apa)
for i in range(len(ret)):
    ret[i] = list(ret[i])


ret
type(ret[0])