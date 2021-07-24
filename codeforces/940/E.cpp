// Problem ID - 940E


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
const int maxx = (int)1e5+1;

int32_t main()
{
	    IOS;
#ifndef KILL_BUG
    	TIE;
#endif
        // GrandMaster Sivav
        // WoW, Nice question, but over rated though.
        // DPSKILLS++;
        // IQ++;
	int n, c; cin>>n>>c;
        vi ar(n+1);
        vi dp(n+1);
        vi sum(n+1);

        //Editorial by ME (GM Sivav)
        // dp[i] is minimum sum we can get by partitioning the given set into c length or 1 length.
        // maintain set of size <= c, in which we store the last c elements, in which the least can be removed when taking c length partition ending at that point.
        // Conceptually Very Good Question.
        multiset<int> mis;
        for(int i(1); i <= n; i++)
        {
            cin>>ar[i];
            sum[i] = sum[i-1]+ar[i];
        }

        for(int i(1); i <= n; i++)
        {
            if(i>c)
                mis.erase(mis.find(ar[i-c]));
            dp[i] = dp[i-1]+ar[i];
            mis.insert(ar[i]);
            if(i>=c)
                dp[i] = min(dp[i], dp[i-c]+sum[i]-sum[i-c]-*mis.begin());
        }
        cout << dp[n] << ln;
	return 0;
}
