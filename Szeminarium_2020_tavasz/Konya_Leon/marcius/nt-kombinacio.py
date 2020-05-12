"""

NT2 Kombinacio
Mester / Halado / Kombinatorikai algoritmusok / 48. Kombinacio

"""

from sys import stdin, stdout

n,m = tuple(map(int,stdin.readline()[:-1].split(" ")))
A  = list(map(int,stdin.readline()[:-1].split(" ")))
Aprev = A[:]

if m==n:
    for i in range(m):
        stdout.write("{} ".format(A[i]))
    stdout.write("\n")
    for i in range(m):
        stdout.write("{} ".format(A[i]))
else:
    if A[m-1]==m:
        for i in range(m):
            stdout.write("{} ".format(A[i]+n-m))
        stdout.write("\n")
        A[m-1]=m+1
        for i in range(m):
            stdout.write("{} ".format(A[i]))
    else:
        if A[0]==n-m+1:
            A[0]-=1
            for i in range(m):
                stdout.write("{} ".format(A[i]))
            stdout.write("\n")
            A[0]+=1
            for i in range(m):
                stdout.write("{} ".format(A[i]-n+m))
        else:
            
            #prev
            if Aprev[m-1]-1==Aprev[m-2]:
                Aprev[m-1]=n
                for i in range(m-2,0,-1):
                    if Aprev[i]-1!=Aprev[i-1]:
                        Aprev[i]-=1
                        for j in range(m-2,i,-1):
                            Aprev[j]=Aprev[j+1]-1
                        break
                    
            else:
                Aprev[m-1]-=1
            for i in range(m):
                stdout.write("{} ".format(Aprev[i]))
                
            stdout.write("\n")
            #next:
            if A[m-1]==n:
                for i in range(m-2,-1,-1):
                    if A[i]+1!=A[i+1]:
                        A[i]+=1
                        for j in range(i+1,m):
                            A[j]=A[j-1]+1
                        break
            else:
                A[m-1]+=1

            for i in range(m):
                stdout.write("{} ".format(A[i]))
