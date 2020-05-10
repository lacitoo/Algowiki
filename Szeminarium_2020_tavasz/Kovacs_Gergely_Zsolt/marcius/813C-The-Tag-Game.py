from sys import stdin

n, x = map(int, input().split())
l = [[] for _ in range(n)]
m = [None]*n
for s in stdin.readlines():
    a, b = map(int, s.split())
    l[a].append(b)
    m[b] = a

def kozep(c):
    while c > 1:
        c = m[c]
        yield c

maxfel = 

lek = [None]*n
def maxle(c):
    global lek
    lek[c] = sum(maxle(i) for i in l[c])