#include <map>
#include <memory>
#include <vector>

using std::make_shared;
using std::shared_ptr;

shared_ptr<PostingListNode> CopyPostingsList(
  const shared_ptr<PostingListNode>& l) {
  if( l ==nullptr) {
    return nullptr;
  }
  
  //Stage 1: Makes a copy of the original list without assigning the jump
  //          field, and creates the mapping for each node in the original
  //          list to the copied list.
  auto iter = l;
  while (iter) {
    auto new_node = 
      
