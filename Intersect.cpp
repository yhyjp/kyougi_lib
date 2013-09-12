
// 線分sとtの交差判定
// test@10709
bool intersectSS(const Segment &s, const Segment &t)
{
	return (
		ccw(s.p1,s.p2,t.p1)*ccw(s.p1,s.p2,t.p2) <= 0 &&
		ccw(t.p1,t.p2,s.p1)*ccw(t.p1,t.p2,s.p2) <= 0
	);
}

// 直線同士の当たり判定
// test@10709
bool intersectLL(const Line &a, const Line &b)
{
	return (abs(cross(a.p2-a.p1, b.p2-b.p1)) > EPS // non-parallel
		|| abs(cross(a.p2-a.p1, b.p1-a.p1)) < EPS); // same line
}

// 直線と線分の当たり判定
// test@10709
bool intersectLS(const Line &l, const Segment &s)
{
	return (cross(l.p2-l.p1, s.p1-l.p1) *  // s.p1とs.p2のいる位置が逆かどうか
		cross (l.p2-l.p1, s.p2-l.p2) < EPS);
}

// 線分s上にpがあるか(点上を含む)
// test@10709
bool intersectSP(const Segment &s, const P &p)
{
	double d = abs(s.p1-p)+abs(s.p2-p);
	double t = abs(s.p2-s.p1);
	return d-t<EPS;
}

// 誤差に強い
inline bool intersectSP(const Segment &s, const P &p)
{
	const P a = p-s.p1;
	const P b = s.p2-p;
	const P c = s.p2-s.p1;
    return EQ(arg(a/c),0) && EQ(arg(b/c),0);
}


// 点cが直線a,b上にあるかないか
int intersectLP(const Line &l, const P &p)
{
  return EQ(cross(l.p2-l.p1, p-l.p1), 0.0);
}


/*
// 交差する線の交差位置を調べる
// test@uva378
P crossPointL(const Line &a, const Line &b)
{
  double ca = cross(a.p2 - a.p1, b.p2 - b.p1);
  double cb = cross(a.p2 - a.p1, a.p2 - b.p1);
  if (abs(ca) < EPS && abs(cb) < EPS) return b.p1; // same line
  //if (abs(ca) < EPS) assert(false);
  return b.p1 + cb/ca * (b.p2-b.p1);
}
*/

// 直線同士の交差位置
// test@uva438
P crossPointL(const Line &l1, const Line &l2)
{
	P a = l1.p2-l1.p1;
	P b = l2.p2-l2.p1;
	return (l1.p1+a*cross(b, l2.p1-l1.p1)/cross(b,a));
}

// 線分の交差位置
// 未テスト
P crossPointS(const Segment &s1, const Segment &s2)
{
	P b = s2.p2-s2.p1;
	double d1 = abs(cross(b, s1.p1-s2.p1));
	double d2 = abs(cross(b, s1.p2-s2.p1));
	double t = d1 / (d1+d2);
	return s1.p1 + (s1.p2-s1.p1)*t;
}
