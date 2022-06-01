#include <algorithm>
#include <queue>
#include <stdexcept>
#include <vector>

using std::all_of;
using std::queue;
using std::vector;

struct GraphVertex;
bool Bfs(GraphVertex* s);

struct GraphVertex {
  int d = -1;
  vector<GraphVertex*> edges;
};

bool IsAnyPlacementFeasible(vector<GraphVertex>* graph) {
return all_of(begin(*graph), end(*graph),
              [](GraphVertex& v) { return v.d != -1 || Bfs(&v); });
}

bool Bfs(GraphVertex* s) {
  
