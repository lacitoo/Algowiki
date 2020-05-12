    #include <iostream>
    #include <vector>
    using namespace std;
     
    int main(){
        long n,m,last=0;
        cin>>n;
        vector<long> groups(n);
        for(int i=0;i<n;++i){
            int a;
            cin>>a;
            last+=a;
            groups[i]=last;
        }
        cin>>m;
        for(int i=0;i<m;++i){
            int a,j=0;
            cin>>a;
            while(a>groups[j]){
                ++j;
            }
            cout<<j+1<<"\n";
        }
     
        return 0;
    }

    /*
    100
    1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
    5
    1 49 99 51 87
    */