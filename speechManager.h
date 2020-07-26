#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<numeric>
#include<fstream>
#include<ctime>
using namespace std;

class SpeechManeger
{
public:
	SpeechManeger();
	~SpeechManeger();
	//比赛选手 容器 12人
	vector<int> v1;
	//第一轮晋级容器
	vector<int> v2;
	//胜利前三名容器 
	vector<int> vVictory;
	//存放编号以及对应的具体选手 容器
	map<int, Speaker> m_Speaker;
	//比赛轮数
	int m_Index;
	//展示菜单
	void showMenu();
	//退出系统
	void exitSystem();
	//初始化
	void initSpeech();
	//创建选手
	void createSpeaker();
	//开始比赛 - 比赛流程控制
	void startSpeech();
	//抽签
	void speechDraw();
	//比赛
	void sppeechContest();
	//显示比赛结果
	void showScore();
	//保存记录
	void saveRecord();
	//读取记录分数
	void loadRecord();
	//文件是否为空？
	bool fileIsEmpty;
	//往届记录
	map<int, vector<string>>m_Record;
	//显示往届得分
	void showRecord();
	//清空
	void clearRecord();





};