#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>

char *nhiphan(int n){
	int i=0,j,k,x;
	char s[33],d[3]="01",tg;
	x=n;
	while(x!=0){
		k = x%2;
		s[i] = d[k];
		i++;
		x = x/2;
	}
	j = i;
	for(i=0; i<(j/2); i++){
		tg = s[i];
		s[i] = s[j-i-1];
		s[j-i-1] = tg;
	}
	s[j]=NULL;
	return &s[0];
}
int main(){
	unsigned long a,m,n,p=1;
	char s[50];
	printf("\nNhap a: ");
	scanf("%lu",&a);
	printf("\nNhap mod m = ");
	scanf("%lu",&m);
	printf("\nNhap mu n= ");
	scanf("%lu",&n);
	strcpy(s,nhiphan(n));
	for(int i=0; i<strlen(s); i++)
		if(s[i]=='0') p = (p*p)%m;
		else p = (((p*p)%m)*a)%m;
	printf("\np cuoi = %lu",p);
	getchar();
}







