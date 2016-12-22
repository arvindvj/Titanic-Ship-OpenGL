#include<GL/glut.h>

void ice();
void display1();
void display2();
void display3();
void display4();
void plane();
void ship();
void water();

GLint a=0,b=0,c=0,d=130,e=-100,f=-5,g=0,h=0,x=100,i=0,w=0;
GLfloat theta=0.0;

void light()
{
	
	GLfloat mat_ambient[]={1.0f,1.0f,1.0f,1.0f};
	GLfloat mat_diffuse[]={1.0f,1.0f,1.0f,1.0f};
	GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
	GLfloat mat_shininess[]={50.0f};
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_ambient);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_ambient);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_ambient);
		
}

void update(int value)
{
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	a+=20.0;
	w-=50;
	if(w<=-80)
		w=0;
	
		if(a==100||a==120||a==250||a==500||b==100||b==150||b==600||b==620||c==120||c==150||c==170)
		{
			
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);	
			light();
			glColor3f(1.0,1.0,1.0);		
			
			glBegin(GL_POLYGON);
				glVertex2f(200.0,700.0);
				glVertex2f(220.0,700.0);
				glVertex2f(420.0,550.0);
				glVertex2f(600.0,450.0);
	        glEnd();
	
			glFlush();
		}		
		glutPostRedisplay();
	
		glutTimerFunc(200,update,0);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	display1();

	if(a>950)
	{
		
		b+=10;
		display2();
		
	}
	if(b>600 )
	{
		d-=5;
		display4();

	}
	if(d<20)
    {
		c+=10;
		h+=25;
		display3();
	}
	glFlush();
}


void display1()
{   
	glPushMatrix();
	glTranslated(a,70,0.0);
	ship();
	glPopMatrix();
	water();
	
}

void display2()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	ice();
	
	glPushMatrix();
	glTranslated(b,70,0.0);
	ship();
	glPopMatrix();
	water();
}

void display3()
{
	glClear(GL_COLOR_BUFFER_BIT);
	x-=5;
	glPushMatrix();
	glTranslated(c,x,0.0);
	glRotated(-15,0,0,1);
	ship();
	glPopMatrix();
	water();
	plane();
			
}

void display4()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslated(500,50,0);
	glScaled(20,10,0);
	glBegin(GL_POLYGON);
		glVertex2f(5.5,2.5);
		glVertex2f(12.5,19.5);
		glVertex2f(15,19.5);
		glVertex2f(12.5,19.5);
		glVertex2f(13.5,18.5);
		glVertex2f(16.5,20.5);
		glVertex2f(17.5,18.5);
		glVertex2f(18.5,3.5);
		glVertex2f(19,3);
		glVertex2f(19.5,2.5);
	glEnd();
	glPopMatrix();
	
	e-=0.05;
	f-=5;
	g+=10;
		
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslated(e,f,0);
	glTranslated(500,50,0);
	glScaled(20,10,0);
	glBegin(GL_POLYGON);
		glVertex2f(5.5,2.5);
		glVertex2f(6,3);
		glVertex2f(8.25,3.5);
		glVertex2f(8.5,18.5);
		glVertex2f(15,17);
		glVertex2f(12.5,19.5);
		glVertex2f(8.5,9.5);
		glVertex2f(12.5,2.5);
        glVertex2f(5.5,2.5);  
    glEnd(); 
	glPopMatrix();
    glPushMatrix();
	glTranslated(g,0,0.0);
	glTranslated(600,70,0.0);
	ship();
	glPopMatrix();
	water();
	
	
    	

}

		

/*To draw plane*/

void plane()
{
	glPushMatrix();
	glColor3f(1.3,1.0,1.0);
	glTranslated(h,550,0);
	glScaled(7,5,0);
	glBegin(GL_POLYGON);
		glVertex2d(20,10);
		glVertex2d(17,14);
		glVertex2d(7,14);
		glVertex2d(5.5,20);
		glVertex2d(4.5,20);
		glVertex2d(4.5,14);
		glVertex2d(1.5,14);
		glVertex2d(3,10);
		glVertex2d(1.5,7);
		glVertex2d(17,7);
		glVertex2d(20,10);
	glEnd();
	glColor3f(0.0,0.0,0.5);
	glBegin(GL_POLYGON);
		glVertex2d(5.3,12);
		glVertex2d(6.8,12);
		glVertex2d(6.8,9.5);
		glVertex2d(5.3,9.5);
		glVertex2d(5.3,12);
	glEnd();
	glColor3f(0.0,0.0,0.5);
	glBegin(GL_POLYGON);
		glVertex2d(8,12);
		glVertex2d(9.5,12);
		glVertex2d(9.5,9.5);
		glVertex2d(8,9.5);
		glVertex2d(8,12);
	glEnd();
	glColor3f(0.0,0.0,0.5);
	glBegin(GL_POLYGON);
		glVertex2d(10.5,12);
		glVertex2d(12.5,12);
		glVertex2d(12.5,9.5);
		glVertex2d(10.5,9.5);
		glVertex2d(10.5,12);
	glEnd();
	glPopMatrix();
}


