class Solution {
  private:
    int mod = 100000;
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end)
            return 0;
        vector<int> ans(100000, 1e9);
        ans[start] = 0;
        queue<pair<int, int> > q;
        q.push({start, 0});
        while(!q.empty()){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();
            for(auto it : arr){
                int next = (num*it)%mod;
                if(ans[next] > step + 1){
                    ans[next] = (step + 1);
                    if(next == end)
                        return step + 1;
                    q.push({next, ans[next]});
                }
            }
        }
        return -1;
    }
};
