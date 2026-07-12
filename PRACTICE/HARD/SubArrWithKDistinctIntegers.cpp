
#include<bits/stdc++.h>
using namespace std;


// * BRUTE FORCE O(n³)
 int subarraysWithKDistinct(vector<int>& nums, int k) {
  int cnt = 0, n = nums.size();

  for(int i = 0; i < n; i++){
      for(int j = i; j < n; j++){
          set<int> st;
          for(int k = i; k <= j; k++){
              st.insert(nums[k]);
          }
          if(st.size() == k)
              cnt++;
      }
  }
  return cnt;
}
// * Slightly Better O(n²)
int subarraysWithKDistinct(vector<int>& nums, int k) {
  int cnt = 0, n = nums.size();

  for(int i = 0; i < n; i++){
      set<int> st;
      for(int j = i; j < n; j++){
          st.insert(nums[j]);
          if(st.size() > k) break;
          else if(st.size() == k) cnt++;
      }
  }
  return cnt;
}

// * Optimal Approach using Sliding Window
int atMostK(vector<int>& nums, int k){
    int cnt = 0, n = nums.size();
  int i = 0, j = 0;
  unordered_map<int, int> hash;
  
  while(j < n){
      // * Include current element in the windows
      int ele = nums[j];
      if(hash.find(ele) == hash.end()) 
          k--;
      hash[ele]++;

      // * Shrink the window if k goes below 0
      while(i <= j && k < 0){
          hash[nums[i]]--;
          if(hash[nums[i]] == 0) {
              hash.erase(nums[i]);
              k++;
          }
          i++;
      }
      cnt += (j-i+1);
      j++;
  }
  return cnt;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
  return atMostK(nums, k) - atMostK(nums, k - 1);
}