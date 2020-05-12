from sys import stdin, stdout


def dfs(sup):
    global emp
    if emp[sup]==[]:
        return 1
    else:
        maxdepth = 0
        for newsup in emp[sup]:
            maxdepth = max(maxdepth,dfs(newsup))
        return 1+maxdepth

n = int(stdin.readline())
emp = [[] for _ in range(n)]
sups = []
for i in range(n):
    x = int(stdin.readline())
    if not x==-1:
        emp[x-1].append(i)
    else:
        sups.append(i)

#print(emp)
maxdepth=0
for sup in sups:
    maxdepth = max(maxdepth,dfs(sup))

stdout.write("{}".format(maxdepth))
