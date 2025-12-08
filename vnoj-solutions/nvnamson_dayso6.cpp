#include<bits/stdc++.h>
#define left sussy
#define right baka
#define int long long
using namespace std;

const int MAXN=1e5;
int n,Q,a[MAXN+5];
int left[MAXN+5],right[MAXN+5];
vector<int>queries,sorted_a;

void compute(){
    stack<int>sta;
    for(int i=1;i<=n;++i){
        while(!sta.empty()&&a[sta.top()]<=a[i])sta.pop();
        if(sta.empty()){
            left[i]=0;
        }
        else left[i]=sta.top();

        sta.push(i);
    }

    while(!sta.empty())sta.pop();

    for(int i=n;i>=1;--i){
        while(!sta.empty()&&a[sta.top()]<=a[i])sta.pop();
        if(sta.empty()){
            right[i]=n+1;
        }
        else right[i]=sta.top();

        sta.push(i);
    }
}

void presolve(){
    vector<pair<int,int>>pairs;
    for(int i=1;i<=n;++i){
        pairs.push_back({a[i],right[i]-left[i]-1});
    }
    sort(pairs.begin(),pairs.end());

    int cur_max=-1e18;
    for(auto p:pairs){
        cur_max=max(cur_max,p.second);
        sorted_a.push_back(p.first);
        queries.push_back(cur_max);
    }
}

void solve(int value){
    auto pos=upper_bound(sorted_a.begin(),sorted_a.end(),value);
    if(pos==sorted_a.begin()){
        cout<<"0\n";
        return;
    }
    int idx=pos-sorted_a.begin()-1;
    cout<<queries[idx]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>Q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    compute();
    presolve();

    while(Q--){
        int k;
        cin>>k;

        solve(k);
    }
    return 0;
}
