#include <stdio.h>
#include <graphics.h>
#include <time.h>

#define ESC   27
#define LEFT  75
#define RIGHT 77
#define UP    72
#define DOWN  80

struct TStars {
	int starX, starY; // coordenadas X e Y
	int starC; // cor do pixel
	int grandezaI, grandezaII; // 1 para primeira grandeza e 2 para segunda grandeza
};

int TamX, TamY;

TStars GeraPixel();
// Essa função desenha os pixels na tela

TStars GeraEstrelasI();
// Essa função desenha as estrelas com a primeira grandeza

TStars GeraEstrelasII();
// Essa função desenha as estrelas com a segunda grandeza

void DesenhaNave(int*v);
// Essa função desenha o triângulo

void RecriaNave(int*v);
// Essa função recria o triângulo

void MoveCima(int*v, int*passo);
// Essa função move a nave pra cima

void MoveBaixo(int*v, int*passo);
// Essa função move a nave pra baixo

void MoveEsq(int*v, int*passo);
// Essa função move a nave pra esquerda

void MoveDir(int*v, int*passo);
// Essa função move a nave pra direita




int main() {
	char tecla = 0;
	int pg;
	int ContP = 0, ContSI = 0, ContSII = 0;
	int i = 0;
	int passo = 10;

	TStars *Pixel;
	TStars *EstrelaI;
	TStars *EstrelaII;
	EstrelaI = NULL;
	EstrelaII = NULL;
	Pixel = NULL;
	srand(time(NULL));
	
	printf("Digite a largura da tela: "); scanf("%d", &TamX);
	
	TamY = TamX * 0.666667;
	
	initwindow(TamX  ,TamY , "N1.D", 50, 5);
	
	//Gera pixels
	for (i = 0; i < TamX*0.6 ; i++) {
		ContP++;
        Pixel = (TStars *)realloc(Pixel, sizeof(TStars) * ContP);
        Pixel[ContP-1] = GeraPixel(); 
	}
	
	//Gera Estrelas 
	for (i = 0; i < TamX*0.08; i++) {
		ContSI++;
		EstrelaI = (TStars *)realloc(EstrelaI, sizeof(TStars) * ContSI);
		EstrelaI[ContSI-1] = GeraEstrelasI();
		ContSII++;
		EstrelaII = (TStars *)realloc(EstrelaII, sizeof(TStars) * ContSII);
		EstrelaII[ContSII-1] = GeraEstrelasII(); 
	}
	
	//desenho nave
	int nave[6]; nave[0] = TamX/2; nave[1] = TamY/2; nave[2] = nave[0] -90; nave[3] = nave[1] +70; nave[4] = nave[0] + 90; nave[5] = nave[1] + 70;
	
	while(tecla != ESC) {
		
		if (pg == 1) pg = 2; else pg = 1;
		//alterna a página de desenho. 
		setactivepage(pg);
		
		cleardevice(); 
		//desenha pixels
		for (i = 0; i < TamX*0.6 ; i++) {
        	putpixel(Pixel[i].starX, Pixel[i].starY, Pixel[i].starC);
    	}
    	
    	//desenha Estrelas
    	for (i = 0; i < TamX*0.08; i++) {
    		setcolor(EstrelaI[i].starC);
    		setfillstyle(1, EstrelaI[i].starC);
    		fillellipse(EstrelaI[i].starX, EstrelaI[i].starY, EstrelaI[i].grandezaI, EstrelaI[i].grandezaI);
    		fillellipse(EstrelaII[i].starX, EstrelaII[i].starY, EstrelaII[i].grandezaII, EstrelaII[i].grandezaII);
    	}
    	
    	//efeito piscante
    	for (i = 0; i < TamX * 0.08; i++) {
  			setcolor (RGB (rand()%40+215, rand()%40+215, rand()%40+215));
  			circle (EstrelaI[i].starX, EstrelaI[i].starY, EstrelaI[i].grandezaI);
  			circle (EstrelaI[i].starX, EstrelaI[i].starY, EstrelaI[i].grandezaI-1);
    	}
    	
    	//desnha nave
    	DesenhaNave(nave);
		
		//torna visual
		setvisualpage(pg);
		
		//movimentação
		if (GetKeyState(VK_UP)&0x80){		//seta UP
			MoveCima(nave,&passo);		
		}
		
		if (GetKeyState(VK_DOWN)&0x80){		//seta DOWN
			MoveBaixo(nave,&passo);		
		}
		
		if (GetKeyState(VK_LEFT)&0x80){		//seta lEFT
			MoveEsq(nave,&passo);
		}
		
		if (GetKeyState(VK_RIGHT)&0x80){	//seta RIGHT
			MoveDir(nave,&passo);
		}
		
		fflush(stdin);
		if (kbhit()){
      		tecla = getch();
      		
      		if (tecla == 32){ 	//recria a nave com a tecla Espaço
      			RecriaNave(nave);	
      			tecla = 0;
			}
			
			if (tecla == 86 || tecla == 118) { //viagem interestrelar com a tecla V ou V	
				
				for (i=0; i<ContP; i ++) {		//gera novas posições dos pixels
					Pixel[i] = GeraPixel();
				}
				
				for (i=0; i<ContSI; i++) {		//gera novas posições da EstrelaI
					EstrelaI[i] = GeraEstrelasI();
				}
				
				for (i=0; i<ContSII; i++) {		//gera novas posições da EstrelaII
					EstrelaII[i] = GeraEstrelasII();
				}
				tecla = 0;
			}
		}
	}
	free(EstrelaI);
	free(EstrelaII);
	free(Pixel);
	closegraph();
	return 0;
}



TStars GeraPixel() {
   TStars p;
  
   p.starC = RGB(rand()%256, rand()%256, rand()%256);
   p.starX = rand()%TamX;
   p.starY = rand()%TamY;   
   
   return p;
}

TStars GeraEstrelasI() {
	TStars s;
	
	s.starC = RGB(rand()%256, rand()%256, rand()%256);
	s.starX = rand()%TamX;
	s.starY = rand()%TamY;
	s.grandezaI = rand()%6;
	
	return s;
}
TStars GeraEstrelasII() {
	TStars s;
	
	s.starC = RGB(rand()%256, rand()%256, rand()%256);
	s.starX = rand()%TamX;
	s.starY = rand()%TamY;
	s.grandezaII = rand()%5;
	
	return s;
}

void DesenhaNave(int*v){
	setcolor(RGB(255,0,0));
  	setfillstyle(1, RGB(0,0,255));
	fillpoly(3, v);
    drawpoly(3, v);
}

void RecriaNave(int*v) {
	v[0] = 100+rand()%((TamX-99)-100);
	v[1] = rand()%(TamY-29);
	v[2] = v[0]+90;
	v[3] = v[1]+70;
	v[4] = v[0]-90;
	v[5] = v[1]+70;
}

void MoveCima(int*v, int*passo) {
	
	for(int i = 1;i<6;i+=2){
		v[i] -=*passo;
	}
}

void MoveBaixo(int*v, int*passo) {
	
	for(int i = 1;i<6;i+=2){
		v[i] +=*passo;
	}
}

void MoveEsq(int*v, int*passo) {
	
	for(int i = 0;i<5;i+=2){
		v[i] -=*passo;
	}
}

void MoveDir(int*v, int*passo) {
	
	for(int i = 0;i<5;i+=2){
		v[i] +=*passo;
	}
}
