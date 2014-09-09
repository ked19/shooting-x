#include "main_winApp.h"

bool bDebug = true;

HANDLE mainHandle = 0; 

const unsigned bufImg_num = 3;
unsigned bufImgFnt_no = 0;
unsigned bufImgBck_idx = 0;
//Mtx apMtxF

//Fl_Text_Buffer txtBuf;
//bool bBindBuf = false;

bool bTx = false;
unsigned char *pTxBuf = 0;
unsigned txW = 0;
unsigned txH = 0;
unsigned txLen = 0;
bool bInitGL = false;
Layer *pLyrIn = 0;

bool bNp = false;
mutex gMutex;

void WINAPI GetRawDataCallback( DWORD UserParam, DWORD dwdataType, BYTE* buf, DWORD len )
{
	// TYPE
	// 1. MPEG4
	// 2. AUDIO PCM
	// 3. AUDIO PCM must with time stamp
	// 4. MJPEG
	// 5. H.264
	// 6. AUDIO G711 mu-law
	// 7. Audio G711 a law
	if(dwdataType==1 || dwdataType==4 || dwdataType==5){
	}
	//cout << len ;
}

bool IsID()
{
	//pAccount_txtIn->fresh();
	string s = pInID_txtIn->value();
	return !s.empty();
}
void WINAPI GetImage_callback(DWORD UserParam, LPVOID b2, LPBITMAPINFO bmpinfo, LPBYTE buf, DWORD len, DWORD dwWidth, DWORD dwHeight )
{	
	if (txW != dwWidth || txH != dwHeight) {
		if (txW < dwWidth || txH < dwHeight) {
			delete pLyrIn;
			pLyrIn = new Layer(dwWidth, dwHeight, 3);
		} else {}
	} else {}

	if (!pTxBuf || len > txLen) {
		delete []pTxBuf;
		pTxBuf = new unsigned char[len]; 
	} else {}
	if (txW != dwWidth || txH != dwHeight) {
		txW = dwWidth;
		txH = dwHeight;
		txLen = len;
		bInitGL = false;
	} else {}
	memcpy((void *)pTxBuf, (void *)buf, len);
	//bTx = true;

	pTarget_win->redraw();
	unsigned skipNum = 15;
	static unsigned sNo = 0;
	if (sNo < skipNum) {
		sNo++;
		return;
	} else {
		sNo = 0;
	}

	cout << "len:" << len << endl;
	cout << "dwWidth:" << dwWidth << endl;
	cout << "dwHeight: " << dwHeight << endl;

	static char aNo[10];
	MyAssert(bufImg_num >= 1);
	unsigned maxFntNo = bufImg_num;
	string imgName;
	if (bufImgFnt_no < maxFntNo) {
		imgName = string("fnt_") + itoa(bufImgFnt_no, aNo, 10);
		bufImgFnt_no++;
	} else if (bufImgFnt_no == maxFntNo) {
		imgName = string("bck_") + itoa(bufImgBck_idx, aNo, 10);
		bufImgBck_idx = (bufImgBck_idx + 1) % bufImg_num;

		//bool bID = IsID();

		if (bufImgBck_idx == 0) {
			pCalculate_litBttn->value(1);
			//if (!bID) {
				//txtBuf.append("No ID\n");
			//	fl_alert("No ID");
			//} else {}
		} else {}
		if (pCalculate_litBttn->value() == 1) {
			//if (bID) {
				pCalculate_litBttn->activate();
			//} else {}
		} else {}
		/*
		if (bufImgBck_idx == 0) {
			pCalculate_litBttn->value(1);	
			if (bID) {
				pCalculate_litBttn->activate();
			} else if ({}
		} else if (pCalculate_litBttn->value() == 1) {
			if (bID) {
				pCalculate_litBttn->activate();
			} else {}
		} else {}
		*/
	} else {
		MyAssert(0);
	}
	imgName += ".pgm"; //".bmp";	

	//static Layer lyrIn(dwWidth, dwHeight, 3);
	unsigned count = 0;
	for (unsigned y = 0; y < dwHeight; y++) {
		unsigned yy = dwHeight - 1 - y;
		for (unsigned x = 0; x < dwWidth; x++) {
			//for (unsigned c = 0; c < 3; c++) {
			pLyrIn->CellRef(x, yy, 2) = (DATA)buf[count++];
			pLyrIn->CellRef(x, yy, 1) = (DATA)buf[count++];
			pLyrIn->CellRef(x, yy, 0) = (DATA)buf[count++];
			//} // c
		} // x
	} // y
	Mtx *pMtxIn = MyImg(*pLyrIn).ConvertGray()->GetMtx(0);	
	imgIO.Write(imgName, MyImg(*pMtxIn));

	cout << "*******************************" << endl;
}

