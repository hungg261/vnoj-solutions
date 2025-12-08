#include <bits/stdc++.h>

using namespace std;

const int MX = 30000;

struct Segment{
    int x, y1, y2, type;

    bool operator < (const Segment& other) const {
        return x < other.x;
    }
};

struct SegmentTree{
    vector<pair<int, int>> s;

    SegmentTree(int n) : s(n * 4 + 5) {
        for (int i = 1; i <= 4 * n; i++) s[i] = {0, 0};
    }

    void update(int id, int l, int r, int tl, int tr, int val) {
        if (l > tr || r < tl) return;
        if (l >= tl && r <= tr) {
            s[id].second += val;
            if (s[id].second != 0) s[id].first = r - l + 1;
            else if (l != r) s[id].first = s[id * 2].first + s[id * 2 + 1].first;
            else s[id].first = 0;
            return;
        }

        int m = (l + r) >> 1;
        update(id * 2, l, m, tl, tr, val);
        update(id * 2 + 1, m + 1, r, tl, tr, val);

        if (s[id].second != 0) s[id].first = r - l + 1;
        else s[id].first = s[id * 2].first + s[id * 2 + 1].first;
    }
};

int n;
vector<Segment> segments;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        segments.push_back({x1, y1, y2, 1});
        segments.push_back({x2, y1, y2, -1});
    }

    sort(segments.begin(), segments.end());

    SegmentTree ST(MX);
    int res = 0;
    for (int i = 0; i < (int)segments.size() - 1; i++) {
        ST.update(1, 0, MX, segments[i].y1, segments[i].y2 - 1, segments[i].type);
        res += (segments[i + 1].x - segments[i].x) * ST.s[1].first;
    }
    cout << res;
}
