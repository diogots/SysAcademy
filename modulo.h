

struct aluno {
    int id;
    char nome[50];
    char tel[18];
    float peso;
    float alt;
    float mensalidade;
    int idade;
};
typedef struct aluno Aln;
void AbrirArquivo(Aln alunos[], int *pid);
void SalvarArquivo(Aln alunos[], int *pid);
void exibirMenu();
void limparTela();
Aln cadastrarAluno(int *pid);
