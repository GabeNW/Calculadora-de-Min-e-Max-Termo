#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

//Função para converter decimal para binario
void DecToBin(unsigned int in, int count, int* out)
{
    //in - valor decimal
    //count - quantidade de bits
    //out - valor binario
    unsigned int mask = 1U << (count-1);
    int i;
    for (i = 0; i < count; i++) {
        out[i] = (in & mask) ? 1 : 0;
        in <<= 1;
    }
}

//Função para mostrar as letras
char PrintLetters(bool b, int n, char letters[]) {
    char letter;
    if (b) {
        //Mostra as letras de entrada
        switch (n)
        {
            case 2 :
            printf("%c %c", letters[0], letters[1]);
            break;
            
            case 3 :
            printf("%c %c %c", letters[0], letters[1], letters[2]);
            break;
            
            case 4 :
            printf("%c %c %c %c", letters[0], letters[1], letters[2], letters[3]);
            break;
            
            case 5 :
            printf("%c %c %c %c %c", letters[0], letters[1], letters[2], letters[3], letters[4]);
            break;
            
            case 6 :
            printf("%c %c %c %c %c %c", letters[0], letters[1], letters[2], letters[3], letters[4], letters[5]);
            break;
            
            case 7 :
            printf("%c %c %c %c %c %c %c", letters[0], letters[1], letters[2], letters[3], letters[4], letters[5], letters[6]);
            break;
            
            default :
            printf ("Valor invalido!\n");
        }
    }
    else {
        //Mostra a letra de saida
        switch (n) {
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
            printf ("Valor invalido!\n");
        }
    }
    //Retorna a letra da saida
    return letter;
}

