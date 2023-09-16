#include <iostream>
#include "Customers.h"
#include <vector>

int main()
{
	//tao danh sach vector chua cac khach hang
	vector <Customers*> list;
	//tao danh sach vector chua cac khach hang da rut tien
	vector <Customers*> withdrawList;
	//choice: lua chon tren man hinh consol
	// n: so khach hang dang cho
	// order: thu tu khach hang
	int choice, n = 0, order = 1;

	//truong hop nguoi dung nhap sai
	string schoice;

	//moneyInQueue: tinh tong so tien trong hang cho
	//withdrawnMoney: tinh tong so tien da rut
	//availableMoney: tong so tien con lai trong Queue sau khi rut
	long long moneyInQueue = 0, withdrawnMoney = 0, availableMoney = 0;

	do
	{
		//them khach hang
		cout << "1. Press 1 to add info!" << endl;
		//goi khach hang
		cout << "2. Press 2 to call next customrs" << endl;
		//xem thong tin 3 khach hang gan nhat gom ten va so thu tu
		cout << "3. Press 3 show the 3 nearest Customers and total Customers" << endl;
		//Thong ke
		cout << "4. Press 4 to sum up!" << endl;
		//thoat
		cout << "5. Press 5 to exit!" << endl;
		//nhap lua chon
		do {
			cout << "Your Option: ";
			cin >> schoice;
			if (schoice < "0" || schoice > "9")
				cout << "ERROR!" << endl;
		} while (schoice < "0" || schoice > "9");
		choice = stoi(schoice);
		//khai bao khach hang a
		Customers* a;
		switch (choice)
		{
		case 1:
			cout << endl << "Customer: " << order << endl;
			a = new Customers();
			a->input();
			//tinh tong so tien trong hang cho
			moneyInQueue += a->getMoney();
			//dua khach hang vip len dau hang cho
			if (a->getMoney() >= 1000000)
			{
				auto v = list.begin();
				list.insert(v, a);
			}
			//them khach hang vao cuoi hang cho
			else
			{
				list.push_back(a);
			}
			//tinh so khach hang hien tai trong hang cho
			n++;
			//thu tu khach hang
			order++;
			break;

		case 2:
			//truong hop co khach hang trong hang cho
			if(list.size() > 0) {
				cout << endl << "Next Customer: " << endl;
				cout << "Customer number " << list.front()->getOrder() << endl;
				cout << "Name: " << list.front()->getName() << endl << endl;
				//tinh so tien da rut
				withdrawnMoney += list.front()->getMoney();
				//tinh so tien con lai trong Queue
				availableMoney = moneyInQueue - withdrawnMoney;
				//them vao danh sach cac khach hang da rut tien
				withdrawList.push_back(list.front());
				//xoa khach hang da rut tien
				list.erase(list.begin());
				n--;
			}
			//truong hop khong co khach hang trong hang cho
			else
			{
				cout << endl << "Empty Queue!" << endl << endl;
				break;
			}
			break;

		case 3:
			cout << "Total customers: " << n << endl;
			if (n == 0) {
				cout << "Empty Queue!" << endl;
				break;
			}
			else if (n < 3) {
				for (int i = 0; i < n; i++) {
					cout << "Customer: " << list[i]->getOrder() << endl;
					cout << "Name: " << list[i]->getName() << endl << endl;
				}
			}
			else {
				for (int i = 0; i < 3; i++) {
					cout << "Customer: " << list[i]->getOrder() << endl;
					cout << "Name: " << list[i]->getName() << endl << endl;
				}
			}
			break;
		case 4:
			cout << endl << "Withdrawal Information:" << endl;
			if (withdrawList.size() == 0) {
				cout << "Withdrawal List is empty" << endl;
				//Tong so tien trong hang cho
				cout << "Total Money in Queue: " << moneyInQueue << endl;
				//tong so ten con lai
				cout << "Available: " << moneyInQueue << endl << endl;
			}
			//thong tin khach hang da rut tien
			else {
				for (Customers* a : withdrawList)
				{
					a->output();
				}
				//Tong so tien trong hang cho
				cout << "Total Money in Queue: " << moneyInQueue << endl;
				//tong so ten con lai
				cout << "Available: " << availableMoney << endl << endl;
			}
			break;
		default:
			list.clear();
			return 0;
			break;
		}
	} while (choice != 5);
	
	return 0;
}