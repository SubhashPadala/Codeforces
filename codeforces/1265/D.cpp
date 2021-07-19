// Problem ID - 1265D

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

void findAnswer(deque<int>&ans, int& a, int& b, int aa, int bb)
{
    while(a and b)
    {
        ans.pb(aa);
        ans.pb(bb);
        a--;
        b--;
    }
    return;
}
void printAnswer(deque<int>&ans)
{
    cout << "YES" << ln;
    for(auto&i: ans)
        cout << i << " ";
    cout << ln;
    return;
}
int32_t main()
{
	    IOS;
#ifndef KILL_BUG
    	TIE;
#endif
	int a, b,c,d;
        cin>>a>>b>>c>>d;
        if(a==1 and !b and !c and !d)
        {
            cout << "YES" << ln;
            rep(i, 0, a)cout << 0 << ln;
            return 0;
        }
        else if(!a and b==1 and !c and !d)
        {
            cout << "YES" << ln;
            rep(i, 0, b)cout << 1 << ln;
            return 0;
        }
        else if(!a and !b and c==1 and !d)
        {
            cout << "YES" << ln;
            rep(i, 0, c)cout << 2 << ln;
            return 0;
        }
        else if(!a and !b and !c and d==1)
        {
            cout << "YES" << ln;
            rep(i, 0, d)cout << 3 << ln;
            return 0;
        }
        deque<int> ans;
        findAnswer(ans, a, b, 0, 1);
        deque<int> ans2;
        findAnswer(ans2, c, d, 2, 3);
        dbg(a, d, ans.size(), ans2.size());
        //now a is zero and d is 0
        //ans = 0....1
        //ans1= 2....1
        //ans2= 2....3
        deque<int> ans1;
        findAnswer(ans1, c, b, 2, 1);
        dbg(ans.size(), ans1.size(), ans2.size(), a, b, c, d);
        if(a>1 || b>1 || c>1 || d>1)
        {
            cout << "NO" << ln;
            return 0;
        }
        //now a <=1 and b<=1 and c<=1 and d<=1
        if(a==1 and c==0 and b==0 and d==0)
        {
            if(ans1.size()==0 and ans2.size()==0)
            {
                ans.push_back(0);
                printAnswer(ans);
                return 0;
            }
            else
            {
                cout << "NO" << ln;
                return 0;
            }
        }
        if(d==1 and c==0 and a==0 and b==0)
        {
            if(ans1.size()==0 and ans.size()==0)
            {
                ans2.push_front(3);
                printAnswer(ans2);
                return 0;
            }
            else
            {
                cout << "NO" << ln;
                return 0;
            }
        }
        dbg(a, b, c, d);
        //ans = 0....1
        //ans1= 2....1
        //ans2= 2....3
        //now a = 0, d = 0;
        if(b==1 and ans.size())
        {
            ans.push_front(1);
            b--;
        }
        if(b==1 and ans.size()==0 and ans1.size())
        {
            ans1.push_front(1);
            b--;
        }
        if(b==1 and ans2.size() and ans1.size()==0)
        {
            ans2.push_front(1);
            b--;
        }
        if(c==1 and ans2.size())
        {
            ans2.pb(2);
            c--;
        }
        if(c==1 and ans1.size() and ans2.size()==0)
        {
            ans1.pb(2);
            c--;
        }
        if(c==1 and ans.size() and ans1.size()==0 and ans2.size()==0)
        {
            ans.push_back(2);
            c--;
        }
        if(!(a==0 and b==0 and c==0 and d==0))
        {
            cout << "NO" << ln;
            return 0;
        }
        cout << "YES" << ln;
        for(auto&i: ans)
        {
            cout << i << " ";
        }
        for(auto&i: ans1)
        {
            cout << i << " ";
        }
        for(auto&i: ans2)
        {
            cout << i << " ";
        }
        cout << ln;
	return 0;
}
