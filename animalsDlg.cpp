
// animalsDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "animals.h"
#include "animalsDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




int rule_prerequisite[rule_num][rule_volume] =
{
	{ 1,0,0,0 },
{ 2,0,0,0 },
{ 3,0,0,0 },
{ 4,5,0,0 },
{ 21,6,0,0 },
{ 7,8,9,0 },
{ 21,10,0,0 },
{ 21,11,0,0 },
{ 23,12,13,0 },
{ 23,12,14,0 },
{ 24,15,16,13 },
{ 24,14,0,0 },
{ 22,15,16,4 },
{ 22,18,19,4 },
{ 22,20,0,0 }
};

int rule_result[rule_num] =
{
	21,
	21,
	22,
	22,
	23,
	23,
	24,
	24,
	25,
	26,
	27,
	28,
	29,
	30,
	31
};

CString fact[fact_num] =
{
	"有毛发","产奶","有羽毛","会飞","会下蛋",
	"吃肉","有犬齿","有爪","眼盯前方","有蹄",
	"反刍","黄褐色","有斑点","有黑色条纹","长脖",
	"长腿","不会飞","会游泳","黑白二色","善飞",
	"哺乳类","鸟类","食肉类","蹄类","金钱豹",
	"虎","长颈鹿","斑马","鸵鸟","企鹅","信天翁"
};


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CanimalsDlg 对话框



CanimalsDlg::CanimalsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_ANIMALS_DIALOG, pParent)
	, m_Output(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CanimalsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Enable, m_Enable);
	DDX_Control(pDX, IDC_Exit, m_Exit);
	//  DDX_Control(pDX, IDC_Toast, m_toast);
	//  DDX_Control(pDX, IDC_Output, m_output);
	//  DDX_Control(pDX, IDC_Output, m_Output);
	DDX_Text(pDX, IDC_Output, m_Output);
	//  DDX_Text(pDX, IDC_Input, m_Input);
	DDX_Text(pDX, IDC_Input_num, m_Input_num);
	//  DDX_Control(pDX, IDC_Clear, m_Clear);
	DDX_Control(pDX, IDC_Clear, m_Clear);
	DDX_Control(pDX, IDC_About, m_About);
	//  DDX_Text(pDX, IDC_Yes_No, m_YorN);
	DDX_Control(pDX, IDC_Try, m_try);
	//  DDX_Control(pDX, IDC_Rule, m_Rule);
	//  DDX_Text(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_Rule, m_Rule);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1);
//	DDX_Control(pDX, IDC_BUTTON1, m_bu);
	DDX_Control(pDX, IDC_BUT, m_buttom);
}

BEGIN_MESSAGE_MAP(CanimalsDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Enable, &CanimalsDlg::OnBnClickedEnable)
	ON_BN_CLICKED(IDC_Exit, &CanimalsDlg::OnBnClickedExit)
//	ON_STN_CLICKED(IDC_LinkHao123, &CanimalsDlg::OnStnClickedLinkhao123)
//	ON_STN_CLICKED(IDC_LinkBaidu, &CanimalsDlg::OnStnClickedLinkbaidu)
//ON_STN_DBLCLK(IDC_Toast, &CanimalsDlg::OnDblclkToast)
//ON_EN_CHANGE(IDC_Output, &CanimalsDlg::OnChangeOutput)
//ON_EN_ERRSPACE(IDC_Output, &CanimalsDlg::OnErrspaceOutput)
ON_EN_CHANGE(IDC_Output, &CanimalsDlg::OnEnChangeOutput)
//ON_EN_CHANGE(IDC_Input, &CanimalsDlg::OnEnChangeInput)
ON_EN_CHANGE(IDC_Input_num, &CanimalsDlg::OnEnChangeInputnum)
//ON_BN_CLICKED(IDC_BUTTON1, &CanimalsDlg::OnBnClickedButton1)
//ON_BN_CLICKED(IDC_Clear, &CanimalsDlg::OnBnClickedClear)
ON_BN_CLICKED(IDC_Clear, &CanimalsDlg::OnBnClickedClear)
ON_BN_CLICKED(IDC_About, &CanimalsDlg::OnBnClickedAbout)
//ON_BN_CLICKED(IDC_CHECK1, &CanimalsDlg::OnBnClickedCheck1)
//ON_EN_ERRSPACE(IDC_Yes_No, &CanimalsDlg::OnErrspaceYesNo)
//ON_EN_HSCROLL(IDC_Yes_No, &CanimalsDlg::OnHscrollYesNo)
ON_BN_CLICKED(IDC_Try, &CanimalsDlg::OnBnClickedTry)
//ON_BN_CLICKED(IDC_Rule, &CanimalsDlg::OnBnClickedRule)
ON_BN_CLICKED(IDC_Rule, &CanimalsDlg::OnBnClickedRule)
ON_BN_CLICKED(IDC_BUT, &CanimalsDlg::OnBnClickedBut)
END_MESSAGE_MAP()


