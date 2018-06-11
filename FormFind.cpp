//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormFind.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFindForm *FindForm;
//---------------------------------------------------------------------------
__fastcall TFindForm::TFindForm(TComponent* Owner)
	: TForm(Owner)
{
	parent = static_cast<TForm*>(Owner);
	caseOnly = false;
	down = true;
	this->Left = parent->Left + parent->Width / 2 - this->Width / 2;
	this->Top = parent->Top + parent->Height / 2 - this->Height / 2;
}
//---------------------------------------------------------------------------
void __fastcall TFindForm::Button1Click(TObject *Sender)
{
	TForm1* f = static_cast<TForm1*>(parent);
	UnicodeString str = Edit1->Text;
	f->FindNext(&str, down, caseOnly);
}
//---------------------------------------------------------------------------
void __fastcall TFindForm::Button2Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFindForm::FormMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	Button1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TFindForm::RadioGroup1Click(TObject *Sender)
{
	if (RadioGroup1->ItemIndex == 0)
		down = false;
	else
		down = true;
}
//---------------------------------------------------------------------------
void __fastcall TFindForm::CheckBox2Click(TObject *Sender)
{
	if (CheckBox2->Checked)
		caseOnly = true;
	else
		caseOnly = false;
}
//---------------------------------------------------------------------------

