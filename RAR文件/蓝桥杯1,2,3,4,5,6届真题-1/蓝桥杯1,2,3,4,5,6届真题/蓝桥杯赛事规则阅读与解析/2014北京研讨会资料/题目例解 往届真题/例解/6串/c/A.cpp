
// c��û�����飬����ı���Ҳ�Ǹ��������ڴ��ַ�� 
// ��νc�Ĵ����ʾ��Ǹ����� ���ڴ��ַ�� 
// ���ջ 

#include <stdio.h>

int main()
{
	char const * a = "abcd";
	char const * a2 = "abcd";
	
	char b[] = "abcd";
	char c[] = "xyz";
	//b[-1] = '*';
	*(b-1) = '*';
	
	printf("%s\n", c);
	
	/*
	printf("%d\n", a);
	printf("%d\n", a2);
	printf("%d\n", b);
	printf("%d\n", c);
	*/
	
	return 0;
}
