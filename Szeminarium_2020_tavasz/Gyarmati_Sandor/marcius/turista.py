import itertools
from sys import stdin, stdout


def main():
    #ab =    stdin.readline().split()
    #N, M, L = int(ab[0]), int(ab[1]), int(ab[2]) 
    N, M, L = list(map(int, stdin.readline().split()))
    #print(N, M, L)
    #t = [ [1001] * (N+1) for i in range(N+1)]
    t = [ [1001 for a in range(N+1)] for i in range(N+1)]
    sz = [ [0 for a in range(N+1)] for i in range(N+1)]

    for i in range(M):
        #ab =    stdin.readline().split()
        #fr, to, inp = int(ab[0]), int(ab[1]), int(ab[2]) 
        fr, to, inp = list(map(int, stdin.readline().split()))
        
        if inp < t[fr][to]:
            t[fr][to] = inp
            t[to][fr] = inp
            sz[fr][to] = fr
            sz[to][fr] = to

    for k in range(1, N+1):
        for i in range(1, N+1):
            for j in range(1, N+1):
                if t[i][j] > t[i][k] + t[k][j]:
                    t[i][j] = t[i][k] + t[k][j]
                    sz[i][j] = k


    mins = 100000
    mego = list()

    c= 0
    p = False
    a = [ i for i in range(1, N+1) if i != L]
    for v in itertools.permutations(a):
        volte = [False] * (N+1) 
        volte[L] = True
        if not volte[ sz[L][v[0]] ]:
            continue

        volte[v[0]] = True
        s = t[L][v[0]]

        for i in range( N-2):  
            if not volte[ sz[v[i]][v[i+1]] ] :
                break
            volte[v[i+1]] = True
            s += t[v[i]][v[i+1]]
        else:
            s += t[v[N-2]][L]
            if s < mins:
                mins = s
                mego = v[:]
        
    stdout.write(str(mins)+'\n')
    stdout.write(" ".join(str(a) for a in mego)+'\n')


main()
