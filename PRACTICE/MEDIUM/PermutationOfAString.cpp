#include<bits/stdc++.h>
using namespace std;

// * Leetcode Link: https://leetcode.com/problems/permutation-in-string/description/

// * O(mlogn)
bool checkInclusion(string s1, string s2) {
  int n = s1.size(), m = s2.size();
  if(n > m) return false;
  sort(s1.begin(), s1.end());

  for(int i = 0; i <= m - n; i++){
      string temp = s2.substr(i, n);

      sort(temp.begin(), temp.end());

      if(temp == s1)
          return true;
  }

  return false;
}

// * Optimized approach compared to TC: O(N)
bool areVectorsEqual(vector<int> a, vector<int> b){
  for(int i=0; i<26; i++){
      // * If any character is found to be of different frequency, this is not a permutation
      if(a[i]!=b[i]) return false;
  }
  return true;
}

bool checkInclusion(string s1, string s2) {
  if(s2.size()<s1.size()) return false;
  vector<int> freqS1(26, 0);
  for(char c: s1) freqS1[c-'a']++;
  
  vector<int> freqS2(26, 0);
  int i=0, j=0;
  
  while(j<s2.size()){
      // * Include the character in curr Window
      freqS2[s2[j]-'a']++;
      
      // * CurrWindow == m.size(), now compare currWindow with the desired window in O(26)
      if(j-i+1==s1.size()){
          if(areVectorsEqual(freqS1, freqS2)) return true;
      }
      // * If desired window size not  reached
      if(j-i+1<s1.size()) j++;
      // * Ensure currWindow size never goes beyond or below the desired window size
      else{
          freqS2[s2[i]-'a']--;
          i++;
          j++;
      }
  }
  return false;
}
