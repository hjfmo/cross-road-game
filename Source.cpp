#define STB_IMAGE_IMPLEMENTATION
#include <GL/stb_image.h>
#include<iostream>
#include<cmath>
#include<GL/glut.h>
//using namespace std;
bool firstTimeq = true
, firstTimep = true, flag = true;
unsigned int texture;
int width, height, nrChannels;
unsigned char* data = NULL;
bool fullScreen;
float ratio, angle, eyey = 0.0416147, eyez = 5, eyex, upx, upz = -20, sWidth = 6, lx, xq1, xq2, xq3, yq1, yq2, yq3, zq1, zq2, zq3,
cy, cx, cz, PI = 22 / 7.0, r = 0.3,
xq, yq, zq, deltaxq = .9, deltayq = .9, deltazq = .9;
void background();
void mydraw();
void reshape(int, int);
void timer(int);
void camare(unsigned char, int, int);
void specialKeyboard(int, int, int);
void mouse(int, int, int, int);
void load(int imgnum);
void check(unsigned char* data);
//GLuint loadTexture(Image* image);
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(GetSystemMetrics(SM_CXSCREEN),
		GetSystemMetrics(SM_CYSCREEN));
	glutCreateWindow(" 3D shapes and animation");
	//glutFullScreen();
	background();
	glutDisplayFunc(mydraw);// Register callback handler for window re-paint event
	glutReshapeFunc(reshape);// Register callback handler for window re-size event
	glutTimerFunc(0, timer, 0);  // First timer call immediately [NEW]
	glutKeyboardFunc(camare);
	glutSpecialFunc(specialKeyboard);
	glutMouseFunc(mouse);
	glutMainLoop();  // Enter the infinite event-processing loop
}
//collision 
void update1_3() {
	if (zq<0 && zq>-2 || zq<-5 && zq>-7)
	{


		/*zq = -2;
		yq = 0.4;
		xq = 0;*/
		if (xq1 <  6.1)
		{
			if (xq1 - xq < 6.5 && xq1 - 6>xq)
			{
				eyez = 5;
				zq = 0;
				yq = 0;
				xq = 0;

			}
			else if (xq1 - xq > 5.25 && xq1 - 6 < xq)
			{
				eyez = 5;
				zq = 0;
				yq = 0;
				xq = 0;

			}

		}
		else if (xq1 < 6)
		{
			if (xq1 - xq > 5.25 && xq1 - 6 < xq)
			{
				eyez = 5;
				zq = 0;
				yq = 0;
				xq = 0;

			}
			/*else if (xq1 - xq > 5.25 && xq1 - 6 < xq)
			{
				eyez = 5;
				zq = 0;
				yq = 0;
				xq = 0;

			}*/

		}

	}
}
void update2_4() {
	if (zq<-3 && zq>-5 || zq<-8 && zq>-10)
	{


		/*zq = -2;
		yq = 0.4;
		xq = 0;*/
		if (xq2 > 6.1)
		{
			if (xq2 - xq < 6.5 && xq2 - 6>xq)
			{
				eyez = 5;
				zq = 0;
				yq = 0;
				xq = 0;

			}
			else if (xq2 - xq > 5.25 && xq2 - 6 < xq)
			{
				eyez = 5;
				zq = 0;
				yq = 0;
				xq = 0;

			}

		}
		else if (xq2 < 6)
		{
			if (xq2 - xq > 5.25 && xq2 - 6 < xq)
			{
				eyez = 5;
				zq = 0;
				yq = 0;
				xq = 0;

			}
			/*else if (xq1 - xq > 5.25 && xq1 - 6 < xq)
			{
				eyez = 5;
				zq = 0;
				yq = 0;
				xq = 0;

			}*/

		}

	}
}
/* Initialize OpenGL Graphics */
void background() {
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);


}
//3d 
void car() {
	//cars
	glPushMatrix();
	glTranslatef(0.0f, -0.55f, 5.0f);
	glBegin(GL_QUADS);//11111
	glColor3f(lx, 0, 1);
	glVertex3d(xq1 - 6.25, yq1 - 1, zq1 + 0);
	glColor3f(0, lx, 1);
	glVertex3d(xq1 - 5.5, yq1 - 1, zq1 + 0);
	glColor3f(0, 0, lx);
	glVertex3d(xq1 - 5.5, yq1 - 1.5, zq1 + 0);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(xq1 - 6.25, yq1 - 1.5, zq1 + 0);
	glEnd();

	glTranslatef(xq1 - 6.25, yq1 - 1.5, zq1 + 0);
	glBegin(GL_QUADS);//11111
	glColor3f(lx, 0, 1);
	glVertex3d(0, 0, 0);
	glColor3f(0, lx, 1);
	glVertex3d(0, 0.5, 0);
	glColor3f(0, 0, lx);
	glVertex3d(0, 0.5, -0.5);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(0, 0, -0.5);
	glEnd();
	glTranslatef(0, 0, -0.5);
	glBegin(GL_QUADS);//11111
	glColor3f(lx, 0, 1);
	glVertex3d(0, 0, 0);
	glColor3f(0, lx, 1);
	glVertex3d(0, 0.5, 0);
	glVertex3d(0.75, 0.5, 0);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(0.75, 0, 0);
	glEnd();
	glTranslatef(0.75, 0, 0);
	glBegin(GL_QUADS);//11111
	glColor3f(.1, lx * .5, 0);
	glVertex3d(0, 0, 0);
	glColor3f(0, lx, 1);
	glVertex3d(0, 0, 0.5);
	glColor3f(0, 0, lx);
	glVertex3d(0., 0.5, 0.5);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(0, 0.5, 0);
	glEnd();
	glTranslatef(0, 0.5, 0);
	glBegin(GL_QUADS);//11111
	glColor3f(lx, 0, 1);
	glVertex3d(0, 0, 0);
	glColor3f(0, lx, 1);
	glVertex3d(-0.75, 0, 0);
	glColor3f(0, 0, lx);
	glVertex3d(-0.75, 0, 0.5);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(0, 0, 0.5);
	glEnd();
	glPopMatrix();
}
void car2() {
	//cars2
	glPushMatrix();
	glTranslatef(0.0f, -0.55f, 2.25f);
	glBegin(GL_QUADS);//11111
	glColor3f(lx, 0, 1);
	glVertex3d(xq2 - 6.25, yq1 - 1, zq1 + 0);
	glColor3f(0, lx, 1);
	glVertex3d(xq2 - 5.5, yq1 - 1, zq1 + 0);
	glColor3f(0, 0, lx);
	glVertex3d(xq2 - 5.5, yq1 - 1.5, zq1 + 0);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(xq2 - 6.25, yq1 - 1.5, zq1 + 0);
	glEnd();

	glTranslatef(xq2 - 6.25, yq1 - 1.5, zq1 + 0);
	glBegin(GL_QUADS);//11111
	glColor3f(lx, 0, 1);
	glVertex3d(0, 0, 0);
	glColor3f(0, lx, 1);
	glVertex3d(0, 0.5, 0);
	glColor3f(0, 0, lx);
	glVertex3d(0, 0.5, -0.5);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(0, 0, -0.5);
	glEnd();
	glTranslatef(0, 0, -0.5);
	glBegin(GL_QUADS);//11111
	glColor3f(lx, 0, 1);
	glVertex3d(0, 0, 0);
	glColor3f(0, lx, 1);
	glVertex3d(0, 0.5, 0);
	glVertex3d(0.75, 0.5, 0);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(0.75, 0, 0);
	glEnd();
	glTranslatef(0.75, 0, 0);
	glBegin(GL_QUADS);//11111
	glColor3f(.1, lx * .5, 0);
	glVertex3d(0, 0, 0);
	glColor3f(0, lx, 1);
	glVertex3d(0, 0, 0.5);
	glColor3f(0, 0, lx);
	glVertex3d(0., 0.5, 0.5);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(0, 0.5, 0);
	glEnd();
	glTranslatef(0, 0.5, 0);
	glBegin(GL_QUADS);//11111
	glColor3f(lx, 0, 1);
	glVertex3d(0, 0, 0);
	glColor3f(0, lx, 1);
	glVertex3d(-0.75, 0, 0);
	glColor3f(0, 0, lx);
	glVertex3d(-0.75, 0, 0.5);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(0, 0, 0.5);
	glEnd();
	glPopMatrix();
}
void car3() {
	//cars
	glPushMatrix();
	glTranslatef(0.0f, -0.55f, -0.25f);
	glBegin(GL_QUADS);//11111
	glColor3f(lx, 0, 1);
	glVertex3d(xq1 - 6.25, yq1 - 1, zq1 + 0);
	glColor3f(0, lx, 1);
	glVertex3d(xq1 - 5.5, yq1 - 1, zq1 + 0);
	glColor3f(0, 0, lx);
	glVertex3d(xq1 - 5.5, yq1 - 1.5, zq1 + 0);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(xq1 - 6.25, yq1 - 1.5, zq1 + 0);
	glEnd();

	glTranslatef(xq1 - 6.25, yq1 - 1.5, zq1 + 0);
	glBegin(GL_QUADS);//11111
	glColor3f(lx, 0, 1);
	glVertex3d(0, 0, 0);
	glColor3f(0, lx, 1);
	glVertex3d(0, 0.5, 0);
	glColor3f(0, 0, lx);
	glVertex3d(0, 0.5, -0.5);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(0, 0, -0.5);
	glEnd();
	glTranslatef(0, 0, -0.5);
	glBegin(GL_QUADS);//11111
	glColor3f(lx, 0, 1);
	glVertex3d(0, 0, 0);
	glColor3f(0, lx, 1);
	glVertex3d(0, 0.5, 0);
	glVertex3d(0.75, 0.5, 0);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(0.75, 0, 0);
	glEnd();
	glTranslatef(0.75, 0, 0);
	glBegin(GL_QUADS);//11111
	glColor3f(.1, lx * .5, 0);
	glVertex3d(0, 0, 0);
	glColor3f(0, lx, 1);
	glVertex3d(0, 0, 0.5);
	glColor3f(0, 0, lx);
	glVertex3d(0., 0.5, 0.5);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(0, 0.5, 0);
	glEnd();
	glTranslatef(0, 0.5, 0);
	glBegin(GL_QUADS);//11111
	glColor3f(lx, 0, 1);
	glVertex3d(0, 0, 0);
	glColor3f(0, lx, 1);
	glVertex3d(-0.75, 0, 0);
	glColor3f(0, 0, lx);
	glVertex3d(-0.75, 0, 0.5);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(0, 0, 0.5);
	glEnd();
	glPopMatrix();
}
void car4() {
	//cars2
	glPushMatrix();
	glTranslatef(0.0f, -0.55f, -2.75f);
	glBegin(GL_QUADS);//11111
	glColor3f(lx, 0, 1);
	glVertex3d(xq2 - 6.25, yq1 - 1, zq1 + 0);
	glColor3f(0, lx, 1);
	glVertex3d(xq2 - 5.5, yq1 - 1, zq1 + 0);
	glColor3f(0, 0, lx);
	glVertex3d(xq2 - 5.5, yq1 - 1.5, zq1 + 0);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(xq2 - 6.25, yq1 - 1.5, zq1 + 0);
	glEnd();

	glTranslatef(xq2 - 6.25, yq1 - 1.5, zq1 + 0);
	glBegin(GL_QUADS);//11111
	glColor3f(lx, 0, 1);
	glVertex3d(0, 0, 0);
	glColor3f(0, lx, 1);
	glVertex3d(0, 0.5, 0);
	glColor3f(0, 0, lx);
	glVertex3d(0, 0.5, -0.5);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(0, 0, -0.5);
	glEnd();
	glTranslatef(0, 0, -0.5);
	glBegin(GL_QUADS);//11111
	glColor3f(lx, 0, 1);
	glVertex3d(0, 0, 0);
	glColor3f(0, lx, 1);
	glVertex3d(0, 0.5, 0);
	glVertex3d(0.75, 0.5, 0);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(0.75, 0, 0);
	glEnd();
	glTranslatef(0.75, 0, 0);
	glBegin(GL_QUADS);//11111
	glColor3f(.1, lx * .5, 0);
	glVertex3d(0, 0, 0);
	glColor3f(0, lx, 1);
	glVertex3d(0, 0, 0.5);
	glColor3f(0, 0, lx);
	glVertex3d(0., 0.5, 0.5);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(0, 0.5, 0);
	glEnd();
	glTranslatef(0, 0.5, 0);
	glBegin(GL_QUADS);//11111
	glColor3f(lx, 0, 1);
	glVertex3d(0, 0, 0);
	glColor3f(0, lx, 1);
	glVertex3d(-0.75, 0, 0);
	glColor3f(0, 0, lx);
	glVertex3d(-0.75, 0, 0.5);
	glColor3f(lx, lx * 5, .1);
	glVertex3d(0, 0, 0.5);
	glEnd();
	glPopMatrix();
}
void road1() {
	//roads1.1
	glPushMatrix();
	glTranslatef(-6.0f, -2.0f, 5.2f);
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(12, 0, 0);
	glEnd();
	glPopMatrix();
	///road1.2
	glPushMatrix();
	glTranslatef(-6.0f, -2.0f, 4.2f);
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(12, 0, 0);
	glEnd();
	glPopMatrix();
}
void road2() {
	//roads2.1
	glPushMatrix();
	glTranslatef(-6.0f, -2.0f, 2.45f);
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(12, 0, 0);
	glEnd();
	glPopMatrix();
	///road2.2
	glPushMatrix();
	glTranslatef(-6.0f, -2.0f, 1.45f);
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(12, 0, 0);
	glEnd();
	glPopMatrix();
}
void road3() {
	//roads3.1
	glPushMatrix();
	glTranslatef(-6.0f, -2.0f, -0.1f);
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(12, 0, 0);
	glEnd();
	glPopMatrix();
	///road3.2
	glPushMatrix();
	glTranslatef(-6.0f, -2.0f, -1.1f);
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(12, 0, 0);
	glEnd();
	glPopMatrix();
}
void road4() {
	//roads4.1
	glPushMatrix();
	glTranslatef(-6.0f, -2.0f, -2.65f);
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(12, 0, 0);
	glEnd();
	glPopMatrix();
	///road4.2
	glPushMatrix();
	glTranslatef(-6.0f, -2.0f, -3.65f);
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(12, 0, 0);
	glEnd();
	glPopMatrix();
}
void player() {
	///  the player

	// the head

	glMatrixMode(GL_MODELVIEW);
	//glRotatef(a1, 0.0f, 0.0f, 1.0f);
	glPushMatrix();
	glTranslatef(0.0f, 0.4f, 6.0f);

	glBegin(GL_QUADS);
	glColor3f(1, 0.7, 0);
	// Define vertices in  with normal pointing out
	glVertex3d(xq - 0.25, yq - 1.5, zq + 0);
	glVertex3d(xq + 0.25, yq - 1.5, zq + 0);
	glVertex3d(xq + 0.25, yq - 1.75, zq + 0);
	glVertex3d(xq - 0.25, yq - 1.75, zq + 0);
	glEnd(); // End of drawing 

	glTranslatef(xq - 0.25, yq - 1.75, zq + 0);
	//glRotatef(a2, 0.0f, 0.0f, 1.0f);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex3d(0, 0, 0);
	glVertex3d(0.25, 0, 0);
	glEnd();
	//glPopMatrix();
	glTranslatef(0.25, 0, 0);
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0, -0.3, 0);
	glEnd();

	glPushMatrix();///right leg
	glTranslatef(0, -0.3, 0);
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0.25, -0.25, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();///left leg
	glTranslatef(0, -0.3, 0);
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(-0.25, -0.25, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();///right hand
	glTranslatef(0, -0.3, 0);
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0.25, 0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();///left hand
	glTranslatef(0, -0.3, 0);
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(-0.25, 0, 0);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	void update();
}
/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void mydraw() {
	glClear(GL_COLOR_BUFFER_BIT |
		GL_DEPTH_BUFFER_BIT);// Clear color and depth buffers
	glLoadIdentity(); // // Reset the model--  matrix
	
	gluLookAt(eyex, eyey, eyez,
		upx, eyey, upz,
		0, 1, 0);

	glColor3f(1, 1, 1);
	glTranslatef(0, 0, -7);// Move right and into the screen
	load(2);
	//glRotatef(angle,1,1,1);
	glBegin(GL_QUADS); // Begin drawing 
	//top
	//glColor3f(1,1,1);
	//glColor3f(.4,.7,.1);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(6, 4, 6);
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-6, 4, 6);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-6, 4, -6);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(6, 4, -6);

	glEnd();
	load(4);
	glBegin(GL_QUADS);
	//land
	//glColor3f(1, 1, 1);
	//glColor3f(.4,.7,.1);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(6, -2, 6);
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-6, -2, 6);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-6, -2, -6);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(6, -2, -6);

	glEnd();
	//back
	load(3);
	glBegin(GL_QUADS);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(-6, -2, -6);
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(6, -2, -6);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(6, 4, -6);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(-6, 4, -6);


	glEnd();
	//left

	load(3);
	glBegin(GL_QUADS);
	//glColor3f(0, 1, .1);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(-6, -2, -6);
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-6, -2, 6);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-6, 4, 6);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(-6, 4, -6);
	glEnd();

	//right
	load(1);
	glBegin(GL_QUADS);
	//glColor3f(0, 1, .1);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(6, -2, -6);
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(6, -2, 6);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(6, 4, 6);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(6, 4, -6);
	glEnd();


	road1();
	road2();
	road3();
	road4();
	car();
	car2();
	car3();
	car4();
	player();
	update1_3();
	update2_4();
	//////////////////////////////////////////////////////////////

	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

	// Update the rotational angle after each refresh [NEW]


}
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(int w, int h) {
	if (h == 0) h = 1;

	// Set the aspect ratio of the clipping volume to match the viewport
	ratio = w / (float)h;
	glViewport(0, 0, w, h);// Set the viewport to cover the new window
	glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
	glLoadIdentity(); // Reset
	gluPerspective(45, ratio, 1, 100);
	glMatrixMode(GL_MODELVIEW);
}
/* Called back when timer expired [NEW] */
void timer(int v) {
	glutPostRedisplay();// Post re-paint request to activate display()
	glutTimerFunc(100, timer, 0); // next timer call milliseconds later
	//animation of boxs
	if (firstTimeq) {
		if (xq1 <= 8 * ratio - 0.25 || xq1 <= 8 * ratio - 0.25)
		{
			lx = 00;
			xq1 += .3;
			xq2 += .4;
		}
		else
			firstTimeq = !firstTimeq;
	}
	if (!firstTimeq) {
		if (xq1 >= -6 * ratio + 9.25 || xq1 >= -6 * ratio + 9.25)
		{
			lx = 1;
			xq1 -= .3;
			xq2 -= .4;
		}
		else
			firstTimeq = !firstTimeq;
	}

}

