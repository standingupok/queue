#pragma once
#include <iostream>
#include <string>
using namespace std;

class Customers {
private:
	string name;
	long long money;
	int order;
	//dung bien tinh~ de dem
	static int count;
public:
	//constructor khong chua tham so
	Customers();
	//des
	~Customers();
	//constructor chua tham so
	Customers(string name, int age, long long money) {
		//ten
		this->name = name;
		//thu tu cua nguoi rut tien
		this->order = order;
		//so tien rut
		this->money = money;
	}
	//lay so tien can rut
	long long getMoney();
	//lay ten
	string getName();
	//lay so thu tu
	int getOrder();
	//nhap
	void input();
	//xuat
	void output();
};