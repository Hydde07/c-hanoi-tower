#include <stdio.h>
#include <math.h>
#include "Mstack.ed.h"
#include <conio2.h>
#include <Windows.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
struct Pinos{
	int PinoDestino,PinoOrigem;
};
void LimpaSeta(int x,int y)
{
	gotoxy(x,y);
	printf("   ");
}
int SetinhaH(int opcoes,int x,int y,int dif,int &posatual)
{
	opcoes--;
	char hit;
	int pos =posatual*dif;
	int plano =0;
	textcolor(10);
	while(hit!=13)
	{
		if(!plano)
		{
			gotoxy(x+pos,y);
			printf(" ->");
			gotoxy(x+pos,y);
		}
		else
		{
			pos = (opcoes/2)*dif;
			gotoxy(x+28,y+2);
			printf(" ->");
			gotoxy(x+28,y+2);		
		}
		
		fflush(stdin);
		hit =getch();
		fflush(stdin);
		LimpaSeta(x+pos,y);
		LimpaSeta(x+28,y+2);
		if(hit == 75)
		{
				if(plano)
					pos = 0,plano=!plano;
				else
				{			
					if(pos == 0)
					{
						pos=opcoes*dif;
					}
					else
						pos-=dif;
				}
		}
		else if(hit == 77)
		{
			if(plano)
				pos = 2*dif,plano=!plano;
			else{
				if(pos/dif==opcoes)
					pos=0;
				else
					pos+=dif;
			}
		}
		else if(hit == 80 || hit ==72)
			plano= !plano;
		
	}
	if(plano)
		return -1;
	posatual = pos/dif;
	textcolor(14);
	return posatual;
}
int Setinha(int opcoes,int x,int y)
{
	opcoes--;
	char hit;
	int pos = 0;	
	textcolor(10);
	while(hit !=13)
	{
		gotoxy(x,pos+y);
		printf(" ->");
		gotoxy(x,pos+y);
		fflush(stdin);
		hit = getch();
		fflush(stdin);
		LimpaSeta(x,pos+y);
		if(hit == 72)
		{
			if(pos == 0)
			{
				pos=opcoes;
			}
			else 
				pos--;
		}
		else if(hit == 80)
		{
			if(pos == opcoes)
				pos = 0;
			else
				pos++;
		}
	}	
	textcolor(11);
	return pos+1;
}

void quadro(int xi,int yi,int xf,int yf,int cor)
{
	textcolor(cor);
	gotoxy(xi,yi); printf("%c",201);
	gotoxy(xf,yi); printf("%c",187);
	gotoxy(xi,yf); printf("%c",200);
	gotoxy(xf,yf); printf("%c",188);
	for(int i=xi+1;i<xf;i++)
	{
		gotoxy(i,yi); printf("%c",205);
		gotoxy(i,yf); printf("%c",205);
	}
	for(int i=yi+1;i<yf;i++)
	{
		gotoxy(xi,i); printf("%c",186);
		gotoxy(xf,i); printf("%c",186);
	}
}

void telaSuperior()
{
	quadro(2,2,92,9,11);
	gotoxy(4,3);printf("___________                               .___        ___ ___                      .__ ");
	gotoxy(4,4);printf("\\__    ___/_________________   ____     __| _/____   /   |   \\_____    ____   ____ |__|");
	gotoxy(4,5);printf("  |    | /  _ \\_  __ \\_  __ \\_/ __ \\   / __ |/ __ \\ /    ~    \\__  \\  /    \\ /  _ \\|  |");
	gotoxy(4,6);printf("  |    |(  <_> )  | \\/|  | \\/\\  ___/  / /_/ \\  ___/ \\    Y    // __ \\|   |  (  <_> )  |");
	gotoxy(4,7);printf("  |____| \\____/|__|   |__|    \\___  > \\____ |\\___  > \\___|_  /(____  /___|  /\\____/|__|");
	gotoxy(4,8);printf("                                  \\/       \\/    \\/        \\/      \\/     \\/           ");
}

void telaInferior()
{
	
	
	for(int i=3;i<116;i++)
		for(int j=11;j<44;j++)
		{
			gotoxy(i,j);
			printf(" ");
		}
	for(int i =94;i<119;i++)
		for(int j=7;j<=42;j++)
			gotoxy(i,j),printf(" ");
	quadro(2,10,92,38,11);
	textcolor(14);
}

