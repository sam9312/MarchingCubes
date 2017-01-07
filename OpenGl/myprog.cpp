#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#define PI 3.1415926535898 
GLint circle_points = 400; 
void display(void)
{	int i;
	float angle;
/*  clear all pixels  */
    glClear (GL_COLOR_BUFFER_BIT);

/*  draw white polygon (rectangle) with corners at
 *  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)  
 */

    glBegin(GL_LINE_LOOP); 
for (i = 0; i < circle_points; i++) {    
   angle = 2*PI*i/circle_points; 
  
   	glColor3f(i%5, i%3, i%2);
   
   glVertex2f(sin(angle), cos(angle));

} 

glEnd();
   
    

/*  don't wait!  
 *  start processing buffered OpenGL routines 
 */
    glFlush ();
}

void init (void) 
{
/*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);

/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display); 
    glutMainLoop();
    return 0;   /* ISO C requires main to return int. */
}
