from sys import stdin, stdout
sets = []
counters = []
darab = 5
def root(a):
    #print(a)
    #global sets
    #print(sets)
    if sets[a] == a:
        return a
    sets[a] = root(sets[a])
    return sets[a]
def unions(a, b):
    #global sets
    #global counters
    global darab
    a = root(a)
    b = root(b)
    if a == b:
        return
    darab= darab-1
    if counters[a] >= counters[b]:
        counters[a] += counters[b]
        sets[b] = a
    else:
        counters[b] += counters[a]
        sets[a] = b
def main():
    N, M, H, K = list(map(int, stdin.readline().split()))
    #print(N, M, H, K)
    #print([] * 2)
    pontok = [0] * H
    #print(pontok)
    elek = [0] * (H * H)
    #print(elek)
    elct = 0
    for i in range(H):
        a = stdin.readline().split()
        #print(a)
        
        pontok[i] = (int(a[0]), int(a[1]))
        for j in range(i):
            hossz = abs(pontok[i][0] - pontok[j][0]) + abs(pontok[i][1] - pontok[j][1]) 
            elek[elct] = ( i, j, hossz )
            elct = elct+1
    elek = elek[:elct]
    elek.sort(key=lambda x: x[2])
    #for a in elek:
        #print(elek)
    global counters
    global darab
    global sets
    darab = H
    counters = [1] * H
    
    sets = list(range(H))
    #print(sets)
    i = 0
    L = 0
    while(i < elct and darab > K):
        L = elek[i][2]
        unions(elek[i][0], elek[i][1])
        i += 1
    print(L)
main()