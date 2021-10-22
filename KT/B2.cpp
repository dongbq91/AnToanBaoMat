#include<stdio.h>
#include<conio.h>
#include<string.h>
char xaumh[100] = "THISCRYPTOSY",xaugm[100],khoa[50]="WIZARD";
char xaumh2[100] = "RANJLV",xaugm2[100]="PSYCHE";
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

char *timKhoa(){
	char timkhoa[100];
    int n = strlen(xaumh2);
    for(int i=0;i<n;i++){
        if(xaumh2[i]<xaugm2[i])
        	timkhoa[i]=xaumh2[i]-xaugm2[i]+65+26;
        else timkhoa[i]=xaumh2[i]-xaugm2[i]+65;
    }
    timkhoa[n] = NULL;
    return &timkhoa[0];
}

int main(){
	char khoax[100],mh[100],s[100];
	printf("Du lieu nhap vao: %s",xaumh);
	printf("\nNhap chuoi can so sanh: ");
	gets(s);
	strcpy(mh,mahoa());
	if(strcmp(s,mh)==0) printf("Yes");
	else printf("No!");
	strcpy(khoax,timKhoa());
	printf("Khoa: %s",khoax);
}










