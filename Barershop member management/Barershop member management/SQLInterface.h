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
	bool Connect_MySQL();//�������ݿ�
	 vector<MemberInfo>  Get_All_Info();//��ȡȫ����Ϣ
	 bool Add_Info(MemberInfo Info);//��ӻ�Ա��Ϣ
	 bool Del_Info(MemberInfo Info);//ɾ����Ա��Ϣ
	 bool Update_info(MemberInfo old_Info,MemberInfo new_Info);//�޸Ļ�Ա��Ϣ
	 vector<MemberInfo> Seek_info1(CString name);
	 vector<MemberInfo> Seek_info2(CString phone);
	 vector<MemberInfo> Seek_info3(CString phone);
};

