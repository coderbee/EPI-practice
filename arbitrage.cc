#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

using std::numeric_limits;
using std::vector;

bool BellmanFord(const vector<vector<double>>&  graph, int source);

bool IsArbitrageExist(vector<vector<double>> graph) {
  //Transforms each edge in graph.
  for_each(begin(graph), end(graph), [](vector<double>& edge_list) {
    for_each( begin(edge_list), end(edge_list),
             [](double& edge) {edge = -log10(edge);});
  });
  
  //Uses Bellman Ford to find negative weight cycle.
  return BellmanFord(graph, 0);
}

bool BellmanFord(const vector<vector<double>>& graph, int source) {
  vector<double> dis_to_source(size(graph), numeric_limits<double>::infinity());
  dis_to_source[source] = 0;
  
