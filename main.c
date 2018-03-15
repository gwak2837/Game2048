#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_2048.h"

int main()
{
	unsigned int board[LENGTH][LENGTH] = { 0, };
	char direction;
	char continue1 = 'y';
	unsigned int score = 0;
	int input_direction = 1; // while문 탈출 조건
	int check_2048;
	int temp = 0;

	srand((unsigned int)time(NULL));
	
	while (1)
	{
		if ((check_2048 = create_number(board)) == 0)
		{
			printf("\nYou fail...\n");
			printf("Your score : %d\n", score);
			system("pause");
			return 0;
		}
		else if (check_2048 == 1 && temp == 0)
		{
			printf("\nComplete!\n");
			printf("계속 진행할까요? (Y/N) ");
			continue1 = getchar();
			clear_input_buffer();
			temp++;
			if (continue1 == 'n' || continue1 == 'N')
				break;
		}

		system("cls");
		printf("Your score : %d\n", score);
		show_board(board);

		while (input_direction)
		{
			fputs("방향을 입력하세요(w/s/a/d) : ", stdout);
			direction = getchar();
			clear_input_buffer();
			switch (direction)
			{
			case 'W':
			case 'w':
				input_direction = 0;
				break;
			case 'S':
			case 's':
				input_direction = 0;
				break;
			case 'A':
			case 'a':
				input_direction = 0;
				break;
			case 'D':
			case 'd':
				input_direction = 0;
				break;
			default:
				printf("    잘못된 방향입니다. 다시 입력하세요.\n\n\n");
			}
			/* 

			if (cannot_move_at_all(board) == 1 && cannot_add_at_all(board) == 1)
				input_direction = 0;
			else if (cannot_add(board, direction) == 1 && cannot_move(board, direction) == 1)
			{
				printf("    지정한 방향으로 움직일 수 없습니다. 다시 입력하세요.\n\n\n");
			}

			*/
		}
		input_direction = 1;
		add_shell(board, direction, &score);
	}
	system("pause");
	return 0;
}
