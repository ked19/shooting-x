#include "algo_target.h"

void RunTarget() 
{}

// A x transF = B
void RunRANSAC(Mtx &mtxTransf, vector<Vect2D<DATA>> &matchFrom, vector<Vect2D<DATA>> &matchTo,
	unsigned tryNum, unsigned smpNum, DATA nearDis, bool bDebug) 
{
	if (bDebug) {
		cout << "RunRANSAC" << endl;
	} else {}

	Vect2D<unsigned> dimTransf = mtxTransf.GetDim();
	MyAssert(matchFrom.size() == matchTo.size());
	MyAssert(dimTransf.m_x == 2 && dimTransf.m_y == 3);

	static Mtx mtxT_x(1, 3);				static Mtx mtxT_y(1, 3);
	static Mtx mtxA(3, smpNum);
	static Mtx mtxB_x(1, smpNum); 			static Mtx mtxB_y(1, smpNum);
	static Mtx mtxAA(3, 3);
	static Mtx mtxAB(1, 3);
	static unsigned aIdx[3];
	static Mtx mtxFrom(3, 1);
	static Mtx mtxTo_x(1, 1);				static Mtx mtxTo_y(1, 1);

	DATA nDis2 = nearDis * nearDis;
	unsigned maxInNum = 0;
	if (bDebug) {
		cout << "tryNo:" << endl;
	} else {}
	for (unsigned t = 0; t < tryNum; t++) {
		if (bDebug) {
			PrintCount(t, tryNum - 1);
		} else {}

		//***************************************
		// sample
		//***************************************
		for (unsigned s = 0; s < smpNum; s++) {
			unsigned rndNo = (unsigned)(myMath.Rnd() * (matchFrom.size() - 1));
			mtxA.CellRef(0, s) = matchFrom[rndNo].m_x;
			mtxA.CellRef(1, s) = matchFrom[rndNo].m_y;
			mtxA.CellRef(2, s) = 1.F;

			mtxB_x.CellRef(0, s) = matchTo[rndNo].m_x;
			mtxB_y.CellRef(0, s) = matchTo[rndNo].m_y;
		}

		//***************************************
		// solve
		//***************************************
		int errX = mtxOp.leastSquare.Gen(mtxT_x, mtxA, mtxB_x, mtxAA, mtxAB, aIdx);
		if (errX != 0) {
			continue;
		} else {}

		int errY = mtxOp.leastSquare.Gen(mtxT_y, mtxA, mtxB_y, mtxAA, mtxAB, aIdx);
		if (errY != 0) {
			continue;
		} else {}

		if (bDebug) {
			cout << "mtxA:"   << endl;		mtxOp.out << mtxA;
			cout << "mtxB_x:" << endl;		mtxOp.out << mtxB_x;
			cout << "mtxT_x:" << endl;		mtxOp.out << mtxT_x;
			cout << "mtxB_y:" << endl;		mtxOp.out << mtxB_y;
			cout << "mtxT_y:" << endl;		mtxOp.out << mtxT_y;
		} else {}

		//***************************************
		// count inliners
		//***************************************
		unsigned inNum = 0;
		for (unsigned i = 0; i < matchFrom.size(); i++) {
			mtxFrom.CellRef(0, 0) = matchFrom[i].m_x;
			mtxFrom.CellRef(1, 0) = matchFrom[i].m_y;
			mtxFrom.CellRef(2, 0) = 1.F;

			mtxOp.mul.Gen(mtxTo_x, mtxFrom, mtxT_x);
			mtxOp.mul.Gen(mtxTo_y, mtxFrom, mtxT_y);

			DATA dX = mtxTo_x.CellVal(0, 0) - matchTo[i].m_x;
			DATA dY = mtxTo_y.CellVal(0, 0) - matchTo[i].m_y;
			DATA dis = dX * dX + dY * dY;
			if (dis < nDis2) {
				inNum++;
			} else {}
		}
		if (bDebug) {
			cout << "inNum:" << inNum << endl;
		} else {}

		if (inNum > maxInNum) {
			maxInNum = inNum;
			for (unsigned y = 0; y < 3; y++) {
				mtxTransf.CellRef(0, y) = mtxT_x.CellVal(0, y);
				mtxTransf.CellRef(1, y) = mtxT_y.CellVal(0, y);
			}
		} else {}
	} // tryNum
	cout << endl;

	if (bDebug) {
		cout << "maxInNum:" << maxInNum << endl;
		cout << "RunRANSAC ok" << endl;
	} else {}
}

