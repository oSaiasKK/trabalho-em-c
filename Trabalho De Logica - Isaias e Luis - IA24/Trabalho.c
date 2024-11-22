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
    int teste, resultado = -1, parar = 0;

    do {
        printf("Por favor digite seu ID: ");
        scanf("%d", &teste);

        for (int j = 0; j > cont; j++) {
            if (teste == funcionarios[j].id) {
                resultado++;
            }
        }

        if (resultado >= 0) {
            printf ("-O ID em questão já está em uso-\n\n");
        } else if (resultado == -1) {
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
    
}

void listar () {

    if (cont == 0) {
        printf("\n-Não há cadastros ainda-\n");
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

    printf("\n");

}

void editar () {
    int idCopia;

    if (cont == 0) {
        printf("\n-Não há cadastros ainda-\n\n");
    } else if (cont >= 1) {
        printf("Digite o ID do funcionario: ");
        scanf("%d", &idCopia);

        for (int i = 0; i < cont; i++) {
            if (funcionarios[i].id == idCopia) {
                int questão;

                do {
                    printf("O que você deseja editar?\n\n1. ID do funcionario\n2. Nome do funcionario\n3. Cargo do funcionario\n4. Salario do funcionario\n5. Idade do funcionaro\n6. departamento do funcionario\n7. Sair\n\nDigite sua resposta: ");
                    scanf("%d", &questão);

                    switch (questão) {
                        case 1:
                            int teste, resultado = -1;

                            printf("Digite o novo ID do Funcionario: ");
                            scanf("%d", &teste);

                            for (int j = 0; j < cont; j++) {
                                if (teste == funcionarios[j].id) {
                                    resultado++;
                                }
                            }

                            if (resultado >= 0) {
                                printf ("\nO ID em questão já está em uso. tente novamente.\n\n");
                            } else if (resultado == -1) {
                                funcionarios[idCopia].id = teste;
                                printf("Id mudado com sucesso\n\n");
                            }
                        break;

                        case 2:
                            printf("Digite o novo nome do funcionario: ");
                            getchar();
                            fgets(funcionarios[idCopia].nome, sizeof(funcionarios[idCopia].nome), stdin);
                        break;

                        case 3:
                            printf("Por favor digite seu cargo: ");
                            getchar();
                            fgets(funcionarios[idCopia].cargo, sizeof(funcionarios[idCopia].cargo), stdin);
                        break;

                        case 4:
                            printf("Por favor digite seu salario: ");
                            scanf("%f", &funcionarios[idCopia].salario);
                        break;

                        case 5:
                            printf("Por favor digite seu idaide: ");
                            scanf("%d", &funcionarios[idCopia].idade);
                        break;

                        case 6:
                            printf("Por favor digite seu departamento: ");
                            getchar();
                            fgets(funcionarios[idCopia].departamento, sizeof(funcionarios[idCopia].departamento), stdin);
                        break;

                        case 7:
                        break;
                        
                        default:
                            printf ("-Opção invalida-\n\n");
                        break;
                    }

                } while (questão != 7);

            } else {
                printf("\n-ID não encontrado-\n\n");
            }
        }
    } 
}

void excluir () {
    if (cont == 0) {
        printf("\n-Não há cadastros ainda-\n\n");
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
                printf("Funcionario excluído com sucesso.\n\n");
                return;
            }
        }
        printf("\n-Funcionario não encontrado-\n\n");
    }
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


