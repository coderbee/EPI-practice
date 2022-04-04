#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using std::invalid_argument;
using std::string;
using std::stringstream;
using std::vector;

string ShortestEquivalentPath(const string& path) {
  if(empty(path)) {
    throw invalid_argument("Empty string is not a valid path.");
  }
  
  vector<string> path_names; //Use vector as a stack.
  //Special case: starts with "/", which is an absolute path.
  if(path.front() == '/') {
    path_names.emplace_back("/");
  }
  
  stringstream ss(path);
