// Problem ID - 1169D


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
int getMx()
{
    return 0;
}
int32_t main()
{
	    IOS;
#ifndef KILL_BUG
    	TIE;
#endif
        // Nice Problem
        // finding that string of size atleast 9 will be good with brute force, is not something we face regulary in contest.
        // but yea, I found that at some length it will be good.
	string s; cin>>s;
        dbg(getMx);
        int n = sz(s),
            ans = 0;
        vi Minr(n+1, n);
        //largest possible non-good substring

        for(int i = n-1; i>=0; i--)
        {
            Minr[i] = Minr[i+1];
            for(int k = 1; i+2*k < Minr[i]; k++)
            {
                if(s[i]==s[i+k] and s[i+k] == s[i+2*k])
                    Minr[i] = i+2*k;
            }
            ans += n-Minr[i];
        }
        cout << ans << ln;
	return 0;
}
