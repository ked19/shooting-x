#include "main.h"
//#include <thread>
//#include "test_sdk.h"

/*
void GenDilateKernel(Mtx &mK)
{
	Vect2D<unsigned> dim = mK.GetDim();
	MyAssert(dim.m_x == dim.m_y);

	unsigned r = dim.m_x / 2;
	unsigned r2 = r * r;

	for (unsigned y = 0; y < dim.m_y; y++) {
		int dY = (int)y - r;
		unsigned dY2 = (unsigned)(dY * dY);
		for (unsigned x = 0; x < dim.m_x; x++) {
			int dX = (int)x - r;
			unsigned dX2 = (unsigned)(dX * dX);
			unsigned dis = dX2 + dY2;

			mK.CellRef(x, y) = (dis < r2) ? 1.F : 0;
		}
	}
}*/

void CallSys()
{
	while (1) {
		if (bNp) {
			system("notepad s.txt");
			//cout << "a" << endl;
			gMutex.lock();
			bNp = false;
			gMutex.unlock();
		} else {}
	}
}

void main()
{
	//test_CSDK();

	//*******************************************
	// template
	//*******************************************
	//GenRegionMsk("mask_pre.bmp", "template.bmp", true);
	//GenScoreRegion("template_SR.bmp", "template_mask.bmp", "template_score.bmp", true);

	//*******************************************
	// target
	//*******************************************
	/*
	string fromN = "template.bmp";
	string toN = "fnt_0.bmp";
	string fromPgm = fromN + ".pgm";
	string toPgm   = toN   + ".pgm";
	MyImg *pImgFP = imgIO.Read(fromN);
	MyImg *pImgTP = imgIO.Read(toN);
	Mtx *pMtxFP = pImgFP->ConvertGray()->GetMtx(0);
	Mtx *pMtxTP = pImgTP->ConvertGray()->GetMtx(0);
	imgIO.Write(fromPgm, MyImg(*pMtxFP));
	imgIO.Write(toPgm,   MyImg(*pMtxTP));

	string fInvN = toPgm;
	string tInvN = fromPgm;
	Mtx mtxTInv(2, 3);
	ComputeTransform(mtxTInv, fInvN, tInvN, true);

	string from2N = "scale_template_SR.bmp";
	string to2N = toN;
	MyImg *pImgFrom = imgIO.Read(from2N);
	MyImg *pImgTo 	= imgIO.Read(to2N);
	Mtx *pMtxFrom = pImgFrom->ConvertGray()->GetMtx(0);
	Mtx *pMtxTo   = pImgTo->ConvertGray()->GetMtx(0);
	Vect2D<unsigned> dimTo = pMtxTo->GetDim();
	Mtx mtxWarp(dimTo.m_x, dimTo.m_y);
	Warp(mtxWarp, *pMtxFrom, *pMtxTo, mtxTInv, true);
	*/

	
	//*******************************************
	// window
	//*******************************************
	thread mThread(CallSys);

	ifstream ifs;
	ifs.open("version.txt");
	if (ifs.fail()) {
		MyAssert(0);
	} else {}
	
	string sLine;
	getline(ifs, sLine);
	string title = "Shooting calculation " + sLine;
	
	getline(ifs, sLine);
	bool bSetDefault = (sLine.compare("set default") == 0) ?
		true : false;

	fl_message_icon()->hide();

	pMain_win = make_window();
	pMain_win->show();
	pMain_win->label(title.c_str());
	if (!bSetDefault) {
		pIP0_txtIn->value("");
		pIP1_txtIn->value("");
		pIP2_txtIn->value("");
		pIP3_txtIn->value("");
		pAccount_txtIn->value("");
		pPasswd_txtIn->value("");
	} else {}

	pTarget_win->show();

	while(Fl::wait(0.05)) {
		if (!Fl::first_window()) {
			break;
		} else {}
	}
	//Fl::run();
	CloseConnect();	
	mThread.detach();
	

	/*
	DATA thrd_sub = 10.F;
	DATA thrd_bck = 30.F;
	unsigned kerlLen = 10;

	string bckN = "bck_0.pgm";
	string fntN = "fnt_0.pgm";

	MyImg *pImgBck = imgIO.Read(bckN);
	MyImg *pImgFnt = imgIO.Read(fntN);
	Mtx *pMtxBck = pImgBck->ConvertGray()->GetMtx(0);
	Mtx *pMtxFnt = pImgFnt->ConvertGray()->GetMtx(0);
	Vect2D<unsigned> dim = pMtxFnt->GetDim();

	Mtx mtxFMin(dim.m_x, dim.m_y);
	//Mtx mtxBMin(dim.m_x, dim.m_y);
	Mtx mtxKerl(kerlLen, kerlLen);
	GenDilateKernel(mtxKerl);
	mtxOp.morphGray.Gen(mtxFMin, *pMtxFnt, mtxKerl, false);
	//mtxOp.morphGray.Gen(mtxBMin, *pMtxBck, mtxKerl, false);

	Mtx mtxSub(dim.m_x, dim.m_y);
	mtxSub.CopyFrom(mtxFMin);
	mtxOp.sub.Gen(mtxSub, *pMtxBck);

	Mtx mtxThrd(dim.m_x, dim.m_y);
	for (unsigned y = 0; y < dim.m_y; y++) {
		for (unsigned x = 0; x < dim.m_x; x++) {
			mtxThrd.CellRef(x, y) = 
				(mtxSub.CellVal(x, y) >= thrd_sub && pMtxBck->CellVal(x, y) <= thrd_bck) ?
				255.F : 0;
		} // x
	} // y
	imgIO.Write("thrd.bmp", MyImg(mtxThrd));

	
	//*******************************************
	// region labeling
	//*******************************************
	static vector<unsigned> rRec;
	Mtx mtxReg(dim.m_x, dim.m_y);
	mtxOp.regionLabel.Gen(mtxReg, mtxThrd, rRec);
	
	static vector<Vect2D<unsigned>> locC;
	static vector<unsigned> area;
	locC.resize(rRec.size());
	area.resize(rRec.size());
	for (unsigned i = 0; i < rRec.size(); i++) {
		locC[i].m_x = 0;
		locC[i].m_y = 0;
		area[i] = 0;
	}
	for (unsigned y = 0; y < dim.m_y; y++) {
		for (unsigned x = 0; x < dim.m_x; x++) {
			unsigned r = (unsigned)mtxReg.CellVal(x, y);
			if (r != 0) {		
				locC[r].m_x += x;
				locC[r].m_y += y;
				area[r]++;
			} else {}
		} // x
	} // y

	for (unsigned i = 1; i < locC.size(); i++) {
		if (rRec[i] == i) {
			cout << "i: " << i << endl;
			MyAssert(area[i] > 0);
			locC[i].m_x /= area[i];
			locC[i].m_y /= area[i];
			cout << "(" << locC[i].m_x << "," << dim.m_y - 1 - locC[i].m_y << ")" << endl;

			//sSum += (unsigned)mtxWarp.CellVal(locC[i].m_x, locC[i].m_y);
		} else {}
	}
	*/
	/*
	MyImg *pImg = imgIO.Read("sub.bmp");
	Mtx *pMtx = pImg->GetMtx(0);
	mtxOp.binThrd.Gen(*pMtx, 10.F, true);
	mtxOp.mul.Gen(*pMtx, 255.F);
	imgIO.Write("bin.bmp", MyImg(*pMtx));

	Vect2D<unsigned> dim = pMtx->GetDim();
	Mtx mtxB(dim.m_x, dim.m_y);
	mtxOp.erose.Gen(mtxB, *pMtx, 2);
	mtxOp.mul.Gen(mtxB, 255.F);
	imgIO.Write("bin2.bmp", MyImg(mtxB));

	Mtx mtxReg(dim.m_x, dim.m_y);
	vector<unsigned> rRec;
	mtxOp.regionLabel.Gen(mtxReg, *pMtx, rRec);

	vector<unsigned> area(rRec.size());
	vector<unsigned> xSum(rRec.size());
	vector<unsigned> ySum(rRec.size());
	for (unsigned i = 0; i < area.size(); i++) {
		area[i] = 0;
		xSum[i] = 0;
		ySum[i] = 0;
	}
	for (unsigned y = 0; y < dim.m_y; y++) {
		for (unsigned x = 0; x < dim.m_x; x++) {
			unsigned v = (unsigned)mtxReg.CellVal(x, y);
			area[v]++;
			xSum[v] += x;
			ySum[v] += y;
		}
	}
	for (unsigned i = 0; i < area.size(); i++) {
		if (area[i] <= 0) {
			continue;
		} else {}

		xSum[i] /= area[i];
		ySum[i] /= area[i];
		cout << "area:" << area[i] << " "
			 << "x:" << xSum[i] << " " 
			 << "y:" << ySum[i] << endl;
	}
	*/
}