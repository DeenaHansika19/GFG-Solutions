//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
          int n=arr.size();
        int a =arr[0];
        int d = arr[1] - arr[0];
        
        if(arr[1] > arr[0])
        d = min(arr[n-1]-arr[n-2],arr[1]-arr[0]);
        else
        d = max(arr[n-1]-arr[n-2],arr[1]-arr[0]);
        
        
        
        
        int low=0,high=n-1;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            int sum = a + (mid)*d;
            if(sum == arr[mid]){
                ans=sum;
                low=mid+1;
            }
            else
                high = mid - 1;
        }
        
        return ans+d;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends