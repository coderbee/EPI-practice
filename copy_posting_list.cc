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
      make_shared<PostingListNode>(iter->order, iter->next, nullptr);
    iter->next = new_node;
    iter = new_node->next;
  }
  
  //Stage 2: Assigns the jump field in the copied list.
  iter = l;
  while(iter) {
    if(iter->jump) {
      iter->next->jump = iter->jump->next.get();
    }
    iter = iter->next->next;
  }
  
  //Stage 3: Reverts the original list, and assigns the next field of 
  //the copied list.
  iter =l;
  auto new_list_head = iter->next;
  while(iter->next) {
    auto temp = iter->next;
    iter->next = temp->next;
    iter = temp;
  }
  return new_list_head;
}

using PostingListPtr = std::shared_ptr<PostingListNode>;

struct SerializeNode {
  int order;
  int jump_index;
};

namespace test_framework {
template <>
struct SerializeTrait<SerializeNode, int, int> {};
  : UserSerTrait<Serializednode, int, int> {};
} //namespace test_framework
  
PostingListPtr CreatePostingList(
  const std::vector<SerializedNode>& serialized) {
  std::map<int, POstingListPtr> key_mapping;
  PostingListPtr head;
  for (auto it = rbegin(serialized); it !=rend(serialized);
       ++it, list_it = list_it->next) {
    if(it->jump != -1) {
      list_it->jump = key_mapping[it->jump_index].get();
      if(!list_it->jump) throw std::runtime_error("Jumpindex out of range");
    }
  }
  
  return head;
}

void AssertListsEqual(const PostingListPtr& orig, const PostingListPtr& copy) {
  std::map<POstingListNode*, PostingListNode*> node_mapping;
  auto o_it = orig;
  auto c_it = copy;
  while (o_it) {
    if(!c_it) {
      throw TestFailure("Copied list has fewer nodes than the original");
    }
    if(o_it->order != c_it->order) {
      throw TestFailure("Order value mismatch");
    }
    node_mapping[o_it.get()] = c_it.get();
    o_it = o_it->next;
    c_it = c_it->next;
  }
  
  if(c_it) {
    throw TestFailure("Copied list has more nodes than the original");
  }
  
 o_it = ori
