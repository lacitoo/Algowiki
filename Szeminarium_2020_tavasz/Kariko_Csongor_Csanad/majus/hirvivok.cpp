#include <algorithm>
#include <queue>
#include <math.h>
#include <iostream>

int megold(const int n, const int m, const int h, const int k, const std::pair<int,int>* const poz){
    int* utolso = new int[h];
    std::fill(utolso, utolso+h, -1);
    
    int proba = 0;
    int bal = 0, jobb = n+m-2;
    while(bal < jobb){
        int kozep = (bal+jobb)/2;
        
        
        int db = 0;
        ++proba;
        for(int i = 0; i < h; ++i){
            if(utolso[i] == proba)
                continue;
            
            ++db;
            std::queue<int> sor;
            sor.push(i);
            utolso[i] = proba;
            while(sor.size() > 0){
                int cur = sor.front();
                
                sor.pop();
                
                for(int j = 0; j < h; ++j){
                    int tav = std::abs(poz[cur].first-poz[j].first)+std::abs(poz[cur].second-poz[j].second);
                    if(utolso[j] < utolso[cur] && tav <= kozep){
                        utolso[j] = proba;
                        sor.push(j);
                    }
                }
            }
        }
      
        
        if(db > k){
            bal = kozep + 1;
        }else{
            jobb = kozep;
        }
    }
    
    delete[] utolso;
    return bal;
}


int main(){
    int N, M, H, K;
    std::cin>>N>>M>>H>>K;
    std::pair<int,int>* poz = new std::pair<int,int>[H];
    for(int i = 0; i < H; ++i){
        std::cin>>poz[i].first>>poz[i].second;
    }
    
	std::cout<<megold(N,M,H,K,poz)<<"\n";
    
    delete[] poz;
    return 0;
}
