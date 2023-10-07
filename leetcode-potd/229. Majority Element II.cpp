Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109



class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Create a frequency map to store the count of each element
        unordered_map<int, int> elementCountMap;
        
        // Iterate through the input array to count element occurrences
        for(int i = 0; i < nums.size(); i++) {
            elementCountMap[nums[i]]++;
        }
        
        vector<int> majorityElements;
        int threshold = nums.size() / 3;
        
        // Iterate through the frequency map to identify majority elements
        for(auto elementCountPair : elementCountMap) {
            int element = elementCountPair.first;
            int count = elementCountPair.second;
            
            // Check if the element count is greater than the threshold
            if(count > threshold) {
                majorityElements.push_back(element);
            }
        }
        
        return majorityElements; 
    }
};
