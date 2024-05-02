#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int i, j;
char fase1[15][15] = 

{
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'D', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
};

int player_i = 1;
int player_j = 1;

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
	GerarFase1(fase1);
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
            	if (fase1[player_i][player_j - 1] != '*'){
                	player_j--;
            	}
            	break;
            
        	case 's':
            	if (fase1[player_i + 1][player_j] != '*'){
                	player_i++;
            	}
            	break;
            
        	case 'd':
            	if (fase1[player_i][player_j + 1] != '*'){
                	player_j++;
            	}
            	break;
		}
	}
}

void linhaCol(int lin, int col){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col-1,lin-1}); //coorddenada na tela
    
    //funcao para deixar o cursor invisivel
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

int main(){
	
	PrimeiraFase();
	
	return 0;
}
