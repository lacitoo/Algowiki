using namespace std;
#include <iostream>

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    // a d   |  b c d
    int answer;
    if (e > f)
    {
        if (a >= d) {answer = d*e; }
        else
        {
            if (b >= (d - a)) {
                if (c >= (d - a)) { answer = (a * e) + (d - a) * f; }
                else { answer = (a * e) + c * f; }
            }
            else {
                if (c >= (d - a)) { answer = (a * e) + b * f; }
                else
                {
                    if(b > c) { answer = (a * e) + c * f; }
                    else { answer = (a * e) + b * f; }
                }
            } 
        }
    }
    else if (e == f)
    {
        if (a >= d) { answer = d* e; }
        else {
            if (c >= d)
            {
                if (b >= d) { answer = d * e; }
                else
                {
                    if (a >= (d - b)) { answer = (b * e) + (d - b) * e; }
                    else { answer = (b * e) + (a*e); }
                }
            }
            else
            {
                if (b >= d)
                {
                    if (a >= (d - c)) { answer = (c * e) + (d - c) * e; }
                    else { answer = (c * e) + (a * e); }
                }
                else
                {
                    if (b >= c)
                    {
                        if (a >= (d - c)) { answer = (c * e) + (d - c) * e; }
                        else { answer = (c * e) + (a * e); }
                    }
                    else
                    {
                        if (a >= (d - b)) { answer = (b * e) + (d - b) * e; }
                        else { answer = (b * e) + (a * e); }
                    }
                }
            }
        }
    }
    else
    {
        if (b >= d)
        {
            if (c >= d) { answer = d * f; }
            else
            {
                if (a >= (d - c)) { answer = (c * f) + (d - c) * e; }
                else { answer = (c * f) + a * e; }
            }
        }
        else
        {
            if (c >= d)
            {
                if (a >= (d - b)) { answer = (b * f) + (d - b) * e; }
                else { answer = (b * f) + a * e; }
            }
            else
            {
                if (b >= c)
                {
                    if (a >= (d - c)) { answer = (c * f) + (d - c) * e; }
                    else { answer = (c * f) + a * e; }
                }
                else
                {
                    if (a >= (d - b)) { answer = (b * f) + (d - b) * e; }
                    else { answer = (b * f) + a * e; }
                }
            }
        }
    }
    cout << answer;
}

