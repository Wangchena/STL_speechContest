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
	//����ѡ�� ���� 12��
	vector<int> v1;
	//��һ�ֽ�������
	vector<int> v2;
	//ʤ��ǰ�������� 
	vector<int> vVictory;
	//��ű���Լ���Ӧ�ľ���ѡ�� ����
	map<int, Speaker> m_Speaker;
	//��������
	int m_Index;
	//չʾ�˵�
	void showMenu();
	//�˳�ϵͳ
	void exitSystem();
	//��ʼ��
	void initSpeech();
	//����ѡ��
	void createSpeaker();
	//��ʼ���� - �������̿���
	void startSpeech();
	//��ǩ
	void speechDraw();
	//����
	void sppeechContest();
	//��ʾ�������
	void showScore();
	//�����¼
	void saveRecord();
	//��ȡ��¼����
	void loadRecord();
	//�ļ��Ƿ�Ϊ�գ�
	bool fileIsEmpty;
	//�����¼
	map<int, vector<string>>m_Record;
	//��ʾ����÷�
	void showRecord();
	//���
	void clearRecord();





};