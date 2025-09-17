class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<int> countStack;
        stack<string> stringStack;
        string current = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // handle multi-digit numbers
            }
            else if (c == '[') {
                countStack.push(num);
                stringStack.push(current);
                num = 0;
                current = "";
            }
            else if (c == ']') {
                int repeatTimes = countStack.top();
                countStack.pop();

                string temp = stringStack.top();
                stringStack.pop();

                for (int i = 0; i < repeatTimes; i++) {
                    temp += current;
                }
                current = temp;
            }
            else {
                current += c; // add character
            }
        }
        return current;
    }
};