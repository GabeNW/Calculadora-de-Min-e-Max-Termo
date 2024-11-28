#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

// Função para converter decimal para binario
void DecToBin(unsigned int in, int count, int *out)
{
    // in - valor decimal
    // count - quantidade de bits
    // out - valor binario
    unsigned int mask = 1U << (count - 1);
    int i;
    for (i = 0; i < count; i++)
    {
        out[i] = (in & mask) ? 1 : 0;
        in <<= 1;
    }
}

// Função para mostrar as letras
char PrintLetters(bool b, int n, char letters[])
{
    char letter;
    if (b)
    {
        // Mostra as letras de entrada
        switch (n)
        {
        case 2:
            printf("%c %c", letters[0], letters[1]);
            break;

        case 3:
            printf("%c %c %c", letters[0], letters[1], letters[2]);
            break;

        case 4:
            printf("%c %c %c %c", letters[0], letters[1], letters[2], letters[3]);
            break;

        case 5:
            printf("%c %c %c %c %c", letters[0], letters[1], letters[2], letters[3], letters[4]);
            break;

        case 6:
            printf("%c %c %c %c %c %c", letters[0], letters[1], letters[2], letters[3], letters[4], letters[5]);
            break;

        case 7:
            printf("%c %c %c %c %c %c %c", letters[0], letters[1], letters[2], letters[3], letters[4], letters[5], letters[6]);
            break;

        default:
            printf("Valor invalido!\n");
        }
    }
    else
    {
        // Mostra a letra de saida
        switch (n)
        {
        case 0:
            letter = letters[0];
            break;

        case 1:
            letter = letters[1];
            break;

        case 2:
            letter = letters[2];
            break;

        case 3:
            letter = letters[3];
            break;

        case 4:
            letter = letters[4];
            break;

        case 5:
            letter = letters[5];
            break;

        case 6:
            letter = letters[6];
            break;

        default:
            printf("Valor invalido!\n");
        }
    }
    // Retorna a letra da saida
    return letter;
}

bool IsNumber(int *result)
{
    int n;
    char c;
    if (scanf("%d%c", &n, &c) != 2 || c != '\n')
    {
        // Descarta a entrada inválida
        scanf("%*[^\n]");
        return false;
    }
    else
    {
        // Atualiza o valor apontado pelo ponteiro
        *result = n;
        return true;
    }
}

void PrintTruthTable(int num, int max, int output[max], char outputLetter, char inputLetters[7])
{
    // Cria as dependencias para gerar a tabela verdade e os termos

    // Variaveis para armazenar cada valor do binario
    int binaryNum[num][max];
    // Variavel para armazenar o tamanho do array
    int arrayValue = 8;
    // Variavel para armazenar os valores binarios
    int binNum[arrayValue];

    // Variavel para armazenar os minTermos
    int minTermo[max];
    // Variavel para armazenar o numero de minTermos
    int minTermoCount = 0;
    // Variavel para armazenar os maxTermos
    int maxTermo[max];
    // Variavel para armazenar o numero de maxTermos
    int maxTermoCount = 0;

    // Variaveis para contar o numero de operações
    int sumOperations = 0;
    int multiOperations = 0;
    int invOperations = 0;

    // Mostra a tabela verdade
    printf("\n");
    // Mostra as letras de entrada no cabeçalho
    PrintLetters(true, num, inputLetters);
    // Mostra a letra de saida no cabeçalho
    printf(" | %c \n", outputLetter);

    // Loop para preencher a tabela verdade
    for (int i = 0; i < max; i++)
    {
        // Converte os valores decimais para binarios e mostra na saida
        DecToBin(i, num, binNum);
        for (int j = 0; j < num; j++)
        {
            // Adiciona os valores binarios na tabela verdade
            binaryNum[j][i] = binNum[j];
            printf("%d ", binaryNum[j][i]);
        }

        // Adiciona na lista de mintermos
        if (output[i] == 1)
        {
            minTermo[minTermoCount] = i;
            minTermoCount++;
        }
        // Adiciona na lista de maxtermos
        else
        {
            maxTermo[maxTermoCount] = i;
            maxTermoCount++;
        }

        // Mostra o valor de saida
        printf("| %d\n", output[i]);
    }

    // Mostra o MinTermo
    printf("\nMinTermo: \n");
    printf("%c = ", outputLetter);
    for (int i = 0; i < minTermoCount; i++)
    {
        // Percorre a lista de minTermos
        for (int j = 0; j < num; j++)
        {
            // Realiza uma inversão e adiciona na lista de operações
            if (binaryNum[j][minTermo[i]] == 0)
            {
                printf("~");
                invOperations++;
            }

            // Mostra a letra correspondente
            printf("%c", PrintLetters(false, j, inputLetters));

            // Adiciona na lista de operações de produto
            if (j + 1 != num)
            {
                printf(".");
                multiOperations++;
            }
        }

        // Verifica se a lista de minTermos acabou
        if (i + 1 == minTermoCount)
            break;
        // Adiciona na lista de operações de soma caso a lista de minTermos não tenha acabado
        printf(" + ");
        sumOperations++;
    }
    // Mostra o numero de operações
    printf("\nNumero de operacoes 'E' : %d", multiOperations);
    printf("\nNumero de operacoes 'OU' : %d", sumOperations);
    printf("\nNumero de operacoes 'NAO' : %d", invOperations);

    // Mostra o MaxTermo
    printf("\n");
    printf("\nMaxTermo: \n");
    printf("%c = ", outputLetter);
    // Reseta as variaveis
    sumOperations = 0;
    multiOperations = 0;
    invOperations = 0;
    for (int i = 0; i < maxTermoCount; i++)
    {
        // Adiciona parenteses no inicio da expressão
        printf("(");

        // Percorre a lista de maxTermos
        for (int j = 0; j < num; j++)
        {
            // Realiza uma inversão e adiciona na lista de operações
            if (binaryNum[j][maxTermo[i]] == 1)
            {
                printf("~");
                invOperations++;
            }

            // Mostra a letra correspondente
            printf("%c", PrintLetters(false, j, inputLetters));

            // Adiciona na lista de operações de soma
            if (j + 1 != num)
            {
                printf("+");
                sumOperations++;
            }
        }

        // Adiciona parenteses no final da expressão
        printf(")");

        // Verifica se a lista de maxTermos acabou
        if (i + 1 == maxTermoCount)
            break;
        // Adiciona na lista de operações de produto caso a lista de maxTermos não tenha acabado
        printf(" . ");
        multiOperations++;
    }
    // Mostra o numero de operações
    printf("\nNumero de operacoes 'E' : %d", multiOperations);
    printf("\nNumero de operacoes 'OU' : %d", sumOperations);
    printf("\nNumero de operacoes 'NAO' : %d", invOperations);
}

