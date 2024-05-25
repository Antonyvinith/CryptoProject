#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//int k1[16],k2[16],k3[16],k4[16];

int * texttobinary(char *s)
{
	int l=strlen(s);
	int *a=(int *)malloc(8*l*sizeof(int));
	int i,j;
	int cou=0;
	for (i=0;i<l;i++)
	{
		int b=*(s+i);
		int c[8]={0,0,0,0,0,0,0,0};
		int cou1=0;
		while(b!=0)
		{
			c[cou1++]=b%2;
			b=b/2;
		}
		for(j=0;j<8;j++)
		{
		*(a+cou++)=c[8-j-1];	
		}	 
	}
	return a;
}

int * dectobinary(int *s,int l)
{
	int *a=(int *)malloc(8*l*sizeof(int));
	int i,j;
	int cou=0;
	for (i=0;i<l;i++)
	{
		int b=*(s+i);
		int c[8]={0,0,0,0,0,0,0,0};
		int cou1=0;
		while(b!=0)
		{
			c[cou1++]=b%2;
			b=b/2;
		}
		for(j=0;j<8;j++)
		{
		*(a+cou++)=c[8-j-1];	
		}	 
	}
	return a;
}



int * hex2key(char *hex,int n)
{
	int i=0,j;
	int *a=(int *)malloc(4*n*sizeof(int));
	int cou=0;
	while(i<n)
	{
		char x=*(hex+i);
		int y=0;
		if (x>=65 || x<=70)
		y=x-55;
		else
		y=x-48;
		int c[4]={0,0,0,0};
		int cou1=0;
		while(y!=0)
		{
			c[cou1++]=y%2;
			y=y/2;
		}
		for(j=0;j<4;j++)
		{
		*(a+cou++)=c[4-j-1];	
		}
		i++;
	}
	return a;
}

int *P_fun(int *b)
{
	int *a=(int *)malloc(4*sizeof(int));
	if (*b==0 && *(b+1)==0 && *(b+2)==0 && *(b+3)==0)
	{
		*a=0,*(a+1)=0,*(a+2)=1,*(a+3)=1;
	}
		if (*b==0 && *(b+1)==0 && *(b+2)==0 && *(b+3)==1)
	{
		*a=1,*(a+1)=1,*(a+2)=1,*(a+3)=1;
	}
		if (*b==0 && *(b+1)==0 && *(b+2)==1 && *(b+3)==0)
	{
		*a=1,*(a+1)=1,*(a+2)=1,*(a+3)=0;
	}
		if (*b==0 && *(b+1)==0 && *(b+2)==1 && *(b+3)==1)
	{
		*a=0,*(a+1)=0,*(a+2)=0,*(a+3)=0;
	}
		if (*b==0 && *(b+1)==1 && *(b+2)==0 && *(b+3)==0)
	{
		*a=0,*(a+1)=1,*(a+2)=0,*(a+3)=1;
	}
		if (*b==0 && *(b+1)==1 && *(b+2)==0 && *(b+3)==1)
	{
		*a=0,*(a+1)=1,*(a+2)=0,*(a+3)=0;
	}
		if (*b==0 && *(b+1)==1 && *(b+2)==1 && *(b+3)==0)
	{
		*a=1,*(a+1)=0,*(a+2)=1,*(a+3)=1;
	}
		if (*b==0 && *(b+1)==1 && *(b+2)==1 && *(b+3)==1)
	{
		*a=1,*(a+1)=1,*(a+2)=0,*(a+3)=0;
	}
		if (*b==1 && *(b+1)==0 && *(b+2)==0 && *(b+3)==0)
	{
		*a=1,*(a+1)=1,*(a+2)=0,*(a+3)=1;
	}
		if (*b==1 && *(b+1)==0 && *(b+2)==0 && *(b+3)==1)
	{
		*a=1,*(a+1)=0,*(a+2)=1,*(a+3)=0;
	}
		if (*b==1 && *(b+1)==0 && *(b+2)==1 && *(b+3)==0)
	{
		*a=1,*(a+1)=0,*(a+2)=0,*(a+3)=1;
	}
		if (*b==1 && *(b+1)==0 && *(b+2)==1 && *(b+3)==1)
	{
		*a=0,*(a+1)=1,*(a+2)=1,*(a+3)=0;
	}
		if (*b==1 && *(b+1)==1 && *(b+2)==0 && *(b+3)==0)
	{
		*a=0,*(a+1)=1,*(a+2)=1,*(a+3)=1;
	}
		if (*b==1 && *(b+1)==1 && *(b+2)==0 && *(b+3)==1)
	{
		*a=1,*(a+1)=0,*(a+2)=0,*(a+3)=0;
	}
		if (*b==1 && *(b+1)==1 && *(b+2)==1 && *(b+3)==0)
	{
		*a=0,*(a+1)=0,*(a+2)=1,*(a+3)=0;
	}
		if (*b==1 && *(b+1)==1 && *(b+2)==1 && *(b+3)==1)
	{
		*a=0,*(a+1)=0,*(a+2)=0,*(a+3)=1;
	}
	return a;
	
}


