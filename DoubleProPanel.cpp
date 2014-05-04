/**
 * @file DoubleProPanel.cpp
 * @brief Double Probability Setting Panel.
 *
 */

#include "DoubleProPanel.h"

static wxString label[5] = {
		L"X0(不中籤數設定)",
		L"X2",
		L"X4",
		L"X6",
		L"總和",
};


DoubleProPanel::DoubleProPanel(wxPanel* parent) : wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxBORDER_NONE){
	this->m_parent = parent;
	this->m_sb = new wxStaticBox(this,wxID_ANY,L"比倍籤筒機率設定",wxDefaultPosition,wxDefaultSize);
	this->m_sz = new wxStaticBoxSizer(this->m_sb,wxVERTICAL);

	this->m_gridSz = new wxGridSizer(5,2,5,5);
	wxTextValidator validator(wxFILTER_NUMERIC);

	//Create Double Up Probability Setting Text
	for(unsigned int i=0; i<sizeof(this->m_doubleOddsText)/sizeof(this->m_doubleOddsText[0]); i++){
		this->m_doubleOddsText[i] = new wxStaticText(this,wxID_ANY,label[i],wxDefaultPosition,wxDefaultSize);
	}

	//Create Double Up Probability Setting Text Control
	wxString defaultValue[4];// = { L"5000",L"4500",L"300",L"200"};
	defaultValue[0] << DEF_DPRO_STEP_1;
	defaultValue[1] << DEF_DPRO_STEP_2;
	defaultValue[2] << DEF_DPRO_STEP_3;
    defaultValue[3] << DEF_DPRO_STEP_4;

	for(unsigned int i=0,TC_ID = CID_ITEM_VALUE_X0; i<sizeof(this->m_doubleOddsTc)/sizeof(this->m_doubleOddsTc[0]); i++){
		if(i!=4)
			this->m_doubleOddsTc[i] = new wxTextCtrl(this,TC_ID,defaultValue[i],wxDefaultPosition,wxSize(50,22),0,validator);
		else
			this->m_doubleOddsTc[i] = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(50,22),0);
		TC_ID++;
	}
    // Set Text Control Max Length to 4 digit( X0 X2 X4 X6 )
	for(unsigned int i=0; i<sizeof(this->m_doubleOddsTc)/sizeof(this->m_doubleOddsTc[0])-1; i++){
		this->m_doubleOddsTc[i]->SetMaxLength(4);
	}

	this->m_doubleOddsTc[4]->SetLabelText(L"10000");
	this->m_doubleOddsTc[4]->SetForegroundColour(wxColour(0,0,255));
	this->m_doubleOddsTc[4]->SetEditable(false);

	//Add All Text & Text Control to GridSizer
	for(unsigned int i=0; i<sizeof(this->m_doubleOddsTc)/sizeof(this->m_doubleOddsTc[0]); i++){
		this->m_gridSz->Add(this->m_doubleOddsText[i],0);
		this->m_gridSz->Add(this->m_doubleOddsTc[i],0);
	}

	this->m_sz->Add(this->m_gridSz,0);
	this->SetSizer(this->m_sz,true);

	for(unsigned int i=0,TC_ID = CID_ITEM_VALUE_X0; i<sizeof(this->m_doubleOddsTc)/sizeof(this->m_doubleOddsTc[0])-1; i++){
		Connect(TC_ID,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(DoubleProPanel::AfterEdit));
		TC_ID++;
	}

}
/**
 *
 */
void DoubleProPanel::AfterEdit(wxCommandEvent& event){
	unsigned int tmp = 0;
	for(unsigned int i=0; i<sizeof(this->m_doubleOddsTc)/sizeof(this->m_doubleOddsTc[0])-1; i++){
		tmp += wxAtoi(this->m_doubleOddsTc[i]->GetValue());
	}

	wxString result(L"");
	result << tmp;
	this->m_doubleOddsTc[4]->SetValue(result);

	if(tmp > 10000){
      this->m_doubleOddsTc[4]->SetForegroundColour(wxColour(255,0,0));
	  wxMessageDialog *dial = new wxMessageDialog(NULL,L"總和值超過10000",L"錯誤", wxOK | wxICON_ERROR);
	  dial->ShowModal();

	}else if(tmp < 10000){
	  this->m_doubleOddsTc[4]->SetForegroundColour(wxColour(255,0,0));
	  //wxMessageDialog *dial = new wxMessageDialog(NULL,L"總和值小於10000",L"錯誤", wxOK | wxICON_ERROR);
	  //dial->ShowModal();
	}else{
	  this->m_doubleOddsTc[4]->SetForegroundColour(wxColour(0,0,255));
	}

}

