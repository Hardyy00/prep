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

unordered_map<char, pair<ll, ll>> mp = {
    {'D', {1, 0}},
    {'R', {0, 1}},
    {'L', {0, -1}},
    {'U', {-1, 0}},
};

vc dir = {'D', 'L' , 'R', 'U'};

ll dfs(ll idx, string &s, ll n, ll r, ll c){

	if(r < 0 || c< 0 || r>=7 || c>=7){
		return 0;
	}

	if(idx==s.size()){
		return r==6 && c==0;
	}

	if(s[idx] != '?'){
		return dfs(idx+1, s, n, r + mp[s[idx]].F , c + mp[s[idx]].S);
	}

	ll res = 0;

	REP(i,0,3){

		res += dfs(idx+1, s, n , r + mp[dir[i]].F , c + mp[dir[i]].S);
	}

	return res;

	
}

void solve() {

    string s;
    cin>> s;

	ll n= s.size();

	
    cout << dfs(0, s, n, 0, 0) << endl;;
}

int main() {


	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
		solve();
	



}