#include "ft_printf.h"
#include <stdio.h>
int 				main()
{
	int t;
	int n;
	int s;
	int p;
	char *tab1[] = {"d\t|%d|","0d\t|%0d|","5d\t|%5d|","10d\t|%10d|","5.0d\t|%5.0d|","10.0d\t|%10.0d|","5.5d\t|%5.5d|","10.5d\t|%10.5d|","5.10d\t|%5.10d|","10.10d\t|%10.10d|",".0d\t|%.0d|",".5d\t|%.5d|",".10d\t|%.10d|",
	"-d\t|%-d|","-0d\t|%-0d|","-5d\t|%-5d|","-10d\t|%-10d|","-0.0d\t|%-0.0d|","-5.0d\t|%-5.0d|","-10.0d\t|%-10.0d|","-0.5d\t|%-0.5d|","-5.5d\t|%-5.5d|","-10.5d\t|%-10.5d|","-0.10d\t|%-0.10d|","-5.10d\t|%-5.10d|","-10.10d\t|%-10.10d|","-.0d\t|%-.0d|","-.5d\t|%-.5d|","-.10d\t|%-.10d|",".d\t%d\t|%.d|","-.d\t%d\t|%-.d|",0};
	char *tab2[] = {"*0-d\t%d\t|%0-*d|",0};//"*d\t%d\t|%*d|","-*d\t%d\t|%-*d|","0*d\t%d\t|%0*d|"
	char *tab3[] = {"0-*.*d\t%d.%d\t|%0-*.*d|","*.*d\t%d.%d\t|%*.*d|","-*.*d\t%d.%d\t|%-*.*d|","0*.*d\t%d.%d\t|%0*.*d|",0};//*.*d\t%d.%d\t|%*.*d|","-*.*d\t%d.%d\t|%-*.*d|","0*.*d\t%d.%d\t|%0*.*d|",
	int arg[] = {0,77,777777,-77,-777777,99};
	int space[] = {0,5,20,-5,-20,99};
	int precision[] = {0,5,20,-20,99};
	int r1;
	int r2;

	t = -1;
	while (tab1[++t])
	{
		n = -1;
		while (arg[++n] != 99)
		{
			r1 = printf(tab1[t], arg[n]);
			printf("\n");
			// // r2 = ft_printf(tab1[t], arg[n]);
			// printf("\n");
			// if (r1 != r2)
			// 	printf("\n\nERROR\n\n");
		}
	}


	printf("================================================================\n");
	t = -1;
	while (tab2[++t])
	{
		n = -1;
		while (arg[++n] != 99)
		{
			printf("d = %d\n",arg[n]);
			s = -1;
			while (space[++s] != 99)
			{
				r1 = printf(tab2[t],space[s],space[s],arg[n]);
				printf("\n");
				// r2 = ft_printf(tab2[t],space[s],space[s],arg[n]);
				// printf("\n");
				// if (r1 != r2)
				// 	printf("\nERROR\n\n");
			}
		}
	}


	printf("================================================================\n");
	t = -1;
	while (tab3[++t])
	{
		n = -1;
		while (arg[++n] != 99)
		{
			printf("d = %d\n", arg[n]);
			s = -1;
			while (space[++s] != 99)
			{
				p = -1;
				while (precision[++p] != 99)
				{
					r1 = printf(tab3[t], space[s], precision[p], space[s], precision[p], arg[n]);
					printf("\n");
					// r2 = ft_printf(tab3[t], space[s], precision[p], space[s], precision[p], arg[n]);
					// printf("\n");

					// if (r1 != r2)
					// 	printf("\nERROR ERROR r1 = %d r2 = %d\n", r1, r2);
				}
			}
		}
	}
	printf("%.d\n", 23);

	return (0);
}