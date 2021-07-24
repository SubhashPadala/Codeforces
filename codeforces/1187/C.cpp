// Problem ID - 1187C


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
#define ub upper_bound
#define lb lower_bound
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
        // GrandMaster Sivav
        // I literally had zeroMood solving this question, wasted so much time.
        // ar[i] = 1 if (i, i+1) form increasing pair
        // ar[i] = -1 if(i, i+1) form decreasing pair
        // if [l, r] is increasing then ar[i] = 1 for all i = [l, r-1]
        // for decreasing if atleast one ar[i] = -1 for i = [l, r-1].
	int n, m; cin>>n>>m;
        vi ar(n+1);
        vp t;
        vi cnt(n+1);
        for(int i = 0; i < m; i++)
        {
            int ct, l,r;cin>>ct>>l>>r;
            if(ct==1)
            {
                cnt[l]++;
                cnt[r]--;
            }
            if(ct==0)
                t.push_back(mp(l, r));
        }
        int curr = 0;
        vi cnts(n+1);
        for(int i = 1; i < n+1; i++)
        {
            curr+=cnt[i];
            if(curr>0)
            {
                ar[i] = 1;
            }
            else
            {
                ar[i] = -1;
                cnts[i]++;
            }
        }
        for(int i = 1; i < n+1; i++)
            cnts[i]+=cnts[i-1];

        for(int i = 0; i < sz(t); i++)
        {
            int l, r;
            tie(l, r) = t[i];
            // [l, r-1], check if any element is there within this
            // lb(l)
            //
            // number of elements less than l, lb(l-1)
            // number of elements less than r-1, lb(r-2) = p
            if(cnts[r-1]-cnts[l-1]<=0)
            {
                cout << "NO" << ln;
                return 0;
            }
        }
        cout << "YES" << ln;
        dbg(ar);
        vi ans(n+1);
        ans[1] = 1e9;
        cout << ans[1] << " ";
        for(int i = 1; i < n; i++)
        {
            if(ar[i]==1)
            {
                ans[i+1] = ans[i];
            }
            else
                ans[i+1] = ans[i]-1;
            cout << ans[i+1] << " ";
        }
        cout << ln;
	return 0;
}
