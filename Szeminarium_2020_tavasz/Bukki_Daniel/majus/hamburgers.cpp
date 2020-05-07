#include <iostream>
#include <vector>
using namespace std;


typedef unsigned long long ulong;

ulong req_bread, req_sausage, req_cheese;
ulong am_bread, am_sausage, am_cheese;
ulong pr_bread, pr_sausage, pr_cheese;
ulong money;
ulong calc_cost(ulong quantity)
{
    ulong tot_bread = quantity * req_bread;
    if (tot_bread > am_bread)
        tot_bread -= am_bread;
    else tot_bread = 0;
    ulong tot_sausage = quantity * req_sausage;
    if (tot_sausage > am_sausage)
        tot_sausage -= am_sausage;
    else tot_sausage = 0;
    ulong tot_cheese = quantity * req_cheese;
    if (tot_cheese > am_cheese)
        tot_cheese -= am_cheese;
    else tot_cheese = 0;
    return tot_bread * pr_bread + tot_sausage * pr_sausage + tot_cheese * pr_cheese;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char c;
    req_bread = 0;
    req_sausage = 0;
    req_cheese = 0;
    while (true)
    {
        switch (cin.peek())
        {
        case 'B':
            ++req_bread;
            cin >> c;
            break;
        case 'S':
            ++req_sausage;
            cin >> c;
            break;
        case 'C':
            ++req_cheese;
            cin >> c;
            break;
        default: goto Amounts;
        }
    }

Amounts:
    cin >> am_bread >> am_sausage >> am_cheese;
    cin >> pr_bread >> pr_sausage >> pr_cheese;
    cin >> money;
    
    ulong min = 0;
    ulong max = ULLONG_MAX / 30000;
    while (min < max)
    {
        ulong quantity = min + (max - min) / 2;
        ulong cost = calc_cost(quantity);
        if (cost == money)
            min = max = quantity;
        else if (cost > money)
            max = quantity - 1;
        else min = quantity + 1;
    }
    cout << ((calc_cost(max) > money) ? (max - 1) : max) << endl;
    return 0;
}
