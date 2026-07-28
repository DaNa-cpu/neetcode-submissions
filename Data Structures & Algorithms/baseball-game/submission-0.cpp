class Solution {

public:
    int calPoints(vector<string>& operations) {
        int sum=0;
        vector<int> ans;
        for( const string &op: operations){
            if(op == "+"){
                int top1 = ans.back(); ans.pop_back();
                int top2 = ans.back();
                int res = top1 + top2;
                
                ans.push_back(top1);
                ans.push_back(res);
                sum += res;
            }
            else if(op =="D"){
                ans.push_back(2*ans.back());
                sum += ans.back();
            }
            else if(op =="C"){
                int top = ans.back(); ans.pop_back();
                sum -= top;
            }
            else{
                ans.push_back(stoi(op));
                sum += ans.back();
            }

        }
        return sum;
    }
};