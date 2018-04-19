



using namespace std;

int countDigitOne(int n) {
	if (n <= 0) return 0;
	int ret = 0;
	for (long long digit = 1; digit <= n; digit *= 10)
	{
		int left = n / digit;
		ret += (left + 8) / 10 * digit + (left % 10 == 1)*(n%digit + 1);
	}
	return ret;
}

//int main(){
//	int ret=countDigitOne(100);
//	return 0;
//}

//string s = stringstream(n).str();
//for


//if (n <= 0) return 0;
//if (n <= 10) return n == 10 ? 2 : 1;
//long int a = 1, b = 10;
//int ret = 2;
//while (n >= b) {
//	ret += n / b - (n%b < a ? 1 : 0) + 1;
//	a *= 10;
//	b *= 10;
//}
//return ret;