// CanimalsDlg 消息处理程序

BOOL CanimalsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//m_Output.SetWindowTextW(_T("请输入密码！\n"));
	//GetDlgItem(IDC_Output)->EnableWindow(false);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CanimalsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CanimalsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CanimalsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CanimalsDlg::OnBnClickedExit()
{
	// TODO: 在此添加控件通知处理程序代码
	SendMessage(WM_CLOSE, 0, 0);
}



void CanimalsDlg::OnEnChangeOutput()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}


bool CanimalsDlg::backward_reasoning(int num1, int message[])   //反向推理
{
	int new_message[fact_num];
	//UpdateData(true);
	for (ii = 0; ii < rule_num; ii++)   //遍历规则匹配
	{
		prerequisite_num = 0;
		hit_num = 0;
		for (ij = 0; ij < rule_volume; ij++)   //计算规则集前提数
		{
			if (rule_prerequisite[ii][ij] == 0)
			{
				break;
			}
			prerequisite_num++;
		}

		need_rule_number[ii] = prerequisite_num;
		for (ij = 0; ij < prerequisite_num; ij++)   //计算输入信息命中规则集中的前提数
		{
			for (ik = 0; ik < num1; ik++)
			{
				if (rule_prerequisite[ii][ij] == message[ik])
				{
					hit_num++;
				}
			}
		}

		//*******************和正向推理是一样的*****************//
		hit_rule_number[ii] = hit_num;
		hit_rule_rate[ii] = (float)hit_num / prerequisite_num;  //命中率

		for (ij = 0; ij<num1; ij++)
		{
			if (message[ij] == rule_result[hit_rule_number[ii]])
			{
				break;
			}
		}
		
		if (hit_rule_rate[ii] == 1 && ij == num1)
		{
			//new_message = new int[num + 1];
			for (ik = 0; ik<num1; ik++)
			{
				new_message[ik] = message[ik];
			}
			new_message[num1] = rule_result[hit_rule_number[ii]];
			num1++;
			return inference(num1, new_message);
		}
	}
	best_hit_rule_number = -1;
	for (ii = 0; ii<rule_num; ii++)
	{
		if (best_hit_rule_rate<hit_rule_rate[ii] &&
			rule_result[ii] >= object_middle_begin&& best_hit_rule_rate<1)
		{
			best_hit_rule_rate = hit_rule_rate[ii];
			best_hit_rule_number = ii;
			m_Output.Format(m_Output + "通过您的输入无法得出准确结果" + "\r\n");
			fla_g = 1;
			b.Format("%d", best_hit_rule_number + 1);
			c.Format("%f", best_hit_rule_rate);
			//m_Output.Format(m_Output + "best_hit_rule_number=" + b + "\r\n");
			//m_Output.Format(m_Output + "best_hit_rule_rate=" + c + "\r\n");
			m_Output.Format(m_Output + "最佳匹配最终结果=" + fact[rule_result[best_hit_rule_number] - 1] + "\r\n");
			m_Output.Format(m_Output + "命中率=" + c + "\r\n");
			m_Output.Format(m_Output + "推理失败" + "\r\n");
		}
		else if (best_hit_rule_rate == hit_rule_rate[ii] &&
			rule_result[ii] >= object_middle_begin&&fla_g == 1)
		{
			best_hit_rule_rate = 1;
			best_hit_rule_number = ii;
		}
	}	
}

