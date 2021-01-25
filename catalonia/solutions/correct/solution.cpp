#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

pll convert(ll i) {
	ll k, l = 0, r = 1e5;

	while(l != r) {
		ll m = (l+r)/2;

		if(3*m*(m+1) >= i) r = m;
		else l = m+1;
	} 

	k = l;
	if(k == 0) return {0, 0};

	pll pos = {1, 2*k-1};

	i -= 3*k*(k-1)+1;

	{
		pll d = {1, -1}; 

		ll a = min(i, k-1);

		pos.first += d.first*a;
		pos.second += d.second*a;

		i -= a;
		if(i == 0) return pos;
	}


	for(pll d : vector<pll>({{0, -2}, {-1, -1}, {-1, 1}, {0, 2}, {1, 1}}) ) {
		
		ll a = min(i, k);

		pos.first += d.first*a;
		pos.second += d.second*a;	

		i -= a;
		if(i == 0) return pos;
	}
	
	return pos;
}

ll dist(pll p1, pll p2) {
	pll d = {p1.first - p2.first, p1.second - p2.second};

	return abs(d.first) + max(0LL, (abs(d.second) - abs(d.first))/2 );
}

ll level(pll p) {
	return dist({0, 0}, p);
}

ll convert_back(pll p) {

	if(p == pll({0, 0})) return 0;

	ll k = level(p), i = 3*k*(k-1)+1;
	pll pos = {1, 2*k-1};

	{
		pll d = {1, -1}; 

		ll a = (p.second - pos.second)/d.second;

		if(a >= 0 && pos.first + a*d.first == p.first) {
			i += a;
			return i;
		}
		else {
			i += k-1;
			pos.first += (k-1)*d.first;
			pos.second += (k-1)*d.second;
		}
	}


	for(pll d : vector<pll>({{0, -2}, {-1, -1}, {-1, 1}, {0, 2}, {1, 1}}) ) {
		
		ll a = (p.second - pos.second)/d.second;

		if(a >= 0 && pos.first + a*d.first == p.first) {
			i += a;
			return i;
		}
		else {
			i += k;
			pos.first += k*d.first;
			pos.second += k*d.second;
		}
	}
	
	return i;
}

int main() {

	ll a, b;
	cin >> a >> b;

	pll pa = convert(a), pb = convert(b);

	cout << dist(pa, pb) << '\n';

	return 0;
}