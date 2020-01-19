
#include <stdio.h>
#include <time.h>

int main()
{
	// ��ǰʱ�� 
	time_t t = time(NULL);
	printf("time: %d\n", t);
	
	struct tm*  t1 = gmtime(&t);
	printf("%d %d %d %d:%d:%d\n", t1->tm_year+1900, t1->tm_mon+1, t1->tm_mday,
				t1->tm_hour, t1->tm_min, t1->tm_sec);
				
	struct tm*  t2 = localtime(&t);
	printf("%d %d %d %d:%d:%d\n", t2->tm_year+1900, t2->tm_mon+1, t2->tm_mday,
				t2->tm_hour, t2->tm_min, t2->tm_sec);

	// ����ʱ��� 1997��7��1�� �� �����ȥ�˶����죿 
	struct tm tm1;
	tm1.tm_year = 1997 - 1900;
	tm1.tm_mon = 7 - 1;
	tm1.tm_mday = 1;
	tm1.tm_hour = 12;
	tm1.tm_min = 0;
	tm1.tm_sec = 0;
	int delta = (time(NULL) - mktime(&tm1))/(24*60*60);
	printf("delta= %d\n", delta);
	
 	// �������ڼ�
	printf("%d\n", tm1.tm_wday); 

	return 0;
}