void CloseConnect()
{
	if (bDebug) {
		cout << "CloseConnect" << endl;
	} else {}

	if (mainHandle) {
		KStop(mainHandle);
		KStopStreaming(mainHandle);
		KDisconnect(mainHandle);
		KCloseInterface(mainHandle);
		mainHandle = 0;
	} else {}
}

void ResetCompute()
{
	bufImgFnt_no = 0;
	bufImgBck_idx = 0;
	pCalculate_litBttn->value(0);
	pCalculate_litBttn->deactivate();
}

void RunConnect(Fl_Button *w, void *v) 
{
	//if (!bBindBuf) {
		//pOutput_txtDisp->buffer(txtBuf);
	//} else {}

	//txtBuf.remove(0, txtBuf.length());
	//txtBuf.append("Connecting..\n");

	//**********************************************
	// configuration
	//**********************************************
	MEDIA_CONNECTION_CONFIG2 *pMcc = 0;
	if (!pMcc) {
		pMcc = new MEDIA_CONNECTION_CONFIG2;
	} else {}

	string ipS0 = pIP0_txtIn->value();	
	string ipS1 = pIP1_txtIn->value();
	string ipS2 = pIP2_txtIn->value();
	string ipS3 = pIP3_txtIn->value();
	string ipS = ipS0 + "." + ipS1 + "." +ipS2 + "." + ipS3;
	string portS = pPort_txtIn->value();	int portNo = atoi(portS.c_str());
	string accountS = pAccount_txtIn->value();
	string passwdS = pPasswd_txtIn->value();

	if (bDebug) {
		cout << "ipS: " << ipS << endl
			 << "portNo: " << portNo << endl
			 << "accountS: " << accountS << endl
			 << "passwdS: " << passwdS << endl
			 << endl;
	} else {}

	memset((void*)pMcc, 0, sizeof(MEDIA_CONNECTION_CONFIG2));
	strcpy(pMcc->UniCastIP, ipS.c_str());
	sprintf(pMcc->MultiCastIP, "%d.%d.%d.%d\0", 228,5, 6,1 );
	pMcc->ContactType = CONTACT_TYPE_UNICAST_WOC_PREVIEW;

	pMcc->RegisterPort = 6000;
	pMcc->ControlPort = 6001;
	pMcc->StreamingPort = 6002;
	pMcc->HTTPPort = portNo;
	pMcc->ConnectTimeOut = 1;
	pMcc->MultiCastPort = 5000 ;
	pMcc->RTSPPort = 7070 ;
	strcpy(pMcc->UserID, accountS.c_str());
	strcpy(pMcc->Password, passwdS.c_str());
	pMcc->SearchPortC2S = 6005;
	pMcc->SearchPortS2C = 6006;

	pMcc->TCPVideoStreamID = 0;
	pMcc->RTPVideoTrackNumber = 1;
	pMcc->RTPAudioTrackNumber = 0;

	//**********************************************
	// conection
	//**********************************************
	CloseConnect();

	mainHandle = KOpenInterface();
	MEDIA_PORT_INFO portInfo;	
	bool bb = KGetPortInfoByHTTP(mainHandle, &portInfo, pMcc->UniCastIP, pMcc->HTTPPort, pMcc->UserID, pMcc->Password);		
	if (!bb) {
		//txtBuf.append("Connection fail\n");
		fl_alert("Connection fail");
		CloseConnect();
		return;
	} else {}

	DWORD UserParam = 0;	
	if (mainHandle) {
		if (pMcc->ContactType != CONTACT_TYPE_PLAYBACK &&
			pMcc->ContactType != CONTACT_TYPE_PLAYBACK_AVI) {
			KSetTCPType(mainHandle, 0);
		} else {}

		bool bMc2 = KSetMediaConfig2(mainHandle, pMcc);
		MyAssert(bMc2);

		ResetCompute();
		KSetRawDataCallback(mainHandle, UserParam, GetRawDataCallback);
		KSetImageCallback3 (mainHandle, UserParam, GetImage_callback);

		if (KConnect(mainHandle)) {
			if (KStartStreaming(mainHandle)) {
				KEnableDisplayTime(mainHandle, true);
				KPlay(mainHandle);
			} else {
				//txtBuf.append("Connection fail\n");
				fl_alert("Connection fail");
				CloseConnect();
				return;
			} 
		} else {
			//txtBuf.append("Connection fail\n");
			fl_alert("Connect fail");
			CloseConnect();
			return;
		} 
	} else {
		//if (bDebug) {
			MyAssert(0);
		//} else {}
	} // mainHandle

	pClose_litBttn->value(1);
	
	bTx = true;
	pClose_litBttn->activate();
	pConnect_bttn->deactivate();
	//pCalculate_litBttn->activate();

	//txtBuf.append("Connection ok\n");
}

