#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAX = 50;

void start_matrix(int A[][MAX], int nl, int nc, int PointP[], int PlayerP[]);
void show_matrix(int A[][MAX], int nl, int nc);
void move_player(int A[][MAX], int x, int y, int PlayerP[]);
bool verifyOver(int PointP[], int PlayerP[]);
bool verifyMove(int PlayerP[], int movel, int movec, int nl, int nc);

int main()
{
    int nl = 0, nc = 0, dir = 0;
    cout << "Digite o Numero de linhas e o Numero de colunas separados por espaco: " << endl;
    cin >> nl >> nc;
    cout << nl << " " << nc;

    int matrix[MAX][MAX];
    int Player_pos[2] = {(nl-1), (nc/2)};
    int Point_pos[2] = {(nl/2),(nc/2)};
    int movel[4] = {0,1,0,-1};
    int movec[4] = {-1,0,1,0};

    start_matrix(matrix, nl, nc, Point_pos, Player_pos);

    while(true){
        do{
            system("cls");
            show_matrix(matrix, nl, nc);

            cout << "-Guia de Direcoes-" << endl;
            cout << "1 - Esquerda \n2 - Baixo \n3 - Direita \n4 - Cima" << endl;
            cout << "Digite o valor correspondente a direcao em que voce deseja andar:" << endl;
            cin >> dir;
        }while(dir < 1 || dir > 4);
        if(verifyMove(Player_pos, movel[dir-1], movec[dir-1], nl, nc)){
            move_player(matrix, movel[dir-1], movec[dir-1], Player_pos);
            if(verifyOver(Point_pos, Player_pos)){
                break;
            }
        }
    }
    system("cls");
    cout << "Voce Finalizou o GAME - CONGRATULATIONS";
    return 0;
}

void start_matrix(int A[][MAX], int nl, int nc, int PointP[], int PlayerP[]){
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            A[i][j] = 0;
        }
    }
    A[PointP[0]][PointP[1]] = 5;
    A[PlayerP[0]][PlayerP[1]] = 2;
}

void show_matrix(int A[][MAX], int nl, int nc){
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void move_player(int A[][MAX], int movel, int movec, int PlayerP[]){
    A[PlayerP[0]][PlayerP[1]] = 0;
    A[PlayerP[0]+movel][PlayerP[1]+movec] = 2;
    PlayerP[0] += movel;
    PlayerP[1] += movec;
}

bool verifyOver(int PointP[], int PlayerP[]){
    for(int i = 0; i < 2; i++){
        if(PointP[i] != PlayerP[i]){
            return false;
        }
    }
    return true;
}

bool verifyMove(int PlayerP[], int movel, int movec, int nl, int nc){
    if ((PlayerP[0]+movel >= 0 && PlayerP[0]+movel < nl) && PlayerP[1]+movec >= 0 && PlayerP[1]+movec < nc){
        return true;
    }else{
        return false;
    }
}
