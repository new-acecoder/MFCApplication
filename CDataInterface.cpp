#include "pch.h"
#include "CDataInterface.h"

bool CDataInterface::Open(CString FilePath)
{
    ifstream in(FilePath, ios::in);
        if (in.is_open()) {
            int num;  //记录有多少个员工
            in >> num;
            for (int i = 0; i < num; i++) {
                CInfo Info;
                Info.load(in);
                Infos.push_back(Info);
            }
            return true;
        }
    return false;
}

void CDataInterface::Add(CInfo Info)
{
    Infos.push_back(Info);
}

void CDataInterface::Del(int index)
{
    Infos.erase(Infos.begin() + index);
}

void CDataInterface::Amend(int index, CInfo Info)
{
    Infos[index] = Info;
}

CInfo CDataInterface::Find(long long id)
{
    for (int i = 0; i < Infos.size(); i++) {
        if (Infos[i].s_id == id)
            return Infos[i];
    }
    return CInfo();
}

bool CDataInterface::Save(CString FilePath)
{

    ofstream out(FilePath, ios::out);
    if (out.is_open()) {
        out << Infos.size() << endl;
        for (int i = 0; i < Infos.size(); i++) {
            Infos[i].Save(out);;
        }
        out.close();
        return true;
    }
    return false;
}

void CDataInterface::SortByID()
{
    std::sort(Infos.begin(), Infos.end(), [](const CInfo& a, const CInfo& b) {
        return a.s_id < b.s_id; // 按 s_id 升序排序
        });
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       