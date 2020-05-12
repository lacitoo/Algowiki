#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> x (n);
    for (int i = 0; i < n; i++){
        cin>>x[i];
    }

    int max=0, haromertek[3], haromind=0, i=0,j=1;
    haromertek[0]=x[i];
    while(j<n){
        if(haromind==0){
            if(x[j]==haromertek[0]){
                ++j;
            }else{
                haromind++;
                haromertek[1]=x[j];
                ++j;
            }
        }else if(haromind==1){
            if(x[j]==haromertek[0] || x[j]==haromertek[1]){
                ++j;
            }else{
                haromind++;
                haromertek[2]=x[j];
                ++j;
            }
        }else{
            if(x[j]==haromertek[0] || x[j]==haromertek[1] || x[j]==haromertek[2]){
                ++j;
            }else{
                if(j-i > max){
                    max=j-i;
                }
                haromind=0;
                ++i;
                haromertek[0]=x[i];
                j=i+1;
            }
        }
    }
    
    cout<<max;
    return 0;
}