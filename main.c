#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include <conio.h>

void hello(void); // ����ڿ��� �ȳ� - MoNisu
void drawLine(int num); // �� �׸��� �Լ� - MoNiSu
void drawBoard(void); // �ٵ��� �׸��� �Լ� - MoNiSu
void cursor(short x, short y); // Ŀ�� �Է� �Լ� - MoNiSu
void moveCursor(int arr[20][20], int num); // Ŀ�� �����̱�, �ٵϵ� �δ� �Լ� - MoNiSu

int test(int t); // ��� �׽�Ʈ �ϴ� �Լ� - MoNiSu

void main(void) {
  int board[20][20]; // 0��ĭ�� �� �� 1������ ���� ��) board[10][10] == 2 ���� ���� 10��° �� ������ - MoNiSu
  bool gameStatus; // true == ���� ���� �ƴϸ� ���� ��, false == ���� �� - MoNiSu
  int user = 2; // 2 == ���� ��, 3 == �� �� - MoNiSu

  // hello(); 
  // enterKey();
  // system("cls"); // �ܼ� â �ʱ�ȭ - MoNiSu
  drawBoard();

  gameStatus = true;

  do {
    moveCursor(board, user);
    if (user == 2) {
      ++user;
    }
    else {
      --user;
    }
  } while (gameStatus);

  // test(1); // �� ���� �� �ּ� ó�� �ص� �� - MoNiSu
}

void hello(void) {
  printf(" *** �ȳ��Ͻʴϱ�. ���� ���� ���� ȯ���մϴ�. ***\n");
  Sleep(1500);
  printf(" *** �� ������ C���� ���� �Ǿ� �ֽ��ϴ�. ***\n");
  Sleep(1500);
  printf(" *** ������ ������ �����մϴ�. ***\n");
  Sleep(1500);
}

void drawLine(int num) {
  char* line[10] = { // int�� �ڷ� ������ char ������ �������� ���� �� �� ǥ�õ� - �輺��
    " ��", " ��", " ��", "����", "����", "����", "����", "����", "����"
  };
  printf("%s", line[num]);
  Sleep(1); // �׽�Ʈ �� �ÿ��� �ּ� ó�� - MoNiSu
}

void drawBoard(void) {
  for (int i = 1; i <= 19; i++) {
    for (int j = 1; j <= 19; j++) {
      if (j == 1) {
        if (i == 1) {
          drawLine(0);
        }
        else if (i == 19) {
          drawLine(2);
        }
        else {
          drawLine(1);
        }
      }
      else if (j == 19) {
        if (i == 1) {
          drawLine(6);
        }
        else if (i == 19) {
          drawLine(8);
        }
        else {
          drawLine(7);
        }
        printf("\n");
      }
      else {
        if (i == 1) {
          drawLine(3);
        }
        else if (i == 19) {
          drawLine(5);
        }
        else {
          drawLine(4);
        }
      }
    }
  }
}

void cursor(short x, short y) {
  COORD pos = { x * 2 - 1, y - 1 }; // COORD�� short ���� �迭 - MoNiSu
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // �ܼ� ��� ��ġ ���� - MoNiSu
}

void moveCursor(int arr[20][20], int num) {
  int x = 10, y = 10, key;
  cursor(x, y);

  do {
    if (_kbhit()) {
      key = _getch();
      if (key == 224) { // 224 + a == ����Ű - MoNiSu
        key = _getch();
        switch (key) {
        case 72: // 72 == �Ʒ� - MoNiSu
          --y;
          if (y < 1) {
            y = 1;
          }
          cursor(x, y);
          break;
        case 75: // 75 == ���� - MoNiSu
          --x;
          if (x < 1) {
            x = 1;
          }
          cursor(x, y);
          break;
        case 77: // 77 == ������ - MoNiSu
          ++x;
          if (x > 19) {
            x = 19;
          }
          cursor(x, y);
          break;
        case 80: // 80 == ���� - MoNiSu
          ++y;
          if (y > 19) {
            y = 19;
          }
          cursor(x, y);
          break;
        }
      }
      else if (key == 32) { // 32 == �����̽� �� - MoNiSu
        if (arr[x][y] != 2 && arr[x][y] != 3) {
          cursor(x, y);
          if (num == 2) {
            printf("��");
            arr[x][y] = num; // board�� ����
          }
          else {
            printf("��");
            arr[x][y] = num;
          }
          break;
        }
      }
    }
  } while (true);
}

int test(int t) { // ��� ���� �� ��� �� �� - MoNiSu
  
  return 0;
}