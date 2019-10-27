#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

#define ll long long

using namespace std;



class comp {
public:
	bool operator() (tuple<ll,ll> t1, tuple<ll,ll> t2)
	{
		return ((get<0>(t1))*(get<1>(t1)) <  (get<0>(t2))*(get<1>(t2)));
	}
};

class hmappy {
private:
	priority_queue<tuple<ll,ll>,vector<tuple<ll,ll>>, comp > bal_can_list;
	int no_ballon, size;
	
public:
	hmappy (ll n, ll m) {
		no_ballon = m;
		size = n;
	}
	void addElement (int a, int b) {
		tuple <ll,ll> temp = make_tuple (a,b);
		bal_can_list.push(temp);
	}
	ll findMinMax () {
		tuple <ll, ll> temp, temp1;
		int s , b, t;
		for(ll i = 0; i < no_ballon ; ++i) {
			temp = bal_can_list.top();
			bal_can_list.pop();
			temp1 = bal_can_list.top();
			b =  get<0>(temp1)* get<1>(temp1);
			s = get<0>(temp);
			t = get<1>(temp);	
			while(b <= s*t  && i < no_ballon) {
				--s;
				++i;
			}
			--i;
			get<0>(temp) = s;
			bal_can_list.push(temp);
		}
		temp = (bal_can_list.top());
		ll res = get<0>(temp)* get<1>(temp);
		return res;
	}
};

int main () {
	ll N, M, counter, a,sum=0;
	cin >> N >> M;
	int b[N];
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	hmappy *h = new hmappy(N,M);
	for(counter = 0 ; counter < N ; ++counter) {
		cin >> b[counter];
		sum+=b[counter];
	}
	if(sum <= M) {
		cout << "0" << endl;
	}
	else {
		for(counter = 0 ; counter < N ; ++counter) {
			cin >> a;
			h->addElement(b[counter],a);
		}
		cout << h->findMinMax() << endl;
	}
	return 0;
}
