/***************************************************************
 * Name:      calculatorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    sonalal (paswansonalal988@gmail.com)
 * Created:   2023-01-21
 * Copyright: sonalal ()
 * License:
 **************************************************************/

#include "calculatorApp.h"

//(*AppHeaders
#include "calculatorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(calculatorApp);

bool calculatorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	calculatorFrame* Frame = new calculatorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
