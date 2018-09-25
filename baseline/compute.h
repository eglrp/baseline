#ifndef LIB_H
#define LIB_H


typedef struct BlInf 
{
	//�������
	char BaseName[120];                //�����ļ���
	char RoveName[120];                //����ļ���
	int epBegin;		               //���߽�����ʼ��Ԫ	
	int epEnd;                         //���߽�����ֹ��Ԫ
	int epSample;                      //��Ԫ������� 
	int CutOff;                        //��ֹ��(��) 
	int SolG;                          //GPS����     1: ���� 0:������ 
	int SolN;                          //Glonass���� 1: ���� 0:������ 
	int SolB;                          //Bd����      1: ���� 0:������ 
	int Freq;                          //��Ƶ����    0: L1(B1) 1:˫Ƶ 2:��Ƶ 
	
	//�����������
	double x0;double y0; double z0;    //�̶�վ����	
    double dx; double dy; double dz;   //��������
									   //��ExProBaseline()Ϊ�������
	
	//�������
	double dis;						   //���߳�      
	double px; double py; double pz;   //x,y,z����Ľ��㾫��
	double ratio;                      //ratio
	double rms;                        //rms
	int epoch;                         //��Ԫ�� 
	int mear;                          //�۲�ֵ��
	int reject;                        //�޳��۲�ֵ��
	double rdop;                       //RDOP
	double SecBegin;                   //��ʼʱ�� (GPS second)       
	double SecEnd;                     //��ֹʱ�� (GPS second)
} BLINF;

extern "C"  int __declspec(dllexport) ProBaseline(BLINF *);//���߽���
extern "C"  int __declspec(dllexport) ExProBaseline(BLINF *);//������Ϣ���߽���

//����ֵ
// -1    �޷��������ļ�
// -2    �����ļ�û��Gnss�۲�����
// -3    ����������,�޷�����
//  1    ����ɹ�
 
#endif 