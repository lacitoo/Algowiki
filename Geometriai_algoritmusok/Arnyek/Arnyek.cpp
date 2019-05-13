#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define PI 3.14159265

struct Point{
    double x;
    int y;
    bool operator==(const Point& a){
        return (a.x==x && a.y==y);
    };
};

int direction(Point a, Point b){
    double S=(a.y*b.x)-(b.y*a.x);
    if (S<0) {return -1;}
    else if (S>0) {return +1;}
    else if (S==0) {return 0;}
};

int turn(Point a, Point b, Point c){
    Point p;
    Point q;
    p.x=b.x-a.x;
    p.y=b.y-a.y;
    q.x=c.x-a.x;
    q.y=c.y-a.y;


    return direction(p,q);
};

int main()
{
    int N;
    cin>>N;
    int alpha;
    cin>>alpha;
    Point H[1000];
    for (int i=0; i<N; i++){
    	cin>>H[i].x>>H[i].y;
    }

    bool all=true;

    vector <int> teljes;
    vector <int> reszben;

    if (alpha<=0){
        Point u=H[0];
        Point d;
        d.x=tan(alpha* PI / 180.0);
        d.y=1;

        for (int i=1; i<N; i++){
            Point e;
            e.x=u.x+d.x;
            e.y=u.y+d.y;
            if (turn(e,u,H[i])==-1){
                if (u.x!=H[i-1].x && u.y!=H[i-1].y){
                    reszben.push_back(i);
                    all=false;
                }
                u=H[i];
            }
            else{
                all=false;
                teljes.push_back(i);
            }
        }
        if (all){
        cout<<"IGEN"<<endl;
        return 0;
        }

        cout<<"NEM"<<endl;
        cout<<teljes[0]<<endl;
        for (int e : teljes){
            cout<<e<<" ";
        }
        cout<<endl;
        for (int e : reszben){
            cout<<e<<" ";
        }
        cout<<endl;

    } else {
        Point u=H[N-1];
        Point d;
        d.x=tan(alpha* PI / 180.0);
        d.y=1;
        for (int i=N-2; i>-1; i--){
            Point e;
            e.x=u.x+d.x;
            e.y=u.y+d.y;
            if (turn(e,u,H[i])==1){
                if (u.x!=H[i+1].x && u.y!=H[i+1].y){
                    reszben.push_back(i+1);
                    all=false;
                }
                u=H[i];
            }
            else{
                all=false;
                teljes.push_back(i+1);
            }
        }
        if (all){
        cout<<"IGEN"<<endl;
        return 0;
        }

        cout<<"NEM"<<endl;
        cout<<teljes[teljes.size()-1]<<endl;
        for (int i=teljes.size()-1; i>-1; i--){
            cout<<teljes[i]<<" ";
        }
        cout<<endl;
        for (int i=reszben.size()-1; i>-1; i--){
            cout<<reszben[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
