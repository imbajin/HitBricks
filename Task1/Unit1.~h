#ifndef Unit1H
#define Unit1H
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "trayicon.h"
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <list>

class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTrayIcon *TrayIcon1;
        TPopupMenu *PopupMenu1;
        TMenuItem *A1;
        TMenuItem *DelNote1;
        TMenuItem *HideNote1;
        TMenuItem *Exit1;
        TMemo *Memo1;
        TPopupMenu *PopupMenu2;
        TMenuItem *SetTitle1;
        TMenuItem *SetFont1;
        TMenuItem *CloseNote1;
        TColorDialog *ColorDialog1;
        TMenuItem *SetBgcolor1;
        TMenuItem *HideNote2;
        TEdit *Edit1;
        TButton *Button1;
        TMenuItem *DelNote2;
        TMenuItem *SetAlert1;
        TTimer *Timer1;
        void __fastcall A1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall DelNote1Click(TObject *Sender);
        void __fastcall HideNote1Click(TObject *Sender);
        void __fastcall SetBgcolor1Click(TObject *Sender);
        void __fastcall SetFont1Click(TObject *Sender);
        void __fastcall CloseNote1Click(TObject *Sender);
        void __fastcall HideNote2Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall SetTitle1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall DelNote2Click(TObject *Sender);
        void __fastcall SetAlert1Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//import std in Unit1.cpp
extern std::list<TForm1 *> x;
//---------------------------------------------------------------------------
#endif
