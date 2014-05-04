/**
 * @file DRunTimeSettingPanel.cpp
 *
 */

#include "DRunTimeSettingPanel.h"

DRunTimeSettingPanel::DRunTimeSettingPanel(wxPanel* parent) : wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxBORDER_NONE){
	this->m_parent = parent;
	this->m_sb = new wxStaticBox(this,wxID_ANY,L"比倍執行設定值",wxDefaultPosition,wxDefaultSize);
	this->m_sz = new wxStaticBoxSizer(this->m_sb,wxVERTICAL);

	this->m_gridSz = new wxGridSizer(2,1,5,5);

	this->m_runDoubleGameChkBox = new wxCheckBox(this,CID_CHECKBOX_RUNDOUBLEGAME,L"執行比倍遊戲",wxDefaultPosition,wxDefaultSize);
	this->m_runDoubleGameChkBox->SetValue(true);

	this->m_runToDeadChkBox     = new wxCheckBox(this,CID_CHECKBOX_RUNTODEAD,L"比到脫褲",wxDefaultPosition,wxDefaultSize);
	this->m_runToDeadChkBox->SetValue(false);
	//this->m_runToDeadChkBox->Disable();

	this->m_gridSz->Add(this->m_runDoubleGameChkBox ,0);
	this->m_gridSz->Add(this->m_runToDeadChkBox ,0);

	this->m_sz->Add(this->m_gridSz,0);
    this->SetSizer(this->m_sz,true);
}


