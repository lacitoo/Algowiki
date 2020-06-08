maxNum = float('inf')

def main():

        n = int(input(""))
        dp = []

        for i in range(0, n+1):
                dp.append(maxNum)
                
        dp[0] = 0

        for i in range(0, n):
                tc = input("").split(' ')
                t = int(tc[0])
                c = int(tc[1])

                for j in range(n, -1, -1):
                        if (j+t+1 < n):
                                dp[j+t+1] = min(dp[j+t+1], dp[j] + c)
                        else:
                                dp[n] = min(dp[n], dp[j] + c)

        print(dp[n])
main()
 
