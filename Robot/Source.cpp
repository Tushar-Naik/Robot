//An implementation of a robot
//Header files required
#include<math.h>
#include<stdio.h>
#include<glut.h> 
//Call list constants
#define R_HEAD 1 
#define ANIMATION
#define R_BODY 2
#define R_L_HAND 3
#define R_R_HAND 4
#define R_LEG 5
#define R_EYE 8
#define R_NOSE 9
#define R_MOUTH 6
#define R_ARM 11
#define PI 3.141592

int head=0,body=0,lhand=0,rhand=0,lleg=0;
int dl=15,dr=15,dll=15,dlr=15;
int torso=0,larm=0,lightturn=0,lightturn1=0;
int rleg=0,rarm=0;
int i,q,a,j,t;
int x=0,y=0,z=0;
int view[2]={0,0};
int xa=0,ya=0,za=0;
int xx=0,yy=0;
int eyexx=0,eyeyy=10,eyezz=20;

//Function to move hands and legs while moving
void ll()
{	
	lhand+=dl;
	larm+=dl;
	lleg-=dll;
	if(lleg<=-70||lleg>70) dl=-dl;
	if(lhand<=-70||lhand>70) dll=-dll;
	rhand-=dr;
	rarm-=dr;
	rleg+=dlr;
	if(rleg>=70||rleg<-70) dlr=-dlr;
	if(rhand>=70||rhand<-70) dr=-dr;
	glutPostRedisplay();
	glFlush();
}
//Drawing the robot
void eye()
{
	glNewList(R_EYE,GL_COMPILE);
		glColor3f(0.0,0.0,0.0);
		glutSolidSphere(0.25,10,10);
	glEndList();
}

