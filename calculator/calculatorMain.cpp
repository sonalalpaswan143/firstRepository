/***************************************************************
 * Name:      calculatorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    sonalal (paswansonalal988@gmail.com)
 * Created:   2023-01-21
 * Copyright: sonalal ()
 * License:
 **************************************************************/

#include "calculatorMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(calculatorFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(calculatorFrame)
const long calculatorFrame::ID_TEXTCTRL1 = wxNewId();
const long calculatorFrame::ID_BUTTON1 = wxNewId();
const long calculatorFrame::ID_BUTTON2 = wxNewId();
const long calculatorFrame::ID_BUTTON3 = wxNewId();
const long calculatorFrame::ID_BUTTON4 = wxNewId();
const long calculatorFrame::ID_BUTTON5 = wxNewId();
const long calculatorFrame::ID_BUTTON6 = wxNewId();
const long calculatorFrame::ID_BUTTON7 = wxNewId();
const long calculatorFrame::ID_BUTTON8 = wxNewId();
const long calculatorFrame::ID_BUTTON9 = wxNewId();
const long calculatorFrame::ID_BUTTON10 = wxNewId();
const long calculatorFrame::ID_BUTTON11 = wxNewId();
const long calculatorFrame::ID_BUTTON12 = wxNewId();
const long calculatorFrame::ID_BUTTON13 = wxNewId();
const long calculatorFrame::ID_BUTTON14 = wxNewId();
const long calculatorFrame::ID_BUTTON15 = wxNewId();
const long calculatorFrame::ID_BUTTON16 = wxNewId();
const long calculatorFrame::idMenuQuit = wxNewId();
const long calculatorFrame::idMenuAbout = wxNewId();
const long calculatorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(calculatorFrame,wxFrame)
    //(*EventTable(calculatorFrame)
    //*)
END_EVENT_TABLE()

calculatorFrame::calculatorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(calculatorFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(400,465));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("text"), wxPoint(8,24), wxSize(368,56), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    wxFont TextCtrl1Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl1->SetFont(TextCtrl1Font);
    Button1 = new wxButton(this, ID_BUTTON1, _("1"), wxPoint(16,120), wxSize(72,64), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    wxFont Button1Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button1->SetFont(Button1Font);
    Button2 = new wxButton(this, ID_BUTTON2, _("2"), wxPoint(120,120), wxSize(64,64), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    wxFont Button2Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button2->SetFont(Button2Font);
    Button3 = new wxButton(this, ID_BUTTON3, _("3"), wxPoint(208,120), wxSize(64,64), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    wxFont Button3Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button3->SetFont(Button3Font);
    Button4 = new wxButton(this, ID_BUTTON4, _("-"), wxPoint(288,120), wxSize(64,64), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    wxFont Button4Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button4->SetFont(Button4Font);
    Button5 = new wxButton(this, ID_BUTTON5, _("4"), wxPoint(16,200), wxSize(72,52), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    wxFont Button5Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button5->SetFont(Button5Font);
    Button6 = new wxButton(this, ID_BUTTON6, _("5"), wxPoint(120,192), wxSize(64,56), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    wxFont Button6Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button6->SetFont(Button6Font);
    Button7 = new wxButton(this, ID_BUTTON7, _("6"), wxPoint(208,200), wxSize(64,56), 0, wxDefaultValidator, _T("ID_BUTTON7"));
    wxFont Button7Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button7->SetFont(Button7Font);
    Button8 = new wxButton(this, ID_BUTTON8, _("+"), wxPoint(296,200), wxSize(64,56), 0, wxDefaultValidator, _T("ID_BUTTON8"));
    wxFont Button8Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button8->SetFont(Button8Font);
    Button9 = new wxButton(this, ID_BUTTON9, _("7"), wxPoint(24,264), wxSize(64,56), 0, wxDefaultValidator, _T("ID_BUTTON9"));
    wxFont Button9Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button9->SetFont(Button9Font);
    Button10 = new wxButton(this, ID_BUTTON10, _("8"), wxPoint(120,264), wxSize(64,56), 0, wxDefaultValidator, _T("ID_BUTTON10"));
    wxFont Button10Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button10->SetFont(Button10Font);
    Button11 = new wxButton(this, ID_BUTTON11, _("9"), wxPoint(208,264), wxSize(72,56), 0, wxDefaultValidator, _T("ID_BUTTON11"));
    wxFont Button11Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button11->SetFont(Button11Font);
    Button12 = new wxButton(this, ID_BUTTON12, _("*"), wxPoint(296,264), wxSize(64,52), 0, wxDefaultValidator, _T("ID_BUTTON12"));
    wxFont Button12Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button12->SetFont(Button12Font);
    Button13 = new wxButton(this, ID_BUTTON13, _("clear"), wxPoint(24,344), wxSize(80,48), 0, wxDefaultValidator, _T("ID_BUTTON13"));
    wxFont Button13Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button13->SetFont(Button13Font);
    Button14 = new wxButton(this, ID_BUTTON14, _("="), wxPoint(208,336), wxSize(72,48), 0, wxDefaultValidator, _T("ID_BUTTON14"));
    wxFont Button14Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button14->SetFont(Button14Font);
    Button15 = new wxButton(this, ID_BUTTON15, _("/"), wxPoint(296,336), wxSize(64,48), 0, wxDefaultValidator, _T("ID_BUTTON15"));
    wxFont Button15Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button15->SetFont(Button15Font);
    Button16 = new wxButton(this, ID_BUTTON16, _("0"), wxPoint(128,336), wxSize(56,52), 0, wxDefaultValidator, _T("ID_BUTTON16"));
    wxFont Button16Font(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button16->SetFont(Button16Font);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&calculatorFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&calculatorFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&calculatorFrame::OnButton3Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&calculatorFrame::OnButton5Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&calculatorFrame::OnButton6Click);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&calculatorFrame::OnButton7Click);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&calculatorFrame::OnButton8Click);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&calculatorFrame::OnButton9Click);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&calculatorFrame::OnButton10Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&calculatorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&calculatorFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&calculatorFrame::OnClose);
    //*)
}

calculatorFrame::~calculatorFrame()
{
    //(*Destroy(calculatorFrame)
    //*)
}

void calculatorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void calculatorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void calculatorFrame::OnButton2Click(wxCommandEvent& event)
{
}

void calculatorFrame::OnClose(wxCloseEvent& event)
{
}

void calculatorFrame::OnButton6Click(wxCommandEvent& event)
{
}

void calculatorFrame::OnButton1Click(wxCommandEvent& event)
{
}
