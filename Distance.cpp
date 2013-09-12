

// 射影を求める
P projection(const Line &l, const P &p)
{
	double t = dot(p-l.p1, l.p1-l.p2) / norm(l.p1-l.p2);
	return l.p1 + t*(l.p1-l.p2);
}

// 点aと点bとの距離
double distPP(const P &a, const P &b)
{
  return abs(b-a);
}

// 直線と点の距離
// test@10709
double distLP(const Line &l, const P &p)
{
	return abs(p - projection(l, p));
}

// 線分と点の距離
// test@10709
double distSP(const Segment &s, const P &p)
{
	const P r = projection(s, p);
	if (intersectSP(s, r)) return abs(r - p);
	return (min(abs(s.p1-p), abs(s.p2-p)));
}

// 線分と線分の距離
// test@10709
double distSS(const Segment &s, const Segment &t)
{
	if (intersectSS(s, t)) return 0;
	return min(min(distSP(s, t.p1), distSP(s, t.p2)),
		min(distSP(t, s.p1), distSP(t, s.p2)));
}

// 直線と線分
// test@10709
double distLS(const Line &l, const Segment &s)
{
	if (intersectLS(l, s)) return 0;
	return min(distLP(l, s.p1), distLP(l, s.p2));
}

// 直線と直線の距離
// test@10709
double distLL(const Line &a, const Line &b)
{
	return (intersectLL(a, b) ? 0 : distLP(a, b.p1));
}
