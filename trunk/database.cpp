#include "database.h"

void MyAssert(bool b) 
{
	assert(b);
}

int WriteData(string fName, string id, unsigned score)
{
	time_t currT;
	time(&currT);
	struct tm *pTLocal = localtime(&currT);

	ofstream ofs;
	ofs.open(fName, ofstream::app);
	MyAssert(ofs.good());
	ofs << id << " " 
		<< score << " " 
		<< asctime(pTLocal);
		//<< endl;

	ofs.close();
	return 0;
}

int SearchData(string fnOut, string fnIn, string idIn)
{
	ifstream ifs;
	ifs.open(fnIn);
	if (ifs.fail()) {
		return -1;
	} else {}

	ofstream ofs;
	ofs.open(fnOut);
	MyAssert(ofs.good());

	string sLine;
	string idNow;
	string sSc;
	char aL[30];
	stringstream ss;
	ofs << setw(15) << left << "Shooter_ID" 
		<< setw(10) << left << "Score" 
		<< setw(30) << left << "Time" << endl;
	while (!ifs.eof()) {
		getline(ifs, sLine);
		ss.str("");
		ss.clear();
		idNow.clear();
		ss << sLine;
		ss >> idNow;

		if (idIn.compare(idNow) == 0) {
			ss >> sSc;
			ss.getline(aL, 30);
			ofs << setw(15) << left << idNow
				<< setw(10)	<< left << sSc
				<< setw(30) << left << aL << endl;
		} else {}
	}

	ofs.close();
	ifs.close();
	return 0;
}