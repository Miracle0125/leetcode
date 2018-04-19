

bool isPowerOfTwo(int n) {
	if (n <= 0) return false;
	while (n) {
		if (n & 1&&n>1) return false;
		n >>= 1;
	}
	return true;
}

//trick
bool isPowerOfTwo2(int n) {
	if (n <= 0) return false;
	return !(n&(n - 1));
}