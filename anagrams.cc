#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

vector<vector<string>> FindingAnagrams(const vector<string>& dictionary) {
  unordered_map<string, vector<string>> sorted_string_to_anagrams;
  for (const string& s : dictionary) { 
    //sorts the string, uses it as a key, and then appends
    //the original string as another value into hash table.
    srting sorted_str(s);
    sort(begin(sorted_str), end(sorted_str));
    sorted_string_to_anagrams[sorted_str].emplace_back(s);
  }
  
  vector<vector<string>> anagram_groups;
  for(const auto& [key, group] : sorted_string_to_anagrams) {
    if(size(group) >= 2) { //Found anagrams.
      anagram_groups.emplace_bacj(group);
    }
  }
  return anagram_groups;
}

    
