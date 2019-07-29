#include "Chrome(Opera)_Decrypt.h"
#include <Wincrypt.h>
#include "sqlite3.h"
#pragma comment(lib,"crypt32.lib")
#pragma warning(disable:4996)

void ChromeRun()
{
	sqlite3* DB = NULL; // һ���򿪵����ݿ�ʵ��
	sqlite3_stmt* stmt = NULL;// sqlite3_stmt Ԥ����������. ��sqlite3_prepare()��������sqlite3_finalize()����
	string LoginDataPath = getChromeProfilePath() + "Login Data";
	const char* path = LoginDataPath.c_str();	// Login Data sql�ļ���·��

	// �����ļ�·�������ݿ����ӡ�������ݿⲻ���ڣ��򴴽���
	// ���ݿ��ļ���·��������C�ַ������롣
	int result = sqlite3_open(path, &DB);

	if (result == SQLITE_OK) {
		std::clog << "\n�����ݿ����ӳɹ�\n";
		const char* sql = "Select origin_url,username_value,password_value from logins";
		int result1 = sqlite3_prepare_v2(DB, sql, -1, &stmt, NULL);
		if (result1 == SQLITE_OK)
		{
			//��ѯ�ɹ�
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				cout << "URL	: " << U2G((const char*)sqlite3_column_text(stmt, 0)) << endl;
				cout << "Username: " << U2G((const char*)sqlite3_column_text(stmt, 1)) << endl;
				cout << "Password: " << U2G(Decrypt(sqlite3_column_text(stmt, 2), sqlite3_column_bytes(stmt, 2)).c_str()) << endl;
				printf("-----------------------------------------------------------------------------------------------------\n");
				Sleep(70);
			}
		}
		else {
			std::clog << "\n��ѯʧ��(���������δ�ر�)\n";
		}
		//�����������׼��ִ����һ�����
		sqlite3_finalize(stmt);
		//�ر����ݿ�
		sqlite3_close(DB);
	}
	else {
		std::clog << "\n�����ݿ�����ʧ��\n";
	}
	return ;
}

void OperaRun()
{
	sqlite3* DB = NULL; // һ���򿪵����ݿ�ʵ��
	sqlite3_stmt* stmt = NULL;// sqlite3_stmt Ԥ����������. ��sqlite3_prepare()��������sqlite3_finalize()����
	string LoginDataPath = getOperaProfilePath() + "Login Data";
	const char* path = LoginDataPath.c_str();	// Login Data sql�ļ���·��

	// �����ļ�·�������ݿ����ӡ�������ݿⲻ���ڣ��򴴽���
	// ���ݿ��ļ���·��������C�ַ������롣
	int result = sqlite3_open(path, &DB);

	if (result == SQLITE_OK) {
		std::clog << "�����ݿ����ӳɹ�\n";
		const char* sql = "Select origin_url,username_value,password_value from logins";
		int result1 = sqlite3_prepare_v2(DB, sql, -1, &stmt, NULL);
		if (result1 == SQLITE_OK)
		{
			//��ѯ�ɹ�
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				cout << "URL	: " << U2G((const char*)sqlite3_column_text(stmt, 0)) << endl;
				cout << "Username: " << U2G((const char*)sqlite3_column_text(stmt, 1)) << endl;
				cout << "Password: " << U2G(Decrypt(sqlite3_column_text(stmt, 2), sqlite3_column_bytes(stmt, 2)).c_str()) << endl;
				printf("--------------------------------------------------------------------------------\n");
				Sleep(70);
			}
		}
		else {
			std::clog << "��ѯʧ��(���������δ�ر�)\n";
		}
		//�����������׼��ִ����һ�����
		sqlite3_finalize(stmt);
		//�ر����ݿ�
		sqlite3_close(DB);
	}
	else {
		std::clog << "�����ݿ�����ʧ��\n";
	}
	return;
}