// Reach a Number

class Solution {
public:
    int reachNumber(int target) {
        if(target < 0)
            target *= -1;
        int i = 0;
        int sum = 0;
        for(; sum < target || (target - sum) & 1; i++) {
            sum += (i + 1);
        }
        return i;
    }
};