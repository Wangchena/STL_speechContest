/*ѧУ����һ���ݽ�����������12���˲μӡ����������֣���һ��Ϊ��̭�����ڶ���Ϊ������
������ʽ�����������ÿ��6���ˣ�
ѡ��ÿ��Ҫ������飬���б���
ÿ��ѡ�ֶ��ж�Ӧ�ı�ţ��� 10001 ~10012
��һ�ַ�Ϊ����С�飬ÿ��6���ˡ� 
���尴��ѡ�ֱ�Ž��г�ǩ��˳���ݽ���
��С���ݽ������̭����������������ѡ�֣�ǰ����������������һ�ֵı�����
�ڶ���Ϊ������ǰ����ʤ��
ÿ�ֱ���������Ҫ��ʾ����ѡ�ֵ���Ϣ

��ʼ�ݽ����������������������̣�ÿ�������׶���Ҫ���û�һ����ʾ���û���������������һ���׶�
�鿴�����¼���鿴֮ǰ����ǰ���������ÿ�α��������¼���ļ��У��ļ���.csv��׺������
��ձ�����¼�����ļ����������
�˳��������򣺿����˳���ǰ����*/
#include<iostream>
using namespace std;
#include"speechManager.h"
int main()
{
	SpeechManeger sp;
	int choice = 0;
	while (true)
	{
		sp.showMenu();
		srand((unsigned int)time(NULL));
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			sp.startSpeech();
			break;
		case 2:
			sp.showRecord();
			break;
		case 3:
			sp.clearRecord();
			break;
		case 0:
			sp.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}

	return 0;

}