//camare
void camare(unsigned char key, int x, int y) {
	angle += 4;
	if (key == 27)
		exit(0);
	if (key == 'a')
	{
		upx -= .9 * cos(.1);
		upz -= .9 * sin(.1);
	}
	if (key == 'd') {
		upx += .9 * cos(.1);
		upz += .9 * sin(.1);
	}
	if (key == 'w')
	{
		eyez -= 5;
		eyey = .3 * abs(cos(angle));
	}
	if (key == 's') {
		eyez += 5;
		eyey = .3 * abs(cos(angle));
	}
}
//animation
void specialKeyboard(int key, int x, int y) {
	angle += .4;
	if (key == GLUT_KEY_F1) {
		fullScreen = !fullScreen;
		if (fullScreen)
			glutFullScreen();
		else {
			glutPositionWindow(10, 10);
			glutReshapeWindow(600, 600);
		}
	}
	//Animation player
	if (key == GLUT_KEY_RIGHT) {
		xq += .1;

	}
	if (key == GLUT_KEY_LEFT) {
		xq -= .1;

	}
	if (key == GLUT_KEY_DOWN) {
		//y = .3*abs(cos(angle));
		eyez += 1.25;
		zq += 1.25;
		eyey = .1 * abs(cos(angle));

	}
	if (key == GLUT_KEY_UP) {
		eyez -= 1.25;
		zq -= 1.25;
		eyey = .1 * abs(cos(angle));
		std::cout << eyez << " " << eyey << " " << eyex << " \n";
	}
}
void mouse(int button, int state, int x, int y) {
	//cout<<(int)(((x-(width/2))*100)/(width/2))
		//<<endl<<
	//	(int)((((heigh/2)-y)*100)/(heigh/2))<<"\n\\\\\\\\\\\\\\\\\\"<<"\n";
}
//texture
void load(int imgnum) {
	if (imgnum == 1) {

		data = stbi_load("xp2.jpg", &width, &height, &nrChannels, 0);
		check(data);
	}
	else if (imgnum == 2) {

		data = stbi_load("sky.jpg", &width, &height, &nrChannels, 0);
		check(data);
	}
	else if (imgnum == 3) {

		data = stbi_load("xp2.jpg", &width, &height, &nrChannels, 0);
		check(data);
	}
	else if (imgnum == 4) {

		data = stbi_load("land.jpg", &width, &height, &nrChannels, 0);
		check(data);
	}
}
void check(unsigned char* data) {
	if (data)
	{
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		//repeat
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		//fillter 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}
