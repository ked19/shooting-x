#ifndef _MAIN_WINAPP_H
#define _MAIN_WINAPP_H

#include "SDK10000.h"
#include "layer.h"
#include "imageIO.h"
#include "algo_target.h"
#include "algo_template.h"
#include "database.h"

#include <FL/Fl.H>
#include <FL/Fl_Input.h>
#include <FL/Fl_Button.H>
#include <FL/Fl_Double_Window.h>
#include <FL/Fl_Light_Button.h>
//#include <Fl/Fl_Text_Buffer.h>
//#include <Fl/Fl_Text_Display.h>
#include <FL/Fl_ask.h>
#include <FL/Fl_Group.h>
#include <FL/Fl_Gl_Window.h>
#include <iostream>
#include <GL/glew.h>
#include <thread>
#include <mutex>

using namespace std;

extern Fl_Input *pIP0_txtIn;
extern Fl_Input *pIP1_txtIn;
extern Fl_Input *pIP2_txtIn;
extern Fl_Input *pIP3_txtIn;
extern Fl_Input *pPort_txtIn;
extern Fl_Input *pAccount_txtIn;
extern Fl_Input *pPasswd_txtIn;
extern Fl_Input *pInID_txtIn;
extern Fl_Input *pSearchID_txtIn;

extern Fl_Light_Button *pClose_litBttn;
extern Fl_Light_Button *pCalculate_litBttn;

extern Fl_Button *pConnect_bttn;

extern bool bNp;
extern mutex gMutex;

//extern Fl_Text_Display *pOutput_txtDisp;


void RunConnect				(Fl_Button *w, void *v);
void SearchID				(Fl_Button *w, void *v);
void ComputeScore			(Fl_Light_Button *w, void *v);
void Disconnect				(Fl_Light_Button *w, void *v);

void CloseConnect();

//extern Mtx *pMtxTarget_draw;

/*
class MyFlImg : public Fl_Group
{
public:
	MyFlImg(int x, int y, int w, int h, const char *l = 0);
	void draw();
	int handle(int event);
};

extern MyFlImg *pTarget_img;
*/

class MyGlWindow : public Fl_Gl_Window
{
public:
	MyGlWindow(int x, int y, int w, int h, const char *l = 0);
	void draw();
	int handle(int event);
};
extern MyGlWindow *pTarget_win;

#endif