int *Q_fun(int *b)
{
	int *a=(int *)malloc(4*sizeof(int));
	if (*b==0 && *(b+1)==0 && *(b+2)==0 && *(b+3)==0)
	{
		*a=1,*(a+1)=0,*(a+2)=0,*(a+3)=1;
	}
		if (*b==0 && *(b+1)==0 && *(b+2)==0 && *(b+3)==1)
	{
		*a=1,*(a+1)=1,*(a+2)=1,*(a+3)=0;
	}
		if (*b==0 && *(b+1)==0 && *(b+2)==1 && *(b+3)==0)
	{
		*a=0,*(a+1)=1,*(a+2)=0,*(a+3)=1;
	}
		if (*b==0 && *(b+1)==0 && *(b+2)==1 && *(b+3)==1)
	{
		*a=0,*(a+1)=1,*(a+2)=1,*(a+3)=0;
	}
		if (*b==0 && *(b+1)==1 && *(b+2)==0 && *(b+3)==0)
	{
		*a=1,*(a+1)=0,*(a+2)=1,*(a+3)=0;
	}
		if (*b==0 && *(b+1)==1 && *(b+2)==0 && *(b+3)==1)
	{
		*a=0,*(a+1)=0,*(a+2)=1,*(a+3)=0;
	}
		if (*b==0 && *(b+1)==1 && *(b+2)==1 && *(b+3)==0)
	{
		*a=0,*(a+1)=0,*(a+2)=1,*(a+3)=1;
	}
		if (*b==0 && *(b+1)==1 && *(b+2)==1 && *(b+3)==1)
	{
		*a=1,*(a+1)=1,*(a+2)=0,*(a+3)=0;
	}
		if (*b==1 && *(b+1)==0 && *(b+2)==0 && *(b+3)==0)
	{
		*a=1,*(a+1)=1,*(a+2)=1,*(a+3)=1;
	}
		if (*b==1 && *(b+1)==0 && *(b+2)==0 && *(b+3)==1)
	{
		*a=0,*(a+1)=0,*(a+2)=0,*(a+3)=0;
	}
		if (*b==1 && *(b+1)==0 && *(b+2)==1 && *(b+3)==0)
	{
		*a=0,*(a+1)=1,*(a+2)=0,*(a+3)=0;
	}
		if (*b==1 && *(b+1)==0 && *(b+2)==1 && *(b+3)==1)
	{
		*a=1,*(a+1)=1,*(a+2)=0,*(a+3)=1;
	}
		if (*b==1 && *(b+1)==1 && *(b+2)==0 && *(b+3)==0)
	{
		*a=0,*(a+1)=1,*(a+2)=1,*(a+3)=1;
	}
		if (*b==1 && *(b+1)==1 && *(b+2)==0 && *(b+3)==1)
	{
		*a=1,*(a+1)=0,*(a+2)=1,*(a+3)=1;
	}
		if (*b==1 && *(b+1)==1 && *(b+2)==1 && *(b+3)==0)
	{
		*a=0,*(a+1)=0,*(a+2)=0,*(a+3)=1;
	}
		if (*b==1 && *(b+1)==1 && *(b+2)==1 && *(b+3)==1)
	{
		*a=1,*(a+1)=0,*(a+2)=0,*(a+3)=0;
	}
	return a;
	
}


