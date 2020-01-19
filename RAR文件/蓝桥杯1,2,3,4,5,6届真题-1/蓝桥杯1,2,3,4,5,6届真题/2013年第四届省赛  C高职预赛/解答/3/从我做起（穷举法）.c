#include<stdio.h>
main()
{
	int a,b,c,d,e,f,g;
	int x=0,y=0;
	for(a=0;a<2;a++)
	{
		for(b=0;b<2;b++)
		{
			for(c=0;c<2;c++)
			{
				for(d=0;d<2;d++)
				{
					for(e=0;e<2;e++)
					{
						for(f=0;f<2;f++)
						{
							for(g=0;g<2;g++)
							{
									x=a+b+c+d+e+f+g;
									if(x==4)
									{
										y++;
										printf("%d %d %d %d %d %d %d\n",a,b,c,d,e,f,g);
									}
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n",y);
}
