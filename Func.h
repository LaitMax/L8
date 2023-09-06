#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>

using namespace std;

void DataInit();
void DataEntry();
void DataReading(string filename);
void Print();
bool DataCleaning();
void DataChange();
void Copy();
int AmountOfData();
void DeleteData();
void AddData();
void SaveData(string filename);