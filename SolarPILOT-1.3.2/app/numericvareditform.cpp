
/*******************************************************************************************************
*  Copyright 2018 Alliance for Sustainable Energy, LLC
*
*  NOTICE: This software was developed at least in part by Alliance for Sustainable Energy, LLC
*  ("Alliance") under Contract No. DE-AC36-08GO28308 with the U.S. Department of Energy and the U.S.
*  The Government retains for itself and others acting on its behalf a nonexclusive, paid-up,
*  irrevocable worldwide license in the software to reproduce, prepare derivative works, distribute
*  copies to the public, perform publicly and display publicly, and to permit others to do so.
*
*  Redistribution and use in source and binary forms, with or without modification, are permitted
*  provided that the following conditions are met:
*
*  1. Redistributions of source code must retain the above copyright notice, the above government
*  rights notice, this list of conditions and the following disclaimer.
*
*  2. Redistributions in binary form must reproduce the above copyright notice, the above government
*  rights notice, this list of conditions and the following disclaimer in the documentation and/or
*  other materials provided with the distribution.
*
*  3. The entire corresponding source code of any redistribution, with or without modification, by a
*  research entity, including but not limited to any contracting manager/operator of a United States
*  National Laboratory, any institution of higher learning, and any non-profit organization, must be
*  made publicly available under this license for as long as the redistribution is made available by
*  the research entity.
*
*  4. Redistribution of this software, without modification, must refer to the software by the same
*  designation. Redistribution of a modified version of this software (i) may not refer to the modified
*  version by the same designation, or by any confusingly similar designation, and (ii) must refer to
*  the underlying software originally provided by Alliance as "Solar Power tower Integrated Layout and 
*  Optimization Tool" or "SolarPILOT". Except to comply with the foregoing, the terms "Solar Power 
*  tower Integrated Layout and Optimization Tool", "SolarPILOT", or any confusingly similar
*  designation may not be used to refer to any modified version of this software or any modified
*  version of the underlying software originally provided by Alliance without the prior written consent
*  of Alliance.
*
*  5. The name of the copyright holder, contributors, the United States Government, the United States
*  Department of Energy, or any of their employees may not be used to endorse or promote products
*  derived from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
*  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
*  FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER,
*  CONTRIBUTORS, UNITED STATES GOVERNMENT OR UNITED STATES DEPARTMENT OF ENERGY, NOR ANY OF THEIR
*  EMPLOYEES, BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
*  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
*  IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
*  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************************************/


#include "numericvareditform.h"

enum {
  ID_GroupBox1=6108,
  ID_GroupBox2=6109,
  ID_cmdCancel=6110,
  ID_btnHelp=6111,
  ID_cmdOk=6112,
  ID_cmdUpdateValues=6113,
  ID_lblNotification=6114,
  ID_cmdMoveDown=6115,
  ID_lstValues=6116,
  ID_cmdRemove=6117,
  ID_cmdAddBefore=6118,
  ID_cmdAddAfter=6119,
  ID_cmdMoveUp=6120,
  ID_Label3=6121,
  ID_Label2=6122,
  ID_Label1=6123,
  ID_numIncr=6124,
  ID_numEnd=6125,
  ID_numStart=6126 
};

BEGIN_EVENT_TABLE( NumericVarEditForm, wxPanel )
    EVT_BUTTON( ID_cmdAddAfter, NumericVarEditForm::OnCommand)
    EVT_BUTTON( ID_cmdAddBefore, NumericVarEditForm::OnCommand)
    EVT_BUTTON( ID_cmdMoveUp, NumericVarEditForm::OnCommand)
    EVT_BUTTON( ID_cmdMoveDown, NumericVarEditForm::OnCommand)
    EVT_BUTTON( ID_cmdRemove, NumericVarEditForm::OnCommand)
    EVT_BUTTON( ID_cmdUpdateValues, NumericVarEditForm::OnCommand)
    EVT_TEXT_ENTER( ID_numStart, NumericVarEditForm::OnCommand)
    EVT_TEXT_ENTER( ID_numEnd, NumericVarEditForm::OnCommand)
    EVT_TEXT_ENTER( ID_numIncr, NumericVarEditForm::OnCommand)
    EVT_LISTBOX_DCLICK( ID_lstValues, NumericVarEditForm::OnCommand)
