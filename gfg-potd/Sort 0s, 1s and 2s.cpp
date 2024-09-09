Given an array arr containing only 0s, 1s, and 2s. Sort the array in ascending order.

Examples:

Input: arr[]= [0, 2, 1, 2, 0]
Output: 0 0 1 2 2
Explanation: 0s 1s and 2s are segregated into ascending order.
Input: arr[] = [0, 1, 0]
Output: 0 0 1
Explanation: 0s 1s and 2s are segregated into ascending order.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size() <= 106
0 <= arr[i] <= 2





class Solution {
  public:
    void sort012(vector<int>& arr) {
        int zero=0,one=0,two=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                zero++;
            }
            else if(arr[i]==1){
                one++;
            }
            else{
                two++;
            }
        }
        for(int i=0;i<arr.size();i++){
            if(zero!=0){
                arr[i]=0;
                zero--;
            }
            else if(zero==0 && one!=0){
                arr[i]=1;
                one--;
            }
            else{
                arr[i]=2;
                two--;
            }
        }

    }
};
