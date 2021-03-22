/*
Software para inclusão de pacientes com Covid 19,
como requisito para o PIM IV, da Universidade Paulista - UNIP

Versão 1.0

Autores:

Allan Carvalho Barbosa  RA:583355
Bruno Cesar Firmino     RA:584501

Data da criação:    02/11/2020
Última atualização: 16/11/2020

*/
//==============================================================================
//--- Inclusão das bibliotecas ---

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

//==============================================================================
// --- Declaração das variáveis

int  senha    = 123456, aux, aux2, ano = 0, dia [3], mes [3], idade;
char login[8] = "usuario",comor[100], cep [9];

//==============================================================================

int main()
{
    setlocale(LC_ALL,"portuguese"); // Define a linguagem de saída como Português

    printf("\n\n ============ Software Selfcare ============\n");
    printf("\n Seja bem vindo!\n");
    logar();
    system("cls");
    cadastro();
    system("cls");
    calculo_idade();
    diagnostico();

   system("pause");
   return 0;
}
//==============================================================================
//--- Funções auxiliares ---

void logar()
{

char aux [8];
int log;
int aux2;

    for(;;)
 {

     printf("\n Login:");
     scanf("%s",&aux);
     log = strncmp(login,aux,8);

    if(log == 0)
     {
     printf("\n Senha:");
     scanf("%d",&aux2);

    if(aux2 == senha)
        {

     printf("\n Tudo certo!");
     break;
        }
    else
     printf("\n Senha incorreta, digite novamente.\n");
     }
    else
     printf("\n Login incorreto, digite novamente.\n");
 }
}

void cadastro(){

char nome[40], rua[40], bairro[40], cidade[40], uf[3], email[40];
int tel [14], num[6], ddata[12], cpf[12];

    printf("\n\n ============ Software Selfcare ============\n");
    printf("\n Digite os Dados do Paciente:\n");
    fflush(stdin); //Limpa o buffer do teclado

    printf("\n Nome:");
    gets(nome);
    fflush(stdin);

    printf(" CPF:");
    gets(cpf);
    fflush(stdin);

    printf(" Data de Nascimento (XX/XX/XXX):");
    scanf ("%2d/%2d/%4d",&dia, &mes, &ano);
    fflush(stdin);

    printf(" Telefone:");
    scanf ("%d",&tel);
    fflush(stdin);

    printf("\n\n Digite o Endereço:\n");
    printf("\n Rua:");
    gets(rua);
    fflush(stdin);

    printf(" Numero:");
    gets (num);
    fflush(stdin);

    printf(" Bairro:");
    gets(bairro);

    printf(" Cidade:");
    gets(cidade);

    printf(" Estado [UF]:");
    gets(uf);
    fflush(stdin);

    printf(" CEP:");
    gets (cep);
    fflush(stdin);

    printf("\n Email:");
    gets(email);
    fflush(stdin);

    printf("\n Data do diagnostico (XX/XX/XXX):");
    gets (ddata);
    fflush(stdin);
    }
void calculo_idade(){

    SYSTEMTIME str_t; // verifica a data atual do sistema
    GetSystemTime(&str_t);

    int anosistema = str_t.wYear;

    idade = (anosistema - ano);

   return 0;
}

void diagnostico(){

char aux[4];
int  aux2;

    printf("\n\n ============ Software Selfcare ============\n");
    fflush(stdin); //Limpa o buffer do teclado
    printf("\n O paciente possui comorbidades:\n Sim ou Não? ");
    gets(aux);
    aux2 = strncmp(aux,"sim",3);

    if (aux2 == 0)
    {
    printf("\n Digite as comorbidades do Paciente:");
    gets(comor);
    }

    if (idade >= 65 || aux2 == 0) {
      FILE *selfcare; // Cria variável do tipo ponteiro para a criação do arquivo

      selfcare = fopen("Selfcare.txt", "a"); // Abrindo o arquivo

      fprintf(selfcare,"\n ============ Software Selfcare ============\n");
      fprintf(selfcare," CEP:%s ", cep);
      fprintf(selfcare,"\n Idade:%d ",idade);
      fclose(selfcare); //Fecha o arquivo
      printf("\n Arquivo gerado com sucesso\n");
      printf("\n ====== Obrigado por utilizar nosso programa ======\n");
    }
    else {
      printf("\n ====== Obrigado por utilizar nosso programa ======\n");
}
    return 0;
}//fim do programa

