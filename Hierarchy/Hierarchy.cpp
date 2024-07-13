#include <bits/stdc++.h>
#define endll "\n"
#define ll long long
using namespace std;
const ll mx = 1e3 + 123;
vector<ll> parent(mx), sz(mx);
ll Find(ll u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = Find(parent[u]);
}
void Union(ll u, ll v)
{
    ll a = Find(u);
    ll b = Find(v);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, i;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    vector<ll> qua(n);
    for (auto &it : qua)
        cin >> it;
    cin >> m;
    vector<pair<ll, pair<ll, ll>>> edges;
    while (m--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        edges.push_back({z, {x, y}});
    }
    sort(edges.begin(), edges.end());
    ll cost = 0;
    for (auto it : edges)
    {
        ll u = it.second.first;
        ll v = it.second.second;
        ll w = it.first;
        if (Find(u) == Find(v))
            continue;
        if (Find(v) == v and qua[u - 1] > qua[v - 1])
        {
            cost += w;
            Union(u, v);
        }
    }
    ll cnt = 0;
    for (i = 1; i <= n; i++)
    {
        if (Find(i) == i)
            cnt++;
        if (cnt > 1)
            return cout << -1 << endll, 0;
    }
    cout << cost << endll;
}