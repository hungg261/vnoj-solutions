//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//
//int c[5]={0,5,10,20,50},a[5],n;
//
//int ans=0;
//void Try(int idx,int sum){
//    if(sum>n){
//        return;
//    }
//    if(idx>4){
//        if(sum==n){
//            ++ans;
//        }
//        return;
//    }
//
//    for(int i=0;i<=a[idx];++i){
//        Try(idx+1,sum+c[idx]*i);
//    }
//}
//
//const int MAX=100;
//int dp[5][MAX+1];
//void solve(int target){
//    dp[1][0]=1;
//    for(int idx=1;idx<=4;++idx){
//        for(int sum=0;sum<=n;++sum){
//            for(int i=0;i<=a[idx];++i){
//                if(sum+c[idx]*i<=n)dp[idx+1][sum+c[idx]*i]+=dp[idx][sum];
//            }
//        }
//    }
//
//    for(int i=1;i<=4;++i){
//        for(int j=0;j<=n;++j){
//            cerr<<dp[i][j]<<' ';
//        }
//        cerr<<'\n';
//    }
//    cout<<dp[4][n]<<'\n';
//}
//
//signed main(){
//    for(int i=1;i<=4;++i)cin>>a[i];
//    cin>>n;
//
////    Try(1,0);
////    cout<<ans<<'\n';
//
//    solve(n);
//    return 0;
//}
//

#include<bits/stdc++.h>
using namespace std;

signed main(){
    int a,b;
    cin>>a>>b;
    
    cout<<a+b<<'\n';
    return 0;
}
