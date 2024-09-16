#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void DecToBin(unsigned int in, int count, int* out)
{
    unsigned int mask = 1U << (count-1);
    int i;
    for (i = 0; i < count; i++) {
        out[i] = (in & mask) ? 1 : 0;
        in <<= 1;
    }
}

char PrintLetters(bool b, int n, char letters[]) {
    char letter;
    if (b) {
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
    return letter;
}

int main(int argc, char *argv[])
{
    int num;
    char term;
    while (true) {
        printf("Digite um numero entre 2 a 7:\n");
        if(scanf("%d%c", &num, &term) != 2 || term != '\n') {
            printf("Digite um valor numerico!\n");
            scanf("%*[^\n]");
        }
        else {
            if(num > 7 || num < 2)
                printf("Digite um valor valido!\n");
            else {
                int max = pow(2, num);
                int output[max];
                char inputLetters[7];
                char outputLetter;
                for (int i = 0; i < num; i++) {
                    printf("Digite o nome do valor de entrada %d: ", i+1);
                    scanf("%s", &inputLetters[i]);
                }
                printf("Digite o nome do valor de saida: ");
                scanf(" %c", &outputLetter);
                char newTerm;
                int newNum;
                //printf("Max e: %d\n", max);
                for (int i = 0; i < max; i++) {
                    printf("Digite o valor da saida %d:\n", i+1);
                    while (true) {
                        if(scanf("%d%c", &newNum, &newTerm) != 2 || newTerm != '\n') {
                            printf("Digite um valor numerico!\n");
                            scanf("%*[^\n]");
                        }
                        else {
                            if(newNum < 0 || newNum > 1)
                                printf("Digite um valor valido!('0' ou '1')\n");
                            else {
                                //printf("NewNum é: %d\n", newNum);
                                output[i] = newNum;
                                break;
                            }
                        }
                    }
                    //printf("I é: %d\n", i);
                }
                int binaryNum[num][max];
                int arrayValue = 8;
                int binNum[arrayValue];

                int minTermo[max];
                int minTermoCount = 0;
                int maxTermo[max];
                int maxTermoCount = 0;
                
                int sumOperations = 0;
                int multiOperations = 0;
                printf("\n");
                PrintLetters(true, num, inputLetters);
                printf(" | %c \n", outputLetter);
                for (int i = 0; i < max; i++)
                {
                    DecToBin(i, num, binNum);
                    for (int j = 0; j < num; j++) {
                        binaryNum[j][i] = binNum[j];
                        printf("%d ", binaryNum[j][i]);
                    }
                    if (output[i] == 1) {
                        minTermo[minTermoCount] = i;
                        minTermoCount++;
                    }
                    else {
                        maxTermo[maxTermoCount] = i;
                        maxTermoCount++;
                    }
                    printf("| %d\n", output[i]);
                    //printf("\n");
                }
                printf("MinTermo: ");
                for (int i = 0; i < minTermoCount; i++) {
                    for (int j = 0; j < num; j++) {
                        if(binaryNum[j][minTermo[i]] == 0) {
                            printf("!");
                        }
                        printf("%c", PrintLetters(false, j, inputLetters));
                        multiOperations++;
                    }
                    if (i+1 == minTermoCount)
                        break;
                    printf(" + ");
                    sumOperations++;
                }
                printf("\nNumero de operacoes +: %d", sumOperations);
                printf("\nNumero de operacoes *: %d", multiOperations);
                printf("\nMaxTermo: ");
                sumOperations = 0;
                multiOperations = 0;
                for (int i = 0; i < maxTermoCount; i++) {
                    for (int j = 0; j < num; j++) {
                        if(binaryNum[j][maxTermo[i]] == 1) {
                            printf("!");
                        }
                        printf("%c", PrintLetters(false, j, inputLetters));
                        sumOperations++;
                    }
                    if (i+1 == maxTermoCount)
                        break;
                    printf(" . ");
                    multiOperations++;
                }
                printf("\nNumero de operacoes *: %d", multiOperations);
                printf("\nNumero de operacoes +: %d", sumOperations);
                break;
            }
        }
    }
    return 0;
}