#include "Func.h"

int _stateMenu;
void Menu()
{
	cout << "Выберите действие" << endl
		<< "(0) Exit" << endl
		<< "(1)Input data " << endl
		<< "(2) Output data" << endl
		<< "(3) redact data" << endl
		<< "(4) delete data" << endl
		<< "(5) add data" << endl
		<< "(6) Save data" << endl
		<< "choose:";
	cin >> _stateMenu;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	DataInit();

	Menu();

	int _actions;
	string filename;

	while (_stateMenu != 0)
	{
		switch (_stateMenu)
		{
		case 1:
			system("cls");

			cout << "vvod console or file: ";
			cin >> _actions;

			system("cls");

			if (_actions == 1)
			{
				DataEntry();
			}
			else
			{
				cout << "filename: ";
				cin >> filename;

				DataReading(filename);

			}

			system("pause");
			system("cls");
			Menu();
			break;
		case 2:
			system("cls");
			Print();
			system("pause");
			system("cls");
			Menu();
			break;

		case 3:
			system("cls");
			DataChange();
			system("pause");
			system("cls");
			Menu();
			break;

		case 4:
			system("cls");
			DeleteData();
			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");
			AddData();
			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");
			SaveData(filename);
			system("pause");
			system("cls");
			Menu();
			break;
		default:
			cout << "error" << endl;
			Menu();
			break;
		}
	}
	system("cls");
	if (DataCleaning())
	{
		cout << "Data clean" << endl;
	}
	else
	{
		cout << "Data NOT clean" << endl;
	}

	cout << "Thanks for work" << endl;
	system("pause");
}
