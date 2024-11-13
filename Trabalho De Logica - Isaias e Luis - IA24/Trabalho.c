#include <stdio.h>
#include <locale.h>

#define maximoDeFuncionarios 100

void cadastro () {

}

void editar () {

}

void excluir () {

}

void listar () {

}

int main (void) {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int question;
    
    do {
        printf ("Que tarefa você deseja executar?\n\n1. Cadastrar Funcionario\n2. Editar Cadastro\n3. Excluir Funcionario\n4. Listar Funcionarios\n5. Sair\n\nDigite aqui sua resposta: ");
        scanf ("%d", &question);

        switch (question) {
            case 1:
                cadastro;
            break;

            case 2:
                editar;
            break;

            case 3:
                excluir;
            break;

            case 4:
                listar;
            break;

            case 5:
            break;

            default:
                printf ("Opção invalida\n");
            break;
        }

    } while (question != 5);
}