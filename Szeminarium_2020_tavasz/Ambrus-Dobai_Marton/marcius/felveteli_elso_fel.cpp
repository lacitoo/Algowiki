#include <iostream>
using namespace std;

int main(){
    int a,b,c,d,e,f,sum = 0, db = 0;
    cin>>a>>b>>c>>d>>e>>f;
    if(e>f){
        if(a>=d){
            sum+=d*e;
            db += d;
            cout<<"d";
        } else {
            sum+=a*e;
            db += a;
            cout<<"a";
        }
        d-=db;
        if( b<=c && b<=d){
            sum+=b*f;
            db += b;
            cout<<"b";
        } else if(c<=b && c<=d){
            sum+=c*f;
            db += c;
            cout<<"c";
        } else {
            sum+=d*f;
            db += d;
            cout<<"d";
        }
    } else {
        if( b<=c && b<=d){
            sum+=b*f;
            db += b;
            cout<<"b";
        } else if(c<=b && c<=d){
            sum+=c*f;
            db += c;
            cout<<"c";
        } else {
            sum+=d*f;
            db += d;
            cout<<"d";
        }
        d-=db;
        if(a>=d){
            sum+=d*e;
            db += d;
            cout<<"d";
        } else {
            sum+=a*e;
            db += a;
            cout<<"a";
        }
    }
    cout<<sum;
}