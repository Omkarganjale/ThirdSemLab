//============================================================================
// Name        : OOP_assignment_8.cpp
// Author      : OGan
// Version     :
// Copyright   : Free to use.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void *currentfont;

const int size=7;

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,char *string)
{
	    char *c;
	glRasterPos2f(x,y);

	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}

class button
{
	int x1,y1,x2,y2;
	int state;
	char str[10];

public:
	button()
	{}

	button(int x11,int y11,int x22,int y22,char *str1)
	{
		x1=x11;
		y1=y11;
		x2=x22;
		y2=y22;
		state=1;
		strcpy(str,str1);
	}

	void draw()
	{
		setFont(GLUT_BITMAP_HELVETICA_18);
		glColor3f(1.0,1.0,1.0);
			drawstring(x1+10,y1+10,str);
		glColor3f(0.2,0.2,0.8);
		glBegin(GL_POLYGON);
		glVertex2f(x1,y1);
		glVertex2f(x2,y1);
		glVertex2f(x2,y2);
		glVertex2f(x1,y2);
		glEnd();
		if(state==0)
		{
		glColor3f(0,0,0);
		glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x2,y1);
		glVertex2f(x2,y1);
		glVertex2f(x2,y2);
		glEnd();
		}
		else if(state==1)
		{
			glColor3f(0,0,0);
			glBegin(GL_LINES);
			glVertex2f(x1,y1);
			glVertex2f(x1,y2);
			glVertex2f(x1,y2);
			glVertex2f(x2,y2);
			glEnd();
		}
	}

	void togglestate(void)
	{
		/*if(state==1)
			state=0;
		else if(state==0)
			state=1;*/
		state=(state==1)?0:1;
	}

	int insidebutton(int x,int y)
	{
		if(x>x1 && x<x2 && y>y1 && y<y2)
			return 1;
		else return 0;
	}

};

button btn1(100,100,175,150,"Push");
button btn2(300,100,275,150,"Pop");
//class stack;
//stack st;

class stack
{
   button s[size];
   int top;

public:
   stack()
   {
	   this->top=-1;
   }

   int stfull() {
      if (this->top >= size-1)
         return 1;
      else
         return 0;
   }

   void push(int item) {
   	char str[10];
   	snprintf(str, sizeof(str), "%d", item);
    button btn(100,250+this->top*50,150,300+this->top*50,str);
   	this->top++;
   	s[this->top] = btn;
   }

   int stempty() {
      if (this->top == -1)
         return 1;
      else
         return 0;
   }

   button pop() {
      button item;
      item = s[this->top];
      this->top--;

      return (item);
   }

   void displaystack() {
      int i;
      if (stempty())
         drawstring(10,10,"Stack Is Empty!");
      else {
         for (i = this->top; i >= 0; i--)
       	  s[i].draw();
      }
   }

} ;

stack st;



void display()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


btn1.draw();
btn2.draw();
st.displaystack();
glFlush();
glutSwapBuffers();
//glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y)
{static int itemno=0;
	y=600-y;
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	if(btn1.insidebutton(x,y))
	{
		btn1.togglestate();
		if(!st.stfull())
		st.push(itemno++);
	}
	if(btn2.insidebutton(x,y))
		{
			btn2.togglestate();
			if(!st.stempty())
					st.pop();

		}

	if(btn==GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if(btn1.insidebutton(x,y))
			{
				btn1.togglestate();
			}
		if(btn2.insidebutton(x,y))
			{
				btn2.togglestate();
			}
	}
	glutPostRedisplay();
	}
}

void init(){
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0,600,0,600);
		glMatrixMode(GL_MODELVIEW);

	}

void idle(){
		glutPostRedisplay();
	}


int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(600,600);
glutCreateWindow("STACK");
glutDisplayFunc(display);
glutMouseFunc(mouse);
glutIdleFunc(idle);
glEnable(GL_DEPTH_TEST);
init();
glutMainLoop();
return 0;
}
