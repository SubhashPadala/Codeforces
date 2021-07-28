// Problem ID - 1000D

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
        // GrandMaster Sivav
        // very Simple Problem, make dp transitions very clear.
        // dp[0] = 1;
        // think of base case clearly.
	int n; cin>>n;
        vi ar(n+1);
        for(int i = n; i >= 1;i--)
        {
            cin>>ar[i];
        }
        dbg(ar);
        vector<int> fact(n+1),
                    inv(n+1),
                    dp(n+1);
        fact[0] = 1;
        inv[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            fact[i] = (fact[i-1]*i)%MOD2;
            inv[i] = (inv[i-1]*powb(i, MOD2-2, MOD2))%MOD2;
        }
        dbg(fact, inv);

        auto nCr = [&](int n, int r)->int{
            if(n<r)
                return 0;
            return (fact[n]*((inv[n-r]*inv[r])%MOD2))%MOD2;
        };

        //assuming that till here everything is correct.
        dp[0] = 1;
        int ans = 0;
        for(int i = 2; i <=n; i++)
        {
            int cur = ar[i]+1;
            if(ar[i]<=0)
                continue;
            //[prev_end+1, i] are used as subarray.
            for(int prev_end = i-cur; prev_end>=0; prev_end--)
            {
                dp[i] += (dp[prev_end]*nCr(i-prev_end-1, ar[i]))%MOD2;
                dp[i] %= MOD2;
            }
            ans += dp[i];
            ans %= MOD2;
        }
        cout << ans << ln;
        dbg(dp);
	return 0;
}
