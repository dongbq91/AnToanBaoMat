#include<stdio.h>
#include<conio.h>
#include<string.h>
int k;
char bcc[30], xaumh[100],xaugm[100];
void docdl(){
	FILE *u;
	u = fopen("inputCeasarA.txt","rt");
	fflush(stdin);
	fgets(xaumh,100,u);
	fflush(stdin);
	fgets(xaugm,100,u);
	fscanf(u,"%d",&k);
	xaumh[strlen(xaumh)-1]= NULL;
	xaugm[strlen(xaugm)-1] = NULL;
	printf("\nDu lieu duoc doc vao : \nXau ma hoa: %s.\nXau giai ma: %s.\nk= %d",xaumh, xaugm,k);
	fclose(u);
	
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
	int n = strlen(xaugm);
	for(int i=0; i<n; i++){
		s[i] = 65+(xaugm[i]-k-65+26)%26;
	}
	s[n] =NULL;
	return &s[0];
}
int main(){
	FILE *u;
	u = fopen("outputCeasarA.txt","wt");
	docdl();
	char mh[100],gm[100];
	strcpy(mh,mahoa());
	strcpy(gm,giaima());
	fprintf(u,"%s ma hoa duoc %s",xaumh,mh);
	fprintf(u,"\n%s giai ma duoc %s",xaugm,gm);
	printf("\nHoan tat vao tep outputCeasarA.txt xem ket qua");
	fclose(u);
	getch();
}










