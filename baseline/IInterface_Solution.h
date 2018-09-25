///////////////////////////////////////////////////////////
//  IInterface_Solution.h
//  Implementation of the Class IInterface_Solution
//  Created on:      2012-03
//  Original author: sxliu
///////////////////////////////////////////////////////////
#pragma once
#include "compute.h"

class IInterface_Solution
{
public:
	/// <summary>
	/// ����ο�ϵ
	/// </summary>
	typedef enum COORDSYSTEMTYPE
	{
		// WGS84��������ϵ
		WGS84_XYZ,
		// ������ֲ�����ϵ
		LLS_NEU
	}COORDSYSTEMTYPE;

public:
	/// <summary>
	/// ��ʼ������ģ��
	/// </summary>
	virtual bool Initialize() = 0;

	/// <summary>
	/// ��������
	/// </summary>
	/// <param name="sBaseFile">��׼�������ļ���</param>
	/// <param name="sRemoteFile">���������ļ���</param>
	virtual int GPSDecord(char* sBaseFile, char* sRemoteFile) = 0;

	/// <summary>
	/// ��ý����Ļ�������ֵ
	/// </summary>
	/// <param name="emCoordSys">����ο�ϵ����</param>
	/// <param name="x">�����������xֵ</param>
	/// <param name="y">�����������yֵ</param>
	/// <param name="z">�����������zֵ</param>
	virtual void GetTransformValue(COORDSYSTEMTYPE emCoordSys, double& x, double& y, double& z) = 0;

	/// <summary>
	/// ��ý�����λ�ƾ���
	/// </summary>
	/// <param name="emCoordSys">����ο�ϵ����</param>
	/// <param name="px">����x����λ�ƾ���</param>
	/// <param name="py">����y����λ�ƾ���</param>
	/// <param name="pz">����z����λ�ƾ���</param>
	virtual void GetTransformPrecision(COORDSYSTEMTYPE emCoordSys, double& px, double& py, double& pz) = 0;

	/// <summary>
	/// ������н�����
	/// </summary>
	/// <param name="emCoordSys">����ο�ϵ����</param>
	/// <param name="allResult">���н�����</param>
	virtual void GetAllResult(COORDSYSTEMTYPE emCoordSys, BLINF& allResult) = 0;

	/// <summary>
	/// ���û�׼վ�̶���ʼλ������ֵ
	/// </summary>
	/// <param name="lonDeg">���� ��λ ��</param>
	/// <param name="latDeg">γ�� ��λ ��</param>
	/// <param name="Hgh">��</param>
	virtual void SetBaseLBH(double lonDeg, double latDeg, double Hgh) = 0;

	/// <summary>
	/// WGS84��γ��ת��ΪWGS84XYZ����
	/// </summary>
	/// <param name="lonDeg">���� ��λ ��</param>
	/// <param name="latDeg">γ�� ��λ ��</param>
	/// <param name="Hgh">��</param>
	/// <param name="X">���WGS84��X����</param>
	/// <param name="Y">���WGS84��Y����</param>
	/// <param name="Z">���WGS84��Z����</param>
	virtual void LBHtoXYZ(double lonDeg, double latDeg, double Hgh, double& X, double& Y, double& Z) = 0;

	/// <summary>
	/// WGS84XYZת��ΪWGS84��γ������
	/// </summary>
	/// <param name="X">WGS84X����</param>
	/// <param name="Y">WGS84Y����</param>
	/// <param name="Z">WGS84Z����</param>
	/// <param name="lonDeg">������� ��λ ��</param>
	/// <param name="latDeg">���γ�� ��λ ��</param>
	/// <param name="Hgh">�����</param>
	virtual void XYZtoLBH(double X, double Y, double Z, double& lonDeg, double& latDeg, double& Hgh) = 0;

	/// <summary>
	/// WGS84��γ��ת��Ϊ��ƽϵ�µ�����
	///����ϵ����Ϊ�������죬����X��Ϊ����Y��Ϊ����Z��Ϊ��
	/// </summary>
	/// <param name="BaseLonDeg">��ƽϵ����ԭ��ľ���</param>
	/// <param name="BaseLatDeg">��ƽϵ����ԭ���γ��</param>
	/// <param name="BaseHgh">��ƽϵ����ԭ��ĸ�</param>
	/// <param name="RemoteLonDeg">��ת����ľ���</param>
	/// <param name="RemoteLatDeg">��ת�����γ��</param>
	/// <param name="RemoteHgh">��ת����ĸ�</param>
	/// <param name="RX">��������</param>
	/// <param name="RY">��������</param>
	/// <param name="RZ">��������</param>
	virtual void WGS84toLLSNEU(double BaseLonDeg, double BaseLatDeg, double BaseHgh, 
		double RemoteLonDeg, double RemoteLatDeg, double RemoteHgh, double& RX, double& RY, double& RZ) = 0;
};

