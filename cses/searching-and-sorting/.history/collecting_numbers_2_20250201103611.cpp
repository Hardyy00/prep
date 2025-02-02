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
typedef vector<char> vc;


const ll MOD = 1e9 + 7;

void print_map(mll &map) {

	cout << "{ ";
	fauto(i, map) {

		cout << "{ " << i.F << " : " << i.S << " }, ";
	}

	cout << " }" << endl;
}

void print_vector(vl &v) {

	cout << "{ ";

	fauto(i, v) cout << i << ", ";

	cout << " }" << endl;
}

void print_set(sll &s) {

	cout << "{ " ;

	fauto(i, s) cout << i << ", ";

	cout << " } " << endl;
}


void swap(vpll &v, ll p1, ll p2){

    ll temp = v[p1].S;
    v[p1].S = v[p2].S;
    v[p2].S = temp;
}

ll check(ll i, vl &flags, vpll &v, ll cn){

    if(i == v.size()){
        return cn;
    }

    if(i-1<0){
        return cn;
    }

    if(v[i].S > v[i-1].S && flags[i]){

        flags[i] = 0;
        cn--;
    }

    if(v[i].S < v[i-1].S && !flags[i]){
        flags[i] = 1;
        cn++;
    }

    return cn;



    
}

void solve() {

    ll n, m;
    cin >> n >> m;

    vpll v(n);

    mll mp;
    
    REP(i,0,n-1){

        ll val;
        cin >> val;

        val--;

        v[i] = {val, i};

        mp[i] = val;
    }

    sort(all(v));

    
    vl flags(n,0);

    ll cn = 1;

    REP(i,1,n-1){

        if(v[i].S < v[i-1].S){
            cn++;
            flags[i] = 1;
        }
    }


    REP(i,0,m-1){

        ll p1 , p2;
        cin >> p1 >> p2;
        --p1;
        --p2;

        ll v1= mp[p1], v2 = mp[p2];

        ll temp = mp[p1];
        mp[p1] = mp[p2];
        mp[p2] = temp;

        swap(v, v1,v2);

        cn = check(v1, flags, v, cn);
        cn = check(v1+1, flags, v, cn);
        cn = check(v2, flags, v, cn);
        cn = check(v2+1, flags, v, cn);

        cout << cn << endl;
    }



}

int main() {


	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
		solve();
	



}