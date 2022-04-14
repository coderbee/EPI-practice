#include <unordered_map>

using std::unordered_map;

unordered_map<int, int> cache;

int Fibonacci(int n) {
  if(n <=1) {
    return n;
  } else if (!cache.count(n)) {
    cache[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
  }
  return cache[n];
}

