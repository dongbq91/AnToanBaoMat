#include <stdio.h>
#include <conio.h>
#include <string.h>

int a=17,b=5;
char xaumh[100]= "TAURUS";
//void nhapdl(){
//	printf("Nhap xau ma hoa: ");
//	gets(xaumh);
//	printf("\nNhap xau giai ma: ");
//	gets(xaugm);
//	printf("\nNhap khoa a: ");
//	scanf("%d",&a);
//	printf("\nNhap khoa b: ");
//	scanf("%d",&b);
//	xaumh[strlen(xaumh)] = NULL;
//	xaugm[strlen(xaugm)] = NULL;
//	printf("\nDu lieu nhap vao: \nxaumh: %s \nxaugm: %s \nk= %d",xaumh, xaugm,a,b);
//}
char *mahoa(){
	char s[100];
	int n = strlen(xaumh);
	for(int i = 0; i<n;i++)
		s[i] = 65 + (a*(xaumh[i]-65)+b)%26;
	s[n] = NULL;
	return &s[0];
}
int timsonghichdao(){
	int r,q,y,y0=0,y1=1,tga,m=26;
	while(a>0){
		r = m%a;
		if(r==0) break;
		q = m/a;
		y = y0-y1*q;
		m=a;
		a=r;
		y0=y1;
		y1=y;
	}
	if(a>1) return -1;
	else if(y>0) return y;
	else return y+26;
}

int main(){
	char s[100];
	printf("Nhap chuoi can so sanh: ");
	gets(s);
	char mh[100],gm[100];
	strcpy(mh,mahoa());

	if(strcmp(mh,s)==0){
		printf("Dung");
	}else{
		printf("sai");
	}
	printf("\nKhoa k(a^-1,b) = (%d,%d)",timsonghichdao(),b);
}
