#include <iostream>
#include <string>

// most az egyszer életemben globális változókat fogok használni, mert ennyit nem vagyok hajlandó átadni
 
long long int bread_need, sausage_need, cheese_need; 
long long int bread_price, sausage_price, cheese_price;
long long int bread, sausage, cheese;
long long int money;
bool can_make = true;
long long int counter;
 
void make()
{
	if (bread - bread_need < 0)
	{
		money -= bread_price * (bread_need - bread);
		bread = 0;
	}
	else
		bread -= bread_need;
	
	if (sausage - sausage_need < 0)
	{
		money -= sausage_price * (sausage_need - sausage);
		sausage = 0;
	}
	else
		sausage -= sausage_need;
 
	if (cheese - cheese_need < 0)
	{
		money -= cheese_price * (cheese_need - cheese);
		cheese = 0;
	}
	else
		cheese = cheese - cheese_need;
 
	if (money < 0)
		can_make = false;
	else
		counter++;
 
}
 
void make_from_scratch()
{
	money -= (bread_need * bread_price) + (sausage_need * sausage_price) + (cheese_need * sausage_price);
	if (money < 0)
		can_make = false;
	else
		counter++;
}
 
 
int main()
{
	std::string burger;
 
	std::cin >> burger;
	std::cin >> bread >> sausage >> cheese;
	std::cin >> bread_price >> sausage_price >> cheese_price;
	std::cin >> money;
 
	for (char i : burger)
	{
		switch (i)
		{
		case 'B':
			bread_need++;
			break;
		case 'S':
			sausage_need++;
			break;
		case 'C':
			cheese_need++;
			break;
		}
	}
 
	while (can_make)
	{
		if (bread * bread_need + sausage * sausage_need + cheese * cheese_need > 0)
			make();
		else
			break;
	}
	long long fullprice = ((bread_need * bread_price) + (sausage_need * sausage_price) + (cheese_need * cheese_price));
	counter += money / fullprice;
 
	std::cout << counter;
}