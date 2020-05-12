#include <iostream>
#include <algorithm>

#define llu long long

using namespace std;

struct ing {
    unsigned need;
    unsigned have;
    unsigned price;

    inline llu cost(llu p){ return max(0LL, price*(need*p-have)); }
};

ing b, s, c;
llu money;

int
main()
{
    // beolv
    char k;
    do{
        scanf("%c", &k);
        if(k == 'B') b.need++;
        else if(k == 'S') s.need++;
        else if(k == 'C') c.need++;
    }while(k != '\n');

    scanf("%u %u %u %u %u %u %llu",
        &b.have, &s.have, &c.have, &b.price, &s.price, &c.price, &money);

    // do
    llu l = 0, r = money+max(b.have, max(s.have, c.have));
    while(l <= r){
        llu piv = (l+r)/2;
        llu ert = b.cost(piv) + s.cost(piv) + c.cost(piv);
        if(ert > money){
            r = piv-1;
        }else{
            l = piv+1;
        }
    }

    printf("%llu\n", r);

    return 0;
}