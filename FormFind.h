//---------------------------------------------------------------------------

#ifndef FormFindH
#define FormFindH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFindForm : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TEdit *Edit1;
	TLabel *Label1;
	TRadioGroup *RadioGroup1;
	TCheckBox *CheckBox2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);

private:	// User declarations
	TForm *parent;
	bool down;
	bool caseOnly;
public:		// User declarations
	__fastcall TFindForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFindForm *FindForm;
//---------------------------------------------------------------------------
#endif
