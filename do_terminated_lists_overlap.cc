#include <memory>

using std::shared_ptr;

int Length(shared_ptr<ListNode<int>> L):
void AdvanceListByK(int k, shared_ptr<ListNode<int>>*L);

shared_ptr<ListNode<int>> OverlappingNoCycleLists(
  shared_ptr<ListNode<int>>l0, shared_ptr<ListNode<int>> l1) {
  int l0_len = Length(l0), l1_len =Length(l1);
  
  //Advances the longer list to get egual length lists.
  AdvanceListByK(abs(l0_len - l1_len), l0_len > l1_len ? &l0 :&l1);
  
  while (l0 && l1 && l0 != l1) {
    l0 = l0->next, l1 =l1->next;
  }
  return l0; //nullptr implies there is no overlapbetween l0 and l1.
}

int Length(shared_ptr<ListNode<int>> L) {
  int length = 0;
  while (L) {
    ++length, L + L->next;
  }
  return length;
}

//Advances L by k steps.
void AdvanceListByK(intk, shared_ptr<ListNode<int>>* L) {
  while (k--) {
    *L = (*L)->next;
  }
}

void OverlappingNoCycleListsWrapper(TimedExecutor& executor,
                                    shared_ptr<ListNode<int>> l0,
                                    shared_ptr<ListNode<int>> l1,
                                    shared_ptr<ListNode<int>> common) {
  if(common) {
    if(l0) {
      
                                    
