#include <wx/wx.h>
#include <chrono>
#include <iostream>
#include <format>

class App1 : public wxApp
{
public:
    bool OnInit() override;
};

class Frame1 : public wxFrame
{
public:
    Frame1(const wxString& title);

private:
    void HelloWorld(wxCommandEvent& event);    
    wxStaticText* aktuelle_zeit;
};

wxIMPLEMENT_APP(App1);

bool App1::OnInit()
{
    Frame1* frame = new Frame1("Uhrzeit");
    frame->Show();
    return true;
}

Frame1::Frame1(const wxString& title) : wxFrame(nullptr, wxID_ANY, title), aktuelle_zeit(nullptr) {
    wxPanel* panel = new wxPanel(this);
    wxButton* aktuallisiere_zeit = new wxButton(panel, wxID_ANY, "Aktuallisiere Zeit");
    aktuelle_zeit = new wxStaticText(panel, wxID_ANY, "Uhr", wxPoint(20, 100));

    aktuallisiere_zeit->Bind(wxEVT_BUTTON, &Frame1::HelloWorld, this);
}

void Frame1::HelloWorld(wxCommandEvent& event)
{
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::cout << "Uhrzeit: " << t << std::endl;

    // das ist der einzigste teil wo ich pures AI code nutzte, der rest ist selbst gemacht
    wxDateTime dt(t);
    wxString wxTime = dt.FormatISOCombined(' ');
    aktuelle_zeit->SetLabel(wxTime);

    aktuelle_zeit->SetLabel(wxTime);
}