// Programa principal
int main()
{
    // Loop principal
    while (true)
    {
        // Variável para armazenar o valor digitado
        int num;
        // Verifica se o valor digitado é um numero
        printf("Digite um numero entre 2 a 7:\n");
        if (!IsNumber(&num))
        {
            // Caso o valor digitado não seja um numero
            printf("Digite um valor numerico!\n");
        }
        else
        {
            // Verifica se o valor digitado é valido
            if (num > 7 || num < 2)
                printf("Digite um valor valido!\n");
            else
            {
                // Variável para armazenar o tamanho da tabela verdade
                int max = pow(2, num);
                // Lista de valores de entrada
                int output[max];
                // String para armazenar as letras de entrada
                char inputLetters[7];
                // Variável para armazenar a letra de saida
                char outputLetter;

                // Recebe o nome das variáveis de entrada
                for (int i = 0; i < num; i++)
                {
                    printf("Digite o nome do valor de entrada %d: ", i + 1);
                    scanf("%s", &inputLetters[i]);
                }
                // Recebe o nome da variável de saida
                printf("Digite o nome do valor de saida: ");
                scanf(" %c", &outputLetter);

                // Verifica o método que o usuário prefere para preencher a tabela verdade
                printf("\nDigite 0 para preencher a tabela de saida com valores aleatorios\n");
                printf("Digite 1 para preencher a tabela de saida manualmente\n");

                // Variável para realizar a verificação
                int option;

                while (true)
                {
                    // Verifica se o valor digitado é um numero
                    if (!IsNumber(&option))
                    {
                        printf("Digite um valor numerico!\n");
                        printf("Digite 0 para preencher a tabela de saida com valores aleatorios\n");
                        printf("Digite 1 para preencher a tabela de saida manualmente\n");
                    }
                    else
                    {
                        // Verifica se o valor digitado é valido
                        if (option < 0 || option > 1)
                        {
                            printf("Digite um valor valido!('0' ou '1')\n");
                            printf("Digite 0 para preencher a tabela de saida com valores aleatorios\n");
                            printf("Digite 1 para preencher a tabela de saida manualmente\n");
                        }
                        else
                        {
                            srand(time(0));
                            if (option == 0)
                            {
                                // Preenche a tabela de saida com valores aleatórios
                                for (int i = 0; i < max; i++)
                                    output[i] = rand() % 2;
                            }
                            else
                            {
                                // Preenche a tabela de saida com valores manuais
                                for (int i = 0; i < max; i++)
                                {
                                    printf("Digite o valor da saida %d:\n", i);
                                    while (true)
                                    {
                                        // Verifica se o valor digitado é um numero
                                        if (!IsNumber(&option))
                                        {
                                            printf("Digite um valor numerico!\n");
                                            printf("Digite o valor da saida %d:\n", i);
                                        }
                                        else
                                        {
                                            // Verifica se o valor digitado é valido
                                            if (option < 0 || option > 1)
                                            {
                                                printf("Digite um valor valido!('0' ou '1')\n");
                                                printf("Digite o valor da saida %d:\n", i);
                                            }
                                            else
                                            {
                                                // Adiciona o valor digitado na tabela de saida
                                                output[i] = option;
                                                break;
                                            }
                                        }
                                    }
                                }
                                break;
                            }
                        }
                    }
                }

                // Mostra a tabela verdade
                PrintTruthTable(num, max, output, outputLetter, inputLetters);
                // Finaliza o loop principal
                break;
            }
        }
    }
    // Finaliza o programa
    return 0;
}