#include<stdio.h>
#include<conio.h>
#include<string.h>

int a,b;
char xaumh[100],xaugm[100];

void nhap(){
	fflush(stdin);
	printf("Nhap chuoi can ma hoa: ");
	gets(xaumh);
	printf("\nNhap chuoi can giai ma: ");
	gets(xaugm);
	
	printf("\nNhap khoa a = ");
	scanf("%d",&a);
	printf("\nNhap khoa b = ");
	scanf("%d",&b);
	
	xaugm[strlen(xaugm)]=NULL;
	xaumh[strlen(xaumh)] = NULL;
	printf("\nDu lieu duoc doc vao : \nxau ma hoa: %s. \nXau giai ma: %s. \na = %d \nb = %d",xaumh,xaugm, a,b);
}
char *mahoa()
{
	char s[100];
	int n= strlen(xaumh);
	for(int i=0; i<n; i++)
		s[i] = 65+ (a*(xaugm[i]-65)+b)%26;
	s[n]= NULL;
	return &s[0];
}
int timsonghichdao(){
	int r,q,y,y0=0,y1=1,tga =a,m=26;
	while(a>0){
		r = m%a;
		if(r==0) break;
		q = m/a;
		y = y0-y1*q;
		m = a;
		a = r;
		y0 = y1;
		y1 = y;
	}
	if(a>1) return -1;
	else if(y>0) return y;
	else return y+26;
}

char *giaima(){
	int nda = timsonghichdao();
	char s[100];
	int n = strlen(xaugm);
	for(int i=0; i<n;i++){
		int tg = (nda*(xaugm[i]-b-65))%26;
		if(tg<0) tg +=26;
		s[i]   = 65+tg;
	}
	s[n] = NULL;
	return &s[0];
}
int main(){
	nhap();
	char mh[100],gm[100];
	strcpy(mh,mahoa());
	strcpy(gm,giaima());
	printf("\n%s ma hoa duoc %s",xaumh,mh);
	printf("\n%s giai ma duoc %s",xaugm,gm);
	
}






