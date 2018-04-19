

void quick_sort(int s[], int l, int r)
{
	//	int s[] = {2,6,1,7,1,13,18,6,14,3,9,9,5,4,16 };
	//	int s[] = {1,6,1,7,2,13,18,6,14,3,9,9,5,4,16 };
	//	int s[] = {1,1,2,7,6,13,18,6,14,3,9,9,5,4,16 };
	if (l < r)
	{
		//Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1  
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����  
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����  
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i - 1); // �ݹ����   
		quick_sort(s, i + 1, r);
	}
}

//int main() {
//	int s[] = {2,6,1,7,1,13,18,6,14,3,9,9,5,4,16 };
//	quick_sort(s,0,sizeof(s)/4 -1);
//	return 1;
//}