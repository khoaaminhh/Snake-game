#pragma once
#include"myGraphic.h"
#include<iostream>	
using namespace std;
#define MAX 100

class Snake 
{
	private:
		int toa_dox[MAX] = { '0' };
		int toa_doy[MAX] = { '0' };
		int sl = 1;
		int tocdo = 1; 
		int score = 0;
		int mau_ran;
		int sleep = 200;
		static int kyluc;

		int xqua = -1, yqua= -1; 
		int xqua_to = -1, yqua_to = -1; 
		int qua_to = 1; 

	public:

		void Setting(); 
 		void ChonTocDo();
		void ChonMauRan();

		void VeTuong();
		void KhoiTaoRan();	
		void VeRan();
		void DiChuyen(int, int);
		bool GameOver(int, int);
		bool KtRanChamThan();

		void XuatDiem();

		void TaoQua();		
		void VeQua();
		bool KtRanDeQua();

		bool KtRanAnQua(); 
		void XuLiRanAnQua(); 

		void TaoQuaTo(); 
		void VeQuaTo(); 
		bool KtRanAnQuaTo();
		bool KtRanDeQuaTo();
		void XuLiRanAnQuaTo(); 

		void Play();

};
