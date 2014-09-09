#ifndef _ALGO_TEMPLATE_H
#define _ALGO_TEMPLATE_H

#include "denseMatrix.h"
#include "layer.h"
#include "imageIO.h"
#include "define.h"
#include "matrixOperation.h"

void GenRegionMsk(string fOutN, string fInN, bool bDebug = false);
void GenScoreRegion(string fSRN, string fMskN, string fScoreN, bool bDebug = false);
void GenDilateKernel(Mtx &mK);

#endif