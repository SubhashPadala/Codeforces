// Problem ID - 710C

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
void check(vv& ans)
{

    int n =((int)ans.size())-1;
    for(int i = 1; i <=n; i++)
    {
        int sum = 0;
        int sum2=0;
        for(int j = 1; j <= n; j++)
        {
            sum+=ans[j][i];
            sum2+=ans[i][j];
        }
        assert((sum%2)==1);
        assert((sum2%2)==1);
    }

    int d1 = 0;
    int d2 = 0;
    for(int i = 1; i <= n; i++)
    {
        d1+=ans[i][i];
        d2+= ans[n-i+1][i];
    }
    assert((d1%2)==1);
    assert((d2%2)==1);
    return;
}
int32_t main()
{
	    IOS;
#ifndef KILL_BUG
    	TIE;
#endif
	int n; cin>>n;
        vv ans(n+1, vi(n+1));
        int curEven = 2;
        int curOdd = 1;
        for(int d = 1; d <= n/2+1; d++)
        {
            int i = d;
            int j = d;
            //start is (d, d);
            int p = (n/2-d+2)%2;
            dbg(p);
            for(; i <=n-d+1; i++)
            {
                dbg(i, d, p);
                if(p==1)
                {
                    if(ans[i][d]==0)
                    {
                        ans[i][d] = curOdd;
                        curOdd+=2;
                    }
                    if(ans[i][n-d+1]==0)
                    {
                        ans[i][n-d+1] = curOdd;
                        curOdd+=2;
                    }
                }
                else
                {
                    if(ans[i][d]==0)
                    {
                        ans[i][d] = curEven++;
                        curEven++;
                    }
                    if(ans[i][n-d+1]==0)
                    {
                        ans[i][n-d+1] = curEven++;
                        curEven++;
                    }
                }
                p++;
                p%=2;
            }
            dbg(ans);
            p = (n/2-d+2)%2;
            for(;j<=n-d+1;j++)
            {
                dbg(d, j, p);
                if(p==1)
                {
                    if(ans[d][j]==0)
                    {
                        ans[d][j] = curOdd++;
                        curOdd++;
                    }
                    if(ans[n-d+1][j]==0)
                    {
                        ans[n-d+1][j] = curOdd++;
                        curOdd++;
                    }
                }
                else
                {
                    if(ans[d][j]==0)
                    {
                        ans[d][j] = curEven++;
                        curEven++;
                    }
                    if(ans[n-d+1][j]==0)
                    {
                        ans[n-d+1][j] = curEven++;
                        curEven++;
                    }
               }
                p++;
                p%=2;
            }
        }
        rep(i, 1, n+1)
        {
            rep(j, 1, n+1)
            {
                cout << ans[i][j] << " ";
            }
            cout << ln;
        }
        check(ans);
	return 0;
}
