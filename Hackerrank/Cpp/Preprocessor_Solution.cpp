#define INF 100000005
#define foreach(v, i) for (int i = 0; i < n; i++)
#define io(v) cin >> v
#define toStr(x) #x
#define minimum(a, b) a = min(a, b)
#define maximum(a, b) a = max(a, b)
#define FUNCTION(it_is, useless)

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}