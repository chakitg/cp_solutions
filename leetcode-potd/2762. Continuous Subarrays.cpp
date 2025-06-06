You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:

Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
Return the total number of continuous subarrays.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [5,4,2,4]
Output: 8
Explanation: 
Continuous subarray of size 1: [5], [4], [2], [4].
Continuous subarray of size 2: [5,4], [4,2], [2,4].
Continuous subarray of size 3: [4,2,4].
Thereare no subarrys of size 4.
Total continuous subarrays = 4 + 3 + 1 = 8.
It can be shown that there are no more continuous subarrays.
 

Example 2:

Input: nums = [1,2,3]
Output: 6
Explanation: 
Continuous subarray of size 1: [1], [2], [3].
Continuous subarray of size 2: [1,2], [2,3].
Continuous subarray of size 3: [1,2,3].
Total continuous subarrays = 3 + 2 + 1 = 6.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109



class Solution {
public:
    long long continuousSubarrays(vector<int>& a) {
        int n = (int)a.size();
        long long ans = 0;
        int l = 0;
        multiset<int>s;
        for(int i = 0 ; i < n ; i++) {
            s.insert(a[i]);
            while(abs(*s.rbegin() - *s.begin()) > 2) {
                s.erase(s.find(a[l]));
                l++;
            }
            ans += (i-l+1);
        }
        return ans;
    }
};



// ______________________________________________________________________________________________

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int l = 0,r = 0;
        int n = nums.size();
        
        multiset<int> st;
        while(l<n){
            
            while(r<n){
                if(st.size()==0){
                    st.insert(nums[r]);
                    r++;
                }
                else{
                    int mn = *st.begin();    
                    int mx = *st.rbegin();
                
                    mn = min(mn,nums[r]);
                    mx = max(mx,nums[r]);
                    if(mx-mn>2)break;
                    st.insert(nums[r]);
                    r++;
                }
            }
          
            long long len = r-l;
            ans+=len;
            st.erase(st.find(nums[l]));
            l++;
        }
        return ans;
    }
};
