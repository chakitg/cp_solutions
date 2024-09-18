Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109




  class Solution {
private:
    static bool comparator(int &num1, int &num2){
        string a = to_string(num1);
        string b = to_string(num2);
        return a + b > b + a;
    }
public:
    string largestNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Note:
        // The list given to us consists of Non negative integers.
        // So, non negative integers consists of values from 0 to 
        // all positive integers.
        // The largest number that can be formed by merging the given numbers to us.
        // Example - 1
        // 10 2
        // 102 210

        // 3 30 34 5 9
        // 9 5 34 30 3

        // Sorting
        // Can I do direct sort operation i.e., ascending or descending sort?

        // We need a custom comparator
        // Comparator : It takes in the vector and sort that based on the requirement specified by us.
        sort(nums.begin(), nums.end(), comparator);
        string ans = "";
        for(auto &num : nums) ans += to_string(num);
        return ans[0] != '0' ? ans : "0";
    }
};
