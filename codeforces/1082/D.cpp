// Problem ID - 1082D

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

int32_t main()
{
	    IOS;
#ifndef KILL_BUG
    	TIE;
#endif
	int n; cin>>n;
        vi deg(n);
        vi a1, a2;
        for(int i = 0; i < n; i++)
        {
            cin>>deg[i];
            if(deg[i]==1)
                a1.pb(i);
            else
                a2.pb(i);

        }
        dbg(a1, a2);
        vp edges;
        int ans = sz(a2)-1;
            if(a2.size() and a1.size())
            {
                edges.pb(mp(a2.back(), a1.back()));
                ans++;
                deg[a2.back()]--;
                deg[a1.back()]--;
                a1.pop_back();
            }
            if(a2.size() and a1.size())
            {
                edges.pb(mp(a2[0], a1.back()));
                ans++;
                deg[a1.back()]--;
                deg[a2[0]]--;
                a1.pop_back();
            }
        dbg(deg);
        vi left;
        for(int i = 0; i < sz(a2)-1; i++)
        {
            edges.pb(mp(a2[i], a2[i+1]));
            deg[a2[i]]--;
            deg[a2[i+1]]--;
        }
        for(int i = 0; i < sz(a2); i++)
        {
            if(deg[a2[i]]!=0)
                left.pb(a2[i]);
        }
        dbg(left);
        //we completed a2.
        //2 left's if there are any.
        //next using the left's, we try to 
        for(int i = 0; i < sz(a1); i++)
        {
            while(sz(left) and deg[left.back()]==0)
                left.pop_back();

            if(left.size()==0)
            {
                cout << "NO" << ln;
                return 0;
            }
            deg[left.back()]--;
            edges.pb(mp(left.back(), a1[i]));
            deg[a1[i]]--;
        }
        dbg(ans);
        dbg(edges);
        cout << "YES" << " " << ans << ln;
        cout << sz(edges) << ln;
        for(auto&i: edges)
            cout << i.fi +1 << " " << i.se +1 << ln;

	return 0;
}
