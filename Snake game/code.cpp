#include"mySnake.h"
using namespace std;


void Snake::KhoiTaoRan() 
{
	int khoi_tao_x = 50;
	int khoi_tao_y = 13;
	for (int i = 0; i < sl; i++) 
	{
		toa_dox[i] = khoi_tao_x--;
		toa_doy[i] = khoi_tao_y;
	}
}

//vẽ rắn
void Snake::VeRan() 
{
	SetColor(mau_ran);
	for (int i = 0; i < sl; i++) 
	{
		gotoXY(toa_dox[i], toa_doy[i]);
		if (i == 0) std::cout << (char)254;
		else std::cout << (char)249;
	}
}



void Snake::VeTuong() {
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
void Snake::ChonTocDo()
{
	SetColor(11);
	for (int i = 10; i <= 40; i++)
	{
		gotoXY(i, 1);
		std::cout << (char)176;
		gotoXY(i, 10);
		std::cout << (char)176;
	}
	for (int i = 1; i <= 10; i++)
	{
		gotoXY(10, i);
		std::cout << (char)176;
		gotoXY(40, i);
		std::cout << (char)176;
	}
	gotoXY(10, 0);
	std::cout << "CHOOSE SNAKE SPEED ";
	gotoXY(15, 3); std::cout << "1. VERY SLOW";
	gotoXY(15, 4); std::cout << "2. SLOW";
	gotoXY(15, 5); std::cout << "3. NORMAL";
	gotoXY(15, 6); std::cout << "4. FAST";
	gotoXY(15, 7); std::cout << "5. VERY FAST";
	gotoXY(15, 8); std::cout << "6. EXTREME FAST";
	for (int i = 10; i <= 40; i++)
	{
		gotoXY(i, 1);
		std::cout << (char)176;
		gotoXY(i, 10);
		std::cout << (char)176;
	}
	for (int i = 1; i <= 10; i++)
	{
		gotoXY(10, i);
		std::cout << (char)176;
		gotoXY(40, i);
		std::cout << (char)176;
	}
	int temp = _getch();
	if (temp == (int)'1')
	{
		sleep = 200;
		tocdo = 1;
	}
	else if (temp == (int)'2')
	{
		sleep = 170;
		tocdo = 2;
	}
	else if (temp == (int)'3')
	{
		tocdo = 3;
		sleep = 140;
	}
	else if (temp == (int)'4')
	{
		sleep = 110;
		tocdo = 4;
	}
	else if (temp == (int)'5')
	{
		sleep = 70;
		tocdo = 5;
	}
	else if (temp == (int)'6')
	{
		sleep = 50;
		tocdo = 6;
	}
	system("cls");
	Setting();
}
void Snake::Setting()
{
	SetColor(11);
	gotoXY(10, 0);
	std::cout << "MAIN MENU";
	gotoXY(21, 4);
	std::cout << "1. PLAY" << std::endl;
	gotoXY(21, 5);
	std::cout << "2. OPTIONS" << std::endl;
	gotoXY(21, 6);
	std::cout << "3. EXIT" << std::endl;
	for (int i = 10; i <= 40; i++)
	{
		gotoXY(i, 1);
		std::cout << (char)176;
		gotoXY(i, 10);
		std::cout << (char)176;
	}
	for (int i = 1; i <= 10; i++)
	{
		gotoXY(10, i);
		std::cout << (char)176;
		gotoXY(40, i);
		std::cout << (char)176;
	}

	int temp = _getch();
	system("cls");
	if (temp == (int)'1') return;
	else if (temp == (int)'2')
	{

		system("cls");
		gotoXY(10, 0); std::cout << "OPTION";
		gotoXY(15, 5);
		std::cout << "1. CHOOSE SNAKE SPEED" << std::endl;
		gotoXY(15, 6);
		std::cout << "2. CHOOSE SNAKE COLOR" << std::endl;
		for (int i = 10; i <= 40; i++)
		{
			gotoXY(i, 1);
			std::cout << (char)176;
			gotoXY(i, 10);
			std::cout << (char)176;
		}
		for (int i = 1; i <= 10; i++)
		{
			gotoXY(10, i);
			std::cout << (char)176;
			gotoXY(40, i);
			std::cout << (char)176;
		}
		int k = _getch();
		if (k == (int)'1')
		{
			system("cls");
			gotoXY(10, 1);
			ChonTocDo();
		}
		else if (k == (int)'2')
		{
			system("cls");
			gotoXY(10, 1);
			ChonMauRan();
		}
	}
	else if (temp == (int)'3')
		exit(0);
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

void Snake::ChonMauRan()
{
	SetColor(11);
	for (int i = 10; i <= 40; i++)
	{
		gotoXY(i, 1);
		std::cout << (char)176;
		gotoXY(i, 10);
		std::cout << (char)176;
	}
	for (int i = 1; i <= 10; i++)
	{
		gotoXY(10, i);
		std::cout << (char)176;
		gotoXY(40, i);
		std::cout << (char)176;
	}
	gotoXY(10, 0);
	std::cout << "CHOOSE SNAKE COLOR ";
	gotoXY(15, 3); std::cout << "1. BLUE";
	gotoXY(15, 4); std::cout << "2. GREEN";
	gotoXY(15, 5); std::cout << "3. WHITE";
	gotoXY(15, 6); std::cout << "4. RED";
	gotoXY(15, 7); std::cout << "5. LIGHT BLUE";
	for (int i = 10; i <= 40; i++)
	{
		gotoXY(i, 1);
		std::cout << (char)176;
		gotoXY(i, 10);
		std::cout << (char)176;
	}
	for (int i = 1; i <= 10; i++)
	{
		gotoXY(10, i);
		std::cout << (char)176;
		gotoXY(40, i);
		std::cout << (char)176;
	}
	int temp = _getch();
	if (temp == (int)'1')
	{
		mau_ran = 1;
	}
	else if (temp == (int)'2')
	{
		mau_ran = 2;
	}
	else if (temp == (int)'3')
	{
		mau_ran = 7;
	}
	else if (temp == (int)'4')
	{
		mau_ran = 4;
	}
	else if (temp == (int)'5')
	{
		mau_ran = 3;
	}
	system("cls");
	Setting();
}


void Snake::Play()
{
	system("cls");

	Setting();

	ShowCur(0);

	//build gamex
	VeTuong();
	KhoiTaoRan();

	TaoQua();
	VeQua();

	XuatDiem();
	int x = toa_dox[0];
	int y = toa_doy[0];

	//điều kiện chạy
		//- check = 0 đi xuống 
		//- check = 1 đi lên
		//- check = 2 sang trái
		//- check = 3 sang phải
	int check = 3;

	//Play
	while (true)
	{
		//xóa đuôi
		gotoXY(toa_dox[sl], toa_doy[sl]);
		std::cout << " ";

		// vẽ rắn
		VeRan();

		//điều khiển
			//sử dụng các phím mũi tên hoặc w, a, s, d để di chuyển rắn
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 72 && check != 0) check = 1;
				else if (c == 80 && check != 1) check = 0;
				else if (c == 75 && check != 3) check = 2;
				else if (c == 77 && check != 2) check = 3;
			}
			if ((c == (int)'w' || c == (int)'W') && check != 0) check = 1;
			else if ((c == (int)'s' || c == (int)'S') && check != 1) check = 0;
			else if ((c == (int)'a' || c == (int)'A') && check != 3) check = 2;
			else if ((c == (int)'d' || c == (int)'D') && check != 2) check = 3;
		}
		if (check == 3) x++;
		else if (check == 2) x--;
		else if (check == 1) y--;
		else if (check == 0) y++;

		//kiểm tra biên
		if (GameOver(toa_dox[0], toa_doy[0]))
		{
			SetColor(12);

			system("cls");
			std::cout << "Game over";
			break;
		}

		if (qua_to % 5 != 0) XuLiRanAnQua();
		else if (qua_to % 5 == 0) XuLiRanAnQuaTo();
		DiChuyen(x, y);
		Sleep(sleep);
	}
	system("cls");
	if (GameOver(toa_dox[0], toa_doy[0]) == true)
	{
		if (score >= kyluc)
			kyluc = score;

		SetColor(11);
		for (int i = 10; i <= 40; i++)
		{
			gotoXY(i, 1);
			std::cout << (char)176;
			gotoXY(i, 10);
			std::cout << (char)176;
		}
		for (int i = 1; i <= 10; i++)
		{
			gotoXY(10, i);
			std::cout << (char)176;
			gotoXY(40, i);
			std::cout << (char)176;
		}
		gotoXY(10, 0);
		std::cout << "GAME OVER";
		gotoXY(12, 5); std::cout << "PRESS M TO RETURN MAIN MENU";
		gotoXY(12, 6); std::cout << "PRESS R TO WATCH RECORD";
		int temp = _getch();
		if (temp == (int)'m')
		{
			sl = 1;
			score = 0;
			Play();
		}
		if (temp == (int)'r' || temp == (int)'R')
		{
			for (int i = 11; i <= 39; i++) {
				gotoXY(i, 5); std::cout << " ";
			}
			gotoXY(12, 5); std::cout << "YOUR RECORD: " << kyluc;
			gotoXY(12, 6); std::cout << "PRESS M TO RETURN MAIN MENU";
			score = 0;
			sl = 1;
			int cur = _getch();
			if (cur == (int)'m' || cur == (int)'m') Play();
		}
	}
}

void Snake::TaoQuaTo() 
{
	this->xqua_to = rand() % (98 - 12 + 1) + 12;
	this->yqua_to = rand() % (23 - 3 + 1) + 3;
	if (KtRanDeQuaTo())
		TaoQuaTo();
}

void Snake::VeQuaTo() 
{
	if (!KtRanDeQuaTo()) 
	{
		for (int i = xqua_to - 1; i <= xqua_to + 1; i++) 
		{
			for (int j = yqua_to - 1; j <= yqua_to + 1; j++)
			{
				gotoXY(i, j);
				std::cout << "*";
			}
		}
	}
}

int main() {
	Snake snake;
	snake.Play();


	_getch();
}
