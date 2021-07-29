// Problem ID - 1343E
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
    //GrandMaster Sivav
    //Invented new problem using partial idea of this problem :joy:
    int n, m, a, b, c;
    cin>>n>>m>>a>>b>>c;
    vi p(m+1);
    rep(i, 1, m+1)
	cin>>p[i];
    sort(all(p));
    for(int i = 1; i <=m; i++)
	p[i] += p[i-1];
    dbg(p);
    // Imagine a graph which has no edges.
    // let m be minimum number of edges to be added to delta graph so that a, b, c vertices are connected.
    // p[m] will be our answer
    vv adj(n);
    rep(i, 0, m)
    {
	int a, b; cin>>a>>b;
	a--, b--;
	adj[a].pb(b);
	adj[b].pb(a);
    }
    dbg(adj);
    auto bfs = [&](auto source, auto&dist){
	queue<int> q;
	q.push(source);
	vi visited(n);
	visited[source] = true;
	dist[source] = 0;
	while(q.size())
	{
	    for(auto i: adj[q.front()])
		if(!visited[i])
		{
		    visited[i] = true;
		    dist[i] = dist[q.front()]+1;
		    q.push(i);
		}
	    q.pop();
	}
    };
    vi dista(n),
       distb(n),
       distc(n);
    bfs(a-1, dista);
    bfs(b-1, distb);
    bfs(c-1, distc);
    dbg(dista);
    dbg(distb);
    dbg(distc);
    int ans = inf;
    auto get = [&](int i){
	return dista[i]+distb[i]+distc[i];
    };
    for(int i = 0; i < n; i++)
    {
	if(get(i)>m)
	    continue;
	ans = min(ans, p[distb[i]]+p[get(i)]);
	dbg(p[distb[i]]+p[get(i)], i);
    }
    cout << ans << ln;
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
