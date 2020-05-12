from sys import stdin,stdout

#n: keresztezodesek szama
#m: utcak szama

def dfs(prevnode,node):
    global visited
    global x
    global asd
    visited[node]=True
    #asd.append(node+1)
    stdout.write("{} ".format(node+1))
    for adj in x[node]:
        if not adj==prevnode:
            if not visited[adj]:
                dfs(node,adj)
            else:
                #burn bridges
                x[node].remove(adj)
                x[adj].remove(node)
                #asd.append(adj+1)
                #asd.append(node+1)
                stdout.write("{} ".format(adj+1))
                stdout.write("{} ".format(node+1))
    
    asd.append(node+1)
        

n,m = tuple(map(int,stdin.readline().split(" ")))

x = [[] for _ in range(n)]
visited = [False for _ in range(n)]
asd = []

for i in range(m):
    a,b = tuple(map(int,stdin.readline().split(" ")))
    x[a-1].append(b-1)
    x[b-1].append(a-1)

dfs(0,0)
for a in asd[1:]:
    stdout.write("{} ".format(a))
