from sys import stdin, stdout

class Ingredient:
    def __init__(self, key, inKitchen, price, count):
        self.key = key
        self.inKitchen = inKitchen
        self.price = price
        self.count = count

class InputData:
    def __init__(self, recipe, inKitchen, price, money):
        self.recipe = recipe
        self.inKitchen = inKitchen
        self.price = price
        self.money = money
    
def ReadFromConsole():

    recipe = stdin.readline();
    inKitchen = list(map(int, stdin.readline().split()))
    price = list(map(int, stdin.readline().split()))
    money = int(stdin.readline())

    return InputData(recipe, inKitchen, price, money)


def CountInHamburger(i, recipe):

    result = 0

    for c in recipe:
        if (c == i):
            result = result + 1

    return result

            

def main():
    inData = ReadFromConsole()

    bread = Ingredient('B', inData.inKitchen[0], inData.price[0], CountInHamburger('B', inData.recipe))
    sausage = Ingredient('S', inData.inKitchen[1], inData.price[1], CountInHamburger('S', inData.recipe))
    cheese = Ingredient('C', inData.inKitchen[2], inData.price[2], CountInHamburger('C', inData.recipe))

    money = inData.money

    countOfHamburger = 0
    canMake = True

    while (canMake):
        if (bread.inKitchen < bread.count):
            if ((bread.count - bread.inKitchen) * bread.price < money):
                bread.inKitchen = 0
                money = money - (bread.count - bread.inKitchen) * bread.price
            else:
                canMake = False
        else:
            bread.inKitchen = bread.inKitchen - bread.count

        if (sausage.inKitchen < sausage.count):
            if ((sausage.count - sausage.inKitchen) * sausage.price < money):
                sausage.inKitchen = 0
                money = money - (sausage.count - sausage.inKitchen) * sausage.price
            else:
                canMake = False
        else:
            sausage.inKitchen = sausage.inKitchen - sausage.count
            
        if (cheese.inKitchen < cheese.count):
            if ((cheese.count - cheese.inKitchen) * cheese.price < money):
                cheese.inKitchen = 0
                money = money - (cheese.count - cheese.inKitchen) * cheese.price
            else:
                canMake = False
        else:
            cheese.inKitchen = cheese.inKitchen - cheese.count

        if (canMake):
            countOfHamburger = countOfHamburger + 1

    stdout.write(str(countOfHamburger))

main()

    


    























    
    

