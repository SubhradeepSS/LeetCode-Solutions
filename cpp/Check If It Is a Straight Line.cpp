class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x0,x1,y0,y1;
        x0=coordinates[0][0];
        y0=coordinates[0][1];
        x1=coordinates[1][0];
        y1=coordinates[1][1];
        int a=x0-x1,b=y0-y1,c=x0*y1-x1*y0;
        
        for(int i=2;i<coordinates.size();i++){
            int x=coordinates[i][0];
            int y=coordinates[i][1];
            if(a*y!=b*x+c)
                return false;
        }
        return true;
    }
};