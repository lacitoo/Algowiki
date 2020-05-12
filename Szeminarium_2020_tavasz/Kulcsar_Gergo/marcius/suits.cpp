#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int sum;
    if(e > f) {
        if(d > a) {
            sum = e*a;
            d = d - a;
            if(d > b && d > c) {
                if(c > b) {
                    sum = sum + f*b;
                } else {
                    sum = sum + f*c;
                }
            } else {
                int seged;
                if(c > b) {
                    seged = b;
                } else {
                    seged = c;
                }
                if(d > seged) {
                    sum = sum + f*seged;
                } else {
                    sum = sum + f*d;
                }
            }
        } else {
            sum = e*d;
        }
    } else {
        if(d > b && d > c) {
            if(c > b) {
                sum = f*b;
                d = d - b;
            } else {
                sum = f*c;
                d = d - c;
            }
            if(d > a) {
                sum = sum + e*a;
            } else {
                sum = sum + e*d;
            }
        } else {
            int seged;
            if(c > b) {
                seged = b;
            } else {
                seged = c;
            }
            if(d > seged) {
                sum = f*seged;
                d = d - seged;
                if(d > a) {
                    sum = sum + e*a;
                } else {
                    sum = sum + e*d;
                }
            } else {
                sum = f*d;
            }
        }
    }
    cout << sum;
    return 0;
}