Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1], k = 1
Output: 1
Example 2:

Input: nums = [1,2], k = 4
Output: -1
Example 3:

Input: nums = [2,-1,2], k = 3
Output: 3
 

Constraints:

1 <= nums.length <= 105
-105 <= nums[i] <= 105
1 <= k <= 109



  class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) {
        stack<long long>s;
        map<long long,int>m;
        long long x=0,ans=INT_MAX,n=a.size();

        for(long long i=0;i<n;i++){
            x+=a[i];
            if(x>=k){ans=min(ans,i+1);}

            long long y=x-k;
            auto it=m.upper_bound(y);
            
            if(it==m.begin()){it=m.end();}
            else{it--;}

            if(it!=m.end()){
                ans=min(ans, i - it->second );}

            while(s.size()!=0 && s.top() >= x){
                m.erase(s.top());
                s.pop();}
            
            s.push(x);
            m[x]=i;

        }
        if(ans==INT_MAX){return -1;}

        return ans;
        
    }
};
