// baseline.h : baseline DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CbaselineApp
// �йش���ʵ�ֵ���Ϣ������� baseline.cpp
//

class CbaselineApp : public CWinApp
{
public:
	CbaselineApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
