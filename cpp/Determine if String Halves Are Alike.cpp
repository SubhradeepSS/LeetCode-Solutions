class Solution {
public:
    bool isV(char c){
        return (
            c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U'
        );
    }
    bool halvesAreAlike(string s) {
        int c=0,n=s.length();
        for(int i=0;i<n;i++){
            if(isV(s[i])){
                i<n/2?c++:c--;
            }
        }
        return !c;
    }
};