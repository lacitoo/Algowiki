def min(a,b):
    if (a<b):
        return a
    else:
        return b

db = int(input(""))
comp=[]
sport= []
for i in range(0, db):
    comp.append(0)
    sport.append(0)
    
for i in range(0, db):
    x = int(input(""))
    if (x < 3):
        if (x != 1):
            comp[i] = 1
        if (x != 2):
            sport[i] = 1

for i in range(db-2, 0, -1):
    sport[i] = min(sport[i] + comp[i + 1], sport[i + 1] + 1)
    comp[i] = min(comp[i] + sport[i + 1], comp[i + 1] + 1)

print(min(sport[0], comp[0]))
