#ifndef GUIEXTRA_HPP
#define GUIEXTRA_HPP

#include "ncmdump_GUIMain.h"
#include "MergeFileDialog.h"
#include <wx/wx.h>
#include <exception>

void addListCtrlCol(wxListCtrl& l)
{
    const int _a[3] = {1, 2, 0};
    const wxArrayInt a(_a, _a+3);
    l.InsertColumn(0, _("Full Path"), wxLIST_FORMAT_LEFT, 350);
    l.InsertColumn(1, _("Music"), wxLIST_FORMAT_LEFT, 300);
    l.InsertColumn(2, _("Size"), wxLIST_FORMAT_LEFT);
    l.SetColumnsOrder(a);
    //wxMessageBox("aaa");
}

void ncmdump_GUIFrame::reFillList()
{
    itembox->DeleteAllItems();
    unsigned cnt = 0;
    for(auto i: sFile){
        wxListItem fn, fs, fp;
        wxFileName f(i);

        fp.SetColumn(0);
        fp.SetId(cnt++);
        fp.SetText(i);
        const auto ind = itembox->InsertItem(fp);

        fn.SetColumn(1);
        fn.SetId(ind);
        fn.SetText( f.GetName() );
        itembox->SetItem(fn);

        fs.SetColumn(2);
        fs.SetId(ind);
        fs.SetText( f.GetHumanReadableSize() );
        itembox->SetItem(fs);
    }
    return;
}

void ncmdump_GUIFrame::setItemColor(const wxString& s, const wxColor& c)
{
    auto p = itembox->FindItem(-1, s);
    if( p != wxNOT_FOUND){
        itembox->SetItemBackgroundColour(p, c);
    }
    return;
}

bool DumpNcm(const std::string& s, const std::string& opath="", const bool fixmeta=false)
{
    try{
        NeteaseCrypt c(s);
        c.Dump(opath);
        if(fixmeta){
            c.FixMetadata();
        }
    }
    catch(std::exception& e){
        std::cerr << e.what();
        return false;
    }
    catch(...){
        std::cerr<< "Catch Unknow Error\n";
    }
    return true;
}

wxString getFileName(const wxString& s)
{
    wxFileName t(s);
    return t.GetFullName();
}

wxString genProcessText(int finished, int total, const wxString& name)
{
    return wxString::Format(" (%d/%d) Processing... [", finished, total) + getFileName(name) + "]";
}

wxString getFileExt(const wxString& s)
{
    wxFileName t(s);
    return t.GetExt();
}

bool isNCMFile(const wxString& s)
{
    return getFileExt(s) == wxString("ncm");
}

class DnDTarget: public wxFileDropTarget
{
    public:
        DnDTarget(ncmdump_GUIFrame *owner): m_owner(owner) {}
        virtual bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames){
            m_owner->AddItems(filenames);
            return true;
        }

    private:
        ncmdump_GUIFrame* m_owner;
};

#endif // GUIEXTRA_HPP
