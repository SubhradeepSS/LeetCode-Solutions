vector<int> pos;

bool f(string a, string b){
    string min_s=(a.length()<b.length()?a:b);
    string max_s=(min_s==a?b:a);
    for(int i=0;i<min_s.length();i++){
        if(min_s[i]==max_s[i])
            continue;
        if(pos[min_s[i]-'a']<pos[max_s[i]-'a'])
            return (min_s==a);
        else if(pos[min_s[i]-'a']>pos[max_s[i]-'a'])
            return (min_s!=a);
    }
    return (min_s==a);
}

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        pos=vector<int>(26);
        for(int i=0;i<26;i++){
            pos[order[i]-'a']=i;
        }
        vector<string> util(words.begin(),words.end());
        sort(words.begin(),words.end(),f);
        return (util==words);
    }
};