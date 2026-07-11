#include<bits/stdc++.h>
using namespace std;

// * Gfg Link: https://www.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1

int smallestSubWithSum(int x, vector<int>& arr) {
  int i = 0, j = 0, sum = 0, n = arr.size(), len = INT_MAX;
  while(j < n){
      sum += arr[j];
      while(i <= j && sum > x){
          len = min(len, (j-i+1));
          sum -= arr[i];
          i++;
      }
      if(sum > x) len = min(len, (j-i+1));
      j++;
  }
  if(len == INT_MAX) return 0;
  return len;
}