#include <stdio.h>
#include <graphics.h>

#define ESC   27

int main(void) {
	int AreaX = 650, AreaY = 650;
  	int left = 10, top = 10; 
  	int bottom = AreaY - 10; 
  	int right = AreaX - 10;
  	int raio = 25;
  	int raioII = 17;
  	char tecla;
	
  	initwindow(AreaX, AreaY);
	setbkcolor(RGB(173, 216, 230)); //COR FUNDO
  	
	cleardevice();
  		
  	setfillstyle(1, RGB(0, 168, 107));	//COR FUNDO DO TABULEIRO
	bar(left, top, right, bottom);
    	
   	//BORDA1
    setcolor(RGB(255, 223, 0)); //COR RETÂNGULOS E LINHAS
	
    rectangle(left+30, top+30, right-30, bottom-30);
    rectangle(left+40, top+40, right-40, bottom-40);
    
    //BORDA2
	rectangle(left+110, top+110, right-110, bottom-110);
    rectangle(left+120, top+120, right-120, bottom-120);
    
    //BORDA3
	rectangle(left+190, top+190, right-190, bottom-190);
    rectangle(left+200, top+200, right-200, bottom-200); 
    	
	//CIRCULOS CANTOS 1
	setfillstyle(1, RGB(255, 223, 0)); //COR CÍRCULO
    circle(left+35, top+35, raio);
    fillellipse(left+35, top+35, raioII, raioII);
    
    circle(left+35, bottom-35, raio);
    fillellipse(left+35, bottom-35, raioII, raioII);
    
    circle(right-35, top+35, raio);
    fillellipse(right-35, top+35, raioII, raioII);
    
    circle(right-35, bottom-35, raio);
    fillellipse(right-35, bottom-35, raioII, raioII);
    	
    //CIRCULOS CANTOS 2	
	circle(left+115, top+115, raio);
    fillellipse(left+115, top+115, raioII, raioII);
    
    circle(left+115, bottom-115, raio);
    fillellipse(left+115, bottom-115, raioII, raioII);
    
    circle(right-115, top+115, raio);
    fillellipse(right-115, top+115, raioII, raioII);
    
    circle(right-115, bottom-115, raio);
    fillellipse(right-115, bottom-115, raioII, raioII);	
    
   	//CIRCULOS CANTOS 3
	circle(left+195, top+195, raio);
   	fillellipse(left+195, top+195, raioII, raioII);
    
    circle(left+195, bottom-195, raio);
    fillellipse(left+195, bottom-195, raioII, raioII);
    
    circle(right-195, top+195, raio);
    fillellipse(right-195, top+195, raioII, raioII);
    
   	circle(right-195, bottom-195, raio);
	fillellipse(right-195, bottom-195, raioII, raioII);	
		
	//CIRCULOS MEIO 1
    circle(left+35, AreaY/2, raio);
    fillellipse(left+35, AreaY/2, raioII, raioII);
    
    circle(right-35, AreaY/2, raio);
    fillellipse(right-35, AreaY/2, raioII, raioII);
    
    circle(AreaX/2, top+35, raio);
    fillellipse(AreaX/2, top+35, raioII, raioII);
   	
    
    circle(AreaX/2, bottom-35, raio);
	fillellipse(AreaX/2, bottom-35, raioII, raioII);
	
	//CIRCULOS MEIO 2
    circle(left+115, AreaY/2, raio);
    fillellipse(left+115, AreaY/2, raioII, raioII);
    
    circle(right-115, AreaY/2, raio);
    fillellipse(right-115, AreaY/2, raioII, raioII);
    
    circle(AreaX/2, top+115, raio);
    fillellipse(AreaX/2, top+115, raioII, raioII);
   	
    
    circle(AreaX/2, bottom-115, raio);
	fillellipse(AreaX/2, bottom-115, raioII, raioII);
    
    //CIRCULOS MEIO 3
    circle(left+195, AreaY/2, raio);
    fillellipse(left+195, AreaY/2, raioII, raioII);
    
    circle(right-195, AreaY/2, raio);
    fillellipse(right-195, AreaY/2, raioII, raioII);
    
    circle(AreaX/2, top+195, raio);
    fillellipse(AreaX/2, top+195, raioII, raioII);
   	
    circle(AreaX/2, bottom-195, raio);
	fillellipse(AreaX/2, bottom-195, raioII, raioII);
    	
    //LINHAS
    line(AreaX/2-5, top+35, AreaX/2-5, top+195);
    line(AreaX/2+5, top+35, AreaX/2+5, top+195);
    
    line(AreaX/2-5, bottom-35, AreaX/2-5, bottom-195);
    line(AreaX/2+5, bottom-35, AreaX/2+5, bottom-195);
    
    line(left+35, AreaY/2-5, left+195, AreaY/2-5);
    line(left+35, AreaY/2+5, left+195, AreaY/2+5);
    
    line(right-35, AreaY/2-5, right-195, AreaY/2-5);
    line(right-35, AreaY/2+5, right-195, AreaY/2+5);
    	
    //BOLINHAS BRANCAS
	setfillstyle(1, RGB(255, 255, 255)); //COR BOLINHA BRANCA
	
	fillellipse(AreaX/2, bottom-195, raioII-5, raioII-5);	
	fillellipse(AreaX/2, bottom-115, raioII-5, raioII-5);
	fillellipse(AreaX/2, bottom-35, raioII-5, raioII-5);
	fillellipse(left+35, AreaY/2, raioII-5, raioII-5);
	fillellipse(left+115, AreaY/2, raioII-5, raioII-5);
	
	//BOLINHAS PRETAS
	setfillstyle(1, RGB(0, 0, 0)); //COR BOLINHA PRETA
	
	fillellipse(AreaX/2, top+195, raioII-5, raioII-5);	
	fillellipse(AreaX/2, top+115, raioII-5, raioII-5);
	fillellipse(AreaX/2, top+35, raioII-5, raioII-5);
	fillellipse(left+195, AreaY/2, raioII-5, raioII-5);
	fillellipse(right-35, AreaY/2, raioII-5, raioII-5);
	fillellipse(right-115, AreaY/2, raioII-5, raioII-5);
	fillellipse(right-195, AreaY/2, raioII-5, raioII-5);
	
    	while(tecla != ESC){	
			if (kbhit())
      			tecla = getch();
		}
  	closegraph();
  	return(0);
}
