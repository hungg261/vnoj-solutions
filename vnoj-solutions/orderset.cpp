#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct FenwickTree{
    int n;
    vector<int> BIT;
    
    FenwickTree() = default;
    FenwickTree(int sz): n(sz){ BIT.resize(sz + 1, 0); }
    
    void update(int idx, int value){ for(int i = idx; i <= n; i += i & -i) BIT[i] += value; }
    int get(int idx){ int res = 0; for(int i = idx; i > 0; i -= i & -i) res += BIT[i]; return res; }
    int get(int l, int r){ return get(r) - get(l - 1); }
    
    void assign(int idx, int value){
        int diff = value - get(idx, idx);
        update(idx, diff);
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q;
    cin >> Q;
    
    ordered_set oset;
    while(Q--){
        char type;
        cin >> type;
        
        if(type == 'I'){
            int x; cin >> x;
            oset.insert(x);
        }
        else if(type == 'D'){
            int x; cin >> x;
            auto pos = oset.find(x);
            if(pos != oset.end()) oset.erase(pos);
        }
        else if(type == 'K'){
            int k; cin >> k;
            auto pos = oset.find_by_order(k - 1);
            
            if(pos != oset.end()) cout << (*pos) << '\n';
            else cout << "invalid\n";
        }
        else if(type == 'C'){
            int x; cin >> x;
            cout << oset.order_of_key(x) << '\n';
        }
    }
    
    return 0;
}
