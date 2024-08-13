Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30




class Solution {
private:
    void helper(vector<vector<int>> &answer, vector<int> &candidates, vector<int> &tmpCandidates, int target, int idx){
        if(target == 0){
            answer.push_back(tmpCandidates);
        }
        for(int i = idx ; i < candidates.size() ; i++){
            if(i > idx and candidates[i] == candidates[i - 1]) continue;
            if(target >= candidates[i]){
                tmpCandidates.push_back(candidates[i]);
                helper(answer, candidates, tmpCandidates, target - candidates[i], i + 1);
                tmpCandidates.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Candidates : 10, 1, 2, 7, 6, 1, 5
        // Target     : 8
        // Candidates : 1 1 6
        // 1 2 5
        // 1 7 - 2 times 
        // 2 6
        // 1 
        // Given the candidates vector I will sort it
        // 10 1 2 7 6 1 5
        // Sorted Candidates vector : 1 1 2 5 6 7 10
        // When to consider selecting a particular candidate
        // If my target is >= the current candidate number then I could obv select that candidate.
        // 8 > 1 ---> I could consider 1
        // 1 1 2 5 6 7 10
        // 1 --> Done --> 7
        // 1 2 5 6 7 10
        // 2 5 6 7 10
        // Done --> 6
        // Backtracking --> Backtracking always will be having the recurrsion calls in it.
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> tmpCandidates;
        helper(answer, candidates, tmpCandidates, target, 0);
        return answer;
    }
};