int selecaoDiscos()
{
	
	quadro(34,11,72,23,11);
	textcolor(11);
	gotoxy(36,12);
	printf("Selecione a quantidade de discos");
	gotoxy(44,14); printf("   3");
	gotoxy(44,15); printf("   4");
	gotoxy(44,16); printf("   5");
	gotoxy(44,17); printf("   6");
	gotoxy(44,18); printf("   7");
	gotoxy(44,19); printf("   8");
	gotoxy(44,20); printf("   9");
	gotoxy(44,21); printf("   10");
	gotoxy(44,22); printf("   Sair");
	return Setinha(9,44,14);
}

void hanoiExtra(int x,Pinos p)
{
	textcolor(14);
	gotoxy(13,34);
	printf("   1");
	gotoxy(43,34);
	printf("   2");
	gotoxy(73,34);
	printf("   3");
	gotoxy(41,36);
	printf("   Sair");
	quadro(94,10,116,38,11);
	quadro(94,7,116,9,11);
	gotoxy(95,8),printf("      Historico");
	
	quadro(44,10,63,12,11);
	gotoxy(45,11);printf("Pino Destino:");
	textcolor(14);printf(" %d",1+p.PinoDestino);
	textcolor(11);
	gotoxy(44,10);printf("%c",203);
	quadro(63,10,92,12,11);
	gotoxy(64,11),printf(" Movimentos Realizados: ");textcolor(14);printf("0   ");
	textcolor(11);
	gotoxy(63,10),printf("%c",203);
	gotoxy(92,12);printf("%c",185);
	quadro(63,12,92,14,11);gotoxy(65,13);printf("Movimentos Minimos:");textcolor(14);printf("    %.0lf",pow(2,x)-1);
	textcolor(11);
	gotoxy(63,12);printf("%c",206);
	gotoxy(92,14);printf("%c",185);
	gotoxy(92,12);printf("%c",185);
	textcolor(14);
}
void historico(int ant,int dps,int &qtd)
{
	textcolor(14);
	gotoxy(88,11),printf("%d",qtd);
	int y = (qtd-1)%27; 
	if(y >27)
		quadro(94,10,116,38+(y-27),11),textcolor(14),gotoxy(110,37+(y-27)),printf("      ");
	if(y!=26)
	{
		gotoxy(95,12+y);
		printf("                  ");
	}
	gotoxy(95,11+y);
	printf("%d -  %d para  %d ",qtd,ant+1,dps+1);
	
}
char passar(PilhaM &s,int ori, int dest, int base, int x, int &cont)
{
	char op=1;
	int a,b,flag,alto=base-x-5;
	if(!ori)
		a=16;
	else if(ori==1)
		a=46;
	else
		a=76;
	if(!dest)
		b=16;
	else if(dest==1)
		b=46;
	else
		b=76;
	if(a<b)
		flag=1;
	else
		flag=-1;
	for(int i=base-qtdStack(s,ori); i>=alto && op!=27;i--)
	{
		for(int j=1;j<=top(s,ori) && op!=27;j++)
		{
			if(kbhit())
				op = getch();
			gotoxy(a+j,i+1);
			printf(" ");
			gotoxy(a-j,i+1);
			printf(" ");
			gotoxy(a+j,i);
			printf("-");
			gotoxy(a-j,i);
			printf("-");
		}
		Sleep(35-x*1.5);
	}
	do
	{
		a+=flag;
		for(int j=1;j<=top(s,ori) && op!=27;j++)
		{
			if(kbhit())
				op = getch();
			gotoxy(a,alto);
			printf(" ");
			gotoxy(a-j*(flag)-flag,alto);
			printf(" ");
			gotoxy(a+j,alto);
			printf("-");
			gotoxy(a-j,alto);
			printf("-");
		}
		Sleep(16-x*1.5);
	}while(a!=b);
	for(int i=alto; i<=base-qtdStack(s,dest) && op!=27;i++)
	{
		for(int j=1;j<=top(s,ori) && op!=27;j++)
		{
			if(kbhit())
				op = getch();
			gotoxy(b+j,i-1);
			printf(" ");
			gotoxy(b-j,i-1);
			printf(" ");
			gotoxy(b+j,i);
			printf("-");
			gotoxy(b-j,i);
			printf("-");
		}
		Sleep(35-x*1.5);
	}
	if(op!=27)
	{
		insert(s,dest,remove(s,ori));
		historico(ori,dest,++cont);
	}
	return op;
}

