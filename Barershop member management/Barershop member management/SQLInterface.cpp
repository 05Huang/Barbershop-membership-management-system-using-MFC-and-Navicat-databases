#include "pch.h"
#include "SQLInterface.h"

bool SQLInterface::Connect_MySQL()
{
    mysql_init(&mysqlCon);
    if (!mysql_real_connect(&mysqlCon, "localhost", "root", "123456", "memberinfo", 3306, NULL, 0))
    {
        AfxMessageBox(_T("��������ʧ�ܣ�"));
        return false;
    }
    else
    {
        AfxMessageBox(_T("�ɹ��������ݿ�"));
        mysql_query(&mysqlCon, "SET NAMES 'GB2312'");
    }
    return true;
}

vector<MemberInfo> SQLInterface::Get_All_Info()
{
    vector<MemberInfo> Info;
    //C��������ַ���
    snprintf(sql, SQL_MAX, "SELECT * FROM info1");
    //��ѯ����
    int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
    //�жϲ�ѯ���
    if (ret)
    {
        AfxMessageBox(_T("��ѯʧ�ܣ�"));
        return Info;
    }
    //��ȡ�����
    res = mysql_store_result(&mysqlCon);
    //��ȡ��ѯ����һ�н����
    //��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݣ�
    while (row = mysql_fetch_row(res))
    {
       MemberInfo memberinfo = MemberInfo(row[0], row[1], row[2], stod(row[3]),row[4]);
       Info.push_back(memberinfo);
    }
    mysql_free_result(res);
    return Info;
}

bool SQLInterface::Add_Info(MemberInfo Info)
{
    snprintf(sql, SQL_MAX, "INSERT INTO info1 VALUES('%s','%s','%s','%lf','%s');"
        ,Info.m_phone.c_str(), Info.m_name.c_str(), Info.m_sex.c_str(), Info.m_balance, Info.m_grade.c_str());
    //��ѯ����
    int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
    if (ret)
    {
        AfxMessageBox(_T("����ʧ�ܣ�"));
        return false;
    }
    //�жϲ�ѯ���
    return true;
}

bool SQLInterface::Del_Info(MemberInfo Info)
{
    snprintf(sql, SQL_MAX, "DELETE FROM info1 WHERE phone = '%s';", Info.m_phone.c_str());
    int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
    if (ret)
    {
        AfxMessageBox(_T("ɾ��ʧ�ܣ�"));
        return false;
    }
    //�жϲ�ѯ���
    return true;
}

bool SQLInterface::Update_info(MemberInfo old_Info, MemberInfo new_Info)
{
    // C��������ַ���
    snprintf(sql, SQL_MAX, "UPDATE info1 SET balance = %lf WHERE name = '%s';", new_Info.m_balance, new_Info.m_name.c_str());
    int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
    if (ret)
    {
        AfxMessageBox(_T("�ۿ�ʧ�ܣ�"));
        return false;
    }
    //�жϲ�ѯ���
    return true;

}



vector<MemberInfo> SQLInterface::Seek_info1(CString name)
{
    vector<MemberInfo> result;
    snprintf(sql, SQL_MAX, "SELECT * FROM info1 WHERE name='%s';", name);
    //��ѯ����
    int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
    //�жϲ�ѯ���
    if (ret)
    {
        AfxMessageBox(_T("��ѯʧ�ܣ�"));
        return result;
    }
    //��ȡ�����
    res = mysql_store_result(&mysqlCon);
    //��ȡ��ѯ����һ�н����
    //��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݣ�
    while (row = mysql_fetch_row(res))
    {
        MemberInfo memberinfo = MemberInfo(row[0], row[1], row[2], stod(row[3]), row[4]);
        result.push_back(memberinfo);
    }
    mysql_free_result(res);
    return result;
    
}

vector<MemberInfo> SQLInterface::Seek_info2(CString name)
{
    vector<MemberInfo> result;
    snprintf(sql, SQL_MAX, "SELECT * FROM info1 WHERE phone='%s';", name);
    //��ѯ����
    int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
    //�жϲ�ѯ���
    if (ret)
    {
        AfxMessageBox(_T("��ѯʧ�ܣ�"));
        return result;
    }
    //��ȡ�����
    res = mysql_store_result(&mysqlCon);
    //��ȡ��ѯ����һ�н����
    //��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݣ�
    while (row = mysql_fetch_row(res))
    {
        MemberInfo memberinfo = MemberInfo(row[0], row[1], row[2], stod(row[3]), row[4]);
        result.push_back(memberinfo);
    }
    mysql_free_result(res);
    return result;

}

vector<MemberInfo> SQLInterface::Seek_info3(CString sex)
{
    vector<MemberInfo> result;
    snprintf(sql, SQL_MAX, "SELECT * FROM info1 WHERE sex='%s';", sex);
    //��ѯ����
    int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
    //�жϲ�ѯ���
    if (ret)
    {
        AfxMessageBox(_T("��ѯʧ�ܣ�"));
        return result;
    }
    //��ȡ�����
    res = mysql_store_result(&mysqlCon);
    //��ȡ��ѯ����һ�н����
    //��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݣ�
    while (row = mysql_fetch_row(res))
    {
        MemberInfo memberinfo = MemberInfo(row[0], row[1], row[2], stod(row[3]), row[4]);
        result.push_back(memberinfo);
    }
    mysql_free_result(res);
    return result;
}
