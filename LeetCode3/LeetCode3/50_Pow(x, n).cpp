
//return myPow(1 / x, -n);   这么写需要考虑INT_MAX
double myPow(double x, int n) {
	if (n == 0) return 1;
	if (n < 0) return myPow(1 / x, -(n + 1))/x;
	return (n % 2 == 0) ? myPow(x*x, n / 2) : myPow(x*x, n / 2)*x;
}