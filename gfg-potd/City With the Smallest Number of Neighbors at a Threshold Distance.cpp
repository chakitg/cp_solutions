There are n cities labeled from 0 to n-1 with m edges connecting them. Given the array edges where edges[i] = [fromi , toi ,weighti]  represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold. You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance. If there are multiple such cities, our answer will be the city with the greatest label.

Note: The distance of a path connecting cities i and j is equal to the sum of the edge's weights along that path.

Example 1:

Input:
n = 4, m = 4
edges = [[0, 1, 3],
         [1, 2, 1], 
         [1, 3, 4],  
         [2, 3, 1]]
distanceThreshold = 4
Output:
3
Explaination:

The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
Example 2:

Input: 
n = 5, m = 6
edges = [[0, 1, 2],
         [0, 4, 8],
         [1, 2, 3], 
         [1, 4, 2], 
         [2, 3, 1],
         [3, 4, 1]]
distanceThreshold = 2.
Output:
0
Explaination:

The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findCity( ) which takes a number of nodes n, total number of edges m and vector of edges and distanceThreshold. and return the city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance. If there are multiple such cities, return the city with the greatest label.

Expected Time Complexity: O(n2 + length(edges)*nlog(n) )
Expected Auxiliary Space:  O(n3)

Constraints:
1  ≤  n ≤  100
1 <= m <= n*(n-1)/2
length(edges[i]) == 3
0 <= fromi < toi < n
1 <= weighti distanceThreshold <= 104
All pairs (fromi, toi) are distinct





class Solution {
public:
    int dijkstra(int curr, int& n, int& distThreshold, vector<vector<pair<int, int>>>& graph) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> vis(n, 0);
        pq.push({0, curr});
        
        int cnt = 0;
        while (!pq.empty()) {
            int dist = pq.top().first; 
            int node = pq.top().second;
            pq.pop();
            
            if (vis[node]) 
                continue;
                
            vis[node] = 1;
            if (dist > distThreshold) 
                continue;
            ++cnt;
            
            for (auto itr : graph[node]) {
                int nodeDist = itr.first;
                int nextNode = itr.second;
                if (!vis[nextNode]) 
                    pq.push({dist + nodeDist, nextNode});
            }
        }
        return cnt;
    }
    
    int findCity(int n, int m, vector<vector<int>>& edges, int distThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        
        for (auto &itr : edges) {
            graph[itr[0]].push_back({itr[2], itr[1]});
            graph[itr[1]].push_back({itr[2], itr[0]});
        }
        
        int out = -1, nax = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int cnt = dijkstra(i, n, distThreshold, graph);
            
            if (cnt <= nax) {
                nax = cnt;
                out = i;
            }
        }
        return out;
    }
};