void store(int *a,int *c,int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		*(a+i)=*(c+i);
	}
}

int * f_fun(int *b)
{
	int *a=(int *)malloc(16*sizeof(int));
	int *c=P_fun(b);
	store(a,c,4);
	free(c);
	c=Q_fun(b+4);
	store(a+4,c,4);
	int i=0;
	c=P_fun(b+8);
    store(a+8,c,4);
	c=Q_fun(b+12);
	store(a+12,c,4);
	

	int *c1=(int *)malloc(4*sizeof(int));
	int *c2=(int *)malloc(4*sizeof(int));
	int *c3=(int *)malloc(4*sizeof(int));
	int *c4=(int *)malloc(4*sizeof(int));
	*c1=*a,*(c1+1)=*(a+1),*(c1+2)=*(a+4),*(c1+3)=*(a+5);
	 c1=Q_fun(c1);

  
	*c2=*(a+2),*(c2+1)=*(a+3),*(c2+2)=*(a+6),*(c2+3)=*(a+7);
	c2=P_fun(c2);
	*c3=*(a+8),*(c3+1)=*(a+9),*(c3+2)=*(a+12),*(c3+3)=*(a+13);
	c3=Q_fun(c3);
	*c4=*(a+10),*(c4+1)=*(a+11),*(c4+2)=*(a+14),*(c4+3)=*(a+15);
	c4=P_fun(c4);
	store(a,c1,4);
	store(a+4,c2,4);
	store(a+8,c3,4);
	store(a+12,c4,4);
	
    *c1=*a,*(c1+1)=*(a+1),*(c1+2)=*(a+4),*(c1+3)=*(a+5);
	c1=P_fun(c1);
	*c2=*(a+2),*(c2+1)=*(a+3),*(c2+2)=*(a+6),*(c2+3)=*(a+7);
	c2=Q_fun(c2);
	*c3=*(a+8),*(c3+1)=*(a+9),*(c3+2)=*(a+12),*(c3+3)=*(a+13);
	c3=P_fun(c3);
	*c4=*(a+10),*(c4+1)=*(a+11),*(c4+2)=*(a+14),*(c4+3)=*(a+15);
	c4=Q_fun(c4);
	store(a,c1,4);
	store(a+4,c2,4);
	store(a+8,c3,4);
	store(a+12,c4,4);
	free(c1);
	free(c2);
	free(c3);
	free(c4);	

	return a;
	
	
}

int * circshift(int *b,int n)
{
	int *a=(int *)malloc(n*sizeof(int));
	int i=0;
	for(i=n-1;i>0;i--)
	{
		*(a+i)=*(b+i-1);
	}
	*a=*(b+n-1);
	return a;
}

int *ncircshift(int *b,int n,int nos)
{
int *a=(int *)malloc(n*sizeof(int));
int i=0;
for(;i<n;i++)
*(a+i)=*(b+i);

i=0;
while(i++<nos)
{
a=circshift(a,n);	
}
return a;
	
}


int * columnsec(int *b,int n)
{
int *c1=(int *)malloc(4*sizeof(int));
int i=0;
for(;i<4;i++)
*(c1+i)=*(b+4*i+n);
return c1;	
	
}

int * flipdim(int *b)
{
int *c1=(int *)malloc(4*sizeof(int));
*c1=*(b+3);
*(c1+1)=*(b+2);
*(c1+2)=*(b+1);
*(c1+3)=*(b+0);	
return c1;
}


int *xor(int*b,int *c,int n)
{
	int *c1=(int *)malloc(n*sizeof(int));
	int i=0;
	for(;i<n;i++)
	{
		if((*(b+i)==0 && *(c+i)==0)||(*(b+i)==1 && *(c+i)==1))
		*(c1+i)=0;
		else
		*(c1+i)=1;
	}
	return c1;
}

int *not(int*b,int n)
{
	int *c1=(int *)malloc(n*sizeof(int));
	int i=0;
	for(;i<n;i++)
	{
		if(*(b+i)==0 )
		*(c1+i)=1;
		else
		*(c1+i)=0;
	}
	return c1;
}



