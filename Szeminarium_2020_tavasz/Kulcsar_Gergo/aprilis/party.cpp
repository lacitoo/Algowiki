#import <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int p[n+1];
    for(int i=1; i<=n; i++){
        cin>>p[i];
    }
    int m = 0;
    for(int i=1;i<=n;i++){
        int k = 0;
        for(int t=i; t!=-1;){
            ++k;
            m = max(m,k);
            t = p[t];
        }
    }
    cout << m;
}