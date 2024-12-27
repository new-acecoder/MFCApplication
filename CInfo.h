#pragma once
class CInfo
{
public:
	long long s_id;  //员工编号
	string s_name;   //员工姓名
	string s_gender;  //员工性别
	string s_depart;  //员工所在部门
	int s_age;        //员工年龄
	string s_date;       //工作时间
	float s_salary;     //员工工资
	string s_title;   //职称
	string s_vitae;   //简历
	CInfo();
	CInfo(long long id, string name,string gender,string depart,int age,string date,float salary,string title,string vitae);
	CInfo::CInfo(const CInfo& other);
	void load(ifstream&in);
	void Save(ofstream&out);

};