int * SF_key_Gen(int *b)
{
	int *key=(int *)malloc(5*64*sizeof(int));
	int *c1=(int *)malloc(16*sizeof(int));
	int i=0;
	for(;i<4;i++)
	{
	c1=f_fun(b+16*i);
	store(key+16*i,c1,16);	
	}
	
	
	store(key+64,key,64);
	store(key+64*2,key+64,4);
	int *c2=(int *)malloc(4*sizeof(int));
    
	for(i=0;i<3;i++)
	{
		c2=ncircshift(key+64+4*(i+1),4,i+1);
		store(key+64*2+4*(i+1),c2,4);
	}
    
    store(key+64*2+16,key+64+16,4);
    
    for(i=0;i<3;i++)
	{
		c2=ncircshift(key+64+16+4*(i+1),4,i+1);
		store(key+64*2+4*(i+1)+16,c2,4);
	}
    
    
    store(key+64*2+32,key+64+16,4);
    
    for(i=0;i<3;i++)
	{
		c2=ncircshift(key+64+32+4*(i+1),4,i+1);
		store(key+64*2+4*(i+1)+32,c2,4);
	}
	
	store(key+64*2+48,key+64+16,4);
    
    for(i=0;i<3;i++)
	{
		c2=ncircshift(key+64+48+4*(i+1),4,i+1);
		store(key+64*2+4*(i+1)+48,c2,4);
	}


	
	
	
   	int *c3=(int *)malloc(64*sizeof(int));
	store(c3,key+64*2,64);
	int *c4=(int *)malloc(64*sizeof(int));
	store(c4,c3,16);
	int *c5=columnsec(c3+16,0);
	store(c4+16,c5,4);	
	c5=columnsec(c3+16,1);
	c5=flipdim(c5);
	store(c4+16+4,c5,4);	
	c5=columnsec(c3+16,2);
	store(c4+16+8,c5,4);
	c5=columnsec(c3+16,3);
	c5=flipdim(c5);
	store(c4+16+12,c5,4);
	
	c5=columnsec(c3+32,0);
	store(c4+32,c5,4);	
	c5=columnsec(c3+32,1);
	c5=flipdim(c5);
	store(c4+32+4,c5,4);	
	c5=columnsec(c3+32,2);
	store(c4+32+8,c5,4);
	c5=columnsec(c3+32,3);
	c5=flipdim(c5);
	store(c4+32+12,c5,4);
	store(c4+48,c3+48,16);
	
	
   int *k=(int *)malloc(80*sizeof(int));
   store(k,c4,64);
   
   int *k1=(int *)malloc(16*sizeof(int));
   int *k2=(int *)malloc(16*sizeof(int));
   
   k1=xor(k,k+16,16);
   k2=xor(k+32,k+48,16);
   k2=xor(k1,k2,16);
   store(k+64,k2,16);
    return k;
    
}






int * SF_Encrypt(int *a,int *k)
{
	
	int *b=(int *)malloc(32*sizeof(int));
	int *c=(int *)malloc(32*sizeof(int));
	store(b,a,32);
	store(c,a+32,32);
	int *enc=(int *)malloc(8*64*sizeof(int));	
	store(enc,a,64);
	int *c1=(int *)malloc(16*sizeof(int));
	c1=xor(k,enc,16);
	c1=not(c1,16);
	store(enc+64,c1,16);
	c1=f_fun(c1);
	c1=xor(c1,enc+32,16);
	store(enc+64+16,c1,16);
	c1=xor(k,enc+48,16);
	c1=not(c1,16);
	store(enc+48+64,c1,16);
	c1=f_fun(c1);
	c1=xor(c1,enc+16,16);
	store(enc+32+64,c1,16);
	
	store(enc+64*2,enc+64+16,16);
	store(enc+64*2+16,enc+64,16);
	store(enc+64*2+32,enc+64+48,16);
	store(enc+64*2+48,enc+64+32,16);
	
	
	c1=xor(k+16,enc+64*2,16);
	c1=not(c1,16);
	store(enc+64*3,c1,16);
	c1=f_fun(c1);
	c1=xor(c1,enc+64*2+16,16);
	store(enc+64*3+16,c1,16);
	c1=xor(k+16,enc+64*2+48,16);
	c1=not(c1,16);
	store(enc+64*3+48,c1,16);
	c1=f_fun(c1);
	c1=xor(c1,enc+64*2+32,16);
	store(enc+64*3+32,c1,16);
	
	c1=xor(k+32,enc+3*64,16);
	c1=not(c1,16);
	store(enc+64*4,c1,16);
	c1=f_fun(c1);
	c1=xor(c1,enc+64*3+32,16);
	store(enc+64*4+16,c1,16);
	c1=xor(k+32,enc+64*3+48,16);
	c1=not(c1,16);
	store(enc+64*4+48,c1,16);
	c1=f_fun(c1);
	c1=xor(c1,enc+3*64+16,16);
	store(enc+4*64+32,c1,16);
	
	store(enc+64*5,enc+64*4+16,16);
	store(enc+64*5+16,enc+64*4,16);
	store(enc+64*5+32,enc+64*4+48,16);
	store(enc+64*5+48,enc+64*4+32,16);
	
	
	c1=xor(k+48,enc+64*5,16);
	c1=not(c1,16);
	store(enc+64*6,c1,16);
	c1=f_fun(c1);
	c1=xor(c1,enc+64*5+16,16);
	store(enc+64*6+16,c1,16);
	c1=xor(k+48,enc+5*64+48,16);
	c1=not(c1,16);
	store(enc+64*6+48,c1,16);
	c1=f_fun(c1);
	c1=xor(c1,enc+64*5+32,16);
	store(enc+64*6+32,c1,16);
	
	
	c1=xor(k+64,enc+64*6,16);
	c1=not(c1,16);
	store(enc+64*7,c1,16);
	c1=f_fun(c1);
	c1=xor(c1,enc+64*6+32,16);
	store(enc+64*7+16,c1,16);
	c1=xor(k+64,enc+64*6+48,16);
	c1=not(c1,16);
	store(enc+64*7+48,c1,16);
	c1=f_fun(c1);
	c1=xor(c1,enc+64*6+16,16);
	store(enc+64*7+32,c1,16);
	
	int *fin=(int *)malloc(64*sizeof(int));
	store(fin,enc+64*7,64);
	free(enc);
	return fin;
	
}

int * bin2dec(int *a)
{
	int *bn=(int *)malloc(8*sizeof(int));
	int i=0;
	while(i<8)
	{
		int sum=0;
		int j=0;
		while(j<8)
		{
			sum=sum+(int)pow(2,7-j)*(*(a+8*i+j));
			j++;
		}
		*(bn+i)=sum;
		i++;
	}
	return bn;
}



int * bin2deca(int *a,int lm)
{
	int *bn=(int *)malloc(lm*sizeof(int));
	int i=0;
	while(i<lm)
	{
		int sum=0;
		int j=0;
		while(j<8)
		{
			sum=sum+(int)pow(2,7-j)*(*(a+8*i+j));
			j++;
		}
		*(bn+i)=sum;
		i++;
	}
	return bn;
}


int * SF_Decryption(int *a,int *k)
{
	int *dec=(int*)malloc(8*64*sizeof(int));
	store(dec,a,64);
	int *c1=(int *)malloc(16*sizeof(int));
	c1=xor(k+64,dec,16);
	c1=not(c1,16);
	store(dec+64,c1,16);
	c1=f_fun(dec);
	c1=xor(c1,dec+16,16);
	store(dec+64+32,c1,16);
	c1=xor(k+64,dec+48,16);
	c1=not(c1,16);
	store(dec+64+48,c1,16);
	c1=f_fun(dec+48);
	c1=xor(c1,dec+32,16);
	store(dec+64+16,c1,16);
	
	c1=xor(k+48,dec+64,16);
	c1=not(c1,16);
	store(dec+64*2,c1,16);
	c1=f_fun(dec+64);
	c1=xor(c1,dec+64+16,16);
	store(dec+64*2+16,c1,16);
	c1=xor(k+48,dec+64+48,16);
	c1=not(c1,16);
	store(dec+64*2+48,c1,16);
	c1=f_fun(dec+64+48);
	c1=xor(c1,dec+64+32,16);
	store(dec+64*2+32,c1,16);
	
	store(dec+64*3,dec+64*2+16,16);
	store(dec+64*3+16,dec+64*2,16);
	store(dec+64*3+32,dec+64*2+48,16);
	store(dec+64*3+48,dec+64*2+32,16);
	
	c1=xor(k+32,dec+64*3,16);
	c1=not(c1,16);
	store(dec+64*4,c1,16);
	c1=f_fun(dec+64*3);
	c1=xor(c1,dec+64*3+16,16);
	store(dec+64*4+32,c1,16);
	c1=xor(k+32,dec+3*64+48,16);
	c1=not(c1,16);
	store(dec+64*4+48,c1,16);
	c1=f_fun(dec+64*3+48);
	c1=xor(c1,dec+64*3+32,16);
	store(dec+64*4+16,c1,16);
	
	c1=xor(k+16,dec+64*4,16);
	c1=not(c1,16);
	store(dec+64*5,c1,16);
	c1=f_fun(dec+64*4);
	c1=xor(c1,dec+64*4+16,16);
	store(dec+64*5+16,c1,16);
	c1=xor(k+16,dec+64*4+48,16);
	c1=not(c1,16);
	store(dec+64*5+48,c1,16);
	c1=f_fun(dec+64*4+48);
	c1=xor(c1,dec+64*4+32,16);
	store(dec+64*5+32,c1,16);
	
	store(dec+64*6,dec+64*5+16,16);
	store(dec+64*6+16,dec+64*5,16);
	store(dec+64*6+32,dec+64*5+48,16);
	store(dec+64*6+48,dec+64*5+32,16);
	
	c1=xor(k,dec+64*6,16);
	c1=not(c1,16);
	store(dec+64*7,c1,16);
	c1=f_fun(dec+64*6);
	c1=xor(c1,dec+64*6+16,16);
	store(dec+64*7+32,c1,16);
	c1=xor(k,dec+64*6+48,16);
	c1=not(c1,16);
	store(dec+64*7+48,c1,16);
	c1=f_fun(dec+64*6+48);
	c1=xor(c1,dec+64*6+32,16);
	store(dec+64*7+16,c1,16);
	
	
	
	
	int *fdec=(int*)malloc(64*sizeof(int));
	store(fdec,dec+64*7,64);
	return fdec;
	
	
	
}


int NPCR(int *a,int *b, int m)
{
	int i=0,cou=0;
	for(;i<m;i++)
	{
		if(*(a+i)!=*(b+i))
		cou++;
	}
	return cou;
}




int UACI(int *a,int *b, int m)
{
	int i=0,cou=0;
	for(;i<m;i++)
	{
		cou=cou+(*(a+i)-*(b+i));
	}
	
	return cou;
	
}


float corrcoef(int *a,int *b,int m)
{
	int i=0;
	float ma=0,mb=0;
	for(;i<m;i++)
	{
		ma=ma+*(a+i);
		mb=mb+*(b+i);
	}
	ma=ma/m;
	mb=mb/m;
	
	float mab=0,maa=0,mbb=0;
	
	for(i=0;i<m;i++)
	{
		mab=mab+(*(a+i)-ma)*(*(b+i)-mb);
		maa=maa+(float)pow((*(a+i)-ma),2);
		mbb=mbb+(float)pow((*(b+i)-mb),2);
	}
	float corr=mab/(sqrt(maa)*sqrt(mbb));
	return corr;
	
}



int main()
{
printf("Enter any text\n");
	char s[250];
	gets(s);
	int *a=texttobinary(s);
	int ln=strlen(s);
	float ln1=(float)ln/8;
	int ln2=ceil(ln1);
	int a2[ln2*64],a4[ln2*8],a5[ln2*8];
	int i;
	for(i=0;i<ln2*64;i++)
	a2[i]=0;
	store(a2,a,ln*8);
	
    int *omsg=bin2deca(a2,ln);
    printf("------Original Message------");
    printf("\n");
    for(i=0;i<ln;i++)
	printf("%c",*(omsg+i));
	printf("\n");
	
	
	
	
    
    
    
    int cou=0;
    int a3[64];
    while(cou<ln2)
    {
	
	char hexkey[16]={'A','A','A','A','A','A','A','A','A','A','A','A','A','A','A','A'};
    int *TT=(int*)malloc(80*sizeof(int));
   
    int * bin_key=hex2key(hexkey,16);
    int D[8];
    int *k=SF_key_Gen(bin_key);
    int *cipher_data=(int *)malloc(64*sizeof(int));
    int *encrypt_msg,*cipher=(int*)malloc(64*sizeof(int));;
    int kk=0;
	
    store(a3,a2+64*cou,64);
    int *dmsg=bin2dec(a3);
  
   
   
    while(kk<2)
    {

   
   
   
   
    cipher=SF_Encrypt(a3,k);
   
   
    int *tk1=(int *)malloc(16*sizeof(int));
    store(tk1,k,8);
    store(tk1+8,a3,8);
    int *tk2=(int *)malloc(16*sizeof(int));
    store(tk2,a3+8,16);
    int *tk3=(int *)malloc(16*sizeof(int));
    store(tk3,a3+24,16);
    int *tk4=(int *)malloc(16*sizeof(int));
    store(tk4,a3+40,16);
    int *tk5=(int *)malloc(16*sizeof(int));
    store(tk5,a3+56,8);
    store(tk5+8,k+64+8,8);
    store(k,tk1,16);
    store(k+16,tk2,16);
    store(k+32,tk3,16);
    store(k+48,tk4,16);
    store(k+64,tk5,16);
   

   
    encrypt_msg=bin2dec(cipher);
    store(cipher_data,cipher,64);
    if(kk<1)
    store(a3,cipher_data,64);
    int Data_binary[64];
   
   
   
    if(kk==0)
    {
    store(D,encrypt_msg,8);
    int *dn=dectobinary(D,8);
    store(a3,dn,64);
    store(TT,k,80);
    encrypt_msg=NULL;
}


    kk++;

}

store(a4+8*cou,encrypt_msg,8);




int *TTT=(int*)malloc(80*sizeof(int));
store(TTT,TT,80);

kk=kk-1;
int k11[64];
int *kk1=(int*)malloc(80*sizeof(int));
int *  decrypt_msg=NULL;





while(kk>=0)
{
if(kk==1)
{
store(kk1,TT,80);
}
else
{
kk1=SF_key_Gen(bin_key);
store(D,decrypt_msg,8);
int *dn=dectobinary(D,8);
store(cipher_data,dn,64);
decrypt_msg=NULL;
}



store(cipher,cipher_data,64);
int *plaintext=SF_Decryption(cipher,kk1);
int *k12=(int*)malloc(80*sizeof(int));
store(k12,k11,8);
store(k12+8,plaintext,8);
store(k12+16,plaintext+8,16);
store(k12+32,plaintext+24,16);
store(k12+48,plaintext+40,16);
store(k12+64,plaintext+56,8);
store(k12+72,k11+64+8,8);
store(k11,k12,80);

decrypt_msg=bin2dec(plaintext);
store(cipher_data,plaintext,64);



kk--;
}


	
store(a5+8*cou,decrypt_msg,8);
cou++;      
}
 
printf("------Encrypted Message------");
printf("\n");
    for(i=0;i<ln;i++)
	printf("%c",*(a4+i)); 
printf("\n");
 
printf("------Decrypted Message------");
printf("\n");
    for(i=0;i<ln;i++)
	printf("%c",*(a5+i)); 
printf("\n");


float npcr=NPCR(omsg,a4, ln)/ln;
printf("NPCR: %f\n",npcr);
float uaci=UACI(omsg,a4,ln)/ln;
printf("UACI: %f\n",uaci);
float corrv=corrcoef(omsg,a5,ln);
printf("correlation coefficient of Original and Decrypted: %f\n",corrv);
corrv=corrcoef(omsg,a4,ln);
printf("correlation coefficient of Original and Encrypted: %f\n",corrv);
  
	return 0;
	
}
