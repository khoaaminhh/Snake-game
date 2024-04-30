#include"mySnake.h"
using namespace std;
void Snake::play() {
	ve_tuong();
	khoi_tao_ran();
	ve_ran();
}


void Snake::khoi_tao_ran() {
	int khoi_tao_x = 50;
	int khoi_tao_y = 13;
	for (int i = 0; i < sl; i++) {
		toa_dox[i] = khoi_tao_x--;
		toa_doy[i] = khoi_tao_y;
	}
}


void Snake::ve_ran() {
	SetColor(13);
	for (int i = 0; i < sl; i++) {
		gotoXY(toa_dox[i], toa_doy[i]);
		if (i == 0) std::cout << "0";
		else std::cout << "o";
	}
}
void Snake::ve_tuong() {
	SetColor(11);
	for (int i = 10; i <= 100; i++) {
		gotoXY(i, 1);
		std::cout << "+";
		gotoXY(i, 25);
		std::cout << "+";
	}
	for (int i = 1; i <= 25; i++) {
		gotoXY(10, i);
		std::cout << "+";
		gotoXY(100, i);
		std::cout << "+";
	}
}


int main() {
	Snake snake;
	snake.play();


	_getch();
}