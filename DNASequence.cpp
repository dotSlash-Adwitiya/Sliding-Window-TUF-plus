// * Leetcode Link: https://leetcode.com/problems/repeated-dna-sequences/?envType=problem-list-v2&envId=sliding-window

#include<bits/stdc++.h>
using namespace std;


// * TC: O(nlogn)
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> ans;
        int left = 0, right = 0, n = s.size();
        set<string> sequence;

        for(int i = 0; i <= n-10; i++){
            string temp = "";
            // * Runs exactly 10 times
            for(int j = i; j < i + 10; j++){
                temp += s[j];
            }
            // * Check if this sequence was seen earlier
            if(sequence.find(temp) != sequence.end())
                ans.insert(temp);
            // * Else insert this sequence to be looked upon later
            else
                sequence.insert(temp);
        }
        vector<string> dna(ans.begin(), ans.end());
        return dna;
    }
};