void ScaleDraw(Mtx &mtxOut, Mtx &mtxIn) 
{
	Vect2D<unsigned> dimOut = mtxOut.GetDim();
	Vect2D<unsigned> dimIn  = mtxIn.GetDim();

	DATA xR = (DATA)dimOut.m_x / dimIn.m_x;
	DATA yR = (DATA)dimOut.m_y / dimIn.m_y;
	DATA sR = (xR < yR) ? xR : yR;
	if (sR >= 1.F) {
		sR = 1.F;
	} else {}

	unsigned xLen = (unsigned)(dimIn.m_x * sR);
	unsigned yLen = (unsigned)(dimIn.m_y * sR);
	unsigned xOff = (dimOut.m_x - xLen) / 2;
	unsigned yOff = (dimOut.m_y - yLen) / 2;

	mtxOp.one.Gen(mtxOut);
	mtxOp.mul.Gen(mtxOut, 100.F);
	Mtx mtxScl(mtxOut, xOff, yOff, xLen, yLen);
	mtxOp.scaleDim.Gen(mtxScl, mtxIn);
}
void ComputeScore(Fl_Light_Button *w, void *v)
{
	DATA thrd_sub = 5.F;
	DATA thrd_bck = 30.F;
	unsigned kerlLen = 10;

	if (pClose_litBttn->value() == 0) {
		//txtBuf.append("No enough data\n");	
		fl_alert("No enough data");
		return;
	} else {}

	bool bID = IsID();
	if (!bID) {
		fl_alert("Please insert your ID");
		return;
	} else {}

	//txtBuf.append("Calculating..\n");

	CloseConnect();
	pClose_litBttn->value(0);

	bufImgFnt_no = 0;
	bufImgBck_idx = 0;
	string fromN = "template.pgm";
	string toN   = "fnt_0.pgm";

	//*******************************************
	// compute trnasform
	//*******************************************
	string fInvN = toN;
	string tInvN = fromN;
	Mtx mtxTInv(2, 3);
	ComputeTransform(mtxTInv, fInvN, tInvN, true);

	//*******************************************
	// warp
	//*******************************************
	string srN = "template_SR.pgm";
	MyImg *pImgSR = imgIO.Read(srN);
	MyImg *pImgTo = imgIO.Read(toN);
	Mtx *pMtxSR = pImgSR->ConvertGray()->GetMtx(0);
	Mtx *pMtxTo = pImgTo->ConvertGray()->GetMtx(0);
	Vect2D<unsigned> dimTo = pMtxTo->GetDim();
	Mtx mtxWarp(dimTo.m_x, dimTo.m_y);
	Warp(mtxWarp, *pMtxSR, *pMtxTo, mtxTInv, true);

	Mtx mtxMsk(dimTo.m_x, dimTo.m_y);
	mtxMsk.CopyFrom(mtxWarp);
	mtxOp.binThrd.Gen(mtxMsk, 0.5F, true);
	//mtxOp.mul.Gen(mtxMsk, 255.F);

	Mtx mtxTMsk(dimTo.m_x, dimTo.m_y);
	mtxOp.erose.Gen(mtxTMsk, mtxMsk, 10);				
	mtxOp.cellX.Gen(mtxWarp, mtxWarp, mtxTMsk);
	imgIO.Write("warp2.bmp", MyImg(mtxWarp));
	
	//*******************************************
	// get bullet hole
	//*******************************************
	string bckN = "bck_0.pgm";
	MyImg *pImgBck = imgIO.Read(bckN);
	Mtx *pMtxBck = pImgBck->ConvertGray()->GetMtx(0);
	Mtx *pMtxFnt = pMtxTo;

	/*
	Mtx mtxFMin(dimTo.m_x, dimTo.m_y);
	Mtx mtxKerl(kerlLen, kerlLen);
	GenDilateKernel(mtxKerl);
	mtxOp.morphGray.Gen(mtxFMin, *pMtxFnt, mtxKerl, true);
	imgIO.Write("b0.bmp", MyImg(mtxFMin));
	//Mtx mtxFMin(*pMtxFnt);
	*/

	Mtx mtxG(8, 8);
	mtxOp.Gauss.Gen(mtxG, 1.8F, 1.8F, true);
	mtxOp.conv.Gen(*pMtxBck, mtxG);
	mtxOp.conv.Gen(*pMtxFnt, mtxG);
	//Mtx mtxFMin(dimTo.m_x, dimTo.m_y);
	//mtxFMin.CopyFrom(*pMtxFnt);
	imgIO.Write("b0.bmp", MyImg(*pMtxFnt));
	imgIO.Write("b1.bmp", MyImg(*pMtxBck));
	

	Mtx mtxSub(dimTo.m_x, dimTo.m_y);
	mtxSub.CopyFrom(*pMtxFnt);
	mtxOp.sub.Gen(mtxSub, *pMtxBck);
	//mtxOp.binThrd.Gen(mtxSub, 0.5F, true);
	//imgIO.Write("b2.bmp", MyImg(mtxSub));

	for (unsigned y = 0; y < dimTo.m_y; y++) {
		for (unsigned x = 0; x < dimTo.m_x; x++) {
			mtxSub.CellRef(x, y) = 
				(mtxSub.CellVal(x, y) >= thrd_sub &&
				 pMtxBck->CellVal(x, y) <= thrd_bck) ?
				255.F : 0;
		} // x
	} // y
	imgIO.Write("bullet.bmp", MyImg(mtxSub));

	/*
	mtxOp.dilate.Gen(mtxFMin, mtxSub, 3);
	mtxSub.CopyFrom(mtxFMin);
	//mtxOp.erose.Gen(mtxFMin, mtxSub, 2);
	mtxOp.mul.Gen(mtxSub, 255.F);
	imgIO.Write("b2.bmp", MyImg(mtxSub));
	*/

	//*******************************************
	// compute score
	//*******************************************
	
	static vector<unsigned> rRec;
	Mtx mtxReg(dimTo.m_x, dimTo.m_y);
	mtxOp.regionLabel.Gen(mtxReg, mtxSub, rRec);
	
	static vector<Vect2D<unsigned>> locC;
	static vector<unsigned> area;
	locC.resize(rRec.size());
	area.resize(rRec.size());
	for (unsigned i = 0; i < rRec.size(); i++) {
		locC[i].m_x = 0;
		locC[i].m_y = 0;
		area[i] = 0;
	}
	for (unsigned y = 0; y < dimTo.m_y; y++) {
		for (unsigned x = 0; x < dimTo.m_x; x++) {
			unsigned r = (unsigned)mtxReg.CellVal(x, y);
			if (r != 0) {
				locC[r].m_x += x;
				locC[r].m_y += y;
				area[r]++;
			} else {}
		} // x
	} // y

	if (bDebug) {
		cout << "bullet position:" << endl;
	} else {}
	unsigned sSum = 0;
	static vector<unsigned> vS;
	vS.clear();
	for (unsigned i = 1; i < locC.size(); i++) {
		if (rRec[i] == i) {
			//if(area[i] < 3) {
			//	continue;
			//} else {}

			locC[i].m_x /= area[i];
			locC[i].m_y /= area[i];

			unsigned s = (unsigned)mtxWarp.CellVal(locC[i].m_x, locC[i].m_y);
			sSum += s;
			vS.push_back(s);

			cout << "(" << locC[i].m_x 
				 << "," << dimTo.m_y - 1 - locC[i].m_y << ")" 
				 << ": " << s << endl;
		} else {}
	}

	cout << "score: " << sSum << endl;
	

	/*
	char aScore[10];
	unsigned score = 0;
	for (unsigned y = 0; y < dimTo.m_y; y++) {
		for (unsigned x = 0; x < dimTo.m_x; x++) {
			score += (unsigned)(pMtxTo->CellVal(x, y) * mtxWarp.CellVal(x, y));
		}
	}
	string sScore = string("Score: ") + itoa(score, aScore, 10) + string("\n");
	txtBuf.append(sScore.c_str());
	*/

	ResetCompute();
	WriteData("db.txt", pInID_txtIn->value(), sSum);

	//txtBuf.append("Calculation ok\n");

	static char aS[10];
	//txtBuf.append("Score: ");
	string sBullet = "Score: ";
	bool bB = false;
	for (unsigned i = 0; i < vS.size(); i++) {
		//txtBuf.append(itoa(vS[i], aS, 10));
		//txtBuf.append(" ");
		if (vS[i] > 0) {
			sBullet += itoa(vS[i], aS, 10) + string(" ");
			bB = true;
		} else {}
	}
	//txtBuf.append("\n");
	if (!bB) {
		sBullet += "0";
	} else {}
	sBullet += "\n";

	//string sScore = string("Sum: ") + itoa(sSum, aS, 10) + string("\n");
	//txtBuf.append(sScore.c_str());
	string sScore = string("Sum: ") + itoa(sSum, aS, 10);

	string sOut = string("Calculation result\n\n") + sBullet + sScore;
	fl_message(sOut.c_str());

	pConnect_bttn->activate();
	pClose_litBttn->deactivate();
}

