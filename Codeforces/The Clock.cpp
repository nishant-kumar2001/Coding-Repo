// Problem Link -: https://codeforces.com/contest/1692/problem/D

#include <bits/stdc++.h>
using namespace std;
 
int check(string s){
    
    int i=0,j=s.size()-1;
    
    while(i<j){
        if(s[i]!=s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
 
void fun(){
    string s;   cin>>s;
    int x;  cin>>x;
    
    int hr = 10*(s[0]-48)+(s[1]-48);
    int min = 10*(s[3]-48)+(s[4]-48);
    
    int tmin = (60*hr)+min;
    
    unordered_map<string,int> v;
 //   int n = x<60? 1440/x : 24/(x/60);
   // n++;
    
    while(1){
        
        string l = to_string((tmin/60)%24);
        string m = to_string((tmin%60)%60);
        
        if(l.size()==1) l = "0"+l;
        if(m.size()==1) m = "0"+m;
        
        string k = l+m;
        if(v.find(k) != v.end())   break;
        else    v[k]++;
        tmin+=x;
    }
    
    int ans = 0;
    
    for(auto it:v){
        ans+=check(it.first);
    }
        
    cout<<ans<<endl;
    
}
 
int main() {
	// your code goes here
	int t;  cin>>t;
	
	while(t--){
	    fun();
	}
	return 0;
}
