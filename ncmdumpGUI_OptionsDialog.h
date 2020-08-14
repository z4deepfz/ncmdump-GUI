#ifndef NCMDUMPGUI_OPTIONSDIALOG_H
#define NCMDUMPGUI_OPTIONSDIALOG_H

//(*Headers(ncmdumpGUI_OptionsDialog)
#include <wx/frame.h>
class wxBoxSizer;
class wxCheckBox;
class wxPanel;
class wxStaticBoxSizer;
class wxStaticText;
//*)

class ncmdumpGUI_OptionsDialog: public wxFrame
{
	public:

		ncmdumpGUI_OptionsDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ncmdumpGUI_OptionsDialog();

		bool isDeleteNCMFile() const;
		bool isFixMetaData() const;

		//(*Declarations(ncmdumpGUI_OptionsDialog)
		wxCheckBox* chkDelNCM;
		wxCheckBox* chkFixMeta;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(ncmdumpGUI_OptionsDialog)
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_STATICTEXT1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(ncmdumpGUI_OptionsDialog)
		void OnClose(wxCloseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
