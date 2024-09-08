class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        int jump = 0;
        int n = arr.size();
        int maxi=0;
        int mrange=0;

        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]+i);
            if(mrange==i){
                mrange=maxi;
                jump++;
                if(mrange>=n-1)
                {
                  return jump;
                }
            }
        }

        return -1;
    }


};
