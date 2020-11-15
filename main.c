#include <stdio.h>
#include <string.h>

/* ���������:
	0. unknown;
	1. zero;
	2. x;
	3. dollar;
	4. digit;
};*/
int states[5][5] = { { 0, 0, 0, 0, 0 },		// ���������: ������
					 { 0, 2, 0, 3, 0 },		// 1. ���������: ������
											// ���������: 0 ��� $
					 { 0, 0, 3, 0, 0 },		// 2. ���������: 0
											// ���������: x
					 { 0, 0, 0, 0, 4 },		// 3. ���������: 0x ��� $
											// ���������: �-F ��� 0-9
					 { 0, 0, 0, 0, 4 }		// 4. ���������: �-F ��� 0-9
											// ���������: �-F ��� 0-9 ��� ����� ������
};		

int main() {
	printf("Input hex-number: ");
	char num[10];
	gets(num);
	int res = check_16number(num);
	printf("%d\n", res);
	return 0;
}

int check_16number(char* number) {
	int state = 1;
	int type = 0;
	for (int i = 0; i < strlen(number); i++) {
		char s = number[i];
		if (i == 0 && s == '0') type = 1;
		else type = get_symbol_type(number[i]);
		state = states[state][type];
	}
	return state == 4;
}

int get_symbol_type(char s) {
	int type;
	if (s == 'x') type = 2;
	else if (s == '$') type = 3;
	else if ((48 <= s && s <= 57) || (65 <= s && s <= 70)) type = 4;
	else type = 0;
	return type;
}