#include<stdio.h>
#include<string.h>
#include<conio.h>
int n,khoa[50][50];
char xaumh[100],xaugm[100];
void xemmang(int a[][50], int x){
	printf("\n");
	for(int i=0; i<x; i++){
		for(int j=0; j<x; j++)
		printf(" %5d",a[i][j]);
		printf("\n");
	}
}
void docdl(){
	FILE *u;
	u= fopen("hill_input.txt","rt");
	fflush(stdin);
	fgets(xaumh,100,u);
	fflush(stdin);
	fgets(xaugm,100,u);
	fscanf(u,"%d",&n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			fscanf(u,"%d",&khoa[i][j]);
	xaumh[strlen(xaumh)-1]=NULL;
	xaugm[strlen(xaugm)-1]=NULL;
	printf("\nDu lieu duoc doc vao: \nXau ma hoa: .%s. \nXau giai  ma: .%s. \nKhoa: ",xaumh,xaugm);
	xemmang(khoa,n);
	fclose(u);
	
}

void tich2matran(int vecto[], int khoa[][50],int kq[]){
	for(int i=0; i<n; i++){
		int s=0;
		for(int j=0; j<n; j++)
			s += vecto[j]*khoa[j][i];
		kq[i] = s%26;
	}
}
char *mahoa(){
	char s[100];
	int t = strlen(xaumh),i=0;
	while(i<t){
		int kq[50],vecto[50];
		for(int j=0; j<n; j++)
			vecto[j] = xaumh[i+j] -65;
		tich2matran(vecto,khoa,kq);
		for(int j=0; j<n; j++)
			s[i+j] = kq[j] +65;
		i=i+n;
	}
	s[t] = NULL;
	return &s[0];
}
int timsonghichdao(int a){
	int r,q,y,y0=0,y1=1,tga = a,m= 26;
	while(a>0){
		r = m%a;
		if(r==0) break;
		q = m/a;
		y = y0 -y1*q;
		m = a;
		a = r;
		y0= y1;
		y1 = y;
		
	}
	if(a>1) return -1;
	else if(y>0) return y;
	else return y+26;
}
void timmatrankhoagm(int khoand[][50]){
	int det = khoa[0][0]*khoa[1][1]-khoa[0][1]*khoa[1][0];
	int detnd = timsonghichdao(det);
	khoand[0][0] = (detnd*khoa[1][1])%26;
	khoand[1][1] = (detnd*khoa[0][0])%26;
	khoand[0][1] = (detnd*-khoa[0][1])%26;
	if(khoand[0][1]<0)	khoand[0][1] = khoand[0][1]+26;
	khoand[1][0] = (detnd*-khoa[1][0])%26;
	if(khoand[1][0]<0)	khoand[1][0] = khoand[1][0]+26;
}
char *giaima(){
	char s[100];
	int t = strlen(xaugm),i=0, khoand[50][50];
	timmatrankhoagm(khoand);
	xemmang(khoand,n);
	while(i<t){
		int kq[50],vecto[50];
		for(int j=0; j<n; j++)	vecto[j] = xaugm[i+j]-65;
		tich2matran(vecto,khoand,kq);
		for(int j=0; j<n; j++) s[i+j] = kq[j]+65;
		i = i+n;
				
	}
	s[t] = NULL;
	return &s[0];
}
int main(){
	FILE *u;
	u = fopen("hill_output.txt","wt");
	docdl();
	char mh[100],gm[100];
	strcpy(mh,mahoa());
	if(n==2) strcpy(gm,giaima());
	else gm[0]=NULL;
	printf("\n.%s. ma hoa dc .%s.",xaumh,mh);
	printf("\n.%s. giai ma dc .%s.",xaugm,gm);
	fprintf(u,"\n%s ma hoa duoc %s",xaumh,mh);
	fprintf(u,"\n%s giai ma duoc %s",xaugm,gm);
	fprintf("\n HOAN TAT Vao tep output.txt de xem ket qua ");
	fclose(u);
	getch();
}








