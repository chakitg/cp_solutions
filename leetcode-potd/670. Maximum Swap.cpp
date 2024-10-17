You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

 

Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.
 

Constraints:

0 <= num <= 108




class Solution {
public:
    int maximumSwap(int num) {
        string st = to_string(num);
        int n = st.size();
        priority_queue<pair<char, int>> pq;
        for(int i = 0; i < n; i++)
        {
            pq.push({st[i], i});
        }
        for(int j = 0; j < n; j++)
        {
            while(! pq.empty() && pq.top().second < j)
                pq.pop();
                if(pq.top().first > st[j])
                {
                    swap(st[j], st[pq.top().second]);
                    break;
                }            
        }
        return stoi(st);
    }
};
