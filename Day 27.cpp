// Jump Game IV

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> visited(n, 0);
        queue<int> q;
        q.push(0);
        int cnt = 0;
        visited[0] = true;
        unordered_map<int, set<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]].insert(i);
        }
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int curr = q.front();
                if(curr == n - 1)
                    return cnt;
                q.pop();
                
                if(curr && !visited[curr - 1]) {
                    q.push(curr - 1);
                    visited[curr - 1] = true;
                }
                if(curr < n - 1 && !visited[curr + 1]) {
                    q.push(curr + 1);
                    visited[curr + 1] = true;
                }
                
                for(auto it : mp[arr[curr]]) {
                    if(!visited[it]) {
                        q.push(it);
                        visited[it] = true;
                    }
                }
                mp[arr[curr]].clear();
            }
            cnt++;
        }
        
        return cnt;
    }
};