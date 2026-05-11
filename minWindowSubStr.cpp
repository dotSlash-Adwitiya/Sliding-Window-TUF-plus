#include<bits/stdc++.h>
using namespace std;

// * TC: O(n²)
string minWindow(string s, string t) {
        int mini = INT_MAX;
        int n = s.size(), m = t.size(), startIdx = -1;
        for(int i = 0; i < n; i++){
            int hash[256] = {0};
            int cnt = 0;
            for(char &ch : t) hash[ch]++;

            for(int j = i; j < n; j++){
                if(hash[s[j]] > 0) cnt++;
                hash[s[j]]--;
                if(cnt == m) {
                   if(j - i + 1 < mini){
                    mini = j - i + 1;
                    startIdx = i;
                   }
                    // * No need to go further because going beyond is pointless as we're looking to minimize the substring size
                    break;
                }
            }
        }

        return (startIdx == - 1) ? "" : s.substr(startIdx, mini);
    }