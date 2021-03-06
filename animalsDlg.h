
// animalsDlg.h: 头文件
//

#pragma once
#include "afxwin.h"


#define fact_num 31      //知识库中的知识:31种知识
#define rule_num 15      //知识库中的规则：15条规则
#define rule_volume 4    //规则中每个结果最多有4个前提条件
#define object_range_begin 25  //从第25个知识开始
#define object_range_end 31    //到第31个知识为目标结论
#define object_middle_begin 21     //中间结果起始位置

// CanimalsDlg 对话框
class CanimalsDlg : public CDialog
{
// 构造
public:
	CanimalsDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ANIMALS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedEnable();
	afx_msg void OnBnClickedExit();
	// 使能按钮
	CButton m_Enable;
	// 退出程序
	CButton m_Exit;
	// 输出结果对话框// 输出结果对话框
//	CString m_output;
//	afx_msg void OnChangeOutput();
//	CString m_Output;
//	afx_msg void OnErrspaceOutput();
	afx_msg void OnEnChangeOutput();
	// 输出对话框
	CString m_Output;
//	CString m_Input;
//	afx_msg void OnEnChangeInput();
	bool  CanimalsDlg::backward_reasoning(int num, int message[]);   //反向推理
	bool  CanimalsDlg::inference(int num, int message[]);         //迭代推理机
																  // 输入的规则的数量
	CString m_Input_num;
	afx_msg void OnEnChangeInputnum();


	bool flag;
	int fla_g;
	int num;
	int message[fact_num];
	//int new_message[fact_num];
	int ii1, ij1, ik1, im1, in1;
	int hit_num1 = 0;          //输入前提也规则前提重合数
	int prerequisite_num1;     //规则前提数
	int message_c[fact_num];           //迭代前提
	int num_c;                //迭代前提数量
	int iii;

	bool flag_back = false;
	int ii, ij, ik;
	int prerequisite_num = 0;
	int hit_num = 0;
	int need_rule_number[rule_num];
	int hit_rule_number[rule_num];
	float hit_rule_rate[rule_num];
	float best_hit_rule_rate = 0;
	int best_hit_rule_number;
	//int *new_message;
	CString input;

	CString a, b, c;

	afx_msg void OnBnClickedButton1();
	// 清除按钮// 清除按钮
	CButton m_Clear;
	afx_msg void OnBnClickedClear();
	// 关于按钮
	CButton m_About;
	afx_msg void OnBnClickedAbout();
	// 选择是对还是错// 选择是对还是错
//	CString m_YorN;
//	afx_msg void OnErrspaceYesNo();
//	afx_msg void OnHscrollYesNo();
	CButton m_try;
	afx_msg void OnBnClickedTry();
//	CButton m_Rule;
//	CString m_Edit1;
//	afx_msg void OnBnClickedRule();
	CButton m_Rule;
	afx_msg void OnBnClickedRule();
	CString m_Edit1;
//	CButton m_bu;
	CButton m_buttom;
	afx_msg void OnBnClickedBut();
};
