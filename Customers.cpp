#include "Customers.h"
//constructor
Customers::Customers() {
	count++;
}
//destructor
Customers::~Customers() {

}
//bien count danh dau so thu tu khach hang
int Customers::count = 0;
//nhap
void Customers::input() {
	cin.ignore();
	//cam co xem khach hang co nhap sai hay khong
	int flag;
	string s="";
	cout << "Customer's Name: ";
	getline(cin, this->name);

	this->order = Customers::count;
	do
	{
		flag = 0;
		cout << "Enter the amount you withdraw: ";
		cin >> s;
		//xu ly tinh hop le so tien khach hang da nhap
		for (int i = 0; i < s.length(); i++) 
		{
			if (s[i] < '0' || s[i] > '9') 
			{
				flag = 1;
				break;
			}
		}
		if (s.size() > 20 or flag == 1) {
			cout << "Invalid number! Please correct the value." << endl;
		}
	}while (s.size() > 20 or flag == 1);
	//so tien hop le, thoat khoi vong lap, chuyen chuoi thanh so
	this->money = stoll(s);
	cout << endl;
}

void Customers::output() {
	cout << "Customer number " << this->order << endl;
	cout << "Name: " << this->name << endl;
	cout << "Value of withdraw: " << this->money << endl << endl;
}

long long Customers::getMoney() {
	return this->money;
}

int Customers::getOrder() {
	return this->order;
}

string Customers::getName() {
	return this->name;
}