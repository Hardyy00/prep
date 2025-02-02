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


void solve() {

    string s;
    cin >> s;

    vl fre(26 , 0);
    
    ll n= s.size();

    for(int i=0;i<n;i++){
        fre[s[i]-'A']++;
    }

    ll odd = 0;
    REP(i,0,25){
        
        if(fre[i] &1){
            odd++;
        }
    }

    if((n % 2 ==0 && odd >0 ) || (n %2  && odd != 1) ){
        cout << "NO SOLUTION" << endl;
        return;
    }

    ll i = 0, j=n-1;
    string ans(n, '*');

    ll val = 0;

    REP(k,0,25){

        while(fre[k] > 0 &&  fre[k] >=2) {
            ans[i++] = (char) (k + 65);
            fre[k]--;
            ans[j--] = (char) (k + 65);
            

            fre[k]--;
            
        }
    }

    REP(k, 0 , 25){

        if(fre[k] &1){
            val = k;
            break;
        
        }
    }

    if(n & 1){
        ans[n/2] = (char)(65 + val);
    }



    cout << ans << endl;




}

int main() {


	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
		solve();
	



}