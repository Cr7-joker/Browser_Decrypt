#include"Chrome(Opera)_Decrypt.h"
#include"Firefox_decrypt.h"
int main() {
	while (1) {
		cout << "\n****************************************" << endl
			 << "*  ������û���Ϣ��ȡ��������ܳ���    *" << endl
			 << "*  ѡ��Chrome�����룺	1              *" << endl
			 << "*  ѡ��Firefox�����룺	2              *" << endl
			 << "*  ѡ��Opera�����룺	3              *" << endl
			 << "*  �˳����������룺	0              *" << endl
			 << "****************************************\n" << endl;
		int input;
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "\nChrome�û���Ϣ��ȡ������" << endl
				 << "------------------------" << endl;
			ChromeRun();
			break;
		case 2:
			cout << "\nFirefox�û���Ϣ��ȡ������" << endl
				 << "-------------------------" << endl;
			FirefoxRun();
			break;
		case 3:
			cout << "\nOpera�û���Ϣ��ȡ������" << endl
				 << "-----------------------" << endl;
			OperaRun();
			break;
		case 0:
			cout << "\n�˳����򡭡�" << endl
				 << "------------------------" << endl;
			return 0;
		default:
			cout << "\n�����������������롭��" << endl
				 << "------------------------" << endl;
			break;
		}
	}
}