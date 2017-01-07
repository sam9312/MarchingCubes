#include <GL/gl.h>
#include <GL/glut.h>

void whiteStud()

{


        glColor3f(1.0, 1.0, 1.0);
        glutSolidSphere(0.01, 16, 16);


}

void blackWheel() 

{


       glColor3f(0.129412, 0.129412, 0.129412);
       glutSolidSphere(0.1, 16, 16);


}


void wheelWithStuds()

   {  
       /**********************************/
        int iTimeElapsed = glutGet(GLUT_ELAPSED_TIME);
        float fScale= 0.5f;
        long i;
       /**********************************/
       /* clear all pixels */
       glClear(GL_COLOR_BUFFER_BIT);
       /**********************************/
       glPushMatrix();
       glTranslatef(0.25, 0.25, 0.0);
       glRotatef(iTimeElapsed * fScale,0.0,0.0,1.0);
       blackWheel(); // draw the wheel without studs.
       /**********************************/
       // five studs, step 72 degree (72*5=360 degree).
       for (i=0; i<5; i++) {
            glPushMatrix();
            glRotatef(72*i,0.0,0.0,1.0); // rotate coordinate 72 degree.
            glTranslatef(0.04, 0.0, 0.0);// translate on the rotated coordinate.
            whiteStud(); // draw the stud.
            glPopMatrix();
            } 
            glTranslatef(0.0, 0.0, 0.0);// translate in order to draw a stud at the center of the wheel.
            whiteStud();// draw the stud at the center of the wheel.
            /**********************************/
            /* don't wait! start processing buffered OpenGL routines */
            glFlush();
            glPopMatrix();
            /**********************************/

   }


int main(int argc, char** argv)

   {
      glutInit(&argc, argv);
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
      glutInitWindowSize(400, 400);
      glutInitWindowPosition(10, 10);
      glutCreateWindow("(-Rotating Car Wheel-)");
      /* select clearing (background) color */
      glClearColor(1.0, 1.0,1.0, 1.0);
      /* initialize viewing values */
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glutDisplayFunc(wheelWithStuds);
      glutMainLoop();
      return 0;
   }