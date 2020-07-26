#include"speechManager.h"

SpeechManeger::SpeechManeger()
{
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
}
SpeechManeger::~SpeechManeger()
{

}
//չʾ�˵�
void SpeechManeger::showMenu()
{
	cout << "********************************************" << endl;
	cout << "************* ��ӭ�μ��ݽ����� ************" << endl;
	cout << "************* 1.��ʼ�ݽ����� *************" << endl;
	cout << "************* 2.�鿴�����¼ *************" << endl;
	cout << "************* 3.��ձ�����¼ *************" << endl;
	cout << "************* 0.�˳��������� *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
//�˳�ϵͳ
void SpeechManeger::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("cls");
	exit(0);
}
//��ʼ��
void SpeechManeger::initSpeech()
{
	//������֤Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Record.clear();
	//��ʼ����������
	this->m_Index = 1;

}
//����ѡ��
void SpeechManeger::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		Speaker ssp;
		ssp.m_Name = name;
		for (int i = 0; i < 2; i++)
		{
			ssp.m_Score[i] = 0;
		}
		this->v1.push_back(i + 10001);
		this->m_Speaker.insert(make_pair(i + 10001, ssp));
	}
}
//��ʼ���� - �������̿���
void SpeechManeger::startSpeech()
{
	//��һ�ֱ���
//1����ǩ
	speechDraw();
//2������
	sppeechContest();
//3����ʾ�������
	showScore();
//�ڶ��ֱ���
	this->m_Index++;
//1����ǩ
	speechDraw();
//2������
	sppeechContest();
//3����ʾ���ս��
	showScore();
//4���������
	saveRecord();
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
}
//��ǩ
void SpeechManeger::speechDraw()
{
	cout << "�� << " << this->m_Index << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "---------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());//����Ԫ��
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		} cout << endl;
	}
	cout << "---------------------" << endl;
	system("pause");
	cout << endl;

}
//����
void SpeechManeger::sppeechContest()
{
	cout << "------------- ��" << this->m_Index << "����ʽ������ʼ��------------- " << endl;
	//��ʱ����������key���� value ѡ�ֱ��
	multimap<double, int, greater<int>> groupScore; 
	int num = 0;//��¼��Ա����6��һ��
	vector<int>v_Src;
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());
		d.pop_back();
		d.pop_front();
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
		//6��һ�飬����ʱ��������
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it
				!= groupScore.end(); it++)
			{
				cout << "���: " << it->second << " ������ " << this->m_Speaker[it -> second].m_Name << " �ɼ��� " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] <<endl;
			}
			int count = 0;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it
				!= groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "------------- ��" << this->m_Index << "�ֱ������ ------------- " << endl;
	system("pause");

}
//��ʾ�������
void SpeechManeger::showScore()
{
	cout << "---------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�-----------" << endl;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	} else
	{
	v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << " ������ " << m_Speaker[*it].m_Name << " �÷֣� " <<
			m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	} cout << endl;
	system("pause");
	system("cls");
	this->showMenu();

}
//�����¼
void SpeechManeger::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;
	this->fileIsEmpty = false;
	system("pause");
	system("cls");
}
//��ȡ��¼����
void SpeechManeger::loadRecord()
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())//��������ļ���β
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	ifs.putback(ch);
	string data;
	int index = 0;
	while (ifs >> data)
	{
		vector<string> v;
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string tmp = data.substr(start, pos - start);
			v.push_back(tmp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));

		index++;

	}
	ifs.close();
}
void SpeechManeger::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "�� " <<
				"�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
				"�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
				"������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
		} 
	}
	system("pause");
	system("cls");
	
}
//���
void SpeechManeger::clearRecord()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open("speech.csv", ios::trunc);
		ofs.close();
		this->initSpeech();
		this->createSpeaker();
		this->loadRecord();
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}
