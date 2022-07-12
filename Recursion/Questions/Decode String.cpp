
// Problem Link -: https://leetcode.com/problems/decode-string/

class Solution {
public:
    
    
    string helper(string s,int &i){
        
      string res;
        
      while(i<s.size() && s[i]!=']'){  
        if(isdigit(s[i])){
            
            int n = 0;
            while(isdigit(s[i])&& i<s.size())
               n = 10*n+(s[i++]-'0');
            
            i++;
            string ans = helper(s,i);
           
            i++;
            while(n-- > 0)
                res+=ans;
            
        }
        else{
            res+=s[i++];
        }
      }
        
        return res;
    }
    
    string decodeString(string s) {
        
        int i=0;
        return helper(s,i);
    }
};
