class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;

        for(auto& c: s){
            if(mp.contains(c)){
                mp[c]++;
            }else{
                mp[c] = 1;
            }
        }

        for(auto& c: t){
            if(mp.contains(c) && mp[c]!=0){
                mp[c]--;
                if(mp[c] == 0){
                    mp.erase(c);
                }
            }else{
                return false;
            }
        }

        return mp.empty();
    }
};
