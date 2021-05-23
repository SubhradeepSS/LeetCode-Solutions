class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0,cows=0;
        vector<int> hash(10,0);
        vector<bool> vis(guess.size(),false);
        for(char c:secret)
            hash[c-'0']++;
        for(int i=0;i<guess.size();i++){
            if(guess[i]==secret[i]){
                bulls++;
                hash[guess[i]-'0']--;
                vis[i]=true;
            }
        }
        for(int i=0;i<guess.size();i++){
            if(!vis[i]&&hash[guess[i]-'0']>0){
                vis[i]=true;
                hash[guess[i]-'0']--;
                cows++;
            }
        }
        return to_string(bulls)+'A'+to_string(cows)+'B';
    }
};