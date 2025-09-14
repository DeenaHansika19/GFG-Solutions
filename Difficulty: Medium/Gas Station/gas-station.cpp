class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
         int availableGas = 0, n = cost.size();
        int currentLocation = 0;
        
        for(int i = 0; i < (2 * n - 1); i++) {
            availableGas = gas[i % n];
            int j = 0;
            
            while(availableGas >= cost[i % n]) {
                if(j == n)
                    return i % n;
                availableGas = availableGas - cost[i % n] + gas[(i + 1) % n];
                i++;
                j++;
            }
        }
        
        return -1;
    }
};