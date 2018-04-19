

void quick_sort(int s[], int l, int r)
{
	//	int s[] = {2,6,1,7,1,13,18,6,14,3,9,9,5,4,16 };
	//	int s[] = {1,6,1,7,2,13,18,6,14,3,9,9,5,4,16 };
	//	int s[] = {1,1,2,7,6,13,18,6,14,3,9,9,5,4,16 };
	if (l < r)
	{
		//Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1  
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数  
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数  
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i - 1); // 递归调用   
		quick_sort(s, i + 1, r);
	}
}

//int main() {
//	int s[] = {2,6,1,7,1,13,18,6,14,3,9,9,5,4,16 };
//	quick_sort(s,0,sizeof(s)/4 -1);
//	return 1;
//}