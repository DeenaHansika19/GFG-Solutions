class Solution {
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.first < b.first) {
            return true;
        }
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return false;
    }
  public:
    int nonLisMaxSum(vector<int>& arr) {
        vector<vector<pair<int, int>>> dp(arr.size(),
                                          vector<pair<int, int>>(arr.size()));
        for (int i = 0; i < arr.size() - 1; i++) {
            dp[arr.size() - 1][i] = {
                arr[arr.size() - 1] > arr[i],
                arr[arr.size() - 1] > arr[i] ? arr[arr.size() - 1] : 0};
        }
        dp[dp.size() - 1][dp.size() - 1] = {1, arr[arr.size() - 1]};
        for (int i = arr.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int mxi = j;
                if (arr[j] < arr[i])
                    mxi = i;
                auto nxt = dp[i + 1][mxi];
                dp[i][j] = {(mxi == i) + nxt.first,
                            (mxi == i ? arr[i] : 0) + nxt.second};
                dp[i][j] = max(dp[i][j], dp[i + 1][j], cmp);
            }
        }
        pair<int, int> mx = {0, INT_MAX};
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            mx = max(dp[i][i], mx, cmp);
        }
        return sum - mx.second;
    }
};