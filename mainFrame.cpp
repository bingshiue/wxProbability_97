/**
 * @file mainFrame.cpp
 *
 */

#include "mainFrame.h"
#include "mainProbabilitySubfunc.h"

MainFrame::MainFrame(const wxString& title) : wxFrame((wxFrame*)NULL,wxID_ANY,title,wxDefaultPosition,wxSize(1280,720))
{

	/* Create wxNotebook instance */
	this->m_noteBook = new wxNotebook(this,wxID_ANY);
	/* Create Panel Instance */
	this->m_parent = new wxPanel(this->m_noteBook,wxID_ANY);
	/*  */
	this->m_doubleUpPanel = new wxPanel(this->m_noteBook,wxID_ANY);
	/* Create Box Sizer (Top Level) */
	this->m_topLevelSizer = new wxBoxSizer(wxVERTICAL);
	/* Create Double Up Box Sizer (Top Level) */
	this->m_DoubleTopLevelSizer = new wxBoxSizer(wxVERTICAL);
    /* Add Panels to Notebook */
	this->m_noteBook->AddPage(this->m_parent,L"主遊戲",true);
    this->m_noteBook->AddPage(this->m_doubleUpPanel,L"比倍遊戲",false);
	//this->m_noteBook->AddPage(this->m_doubleUpPanel,L"主遊戲",true,0);
    //this->m_noteBook->SetImageList(NULL);
	/*  */
	this->m_hbox   = new wxBoxSizer(wxHORIZONTAL);
	this->m_hbox_2 = new wxBoxSizer(wxHORIZONTAL);
	this->m_hbox_3 = new wxBoxSizer(wxHORIZONTAL);
	this->m_hbox_4 = new wxBoxSizer(wxHORIZONTAL);
	this->m_hbox_5 = new wxBoxSizer(wxHORIZONTAL);

	this->m_vbox_1 = new wxBoxSizer(wxVERTICAL);
	this->m_vbox_2 = new wxBoxSizer(wxVERTICAL);

	this->m_probabilityPanel_1 = new ProbabilityPanel(this->m_parent,L"滾輪1  物件設定值");
	this->m_probabilityPanel_2 = new ProbabilityPanel(this->m_parent,L"滾輪2  物件設定值");
	this->m_probabilityPanel_3 = new ProbabilityPanel(this->m_parent,L"滾輪3  物件設定值");
	this->m_probabilityPanel_4 = new ProbabilityPanel(this->m_parent,L"滾輪4  物件設定值");
	this->m_probabilityPanel_5 = new ProbabilityPanel(this->m_parent,L"滾輪5  物件設定值");
	this->m_probabilityPanel_6 = new ProbabilityPanel(this->m_parent,L"滾輪6  物件設定值");
	this->m_probabilityPanel_7 = new ProbabilityPanel(this->m_parent,L"滾輪7  物件設定值");
	this->m_probabilityPanel_8 = new ProbabilityPanel(this->m_parent,L"滾輪8  物件設定值");
	this->m_probabilityPanel_9 = new ProbabilityPanel(this->m_parent,L"滾輪9  物件設定值");

	this->m_doubleProPanel = new DoubleProPanel(this->m_doubleUpPanel);
	this->m_doubleContinuePanel = new DoubleContinuePanel(this->m_doubleUpPanel);

	this->setSlot1DefaultValue();
	this->setSlot2DefaultValue();
	this->setSlot3DefaultValue();
	this->setSlot4DefaultValue();
	this->setSlot5DefaultValue();
	this->setSlot6DefaultValue();
	this->setSlot7DefaultValue();
	this->setSlot8DefaultValue();
	this->setSlot9DefaultValue();

	keyInMaxValue = 50000;

	this->m_keyInOutPanel = new KeyInOutPanel(this->m_parent);
	this->setAutoKeyInOutDefault();
	this->m_settingValuePanel = new SettingValuePanel(this->m_parent);
	this->m_dRunTimeSettingPanel = new DRunTimeSettingPanel(this->m_parent);
	this->setKeyInMaxDefaultValue();
	this->m_resultPanel = new ResultPanel(this->m_parent);

	//this->m_gauge = new wxGauge(this->m_parent,wxID_ANY,100);
	//this->m_gauge->SetValue(50);
	this->m_runButton = new wxButton(this->m_parent,CID_RUN_BUTTON,L"執行");
	this->m_resetButton = new wxButton(this->m_parent,CID_RESET_BUTTON,L"重置");

	Connect(CID_RUN_BUTTON,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(MainFrame::Run));
	Connect(CID_RESET_BUTTON,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(MainFrame::Reset));

	Connect(CID_COMBOBOX_COINSET,wxEVT_COMMAND_COMBOBOX_SELECTED,wxCommandEventHandler(MainFrame::AfterSelectCoinSet));
	Connect(CID_COMBOBOX_MAXBET,wxEVT_COMMAND_COMBOBOX_SELECTED,wxCommandEventHandler(MainFrame::AfterSelectMaxBet));
	Connect(CID_COMBOBOX_MAINGAMEMAXWIN,wxEVT_COMMAND_COMBOBOX_SELECTED,wxCommandEventHandler(MainFrame::AfterSelectMainGameMaxWin));
	Connect(CID_COMBOBOX_DOUBLEGAMEMAXWIN,wxEVT_COMMAND_COMBOBOX_SELECTED,wxCommandEventHandler(MainFrame::AfterSelectDoubleGameMaxWin));
	Connect(CID_CHECKBOX_RUNDOUBLEGAME,wxEVT_COMMAND_CHECKBOX_CLICKED,wxCommandEventHandler(MainFrame::AfterSelectRunDoubleGame));
	Connect(CID_CHECKBOX_RUNTODEAD,wxEVT_COMMAND_CHECKBOX_CLICKED,wxCommandEventHandler(MainFrame::AfterSelectRunToDead));


	this->m_hbox->Add(this->m_probabilityPanel_1,1);
	this->m_hbox->Add(this->m_probabilityPanel_2,1);
	this->m_hbox->Add(this->m_probabilityPanel_3,1);
	this->m_hbox_2->Add(this->m_probabilityPanel_4,1);
	this->m_hbox_2->Add(this->m_probabilityPanel_5,1);
	this->m_hbox_2->Add(this->m_probabilityPanel_6,1);
	this->m_hbox_3->Add(this->m_probabilityPanel_7,1);
	this->m_hbox_3->Add(this->m_probabilityPanel_8,1);
	this->m_hbox_3->Add(this->m_probabilityPanel_9,1);


	this->m_hbox_4->Add(this->m_keyInOutPanel,1,wxEXPAND | wxALL);
	this->m_vbox_2->Add(this->m_settingValuePanel,1, wxEXPAND | wxALL);
	this->m_vbox_2->Add(this->m_dRunTimeSettingPanel,1,wxEXPAND | wxALL);
	this->m_hbox_4->Add(this->m_vbox_2,0);

	//this->m_hbox_5->Add(this->m_gauge,0, wxALIGN_CENTER | wxRIGHT ,10);
	this->m_hbox_5->Add(this->m_resetButton,0);
	this->m_hbox_5->Add(this->m_runButton,0);

	this->m_vbox_1->Add(this->m_resultPanel,1,wxEXPAND);
	this->m_vbox_1->Add(this->m_hbox_5,0,wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 10);

	this->m_hbox_4->Add(this->m_vbox_1,1,wxEXPAND );


	this->m_topLevelSizer->Add(this->m_hbox,   1, wxEXPAND | (wxALL & ~wxLEFT), 1);
	this->m_topLevelSizer->Add(this->m_hbox_2, 1, wxEXPAND | (wxALL & ~wxLEFT), 1);
	this->m_topLevelSizer->Add(this->m_hbox_3, 1, wxEXPAND | (wxALL & ~wxLEFT), 1);
	this->m_topLevelSizer->Add(this->m_hbox_4, 1, wxEXPAND | (wxALL & ~wxLEFT), 1);

	this->m_parent->SetSizer(this->m_topLevelSizer,true);

	this->m_DoubleTopLevelSizer->Add(this->m_doubleProPanel,1,wxEXPAND | wxALL);
	this->m_DoubleTopLevelSizer->Add(this->m_doubleContinuePanel,1,wxEXPAND | wxALL);
	this->m_doubleUpPanel->SetSizer(this->m_DoubleTopLevelSizer,true);

	m_menubar = new wxMenuBar();
	m_file    = new wxMenu();
	m_file->Append(CID_SAVE_MENU, L"Save");
	m_file->Append(CID_LOAD_MENU, L"Load");
	m_file->AppendSeparator();

	quit = new wxMenuItem(m_file, wxID_EXIT);//, wxT("&Quit\tCtrl+W"));
	m_file->Append(quit);

	m_menubar->Append(m_file,L"File");

	m_about   = new wxMenu();
	m_about->Append(CID_ABOUT_MENU,L"About");

	m_menubar->Append(m_about,L"Other");

	SetMenuBar(m_menubar);

	Connect(CID_SAVE_MENU,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MainFrame::SaveFile));
	Connect(CID_LOAD_MENU,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MainFrame::LoadFile));
	Connect(wxID_EXIT,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MainFrame::OnQuit));
	Connect(CID_ABOUT_MENU,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MainFrame::OnAbout));

	SetIcon(icon_xpm);
	Centre();

	//
	m_needToReset = false;
	m_runOneTest  = false;

	//
	srand(time(NULL));
	mtRandom.resetMT(rand()%10000);//19650218UL);

	//
	this->systemSettingData = (SystemSettingData*)malloc(sizeof(SystemSettingData));
	this->systemSettingData->clearRamReset();

	//
	this->probabilitySettingData = (ProbabilitySettingData*)malloc(sizeof(ProbabilitySettingData));
	this->probabilitySettingData->clearRamReset();

	//Bonus Setting Data
	this->bonusSettingData = (BonusSettingData*)malloc(sizeof(BonusSettingData));
	this->bonusSettingData->clearRamReset();

	//Connect Setting Data
    this->connectSetting = (CONNECTSETTING*)malloc(sizeof(CONNECTSETTING));
    this->connectSetting->clearRamReset();


    //Double game run time setting data
    this->doubleRunTime = (DOUBLEGAMERUNTIME*)malloc(sizeof(DOUBLEGAMERUNTIME));
    this->doubleRunTime->Reset();

	//
	this->mf = (MainGameFrame*)malloc(sizeof(MainGameFrame));
	this->mf->ramClearReset();

	//
	this->gameCredits = (GameCredits*)malloc(sizeof(GameCredits));
    this->gameCredits->reSet();

    //
    this->rangeRec = (GameRec*)malloc(sizeof(GameRec));
    this->rangeRec->reset();

    this->totalRec = (GameRec*)malloc(sizeof(GameRec));
    this->totalRec->reset();

    this->dGameAwardRec = (DGAMEAWARDREC*)malloc(sizeof(DGAMEAWARDREC));
    this->dGameAwardRec->Reset();

	//
	this->probabilityControl = (ProbabilityControl*)malloc(sizeof(ProbabilityControl));
	this->probabilityControl->_RamClearReset(
			this->rangeRec,
			this->totalRec,
			&(this->connectSetting->_LinkFuncOnOff),
            &(this->systemSettingData->_GameLevel_Link),
            &(this->probabilitySettingData->_MainProSetting_Link),
            &(this->systemSettingData->_GameLevel),
            &(this->probabilitySettingData->_MainProSetting),
            &(this->systemSettingData->_CoinValue));

	//
	this->doubleProStep  = (DOUBLEPROSTEP*)malloc(sizeof(DOUBLEPROSTEP));
	this->doubleProStep->reset();

	//Double game continue setting
	this->doubleContinue = (DOUBLECONTINUE*)malloc(sizeof(DOUBLECONTINUE));
	this->doubleContinue->reset();

	this->setDoubleStepDefault();
	this->setDoubleContinueDefault();
}

