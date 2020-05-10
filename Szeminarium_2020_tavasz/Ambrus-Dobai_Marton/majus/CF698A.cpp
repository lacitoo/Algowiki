#include <iostream>
#include <vector>
using namespace std;

int n, c;
vector<int> a;

/*int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        int b;
        cin>>b;
        a.push_back(b);
    }
    for(int i=0;i<n;++i){
        if(a[i]==3){
            if(i>0 && a[i-1]==1) a[i]=2;
            else if(i>0 && a[i-1]==2) a[i]=1;
            else {
                if(i<n && a[i+1]==1) a[i]=2;
                else if(i<n && a[i+1]==2) a[i]=1;
                else a[i]=1;
            }
        }
        else if(i>0 && ((a[i]==2 && a[i-1]==2) || (a[i]==1 && a[i-1]==1))) { a[i]==0; c++; }
        else if(a[i]==0) c++;
    }
    cout<<c;
}*/

int r[3],_r[3];
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        int b;
        cin>>b;
        a.push_back(b);
    }
    for(int i=0;i<n;++i){
        _r[0] = (r[0]<r[1]?r[1]:r[0]);
        _r[0] = (_r[0]<r[2]?r[2]:_r[0]);
        if(a[i]==1)     {_r[1]=(r[0]>r[2]?r[0]:r[2])+1; _r[2]=0;}
        else if(a[i]==2){_r[1]=0; _r[2]=(r[0]>r[1]?r[0]:r[1])+1;}
        else if(a[i]==3){_r[1]=(r[0]>r[2]?r[0]:r[2])+1; _r[2]=(r[0]>r[1]?r[0]:r[1])+1;}
        r[0]=_r[0];
        r[1]=_r[1];
        r[2]=_r[2];
        cout<<a[i]<<" "<<r[0]<<" "<<r[1]<<" "<<r[2]<<"\n";
    }
    _r[0] = (r[0]<r[1]?r[1]:r[0]);
    _r[0] = (_r[0]<r[2]?r[2]:_r[0]);
    r[0]=_r[0];
    cout<<(n-r[0]);
}
/*for (int i = 0; i < n; i++)
	{
		int max_nothing_temporary = max_nothing;
		max_nothing_temporary = max(max_contest, max_sport, max_nothing_temporary);
		int max_contest_temporary = 0;
		if (data[i] == 1 || data[i] == 3){
			max_contest_temporary = max(max_contest_temporary, max_nothing, max_sport) + 1;
		}
		int max_sport_temporary = 0;
		if (data[i] == 2 || data[i] == 3){
			max_sport_temporary = max(max_contest, max_nothing, max_sport_temporary) + 1;
		}
		max_contest = max_contest_temporary;
		max_nothing = max_nothing_temporary;
		max_sport = max_sport_temporary;
	}
 
	std::cout << n - max(max_contest, max_nothing, max_sport) << std::endl;
*/
/*
    #include <iostream>
    #include <vector>
     
    int max(const int a, const int b, const int c)
    {
    	int max = a;
    	if (max < b)
    	{
    		max = b;
    	}
    	if (max < c)
    	{
    		max = c;
    	}
    	return max;
    }
     
    int main()
    {
    	int n;
    	std::cin >> n;
    	std::vector<int> data;
    	for (int i = 0; i < n; i++)
    	{
    		int element;
    		std::cin >> element;
    		data.push_back(element);
    	}
     
    	int max_contest = 0;
    	int max_sport = 0;
    	int max_nothing = 0;
     
    	for (int i = 0; i < n; i++)
    	{
    		int max_nothing_temporary = max_nothing;
    		max_nothing_temporary = max(max_contest, max_sport, max_nothing_temporary);
     
    		int max_contest_temporary = 0;
    		if (data[i] == 1 || data[i] == 3)
    		{
    			max_contest_temporary = max(max_contest_temporary, max_nothing, max_sport) + 1;
    		}
     
    		int max_sport_temporary = 0;
    		if (data[i] == 2 || data[i] == 3)
    		{
    			max_sport_temporary = max(max_contest, max_nothing, max_sport_temporary) + 1;
    		}
     
    		max_contest = max_contest_temporary;
    		max_nothing = max_nothing_temporary;
    		max_sport = max_sport_temporary;
     
    	}
     
    	std::cout << n - max(max_contest, max_nothing, max_sport) << std::endl;
    }*/