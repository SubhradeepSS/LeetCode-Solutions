class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area=0,i=0;
        stack<int> s;
        while(i<heights.size()){
            if(s.empty()||heights[i]>=heights[s.top()])
                s.push(i++);
            else{
                int h=heights[s.top()];
                s.pop();
                int a=h*(s.empty()?i:i-s.top()-1);
                if(a>area)
                    area=a;
            }
        }
        while(!s.empty()){
            int h=heights[s.top()];
            s.pop();
            int a=h*(s.empty()?i:i-s.top()-1);
            if(a>area)
                area=a;       
        }
        return area;
    }
};