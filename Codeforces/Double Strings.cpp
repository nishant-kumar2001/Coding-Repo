// Problem link -: https://codeforces.com/problemset/problem/1703/D

// TOC -: O(n*(l1+l2+......ln))  

#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> mp;

bool helper(vector<string> &v,int n,int ind){
    
    string si = v[ind];
    
    for(int i=0;i<si.size();i++){
        if(mp.count(si.substr(0,i)) && mp.count(si.substr(i)))
            return 1;
    }
    
    return 0;
}

void solve(){
    
    int n;  cin>>n;
    vector<string> v(n);
    
    for(int i=0;i<n;i++){
        string s;   cin>>s;
        v[i] = s;
        mp[s]++;
    }
    
    string ans;
    
    int i=0;
    while(i<n){
        mp[v[i]]--;
        if(mp[v[i]]==0) mp.erase(v[i]);
        ans+= helper(v,n,i)==1?"1":"0";
        mp[v[i]]++;
        i++;
    }
        
    cout<<ans<<endl;
    
}

int main() {
	// your code goes here
	int t;  cin>>t;
	
	while(t--){
	    solve();
	    mp.clear();
	}
	    
	return 0;
}
