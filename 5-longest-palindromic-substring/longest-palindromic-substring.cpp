class Solution {
public:
    string longestPalindrome(string s) {

        string t = "#";

        for(char c : s)
        {
            t += c;
            t += '#';
        }

        int n = t.length();

        vector<int> p(n, 0);

        int center = 0;
        int right = 0;

        int maxLen = 0;
        int centerIndex = 0;

        for(int i = 0; i < n; i++)
        {
            int mirror = 2 * center - i;

            if(i < right)
            {
                p[i] = min(right - i, p[mirror]);
            }

            int left = i - (p[i] + 1);
            int r = i + (p[i] + 1);

            while(left >= 0 && r < n && t[left] == t[r])
            {
                p[i]++;
                left--;
                r++;
            }

            if(i + p[i] > right)
            {
                center = i;
                right = i + p[i];
            }

            if(p[i] > maxLen)
            {
                maxLen = p[i];
                centerIndex = i;
            }
        }

        int start = (centerIndex - maxLen) / 2;

        return s.substr(start, maxLen);
    }
};