// ��֧���귨.cpp : Defines the entry point for the console application.
//


/*
  ʮ��ɣ�ʮ����֧
  60��һ����ѭ��


*/


#include "stdafx.h"

void f(int year)
{
	char* x[] = {"��","��","��","��","��","��","��","��","��","��"};
	char* y[] = {"��","��","��","î","��","��","��","δ","��","��","��","��"};
	
	int n = year - 1984;
	while(n<0) n += 60;
	printf("%s%s\n", x[n%10], y[n%12]);  // ���1��2
}

int main(int argc, char* argv[])
{
	f(1911);
	f(1970);
	f(2012);
	return 0;
}

