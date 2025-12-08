/******************************************************************************
Link: https://cses.fi/problemset/task/2134
Code: 2134
Time (YYYY-MM-DD-hh.mm.ss): 2025-09-26-17.55.02
*******************************************************************************/
#include<bits/stdc++.h>
//#define int long long
using namespace std;
 
const int MAXN = 2e5;
int h[MAXN + 5],
    sz[MAXN + 5],
    par[MAXN + 5],
 
    ChainHead[MAXN + 5],
    ChainID[MAXN + 5],
    Arr[MAXN + 5],
    Pos[MAXN + 5],
    curChain = 1, curPos;
 
vector<int> adj[MAXN + 5];
int n, v[MAXN + 5];
 
// Segment tree
int nodes[MAXN * 4 + 5];
void update(int id, int l, int r, int idx, int val){
    if(r < idx || idx < l) return;
    if(l == r){
        nodes[id] = val;
        return;
    }
 
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, idx, val);
    update(id << 1 | 1, mid + 1, r, idx, val);
    nodes[id] = max(nodes[id << 1], nodes[id << 1 | 1]);
}
 
int get(int id, int l, int r, int u, int v){
    if(r < u || v < l) return -1e9;
    if(u <= l && r <= v) return nodes[id];
 
    int mid = (l + r) >> 1;
    return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}
 
// HLD
void dfs(int u, int prev){
    sz[u] = 1;
 
    for(int v: adj[u]){
        if(v == prev) continue;
 
        par[v] = u;
        h[v] = h[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
 
void hld(int u, int prev){
    if(!ChainHead[curChain]) ChainHead[curChain] = u;
    ChainID[u] = curChain;
 
    ++curPos;
    Arr[curPos] = u;
    Pos[u] = curPos;
    update(1, 1, n, curPos, v[u]);
 
    int nxt = 0;
    for(int v: adj[u]){
        if(v == prev) continue;
 
        if(nxt == 0 || sz[nxt] < sz[v]) nxt = v;
    }
    if(nxt) hld(nxt, u);
 
    for(int v: adj[u]){
        if(v == prev || v == nxt) continue;
 
        ++curChain;
        hld(v, u);
    }
}
 
// queries
int maxquery(int u, int v){
    int res = -1e9;
    while(ChainID[u] != ChainID[v]){
        if(ChainID[u] > ChainID[v]){
            res = max(res, get(1, 1, n, Pos[ChainHead[ChainID[u]]], Pos[u]));
            u = par[ChainHead[ChainID[u]]];
        }
        else{
            res = max(res, get(1, 1, n, Pos[ChainHead[ChainID[v]]], Pos[v]));
            v = par[ChainHead[ChainID[v]]];
        }
    }
    if(h[u] > h[v]) swap(u, v);
    res = max(res, get(1, 1, n, Pos[u], Pos[v]));
 
    return res;
}
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
    }
 
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;
 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs(1, 0);
    hld(1, 0);
 
    while(q--){
        int type;
        cin >> type;
 
        if(type == 1){
            int s, x;
            cin >> s >> x;
 
            update(1, 1, n, Pos[s], x);
        }
        else{
            int u, v;
            cin >> u >> v;
 
            cout << maxquery(u, v) << ' ';
        }
    }
 
    return 0;
}
