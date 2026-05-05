#include<bits/stdc++.h>
using namespace std;

// * TC: O(N²)
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

// * BETTER Approach
// * TC: O(N + N) * 26
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0, maxFreq = 0, n = s.size();
        int left = 0, right = 0;
        int hash[26] = {0};
        while(right < n){
            hash[s[right] - 'A']++;
            maxFreq = max(maxFreq, hash[s[right] - 'A']);
            while(left < right && ((right - left + 1) - maxFreq) > k) {
                hash[s[left] - 'A']--;
                maxFreq = 0;
                for(int i = 0; i < 26; i++){
                    maxFreq = max(maxFreq, hash[i]);
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;

    }
};


// * OPTIMAL Approach
// * TC: O(n) * 26
int characterReplacement(string s, int k) {
    int maxLen = 0, maxFreq = 0, n = s.size();
    int left = 0, right = 0;
    int hash[26] = {0};
    while(right < n){
        hash[s[right] - 'A']++;
        maxFreq = max(maxFreq, hash[s[right] - 'A']);
        if(left < right && ((right - left + 1) - maxFreq) > k) {
            hash[s[left] - 'A']--;
            maxFreq = 0;
            for(int i = 0; i < 26; i++){
                maxFreq = max(maxFreq, hash[i]);
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;

}