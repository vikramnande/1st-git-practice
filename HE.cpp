#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define mp make_pair

ll root(ll x,vector<ll> &id)
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		x=id[x];
	}

	return x;
}

void unin(ll x,ll y,vector<ll> &id)
{
	int p=root(x,id);
	int q=root(y,id);
	id[p]=id[q];
}

ll krushkals(vector<pair<ll,pair<ll,ll> > > &vec,vector<ll> &id)
{
	ll u,v,w;

	ll mincost=0;
	for(ll i=0;i<vec.size();i++)
	{
		u=vec[i].second.first;
		v=vec[i].second.second;
		w=vec[i].first;
		if(root(u,id)!=root(v,id))
		{
			unin(u,v,id);
			mincost+=w;
		}
	}

	return mincost;
}

int main()
{
	ll n,m,a,b,c;
	cin>>n>>m;
	vector<pair<ll,pair<ll,ll> > > vec;
	for(ll i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		vec.pb(mp(c,mp(a-1,b-1)));
	}
	sort(vec.begin(),vec.end());
	vector<ll> id(n,0);
	for(ll i=0;i<n;i++)
		id[i]=i;

	ll mincost=krushkals(vec,id);

	cout<<mincost<<endl;
	return 0;
}
