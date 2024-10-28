#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

int att1 = 3, att2 = 3, contador = 1;
char palabrasCorrectas[50][25];
char nombres[100][50] = {"Alice", "Bob", "Charlie"};
int puntuaciones[50] = {150, 200, 250};
int num_jugadores = 3;

void compararLetra(char answ[25], char resp, int jugador);
int compararPalabra(char answ[25]);
void printLogo();
void setRandomColor();

void guardarpuntaje(int id, int punt)
{
	if (punt > puntuaciones[id])
	{
		puntuaciones[id] = punt;
	}
}
void endgame(int punt1, int punt2, char user1[50], char user2[50], int id1, int id2)
{
	if (punt1 > punt2)
	{
		printf("\nEl jugador 1 %s es el ganador\n", user1);
        printf("\n+-+-+-+-+-+-+-+-+\n|P|U|N|T|A|J|E|S|\n+-+-+-+-+-+-+-+-+\n\n");
		printf("%s - %d\n", user1, punt1);
		printf("%s - %d\n\n", user2, punt2);
	}
	else if (punt2 > punt1)
	{
		printf("\nEl jugador 2 %s es el ganador\n", user2);
		printf("\n+-+-+-+-+-+-+-+-+\n|P|U|N|T|A|J|E|S|\n+-+-+-+-+-+-+-+-+\n\n");
		printf("%s. %d\n", user2, punt2);
		printf("%s. %d\n\n", user1, punt1);
	}
	else if (punt1 == punt1)
	{
		printf("\nEmpate\n");
		printf("\n+-+-+-+-+-+-+-+-+\n|P|U|N|T|A|J|E|S|\n+-+-+-+-+-+-+-+-+\n\n");
		printf("%s. %d\n", user1, punt1);
		printf("%s. %d\n\n", user2, punt2);
	}
	guardarpuntaje(id1, punt1);
	guardarpuntaje(id2, punt2);
}

int calcularPuntos(char palabra[100])
{
	int longitud = strlen(palabra);

	if (longitud > 7)
		return 6;
	else if (longitud == 7)
		return 5;
	else if (longitud == 6)
		return 4;
	else if (longitud == 5)
		return 3;
	else if (longitud == 4)
		return 2;
	else if (longitud < 4)
		return 1;

	return 0;
}

int buscar_jugador(char nombres[100][50], int num_jugadores, char nombre[50])
{
	int i;
	for (i = 0; i < num_jugadores; i++)
	{
		if (strcmp(nombres[i], nombre) == 0)
		{
			return i;
		}
	}
	return -1;
}

void ver_puntuaciones(char nombre_buscar[50], char nombres[100][50], int puntuaciones[100], int num_jugadores)
{

	int i, j;
	// Ordenar los jugadores por puntuaci�n de mayor a menor
	for (i = 0; i < num_jugadores - 1; i++)
	{
		for (j = 0; j < num_jugadores - i - 1; j++)
		{
			if (puntuaciones[j] < puntuaciones[j + 1])
			{
				int temp_puntuacion = puntuaciones[j];
				puntuaciones[j] = puntuaciones[j + 1];
				puntuaciones[j + 1] = temp_puntuacion;

				char temp_nombre[50];
				strcpy(temp_nombre, nombres[j]);
				strcpy(nombres[j], nombres[j + 1]);
				strcpy(nombres[j + 1], temp_nombre);
			}
		}
	}

	int posicion = buscar_jugador(nombres, num_jugadores, nombre_buscar);
	if (posicion == -1)
	{
		printf("\nERROR. El jugador %s no esta en el ranking.\n", nombre_buscar);
		return;
	}
	else
	{
		system("cls");
		printLogo();
		printf("Hola %s actualmente estas en el puesto %d del ranking", nombre_buscar, posicion + 1);
		printf(" con una puntuacion de %d puntos.\n\n", puntuaciones[posicion]);
	}
    printf(">>====================================<<\n");
    printf("|| ___    _   _  _ _  _____ _  _  ___ ||\n");
    printf("||| _ \\  /_\\ | \\| | |/ /_ _| \\| |/ __|||\n");
    printf("|||   / / _ \\| .` | ' < | || .` | (_ |||\n");
    printf("|||_|_\\/_/ \\_\\_|\\_|_|\\_\\___|_|\\_|\\___|||\n");
    printf("||                                    ||\n");
    printf(">>====================================<<\n\n");
	for (i = 0; i < num_jugadores; i++)
	{
		printf("%d. %s - Puntuacion: %d\n", i + 1, nombres[i], puntuaciones[i]);
	}

	// Buscar un jugador espec�fico y mostrar su posici�n en el ranking
}

