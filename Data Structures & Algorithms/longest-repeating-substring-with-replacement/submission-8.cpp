class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int L = 0;
        int maxLen = 0;
        int mostFreq = 0;

        for(int R = 0; R < s.size(); R++){
            if(freq.count(s[R])){
                freq[s[R]]++;
            }else{
                freq[s[R]] = 1;
            }
            mostFreq = max(mostFreq, freq[s[R]]);
            while(R - L + 1 - mostFreq > k){
                freq[s[L]]--;
                L++;
            }
            maxLen = max(R-L+1, maxLen);
        }
        return maxLen;
    }
};
