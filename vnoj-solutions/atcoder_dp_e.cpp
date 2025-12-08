#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=100,MAXW=1e9,MAXV=1e5;
int w[MAXN+1],v[MAXN+1],n,weight,dp[MAXN+1][MAXV+1];

void solve(){
    // dp[i][j] la khoi luong nho nhat sao cho chon duoc do co gia tri j sau i phan tu dau tien
    memset(dp,1,sizeof dp);
    int limit=dp[0][0];
    
    dp[0][0]=0;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=MAXV;++j){
            dp[i][j]=dp[i-1][j];
            if(j>=v[i]){
                dp[i][j]=min(dp[i][j],dp[i-1][j-v[i]]+w[i]);
            }
        }
    }
    
    for(int j=MAXV;j>=0;--j){
        if(dp[n][j]<=weight){
            cout<<j<<'\n';
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>weight;
    for(int i=1;i<=n;++i){
        cin>>w[i]>>v[i];
    }
    
    solve();
    return 0;
}
