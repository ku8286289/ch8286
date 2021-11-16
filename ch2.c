#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define map_colrow 20

int main(void)
{
    int real_map[map_colrow][map_colrow];
    int raw_map[map_colrow][map_colrow];
    int start_map[map_colrow][map_colrow];
    int bomb_num = 0, bomb_X = 0, bomb_Y = 0;

    for (int i = 0; i < map_colrow; i++)
    {
        for (int j = 0; j < map_colrow; j++)
        {
            real_map[i][j] = 0;
            raw_map[i][j] = 0;
            start_map[i][j] = 0;
        }
    }
    srand((unsigned)time(NULL));

    printf("생성할 지뢰 개수: ");
    scanf("%d", &bomb_num);

    for (int i = 0; i < bomb_num; i++)
    {
        bomb_X = rand() % map_colrow;
        bomb_Y = rand() % map_colrow;

        real_map[bomb_X][bomb_Y] = 1;
    }

    int select_X = 0, select_Y = 0;

    while (1)
    {
        draw_map(start_map);
        printf("X좌표 입력: ");
        scanf("%d", &select_X);
        printf("Y좌표 입력: ");
        scanf("%d", &select_Y);

        select_X--;
        select_Y--;

        if (select_X >= map_colrow || select_Y >= map_colrow || select_X < 0 || select_Y < 0)
        {
            printf("좌표를 다시 지정해주세요.");
        }
        else if (real_map[select_X][select_Y] == 1)
        {
            start_map[select_X][select_Y] = 1;
            draw_map(start_map);
            printf("지뢰를 골랐습니다!");
            printf("\n");
            break;
        }
        else if (real_map[select_X][select_Y] == 2)
        {
            printf("이미 확인한 좌표입니다.");
            printf("\n");
        }
        else if (real_map[select_X][select_Y] == 0)
        {
            printf("지뢰가 아닙니다.");
            printf("\n");
            start_map[select_X][select_Y] = 2;
        }
    }
    char check_map = 0;
    printf("지뢰 위치를 확인하시겠습니까?(예 - Y, 아니오 - N)");
    scanf(" %c", &check_map);
    draw_map(real_map);

    return 0;
}