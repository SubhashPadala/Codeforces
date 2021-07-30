// Problem ID - 1324F

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
        // Not a 1800 rated problem, probably 2100 rated.
	int n; cin>>n;
        vi ar(n);
        vi visited(n), down(n);
        vv adj(n);
        for(auto&i: ar)
        {
            cin>>i;
            if(i==0)
                i--;
        }
        rep(i, 0, n-1)
        {
            int u, v; cin>>u>>v;
            u--, v--;
            adj[u].pb(v), adj[v].pb(u);
        }
        auto ddfs = y_combinator([&](auto ddfs, int source)->void{
                visited[source] = true;
                down[source] = ar[source];
                for(auto&i: adj[source])
                {
                    if(!visited[i])
                    {
                        ddfs(i);
                        down[source] += max(0LL, down[i]);
                    }
                }
                return;
            });
        ddfs(0);
        vi up(n);
        visited.assign(n, 0);
        auto udfs = y_combinator([&](auto udfs, int source)->void{
                visited[source] = true;
                for(auto&i: adj[source])
                {
                    if(!visited[i])
                    {
                        up[i] = max(0LL, up[source]+down[source]-max(down[i], 0LL));
                        udfs(i);
                    }
                }
                return;
        });
        udfs(0);
        //what is the maximum value we can get from top.
        rep(i, 0, n)
        {
            cout << down[i]+up[i] << " ";
        }
        cout << ln;
	return 0;
}
