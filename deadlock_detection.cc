#include <stdexcept>
#include <vector>

using std::vector;

struct GraphVertex;
bool HasCycle(GraphVertex*);

struct GraphVertex {
  enum class Color { kWhite, kGray, kBlack } color = Color::kWhite;
  
  vector<GraphVertex*> edges;
};

bool IsDeadLocked(vector<GraphVertex>* graph) {
  return any_of(begin(*graph), end(*graph), [](GraphVertex& vertex) {
    return vertex.color == GraphVertex::Color::kWhite && HasCycle(&vertex);
  });
}

bool HasCycle(GraphVertex* cur) {
  //Visiting a gray vertex means a cycle.
  if(cur->color ==GraphVertex::Color::kGray) {
    return true;
  }
  
  cur->color = 
    GraphVertex::Color::kGray; //Marks current vertex as a gray one.
  //Traverse the neighbor vertices.
  for(GraphVertex*& : cur->edges) {
    if(next->color != GraphVertex::Color::kBlack && HasCycle(next)) {
      return true;
    }
  }
  cur->color = GraphVertex::Color::kBlack; //Marks current vertex as black.
  return false;
}

struct Edge {
  int from;
  int to;
};
