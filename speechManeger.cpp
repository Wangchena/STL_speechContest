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
//展示菜单
void SpeechManeger::showMenu()
{
	cout << "********************************************" << endl;
	cout << "************* 欢迎参加演讲比赛 ************" << endl;
	cout << "************* 1.开始演讲比赛 *************" << endl;
	cout << "************* 2.查看往届记录 *************" << endl;
	cout << "************* 3.清空比赛记录 *************" << endl;
	cout << "************* 0.退出比赛程序 *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
//退出系统
void SpeechManeger::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("cls");
	exit(0);
}
//初始化
void SpeechManeger::initSpeech()
{
	//容器保证为空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Record.clear();
	//初始化比赛轮数
	this->m_Index = 1;

}
//创建选手
void SpeechManeger::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
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
//开始比赛 - 比赛流程控制
void SpeechManeger::startSpeech()
{
	//第一轮比赛
//1、抽签
	speechDraw();
//2、比赛
	sppeechContest();
//3、显示晋级结果
	showScore();
//第二轮比赛
	this->m_Index++;
//1、抽签
	speechDraw();
//2、比赛
	sppeechContest();
//3、显示最终结果
	showScore();
//4、保存分数
	saveRecord();
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
}
//抽签
void SpeechManeger::speechDraw()
{
	cout << "第 << " << this->m_Index << " >> 轮比赛选手正在抽签" << endl;
	cout << "---------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());//打乱元素
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
//比赛
void SpeechManeger::sppeechContest()
{
	cout << "------------- 第" << this->m_Index << "轮正式比赛开始：------------- " << endl;
	//临时容器，保存key分数 value 选手编号
	multimap<double, int, greater<int>> groupScore; 
	int num = 0;//记录人员数，6个一组
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
		//评委打分
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
		//6人一组，用临时容器保存
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it
				!= groupScore.end(); it++)
			{
				cout << "编号: " << it->second << " 姓名： " << this->m_Speaker[it -> second].m_Name << " 成绩： " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] <<endl;
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
	cout << "------------- 第" << this->m_Index << "轮比赛完毕 ------------- " << endl;
	system("pause");

}
//显示比赛结果
void SpeechManeger::showScore()
{
	cout << "---------第" << this->m_Index << "轮晋级选手信息如下：-----------" << endl;
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
		cout << "选手编号：" << *it << " 姓名： " << m_Speaker[*it].m_Name << " 得分： " <<
			m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	} cout << endl;
	system("pause");
	system("cls");
	this->showMenu();

}
//保存记录
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
	cout << "记录已经保存" << endl;
	this->fileIsEmpty = false;
	system("pause");
	system("cls");
}
//读取记录分数
void SpeechManeger::loadRecord()
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())//如果到了文件结尾
	{
		cout << "文件为空！" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件不为空
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
		cout << "文件为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届 " <<
				"冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
				"亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
				"季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
		} 
	}
	system("pause");
	system("cls");
	
}
//清空
void SpeechManeger::clearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
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
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}
