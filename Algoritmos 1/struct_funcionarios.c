#include <stdio.h>
#include <string.h>
/*Faça um programa que armazene em uma estrutura os dados de um funcionário de uma
empresa, compostos de: Nome, Idade, Sexo (M/F), CPF, Data de Nascimento, Código do
Setor onde trabalha (0-99), Cargo que ocupa e Salário. Os dados devem ser digitados pelo
usuário, armazenados na estrutura e exibidos na tela. Obs.: crie uma estrutura para
armazenar a data de nascimento e use esta estrutura dentro da estrutura do cadastro.*/
typedef struct funcionario Funcionario;
typedef struct data Data;
struct data{
    int dia;
    int mes;
    int ano;
};
struct funcionario{
    char nome[31];
    char sexo[1];
    char cargo[31];
    int idade;
    long int cpf;
    int codigo;
    float salario;
    Data data;
};
Funcionario cadastro(){
    fflush(stdin);
    Funcionario f;
    printf("Nome: \n");
    gets(f.nome);
    printf("Sexo: \n");
    gets(f.sexo);
    printf("Cargo: \n");
    gets(f.cargo);
    printf("Idade: \n");
    scanf(" %d",&f.idade);
    printf("Codigo de setor: \n");
    scanf(" %ld",&f.cpf);
    printf("Salario: \n");
    scanf(" %f",&f.salario);
    printf("Data de nascimento: \n");
    printf("Dia: \n");
    scanf(" %d", &f.data.dia);
    printf("Mes: \n");
    scanf(" %d", &f.data.mes);
    printf("Ano: \n");
    scanf(" %d", &f.data.ano);
    return f;
}

void mostrar_dados(int tam, Funcionario f[]){
    for(int i=0;i<tam;i++){
        printf("\n");
        printf("Nome: %s\n",f[i].nome);
        printf("Sexo: %s\n",f[i].sexo);
        printf("Cargo: %s\n",f[i].cargo);
        printf("Idade: %d\n",f[i].idade);
        printf("Codigo de setor: %d\n",f[i].codigo);
        printf("Cpf: %ld\n",f[i].cpf);
        printf("Salario: %f\n",f[i].salario);
        printf("Data de nascimento: %d/%d/%d\n",f[i].data.dia,f[i].data.mes,f[i].data.ano);
    }
}
main(){
    int i, n=2;
    Funcionario f[n];
    for(i=0;i<n;i++){
        f[i] = cadastro();
    }
    mostrar_dados(n, f);
}