// Problem ID - 1551C

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
    int n; cin>>n;
    vector<vector<pii>> cntChar(5, vp(n));
    rep(i, 0, n)
    {
	string s;
	cin>>s;
	rep(j, 0, 5)
	    cntChar[j][i].fi = sz(s);
	for(auto&j: s)
	{
	    cntChar[j-'a'][i].se++;
	    cntChar[j-'a'][i].fi--;
	}
	
    }
    dbg(cntChar);
    int mx = -inf;

    for(auto&i: cntChar)
    {
	int curr = 0;
	sort(all(i), [](auto&left, auto &right){
	    return ((left.se-left.fi) < (right.se-right.fi));
	});
	reverse(all(i));
	int cntother = 0;
	int cnt = 0;
	while(cntother<=cnt)
	{
	    if(cntother+i[curr].fi < cnt+i[curr].se)
	    {
		cntother += i[curr].fi;
		cnt+=i[curr].se;
		curr++;
	    }
	    else
	    {
		break;
	    }
	    if(curr==n)
		break;
	}
	mx = max(curr, mx);
    }
    cout << mx << ln;
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
