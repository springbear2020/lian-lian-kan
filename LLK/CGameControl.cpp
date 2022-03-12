#include "pch.h"
#include "CGameControl.h"

//��ʼ��Ϸ
void CGameControl::StartGame(void)
{
	CGameLogic gameLogic;
	gameLogic.InitMap(m_anMap);
}

//����Ԫ����Ϣ
int CGameControl::GetElement(int nRow, int nCol)
{
	return m_anMap[nRow][nCol];
}

//���õ�һ����
void CGameControl::SetFirstPoint(int nRow, int nCol)
{
	m_svSelFst.row = nRow;
	m_svSelFst.col = nCol;
}

//���õڶ�����
void CGameControl::SetSecPoint(int nRow, int nCol)
{
	m_svSelSec.row = nRow;
	m_svSelSec.col = nCol;
}

//����
bool CGameControl::Link(Vertex avPath[2])
{
	//�ж�����ѡ�е��Ƿ���ͬһ����
	if (m_svSelFst.row == m_svSelSec.row && m_svSelFst.col == m_svSelSec.col)
	{
		return false;
	}

	//�ж�����ѡ���ͼƬ�Ƿ���ͬͼƬ
	if (m_anMap[m_svSelFst.row][m_svSelFst.col] != m_anMap[m_svSelSec.row][m_svSelSec.col])
	{
		return false;
	}

	//�ж��Ƿ���ͨ
	CGameLogic logic;
	if (logic.IsLink(m_anMap, m_svSelFst, m_svSelSec))
	{
		//����
		logic.Clear(m_anMap, m_svSelFst, m_svSelSec);

		//����·������
		avPath[0] = m_svSelFst;
		avPath[1] = m_svSelSec;
		return true;
	} 
	return false;
}