#include<bits/stdc++.h>
using namespace std;

const int MAXN=17000;
int n,k,a[MAXN+1];

void solve(){
    deque<int>dq;
    for(int i=1;i<=n;++i){
        if(!dq.empty()&&i-dq.front()+1>k)dq.pop_front();
        while(!dq.empty()&&a[dq.back()]>=a[i])dq.pop_back();
        dq.push_back(i);
        
        if(i>=k){
            cout<<a[dq.front()]<<' ';
        }
    }
    cout<<'\n';
}

void input(){
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    
    solve();
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    
    while(t--){
        input();
    }
    return 0;
}
