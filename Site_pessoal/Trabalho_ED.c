#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct elemento{
	char dado;
	struct elemento * proximo;
}element;


typedef struct lista{
	element * primeiro;
	element * ultimo;
}list;


typedef struct pilha{
	list * l;
}pila;


list * criaLista(){
   list * l = (list *)malloc(sizeof(list));
   l->primeiro = NULL;
   l->ultimo = NULL;
   return l;
}


void insereInicio(char valor, list * l){
    element * novoprimeiro = (element *)malloc(sizeof(element));
    novoprimeiro->dado = valor;
    novoprimeiro->proximo = l->primeiro;
    l->primeiro = novoprimeiro;
    if(l->ultimo == NULL){
        l->ultimo = novoprimeiro;
    }
}


void insereFinal(char valor, list * l){
   element * novoultimo = (element *)malloc(sizeof(element));
   novoultimo->dado = valor;
   novoultimo->proximo = NULL;
   if(l->primeiro == NULL){
      l->primeiro = novoultimo;
   }else{
     l->ultimo->proximo = novoultimo;
   }
   l->ultimo = novoultimo;
}

char removeInicio(list * l){
    if(estaVazia(l)){
        return -1;
    }
    int tmp = l->primeiro->dado;
    element * removido = l->primeiro;
    l->primeiro = l->primeiro->proximo;
    free(removido);
    if(l->primeiro == NULL){
       l->ultimo = NULL;
    }
    return tmp;
}



int estaVazia(list * l){
    if(l->primeiro == NULL){
       return 1;
    }
    return 0;
}

pila * criaPilha(){
   pila * p =  (pila *)malloc(sizeof(pila));
   p->l = criaLista();
   return p;
}

void empilhar(char valor,pila * p){
  insereInicio(valor, p->l);
}


char desempilhar(pila * p){
  return removeInicio(p->l);
}


int estaVaziaPilha(pila * p){
    return estaVazia(p->l);
}


//Pilha de vetor int

float desempilharfloat (int *i,float v[]){
    int posicao;
    posicao = *i;
    if(posicao == -1){
        return 0;
    }
    else{

        *i = *i - 1;
        return v[posicao];
    }
}

void empilharfloat (float numero,int *i,float v[]){
    *i = *i +1;
    v[*i] = numero;
}

/*int chartoint(char a[]){
    int j=0,convertido=0;
    int i=0;
    while(a[j]!='\0'){
        j++;

    }
    j-=1;
    while(j>=0){

        convertido += (a[i]-'0')*pow(10.0,j);
        j = j - 1;
        i++;
        printf("%d\n",convertido);

    }
    return convertido;
}*/

int validador(char expressao[]){
    pila *pila = criaPilha();
    int i = 0;
    while(expressao[i]!='\0'){
        if(expressao[i] == '(' ||expressao[i] == '[' || expressao[i] == '{' ){
            empilhar(expressao[i],pila);

        }
        else if(expressao[i] == ')' ||expressao[i] == ']'||expressao[i] == '}'){
            if(estaVaziaPilha(pila)){
                return 0;
            }
            else{
                char x = desempilhar(pila);
                switch(expressao[i]){
                    case ')':
                        if(x!='('){
                            return 0;
                        }
                        break;
                    case ']':
                        if(x!='['){
                            return 0;
                        }
                        break;
                    case '}':
                        if(x!='{'){
                            return 0;
                        }
                        break;
                    default:
                        break;
                }
            }
        }
        i++;
    }
    if(estaVaziaPilha(pila)){

        return 1;
    }
    else{

        return 0;
    }


}

int comparepriority(char a, char b){//retorna verdadeiro se a tem menor ou igual prioridade que b
    switch(a){
        case '+':
            if(b=='('){
                return 0;
            }
            return 1;

        case '-':
            if(b=='('){
                return 0;
            }
            return 1;

        case '*':
            if(b=='/'){
                return 1;
            }
            else{
                return 0;
            }
        case '/':
            if(b=='*'){
                return 1;
            }
            else{
                return 0;
            }
        case '(':
            return 0;

        case ')':
            return 0;

        default:
            printf("Operador Invalido\n");
            return 0;
    }

}

int eoperando(char a){
    if(a>=48){
        if(a<58){
            return 1;
        }
    }
    return 0;
}

//48 e o numero que representa o zero na tabela ASCII
char * posfixa(char expressao[]){
    pila *p = criaPilha();
    char b;
    static char equacao[50];
    int i=0;
    int j=0;
    while(expressao[i] != '\0'){
        if(eoperando(expressao[i])){
            equacao[j] = expressao[i];
            j++;

        }
        else{
            //equacao[j] = ' ';
            //j++;
            if(expressao[i]>= 42){
                if(estaVaziaPilha(p)){
                    empilhar(expressao[i],p);
                }

                else{
                    int x = 1;

                    do{
                        char a = desempilhar(p);
                        if(comparepriority(expressao[i],a)){
                            equacao[j] = a;
                            j++;
                        }
                        else{
                            empilhar(a,p);
                            empilhar(expressao[i],p);
                            break;
                        }

                        if(estaVaziaPilha(p)){
                            empilhar(expressao[i],p);
                            break;
                        }

                    }while(1);

                }
            }
            else{
                if(expressao[i]=='('){
                    empilhar(expressao[i],p);
                }
                else if(expressao[i]==')'){
                    b = desempilhar(p);
                    while(b != '('){
                        equacao[j] = b;
                        b = desempilhar(p);
                        j++;
                    }
                }
            }
        }
        i++;
    }
    while(!estaVaziaPilha(p)){
        equacao[j] = desempilhar(p);
        j++;
    }
    equacao[j] = '\0';


    return equacao;
}

float resultado (char equacao[]){
    float p[40];
    float result;
    int i=-1;
    int j=0;
    float a,b;
    while(equacao[j]!='\0'){
        if(eoperando(equacao[j])){
            float c = (equacao[j] - '0');
            empilharfloat(c,&i,p);
        }
        else{
            char operador = equacao[j];
            a = desempilharfloat(&i,p);
            b = desempilharfloat(&i,p);
            switch(operador){
                case('+'):
                    empilharfloat(a+b,&i,p);
                    break;
                case('-'):
                    empilharfloat(b-a,&i,p);
                    break;
                case('*'):
                    empilharfloat(a*b,&i,p);
                    break;
                case('/'):
                    empilharfloat(b/a,&i,p);
                    break;
                default:
                    break;
            }

        }
        j++;
    }
    result = desempilharfloat(&i,p);

    return result;

}

int main(){
    char expressao[50];

    printf("Digite a expressao:\n");
    scanf("%[^\n]s",expressao);
    int x = validador(expressao);

    if(x){
        printf("Valida\n");
    }
    else{
        printf("Invalida");
    }

    printf("Forma posfixa: %s\n",posfixa(expressao));
    printf("Resultado: %.2f\n",resultado(posfixa(expressao)));

    return 0;

}
