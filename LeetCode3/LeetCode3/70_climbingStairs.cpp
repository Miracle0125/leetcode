

//����˼�������һ����һ�����������������������Ӿ���
int climbStairs(int n) {
	if (n <= 0) return 0;
	if (n == 1 || n == 2) return n;
	int one_step_before = 2, two_step_before = 1, all = 0;
	for (int i = 2; i < n; i++)
	{
		all = one_step_before + two_step_before;
		two_step_before = one_step_before;
		one_step_before = all;
	}
	return all;
}



//�Լ�д�ģ���ʱ̫��....
int climbStairs2(int n) {
	if (n <= 0) return 0;
	if (n == 1 || n == 2) return n;
	return climbStairs2(n - 1) + climbStairs2(n - 2);
}