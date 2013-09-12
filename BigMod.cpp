typedef long long ll;
ll f(ll b, ll p, ll m)
{
	if (p==0) return 1;

	if (p % 2) {
		ll t = f(b, p/2, m) % m;
		return ((t*t)%m * b)%m;
	}
	else {
		ll t = f(b, p/2, m) % m;
		return (t*t)%m;
	}
}
