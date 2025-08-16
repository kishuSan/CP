#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    // std::cout << "Try programiz.pro";
    // string st = "Hello world";
    // unordered_map<char, int> mp;
    // for(char ch : st){
    //     mp[ch]++;
    // }
    
    // for(auto node : mp){
    //     cout << "letter: " << node.first << " freq: " << node.second << endl;
    // }

    // vector<int> vec = {2,6,7,2,8,9,10,7,18,4};
    // sort(vec.rbegin(), vec.rend()); // desc 
    // for(int i = 0; i < 5; i++){
    //     cout << vec[i] << " ";
    // }

    string st = "Apple,Orange,banana,Grapes";
    string curr = "";
    vector<string> ans;
    for(char ch : st){
        if(ch == ','){
            ans.push_back(curr);
            curr = ""; // reset
        }
        else curr += ch;
    }
    ans.push_back(curr);
    
    int n = ans.size();
    for(int i = 0; i < n/2; i++){
        string temp = ans[i];
        ans[i] = ans[n-i-1]; 
        ans[n-i-1] = temp;
    }
    
    for(auto it : ans) cout << it << " ";

    return 0;
}
