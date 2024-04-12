Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105






class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        int left=0,right=n-1;
        int l=0,r=0,ans=0;
        while(left<=right){
            if(a[left]<=a[right]){
                // left may be contrtibuting
                l=max(l,a[left]);
                ans+=l-a[left];
                left++; 
            }
            else if(a[left]>a[right]){
                r=max(r,a[right]);
                ans+=r-a[right];
                right--;
            }
        }
        return ans;
    }
};
