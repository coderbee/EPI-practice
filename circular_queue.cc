#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>

using std::length_error;
using std::rotate;
using std::vector;

class Queue {
  public:
    Queue(size_t capacity) {}
  
    explicit Queue(int capacity) : entries_(capacity) {}
  
    void Enqueue(int x) {
      
  
