// КТбо1-2 Колмогоров Владислав
// «Покупатель»:  фамилия,  имя,  отчество,  город,  улица,  номер  дома,  номер  квартиры,  номер  кредитной  карточки,  код  покупки.


#include <iostream>
#include<fstream>

using namespace std;
struct buyer {
	char surname[20];
	char name[20];
	char patronymic[20];
	struct { char city[20]; char street[20]; int home; int kv; } address;
	long long int code;
	long long int credit;
};

void SortCode(buyer** q, int k)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k - i - 1; j++)
			if (q[j]->code > q[j + 1]->code)
			{
				buyer* temp = q[j];
				q[j] = q[j + 1];
				q[j + 1] = temp;
			}
};

void print(buyer* b, int k)
{
	for (int i = 0; i < k; i++)
	{
		cout << endl << endl;
		cout << i + 1 << " покупатель: " << endl;
		cout << b[i].surname << "	" << b[i].name << "	" << b[i].patronymic << "	" << b[i].address.city << "	"
			<< b[i].address.street << "	" << b[i].address.home << "	" << b[i].address.kv << "	" << b[i].credit << "	"
			<< b[i].code;
	}
};

void print_2(buyer* b, int i)
{
	cout << endl;
	cout << i + 1 << " покупатель: " << endl;
	cout << b[i].surname << "	" << b[i].name << "	" << b[i].patronymic << "	" << b[i].address.city << "	"
		<< b[i].address.street << "	" << b[i].address.home << "	" << b[i].address.kv << "	" << b[i].credit << "	"
		<< b[i].code;
}

