// Can Place Flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int cnt) {
        for(int i = 0; i < arr.size(); i++) {
            if(cnt && !arr[i]) {
                if(i && arr[i - 1])
                    continue;
                if(i < arr.size() - 1 && arr[i + 1])
                    continue;
                arr[i] = 1;
                cnt--;
            }
        }
        return cnt == 0;
    }
};