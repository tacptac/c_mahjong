#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ALL 136
#define NONE -1

int all[ALL];//id 0〜33
char *suhai[] = {"萬", "索", "筒"};
char *jihai[] = {"東", "南", "西", "北", "白", "発", "中"};
int tehai[4][13];
int tsumo[4];
int remain = ALL;

char *getName(int id);
void shuffle(int *array,int size);
void showAll();
int tsumoru();
void ripai(int player);

int main()
{
    //初期化
    for (int i = 0; i < ALL/4; i++){
        for (int j = 0; j < 4; j++){
            all[i * 4 + j] = i;
        }
    }
    unsigned int now = (unsigned int)time(0);
    srand(now);
    shuffle(all,ALL);
    //配牌
    for (int i = 0; i < 4;i++){
        for (int j = 0; j < 13;j++){
            tehai[i][j] = tsumoru();
        }
        ripai(i);
    }

    //ゲームスタート
    while(1){

    }
    showAll();
}

void ripai(int player){
    for (int i = 0; i < 13; i++){
        for (int j = 0; j < 13; j++){
            if(i == j)continue;
            if (tehai[player][j] > tehai[player][i])
            {
                int tmp = tehai[player][j];
                tehai[player][j] = tehai[player][i];
                tehai[player][i] = tmp;
            }
        }
    }
}

int tsumoru(){
    int result = all[remain];
    all[remain] = NONE;
    remain--;
    return result;
}

void showAll(){
    printf("ALL\n\t");
    for(int i = 0; i < ALL; i++){
        printf("%s,",getName(all[i]));
    }
    printf("\n");
    for (int i = 0; i < 4;i++){
        printf("PLAYER%d\n\t",i+1);
        for (int j = 0; j < 13; j++)
        {
            printf("%s,",getName(tehai[i][j]));
        }
        printf("\n");
    }
}

void shuffle(int *array,int size)
{
    for(int i = 0; i < size; i++){
        int j = rand()%size;
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
    }
}

char* getName(int id){
    if(id==NONE)return "×";
    char *b;
    b = (char *)malloc(sizeof(char) * 3);
    id += 1;

    if (id >= 28 && id < 35)
    {
        b = jihai[6 + (id - 34)];
        return b;
    }

    int n = 0;
    if (id >= 10 && id < 19){id -= 9;n=1;}
    else if (id >= 19 && id < 28){id -= 18;n=2;}
    b[0] = '0'+id;
    strcat(b, suhai[n]);
    return b;
}