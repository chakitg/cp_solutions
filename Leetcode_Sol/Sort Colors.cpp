class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=-1, b=nums.size();
        int i=0;
        
        while(i<b)
        {
            if(nums[i]==0)
            {
                r++;
                swap(nums, i, r);
            }
            if (nums[i]==2)
            {
                b--;
                swap(nums, i, b);
                i--;
            }
            i++;
        }
    }
    
private:
    void swap(vector<int>& nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};