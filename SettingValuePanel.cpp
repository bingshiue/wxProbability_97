/**
 * SettingValuePanel.cpp
 *
 */

#include "SettingValuePanel.h"

SettingValuePanel::SettingValuePanel(wxPanel* parent) : wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxBORDER_NONE)
{
	this->m_parent = parent;

	this->m_sb = new wxStaticBox(this,wxID_ANY,L"設定值");
	this->m_sbz = new wxStaticBoxSizer(this->m_sb,wxVERTICAL);
	this->m_gridSz = new wxGridSizer(6,2,5,0);
	//this->m_hsz1 = new wxBoxSizer(wxHORIZONTAL);
	//this->m_hsz2 = new wxBoxSizer(wxHORIZONTAL);

	wxTextValidator validator(wxFILTER_NUMERIC);
	this->m_maxKeyIn = new wxStaticText(this,wxID_ANY,L"開分枚數上限",wxDefaultPosition,wxDefaultSize);
	this->m_maxKeyIn_tc = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxDefaultSize,0,validator);

	//
	this->m_coinSet = new wxStaticText(this,wxID_ANY,L"遊戲幣值設定",wxDefaultPosition,wxDefaultSize);

	wxString coinSetStr[sizeof(coin_value_tab)/sizeof(coin_value_tab[0])];
	for(unsigned int idx=0; idx<sizeof(coin_value_tab)/sizeof(coin_value_tab[0]); idx++){
		coinSetStr[idx] << coin_value_tab[idx];
	}
	this->m_coinSetCB = new wxComboBox(this,CID_COMBOBOX_COINSET,"",wxDefaultPosition,wxDefaultSize,sizeof(coin_value_tab)/sizeof(coin_value_tab[0])
			,coinSetStr,wxCB_READONLY);

	this->m_coinSetCB->SetSelection(2);

	//
	this->m_maxBet = new wxStaticText(this,wxID_ANY,L"最大押分設定",wxDefaultPosition,wxDefaultSize);

	wxString maxBetStr[sizeof(maxbet_tab)/sizeof(maxbet_tab[0])];
	for(unsigned int idx=0; idx<sizeof(maxbet_tab)/sizeof(maxbet_tab[0]); idx++){
		maxBetStr[idx] << maxbet_tab[idx];
	}
	this->m_maxBetCB = new wxComboBox(this,CID_COMBOBOX_MAXBET,"",wxDefaultPosition,wxDefaultSize,sizeof(maxbet_tab)/sizeof(maxbet_tab[0])
			,maxBetStr,wxCB_READONLY);

	this->m_maxBetCB->SetSelection(7);

	this->m_mainGameMaxWin = new wxStaticText(this,wxID_ANY,L"主遊戲爆機枚數設定",wxDefaultPosition,wxDefaultSize);

	wxString mainGameMaxWinStr[sizeof(credituplimit_tab)/sizeof(credituplimit_tab[0])];
	for(unsigned int idx=0; idx<sizeof(credituplimit_tab)/sizeof(credituplimit_tab[0]); idx++){
		mainGameMaxWinStr[idx] << credituplimit_tab[idx];
	}
	this->m_mainGameMaxWinCB = new wxComboBox(this,CID_COMBOBOX_MAINGAMEMAXWIN,"",wxDefaultPosition,wxDefaultSize,sizeof(credituplimit_tab)/sizeof(credituplimit_tab[0]),
			mainGameMaxWinStr,wxCB_READONLY);
	this->m_mainGameMaxWinCB->SetSelection(4);

	this->m_doubleGameMaxWin = new wxStaticText(this,wxID_ANY,L"比倍遊戲爆機枚數設定",wxDefaultPosition,wxDefaultSize);

	wxString doubleGameMaxWinStr[sizeof(dduplimit_tab)/sizeof(dduplimit_tab[0])];
	for(unsigned int idx=0; idx<sizeof(dduplimit_tab)/sizeof(dduplimit_tab[0]); idx++){
		doubleGameMaxWinStr[idx] << dduplimit_tab[idx];
	}
	this->m_doubleGameMaxWinCB = new wxComboBox(this,CID_COMBOBOX_DOUBLEGAMEMAXWIN,"",wxDefaultPosition,wxDefaultSize,sizeof(dduplimit_tab)/sizeof(dduplimit_tab[0]),
			doubleGameMaxWinStr,wxCB_READONLY);
	this->m_doubleGameMaxWinCB->SetSelection(4);

#if 0
	this->m_runDoubleGameChkBox = new wxCheckBox(this,CID_CHECKBOX_RUNDOUBLEGAME,L"執行比倍遊戲",wxDefaultPosition,wxDefaultSize);
	this->m_runDoubleGameChkBox->SetValue(true);

	this->m_runToDeadChkBox     = new wxCheckBox(this,CID_CHECKBOX_RUNTODEAD,L"比到脫褲",wxDefaultPosition,wxDefaultSize);
	//this->m_runToDeadChkBox->SetValue(true);
	//this->m_runToDeadChkBox->Disable();
#endif

	this->m_gridSz->Add(this->m_maxKeyIn,0);
	this->m_gridSz->Add(this->m_maxKeyIn_tc,0,wxLEFT,5);

	this->m_gridSz->Add(this->m_coinSet,0);
	this->m_gridSz->Add(this->m_coinSetCB,0,wxLEFT,5);

	this->m_gridSz->Add(this->m_maxBet,0);
	this->m_gridSz->Add(this->m_maxBetCB,0,wxLEFT,5);

	this->m_gridSz->Add(this->m_mainGameMaxWin,0);
	this->m_gridSz->Add(this->m_mainGameMaxWinCB,0,wxLEFT,5);

	this->m_gridSz->Add(this->m_doubleGameMaxWin,0);
	this->m_gridSz->Add(this->m_doubleGameMaxWinCB,0,wxLEFT,5);

#if 0
	this->m_gridSz->Add(this->m_runDoubleGameChkBox ,0);
	this->m_gridSz->Add(this->m_runToDeadChkBox ,0);
#endif

	//this->m_hsz1->Add(this->m_maxKeyIn,0);
	//this->m_hsz1->Add(this->m_maxKeyIn_tc,0,wxLEFT, 5);

	//this->m_hsz2->Add(this->m_coinSet,0);
	//this->m_hsz2->Add(this->m_coinSetCB,0);

	//this->m_sbz->Add(this->m_hsz1,0);
	//this->m_sbz->Add(this->m_hsz2,0);
	this->m_sbz->Add(this->m_gridSz,0);

    this->SetSizer(this->m_sbz,true);
}
