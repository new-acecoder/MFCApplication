#pragma once
#include"CInfo.h"
class CDataInterface
{
public:
	bool Open(CString FilePath);
	void Add(CInfo Info);
	void Del(int index);
	void Amend(int index, CInfo Info);
	CInfo Find(long long id);
	bool Save(CString FilePath);
	void CDataInterface::SortByID();
	vector<CInfo>Infos;
};

