//
//

#ifndef _SHAREDMEMORY_H
#define _SHAREDMEMORY_H

typedef struct
{
	bool m_UserMode;
	bool m_Simulator;
	bool m_Start;

	signed long long m_TimeUs;
	signed long long m_TimeMs;
	signed long long m_DeltaTimeUs;
	signed long long m_DeltaTimeMs;
	
	unsigned int m_BootTime; // 相对于 NS100_RTC_2010_01_01 的秒数
	unsigned int m_SysTime;

	signed long long m_TimerCounter;

	//CPlcMemMap m_PlcMemMap;//1395212

	int m_PdoSize;

	//PdoVmCode_t m_PdoCodeIn[4096];
	//PdoVmCode_t m_PdoCodeIn2[4096];
	//PdoVmCode_t m_PdoCodeOut[4096];
	//PdoVmCode_t m_PdoCodeOut2[4096];

	//CMsgInFifo m_msgIn;//524296
	//CMsgOutFifo m_msgOut;//524296

	//CServoControlData m_Servo_Control_Data;//65544
	//CServoFeedbackData m_Servo_Feedback_Data;//65544

	//CLeadScrewData m_LeadScrewData;//164160
	//CFrictData m_FrictData;//40960

	bool m_Expired;
	unsigned long m_ExpirationTime;

	int m_SlaveCount;
	int m_AxisCount;

	//FeedbackPosition_t m_FeedbackPosition[MAX_AXIS_COUNT];
	
	char m_KernerData[1024];//用于测试
	unsigned long long m_sendecat_count;
	unsigned long long m_recvecat_count; 
	unsigned long long m_200or400_count; 
	unsigned long long m_400or600_count; 
	unsigned long long m_600or800_count; 
	unsigned long long m_800or1000_count; 
	
	unsigned long long m_a[65530];
	unsigned long long m_b[65530]; 
	unsigned long long m_d[65530]; 
	unsigned long long m_e[65530]; 
	unsigned long long m_f[65530]; 
	unsigned long long m_g[65530]; 
	
}KernelSharedMemory_t;


#endif /*_SHAREDMEMORY_H*/
