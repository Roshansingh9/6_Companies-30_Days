class Solution {
public:
    vector<int> v;
    vector<vector<int>> rect;
    int area(vector<int>& r) {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }
    Solution(vector<vector<int>>& rects) {
        rect=rects;
        int totalArea=0;
        for (auto r: rects) {
            totalArea+=area(r);
            v.push_back(totalArea);
        }
    }
    
    vector<int> pick() {
        int rnd = rand() % v.back();
        int idx = upper_bound(v.begin(), v.end(), rnd) - v.begin();
        auto r = rect[idx];
        int x = rand() % (r[2] - r[0] + 1) + r[0];
        int y = rand() % (r[3] - r[1] + 1) + r[1];
        return { x, y };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */