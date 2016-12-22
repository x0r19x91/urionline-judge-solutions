#include <iostream>
#include <algorithm>
#include <vector>
// Binary Knapsack
typedef long long ll;
ll min_wt;
std::vector<ll> prices, weights;
std::vector<std::vector<ll> > dp;

void precompute(ll W, int n)
{
    int i, j;
    for (i = 0; i <= W; ++i) {
        dp[0][i] = 0;
    }
    for (i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }
    for (i = 0; i <= n; ++i) {
        for (j = 1; j <= W; ++j) {
            dp[i][j] = dp[i-1][j];
            if (weights[i] <= j) {
                dp[i][j] = std::max(dp[i][j], prices[i]+dp[i-1][j-weights[i]]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, W, x, y;
    while (std::cin >> n, n) {
        std::vector<ll>().swap(prices);
        std::vector<ll>().swap(weights);
        dp.clear();
        min_wt = 2147483647;
        for (int i = 0; i < n; ++i) {
            std::cin >> x >> y;
            prices.push_back(x);
            weights.push_back(y);
            min_wt = std::min(min_wt, (ll)y);
        }
        std::cin >> W;
        for (int i = 0; i <= n+1; ++i) {
            dp.push_back(std::vector<ll>(W+1, 0));
        }
        precompute(W, n);
        std::cout << dp[n][W] << '\n';
    }
    return 0;
}
