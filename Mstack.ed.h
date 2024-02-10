#define MAXP 33

struct PilhaM{
	char stack[MAXP];
	int top[MAXP],base[MAXP+1];
};

void newStack(PilhaM &s,int qtd)
{
	int qtdelem = MAXP/qtd,i;
	s.base[0]=0;
	s.top[0]=-1;
	for(i=1;i<qtd;i++)
	{
		s.base[i]=s.base[i-1]+qtdelem;
		s.top[i]=s.top[i-1]+qtdelem;
	}
	s.base[i]=s.base[i-1]+qtd;
}

char full(PilhaM s, int n)
{
	return s.top[n]+1==s.base[n+1];
}

char empty(PilhaM s, int n)
{
	return s.top[n]<s.base[n];
}

void insert(PilhaM &s, int n, char elem)
{
	s.stack[++s.top[n]]=elem;
}

char remove(PilhaM &s, int n)
{
	return s.stack [s.top[n]--];
}

char top(PilhaM s, int n)
{
	return s.stack [s.top[n]];
}

int qtdStack(PilhaM s,int n)
{
	return s.top[n]-s.base[n]+1;
}
