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
        setcolor(WHITE);
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
        setlinestyle(SOLID_LINE,0,5);
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
        int w;
        while(!ismouseclick(WM_LBUTTONDOWN))
            delay(500);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if(!whichbox())//whichbox determines which box is clicked and returns 1 if the box is not repeated otherwise 0
            return ;
        draw();
        if(C>=5)
            w=checkwin();
            if(w==0 && C==9){
                winbroadcast(0);
                return;
            }
            if(w==0)
                return;
            drawwin(w);
            winbroadcast(1);
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
        return 0;
    }
    int checkwin(){
        if     (win[0] && win[1] && win[2]) //win by row 1
            return 1;
        else if(win[3] && win[4] && win[5]) // win by row 2
            return 2;
        else if(win[6] && win[7] && win[8]) //win by row 3
            return 3;
        else if(win[0] && win[3] && win[6]) //win by col 1
            return 4;
        else if(win[1] && win[4] && win[7]) //win by col 2
            return 5;
        else if(win[2] && win[5] && win[8]) //win by col 3
            return 6;
        else if(win[0] && win[4] && win[8]) // win by diagonal from left
            return 7;
        else if(win[2] && win[4] && win[6]) // win by diagonal fron right
            return 8;
        else
            return 0;

    }
    void drawwin(int x){
        C=9;
        setlinestyle(SOLID_LINE, 0, 5);
        setcolor(WHITE);
        switch(x){
            case 1:
                line(Whight/2 - Lbox, Whight/2 - Lbox, Whight/2 + Lbox, Whight/2 - Lbox);
                break;
            case 2:
                line(Whight/2 - Lbox, Whight/2, Whight/2 + Lbox, Whight/2);
                break;
            case 3:
                line(Whight/2 - Lbox, Whight/2 + Lbox, Whight/2 + Lbox, Whight/2 + Lbox);
                break;
            case 4:
                line(Whight/2 - Lbox, Whight/2 - Lbox, Whight/2 - Lbox, Whight/2 + Lbox);
                break;
            case 5:
                line(Whight/2, Whight/2 - Lbox, Whight/2, Whight/2 + Lbox);
                break;
            case 6:
                line(Whight/2 + Lbox, Whight/2 - Lbox, Whight/2 + Lbox, Whight/2 + Lbox);
                break;
            case 7:
                line(Whight/2 - Lbox, Whight/2 - Lbox, Whight/2 + Lbox, Whight/2 + Lbox);
                break;
            case 8:

                line(Whight/2 + Lbox, Whight/2 - Lbox, Whight/2 - Lbox, Whight/2 + Lbox);
                break;
        }
    }
    void winbroadcast(bool x){ //x=1 is win, x=0 id draw
        settextstyle(SANS_SERIF_FONT,0, 5);
        if(x){
            if(playerNo==1){
                setcolor(LIGHTRED);
                outtextxy(Whight/2+325, Whight/2-100, (char*)"Player X wins");
                return;
            }
            setcolor(LIGHTGREEN);
            outtextxy(Whight/2+325, Whight/2-100,(char*) "Player O wins");
            return;
        }
        setcolor(WHITE);
        outtextxy(Whight/2+325, Whight/2-100,(char*) "No One wins");
    }

};
void buttons(){
    setcolor(LIGHTCYAN);
    rectangle(Whight/2+325, Whight/2, Whight/2+500, Whight/2+100);
    outtextxy(Whight/2+350, Whight/2+30, (char*)"Again");
    rectangle(Whight/2+325, Whight/2+150, Whight/2+500, Whight/2+250);
    outtextxy(Whight/2+350, Whight/2+180, (char*)"Quit");
}
int buttonfun(){
    int px,py;
    while(!ismouseclick(WM_LBUTTONDOWN))
            delay(500);
    getmouseclick(WM_LBUTTONDOWN, px, py);
    if((px>Whight/2+325 && px<Whight/2+500) && (py>Whight/2 && py< Whight/2+100))
        return 1; //if button Again is pressed
    if((px>Whight/2+325 && px<Whight/2+500)&&(py>Whight/2+150 && py<Whight/2+250))
        return 0;
    return -1;
}
int main(void)
{
    proto *gamelook;
    player *p1, *p2;
    initwindow(Whight+300,Whight,"Tic Tac Toe");
    while(1){
        gamelook=new proto;
        p1= new player((short)1);
        p2= new player((short)2);
        while(1){
            if(C%2==0)
                p1->onclick();
            else
                p2->onclick();
            if(C==9)
                break;
        }
        buttons();
        while(1){
            int buttonsays=buttonfun();
            if(buttonsays==0)
                return 1;
            else if(buttonsays=1)
                break;
        }
        delete gamelook;
        delete p1;
        delete p2;
        C=0;
        for(int i=0;i<9;i++)
            check[i]=0;
            setfillstyle(SOLID_FILL, BLACK);
        floodfill(5,5,BROWN);//no boundary with brown color, so all screen will be painted
        printf("");//I don't know why it is needed
    }
    closegraph();
}
