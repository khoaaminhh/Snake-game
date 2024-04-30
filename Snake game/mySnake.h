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

public:
	void play();
	void ve_tuong();
	void khoi_tao_ran();
	void ve_ran();




};