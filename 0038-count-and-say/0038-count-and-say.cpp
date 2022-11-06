class Solution {
public:
    string countAndSay(int n) {
         string s = "1&"; // we just add "&" sign in the end so that we can compare every character with a character before it, if it's equal or not.
        for(int i = 2; i <= n; i++)
        {
            int size = s.size();
            int cnt = 1;
            string s2 = ""; // we create an empty string s2, where we store ans for n = i, and we append "&" sign in the end
            for(int j = 1; j < size; j++)
            {
                if(s[j] == s[j-1]) cnt++; // if current digit is equal to prev, we simply increase counter by 1;
                else // if we found a dight not equal to previous;
                {
                    s2 += to_string(cnt); //we first append counter of prev digits which were same;
                    s2 += s[j-1]; // the we append the prev digit;
                    cnt = 1; // we re-initialize counter to 1;
                }
            }
            s = s2 + '&';
        }
        return s.substr(0, s.size() - 1); //finally return our string leaving the last "&" sign;
    }
};