char par(PilhaM s,int p)
{
	return !((qtdStack(s,p)+2)%2);
}

char podeTirar(PilhaM s, int p)
{
	if(!p)
		return !empty(s,0) && ((empty(s,1) || top(s,0)<top(s,1)) || (empty(s,2) || top(s,0)<top(s,2)));
	else if(p==1)
		return !empty(s,1) && ((empty(s,0) || top(s,1)<top(s,0)) || (empty(s,2) || top(s,1)<top(s,2)));
	else
		return !empty(s,2) && ((empty(s,1) || top(s,2)<top(s,1)) || (empty(s,0) || top(s,2)<top(s,0)));
}

char podeIr(PilhaM s,int o, int d)
{
	return empty(s,d) || top(s,o)<top(s,d);
}

void criaTorre(int base,int color, int x,int qual)
{
	textcolor(color);
	int d=16,b=46,c=76,a;
	if(qual == 0)
		a=16;
	if(qual == 1)
		a =46;
	if(qual == 2)
		a =76;
	
		for(int i=base;i>=base-x;i--)
		{
			gotoxy(d,i);
			printf("|");
			gotoxy(b,i);
			printf("|");
			gotoxy(c,i);
			printf("|");
		}
		for(int i=1;i<=x;i++)
		{
			for(int j=0;j<i;j++)
			{
				gotoxy(a+1+j,base-x+i);
				printf("-");
				gotoxy(a-1-j,base-x+i);
				printf("-");
			}
		}
	}


void Hanoi(PilhaM s, int x,Pinos p)
{
	char op=0;
	newStack(s,3);
	telaInferior();
	int base=33,pos,cont=0;
	for(int i=x;i>0;i--)
		insert(s,0,i);
	criaTorre(base,14,x,0);
	hanoiExtra(x,p);
	gotoxy(34,36);
	printf("Pressione esc para cancelar");
	if((x%2))
		while(qtdStack(s,2)!=x && op!=27)
		{
			pos=1;
			while(podeTirar(s,0) && pos && op!=27)
			{
				if(par(s,0) && podeIr(s,0,1))
					op = passar(s,0,1,base,x,cont);
				else if(!par(s,0) && podeIr(s,0,2))
					op = passar(s,0,2,base,x,cont);
				else
					pos=0;
			}
			pos=1;
			while(podeTirar(s,1) && pos && op!=27)
			{
				if(par(s,1) && podeIr(s,1,0))
					op = passar(s,1,0,base,x,cont);
				else if(!par(s,1) && podeIr(s,1,2))
					op = passar(s,1,2,base,x,cont);
				else
					pos=0;
			}
			pos=1;
			while(podeTirar(s,2) && pos && op!=27)
			{
				if(qtdStack(s,2)!=x)
				{
					if(par(s,2) && podeIr(s,2,0))
						op = passar(s,2,0,base,x,cont);
					else if(!par(s,2) && podeIr(s,2,1))
						op = passar(s,2,1,base,x,cont);
					else
						pos=0;
				}
				else
					pos=0;
			}
		}
	else
		while(qtdStack(s,2)!=x && op!=27)
		{
			pos=1;
			while(podeTirar(s,2) && pos && op!=27)
			{
				if(qtdStack(s,2)!=x)
				{
					if(par(s,2) && podeIr(s,2,0))
						op = passar(s,2,0,base,x,cont);
					else if(!par(s,2) && podeIr(s,2,1))
						op = passar(s,2,1,base,x,cont);
					else
						pos=0;
				}
				else
					pos=0;
			}
			pos=1;
			while(podeTirar(s,1) && pos && op!=27)
			{
				if(par(s,1) && podeIr(s,1,0))
					op = passar(s,1,0,base,x,cont);
				else if(!par(s,1) && podeIr(s,1,2))
					op = passar(s,1,2,base,x,cont);
				else
					pos=0;
			}
			pos=1;
			while(podeTirar(s,0) && pos && op!=27)
			{
				if(par(s,0) && podeIr(s,0,1))
					op = passar(s,0,1,base,x,cont);
				else if(!par(s,0) && podeIr(s,0,2))
					op = passar(s,0,2,base,x,cont);
				else
					pos=0;
			}
		}
	if(op!=27)
	{
		criaTorre(base,10,x,2);				
		textcolor(14);
		gotoxy(28,36);
		printf("Pressione uma tecla para continuar...");
		getch();
	}
}
void Clear(int n)
{
	for(int i =0;i<=n;i++)
	{
		printf(" ");
	}
}
int tiraElem(PilhaM a,int elem,int pil)
{
	gotoxy(16+ pil *30 - elem,33 - qtdStack(a,pil));
	for(int i=0;i<=elem*2;i++)
	{
			if(i == elem)
			{
				printf("|");
			}
			else
			{
				printf(" ");
			}
	}
	int opcoes=2;
	char hit;
	int pos = pil*30;
	while(hit!=13)
	{
		gotoxy(16+pos-elem,20);
		for(int i =0;i<=elem*2;i++)
		{
			if(elem==i)
			{
				printf(" ");
			}
			else
				printf("-");
		}
		gotoxy(16+pos-elem,20);
		fflush(stdin);
		hit =getch();
		fflush(stdin);
		gotoxy(16+pos-elem,20);
		Clear(elem*2);
		if(hit == 75)
		{
			if(pos == 0)
			{
				pos=opcoes*30;
			}
			else
				pos-=30;
		}
		else if(hit == 77)
		{
			if(pos/30==opcoes)
				pos=0;
			else
				pos+=30;
		}
		
	}
	int k = pos/30;
	return k;
}
void poeElem(PilhaM a,int elem,int pil)
{
	
	gotoxy(16+ pil *30 - elem,33 - (qtdStack(a,pil)));
	for(int i =0;i<=elem*2;i++)
	{
		if(i == elem)
			printf("|");
		else
			printf("-");
		
	}
}		

