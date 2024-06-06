Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

 

Constraints:

1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length




  class Solution {
public:
    using int2=pair<int, int>;
    static bool isNStraightHand(vector<int>& hand, int groupSize) {
        const int n=hand.size();
        if (n%groupSize!=0) return 0;
        unordered_map<int, int> mp;
        for(int x: hand) mp[x]++;
        priority_queue<int2> pq(mp.begin(), mp.end());// Max heap
        while(!pq.empty()){
            auto [x, f]=pq.top(); pq.pop();
            vector<int2> group;
            group.reserve(groupSize-1);
            for(int k=1; k<groupSize; k++){
                auto [y, f2]=pq.top(); pq.pop();
                f2-=f;
                if(y!=x-k || f2<0) return 0;
                if( f2>0) group.emplace_back(y, f2);
            }
            for(auto& pair: group) pq.push(pair);
        }
        return 1;
    }
};
