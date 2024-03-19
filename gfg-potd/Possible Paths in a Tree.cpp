Given a weighted tree with n nodes and (n-1) edges. You are given q queries. Each query contains a number x. For each query, find the number of paths in which the maximum edge weight is less than or equal to x.

Note: Path from A to B and B to A are considered to be the same.

Example 1:

Input: 
n = 3
edges {start, end, weight} = {{1, 2, 1}, {2, 3, 4}}
q = 1
queries[] = {3}
Output: 
1
Explanation:
Query 1: Path from 1 to 2
Example 2:

Input: 
n = 7
edges {start, end, weight} = {{1, 2, 3}, {2, 3, 1}, {2, 4, 9}, {3, 6, 7}, {3, 5, 8}, {5, 7, 4}}
q = 3
queries[] = {1, 3, 5}
Output: 
1 3 4
Explanation: 
Query 1: Path from 2 to 3
Query 2: Path from 1 to 2, 1 to 3, and 2 to 3
Query 3: Path from 1 to 2, 1 to 3, 2 to 3, and 5 to 7
Your Task:  
You don't need to read input or print anything. Complete the function maximumWeight()which takes integers n, list of edges where each edge is given by {start,end,weight}, an integer q and a list of q queries as input parameters and returns a list of integers denoting the number of possible paths for each query. 

Expected Time Complexity: O(nlogn + qlogn)
Expected Auxiliary Space: O(n)

Constraints:
2 ≤ n ≤ 104
1 ≤ q ≤ 104
1 ≤ edges[i][0], edges[i][1] ≤ n
edges[i][0] != edges[i][1]
0 ≤ edges[i][2] ≤ 105
0 ≤ queries[i] ≤ 105




class Solution{
int ans;
private:
int root(int i, vector<int> &parent)
{
    while(parent[i]!=i)
    {
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}
    int Union(int a, int b, vector<int> &parent, vector<int> &sz)
    {
        int ra = root(a, parent);
        int rb = root(b, parent);
        if(ra == rb)
            return sz[ra]*sz[ra];
        if(sz[ra] < sz[rb])
    {
        swap(ra,rb);
        swap(a,b);
    }
    ans += sz[ra]*sz[rb];
    parent[rb] = ra;
    sz[ra] += sz[rb];
    return ans;
    }
public:
vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
{
    ans = 0;
vector<int> parent(n+1, 0), sz(n+1, 0);
for(int i = 0;i <= n; i++)
{
            parent[i] = i;
            sz[i] = 1;
        }
        vector<pair<int, pair<int, int>>> wt;
        for(int i = 0; i < n-1; i++)
            wt.push_back({edges[i][2] , {edges[i][0], edges[i][1]}}); sort(wt.begin() , wt.end());
        map<int, int> mp;
        for(int i = 0;i < n-1; i++){
            int a = wt[i].first;
            int b = wt[i].second.first;
            int c = wt[i].second.second;
            mp[a] = Union(b, c, parent, sz);
            }
        vector<int> res;
        for(int i = 0; i < q; i++)
        {
            auto val = mp.upper_bound(queries[i]);
            if(val == mp.begin())
                res.push_back(0);
            else
            {
                val--;
                res.push_back(val->second);
            }
        }
        return res;

}

};
