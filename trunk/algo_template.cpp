#include "algo_template.h"

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
}

void GenRegionMsk(string fOutN, string fInN, bool bDebug)
{
	DATA binThrd_v = 100.F;
	unsigned closeLen = 5;
	//unsigned kerlLen = 10;

	string tmpN = "tmp";

	MyImg *pImgIn = imgIO.Read(fInN);
	Vect3D<unsigned> dim = pImgIn->GetDim();

	Mtx *pMtxG = pImgIn->ConvertGray()->GetMtx(0);
	if (bDebug) {
		string grayN = "gray_" + tmpN + "_" + fInN;
		imgIO.Write(grayN, MyImg(*pMtxG));
	} else {}

	mtxOp.binThrd.Gen(*pMtxG, binThrd_v, true);
	mtxOp.mul.Gen(*pMtxG, 255.F);
	if (bDebug) {
		string boundN = "background_" + tmpN + "_" + fInN;
		imgIO.Write(boundN, MyImg(*pMtxG));
	} else {}

	Mtx mtxClose(dim.m_x, dim.m_y);
	mtxOp.erose.Gen(mtxClose, *pMtxG, closeLen);
	pMtxG->CopyFrom(mtxClose);
	mtxOp.dilate.Gen(mtxClose, *pMtxG, closeLen);
	mtxOp.mul.Gen(mtxClose, 255.F);
	if (bDebug) {
		string closeN = "close_" + tmpN + "_" + fInN;
		imgIO.Write(closeN, MyImg(mtxClose));
	} else {}
}

void GenScoreRegion(string fSRN, string fMskN, string fScoreN, bool bDebug) 
{
	DATA sScl = 20.F;
	unsigned aS[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	MyImg *pMsk = imgIO.Read(fMskN);
	MyImg *pScr = imgIO.Read(fScoreN);

	Vect3D<unsigned> dimMsk = pMsk->GetDim();
	Vect3D<unsigned> dimScr = pScr->GetDim();
	MyAssert(dimMsk.m_x == dimScr.m_x &&
			 dimMsk.m_y == dimScr.m_y);

	Mtx mtxSR(dimMsk.m_x, dimMsk.m_y);
	Vect2D<unsigned> dimOut = mtxSR.GetDim();

	unsigned sLen = sizeof(aS) / sizeof(unsigned);
	MyAssert(aS[sLen - 1] == 0);
	mtxOp.zero.Gen(mtxSR);
	for (unsigned y = 0; y < dimOut.m_y; y++) {
		for (unsigned x = 0; x <dimOut.m_x; x++) {
			if (pMsk->CellVal(x, y, 0) > 128.F) {
				DATA sV = pScr->CellVal(x, y, 0);

				for (unsigned i = 0; i <= sLen - 2; i++) {
					DATA mid = (aS[i] + aS[i + 1]) / 2.F * sScl;
					if (sV > mid) {
						mtxSR.CellRef(x, y) = aS[i];
						break;
					} else {}
				}
			} else {}
		}
	}
	imgIO.Write(fSRN, MyImg(mtxSR));

	if (bDebug) {
		mtxOp.mul.Gen(mtxSR, sScl);
		string sN = "scale_" + fSRN;
		imgIO.Write(sN, MyImg(mtxSR));
	} else {}
}