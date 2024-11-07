Given an array, arr[], determine if arr can be split into three consecutive parts such that the sum of each part is equal. If possible, return any index pair(i, j) in an array such that sum(arr[0..i]) = sum(arr[i+1..j]) = sum(arr[j+1..n-1]), otherwise return an array {-1,-1}.

Note: Since multiple answers are possible, return any of them. The driver code will print true if it is correct otherwise, it will print false.

Examples :

Input:  arr[] = [1, 3, 4, 0, 4]
Output: true
Explanation: [1, 2] is valid pair as sum of subarray arr[0..1] is equal to sum of subarray arr[2..3] and also to sum of subarray arr[4..4]. The sum is 4, so driver code prints true.
Input: arr[] = [2, 3, 4]
Output: false
Explanation: No three subarrays exist which have equal sum.
Input: arr[] = [0, 1, 1]
Output: false
Constraints:
3 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106



class Solution {
    public:
    vector<int> findSplit(vector<int>& arr) {
        int sum=0;
        for(auto& it:arr)
        sum+=it;
        
        if(sum==0)
        return {0,1};
        
        int s=0;
        int e=sum;
        while(s<=e)
        {
            int mid=(s+e)/2;
            //cout<<"mid -> "<<mid<<endl;
            vector<int> index;
            int currSum=arr[0];
            bool flag=1;
            for(int i=1;i<arr.size();i++)
            {
                //if(currSum)
                if(currSum+arr[i]>mid)
                {
                    if(currSum!=mid)
                    flag=0;
                    
                    index.push_back(i-1);
                    currSum=arr[i];
                }
                else
                currSum+=arr[i];
            }
            
            if(currSum and currSum!=mid)
            flag=0;
            
            if(flag and index.size()==2)
            {
                //cout<<"yes"<<endl;
                return index;
            }
            
            //cout<<"mid -> "<<mid<<" size "<<index.size()<<endl;
            if(index.size()==2)
            {
                if(currSum<mid)
                e=mid-1;
                else
                s=mid+1;
            }
            else if(index.size()>2)
            s=mid+1;
            else
            e=mid-1;
        }
        
        return {-1,-1};
    }
};
