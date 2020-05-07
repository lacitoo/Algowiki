#include <iostream>
using namespace std;


struct item
{
    int weight;
    int price;
    int amount;
};

int main()
{
    // load items
    int n, weight;
    cin >> n >> weight;
    int benefit = 0;
    item* items = new item[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> items[i].weight >> items[i].price >> items[i].amount;
        int min;
        cin >> min;
        // adjust minimum benefit, maximum weight and item amount
        weight -= min * items[i].weight;
        benefit += min * items[i].price;
        items[i].amount -= min;
    }

    // check if possible/valid
    if (weight < 0)
        cout << -1 << endl;
    else
    {
        // dynamic programming, table of maximum benefits, row-by-row
        int wlength = weight + 1;
        int* B = new int[wlength];
        // initial benefit for all cases
        for (int w = 0; w < wlength; ++w)
            B[w] = benefit;
        // for all items
        for (int i = 0; i < n; ++i)
        {
            // calculate the next row
            int* B_ = new int[wlength];
            for (int w = 0; w < wlength; ++w)
            {
                int bi = w;// benefit index (in table row) (= w - items[i].weight * c)
                int best = B[bi];// benefit of pack with c item(s) (initially c=0)
                int price = 0;// total price of c item(s) (= items[i].price * c)
                // for each next item taken
                for (int c = 0; c < items[i].amount; ++c)
                {
                    // adjust benefit index and total price so far
                    bi -= items[i].weight;
                    price += items[i].price;
                    // if valid (is inside table)
                    if (bi >= 0)
                    {
                        // replace best if this combo is better
                        int val = B[bi] + price;
                        if (val > best)
                            best = val;
                    }
                    else break;
                }
                // set best outcome in row
                B_[w] = best;
            }
            // the current row is the new next row
            delete[] B;
            B = B_;
        }
        // the answer is the benefit at total weight
        cout << B[weight] << endl;
        delete[] B;
    }
    return 0;
}
