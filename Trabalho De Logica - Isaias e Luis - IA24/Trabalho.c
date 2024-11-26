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

int cont = 0;

void cadastro () {
    int teste, parar = 0;

    do {
        int resultado = 0;

        printf("Por favor digite seu ID: ");
        scanf("%d", &teste);

        for (int i = -1; i < cont; i++) {
            if (teste == funcionarios[i].id) {
                resultado++;
            }
        }

        if (resultado > 0) {
            printf ("\n-O ID em questão já está em uso-\n\n");
        } else if (resultado == 0) {
            funcionarios[cont].id = teste;
            parar = 1;
        }

    } while (parar != 1);

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

    printf("====================================\n\n");
    
}

void listar () {

    if (cont == 0) {
        printf("-Não há cadastros ainda-\n\n");
    } else if (cont >= 1) {
        for (int i = 0 ; i < cont ; i++) {
            printf("O ID do funcionario %d é: %d\n", i, funcionarios[i].id);
            printf("O nome do funcionario %d é: %s", i, funcionarios[i].nome);
            printf("O cargo do funcionario %d é: %s", i, funcionarios[i].cargo);
            printf("O salario do funcionario %d é: %.2f\n", i, funcionarios[i].salario);
            printf("A idade do funcionario %d é: %d\n", i, funcionarios[i].idade);
            printf("O departamento do funcionario %d é: %s\n", i, funcionarios[i].departamento);
        }
    }

    while (getchar() != '\n');

    printf("====================================\n\n");

}

void editar () {
    int idCopia;

    if (cont == 0) {
        printf("-Não há cadastros ainda-\n\n");
    } else if (cont >= 1) {
        printf("Digite o ID do funcionario: ");
        scanf("%d", &idCopia);

        for (int i = 0; i < cont; i++) {
            if (funcionarios[i].id == idCopia) {
                int question = 0;

                do {
                    printf("O que você deseja editar?\n\n1. Nome do funcionario\n2. Cargo do funcionario\n3. Salario do funcionario\n4. Idade do funcionaro\n5. departamento do funcionario\n6. Sair\n\nDigite sua resposta: ");
                    scanf("%d", &question);

                    switch (question) {
                        case 1:
                            printf("Digite o novo nome do funcionario: ");
                            getchar();
                            fgets(funcionarios[i].nome, sizeof(funcionarios[i].nome), stdin);
                        break;

                        case 2:
                            printf("Por favor digite seu cargo: ");
                            getchar();
                            fgets(funcionarios[i].cargo, sizeof(funcionarios[i].cargo), stdin);
                        break;

                        case 3:
                            printf("Por favor digite seu salario: ");
                            scanf("%f", &funcionarios[i].salario);
                        break;

                        case 4:
                            printf("Por favor digite seu idaide: ");
                            scanf("%d", &funcionarios[i].idade);
                        break;

                        case 5:
                            printf("Por favor digite seu departamento: ");
                            getchar();
                            fgets(funcionarios[i].departamento, sizeof(funcionarios[i].departamento), stdin);
                        break;

                        case 6:
                        printf("\n");
                        break;
                        
                        default:
                            printf ("\n-Opção invalida-\n\n");
                        break;
                    }

                } while (question != 6);

            } else {
                printf("\n-ID não encontrado-\n\n");
            }
        }
    } 
    printf("====================================\n\n");
}

void excluir () {
    if (cont == 0) {
        printf("-Não há cadastros ainda-\n\n");
    } else if (cont >= 1) {
        int teste, i;
        printf("Digite o ID do funcionario a ser excluído: ");
        scanf("%d", &teste);

        for (i = 0; i < cont; i++) {
            if (funcionarios[i].id == teste) { 
                for (int j = i; j < cont - 1; j++) {
                    funcionarios[j] = funcionarios[j + 1]; 
                }
                cont--; 
                printf("\n-Funcionario excluído com sucesso-\n\n");
                printf("====================================\n\n");

                return;
            }
        }
        printf("\n-Funcionario não encontrado-\n\n");
    }
}



int main (void) {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int question = 0;
    
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
            break;

            default:
                printf ("-Opção invalida-\n\n");
            break;
        }

    } while (question != 5);

    printf("====================================\n\n");
}
