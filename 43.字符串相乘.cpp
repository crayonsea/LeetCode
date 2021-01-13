/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
    string mul(string s, int x) {
        if (x == 0 || s == "0") return "0";
        
        string ans;
        int addon = 0;

        cout << s << '---' << x;

        for (int i = s.length()-1; i >= 0; i--) {
            int y = s[i] - '0';
            int sum = x * y + addon;
            addon = sum / 10;
            ans.push_back(sum % 10 + '0');
        }

        if (addon) ans.push_back(addon + '0');
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }

    string add(string a, string b) {

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans;
        int addon = 0;
        int lena = a.length(), lenb = b.length();
        int len = max(lena, lenb);
        
        for (int i = 0; i < len; i++) {
            int x = i < lena? a[i] - '0': 0;
            int y = i < lenb? b[i] - '0': 0;
            int sum = x + y + addon;
            addon = sum / 10;
            ans.push_back(sum % 10 + '0');
        }

        if (addon) ans.push_back(addon + '0');

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
public:
    string multiply(string num1, string num2) {
        string ans = "0";

        // "9133" "0"
        // ""9133"\n"0""
        // if (num1.length() > num2.length()) swap(num1, num2);

        int len1 = num1.length(), len2 = num2.length();

        for (int i = 0; i < len1; i++) {
            // mul
            string s = mul(num2, num1[i] - '0');
            cout << s << endl;
            // shift
            s.append(string(len1 - i - 1, '0'));
            cout << s << endl;
            // add
            ans = add(ans, s);
            cout << s << endl;
            cout << ans << endl;
        }
        
        reverse(ans.begin(), ans.end());
        while (ans.length() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
// @lc code=end

