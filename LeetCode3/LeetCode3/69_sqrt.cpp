



//NewTon's method,    I DON'T understand
int sqrt_Newton(int x) {
	long r = x;
	while (r*r > x)
		r = (r + x / r) / 2;
	return r;
}

// binary search
int sqrt_binary1(int x) {
	if (x == 0)
		return 0;
	int left = 1, right = x;
	while (true) {
		int mid = left + (right - left) / 2;
		if (mid > x / mid) {
			right = mid - 1;
		}
		else {
			//???
			if (mid + 1 > x / (mid + 1))
				return mid;
			left = mid + 1;
		}
	}
}

int sqrt_binary2(int x) {
	if (0 == x) return 0;
	int left = 1, right = x, ans;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (mid <= x / mid) {
			left = mid + 1;
			ans = mid;
		}
		else {
			right = mid - 1;
		}
	}
	return ans;
}