//void Align(Mtx &mtxWarp, Mtx const &mtxFrom , Mtx const &mtxTo, 
//	string fromN, string toN, bool bDebug) 
void ComputeTransform(Mtx &mtxTransf, string fromN, string toN, bool bDebug)
{
	unsigned tryNum = 5000;
	unsigned smpNum = 3;
	DATA nearDis = 5.F;

	Vect2D<unsigned> dimT = mtxTransf.GetDim();
	MyAssert(dimT.m_x == 2 && dimT.m_y == 3);

	//*******************************************
	// gen keypoints
	//*******************************************
	if (bDebug) {
		cout << "gen keypoint" << endl;
	} else {}

	string scall_pre = "siftWin32.exe";
	string keyFromN = fromN + ".key";
	string keyToN	= toN   + ".key";
	string scall_from = scall_pre + "<" + fromN + " >" + keyFromN;
	string scall_to	  = scall_pre + "<" + toN   + " >" + keyToN;
	system(scall_from.c_str());
	system(scall_to.c_str());

	if (bDebug) {
		cout << "gen keypoint ok" << endl;
	} else {}

	//*******************************************
	// match keypoints
	//*******************************************
	if (bDebug) {
		cout << "match keypoint" << endl;
	} else {}

	Keypoint kFrom = ReadKeyFile(keyFromN.c_str());
	Keypoint kTo   = ReadKeyFile(keyToN.c_str());

	vector<Vect2D<DATA>> matchFrom;
	vector<Vect2D<DATA>> matchTo;
	matchFrom.clear();
	matchTo.clear();
	for (Keypoint k = kFrom; k != 0; k = k->next) {
		Keypoint kToMatch = CheckForMatch(k, kTo);

		if (kToMatch) {
			Vect2D<DATA> posKFrom(k->col, k->row);
			Vect2D<DATA> posKTo(kToMatch->col, kToMatch->row);

			matchFrom.push_back(posKFrom);
			matchTo.push_back(posKTo);
		} else {}
	}
	MyAssert(matchFrom.size() == matchTo.size());

	if (bDebug) {
		cout << "match pair:" << endl;
		for (unsigned m = 0; m < matchFrom.size(); m++) {
			cout << "(" << matchFrom[m].m_x << "," << matchFrom[m].m_y << ")" << "\t"
				 << "(" << matchTo[m].m_x   << "," << matchTo[m].m_y   << ")" << endl;
		}

		cout << "match keypoint ok" << endl;
	} else {}

	//*******************************************
	// get transform
	//*******************************************
	RunRANSAC(mtxTransf, matchFrom, matchTo, tryNum, smpNum, nearDis, false);

	if (bDebug) {
		cout << "transform:" << endl;	mtxOp.out << mtxTransf;
	} else {}
}

void Warp(Mtx &mtxWarp, Mtx &mtxFrom, Mtx &mtxTo, Mtx &mtxTInv, bool bDebug)
{
	Vect2D<unsigned> dimWarp = mtxWarp.GetDim();
	Vect2D<unsigned> dimFrom = mtxFrom.GetDim();
	Vect2D<unsigned> dimTo 	 = mtxTo.GetDim();
	MyAssert(dimWarp.m_x == dimTo.m_x &&
			 dimWarp.m_y == dimTo.m_y);
	
	Mtx mtxT(3, 1);
	Mtx mtxF(2, 1);
	mtxOp.zero.Gen(mtxWarp);
	for (unsigned y = 0; y < dimTo.m_y; y++) {
		for (unsigned x = 0;  x < dimTo.m_x; x++) {
			mtxT.CellRef(0, 0) = x;
			mtxT.CellRef(1, 0) = dimTo.m_y - 1 - y;
			mtxT.CellRef(2, 0) = 1.F;
			mtxOp.mul.Gen(mtxF, mtxT, mtxTInv);

			int f_x = (int)(mtxF.CellVal(0, 0) + 0.5F);
			int f_y = (int)(mtxF.CellVal(1, 0) + 0.5F);
			f_y = dimFrom.m_y - 1 - f_y;
			if (mtxFrom.IsInside(f_x, f_y)) {
				mtxWarp.CellRef(x, y) = mtxFrom.CellVal(f_x, f_y);
			} else {}
		} // x
	} // y

	if (bDebug) {
		imgIO.Write("warp.bmp", MyImg(mtxWarp));
	} else {}
}

