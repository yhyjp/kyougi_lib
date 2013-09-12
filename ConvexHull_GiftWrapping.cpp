// Gift-Wrapping ‚Å“Ê•ï‚ğ‹‚ß‚é
// test@10065
void convexHull(const vector<P> &pt, vector<P> &result)
{
	int st = 0;
	for (int i=0; i < pt.size(); ++i) {
		if (pt[st].imag() >= pt[i].imag()) {
			if (pt[st].imag()==pt[i].imag() && pt[st].real() <= pt[i].real()) continue;
			st = i;
		}
	}
	int now = st;
	P prev = P(pt[st].real()-1, pt[st].imag());
	do {
		result.push_back(pt[now]);
		int min_index = -1;
		double min_arg = PI * 10;
		for (int i=0; i < pt.size(); ++i) {
			if (i==now || pt[i]==prev) continue;
			P p = (pt[i]-pt[now]) / (pt[now] - prev);
			double angle = arg(p);

			if (angle+EPS >= 0 && angle+EPS < min_arg) {
				min_arg = angle;
				min_index = i;
			}
			else if (EQ(angle, min_arg)) {
				// “¯‚¶Šp“x‚È‚ç‹——£‚ª‰“‚¢•û‚ğ‘I‚Ô
				if (abs(pt[min_index]-pt[now]) < abs(pt[i]-pt[now])) {
					min_index = i;
				}
			}
		}
		prev = pt[now];
		now = min_index;
	} while (now!=st);
}
