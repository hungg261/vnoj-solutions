#include<bits/stdc++.h>
#define int long long
using namespace std;

const int dx[4]={2,2,1,1},dy[4]={-1,1,-2,2};
void solve(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>a(n+1,vector<int>(m+1));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>a[i][j];
        }
    }
    
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(2,0)));
    for(int j=1;j<=m;++j){
        dp[1][j][0]=dp[1][j][1]=a[1][j];
    }
    for(int i=2;i<=n;++i){
        for(int j=1;j<=m;++j){
            for(int d=0;d<2;++d){
                int nx=i-dx[d],ny=j-dy[d];
                if(nx>=1&&ny>=1&&nx<=n&&ny<=m){
                    dp[i][j][0]=max(dp[i][j][0],dp[nx][ny][0]+a[i][j]);
                    dp[i][j][1]=max({dp[i][j][1],dp[nx][ny][0]+a[i][j],dp[nx][ny][1]+a[i][j]});
                }
            }
            
            for(int d=2;d<4;++d){
                int nx=i-dx[d],ny=j-dy[d];
                if(nx>=1&&ny>=1&&nx<=n&&ny<=m){
                    dp[i][j][1]=max(dp[i][j][1],dp[nx][ny][0]+a[i][j]);
                }
            }
        }
    }
    
    int ans=0;
    for(int j=1;j<=m;++j){
        ans=max(ans,dp[n][j][1-n%2]);
    }
    
    cout<<n/2<<' '<<ans<<'\n';
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=m;++j){
    //         cout<<dp[i][j][0]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=m;++j){
    //         cerr<<dp[i][j][1]<<' ';
    //     }
    //     cerr<<'\n';
    // }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    
    return 0;
}
