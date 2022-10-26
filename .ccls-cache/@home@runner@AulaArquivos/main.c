
#include <stdio.h>
#include <stdlib.h>
#include "modulo.h"
#define MAX 100

int main()
{   Aln alunos[100];
    int id = 0;

    /*
    funcionalidades:
    1 - cadastrar aluno
    2 - imprimir alunos
    3 - editar Cadastro
    4 - calcular IMC
    5 - Sair
    */

    int opc = 0;

    AbrirArquivo(alunos,&id);
    limparTela();

    do{
        exibirMenu();
        scanf("%d",&opc);

        switch(opc){
            case 1:
            alunos[id] = cadastrarAluno(&id);
            limparTela();
            break;
            case 2:
            imprimirAlunos(id,alunos);
            limparTela();
            break;
            case 3: break;
            case 4: break;
            case 5:
                puts("Salvando dados de Alunos...");
                SalvarArquivo(alunos,&id);
                break;
            default:
            puts("Opção inválida!");
            limparTela();
        }

    }while(opc != 5);
}