//�����������ģ��
_declspec(dllexport) bool CreateSolutionModule();

//�ͷŽ������ģ��
_declspec(dllexport) void ReleaseSolutionModule();

//�������� ����ֵΪ0,��������ɹ�,����,��������ʧ��
/// <param name="sBaseFile">��׼�������ļ���</param>
/// <param name="sRemoteFile">���������ļ���</param>
/// <param name="x">�����������xֵ</param>
/// <param name="y">�����������yֵ</param>
/// <param name="z">�����������zֵ</param>
/// <param name="px">����x����λ�ƾ���</param>
/// <param name="py">����y����λ�ƾ���</param>
/// <param name="pz">����z����λ�ƾ���</param>
/// <param name="coordSysType">����ο�ϵ���� 0-WGS84��������ϵ 1-������ֲ�����ϵ(Ĭ��)</param>
_declspec(dllexport) int BaseLine(char* sBaseFile, char* sRemoteFile,
								   double& x, double& y, double& z,
								   double& px, double& py, double& pz, int coordSysType = 1);

//���н������� ����ֵΪ0,��������ɹ�,����,��������ʧ��
/// <param name="sBaseFile">��׼�������ļ���</param>
/// <param name="sRemoteFile">���������ļ���</param>
/// <param name="allResult">���н�����</param>
/// <param name="coordSysType">����ο�ϵ���� 0-WGS84��������ϵ 1-������ֲ�����ϵ(Ĭ��)</param>
_declspec(dllexport) int AllResult(char* sBaseFile, char* sRemoteFile,
	BLINF& allResult, int coordSysType = 1);

/// <summary>
/// ���û�׼վ�̶���ʼλ������ֵ
/// ��ͨ���޸������ļ��ķ�ʽ��Ҳ���ڳ����е��øýӿڽ�����������
/// </summary>
/// <param name="lonDeg">���� ��λ ��</param>
/// <param name="latDeg">γ�� ��λ ��</param>
/// <param name="Hgh">��</param>
_declspec(dllexport) void SetBaseLBH(double lonDeg, double latDeg, double Hgh);


//////////////////////////////////////////////////////////////////////////
// ����Ϊ�����ļ�������ת���ӿں������û��ɸ���ʵ�����������ؽӿ�

/// <summary>
/// WGS84��γ��ת��ΪWGS84XYZ����
/// </summary>
/// <param name="lonDeg">���� ��λ ��</param>
/// <param name="latDeg">γ�� ��λ ��</param>
/// <param name="Hgh">��</param>
/// <param name="X">���WGS84��X����</param>
/// <param name="Y">���WGS84��Y����</param>
/// <param name="Z">���WGS84��Z����</param>
_declspec(dllexport) void LBHtoXYZ(double lonDeg, double latDeg, double Hgh, double& X, double& Y, double& Z);

/// <summary>
/// WGS84XYZת��ΪWGS84��γ������
/// </summary>
/// <param name="X">WGS84X����</param>
/// <param name="Y">WGS84Y����</param>
/// <param name="Z">WGS84Z����</param>
/// <param name="lonDeg">������� ��λ ��</param>
/// <param name="latDeg">���γ�� ��λ ��</param>
/// <param name="Hgh">�����</param>
_declspec(dllexport) void XYZtoLBH(double X, double Y, double Z, double& lonDeg, double& latDeg, double& Hgh);

/// <summary>
/// WGS84��γ��ת��Ϊ��ƽϵ�µ�����
///����ϵ����Ϊ�������죬����X��Ϊ����Y��Ϊ����Z��Ϊ��
/// </summary>
/// <param name="BaseLonDeg">��ƽϵ����ԭ��ľ���</param>
/// <param name="BaseLatDeg">��ƽϵ����ԭ���γ��</param>
/// <param name="BaseHgh">��ƽϵ����ԭ��ĸ�</param>
/// <param name="RemoteLonDeg">��ת����ľ���</param>
/// <param name="RemoteLatDeg">��ת�����γ��</param>
/// <param name="RemoteHgh">��ת����ĸ�</param>
/// <param name="RX">��������</param>
/// <param name="RY">��������</param>
/// <param name="RZ">��������</param>
_declspec(dllexport) void WGS84toLLSNEU(double BaseLonDeg, double BaseLatDeg, double BaseHgh, 
						   double RemoteLonDeg, double RemoteLatDeg, double RemoteHgh, double& RX, double& RY, double& RZ);