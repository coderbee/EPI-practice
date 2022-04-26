
shared_ptr<ListNode<int>> AddTwoNumbers(shared_ptr<List_Node<int>> L1,
                                        shared_ptr<List_node<int>> L2) {
  shared_ptr<ListNode<int>> dummy_head(new ListNode<int>);
  auto place_iter  = dummy_head;
  int carry = 0;
  while (L1 || L2 || carry) {
    int val = carry + (L1 ? L1->data : 0) + (L2 ? L2->data : 0);
    L1 = L1 ? L1->next : nullptr;
    L2 = L2 ? L2->next : nullptr;
    place_iter->next = make_shared<ListNode<int>>(val % 10, nullptr);
    carry = val /10, place_iter = place_iter->next;
  }
  return dummy->head->next;
}

