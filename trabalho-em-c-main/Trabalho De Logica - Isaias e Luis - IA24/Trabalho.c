#include <stdio.h>
#include <locale.h>

#define maximoDeFuncionarios 100

struct Funcionario {
int id;
char nome[50];
char cargo[30];
float salario;
int idade;
char departamento[30];
};

struct Funcionario funcionarios[maximoDeFuncionarios];

int cont=0;

void cadastro () {
    
    printf("Por favor digite seu id: ");
    scanf("%d", &funcionarios[cont].id);
    printf("Por favor digite seu nome: ");
    getchar();
    fgets(funcionarios[cont].nome, sizeof(funcionarios[cont].nome), stdin);
    printf("Por favor digite seu cargo: ");
    fgets(funcionarios[cont].cargo, sizeof(funcionarios[cont].cargo), stdin);
    printf("Por favor digite seu salario: ");
    scanf("%f", &funcionarios[cont].salario);
    printf("Por favor digite seu idaide: ");
    scanf("%d", &funcionarios[cont].idade);
    printf("Por favor digite seu departamento: ");
    getchar();
    fgets(funcionarios[cont].departamento, sizeof(funcionarios[cont].departamento), stdin);

    printf("\n");

    cont++;
    
}

void listar () {

    for (int i=0 ; i < cont ; i++) {
        printf("O id do funcionario %d é: %d\n", i, funcionarios[i].id);
        printf("O nome do funcionario %d é: %s", i, funcionarios[i].nome);
        printf("O cargo do funcionario %d é: %s", i, funcionarios[i].cargo);
        printf("O salario do funcionario %d é: %.2f\n", i, funcionarios[i].salario);
        printf("A idade do funcionario %d é: %d\n", i, funcionarios[i].idade);
        printf("O departamento do funcionario %d é: %s\n", i, funcionarios[i].departamento);
    }

    while (getchar() != '\n');

    printf("\n");

}

void editar () {

}

void excluir () {

}



int main (void) {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int question;
    
    do {
        printf ("Que tarefa você deseja executar?\n\n1. Cadastrar Funcionario\n2. Listar Funcionarios\n3. Editar Cadastro \n4. Excluir Funcionario \n5. Sair\n\nDigite aqui sua resposta: ");
        scanf ("%d", &question);
        printf("\n");

        switch (question) {
            case 1:
                cadastro();
            break;

            case 2:
                listar();
            break;

            case 3:
                editar();
            break;

            case 4:
               excluir();
            break;

            case 5:
                printf("\n");
            break;

            default:
                printf ("Opção invalida\n\n");
            break;
        }

    } while (question != 5);
}


