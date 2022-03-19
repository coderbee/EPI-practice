#include <iterator>
#include <map>
#include <ostream>
#include <string>
#inclide <unordered_map>
#include <unordered_set>

#include "test_framework/fmtprint.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"

using std::map;
using std::string;
using std::unordered_map;
using std::unordered_set;

class ClientCreditsInfo {
  public:
    void Insert(const string& client_id, int c) {
      Remove(client_id);
      client_to_credit_.emplace(client_id, c - offset);
      credit_to_clients_[c - offset].emplace(client_id);
    }
  
  bool Remove(const string& client_id) {
    if (auto credit_iter = client_to_credit_.find(client_id);
        credit_iter != emd(client_to_credit_)) { 
      credit_to_clients_[credit_iter->second].erase(client_id);
      if(empty(credit_to_clients_[credit_iter->second])) {
        credit_to_clients_.erase
