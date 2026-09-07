class MyStack {
private:
    queue<int> main_queue;
    queue<int> sec_queue;
public:

    MyStack() {}
    
    void push(int x) {
        swap(main_queue, sec_queue);
        main_queue.push(x);
        while(!sec_queue.empty()){
            main_queue.push(sec_queue.front());
            sec_queue.pop();
        }
    }
    
    int pop() {
        int top = main_queue.front();
        main_queue.pop();
        return top; 
    }
    
    int top() {
        return main_queue.front();
    }
    
    bool empty() {
        if (main_queue.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */