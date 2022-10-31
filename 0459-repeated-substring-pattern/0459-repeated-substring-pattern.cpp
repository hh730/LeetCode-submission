class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string a= s;
        s=a+a;
        return s.find(a, 1) != a.length();
    }
};