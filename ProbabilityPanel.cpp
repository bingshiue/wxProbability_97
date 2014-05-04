/**
 * ProbabilityPanel.cpp
 *
 */

#include "ProbabilityPanel.h"

ProbabilityPanel::ProbabilityPanel(wxPanel* parent,wxString title) : wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxBORDER_NONE)
{
	//
	this->m_parent = parent;

	this->m_sb = new wxStaticBox(this,wxID_ANY,title,wxDefaultPosition,wxDefaultSize);
	this->m_sz = new wxStaticBoxSizer(this->m_sb,wxVERTICAL);
	//this->m_gridSz = new wxGridSizer(4,6,5,5);
	this->m_gridSz = new wxGridSizer(3,6,5,5);

	this->m_hbox = new wxBoxSizer(wxHORIZONTAL);

	//m_bmap  = new wxBitmap(64,64);
	//m_sbmap = new wxStaticBitmap(this,wxID_ANY,*this->m_bmap);
	wxTextValidator validator(wxFILTER_NUMERIC);
	this->m_slotItem_1_label = new wxStaticText(this,wxID_ANY,L"荔枝",wxDefaultPosition,wxDefaultSize);
	    this->m_slotItem_1_tc = new wxTextCtrl(this,CID_ITEM_VALUE_1,L"",wxDefaultPosition,wxSize(50,22),0,validator);
	this->m_slotItem_2_label = new wxStaticText(this,wxID_ANY,L"橘子",wxDefaultPosition,wxDefaultSize);
		this->m_slotItem_2_tc = new wxTextCtrl(this,CID_ITEM_VALUE_2,L"",wxDefaultPosition,wxSize(50,22),0,validator);
	this->m_slotItem_3_label = new wxStaticText(this,wxID_ANY,L"芒果",wxDefaultPosition,wxDefaultSize);
		this->m_slotItem_3_tc = new wxTextCtrl(this,CID_ITEM_VALUE_3,L"",wxDefaultPosition,wxSize(50,22),0,validator);

	this->m_slotItem_4_label = new wxStaticText(this,wxID_ANY,L"金鐘",wxDefaultPosition,wxDefaultSize);
		this->m_slotItem_4_tc = new wxTextCtrl(this,CID_ITEM_VALUE_4,L"",wxDefaultPosition,wxSize(50,22),0,validator);
	this->m_slotItem_5_label = new wxStaticText(this,wxID_ANY,L"西瓜",wxDefaultPosition,wxDefaultSize);
		this->m_slotItem_5_tc = new wxTextCtrl(this,CID_ITEM_VALUE_5,L"",wxDefaultPosition,wxSize(50,22),0,validator);
	this->m_slotItem_6_label = new wxStaticText(this,wxID_ANY,L"黃 BAR",wxDefaultPosition,wxDefaultSize);
		this->m_slotItem_6_tc = new wxTextCtrl(this,CID_ITEM_VALUE_6,L"",wxDefaultPosition,wxSize(50,22),0,validator);

	this->m_slotItem_7_label = new wxStaticText(this,wxID_ANY,L"紅 BAR",wxDefaultPosition,wxDefaultSize);
		this->m_slotItem_7_tc = new wxTextCtrl(this,CID_ITEM_VALUE_7,L"",wxDefaultPosition,wxSize(50,22),0,validator);
	this->m_slotItem_8_label = new wxStaticText(this,wxID_ANY,L"藍 BAR",wxDefaultPosition,wxDefaultSize);
		this->m_slotItem_8_tc = new wxTextCtrl(this,CID_ITEM_VALUE_8,L"",wxDefaultPosition,wxSize(50,22),0,validator);
	this->m_slotItem_9_label = new wxStaticText(this,wxID_ANY,L"鬼牌",wxDefaultPosition,wxDefaultSize);
		this->m_slotItem_9_tc = new wxTextCtrl(this,CID_ITEM_VALUE_9,L"",wxDefaultPosition,wxSize(50,22),0,validator);

	//this->m_slotItem_10_label = new wxStaticText(this,wxID_ANY,L"Item 10",wxDefaultPosition,wxDefaultSize);
		//this->m_slotItem_10_tc = new wxTextCtrl(this,CID_ITEM_VALUE_10,L"",wxDefaultPosition,wxSize(50,22));
	this->m_totalValue_label = new wxStaticText(this,wxID_ANY,L"總合",wxDefaultPosition,wxDefaultSize);
		this->m_totalValue_tc = new wxTextCtrl(this,wxID_ANY,L"10000",wxDefaultPosition,wxSize(50,22));
		this->m_totalValue_tc->SetForegroundColour(wxColour(0,0,255));
		this->m_totalValue_tc->SetEditable(false);

	this->m_gridSz->Add(this->m_slotItem_1_label,0);
	this->m_gridSz->Add(this->m_slotItem_1_tc,0);
	this->m_gridSz->Add(this->m_slotItem_2_label,0);
	this->m_gridSz->Add(this->m_slotItem_2_tc,0);
	this->m_gridSz->Add(this->m_slotItem_3_label,0);
	this->m_gridSz->Add(this->m_slotItem_3_tc,0);

	this->m_gridSz->Add(this->m_slotItem_4_label,0);
	this->m_gridSz->Add(this->m_slotItem_4_tc,0);
	this->m_gridSz->Add(this->m_slotItem_5_label,0);
	this->m_gridSz->Add(this->m_slotItem_5_tc,0);
	this->m_gridSz->Add(this->m_slotItem_6_label,0);
	this->m_gridSz->Add(this->m_slotItem_6_tc,0);

	this->m_gridSz->Add(this->m_slotItem_7_label,0);
	this->m_gridSz->Add(this->m_slotItem_7_tc,0);
	this->m_gridSz->Add(this->m_slotItem_8_label,0);
	this->m_gridSz->Add(this->m_slotItem_8_tc,0);
	this->m_gridSz->Add(this->m_slotItem_9_label,0);
	this->m_gridSz->Add(this->m_slotItem_9_tc,0);

	//this->m_gridSz->Add(this->m_slotItem_10_label,0);
	//this->m_gridSz->Add(this->m_slotItem_10_tc,0);

	//this->m_gridSz->Add(new wxStaticText(this,wxID_ANY,L""));
	//this->m_gridSz->Add(new wxStaticText(this,wxID_ANY,L""));

	//this->m_gridSz->Add(this->m_totalValue_label,0);
	//this->m_gridSz->Add(this->m_totalValue_tc,0);

	this->m_hbox->Add(this->m_gridSz,0);
	//this->m_hbox->Add(this->m_sbmap,0, wxALL, 20);
	this->m_hbox->Add(this->m_totalValue_label,0);
	this->m_hbox->Add(this->m_totalValue_tc,0);
	this->m_sz->Add(this->m_hbox,0);

	this->SetSizer(this->m_sz,true);

	this->m_slotItem_1_tc->SetMaxLength(4);
	this->m_slotItem_2_tc->SetMaxLength(4);
	this->m_slotItem_3_tc->SetMaxLength(4);
	this->m_slotItem_4_tc->SetMaxLength(4);
	this->m_slotItem_5_tc->SetMaxLength(4);
	this->m_slotItem_6_tc->SetMaxLength(4);
	this->m_slotItem_7_tc->SetMaxLength(4);
	this->m_slotItem_8_tc->SetMaxLength(4);
	this->m_slotItem_9_tc->SetMaxLength(4);
	//this->m_slotItem_10_tc->SetMaxLength(4);

	Connect(CID_ITEM_VALUE_1,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(ProbabilityPanel::AfterEdit));
	Connect(CID_ITEM_VALUE_2,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(ProbabilityPanel::AfterEdit));
	Connect(CID_ITEM_VALUE_3,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(ProbabilityPanel::AfterEdit));
	Connect(CID_ITEM_VALUE_4,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(ProbabilityPanel::AfterEdit));
	Connect(CID_ITEM_VALUE_5,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(ProbabilityPanel::AfterEdit));
	Connect(CID_ITEM_VALUE_6,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(ProbabilityPanel::AfterEdit));
	Connect(CID_ITEM_VALUE_7,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(ProbabilityPanel::AfterEdit));
	Connect(CID_ITEM_VALUE_8,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(ProbabilityPanel::AfterEdit));
	Connect(CID_ITEM_VALUE_9,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(ProbabilityPanel::AfterEdit));
	Connect(CID_ITEM_VALUE_10,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(ProbabilityPanel::AfterEdit));

}

void ProbabilityPanel::AfterEdit(wxCommandEvent& event){
	unsigned int tmp;
	tmp = wxAtoi(this->m_slotItem_1_tc->GetValue()) +
		  wxAtoi(this->m_slotItem_2_tc->GetValue()) +
		  wxAtoi(this->m_slotItem_3_tc->GetValue()) +
		  wxAtoi(this->m_slotItem_4_tc->GetValue()) +
		  wxAtoi(this->m_slotItem_5_tc->GetValue()) +
		  wxAtoi(this->m_slotItem_6_tc->GetValue()) +
		  wxAtoi(this->m_slotItem_7_tc->GetValue()) +
		  wxAtoi(this->m_slotItem_8_tc->GetValue()) +
		  wxAtoi(this->m_slotItem_9_tc->GetValue());// +
		  //wxAtoi(this->m_slotItem_10_tc->GetValue());

	wxString result(L"");
	result << tmp;
	this->m_totalValue_tc->SetValue(result);

	if(tmp > 10000){
      this->m_totalValue_tc->SetForegroundColour(wxColour(255,0,0));
	  wxMessageDialog *dial = new wxMessageDialog(NULL,L"總和值超過10000",L"錯誤", wxOK | wxICON_ERROR);
	  dial->ShowModal();

	}else if(tmp < 10000){
	  this->m_totalValue_tc->SetForegroundColour(wxColour(255,0,0));
	  //wxMessageDialog *dial = new wxMessageDialog(NULL,L"總和值小於10000",L"錯誤", wxOK | wxICON_ERROR);
	  //dial->ShowModal();
	}else{
	  this->m_totalValue_tc->SetForegroundColour(wxColour(0,0,255));
	}
}


