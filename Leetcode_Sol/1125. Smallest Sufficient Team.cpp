In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.

Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.

For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].
Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.

It is guaranteed an answer exists.

 

Example 1:

Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]
Example 2:

Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]
 

Constraints:

1 <= req_skills.length <= 16
1 <= req_skills[i].length <= 16
req_skills[i] consists of lowercase English letters.
All the strings of req_skills are unique.
1 <= people.length <= 60
0 <= people[i].length <= 16
1 <= people[i][j].length <= 16
people[i][j] consists of lowercase English letters.
All the strings of people[i] are unique.
Every skill in people[i] is a skill in req_skills.
It is guaranteed a sufficient team exists.



class Solution {
public:
    std::vector<int> smallestSufficientTeam(std::vector<std::string>& req_skills, std::vector<std::vector<std::string>>& people) {
        int n = req_skills.size();
        int m = people.size();
        
        std::unordered_map<std::string, int> skillToIndex;
        for (int i = 0; i < n; i++) {
            skillToIndex[req_skills[i]] = i;
        }
        
        std::vector<int> arr(m, 0);
        for (int i = 0; i < m; i++) {
            std::vector<std::string>& personSkills = people[i];
            int val = 0;
            for (const std::string& skill : personSkills) {
                val |= 1 << skillToIndex[skill];
            }
            arr[i] = val;
        }
        
        std::vector<bool> banned(m, false);
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int val = arr[i] | arr[j];
                if (val == arr[i]) {
                    banned[j] = true;
                }
                else if (val == arr[j]) {
                    banned[i] = true;
                }
            }
        }
        
        std::vector<int> ans;
        helper(0, n, arr, std::vector<int>(), banned, ans);
        
        return ans;
    }
    
private:
    void helper(int cur, int n, const std::vector<int>& arr, std::vector<int> team, const std::vector<bool>& banned, std::vector<int>& ans) {
        if (cur == (1 << n) - 1) {
            if (ans.empty() || team.size() < ans.size()) {
                ans = team;
            }
            return;
        }
        
        if (!ans.empty() && team.size() >= ans.size()) {
            return;
        }
        
        int zero = 0;
        while (((cur >> zero) & 1) == 1) {
            zero++;
        }
        
        for (int i = 0; i < arr.size(); i++) {
            if (banned[i]) {
                continue;
            }
            
            if (((arr[i] >> zero) & 1) == 1) {
                team.push_back(i);
                helper(cur | arr[i], n, arr, team, banned, ans);
                team.pop_back();
            }
        }
    }
};
