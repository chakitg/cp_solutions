There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.

Return a sorted list of the items such that:

The items that belong to the same group are next to each other in the sorted list.
There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).
Return any solution if there is more than one solution and return an empty list if there is no solution.

 

Example 1:



Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
Output: [6,3,4,1,5,2,0,7]
Example 2:

Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
Output: []
Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.
 

Constraints:

1 <= m <= n <= 3 * 104
group.length == beforeItems.length == n
-1 <= group[i] <= m - 1
0 <= beforeItems[i].length <= n - 1
0 <= beforeItems[i][j] <= n - 1
i != beforeItems[i][j]
beforeItems[i] does not contain duplicates elements.



class Solution {
public:
        // Topological sort function
        vector<int> topologicalSort(vector<vector<int>>& graph, vector<int>& degrees) {
            vector<int> sorted;
            queue<int> q;
            // we start top sort from nodes with 0 degrees
            for (int i = 0; i < degrees.size(); ++i) {
                if (degrees[i] == 0) {
                    q.push(i);
                }
            }

            while (!q.empty()) {
                // remove u from graph
                int u = q.front();
                q.pop();
                sorted.push_back(u);
                // remove the edges from u -> v
                for (int v : graph[u]) {
                    // degree of v decreases
                    degrees[v]--;
                    // if is now 0 add it to queue
                    if (degrees[v] == 0) {
                        q.push(v);
                    }
                }
            }
            // if the whole graph could be sorted (no cycles) return its sorted order
            // if not return an empty vector signifying the top sort could not be ran
            return sorted.size() == graph.size() ? sorted : vector<int>();
        };
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // Create a new group for items that don't belong to any group
        for (int u = 0; u < n; ++u) {
            if (group[u] == -1) {
                group[u] = m++;
            }
        }
        
        // Build directed graphs for items and groups
        // graph is for items
        // groupGraph is for groups
        vector<vector<int>> graph(n), groupGraph(m);

        // degrees keeps tack of items
        // group degrees keep track of a particular groups degrees
        vector<int> degrees(n, 0), groupDegree(m, 0);

        // creating the graphs
        for (int u = 0; u < n; ++u) {
            for (int v : beforeItems[u]) {
                graph[v].push_back(u); // v -> u
                degrees[u]++;
                // if they are not in the same group, add 1 degree to group[u]
                // also add the edge from group[v] -> group[u]
                if (group[u] != group[v]) {
                    groupGraph[group[v]].push_back(group[u]);
                    groupDegree[group[u]]++;
                }
            }
        }
        
        // Get topologically sorted items and groups
        vector<int> itemsSorted = topologicalSort(graph, degrees);
        vector<int> groupsSorted = topologicalSort(groupGraph, groupDegree);
        
        // if there is either a cycle in the items or in the groups graphs
        if (itemsSorted.empty() || groupsSorted.empty()) {
            return {};
        }
        
        // Order items based on group order
        vector<int> order;
        unordered_map<int, vector<int>> groupItems;

        // items are placed together based on their group
        for (int v : itemsSorted) {
            groupItems[group[v]].push_back(v);
        }

        // in sorted order of the groups, place each item of the group into the final output
        for (int group : groupsSorted) {
            for (int item : groupItems[group]) {
                order.push_back(item);
            }
        }

        return order;
    }
};
