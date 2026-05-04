#include<bits/stdc++.h>
using namespace std;

// * BRUTE FORCE :
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0, n = s.size();

        for(int i = 0; i < n; i++){
            int hash[26] = {0}, maxFreq = 0;
            for(int j = i; j < n; j++){
               hash[s[j] - 'A']++;
               if(hash[s[j] - 'A'] > maxFreq)
                maxFreq =  hash[s[j] - 'A'];

               int changes = (j - i + 1) - maxFreq;

               if(changes <= k) maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;

    }
};