void HanoiManual(PilhaM &a, int x,Pinos &p)
{
	int pilo = p.PinoOrigem;
	int pilf = p.PinoDestino;
	int pilm,elem,posatual=0;
	if((pilo+pilf)%4 == 2)
	{
		pilm = 1;
	}
	else if((pilo+pilf)%4 == 1)
	{
		pilm = 2;
	}
	else if((pilo+pilf)%4 == 3)
	{
		pilm = 0;
	}
	
	telaInferior();
	newStack(a,3);
	for(int i=x;i>0;i--)
		insert(a,pilo,i);	
	criaTorre(33,14,x,pilo);
	hanoiExtra(x,p);
	
	
	textcolor(14);
	int cont=0;
	int pos=pilo;
	int sair =0;
	while((!empty(a,pilo) || !empty(a,pilm)) && !sair) 
	{
		int flag =1;
		int po = SetinhaH(3,13,34,30,pos);
		if(po == -1)
			sair =1;
		fflush(stdin);
		if(!sair &&!empty(a,po))
		{
			elem = remove(a,po);
			pos = tiraElem(a,elem,po);
			while(flag)
			{
				if(!empty(a,pos)){
					if(elem < top(a,pos))
					{
						poeElem(a,elem,pos);
						insert(a,pos,elem);
					
						if(po!= pos)	
							cont++,historico(po,pos,cont);
						
						flag =0;	
					}
					else
					{
						pos = tiraElem(a,elem,po);
					}
				}
				else
				{
					poeElem(a,elem,pos);
					insert(a,pos,elem);
					
					if(po!= pos)	
						cont++,historico(po,pos,cont);
					flag=0;	
				}			
			}
			flag=1;
		}
	}
		if(!sair){
			criaTorre(33,10,x,pilf);
			gotoxy(13,13);printf("PARABENS, VOCE GANHOU!!!");
			getch();
			}
	
		
}
int SetinhaEspaco(int opcoes,int x,int y,int espaco)
{
	opcoes--;
	char hit;
	int pos = 0;	
	textcolor(10);
	while(hit !=13)
	{
		gotoxy(x,pos*espaco+y);
		printf(" ->");
		gotoxy(x,pos*espaco+y);
		fflush(stdin);
		hit = getch();
		fflush(stdin);
		LimpaSeta(x,pos*espaco+y);
		if(hit == 72)
		{
			if(pos == 0)
			{
				pos=opcoes;
			}
			else 
				pos--;
		}
		else if(hit == 80)
		{
			if(pos == opcoes)
				pos = 0;
			else
				pos++;
		}
	}	
	textcolor(11);
	return pos+1;
}

