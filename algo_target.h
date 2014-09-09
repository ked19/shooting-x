#ifndef _ALGO_TARGET_H
#define _ALGO_TARGET_H

#include "matrixOperation.h"
#include "denseMatrix.h"
#include "defs.h"
#include "myMath.h"

#include <vector>

using namespace std;

//void Align(Mtx &mtxWarp, Mtx const &mtxFrom , Mtx const &mtxTo, 
//	string fromN, string toN, bool bDebug = false);
void ComputeTransform(Mtx &mtxTransf, string fromN, string toN, bool bDebug = false);
void Warp(Mtx &mtxWarp, Mtx &mtxFrom, Mtx &mtxTo, Mtx &mtxTInv, bool bDebug = false);

void RunTarget();

#endif