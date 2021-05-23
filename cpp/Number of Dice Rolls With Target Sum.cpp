class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int table[d+1][target+1];
        int p=pow(10,9)+7;
        memset(table,0,sizeof(table));
        for(int i=1;i<=min(f,target);i++)
            table[1][i]=1;
        for(int i=2;i<=d;i++){
            for(int j=1;j<=target;j++){
                for(int k=1;k<=min(j-1,f);k++)
                    table[i][j]=(table[i-1][j-k]%p+table[i][j]%p)%p;;
            }
        }
        return table[d][target];
    }
};