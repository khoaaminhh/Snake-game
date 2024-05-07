#pragma once
#include"myGraphic.h"
#include<iostream>	
using namespace std;
#define MAX 100
class Snake {
private:
	int toa_dox[MAX] = { '0' };
	int toa_doy[MAX] = { '0' };
	int sl = 1;
	int xqua = -1, yqua = -1;
	int xqua_to = -1, yqua_to = -1;
	int tocdo = 1;
	int sleep = 200;
	int mau_ran; 

public:
	void Play();
	void VeTuong();
	void KhoiTaoRan();
	void VeRan();
	void ChonTocDo(); 
	void ChonMauRan();
	void Setting();
	bool kt_ran_an_qua(); 
	void ve_qua(); 
	void xu_li_ran_an_qua(); 
	bool kiem_tra_ran_de_qua(); 
	bool kiem_tra_ran_cham_than(); 
	bool kiem_tra_ran_de_qua_to();
	void xu_li_ran_an_qua_to(); 
	bool kt_ran_an_qua_to(); 
};