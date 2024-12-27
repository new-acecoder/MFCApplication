#include "pch.h"
#include "CInfo.h"

CInfo::CInfo()
	: s_id(-1), s_name(""), s_gender(""), s_depart(""), s_age(0), s_salary(0.0), s_title(""), s_vitae("") {
}


CInfo::CInfo(long long id, string name, string gender, string depart, int age, string date, float salary, string title, string vitae)
{
	s_id = id;
	s_name = name;
	s_gender = gender;
	s_depart = depart;
	s_age = age;
	s_date = date;
	s_salary = salary;
	s_title = title;
	s_vitae = vitae;


}
CInfo::CInfo(const CInfo& other) {
	s_id = other.s_id;
	s_name = other.s_name;
	s_gender = other.s_gender;
	s_depart = other.s_depart;
	s_age = other.s_age;
	s_date = other.s_date;
	s_salary = other.s_salary;
	s_title = other.s_title;
	s_vitae = other.s_vitae;
}

void CInfo::load(ifstream& in)
{
	in >> s_id;
	in >> s_name;
	in >> s_gender;
	in >> s_depart;
	in >> s_age;
	in >> s_date;
	in >> s_salary;
	in >> s_title;
	in >> s_vitae;
}

void CInfo::Save(ofstream& out)
{
	out << s_id << "\t";
	out << s_name << "\t";
	out << s_gender << "\t";
	out << s_depart << "\t";
	out << s_age << "\t";
	out << s_date << "\t";
	out << s_salary << "\t";
	out << s_title << "\t";
	out << s_vitae << "\n";
}


