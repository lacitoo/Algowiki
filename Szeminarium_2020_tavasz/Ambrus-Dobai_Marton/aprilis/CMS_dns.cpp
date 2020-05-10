#include <iostream>
#include <string>

int main(){
    std::string input = "";
    std::cin >> input;
    bool a=false;
    bool c=false;
    bool g=false;
    bool t=false;
    bool ea=false;
    bool ec=false;
    bool eg=false;
    bool et=false;
    int k=0, n=0;
    while(input[n]!='\0'){
        ++n;
    }


    for (int i=0;i<n;++i){

        int j=0;
        a=false; c=false; g=false;t=false;
        while(( !a || !c || !g || !t ) && i+j<n){
            if(input[i+j]=='A'){
                a=true;
                ea=true;
            }else if(input[i+j]=='C'){
                c=true;
                ec=true;
            }else if(input[i+j]=='G'){
                g=true;
                eg=true;
            }else if(input[i+j]=='T'){
                t=true;
                et=true;
            }
            ++j;
            if(j>k)
                k=j;
        }
    }
    if( !ea || !ec || !eg || !et ){
        std::cout<<0;
    }else{
        std::cout<<k;
    }
}