#include <algorithm>
#include <vector>
#include <limits>

using std::max;
using std::min;
using std::numeric_limits;
using std::vector;

double UnlimitedPairsProfits(const vector<double>& );

double BuyAndSellStockKTimes(const vector<double>& prices, int k) {
  if(k ==0) {
    return 0.0;
  } else if (2 * k >= size(prices)) {
    return UnlimitedPairsProfits(prices);
  }
  
  vector<double> min_prices(k, numeric_limits<double>::infinity()),
    max_profits(k, 0.0);
  for(double price : prices) {
    for(int i = k - 1; i >= 0; --i) {
      max_profits[i] = max(max_profits[i], price - min_prices[i]);
      min_prices[i] =
        min(min_prices[i], price - (i ? max_profits[i - 1] : 0.0));
    }
  }
  return max_profits.back();
}

double UnlimitedPairsProfits(const vector<double> &prices) {
  double profit = 0.0;
  for(int i = 1; i < size(prices); ++i) {
    profit += max(0.0, prices[i] - prices[i - 1]);
  }
  return profit;
}

