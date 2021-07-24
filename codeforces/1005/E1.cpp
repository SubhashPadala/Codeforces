// Problem ID - 1005E1

//          _____                 ___    __
//  ___________(_)___   ________ ___ |  / /
//  __  ___/__  / __ | / /_  __ `/__ | / /
//  _(__  ) _  /  __ |/ / / /_/ / __ |/ /
//  /____/  /_/   _____/  \__,_/  _____/
//  ________________________   ________         ______        ______  ______          _________
//  ____  _/____  _/___  __/   ___  __ \______ ____  /______ ____  /_____  /________ _______  /
//   __  /   __  /  __  /      __  /_/ /_  __ `/__  / _  __ `/__  //_/__  //_/_  __ `/_  __  /
//  __/ /   __/ /   _  /       _  ____/ / /_/ / _  /  / /_/ / _  ,<   _  ,<   / /_/ / / /_/ /
//  /___/   /___/   /_/        /_/      \__,_/  /_/   \__,_/  /_/|_|  /_/|_|  \__,_/  \__,_/
//
#include "bits/stdc++.h"

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KILL_BUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define pb push_back
#define int long long
#define mp make_pair
#define ln "\n"

#define sz(x) ((int)(x).size())
#define prec(x) cout << fixed << showpoint; cout << setprecision(x)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using vi = vector<int>;
using pii = pair<int, int>;
using vp = vector<pii>;
using vv = vector<vector<int>>;

const int MOD = (int)1e9 + 7;
const int MOD2 = (int)998244353;
const int inf = (int)1e18 + 1;

int powb(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

int powb(int a, int n, int m) {
    a %= m;
    int res = 1;
    while (n > 0) {
        if (n & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    return res;
}

int32_t main()
{
	    IOS;
#ifndef KILL_BUG
    	TIE;
#endif
	int n, m; cin>>n>>m;
        vi p(n+1);
        int id = -1;
        for(int i= 1; i <= n; i++)
        {
            cin>>p[i];
            if(p[i]==m)
                id = i;
        }
        vi gl(n+3);
        vi gr(n+3);
        map<int, int> cntre;
        map<int, int> cntro;
        for(int r = id; r <= n; r++)
        {
            gr[r] = gr[r-1]+(p[r]>m);
            if(r%2==0)
                cntre[r-2*gr[r]]++;
            else
                cntro[r-2*gr[r]]++;
        }
        int ans = 0;
        for(int l = id; l>=1; l--)
        {
            gl[l] = gl[l+1]+(p[l]>m);
            if(l%2==0)
            {
                ans += cntre[l+2*gl[l]];
                ans += cntro[l+2*gl[l]-1];
            }
            else
            {
                ans += cntro[l+2*gl[l]];
                ans += cntre[l+2*gl[l]-1];
            }
        }
        cout << ans << ln;
	return 0;
}
