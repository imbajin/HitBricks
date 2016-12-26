#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1; //С���С25*25
TShape *bricks[31];//��ʼ��30��ש���������,����һ������
static int score,countTime,leftTime=120;

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        initBricks();//���ó�ʼ��ש�麯��
}

//С���,������,dx�Ǻ�������,dy����������
int x = 456;   // X_max:1000
int y = 456;   // Y_max:500  PanelSize:200*25
int dx = 1;
int dy = 1;

void __fastcall TForm1::Timer1Timer(TObject *Sender){ //10�д���,С���ı���ײ
        alert("time");
        Shape1->Left=x;
        Shape1->Top=y;
        x+=3*dx;//3��������
        y-=3*dy;

        if(y<0) dy=-dy;                     //A.����x��,y�����ٶ�ȡ��
        if(x>965|x<0) dx=-dx;               //B.����y�������,x�����ٶ�ȡ��
        if(y>435||y<200) hitBrick();        //C.����һ��y1<y<y2,Խ������ٽ���,���ж���ײ.���ٴ�������Ҫ��ѭ��
        if(score>29) alert("pass");         //D.Succeed.
        if(y>476||leftTime<1) alert("end"); //E.Game Over.
}

int brickX;
int brickY;
int brickHeight =60;
int brickWidth =100;
int status =1;

//��ʼ��ש����
void __fastcall TForm1::initBricks(void){
        ShowMessage("�ո����ʼ��ͣ,���Ҽ����Ƶ���");
        int tempX = 0;
        int tempY = 0;
        for(int i=0;i<30;i++){
         bricks[i]=new TShape(NULL);
         bricks[i]->Height=brickHeight;
         bricks[i]->Width=brickWidth;
         bricks[i]->Left=100*tempX;
         bricks[i]->Top=60*tempY;
         bricks[i]->Brush->Color=i*60;
         bricks[i]->Parent=Form1;
         ++tempX;
         if((tempX%10)==0){//��α���
                ++tempY;
                tempX=0;
         }
      } //��ʼ������
         bricks[30]=new TShape(NULL);
         bricks[30]->Height=25;
         bricks[30]->Width=200;
         bricks[30]->Left=360;
         bricks[30]->Top=472;
         bricks[30]->Parent=Form1;
}


/*С����������ש��ĺ��� --- ���� : �ŷ����жϷ�
 *�����ĳһ��ש��,������ĳ��ש������Թ滮����.ש��ĳ���̶�Ϊ100*60
 *�������׶ν���:
 *��С�򿿽�ש������.��С��ǰλ��������(3*3)ש������,Ȼ���������8��ש��
 *  ÿ��ֻ��������3��,���7��ש��,��������˱�������ש������ʱ��
 *  �㷨���ӶȺ�Ϊ��������O(1).
 *��Ȼ�������ʽ���ж�.С��ǰ������ĳ��ש��������ص�,��Ϊײ��
 */

void __fastcall TForm1::hitBrick(void){
      /*1.�ҵ�С������ש��(����)�ǵڼ���
       *2.�������Χ��8��ש��bricks[i]ֵ.(���ڼ���ש��,�Ӷ�ש���x(Left),y(Top),visibleȫ�������)
       */
        int ballX = Shape1->Left;
        int ballY = Shape1->Top;
        int ballRow = ballY/60;
        int ballColumn = ballX/100;
        int ballIndex =ballRow*10+ballColumn+1;//���������С������ש��(����)��index
        int brickIndex;
        int tempBricks[9]={ballIndex-11,ballIndex-10,ballIndex-9,ballIndex-1,
        ballIndex,ballIndex+1,ballIndex+9,ballIndex+10,ballIndex+11};//��Χ�ľŸ�ש��index
        if(ballX<bricks[30]->Left+200&ballX>bricks[30]->Left&ballY>bricks[30]->Top-15 ) dy=1; //�򵽵���
        for(int i=0;i<9;i++){
        brickIndex = tempBricks[i];
        if(brickIndex>-1&&brickIndex<30&&bricks[brickIndex]->Visible==true){//ֻ�ڱ߽��ڸ���ǰש��visibleΪtrue�ж�
        if(ballX>bricks[brickIndex]->Left&&ballX<(bricks[brickIndex]->Left)+100
        &&ballY>bricks[brickIndex]->Top&&ballY<(bricks[brickIndex]->Top)+60){//ש��ľ�������
               bricks[brickIndex]->Visible=false;
               Label1->Caption=AnsiString("Score:")+(++score);//�Ʒ�
               dy=-dy;
               break; //hit one then jump out loop
        }
     }
   }
}

//���������λ��,�ո���ƿ�ʼ��ͣ
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift){
      if(Key==37&&bricks[30]->Left>0){
                 bricks[30]->Left-=25;
        }
          if(Key==39&&bricks[30]->Left<790){
                bricks[30]->Left+=15;
        }
        if(Key==32&&(Timer1->Enabled==false)){
                 Timer1->Enabled=true;
        }else if(Key==32&&(Timer1->Enabled==true)){
                 Timer1->Enabled=false;
        }
}

//��ȡһ�»�����״̬
void __fastcall TForm1::alert(AnsiString status){
        ++countTime;
      if(status=="pass"){
      ShowMessage("Succeed!��ϲͨ��,");
      }
      if(status=="end"){//Game over
       Timer1->Enabled=false;
       ShowMessage("Game Over,Please Try Again!");
       Sleep(1200);
       this->Close();
      }
      if(status=="time"&&countTime%70==0){
      Label2->Caption=AnsiString("LeftTime:")+(--leftTime);
      }


}







