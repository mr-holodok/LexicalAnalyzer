//---------------------------------------------------------------------------

#ifndef FindReplaceFormH
#define FindReplaceFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TCheckBox *CheckBox2;
	TEdit *Edit1;
	TLabel *Label1;
	TRadioGroup *RadioGroup1;
	TLabel *Label2;
	TEdit *Edit2;
	TButton *Button3;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);


private:	// User declarations
	TForm *parent;
	bool down;
	bool caseOnly;
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