int main()
{
	char nombre_buscar[50];
	char nul[100];
	srand(time(NULL));
	char nombre[50];
	int puntuacion;
	int id1, id2;
	int a = rand() % 27;
	;
	int b = 0;
	char letras[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int menu;
	int longitud;
	int punt1, punt2;
	char user1[50], user2[50], answ[30], resp;
	while (1)
	{
		char opcion = 's';
		system("cls");
		setRandomColor();
		printLogo();
        printf("Menu\n");
		printf("\n1.- Registrar jugadores.");
		printf("\n\n2.- Verificar puntuaciones.");
		printf("\n\n3.- Jugar.");
		printf("\n\n4.- Salir");
		printf("\n\nElige una opcion: ");
		scanf("%d", &menu);

		switch (menu)
		{

		case 1: // Registrar jugadores
			do
			{
				system("cls");
                setRandomColor();
                printLogo();
                printf("Bienvenido a registro, presione x si quiere regresar al menu\n");
				printf("\nIntroduce el nombre del nuevo jugador: ");
				scanf("%s", nombre);
				fflush(stdin);
				fflush(stdin);
				if (strcmp(nombre, "x") == 0)
				{
					break;
				}
				if (buscar_jugador(nombres, num_jugadores, nombre) != -1)
				{
					printf("\nEl nombre del jugador ya esta registrado. Introduzca un nombre diferente.\n");
				}
				else
				{
                    printf("\n+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+\n");
                    printf("|R|e|g|i|s|t|r|o| |e|x|i|t|o|s|o|\n");
                    printf("+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+\n");
					strcpy(nombres[num_jugadores], nombre);
					puntuaciones[num_jugadores] = 0;
					num_jugadores++;

					printf("\nDesea agregar otro jugador? (s/n): ");
					scanf(" %c", &opcion); // Espacio antes de %c para consumir cualquier car�cter de nueva l�nea residual
				}
			} while (opcion == 's' || opcion == 'S');

			break;

		case 2:

			do
			{
				system("cls");
				setRandomColor();
				printLogo();
				printf("Bienvenido a Verificacion de puntuaciones, presione x si quiere regresar al menu\n");
				printf("\n\nIntroduce el nombre del jugador que deseas buscar: ");
				scanf("%s", nombre_buscar);
				if (strcmp(nombre_buscar, "x") == 0)
				{
					break;
				}
				ver_puntuaciones(nombre_buscar, nombres, puntuaciones, num_jugadores);
				printf("\nDesea buscar otro jugador? (s/n): ");
				scanf(" %c", &opcion);
				if (opcion == 'n' || opcion == 'N')
				{
					break;
				}
			} while (1);
			break;

		case 3:

			system("cls");
			setRandomColor();
			printLogo();
			printf("\nBienvenido a el juego de palabras, presione x si quiere regresar al menu\n\n");

			b = 0;
			att1 = 3;
			att2 = 3;
			for (int i = 0; i < 50; i++)
			{
				palabrasCorrectas[i][0] = '\0';
			}
			char palabrasCorrectas[50][25];

			do
			{
				printf("\nIngresa el nombre del jugador 1: ");
				fflush(stdin);
				scanf("%s", user1);
				if (strcmp(user1, "x") == 0)
				{
					break;
				}
				if (buscar_jugador(nombres, num_jugadores, user1) == -1)
				{
					printf("\nEl nombre del jugador no se encuentra en nuestros usuarios registrados, por favor intentelo de nuevo.\n");
				}
				else
				{
					printf("\n%s eres el jugador 1.\n", user1);
					id1 = buscar_jugador(nombres, num_jugadores, user1);
					break;
				}
			} while (1);
			if (strcmp(user1, "x") != 0)
			{

				do
				{
					printf("\nIngresa el nombre del jugador 2: ");
					fflush(stdin);
					scanf("%s", user2);
					if (strcmp(user2, "x") == 0)
					{
						break;
					}
					if (buscar_jugador(nombres, num_jugadores, user2) == -1)
					{
						printf("\nEl nombre del jugador no se encuentra en nuestros usuarios registrados, por favor intentelo de nuevo.\n");
					}
					else
					{
						printf("\n%s eres el jugador 2.\n", user2);
						id2 = buscar_jugador(nombres, num_jugadores, user2);
						break;
					}
				} while (1);
				if (strcmp(user2, "x") != 0)
				{
					answ[0] = letras[a];
					while (b < 10)
					{
						// jugador 1
						longitud = strlen(answ);
						resp = answ[longitud - 1];
						do
						{
							Sleep(1700);
                            system("cls");
							setRandomColor();
							printLogo();
							printf(">>=======<<\n");
                            printf("||RONDA %d||\n", b + 1);
                            printf(">>=======<<\n");
							printf("\n%s ingresa una palabra que comienze con %c: ", user1, resp);
							fflush(stdin);
							scanf("%s", answ);
							strupr(answ);

							if (compararPalabra(answ) == 1)
							{
								printf("\nLa palabra %s ya la han puesto", answ);
								att1 = att1 - 1;
								printf("\n%s tiene %d intentos restantes.\n", user1, att1);
								Sleep(1200);
							}
							compararLetra(answ, resp, 1);
							if (answ[0] != resp)
							{
								printf("\n-2 puntos");
								punt1 = punt1 - 2;
								printf("\n+%d puntos totales", punt1);
								Sleep(1200);
							}
							if (att1 <= 0)
							{
								Sleep(2000);
                                system("cls");
                                printLogo();
								printf("Partida finalizada\n");
								endgame(punt1, punt2, user1, user2, id1, id2);
								b = 10;
								scanf("%s", nul);
								break;
							}
						} while (compararPalabra(answ) == 1 || answ[0] != resp);
						if (att2 <= 0 || att1 <= 0)
						{
							break;
						}
						punt1 = punt1 + calcularPuntos(answ);
						printf("\n+%d puntos", calcularPuntos(answ));
						printf("\n%d puntos totales", punt1);

						if (b < 10)
						{

							// jugador 2
							longitud = strlen(answ);
							resp = answ[longitud - 1];
							do
							{

								printf("\n\n%s ingresa una palabra que comienze con %c: ", user2, resp);
								fflush(stdin);
								scanf("%s", answ);
								strupr(answ);

								if (compararPalabra(answ) == 1)
								{
									printf("\nLa palabra %s ya la han puesto", answ);
									att2 = att2 - 1;
									printf("\n%s tienes %d intentos restantes.\n", user2, att2);
								}
								compararLetra(answ, resp, 2);
								if (answ[0] != resp)
								{
									printf("\n-2 puntos");
									punt2 = punt2 - 2;
									printf("\n+%d puntos totales", punt2);
									Sleep(1200);
								}
								if (att2 <= 0)
								{
									Sleep(2000);
                                    system("cls");
                                    printLogo();
									printf("Partida finalizada\n");
									endgame(punt1, punt2, user1, user2, id1, id2);
									b = 10;
									scanf("%s", nul);
									break;
								}
							} while (compararPalabra(answ) == 1 || answ[0] != resp);
							if (att2 > 0)
							{
								punt2 = punt2 + calcularPuntos(answ);
								printf("\n+%d puntos", calcularPuntos(answ));
								printf("\n%d puntos totales", punt2);
								b++;
							}
						}
					}
					if (att2 <= 0 || att1 <= 0)
					{
						break;
					}
					Sleep(2000);
					system("cls");
					printLogo();
					endgame(punt1, punt2, user1, user2, id1, id2);
					scanf("%s", nul);
					break;
				}
			}
			break;
		case 4:
			system("cls");
			setRandomColor();
            printf("                  _                             _                    \n");
            printf(" __ _ _ _ __ _ __(_)__ _ ___  _ __  ___ _ _    (_)_  _ __ _ __ _ _ _ \n");
            printf("/ _` | '_/ _` / _| / _` (_-< | '_ \\/ _ \\ '_|   | | || / _` / _` | '_|\n");
            printf("\\__, |_| \\__,_\\__|_\\__,_/__/ | .__/\\___/_|    _/ |\\_,_\\__, \\__,_|_|  \n");
            printf("|___/                        |_|             |__/     |___/          \n");
			exit(0);
			break;
		}
	}
	return 0;
}

void compararLetra(char answ[25], char resp, int jugador)
{
	if (answ[0] == resp)
	{
		strcpy(palabrasCorrectas[contador], answ);
		contador++;
	}
	else
	{
		printf("\nError la palabra ingresada no comienza con %c\n", resp);
		if (jugador == 1)
		{
			att1--;
			printf("\nJugador 1 tiene %d intentos restantes.\n", att1);
		}
		else if (jugador == 2)
		{
			att2--;
			printf("\nJugador 2 tiene %d intentos restantes.\n", att2);
		}
	}
}

int compararPalabra(char answ[25])
{
	int i;
	for (0; i <= 50; i++)
	{
		if (strcmp(answ, palabrasCorrectas[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}

void setRandomColor() {
    srand(time(NULL));
    int text = rand() % 16;
    char colorCommand[10];
    snprintf(colorCommand, sizeof(colorCommand), "color %X", text);
    system(colorCommand);
}

void printLogo(){
printf(" _____                                                                                                     _____ \n");
printf("( ___ )                                                                                                   ( ___ )\n");
printf(" |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | \n");
printf(" |   |                      d8b            d8b                                                             |   | \n");
printf(" |   |                      88P            ?88                                                             |   | \n");
printf(" |   |                     d88              88b                                                            |   | \n");
printf(" |   | ?88,.d88b, d888b8b  888   d888b8b    888888b   88bd88b d888b8b   .d888b,                            |   | \n");
printf(" |   | `?88'  ?88d8P' ?88  ?88  d8P' ?88    88P `?8b  88P'  `d8P' ?88   ?8b,                               |   | \n");
printf(" |   |   88b  d8P88b  ,88b  88b 88b  ,88b  d88,  d88 d88     88b  ,88b    `?8b                             |   | \n");
printf(" |   |   888888P'`?88P'`88b  88b`?88P'`88bd88'`?88P'd88'     `?88P'`88b`?888P'                             |   | \n");
printf(" |   |   88P'                                                                                              |   | \n");
printf(" |   |  d88                                                                                                |   | \n");
printf(" |   |  ?8P                                                                                                |   | \n");
printf(" |   |                                         d8b                                  d8b                    |   | \n");
printf(" |   |                                         88P                                  88P                    |   | \n");
printf(" |   |                                        d88                                  d88                     |   | \n");
printf(" |   |  d8888b  88bd88b  d8888b d888b8b   d888888   d8888b  88bd88b  d888b8b   d888888   d888b8b   .d888b, |   | \n");
printf(" |   | d8b_,dP  88P' ?8bd8P' `Pd8P' ?88  d8P' ?88  d8b_,dP  88P' ?8bd8P' ?88  d8P' ?88  d8P' ?88   ?8b,    |   | \n");
printf(" |   | 88b     d88   88P88b    88b  ,88b 88b  ,88b 88b     d88   88P88b  ,88b 88b  ,88b 88b  ,88b    `?8b  |   | \n");
printf(" |   | `?888P'd88'   88b`?888P'`?88P'`88b`?88P'`88b`?888P'd88'   88b`?88P'`88b`?88P'`88b`?88P'`88b`?888P'  |   | \n");
printf(" |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| \n");
printf("(_____)                                                                                                   (_____)\n\n\n");
}
