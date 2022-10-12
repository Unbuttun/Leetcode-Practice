/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 *
 * https://leetcode.com/problems/find-if-path-exists-in-graph/description/
 *
 * algorithms
 * Easy (50.53%)
 * Likes:    1559
 * Dislikes: 86
 * Total Accepted:    140.7K
 * Total Submissions: 278.6K
 * Testcase Example:  '3\n[[0,1],[1,2],[2,0]]\n0\n2'
 *
 * There is a bi-directional graph with n vertices, where each vertex is
 * labeled from 0 to n - 1 (inclusive). The edges in the graph are represented
 * as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a
 * bi-directional edge between vertex ui and vertex vi. Every vertex pair is
 * connected by at most one edge, and no vertex has an edge to itself.
 *
 * You want to determine if there is a valid path that exists from vertex
 * source to vertex destination.
 *
 * Given edges and the integers n, source, and destination, return true if
 * there is a valid path from source to destination, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
 * Output: true
 * Explanation: There are two paths from vertex 0 to vertex 2:
 * - 0 → 1 → 2
 * - 0 → 2
 *
 *
 * Example 2:
 *
 *
 * Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0,
 * destination = 5
 * Output: false
 * Explanation: There is no path from vertex 0 to vertex 5.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2 * 10^5
 * 0 <= edges.length <= 2 * 10^5
 * edges[i].length == 2
 * 0 <= ui, vi <= n - 1
 * ui != vi
 * 0 <= source, destination <= n - 1
 * There are no duplicate edges.
 * There are no self edges.
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  bool dfs(vector<vector<int>> &graph, vector<int> &visited, int current, int end)
  {
    if (current == end)
      return true;
    if (visited[current])
      return false;

    visited[current] = 1;

    for (int i = 0; i < graph[current].size(); i++)
    {
      if (dfs(graph, visited, graph[current][i], end))
        return true;
    }

    return false;
  }

  bool validPath(int n, vector<vector<int>> &edges, int start, int end)
  {
    vector<vector<int>> graph(n);
    for (int i = 0; i < edges.size(); i++)
    {
      graph[edges[i][0]].push_back(edges[i][1]);
      graph[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> visited(n, 0);
    return dfs(graph, visited, start, end);
  }
};
// @lc code=end
