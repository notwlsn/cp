#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e4;
vector<ar<int, 2>> pf[mxN+1];
int b[mxN+1];

void solve() {
    int n, m;
    cin >> n >> m;
    memset(b, 0, 4*m+4);
    for(int i=0, a; i<n; ++i) {
        cin >> a;
        for(ar<int, 2> j : pf[a])
            b[j[0]]=max(j[1], b[j[0]]);
    }

    int ans=1, increase=1;
    for(int i=2; i<=m; ++i) {
        int cur=1;
        for(ar<int, 2> j : pf[i])
            for(; j[1]>b[j[0]]; --j[1])
                cur=cur*j[0];
        if(cur>increase) {
            ans=i;
            increase=cur;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1; i<=mxN; ++i) {
        int a=i;
        for(int j=2; j*j<=a; ++j) {
            if(a%j)
                continue;
            pf[i].push_back({j, 0});
            for(; a%j<1; a/=j)
                ++pf[i].back()[1];
        }
        if(a>1)
            pf[i].push_back({a, 1});
    }

    int t;
    cin >> t;
    while(t--)
        solve();
}
