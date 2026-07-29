#include<bits/stdc++.h>
using namespace std;


int sumOfModes(vector<int>& arr, int k) {
  unordered_map<int, int> mp;
  int maxFreq = 0;
  int maxFreqEle = arr[0];
  int i = 0, j = 0, n = arr.size(), sumMode = 0;

  while(j < n){
      // * Expand Window
      mp[arr[j]]++;
      
      // * Updated Freq if freq is more
      if(maxFreq < mp[arr[j]]){
        maxFreq = mp[arr[j]];
        maxFreqEle = arr[j];
      }
      // * Updated Freq if freq is same but value is small
      else if(maxFreq == mp[arr[j]] && arr[j] < maxFreqEle){
          maxFreq = mp[arr[j]];
          maxFreqEle = arr[j];
      }
      
      
      if((j - i + 1 ) > k){
          mp[arr[i]]--;
          if(arr[i] == maxFreqEle){
              maxFreq--;
              // * Go through map to find the new high freq ele
              for (const auto& it : mp) {
                  if (it.second > maxFreq ||
                      (it.second == maxFreq && it.first < maxFreqEle)) {
                      maxFreq = it.second;
                      maxFreqEle = it.first;
                  }
              }
          }
          // * Shrink Window
          i++;
      }
      
      if((j - i + 1) == k)
          sumMode += maxFreqEle;
      
      j++;
  }
  return sumMode;
}