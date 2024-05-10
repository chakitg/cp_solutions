Given an array of integers arr, the length of the array n, and an integer k, find all the unique combinations in arr where the sum of the combination is equal to k. Each number can only be used once in a combination.
Return the combinations in the lexicographically sorted order, where each combination is in non-decreasing order.

Example 1:

Input: 
n = 5, k = 7
arr[] = { 1, 2, 3, 3, 5 }
Output:
{ { 1, 3, 3 }, { 2, 5 } }
Explanation:
1 + 3 + 3 = 7
2 + 5 = 7
Example 2:

Input:
n = 6, k = 30
arr[] = { 5, 10, 15, 20, 25, 30 }
Output:
{ { 5, 10, 15 }, { 5, 25 }, { 10, 20 }, { 30 } }
Explanation:
5 + 10 + 15 = 30
5 + 25 = 30
10 + 20 = 30
Your Task:
You don't need to read input or print anything. Your task is to complete the function CombinationSum2() which takes arr[],n, and k as input parameters and returns all the unique combinations.
 

Constraints:
1 <= n <= 100
1 <= arr[i] <= 50
1 <= k <= 30

let p = number of elements, at maximum, can sum up to the given value k.

Expected Time Complexity: O(2min(n,p))
Expected Auxiliary Space: O(n)






class Solution{
public:
    void solve1(vector<int> &arr, int i, int k, vector<int> &temp, vector<vector<int>> &ans){
        if(i == arr.size()){
            if(k == 0){
                ans.push_back(temp);

            }
            return;
        }

        if(arr[i] <= k){
            temp.push_back(arr[i]);
            solve1(arr, i+1, k-arr[i], temp, ans);
            temp.pop_back();
        }

        int j = 0;
        while(j+i < arr.size() && arr[i] == arr[j+i]) j++;

        solve1(arr, i+j, k, temp, ans);

    }

    void solve2(vector<int> &arr, int ind, int target, vector<int>& temp, vector<vector<int>> &ans){

            if(target == 0) 
            {
                ans.push_back(temp);
                return;
            }

        for(int j = ind; j < arr.size(); j++){

            if(j > ind && arr[j] == arr[j-1]) continue;

            if(target < arr[j]) break;

            temp.push_back(arr[j]);
            solve2(arr, j+1, target - arr[j], temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        vector<vector<int>> ans;
        vector<int> temp;

        sort(arr.begin(), arr.end());
        solve2(arr, 0, k, temp, ans);


        // solve1(arr, 0, k, temp, ans);
        return ans;
    }
};
