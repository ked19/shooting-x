#ifndef _DATABASE_H
#define _DATABASE_H

//#include "define.h"

#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <cassert>
#include <iomanip>

using namespace std;

int WriteData(string fName, string id, unsigned score);
int SearchData(string fnOut, string fnIn, string idIn);

#endif