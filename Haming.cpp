// Haming ”‚ğ‹‚ß‚é
const int N = 1500;
void haming(long t[N])
{
	int p=0, q=0, r=0, s=1;

	t[0] = 1;
	while (s < N) {
		long x = 2 * t[p];
		if (3*t[q] < x) x = 3*t[q];
		if (5*t[r] < x) x = 5*t[r];
		t[s] = x;
		s++;
		if (x == 2*t[p]) p++;
		if (x == 3*t[q]) q++;
		if (x == 5*t[r]) r++;
	}
}
