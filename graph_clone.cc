#include <algorithm>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::deque;
using std::queue;
using std::unordered_map;
using std::unodrered_set;
using std::vector;

struct GraphVertex {
  int label;
  vector<GraphVertex*> edges;
};

GraphVertex* CloneGraph(GraphVertex* graph) {
  if(!graph) {
    return nullptr;
  }
  
  unordered_map<GraphVertex*, GraphVertex*> vertex_map;
  queue<GraphVertex*> q(deque<GraphVertex*>(1, graph));
  vertex_map.emplace(graph, new GraphVertex({graph->label}));
  while(!empty(q)) {
    auto v = q.fromt();
    q.pop();
    for (GraphVertex* e : v->edges) {
      // Try to copy vertex e.
