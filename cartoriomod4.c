#include <stdio.h>  // Biblioteca de comunicação com o usuário.
#include <stdlib.h> // Biblioteca de alocação de espaço em memória.
#include <locale.h> // Biblioteca de alocações de texto por região.
#include <string.h> // Biblioteca responsável por cuidar das strings.

int registro() //Função responsável por cadastrar os usuários no sistema
{
    //Início criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: \n");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); // Responsável por copiar os valores das strings.

    FILE *file;                 // Cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo no bando de dados.
    fprintf(file, cpf);         // Salva o valor variável.
    fclose(file);               // Fecha o arquivo.

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o Nome a ser cadastrado: \n");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o Sobrenome a ser cadastrado: \n");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o Cargo a ser cadastrado: \n");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("read"); //pausa a tela
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo, não localizado! \n");
    }

    while (fgets(conteudo, 200, file) != NULL)

    {
        printf("\n Essas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n \n");
    }
}

int deletar()
{
    printf("Você escolheu deletar nomes! \n");
    system("read");
}

int main()
{
    int opcao = 0; // Definindo variáveis
    int laco = 1;

    for (laco = 1; laco = 1;)

    {

        system("clear");

        setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

        printf("### Cartório do Wess ### \n\n"); // Início do menu
        printf("escolha a opção desejada: \n\n");
        printf("\t1 - Registrar nomes:\n");
        printf("\t2 - Consultar nomes:\n");
        printf("\t3 - Deletar nomes:\n\n");
        printf("Opção: "); // Fim do menu

        scanf("%d", &opcao); // armazenando a escolha do usuário

        system("clear"); // Limpa a tela

        switch (opcao)
        {
        case 1:
            registro();
            break;

        case 2:
            consulta();
            break;

        case 3:
            deletar();
            break;

        default:
            printf("Essa opção não está disponível! \n");
            system("read");
            break;
        } // Fim da seleção
    }
}