// Problem Link -: https://codeforces.com/contest/1702/problem/D

// TOC ~ O(nlogn) 

#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    string s;   cin>>s;
    int p;  cin>>p;
    
    int sum = 0;
    for(char c:s)               // n times
        sum += (c-96);
    
    string r = s;
    sort(r.begin(),r.end(),greater<char>());        // nlogn
    
    unordered_map<char,int> mp;
    while(sum>p && !r.empty()){                     // n times
        sum-=(r[0]-96);
        mp[r[0]]++;
        r = r.substr(1);
    }
    
    string ans;
    for(char c:s){                          // n times
        
        if(mp.count(c) && mp[c]>0)
                mp[c]--;
        else
            ans+=c;
    }
    
    cout<<ans<<endl;
    
}

int main() {
	// your code goes here
	int t;  cin>>t;
	
	while(t--)
	    solve();
	return 0;
}
