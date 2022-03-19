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
