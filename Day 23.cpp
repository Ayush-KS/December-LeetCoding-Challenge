// Next Greater Element III

class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        n = str.size();
        int i = n - 1;
        while(i > 0) {
            if(str[i - 1] < str[i]) {
                break;
            }
            i--;
        }
        if(!i)
            return -1;
        int j = i + 1;
        int x = i;
        while(j < n) {
            if(str[j] > str[i - 1] && str[j] < str[x]) {
                x = j;
            }
            j++;
        }
        swap(str[i - 1], str[x]);
        sort(str.begin() + i, str.end());
        long ans = stol(str);
        if(ans >= INT_MAX)
            return -1;
        return ans;
    }
};