#include <bits/stdc++.h>
using namespace std;
 
vector<int> kitchen(3), price(3), quantity(3);
//0: Bread, 1:Sausage, 2:Cheese
 
// x hamburgerhez mennyi pénz kell
long long f(long long x) {
  long long sum = 0;
  for (int i = 0; i < 3; i++) sum += max(quantity[i] * x - kitchen[i], 0ll) * price[i];
  return sum;
}
 
int main() {
  //adatok feltoltese
  string s;
  cin >> s;
  for (char c : s) {
    if (c == 'B') quantity[0]++;
    if (c == 'S') quantity[1]++;
    if (c == 'C') quantity[2]++;
  }
  for (int& value : kitchen) cin >> value;
  for (int& value : price) cin >> value;
  long long money;
  cin >> money;
  
  long long a = 0;
  long long b = money + kitchen[0] + kitchen[1] + kitchen[2]; //maximum hany darab hamburgert keszithetunk
  
  // binaris kereses: a <= megoldás < b
  while (a + 1 < b){
    long long p = (a + b) / 2;
    if (f(p)>money){
      b=p;
    }else{
      a=p;
    }
  }
  cout << a << endl;
  return 0;
}