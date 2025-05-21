// wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class chatbot_ui : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame();

private:
    // Event Handler Declaration
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnSend(wxCommandEvent& event);
    void OnStop(wxCommandEvent& event);
    void OnClear(wxCommandEvent& event);

    void OnCounter(wxCommandEvent &event);

    int counter = 0;

    wxTextCtrl* inputField; // text input for sending the message
    wxTextCtrl* m_display; // message, that will be shown in the window, hope not a pop-up

    // buttons
    wxButton* sendButton;
    wxButton* stopButton;
    wxButton* clearButton;

    // options
    wxCheckBox* firstOption;
    wxCheckBox* secondOption;

    wxButton* counterButton;

};

enum
{
    ID_Hello = 1
};

wxIMPLEMENT_APP(chatbot_ui);

bool chatbot_ui::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Chatbot Solver")
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar( menuBar );

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    // panel to place controls, text input will need it as a parameter
    wxPanel* panel = new wxPanel(this);

    // initialize input field
    inputField = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 220), wxSize(220, 30));

    // create the output (message)
    m_display = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 10), wxSize(300, 200),wxTE_MULTILINE | wxTE_READONLY | wxTE_RICH); //wxte_rich enables text styling for later :D

    // button definitions
    sendButton = new wxButton(panel, wxID_ANY, "Send", wxPoint(240, 220), wxSize(45, 30));
    stopButton = new wxButton(panel, wxID_ANY, "Stop", wxPoint(290, 220), wxSize(40, 30));
    clearButton = new wxButton(panel, wxID_ANY, "Clear", wxPoint(335, 220), wxSize(50, 30));
    counterButton = new wxButton(panel, wxID_ANY, "Counter", wxPoint(390, 220), wxSize(50, 30));

    firstOption = new wxCheckBox(panel, wxID_ANY, "First Option", wxPoint(10, 260));
    secondOption = new wxCheckBox(panel, wxID_ANY, "Second Option", wxPoint(10, 280));

    // connect the button click
    sendButton->Bind(wxEVT_BUTTON, &MyFrame::OnSend, this);
    stopButton->Bind(wxEVT_BUTTON, &MyFrame::OnStop, this);
    clearButton->Bind(wxEVT_BUTTON, &MyFrame::OnClear, this);
    counterButton->Bind(wxEVT_BUTTON, &MyFrame::OnCounter, this);

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a project which using wxWidgets's Hello World example as a skeleton.",
                 "About the application", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from team projekt!");
}

void MyFrame::OnSend(wxCommandEvent& event)
{
    wxString message = inputField->GetValue();

    if (!message.IsEmpty()) {
        m_display->AppendText("You: "+message+ "\n");
        /*that makes a pop up display
        wxLogMessage("You sent: %s", message);*/
        inputField->Clear(); // Clear after sending
    } else {
        wxLogMessage("Do not ever try sending an empty message!!!");
    }
}
void MyFrame::OnStop(wxCommandEvent& event) {
    Close(true);
    // or force computer to stop "thinking"
    std::cout << "the following messages has sent during the conversation" << std::endl;
    std::cout << m_display->GetValue() << std::endl;
}

void MyFrame::OnClear(wxCommandEvent& event) {
    m_display->Clear();
}

void MyFrame::OnCounter(wxCommandEvent& event) {
    counter += 1;
    std::cout << counter << std::endl;
}
