#pragma once
class CInfo
{
public:
	long long s_id;  //Ա�����
	string s_name;   //Ա������
	string s_gender;  //Ա���Ա�
	string s_depart;  //Ա�����ڲ���
	int s_age;        //Ա������
	string s_date;       //����ʱ��
	float s_salary;     //Ա������
	string s_title;   //ְ��
	string s_vitae;   //����
	CInfo();
	CInfo(long long id, string name,string gender,string depart,int age,string date,float salary,string title,string vitae);
	CInfo::CInfo(const CInfo& other);
	void load(ifstream&in);
	void Save(ofstream&out);

};

