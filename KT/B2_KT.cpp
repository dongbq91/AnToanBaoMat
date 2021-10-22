#include<bits/stdc++.h>
using namespace std;
char xaumh[100] = "THISCRYPTOSY";

int m = 6;
char khoa[10] ="WIZARD";

char *mahoa()
{
	int t = strlen(xaumh);
	int i =0;
	char s[100];
	while(i<t)
	{
		for(int j=0;j<m;j++)
		{
			s[j+i] = (xaumh[j+i] + khoa[j] -65*2) %26 +65; 
			
		}
		i = i+m;
	}
	s[t]=NULL;
	return &s[0];
}

int main()
{
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
	
	char r[7];
	char c[7]="RANJLV";
	char p[7]="PSYCHE";
	for(int i=0;i<m;i++)
	{
		r[i] = (c[i] -p[i]+26) %26 +65;
	}
	cout<<r;
}