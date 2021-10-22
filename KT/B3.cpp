#include <stdio.h>
#include <conio.h>
#include <string.h>

int n = 2,khoa[50][50]={{12,5},{3,7}};
char xaumh[100] = "HARD",xaugm[100];
void xemmang(int a[][50],int x){
	printf("\n");
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
}

//void nhapdl(){
//	printf("Nhap xau ma hoa: ");
//	gets(xaumh);
//	printf("Nhap xau giai ma: ");
//	gets(xaugm);
//	printf("Du lieu nhap vao: \nxaumh: %s, \nxaugm: %s \nKhoa=",xaumh,xaugm);
//	xemmang(khoa,n);
//}

void tich2matran(int vecto[],int khoa[][50],int kq[]){
	for(int i=0;i<n;i++){
		int s=0;
		for(int j=0;j<n;j++) 
			s+= vecto[j]*khoa[j][i];
		kq[i]=s%26;
	}
}
char *mahoa(){
	char s[100];
	int t = strlen(xaumh), i=0;
	while(i<t){
		int vecto[50],kq[50];
		for(int j=0;j<n;j++) vecto[j] = xaumh[i+j] -65;
		tich2matran(vecto,khoa,kq);
		for(int j=0;j<n;j++) s[i+j] = kq[j]+65;
		i+=n;
	}
	s[t]= NULL;
	return &s[0];
}

int timsonghichdao(int a){
	int r,q,y,y0=0,y1=1,tga=a,m=26;
	while(a>0){
		r = m%a;
		if(r==0) break;
		q = m/a;
		y = y0 - y1*q;
		m = a;
		a = r;
		y0= y1;
		y1= y;
	}
	if(a>1) return -1;
	else if(y>0) return y;
	else return y+26;
}

void timmatrankhoagm(int khoand[][50]){
	int det = khoa[0][0]*khoa[1][1] - khoa[0][1]*khoa[1][0];
	int detnd = timsonghichdao(det);
	khoand[0][0] = (detnd*khoa[1][1])%26;
	khoand[1][1] = (detnd*khoa[0][0])%26;
	khoand[0][1] = (detnd*-khoa[0][1])%26;
	if(khoand[0][1]<0) khoand[0][1] +=26;
	khoand[1][0] = (detnd*-khoa[1][0])%26;
	if(khoand[1][0]<0) khoand[1][0] +=26;
}

int main(){
	printf("Du lieu nhap vao: \nxaumh: %s \nKhoa:",xaumh);
	xemmang(khoa,n);
	char s[100];
	printf("Nhap ma can so sanh: "); 
	gets(s);
	char mh[100];
	strcpy(mh,mahoa());
	if(strcmp(s,mh)==0) printf("Ban Nhap Dung");
	else printf("Ban Nhap sai");
	//----------------//
	int khoand[50][50];
	timmatrankhoagm(khoand);
	printf("\nKhoa(giama): ");
	xemmang(khoand,n);
}