void MainFrame::Run(wxCommandEvent& event){

	  bool runFlag = true;
	  unsigned long previousKeyIn=0;
	  unsigned long currentKeyIn=0;

	  if( m_needToReset == true){
		  wxMessageDialog *dial = new wxMessageDialog(NULL,L"請先按重置鈕",L"錯誤", wxOK | wxICON_ERROR);
		  dial->ShowModal();
		  return;
	  }else if( m_needToReset == false){
		  m_needToReset = true;
	  }

      // Check the value of Key In Maximum
	  if(wxAtoi(this->m_settingValuePanel->m_maxKeyIn_tc->GetValue()) < 10000 ){
		  wxMessageDialog *keyIndial = new wxMessageDialog(NULL,L"開分枚數不得小於 10000  枚",L"錯誤", wxOK | wxICON_ERROR);
		  keyIndial->ShowModal();
		  return;
	  }else if(wxAtoi(this->m_settingValuePanel->m_maxKeyIn_tc->GetValue())%100 != 0){
		  wxMessageDialog *keyIndial = new wxMessageDialog(NULL,L"開分枚數請以 100 枚為單位",L"錯誤", wxOK | wxICON_ERROR);
		  keyIndial->ShowModal();
		  return;
	  }

	  this->setSlot1ProbabilityStep();
	  this->mf->singleFrame[0].frameProTypeFunc = Slot1Probability;

	  this->setSlot2ProbabilityStep();
	  this->mf->singleFrame[1].frameProTypeFunc = Slot2Probability;

	  this->setSlot3ProbabilityStep();
	  this->mf->singleFrame[2].frameProTypeFunc = Slot3Probability;

	  this->setSlot4ProbabilityStep();
	  this->mf->singleFrame[3].frameProTypeFunc = Slot4Probability;

	  this->setSlot5ProbabilityStep();
	  this->mf->singleFrame[4].frameProTypeFunc = Slot5Probability;

	  this->setSlot6ProbabilityStep();
	  this->mf->singleFrame[5].frameProTypeFunc = Slot6Probability;

	  this->setSlot7ProbabilityStep();
	  this->mf->singleFrame[6].frameProTypeFunc = Slot7Probability;

	  this->setSlot8ProbabilityStep();
	  this->mf->singleFrame[7].frameProTypeFunc = Slot8Probability;

	  this->setSlot9ProbabilityStep();
	  this->mf->singleFrame[8].frameProTypeFunc = Slot9Probability;

	  this->setKeyInMaxValue();
	  this->setAutoKeyInOutValue();

	  this->setDoubleStepValue();
	  this->setDoubleContinueValue();

	  unsigned int targetKeyInCoin  = keyInMaxValue;
	  unsigned int progressMaxValue = 10000;
	  wxProgressDialog* progressDial = new wxProgressDialog(L"機率計算中",L"請稍後",progressMaxValue,NULL,wxPD_AUTO_HIDE|wxPD_APP_MODAL|wxPD_ELAPSED_TIME|wxPD_CAN_ABORT);
	  progressDial->Show();
	  wxSleep(1);

	  while(this->totalRec->key_in < targetKeyInCoin && runFlag == true){

		  //Auto KeyIn Credits
		  if(this->gameCredits->credits < 1000){
			  this->gameCredits->credits += systemSettingData->_KeyInKeyOut * systemSettingData->_CoinValue;
			  this->totalRec->key_in += systemSettingData->_KeyInKeyOut;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
			  cout<< "Auto KeyIn Credits : "<< this->gameCredits->credits << " " << "Total KeyIn : " << this->totalRec->key_in << endl;
#endif
			  currentKeyIn = this->totalRec->key_in;
		  }

		  //Bet MaxBet
		  this->BetForMax(&this->gameCredits->wager,&this->gameCredits->credits,true);
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
		  cout<< "Bet : "<<this->gameCredits->wager << " " << "Credits : " <<this->gameCredits->credits << endl;
#endif
		  this->ComputeWagerForLineAndSide(this->gameCredits->wager);
		  this->mf->bet = this->gameCredits->wager;

		  //Save total played & total bet scores
		  this->totalRec->played++;
		  this->totalRec->bet += this->gameCredits->wager;

          //Get stop item
		  //mpctrl = (MainGameProController*)(this->GetTask(tid_MainGameProController,0));
		  for(unsigned int i=0; i<sizeof(this->mf->singleFrame)/sizeof(this->mf->singleFrame[0]);i++){
			 // Get Stop Item
			 this->mf->singleFrame[i].getStopFrame(&mtRandom,this->probabilityControl);
			 //cout<< this->mf->singleFrame[i].stopItem << endl;
#ifdef DEBUG_MAINGAME_SPECIFIED_ITEM
			 // Test Fixed Item
			 unsigned int test[9] ={ 6,6,6,6,6,6,6,6,6 };
			 this->mf->singleFrame[i].stopItem = test[i];
#endif
			 //
			 this->mf->singleFrame[i].getStopLineFromItem(this->mf->singleFrame[i].stopItem);
		  }
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
		  //Print Stop Frame
		  for(unsigned int i=0; i<sizeof(this->mf->singleFrame)/sizeof(this->mf->singleFrame[0]);i++){
			  if(i>=0 && i<=2){
				  cout<< std::setw(3) << this->mf->singleFrame[i].stopItem;
				  if(i==2)
				  cout<< std::endl;
			  }else if(i>=3 && i<=5){
				  cout<< std::setw(3) << this->mf->singleFrame[i].stopItem;
				  if(i==5)
				  cout<< std::endl;
			  }else{
				  cout<< std::setw(3) << this->mf->singleFrame[i].stopItem;
				  if(i==8)
				  cout<< std::endl;
			  }
		  }
#endif
		  //Get Win
		  this->gameCredits->win = this->mf->getTotalWin(this->systemSettingData);
		  if(this->gameCredits->win > 0){
			  //Save total win times & total win scores
			  this->totalRec->hit++;
			  this->totalRec->won += this->gameCredits->win;
		  }

#ifdef DEBUG_OUTPUT_AWARD_DETAIL
		  cout<< "Win : " << this->gameCredits->win << endl;
#endif
		  //Enter double up game
		  unsigned int tmp_random=0;
		  unsigned int dPlayedTimes=0;
		  bool runToDeadFlag = false;
		  bool doubleOverMaxWinFlag = false;
		  if(this->m_dRunTimeSettingPanel->m_runDoubleGameChkBox->IsChecked() && this->gameCredits->win > 0){

			  if(this->m_dRunTimeSettingPanel->m_runToDeadChkBox->IsChecked()){ runToDeadFlag = true; }

			  while(( (tmp_random = this->mtRandom.getRandomLong(100)) < (unsigned)wxAtoi(this->m_doubleContinuePanel->m_doubleContinueTc[dPlayedTimes]->GetValue()) || runToDeadFlag )
			           && this->gameCredits->win >0 && dPlayedTimes < 15 && doubleOverMaxWinFlag==false){

					  this->totalRec->DoubleTotalPlayedScores += this->gameCredits->win;
					  this->totalRec->DoubleTotalPlayedTimes++;

					  switch(this->getDoubleGameAward()){

					  case DEF_DAWARD_TYPE_X0:
						  this->gameCredits->win *= 0;
						  this->dGameAwardRec->X0++;
						  break;
					  case DEF_DAWARD_TYPE_X2:
						  this->gameCredits->win *= 2;
						  this->dGameAwardRec->X2++;
						  break;
					  case DEF_DAWARD_TYPE_X4:
						  this->gameCredits->win *= 4;
						  this->dGameAwardRec->X4++;
						  break;
					  case DEF_DAWARD_TYPE_X6:
						  this->gameCredits->win *= 6;
						  this->dGameAwardRec->X6++;
						  break;
					  default:
						  break;

					  }

				  if(this->gameCredits->win > 0){
					  this->totalRec->DoubleTotalWonScores += this->gameCredits->win;
					  //Double game over max win
					  if(this->gameCredits->win/this->systemSettingData->_CoinValue > this->systemSettingData->_DDWNOfOverMaxWin){
						  this->totalRec->doubleover++;
						  doubleOverMaxWinFlag = true;
					  }
					  this->totalRec->DoubleTotalWonTimes++;
				  }

				  dPlayedTimes++;
				  //Save max consecutive pass times
				  if(dPlayedTimes > this->totalRec->DoubleMaxConsecutivePassTimes){
					  this->totalRec->DoubleMaxConsecutivePassTimes = dPlayedTimes;
				  }
			  }
		  }

		  //Add win to credits
		  if(this->gameCredits->win > 0){
			  this->gameCredits->credits += this->gameCredits->win;
			  if(this->gameCredits->credits/this->systemSettingData->_CoinValue > this->systemSettingData->_CreditUpLimit){
				  this->totalRec->sysover++;
			  }
			  this->gameCredits->win = 0;
		  }

		  //Reset Scroll Parameters
		  this->mf->reStartScrollPara();


		  //Auto KeyOut Credits
		  if(autoKeyOutCheck(this->gameCredits->credits) ==true){
			  while(this->gameCredits->credits >= systemSettingData->_KeyInKeyOut * systemSettingData->_CoinValue){
				  this->gameCredits->credits -= systemSettingData->_KeyInKeyOut * systemSettingData->_CoinValue;
				  this->totalRec->key_out += systemSettingData->_KeyInKeyOut;
			  }
		  }

		  //Update progress Dial
		  if((int)(this->totalRec->key_in/(keyInMaxValue/progressMaxValue))==progressMaxValue){
			  this->printLineAwardRecord();
			  this->printFullAwardRecord();
			  this->printFrameItemRecord();
			  this->printDoubleGameAwardRecord();
			  m_runOneTest = true;
		  }


		  if(previousKeyIn != currentKeyIn){
			  previousKeyIn = currentKeyIn;
			  this->updateResultPanel();
			  if( progressDial->Update((int)(this->totalRec->key_in/(keyInMaxValue/progressMaxValue))) == false ){
				  progressDial->Destroy();
				  this->totalRec->key_out += this->gameCredits->credits/systemSettingData->_CoinValue;
				  this->gameCredits->credits=0;
				  this->updateResultPanel();
				  runFlag = false;
			  }
		  }

	  }

	  /*
	  int tmp2 = 0;
	  wxProgressDialog* progressDial = new wxProgressDialog(L"機率計算中",L"請稍後",10,NULL,wxPD_AUTO_HIDE|wxPD_APP_MODAL|wxPD_ELAPSED_TIME);
	  profressDial->Show();
	  wxSleep(1);

	  while(tmp2<10){
		  tmp2++;
		  progressDial->Update(tmp2);
		  wxString test;
		  test << tmp2;
		  this->m_resultPanel->m_PlayWinScorePercent_tc->SetLabelText(test);
		  wxSleep(1);
	  }
	  */
}

void MainFrame::Reset(wxCommandEvent& event){

	this->mf->ramClearReset();

    this->gameCredits->reSet();

    this->rangeRec->reset();

    this->totalRec->reset();

    this->dGameAwardRec->Reset();

	this->m_resultPanel->m_totalKeyIn_tc->SetValue("0");

	this->m_resultPanel->m_totalKeyOut_tc->SetValue("0");

	this->m_resultPanel->m_keyInOutPercent_tc->SetValue("0");

	this->m_resultPanel->m_totalPlayScore_tc->SetValue("0");

	this->m_resultPanel->m_totalWinScore_tc->SetValue("0");

	this->m_resultPanel->m_PlayWinScorePercent_tc->SetValue("0");

	this->m_resultPanel->m_totalPlayTimes_tc->SetValue("0");

	this->m_resultPanel->m_totalWinTimes_tc->SetValue("0");

	this->m_resultPanel->m_PlayWinTimesPercent_tc->SetValue("0");

	this->m_resultPanel->m_doubleTotalPlayScore_tc->SetValue("0");

	this->m_resultPanel->m_doubleTotalWinScore_tc->SetValue("0");

	this->m_resultPanel->m_doubleTotalPlayTimes_tc->SetValue("0");

	this->m_resultPanel->m_doubleTotalWinTimes_tc->SetValue("0");

    this->m_resultPanel->m_doublePlayWinScorePercent_tc->SetValue("0");

    this->m_resultPanel->m_doublePlayWinTimesPercent_tc->SetValue("0");

    this->m_resultPanel->m_mainGameOverMaxWinTimes_tc->SetValue("0");

    this->m_resultPanel->m_doubleGameOverMaxWinTimes_tc->SetValue("0");

    this->m_resultPanel->m_doubleGameMaxConsecutivePassTimes_tc->SetValue("0");

	wxMessageDialog *dial = new wxMessageDialog(NULL,L"相關變數已經重置",L"訊息", wxOK | wxICON_INFORMATION);
	dial->ShowModal();

	if(m_needToReset == true){
		m_needToReset = false;
	}

	if(m_runOneTest == true){
		m_runOneTest = false;
	}

}

void MainFrame::OnQuit(wxCommandEvent& event){
	Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event){

	wxString buildDate = L"建置日期 : ";
	buildDate += __DATE__;
	buildDate += L" ";
	buildDate += __TIME__;

	wxMessageBox( buildDate,
        L"西遊記機率計算程式", wxOK | wxICON_INFORMATION, this);
}

