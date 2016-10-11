#include<stdio.h>
#include<stdlib.h>
void criar();
void rpg();
void menu();
void batalha();

char nome[10];

typedef struct inventario{
int pot;

}inv;

typedef struct personagem{
int vida;
int classe;
int dano,eva,def;

}pe;

typedef struct morcego{
int vida;
int danoini;
}mo;

typedef struct esqueleto{
int vida,danoini2,eva,def;
}es;


int main(){
menu();

return 0;
}

void menu(){
	system("cls");
	
	int op,esc;
	printf("JANIO'S BIZARRE ADVENTURE\n Pressione 1 para comecar: \n Pressione 2 para sair\n");
	scanf("%d",&esc);
	if(esc==2){
	exit(0);
	}
	system("cls");
	printf("Selecione uma opcao\n 1-Novo jogo\n 2-Carregar jogo salvo\n 3-Sair\n");
	scanf("%d", &op);
	switch(op){
		case 1:{
			
			system("cls");
			criar();
			break;
		}
		case 2:{
			
			printf("Gravar progresso ainda nao implementada\n");
			system("pause");
			menu();
			break;
		}
		case 3:{
			
			menu();
			//exit(0);
			break;
		}
	}
	
}



void criar(){
pe  perso;
int op,x;

while (x!=1){

printf("Informe seu nome\n->");
scanf("%s", &nome);
system("cls");
printf("Esse eh seu nome mesmo? ---> %s\n1-Sim, este eh meu nome. \n2-Nao, voce esta surdo?\n",nome);
scanf("%d",&x);
}
system("cls");
printf("Selecione a sua classe:\n1-Guerreiro\n2-Mago\n3-Arqueiro\n");
scanf("%d", &op);
if (op==1){
	system("cls");
	printf("voce escolheu Guerreiro\n");
	perso.vida 		= 200;
	perso.dano 		= 30;
	perso.def  		= 50;
	perso.eva  		= 20;
	perso.classe 	= 1;
	rpg(&perso);
     }
if (op==2){
    system("cls");
    printf("voce escolheu Mago\n");
    perso.vida 		= 100;
	perso.dano 		= 50;
	perso.def  		= 10;
	perso.eva  		= 10;
	perso.classe 	= 2;
	rpg(&perso);
}
if(op==3){
	system("cls");
	printf("Voce escolheu Arqueiro\n");
	perso.vida	 	= 150;
	perso.dano	 	= 40;
	perso.def 	 	= 10;
	perso.eva 	 	= 50;
	perso.classe 	= 3;
    rpg(&perso);
}     
}



void rpg(pe * x){
pe perso;
int op;
while (op!=3){

system("cls");
//printf("batalha\n");
printf("1-Mostrar status\n2-Entrar na Dungeon\n3-Sair\n");
scanf("%d", &op);

switch(op){
case 1:{
	system("pause");
	system("cls");
	if(x->classe == 1){
	printf("Classe : Guerreiro\n");
	}
	if(x->classe == 2){
	printf("Classe : Mago\n");
	}
	if(x->classe == 3){
	printf("Classe : Arqueiro\n");
	}
	printf("Nome : %s\nVida : %d\nDano : %d\nDefesa : %d\nEvasao : %d\n",nome,x->vida,x->dano,x->def,x->eva);
	system("pause");
	break;
}
case 2:{
	pe person = *x;
	batalha(person);
	break;
}
case 3:{
	menu();
	break;
}
default:{
	break;
}
}
}
}

void batalha(pe * x){
int op,opinv;
int c,ata;
inv invent;
invent.pot = 10;
es esq;
system("cls");

 c=1+(rand() %2);
 if (c==1){
    printf("Voce encontrou um morcego!\n");
     
 }
 if (c==2){
    printf("voce encontrou um esqueleto!\n");
 	esq.vida =100;
    //esq.dano =10;
 }
 
while (op!=3){

printf("selecione sua acao\n1-atacar\n2-usar item\n3-fugir\n4-Ver status do inimigo\n");
scanf("%d", &op);



switch(op){
case 1:{
	system("cls");
	printf("voce atacou\n");
	printf("seu dano : %d\n",x->dano);
	ata = 0;
	ata = x->dano;
	
	//ata = 30;
	printf("voce hitou : %d\n",ata);
	esq.vida-=ata;
	printf("vida do inimigo : %d\n",esq.vida);
	if (esq.vida<=0){
	printf("monstro derrotado\n");
	
	}
	system("pause");
	break;
}
case 2:{
	printf("selecione um item pra usar :\n1-Usar potion : '%d'\n",invent.pot);
	scanf("%d",&opinv);
	if (invent.pot>0){
	invent.pot-=1;
	system("cls");
	printf("voce  usou uma potion\n");
	}
	else{
	system("cls");
	printf("voce nao tem mais potions\n");
	}
	break;
}
case 3:{
	printf("voce fugiu !");
	system("pause");
	break;
}
case 4:{
	system("cls");
	printf("Inimigo : Esqueleto\nVida : %d\n",esq.vida);
	system("pause");
	break;
}
}
}
}
