Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.

 

Example 1:


Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]
Example 2:


Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i].length <= 105
1 <= sum(nums[i].length) <= 105
1 <= nums[i][j] <= 105




class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=nums.size(), M=0, sz;
        
        for(int i=0; i<n; i++){
            M=max(M, i+(int)nums[i].size());
            sz+=nums[i].size();
        }
        vector<vector<int>> diag(M+1);

        
        for(int i=0; i<n; i++){
            int col=nums[i].size();
            
            for(int j=0; j<col; j++){
                diag[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans(sz);
        int idx=0;
       
        for(int i=0; i<=M; i++){
           copy(diag[i].rbegin(), diag[i].rend(), ans.begin()+idx);
           idx+=diag[i].size();
        }
        return ans;
    }
};
