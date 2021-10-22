#include<stdio.h>
#include<conio.h>
#include<string.h>
int k;
char xaumh[100],xaugm[100];
void nhapdl(){
	printf("Nhap chuoi can ma hoa: ");
	gets(xaumh);
	printf("\nNhap chuoi can giai ma: ");
	gets(xaugm);
	printf("\nNhap khoa k: ");
	scanf("%d",&k);
	xaumh[strlen(xaumh)] = NULL;
	xaugm[strlen(xaugm)] = NULL;
	
}
char *mahoa(){
	char s[100];
	int n = strlen(xaumh);
	for(int i=0; i<n; i++)
		s[i] = 65+ (xaumh[i]+k-65)%26;
	s[n] = NULL;
	return &s[0];
}
char *giaima(){
	char s[100];
	int n= strlen(xaugm);
	for(int i=0; i<n; i++)
		s[i] = 65 +(xaugm[i]-k-65+26)%26;
	s[n] = NULL;
	return &s[0];
}
int main(){
	nhapdl();
	char mh[100], gm[100];
	strcpy(mh,mahoa());
	strcpy(gm,giaima());
	printf("\n%s ma hoa duoc %s",xaumh,mh);
	printf("\n%s giai ma duoc %s",xaugm, gm);
	getch();
}
