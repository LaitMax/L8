#include "Func.h"

void DataInit()
{
	ofstream _buf("Buffer.txt");

	if (!_buf)
	{
		cout << "Ошибка создания буферного файла!" << endl;
	}
	_buf.close();
}

void DataEntry()
{
	string _surname;
	int _phoneNum;
	string _city;
	int n;

	cout << "Kol-vo of data: ";
	cin >> n;

	ofstream record("Buffer.txt", ios::app);

	if (record)
	{
		record << n << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "surname: ";
			cin >> _surname;

			cout << "phoneNum: ";
			cin >> _phoneNum;

			cout << "city: ";
			cin >> _city;

			record << _surname << endl;
			record << _phoneNum << endl;
			if (i < n - 1)
			{
				record << _city << endl;
			}
			else
			{
				record << _city;
			}
			cout << "_______________________________________________" << endl;

		}

	}
	else
	{
		cout << "error" << endl;
	}
	record.close();
}

void DataReading(string filename)
{
	ifstream reading(filename);
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				reading >> _phoneNum;
				reading >> _city;

				record << _surname << endl;
				record << _phoneNum << endl;
				if (i < n - 1)
				{
					record << _city << endl;
				}
				else
				{
					record << _city;
				}
			}
			cout << "Data read!" << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	else
	{
		cout << "error" << endl;
	}
	reading.close();
	record.close();
}

void Print()
{
	ifstream reading("Buffer.txt");
	if (reading)
	{
		string _surname;
		int _phoneNum;
		string _city;
		int n;

		reading >> n;
		cout << "kol-vo" << n << endl << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "data of #: " << i + 1 << endl;
			reading >> _surname;
			cout << "surname: " << _surname << endl;
			reading >> _phoneNum;
			cout << "phoneNum: " << _phoneNum << endl;
			reading >> _city;
			cout << "city: " << _city << endl;
			cout << "___________________________________________________" << endl;
		}
	}
	else
	{
		cout << "error" << endl;
	}
	reading.close();
}

void DataChange()
{
	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);
	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n, _n;
			reading >> n;
			cout << "choose # from 1 to " << n << ": ";
			cin >> _n;
			_n--;
			system("cls");
			record << n << endl;
			if (_n >= 0 && _n < n)
			{
				for (int i = 0; i < n; i++)
				{
					if (i != _n)
					{
						reading >> _surname;
						record << _surname << endl;

						reading >> _phoneNum;
						record << _phoneNum << endl;

						reading >> _city;
						if (i < n - 1)
						{
							record << _city << endl;
						}
						else
						{
							record << _city;
						}
					}
					else
					{
						cout << "surname: ";
						cin >> _surname;

						cout << "phoneNum: ";
						cin >> _phoneNum;

						cout << "city: ";
						cin >> _city;

						record << _surname << endl;
						record << _phoneNum << endl;
						if (i < n - 1)
						{
							record << _city << endl;
						}
						else
						{
							record << _city;
						}
						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}
					cout << "data change" << endl;
				}
			}
			else
			{
				cout << "phoneNum error" << endl;
			}
		}
		else
		{
			cout << "error" << endl;
		}
	}
	else
	{
		cout << "error" << endl;
	}
	record.close();
	reading.close();

	remove("Buffer_.txt");
}

void Copy()
{
	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);
	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n;

			reading >> n;
			record << n << endl;
			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				record << _surname << endl;

				reading >> _phoneNum;
				record << _phoneNum << endl;

				reading >> _city;
				if (i < n - 1)
				{
					record << _city << endl;
				}
				else
				{
					record << _city;
				}
			}
		}
		else
		{
			cout << "error" << endl;
		}
	}
	else
	{
		cout << "error buffer" << endl;
	}
	record.close();
	reading.close();
}

void DeleteData()
{
	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);
	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n, _n;
			reading >> n;
			int b = n - 1;
			cout << "choose # from 1 to " << n << ": ";
			cin >> _n;
			_n--;
			system("cls");
			record << b << endl;

			if (_n >= 0 && _n < n)
			{
				for (int i = 0; i < n; i++)
				{
					if (i != _n)
					{
						reading >> _surname;
						record << _surname << endl;

						reading >> _phoneNum;
						record << _phoneNum << endl;

						reading >> _city;
						if (i < n - 1)
						{
							record << _city << endl;
						}
						else
						{
							record << _city;
						}
					}
					else
					{
						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}
					cout << "data delete" << endl;
				}
			}
			else
			{
				cout << "Num error" << endl;
			}
		}
		else
		{
			cout << "error" << endl;
		}
	}
	else
	{
		cout << "error" << endl;
	}
	record.close();
	reading.close();

	remove("Buffer_.txt");
}

void AddData()
{
	string _surname;
	int _phoneNum;
	string _city;
	int n = AmountOfData() + 1;

	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);

	if (record_)
	{
		record_ << n << endl;
	}
	else
	{
		cout << "error" << endl;
	}
	if (record)
	{
		record << endl;

		cout << "surname: ";
		cin >> _surname;
		cout << "phone: ";
		cin >> _phoneNum;
		cout << "city: ";
		cin >> _city;

		record << _surname << endl;
		record << _phoneNum << endl;
		record << _city << endl;
	}
	else
	{
		cout << "error" << endl;
	}
	record_.close();
	record.close();

}

int AmountOfData()
{
	ifstream _buf("Buffer.txt");
	int n;

	if (_buf)
	{
		_buf >> n;
	}
	else
	{
		cout << "error" << endl;
	}
	_buf.close();
	return n;
}

void SaveData(string filename)
{
	ifstream reading("Buffer.txt");
	ofstream record(filename, ios::out);

	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				record << _surname << endl;

				reading >> _phoneNum;
				record << _phoneNum << endl;

				reading >> _city;
				if (i < n - 1)
				{
					record << _city << endl;
				}
				else
				{
					record << _city;
				}
				cout << "Data saved in: " << filename << endl;

			}
		}
		else
		{
			cout << "error" << endl;
		}
	}
	else
	{
		cout << "error" << endl;
	}
	record.close();
	reading.close();
}

bool DataCleaning()
{
	bool clear = 0;
	fstream _buf("Buffer.txt", ios::out);

	if (!_buf)
	{
		cout << "error" << endl;
	}
	_buf.clear();
	if (_buf.peek() == EOF)
	{
		clear = 1;
	}
	else
	{
		clear = 0;
	}

	_buf.close();
	return clear;
}