/*To draw water*/
void water()
{
		glPushMatrix();
		//glPushMatrix();
		glTranslated(w,0,0.0);
		glColor3f(0.1,0.5,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0,100);
		glVertex2f(10,96); 
		glVertex2f(25,98);		
		glVertex2f(39,94);
		glVertex2f(50,92);
		glVertex2f(70,98);
		glVertex2f(85,95);
		glVertex2f(95,96);
		glVertex2f(110,99);
		glVertex2f(128,97);
		glVertex2f(139,95);
		glVertex2f(145,97);
		glVertex2f(155,99);
		glVertex2f(172,95);
		glVertex2f(195,96);
		glVertex2f(212,95);
		glVertex2f(254,92);
		glVertex2f(284,96);
		glVertex2f(344,98);
		glVertex2f(360,93);
		glVertex2f(390,94);
		glVertex2f(410,99);
		glVertex2f(450,94);
		glVertex2f(485,100);
		glVertex2f(502,92);
		glVertex2f(552,92);
		glVertex2f(592,96);
		glVertex2f(630,105);
		glVertex2f(680,93);
		glVertex2f(720,97);
		glVertex2f(750,93);
		glVertex2f(800,95);
		glVertex2f(850,97);
		glVertex2f(880,108);
		glVertex2f(900,96);
		glVertex2f(920,93);
		glVertex2f(950,99);
		glVertex2f(980,92);
		glVertex2f(1000,99);
		glVertex2f(1000,0);
		glVertex2f(1600,10);
		glVertex2f(3000,280);
		glEnd();
		glPopMatrix();
}

