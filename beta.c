#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

int i, j;
int player_i = 1;
int player_j = 1;
int possui_chave = 0;
int hp = 30;
int hp_max = 30;
char fase1[15][15] = 

{
	//0    1    2    3    4    5    6    7    8    9    10   11   12   13   14
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}, //0
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //1
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //2
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', '*'}, //3
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //4
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //5
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*'}, //6
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*'}, //7
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*'}, //8
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', '@', ' ', '*'}, //9
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*'}, //10
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //11
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'D'}, //12
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //13
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}, //14
};

void linhaCol(int lin, int col){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col - 1,lin - 1}); //coorddenada na tela
    
    //Cursor invisível
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
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

void PrimeiraFase(){
	char input;
	linhaCol(1,1);
	
	while(1){
		system("cls");
		GerarFase1(fase1);
		printf("\n\tHP: %d/%d\n", hp, hp_max);
		input = getch();
		switch (input){
    		case 'w':
            	if (fase1[player_i - 1][player_j] != '*'){
                	player_i--;
            	}
            	break;
            
        	case 'a':
				if ((fase1[player_i][player_j - 1] == '*') && (player_i == 7) && (player_j - 5 == 0)){
					fase1[7][4] = ' ';
					fase1[7][3] = ' ';
					fase1[7][2] = ' ';
					fase1[7][1] = '@';
					player_j--;
				}

            	else if ((fase1[player_i][player_j - 1] != '*')){
                	player_j--;
            	}

				if ((player_i == 7) && (player_j - 1 == 0) && (possui_chave == 0)){
					printf("\tAperte I para pegar a chave.\n");
					input = getch();
					switch (input){
						case 'i':
							possui_chave = 1;
							fase1[7][1] = ' ';
							fase1[9][12] = ' ';
							fase1[12][14] = '=';
							break;

						default:
							player_j++;
							break;
							
					}
					
				}

            	break;
            
        	case 's':

            	if (fase1[player_i + 1][player_j] != '*'){
                	player_i++;
            	}

            	break;
            
        	case 'd':

				if((fase1[player_i][player_j + 1] == 'D') && (possui_chave == 0)){
					printf("\tA porta esta trancada.\n");
					input = getch();
				}

            	else if ((fase1[player_i][player_j + 1] != '*')){
                	player_j++;
            	}

				else if((fase1[player_i][player_j] == '=') && (possui_chave == 1)){
					printf("\n\nFase 1 concluida!\n");
					system("pause");
				}

            	break;
		}
	}
}

int main(){
	
	PrimeiraFase();
	
	return 0;
}
