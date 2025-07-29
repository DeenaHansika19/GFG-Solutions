class Solution {
  public:
    int substrWithVowels(string &s1, string &s2) {
        // code here
        unordered_set<char> vowels(s1.begin(), s1.end());
        unordered_map<char, int> freq;
        int left = 0, count = 0, minLen = INT_MAX;

        for (int right = 0; right < s2.size(); ++right) {
            char ch = s2[right];
            if (vowels.count(ch)) {
                if (++freq[ch] == 1) count++;
            }

            while (count == vowels.size()) {
                minLen = min(minLen, right - left + 1);
                char leftChar = s2[left++];
                if (vowels.count(leftChar)) {
                    if (--freq[leftChar] == 0) count--;
                }
            }
        }

        return (minLen == INT_MAX) ? -1 : minLen;

    }
};