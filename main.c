#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void hello(void); // ����ڿ��� �ȳ� - MoNisu
void drawLine(int num); // �� �׸��� �Լ� - MoNiSu
void drawBoard(void); // �ٵ��� �׸��� �Լ� - MoNiSu
void sequence(int num); //���� ��Ÿ���� �Լ� - �輺��
void cursor(short x, short y); // Ŀ�� �Է� �Լ� - MoNiSu
void playGoStone(int arr[20][20], int num); // Ŀ�� �����̱�, �ٵϵ� �δ� �Լ� - MoNiSu, �Լ� �̸� ����� ������ �̿� - �輺��
void checkRule(int arr[20][20]); //���� �� Ȯ�� - �輺��
void checkWin(int arr[20][20], bool* status); // ���� �¸� ���� - �輺��, MoNiSu

void main(void) {
  int board[20][20]; // 0��ĭ�� �� �� 1������ ���� ��) board[10][10] == 2 ���� ���� 10��° �� ������ - MoNiSu
  bool gameStatus; // true == ���� ���� �ƴϸ� ���� ��, false == ���� �� - MoNiSu
  bool* pGameStatus = &gameStatus; // �����͸� Ȱ���� ������ ��Ȳ�� ���� - MoNiSu
  int user = 2; // 2 == ���� ��, 3 == �� �� - MoNiSu

  for (int i = 0; i <= 19; i++) { // �ٵ����� ������ ��� 0���� ä�� - �輺��, MoNiSu
    for (int j = 0; j <= 19; j++) {
      board[i][j] = 0;
    }
  }

  // hello();
  system("cls"); // �ܼ� â �ʱ�ȭ - MoNiSu
  drawBoard();

  *pGameStatus = true;

  do {
    sequence(user);
    playGoStone(board, user);
    checkWin(board, pGameStatus);
    if (user == 2) {
      ++user;
    }
    else {
      --user;
    }
  } while (gameStatus);

  system("cls");

  cursor(5, 5);
  if (user == 3) {
    printf("***  ���� (�浹 / ��) �� �¸� �Ͽ����ϴ�. ***\n\n\n");
  }
  else {
    printf("***  �İ� (�鵹 / ��) �� �¸� �Ͽ����ϴ�. ***\n\n\n");
  }

  exit(0);
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
  // Sleep(1); // �׽�Ʈ �� �ÿ��� �ּ� ó�� - MoNiSu
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

void sequence(int num) {
  if (num == 2) { //�浹 �����϶� - �輺��
    cursor(2, 21);
    printf("*** �浹 �����Դϴ� (�浹 / ��) ***");
  }
  else { //�鵹 �����϶� - �輺��
    cursor(2, 21);
    printf("*** �鵹 �����Դϴ� (�鵹 / ��) ***");
  }
}

void cursor(short x, short y) {
  COORD pos = { x * 2 - 1, y - 1 }; // COORD�� short ���� �迭 - MoNiSu
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // �ܼ� ��� ��ġ ���� - MoNiSu
}

void playGoStone(int arr[20][20], int num) {
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
        if (arr[x][y] == 0) {
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

void checkRule(int arr[20][20]) {

}

void checkWin(int arr[20][20], bool* status) {
  for (int i = 1; i <= 19; i++) { // ���� ���� - MoNiSu
    for (int j = 5; j <= 19; j++) {
      if (i <= 15) {
        if ( // ���� Ȯ�� - �輺��, MoNiSu
          arr[i][j] != 0 &&
          arr[i][j] == arr[i + 1][j] &&
          arr[i + 1][j] == arr[i + 2][j] &&
          arr[i + 2][j] == arr[i + 3][j] &&
          arr[i + 3][j] == arr[i + 4][j]
          ) {
          *status = false;
        }

        if (j >= 5) {
          if ( // /(������) �밢�� Ȯ�� - �輺��, MoNiSu
            arr[i][j] != 0 &&
            arr[i][j] == arr[i + 1][j - 1] &&
            arr[i + 1][j - 1] == arr[i + 2][j - 2] &&
            arr[i + 2][j - 2] == arr[i + 3][j - 3] &&
            arr[i + 3][j - 3] == arr[i + 4][j - 4]
            ) {
            *status = false;
          }
        }

        if (j <= 15) {
          if ( // �������� �밢�� Ȯ�� - �輺��, MoNiSu
            arr[i][j] != 0 &&
            arr[i][j] == arr[i + 1][j + 1] &&
            arr[i + 1][j + 1] == arr[i + 2][j + 2] &&
            arr[i + 2][j + 2] == arr[i + 3][j + 3] &&
            arr[i + 3][j + 3] == arr[i + 4][j + 4]
            ) {
            *status = false;
          }
        }
      }

      if (j <= 15) {
        if ( // ���� Ȯ�� - �輺��, MoNiSu
          arr[i][j] != 0 &&
          arr[i][j] == arr[i][j + 1] &&
          arr[i][j + 1] == arr[i][j + 2] &&
          arr[i][j + 2] == arr[i][j + 3] &&
          arr[i][j + 3] == arr[i][j + 4]
          ) {
          *status = false;
        }
      }
    }
  }
}