bool  CanimalsDlg::inference(int num, int message[])         //迭代推理机
{
	//UpdateData(true);
	bool flag11 = 0;
	for (ik1 = 0; ik1 < num; ik1++)     //剪枝函数
	{
		if (message[ik1] >= object_range_begin && message[ik1] <= object_range_end)
		{
			m_Output.Format(m_Output + "归并信息：" + fact[message[ik1] - 1] + "\r\n");
			m_Output.Format(m_Output + "推理成功！" + "\r\n");
			flag11 = 1;
		}
	}

	for (ii1 = 0; ii1 < rule_num; ii1++)   //遍历规则匹配
	{
		prerequisite_num1 = 0;
		hit_num1 = 0;
		for (ij1 = 0; ij1 < rule_volume; ij1++)   //计算规则集前提数
		{
			if (rule_prerequisite[ii1][ij1] == 0)
			{
				break;
			}
			prerequisite_num1++;
		}

		for (ij1 = 0; ij1 < prerequisite_num1; ij1++)
		{
			for (ik1 = 0; ik1 < num; ik1++)
			{
				if (rule_prerequisite[ii1][ij1] == message[ik1])
				{
					hit_num1++;
				}
			}
		}

		if (hit_num1 == prerequisite_num1)  //满足某个规则集全部前提
		{
			bool flag;
			for (ik1 = 0; ik1 < num; ik1++)
			{
				if (message[ik1] == rule_result[ii1])
				{
					break;
				}
			}
			if (ik1 == num)
			{
				num_c = num - hit_num1 + 1;
				flag = true;
			}
			else
			{
				num_c = num - hit_num1;
				flag = false;
			}
			//message_c = new int[num_c];
			in1 = 0;
			for (ik1 = 0; ik1 < num; ik1++)
			{
				for (im1 = 0; im1 < hit_num1; im1++)
				{
					if (rule_prerequisite[ii1][im1] == message[ik1])
					{
						break;
					}
				}
				if (im1 < hit_num1)
				{
					continue;
				}
				message_c[in1++] = message[ik1];
			}
			if (flag == true)
			{
				message_c[in1] = rule_result[ii1];
			}
			m_Output.Format(m_Output + "推导信息：" + "\r\n");
			
			for (int iz1 = 0; iz1 < num; iz1++)
			{
				m_Output.Format(m_Output + fact[message[iz1] - 1] + " ");
			}
			m_Output.Format(m_Output + "\r\n");
			return inference(num_c, message_c);
		}
	}
	
	m_Output.Format(m_Output +"\r\n"+ "归并信息：" + " ");
	for (int iz1 = 0; iz1 < num; iz1++)
	{
		m_Output.Format(m_Output + fact[message[iz1] - 1] + " ");
	}
	m_Output.Format(m_Output + "\r\n");
	//不管规则是对还是错，都可以运行到这一步
	/*if (flag11)
	{
		backward_reasoning(num, message);
		flag11 = 0;
	}*/
	if (!(message[ik1] >= object_range_begin && message[ik1] <= object_range_end))
	{
		backward_reasoning(num, message);
	}
	
	UpdateData(false);
	return false;
}



void CanimalsDlg::OnBnClickedEnable()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);          // 获取数据
	
	m_Output.Format(m_Output + "刚刚输入的初始规则信息为：" + "\r\n");
	for (ij = 0; ij < num; ij++)
	{
		m_Output.Format(m_Output + fact[message[ij] - 1] + " ");
	}
	m_Output.Format(m_Output + "\r\n");


	UpdateData(false);//停止处理数据
}


void CanimalsDlg::OnEnChangeInputnum()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}



void CanimalsDlg::OnBnClickedClear()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	m_Output.Empty();
	for (ij = 0; ij < num; ij++)
	{
		message[ij] = 0;
		message_c[ij] = 0;
	}	
	num = 0;	
	hit_num1 = 0;          //输入前提也规则前提重合数
    prerequisite_num1 = 0;     //规则前提数
	num_c = 0;                //迭代前提数量
	iii = 0;

	prerequisite_num = 0;
	hit_num = 0;
	for (ij = 0; ij < rule_num; ij++)
	{
		need_rule_number[ij]= 0;
		hit_rule_number[ij]= 0;
	    hit_rule_rate[ij] = 0;
	}
	
	best_hit_rule_rate = 0;
	best_hit_rule_number = 0;
	fla_g = 0;
	UpdateData(0);
}


void CanimalsDlg::OnBnClickedAbout()
{
	// TODO: 在此添加控件通知处理程序代码	
	UpdateData(1);
	bool tt;
	tt = inference(num, message);
	if (!tt)
	{
		//m_Output.Format(m_Output + "通过您的输入无法得出准确结果" + " ");
	}
	for (ij = 0; ij < num; ij++)
	{
		message[ij] = 0;
		message_c[ij] = 0;
	}
	num = 0;
	UpdateData(0);
}


void CanimalsDlg::OnBnClickedTry()
{
	UpdateData(1);	
	
	message[num] = atoi(m_Input_num);
	num++;
	m_Input_num.Empty();
	UpdateData(0);
	// TODO: 在此添加控件通知处理程序代码
}



void CanimalsDlg::OnBnClickedRule()
{
	// TODO: 在此添加控件通知处理程序代码
		UpdateData(1);
		//m_Edit1.Format(m_Edit1 + "《知识库》" + "\r\n");
		m_Edit1 += "规则库如下：\r\n";
		for (ii = 0; ii < fact_num; ii++)
		{
			m_Edit1.Format(m_Edit1 + "第%d个规则：", ii + 1);
			m_Edit1.Format(m_Edit1 + fact[ii] + "\r\n");
		}
		UpdateData(0);
}


void CanimalsDlg::OnBnClickedBut()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("自实1501班 杨毅远  U201514417\r\r\n\r\n指导老师：王祖喜"));
}


