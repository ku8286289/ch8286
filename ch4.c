#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
re:
    printf("지뢰찾기를 시작합니다.");
    printf("\n");
    printf("지뢰가 설치될 맵의 크기를 지정하고");
    printf("\n");
    printf("그 안에 들어갈 지뢰의 수를 지정하세요.");
    printf("\n");
    printf("시작하려면 Y를 눌러주세요 : ");

    char start_Y = 0;
    scanf(" %c", &start_Y);

    if (start_Y == 'Y')
    {
        printf("시작되었습니다.");
        printf("\n\n\n");
    }
    else
    {
        printf("종료됩니다.");
        return 0;
    }

    int map_col = 0, map_row = 0;
    printf("맵의 행의 크기를 지정하시오 : ");
    scanf("%d", &map_row);
    printf("맵의 열의 크기를 지정하시오 : ");
    scanf("%d", &map_col);

    int** real_map = (int**)malloc(sizeof(int*) * map_row);
    int** start_map = (int**)malloc(sizeof(int*) * map_row);

    for (int i = 0; i < map_row; i++)
    {
        real_map[i] = (int*)malloc(sizeof(int) * map_col);
        start_map[i] = (int*)malloc(sizeof(int) * map_col);
    }


    int bomb_num = 0, bomb_X = 0, bomb_Y = 0;

    for (int i = 0; i < map_col; i++)
    {
        for (int j = 0; j < map_row; j++)
        {
            real_map[i][j] = 0;
            start_map[i][j] = 0;
        }
    }
    srand((unsigned)time(NULL));

    printf("생성할 지뢰 개수: ");
    scanf("%d", &bomb_num);

    for (int i = 0; i < bomb_num; i++)
    {
        while (1)
        {
            bomb_X = rand() % map_col;
            bomb_Y = rand() % map_row;

            if (real_map[bomb_X][bomb_Y] == 1)
            {
            }
            else
            {
                real_map[bomb_X][bomb_Y] = 1;
                break;
            }
        }
    }

    int select_X = 0, select_Y = 0;

    while (1)
    {
        for (int i = 0; i < map_col; i++)
        {
            for (int j = 0; j < map_row; j++)
            {
                if (start_map[i][j] == 0)
                {
                    printf("■");
                }
                else if (start_map[i][j] == 1)
                {
                    printf("※");
                }
                else if (start_map[i][j] == 2)
                {
                    printf("○");
                }
            }
            printf("\n");
        }

        printf("X좌표 입력: ");
        scanf("%d", &select_X);
        printf("Y좌표 입력: ");
        scanf("%d", &select_Y);

        select_X--;
        select_Y--;

        if (select_X >= map_col || select_Y >= map_row || select_X < 0 || select_Y < 0)
        {
            printf("좌표를 다시 지정해주세요.\n");
        }
        else if (real_map[select_X][select_Y] == 1)
        {
            start_map[select_X][select_Y] = 1;
            for (int i = 0; i < map_col; i++)
            {
                for (int j = 0; j < map_row; j++)
                {
                    if (start_map[i][j] == 0)
                    {
                        printf("■");
                    }
                    else if (start_map[i][j] == 1)
                    {
                        printf("※");
                    }
                    else if (start_map[i][j] == 2)
                    {
                        printf("○");
                    }
                }
                printf("\n");
            }
            printf("지뢰를 골랐습니다!");
            printf("\n");
            break;
        }
        else if (start_map[select_X][select_Y] == 2)
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
    printf("\n");

    if (check_map == 'Y')
    {
        for (int i = 0; i < map_col; i++)
        {
            for (int j = 0; j < map_row; j++)
            {
                if (real_map[i][j] == 0)
                {
                    printf("■");
                }
                else if (real_map[i][j] == 1)
                {
                    printf("※");
                }
                else if (real_map[i][j] == 2)
                {
                    printf("○");
                }
            }
            printf("\n");
        }
    }
    printf("수고하셨습니다.");
    printf("\n");
    printf("다시 시작하려면 Y를 눌러주세요: ");

    char restart = 0;
    scanf(" %c", &restart);

    if (restart = 'Y')
    {
        printf("맵을 재구성합니다.");
        printf("\n");
        goto re;
    }
    else
    {
        printf("게임이 종료되었습니다.");
        printf("\n");
    }

    for (int i = 0; i < map_row; i++)
    {
        free(real_map[i]); //가로공간 메모리 해제
        free(start_map[i]);
    }


    free(real_map); //세로공간 메모리 해제
    free(start_map);

    return 0;
}