#include <iostream>

#define MAXN    500000

#define ull unsigned long long

using namespace std;

int N;
ull row1[MAXN+1], row2[MAXN+1];
pair<ull, ull> steps[MAXN+1];

int
main()
{
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> row1[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> row2[i];
    }

    steps[0] = {0,0};
    steps[1] = {row1[1], row2[1]};

    for(int i = 2; i <= N; i++) {
        steps[i].first = row1[i] + max(max(steps[i-2].first, steps[i-2].second),steps[i-1].second);
        steps[i].second = row2[i] + max(max(steps[i-2].first, steps[i-2].second),steps[i-1].first);
    }

    cout << max(steps[N].first, steps[N].second) << endl;

    return 0;
}