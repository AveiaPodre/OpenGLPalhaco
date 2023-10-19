// Bibliotecas utilizadas pelo OpenGL
#ifdef __APPLE__ // MacOS
    #define GL_SILENCE_DEPRECATION
    #include <GLUT/glut.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#else // Windows e Linux
    #include <GL/glut.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif

#include <cstdlib>

#include "circulo.h"
#define ESC 27

// Declaracoes antecipadas (forward) de funcoes para as funcoes callback do OpenGL
void init(void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void display(void);

/*
 * Funcao principal
 */
int main(int argc, char** argv){
    glutInit(&argc, argv); // Passagens de parametros C para o glut
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // Selecao do Modo do Display e do Sistema de cor utilizado
    glutInitWindowSize (800, 800);  // Tamanho da janela do OpenGL
    glutCreateWindow ("Palhaço"); // Da nome para uma janela OpenGL
    init(); // Chama a funcao init();
    glutReshapeFunc(reshape); //funcao callback para redesenhar a tela
    glutDisplayFunc(display); //funcao callback de desenho
    glutKeyboardFunc(keyboard); //funcao callback do teclado
    glutMainLoop(); // executa o loop do OpenGL
    return EXIT_SUCCESS; // retorna 0 para o tipo inteiro da funcao main()
}

/*
 * Inicializa alguns parametros do GLUT
 */
void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0); //Limpa a tela com a cor branca;
}

/*
 * Ajusta a projecao para o redesenho da janela
 */
void reshape(int w, int h){
	// Reinicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    // Definindo o Viewport para o tamanho da janela
	glViewport(0, 0, w, h);
	glOrtho (-400, 400, -400, 400, -1 ,1); 
    
	// muda para o modo GL_MODELVIEW (nao pretendemos alterar a projecao
	// quando estivermos desenhando na tela)
	glMatrixMode(GL_MODELVIEW);
}

/*
 * Funcao usada na funcao callback para controlar as teclas comuns (1 Byte) do teclado
 */
void keyboard(unsigned char key, int x, int y){
    switch (key) { // key - variavel que possui valor ASCII da tecla precionada
        case ESC: exit(EXIT_SUCCESS); break; //encerra o programa com sucesso
    }
}

/*
 * Funcao usada na funcao callback para desenhar na tela
 */
void display(void){
	//Limpa o Buffer de Cores e reinicia a matriz
    glClear(GL_COLOR_BUFFER_BIT); 
	glLoadIdentity();
	
	//corpo
	glPushMatrix();
		// forma do corpo
		glColor3f(0, 0, 1);
		glBegin(GL_QUADS);
			glVertex2f(-100, -100);
			glVertex2f(100, -100);
			glVertex2f(100, 100);
			glVertex2f(-100, 100);
		glEnd();
		
		//botões da roupa
		glColor3f(0, 1, 0);
		desenhaCirculo(20,30,true);
		glTranslatef(0, 60, 0);
		desenhaCirculo(20,30,true);
		glTranslatef(0, -120, 0);
		desenhaCirculo(20,30,true);
	glPopMatrix();		
	
	//cabeça
	glPushMatrix();
		glTranslatef(0, 200, 0); // centro da cabeça
		
		//cabeça		
		glPushMatrix();
			glColor3f(1, 1, 0);
			desenhaCirculo(100,30,true); 
		glPopMatrix();
		
		//nariz
		glPushMatrix();	
			glColor3f(1, 0, 0);
			desenhaCirculo(20,30,true);  
		glPopMatrix();
		
		//olhos
		glPushMatrix();
			glColor3f(0, 0, 0);
			glTranslatef(40, 40, 0);
			desenhaCirculo(20,30,true);
			glTranslatef(-80, 0, 0);
			desenhaCirculo(20,30,true);			   
		glPopMatrix();
		
		//boca
		glPushMatrix();
			glColor3f(0, 0, 0);
			glBegin(GL_QUADS);          
				glVertex2f(-40, -60);
				glVertex2f(40, -60);
				glVertex2f(40, -40);
				glVertex2f(-40, -40);
			glEnd();	
		glPopMatrix();
		
		//chapeu
		glPushMatrix();
			glColor3f(0, 0, 1);
			glBegin(GL_TRIANGLES);       
				glVertex2f(0, 200);
				glVertex2f(100, 100);
				glVertex2f(-100, 100);
			glEnd();	
		glPopMatrix();
		
	glPopMatrix();
	
	//braços
	glPushMatrix();               
		glPushMatrix(); 
			//braço direito                  
			glColor3f(1, 0, 0);  		
			glRotatef(45, 0, 0, 1);
			glTranslatef(200, 0, 0);
			glBegin(GL_QUADS);
				glVertex2f(-60, -40);
				glVertex2f(90, -40);
				glVertex2f(90, 40);
				glVertex2f(-60, 40);
			glEnd();
			
			//mão direita
			glColor3f(1, 1, 0);
			glTranslatef(140, 0, 0);
			desenhaCirculo(45,30,true);
		glPopMatrix();
		
		glPushMatrix();   
			//braço esquerdo               
			glColor3f(1, 0, 0);
			glRotatef(135, 0, 0, 1);
			glTranslatef(200, 0, 0);
			glBegin(GL_QUADS);
				glVertex2f(-60, -40);
				glVertex2f(90, -40);
				glVertex2f(90, 40);
				glVertex2f(-60, 40);
			glEnd();
			
			//mão esquerda
			glColor3f(1, 1, 0);
			glTranslatef(140, 0, 0);
			desenhaCirculo(45,30,true);
		glPopMatrix();	
	glPopMatrix();
	
	//pernas
	glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslatef(0, -100, 0);
		
		//perna direita
		glPushMatrix();
			glBegin(GL_QUADS);
				glVertex2f(100, -10);
				glVertex2f(100, -180);
				glVertex2f(10, -180);
				glVertex2f(10, -10);
			glEnd();	
		glPopMatrix();
		
		//perna esquerda
		glPushMatrix();
			glBegin(GL_QUADS);
				glVertex2f(-100, -10);
				glVertex2f(-100, -180);
				glVertex2f(-10, -180);
				glVertex2f(-10, -10);
			glEnd();
		glPopMatrix();
		
		//pés
		glColor3f(1, 1, 0);
		glTranslatef(0, -180, 0);
		
		//pé direito
		glPushMatrix();
			glBegin(GL_QUADS);
				glVertex2f(150, -10);
				glVertex2f(150, -50);
				glVertex2f(10, -50);
				glVertex2f(10, -10);
			glEnd();	
		glPopMatrix();
		
		//pé esquerdo
		glPushMatrix();
			glBegin(GL_QUADS);
				glVertex2f(-150, -10);
				glVertex2f(-150, -50);
				glVertex2f(-10, -50);
				glVertex2f(-10, -10);
			glEnd();	
		glPopMatrix();
	glPopMatrix();
	
	// manda o OpenGl renderizar as primitivas
	glFlush(); 

}
