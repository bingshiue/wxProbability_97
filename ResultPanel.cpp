/**
 * ResultPanel.cpp
 *
 */

#include "ResultPanel.h"

ResultPanel::ResultPanel(wxPanel* parent) : wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxBORDER_NONE)
{
	this->m_parent = parent;

	this->m_sb = new wxStaticBox(this,wxID_ANY,L"執行結果",wxDefaultPosition,wxDefaultSize);
	this->m_sz = new wxStaticBoxSizer(this->m_sb,wxVERTICAL);

	this->m_gridSz = new wxGridSizer(6,6,5,0);

#if 0
	this->m_hbox_1 = new wxBoxSizer(wxHORIZONTAL);
	this->m_hbox_2 = new wxBoxSizer(wxHORIZONTAL);
	this->m_hbox_3 = new wxBoxSizer(wxHORIZONTAL);
	this->m_hbox_4 = new wxBoxSizer(wxHORIZONTAL);
	this->m_hbox_5 = new wxBoxSizer(wxHORIZONTAL);
	this->m_hbox_6 = new wxBoxSizer(wxHORIZONTAL);
#endif

	this->m_totalKeyIn = new wxStaticText(this,wxID_ANY,L"總開枚數");
	this->m_totalKeyOut = new wxStaticText(this,wxID_ANY,L"總洗枚數");
	this->m_keyInOutPercent = new wxStaticText(this,wxID_ANY,L"營業機率");

	this->m_totalPlayScore = new wxStaticText(this,wxID_ANY,L"總玩分數");
	this->m_totalWinScore = new wxStaticText(this,wxID_ANY,L"總贏分數");
	this->m_PlayWinScorePercent = new wxStaticText(this,wxID_ANY,L"機械機率");

	this->m_totalPlayTimes = new wxStaticText(this,wxID_ANY,L"總玩次數");
	this->m_totalWinTimes = new wxStaticText(this,wxID_ANY,L"總贏次數");
	this->m_PlayWinTimesPercent = new wxStaticText(this,wxID_ANY,L"中獎機率");

	this->m_doubleTotalPlayScore = new wxStaticText(this,wxID_ANY,L"比倍總玩分數");
	this->m_doubleTotalWinScore = new wxStaticText(this,wxID_ANY,L"比倍總贏分數");
	this->m_doublePlayWinScorePercent = new wxStaticText(this,wxID_ANY,L"比倍機械機率");

	this->m_doubleTotalPlayTimes = new wxStaticText(this,wxID_ANY,L"比倍總玩次數");
	this->m_doubleTotalWinTimes = new wxStaticText(this,wxID_ANY,L"比倍總贏次數");
	this->m_doublePlayWinTimesPercent = new wxStaticText(this,wxID_ANY,L"比倍中獎機率");

	this->m_mainGameOverMaxWinTimes = new wxStaticText(this,wxID_ANY,L"主遊戲爆機次數");
	this->m_doubleGameOverMaxWinTimes = new wxStaticText(this,wxID_ANY,L"比倍遊戲爆機次數");
	this->m_doubleGameMaxConsecutivePassTimes = new wxStaticText(this,wxID_ANY,L"比倍連續過關次數");

	this->m_totalKeyIn_tc = new wxTextCtrl(this,wxID_ANY,L"");
	this->m_totalKeyOut_tc = new wxTextCtrl(this,wxID_ANY,L"");
	this->m_keyInOutPercent_tc = new wxTextCtrl(this,wxID_ANY,L"");

	this->m_totalPlayScore_tc = new wxTextCtrl(this,wxID_ANY,L"");
	this->m_totalWinScore_tc = new wxTextCtrl(this,wxID_ANY,L"");
	this->m_PlayWinScorePercent_tc = new wxTextCtrl(this,wxID_ANY,L"");

	this->m_totalPlayTimes_tc = new wxTextCtrl(this,wxID_ANY,L"");
	this->m_totalWinTimes_tc = new wxTextCtrl(this,wxID_ANY,L"");
	this->m_PlayWinTimesPercent_tc = new wxTextCtrl(this,wxID_ANY,L"");

	this->m_doubleTotalPlayScore_tc = new wxTextCtrl(this,wxID_ANY,L"");
	this->m_doubleTotalWinScore_tc = new wxTextCtrl(this,wxID_ANY,L"");
	this->m_doublePlayWinScorePercent_tc = new wxTextCtrl(this,wxID_ANY,L"");

	this->m_doubleTotalPlayTimes_tc = new wxTextCtrl(this,wxID_ANY,L"");
	this->m_doubleTotalWinTimes_tc = new wxTextCtrl(this,wxID_ANY,L"");
	this->m_doublePlayWinTimesPercent_tc = new wxTextCtrl(this,wxID_ANY,L"");

	this->m_mainGameOverMaxWinTimes_tc = new wxTextCtrl(this,wxID_ANY,L"");
	this->m_doubleGameOverMaxWinTimes_tc = new wxTextCtrl(this,wxID_ANY,L"");
	this->m_doubleGameMaxConsecutivePassTimes_tc = new wxTextCtrl(this,wxID_ANY,L"");

	this->m_totalKeyIn_tc->SetEditable(false);
	this->m_totalKeyOut_tc->SetEditable(false);
	this->m_keyInOutPercent_tc->SetEditable(false);

	this->m_totalPlayScore_tc->SetEditable(false);
	this->m_totalWinScore_tc->SetEditable(false);
	this->m_PlayWinScorePercent_tc->SetEditable(false);

	this->m_totalPlayTimes_tc->SetEditable(false);
	this->m_totalWinTimes_tc->SetEditable(false);
	this->m_PlayWinTimesPercent_tc->SetEditable(false);

	this->m_doubleTotalPlayScore_tc->SetEditable(false);
	this->m_doubleTotalWinScore_tc->SetEditable(false);
	this->m_doublePlayWinScorePercent_tc->SetEditable(false);

	this->m_doubleTotalPlayTimes_tc->SetEditable(false);
	this->m_doubleTotalWinTimes_tc->SetEditable(false);
	this->m_doublePlayWinTimesPercent_tc->SetEditable(false);

	this->m_mainGameOverMaxWinTimes_tc->SetEditable(false);
	this->m_doubleGameOverMaxWinTimes_tc->SetEditable(false);
	this->m_doubleGameMaxConsecutivePassTimes_tc->SetEditable(false);

	this->m_totalKeyIn_tc->SetValue("0");
	this->m_totalKeyOut_tc->SetValue("0");
	this->m_keyInOutPercent_tc->SetValue("0");

	this->m_totalPlayScore_tc->SetValue("0");
	this->m_totalWinScore_tc->SetValue("0");
	this->m_PlayWinScorePercent_tc->SetValue("0");

	this->m_totalPlayTimes_tc->SetValue("0");
	this->m_totalWinTimes_tc->SetValue("0");
	this->m_PlayWinTimesPercent_tc->SetValue("0");

	this->m_doubleTotalPlayScore_tc->SetValue("0");
	this->m_doubleTotalWinScore_tc->SetValue("0");
	this->m_doublePlayWinScorePercent_tc->SetValue("0");

	this->m_doubleTotalPlayTimes_tc->SetValue("0");
	this->m_doubleTotalWinTimes_tc->SetValue("0");
	this->m_doublePlayWinTimesPercent_tc->SetValue("0");

	this->m_mainGameOverMaxWinTimes_tc->SetValue("0");
	this->m_doubleGameOverMaxWinTimes_tc->SetValue("0");
	this->m_doubleGameMaxConsecutivePassTimes_tc->SetValue("0");

	this->m_gridSz->Add(this->m_totalKeyIn,0,wxALL, 5);
	this->m_gridSz->Add(this->m_totalKeyIn_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_totalKeyOut,0,wxALL, 5);
	this->m_gridSz->Add(this->m_totalKeyOut_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_keyInOutPercent,0,wxALL, 5);
	this->m_gridSz->Add(this->m_keyInOutPercent_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_totalPlayScore,0,wxALL, 5);
	this->m_gridSz->Add(this->m_totalPlayScore_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_totalWinScore,0,wxALL, 5);
	this->m_gridSz->Add(this->m_totalWinScore_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_PlayWinScorePercent,0,wxALL, 5);
	this->m_gridSz->Add(this->m_PlayWinScorePercent_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_totalPlayTimes,0,wxALL, 5);
	this->m_gridSz->Add(this->m_totalPlayTimes_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_totalWinTimes,0,wxALL, 5);
	this->m_gridSz->Add(this->m_totalWinTimes_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_PlayWinTimesPercent,0,wxALL, 5);
	this->m_gridSz->Add(this->m_PlayWinTimesPercent_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_doubleTotalPlayScore,0,wxALL, 5);
	this->m_gridSz->Add(this->m_doubleTotalPlayScore_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_doubleTotalWinScore,0,wxALL, 5);
	this->m_gridSz->Add(this->m_doubleTotalWinScore_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_doublePlayWinScorePercent,0,wxALL, 5);
	this->m_gridSz->Add(this->m_doublePlayWinScorePercent_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_doubleTotalPlayTimes,0,wxALL, 5);
	this->m_gridSz->Add(this->m_doubleTotalPlayTimes_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_doubleTotalWinTimes,0,wxALL, 5);
	this->m_gridSz->Add(this->m_doubleTotalWinTimes_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_doublePlayWinTimesPercent,0,wxALL, 5);
	this->m_gridSz->Add(this->m_doublePlayWinTimesPercent_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_mainGameOverMaxWinTimes,0,wxALL, 5);
	this->m_gridSz->Add(this->m_mainGameOverMaxWinTimes_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_doubleGameOverMaxWinTimes,0,wxALL, 5);
	this->m_gridSz->Add(this->m_doubleGameOverMaxWinTimes_tc,0,wxALL, 5);

	this->m_gridSz->Add(this->m_doubleGameMaxConsecutivePassTimes,0,wxALL, 5);
	this->m_gridSz->Add(this->m_doubleGameMaxConsecutivePassTimes_tc,0,wxALL, 5);

	this->m_sz->Add(this->m_gridSz,0);

#if 0
	this->m_hbox_1->Add(this->m_totalKeyIn,0,wxALL, 5);
	this->m_hbox_1->Add(this->m_totalKeyIn_tc,0,wxALL, 5);

	this->m_hbox_1->Add(this->m_totalKeyOut,0,wxALL, 5);
	this->m_hbox_1->Add(this->m_totalKeyOut_tc,0,wxALL, 5);

	this->m_hbox_1->Add(this->m_keyInOutPercent,0,wxALL, 5);
	this->m_hbox_1->Add(this->m_keyInOutPercent_tc,0,wxALL, 5);

	this->m_hbox_2->Add(this->m_totalPlayScore,0,wxALL, 5);
	this->m_hbox_2->Add(this->m_totalPlayScore_tc,0,wxALL, 5);

	this->m_hbox_2->Add(this->m_totalWinScore,0,wxALL, 5);
	this->m_hbox_2->Add(this->m_totalWinScore_tc,0,wxALL, 5);

	this->m_hbox_2->Add(this->m_PlayWinScorePercent,0,wxALL, 5);
	this->m_hbox_2->Add(this->m_PlayWinScorePercent_tc,0,wxALL, 5);

	this->m_hbox_3->Add(this->m_totalPlayTimes,0,wxALL, 5);
	this->m_hbox_3->Add(this->m_totalPlayTimes_tc,0,wxALL, 5);

	this->m_hbox_3->Add(this->m_totalWinTimes,0,wxALL, 5);
	this->m_hbox_3->Add(this->m_totalWinTimes_tc,0,wxALL, 5);

	this->m_hbox_3->Add(this->m_PlayWinTimesPercent,0,wxALL, 5);
	this->m_hbox_3->Add(this->m_PlayWinTimesPercent_tc,0,wxALL, 5);

	this->m_hbox_4->Add(this->m_doubleTotalPlayScore,0,wxALL, 5);
	this->m_hbox_4->Add(this->m_doubleTotalPlayScore_tc,0,wxALL, 5);

	this->m_hbox_4->Add(this->m_doubleTotalWinScore,0,wxALL, 5);
	this->m_hbox_4->Add(this->m_doubleTotalWinScore_tc,0,wxALL, 5);

	this->m_hbox_4->Add(this->m_doublePlayWinScorePercent,0,wxALL, 5);
	this->m_hbox_4->Add(this->m_doublePlayWinScorePercent_tc,0,wxALL, 5);

	this->m_hbox_5->Add(this->m_doubleTotalPlayTimes,0,wxALL, 5);
	this->m_hbox_5->Add(this->m_doubleTotalPlayTimes_tc,0,wxALL, 5);

	this->m_hbox_5->Add(this->m_doubleTotalWinTimes,0,wxALL, 5);
	this->m_hbox_5->Add(this->m_doubleTotalWinTimes_tc,0,wxALL, 5);

	this->m_hbox_5->Add(this->m_doublePlayWinTimesPercent,0,wxALL, 5);
	this->m_hbox_5->Add(this->m_doublePlayWinTimesPercent_tc,0,wxALL, 5);

	this->m_hbox_6->Add(this->m_mainGameOverMaxWinTimes,0,wxALL, 5);
	this->m_hbox_6->Add(this->m_mainGameOverMaxWinTimes_tc,0,wxALL, 5);

	this->m_hbox_6->Add(this->m_doubleGameOverMaxWinTimes,0,wxALL, 5);
	this->m_hbox_6->Add(this->m_doubleGameOverMaxWinTimes_tc,0,wxALL, 5);

	this->m_sz->Add(this->m_hbox_1,0);
	this->m_sz->Add(this->m_hbox_2,0);
	this->m_sz->Add(this->m_hbox_3,0);
	this->m_sz->Add(this->m_hbox_4,0);
	this->m_sz->Add(this->m_hbox_5,0);
	this->m_sz->Add(this->m_hbox_6,0);
#endif

	this->SetSizer(this->m_sz,true);


}

