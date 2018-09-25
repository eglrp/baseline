///////////////////////////////////////////////////////////
//  Business.h
//  Implementation of the Class CBusiness
//  Created on:      2012-03
//  Original author: sxliu
///////////////////////////////////////////////////////////
#pragma once

#include "ISolution.h"

class CBusiness
{
public:
	CBusiness(void);
	virtual ~CBusiness(void);

	// ���ؽ������ģ��
	bool LoadSolution();

	// ж�ؽ������ģ��
	void FreeSolution();

	// ��ȡ�������ģ��
	ISolution* GetSolution();

protected:
	// �������ģ��ʵ�����
	ISolution* m_pSolution;

	// �߳�ֹͣ�¼����
	HANDLE m_hStopProcess;

	// �Ƿ��Ѿ������������
	bool m_bEncrypt;
};
