#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=100,MAXW=1e5;
int w[MAXN+1],v[MAXN+1],dp[MAXN+1][MAXW+1],N,W;

void solve(){
    for(int i=1;i<=N;++i){
        for(int j=0;j<=W;++j){
            dp[i][j]=dp[i-1][j];
            if(j>=w[i]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    
    cout<<dp[N][W]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>W;
    for(int i=1;i<=N;++i){
        cin>>w[i]>>v[i];
    }
    
    solve();
    return 0;
}
