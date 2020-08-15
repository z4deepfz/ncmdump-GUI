#include "ncmdumpGUI_OptionsDialog.h"

//(*InternalHeaders(ncmdumpGUI_OptionsDialog)
#include <wx/checkbox.h>
#include <wx/intl.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/string.h>
//*)

//(*IdInit(ncmdumpGUI_OptionsDialog)
const long ncmdumpGUI_OptionsDialog::ID_CHECKBOX1 = wxNewId();
const long ncmdumpGUI_OptionsDialog::ID_CHECKBOX2 = wxNewId();
const long ncmdumpGUI_OptionsDialog::ID_STATICTEXT1 = wxNewId();
const long ncmdumpGUI_OptionsDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ncmdumpGUI_OptionsDialog,wxFrame)
	//(*EventTable(ncmdumpGUI_OptionsDialog)
	//*)
END_EVENT_TABLE()

ncmdumpGUI_OptionsDialog::ncmdumpGUI_OptionsDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ncmdumpGUI_OptionsDialog)
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;

	Create(parent, id, _("Options"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX|wxCLIP_CHILDREN, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	SetMinSize(wxSize(480,320));
	SetIcon(wxIcon(wxT("options_icon")));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(280,392), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Files"));
	chkDelNCM = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Delete .ncm file after converted successfully (be careful)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	chkDelNCM->SetValue(false);
	StaticBoxSizer1->Add(chkDelNCM, 1, wxALL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Meta Data"));
	chkFixMeta = new wxCheckBox(Panel1, ID_CHECKBOX2, _("Fix Meta data after decrypted (unstable)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	chkFixMeta->SetValue(true);
	StaticBoxSizer2->Add(chkFixMeta, 1, wxALL, 5);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Fix Metadata seems not pretty stable. So if you don\'t care about the meta data (author, album, cover, etc...), don\'t check the box."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticBoxSizer2->Add(StaticText1, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer2, 2, wxALL|wxEXPAND, 5);
	Panel1->SetSizer(BoxSizer1);
	BoxSizer1->Fit(Panel1);
	BoxSizer1->SetSizeHints(Panel1);
	Center();

	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&ncmdumpGUI_OptionsDialog::OnClose);
	//*)
}

ncmdumpGUI_OptionsDialog::~ncmdumpGUI_OptionsDialog()
{
	//(*Destroy(ncmdumpGUI_OptionsDialog)
	//*)
}


void ncmdumpGUI_OptionsDialog::OnClose(wxCloseEvent& event)
{
    Hide();
    /// don't destroy the frame. Hide it instead.
}

bool ncmdumpGUI_OptionsDialog::isDeleteNCMFile() const
{
    return chkDelNCM->GetValue();
}

bool ncmdumpGUI_OptionsDialog::isFixMetaData() const
{
    return chkFixMeta->GetValue();
}
