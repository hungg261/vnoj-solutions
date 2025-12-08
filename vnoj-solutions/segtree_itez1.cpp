#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5;
struct segment_tree{
    int n;
    vector<int>nodes;
    
    void init(int newsize){
        n=newsize;
        nodes.resize(n*4);
    }
    
    void build(int id,int L,int R,vector<int>&arr){
        if(L==R){
            nodes[id]=arr[L];
            return;
        }
        
        int mid=(L+R)/2;
        build(id*2,L,mid,arr);
        build(id*2+1,mid+1,R,arr);
        
        nodes[id]=max(nodes[id*2],nodes[id*2+1]);
    }
    
    void update(int id,int L,int R,int pos,int x){
        if(pos<L||R<pos){
            return;
        }
        if(L==R){
            nodes[id]=x;
            return;
        }
        
        int mid=(L+R)/2;
        update(id*2,L,mid,pos,x);
        update(id*2+1,mid+1,R,pos,x);
        
        nodes[id]=max(nodes[id*2],nodes[id*2+1]);
    }
    
    int get(int id,int L,int R,int u,int v){
        if(v<L||R<u){
            return -1e9;
        }
        if(u<=L&&R<=v){
            return nodes[id];
        }
        
        int mid=(L+R)/2;
        return max(get(id*2,L,mid,u,v),get(id*2+1,mid+1,R,u,v));
    }
    
    void build(vector<int>&arr){
        build(1,1,n,arr);
    }
    
    void update(int pos,int x){
        update(1,1,n,pos,x);
    }
    
    int get(int u,int v){
        return get(1,1,n,u,v);
    }
};

void query(segment_tree&segg){
    int type;
    cin>>type;
    
    if(type==1){
        int x,y;
        cin>>x>>y;
        
        segg.update(x,y);
    }
    else{
        int l,r;
        cin>>l>>r;
        
        cout<<segg.get(l,r)<<'\n';
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n+1);
    for(int i=1;i<=n;++i){
        cin>>arr[i];
    }
    
    segment_tree segg;
    segg.init(n);
    segg.build(arr);
    
    int q;
    cin>>q;
    while(q--){
        query(segg);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    
    return 0;
}
