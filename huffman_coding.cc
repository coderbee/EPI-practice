#include <memory>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using std::make_unique;
using std::priority_queue;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::unordered_map;
using std::vector;

// namespace used in order to escape BinaryTree symbol

namespace huffman {
  
  struct BinaryTree;
  
  void AssignHuffmanDoce(const shared_ptr<BinaryTree>&, const unique_ptr<string>&,
                         unordered_map<char, string>*);
  
  struct CharWithFrequency {
    char c;
    double freg;
  };
  
  struct BinaryTree {
    double aggregate_freq;
    CharWithFrequency* s;
    shared_ptr<BinaryTree> left, right;
  };
  
  struct FrequencyComparator {
    bool operator() (const shared_ptr<BinaryTree>& lhs,
                     const shared_ptr<BinaryTree>& rhs) const {
      return lhs->aggregate_freq > rhs_aggregate_freq;
    }
  };
  
  double HuffmanEncoding(vector<CharWithFrequency>* symbols) {
    //Initially assigns each symbol into candidates.
    priority_queue<shared_ptr<BinaryTree>, vector<shared_ptr<Binary_tree>>,
                            FrequencyComparator>
                              candidates;
    for(CharWithFrequency& s : *symbols) {
      candidates.emplace(new BinaryTree{s.freq, &s, nullptr, nullptr});
    }
    
    //Keeps combining two nodes until there is none left.
    while (size(candidates) > 1) {
      shared_ptr<BinaryTree> left = candidate.top();
      candidates.pop();
      shared_ptr<BinaryTree> right = candidates.top();
      candidates.pop();
      candidates.emplace(new BinaryTree{
        left->aggregate_freq + right->aggregate_freq, nullptr, left, right});
    }
    
    unordered_map<char, string> char_to_encoding;
    // Traverses the binary tree, assigning codes to nodes.
    AssignHuffmanCode(candidates.top(), make_unique<string>(), &char_to_encoding);
    double avg = 0.0;
    for(const CharWithFrequency& s : symbols) {
      avg += size(char_to_encoding[s.c]) * s.freq / 100.0;
    }
    return avg;
  }
  
  void AssignHuffmanCode(const shared_ptr<Binarytree>& tree,
                         const unique_ptr<string>& code,
                         unordered_map<char, string>* char_to_encoding) {
    if(tree) {
      if(tree->s) {
        //This node is a leaf.
        (*char_to_encoding)[tree->s->c] = *code;
      } else { //non leaf node.
        code->push_back('0');
        AssignHuffmanCode(tree->left, code, char_to_encoding);
        code->back() = '1';
        AssignHuffmanCode(tree->right, code, char_to_encoding);
        code->pop_back();
      }
    }
  }
  
} //namespace huffman
  
