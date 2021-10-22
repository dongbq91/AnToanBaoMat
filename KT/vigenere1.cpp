#include<stdio.h>
#include<conio.h>
#include<string.h>
char xaumh[100],xaugm[100],khoa[50];
void nhapdl(){
	printf("\nNhap ban ro: ");
	fflush(stdin);
	gets(xaumh);
	printf("\nNhap ban ma: ");
	fflush(stdin);
	gets(xaugm);
	printf("\nNhap khoa: ");
	fflush(stdin);
	gets(khoa);

}
char *mahoa(){
	char s[100];
	int n = strlen(xaumh), k = strlen(khoa), i=0;
	while(i<n){
		for(int j = 0; j<k; j++){
			s[i] = 65 + (xaumh[i] + khoa[j] -65*2)%26;
			i++;
		}
	}
	s[n] = NULL;
	return &s[0];
}
char *giaima(){
	char s[100];
	int n = strlen(xaugm), k = strlen(khoa), i=0;
	while(i<n){
		for(int j=0; j<k; j++){
			if(xaugm[i]>khoa[j])
				s[i] = 65 + (xaugm[i]-khoa[j])%26;
		    else
		    	s[i] = 65 + 26+ (xaugm[i]-khoa[j])%26;
		i++;
		}
		
	}
	s[n] = NULL;
	return &s[0];
}
int main(){
	nhapdl();
	char mh[100],gm[100];
	strcpy(mh,mahoa());
	strcpy(gm,giaima());
	printf("\n%s ma hoa duoc %s",xaumh,mh);
	printf("\n%s giai ma duoc %s",xaugm,gm);
	getch();
}







