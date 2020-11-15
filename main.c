#include <stdio.h>
#include <string.h>

/* Состояния:
	0. unknown;
	1. zero;
	2. x;
	3. dollar;
	4. digit;
};*/
int states[5][5] = { { 0, 0, 0, 0, 0 },		// Состояние: ошибка
					 { 0, 2, 0, 3, 0 },		// 1. Прочитано: ничего
											// Ожидается: 0 или $
					 { 0, 0, 3, 0, 0 },		// 2. Прочитано: 0
											// Ожидается: x
					 { 0, 0, 0, 0, 4 },		// 3. Прочитано: 0x или $
											// Ожидается: А-F или 0-9
					 { 0, 0, 0, 0, 4 }		// 4. Прочитано: А-F или 0-9
											// Ожидается: А-F или 0-9 или конец строки
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