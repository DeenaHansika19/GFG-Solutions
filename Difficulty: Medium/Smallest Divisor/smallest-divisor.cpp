class Solution {
  private:
    int solveBinarySearchOnAnswer(vector<int>& arr, int mid){
        int sum = 0;
        for(int n : arr){
            sum += (n + mid - 1) / mid;
        }
        return sum;
    }
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(solveBinarySearchOnAnswer(arr, mid) <= k){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
