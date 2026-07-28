class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> rules = { {')','('}, {']','['}, {'}','{'} };

        for(char c:s){
            if(!stack.empty() and c == ')' and stack.top()=='('){
                stack.pop();
            }
            else if(!stack.empty() and c == ']' and stack.top()=='['){
                stack.pop();
            }
            else if(!stack.empty() and c == '}' and stack.top()=='{'){
                stack.pop();
            }
            else{
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
