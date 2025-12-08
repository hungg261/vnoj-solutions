#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e6;
int a[MAXN+1],dp[MAXN+1][2],n;

void solve(){
    dp[0][0]=dp[0][1]=-1e18;
    for(int i=1;i<=n;++i){
        dp[i][0]=max({dp[i-1][0],dp[i-1][1]+a[i],a[i]});
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]-a[i]);
    }
    
    // for(int i=0;i<=1;++i){
    //     for(int j=1;j<=n;++j){
    //         cout<<dp[j][i]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<max(dp[n][0],dp[n][1])<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    
    solve();
    return 0;
}
