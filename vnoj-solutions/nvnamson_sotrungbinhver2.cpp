#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
using namespace std;

struct CustomHash {
    size_t operator()(int x) const {
        x>>((x>>16)^x)*0x45d9f3b;
        x>>((x>>16)^x)*0x45d9f3b;
        x>>(x>>16)^x;
        return x;
    }
};

const int MAXN=1700;
int n,a[MAXN];

// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// int Rand(int l,int r){
//     return l+rng()%(r-l+1);
// }

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=10;
    cin>>t;
    unordered_map<int,int,CustomHash>freq;
    while(t--){
        cin>>n;
        // n=1000;
        for(int i=0;i<n;++i){
            cin>>a[i];
            // a[i]=Rand(-1e9,1e9);
        }
        
        freq.clear();
        freq.reserve(n);
        long long total=0;
        for(int k=n-1;k>=0;--k){
            for(int i=0;i<k;++i){
                int target=2*a[k]-a[i];
                auto it=freq.find(target);
                if(it!=freq.end()){
                    total+=it->second;
                }
            }
            ++freq[a[k]];
        }
        
        cout<<total<<'\n';
    }
    return 0;
}
