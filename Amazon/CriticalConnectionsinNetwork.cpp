// https://leetcode.com/problems/critical-connections-in-a-network/

/* Articulation Point/Vertex An articulation point in a connected graph is a
vertex that would disconnect the graph if it (and its incident edges) were
removed. Alternatively, articulation vertex is a vertex whose removal increases
the number of connected components.  
Bridge: A bridge (or cut-edge) is an edge
whose deletion increases the number of connected components.  
Equivalently, an edge is a bridge if and only if it is not contained in any cycle. 
Essentially, the solution to this problem involves finding the list of bridges in 
the given graph. 
“Finding bridge(s) in a given graph is a fundamental applications of DFS”
An edge from v to u is a bridge if u can be reached from v. We can solve this
by doing dfs and finding following information: Preorder time of vertex v—
simple monotonously increasing counter in DFS Lowest preorder time of a vertex v
— lowest preorder time of all vertices that are part of the DFS subgraph with v
as root. An edge from v to u is a bridge if lowest preorder time of u is same as
preorder time of u.

Time complexity of the above solution Since the solution involves running DFS
the time complexity is = O(E+V) where V is the number of vertices and E is the
number of edges.
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<vector<int>>& graph, vector<vector<int>>& result) {
    static int time = 0;
    visited[node] = true;
    disc[node] = low[node] = time++;
    for (int neighour: graph[node]) {
        if (!visited[neighour]) {
            parent[neighour] = node;
            dfs(neighour, visited, disc, low, parent, graph, result);
            low[node] = min(low[node], low[neighour]);
            if (low[neighour] > disc[node]) {
                result.push_back({node, neighour});
            }
        } 
        else if (neighour != parent[node]) {
            low[node] = min(low[node], disc[neighour]);
        }
    }
}

// We record the timestamp that we visit each node. For each node, we check
// every neighbor except its parent and return a smallest timestamp in all its
// neighbors. If this timestamp is strictly less than the node's timestamp, we
// know that this node is somehow in a cycle. Otherwise, this edge from the
// parent to this node is a critical connection

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<bool> visited(n, false);
    vector<int> discovery(n, 0), low(n, 0), parent(n, -1);
    vector<vector<int>> graph(n, vector<int>());
    vector<vector<int>> result;

    //construct graph
    for (auto& edge: connections) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        dfs(i, visited, discovery, low, parent, graph, result);
    }

    return result;
}

int main() {
    int edge1 = 7;
    int edge2 = 4;
    vector<vector<int>> connections1 = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 5}, {5, 6}, {3, 4}};
    vector<vector<int>> connections2 = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    vector<vector<int>> result = criticalConnections(edge1, connections1);
    cout << "[";
    for (int i = 0; i < result.size(); i++){
        cout << "[";
        for (int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << ", ";
        }
        cout << "],";
    }
    cout << "]"<<endl;
    return 0;
}