//Programa principal
int main(int argc, char *argv[])
{
    //Cria as dependencias para receber os valores digitados pelo usuário
    int num;
    char term;
    //Loop principal
    while (true) {
        //Verifica se o valor digitado é um numero
        printf("Digite um numero entre 2 a 7:\n");
        if(scanf("%d%c", &num, &term) != 2 || term != '\n') {
            printf("Digite um valor numerico!\n");
            scanf("%*[^\n]");
        }
        else {
            //Verifica se o valor digitado é valido
            if(num > 7 || num < 2)
                printf("Digite um valor valido!\n");
            else {
                //Cria algumas variáveis baseadas no valor digitado
                int max = pow(2, num);
                int output[max];
                char inputLetters[7];
                char outputLetter;
                //Recebe os valores de entrada e saida digitados pelo usuário
                for (int i = 0; i < num; i++) {
                    printf("Digite o nome do valor de entrada %d: ", i+1);
                    scanf("%s", &inputLetters[i]);
                }
                printf("Digite o nome do valor de saida: ");
                scanf(" %c", &outputLetter);

                //Verifica o método que o usuário prefere para preencher a tabela verdade
                printf("\nDigite 0 para preencher a tabela de saida com valores aleatorios\n");
                printf("Digite 1 para preencher a tabela de saida manualmente\n");
                //Variáveis para realizar a verificação
                int option;
                char optionTerm;
                //Verifica se o valor digitado é um numero
                if(scanf("%d%c", &option, &optionTerm) != 2 || optionTerm != '\n') {
                    printf("Digite um valor numerico!\n");
                    scanf("%*[^\n]");
                }
                else {
                    //Verifica se o valor digitado é valido
                    if(option < 0 || option > 1)
                        printf("Digite um valor valido!('0' ou '1')\n");
                    else {
                        srand(time(0));
                        if (option == 0) {
                            //Preenche a tabela de saida com valores aleatórios
                            for(int i = 0; i < max; i++) {
                                output[i] = rand() % 2;
                            }
                        }
                        else {
                            //Preenche a tabela de saida com valores manuais

                            //Variáveis para realizar a verificação
                            int newNum;
                            char newTerm;
                            for (int i = 0; i < max; i++) {
                                printf("Digite o valor da saida %d:\n", i);
                                while (true) {
                                    //Verifica se o valor digitado é um numero
                                    if(scanf("%d%c", &newNum, &newTerm) != 2 || newTerm != '\n') {
                                        printf("Digite um valor numerico!\n");
                                        scanf("%*[^\n]");
                                    }
                                    else {
                                        //Verifica se o valor digitado é valido
                                        if(newNum < 0 || newNum > 1)
                                            printf("Digite um valor valido!('0' ou '1')\n");
                                        else {
                                            //Adiciona o valor digitado na tabela de saida
                                            output[i] = newNum;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        //Cria as dependencias para gerar a tabela verdade e os termos
                        int binaryNum[num][max];
                        int arrayValue = 8;
                        int binNum[arrayValue];

                        int minTermo[max];
                        int minTermoCount = 0;
                        int maxTermo[max];
                        int maxTermoCount = 0;
                        
                        //Variaveis para contar o numero de operações
                        int sumOperations = 0;
                        int multiOperations = 0;
                        int invOperations = 0;

                        //Mostra a tabela verdade
                        printf("\n");
                        PrintLetters(true, num, inputLetters);
                        printf(" | %c \n", outputLetter);
                        for (int i = 0; i < max; i++)
                        {
                            //Converte os valores decimais para binarios e mostra na saida
                            DecToBin(i, num, binNum);
                            for (int j = 0; j < num; j++) {
                                binaryNum[j][i] = binNum[j];
                                printf("%d ", binaryNum[j][i]);
                            }
                            //Adiciona na lista de mintermos
                            if (output[i] == 1) {
                                minTermo[minTermoCount] = i;
                                minTermoCount++;
                            }
                            //Adiciona na lista de maxtermos
                            else {
                                maxTermo[maxTermoCount] = i;
                                maxTermoCount++;
                            }
                            printf("| %d\n", output[i]);
                        }

                        //Mostra o MinTermo
                        printf("MinTermo: \n");
                        printf("%c = ", outputLetter);
                        for (int i = 0; i < minTermoCount; i++) {
                            for (int j = 0; j < num; j++) {
                                if(binaryNum[j][minTermo[i]] == 0) {
                                    //Realiza uma inversão e adiciona na lista de operações
                                    printf("~");
                                    invOperations++;
                                }
                                printf("%c", PrintLetters(false, j, inputLetters));
                                if (j+1 != num) {
                                    //Adiciona na lista de operações de produto
                                    printf(".");
                                    multiOperations++;
                                }
                            }
                            if (i+1 == minTermoCount)
                                break;
                            //Adiciona na lista de operações de soma
                            printf(" + ");
                            sumOperations++;
                        }
                        //Mostra o numero de operações
                        printf("\nNumero de operacoes 'E' : %d", multiOperations);
                        printf("\nNumero de operacoes 'OU' : %d", sumOperations);
                        printf("\nNumero de operacoes 'NAO' : %d", invOperations);

                        //Mostra o MaxTermo
                        printf("\n");
                        printf("\nMaxTermo: \n");
                        printf("%c = ", outputLetter);
                        //Reseta as variaveis
                        sumOperations = 0;
                        multiOperations = 0;
                        invOperations = 0;
                        for (int i = 0; i < maxTermoCount; i++) {
                            printf("(");
                            for (int j = 0; j < num; j++) {
                                if(binaryNum[j][maxTermo[i]] == 1) {
                                    //Realiza uma inversão e adiciona na lista de operações
                                    printf("~");
                                    invOperations++;
                                }
                                printf("%c", PrintLetters(false, j, inputLetters));
                                if (j+1 != num) {
                                    //Adiciona na lista de operações de soma
                                    printf("+");
                                    sumOperations++;
                                }
                            }
                            printf(")");
                            if (i+1 == maxTermoCount)
                                break;
                            //Adiciona na lista de operações de produto
                            printf(" . ");
                            multiOperations++;
                        }
                        //Mostra o numero de operações
                        printf("\nNumero de operacoes 'E' : %d", multiOperations);
                        printf("\nNumero de operacoes 'OU' : %d", sumOperations);
                        printf("\nNumero de operacoes 'NAO' : %d", invOperations);
                        //Finaliza o loop principal
                        break;
                    }
                }
            }
        }
    }
    //Finaliza o programa
    return 0;
}