/* TO DRAW SHIP */
void ship()
{

	glScaled(20,20,0);
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
		glVertex2f(3.5,5.5);
		glVertex2f(3.5,8.5);
		glVertex2f(19.5,8.5);
		glVertex2f(19.5,5.5);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1,5.5);
		glVertex2f(4,1);
		glVertex2f(19,1);
		glVertex2f(21.5,5.5);
	glEnd();
	glColor3f(0.7,0.4,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(4,5.5);
		glVertex2f(4,8);
		glVertex2f(5,8);
		glVertex2f(5,5.5);
	glEnd();
	glColor3f(0.9,0.9,0.9);
	glBegin(GL_POLYGON);
		glVertex2f(7,7.5);
		glVertex2f(7,8);
		glVertex2f(10,8);
		glVertex2f(10,7.5);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(11.5,7.5);
		glVertex2f(11.5,8);
		glVertex2f(15,8);
		glVertex2f(15,7.5);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(16,7.5);
		glVertex2f(16,8);
		glVertex2f(19,8);
		glVertex2f(19,7.5);
	glEnd();
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
		glVertex2f(4.5,8.5);
		glVertex2f(4.5,10);
		glVertex2f(18.5,10);
		glVertex2f(18.5,8.5);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(5.5,10);
		glVertex2f(5.5,12.9);
		glVertex2f(7,12.9);
		glVertex2f(7,10);
	glEnd();
	glColor3f(0.9,0.5,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(5.5,12.9);
		glVertex2f(5.5,13.5);
		glVertex2f(7,13.5);
		glVertex2f(7,12.9);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(8.5,10);
		glVertex2f(8.5,12.9);
		glVertex2f(10,12.9);
		glVertex2f(10,10);
	glEnd();
	glColor3f(0.9,0.5,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(8.5,12.9);
		glVertex2f(8.5,13.5);
		glVertex2f(10,13.5);
		glVertex2f(10,12.9);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(11.5,10);
		glVertex2f(11.5,12.9);
		glVertex2f(13,12.9);
		glVertex2f(13,10);
	glEnd();
	glColor3f(0.9,0.5,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(11.5,12.9);
		glVertex2f(11.5,13.5);
		glVertex2f(13,13.5);
		glVertex2f(13,12.9);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(14.5,10);
		glVertex2f(14.5,12.9);
		glVertex2f(16,12.9);
		glVertex2f(16,10);
	glEnd();
	glColor3f(0.9,0.5,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(14.5,12.9);
		glVertex2f(14.5,13.5);
		glVertex2f(16,13.5);
		glVertex2f(16,12.9);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(1.5,5.5);
		glVertex2f(1.5,6.5);
		glVertex2f(2,6.2);
		glVertex2f(3,6.2);
		glVertex2f(3.5,6.5);
		glVertex2f(3.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(3.5,5.5);
		glVertex2f(3.5,6.5);
		glVertex2f(4,6.2);
		glVertex2f(5,6.2);
		glVertex2f(5.5,6.5);
		glVertex2f(5.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(5.5,5.5);
		glVertex2f(5.5,6.5);
		glVertex2f(6,6.2);
		glVertex2f(7,6.2);
		glVertex2f(7.5,6.5);
		glVertex2f(7.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(7.5,5.5);
		glVertex2f(7.5,6.5);
		glVertex2f(8,6.2);
		glVertex2f(9,6.2);
		glVertex2f(9.5,6.5);
		glVertex2f(9.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(9.5,5.5);
		glVertex2f(9.5,6.5);
		glVertex2f(10,6.2);
		glVertex2f(11,6.2);
		glVertex2f(11.5,6.5);
		glVertex2f(11.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(11.5,5.5);
		glVertex2f(11.5,6.5);
		glVertex2f(12,6.2);
		glVertex2f(13,6.2);
		glVertex2f(13.5,6.5);
		glVertex2f(13.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(13.5,5.5);
		glVertex2f(13.5,6.5);
		glVertex2f(14,6.2);
		glVertex2f(15,6.2);
		glVertex2f(15.5,6.5);
		glVertex2f(15.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(15.5,5.5);
		glVertex2f(15.5,6.5);
		glVertex2f(16,6.2);
		glVertex2f(17,6.2);
		glVertex2f(17.5,6.5);
		glVertex2f(17.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(17.5,5.5);
		glVertex2f(17.5,6.5);
		glVertex2f(18,6.2);
		glVertex2f(19,6.2);
		glVertex2f(19.5,6.5);
		glVertex2f(19.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(19.5,5.5);
		glVertex2f(19.5,6.5);
		glVertex2f(20,6.2);
		glVertex2f(20.5,6.2);
		glVertex2f(21,6.5);
		glVertex2f(21,5.5);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(4.5,3.5);
		glVertex2f(4.5,4.5);
		glVertex2f(5.5,4.5);
		glVertex2f(5.5,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(7,3.5);
		glVertex2f(7,4.5);
		glVertex2f(8,4.5);
		glVertex2f(8,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(9.5,3.5);
		glVertex2f(9.5,4.5);
		glVertex2f(10.5,4.5);
		glVertex2f(10.5,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(12,3.5);
		glVertex2f(12,4.5);
		glVertex2f(13,4.5);
		glVertex2f(13,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(14.5,3.5);
		glVertex2f(14.5,4.5);
		glVertex2f(15.5,4.5);
		glVertex2f(15.5,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(17,3.5);
		glVertex2f(17,4.5);
		glVertex2f(18,4.5);
		glVertex2f(18,3.5);
	glEnd();


	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(5,10);
		glVertex2f(5,11);
		glVertex2f(5.5,10.8);
		glVertex2f(6.5,10.8);
		glVertex2f(7,11);
		glVertex2f(7,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(7,10);
		glVertex2f(7,11);
		glVertex2f(7.5,10.8);
		glVertex2f(8.5,10.8);
		glVertex2f(9,11);
		glVertex2f(9,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(9,10);
		glVertex2f(9,11);
		glVertex2f(9.5,10.8);
		glVertex2f(10.5,10.8);
		glVertex2f(11,11);
		glVertex2f(11,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(11,10);
		glVertex2f(11,11);
		glVertex2f(11.5,10.8);
		glVertex2f(12.5,10.8);
		glVertex2f(13,11);
		glVertex2f(13,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(13,10);
		glVertex2f(13,11);
		glVertex2f(13.5,10.8);
		glVertex2f(14.5,10.8);
		glVertex2f(15,11);
		glVertex2f(15,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(15,10);
		glVertex2f(15,11);
		glVertex2f(15.5,10.8);
		glVertex2f(16.5,10.8);
		glVertex2f(17,11);
		glVertex2f(17,10);
	glEnd();
}

/* TO DRAW ICEBERG */
void ice()
{
	glPushMatrix();
	glTranslated(500,50,0.0);
	glScaled(20,10,0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(5.5,2.5);
	
		glVertex2f(12.5,19.5);
		glVertex2f(15,19.5);
		glVertex2f(12.5,19.5);
		glVertex2f(13.5,18.5);
		glVertex2f(16.5,20.5);
		glVertex2f(17.5,18.5);
		glVertex2f(18.5,3.5);
		glVertex2f(19,3);
		glVertex2f(19.5,2.5);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(5.5,2.5);
		glVertex2f(6,3);
		glVertex2f(8.25,3.5);
		glVertex2f(8.5,18.5);
		glVertex2f(12,15);
		glVertex2f(13,17);
		glVertex2f(12.5,19.5);
		glVertex2f(8.5,9.5);
		glVertex2f(12.5,2.5);
        glVertex2f(5.5,2.5);  
    glEnd();  
   	glPopMatrix();
}



void myinit()
{
	glClearColor(0.1f,0.1f,0.1f,0.1f);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,999.0,0.0,799.0);
	
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1024.0,768.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("titanic ship");
	glutDisplayFunc(display);
	myinit();
	glutTimerFunc(100,update,0);
	glutMainLoop();
}
