class Solution {
public:
    int area(int x1, int y1, int x2, int y2) { return max(0, y2 - y1) * max(0, x2 - x1); }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int cx1 = max(ax1, bx1), cy1 = max(ay1, by1), cx2 = min(ax2, bx2), cy2 = min(ay2, by2);
        return area(ax1, ay1, ax2, ay2) + area(bx1, by1, bx2, by2) - area(cx1, cy1, cx2, cy2);
    }
};