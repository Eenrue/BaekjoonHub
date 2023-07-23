#include <stdio.h>
int main(void)
{
	int kilo;
	int num=0;
	scanf("%d",&kilo);
	if(kilo%3==0)
	{
		num=kilo/3;
	}
	int i;
	int k;
	k=kilo/5;
	for(i=1;i<=k;i++)
	{
		int res=0;
		res+=i;
		kilo-=5;
		if(kilo%3==0)
		{
			res+=kilo/3;
			num=res;
		}
	}
	if(num==0)
	{
		printf("-1");
		return 0;
	}
	printf("%d",num);
}