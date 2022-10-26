class Solution {
public:
    void reverse(string &s,int start,int end){
        while(start<end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        int len=s.length();
        int start=0;
        int end=0;
        start=0;
        bool leadingSpaces=false;
        bool trailingSpaces=false;
        while(s[start]==' '){
            leadingSpaces=true;
            start++;
        }
        if(leadingSpaces){
            s.erase(0,start);
        }
        len=s.length();
        end=len-1;
        while(s[end]==' '){
            trailingSpaces=true;
            end--;
        }
        len=s.length();
        if(trailingSpaces){
            s.erase(end+1,len-1);
        }
        len=s.length();
        for(int i=0;i<len-1;i++){
            if(s[i]==' '&&s[i+1]==' '){
                s.erase(s.begin()+i,s.begin()+i+1);
                i--;
                len=s.length();
            }
        }
        len=s.length();
        start=0;
        end=0;
        reverse(s,0,len-1);
        for(int i=0;i<len;i++){
            if(s[i]==' '){
                reverse(s,start,i-1);
                start=i+1;
            }
        }
        reverse(s,start,len-1);
        return s;
    }
};