#include <stdio.h>
#include <conio.h>
#include <string.h>

char bcc[30],xaumh[100],xaugm[100],khoa[50];

void docdl(){
	FILE *u;
	u=fopen("input.txt","rt");
	
	fflush(stdin);
	fgets(xaumh,100,u);
	fflush(stdin);
	fgets(xaugm,100,u);
	xaumh[strlen(xaumh)-1]=NULL;
	xaugm[strlen(xaugm)-1]=NULL;
	khoa[strlen(khoa)-1]=NULL;
	printf("\n Doc du duoc doc vao : \n xaumh: .%s .\n xaugm : .%s \n khoa = %s ", xaumh,xaugm,khoa);
	fclose(u);
}

char *mahoa(){
	char s[100];
	int n=strlen(xaumh),k=strlen(khoa),i=0;
	while(i<n){
		for(int j=0;j<k;j++){
			s[i]=65 +(xaumh[i]+khoa[j]-65*2)%26;
			i++;
		}
	}
	s[n]=NULL;
	return &s[0];
}
char *giaima(){
	char s[100];
	int n=strlen(xaugm),k=strlen(khoa),i=0;
	while(i<n){
		for(int j=0;j<k;j++){
			if(xaugm[i]>khoa[j])
				s[i]=65 + (xaugm[i]-khoa[j]) %26;
			else s[i]=65+26+(xaugm[i]-khoa[j])%26;
			i++;
		}
	}
	s[n]=NULL;
	return &s[0];
}
int main(){
	FILE *u;
	u=fopen("output.txt","wt");
	docdl();
	char mh[100], gm[100];
	strcpy(mh,mahoa());
	strcpy(gm,giaima());
	fprintf(u, "%s ma hoa duoc %s ",xaumh,mh );
	fprintf(u, "%s gia ma duoc %s",xaugm,gm );
	printf("\n Hoan tat vao ten output.txt xem xet ket qua");
	fclose(u);
}