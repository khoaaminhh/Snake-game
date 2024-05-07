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

bool Snake::kt_ran_an_qua() 
{
	return  (toa_dox[0] == xqua && toa_doy[0] == yqua);
}

// xử lí khi rắn ăn quả
void Snake::xu_li_ran_an_qua() 
{
	if (kt_ran_an_qua()) 
	{
		sl++;
		score += tocdo;
		qua_to++;
		if (qua_to % 5 != 0) 
		{
			tao_qua();
			ve_qua();
			xuat_diem();
		}
		else if (qua_to % 5 == 0) 
		{
			tao_qua_to();
			ve_qua_to();
		}
	}
}

//kiểm tra quả xuất hiện có trùng với rắn không
bool Snake::kiem_tra_ran_de_qua() 
{
	for (int i = 0; i < sl; i++) 
	{
		if (toa_dox[i] == xqua && toa_doy[i] == yqua) return true;
	}
	return false;
}

//kiểm tra rắn chạm thân
bool Snake::kiem_tra_ran_cham_than() 
{
	for (int i = 4; i < sl; i++) 
	{
		if (toa_dox[0] == toa_dox[i] && toa_doy[0] == toa_doy[i]) return true;
	}
	return false;
}

void Snake::xu_li_ran_an_qua_to() 
{
	if (kt_ran_an_qua_to()) 
	{
		sl++;
		score += 10;
		qua_to++;
		for (int i = xqua_to - 1; i <= xqua_to + 1; i++) 
		{
			for (int j = yqua_to - 1; j <= yqua_to + 1; j++)
			{
				gotoXY(i, j);
				std::cout << " ";
			}
		}
		tao_qua();
		ve_qua();
		xuat_diem();
	}
}

bool Snake::kt_ran_an_qua_to() 
{
	if      (toa_dox[0] == xqua_to - 1 && toa_doy[0] == yqua_to - 1) return true;
	else if (toa_dox[0] == xqua_to && toa_doy[0] == yqua_to - 1) return true;
	else if (toa_dox[0] == xqua_to + 1 && toa_doy[0] == yqua_to - 1) return true;
	else if (toa_dox[0] == xqua_to + 1 && toa_doy[0] == yqua_to) return true;
	else if (toa_dox[0] == xqua_to + 1 && toa_doy[0] == yqua_to + 1) return true;
	else if (toa_dox[0] == xqua_to && toa_doy[0] == yqua_to + 1) return true;
	else if (toa_dox[0] == xqua_to - 1 && toa_doy[0] == yqua_to + 1) return true;
	else if (toa_dox[0] == xqua_to - 1 && toa_doy[0] == yqua_to) return true;
	return false;
}

bool Snake::kiem_tra_ran_de_qua_to() 
{
	for (int i = 0; i < sl; i++) 
	{
		if (toa_dox[i] == xqua_to && toa_doy[i] == yqua_to) return true;
		else if (toa_dox[i] == xqua_to - 1 && toa_doy[i] == yqua_to - 1) return true;
		else if (toa_dox[i] == xqua_to && toa_doy[i] == yqua_to - 1) return true;
		else if (toa_dox[i] == xqua_to + 1 && toa_doy[i] == yqua_to - 1) return true;
		else if (toa_dox[i] == xqua_to + 1 && toa_doy[i] == yqua_to) return true;
		else if (toa_dox[i] == xqua_to + 1 && toa_doy[i] == yqua_to + 1) return true;
		else if (toa_dox[i] == xqua_to && toa_doy[i] == yqua_to + 1) return true;
		else if (toa_dox[i] == xqua_to - 1 && toa_doy[i] == yqua_to + 1) return true;
		else if (toa_dox[i] == xqua_to - 1 && toa_doy[i] == yqua_to) return true;
	}
	return false;
}


int main() {
	Snake snake;
	snake.play();


	_getch();
}