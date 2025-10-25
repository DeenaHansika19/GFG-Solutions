class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        int ans=0;
        priority_queue<double>pq;
        double s=0;
        for(int i=0;i<arr.size();i++)
        {
            s+=arr[i];
            pq.push(arr[i]);
        }
    
    double g=s;
    s=s/2.0;
    while(g>s){
        ans++;
        double t=pq.top();
        pq.pop();
        g-=t/2.0;
        pq.push(t/2.0);
    }
    return ans;
    }
};