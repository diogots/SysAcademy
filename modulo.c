#include <stdio.h>

struct aluno
{
    int id;
    char nome[50];
    char tel[18];
    float peso;
    float alt;
    float mensalidade;
    int idade;
};
typedef struct aluno Aln;

void exibirMenu()
{
    puts("<>>>>>>>>>>>>>>>>>SYSAcademy<<<<<<<<<<<<<<<<<>");
    puts("Escolha a opção Desejada:");
    puts("1 - Cadastrar Aluno:");
    puts("2 - Imprimir Relação de Alunos:");
    puts("3 - Editar Cadastro de Aluno:");
    puts("4 - Calcular IMC de um Aluno:");
    puts("5 - Sair");
    printf("Opção: ");
}

void limparTela()
{
    if(getchar())
    {
        printf("Digite qualquer tecla para continuar...");
        getchar();
        system("clear");
    }
}

Aln cadastrarAluno(int *pid)
{
    Aln aluno;
    aluno.id = *pid+1;
    (*pid)++;
    getchar();
    puts("Digite o nome do Aluno:");
    scanf("%[^\n]s",aluno.nome);
    getchar();
    puts("Digite o telefone do Aluno:");
    scanf("%[^\n]s",aluno.tel);
    getchar();
    puts("Digite a idade do Aluno:");
    scanf("%i",&aluno.idade);
    puts("Digite o peso do Aluno:");
    scanf("%f",&aluno.peso);
    puts("Digite a altura do Aluno:");
    scanf("%f",&aluno.alt);
    puts("Digite o valor da mensalidade do Aluno:");
    scanf("%f",&aluno.mensalidade);

    return aluno;


}

void printAluno(Aln aluno)
{
    puts("Dados do aluno:");
    printf("Nome: %s\n",aluno.nome);
    printf("ID: %d\n",aluno.id);
    printf("Tel: %s\n",aluno.tel);
    printf("Idade: %d\n",aluno.idade);
    printf("Peso: %.1f\n",aluno.peso);
    printf("Altura: %.1f\n",aluno.alt);
    printf("Mensalidade: R$%.2f\n\n",aluno.mensalidade);
}

void imprimirAlunos(int id,Aln alunos[])
{
    for(int i=0; i< id; i++)
    {
        printAluno(alunos[i]);
    }
}

void AbrirArquivo(Aln alunos[], int *pid)
{
    FILE *fp;
    puts("Lendo dados de arquivo...");

    fp = fopen("Alunos.txt","r");
    if (fp != NULL)
    {
        puts("Carregando dados de alunos...");
        while(!feof(fp))
        {
            int i = *pid;
            printf("Inserindo o aluno %d do arquivo. Id em %d\n",i,*pid+1);

            fscanf(fp,"%[^\n]s",alunos[i].nome);
            fscanf(fp,"%s",alunos[i].tel);
            fscanf(fp,"%d %d %f %f %f\n",&alunos[i].id,&alunos[i].idade,&alunos[i].peso,&alunos[i].alt,&alunos[i].mensalidade);
            puts("Cadastro lido:");
            printAluno(alunos[i]);
            *pid = *pid + 1;
        }
        puts("Dados de alunos carregados com sucesso!");
        fclose(fp);
    }
    else
    {
        puts("Arquivo não encontrado...");
    }

}

void SalvarArquivo(Aln alunos[], int *pid)
{
    FILE *fp;
    fp = fopen("Alunos.txt","w");

    //escrita em arquivo
    for(int i = 0; i<*pid; i++)
    {
        fprintf(fp,"%s\n",alunos[i].nome);
        fprintf(fp,"%s\n",alunos[i].tel);
        fprintf(fp,"%d %d %f %f %f\n",alunos[i].id,alunos[i].idade,alunos[i].peso,alunos[i].alt,alunos[i].mensalidade);
    }
    fclose(fp);
}