void Disconnect(Fl_Light_Button *w, void *v)
{
	ResetCompute();

	CloseConnect();
	pClose_litBttn->value(0);
	pClose_litBttn->deactivate();
	pConnect_bttn->activate();
	bTx = false;
}

void SearchID(Fl_Button *w, void *v)
{
	//if (!bBindBuf) {
		//pOutput_txtDisp->buffer(txtBuf);
	//} else {}

	SearchData("s.txt", "db.txt", pSearchID_txtIn->value());

	//txtBuf.remove(0, txtBuf.length());
	//txtBuf.append("Results:\n");

	ifstream ifs;
	ifs.open("s.txt");
	if (ifs.fail()) {
		return;
	} else {}

	string sLine;
	//string sFile;
	//sFile.clear();
	unsigned dataNum = 0;
	while (!ifs.eof()) {
		getline(ifs, sLine);
		if (!sLine.empty()) {
			//txtBuf.append(sLine.c_str());
			//txtBuf.append("\n");
			//sFile += sLine + "\n";
			dataNum++;
		} else {}
	}
	if (dataNum <= 1) { //== 0) {
		fl_alert("Not exist");
		//txtBuf.append("Not exist\n");
	} else {
		//system("notepad s.txt");
		//fl_message(sFile.c_str());
		gMutex.lock();
		bNp = true;
		gMutex.unlock();
	}
}

