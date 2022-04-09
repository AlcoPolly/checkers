#include <stdio.h>
#include <Windows.h>

unsigned char what;
unsigned short count_white = 12;
unsigned short coun_black = 12;
unsigned short x1 = 0; //из строки
unsigned short y1 = 0; //из столбца
unsigned short x2 = 0; //в строку
unsigned short y2 = 0; //в столбец
typedef enum condition { w, b, W, B, empty, X } condition;
struct Cage {
	unsigned short index;//порядковый номер клетки
	condition value;//её состояние
	//struct Cage* left;
	//struct Cage* right;
}Cage[64];
enum Erorrs
{
	error_wrong_checker,
	error_beat,
	error_defect,
	error_wrong_cage,
};
void Erorrs_print(Errors) {
	switch (Errors) {
	case error_wrong_checker:
		printf("Выберете другую шашку!");
		break;
	case error_beat:
		printf("Нарушение правил! Бить обязательно!");
		break;
	case error_defect:
		printf("Выберете другую шашку!");
		break;
	case error_wrong_cage:
		printf("Выберете другую клетку!");
		break;
	default:
		break;
	}
}
void completion() {
	unsigned short x, y;
	unsigned short n = 0;
	for (x = 0; x < 3; x++) {
		for (y = 0; y < 8; y++) {
			if (x % 2 == 0) {
				if (n % 2 == 1) Cage[n].value = w;
				else Cage[n].value = X;
			}
			else {
				if (n % 2 == 0) Cage[n].value = w;
				else Cage[n].value = X;
			}
			n++;
		}
	}
	for (x; x < 5; x++) {
		for (y = 0; y < 8; y++) {
			if (x % 2 == 0) {
				if (n % 2 == 1) Cage[n].value = empty;
				else Cage[n].value = X;
			}
			else {
				if (n % 2 == 0) Cage[n].value = empty;
				else Cage[n].value = X;
			}
			n++;
		}
	}
	for (x; x < 8; x++) {
		for (y = 0; y < 8; y++) {
			if (x % 2 == 0) {
				if (n % 2 == 1) Cage[n].value = b;
				else Cage[n].value = X;
			}
			else {
				if (n % 2 == 0) Cage[n].value = b;
				else Cage[n].value = X;
			}
			n++;
		}
	}
}
void print_desk() {
	unsigned short x = 1;
	printf("  ");
	for (int i = 'A'; i < 'A' + 8; i++)	printf(" %c  ", i);
	printf("\n   ");
	for (int i = 0; i < 31; i++) putchar('-');
	for (int i = 0; i < 64; i++) {
		if (i % 8 == 0) printf("\n %hu|", x);
		switch (Cage[i].value) {
		case w:
			putchar('w');
			break;
		case b:
			putchar('b');
			break;
		case empty:
			putchar('o');
			break;
		case X:
			putchar('x');
			break;
		case W:
			putchar('W');
			break;
		case B:
			putchar('B');
			break;
		}
		if (i % 8 != 7) printf("   ");
		if (i % 8 == 7) {
			printf("  |%hu", x);
			x++;
		}
	}
	printf("\n   ");
	for (int i = 0; i < 31; i++) putchar('-');
	printf("\n   ");
	for (int i = 'A'; i < 'A' + 8; i++) 	printf(" %c  ", i);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("\t\t\t\tДобро пожаловать!\n\t\t\tВас приветствует игра \"Шашки\"!\n\nПравила игры:\n");
	printf("1. Обозначения:\n\tw -- белая шашка\n\tb -- чёрная шашка\n\tW -- белая дамка\n\tB -- чёрная дамка\n");
	printf("\tх -- поле, не доступное для хода\n");
	printf("2. На пустые поля ходить нельзя!\n");//на будущее
	printf("3. Для осуществления хода, игрок вводит номер клетки, указывающей на шашку,\n   которую необходимо передвинуть, и номер клетки, куда её надо передвинуть через пробел.\n");
	printf("4. Номер клетки состоит из буквы столбца и номера строки.\n");
	printf("5. Обычные шашки не могут ходить назад.\n");
	printf("6. Бить назад можно.\n");
	printf("7. Шашка превращается в дамку, достигнув противоположного конца доски.\n");
	printf("8. Дамки могут ходить в любом направлении на любое количество клеток, в том числе и назад.\n");
	printf("9. Проигрывает тот, у кого не остается фигур, либо ходов.\n");
	printf("10. Бить обязательно\n");
	completion();
	print_desk();
}