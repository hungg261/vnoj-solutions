// ko phai code cua minh :)
// src: https://ptnkoj.com/src/138528

#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define bit(i, j) (1<<((i)*4+(j)))
const int MAX = 65535, INF = 99999;
int dp[MAX + 1], m, t, n;
queue<pair<int, int>> Q;

int main() {
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    fill(dp, dp+MAX+1, INF);

    Q.emplace(0, 0);
    Q.emplace(MAX, 0);
    while(!Q.empty()) {
        tie(m, t) = Q.front(); Q.pop();
        if(dp[m] != INF) continue;
        dp[m] = t++;
        FOR(i, 4) FOR(j, 4) {
            int m2 = m ^ bit(i, j);
            if(j != 0) m2 ^= bit(i, j-1);
            if(j != 3) m2 ^= bit(i, j+1);
            if(i != 0) m2 ^= bit(i-1, j);
            if(i != 3) m2 ^= bit(i+1, j);
            if(dp[m2] == INF) Q.emplace(m2, t);
        }
    }

    cin >> n;
    while(n--) {
        int m = 0; 
        FOR(i, 16) {
            char c; cin >> c;
            m = m*2 + (c == 'T');
        }
        ((m = dp[m]) == INF)? (cout << "Impossible\n"): (cout << m << '\n');
    }       
}
