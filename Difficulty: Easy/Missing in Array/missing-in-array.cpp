//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        // code here
        long long sum = 0;
       long long n = arr.size() + 1; // Since one number is missing, the original size should be n

       // Sum all elements in the array
       for (auto num : arr) {
         sum += num;
       }

       // Calculate the expected sum of first n natural numbers using the formula: n * (n + 1) / 2
       long long total = (n * (n + 1)) / 2;

       // The missing number is the difference between the expected total and the actual sum
       return total - sum;
       
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNumber(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends