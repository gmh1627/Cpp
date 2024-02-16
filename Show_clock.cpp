#include<graphics.h>
#include<conio.h>
#include<math.h>
#define High 480 //游戏画面尺寸
#define Width 640
#define PI 3.14159
int main(void){
	initgraph(Width,High);//初始化绘图窗口
	int center_x,center_y;//中心点的坐标，也是钟表的坐标
	center_x=Width/2;
	center_y=High/2;
	int secondLength=Width/7;//秒针的长度
	int minuteLength=Width/6;//分针的长度
	int hourLength=Width/5;//时针的长度
	int secondEnd_x,secondEnd_y;//秒针的终点
	int minuteEnd_x,minuteEnd_y;//分针的终点
	int hourEnd_x,hourEnd_y;//时针的终点
	float secondAngle=0;//秒针对应的角度
	float minuteAngle=0;//分针对应的角度
	float hourAngle=0;//时针对应的角度
	SYSTEMTIME ti;//定义保存当前时间的变量
	while(1){
        //绘制一个简单的表盘
        setlinestyle(PS_SOLID,1);//设置表盘边的粗细
        setcolor(WHITE);//设置表盘边的颜色
        circle(center_x,center_y,Width/4);//画表盘
		//画刻度
        int x,y,i;
        for(i=0;i<60;i++){
            x=center_x+int(Width/4.3*sin(PI*2*i/60));
            y=center_y+int(Width/4.3*cos(PI*2*i/60));
            if(i%15==0)
                bar(x-5,y-5,x+5,y+5);
            else if(i%5==0)
                circle(x,y,3);
            else
                putpixel(x,y,WHITE);
        }
        outtextxy(center_x-25,center_y+Width/6,"我的时钟");
        outtextxy(center_x-120,High-60,"[时针: 红色]  [分针: 蓝色]  [秒针: 白色]");
        GetLocalTime(&ti);//获取当前时间
        //秒针角度的变化
        secondAngle=ti.wSecond*2*PI/60;
        //一圈一共2*PI，一圈60秒，一秒钟秒针走过的角度为2*PI/60
        //由角度决定的秒针终点坐标
		//分针角度的变化
        minuteAngle=ti.wMinute*2*PI/60;
        //一圈一共2*PI，一圈60分，一分钟秒针走过的角度为2*PI/60
        //时针角度的变化
        hourAngle=ti.wHour*2*PI/12;
        //一圈一共2*PI，一圈12时，一小时时针走过的角度为2*PI/12
		//由角度决定的秒针终点坐标
        secondEnd_x=center_x+secondLength*sin(secondAngle);
        secondEnd_y=center_y-secondLength*cos(secondAngle);
        //由角度决定的分针终点坐标
        minuteEnd_x=center_x+minuteLength*sin(minuteAngle);
        minuteEnd_y=center_y-minuteLength*cos(minuteAngle);
        //由角度决定的时针终点坐标
        hourEnd_x=center_x+hourLength*sin(hourAngle);
        hourEnd_y=center_y-hourLength*cos(hourAngle);
		//画秒针
        setlinestyle(PS_SOLID,2);//画实线,宽度为两个像素
        setcolor(WHITE);
        line(center_x,center_y,secondEnd_x,secondEnd_y);
        //画分针
        setlinestyle(PS_SOLID,4);//画实线,宽度为4个像素
        setcolor(BLUE);
        line(center_x,center_y,minuteEnd_x,minuteEnd_y);
        //画时针
        setlinestyle(PS_SOLID,6);//画实线,宽度为6个像素
        setcolor(RED);
        line(center_x,center_y,hourEnd_x,hourEnd_y);
        Sleep(1000);//1秒
		setcolor(BLACK);
        setlinestyle(PS_SOLID,2);
        line(center_x,center_y,secondEnd_x,secondEnd_y);//隐藏前一帧的秒针
        setlinestyle(PS_SOLID,4);
        line(center_x,center_y,minuteEnd_x,minuteEnd_y);//隐藏前一帧的分针
        setlinestyle(PS_SOLID,6);
        line(center_x,center_y,hourEnd_x,hourEnd_y);//隐藏前一帧的时针
		}
	getch();
	closegraph();//关闭绘图窗口
	return 0;
}