#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

void hello(void); // ����ڿ��� �ȳ� - MoNisu
void drawLine(int num); // �� �׸��� �Լ� - MoNiSu
void drawBoard(void); // �ٵ��� �׸��� �Լ� - MoNiSu

int test(int t); // ��� �׽�Ʈ �ϴ� �Լ� - MoNiSu


void main(void) {
  // hello(); // ���� �ð��� ����� �׽�Ʈ �ϱ� ����� �ּ� ó���� - MoNiSu
  system("cls"); // �ܼ� â �ʱ�ȭ - MoNiSu
  drawBoard();

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
    "��", "��", "��", "����", "����", "����", "����", "����", "����", "��"
  };
  printf("%s", line[num]);
  Sleep(5);
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

int test(int t) { // ��� ���� �� ��� �� �� - MoNiSu

  return 0;
}