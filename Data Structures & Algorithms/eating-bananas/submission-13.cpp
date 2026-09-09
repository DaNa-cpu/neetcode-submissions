class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // the range should be between min and max values;
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while(left < right){
            int mid = left + (right - left) / 2;
            if(!condition(mid, piles, h)){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
private:
    bool condition(int speed, vector<int>& piles, int h){
        long long hours = 0;
        for(int pile: piles){
            hours += (pile + speed - 1) / speed;
        }
        return hours <= h;
    }
};
