from sys import stdin,stdout

n,m = tuple(map(int,stdin.readline().rstrip().split(" ")))
a   = list(map(int,stdin.readline().rstrip().split(" ")))
b   = list(map(int,stdin.readline().rstrip().split(" ")))

dp = [[0 for _ in range(m+1)] for _ in range(n+1)]

for i in range(1,n+1):
    for j in range(1,m+1):
        if a[i-1] == b[j-1]:
            dp[i][j] = dp[i-1][j-1] +1
        else:
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])

length = dp[n][m]

lcs = [-1 for _ in range(length+1)]

i,j = n,m

while i>0 and j>0:
    if a[i-1] == b[j-1]:
        lcs[length-1]=a[i-1]
        length-=1
        i-=1
        j-=1
    elif dp[i-1][j]>dp[i][j-1]:
        i-=1
    else:
        j-=1

for x in lcs:
    if not x==-1:
        stdout.write("{} ".format(x))
