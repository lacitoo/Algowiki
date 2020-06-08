from sys import stdin, stdout
 
 
def main():
 
    data = []
    count = 0
    n = int(stdin.readline())
    for i in range(0, n+1):
        data.append(0)
 
 
    for i in range(1, n+1):
        data[i] = int(stdin.readline())
 
        
    for i in range(1, n+1):
        currentCounter = 0
        currentData = data[i]
        
        while (currentData != -1):
            currentData = data[currentData]
            currentCounter = currentCounter + 1
            
        if (count < currentCounter):
            count = currentCounter
 
 
    count = count + 1
    stdout.write(str(count))
 
main()