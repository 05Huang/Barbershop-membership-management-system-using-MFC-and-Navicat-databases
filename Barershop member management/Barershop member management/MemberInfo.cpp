#include "pch.h"
#include "MemberInfo.h"
MemberInfo::MemberInfo()
{

}
MemberInfo::MemberInfo(string phone, string name, string sex, double balance, string grade)
{
	m_phone = phone;
	m_name = name;
	m_sex = sex;
	m_balance = balance;
	m_grade = grade;
}