END_EVENT_TABLE()

wxString IntToStr(int val)
{
    return wxString::Format("%d",val);
}

wxString FloatToStr(double val)
{
    return wxString::Format("%lg",val);
}

NumericVarEditForm::NumericVarEditForm(wxWindow *parent, int id)
     : wxPanel( parent, id )
{
    SetClientSize( 486, 323 );
    GroupBox1 = new wxStaticBox(this, ID_GroupBox1, "Define Range", wxPoint(246,9), wxSize(230,167));
    GroupBox2 = new wxStaticBox(this, ID_GroupBox2, "Variable Values", wxPoint(9,9), wxSize(224,272));
    numStart = new AFNumeric(this, ID_numStart, 0, false, wxPoint(366,39), wxSize(100,21));
    numStart->SetFormat( "%lg");
    numStart->SetDouble( 0 );
    numEnd = new AFNumeric(this, ID_numEnd, 0, false, wxPoint(366,66), wxSize(100,21));
    numEnd->SetFormat( "%lg");
    numEnd->SetDouble( 0 );
    numIncr = new AFNumeric(this, ID_numIncr, 0, false, wxPoint(366,93), wxSize(100,21));
    numIncr->SetFormat( "%lg");
    numIncr->SetDouble( 0 );
    cmdMoveUp = new wxButton(this, ID_cmdMoveUp, "Up", wxPoint(18,246), wxSize(56,21));
    cmdAddAfter = new wxButton(this, ID_cmdAddAfter, "Add After...", wxPoint(18,219), wxSize(98,21));
    cmdAddBefore = new wxButton(this, ID_cmdAddBefore, "Add Before...", wxPoint(123,219), wxSize(98,21));
    cmdRemove = new wxButton(this, ID_cmdRemove, "Remove", wxPoint(144,246), wxSize(77,21));
    wxArrayStr _data_lstValues;
    lstValues = new wxListBox(this, ID_lstValues, wxPoint(18,27), wxSize(203,186), _data_lstValues, wxLB_SINGLE);
    cmdMoveDown = new wxButton(this, ID_cmdMoveDown, "Down", wxPoint(81,246), wxSize(56,21));
    cmdUpdateValues = new wxButton(this, ID_cmdUpdateValues, "Update", wxPoint(372,123), wxSize(89,21));
    cmdOk = new wxButton(this, ID_cmdOk, "OK", wxPoint(315,294), wxSize(80,21));
    cmdCancel = new wxButton(this, ID_cmdCancel, "Cancel", wxPoint(399,294), wxSize(80,21));
    lblNotification = new AFLabel(this, ID_lblNotification, "", wxPoint(252,147), wxSize(218,21));
    lblNotification->SetColour(wxColour(255, 0, 0));
    lblNotification->SetRelativeSize(0);
    Label3 = new AFLabel(this, ID_Label3, "Increment:", wxPoint(252,93), wxSize(110,21));
    Label3->AlignRight();
    Label3->SetColour(wxColour(0, 0, 0));
    Label3->SetRelativeSize(0);
    Label2 = new AFLabel(this, ID_Label2, "End Value:", wxPoint(252,66), wxSize(110,21));
    Label2->AlignRight();
    Label2->SetColour(wxColour(0, 0, 0));
    Label2->SetRelativeSize(0);
    Label1 = new AFLabel(this, ID_Label1, "Start Value:", wxPoint(252,39), wxSize(110,21));
    Label1->AlignRight();
    Label1->SetColour(wxColour(0, 0, 0));
    Label1->SetRelativeSize(0);
    wxArrayStr val_choices;
    val_choices.Add(wxT("Keep existing layout"));
    val_choices.Add(wxT("Regenerate field layout"));
    layoutCombo = new wxComboBox(this, wxID_ANY, val_choices[0], wxPoint(246, 190), wxSize(230,22), val_choices, wxCB_DROPDOWN|wxCB_READONLY);
        
    bIntOnly = false;
    cmdOk->SetDefault();
}
NumericVarEditForm::~NumericVarEditForm()
{
}

