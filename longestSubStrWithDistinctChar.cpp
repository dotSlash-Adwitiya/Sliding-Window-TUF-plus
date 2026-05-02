#include<bits/stdc++.h>

//*  NAIVE APPROACH : 
class Solution{
  public:
    int longestNonRepeatingSubstring(string& s){
        if(s.size() == 1) return 1;
       int i = 0, maxLen = 0;
       for(i = 0; i < s.size(); i++){
            int currLen = 0;
            for(int j = i + 1; j < s.size(); j++){
                bool dup = false;
                for(int k = i; k < j; k++){
                    if(s[k] == s[j]){
                        i = k+1;
                        dup =  true;
                        break;
                    }
                }
                if(!dup){
                    currLen = j - i + 1;
                    maxLen = max(maxLen, currLen);
                }
            }
       }
       return maxLen;

    }
};


// * OPTIMAL APPROACH:
class Solution2{
  public:
    int longestNonRepeatingSubstring(string& s){
        map<char, int> mp;
        int left = 0, right = 0, maxLen = 0;

        while(right < s.size()){
            if(mp.find(s[right]) != mp.end() &&  mp[s[right]]  >= left) {
                left = mp[s[right]] + 1;
                continue;
            }
            else mp[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};