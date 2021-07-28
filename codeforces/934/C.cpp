// Problem ID - 934C

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
        //GrandMaster Sivav
	int n; cin>>n;
        vi ar(n);
        for(auto&i: ar)
            cin>>i;
        dbg(ar);
        //vector<array<array<int, 3>, 2>> dp(n);
        //dbg(dp);
        //dp[i][mx][reverse];
        //if reverse == 0 reverse not started
        //if reverse == 1 reverse is running
        //if reverse == 2 reverse is completed.
        //mx is the maximum element till now in the maximum subsequence formed using first i elements.
        //the sequence we are searching for looks like 11**22**11**22, we can reverse the middle part,
        // maximum length of subsequence ending at i, and having j parts.
        vector<array<int, 4>> dp(n);
        int ans = 0;
        if(ar[0]==1)
        {
            dp[0][0] = 1;
            dp[0][2] = 1;
            ans = 1;
        }
        else
        {
            dp[0][1] = dp[0][3] = 1;
            ans = 1;
        }
        for(int i = 1; i < n; i++)
        {
            if(ar[i]==2)
            {
                dp[i][3] = max(dp[i-1][3]+1, dp[i-1][2]+1);
                dp[i][0] = dp[i-1][0];
                dp[i][2] = dp[i-1][2];
                dp[i][1] = max(dp[i-1][0]+1, dp[i-1][1]+1);
            }
            else
            {
                // 1
                // 12
                // 121
                // 1212
                dp[i][0] = dp[i-1][0]+1;
                dp[i][2] = max(dp[i-1][1]+1, dp[i-1][2]+1);
                dp[i][1] = dp[i-1][1];
                dp[i][3] = dp[i-1][3];
            }
            ans = max(max(max(dp[i][0], dp[i][1]), max(dp[i][2], dp[i][3])), ans);
        }
        cout << ans << ln;
	return 0;
}
