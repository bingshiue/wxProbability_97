/**
 * @file DoubleContinuePanel.cpp
 *
 */

#include "DoubleContinuePanel.h"

static wxString label[15] = {
		L"主遊戲中獎進入比倍機率     百分之",
		L"比倍第 2 次續比機率             百分之",
		L"比倍第 3 次續比機率             百分之",
		L"比倍第 4 次續比機率             百分之",
		L"比倍第 5 次續比機率             百分之",
		L"比倍第 6 次續比機率             百分之",
		L"比倍第 7 次續比機率             百分之",
		L"比倍第 8 次續比機率             百分之",
		L"比倍第 9 次續比機率             百分之",
		L"比倍第 10 次續比機率           百分之",
		L"比倍第 11 次續比機率           百分之",
		L"比倍第 12 次續比機率           百分之",
		L"比倍第 13 次續比機率           百分之",
		L"比倍第 14 次續比機率           百分之",
		L"比倍第 15 次續比機率           百分之",
};

DoubleContinuePanel::DoubleContinuePanel(wxPanel* parent) : wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxBORDER_NONE){
	this->m_parent = parent;
	this->m_sb = new wxStaticBox(this,wxID_ANY,L"比倍續比機率設定",wxDefaultPosition,wxDefaultSize);
	this->m_sz = new wxStaticBoxSizer(this->m_sb,wxVERTICAL);

	this->m_gridSz = new wxGridSizer(15,2,5,5);
	wxTextValidator validator(wxFILTER_NUMERIC);

	for(unsigned int i=0; i<sizeof(this->m_doubleContinueText)/sizeof(this->m_doubleContinueText[0]); i++){
		this->m_doubleContinueText[i] = new wxStaticText(this,wxID_ANY,label[i],wxDefaultPosition,wxDefaultSize);
	}


	for(unsigned int i=0,TC_ID = CID_CONTINUE_TC_1; i<sizeof(this->m_doubleContinueTc)/sizeof(this->m_doubleContinueTc[0]); i++){
			this->m_doubleContinueTc[i] = new wxTextCtrl(this,TC_ID,L"50",wxDefaultPosition,wxSize(50,22),0,validator);
			this->m_doubleContinueTc[i]->SetMaxLength(3);
			TC_ID++;
	}

	//Add All Text & Text Control to GridSizer
	for(unsigned int i=0; i<sizeof(this->m_doubleContinueTc)/sizeof(this->m_doubleContinueTc[0]); i++){
		this->m_gridSz->Add(this->m_doubleContinueText[i],0);
		this->m_gridSz->Add(this->m_doubleContinueTc[i],0);
	}

	this->m_sz->Add(this->m_gridSz,0);
	this->SetSizer(this->m_sz,true);

}
