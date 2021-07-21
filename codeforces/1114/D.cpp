// Problem ID - 1114D

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

int dp[5000][5000][2];
int findAnswer(int i, int j, int color, vi&c)
{
    if(i==j)
        return 0;
    if(dp[i][j-1][0]==0)
        dp[i][j-1][0] = findAnswer(i, j-1, 0, c);
    if(dp[i][j-1][1]==0)
        dp[i][j-1][1] = findAnswer(i, j-1, 1, c);
    if(dp[i+1][j][0] == 0)
        dp[i+1][j][0] = findAnswer(i+1, j, 0, c);
    if(dp[i+1][j][1]==0)
        dp[i+1][j][1] = findAnswer(i+1, j, 1, c);

    int ans = inf;
    if(color==1)
    {
        //change to c[j];
        // [i, j-1] to c[j];
        ans = min(dp[i][j-1][1]+1, dp[i][j-1][0]+(int)(c[j]!=c[i]));
    }
    else if(color==0)
    {
        //change to c[i];
        // [i+1, j] to c[i];
        ans = min(dp[i+1][j][0]+1, dp[i+1][j][1]+(int)(c[j]!=c[i]));
    }
    return ans;
}
int32_t main()
{
	    IOS;
#ifndef KILL_BUG
    	TIE;
#endif
	int n; cin>>n;
        vi c;
        rep(i,0,n)
        {
            int cur; cin>>cur;
            if(c.size()==0 || c.back()!=cur)
                c.pb(cur);
        }
        dbg(c);
        n = (int)c.size();
        //vector<vv> dp(5000, vv(5000, vi(2, -1)));
        //dp[i][j][0] is number of steps required to make segment i, j to color c[i];
        //dp[i][j][1] is number of steps required to make segment i, j to color c[j];
        cout << min(findAnswer(0, n-1, 0, c), findAnswer(0, n-1, 1, c));
	return 0;
}
