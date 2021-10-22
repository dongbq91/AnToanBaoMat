#include<bits/stdc++.h>
using namespace std;
int n = 2;
char xaumh[100]="HARD";
int khoa[2][2] ={{12,5},{3,7}};
void xemmang(int a[][2],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<" "<<a[i][j];
		}
		cout<<endl;
	}
}
void tich2matran(int vecto[], int khoa[][2], int kq[]){
	for(int i=0; i<n; i++){
		int s=0;
		for(int j=0; j<n; j++)	s +=vecto[j]*khoa[j][i];
		kq[i] = s%26;
		
	}
}
char *mahoa(){
	char s[100];
	int t = strlen(xaumh),i=0;
	while(i<t){
		int kq[50],vecto[50];
		for(int j=0;j<n; j++) vecto[j] = xaumh[i+j] -65;
		tich2matran(vecto,khoa,kq);
		for(int j=0; j<n;j++) s[i+j] = kq[j]+65;
		i =i+n;
	}
	s[t] = NULL;
	return &s[0];
}
int timsonghichdao(int a){
	int r,q,y,y0=0,y1=1,tga=a,m = 26;
	while(a>0){
		r = m%a;
		if(r==0) break;
		q = m/a;
		y = y0-y1*q;
		m= a;
		a =r;
		
		y0=y1;
		y1 =y;
	}
	if(a>1) return -1;
	else if(y>0) return y;
	else return y+26;
}
void timmatrankhoagm(int khoand[][2]){
	int det= khoa[0][0]*khoa[1][1]-khoa[1][0]*khoa[0][1];
	int detnd = timsonghichdao(det);
	khoand[0][0] = (detnd*khoa[1][1])%26;
	khoand[1][1] = (detnd*khoa[0][0])%26;
	khoand[1][0] = (detnd*-khoa[1][0])%26;
	if(khoand[1][0]<0) khoand[1][0] +=26;
	khoand[0][1] = (detnd*-khoa[0][1])%26;
	if(khoand[0][1]<0) khoand[0][1] +=26;
	xemmang(khoand,2);
}

int main(){
	char x[100];
	cout<<"Nhap xau can ktra: ";fflush(stdin);gets(x);
	char mh[100],gm[100];
	strcpy(mh,mahoa());
	
	if(strcmp(mh,x)==0)
	{
		cout<<"Ban da nhap dung";
	}
	else cout<<"Ban da nhap sai";
	cout<<"\n";
	timmatrankhoagm(khoa);
}