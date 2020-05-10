#include <iostream>
#include <vector>

using namespace std;

struct employee{
    int group;
    int manager;
    vector<int> hier;
    vector<int> ban;
};

int n;
vector<employee> emps;
vector<vector<employee>> groups;

void setup(){
    cin>>n;
    emps.resize(n);
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        emps[i].group=-1;
        emps[i].manager=a-1;
        if(a!=-1){
            emps[a-1].hier.push_back(i);
        }
    }
}

void set_ban1(int i){
    int p=emps[i].manager;
    while(p!=-2){
        if(emps[p].group!=-1){
            emps[i].ban.push_back(emps[p].group);
        }
        p=emps[p].manager;
    }
}

void set_ban2(int i,int s){
    //cout<<"\tSet ban start manager:"<<s<<endl;
    //p=emps[p].manager;
    for(int j=0;j<emps[s].hier.size();++j){
        int p=emps[s].hier[j];
        //cout<<"\t\tSet ban manager set to:"<<p<<endl;
        if(p!=-2){
            
            if(emps[p].group!=-1){
                emps[i].ban.push_back(emps[p].group);
            }
            set_ban2(i,p);
        }
    }
    //cout<<"\tSet ban end manager:"<<s<<endl;
}

bool in_ban(int i,int j){
    bool in = false;
    for(int k=0;k<emps[i].ban.size() && !in;++k){
        //cout<<"\t\tGroup in ban group:"<<j<<" ban:"<<emps[i].ban[k]<<endl;
        if(emps[i].ban[k]==j) in = true;
    }
    return in;
}

bool in_groups(int i){
    bool good = false;
    for(int j=0;j<groups.size() && !good;++j){
        //cout<<"\tGroup deciding start group:"<<j<<endl;
        
        if(!in_ban(i,j)){
            good = true;
            groups[j].push_back(emps[i]);
            emps[i].group=j;
            //cout<<"\t\t\tAdded element:"<<i<<"to group:"<<j<<endl;
        }
        //cout<<"\tGroup deciding end group:"<<j<<endl;
    }
    return good;
}

void group_search(int i){
    //cout<<"Group search start element:"<<i<<endl;
    set_ban1(i);
    set_ban2(i,i);

    if(!in_groups(i)){
        emps[i].group=groups.size();
        vector<employee> group1; 
        group1.push_back(emps[i]);
        groups.push_back(group1);
        //cout<<"\t\t\tAdded element:"<<i<<"to group:"<<groups.size()-1<<endl;
    }
    //cout<<"Group search end element:"<<i<<endl;
}

int main(){
    setup();

    vector<employee> group1; 
    group1.push_back(emps[0]);
    emps[0].group=0;
    groups.push_back(group1);

    for(int i=1;i<n;++i){
        group_search(i);
    }

    cout<<groups.size();
    return 0;
}
