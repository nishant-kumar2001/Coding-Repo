// Problem Link -: https://leetcode.com/problems/decode-ways/

// using memoization 

class Solution {
public:
    unordered_map<string,int> mp;
    
    int helper(string s){
        
        if(s.empty())
            return 1;
        
        if(mp.find(s)!=mp.end())
            return mp[s];
        
        char c = s[0];
        int l=0,r=0;
        if(c!='0'){  
            l = helper(s.substr(1));
            if(s.size()>1){
                int h = 10*(s[0]-'0')+(s[1]-'0');
                if(h<27)    r = helper(s.substr(2));
            }
        }
        
        return mp[s] = l+r;
    }
    
    int numDecodings(string s) {

        return helper(s);
        
    }
};
