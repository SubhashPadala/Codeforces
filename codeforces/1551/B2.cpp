// Problem ID - 1551B2

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
#define case cout << "Case #" << cno << ": " << ln

#define sz(x) ((int)(x).size())
#define prec(x) cout << fixed << showpoint; cout << setprecision(x)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using vi = vector<int>;
using pii = pair<int, int>;
using vp = vector<pii>;
using vv = vector<vector<int>>;
using mii = map<int, int>;

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


void reset(){ }

void runtestcase()
{
    int n, k; cin>>n>>k;
    vi ar(n);
    for(auto&i: ar)
        cin>>i;
    vi cnt(n+1);
    vv pos(n+1);
    for(int i = 0; i < n; i++)
    {
        pos[ar[i]].pb(i);
        cnt[ar[i]]++;
    }
    dbg(cnt);
    vi uniq;
    vi ans(n);
    for(int i = 1; i<=n; i++)
    {
	if(cnt[i]>=k)
        {
            rep(j, 0, k)
            {
                ans[pos[i][j]] = j+1;
            }
        }
        else if(cnt[i]>=1)
        {
            for(auto&j: pos[i])
                uniq.pb(j);
        }
    }
    dbg(uniq.size());
    for(int i = 0; i+k-1<sz(uniq); i+=k)
    {
        dbg(i);
        rep(j, 0, k)
            ans[uniq[i+j]] = j+1;
    }
    dbg(ans);
    for(auto&i: ans)
        cout << i << " ";
    cout << ln;
    return;
}

int32_t main()
{
	    IOS;
#ifndef KILL_BUG
    	TIE;
#endif
	int testcase = 1; 
	cin >> testcase;
	rep(tc, 1, testcase+1)
	{
		dbg(tc);
		reset();
		runtestcase();
	}
	return 0;
}

