#include<stdio.h>
#include<math.h>

long A,B;
long bezout(long A,long B);
 int main()
 	{
 		A=9; B=0; bezout(A,B);A=13; B=17;bezout(A,B);
 		A=21; B=36; bezout(A,B);A=2145378312;
 		B=1256993; bezout(A,B);getchar();
 		return 0;
 	}
 	long a ,b ;
 	long bezout (long a, long b){
 		long d,q,r,x,x1,x2,y,y1,y2,tem;
	if(b==0){
		d = a; x =1; y =0;
	}
	else{
		x2 = 1; x1 = 0; y2 = 0; y1 = 1;
		while(b>0){
			q = a/b; r = a- b*q; x = x2-x1*q; y = y2-y1*q;
			a = b; b = r; x2=x1; x1= x; y2 =y1; y1= y;
		}
		d = a; x = x2; y =y2;
	}
	tem = A*x+ B*y-d;
	printf("\nA = %d \nB= %d \nd = %d \nx =%d \ny= %d \ntem = %d",A,B,d,x,y,tem);
	return (a,b);
 	}
 