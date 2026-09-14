class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x11=rec1[0];
        int y11=rec1[1];
        int x12=rec1[2];
        int y12=rec1[3];
        int x21=rec2[0];
        int y21=rec2[1];
        int x22=rec2[2];
        int y22=rec2[3];

        if(x22 > x11 && x21 < x12 && y22 > y11 && y21 < y12) return true;
        return false; 
    }
};