void MainFrame::SaveFile(wxCommandEvent& event){

	if(m_runOneTest==false){
	  wxMessageDialog *dial = new wxMessageDialog(NULL,L"請跑過計算後再儲存",L"錯誤", wxOK | wxICON_ERROR);
	  dial->ShowModal();
	  return;
	}
    wxFileDialog
        saveFileDialog(this, L"Save TXT file", "", "result",
                       "TXT files (*.txt)|*.txt", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

    wxFFileOutputStream output_stream(saveFileDialog.GetPath());
    if(!output_stream.IsOk()){
        wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
        return;
    }
    wxTextOutputStream store(output_stream);
    this->SaveFileContent(store);
    store.Flush();
#if 0
    // save the current contents in the file;
    // this can be done with e.g. wxWidgets output streams:
    wxFileOutputStream output_stream(saveFileDialog.GetPath());
    if (!output_stream.IsOk())
    {
        wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
        return;
    }
#endif

}

void MainFrame::SaveFileContent(wxTextOutputStream& store){
    //Slot 1
	store << wxString(L"滾輪 1 設定值") << endl;
	store << " # " ;
    store << this->m_probabilityPanel_1->m_slotItem_1_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_1->m_slotItem_2_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_1->m_slotItem_3_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_1->m_slotItem_4_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_1->m_slotItem_5_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_1->m_slotItem_6_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_1->m_slotItem_7_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_1->m_slotItem_8_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_1->m_slotItem_9_tc->GetValue() << endl;
    store << endl;
    //Slot 2
    store << wxString(L"滾輪 2 設定值") << endl;
    store << " # " ;
    store << this->m_probabilityPanel_2->m_slotItem_1_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_2->m_slotItem_2_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_2->m_slotItem_3_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_2->m_slotItem_4_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_2->m_slotItem_5_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_2->m_slotItem_6_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_2->m_slotItem_7_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_2->m_slotItem_8_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_2->m_slotItem_9_tc->GetValue() << endl;
    store << endl;
    //Slot 3
    store << wxString(L"滾輪 3 設定值") << endl;
    store << " # " ;
    store << this->m_probabilityPanel_3->m_slotItem_1_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_3->m_slotItem_2_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_3->m_slotItem_3_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_3->m_slotItem_4_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_3->m_slotItem_5_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_3->m_slotItem_6_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_3->m_slotItem_7_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_3->m_slotItem_8_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_3->m_slotItem_9_tc->GetValue() << endl;
    store << endl;
    //Slot 4
    store << wxString(L"滾輪 4 設定值") << endl;
    store << " # " ;
    store << this->m_probabilityPanel_4->m_slotItem_1_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_4->m_slotItem_2_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_4->m_slotItem_3_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_4->m_slotItem_4_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_4->m_slotItem_5_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_4->m_slotItem_6_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_4->m_slotItem_7_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_4->m_slotItem_8_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_4->m_slotItem_9_tc->GetValue() << endl;
    store << endl;
    //Slot 5
    store << wxString(L"滾輪 5 設定值") << endl;
    store << " # " ;
    store << this->m_probabilityPanel_5->m_slotItem_1_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_5->m_slotItem_2_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_5->m_slotItem_3_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_5->m_slotItem_4_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_5->m_slotItem_5_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_5->m_slotItem_6_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_5->m_slotItem_7_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_5->m_slotItem_8_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_5->m_slotItem_9_tc->GetValue() << endl;
    store << endl;
    //Slot 6
    store << wxString(L"滾輪 6 設定值") << endl;
    store << " # " ;
    store << this->m_probabilityPanel_6->m_slotItem_1_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_6->m_slotItem_2_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_6->m_slotItem_3_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_6->m_slotItem_4_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_6->m_slotItem_5_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_6->m_slotItem_6_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_6->m_slotItem_7_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_6->m_slotItem_8_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_6->m_slotItem_9_tc->GetValue() << endl;
    store << endl;
    //Slot 7
    store << wxString(L"滾輪 7 設定值") << endl;
    store << " # " ;
    store << this->m_probabilityPanel_7->m_slotItem_1_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_7->m_slotItem_2_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_7->m_slotItem_3_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_7->m_slotItem_4_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_7->m_slotItem_5_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_7->m_slotItem_6_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_7->m_slotItem_7_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_7->m_slotItem_8_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_7->m_slotItem_9_tc->GetValue() << endl;
    store << endl;
    //Slot 8
    store << wxString(L"滾輪 8 設定值") << endl;
    store << " # " ;
    store << this->m_probabilityPanel_8->m_slotItem_1_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_8->m_slotItem_2_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_8->m_slotItem_3_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_8->m_slotItem_4_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_8->m_slotItem_5_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_8->m_slotItem_6_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_8->m_slotItem_7_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_8->m_slotItem_8_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_8->m_slotItem_9_tc->GetValue() << endl;
    store << endl;
    //Slot 9
    store << wxString(L"滾輪 9 設定值") << endl;
    store << " # " ;
    store << this->m_probabilityPanel_9->m_slotItem_1_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_9->m_slotItem_2_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_9->m_slotItem_3_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_9->m_slotItem_4_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_9->m_slotItem_5_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_9->m_slotItem_6_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_9->m_slotItem_7_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_9->m_slotItem_8_tc->GetValue() << "  ";
    store << this->m_probabilityPanel_9->m_slotItem_9_tc->GetValue() << endl;
    store << endl;

    //Double game X0 setting value
    wxString double_award_name[4] ={
    		L"X0  簽數設定",
    		L"X2  簽數設定",
    		L"X4  簽數設定",
    		L"X6  簽數設定",
    };

    for(unsigned int idx=0; idx<sizeof(this->m_doubleProPanel->m_doubleOddsTc)/sizeof(this->m_doubleProPanel->m_doubleOddsTc[0])-1; idx++){
    	store << double_award_name[idx] << endl;
    	store << "%" ;
    	store << " " ;
    	store << this->m_doubleProPanel->m_doubleOddsTc[idx]->GetValue() << endl;
    }

    store << endl;

    store << L"遊戲幣值設定 :" << endl;
    store << " $ " << this->systemSettingData->_CoinValue << endl;

    store << endl;

    store << L"最大押分設定 :" << endl;
    store << " $ " << this->systemSettingData->_MaxBet  << endl;

    store << endl;

    store << L"主遊戲爆機枚數設定 :" << endl;
    store << " $ " << this->systemSettingData->_CreditUpLimit  << endl;

    store << endl;

    store << L"比倍遊戲爆機枚數設定 :" << endl;
    store << " $ " << this->systemSettingData->_DDWNOfOverMaxWin  << endl;

    store << endl;

    store << L"執行比倍遊戲 (True:1 False:0):" << endl;
    store << " $ " << this->doubleRunTime->_enable  << endl;
    //cout <<  " $ " << this->doubleRunTime->_enable  << endl;

    store << endl;

    store << L"比到脫褲 (True:1 False:0):" << endl;
    store << " $ " << this->doubleRunTime->_runToDead  << endl;

    store << endl;
    store << endl;

    //Key In Maximum value
    store << L"開分枚數上限 : " << this->m_settingValuePanel->m_maxKeyIn_tc->GetValue() << endl;

    //Total KeyIn & KeyOut
    store << L"總開枚數  : " << this->m_resultPanel->m_totalKeyIn_tc->GetValue() << endl;

    store << L"總洗枚數  : " << this->m_resultPanel->m_totalKeyOut_tc->GetValue() << endl;

    store << L"營業機率  : " << 100 * (float)this->totalRec->key_out/(float)this->totalRec->key_in << " % " << endl;

    //Total Play & Win scores
    store << L"總玩分數  : " << this->m_resultPanel->m_totalPlayScore_tc->GetValue() << endl;

    store << L"總贏分數  : " << this->m_resultPanel->m_totalWinScore_tc->GetValue() << endl;

    store << L"機械機率  : " << 100 * (float)this->totalRec->won/(float)this->totalRec->bet << " % " << endl;

    //Total Play & Hit times
    store << L"總玩次數  : " << this->m_resultPanel->m_totalPlayTimes_tc->GetValue() << endl;

    store << L"總贏次數  : " << this->m_resultPanel->m_totalWinTimes_tc->GetValue() << endl;

    store << L"中獎機率  : " << 100 * (float)this->totalRec->hit / (float)this->totalRec->played << " % " << endl;

    //Double up game total Played & Won Scores
    store << L"比倍總玩分數 : " << this->m_resultPanel->m_doubleTotalPlayScore_tc->GetValue() << endl;

    store << L"比倍總贏分數 : " << this->m_resultPanel->m_doubleTotalWinScore_tc->GetValue() << endl;
    if(this->totalRec->DoubleTotalPlayedScores != 0){
    	store << L"比倍機械機率 : " << 100 * (float)this->totalRec->DoubleTotalWonScores / (float)this->totalRec->DoubleTotalPlayedScores << " % " << endl;
    }else{
    	store << L"比倍機械機率 : " << "0" << endl;
    }
    //Double up game total Played & Won Times
    store << L"比倍總玩次數 : " << this->m_resultPanel->m_doubleTotalPlayTimes_tc->GetValue() << endl;

    store << L"比倍總贏次數 : " << this->m_resultPanel->m_doubleTotalWinTimes_tc->GetValue() << endl;

    if(this->totalRec->DoubleTotalPlayedTimes != 0){
    	store << L"比倍中獎機率 : " << 100 * (float)this->totalRec->DoubleTotalWonTimes / (float)this->totalRec->DoubleTotalPlayedTimes << " % " << endl;
    }else{
    	store << L"比倍中獎機率 : " << "0" << endl;
    }
    //Main game over max win & Double up game over max win & Double up game max consecutive pass times
    store << L"主遊戲爆機次數 : " << (unsigned int)this->totalRec->sysover << endl;

    store << L"比倍遊戲爆機次數 : " << (unsigned int)this->totalRec->doubleover << endl;

    store << L"比倍連續過關次數 : " << this->totalRec->DoubleMaxConsecutivePassTimes << endl;

    store << endl;
    store << endl;

	const char* awardName[13] = {
		"None               ",
		"One cherry         ",
		"Two cherry         ",
		"Cherry Straight    ",
		"Orange Straight    ",
		"Mix Bar Straight   ",
		"Mango Straight     ",
		"Bell Straight      ",
		"WaterMelon Straight",
		"Bar yellow Straight",
		"Bar Red Straight   ",
		"Bar Blue Straight  ",
		"Wild Straight      "
	};

	store << "------------------------ Line Award Record ------------------------" << endl;
	for(unsigned int i=0;i<sizeof(this->mf->line)/sizeof(this->mf->line[0]);i++){
		store << "----- Line " << wxInt32(i+1) << " Award Times -----" << endl;
		for(unsigned int j=0; j<sizeof(this->mf->line[i].AwardRecord)/sizeof(this->mf->line[i].AwardRecord[0]);j++){
			store << wxString(awardName[j]) << " : " << wxInt32(this->mf->line[i].AwardRecord[j]) << " " << endl;;
		}
	}

    store << endl;
    store << endl;

	//Print Full Frame Award Record
    store << "--------------------- FULL Frame Award Record ---------------------" << endl;
    store << "FULL ALL FRUIT Times       : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_ALL_FRUIT-1][9]) << endl;
    store << "FULL ANY_BAR Times         : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_ANY_BAR-1][9])   << endl;
    store << "FULL ORANGE Times          : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_ORANGE-1][9])    << endl;
    store << "FULL MANGO Times           : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_MANGO-1][9])     << endl;
    store << "FULL BELL Times            : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_BELL-1][9])      << endl;
    store << "FULL WATERMELON Times      : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_WATERMELON-1][9])<< endl;
    store << "FULL BAR YELLOW Times      : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_BAR_YELLOW-1][9])<< endl;
    store << "FULL CHERRY Times          : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_CHERRY-1][9])    << endl;
    store << "FULL BAR RED Times         : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_BAR_RED-1][9])   << endl;
    store << "FULL BAR BLUE Times        : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_BAR_BLUE-1][9])  << endl;
    store << "WILD X3 Times              : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_WILD-1][3])      << endl;
    store << "WILD X4 Times              : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_WILD-1][4])      << endl;
    store << "WILD X5 Times              : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_WILD-1][5])      << endl;
    store << "WILD X6 Times              : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_WILD-1][6])      << endl;
    store << "WILD X7 Times              : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_WILD-1][7])      << endl;
    store << "WILD X8 Times              : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_WILD-1][8])      << endl;
    store << "FULL WILD Times            : " << wxInt32(this->mf->FullFrameAwardRecord[FULL_AWARD_WILD-1][9])      << endl;

    store << endl;
    store << endl;

	const char* itemName[10] = {
		"Unknow    ",
		"cherry    ",
		"Orange    ",
		"Mango     ",
		"Bell      ",
		"WaterMelon",
		"Bar yellow",
		"Bar Red   ",
		"Bar Blue  ",
		"Wild      "
	};

	store << "----------------------- Frame Item Record -----------------------" << endl;
	for(unsigned int i=0; i<sizeof(this->mf->singleFrame)/sizeof(this->mf->singleFrame[0]);i++){
		store << "----- Frame " << wxInt32(i+1) << " Item Times -----" << endl;
		for(unsigned int k=0; k<sizeof(this->mf->singleFrame[i].GetItemRecord)/sizeof(this->mf->singleFrame[i].GetItemRecord[0]);k++){
			store << wxString(itemName[k]) << " : " << wxInt32(this->mf->singleFrame[i].GetItemRecord[k]) <<endl;
		  }
	}


	const char* dAwardName[4] = {
			"X0 Times : ",
			"X2 Times : ",
			"X4 Times : ",
			"X6 Times : "
	};

	store<< "------------------- Double Up Game Award Record -------------------" << endl;
	store<< dAwardName[0]  << this->dGameAwardRec->X0 << endl;
	store<< dAwardName[1]  << this->dGameAwardRec->X2 << endl;
	store<< dAwardName[2]  << this->dGameAwardRec->X4 << endl;
	store<< dAwardName[3]  << this->dGameAwardRec->X6 << endl;

}

void MainFrame::LoadFile(wxCommandEvent& event){
	if(m_runOneTest==true){
	  wxMessageDialog *dial = new wxMessageDialog(NULL,L"請重置後再讀檔",L"錯誤", wxOK | wxICON_ERROR);
	  dial->ShowModal();
	  return;
	}

    wxFileDialog
        loadFileDialog(this, L"Save TXT file", "", "",
                       "TXT files (*.txt)|*.txt", wxFD_OPEN);

    if (loadFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

#if 0
    //Way 1
    wxFFileInputStream input_stream(loadFileDialog.GetPath());
    if(!input_stream.IsOk()){
        wxLogError("Cannot load file : '%s'.", loadFileDialog.GetPath());
        return;
    }

    wxTextInputStream load(input_stream);
    this->LoadFileContent(load);

#endif

#if 1
    //Way 2
    this->LoadFileContentAlternative(loadFileDialog.GetPath());
#endif
}

void MainFrame::LoadFileContent(wxTextInputStream& load){

	load.SetStringSeparators(wxString("\r\n"));
	wxString tmp;

	load >> tmp;
	while(tmp.IsNull()==false){
		printf("%s\n",(const char*)tmp.mb_str());
		load >> tmp;
	}
}

void MainFrame::LoadFileContentAlternative(wxString filePath){
	wxTextFile tfile;
	tfile.Open(filePath);
	wxString content;
    int times = 0;
    int dproTimes=0;
    int settingTimes = 0;
    int index=0;
    int item_percent[9][9];
    int dpro_tmp[4]= {0,0,0,0};
    for(unsigned int i=0; i<sizeof(item_percent)/sizeof(item_percent[0]);i++){
    	for(unsigned int j=0;j<sizeof(item_percent[0])/sizeof(item_percent[0][0]);j++){
    		item_percent[i][j]=0;
    	}
    }

    content=tfile.GetFirstLine();
    while(!tfile.Eof()){
    	//Test chinaese output
    	{
        //puts(str.mb_str());//OK
        //printf("%s\n",(const char*)str.mb_str());//OK
        //cout<<str.mb_str()<<endl;//NOT OK
    	}

        if(content.Contains(wxString("#"))){
        	++times;
        	//printf("%s\n",(const char*)content.mb_str());
        	wxStringTokenizer tokenizer(content," ");
        	index=0;

        	switch(times){

        	case 1:
            	while(tokenizer.HasMoreTokens()==true){
            		wxString token = tokenizer.GetNextToken();
            		if(token.IsNumber()==true){
            			//printf("SLOT 1 Token: %s\n",(const char*)token.mb_str());
            			item_percent[0][index] = wxAtoi(token);
            			//printf("%d : %d\n",index,item_percent[0][index]);
            			++index;
            		}
            	}
        		break;
        	case 2:
            	while(tokenizer.HasMoreTokens()==true){
            		wxString token = tokenizer.GetNextToken();
            		if(token.IsNumber()==true){
            			//printf("SLOT 2 Token: %s\n",(const char*)token.mb_str());
            			item_percent[1][index] = wxAtoi(token);
            			//printf("%d : %d\n",index,item_percent[1][index]);
            			++index;
            		}
            	}
        		break;
        	case 3:
            	while(tokenizer.HasMoreTokens()==true){
            		wxString token = tokenizer.GetNextToken();
            		if(token.IsNumber()==true){
            			//printf("SLOT 3 Token: %s\n",(const char*)token.mb_str());
            			item_percent[2][index] = wxAtoi(token);
            			//printf("%d : %d\n",index,item_percent[2][index]);
            			++index;
            		}
            	}
        		break;
        	case 4:
            	while(tokenizer.HasMoreTokens()==true){
            		wxString token = tokenizer.GetNextToken();
            		if(token.IsNumber()==true){
            			//printf("SLOT 4 Token: %s\n",(const char*)token.mb_str());
            			item_percent[3][index] = wxAtoi(token);
            			//printf("%d : %d\n",index,item_percent[3][index]);
            			++index;
            		}
            	}
        		break;
        	case 5:
            	while(tokenizer.HasMoreTokens()==true){
            		wxString token = tokenizer.GetNextToken();
            		if(token.IsNumber()==true){
            			//printf("SLOT 5 Token: %s\n",(const char*)token.mb_str());
            			item_percent[4][index] = wxAtoi(token);
            			//printf("%d : %d\n",index,item_percent[4][index]);
            			++index;
            		}
            	}
        		break;
        	case 6:
            	while(tokenizer.HasMoreTokens()==true){
            		wxString token = tokenizer.GetNextToken();
            		if(token.IsNumber()==true){
            			//printf("SLOT 6 Token: %s\n",(const char*)token.mb_str());
            			item_percent[5][index] = wxAtoi(token);
            			//printf("%d : %d\n",index,item_percent[5][index]);
            			++index;
            		}
            	}
        		break;
        	case 7:
            	while(tokenizer.HasMoreTokens()==true){
            		wxString token = tokenizer.GetNextToken();
            		if(token.IsNumber()==true){
            			//printf("SLOT 7 Token: %s\n",(const char*)token.mb_str());
            			item_percent[6][index] = wxAtoi(token);
            			//printf("%d : %d\n",index,item_percent[6][index]);
            			++index;
            		}
            	}
        		break;
        	case 8:
            	while(tokenizer.HasMoreTokens()==true){
            		wxString token = tokenizer.GetNextToken();
            		if(token.IsNumber()==true){
            			//printf("SLOT 8 Token: %s\n",(const char*)token.mb_str());
            			item_percent[7][index] = wxAtoi(token);
            			//printf("%d : %d\n",index,item_percent[7][index]);
            			++index;
            		}
            	}
        		break;
        	case 9:
            	while(tokenizer.HasMoreTokens()==true){
            		wxString token = tokenizer.GetNextToken();
            		if(token.IsNumber()==true){
            			//printf("SLOT 9 Token: %s\n",(const char*)token.mb_str());
            			item_percent[8][index] = wxAtoi(token);
            			//printf("%d : %d\n",index,item_percent[8][index]);
               			++index;
            		}
            	}
        		break;

        	default:
        		break;

        	}
        }else if(content.Contains(wxString("%"))){//Double game probability setting value
        	++dproTimes;
        	wxStringTokenizer setting_tokenizer(content,wxString(" "));

        	switch(dproTimes){

        	case 4://X6
        		while(setting_tokenizer.HasMoreTokens()){
        			wxString setting_tmp = setting_tokenizer.GetNextToken();
        			if(setting_tmp.IsNumber()==true){
        			    //Load double game probability setting
        				unsigned int x6_tmp = wxAtoi(setting_tmp);
        				//
        				dpro_tmp[3] = x6_tmp;
        			}
        		}
        		break;

        	case 3://X4
        		while(setting_tokenizer.HasMoreTokens()){
        			wxString setting_tmp = setting_tokenizer.GetNextToken();
        			if(setting_tmp.IsNumber()==true){
        			    //Load double game probability setting
        				unsigned int x4_tmp = wxAtoi(setting_tmp);
        				//
        				dpro_tmp[2] = x4_tmp;
        			}
        		}
        		break;

        	case 2://X2
        		while(setting_tokenizer.HasMoreTokens()){
        			wxString setting_tmp = setting_tokenizer.GetNextToken();
        			if(setting_tmp.IsNumber()==true){
        			    //Load double game probability setting
        				unsigned int x2_tmp = wxAtoi(setting_tmp);
        				//
        				dpro_tmp[1] = x2_tmp;
        			}
        		}
        		break;

        	case 1://X0
        		while(setting_tokenizer.HasMoreTokens()){
        			wxString setting_tmp = setting_tokenizer.GetNextToken();
        			if(setting_tmp.IsNumber()==true){
        			    //Load double game probability setting
        				unsigned int x0_tmp = wxAtoi(setting_tmp);
        				//
        				dpro_tmp[0] = x0_tmp;
        			}
        		}

        		break;

        	default:
        		break;
        	}

        }else if(content.Contains(wxString("$"))){
        	++settingTimes;
        	wxStringTokenizer setting_tokenizer(content,wxString(" "));

        	switch(settingTimes){

        	case 1://Coin Set
        		while(setting_tokenizer.HasMoreTokens()){
        			wxString setting_tmp = setting_tokenizer.GetNextToken();
        			if(setting_tmp.IsNumber()==true){
        				//Load Coin Set Save value
        				unsigned int saveCoinSet = wxAtoi(setting_tmp);
        				//bool resultCoinSet = false;
        				for(unsigned int idx=0; idx<sizeof(coin_value_tab)/sizeof(coin_value_tab[0]);idx++){
        					if(coin_value_tab[idx] == saveCoinSet){
        						cout<< "Get CoinSet Save Value : " << saveCoinSet << endl;
        					    this->m_settingValuePanel->m_coinSetCB->SetSelection(idx);
        					    this->systemSettingData->_CoinValue = coin_value_tab[idx];
        						//resultCoinSet = true;
        						break;
        					}
        				}
        			}
        		}
        		break;

        	case 2://Max Bet
        		while(setting_tokenizer.HasMoreTokens()){
        			wxString setting_tmp = setting_tokenizer.GetNextToken();
        			if(setting_tmp.IsNumber()==true){
        				//Load Max Bet Set
        				unsigned int saveMaxBet = wxAtoi(setting_tmp);
        				//bool resultMaxBet = false;
        				for(unsigned int idx=0; idx<sizeof(maxbet_tab)/sizeof(maxbet_tab[0]); idx++){
        					if(maxbet_tab[idx] == saveMaxBet){
        						cout<< "Get MaxBet Save Value : " << saveMaxBet << endl;
        						this->m_settingValuePanel->m_maxBetCB->SetSelection(idx);
        						this->systemSettingData->_MaxBet = maxbet_tab[idx];
        						//resultMaxBet = true;
        						break;
        					}
        				}
        			}
        		}

        		break;

        	case 3://Main Game Max Win Coins
        		while(setting_tokenizer.HasMoreTokens()){
        			wxString setting_tmp = setting_tokenizer.GetNextToken();
        			if(setting_tmp.IsNumber()==true){
        				//Load Main Game Max Win Coins
        				unsigned int saveMainGameMaxWin = wxAtoi(setting_tmp);
        				//bool resultMaxBet = false;
        				for(unsigned int idx=0; idx<sizeof(credituplimit_tab)/sizeof(credituplimit_tab[0]); idx++){
        					if(credituplimit_tab[idx] == saveMainGameMaxWin){
        						cout<< "Get Main Game Max Win Coins Save Value : " << saveMainGameMaxWin << endl;
        						this->m_settingValuePanel->m_mainGameMaxWinCB->SetSelection(idx);
        						this->systemSettingData->_CreditUpLimit = credituplimit_tab[idx];
        						//resultMaxBet = true;
        						break;
        					}
        				}
        			}
        		}

        		break;

        	case 4://Double Game Max Win Coins
        		while(setting_tokenizer.HasMoreTokens()){
        			wxString setting_tmp = setting_tokenizer.GetNextToken();
        			if(setting_tmp.IsNumber()==true){
        				//Load Double Game Max Win Coins
        				unsigned int saveDoubleGameMaxWin = wxAtoi(setting_tmp);
        				//bool resultMaxBet = false;
        				for(unsigned int idx=0; idx<sizeof(dduplimit_tab)/sizeof(dduplimit_tab[0]); idx++){
        					if(dduplimit_tab[idx] == saveDoubleGameMaxWin){
        						cout<< "Get Double Game Max Win Coins Save Value : " << saveDoubleGameMaxWin << endl;
        						this->m_settingValuePanel->m_doubleGameMaxWinCB->SetSelection(idx);
        						this->systemSettingData->_DDWNOfOverMaxWin = dduplimit_tab[idx];
        						//resultMaxBet = true;
        						break;
        					}
        				}
        			}
        		}

        		break;

        	case 5://Run double game
        		while(setting_tokenizer.HasMoreTokens()){
        			wxString setting_tmp = setting_tokenizer.GetNextToken();
        			if(setting_tmp.IsNumber()==true){
        				//Load Double Game Max Win Coins
        				unsigned int runDoubleGame = wxAtoi(setting_tmp);
        				//bool resultMaxBet = false;
        				cout<< "Get Run-Double-Game Save Value : " << runDoubleGame << endl;
        				switch(runDoubleGame){

        				case 1:
        					this->m_dRunTimeSettingPanel->m_runDoubleGameChkBox->SetValue(true);
        					this->doubleRunTime->_enable = runDoubleGame;
        					break;

        				case 0:
        					this->m_dRunTimeSettingPanel->m_runDoubleGameChkBox->SetValue(false);
        					this->doubleRunTime->_enable = runDoubleGame;
        					break;

        				default:

        					break;
        				}
        			}
        		}

        		break;

        	case 6://Run to dead
        		while(setting_tokenizer.HasMoreTokens()){
        			wxString setting_tmp = setting_tokenizer.GetNextToken();
        			if(setting_tmp.IsNumber()==true){
        				//Load Double Game Max Win Coins
        				unsigned int runToDead = wxAtoi(setting_tmp);
        				//bool resultMaxBet = false;
        				cout<< "Get Run-To-Dead Save Value : " << runToDead << endl;
        				switch(runToDead){

        				case 1:
        					this->m_dRunTimeSettingPanel->m_runToDeadChkBox->SetValue(true);
        					this->doubleRunTime->_runToDead = runToDead;
        					break;

        				case 0:
        					this->m_dRunTimeSettingPanel->m_runToDeadChkBox->SetValue(false);
        					this->doubleRunTime->_runToDead = runToDead;
        					break;

        				default:

        					break;
        				}
        			}
        		}

        		break;

        	default:
        		break;
        	}

        }

        content=tfile.GetNextLine();
        if(times==9 && settingTimes==6 && dproTimes==4) break;
    }


    if(times==9){
    	wxString _item;
    	//Slot 1
    	_item << 0;
			this->m_probabilityPanel_1->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
    	_item << 0;
			this->m_probabilityPanel_1->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
    	_item << 0;
			this->m_probabilityPanel_1->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
    	_item << 0;
			this->m_probabilityPanel_1->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
    	_item << 0;
			this->m_probabilityPanel_1->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
    	_item << 0;
			this->m_probabilityPanel_1->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
    	_item << 0;
			this->m_probabilityPanel_1->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
    	_item << 0;
			this->m_probabilityPanel_1->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
    	_item << 0;
			this->m_probabilityPanel_1->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();
		//
    	_item << item_percent[0][0];
			this->m_probabilityPanel_1->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
    	_item << item_percent[0][1];
			this->m_probabilityPanel_1->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
    	_item << item_percent[0][2];
			this->m_probabilityPanel_1->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
    	_item << item_percent[0][3];
			this->m_probabilityPanel_1->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
    	_item << item_percent[0][4];
			this->m_probabilityPanel_1->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
    	_item << item_percent[0][5];
			this->m_probabilityPanel_1->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
    	_item << item_percent[0][6];
			this->m_probabilityPanel_1->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
    	_item << item_percent[0][7];
			this->m_probabilityPanel_1->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
    	_item << item_percent[0][8];
			this->m_probabilityPanel_1->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();

		//Slot 2
		_item << 0;
			this->m_probabilityPanel_2->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_2->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_2->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_2->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_2->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_2->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_2->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_2->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_2->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();
		//
		_item << item_percent[1][0];
			this->m_probabilityPanel_2->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[1][1];
			this->m_probabilityPanel_2->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[1][2];
			this->m_probabilityPanel_2->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[1][3];
			this->m_probabilityPanel_2->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[1][4];
			this->m_probabilityPanel_2->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[1][5];
			this->m_probabilityPanel_2->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[1][6];
			this->m_probabilityPanel_2->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[1][7];
			this->m_probabilityPanel_2->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[1][8];
			this->m_probabilityPanel_2->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();

		//Slot 3
		_item << 0;
			this->m_probabilityPanel_3->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_3->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_3->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_3->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_3->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_3->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_3->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_3->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_3->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();

		_item << item_percent[2][0];
			this->m_probabilityPanel_3->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[2][1];
			this->m_probabilityPanel_3->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[2][2];
			this->m_probabilityPanel_3->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[2][3];
			this->m_probabilityPanel_3->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[2][4];
			this->m_probabilityPanel_3->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[2][5];
			this->m_probabilityPanel_3->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[2][6];
			this->m_probabilityPanel_3->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[2][7];
			this->m_probabilityPanel_3->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[2][8];
			this->m_probabilityPanel_3->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();

		//Slot 4
		_item << 0;
			this->m_probabilityPanel_4->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_4->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_4->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_4->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_4->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_4->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_4->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_4->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_4->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();

		_item << item_percent[3][0];
			this->m_probabilityPanel_4->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[3][1];
			this->m_probabilityPanel_4->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[3][2];
			this->m_probabilityPanel_4->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[3][3];
			this->m_probabilityPanel_4->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[3][4];
			this->m_probabilityPanel_4->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[3][5];
			this->m_probabilityPanel_4->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[3][6];
			this->m_probabilityPanel_4->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[3][7];
			this->m_probabilityPanel_4->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[3][8];
			this->m_probabilityPanel_4->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();

		//Slot 5
		_item << 0;
			this->m_probabilityPanel_5->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_5->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_5->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_5->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_5->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_5->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_5->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_5->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_5->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();

		_item << item_percent[4][0];
			this->m_probabilityPanel_5->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[4][1];
			this->m_probabilityPanel_5->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[4][2];
			this->m_probabilityPanel_5->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[4][3];
			this->m_probabilityPanel_5->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[4][4];
			this->m_probabilityPanel_5->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[4][5];
			this->m_probabilityPanel_5->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[4][6];
			this->m_probabilityPanel_5->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[4][7];
			this->m_probabilityPanel_5->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[4][8];
			this->m_probabilityPanel_5->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();

		//Slot 6
		_item << 0;
			this->m_probabilityPanel_6->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_6->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_6->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_6->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_6->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_6->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_6->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_6->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_6->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();

		_item << item_percent[5][0];
			this->m_probabilityPanel_6->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[5][1];
			this->m_probabilityPanel_6->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[5][2];
			this->m_probabilityPanel_6->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[5][3];
			this->m_probabilityPanel_6->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[5][4];
			this->m_probabilityPanel_6->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[5][5];
			this->m_probabilityPanel_6->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[5][6];
			this->m_probabilityPanel_6->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[5][7];
			this->m_probabilityPanel_6->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[5][8];
			this->m_probabilityPanel_6->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();

		//Slot 7
		_item << 0;
			this->m_probabilityPanel_7->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_7->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_7->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_7->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_7->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_7->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_7->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_7->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_7->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();

		_item << item_percent[6][0];
			this->m_probabilityPanel_7->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[6][1];
			this->m_probabilityPanel_7->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[6][2];
			this->m_probabilityPanel_7->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[6][3];
			this->m_probabilityPanel_7->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[6][4];
			this->m_probabilityPanel_7->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[6][5];
			this->m_probabilityPanel_7->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[6][6];
			this->m_probabilityPanel_7->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[6][7];
			this->m_probabilityPanel_7->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[6][8];
			this->m_probabilityPanel_7->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();

		//Slot 8
		_item << 0;
			this->m_probabilityPanel_8->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_8->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_8->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_8->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_8->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_8->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_8->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_8->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_8->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();

		_item << item_percent[7][0];
			this->m_probabilityPanel_8->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[7][1];
			this->m_probabilityPanel_8->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[7][2];
			this->m_probabilityPanel_8->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[7][3];
			this->m_probabilityPanel_8->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[7][4];
			this->m_probabilityPanel_8->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[7][5];
			this->m_probabilityPanel_8->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[7][6];
			this->m_probabilityPanel_8->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[7][7];
			this->m_probabilityPanel_8->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[7][8];
			this->m_probabilityPanel_8->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();

		//Slot 9
		_item << 0;
			this->m_probabilityPanel_9->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_9->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_9->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_9->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_9->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_9->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_9->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_9->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
		_item << 0;
			this->m_probabilityPanel_9->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();

		_item << item_percent[8][0];
			this->m_probabilityPanel_9->m_slotItem_1_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[8][1];
			this->m_probabilityPanel_9->m_slotItem_2_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[8][2];
			this->m_probabilityPanel_9->m_slotItem_3_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[8][3];
			this->m_probabilityPanel_9->m_slotItem_4_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[8][4];
			this->m_probabilityPanel_9->m_slotItem_5_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[8][5];
			this->m_probabilityPanel_9->m_slotItem_6_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[8][6];
			this->m_probabilityPanel_9->m_slotItem_7_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[8][7];
			this->m_probabilityPanel_9->m_slotItem_8_tc->SetValue(_item);
			_item.Clear();
		_item << item_percent[8][8];
			this->m_probabilityPanel_9->m_slotItem_9_tc->SetValue(_item);
			_item.Clear();

		if(dproTimes==4){
			//Setup double game probability;
			wxString dpro_tmp_str;
			// X0
			this->doubleProStep->step1 = dpro_tmp[0];
			dpro_tmp_str << dpro_tmp[0];
				cout<< "Get X0 probability setting : "<< dpro_tmp[0] <<endl;
				this->m_doubleProPanel->m_doubleOddsTc[0]->SetValue(dpro_tmp_str);
				dpro_tmp_str.Clear();
			// X2
			this->doubleProStep->step2 = dpro_tmp[1];
			dpro_tmp_str << dpro_tmp[1];
				cout<< "Get X2 probability setting : "<< dpro_tmp[1] <<endl;
				this->m_doubleProPanel->m_doubleOddsTc[1]->SetValue(dpro_tmp_str);
				dpro_tmp_str.Clear();
			// X4
			this->doubleProStep->step2 = dpro_tmp[2];
			dpro_tmp_str << dpro_tmp[2];
				cout<< "Get X4 probability setting : "<< dpro_tmp[2] <<endl;
				this->m_doubleProPanel->m_doubleOddsTc[2]->SetValue(dpro_tmp_str);
				dpro_tmp_str.Clear();
			// X6
			this->doubleProStep->step2 = dpro_tmp[3];
			dpro_tmp_str << dpro_tmp[3];
				cout<< "Get X6 probability setting : "<< dpro_tmp[3] <<endl;
				this->m_doubleProPanel->m_doubleOddsTc[3]->SetValue(dpro_tmp_str);
				dpro_tmp_str.Clear();
		}


	    wxMessageDialog *dial2 = new wxMessageDialog(NULL,L"讀取檔案成功",L"訊息", wxOK | wxICON_INFORMATION);
	    dial2->ShowModal();
	    this->SetTitle(filePath);
	    return;


    }else{
  	  wxMessageDialog *dial = new wxMessageDialog(NULL,L"檔案內容不正確",L"錯誤", wxOK | wxICON_ERROR);
  	  dial->ShowModal();
  	  return;
    }

}

MainFrame::~MainFrame(){

}

bool MainFrame::BetForMax(unsigned long* _bet,unsigned long* _credit,unsigned char _clearBetFirst){
    //SettingDataController* sdctrl = (SettingDataController*)(this->GetTask(tid_SettingDataController,0));
    int target=0;
    int target_2=0;
    unsigned char result=0;
     if(_clearBetFirst==true){
		*_bet = 0;
     }
     if(*_bet  < this->systemSettingData->_MaxBet){
		target = this->systemSettingData->_MaxBet;
		target_2 = this->systemSettingData->_MaxBet - *_bet;
		if(target_2 % this->systemSettingData->_BetUnit != 0){
		   return false;
		}
		result=1;
     }
     if(result==1){
		if( *_credit >= (target - *_bet)){
			*_credit -= (target - *_bet);
			*_bet    += (target - *_bet);
			return true;
		}else{
			return false;
		}
     }
     return false;
}

unsigned int MainFrame::ComputeWagerForLineAndSide(unsigned int wager){
        //SettingDataController* sdctrl = (SettingDataController*)(this->GetTask(tid_SettingDataController,0));
        //MainGameController*    mgctrl = (MainGameController*)this->GetTask(tid_MainGameController,0);
        unsigned int temp;
        unsigned int mod;
        unsigned int index=0;
        if(wager>0){
                temp = wager / (8*this->systemSettingData->_BetUnit);
                mod  = wager % (8*this->systemSettingData->_BetUnit);
                for(unsigned int i=0; i<sizeof(this->mf->line)/sizeof(this->mf->line[0]); i++){
                	this->mf->line[i].bet = temp*this->systemSettingData->_BetUnit;
                	this->mf->sideItem[i].bet = temp*this->systemSettingData->_BetUnit;
                }
                for(unsigned int i=mod; i>0; i-=this->systemSettingData->_BetUnit){
                	this->mf->line[index].bet+=this->systemSettingData->_BetUnit;
                	this->mf->sideItem[index].bet+=this->systemSettingData->_BetUnit;
                        index++;
                        if(index > 7) index %= 8;
                }
        }else{
                for(unsigned int i=0; i<sizeof(this->mf->line)/sizeof(this->mf->line[0]); i++){
                	this->mf->line[i].bet = 0;
                	this->mf->sideItem[i].bet = 0;
                }
        }
        return EXIT_SUCCESS;
}

void MainFrame::setSlot1DefaultValue(void){
	wxString item1Value; item1Value << SCROLL_1_PROBABILITY_CHERRY;
	this->m_probabilityPanel_1->m_slotItem_1_tc->SetValue(item1Value);

	wxString item2Value; item2Value << SCROLL_1_PROBABILITY_ORANGE;
	this->m_probabilityPanel_1->m_slotItem_2_tc->SetValue(item2Value);

	wxString item3Value; item3Value << SCROLL_1_PROBABILITY_MANGO;
	this->m_probabilityPanel_1->m_slotItem_3_tc->SetValue(item3Value);

	wxString item4Value; item4Value << SCROLL_1_PROBABILITY_BELL;
	this->m_probabilityPanel_1->m_slotItem_4_tc->SetValue(item4Value);

	wxString item5Value; item5Value << SCROLL_1_PROBABILITY_WATERMELON;
	this->m_probabilityPanel_1->m_slotItem_5_tc->SetValue(item5Value);

	wxString item6Value; item6Value << SCROLL_1_PROBABILITY_BAR_YELLOW;
	this->m_probabilityPanel_1->m_slotItem_6_tc->SetValue(item6Value);

	wxString item7Value; item7Value << SCROLL_1_PROBABILITY_BAR_RED;
	this->m_probabilityPanel_1->m_slotItem_7_tc->SetValue(item7Value);

	wxString item8Value; item8Value << SCROLL_1_PROBABILITY_BAR_BLUE;
	this->m_probabilityPanel_1->m_slotItem_8_tc->SetValue(item8Value);

	wxString item9Value; item9Value << SCROLL_1_PROBABILITY_WILD;
	this->m_probabilityPanel_1->m_slotItem_9_tc->SetValue(item9Value);
}

void MainFrame::setSlot2DefaultValue(void){
	wxString item1Value; item1Value << SCROLL_2_PROBABILITY_CHERRY;
	this->m_probabilityPanel_2->m_slotItem_1_tc->SetValue(item1Value);

	wxString item2Value; item2Value << SCROLL_2_PROBABILITY_ORANGE;
	this->m_probabilityPanel_2->m_slotItem_2_tc->SetValue(item2Value);

	wxString item3Value; item3Value << SCROLL_2_PROBABILITY_MANGO;
	this->m_probabilityPanel_2->m_slotItem_3_tc->SetValue(item3Value);

	wxString item4Value; item4Value << SCROLL_2_PROBABILITY_BELL;
	this->m_probabilityPanel_2->m_slotItem_4_tc->SetValue(item4Value);

	wxString item5Value; item5Value << SCROLL_2_PROBABILITY_WATERMELON;
	this->m_probabilityPanel_2->m_slotItem_5_tc->SetValue(item5Value);

	wxString item6Value; item6Value << SCROLL_2_PROBABILITY_BAR_YELLOW;
	this->m_probabilityPanel_2->m_slotItem_6_tc->SetValue(item6Value);

	wxString item7Value; item7Value << SCROLL_2_PROBABILITY_BAR_RED;
	this->m_probabilityPanel_2->m_slotItem_7_tc->SetValue(item7Value);

	wxString item8Value; item8Value << SCROLL_2_PROBABILITY_BAR_BLUE;
	this->m_probabilityPanel_2->m_slotItem_8_tc->SetValue(item8Value);

	wxString item9Value; item9Value << SCROLL_2_PROBABILITY_WILD;
	this->m_probabilityPanel_2->m_slotItem_9_tc->SetValue(item9Value);
}

void MainFrame::setSlot3DefaultValue(void){
	wxString item1Value; item1Value << SCROLL_3_PROBABILITY_CHERRY;
	this->m_probabilityPanel_3->m_slotItem_1_tc->SetValue(item1Value);

	wxString item2Value; item2Value << SCROLL_3_PROBABILITY_ORANGE;
	this->m_probabilityPanel_3->m_slotItem_2_tc->SetValue(item2Value);

	wxString item3Value; item3Value << SCROLL_3_PROBABILITY_MANGO;
	this->m_probabilityPanel_3->m_slotItem_3_tc->SetValue(item3Value);

	wxString item4Value; item4Value << SCROLL_3_PROBABILITY_BELL;
	this->m_probabilityPanel_3->m_slotItem_4_tc->SetValue(item4Value);

	wxString item5Value; item5Value << SCROLL_3_PROBABILITY_WATERMELON;
	this->m_probabilityPanel_3->m_slotItem_5_tc->SetValue(item5Value);

	wxString item6Value; item6Value << SCROLL_3_PROBABILITY_BAR_YELLOW;
	this->m_probabilityPanel_3->m_slotItem_6_tc->SetValue(item6Value);

	wxString item7Value; item7Value << SCROLL_3_PROBABILITY_BAR_RED;
	this->m_probabilityPanel_3->m_slotItem_7_tc->SetValue(item7Value);

	wxString item8Value; item8Value << SCROLL_3_PROBABILITY_BAR_BLUE;
	this->m_probabilityPanel_3->m_slotItem_8_tc->SetValue(item8Value);

	wxString item9Value; item9Value << SCROLL_3_PROBABILITY_WILD;
	this->m_probabilityPanel_3->m_slotItem_9_tc->SetValue(item9Value);
}

void MainFrame::setSlot4DefaultValue(void){
	wxString item1Value; item1Value << SCROLL_4_PROBABILITY_CHERRY;
	this->m_probabilityPanel_4->m_slotItem_1_tc->SetValue(item1Value);

	wxString item2Value; item2Value << SCROLL_4_PROBABILITY_ORANGE;
	this->m_probabilityPanel_4->m_slotItem_2_tc->SetValue(item2Value);

	wxString item3Value; item3Value << SCROLL_4_PROBABILITY_MANGO;
	this->m_probabilityPanel_4->m_slotItem_3_tc->SetValue(item3Value);

	wxString item4Value; item4Value << SCROLL_4_PROBABILITY_BELL;
	this->m_probabilityPanel_4->m_slotItem_4_tc->SetValue(item4Value);

	wxString item5Value; item5Value << SCROLL_4_PROBABILITY_WATERMELON;
	this->m_probabilityPanel_4->m_slotItem_5_tc->SetValue(item5Value);

	wxString item6Value; item6Value << SCROLL_4_PROBABILITY_BAR_YELLOW;
	this->m_probabilityPanel_4->m_slotItem_6_tc->SetValue(item6Value);

	wxString item7Value; item7Value << SCROLL_4_PROBABILITY_BAR_RED;
	this->m_probabilityPanel_4->m_slotItem_7_tc->SetValue(item7Value);

	wxString item8Value; item8Value << SCROLL_4_PROBABILITY_BAR_BLUE;
	this->m_probabilityPanel_4->m_slotItem_8_tc->SetValue(item8Value);

	wxString item9Value; item9Value << SCROLL_4_PROBABILITY_WILD;
	this->m_probabilityPanel_4->m_slotItem_9_tc->SetValue(item9Value);
}

void MainFrame::setSlot5DefaultValue(void){
	wxString item1Value; item1Value << SCROLL_5_PROBABILITY_CHERRY;
	this->m_probabilityPanel_5->m_slotItem_1_tc->SetValue(item1Value);

	wxString item2Value; item2Value << SCROLL_5_PROBABILITY_ORANGE;
	this->m_probabilityPanel_5->m_slotItem_2_tc->SetValue(item2Value);

	wxString item3Value; item3Value << SCROLL_5_PROBABILITY_MANGO;
	this->m_probabilityPanel_5->m_slotItem_3_tc->SetValue(item3Value);

	wxString item4Value; item4Value << SCROLL_5_PROBABILITY_BELL;
	this->m_probabilityPanel_5->m_slotItem_4_tc->SetValue(item4Value);

	wxString item5Value; item5Value << SCROLL_5_PROBABILITY_WATERMELON;
	this->m_probabilityPanel_5->m_slotItem_5_tc->SetValue(item5Value);

	wxString item6Value; item6Value << SCROLL_5_PROBABILITY_BAR_YELLOW;
	this->m_probabilityPanel_5->m_slotItem_6_tc->SetValue(item6Value);

	wxString item7Value; item7Value << SCROLL_5_PROBABILITY_BAR_RED;
	this->m_probabilityPanel_5->m_slotItem_7_tc->SetValue(item7Value);

	wxString item8Value; item8Value << SCROLL_5_PROBABILITY_BAR_BLUE;
	this->m_probabilityPanel_5->m_slotItem_8_tc->SetValue(item8Value);

	wxString item9Value; item9Value << SCROLL_5_PROBABILITY_WILD;
	this->m_probabilityPanel_5->m_slotItem_9_tc->SetValue(item9Value);
}

void MainFrame::setSlot6DefaultValue(void){
	wxString item1Value; item1Value << SCROLL_6_PROBABILITY_CHERRY;
	this->m_probabilityPanel_6->m_slotItem_1_tc->SetValue(item1Value);

	wxString item2Value; item2Value << SCROLL_6_PROBABILITY_ORANGE;
	this->m_probabilityPanel_6->m_slotItem_2_tc->SetValue(item2Value);

	wxString item3Value; item3Value << SCROLL_6_PROBABILITY_MANGO;
	this->m_probabilityPanel_6->m_slotItem_3_tc->SetValue(item3Value);

	wxString item4Value; item4Value << SCROLL_6_PROBABILITY_BELL;
	this->m_probabilityPanel_6->m_slotItem_4_tc->SetValue(item4Value);

	wxString item5Value; item5Value << SCROLL_6_PROBABILITY_WATERMELON;
	this->m_probabilityPanel_6->m_slotItem_5_tc->SetValue(item5Value);

	wxString item6Value; item6Value << SCROLL_6_PROBABILITY_BAR_YELLOW;
	this->m_probabilityPanel_6->m_slotItem_6_tc->SetValue(item6Value);

	wxString item7Value; item7Value << SCROLL_6_PROBABILITY_BAR_RED;
	this->m_probabilityPanel_6->m_slotItem_7_tc->SetValue(item7Value);

	wxString item8Value; item8Value << SCROLL_6_PROBABILITY_BAR_BLUE;
	this->m_probabilityPanel_6->m_slotItem_8_tc->SetValue(item8Value);

	wxString item9Value; item9Value << SCROLL_6_PROBABILITY_WILD;
	this->m_probabilityPanel_6->m_slotItem_9_tc->SetValue(item9Value);
}

void MainFrame::setSlot7DefaultValue(void){
	wxString item1Value; item1Value << SCROLL_7_PROBABILITY_CHERRY;
	this->m_probabilityPanel_7->m_slotItem_1_tc->SetValue(item1Value);

	wxString item2Value; item2Value << SCROLL_7_PROBABILITY_ORANGE;
	this->m_probabilityPanel_7->m_slotItem_2_tc->SetValue(item2Value);

	wxString item3Value; item3Value << SCROLL_7_PROBABILITY_MANGO;
	this->m_probabilityPanel_7->m_slotItem_3_tc->SetValue(item3Value);

	wxString item4Value; item4Value << SCROLL_7_PROBABILITY_BELL;
	this->m_probabilityPanel_7->m_slotItem_4_tc->SetValue(item4Value);

	wxString item5Value; item5Value << SCROLL_7_PROBABILITY_WATERMELON;
	this->m_probabilityPanel_7->m_slotItem_5_tc->SetValue(item5Value);

	wxString item6Value; item6Value << SCROLL_7_PROBABILITY_BAR_YELLOW;
	this->m_probabilityPanel_7->m_slotItem_6_tc->SetValue(item6Value);

	wxString item7Value; item7Value << SCROLL_7_PROBABILITY_BAR_RED;
	this->m_probabilityPanel_7->m_slotItem_7_tc->SetValue(item7Value);

	wxString item8Value; item8Value << SCROLL_7_PROBABILITY_BAR_BLUE;
	this->m_probabilityPanel_7->m_slotItem_8_tc->SetValue(item8Value);

	wxString item9Value; item9Value << SCROLL_7_PROBABILITY_WILD;
	this->m_probabilityPanel_7->m_slotItem_9_tc->SetValue(item9Value);
}

void MainFrame::setSlot8DefaultValue(void){
	wxString item1Value; item1Value << SCROLL_8_PROBABILITY_CHERRY;
	this->m_probabilityPanel_8->m_slotItem_1_tc->SetValue(item1Value);

	wxString item2Value; item2Value << SCROLL_8_PROBABILITY_ORANGE;
	this->m_probabilityPanel_8->m_slotItem_2_tc->SetValue(item2Value);

	wxString item3Value; item3Value << SCROLL_8_PROBABILITY_MANGO;
	this->m_probabilityPanel_8->m_slotItem_3_tc->SetValue(item3Value);

	wxString item4Value; item4Value << SCROLL_8_PROBABILITY_BELL;
	this->m_probabilityPanel_8->m_slotItem_4_tc->SetValue(item4Value);

	wxString item5Value; item5Value << SCROLL_8_PROBABILITY_WATERMELON;
	this->m_probabilityPanel_8->m_slotItem_5_tc->SetValue(item5Value);

	wxString item6Value; item6Value << SCROLL_8_PROBABILITY_BAR_YELLOW;
	this->m_probabilityPanel_8->m_slotItem_6_tc->SetValue(item6Value);

	wxString item7Value; item7Value << SCROLL_8_PROBABILITY_BAR_RED;
	this->m_probabilityPanel_8->m_slotItem_7_tc->SetValue(item7Value);

	wxString item8Value; item8Value << SCROLL_8_PROBABILITY_BAR_BLUE;
	this->m_probabilityPanel_8->m_slotItem_8_tc->SetValue(item8Value);

	wxString item9Value; item9Value << SCROLL_8_PROBABILITY_WILD;
	this->m_probabilityPanel_8->m_slotItem_9_tc->SetValue(item9Value);
}

void MainFrame::setSlot9DefaultValue(void){
	wxString item1Value; item1Value << SCROLL_9_PROBABILITY_CHERRY;
	this->m_probabilityPanel_9->m_slotItem_1_tc->SetValue(item1Value);

	wxString item2Value; item2Value << SCROLL_9_PROBABILITY_ORANGE;
	this->m_probabilityPanel_9->m_slotItem_2_tc->SetValue(item2Value);

	wxString item3Value; item3Value << SCROLL_9_PROBABILITY_MANGO;
	this->m_probabilityPanel_9->m_slotItem_3_tc->SetValue(item3Value);

	wxString item4Value; item4Value << SCROLL_9_PROBABILITY_BELL;
	this->m_probabilityPanel_9->m_slotItem_4_tc->SetValue(item4Value);

	wxString item5Value; item5Value << SCROLL_9_PROBABILITY_WATERMELON;
	this->m_probabilityPanel_9->m_slotItem_5_tc->SetValue(item5Value);

	wxString item6Value; item6Value << SCROLL_9_PROBABILITY_BAR_YELLOW;
	this->m_probabilityPanel_9->m_slotItem_6_tc->SetValue(item6Value);

	wxString item7Value; item7Value << SCROLL_9_PROBABILITY_BAR_RED;
	this->m_probabilityPanel_9->m_slotItem_7_tc->SetValue(item7Value);

	wxString item8Value; item8Value << SCROLL_9_PROBABILITY_BAR_BLUE;
	this->m_probabilityPanel_9->m_slotItem_8_tc->SetValue(item8Value);

	wxString item9Value; item9Value << SCROLL_9_PROBABILITY_WILD;
	this->m_probabilityPanel_9->m_slotItem_9_tc->SetValue(item9Value);
}

int MainFrame::setSlot1ProbabilityStep(void){
	//step 1
	slot1Step.step1 = wxAtoi(this->m_probabilityPanel_1->m_slotItem_1_tc->GetValue());
	//step 2
	slot1Step.step2 = wxAtoi(this->m_probabilityPanel_1->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_1->m_slotItem_2_tc->GetValue());
	//step 3
	slot1Step.step3 = wxAtoi(this->m_probabilityPanel_1->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_1->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_1->m_slotItem_3_tc->GetValue());
	//step 4
	slot1Step.step4 = wxAtoi(this->m_probabilityPanel_1->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_1->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_1->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_1->m_slotItem_4_tc->GetValue());
	//step 5
	slot1Step.step5 = wxAtoi(this->m_probabilityPanel_1->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_1->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_1->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_1->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_1->m_slotItem_5_tc->GetValue());
	//step 6
	slot1Step.step6 = wxAtoi(this->m_probabilityPanel_1->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_1->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_1->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_1->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_1->m_slotItem_5_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_1->m_slotItem_6_tc->GetValue());
	//step 7
	slot1Step.step7 = wxAtoi(this->m_probabilityPanel_1->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_7_tc->GetValue());
	//step 8
	slot1Step.step8 = wxAtoi(this->m_probabilityPanel_1->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_8_tc->GetValue());
	//step 9
	slot1Step.step9 = wxAtoi(this->m_probabilityPanel_1->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_8_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_1->m_slotItem_9_tc->GetValue());

	return 0;
}

int MainFrame::setSlot2ProbabilityStep(void){
	//step 1
	slot2Step.step1 = wxAtoi(this->m_probabilityPanel_2->m_slotItem_1_tc->GetValue());
	//step 2
	slot2Step.step2 = wxAtoi(this->m_probabilityPanel_2->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_2->m_slotItem_2_tc->GetValue());
	//step 3
	slot2Step.step3 = wxAtoi(this->m_probabilityPanel_2->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_2->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_2->m_slotItem_3_tc->GetValue());
	//step 4
	slot2Step.step4 = wxAtoi(this->m_probabilityPanel_2->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_2->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_2->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_2->m_slotItem_4_tc->GetValue());
	//step 5
	slot2Step.step5 = wxAtoi(this->m_probabilityPanel_2->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_2->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_2->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_2->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_2->m_slotItem_5_tc->GetValue());
	//step 6
	slot2Step.step6 = wxAtoi(this->m_probabilityPanel_2->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_2->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_2->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_2->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_2->m_slotItem_5_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_2->m_slotItem_6_tc->GetValue());
	//step 7
	slot2Step.step7 = wxAtoi(this->m_probabilityPanel_2->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_7_tc->GetValue());
	//step 8
	slot2Step.step8 = wxAtoi(this->m_probabilityPanel_2->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_8_tc->GetValue());
	//step 9
	slot2Step.step9 = wxAtoi(this->m_probabilityPanel_2->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_8_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_2->m_slotItem_9_tc->GetValue());

	return 0;
}

int MainFrame::setSlot3ProbabilityStep(void){
	//step 1
	slot3Step.step1 = wxAtoi(this->m_probabilityPanel_3->m_slotItem_1_tc->GetValue());
	//step 2
	slot3Step.step2 = wxAtoi(this->m_probabilityPanel_3->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_3->m_slotItem_2_tc->GetValue());
	//step 3
	slot3Step.step3 = wxAtoi(this->m_probabilityPanel_3->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_3->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_3->m_slotItem_3_tc->GetValue());
	//step 4
	slot3Step.step4 = wxAtoi(this->m_probabilityPanel_3->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_3->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_3->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_3->m_slotItem_4_tc->GetValue());
	//step 5
	slot3Step.step5 = wxAtoi(this->m_probabilityPanel_3->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_3->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_3->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_3->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_3->m_slotItem_5_tc->GetValue());
	//step 6
	slot3Step.step6 = wxAtoi(this->m_probabilityPanel_3->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_3->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_3->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_3->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_3->m_slotItem_5_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_3->m_slotItem_6_tc->GetValue());
	//step 7
	slot3Step.step7 = wxAtoi(this->m_probabilityPanel_3->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_7_tc->GetValue());
	//step 8
	slot3Step.step8 = wxAtoi(this->m_probabilityPanel_3->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_8_tc->GetValue());
	//step 9
	slot3Step.step9 = wxAtoi(this->m_probabilityPanel_3->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_8_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_3->m_slotItem_9_tc->GetValue());

	return 0;
}

int MainFrame::setSlot4ProbabilityStep(void){
	//step 1
	slot4Step.step1 = wxAtoi(this->m_probabilityPanel_4->m_slotItem_1_tc->GetValue());
	//step 2
	slot4Step.step2 = wxAtoi(this->m_probabilityPanel_4->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_4->m_slotItem_2_tc->GetValue());
	//step 3
	slot4Step.step3 = wxAtoi(this->m_probabilityPanel_4->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_4->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_4->m_slotItem_3_tc->GetValue());
	//step 4
	slot4Step.step4 = wxAtoi(this->m_probabilityPanel_4->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_4->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_4->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_4->m_slotItem_4_tc->GetValue());
	//step 5
	slot4Step.step5 = wxAtoi(this->m_probabilityPanel_4->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_4->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_4->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_4->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_4->m_slotItem_5_tc->GetValue());
	//step 6
	slot4Step.step6 = wxAtoi(this->m_probabilityPanel_4->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_4->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_4->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_4->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_4->m_slotItem_5_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_4->m_slotItem_6_tc->GetValue());
	//step 7
	slot4Step.step7 = wxAtoi(this->m_probabilityPanel_4->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_7_tc->GetValue());
	//step 8
	slot4Step.step8 = wxAtoi(this->m_probabilityPanel_4->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_8_tc->GetValue());
	//step 9
	slot4Step.step9 = wxAtoi(this->m_probabilityPanel_4->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_8_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_4->m_slotItem_9_tc->GetValue());

	return 0;
}

int MainFrame::setSlot5ProbabilityStep(void){
	//step 1
	slot5Step.step1 = wxAtoi(this->m_probabilityPanel_5->m_slotItem_1_tc->GetValue());
	//step 2
	slot5Step.step2 = wxAtoi(this->m_probabilityPanel_5->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_5->m_slotItem_2_tc->GetValue());
	//step 3
	slot5Step.step3 = wxAtoi(this->m_probabilityPanel_5->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_5->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_5->m_slotItem_3_tc->GetValue());
	//step 4
	slot5Step.step4 = wxAtoi(this->m_probabilityPanel_5->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_5->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_5->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_5->m_slotItem_4_tc->GetValue());
	//step 5
	slot5Step.step5 = wxAtoi(this->m_probabilityPanel_5->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_5->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_5->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_5->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_5->m_slotItem_5_tc->GetValue());
	//step 6
	slot5Step.step6 = wxAtoi(this->m_probabilityPanel_5->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_5->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_5->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_5->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_5->m_slotItem_5_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_5->m_slotItem_6_tc->GetValue());
	//step 7
	slot5Step.step7 = wxAtoi(this->m_probabilityPanel_5->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_7_tc->GetValue());
	//step 8
	slot5Step.step8 = wxAtoi(this->m_probabilityPanel_5->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_8_tc->GetValue());
	//step 9
	slot5Step.step9 = wxAtoi(this->m_probabilityPanel_5->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_8_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_5->m_slotItem_9_tc->GetValue());

	return 0;
}

int MainFrame::setSlot6ProbabilityStep(void){
	//step 1
	slot6Step.step1 = wxAtoi(this->m_probabilityPanel_6->m_slotItem_1_tc->GetValue());
	//step 2
	slot6Step.step2 = wxAtoi(this->m_probabilityPanel_6->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_6->m_slotItem_2_tc->GetValue());
	//step 3
	slot6Step.step3 = wxAtoi(this->m_probabilityPanel_6->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_6->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_6->m_slotItem_3_tc->GetValue());
	//step 4
	slot6Step.step4 = wxAtoi(this->m_probabilityPanel_6->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_6->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_6->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_6->m_slotItem_4_tc->GetValue());
	//step 5
	slot6Step.step5 = wxAtoi(this->m_probabilityPanel_6->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_6->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_6->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_6->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_6->m_slotItem_5_tc->GetValue());
	//step 6
	slot6Step.step6 = wxAtoi(this->m_probabilityPanel_6->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_6->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_6->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_6->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_6->m_slotItem_5_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_6->m_slotItem_6_tc->GetValue());
	//step 7
	slot6Step.step7 = wxAtoi(this->m_probabilityPanel_6->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_7_tc->GetValue());
	//step 8
	slot6Step.step8 = wxAtoi(this->m_probabilityPanel_6->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_8_tc->GetValue());
	//step 9
	slot6Step.step9 = wxAtoi(this->m_probabilityPanel_6->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_8_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_6->m_slotItem_9_tc->GetValue());

	return 0;
}

int MainFrame::setSlot7ProbabilityStep(void){
	//step 1
	slot7Step.step1 = wxAtoi(this->m_probabilityPanel_7->m_slotItem_1_tc->GetValue());
	//step 2
	slot7Step.step2 = wxAtoi(this->m_probabilityPanel_7->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_7->m_slotItem_2_tc->GetValue());
	//step 3
	slot7Step.step3 = wxAtoi(this->m_probabilityPanel_7->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_7->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_7->m_slotItem_3_tc->GetValue());
	//step 4
	slot7Step.step4 = wxAtoi(this->m_probabilityPanel_7->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_7->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_7->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_7->m_slotItem_4_tc->GetValue());
	//step 5
	slot7Step.step5 = wxAtoi(this->m_probabilityPanel_7->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_7->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_7->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_7->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_7->m_slotItem_5_tc->GetValue());
	//step 6
	slot7Step.step6 = wxAtoi(this->m_probabilityPanel_7->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_7->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_7->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_7->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_7->m_slotItem_5_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_7->m_slotItem_6_tc->GetValue());
	//step 7
	slot7Step.step7 = wxAtoi(this->m_probabilityPanel_7->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_7_tc->GetValue());
	//step 8
	slot7Step.step8 = wxAtoi(this->m_probabilityPanel_7->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_8_tc->GetValue());
	//step 9
	slot7Step.step9 = wxAtoi(this->m_probabilityPanel_7->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_8_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_7->m_slotItem_9_tc->GetValue());

	return 0;
}

int MainFrame::setSlot8ProbabilityStep(void){
	//step 1
	slot8Step.step1 = wxAtoi(this->m_probabilityPanel_8->m_slotItem_1_tc->GetValue());
	//step 2
	slot8Step.step2 = wxAtoi(this->m_probabilityPanel_8->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_8->m_slotItem_2_tc->GetValue());
	//step 3
	slot8Step.step3 = wxAtoi(this->m_probabilityPanel_8->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_8->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_8->m_slotItem_3_tc->GetValue());
	//step 4
	slot8Step.step4 = wxAtoi(this->m_probabilityPanel_8->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_8->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_8->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_8->m_slotItem_4_tc->GetValue());
	//step 5
	slot8Step.step5 = wxAtoi(this->m_probabilityPanel_8->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_8->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_8->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_8->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_8->m_slotItem_5_tc->GetValue());
	//step 6
	slot8Step.step6 = wxAtoi(this->m_probabilityPanel_8->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_8->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_8->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_8->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_8->m_slotItem_5_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_8->m_slotItem_6_tc->GetValue());
	//step 7
	slot8Step.step7 = wxAtoi(this->m_probabilityPanel_8->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_7_tc->GetValue());
	//step 8
	slot8Step.step8 = wxAtoi(this->m_probabilityPanel_8->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_8_tc->GetValue());
	//step 9
	slot8Step.step9 = wxAtoi(this->m_probabilityPanel_8->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_8_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_8->m_slotItem_9_tc->GetValue());

	return 0;
}

int MainFrame::setSlot9ProbabilityStep(void){
	//step 1
	slot9Step.step1 = wxAtoi(this->m_probabilityPanel_9->m_slotItem_1_tc->GetValue());
	//stop 2
	slot9Step.step2 = wxAtoi(this->m_probabilityPanel_9->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_9->m_slotItem_2_tc->GetValue());
	//step 3
	slot9Step.step3 = wxAtoi(this->m_probabilityPanel_9->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_9->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_9->m_slotItem_3_tc->GetValue());
	//step 4
	slot9Step.step4 = wxAtoi(this->m_probabilityPanel_9->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_9->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_9->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_9->m_slotItem_4_tc->GetValue());
	//step 5
	slot9Step.step5 = wxAtoi(this->m_probabilityPanel_9->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_9->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_9->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_9->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_9->m_slotItem_5_tc->GetValue());
	//step 6
	slot9Step.step6 = wxAtoi(this->m_probabilityPanel_9->m_slotItem_1_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_9->m_slotItem_2_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_9->m_slotItem_3_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_9->m_slotItem_4_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_9->m_slotItem_5_tc->GetValue()) +
    		          wxAtoi(this->m_probabilityPanel_9->m_slotItem_6_tc->GetValue());
	//step 7
	slot9Step.step7 = wxAtoi(this->m_probabilityPanel_9->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_7_tc->GetValue());
	//step 8
	slot9Step.step8 = wxAtoi(this->m_probabilityPanel_9->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_8_tc->GetValue());
	//step 9
	slot9Step.step9 = wxAtoi(this->m_probabilityPanel_9->m_slotItem_1_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_2_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_3_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_4_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_5_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_6_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_7_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_8_tc->GetValue()) +
					  wxAtoi(this->m_probabilityPanel_9->m_slotItem_9_tc->GetValue());

	return 0;
}

int MainFrame::setAutoKeyInOutDefault(void){
	//Set 1
	wxString set_1_start; set_1_start << AutoKeyInOutSetting[0][0];
	this->m_keyInOutPanel->m_keyIn_tc_1->SetValue(set_1_start);
	wxString set_1_end; set_1_end << AutoKeyInOutSetting[0][1];
	this->m_keyInOutPanel->m_keyOut_tc_1->SetValue(set_1_end);
	wxString set_1_percent; set_1_percent << AutoKeyInOutSetting[0][2];
	this->m_keyInOutPanel->m_percent_tc_1->SetValue(set_1_percent);

	//Set 2
	wxString set_2_start; set_2_start << AutoKeyInOutSetting[1][0];
	this->m_keyInOutPanel->m_keyIn_tc_2->SetValue(set_2_start);
	wxString set_2_end; set_2_end << AutoKeyInOutSetting[1][1];
	this->m_keyInOutPanel->m_keyOut_tc_2->SetValue(set_2_end);
	wxString set_2_percent; set_2_percent << AutoKeyInOutSetting[1][2];
	this->m_keyInOutPanel->m_percent_tc_2->SetValue(set_2_percent);

	//Set 3
	wxString set_3_start; set_3_start << AutoKeyInOutSetting[2][0];
	this->m_keyInOutPanel->m_keyIn_tc_3->SetValue(set_3_start);
	wxString set_3_end; set_3_end << AutoKeyInOutSetting[2][1];
	this->m_keyInOutPanel->m_keyOut_tc_3->SetValue(set_3_end);
	wxString set_3_percent; set_3_percent << AutoKeyInOutSetting[2][2];
	this->m_keyInOutPanel->m_percent_tc_3->SetValue(set_3_percent);

	//Set 4
	wxString set_4_start; set_4_start << AutoKeyInOutSetting[3][0];
	this->m_keyInOutPanel->m_keyIn_tc_4->SetValue(set_4_start);
	wxString set_4_end; set_4_end << AutoKeyInOutSetting[3][1];
	this->m_keyInOutPanel->m_keyOut_tc_4->SetValue(set_4_end);
	wxString set_4_percent; set_4_percent << AutoKeyInOutSetting[3][2];
	this->m_keyInOutPanel->m_percent_tc_4->SetValue(set_4_percent);

	//Set 5
	wxString set_5_start; set_5_start << AutoKeyInOutSetting[4][0];
	this->m_keyInOutPanel->m_keyIn_tc_5->SetValue(set_5_start);
	wxString set_5_end; set_5_end << AutoKeyInOutSetting[4][1];
	this->m_keyInOutPanel->m_keyOut_tc_5->SetValue(set_5_end);
	wxString set_5_percent; set_5_percent << AutoKeyInOutSetting[4][2];
	this->m_keyInOutPanel->m_percent_tc_5->SetValue(set_5_percent);

	//Set 6
	wxString set_6_start; set_6_start << AutoKeyInOutSetting[5][0];
	this->m_keyInOutPanel->m_keyIn_tc_6->SetValue(set_6_start);
	wxString set_6_end; set_6_end << AutoKeyInOutSetting[5][1];
	this->m_keyInOutPanel->m_keyOut_tc_6->SetValue(set_6_end);
	wxString set_6_percent; set_6_percent << AutoKeyInOutSetting[5][2];
	this->m_keyInOutPanel->m_percent_tc_6->SetValue(set_6_percent);

	//Set 7
	wxString set_7_start; set_7_start << AutoKeyInOutSetting[6][0];
	this->m_keyInOutPanel->m_keyIn_tc_7->SetValue(set_7_start);
	wxString set_7_end; set_7_end << AutoKeyInOutSetting[6][1];
	this->m_keyInOutPanel->m_keyOut_tc_7->SetValue(set_7_end);
	wxString set_7_percent; set_7_percent << AutoKeyInOutSetting[6][2];
	this->m_keyInOutPanel->m_percent_tc_7->SetValue(set_7_percent);

	//Set 8
	wxString set_8_start; set_8_start << AutoKeyInOutSetting[7][0];
	this->m_keyInOutPanel->m_keyIn_tc_8->SetValue(set_8_start);
	wxString set_8_end; set_8_end << AutoKeyInOutSetting[7][1];
	this->m_keyInOutPanel->m_keyOut_tc_8->SetValue(set_8_end);
	wxString set_8_percent; set_8_percent << AutoKeyInOutSetting[7][2];
	this->m_keyInOutPanel->m_percent_tc_8->SetValue(set_8_percent);

	//Set 9
	wxString set_9_start; set_9_start << AutoKeyInOutSetting[8][0];
	this->m_keyInOutPanel->m_keyIn_tc_9->SetValue(set_9_start);
	wxString set_9_end; set_9_end << AutoKeyInOutSetting[8][1];
	this->m_keyInOutPanel->m_keyOut_tc_9->SetValue(set_9_end);
	wxString set_9_percent; set_9_percent << AutoKeyInOutSetting[8][2];
	this->m_keyInOutPanel->m_percent_tc_9->SetValue(set_9_percent);

	//Set 10
	wxString set_10_start; set_10_start << AutoKeyInOutSetting[9][0];
	this->m_keyInOutPanel->m_keyIn_tc_10->SetValue(set_10_start);
	wxString set_10_end; set_10_end << AutoKeyInOutSetting[9][1];
	this->m_keyInOutPanel->m_keyOut_tc_10->SetValue(set_10_end);
	wxString set_10_percent; set_10_percent << AutoKeyInOutSetting[9][2];
	this->m_keyInOutPanel->m_percent_tc_10->SetValue(set_10_percent);

	return 0;
}

int MainFrame::setAutoKeyInOutValue(void){
	//Set 1
	AutoKeyInOutSetting[0][0] = wxAtoi(this->m_keyInOutPanel->m_keyIn_tc_1->GetValue());
	AutoKeyInOutSetting[0][1] = wxAtoi(this->m_keyInOutPanel->m_keyOut_tc_1->GetValue());
	AutoKeyInOutSetting[0][2] = wxAtoi(this->m_keyInOutPanel->m_percent_tc_1->GetValue());

	//Set 2
	AutoKeyInOutSetting[1][0] = wxAtoi(this->m_keyInOutPanel->m_keyIn_tc_2->GetValue());
	AutoKeyInOutSetting[1][1] = wxAtoi(this->m_keyInOutPanel->m_keyOut_tc_2->GetValue());
	AutoKeyInOutSetting[1][2] = wxAtoi(this->m_keyInOutPanel->m_percent_tc_2->GetValue());

	//Set 3
	AutoKeyInOutSetting[2][0] = wxAtoi(this->m_keyInOutPanel->m_keyIn_tc_3->GetValue());
	AutoKeyInOutSetting[2][1] = wxAtoi(this->m_keyInOutPanel->m_keyOut_tc_3->GetValue());
	AutoKeyInOutSetting[2][2] = wxAtoi(this->m_keyInOutPanel->m_percent_tc_3->GetValue());

	//Set 4
	AutoKeyInOutSetting[3][0] = wxAtoi(this->m_keyInOutPanel->m_keyIn_tc_4->GetValue());
	AutoKeyInOutSetting[3][1] = wxAtoi(this->m_keyInOutPanel->m_keyOut_tc_4->GetValue());
	AutoKeyInOutSetting[3][2] = wxAtoi(this->m_keyInOutPanel->m_percent_tc_4->GetValue());

	//Set 5
	AutoKeyInOutSetting[4][0] = wxAtoi(this->m_keyInOutPanel->m_keyIn_tc_5->GetValue());
	AutoKeyInOutSetting[4][1] = wxAtoi(this->m_keyInOutPanel->m_keyOut_tc_5->GetValue());
	AutoKeyInOutSetting[4][2] = wxAtoi(this->m_keyInOutPanel->m_percent_tc_5->GetValue());

	//Set 6
	AutoKeyInOutSetting[5][0] = wxAtoi(this->m_keyInOutPanel->m_keyIn_tc_6->GetValue());
	AutoKeyInOutSetting[5][1] = wxAtoi(this->m_keyInOutPanel->m_keyOut_tc_6->GetValue());
	AutoKeyInOutSetting[5][2] = wxAtoi(this->m_keyInOutPanel->m_percent_tc_6->GetValue());

	//Set 7
	AutoKeyInOutSetting[6][0] = wxAtoi(this->m_keyInOutPanel->m_keyIn_tc_7->GetValue());
	AutoKeyInOutSetting[6][1] = wxAtoi(this->m_keyInOutPanel->m_keyOut_tc_7->GetValue());
	AutoKeyInOutSetting[6][2] = wxAtoi(this->m_keyInOutPanel->m_percent_tc_7->GetValue());

	//Set 8
	AutoKeyInOutSetting[7][0] = wxAtoi(this->m_keyInOutPanel->m_keyIn_tc_8->GetValue());
	AutoKeyInOutSetting[7][1] = wxAtoi(this->m_keyInOutPanel->m_keyOut_tc_8->GetValue());
	AutoKeyInOutSetting[7][2] = wxAtoi(this->m_keyInOutPanel->m_percent_tc_8->GetValue());

	//Set 9
	AutoKeyInOutSetting[8][0] = wxAtoi(this->m_keyInOutPanel->m_keyIn_tc_9->GetValue());
	AutoKeyInOutSetting[8][1] = wxAtoi(this->m_keyInOutPanel->m_keyOut_tc_9->GetValue());
	AutoKeyInOutSetting[8][2] = wxAtoi(this->m_keyInOutPanel->m_percent_tc_9->GetValue());

	//Set 10
	AutoKeyInOutSetting[9][0] = wxAtoi(this->m_keyInOutPanel->m_keyIn_tc_10->GetValue());
	AutoKeyInOutSetting[9][1] = wxAtoi(this->m_keyInOutPanel->m_keyOut_tc_10->GetValue());
	AutoKeyInOutSetting[9][2] = wxAtoi(this->m_keyInOutPanel->m_percent_tc_10->GetValue());

	return 0;
}

int MainFrame::setDoubleStepDefault(void){

	wxString step1; step1 <<this->doubleProStep->step1;
	this->m_doubleProPanel->m_doubleOddsTc[0]->SetValue(step1);

	wxString step2; step2 <<this->doubleProStep->step2;
	this->m_doubleProPanel->m_doubleOddsTc[1]->SetValue(step2);

	wxString step3; step3 <<this->doubleProStep->step3;
	this->m_doubleProPanel->m_doubleOddsTc[2]->SetValue(step3);

	wxString step4; step4 <<this->doubleProStep->step4;
	this->m_doubleProPanel->m_doubleOddsTc[3]->SetValue(step4);

	return 0;
}

int MainFrame::setDoubleStepValue(void){

	this->doubleProStep->step1 = wxAtoi(this->m_doubleProPanel->m_doubleOddsTc[0]->GetValue());

	this->doubleProStep->step2 = wxAtoi(this->m_doubleProPanel->m_doubleOddsTc[1]->GetValue());

	this->doubleProStep->step3 = wxAtoi(this->m_doubleProPanel->m_doubleOddsTc[2]->GetValue());

	this->doubleProStep->step4 = wxAtoi(this->m_doubleProPanel->m_doubleOddsTc[3]->GetValue());

	return 0;
}

int MainFrame::setDoubleContinueDefault(void){

	wxString tmp;

	for(unsigned int idx=0; idx<sizeof(this->doubleContinue->probability)/sizeof(this->doubleContinue->probability[0]); idx++){
		tmp.clear();
		tmp << this->doubleContinue->probability[idx];
		this->m_doubleContinuePanel->m_doubleContinueTc[idx]->SetValue(tmp);
	}

	return 0;
}

int MainFrame::setDoubleContinueValue(void){

	for(unsigned int idx=0; idx<sizeof(this->doubleContinue->probability)/sizeof(this->doubleContinue->probability[0]); idx++){
		this->doubleContinue->probability[idx] = wxAtoi(this->m_doubleContinuePanel->m_doubleContinueTc[idx]->GetValue());
	}

	return 0;
}

bool MainFrame::autoKeyOutCheck(unsigned long _credit){
	bool result;
	unsigned long w1;
	unsigned long auto_money;
	float  coin;

	auto_money = _credit;

	result = false;
	coin   = (float)auto_money /(float)(this->systemSettingData->_CoinValue);
	w1 = mtRandom.getRandomLong(1000);

	if (coin > AutoKeyInOutSetting[0][0] && coin < AutoKeyInOutSetting[0][1]) {
		if (w1 < AutoKeyInOutSetting[0][2])
		{
			result = true;
		}
	} else if (coin >= AutoKeyInOutSetting[1][0] && coin < AutoKeyInOutSetting[1][1]) {
		if (w1 < AutoKeyInOutSetting[1][2])
		{
			result = true;
		}
	} else if (coin >= AutoKeyInOutSetting[2][0] && coin < AutoKeyInOutSetting[2][1]) {
		if (w1 < AutoKeyInOutSetting[2][2])
		{
			result = true;
		}
	} else if (coin >= AutoKeyInOutSetting[3][0] && coin < AutoKeyInOutSetting[3][1]) {
		if (w1 < AutoKeyInOutSetting[3][2])
		{
			result = true;
		}
	} else if (coin >= AutoKeyInOutSetting[4][0] && coin < AutoKeyInOutSetting[4][1]) {
		if (w1 < AutoKeyInOutSetting[4][2])
		{
			result = true;
		}
	} else if (coin >= AutoKeyInOutSetting[5][0] && coin < AutoKeyInOutSetting[5][1]) {
		if (w1 < AutoKeyInOutSetting[5][2])
		{
			result = true;
		}
	} else if (coin >= AutoKeyInOutSetting[6][0] && coin < AutoKeyInOutSetting[6][1]) {
		if (w1 < AutoKeyInOutSetting[6][2])
		{
			result = true;
		}
	} else if (coin >= AutoKeyInOutSetting[7][0] && coin < AutoKeyInOutSetting[7][1]) {
		if (w1 < AutoKeyInOutSetting[7][2])
		{
			result = true;
		}
	} else if (coin >= AutoKeyInOutSetting[8][0] && coin < AutoKeyInOutSetting[8][1]) {
		if (w1 < AutoKeyInOutSetting[8][2])
		{
			result = true;
		}
	} else if (coin >= AutoKeyInOutSetting[9][0] && coin < AutoKeyInOutSetting[9][1]) {
		if (w1 < AutoKeyInOutSetting[9][2])
		{
			result = true;
		}
	} else if (coin >= AutoKeyInOutSetting[9][2]) {
		if (w1 <= 999)//100%
		{
			result = true;
		}
	}

	return result;
}

void MainFrame::setKeyInMaxDefaultValue(void){
	wxString keyInMax; keyInMax << keyInMaxValue;
	this->m_settingValuePanel->m_maxKeyIn_tc->SetValue(keyInMax);
}

void MainFrame::setKeyInMaxValue(void){
	keyInMaxValue = wxAtoi(this->m_settingValuePanel->m_maxKeyIn_tc->GetValue());
}

void MainFrame::updateResultPanel(void){
	  //Total KeyIn coins & KeyOut coins
	  wxString total_keyin_coins; total_keyin_coins << this->totalRec->key_in;
	  this->m_resultPanel->m_totalKeyIn_tc->SetValue(total_keyin_coins);

	  wxString total_keyout_coins; total_keyout_coins << this->totalRec->key_out;
	  this->m_resultPanel->m_totalKeyOut_tc->SetValue(total_keyout_coins);

	  wxString keyinKeyOutPercent; keyinKeyOutPercent << 100 * (float)this->totalRec->key_out/(float)this->totalRec->key_in;
	  keyinKeyOutPercent += " %";
	  this->m_resultPanel->m_keyInOutPercent_tc->SetValue(keyinKeyOutPercent);

	  //Total play scores & Total win scores
	  wxString total_play_scores; total_play_scores << this->totalRec->bet;
	  this->m_resultPanel->m_totalPlayScore_tc->SetValue(total_play_scores);

	  wxString total_win_scores; total_win_scores << this->totalRec->won;
	  this->m_resultPanel->m_totalWinScore_tc->SetValue(total_win_scores);

	  wxString playWinScoresPercent; playWinScoresPercent << 100 * (float)this->totalRec->won/(float)this->totalRec->bet;
	  playWinScoresPercent += " %";
	  this->m_resultPanel->m_PlayWinScorePercent_tc->SetValue(playWinScoresPercent);

	  //Total played times & Total win times
	  wxString total_play_times; total_play_times << this->totalRec->played;
	  this->m_resultPanel->m_totalPlayTimes_tc->SetValue(total_play_times);

	  wxString total_win_times; total_win_times << this->totalRec->hit;
	  this->m_resultPanel->m_totalWinTimes_tc->SetValue(total_win_times);

	  wxString playedHitPercent; playedHitPercent << 100 * (float)this->totalRec->hit / (float)this->totalRec->played;
	  playedHitPercent += " %";
	  this->m_resultPanel->m_PlayWinTimesPercent_tc->SetValue(playedHitPercent);

	  //Double Game total played scores & total won scores
	  wxString total_dplay_scores; total_dplay_scores << this->totalRec->DoubleTotalPlayedScores;
	  this->m_resultPanel->m_doubleTotalPlayScore_tc->SetValue(total_dplay_scores);

	  wxString total_dwin_scores; total_dwin_scores << this->totalRec->DoubleTotalWonScores;
	  this->m_resultPanel->m_doubleTotalWinScore_tc->SetValue(total_dwin_scores);

	  if(this->totalRec->DoubleTotalPlayedScores > 0){
		  wxString DplayWinScoresPercent; DplayWinScoresPercent << 100 * (float)this->totalRec->DoubleTotalWonScores / (float)this->totalRec->DoubleTotalPlayedScores;
		  playedHitPercent += " %";
		  this->m_resultPanel->m_doublePlayWinScorePercent_tc->SetValue(DplayWinScoresPercent);
	  }else{
		  this->m_resultPanel->m_doublePlayWinScorePercent_tc->SetValue("0");
	  }

	  //Double Game total played times & total won times
	  wxString total_dplay_times; total_dplay_times << this->totalRec->DoubleTotalPlayedTimes;
	  this->m_resultPanel->m_doubleTotalPlayTimes_tc->SetValue(total_dplay_times);

	  wxString total_dwin_times; total_dwin_times << this->totalRec->DoubleTotalWonTimes;
	  this->m_resultPanel->m_doubleTotalWinTimes_tc->SetValue(total_dwin_times);

	  if(this->totalRec->DoubleTotalPlayedTimes > 0){
		  wxString DplayWinTimesPercent; DplayWinTimesPercent << 100 * (float)this->totalRec->DoubleTotalWonTimes/(float)this->totalRec->DoubleTotalPlayedTimes;
		  playWinScoresPercent += " %";
		  this->m_resultPanel->m_doublePlayWinTimesPercent_tc->SetValue(DplayWinTimesPercent);
	  }else{
		  this->m_resultPanel->m_doublePlayWinTimesPercent_tc->SetValue("0");
	  }

	  //Main game over max win times
	  wxString mainGameOver; mainGameOver << this->totalRec->sysover;
	  this->m_resultPanel->m_mainGameOverMaxWinTimes_tc->SetValue(mainGameOver);

	  //Double game over max win times
	  wxString doubleGameOver; doubleGameOver << this->totalRec->doubleover;
	  this->m_resultPanel->m_doubleGameOverMaxWinTimes_tc->SetValue(doubleGameOver);

	  //Double game max consecutive pass times
	  wxString dconsecutive; dconsecutive << this->totalRec->DoubleMaxConsecutivePassTimes;
	  this->m_resultPanel->m_doubleGameMaxConsecutivePassTimes_tc->SetValue(dconsecutive);

}

unsigned int MainFrame::getDoubleGameAward(void){
	unsigned int award_type = DEF_DAWARD_TYPE_X0;
	unsigned int random = this->mtRandom.getRandomLong(_double_award_random_base);

	unsigned int d_step1,d_step2,d_step3,d_step4;
	d_step1 = doubleProStep->step1;
	d_step2 = doubleProStep->step1 + doubleProStep->step2;
	d_step3 = doubleProStep->step1 + doubleProStep->step2 + doubleProStep->step3;
	d_step4 = doubleProStep->step1 + doubleProStep->step2 + doubleProStep->step3 + doubleProStep->step4;

	if( random < d_step1 ){
		award_type = DEF_DAWARD_TYPE_X0;
	}else if( random >= d_step1 && random < d_step2 ){
		award_type = DEF_DAWARD_TYPE_X2;
	}else if( random >= d_step2 && random < d_step3 ){
		award_type = DEF_DAWARD_TYPE_X4;
	}else if( random >= d_step3 && random < d_step4 ){
		award_type = DEF_DAWARD_TYPE_X6;
	}

	return award_type;
}

void MainFrame::printFrameItemRecord(void){
	const char* itemName[10] = {
		"Unknow",
		"cherry",
		"Orange",
		"Mango",
		"Bell",
		"WaterMelon",
		"Bar yellow",
		"Bar Red",
		"Bar Blue",
		"Wild"
	};

	cout<< "----------------------- Frame Item Record -----------------------" << endl;
	for(unsigned int i=0; i<sizeof(this->mf->singleFrame)/sizeof(this->mf->singleFrame[0]);i++){
		cout<< "----- Frame " << i+1 << " Item Times -----" << endl;
		for(unsigned int k=0; k<sizeof(this->mf->singleFrame[i].GetItemRecord)/sizeof(this->mf->singleFrame[i].GetItemRecord[0]);k++){
			  cout<< setw(10) << itemName[k] << " : " << setw(8) << this->mf->singleFrame[i].GetItemRecord[k] <<endl;
		  }
	}
}

void MainFrame::printFullAwardRecord(void){
	  //Print Full Frame Award Record
	  cout<< "--------------------- FULL Frame Award Record ---------------------" << endl;
	  cout<< "FULL ALL FRUIT Times       : " << this->mf->FullFrameAwardRecord[FULL_AWARD_ALL_FRUIT-1][9] << endl;
	  cout<< "FULL ANY_BAR Times         : " << this->mf->FullFrameAwardRecord[FULL_AWARD_ANY_BAR-1][9]   << endl;
	  cout<< "FULL ORANGE Times          : " << this->mf->FullFrameAwardRecord[FULL_AWARD_ORANGE-1][9]    << endl;
	  cout<< "FULL MANGO Times           : " << this->mf->FullFrameAwardRecord[FULL_AWARD_MANGO-1][9]     << endl;
	  cout<< "FULL BELL Times            : " << this->mf->FullFrameAwardRecord[FULL_AWARD_BELL-1][9]      << endl;
	  cout<< "FULL WATERMELON Times      : " << this->mf->FullFrameAwardRecord[FULL_AWARD_WATERMELON-1][9]<< endl;
	  cout<< "FULL BAR YELLOW Times      : " << this->mf->FullFrameAwardRecord[FULL_AWARD_BAR_YELLOW-1][9]<< endl;
	  cout<< "FULL CHERRY Times          : " << this->mf->FullFrameAwardRecord[FULL_AWARD_CHERRY-1][9]    << endl;
	  cout<< "FULL BAR RED Times         : " << this->mf->FullFrameAwardRecord[FULL_AWARD_BAR_RED-1][9]   << endl;
	  cout<< "FULL BAR BLUE Times        : " << this->mf->FullFrameAwardRecord[FULL_AWARD_BAR_BLUE-1][9]  << endl;
	  cout<< "WILD X3 Times              : " << this->mf->FullFrameAwardRecord[FULL_AWARD_WILD-1][3]      << endl;
	  cout<< "WILD X4 Times              : " << this->mf->FullFrameAwardRecord[FULL_AWARD_WILD-1][4]      << endl;
	  cout<< "WILD X5 Times              : " << this->mf->FullFrameAwardRecord[FULL_AWARD_WILD-1][5]      << endl;
	  cout<< "WILD X6 Times              : " << this->mf->FullFrameAwardRecord[FULL_AWARD_WILD-1][6]      << endl;
	  cout<< "WILD X7 Times              : " << this->mf->FullFrameAwardRecord[FULL_AWARD_WILD-1][7]      << endl;
	  cout<< "WILD X8 Times              : " << this->mf->FullFrameAwardRecord[FULL_AWARD_WILD-1][8]      << endl;
	  cout<< "FULL WILD Times            : " << this->mf->FullFrameAwardRecord[FULL_AWARD_WILD-1][9]      << endl;
}

void MainFrame::printLineAwardRecord(void){
	const char* awardName[13] = {
		"None",
		"One cherry",
		"Two cherry",
		"Cherry Straight",
		"Orange Straight",
		"Mix Bar Straight",
		"Mango Straight",
		"Bell Straight",
		"WaterMelon Straight",
		"Bar yellow Straight",
		"Bar Red Straight",
		"Bar Blue Straight",
		"Wild Straight"
	};

	cout<< "------------------------ Line Award Record ------------------------" << endl;
	for(unsigned int i=0;i<sizeof(this->mf->line)/sizeof(this->mf->line[0]);i++){
		cout<< "----- Line " << i+1 << " Award Times -----" << endl;
		for(unsigned int j=0; j<sizeof(this->mf->line[i].AwardRecord)/sizeof(this->mf->line[i].AwardRecord[0]);j++){
			cout<< setw(20) <<awardName[j] << " : " << setw(8) << this->mf->line[i].AwardRecord[j] << " " << endl;;
		}
	}

}

void MainFrame::printDoubleGameAwardRecord(void){
	const char* dAwardName[4] = {
			"X0 Times : ",
			"X2 Times : ",
			"X4 Times : ",
			"X6 Times : "
	};

	cout<< "------------------- Double Up Game Award Record -------------------" << endl;
	cout<< dAwardName[0]  << setw(10) << this->dGameAwardRec->X0 << endl;
	cout<< dAwardName[1]  << setw(10) << this->dGameAwardRec->X2 << endl;
	cout<< dAwardName[2]  << setw(10) << this->dGameAwardRec->X4 << endl;
	cout<< dAwardName[3]  << setw(10) << this->dGameAwardRec->X6 << endl;

}

void MainFrame::AfterSelectCoinSet(wxCommandEvent& event){
	//cout<< "AfterSelectCoinSet : " << this->m_settingValuePanel->m_coinSetCB->GetValue() << endl;
	this->systemSettingData->_CoinValue = wxAtoi(this->m_settingValuePanel->m_coinSetCB->GetValue());
	cout<< "Now CoinSet is : " << this->systemSettingData->_CoinValue << endl;
}

void MainFrame::AfterSelectMaxBet(wxCommandEvent& event){
	//cout<< "AfterSelectMaxBet : " << this->m_settingValuePanel->m_maxBetCB->GetValue() << endl;
	this->systemSettingData->_MaxBet = wxAtoi(this->m_settingValuePanel->m_maxBetCB->GetValue());
	cout<< "Now MaxBet is : " << this->systemSettingData->_MaxBet << endl;
}

void MainFrame::AfterSelectMainGameMaxWin(wxCommandEvent& event){
	this->systemSettingData->_CreditUpLimit = wxAtoi(this->m_settingValuePanel->m_mainGameMaxWinCB->GetValue());
	cout<< "Now Main Game Max Win Coin is : " << this->systemSettingData->_CreditUpLimit << endl;
}

void MainFrame::AfterSelectDoubleGameMaxWin(wxCommandEvent& event){
	this->systemSettingData->_DDWNOfOverMaxWin = wxAtoi(this->m_settingValuePanel->m_doubleGameMaxWinCB->GetValue());
	cout<< "Now Double Game Max Win Coin is : " << this->systemSettingData->_DDWNOfOverMaxWin << endl;
}

void MainFrame::AfterSelectRunDoubleGame(wxCommandEvent& event){
	if(this->m_dRunTimeSettingPanel->m_runDoubleGameChkBox->IsChecked()==true){
		//
		this->m_dRunTimeSettingPanel->m_runToDeadChkBox->Enable();
		this->doubleRunTime->_enable = 1;
	}else{
		//
		this->m_dRunTimeSettingPanel->m_runToDeadChkBox->Disable();
		this->doubleRunTime->_enable = 0;
	}
}

void MainFrame::AfterSelectRunToDead(wxCommandEvent& event){
	//
	if(this->m_dRunTimeSettingPanel->m_runToDeadChkBox->IsChecked()==true){
		this->doubleRunTime->_runToDead = 1;
	}else{
		this->doubleRunTime->_runToDead = 0;
	}
}
