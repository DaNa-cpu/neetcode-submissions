class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> rules = { {')','('}, {']','['}, {'}','{'} };

        for(char c:s){
            if(rules.count(c)){
                if (!stack.empty() and stack.top()== rules[c]){
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};