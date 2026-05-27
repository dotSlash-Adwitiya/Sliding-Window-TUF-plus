#include<bits/stdc++.h>
using namespace std;

// * BRUTE FORCE: O(N²)
int numberOfSubstrings(string s) {
  int cnt = 0, n = s.size();
  for(int i = 0; i < n; i++){
      int hash[3] = {0};
      for(int j = i; j < n; j++){    
          hash[s[j] - 'a'] = 1;
          if(hash[0] + hash[1] + hash[2] == 3)
              cnt++;
      }
  }
  return cnt;
}

// * Slight Optimization for some cases except for: "aaaaaa"
int numberOfSubstrings(string s) {
  int cnt = 0, n = s.size();
  for(int i = 0; i < n; i++){
      int hash[3] = {0};
      for(int j = i; j < n; j++){    
          hash[s[j] - 'a'] = 1;
          if(hash[0] + hash[1] + hash[2] == 3){
              cnt += (n-j);
              break;
          }
      }
  }
  return cnt;
}

// * Optimal Approach:
// * TC: O(N)
int numberOfSubstrings(string s) {
  int cnt = 0, n = s.size();
  int lastSeen[3] = {-1, -1, -1};
  for(int i = 0; i < n; i++){
          lastSeen[s[i] - 'a'] = i; 
          if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
              cnt += min(lastSeen[0], min(lastSeen[1], lastSeen[2])) + 1;
  }
  return cnt;
}