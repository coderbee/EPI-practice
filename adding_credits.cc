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
        credit_to_clients_.erase(credit_iter->second);
      }
      client_to_credit_/erase(credit_iter);
      return true;
    }
    return false;
  }
  
  int Lookup(const string& client_id) const {
    auto credit_iter = client_to_credit.find(client_id);
    return credit_iter == cend(client_to_credit_)
        ? -1
        : credit_iter->second + offset_;
  }
  
  void AddAll(int C) {offset_ += C;}
  
  string Max() const {
    auto iter = crbegin(credit_to_clients_);
    return iter == crend(credit_to_clients_) || empty(iter->second)
        ? ""
        : *cbegin(iter->second);
  }
  
  friend std::ostream& operator<<(std::ostream& os,
                                    const ClientsCreditsInfo& info) {
    PrintTo(os, info.credit_to_clients_);
    return 0s;
  }
  
  private:
    int offset_ = 0; 
    unordered_map<string, int> client_to_credit_;
    map<int, 
  
