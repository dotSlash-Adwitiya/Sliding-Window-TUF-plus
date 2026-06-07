#include<bits/stdc++.h>
using namespace std;

int solve(string &s, int k){
    int i = 0, j = 0, n = s.size(), cnt = 0, distinct = 0;
    int mp[26] = {0};
    while(j < n){
        if(mp[s[j] - 'a'] == 0) distinct++;
        mp[s[j] - 'a']++;
        while(distinct > k){
            mp[s[i] - 'a']--;
            if(mp[s[i] - 'a'] == 0)
                distinct--;
            i++;
        }
        cnt += j - i + 1;
        j++;
    }
    return cnt;
}
int countSubstr(string& s, int k) {
    return solve(s, k) - solve(s, k - 1);
}