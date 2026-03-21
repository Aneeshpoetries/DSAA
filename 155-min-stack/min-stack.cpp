class MinStack {
public:
    stack<int>s;
    stack<int>ms;
    int curr;
    MinStack() {
        curr=INT_MAX;
    }
    
    void push(int val) {
        s.push(val);
        if(val<=curr){
            curr=val;
            ms.push(val);
        }

    }
    
    void pop() {
        if(s.empty())return;
        if(s.top()==ms.top()){ms.pop();}
        s.pop();
        if(!ms.empty()){
            curr=ms.top();}
        else{
            curr=INT_MAX;
        }
        
    }
    
    int top() {
        if(s.empty())return -1;
        return s.top();
    }
    
    int getMin() {
        return curr;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */