#ifndef __TES__H__
#define __TES_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Planted.h"
#include "Que.h"

typedef unsigned char UCHAR;

int forLen(char* type)
{
	if (strcmp(type, "char") == 0)
		return CHAR_LEN;
	if (strcmp(type, "float") == 0)
		return FLOAT_LEN;
	if (strcmp(type, "double") == 0)
		return DOUBLE_LEN;
	if (strcmp(type, "byte") == 0)
		return BYTE_LEN;
	if (strcmp(type, "long") == 0)
		return LONG_LEN;
	if (strcmp(type, "int") == 0)
		return INT_LEN;
	else
		return 0;
}

void noEmpty(char* str)
{
	char* q = str;
	while (*q != '\0')
	{
		if (*q != ' ')
			*str++ = *q;
		q++;
	}
	*str = '\0';
}

char* split(char* &str, char del)
{
	int n = 0;
	static char ptr[30];
	if (!strlen(str))
		return NULL;
	else if (!strchr(str, del))
	{
		n = strlen(str);
		memcpy(ptr,str,n);
		ptr[n] = '\0';
		str += n;
		return ptr;
	}
	else
	{
		char* d = strchr(str,del);
		n = d - str;
		memcpy(ptr,str,n);
		ptr[n] = '\0';
		str = d + 1;
		return ptr;
	}
}

char* getTrue(char* str)
{
	char* b = strchr(str,'|');
	char* p = b + 1;
	return p;
}

#pragma pack(push,1)
typedef struct _Tst
{
	float	a;
	int		b;
	int		c;
	int		d;
	int		e;
	char	f[32];
	char	g[256];
	char	h[256];
	char	i[128];
}Tst;
#pragma pack(pop,1)


char* getEx()
{
	static Tst *tst = (Tst*) malloc(sizeof(Tst));
	memset(tst, 0, sizeof(Tst));
	return (char*)tst;
}


void showEx(Tst* tst)
{
	printf("a:%f\n", tst->a);
	printf("b:%d\n", tst->b);
	printf("c:%d\n", tst->c);
	printf("d:%d\n", tst->d);
	printf("e:%d\n", tst->e);
	printf("f:%s\n", tst->f);
	printf("g:%s\n", tst->g);
	printf("h:%s\n", tst->h);
	printf("i:%s\n", tst->i);
}

char* getBuf()
{
	static char buf[1024*4];
	memset(buf, 0, sizeof(buf));
	return buf;
}


char* getDesc()
{
	static char desc[] = "float,int,int,int,int,char:2|32,char:3|256,char:4|256,char:5|128";
	return desc;
}


void setBuf(char* buf)
{
	float _a = 7.5;
	int	_b = 4;
	int _c = 2;
	int _d = 3;
	int _e = 5;
	char _f[32]  = "abcdefghigklmnopkrstuwxyz";
	char _g[256] = "abcdefghigklmnopkrstuwxyz";
	char _h[256] = "abcdefghigklmnopkrstuwxyz";
	char _i[128] = "abcdefghigklmnopkrstuwxyz";

	int off = 0;
	memcpy(buf + off, &_a, sizeof(float));

	off += sizeof(float);
	memcpy(buf+off, &_b, sizeof(int));

	off += sizeof(int);
	memcpy(buf + off, &_c, sizeof(int));

	off += sizeof(int);
	memcpy(buf + off, &_d, sizeof(int));

	off += sizeof(int);
	memcpy(buf + off, &_e, sizeof(int));

	off += sizeof(int);
	_f[_b] = '\0';
	memcpy(buf + off, _f, _b);

	off += _b;
	_g[_c] = '\0';
	memcpy(buf + off, _g, _c);

	off += _c;
	_h[_d] = '\0';
	memcpy(buf + off, _h, _d);

	off += _d;
	_i[_e] = '\0';
	memcpy(buf + off, _i, _e);

	off += _e;

}

void run()
{
	char* ptst = getEx();
	Que que, len_que;
	char* buf = getBuf(); 
	setBuf(buf);

	char* str = getDesc();
	noEmpty(str);

	char* s = str;
	char* p = NULL;
	
	while (p = split(s, ':'))
	{
		if (atoi(p))
		{
			que.push(atoi(p));
		}
			
	}

	s = str;
	int i = 0;
	int off_stru = 0;
	int off_buf = 0;
	int x = 0;
	int off_len = 0;
	int off_stru_len = 0;
	int off_buf_len = 0;

	while (p = split(s, ','))
	{
		i++;
		if (que.isIn(i))
		{
			memcpy(&x, buf+off_buf, sizeof(x));
			len_que.push(x);

			off_len = forLen(p);
			off_stru_len = off_len;
			off_buf_len = off_len;
		}
		else if (strchr(p, ':'))
		{
			off_stru_len = atoi(getTrue(p));
			off_buf_len = len_que.pop();
		}
		else
		{
			off_len = forLen(p);
			off_stru_len = off_len;
			off_buf_len = off_len;
		}

		memcpy(ptst+off_stru, buf+off_buf, off_buf_len);
		off_stru += off_stru_len;
		off_buf += off_buf_len;
	}


	showEx((Tst*)ptst);
}

#endif //__TES__H__
