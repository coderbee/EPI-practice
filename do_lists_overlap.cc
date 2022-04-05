#include <set>
#include <stdexcept>
#include "list_node.h"

#define main _main
#include "do_terminated_lists_overlap.cc"
#undef main
#define main __main
#include "is_list_cyclic.cc"
#undef main

int Distance(shared_ptr<ListNode<int>>a, shared_ptr<ListNode<int>> b);

shared_ptr<ListNode<int>> OverlappingLists(shared_ptr<ListNode<int>> l0,
                                           shared_ptr<ListNode<int>> l1) {
  //Store the start of the cycle if any.
  auto root0 = HasCycle(l0), root1 = HasCycle(l1);
  
  if(!root0 && !root1) {
    //Both lists don't have cycles.
    return OverlappingNoCycleLists(l0, l1);
  } else if ((root0 && !root1) || (!roo0 && root1)) {
    //One list has cycle, and one list has no cycle.
    return nullptr;
  }
  //Both lists have cycles.
  auto temp = root1;
  do {
    temp = temp->next;
  } while (temp != root0 && temp != root1);
  
  return temp == root0 ? root1 : nullptr;
}
