Given two positive integer arrays arr and brr, find the number of pairs such that xy > yx (raised to power of) where x is an element from arr and y is an element from brr.

Examples :

Input: arr[] = [2, 1, 6], brr[] = [1, 5]
Output: 3
Explanation: The pairs which follow xy > yx are: 21 > 12,  25 > 52 and 61 > 16 .
Input: arr[] = [2 3 4 5], brr[] = [1 2 3]
Output: 5
Explanation: The pairs which follow xy > yx are: 21 > 12 , 31 > 13 , 32 > 23 , 41 > 14 , 51 > 15 .
Expected Time Complexity: O((N + M)log(N)).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ arr.size(), brr.size() ≤ 105
1 ≤ brr[i], arr[i] ≤ 103





class Solution {
  public:
   int binarySearch(int key,vector<int> &brr){
        int low=0,high=brr.size()-1,mid,index=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(brr[mid]<=key){
                index=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return index;
    }
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
         long long ans = 0, one = 0, two = 0, threeFour = 0;
        sort(brr.begin(),brr.end());
        for(auto x:brr){
            if(x==1)one++;
            else if(x==2)two++;
            else if(x==3 or x==4)threeFour++;
        }
        for(auto x:arr){
            if(x!=1){
                ans+=one;
                if(x==2)ans-=threeFour;
                if(x==3)ans+=two;
                int index = binarySearch(x,brr);
                ans+=(brr.size()-index-1);
            }
        }
        return ans;
    }
};
