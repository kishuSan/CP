#include <bits/stdc++.h>
using namespace std;
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
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    
// debug(a);

    // vector<vector<int>> dp(n + 1, vector<int>(m+1, 0)); // n -> 1-n, m -> 1-m
    vector<int> prev(m+1, 1), curr(m+1, 0);
    prev[0] = 0;
    if(a[0] != 0){
        prev.assign(m+1, 0);
        prev[a[0]] = 1;
    }

    // debug(prev);
    // debug(curr);
    for(int i = 2; i <= n; i++){
        int num = a[i-1];
        if(num != 0){
            if(num - 1 > 0) curr[num] = (curr[num] + prev[num - 1]) % MOD;
            curr[num] = (curr[num] + prev[num]) % MOD;
            if(num + 1 <= m) curr[num] = (curr[num] + prev[num + 1]) % MOD; 
        } 
        else {
            for(int j = 1; j <= m; j++){
                if(j - 1 > 0) curr[j] = (curr[j] + prev[j - 1]) % MOD;
                curr[j] = (curr[j] + prev[j]) % MOD;
                if(j + 1 <= m) curr[j] = (curr[j] + prev[j + 1]) % MOD; 
            }
        }
        prev = curr;
        curr.assign(m+1, 0);
    }
 

    // debug(prev);
    int res = 0;
    for(int i : prev) res = (res+i)%MOD;
    cout << res << endl;

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
