class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int L = 0;
        int maxLength = 0;
        
        for(int R = 0; R < s.size(); R++){
            while(seen.count(s[R])){
                seen.erase(s[L]);
                L++;
            }
            seen.insert(s[R]);
            maxLength = max(maxLength, R - L + 1);
        }
        return maxLength;
    }
};
