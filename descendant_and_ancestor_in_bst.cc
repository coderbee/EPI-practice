#include <memory>
#include "bst_node.h"

using std::unique_ptr;

bool SearchTarget(const unique_ptr<BstNode<int>>&,
                  const unique_ptr<BstNode<int>>&);

bool PairIncludesncestorAndDescendantOfM(
  const unique_ptr<BstNode<int>>& possible_anc_or_desc_0,
  const unique_ptr<BstNode<int>>& possible_anc_or_desc_1,
  const unique_ptr<BstNode<int>>& middle) {
  auto* search_0 = possible_anc_or_desc_0.get();
  auto* search_1 = possible_anc_or_desc_1.get();
  
  //Perform interleaved searching from possible_anc_or_desc_0 and
  //possible_anc_or_desc for middle.
  while(search_0 != possible_anc_or_desc_1.get() && search_0 != middle.get() &&
        search_1 != possible_anc_or_desc_0.get() && search_1 != middle.get() &&
        (search_0 || search_1 )) {
