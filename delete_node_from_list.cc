//Assumes node_to_delete is not tail.
void DeletionFromList (const shared_ptr<ListNode<int>>& node_to_delete) {
  node_to_delete->data = node_to_delete->next->data;
  node_to_delete->next = node_to_delete->next->data;
}

shared_ptr<ListNode<int>> DeletionFromListWrapper(
  TimedExecutor& executor, const shared_ptr<ListNode<int>>& head,
  int node_to_delete_idx) {
  shared_ptr<ListNode<int>> selected_node = head;
  while (node_to_deelete_idx-- > 0 ) {
    if(!selected_node || !selected_node->next)
      throw std::runtime_error("Node index is out of range");
    selected_node = selected_node->next;
  }
  
  executoe.Run([&] { DeletionFromList(selected_node); });
  return head;
}

