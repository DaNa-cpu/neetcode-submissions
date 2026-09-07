class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int, int> freq = {{0, 0},{1, 0}};
        for( int i=0 ; i < students.size(); i++){
            freq[students[i]]++;
        }
        
        for( int i=0 ; i < sandwiches.size(); i++){
            if( freq[sandwiches[i]] == 0 ){
                break;
            }
            else{
                freq[sandwiches[i]]--;
            }
        }
        int sum = freq[1] + freq[0];
        return sum;
    }
};