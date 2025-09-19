#include <bits/stdc++.h>
using namespace std;
#define int long long
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


// void solve(){
//     int n;
//     cin >> n;
//     vector<int> b(n);
//     for(int &i : b) cin >> i;

//     unordered_map<int, int> freq;
//     for(int i = 0; i < n; i++) freq[b[i]]++;

//     for(auto node : freq){
//         if(node.first != node.second){
//             cout << -1 << endl;
//             return;
//         }
//     }

//     for(int i = 0; i < n; i++){
//         cout << b[i] << " ";
//     }
//     cout << endl;
        
// }

void solve(){
    int a, b;
    cin >> a >> b;
    // debug(a);
    // debug(b);
    int maxi = -1;
    set<int> fact;
    for(int i = 1; i*i <= b; i++){
        if(b % i == 0){
            //root
            debug(i);
            debug(b/i);
            fact.insert(i);
            fact.insert(b/i);
            int root_pair = b/i;
            int updated_a = a * root_pair;
            int sum = updated_a + i;
            // debug(sum);
            if(sum % 2 == 0){
                maxi = max(maxi, sum);
                // cout << sum << endl;
                // return;
            }
        }
    }
    // cout << -1 << endl;
    debug(fact);
    cout << maxi << endl;
    return;
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
    int t;
    cin >> t;
    while (t--) {
        solve(); 
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}