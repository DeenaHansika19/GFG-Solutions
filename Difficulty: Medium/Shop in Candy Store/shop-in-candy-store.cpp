class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin(),prices.end());
        int n = prices.size();
        int mini =0, maxi = 0;
        
        int j = n-1;
        
    
        for (int i = 0 ; i < n && i <= j ; i++){
            mini += prices[i];
            j -= k;
        }
        
        j=0;
        
        
        for (int i = n-1 ; i >= 0 && i >= j ; i--){
            maxi += prices[i];
            j += k;
        }
        
        return {mini,maxi};
    }
};