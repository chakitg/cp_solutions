The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

 

Example 1:

Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.
Example 2:

Input: nums = [1,4,8,13], k = 5
Output: 2
Explanation: There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
Example 3:

Input: nums = [3,9,6], k = 2
Output: 1
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= k <= 105




class Solution {
public:
    bool check(int mid,vector<int> &nums,int k,int n)
    {
        long long int i=0,j=0;
        long long int sum=0;
        while(j<n)
        {
            sum+=nums[j];
            while((j-i+1)>mid)
            {
                sum-=nums[i];
                i++;
            }
            if((j-i+1)==mid)
            {
                if(((j-i+1)*nums[j] - sum) <= k)
                    return 1;
            }
            j++;
        }
        return 0;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int low=1,high=n;
        int ans=1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(check(mid,nums,k,n))
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};
