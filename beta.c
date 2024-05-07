#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int i, j;
int player_i, player_j;
int monster_i, monster_j;
int hp = 30;
int hp_max = 30;
char input;
char cheat[10];
char fase1[15][15] = 

{
	//0    1    2    3    4    5    6    7    8    9    10   11   12   13   14
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}, //0
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //1
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //2
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', '*'}, //3
    {'*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //4
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //5
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', '*', '*'}, //6
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*'}, //7
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*'}, //8
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', '@', ' ', '*'}, //9
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*'}, //10
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //11
    {'*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'D'}, //12
    {'*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //13
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}, //14
};

char fase2[30][30] =

{
	//0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25   26   27   28   29
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}, //0
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //1
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //2
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //3
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //4
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //5
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //6
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //7
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //8
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //9
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //10
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //11
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //12
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //13
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //14
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //15
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //16
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //17
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //18
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //19
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //20
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //21
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //22
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //23
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //24
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //25
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //26
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //27
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //28
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}, //29
};

void Cursor_Invisivel(){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void linhaCol(int lin, int col){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col - 1,lin - 1}); //coorddenada na tela
    Cursor_Invisivel();
}

void mov_monstro1(){
	srand(time(NULL));
	switch ((rand() % 4) + 1){
		case 1:
			if (fase2[monster_i - 1][monster_j] != '*'){
				fase2[monster_i][monster_j] = ' ';
                monster_i--;
				fase2[monster_i][monster_j] = 'X';
            } else {
				fase2[monster_i][monster_j] = ' ';
                monster_i++;
				fase2[monster_i][monster_j] = 'X';
			}
            break;
		
		case 2:
			if ((fase2[monster_i][monster_j - 1] != '*')){
				fase2[monster_i][monster_j] = ' ';
                monster_j--;
				fase2[monster_i][monster_j] = 'X';
            } else {
				fase2[monster_i][monster_j] = ' ';
                monster_j++;
				fase2[monster_i][monster_j] = 'X';
			}
			break;
		
		case 3:
			if ((fase2[monster_i + 1][monster_j] != '*')){
				fase2[monster_i][monster_j] = ' ';
                monster_i++;
				fase2[monster_i][monster_j] = 'X';
            } else {
				fase2[monster_i][monster_j] = ' ';
                monster_i--;
				fase2[monster_i][monster_j] = 'X';
			}
			break;
		
		case 4:
			if ((fase2[monster_i][monster_j + 1] != '*')){
				fase2[monster_i][monster_j] = ' ';
                monster_j++;
				fase2[monster_i][monster_j] = 'X';
            } else {
				fase2[monster_i][monster_j] = ' ';
                monster_j--;
				fase2[monster_i][monster_j] = 'X';
			}
			break;
	}
}

void PrimeiraFase();
void SegundaFase();
void cheats();

void cheats(){
	printf("\n\nCodigo de trapaca:\n> ");
	fgets(cheat, 10, stdin);
	fflush(stdin);
}

void TutorialA(){
	printf("Fase 1: \n\n\tDimensao: 15x15 \n\tElementos: \n\n\t1 - Jogador \n\t2 - Parede \n\t3 - Porta \n\t4 - Chave\n\n");
	printf("Fase 2: \n\n\tDimensao: 30x30 \n\tElementos: \n\n\t1 - Todos os elementos da Fase 1 \n\t2 - Botao \n\t3 - Espinhos \n\t4 - Monstro Nivel 1\n\n");
	printf("Fase 3: \n\n\tDimensao: 60x60 \n\tElementos: \n\n\t1 - Todos os elementos das Fases 1 e 2 \n\t2 - Teletransporte \n\t3 - Monstro Nivel 2\n\n");
	printf("Aperte Z para voltar.\n");
}

void TutorialB(){
	printf("Comandos:\n\n");
    printf("\tW: Anda uma casa para cima.\n");
    printf("\tA: Anda uma casa para a esquerda.\n");
    printf("\tS: Anda uma casa para baixo.\n");
    printf("\tD: Anda uma casa para a direita.\n");
    printf("\tI: Interage com elementos do mapa.\n\n");
	printf("Aperte Z para voltar.\n");
}

void TutorialC(){
	printf("Elementos do jogo:\n\n");
    printf("\t* - Parede \n\t& - jogador \n\tD - Porta fechada \n\t= - Porta aberta \n\t@ - Chave \n\tO - Botao \n\t# - Espinho \n\tX - Monstro nivel 1 \n\tV - Monstro nivel 2\n\n");
	printf("Aperte Z para voltar.\n");
}

void GerarTutorial(){
    Cursor_Invisivel();
    system("cls");
	printf("Qual conhecimento deseja buscar?\n\n\tA - Fases\n\tB - Comandos\n\tC - Elementos do jogo\n\tZ - Sair\n");
    input = getch();
	system("cls");
    switch(toupper(input)){
        case 'A':
            TutorialA();
		    input = getch();
            switch (toupper(input)){
                case 'Z':
		            system("cls");
                    GerarTutorial();
            }
            break;
            
        case 'B':
            TutorialB();
		    input = getch();
            switch (toupper(input)){
                case 'Z':
		            system("cls");
                    GerarTutorial();
            }
            break;
            
        case 'C':
            TutorialC();
		    input = getch();
            switch (toupper(input)){
                case 'Z':
		            system("cls");
                    GerarTutorial();
            }
            break;
                
        case 'Z':
			printf("\nSaindo");
    		for (i = 0; i < 5; i++){
        	Sleep(200);
        	printf(".");
    		}
            break;
    }
}

