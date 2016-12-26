//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *Shape1;//Ð¡Çò
        TTimer *Timer1;
        TLabel *Label1;
        TLabel *Label2;//µ²°å
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);


private:
        	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        //void hitWall(void);
        void __fastcall TForm1::initBricks(void);
        void __fastcall TForm1::hitBrick(void);
        void __fastcall TForm1::alert(AnsiString status);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
