class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
         int n = s.size();
        vector<int>ans;
        vector<int>freq(26, -1);
        vector<int>prefixsum(26, 0);
        int sum = 0;
        for(int i = 0; i<n; i++){
            char c = s[i];
            sum += int(c);
            if( freq[int(c) - 97] == -1){
               prefixsum[int(c) - 97] = sum;
               freq[int(c) - 97] = 1;
            }
            else{
             freq[int(c) - 97] = sum - int(c) - prefixsum[int(c) - 97];
            }
        }
        
        for(int i = 0; i<26; i++){
            if(freq[i] != 0 && freq[i] != 1 && freq[i] != -1){
                ans.push_back(freq[i]);
            }
        }
        return ans;
    }
};