int main()
{
	setlocale(LC_ALL, "ru");
	ofstream fout;
	fout.open("test.txt");
	if (!fout.is_open())
	{
		cout << "Ошибка создания файла";
		return 0;
	}
	else
	{
		int k = 0;
		const int N = 20; // максимальное кол-во структур
		buyer* b = new buyer[N]; // указатель на массив структур

		// заполнение структуры с клавиатуры в файл

		for (int i = 0; i < N; i++)  // цикл заполнения структуры
		{
			cout << "Введите фамилию " << i + 1 << " покупателя: " << endl;
			cin >> b[i].surname;
			fout << b[i].surname << "	";
			cout << "Введите имя " << i + 1 << " покупателя: " << endl;
			cin >> b[i].name;
			fout << b[i].name << "	";
			cout << "Введите отчество " << i + 1 << " покупателя: " << endl;
			cin >> b[i].patronymic;
			fout << b[i].patronymic << "	";
			cout << "Введите город " << i + 1 << " покупателя: " << endl;
			cin >> b[i].address.city;
			fout << b[i].address.city << "	";
			cout << "Введите улицу " << i + 1 << " покупателя:" << endl;
			cin >> b[i].address.street;
			fout << b[i].address.street << "	";
			cout << "Введите номер дома " << i + 1 << " покупателя:" << endl;
			cin >> b[i].address.home;
			fout << b[i].address.home << "	";
			cout << "Введите номер квартиры " << i + 1 << " покупателя:" << endl;
			cin >> b[i].address.kv;
			fout << b[i].address.kv << "	";
			cout << "Введите номер кредитной карты " << i + 1 << " покупателя:" << endl;
			cin >> b[i].credit;
			fout << b[i].credit << "	";
			cout << "Введите код покупки " << i + 1 << " покупателя:" << endl;
			cin >> b[i].code;
			fout << b[i].code << "	";
			k++;
			cout << "Продолжить заполнять структуры?" << endl;
			cout << "Если нет, введите T(t), иначе введите любой другой символ: ";
			char res_1;
			cin >> res_1;
			if (res_1 == 'T' || res_1 == 't')
				break;
			fout << (char)13; // enter (перевод на новую строку в файле после ввода структуры)
		}
		buyer** q = new buyer * [N]; // массив указателей
		for (int i = 0; i < k; i++)// цикл заполнения массива указателей
			q[i] = &b[i];
		cout << "Вывести на экран содержимое массива структур?" << endl;
		cout << "Если да, введите R(r), иначе введите любой другой символ:" << endl;
		char res_2;
		cin >> res_2;
		if (res_2 == 'R' || res_2 == 'r')
		{
			print(b, k);
		}

		// поиск элемента массива структур

		cout << endl;
		cout << "Выполнить поиск элемента массива структур?" << endl;
		cout << "Введите Y(y), если да, иначе введите любой другой символ: ";
		char res_3;
		cin >> res_3;
		if (res_3 == 'Y' || res_3 == 'y')
		{
			cout << "По какому критерию будет поиск" << endl;
			cout << "Введите 1, если по фамилии" << endl << "Введите 2, если по имени" << endl << "Введите 3, если по отчеству"
				<< endl << "Введите 4, если по городу" << endl << "Введите 5, если по улице" << endl << "Введите 6, если по номеру дома"
				<< endl << "Введите 7, если по номеру квартиры" << endl << "Введите 8, если по номеру кредитной карты" << endl
				<< "Введите 9, если по коду покупки" << endl;
			bool is = true;
			while (is)
			{


				int otv_4;
				cin >> otv_4;
				string poisk;
				long long int poisk_2;
				if (otv_4 == 1)
				{
					is = false;
					cout << "Введите фамилию: ";
					cin >> poisk;
					for (int i = 0; i < k; i++)
					{
						if (poisk == b[i].surname)
						{
							print_2(b, i);
						}
					}
				}
				else if (otv_4 == 2)
				{
					is = false;
					cout << "Введите имя: ";
					cin >> poisk;
					for (int i = 0; i < k; i++)
					{
						if (poisk == b[i].name)
						{
							print_2(b, i);
						}
					}
				}
				else if (otv_4 == 3)
				{
					is = false;
					cout << "Введите отчество: ";
					cin >> poisk;
					for (int i = 0; i < k; i++)
					{
						if (poisk == b[i].patronymic)
						{
							print_2(b, i);
						}
					}
				}
				else if (otv_4 == 4)
				{
					is = false;
					cout << "Введите город: ";
					cin >> poisk_2;
					for (int i = 0; i < k; i++)
					{
						if (poisk_2 == *b[i].address.city)
						{
							print_2(b, i);
						}
					}
				}
				else if (otv_4 == 5)
				{
					is = false;
					cout << "Введите улицу: ";
					cin >> poisk_2;
					for (int i = 0; i < k; i++)
					{
						if (poisk_2 == *b[i].address.street)
						{
							print_2(b, i);
						}
					}
				}
				else if (otv_4 == 6)
				{
					is = false;
					cout << "Введите номер дома: ";
					cin >> poisk_2;
					for (int i = 0; i < k; i++)
					{
						if (poisk_2 == b[i].address.home)
						{
							print_2(b, i);
						}
					}
				}
				else if (otv_4 == 7)
				{
					is = false;
					cout << "Введите номер квартиры: ";
					cin >> poisk_2;
					for (int i = 0; i < k; i++)
					{
						if (poisk_2 == b[i].address.kv)
						{
							print_2(b, i);
						}
					}
				}
				else if (otv_4 == 8)
				{
					is = false;
					cout << "Введите номер кредитной карты: ";
					cin >> poisk_2;
					for (int i = 0; i < k; i++)
					{
						if (poisk_2 == b[i].credit)
						{
							print_2(b, i);
						}
					}
				}
				else if (otv_4 == 9)
				{
					is = false;
					cout << "Введите код покупки: ";
					cin >> poisk_2;
					for (int i = 0; i < k; i++)
					{
						if (poisk_2 == b[i].code)
						{
							print_2(b, i);
						}
					}
				}
				else
				{
					is = true;
					cout << "Введена неверная цифра, попробуйте ещё раз : " << endl;
				}
			}
		}
		// сортировка по коду покупки

		char res;
		cout << endl;
		cout << "Введите Y(y), если хотите выполнить сортировку по коду" << endl;
		cin >> res;
		if (res == 'Y' || res == 'y')
		{
			SortCode(q, k);
			for (int i = 0; i < k; i++)
			{
				cout << endl << endl;
				cout << i + 1 << " покупатель: " << endl;
				cout << q[i]->surname << "	" << q[i]->name << "	" << q[i]->patronymic << "	" << q[i]->address.city << "	"
					<< q[i]->address.street << "	" << q[i]->address.home << "	" << q[i]->address.kv << "	" << q[i]->credit << "	"
					<< q[i]->code;
			}
		}
	}


	return 0;
}