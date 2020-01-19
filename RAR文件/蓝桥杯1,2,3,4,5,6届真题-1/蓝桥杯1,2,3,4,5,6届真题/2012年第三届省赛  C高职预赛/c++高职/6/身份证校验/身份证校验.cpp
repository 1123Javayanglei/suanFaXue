// ���֤У��.cpp : Defines the entry point for the console application.
//

/*
  ���������Ƹ�������ʲô�����������֤�����أ������������𣿲����ԣ�
  ��Ϊ���˵����֤���һλ��"X"
  ʵ���ϣ��������һλ��X���������������ĸ��

  ���֤����18λ = 17λ + У����

  У����ļ�����̣�

  ���磺���֤ǰ17λ = ABCDEFGHIJKLMNOPQ
  
  A~Q ÿλ���ֳ���Ȩֵ��� 17λ��Ӧ��Ȩֵ�ֱ��ǣ�

  7 9 10 5 8 4 2 1 6 3 7 9 10 5 8 4 2

  ������ֶ�11��ģ

  Ȼ���±�ӳ�䣺

  ����     0   1   2   3   4   5   6   7   8   9   10 
  У���룺 1   0   X   9   8   7   6   5   4   3   2 

*/


#include "stdafx.h"
#include "math.h"

char verifyCode(char* s)
{
	static int weight[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	static char map[] = {'1','0','X','9','8','7','6','5','4','3','2'};

	int sum = 0;
	for(int i=0; i<17; i++)
	{
		sum += (s[i] - '0') * weight[i];  // ���
	}

	//return map[sum % 11];  // ���
	return map[fmod(sum,11)];
}

int main(int argc, char* argv[])
{
	printf("%c\n", verifyCode("32011119610215381"));
	printf("%c\n", verifyCode("42900819801018236"));
	return 0;
}

