class Solution {
public:
    bool isV(char a){
        return (
            a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U'
        );
    }
    string toGoatLatin(string S) {
        vector<string> words;
        string curr="";
        for(int i=0;S[i];i++){
            if(S[i]!=' ')
                curr+=S[i];
            else{
                words.push_back(curr);
                curr="";
            }
        }
        if(curr!="")
            words.push_back(curr);
        // for(auto w:words)
        //     cout<<w<<" ";
        string ans="";
        int i=1;
        for(string w:words){
            if(isV(w[0]))
                ans+=w+"ma";
            else{
                ans+=w.substr(1)+w[0]+"ma";
            }
            for(int c=0;c<i;c++)
                ans+="a";
            i++;
            // ans+=w;
            ans+=" ";
        }
        return ans.substr(0,ans.length()-1);
    }
};