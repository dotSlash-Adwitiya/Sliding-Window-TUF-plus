#include<bits/stdc++.h>
using namespace std;

// * Leetcode Link: https://leetcode.com/problems/k-radius-subarray-averages/

// * Sliding Window Approach
vector<int> getAverages(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> average(n, -1);
    if(k >= n) return average;
    int i = 0;
    int j = i + (k * 2);
    if((j > n) || (i + k) > n || (i + k + 1 > n) || (i + k + k + 1 > n)) 
        return average;
    int totalEle = j - i + 1;
    
    long long prefixSum = accumulate(nums.begin(), nums.begin()+k+1, 0LL);
    long long suffixSum = accumulate(nums.begin()+k+1, nums.begin()+k+k+1, 0LL);
    long long sum = prefixSum + suffixSum;
    int idx = k;
    while(j < n){
        average[idx] = sum/totalEle;
        idx++;
        sum -= nums[i];
        
        j++, i++;
        if(j < n) sum += nums[j];
    }
    return average;
}