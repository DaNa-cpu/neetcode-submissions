class Solution {

public:
    int calPoints(vector<string>& operations) {
        int sum=0;
        stack<int> ans;
        for( const string &op: operations){
            if(op == "+"){
                int top1 = ans.top(); ans.pop();
                int top2 = ans.top();
                int res = top1 + top2;
                
                ans.push(top1);
                ans.push(res);
                sum += res;
            }
            else if(op =="D"){
                ans.push(2*ans.top());
                sum += ans.top();
            }
            else if(op =="C"){
                int top = ans.top(); ans.pop();
                sum -= top;
            }
            else{
                ans.push(stoi(op));
                sum += ans.top();
            }

        }
        return sum;
    }
};