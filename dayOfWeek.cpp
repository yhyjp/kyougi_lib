
// 0 : “ú—j“ú
int dayOfWeek(int y, int m, int d)
{
	if (m==1 || m==2) {
		--y;
		m += 12;
	}
	return (y + y/4 - y/100 + y/400 + (13*m+8)/5+d) % 7;
}
