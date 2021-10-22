#include <stdio.h>
#include <conio.h>
#include <string.h>

int a,b;

char xaumh[100],xaugm[100];

void docl(){
	FILE *u ;
	u= fopen("input.txt", "rt");
	fflush(stdin);
	fgets(xaumh,100,u);
	fflush(stdin);
	fgets(xaugm,100,u);
	xaumh[strlen(xaumh)-1]=NULL;
	xaugm[strlen(xaugm)-1]=NULL;
	fscanf(u,"%d%d",&a,&b);
	printf("\n Doc du duoc doc vao : \n xaumh: .%s .\n xaugm : .%s \n a = %d \n b = %d", xaumh,xaugm,a,b);
	fclose(u);
} 
char *mahoa(){
	char s[100];
	int n= strlen(xaumh);
	for(int i=0; i<n;i++)
		s[i]= 65+(a*(xaumh[i]-65 )+b)% 26;
	s[n] = NULL;
	return &s[0];
}
int timsonghichdao(){
	int r,q,y,y0=0,y1=1,tga=a,m=26;
	while(a>0){
		r=m&a;
		if(r==0) break;
		q=m/a;
		y=y0-y1*q;
		m=a;
		a=r;
		y0=y1;
		y1=y;
	}
	if(a>1)
		return -1;
	else if(y>0)
		return y ;
	else
		return y+26;
}
char *giama(){
	int nda = timsonghichdao();
	char s[100];
	int n=strlen(xaugm);
	for(int i=0;i<n;i++){
		int  tg = (nda *(xaugm[i]-b-65))&26;
		if(tg<0) tg+=26;
		s[i] =65 +tg;
	}
	s[n]=NULL;
	return &s[0];
}
int main(){
	FILE *u;
	u=fopen("output.txt","wt");
	docl();
	char mh[100],gm[100];
	strcpy(mh,mahoa());
	strcpy(gm,giama());
	fprintf(u, "%s ma hoa duoc %s ",xaumh,mh );
	fprintf(u, "%s gia ma duoc %s",xaugm,gm );
	printf("\n Hoan tat vao ten output.txt xem xet ket qua");
	fclose(u);
	getch();
}