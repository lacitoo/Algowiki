#include <iostream>
#include <algorithm>

using namespace std;

struct Point{
    int x;
    int y;
};

double tan(Point a){
    return (double)a.y/(double)a.x;
}

double tans[100000];

int main()
{
    int N;
    cin>>N;
    for (int i=0; i<N; i++){
        Point a;
        cin>>a.x>>a.y;
        tans[i]=tan(a);
    }

    sort(tans,tans+N);

    int seen=1;
    for (int i=1; i<N; i++){
        if (tans[i]!=tans[i-1]){
            seen++;
        }
    }
    cout<<seen<<endl;

    return 0;
}
