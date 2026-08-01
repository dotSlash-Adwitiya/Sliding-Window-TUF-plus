#include<bits/stdc++.h>
using namespace std;

// * Leetcode Link: https://leetcode.com/problems/sliding-subarray-beauty/submissions/2090532288/

//* TC: O(n), SC:O(1)
int findXthSmallest(vector<int>& freq, int x) {
  int count = 0;
  // * We only care about negative numbers for beauty
  // * Observing the constraints
  for (int val = -50; val < 0; val++) {
      count += freq[val + 50];
      if (count >= x) return val;
  }
  return 0;
}

vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {

  int n = nums.size();
  // * nums[i] ranges from -50 to 50
  // * index = value + 50
  vector<int> freq(101, 0);
  vector<int> beauty;
  int i = 0, j = 0;
  while(j < n){
      // * Add current element to window (+50 because hash index can't be negative)
      freq[nums[j] + 50]++;
      // * Window became larger than k
      if (j - i + 1 > k) {
          freq[nums[i] + 50]--;
          i++;
      }
      // * Valid window
      if (j - i + 1 == k) beauty.push_back(findXthSmallest(freq, x));
      j++;
  }
  return beauty;
}


// * TC: O(nlogn), SC: O(n)
int findXthSmallest(vector<int> nums, int x, int i, int j) {
  vector<int> temp(nums.begin() + i, nums.begin() + j + 1);
  sort(temp.begin(), temp.end());
  return temp[x - 1];
}

vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
  int i = 0;
  int j = 0;
  int n = nums.size();
  vector<int> beauty;
  while (j < n) {
      if (j - i + 1 == k) {
          int xthSmall = findXthSmallest(nums, x, i, j);
          beauty.push_back(min(xthSmall, 0));
          i++;
      }
      j++;
  }
  return beauty;
}