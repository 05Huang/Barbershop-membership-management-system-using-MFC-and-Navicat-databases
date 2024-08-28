#pragma once
#include "MemberInfo.h"
#define SQL_MAX 256
class SQLInterface
{
public:
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL mysqlCon;//connect
	char sql[SQL_MAX];
	bool Connect_MySQL();//连接数据库
	 vector<MemberInfo>  Get_All_Info();//获取全部信息
	 bool Add_Info(MemberInfo Info);//添加会员信息
	 bool Del_Info(MemberInfo Info);//删除会员信息
	 bool Update_info(MemberInfo old_Info,MemberInfo new_Info);//修改会员信息
	 vector<MemberInfo> Seek_info1(CString name);
	 vector<MemberInfo> Seek_info2(CString phone);
	 vector<MemberInfo> Seek_info3(CString phone);
};

