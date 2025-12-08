#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e6;

int C(int n,int k){
    if(n<0)return 0;
    
    if(k==0) return 1;
    if(k==1) return n;
    if(k==2) return n*(n-1)/2;
    if(k==3) return n*(n-1)*(n-2)/6;
    
    throw k;
    return -1;
}

int stars_and_bars(int d,int s,int bound){
    int ans=0;
    
    for(int i=0;i<=d;++i){
        int cur=C(d,i)*C(s-bound*i-1,d-1);
        
        // bao ham - loai tru
        if(i%2==0)ans+=cur;
        else ans-=cur;
    }
    
    return ans;
}

pair<int,int> find_sum(int N,int T,int d){
    int cum=0;
    for(int sum=3;sum<=N*3;++sum){
        int temp=cum;
        cum+=stars_and_bars(d,sum,N);
        if(T<=cum){
            return {sum,T-temp};
        }
    }
    return {-1,-1};
}

void step3(int sum,int pos,int N){
    int cum=0;
    for(int b=1;b<=N;++b){
        cum+=stars_and_bars(1,sum-b,N);
        if(pos<=cum){
            cout<<b<<' '<<sum-b<<'\n';
            return;
        }
    }
}

void step2(int sum,int pos,int N){
    int cum=0;
    for(int a=1;a<=N;++a){
        int temp=cum;
        cum+=stars_and_bars(2,sum-a,N);
        if(pos<=cum){
            cout<<a<<' ';
            step3(sum-a,pos-temp,N);
            return;
        }
    }
}

void solve(int N,int T){
    int sum,pos;
    tie(sum,pos)=find_sum(N,T,3);
    
    step2(sum,pos,N);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,T;
    cin>>N>>T;
    
    solve(N,T);
    return 0;
}
