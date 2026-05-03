// * BRUTE FORCE
class Solution1 {
public:
    int kDistinctChar(string& s, int k) {

        int maxLen = 0, n = s.size();

        for(int i = 0; i < n; i++){
            unordered_map<char , int> freq;
            for(int j = i; j < n; j++){
                freq[s[j]]++;
                if(freq.size() <= k) maxLen = max(maxLen, j - i + 1);
                else break;
            }
        }
        return maxLen;

    }
};

// * Better Approach :-
class Solution {
public:
    int kDistinctChar(string& s, int k) {

        int maxLen = 0, n = s.size();
        int left = 0, right = 0;
        unordered_map<char, int> mp;
        while(right < n){
            // Increment frequency of current character
            mp[s[right]]++;
            /* If the number of distinct characters 
            exceeds k, shrink the window from the left*/
            while(mp.size() > k && left < right){
                // Decrement frequency of character at left pointer
                mp[s[left]]--;
                /* Remove character from map 
                   if its frequency becomes zero*/
                if(mp[s[left]] == 0) 
                    mp.erase(s[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};