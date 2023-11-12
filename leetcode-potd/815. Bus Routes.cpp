You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

 

Example 1:

Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
Example 2:

Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1
 

Constraints:

1 <= routes.length <= 500.
1 <= routes[i].length <= 105
All the values of routes[i] are unique.
sum(routes[i].length) <= 105
0 <= routes[i][j] < 106
0 <= source, target < 106





class Solution {
public:
    // time/space: O(V + E)/O(V + E);
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // base case
        if (source == target) return 0;

        // build the graph (bus as node, bus-transfer as edge)
        // the hash table for `stop2bus`, and the `bus2stop` is the `routes`
        unordered_map<int, unordered_set<int>> stop2bus;
        for (int bus = 0; bus < routes.size(); bus++) {
            for (auto& stop : routes[bus]) stop2bus[stop].insert(bus);
        }

        // start from the buses which pass the bus stop `source`
        queue<int> q;
        unordered_set<int> bus_taken;
        for (auto& bus : stop2bus[source]) {
            q.push(bus);
            bus_taken.insert(bus);
        }

        // BFS
        int step = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int bus = q.front();
                q.pop();
                for (auto& next_stop : routes[bus]) {
                    if (next_stop == target) return step;
                    for (auto& next_bus : stop2bus[next_stop]) {
                        if (bus_taken.count(next_bus) != 0) continue;
                        bus_taken.insert(next_bus);
                        q.push(next_bus);
                    }
                }
            }
            step++;
        }

        // unreachable
        return -1;
    }
};
