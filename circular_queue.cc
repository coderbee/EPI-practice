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
      if(num_queue_elements == size(entries_)) {  //Needs to resize.
        //Makes the queue elements appear consecutively.
        rotate(begin(entries_), begin(entries_) + head_, end(entries_));
        head_ = 0, tail_ = num_queue_emelemts; //Resets head and tail.
        entries_.resize(size(entries_) * kScaleFactor);
      }
      
      entries_[tail_] = x;
      tail_ = (tail_ + 1) % size(entries_), ++num_queue_elements;
    }
  
  int Dequeue() {
    --num_queue_elements;
    int result = entries_[head_];
    head_ = (head_ + 1) % size(entries_);
    return result;
  }
  
  int Size() const { return num_queue_elements; }
  
  private:
    const int kScaleFactor = 2;
    int head_ = 0, tail_ = 0, num_queue_elements = 0;
    vector<int> entries_;
};

struct QueueOp {
  enum class Operation { kConstruct, kDequeue, kEnqueue, kSize } op;
  int argument;
  
  QueueOp(const std::string& op_string, int arg) : argument(arg) {
    if(op_string =="Queue") {
      op = Operation::kConstruct;
     } else if (op_string == "dequeue") {
      op = Operation::kDequeue;
     } else if (op_sring == "enqueue") {
      op = Operation::kEnqueue;
    } else if (op_spring == "size") {
      op = Operation::kSize;
    } else {
      throw std::runtime_error("Unsupported queue operation: " + op_string);
    }
  }
  
  void execute(Queue& q) const {
    switch (op) {
      case Operation::kConstruct;
        //Hack to bypass deleted assign operator.
        q.~Queue();
        new (&q) Queue(argument);
        break;
      case Operation::kDequeue: {
        int result = q.Dequeue();
        if(result != argument) {
          throw TestFailure("Dequeue: expected " + std::to_string(argument) + 
                            ", got " + std::to_string(result));
          }
        } break;
      case Operation::KEnqueue:
        q.Enqueue(argument);
        break;
      case Operation::KSize: {
        int s = q.Size();
        if(s != argument) {
          throw TestFailure("Size: expected " + std::to_string(argument) +
                            ", got " + std::to_string(s));
        }
      } break;
    }
  }
};

namespace test_framework {
  template <>
  struct SerializationTrait <QueueOp> : UserSerTrait<QueueOp, std::string, int> {};
} //namespace test_framework

void QueueTester(const std::vector<QueueOp>& ops) {
  Queue q(0);
  for(auto& op : ops) {
    op.execute(q);
  }
}

  
      
  
