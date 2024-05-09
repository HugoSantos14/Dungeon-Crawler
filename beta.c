#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>

int i, j;
int player_i, player_j;
int monster_i, monster_j;
int tamlin, tamcol;
int player_hp = 30;
int monster1_hp = 30;
int fase_concluida = 0;
char input;
char cheat[10];

void PrimeiraFase();
void SegundaFase();
void cheats();
void Cursor_Invisivel();
void linhaCol(int lin, int col);
void textColor(int letras, int fundo);
void box(int lin1, int col1, int lin2, int col2);
int menu(int lin1, int col1, int qtd, char lista[3][40]);

//COR DA LETRA
enum{BLACK,                //0
    BLUE,                  //1
    GREEN,                 //2
    CYAN,                  //3
    RED,                   //4
    MAGENTA,               //5
    BROWN,                 //6
    LIGHTGRAY,             //7
    DARKGRAY,              //8
    LIGHTBLUE,             //9
    LIGHTGREEN,            //10
    LIGHTCYAN,             //11
    LIGHTRED,              //12
    LIGHTMAGENTA,          //13
    YELLOW,                //14
    WHITE                  //15
};  

  //COR DO FUNDO
enum{_BLACK = 0,                 //0
    _BLUE = 16,                  //1
    _GREEN = 32,                 //2
    _CYAN = 48,                  //3
    _RED = 64,                   //4
    _MAGENTA = 80,               //5
    _BROWN = 96,                 //6
    _LIGHTGRAY = 112,            //7
    _DARKGRAY = 128,             //8
    _LIGHTBLUE = 144,            //9
    _LIGHTGREEN = 160,           //10
    _LIGHTCYAN = 176,            //11
    _LIGHTRED = 192,             //12
    _LIGHTMAGENTA = 208,         //13
    _YELLOW = 224,               //14
    _WHITE = 240                 //15       
};

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
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'D'}, //3
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //4
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //5
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //6
	{'*', ' ', ' ', ' ', ' ', '#', '*', '*', '*', '*', '*', '#', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //7
	{'*', ' ', ' ', ' ', ' ', '#', '*', '*', '*', '*', '*', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //8
	{'*', ' ', ' ', ' ', ' ', '#', '*', '*', '*', '*', '*', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //9
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //10
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //11
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //12
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //13
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //14
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //15
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //16
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //17
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //18
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //19
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '*', '*', '*', '*', '*', '#', ' ', ' ', ' ', ' ', '*'}, //20
	{'*', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '*', '*', '*', '*', '*', '#', ' ', ' ', ' ', ' ', '*'}, //21
	{'*', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '*', '*', '*', '*', '*', '#', ' ', ' ', ' ', ' ', '*'}, //22
	{'*', '#', ' ', '#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //23
	{'*', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //24
	{'*', '*', '*', '*', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //25
	{'*', ' ', ' ', '*', '#', '#', ' ', '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //26
	{'*', 'A', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //27
	{'*', ' ', ' ', '*', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //28
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

void textColor(int letras, int fundo){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letras + fundo);
}

void box(int lin1, int col1, int lin2, int col2){
    tamlin = lin2 - lin1;
    tamcol = col2 - col1;
    for (i = col1; i <= col2; i++){
        linhaCol(lin1, i);
        printf("%c", 196);
        linhaCol(lin2, i);
        printf("%c", 196);
    }

    for (j = lin1; j <= lin2; j++){
        linhaCol(j, col1);
        printf("%c", 179);
        linhaCol(j, col2);
        printf("%c", 179);
    }

    for (i = lin1 + 1; i < lin2; i++){
        for (j = col1 + 1; j < col2; j++){
            linhaCol(i, j);
            printf(" ");
        }
    }

    linhaCol(lin1, col1);
    printf("%c", 218);
    linhaCol(lin1, col2);
    printf("%c", 191);
    linhaCol(lin2, col1);
    printf("%c", 192);
    linhaCol(lin2, col2);
    printf("%c", 217);
}

int menu(int lin1, int col1, int qtd, char lista[3][40]){
    int opc = 1, lin2, col2, linha,i,tamMaxItem, tecla;
     
    //calcula as coordenadas
    tamMaxItem = strlen(lista[0]);
    //tamanho maximo do item
    for(i = 1; i < qtd; i++){
        if (strlen(lista[i]) > tamMaxItem){
            tamMaxItem = strlen(lista[i]); 
        }
    }
    lin2 = lin1 + (qtd * 2 + 2);
    col2 = col1 + tamMaxItem + 4;
     
    //Monta Tela
    textColor(WHITE, _BLACK);
    setlocale(LC_ALL, "C");
    box(lin1, col1, lin2, col2);
    setlocale(LC_ALL, "");
    //laÃ¯Â¿Â½o das opcÃ¯Â¿Â½es
    while(1){
    
        linha = lin1 + 2;
        for(i = 0; i < qtd; i++){           
            if (i + 1 == opc){
                textColor(BLACK, _LIGHTGREEN);
            } else {
                textColor(WHITE, _BLACK);
            }
            linhaCol(linha, col1 + 2);
            printf("%s", lista[i]);
            linha += 2;
        }
       
        //Aguarda tecla
        linhaCol(1, 1);
        tecla = getch();
        linhaCol(22, 1);
        //OpÃ¯Â¿Â½Ã¯Â¿Â½o
        if (tecla == 27){               //ESC
            opc = 0;
            break;
        } else if (tecla == 13){        //ENTER
            break;
        } else if (tecla == 119 || tecla == 87){        //W
            if(opc > 1){
                opc--;                  // se a opÃƒÂ§ÃƒÂ£o for maior que 1, pode voltar 
            }
        } else if (tecla == 115 || tecla == 83){        //S
            if (opc < qtd){
                opc++;                  //Se a opÃƒÂ§ÃƒÂ£o for menor que quantidade de itens, posso avanÃƒÂ§ar    
            }
        }
    }
    return opc;
}

void mov_monstro1(){
	srand(time(NULL));
	switch ((rand() % 4) + 1){
		case 1:
			if (fase2[monster_i - 1][monster_j] == '&'){
				player_hp -= 10;
			} else if (fase2[monster_i - 1][monster_j] == ' '){
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
			if (fase2[monster_i][monster_j - 1] == '&'){
				player_hp -= 10;
			} else if ((fase2[monster_i][monster_j - 1] == ' ')){
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
			if (fase2[monster_i + 1][monster_j] == '&'){
				player_hp -= 10;
			} else if ((fase2[monster_i + 1][monster_j] == ' ')){
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
			if (fase2[monster_i][monster_j + 1] == '&'){
				player_hp -= 10;
			} else if ((fase2[monster_i][monster_j + 1] == ' ')){
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

void cheats(){
	printf("\n\nCodigo de trapaca:\n> ");
	fgets(cheat, 10, stdin);
	fflush(stdin);
}

void TutorialA(){
	system("cls");
	printf("Fase 1: \n\n\tDimensao: 15x15 \n\tElementos: \n\n\t1 - Jogador \n\t2 - Parede \n\t3 - Porta \n\t4 - Chave\n\n");
	printf("Fase 2: \n\n\tDimensao: 30x30 \n\tElementos: \n\n\t1 - Todos os elementos da Fase 1 \n\t2 - Botao \n\t3 - Espinhos \n\t4 - Monstro Nivel 1\n\n");
	printf("Fase 3: \n\n\tDimensao: 60x60 \n\tElementos: \n\n\t1 - Todos os elementos das Fases 1 e 2 \n\t2 - Teletransporte \n\t3 - Monstro Nivel 2\n\n");
	printf("Aperte Z para voltar.\n");
}

void TutorialB(){
	system("cls");
	printf("Comandos:\n\n");
    printf("\tW: Anda uma casa para cima.\n");
    printf("\tA: Anda uma casa para a esquerda.\n");
    printf("\tS: Anda uma casa para baixo.\n");
    printf("\tD: Anda uma casa para a direita.\n");
    printf("\tI: Interage com elementos do mapa.\n\n");
	printf("Aperte Z para voltar.\n");
}

void TutorialC(){
	system("cls");
	printf("Elementos do jogo:\n\n");
    printf("\t* - Parede \n\t& - jogador \n\tD - Porta fechada \n\t= - Porta aberta \n\t@ - Chave \n\tO - Botao \n\t# - Espinho \n\tX - Monstro nivel 1 \n\tV - Monstro nivel 2\n\n");
	printf("Aperte Z para voltar.\n");
}

void GerarTutorial(){
	int opc;
	int sair;
    char lista[4][40] = {"Fases\t\t\t\t\t", "Comandos\t\t\t\t\t", "Elementos do jogo\t\t\t\t\t", "Voltar\t\t\t\t\t"};
	system("cls");
    
    setlocale(LC_ALL,"");
		linhaCol(9, 11);
		printf("Qual conhecimento deseja?");
        opc = menu(10, 11, 4, lista);
    while(1){
    
        if (opc == 4){
            break;
        } else {
			switch (opc){
				case 1:
					TutorialA();
					input = getch();
					switch (toupper(input)){
						case 'Z':
							system("cls");
							GerarTutorial();
							break;
					}
					
					break;
				
				case 2:
					TutorialB();
					input = getch();
					switch (toupper(input)){
						case 'Z':
							system("cls");
							GerarTutorial();
							break;
					}
					break;
				
				case 3:
					TutorialC();
					input = getch();
					switch (toupper(input)){
						case 'Z':
							system("cls");
							GerarTutorial();
							break;
					}
					break;
			}
			break;
		}
    }
    textColor(WHITE, _BLACK);
    system("cls");
}

void Tutorial(){
    system("cls");
	printf("\nBem-vindo ao tutorial!\n\n\tCarregando");
    for (i = 0; i < 5; i++){
        Sleep(300);
        printf(".");
    }
    system("cls");
    GerarTutorial();
}

void GerarFase1(char fase1[15][15]){
	printf("\n\n");
    for (i = 0; i < 15; i++){
		printf("\t");
        for (j = 0; j < 15; j++){ 
        	if (i == player_i && j == player_j){
        		textColor(YELLOW, _BLACK);
                printf("&");
            } else if (fase1[i][j] == '@'){
            	textColor(YELLOW, _BLACK);
            	printf("%c", fase1[i][j]);
			} else if (fase1[i][j] == 'D'){
				textColor(LIGHTMAGENTA, _BLACK);
				printf("%c", fase1[i][j]);
			} else if (fase1[i][j] == '='){
				textColor(LIGHTGREEN, _BLACK);
				printf("%c", fase1[i][j]);
			} else {
            	textColor(DARKGRAY, _BLACK);
                printf("%c", fase1[i][j]);
            }
            textColor(WHITE, _BLACK);
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
        		textColor(YELLOW, _BLACK);
                printf("&");
            } else if (fase2[i][j] == '@'){
            	textColor(YELLOW, _BLACK);
            	printf("%c", fase2[i][j]);
			} else if (fase2[i][j] == 'D'){
				textColor(LIGHTMAGENTA, _BLACK);
				printf("%c", fase2[i][j]);
			} else if (fase2[i][j] == '='){
				textColor(LIGHTGREEN, _BLACK);
				printf("%c", fase2[i][j]);
			} else if (fase2[i][j] == 'X'){
				textColor(RED, _BLACK);
				printf("%c", fase2[i][j]);
			} else if (fase2[i][j] == '#'){
				textColor(LIGHTGRAY, _BLACK);
				printf("%c", fase2[i][j]);
			}else {
            	textColor(DARKGRAY, _BLACK);
                printf("%c", fase2[i][j]);
            }
            textColor(WHITE, _BLACK);
		}
		
		printf("\n");
    }
}

void PrimeiraFase(){
	fase_concluida = 0;
	system("cls");
	printf("\nCarregando");
	for (i = 0; i < 5; i++){
        Sleep(300);
        printf(".");
    }
	player_i = 1;
	player_j = 1;
	linhaCol(1, 1);
	
	while(1){
		system("cls");
		GerarFase1(fase1);
		printf("\n\tEvans: %d/30 HP\n", player_hp);
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
							printf("\nNao aconteceu nada... parece que a chave era falsa.\n");
							system("pause");
							printf("\nParece que tem algo escrito nessa chave... um enigma!\n");
							system("pause");
							printf("\n\"No oeste se encontra a sua resposta. Sua saida daqui. A reliquia que dara luz a sua fuga.\"\n");
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
							printf("\nNao aconteceu nada... parece que a chave era falsa.\n");
							system("pause");
							printf("\nParece que tem algo escrito nessa chave... um enigma!\n");
							system("pause");
							printf("\n\"No oeste se encontra a sua resposta. Sua saida daqui. A reliquia que dara luz a sua fuga.\"\n");
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
							printf("\nNao aconteceu nada... parece que a chave era falsa.\n");
							system("pause");
							printf("\nParece que tem algo escrito nessa chave... um enigma!\n");
							system("pause");
							printf("\n\"No oeste se encontra a sua resposta. Sua saida daqui. A reliquia que dara luz a sua fuga.\"\n");
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
					fase_concluida = 1;
					break;
				}

            	break;
		}
		if (fase_concluida == 1){
			printf("\n\nFase 1 concluida!\n");
			system("pause");
			SegundaFase();
			break;
		}
	}
}

void SegundaFase(){
	fase_concluida = 0;
	system("cls");
	printf("\nCarregando");
	for (i = 0; i < 5; i++){
        Sleep(300);
        printf(".");
    }
	player_i = 27;
	player_j = 1;
	monster_i = 7;
	monster_j = 14;
	fase2[monster_i][monster_j] = 'X';
	linhaCol(27, 1);

	while(1){
		system("cls");
		GerarFase2(fase2);
		printf("\n\tEvans: %d/30 HP\n", player_hp);
		printf("\tMonstro nivel 1: %d/30 HP\n", monster1_hp);
		if (player_hp == 0){
			printf("\n\nFIM DE JOGO\n");
			system("pause");
			system("cls");
			printf("\nCarregando");
			for (i = 0; i < 5; i++){
        		Sleep(300);
        		printf(".");
    		}
    		player_hp = 30;
    		fase1[7][4] = '*';
			fase1[7][3] = '*';
			fase1[7][2] = '*';
			fase1[7][1] = '*';
			fase1[9][12] = '@';
			fase1[12][14] = 'D';
			fase2[monster_i][monster_j] = ' ';
			break;
		}
		input = getch();
		switch(toupper(input)){
			case 'W':
				if (fase2[player_i - 1][player_j] == '#'){
					if (player_hp != 0){
						player_hp -= 10;
						player_i = 27;
						player_j = 1;
					}
					mov_monstro1();
				} else if (fase2[player_i - 1][player_j] == 'X'){
					if (player_hp != 0){
						player_hp -= 10;
						player_i = 27;
						player_j = 1;
					}
					mov_monstro1();
				} else if (fase2[player_i - 1][player_j] != '*'){
                	player_i--;
					mov_monstro1();
            	}
				
            	break;
			
			case 'A':
				if (fase2[player_i][player_j - 1] == '#'){
					if (player_hp != 0){
						player_hp -= 10;
						player_i = 27;
						player_j = 1;
					}
					mov_monstro1();
				} else if (fase2[player_i][player_j - 1] == 'X'){
					if (player_hp != 0){
						player_hp -= 10;
						player_i = 27;
						player_j = 1;
					}
					mov_monstro1();
				} else if ((fase2[player_i][player_j - 1] != '*')){
                	player_j--;
					mov_monstro1();
            	}
				break;

			case 'S':
				if (fase2[player_i + 1][player_j] == '#'){
					if (player_hp != 0){
						player_hp -= 10;
						player_i = 27;
						player_j = 1;
					}
					mov_monstro1();
				} else if (fase2[player_i + 1][player_j] == 'X'){
					if (player_hp != 0){
						player_hp -= 10;
						player_i = 27;
						player_j = 1;
					}
					mov_monstro1();
				} else if (fase2[player_i + 1][player_j] != '*'){
                	player_i++;
					mov_monstro1();
            	}

            	break;

			case 'D':
				if (fase2[player_i][player_j + 1] == '#'){
					if (player_hp != 0){
						player_hp -= 10;
						player_i = 27;
						player_j = 1;
					}
					mov_monstro1();
				} else if (fase2[player_i][player_j + 1] == 'X'){
					if (player_hp != 0){
						player_hp -= 10;
						player_i = 27;
						player_j = 1;
					}
					mov_monstro1();
				} else if (fase2[player_i][player_j + 1] == 'D'){
					printf("\n\nA porta esta trancada.\n");
					input = getch();
				} else if ((fase2[player_i][player_j + 1] != '*')){
                	player_j++;
					mov_monstro1();
            	}
				break;
		}
	}
}

int main(){
	
    int opc;
    char lista[3][40] = {"Jogar\t\t\t\t\t", "Tutorial\t\t\t\t\t", "Sair\t\t\t\t\t"};
	system("cls");
    
    setlocale(LC_ALL,"");
    while(1){
		linhaCol(9, 10);
		printf("Dungeon Crawler (Beta)");
        opc = menu(10, 11, 3, lista);
    
        if (opc == 3){
            break;
        } else {
			switch (opc){
				case 1:
					PrimeiraFase();
					system("cls");
					break;
				
				case 2:
					Tutorial();
					system("cls");
					break;
			}
		}
    }

    textColor(WHITE, _BLACK);
	system("cls");
    printf("\nSaindo");
    for (i = 0; i < 5; i++){
    	Sleep(300);
        printf(".");
    }
	
	return 0;
}
