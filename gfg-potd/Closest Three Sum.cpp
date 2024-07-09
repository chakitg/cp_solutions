Given an array, arr of integers, and another number target, find three integers in the array such that their sum is closest to the target. Return the sum of the three integers.

Note: If there are multiple solutions, return the maximum one.

Examples :

Input: arr[] = [-7, 9, 8, 3, 1, 1], target = 2
Output: 2
Explanation: There is only one triplet present in the array where elements are -7,8,1 whose sum is 2.
Input: arr[] = [5, 2, 7, 5], target = 13
Output: 14
Explanation: There is one triplet with sum 12 and other with sum 14 in the array. Triplet elements are 5, 2, 5 and 2, 7, 5 respectively. Since abs(13-12) ==abs(13-14) maximum triplet sum will be preferred i.e 14.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)

Constraints:
3 ≤ arr.size() ≤ 103
-105 ≤ arr[i] ≤ 105
1 ≤ target ≤ 105





int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int diff = INT_MAX, maxi=INT_MIN;

        sort(arr.begin(), arr.end());

        int n = arr.size();

        for(int i=0; i<n-2; i++) {
            int l = i+1, r = n-1;

            int sum = 0;

            while(l<r) {
                sum = arr[i]+arr[l]+arr[r];

                int temp = abs(target-sum);

                if(temp==diff) {
                    maxi=max(sum, maxi);
                } else if(temp<diff) maxi=sum, diff=temp;

                if(sum<target) l++;
                else {
                    r--;
                }

            }
        }

        return maxi;
    }
