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
      if(vertex_map.emplace(e, new GraphVertes({e->label})).second) {
        q.emplace(e);
      }
      // Copy edge.
      vertex_map[v]->edges.emplace_back(vertes_map[e]);
    }
  }
  return vertex_map[graph];
}

vector<int> CopyLabels(const vector<GraphVertex*>& edges) {
  vector<int> labels;
  transform(begin(edges), end(edges), back_inserter(labels),
            [](const auto& e) { return e->label;});
  return labels;
}