void Tutorial(){
    system("cls");
	printf("\nBem-vindo ao tutorial!\n\n\tCarregando");
    for (i = 0; i < 5; i++){
        Sleep(200);
        printf(".");
    }
    system("cls");
    GerarTutorial();
	PrimeiraFase();
}

void GerarFase1(char fase1[15][15]){
	printf("\n\n");
    for (i = 0; i < 15; i++){
		printf("\t");
        for (j = 0; j < 15; j++){ 
        	if (i == player_i && j == player_j){
                printf("&");
            } else {
                printf("%c", fase1[i][j]);
            }
		}
		
		printf("\n");
    }
}

void GerarFase2(char fase2[30][30]){
	printf("\n\n");
    for (i = 0; i < 30; i++){
		printf("\t");
        for (j = 0; j < 30; j++){ 
        	if (i == player_i && j == player_j){
                printf("&");
            } else {
                printf("%c", fase2[i][j]);
            }
		}
		
		printf("\n");
    }
}

void PrimeiraFase(){
	player_i = 1;
	player_j = 1;
	linhaCol(1, 1);
	
	while(1){
		system("cls");
		GerarFase1(fase1);
		printf("\n\tHP: %d/%d\n", hp, hp_max);
		input = getch();
		switch (toupper(input)){
			case 'W':
            	if (fase1[player_i - 1][player_j] != '*'){
                	player_i--;
            	}
            	break;
            
            case 'A':
        		
				if ((fase1[player_i][player_j - 1] == '@') && (player_i != 7)){
					printf("\n\nAperte I para pegar a chave.\n");
					input = getch();
					switch (toupper(input)){
						case 'I':
							printf("\nNao aconteceu nada... parece que a chave era falsa.\n\n");
							system("pause");
						
						default:
							break;
					}
				} else if ((fase1[player_i][player_j - 1] == '*') && (player_i == 7) && (player_j - 5 == 0)){
					fase1[7][4] = ' ';
					fase1[7][3] = ' ';
					fase1[7][2] = ' ';
					fase1[7][1] = '@';
					player_j--;
				} else if ((fase1[player_i][player_j - 1] != '*')){
                	player_j--;
            	}

				if ((fase1[7][1] == '@') && (player_i == 7) && (player_j - 1 == 0)){
					printf("\n\nAperte I para pegar a chave.\n");
					input = getch();
					switch (toupper(input)){
						case 'I':
							fase1[7][1] = ' ';
							fase1[9][12] = ' ';
							fase1[12][14] = '=';
							player_j++;
							break;

						default:
							player_j++;
							break;
					}
					
				}

            	break;
            
            case 'S':
				
				if (fase1[player_i + 1][player_j] == '@'){
					printf("\n\nAperte I para pegar a chave.\n");
					input = getch();
					switch (toupper(input)){
						case 'I':
							printf("Nao aconteceu nada... parece que a chave era falsa.\n\n");
							system("pause");
						
						default:
							break;
					}
				} else if (fase1[player_i + 1][player_j] != '*'){
                	player_i++;
            	} 
				
            	break;
            
            case 'D':
				if (fase1[player_i][player_j + 1] == '@'){
					printf("\n\nAperte I para pegar a chave.\n");
					input = getch();
					switch (toupper(input)){
						case 'I':
							printf("Nao aconteceu nada... parece que a chave era falsa.\n\n");
							system("pause");
						
						default:
							break;
					}
				} else if (fase1[player_i][player_j + 1] == 'D'){
					printf("\n\nA porta esta trancada.\n");
					input = getch();
				} else if ((fase1[player_i][player_j + 1] != '*')){
                	player_j++;
            	}

				if ((fase1[12][14] == '=') && (player_i == 12) && (player_j == 14)){
					printf("\n\nFase 1 concluida!\n");
					system("pause");
					SegundaFase();
				}

            	break;
		}
	}
}

void SegundaFase(){
	player_i = 27;
	player_j = 1;
	monster_i = 7;
	monster_j = 14;
	fase2[monster_i][monster_j] = 'X';
	linhaCol(27, 1);

	while(1){
		system("cls");
		GerarFase2(fase2);
		printf("\n\tHP: %d/%d\n", hp, hp_max);
		input = getch();
		switch(toupper(input)){
			case 'W':
				if (fase2[player_i - 1][player_j] != '*'){
                	player_i--;
					mov_monstro1();
            	}
            	break;
			
			case 'A':
				if ((fase2[player_i][player_j - 1] != '*')){
                	player_j--;
					mov_monstro1();
            	}
				break;

			case 'S':
				if (fase2[player_i + 1][player_j] != '*'){
                	player_i++;
					mov_monstro1();
            	}

            	break;
			case 'D':
				if ((fase2[player_i][player_j + 1] != '*')){
                	player_j++;
					mov_monstro1();
            	}
				break;

		}
	}
}

int main(){
	
	Tutorial();
	//PrimeiraFase();
	//SegundaFase();
	//cheats();
	
	return 0;
}
