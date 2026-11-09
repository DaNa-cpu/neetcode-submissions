class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0;
        int R = s.size();

        while(L < R){
            while(L < R && !iswalnum(s[L])){
                L++;
            }
            while(L < R && !iswalnum(s[R])){
                R--;
            }

            char left = tolower(s[L]);
            char right = tolower(s[R]);
            if(left == right){
                L++;
                R--;
            }else{
                return false;
            }

        }
        return true;
    }
};
