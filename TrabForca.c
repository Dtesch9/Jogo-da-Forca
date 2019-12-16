#include <stdio.h>
#include <string.h>
//#include<conio.h> // Windows
#include <stdlib.h>
#include <curses.h> // suprir conio, reconhecer o gets não é uma substituição perfeita

void desenho(int rvida, char palavra[25])
{
	printf("\n RESTAM %d VIDA(S)\n", rvida);
	switch (rvida)
	{
	case 6:
		printf("_____________   \n|.|         |   \n|.|        _|_\n|.|          \n|.|        \ \n|.|         \n|.| \n|.| \n|.| \n\n");
		break;

	case 5:
		printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|         \n|.|       \n|.| \n|.| \n|.| \n\n");
		break;

	case 4:
		printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|         |    \n|.|         \n|.| \n|.| \n|.| \n\n");
		break;

	case 3:
		printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|        /|    \n|.|         \n|.| \n|.| \n|.| \n\n");
		break;

	case 2:
		printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|        /|\\    \n|.|         \n|.| \n|.| \n|.| \n\n");
		break;

	case 1:
		printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|        /|\\    \n|.|        /  \n|.|  \n|.|  \n|.| \n\n");
		break;
	case 0:
		printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|        /|\\    \n|.|        / \\ \n|.|  \n|.|  \n|.| \n\n");

		printf("\n******************************************************");
		printf("\n***********            VOCÊ              *************");
		printf("\n***********            FOI               *************");
		printf("\n***********           MORTO              *************");
		printf("\n******************************************************\n");
		printf("\n A PALAVRA ERA: %s", palavra);
		break;
	}
}

int main()
{

	char tam_palavra, palavra[25], letra[25], ja_acertou[25], lacuna[25] = "_";
	int vida = 6, x, i, pontos = 0;

	FILE *arquivo;

	arquivo = fopen("Bicho.txt", "r");
	fgets(palavra, 79, arquivo);
	palavra[(strlen(palavra) - 1)] = '\0'; // removendo buffer
	printf("\n %s\n", palavra);

	/*printf("\n\nDigite a palavra secreta:\n\n");
	gets(palavra);*/

	system("clear");

	for (i = 0; i < strlen(palavra); i++)
	{

		lacuna[i] = '-';
		tam_palavra = strlen(palavra);
	}

	desenho(vida, palavra);

Tryagain:
	while (vida > 0)
	{

		x = 0;
		printf("\n %s \n", lacuna);
		printf("\n Digite uma letra: ");
		gets(letra);
		system("clear");

		//Loop para atribuição de letra caso acerte

		for (i = 0; i < strlen(palavra); i++) // entrega o tamanho da palavra em interiro
		{

			if (ja_acertou[i] == letra[0])
			{

				desenho(vida, palavra);
				printf("\n VOCÊ JÁ ACERTOU HAVIA ACERTADO ESSA LETRA !");

				goto Tryagain; // caso já tenha acertado, tentará novamente...
			}

			else if (letra[0] == palavra[i])
			{

				lacuna[i] = palavra[i]; // retira lacuna '-' e atribui a letra
				pontos++;				// pontos corresponde ao acerto
				x++;					// caso acerte uma letra x ganha "1" para verificação de acerto
				ja_acertou[i] = palavra[i];
			}
		}

		// Verifica caso tenha perdido toda vida ou acertado uma letra ou a palavra

		if (x == 0) // se x == 0 você errou uma letra
		{

			vida--;
			if (vida == 0) // se vida for 0 você não recebe errou apenas perde e é isso
			{
				desenho(vida, palavra);
			}
			else
			{

				desenho(vida, palavra);
				printf("\n VOCÊ ERROU!");
			}
		}

		else // caso x != 0 então acertou uma letra
		{
			if (pontos == tam_palavra) // número de acertos for igual ao tamanho da palavra, logo você acertou a palavra
			{						   // fim do jogo com vitória

				desenho(vida, palavra);
				printf("\n******************************************************");
				printf("\n***********          PARABÉNS            *************");
				printf("\n***********            VOCÊ              *************");
				printf("\n***********           VENCEU             *************");
				printf("\n******************************************************\n");
				printf("\n A PALAVRA E: %s", palavra);
				break;
			}
			else
			{
				desenho(vida, palavra);
				printf("\n VOCE ACERTOU UMA LETRA!");
			}
		}
	}
	printf("\n\n");
	return 0;
}