void NumericVarEditForm::SetVarOptimizationType(int index){
    if(layoutCombo) layoutCombo->SetSelection(index);
}

void NumericVarEditForm::SetValues(const wxArrayStr &values, bool int_only)
{
    bIntOnly = int_only;

    lstValues->Clear();
    lstValues->Freeze();
    
    double min = 1e100, max=-1e100;

    for (int i=0;i<(int)values.Count();i++)
    {
        if (bIntOnly)
        {
            long x=0;
            values[i].ToLong(&x);
            lstValues->Append( wxString::Format("%d", x ));
            if ( x < min)
                min = x;
            if (x > max)
                max = x;
        }
        else
        {
            double x=0;
            values[i].ToDouble(&x);
            lstValues->Append( wxString::Format("%lg", x));
            if ( x < min)
                min = x;
            if (x > max)
                max = x;
        }
    }
    
    lstValues->Thaw();

    numStart->SetDouble(min);
    numEnd->SetDouble(max);
    if (values.Count() > 1)
        numIncr->SetDouble((max-min)/(double)(values.Count()-1));
    CheckRanges();
}

void NumericVarEditForm::OnCommand(wxCommandEvent &evt)
{
    int nsel = 0;
    switch(evt.GetId())
    {
    case ID_lstValues:
        {
            nsel = lstValues->GetSelection();
            if (nsel < 0)
                return;

            wxString item = lstValues->GetString(nsel);
            item = wxGetTextFromUser("Change value:", "Edit", item);
            if (item != wxEmptyString)
            {
                if (bIntOnly) lstValues->SetString(nsel, IntToStr( atoi( item.c_str() ) ) );
                else lstValues->SetString(nsel, FloatToStr( atof( item.c_str() ) ) );
            }

        }
        break;
    case ID_cmdAddAfter:
    case ID_cmdAddBefore:
        {
            nsel = lstValues->GetSelection();
            if (nsel < 0)
                nsel = 0;

            wxString item = "1.0";
            if (nsel < (int) lstValues->GetCount())
                item = lstValues->GetString( nsel );

            wxString str = wxGetTextFromUser("Enter new value:", 
                evt.GetId() == ID_cmdAddAfter ? "Add Number After Selection" : "Add Number Before Selection",
                item);
            if (str != wxEmptyString)
            {
                int idxincr = (evt.GetId() == ID_cmdAddAfter && lstValues->GetCount()>0 )? 1 : 0;
                
                if (bIntOnly) lstValues->Insert( IntToStr( atoi( str.c_str() ) ), nsel+idxincr );
                else lstValues->Insert( FloatToStr( atof( str.c_str() ) ), nsel+idxincr );
            }
        }

        break;

    case ID_cmdRemove:
        if ( (nsel=lstValues->GetSelection()) >= 0)
        {
            lstValues->Delete( lstValues->GetSelection() );
            if (nsel >= (int)lstValues->GetCount())
                nsel = lstValues->GetCount() - 1;
            if (nsel >= 0)
                lstValues->SetSelection(nsel);
        }
        break;
    case ID_cmdMoveUp:
        if (lstValues->GetCount() >= 2)
        {
            int isel = lstValues->GetSelection();
            if (isel >= 1)
            {
                wxString tmp = lstValues->GetString( isel - 1 );
                lstValues->SetString(isel - 1, lstValues->GetString(isel) );
                lstValues->SetString(isel, tmp);
                lstValues->SetSelection( isel - 1 );
            }
        }
        break;

    case ID_cmdMoveDown:
        if (lstValues->GetCount() >= 2)
        {
            int isel = lstValues->GetSelection();
            if (isel <= (int)lstValues->GetCount() - 2 && isel >= 0)
            {
                wxString tmp = lstValues->GetString( isel + 1 );
                lstValues->SetString(isel + 1, lstValues->GetString(isel) );
                lstValues->SetString(isel, tmp);
                lstValues->SetSelection( isel + 1 );
            }
        }
        break;

    case ID_cmdUpdateValues:
    case ID_numStart:
    case ID_numEnd:
    case ID_numIncr:
        GenerateValues();
        break;
    }
}

