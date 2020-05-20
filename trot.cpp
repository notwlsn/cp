#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, M=998244353;
int n, v, a[mxN], b[mxN], pa[mxN], pb[mxN], c[mxN+1];

void ad(int i, int j, int x) {
    c[0]+=x;
    c[max(i-j, 0)]-=x;
    c[n-j]+=x;
    c[min(i-j+n, n)]-=x;
}

void solve() {
    cin >> n >> v;
    for(int i=0; i<n; ++i) {
        cin >> a[i], --a[i];
        pa[a[i]]=i;
    }
    for(int i=0; i<n; ++i) {
        cin >> b[i], --b[i];
        pb[b[i]]=i;
    }

    memset(c, 0, 4*n+4);
    for(int i=0; i<n; ++i) {
        for(int l=2; l<n; l*=2) {
            ad(n, pb[i], 1);
            ad(min(pa[i]+l, n), pb[i], -1);
            ad(max(pa[i]-l+1, 0), pb[i], 1);
        }
    }

    ll ans=1;
    for(int i=0; i<v; ++i) {
        c[i+1]+=c[i];
        ans=ans*c[i]%M;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}
