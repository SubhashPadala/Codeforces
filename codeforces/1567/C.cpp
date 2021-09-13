// Problem ID - 1567C
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

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html

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
vector<int> val;
int getvalue(vector<int> &d, vector<int>&c, int &n)
{
    /*
     * number of numbers that can use current carry
     */
    int ans = 1;
    if(n >=1 and c[0]!=0 and n >= 1)
    {
	return 0;
    }
    if(n>=2 and c[1]!=0 )
    {
	return 0;
    }
    for(int i = 0; i < n; i++)
    {
	int cur = c[i]*10+d[i];
	if(i+2 < n)
	    cur -= c[i+2];
	if(cur<0 || cur>18)
	{
	    dbg(c, ans, cur);
	    return 0;
	}
	/*
	 * ai+bi = cur
	 */
	ans*=val[cur];
	dbg(cur);
    }
    dbg(c, ans);
    return ans;
}
void runtestcase()
{
    string s;
    cin>>s;
    vector<int> d;
    int n = sz(s);
    dbg(n);
    for(int i = 0; i < n; i++)
    {
	d.pb(s[i]-'0');
    }
    dbg(d);
    int ans = 0;
    /*
     * carry can either be 1 or 0;
     * 2^9 combinations are easy to search
     */
    int pn = (1<<n);
    for(int i = 0; i < (pn); i++)
    {
	vector<int> carry;
	for(int j = 0, k = pn/2; j < n; j++, k/=2)
	{
	    carry.pb((i&k)==k);
	}
	ans += getvalue(d, carry, n);
    }
    cout << ans-2 << ln;
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
	val.assign(19, 0);
	for(int i = 0; i < 10; i++)
	{
	    for(int j = 0; j < 10; j++)
	    {
		val[i+j]++;
	    }
	}
	dbg(val);
	rep(tc, 1, testcase+1)
	{
		dbg(tc);
		reset();
		runtestcase();
	}
	return 0;
}
