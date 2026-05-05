#include<bits/stdc++.h>
using namespace std;

// * TC : O(N²)
//* BRUTE FORCE
class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int ans = 0, n = s.size();
       for(int i = 0; i <= n - k; i++){
        int hash[26] = {0};
        string temp = "";
        for(int j = i; j < n; j++){
            // * If char is not present, EXPAND
            if(hash[s[j] - 'a'] == 0){
                hash[s[j] - 'a']++;
            } else {
                // * SHRINK
                break;
            }
            if((j - i + 1) == k) {
                // cout << "Size k = " << k << ", " << temp << endl;
                ans++;
                break;
            }
        }
       }
       return ans;
    }
};