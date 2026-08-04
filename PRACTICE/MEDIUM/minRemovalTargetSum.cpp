#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums, int k) {
  int n = nums.size(); 
  int maxLen = -1;
  int currSum = 0;
  int i = 0, j = 0;
  
  while(j < n) {
      currSum += nums[j];
  
      while(i <= j && currSum > k) {
          currSum -= nums[i];
          i++;
      }
  
      if(currSum == k)
          maxLen = max(maxLen, j - i + 1);
  
      j++;
  }
  return maxLen;
}

int minRemovals(vector<int> &arr, int k) {
  int n = arr.size();
  
  int totalSum = accumulate(arr.begin(), arr.end(), 0);
  
  int target = totalSum - k;
  
  int maxSubArr = longestSubarray(arr, target);
  
  if(maxSubArr == -1)
      return -1;
  
  return n - maxSubArr;
}