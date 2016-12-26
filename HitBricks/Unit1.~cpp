#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1; //小球大小25*25
TShape *bricks[31];//初始化30个砖块对象数组,最后带一个挡板
static int score,countTime,leftTime=120;

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        initBricks();//调用初始化砖块函数
}

//小球横,纵坐标,dx是横向方向速,dy是纵向方向速
int x = 456;   // X_max:1000
int y = 456;   // Y_max:500  PanelSize:200*25
int dx = 1;
int dy = 1;

void __fastcall TForm1::Timer1Timer(TObject *Sender){ //10行代码,小球四边碰撞
        alert("time");
        Shape1->Left=x;
        Shape1->Top=y;
        x+=3*dx;//3倍速运行
        y-=3*dy;

        if(y<0) dy=-dy;                     //A.碰到x轴,y方向速度取反
        if(x>965|x<0) dx=-dx;               //B.碰到y轴跟挡板,x方向速度取反
        if(y>435||y<200) hitBrick();        //C.设置一个y1<y<y2,越过这个临界线,不判断碰撞.减少大量不必要的循环
        if(score>29) alert("pass");         //D.Succeed.
        if(y>476||leftTime<1) alert("end"); //E.Game Over.
}

int brickX;
int brickY;
int brickHeight =60;
int brickWidth =100;
int status =1;

//初始化砖块们
void __fastcall TForm1::initBricks(void){
        ShowMessage("空格键开始暂停,左右键控制挡板");
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
         if((tempX%10)==0){//层次遍历
                ++tempY;
                tempX=0;
         }
      } //初始化挡板
         bricks[30]=new TShape(NULL);
         bricks[30]->Height=25;
         bricks[30]->Width=200;
         bricks[30]->Left=360;
         bricks[30]->Top=472;
         bricks[30]->Parent=Form1;
}


/*小球碰到单个砖块的函数 --- 核心 : 九方格判断法
 *假设打到某一个砖块,即进入某个砖块的线性规划区域.砖块的长宽固定为100*60
 *分两个阶段进行:
 *①小球靠近砖块区域.以小球当前位置立方体(3*3)砖块中心,然后计算其它8个砖块
 *  每次只遍历最少3个,最多7个砖块,极大减少了遍历所有砖块所耗时间
 *  算法复杂度恒为常数级别O(1).
 *②然后进入正式的判断.小球当前坐标与某块砖块的区域重叠,视为撞到
 */

void __fastcall TForm1::hitBrick(void){
      /*1.找到小球所在砖块(虚拟)是第几个
       *2.计算出周围的8个砖块bricks[i]值.(即第几个砖块,从而砖块的x(Left),y(Top),visible全部获得了)
       */
        int ballX = Shape1->Left;
        int ballY = Shape1->Top;
        int ballRow = ballY/60;
        int ballColumn = ballX/100;
        int ballIndex =ballRow*10+ballColumn+1;//算出来的是小球所在砖块(虚拟)的index
        int brickIndex;
        int tempBricks[9]={ballIndex-11,ballIndex-10,ballIndex-9,ballIndex-1,
        ballIndex,ballIndex+1,ballIndex+9,ballIndex+10,ballIndex+11};//周围的九个砖块index
        if(ballX<bricks[30]->Left+200&ballX>bricks[30]->Left&ballY>bricks[30]->Top-15 ) dy=1; //打到挡板
        for(int i=0;i<9;i++){
        brickIndex = tempBricks[i];
        if(brickIndex>-1&&brickIndex<30&&bricks[brickIndex]->Visible==true){//只在边界内跟当前砖块visible为true判断
        if(ballX>bricks[brickIndex]->Left&&ballX<(bricks[brickIndex]->Left)+100
        &&ballY>bricks[brickIndex]->Top&&ballY<(bricks[brickIndex]->Top)+60){//砖块的矩形区域
               bricks[brickIndex]->Visible=false;
               Label1->Caption=AnsiString("Score:")+(++score);//计分
               dy=-dy;
               break; //hit one then jump out loop
        }
     }
   }
}

//挡板的左右位移,空格控制开始暂停
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

//抽取一下基本的状态
void __fastcall TForm1::alert(AnsiString status){
        ++countTime;
      if(status=="pass"){
      ShowMessage("Succeed!恭喜通关,");
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







