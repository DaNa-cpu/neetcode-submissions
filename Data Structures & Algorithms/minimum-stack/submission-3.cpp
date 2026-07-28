class MinStack {
private:
    vector<int> stack;
    vector<int> minime;  

public:
    MinStack() {}
    
    void push(int val) {
        if(stack.empty()){
            minime.push_back(val);
        } else {
            minime.push_back(min(val, minime.back()));
        }
        stack.push_back(val);
    }
    
    void pop() {
        if(!stack.empty()){
            stack.erase(stack.end()-1);
            minime.erase(stack.end()-1);
        }
    }
    
    int top() {
        if(!stack.empty()){
            return stack[stack.size()-1];
        }
    }
    
    int getMin() {
        if(!stack.empty()){
            return minime[minime.size()-1];
        }
    }
};
