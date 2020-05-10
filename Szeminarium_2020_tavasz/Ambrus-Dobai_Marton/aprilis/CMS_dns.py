inp = input()
a=False
c=False
g=False
t=False
k=0

for i in range(1,inp.count):
    j=i
    while not a or not c or not g or not t:
        if(inp[j]=='A'):
            a=True
        elif(inp[j]=='C'):
            c=True
        elif(inp[j]=='G'):
            g=True
        elif(inp[j]=='T'):
            t=True
        j=j+1
        if(j>k):
            k=j