// Problem ID - 1033D

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
        vi ar(n);
        map<int, int> cnt;
        for(auto&i: ar)
        {
            cin>>i;
            cnt[i]++;
        }

        // 1, sqrt(a), a
        // 1, x, y, a
        // 1 , x, sqrt(a), y, a
        // sqrt(a), x, are primes pakka
        // 3 -> a = p^2
        // 4 -> a = p^3 or p1*p2
        // 5 -> a = p^4
        // getting away without p1*p2? is there a way.
        // number of different p's is O(2) for each number.
        // O(1000) is the number of distinct p's.
        // for each a of the form p1*p2, find __gcd(a, x)!=1, for all x in given numbers.
        // depending upon what x type is we can add the required cnt of that prime.
        // if we make all ai's distinct using map and cnt, then our __gcd(a, x) will be either prime or 1, using this we can complete ig.
        // how to eliminate choosen prime or use o
        // after finding gcd divide number by gcd maybe, then choosen prime count is taken away.
        //
        // a1, a2, ...., an.
        map<int, int> ans;
        vector<int> p1p2Type;
        vector<int> primes;
        for(auto&i: cnt)
        {
            int a = i.fi;
            long double a4 = sqrtl(sqrtl(a));
            long double a3 = cbrtl(a);
            long double a2 = sqrtl(a);
            if(ceil(a4)==a4)
            {
                if(!ans.count((int)a4))
                    primes.pb((int)a4);
                ans[(int)a4]+=4*i.se;
            }
            else if(ceil(a3)==a3)
            {
                if(!ans.count((int)a3))
                    primes.pb((int)a3);
                ans[(int)a3]+=3*i.se;
            }
            else if(ceil(a2)==a2)
            {
                if(!ans.count((int)a2))
                    primes.pb((int)a2);
                ans[(int)a2]+=2*i.se;
            }
            else
            {
                p1p2Type.pb(a);
            }
        }
        dbg(cnt);
        dbg(primes);
        //we have unique primes in primes
        int Answer = 1;
        //now we have all primes for type 2, 3, 4.
        // all these are different.
        // so max only one prime intersection.
        for(int i = 0; i < sz(p1p2Type); i++)
        {
            dbg(p1p2Type);
            int curr = 1;
            int a = p1p2Type[i];
            if(a==1)
                continue;
            int g = 1;
            for(int j = i+1; j < sz(p1p2Type); j++)
            {
                g = (__gcd(p1p2Type[i], p1p2Type[j]));
                int b = p1p2Type[j];
                if(g!=1)
                {
                    if(!ans.count(b/g))
                        primes.pb(b/g);
                    if(!ans.count(g))
                        primes.pb(g);
                    ans[b/g]+=cnt[b];
                    ans[g]+=cnt[b];
                    p1p2Type[j] = 1;
                    curr=g;
                }
            }
            if(curr!=1)
            {
                if(!ans.count(a/curr))
                    primes.pb(a/curr);
                if(!ans.count(curr))
                    primes.pb(curr);
                ans[a/curr]+=cnt[a];
                ans[curr]+=cnt[a];
                p1p2Type[i] = 1;
            }
        }
        for(int j = 0; j < primes.size(); j++)
        {
            int p = primes[j];
            for(int i = 0; i < sz(p1p2Type); i++)
            {
                if(p1p2Type[i]%p==0)
                {
                    ans[p] += cnt[p1p2Type[i]];
                    ans[p1p2Type[i]/p] += cnt[p1p2Type[i]];
                    if(!ans.count(p1p2Type[i]/p))
                        primes.pb(p1p2Type[i]/p);
                    p1p2Type[i] = 1;
                }
            }
        }
        for(int i = 0; i < sz(p1p2Type); i++)
        {
            int a = p1p2Type[i];
            if(p1p2Type[i]!=1)
            {
                Answer = (Answer*(cnt[a]+1))%MOD2;
                Answer = (Answer*(cnt[a]+1))%MOD2;
            }
        }

        for(auto&i: ans)
            Answer = ((i.se+1)*Answer)%MOD2;
        cout << Answer << ln;
	return 0;
}
