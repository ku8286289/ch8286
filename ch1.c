#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define map_colrow 20

int main(void) {
    int map[map_colrow][map_colrow];
    int bomb_num = 0, bomb_X = 0, bomb_Y = 0;

    for (int i = 0; i < map_colrow; i++) {
        for (int j = 0; j < map_colrow; j++) {
            map[i][j] = 0;
        }
    }
    srand((unsigned)time(NULL));

    printf("생성할 지뢰 개수: ");
    scanf("%d", &bomb_num);

    for (int i = 0; i < bomb_num; i++) {
        bomb_X = rand() % map_colrow;
        bomb_Y = rand() % map_colrow;

        map[bomb_X][bomb_Y] = 1;
    }

    for (int i = 0; i < map_colrow; i++) {
        for (int j = 0; j < map_colrow; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}