// Problem ID - 1183G
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
    mii avail;
    mii give;
    int ai, fi;
    for(int i = 0; i < n; i++)
    {
	cin>>ai>>fi;
	avail[ai]++;
	if(fi==1)
	    give[ai]++;
    }
    map<int, multiset<int, greater<int>>, greater<int>> v;
    // for each gift size, give the one which is having maximum give
    for(auto i: avail)
    {
	v[avail[i.fi]].insert(give[i.fi]);
    }

    multiset<int, greater<int>> temp;
    int cur = (*v.begin()).fi;
    int ans = 0;
    int cnt = 0;

    while(cur>0)
    {
	//get_best and delete best and then update rest;
	// best can come from temp or v[cur];
	if(v[cur].size()==0 and temp.size()==0)
	{
	    cur--;
	    continue;
	}
	ans+=cur;
	if(temp.size()==0 and v[cur].size()!=0)
	{
	    cnt+=*v[cur].begin();
	    v[cur].erase(v[cur].begin());
	}
	else if(temp.size()!=0 and v[cur].size()==0)
	{
	    cnt+=min(*temp.begin(), cur);
	    temp.erase(temp.begin());
	}
	else if(*v[cur].begin()>*temp.begin())
	{
	    cnt+=*v[cur].begin();
	    v[cur].erase(v[cur].begin());
	}
	else
	{
	    cnt+=min(*temp.begin(), cur);
	    temp.erase(temp.begin());
	}
	for(auto i: v[cur])
	    temp.insert(i);
	cur--;
    }
    cout << ans << " " << cnt << ln;
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
