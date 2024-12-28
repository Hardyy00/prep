#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for(long long i=a;i<=b;i++)
#define all(a) (a).begin(), (a).end()
#define fauto(i,v) for(auto i : (v))
#define REPD(i,a,b) for(long long i=a;i>=b;i--)
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_multiset tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>


typedef long long ll;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<long long>> vvll;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
typedef pair<long long , long long> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef map<long long, long long> mll;
typedef unordered_map<long long, long long> umll;
typedef set<long long> sll;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef unordered_set<long long> usll;
typedef stack<int> sti;
typedef stack<long long> stll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<long long, long long>> vpll;
typedef priority_queue<int> pqi;
typedef priority_queue<pair<int, int>> pqpii;

const ll MOD = 1e9 + 7;

void print_map(mll &map) {

	cout << "{ ";
	fauto(i, map) {

		cout << "{ " << i.F << " : " << i.S << " }, ";
	}

	cout << " }" << endl;
}

void print_vector(vc &v) {

	cout << "{ ";

	fauto(i, v) cout << i << ", ";

	cout << " }" << endl;
}

void print_set(sll &s) {

	cout << "{ " ;

	fauto(i, s) cout << i << ", ";

	cout << " } " << endl;
}

map<char, pair<ll, ll>> mp = {
    {'D', {1, 0}},
    {'R', {0, 1}},
    {'L', {0, -1}},
    {'U', {-1, 0}},
};

bool check(vc &s){


    ll r = 0, c =0;
	ll n= s.size();

    REP(i,0,n-1){

		pll p = mp[s[i]];

		r += p.F;
		c += p.S;

		if(r>=7 || r<0 || c>=7 || c<0){
			return false;
		}
        
    }

	return r==6 && c==0;
}


ll dfs(ll idx, vc &s, ll n){

	if(idx == n){
		print_vector(s);
		exit(1);
		return check(s);

	}

	if(s[idx] != '?' ){
		return dfs(idx+1, s, n);
	}

	vc dir = {'D','L' ,'R', 'U'};
	ll res = 0;

	REP(i,0,3){
		s[idx] = dir[i];
		res += dfs(idx+1, s, n);
		s[idx] = '?';

	}
	return res;
}

void solve() {

    string s;
    cin>> s;

	ll n= s.size();

	vc v(n);

	REP(i,0,n-1){
		v[i] = s[i];
	}

    cout << dfs(0, v, n) << endl;;
}

int main() {


	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
		solve();
	



}