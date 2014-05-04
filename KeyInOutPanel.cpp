/**
 * KeyInOutPanel.cpp
 *
 */

#include "KeyInOutPanel.h"

KeyInOutPanel::KeyInOutPanel(wxPanel* parent) : wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxBORDER_NONE)
{
	this->m_parent = parent;

	this->m_sb = new wxStaticBox(this,wxID_ANY,L"自動洗分枚數設定值",wxDefaultPosition,wxDefaultSize);
	this->m_sz = new wxStaticBoxSizer(this->m_sb,wxVERTICAL);
	this->m_fgsz = new wxFlexGridSizer(10,5,5,5);

	wxTextValidator validator(wxFILTER_NUMERIC);
	this->m_keyInOut_Label_1 = new wxStaticText(this,wxID_ANY,L"自動洗分枚數設定值 1",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_1 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_1 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_1 = new wxStaticText(this,wxID_ANY,L"千分之",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_1 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_1->SetMaxLength(4);

	this->m_keyInOut_Label_2 = new wxStaticText(this,wxID_ANY,L"自動洗分枚數設定值 2",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_2 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_2 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_2 = new wxStaticText(this,wxID_ANY,L"千分之",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_2 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_2->SetMaxLength(4);

	this->m_keyInOut_Label_3 = new wxStaticText(this,wxID_ANY,L"自動洗分枚數設定值 3",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_3 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_3 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_3 = new wxStaticText(this,wxID_ANY,L"千分之",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_3 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_3->SetMaxLength(4);

	this->m_keyInOut_Label_4 = new wxStaticText(this,wxID_ANY,L"自動洗分枚數設定值 4",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_4 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_4 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_4 = new wxStaticText(this,wxID_ANY,L"千分之",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_4 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_4->SetMaxLength(4);

	this->m_keyInOut_Label_5 = new wxStaticText(this,wxID_ANY,L"自動洗分枚數設定值 5",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_5 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_5 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_5 = new wxStaticText(this,wxID_ANY,L"千分之",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_5 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_5->SetMaxLength(4);

	this->m_keyInOut_Label_6 = new wxStaticText(this,wxID_ANY,L"自動洗分枚數設定值 6",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_6 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_6 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_6 = new wxStaticText(this,wxID_ANY,L"千分之",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_6 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_6->SetMaxLength(4);

	this->m_keyInOut_Label_7 = new wxStaticText(this,wxID_ANY,L"自動洗分枚數設定值 7",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_7 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_7 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_7 = new wxStaticText(this,wxID_ANY,L"千分之",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_7 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_7->SetMaxLength(4);

	this->m_keyInOut_Label_8 = new wxStaticText(this,wxID_ANY,L"自動洗分枚數設定值 8",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_8 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_8 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_8 = new wxStaticText(this,wxID_ANY,L"千分之",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_8 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_8->SetMaxLength(4);

	this->m_keyInOut_Label_9 = new wxStaticText(this,wxID_ANY,L"自動洗分枚數設定值9",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_9 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_9 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_9 = new wxStaticText(this,wxID_ANY,L"千分之",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_9 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_9->SetMaxLength(4);

	this->m_keyInOut_Label_10 = new wxStaticText(this,wxID_ANY,L"自動洗分枚數設定值 10",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_10 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_10 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_10 = new wxStaticText(this,wxID_ANY,L"千分之",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_10 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_10->SetMaxLength(4);

	this->m_fgsz->Add(this->m_keyInOut_Label_1,0);
	this->m_fgsz->Add(this->m_keyIn_tc_1,0);
	this->m_fgsz->Add(this->m_keyOut_tc_1,0);
	this->m_fgsz->Add(this->m_percent_Label_1,1,0);
	this->m_fgsz->Add(this->m_percent_tc_1,1,0);

	this->m_fgsz->Add(this->m_keyInOut_Label_2,0);
	this->m_fgsz->Add(this->m_keyIn_tc_2,0);
	this->m_fgsz->Add(this->m_keyOut_tc_2,0);
	this->m_fgsz->Add(this->m_percent_Label_2,1,0);
	this->m_fgsz->Add(this->m_percent_tc_2,1,0);

	this->m_fgsz->Add(this->m_keyInOut_Label_3,0);
	this->m_fgsz->Add(this->m_keyIn_tc_3,0);
	this->m_fgsz->Add(this->m_keyOut_tc_3,0);
	this->m_fgsz->Add(this->m_percent_Label_3,1,0);
	this->m_fgsz->Add(this->m_percent_tc_3,1,0);

	this->m_fgsz->Add(this->m_keyInOut_Label_4,0);
	this->m_fgsz->Add(this->m_keyIn_tc_4,0);
	this->m_fgsz->Add(this->m_keyOut_tc_4,0);
	this->m_fgsz->Add(this->m_percent_Label_4,1,0);
	this->m_fgsz->Add(this->m_percent_tc_4,1,0);

	this->m_fgsz->Add(this->m_keyInOut_Label_5,0);
	this->m_fgsz->Add(this->m_keyIn_tc_5,0);
	this->m_fgsz->Add(this->m_keyOut_tc_5,0);
	this->m_fgsz->Add(this->m_percent_Label_5,1,0);
	this->m_fgsz->Add(this->m_percent_tc_5,1,0);

	this->m_fgsz->Add(this->m_keyInOut_Label_6,0);
	this->m_fgsz->Add(this->m_keyIn_tc_6,0);
	this->m_fgsz->Add(this->m_keyOut_tc_6,0);
	this->m_fgsz->Add(this->m_percent_Label_6,1,0);
	this->m_fgsz->Add(this->m_percent_tc_6,1,0);

	this->m_fgsz->Add(this->m_keyInOut_Label_7,0);
	this->m_fgsz->Add(this->m_keyIn_tc_7,0);
	this->m_fgsz->Add(this->m_keyOut_tc_7,0);
	this->m_fgsz->Add(this->m_percent_Label_7,1,0);
	this->m_fgsz->Add(this->m_percent_tc_7,1,0);

	this->m_fgsz->Add(this->m_keyInOut_Label_8,0);
	this->m_fgsz->Add(this->m_keyIn_tc_8,0);
	this->m_fgsz->Add(this->m_keyOut_tc_8,0);
	this->m_fgsz->Add(this->m_percent_Label_8,1,0);
	this->m_fgsz->Add(this->m_percent_tc_8,1,0);

	this->m_fgsz->Add(this->m_keyInOut_Label_9,0);
	this->m_fgsz->Add(this->m_keyIn_tc_9,0);
	this->m_fgsz->Add(this->m_keyOut_tc_9,0);
	this->m_fgsz->Add(this->m_percent_Label_9,1,0);
	this->m_fgsz->Add(this->m_percent_tc_9,1,0);

	this->m_fgsz->Add(this->m_keyInOut_Label_10,0);
	this->m_fgsz->Add(this->m_keyIn_tc_10,0);
	this->m_fgsz->Add(this->m_keyOut_tc_10,0);
	this->m_fgsz->Add(this->m_percent_Label_10,1,0);
	this->m_fgsz->Add(this->m_percent_tc_10,1,0);

	this->m_sz->Add(this->m_fgsz,0);

	this->SetSizer(this->m_sz,true);

}