Pinos opcoes(Pinos &p)
{
	int x,y;
	quadro(4,19,32,29,11);


	do{
		
		gotoxy(5,20);printf("   Escolher Pino Origem");
		
		gotoxy(14,21);printf("   1");
		gotoxy(14,22);printf("   2");
		gotoxy(14,23);printf("   3");
		
		
		gotoxy(5,24);printf("   Escolher Pino Destino");
		gotoxy(14,25);printf("   1");
		gotoxy(14,26);printf("   2");
		gotoxy(14,27);printf("   3");
		
		gotoxy(5,28);printf("    Voltar");
		textcolor(10);
		gotoxy(14,21+p.PinoOrigem);
		printf("   %d",p.PinoOrigem+1);
		gotoxy(14,25+p.PinoDestino);
		printf("   %d",p.PinoDestino+1);
		textcolor(12);
		gotoxy(14,21+p.PinoDestino);
		printf("   %d",p.PinoDestino+1);
		gotoxy(14,25+p.PinoOrigem);
		printf("   %d",p.PinoOrigem+1);
		textcolor(11);
	
		x = SetinhaEspaco(3,5,20,4);
		fflush(stdin);
		if(x == 1){//origem
			textcolor(10);gotoxy(5,20);printf(" ->Escolher Pino Origem");
			textcolor(11);
			if(p.PinoDestino == 0)
			{
				y = Setinha(2,14,22);fflush(stdin);	
			}	
			else if(p.PinoDestino == 1)
			{
				y = SetinhaEspaco(2,14,21,2);fflush(stdin);
				if(y == 1)
					y =0;
			}
			else if(p.PinoDestino == 2)
			{
				y = Setinha(2,14,21);fflush(stdin);
				y--;
			}
			p.PinoOrigem = y;
		}
		else if(x == 2)//Destino
		{
			textcolor(10);
			gotoxy(5,24);printf(" ->Escolher Pino Destino");
			textcolor(11);
			if(p.PinoOrigem == 0)
			{
				y = Setinha(2,14,26);fflush(stdin);		
			} 
			else if(p.PinoOrigem == 1)
			{
				y = SetinhaEspaco(2,14,25,2);
				fflush(stdin);
				if(y == 1)
					y =0;
					
			}
			else if(p.PinoOrigem == 2)
			{
				y = Setinha(2,14,25);
				fflush(stdin);
				y--;	
			}	
			p.PinoDestino = y;
		}	
	}while(x!=3);
	return p;
}

int modo()
{
	quadro(4,11,32,18,11);
	gotoxy(5,12);
	printf("           Menu");
	gotoxy(5,14);printf("   Manual");
	gotoxy(5,15);printf("   Automatico");
	gotoxy(5,16);printf("   Opcoes");
	gotoxy(5,17);printf("   Sair");
	int x = Setinha(4,5,14);
	textcolor(10);
	quadro(4,11,32,18,10);
	if(x == 1)
	{
		gotoxy(5,14);printf(" ->Manual");
	}
	if(x == 2)
	{
		gotoxy(5,15);printf(" ->Automatico");
	}
	if(x == 3)
	{
		gotoxy(5,16);printf(" ->Opcoes");
	}
	return x;
}

void menu(PilhaM &a)
{
	Pinos p;
	p.PinoDestino = 2;
	p.PinoOrigem = 0;
	int x,y;
	do{
		quadro(2,10,92,38,11);
		 y = modo();
		if(y == 3)
		{
			p = opcoes(p);
			
		}
		else if(y!=4){
			x= selecaoDiscos();
			if(y==1 && x!=9)
			{
				HanoiManual(a,x+2,p);
			}
			if(y == 2 && x!=9){
				Hanoi(a,x+2,p);
			}
		}
		telaInferior();
	}while(y!=4);	
	
	
}

int main(){
	
	PilhaM a;
	system("mode con:cols=125 lines=44");
	telaSuperior();
	menu(a);
	
	gotoxy(1,38);textcolor(15);
	return 0;
}
