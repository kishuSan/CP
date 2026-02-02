#include <bits/stdc++.h>
using namespace std;

void run_starvation_cal(vector<int> priorities)
{
    int n = priorities.size();
    int time = 1;
    map<int, int> prev_p; // pri : time

    int ans;
    for(int i = n-1; i >= 0; --i)
    {
        ans = 0;
        if(lower_bound(prev_p.begin(), prev_p.end(), priorities[i]) - 1)
            ans = *(lower_bound(prev_p.begin(), prev_p.end(), priorities[i]) - 1);
        prev_p[priorities[i]] = time;
        time++;
        cout << ans << endl;
    }
}

int main()
{
    vector<int> priorities = {7, 2, 5, 3};
    run_starvation_cal(priorities);
    return 0;
}