void draw_head()
{
	glNewList(R_HEAD,GL_COMPILE);
		glColor3f(1,1,.8);
		glutSolidCube(1.2);	
		glTranslatef(-0.28,0.2,0.6);
		glCallList(R_EYE);
		glTranslatef(0.56,0,0);
		glCallList(R_EYE);
		glTranslatef(-.28,-.2,0.0);
	glEndList();
}
void draw_body()
{
		glNewList(R_BODY,GL_COMPILE);
			glColor3f(.7,.7,.7);
			glutSolidCube(1);
		glEndList();
}
void draw_L_hand()
{
	glNewList(R_L_HAND,GL_COMPILE);
	glColor3f(1,1,1);
		glutSolidCube(1.0);
	glEndList();
}
void draw_R_hand()
{
	glNewList(R_R_HAND,GL_COMPILE);
	glColor3f(1,1,1);
	glutSolidCube(1.0);
	glEndList();
}
void draw_leg()
{
	glNewList(R_LEG,GL_COMPILE);
	glColor3f(1,1,1);
	glutSolidCube(1.0);
	glEndList();
}
void draw_arm()
{
	glNewList(R_ARM,GL_COMPILE);
	glColor3f(1,1,1);
	glutSolidCube(.2);
	glEndList();
}
void myinit()
{	glClearColor(0,0,0,0);
	glColor3f(0.0,1.0,1.0);
	draw_head();
	eye();
	draw_body();
	draw_L_hand();
	draw_R_hand();
	draw_leg();
	draw_arm();
}
void myreshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70,(GLfloat)w/(GLfloat)h,1.0,300.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-5);
}
void mykey(unsigned char key,int x,int y)
{	
	switch(key)
	{
	case 'q':head=(head+5)%360;
			glutPostRedisplay();
			break;
	case 'a':head=(head-5)%360;
			glutPostRedisplay();
			break;
	case 'w':body=(body+5)%360;
			glutPostRedisplay();
			break;
	case 's':body=(body-5)%360;
			glutPostRedisplay();
			break;
	case 'e':lhand=lhand+5%360;
			glutPostRedisplay();
			break;
	case 'd':lhand=lhand-5%360;
			glutPostRedisplay();
			break;
	case 'r':rhand=rhand+5%360;
			glutPostRedisplay();
			break;
	case 'f':rhand=rhand-5%360;
			glutPostRedisplay();
			break;
	case 't':lleg=lleg+5%360;
			if(lleg>=90) lleg=0;
		   	glutPostRedisplay();
			break;
	case 'g':lleg=lleg-5%360;
			if(lleg<=-90) lleg=0;
			glutPostRedisplay();
			break;
	case 'E':larm=larm+5%360;
			if(larm>=175) larm=0;
			glutPostRedisplay();
			break;
	case 'D':larm=larm-5%360;
			if(larm<=-175) larm=0;
			glutPostRedisplay();
			break;
	case 'y':rleg=rleg+5%360;
			if(rleg>=90) rleg=0;
			glutPostRedisplay();
			break;
	case 'h':rleg=rleg-5%360;
			if(rleg<=-90) rleg=0;
			glutPostRedisplay();
			break;
	case 'R':rarm=rarm+5%360;
			if(rarm>=175) rarm=0;
			glutPostRedisplay();
			break;
	case 'F':rarm=rarm-5%360;
			if(rarm<=-175) rarm=0;
			glutPostRedisplay();
			break;
	case'j':eyexx++;
			glutPostRedisplay();
			break;
	case'k':eyeyy++;
			glutPostRedisplay();
			break;
	case'l':eyezz++;
			glutPostRedisplay();
			break;
	case'u':eyexx--;
			glutPostRedisplay();
			break;
	case'i':eyeyy--;
			glutPostRedisplay();
			break;
	case'o':eyezz--;
			glutPostRedisplay();
			break;
	default:		break;
	}
}
void road()
{
	glPushMatrix();				
		glColor3f(1,1,1);		
		glTranslatef(0,-3,-10);		
		glRotatef(90,1,0,0);			
		glScalef(40,40,.4);		
		glutSolidCube(1);		
	glPopMatrix();
}
void robot()
{
	glPushMatrix();
		glTranslatef(0,1.6,0);
		glRotatef((GLfloat)head,0,1,0);
		glScalef(1,.8,.5);
			glCallList(R_HEAD);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0,.1,0);
		glRotatef((GLfloat)body,0,1,0);
		glScalef(2,2,1);
			glCallList(R_BODY);
		glPushMatrix();
			glTranslatef(-.60,.5,0);
			glutSolidSphere(.08,10,10);
			glTranslatef(-.2,0,0);
			glRotatef((GLfloat)lhand,1,0,0);
			glScalef(0.2,.5,.2);
			glTranslatef(0.1,-.5,0);
				glCallList(R_L_HAND);
			glTranslatef(0,-.5,0);
			glRotatef((GLfloat)larm,1,0,0);
			glScalef(.9,1,.2);
			glTranslatef(0,-.5,0);
				glCallList(R_ARM);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.59,.5,0);
			glutSolidSphere(.08,10,10);
			glTranslatef(0.2,.04,0);
			glRotatef((GLfloat)rhand,1,0,0);
			glScalef(.2,.5,.2);
			glTranslatef(0,-.5,0);
				glCallList(R_R_HAND);
			glTranslatef(0,-.5,0);
			glRotatef((GLfloat)rarm,1,0,0);
			glScalef(.9,1,.2);
			glTranslatef(0,-.5,0);
				glCallList(R_ARM);
		glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glRotatef((GLfloat)body,0,1,0);
		glTranslatef(-1,-1,0);
		glutSolidSphere(.1,10,10);
		glTranslatef(0,-.1,0);
		glRotatef((GLfloat)lleg,1,0,0);
		glScalef(.6,1.4,.4);
		glTranslatef(0,-.5,0);
			glCallList(R_LEG);
	glPopMatrix();
	glPushMatrix();
	glRotatef((GLfloat)body,0,1,0);
		glTranslatef(1,-1,0);
		glutSolidSphere(.1,10,10);
		glRotatef((GLfloat)rleg,1,0,0);
		glScalef(.6,1.4,.4);
		glTranslatef(0,-.6,0);
			glCallList(R_LEG);
	glPopMatrix();
}
//initialize the first configurations
void Initialize(void) 
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f); //Change the background to sky blue
      glEnable(GL_COLOR_MATERIAL); //Enable color
       glEnable(GL_LIGHTING); //Enable lighting
       glEnable(GL_LIGHT0); //Enable light #0
       glEnable(GL_LIGHT1); //Enable light #1
    glEnable(GL_NORMALIZE); //Automatically normalize normals
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(0.5,0.5,0.5);
		
			glLoadIdentity();
			gluLookAt(eyexx,eyeyy,eyezz,0,0,0,0,1,0);
		
			road();
			glPushMatrix();
				glTranslatef(xa,ya,za);
				robot();
			glPopMatrix();
	glFlush();
}
int k1;
void keys(int key,int x,int y)
{
	
	switch(key)
	{
	case GLUT_KEY_LEFT:if(xa>-19)
					   {
						   if(key!=k1)
						   { xa--;body=-90;head=-90;lhand=0;rhand=0;lleg=0;rleg=0;rarm=0;larm=0;ll();}
							else
							{xa--;body=-90;head=-90;ll();}
					   }
					   break;

	case GLUT_KEY_RIGHT:if(xa<19)
						{
							if(key!=k1)
							{xa++;body=90;head=90;lhand=0;rhand=0;lleg=0;rleg=0;rarm=0;larm=0;ll();}
							else
							{xa++;body=90;head=90;ll();}
						}
						break;
	case GLUT_KEY_UP:if(za>-27)
					 {
						 if(key!=k1)
						 { za--;body=180;head=180;lhand=0;rhand=0;lleg=0;rleg=0;rarm=0;larm=0;ll();}
						 else
						 {za--;body=180;head=180;ll();}
					 }
					 break;
	case GLUT_KEY_DOWN:if(za<10)
					   {
						   if(key!=k1)
						   { 	za++;body=0;head=0;lhand=0;rhand=0;lleg=0;rleg=0;rarm=0;larm=0;ll();}
						   else
						   {za++;body=0;head=0;ll();}
					   }
					   break;

	}
	k1=key;
}

void main()
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(900,900);
	glutCreateWindow("ROBOT");
	myinit();
	glutDisplayFunc(display);
	glutReshapeFunc(myreshape);
	glutKeyboardFunc(mykey);
	glutSpecialFunc(keys);
		Initialize();
	glutMainLoop();
}