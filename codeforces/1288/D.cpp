// Problem ID - 1288D

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
int n, m;
int a1, a2;
pair<bool, pii> can(int x, vv&ar)
{
    vector<int> msk(1<<m, -1);
    for(int i=1; i <=n; i++)
    {
        int cur = 0;
        for(int j = 0; j < m; j++)
        {
            if(ar[i][j]>=x)
                cur ^= (1<<j);
            msk[cur] = i;
        }
    }
    if(msk[(1<<m)-1]!=-1)
    {
        a1 = a2 = msk[(1<<m)-1];
        return mp(true, mp(a1, a2));
    }
    for(int i=0;i<(1<<m); i++)
    {
        for(int j =0; j <(1<<m); j++)
        {
            if(msk[i]!=-1 and msk[j]!=-1 and ((i|j)==((1<<m)-1)))
            {
                dbg(i, j);
                dbg(msk);
                a1 = msk[i];
                a2 = msk[j];
                return mp(true, mp(a1, a2));
            }
        }
    }
    return mp(false, mp(-1, -1));
}

int32_t main()
{
	    IOS;
#ifndef KILL_BUG
    	TIE;
#endif
        cin>> n>>m;
        vv ar(n+1, vi(m));
        set<int> v;
        vi vals;
        rep(i,1, n+1)
        {
            rep(j, 0, m)
            {
                cin>>ar[i][j];
                if(!v.count(ar[i][j]))
                    vals.pb(ar[i][j]);
                v.insert(ar[i][j]);
            }
        }
        sort(all(vals));
        dbg(vals);
        int l = 0;
        int r = sz(vals)-1;
        int mid;
        // for any x >= answer, we can find two arrays
        while(l<r)
        {
            mid = (l+r+1)/2;
            if(can(vals[mid], ar).fi)
            {
                l = mid;
            }
            else
            {
                r = mid-1;
            }
        }
        dbg(l, r);
        dbg(a1, a2);
        pii ans = can(vals[l], ar).se;
        cout << ans.fi << " " << ans.se << ln;
	return 0;
}
