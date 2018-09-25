///////////////////////////////////////////////////////////
//  ISolution.h
//  Implementation of the Class ISolution
//  Created on:      2012-03
//  Original author: sxliu
///////////////////////////////////////////////////////////
#pragma once
#include "IInterface_Solution.h"
#include <afxstr.h>
#include "compute.h"


class ISolution : public IInterface_Solution
{
public:
	ISolution(void);
	virtual ~ISolution(void);

	// ��ʼ������ģ��
	bool Initialize();

	// ��������
	int GPSDecord(char* sBaseFile, char* sRemoteFile);

	// ��ý����Ļ�������ֵ
	void GetTransformValue(COORDSYSTEMTYPE emCoordSys, double& x, double& y, double& z);

	// ��ý�����λ�ƾ���
	void GetTransformPrecision(COORDSYSTEMTYPE emCoordSys, double& px, double& py, double& pz);

	//������н�����
	void GetAllResult(COORDSYSTEMTYPE emCoordSys, BLINF& allResult);

	// ���ù̶�վ��ʼ����λ������
	void SetBaseLBH(double lonDeg, double latDeg, double Hgh);

	// ������֤״̬
	void SetIsVerified(bool bVerify);

	// �����������������ת��
	void LBHtoXYZ(double lonDeg, double latDeg, double Hgh, double& X, double& Y, double& Z);

	// �����������������ת��
	void XYZtoLBH(double X, double Y, double Z, double& lonDeg, double& latDeg, double& Hgh);

	// �ֲ�����ϵ����:ָ�������Ϊԭ��,�õ���������ΪX,����ΪY,���Ϸ�ΪZ
	// ����������ָ��ԭ��ĵ���ֲ�����ת��,BaseLonDegΪ�ο�ԭ�������
	void WGS84toLLSNEU(double BaseLonDeg, double BaseLatDeg, double BaseHgh,
		double RemoteLonDeg, double RemoteLatDeg, double RemoteHgh, double& RX, double& RY, double& RZ);
	
private:
	// �źŻ�����
	CRITICAL_SECTION m_csLock;

	// ��֤�Ƿ�ͨ��
	bool m_bVerified;

protected:
	// �������
	int m_nGPS;
	int m_nGlonass;
	int m_nBeidou;
	int m_nFreq;
	int m_nEpSample;
	int m_nCutOff;
	double m_dRatio;
	double m_dRms;

	// �̶�վ��ʼ����λ������ֵ
	double m_dBaseLon;
	double m_dBaseLat;
	double m_dBaseHgh;

	// ��ǰ�����Ļ�������ֵ
	double m_dX;
	double m_dY;
	double m_dZ;

	// ��ǰ������λ�ƾ���
	double m_dPX;
	double m_dPY;
	double m_dPZ;

	//��ǰ���н�����
	BLINF m_sAll;
};
