#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

int i, j;
char fase1[15][15] = 

{
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
};

//7, 4

int player_i = 1;
int player_j = 1;
int possui_chave = 0;

void linhaCol(int lin, int col){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col-1,lin-1}); //coorddenada na tela
    
    //funcao para deixar o cursor invisivel
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void GerarFase1(char fase1[15][15]){
    for (i = 0; i < 15; i++){
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
	fase1[9][12] = '@';
	fase1[12][14] = 'D';
	linhaCol(1,1);
	char input;
	
	while(1){
		system("cls");
		GerarFase1(fase1);
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

            	else if ((fase1[player_i][player_j - 1] != '*') && (fase1[player_i][player_j - 1] != fase1[7][1])){
                	player_j--;
            	}

				if ((player_i == 7) && (player_j - 1 == 1)){
					printf("\n\nAperte I para pegar a chave.\n");
					system("pause");
					switch (input){
						case 'i':
							possui_chave = 1;
							fase1[7][1] = ' ';
							fase1[12][14] = '=';
							break;

					}
					
				}

            	break;
            
        	case 's':
				if((fase1[player_i + 1][player_j] == fase1[9][12])){

				}

            	if (fase1[player_i + 1][player_j] != '*'){
                	player_i++;
            	}

            	break;
            
        	case 'd':
            	if ((fase1[player_i][player_j + 1] != '*') && (fase1[player_i][player_j + 1] != 'D')){
                	player_j++;
            	}

				else if((fase1[player_i][player_j + 1] == '=') && (possui_chave == 1)){
					
				}

            	break;
		}
	}
}

int main(){
	
	PrimeiraFase();
	
	return 0;
}
