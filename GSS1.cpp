#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(),a.end()
#define pb push_back
#define pp pop_back
#define MP make_pair
#define fs first
#define sc second

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,int> pli;
typedef pair<int,int> ii;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int row[] = { -1,0,1,0};
int col[] = { 0,1,0,-1};
int mod = 1e9+7;
int mod1 = 998244353;
const ll ninf = -1*1e18;
const ll pinf = 1e18;

// maximum subarray sum using segment tree 
// empty subarray is not possible

const int maxn = 5e4 + 10;
struct node{
	ll sum,pref,suff,ans;
};

node t[4*maxn];
ll a[maxn];

node combine(node left_node,node right_node)
{
	node curr;
	curr.sum = left_node.sum + right_node.sum;
	curr.pref = max(left_node.pref,left_node.sum + right_node.pref);
	curr.suff = max(right_node.suff,right_node.sum + left_node.suff);
	curr.ans = max(max(left_node.ans,right_node.ans),left_node.suff+right_node.pref);
	return curr; 
}

void build(int nd,int l,int r)
{
	if(l==r)
	{
		t[nd].sum = a[l];
		t[nd].pref = a[l];
		t[nd].suff = a[l];
		t[nd].ans = a[l];
		return;
	}

	int mid = l + (r-l)/2;
	build(2*nd+1,l,mid);
	build(2*nd+2,mid+1,r);
	t[nd] = combine(t[2*nd+1],t[2*nd+2]);
}

node query(int nd,int l,int r,int tl,int tr)
{
	if(l>tr||r<tl)
	{
		node res;
		res.sum = 0;
		res.pref = INT_MIN; // empty subarray is not possible
		res.suff = INT_MIN; // empty subarray is not possible
		res.ans = INT_MIN; // empty subarray is not possible
		return res;
	}

	if(l>=tl&&r<=tr)
	{
		return t[nd];
	}

	int mid = l + (r-l)/2;
	return combine(query(2*nd+1,l,mid,tl,tr),query(2*nd+2,mid+1,r,tl,tr));
}

void solveTestCase()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	build(0,0,n-1);
	int m;
	cin>>m;
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		l--;
		r--;
		node res = query(0,0,n-1,l,r);
		cout << max(res.sum,res.ans) << "\n";
	}
}

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif

	#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << setprecision(9);
	cout << fixed;

	int testcases;
	//cin>>testcases;

	testcases = 1;
	
	while(testcases--)
		solveTestCase();

	return 0;
}
