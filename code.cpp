#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define POS_MAX 1e18
#define MOD 1000000007
#define endl '\n'
#define ll long long
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"; cerr << endl;}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m)); 
    vector<vector<pair<bool, int>>> dp(n+1, vector<pair<bool, int>>(1024, {false, -1}));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    // for(int i = 1; i <= 1023; i++) dp[0][i].first = true;    
    dp[0][0].first = true;

    for(int i = 1; i <= n; i++){
        for(int x = 0; x <= 1023; x++){
            for(int j = 0; j < m; j++){
                if(dp[i-1][x ^ a[i-1][j]].first){
                    dp[i][x].first = true;
                    dp[i][x].second = j;
                    break;
                } 
            }
        }
    }

    // debug(dp);

    int target = -1;
    for (int x = 1; x <= 1023; x++) {
        if (dp[n][x].first) { target = x; break; }
    }

    if (target == -1) {
        cout << "NIE" << endl;
        return;
    }
    cout << "TAK" << endl;
    vector<int> choice(n);
    int cur = target;
    for (int i = n; i >= 1; --i) {
        int j = dp[i][cur].second; // column chosen at row i-1
        choice[i-1] = j;
        cur ^= a[i-1][j]; // move to previous XOR
    }

    for (int i = 0; i < n; i++) {
        cout << (choice[i] + 1) << (i + 1 == n ? '\n' : ' ');
    }

}

 
signed main() {
   auto begin = std::chrono::high_resolution_clock::now();
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
 
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  freopen("Error.txt", "w", stderr);
#endif
    solve(); 
   auto end = std::chrono::high_resolution_clock::now();
   auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
   cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
   return 0;
}
