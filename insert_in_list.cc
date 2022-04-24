#include <memory>

#include "list_node.h"

using std::make_shared;
using std::shared_ptr;

//Insert a new node after node.
void InsertAfter(const shared_ptr<ListNode<int>>& node,
                 const shared_ptr<ListNode<int>>& new_node) {
  new_node->next = node->next;
  node->next = new_node;
}

shared_ptr<ListNode<int>> InsertListWrapper(TimedExecutor& executor,
                                            const shared_ptr<ListNode<int>>& l,
                                            int node_idx, int new_node_data) {
  auto node = l;
  while(node_idx > 1) {
    node = node->next;
    --node_idx;
  }
  auto new_node = make_shared<ListNode<int>>(new_node_data, nullptr);
  
  executor.Run([&] {InsertAfter(node, new_node); });
  
  return l;
}
