#include <iostream>
#include <graphics.h>
#define Whight 750
#define Lbox 200 //length of any 9 boxes
short int C=0;
bool check[9]={0,0,0,0,0,0,0,0,0};
class proto{
public:
    proto(){
        setlinestyle(SOLID_LINE, 0, 5);
        rectangle(Whight/2-(Lbox*3)/2, Whight/2-(Lbox*3)/2, Whight/2+(Lbox*3)/2, Whight/2+(Lbox*3)/2);
        line(Whight/2-Lbox/2, Whight/2-(Lbox*3)/2, Whight/2-Lbox/2, Whight/2+(Lbox*3)/2);
        line(Whight/2+Lbox/2, Whight/2-(Lbox*3)/2, Whight/2+Lbox/2, Whight/2+(Lbox*3)/2);
        line(Whight/2-(Lbox*3)/2, Whight/2 -Lbox/2, Whight/2+(Lbox*3)/2, Whight/2-Lbox/2);
        line(Whight/2-(Lbox*3)/2, Whight/2+Lbox/2, Whight/2+(Lbox*3)/2, Whight/2+Lbox/2);
    }
};
class player{
    int x,y;
    short int playerNo;
    short int win[9]={0,0,0,0,0,0,0,0,0};
public:
    player(short int x):playerNo(x){}
    void draw(){
        if(playerNo==1){
            setcolor(LIGHTRED);
            line(x-57, y-57, x+57, y+57);
            line(x-57, y+57, x+57, y-57);
            C++;
        }
        else{
            setcolor(LIGHTGREEN);
            circle(x, y, 80);
            C++;
        }
    }
    void onclick(){
        while(!ismouseclick(WM_LBUTTONDOWN))
            delay(500);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if(!whichbox())//whichbox determines which box is clicked and returns 1 if the box is not repeated otherwise 0
            return ;
        draw();
    }
    bool whichbox(){
        if(x>(Whight/2-(Lbox*3)/2) && x<(Whight/2-Lbox/2)){
            x=Whight/2 - Lbox;
            if((y>Whight/2-(Lbox*3)/2) && (y<Whight/2-Lbox/2)){ //position 0
                y=Whight/2 - Lbox;
                if(check[0])
                    return 0;
                check[0]=1;
                win[0]=playerNo;
                return 1;
            }
            else if(y>Whight/2 -Lbox/2 && y<Whight/2 + Lbox/2){ //position 3
                y=Whight/2;
                if(check[3])
                    return 0;
                check[3]=1;
                win[3]=playerNo;
                return 1;
            }
            else if(y>Whight/2 + Lbox/2 && y<Whight/2 + (Lbox*3)/2){    //position 6
                y=Whight/2 + Lbox;
                if(check[6])
                    return 0;
                check[6]=1;
                win[6]=playerNo;
                return 1;
            }
        }
        else if(x>(Whight/2-Lbox/2) && x<(Whight/2+Lbox/2)){
            x=Whight/2;
            if((y>Whight/2-(Lbox*3)/2) && (y<Whight/2-Lbox/2)){ //position 1
                y=Whight/2 - Lbox;
                if(check[1])
                    return 0;
                check[1]=1;
                win[1]=playerNo;
                return 1;
            }
            else if(y>Whight/2 -Lbox/2 && y<Whight/2 + Lbox/2){ //position 4
                y=Whight/2;
                if(check[4])
                    return 0;
                check[4]=1;
                win[4]=playerNo;
                return 1;
            }
            else if(y>Whight/2 + Lbox/2 && y<Whight/2 + (Lbox*3)/2){    //position 7
                y=Whight/2 + Lbox;
                if(check[7])
                    return 0;
                check[7]=1;
                win[7]=playerNo;
                return 1;
            }
        }
        else if(x>(Whight/2+Lbox/2) && x<(Whight/2+(Lbox*3)/2)){
            x=Whight/2 + Lbox;
            if((y>Whight/2-(Lbox*3)/2) && (y<Whight/2-Lbox/2)){ //position 2
                y=Whight/2 - Lbox;
                if(check[2])
                    return 0;
                check[2]=1;
                win[2]=playerNo;
                return 1;
            }
            else if(y>Whight/2 -Lbox/2 && y<Whight/2 + Lbox/2){ //position 5
                y=Whight/2;
                if(check[5])
                    return 0;
                check[5]=1;
                win[5]=playerNo;
                return 1;
            }
            else if(y>Whight/2 + Lbox/2 && y<Whight/2 + (Lbox*3)/2){ //position 8
                y=Whight/2 + Lbox;
                if(check[8])
                    return 0;
                check[8]=1;
                win[8]=playerNo;
                return 1;
            }
        }
    }
};
int main(void)
{
    int x,y;
    initwindow(Whight+300,Whight,"Tic Tac Toe");
    proto gameLook;
    player p1((short)1), p2((short)2);
    while(1){
        if(C%2==0)
            p1.onclick();
        else
            p2.onclick();
        if(C==9)
            break;
    }
    getch();
    closegraph();
}