//***********************************************
// MyGlWindow
//***********************************************
MyGlWindow::MyGlWindow(int x, int y, int w, int h, const char *l)
	: Fl_Gl_Window(x, y, w, h, l)
{}

int MyGlWindow::handle(int event)
{
	//redraw();
	return 0;
}

void MyGlWindow::draw()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(0, w(), 0, h());
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glViewport(0, 0, w(), h());

	glClearColor(0.9f, 0.9f, 0.9f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//if (pClose_litBttn->value() == 0) {
	if (!bTx) {
		glFlush();
		return;
	} else {}

	//*******************************************
	// draw
	//*******************************************

	static unsigned xOff = 0; 
	static unsigned yOff = 0;
	static unsigned xLen = 0;
	static unsigned yLen = 0;

	static GLuint txName;
	//static bool bInit = false;
	if (!bInitGL) {
		bInitGL = true;

		glEnable(GL_TEXTURE_2D);
		glGenTextures(1, &txName);
		glBindTexture(GL_TEXTURE_2D, txName);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //GL_NEAREST);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, txW, txH, 0, GL_BGR, GL_UNSIGNED_BYTE, pTxBuf);		

		DATA xR = (DATA)w() / txW;
		DATA yR = (DATA)h() / txH;
		DATA mR = (xR < yR) ? xR : yR;
		xLen = (unsigned)(txW * mR);
		yLen = (unsigned)(txH * mR);
		xOff = (w() - xLen) / 2;
		yOff = (h() - yLen) / 2;
	} else {		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, txName);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, txW, txH, GL_BGR, GL_UNSIGNED_BYTE, pTxBuf);		
	}

	glViewport(xOff, yOff, xLen, yLen);

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txName);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 1.f);			glVertex2f(-1.f, -1.f);			
		glTexCoord2f(1.f, 1.f);			glVertex2f(1.f, -1.f);			
		glTexCoord2f(1.f, 0);			glVertex2f(1.f, 1.f);		
		glTexCoord2f(0, 0);				glVertex2f(-1.f, 1.f);			
	glEnd();

	glFlush();
	glDisable(GL_TEXTURE_2D);
}

/*
MyFlImg::MyFlImg(int x, int y, int w, int h, const char *l)
	: Fl_Group(x, y, w, h, l)
{}

void MyFlImg::draw()
{
	if (!pDrawBuf) {
		return;
	} else {}

	fl_draw_image_mono(pDrawBuf, x(), y(), w(), h(), 1, 0);
}


int MyFlImg::handle(int event)
{
	return 0;
}
*/