bool NumericVarEditForm::CheckRanges()
{
    double start, end, incr;

    start = numStart->GetDouble();
    end = numEnd->GetDouble();
    incr = numIncr->GetDouble();

    lblNotification->SetCaption("");

    if (incr == 0)
        lblNotification->SetCaption("Increment is 0.");

    if (end <= start && incr > 0)
        lblNotification->SetCaption("End < Start & Incr > 0");

    if (start < end && incr < 0)
        lblNotification->SetCaption("Start < End & Incr < 0");

    lblNotification->Refresh();

    return lblNotification->GetCaption() == "";
}

void NumericVarEditForm::GenerateValues()
{
    if (!CheckRanges())
        return;

    double start, end, incr;

    start = numStart->GetDouble();
    end = numEnd->GetDouble();
    incr = numIncr->GetDouble();

    double curval = start;
    wxString endvalstr = bIntOnly?
        wxString::Format("%d", (int) end ) :
        wxString::Format("%lg", end );

#define NMAXVALS 200

    wxArrayStr vals;
    int nadded = 0;
    while ( (incr > 0 && curval <= end)
            || (incr < 0 && curval >= end ) )
    {
        if (vals.Index( endvalstr ) >= 0)
            break;

        if (nadded > NMAXVALS)
            break;

        nadded++;

        if (incr > 0 && curval > 1.001*end)
            break;

        if (incr < 0 && curval < 0.999*end)
            break;

        vals.Add( bIntOnly?
            wxString::Format("%d", (int) curval ) :
            wxString::Format("%lg", curval ) );
            
        curval += incr;
    }

    if (vals.Index(endvalstr) < 0 && nadded <= NMAXVALS)
        vals.Add(endvalstr);


    lstValues->Freeze();
    lstValues->Clear();
    lstValues->Append(vals);
    lstValues->Thaw();
}

int NumericVarEditForm::GetVarOptimizationType(){
    return layoutCombo->GetSelection();        //[0=Keep existing, 1=Regenerate layout]
}


BEGIN_EVENT_TABLE( NumericVarEditFormDialog, wxDialog )
EVT_BUTTON(ID_cmdOk, NumericVarEditFormDialog::OnCommand)
EVT_BUTTON(ID_cmdCancel, NumericVarEditFormDialog::OnCommand)
EVT_CLOSE(NumericVarEditFormDialog::OnClose)
END_EVENT_TABLE()

NumericVarEditFormDialog::NumericVarEditFormDialog(wxWindow *parent, const wxString &title, void *data)
     : wxDialog( parent, -1, title )
{
    (void)data;

    mPanel = new NumericVarEditForm(this);
    wxSize _sz = mPanel->GetClientSize();
    SetClientSize(_sz.GetWidth(), _sz.GetHeight());

    wxAcceleratorEntry entries[1];
    entries[0].Set( ::wxACCEL_NORMAL, WXK_F1, ID_btnHelp );
    SetAcceleratorTable( wxAcceleratorTable(1,entries) );
    SetEscapeId(ID_cmdCancel);
}

NumericVarEditForm *NumericVarEditFormDialog::GetPanel() { return mPanel; }

void NumericVarEditFormDialog::OnCommand(wxCommandEvent &evt)
{

    if (evt.GetId() == ID_cmdOk)
        EndModal( wxID_OK );
    else
        EndModal( wxID_CANCEL );
}

void NumericVarEditFormDialog::OnClose(wxCloseEvent &WXUNUSED(event))
{
    EndModal(wxID_CANCEL);
}


