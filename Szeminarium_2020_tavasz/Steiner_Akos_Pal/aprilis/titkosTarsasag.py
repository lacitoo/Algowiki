from sys import stdin, stdout



#######################################Beolvasásért felelős függvény
def readFromConsole():
    
    inputNums = list(map(int, stdin.readline().split()))
    N = inputNums[0]
    X = inputNums[1]
    Y = inputNums[2]

    junior = []

    for i in range(0, N):
        junior.append([])

    for i in range(1, N):

        inputNum = int(stdin.readline())
        junior[inputNum-1].append(i+1)

    return [N,X,Y,junior]


#######################################Az első feladatért felelős függény
def onlyDown(h,x,y):

    result = False

    i = 0
    while (i < len(h[x-1]) and not result):
        if (h[x-1][i] == y-1):
            result = True
        else:
            result = onlyDown(h, h[x-1][i], y)
        i = i+1

    return result


#######################################Az első feladatért felelős függény
def upAndDown(h,x,y):


#######################################A harmadik feladatért felelős függény
def juniorsOf(h,a):

    result = 0

    for e in h[a-1]:
        result = result + 1
        result = result + juniorsOf(h, e)

    return result


#######################################A főprogram függénye
def main():

    parameters = readFromConsole()

    N = parameters[0]
    X = parameters[1]
    Y = parameters[2]
    junior = parameters[3]



#######################################1. feladat
    if (onlyDown(junior, X, Y)):
        stdout.write(str(1))
    elif (onlyDown(junior, Y, X)):
        stdout.write(str(2))
    else:
        stdout.write(str(3))
#######################################2. feladat
    print(stepNum(junior, X, Y))
#######################################3. feladat        
    print(juniorsOf(junior,X), juniorsOf(junior,Y))

main()
















    
