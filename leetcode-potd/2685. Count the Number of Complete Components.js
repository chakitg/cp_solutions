You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.

 

Example 1:



Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
Output: 3
Explanation: From the picture above, one can see that all of the components of this graph are complete.
Example 2:



Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
Output: 1
Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
 

Constraints:

1 <= n <= 50
0 <= edges.length <= n * (n - 1) / 2
edges[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
There are no repeated edges.


  const countCompleteComponents = (n, edges) => {
    let result = n - new Set(edges.flat()).size, connectedGraph;
    while (edges.length > 0) {
        [connectedGraph, edges] = extractConnectedSubgraph(edges);
        result += isComplete(connectedGraph);
    }
    return result;
};

const extractConnectedSubgraph = (edges) => {
    const subgraph = [edges.shift()];
    while (!totallyDistinct(subgraph, edges)) {
        const vertices = subgraph.flat();
        for (let i in edges) {
            if (vertices.includes(edges[i][0]) || vertices.includes(edges[i][1])) {
                subgraph.push(edges.splice(i, 1)[0]);
            }
        }
    }
    return [subgraph, edges]
};

const isComplete = (graph, count = new Set(graph.flat()).size) => 
   (count - 1) * count === 2 * graph.length;

const totallyDistinct = (g1, g2, s2 = new Set(g2.flat())) =>
    !g1.flat().some(r=> s2.has(r));
