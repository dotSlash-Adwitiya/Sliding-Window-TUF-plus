#include<bits/stdc++.h>
using namespace std;
// * Leetcode (209.) Link: https://leetcode.com/problems/minimum-size-subarray-sum/description/

int minSubArrayLen(int target, vector<int>& nums) {
    int minLen = INT_MAX;
    int i = 0, j = 0, n = nums.size();
    long long sum = 0;
    while(j < n){
        sum += nums[j];
        if(sum >= target) minLen = min(minLen, j - i + 1);
        while(sum > target){
            sum -= nums[i];
            i++;
            if(sum >= target) minLen = min(minLen, j - i + 1);
        }
        if(sum >= target) minLen = min(minLen, j - i + 1);
        j++;
    }
    return (minLen == INT_MAX ? 0 : minLen);
}