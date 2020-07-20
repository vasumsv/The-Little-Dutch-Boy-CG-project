#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>
#include <math.h>
#define PI 3.141592653589

void first_window();
void display(void);                          //Display first window
void first_window_mouse(int, int, int, int);    //Right click
void second_window();
void key1(unsigned char, int, int);            //Keyboard key a
void tree(int, int, int, int);                  // tree function
void third_window();
void fourth_window();
void Timer(int);                             //Timer function
void fifth_window();
void hole_in_dike();
void sixth_window();
void seventh_window();
void eighth_window();
void nineth_window();
void tenth_window();
void final_window();
void key2(unsigned char, int, int);         //Keyboard key b
void key3(unsigned char, int, int);			//Keyboard key c
void key4(unsigned char, int, int);			//Keyboard key d
void key5(unsigned char, int, int);			//Keyboard key e
void key6(unsigned char, int, int);			//Keyboard key f
void key7(unsigned char, int, int);			//Keyboard key g
void key8(unsigned char, int, int);			//Keyboard key h
void key9(unsigned char, int, int);			//Keyboard key k
void water_leak(void);
void drawing_day();                             //Scenary of the dike day
void drawing_night();							//Scenary of the dike night
void sun();
void moon();
void drawing();                                //Scenary of the dike
void boy(int);                                   // moving boy
void dike_boy(int);
void boy_finger(int, int);                      //boy finger in dike
void priest();


int i, flag;
float temp = 0.0, m = 0.0, n = 0.0, move = 0.0;
float theta;
int id, id1, id2, id3, id4, id5, id6, id7, id8, id9, id10;

void drawKidsShirtAndTrousers(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Bottom Shirt
	glColor3ub(shirt_r, shirt_g, shirt_b);
	glBegin(GL_POLYGON);
	glVertex2f(0, 20);
	glVertex2f(100, 20);
	glVertex2f(100, 100);
	glVertex2f(0, 100);
	glEnd();

	// Top Shirt
	glBegin(GL_POLYGON);
	glVertex2f(100, 100);
	glVertex2f(135, 105);
	glVertex2f(120, 175);
	glVertex2f(100, 200);
	glVertex2f(50, 180);
	
	glVertex2f(-20, 175);
	glVertex2f(-35, 105);
	glVertex2f(0, 100);
	

	// Left Trouser
	glColor3ub(37, 107, 202);
	glBegin(GL_POLYGON);
	glVertex2f(0, 25);
	glVertex2f(0, -100);
	glVertex2f(35, -100);
	glVertex2f(65, 25);
	

	// Right Trouser
	glBegin(GL_POLYGON);
	glVertex2f(35, 25);
	glVertex2f(65, -100);
	glVertex2f(100, -100);
	glVertex2f(100, 25);
	glEnd();

	
}
// Function to Draw Circle
void drawCircle(GLfloat x, GLfloat y,
	GLfloat r, GLfloat g, GLfloat b,
	GLfloat sx, GLfloat sy,
	GLfloat radius) {
	glPushMatrix();

	glTranslatef(x, y, 0);
	glScalef(sx, sy, 0);

	glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
	for (GLfloat i = 0; i < 360; i += 5)
		glVertex2f(radius * sin(i *  / 180), radius * cos(i * PI / 180));
	glEnd();

	glPopMatrix();
}

// Function to Draw Circle
void drawSemiCircle(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat r, GLfloat g, GLfloat b,
	
	GLfloat start_angle, GLfloat end_angle) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
	for (GLfloat i = start_angle; i < end_angle; i += 5)
		
	glEnd();

	glPopMatrix();
}

void drawKid(GLfloat tx, GLfloat ty, GLfloat sx, GLfloat sy,
	GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Neck
	drawSemiCircle(-1, -35, .6, 1,
		203, 166, 108,
		20, -90, 90);

	// Face
	drawCircle(0, 0,
		232, 190, 123,
		1, 1,
		24);

	// Left Eye
	drawCircle(-8, 0,
		250, 250, 250,
		1, 1,
		4);
	drawCircle(-6, 0,
		10, 10, 10,
		1, 1,
		2);

	// Right Eye
	drawCircle(8, 0,
		250, 250, 250,
		1, 1,
		4);
	drawCircle(10, 0,
		10, 10, 10,
		1, 1,
		2);

	// Cap
	drawSemiCircle(0, 10, 1, 1,
		37, 107, 202,
		24, -90, 90);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(20, 14);
	glVertex2f(40, 16);
	glEnd();
	glLineWidth(1);

	// Hands
	drawCircle(-42, -82,
		232, 190, 123,
		1, 1,
		10);
	drawCircle(38, -82,
		232, 190, 123,
		1, 1,
		10);

	// Shirt and Trousers
	drawKidsShirtAndTrousers(-32, -125,
		.6, .5,
		shirt_r, shirt_g, shirt_b);

	// Left Shoe
	drawSemiCircle(-21, -178,
		1.2, 1,
		20, 20, 20,
		10,
		-90, 90);

	// Right Shoe
	drawSemiCircle(18, -178,
		1.2, 1,
		20, 20, 20,
		10,
		-90, 90);

	glPopMatrix();

}

//First Window Function
void first_window()
{


	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	
	gluOrtho2D(0, 1000, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	char str42[] = "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING";
	glColor3f(1, 1, 1);
	glRasterPos2f(230, 950);
	for (i = 0;i < strlen(str42);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str42[i]);
	}

	char str43[] = "COMPUTER GRAPHICS AND VISUALIZATION";
	glColor3f(1, 1, 1);
	glRasterPos2f(270, 900);
	for (i = 0;i < strlen(str43);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str43[i]);
	}


	char str44[] = "MINI PROJECT ";
	glColor3f(1, 1, 1);
	glRasterPos2f(410, 700);
	for (i = 0;i < strlen(str44);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str44[i]);
	}

	char str45[] = "ON ";
	glColor3f(1, 1, 1);
	glRasterPos2f(458, 640);
	for (i = 0;i < strlen(str45);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str45[i]);
	}




	char str1[] = "THE LITTLE DUTCH BOY WHO SAVED THE HOLLAND";
	glColor3f(1, 1, 1);
	glRasterPos2f(245, 570);
	for (i = 0;i < strlen(str1);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str1[i]);
	}

	char str2[] = "TEAM MEMBERS";
	glColor3f(1, 1, 1);
	glRasterPos2f(10, 130);
	for (i = 0;i < strlen(str2);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str2[i]);
	}

	char str3[] = "VASU D                     USN";
	glColor3f(1, 1, 1);
	glRasterPos2f(10, 80);
	for (i = 0;i < strlen(str3);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[i]);
	}

	char str4[] = "SUBRAMANYA R    USN";
	glColor3f(1, 1, 1);
	glRasterPos2f(10, 30);
	for (i = 0;i < strlen(str4);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str4[i]);
	}

	char str5[] = "RIGHT CLICK TO START";
	glColor3f(1, 1, 1);
	glRasterPos2f(780, 30);
	for (i = 0;i < strlen(str5);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str5[i]);
	}



	glFlush();
}
//Function to display first_window
void display(void)
{

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	first_window();
	glutMouseFunc(first_window_mouse);             //mouse function called here 
	glFlush();
}


//Function to destroy first_window and open second_window mouse function
void first_window_mouse(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)                            //right mouse button
	{
		x = 0;
		y = 0;
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1350, 695);
		glutInitWindowPosition(0, -300);
		glutDestroyWindow(id);
		id1 = glutCreateWindow("THE LITTLE DUTCH BOY WHO SAVED THE HOLLAND");
		glutPostRedisplay();
		glutDisplayFunc(second_window);
	}
}

//Second window function
void second_window()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1000, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	char str6[] = "One day, a young boy named Hans went to visit his blind, elderly friend, Mr. Janssen.";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 700);
	for (i = 0;i < strlen(str6);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str6[i]);
	}

	char str7[] = "After a pleasant visit, he started walking home.";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 650);
	for (i = 0;i < strlen(str7);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str7[i]);
	}
	char str8[] = "On his way, though, he was distracted by the trees and birds.";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 600);
	for (i = 0;i < strlen(str8);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str8[i]);
	}
	char str9[] = "He played for many happy hours near the dikes that ran by the road.";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 550);
	for (i = 0;i < strlen(str9);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str9[i]);
	}

	char str10[] = "The dikes were large walls that held back the sea.";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 500);
	for (i = 0;i < strlen(str10);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str10[i]);
	}

	char str11[] = "PRESS 'a' TO CONTINUE";
	glColor3f(1, 1, 1);
	glRasterPos2f(390, 30);
	for (i = 0;i < strlen(str11);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str11[i]);
	}
	glutKeyboardFunc(key1);           //Keyboard function key1 is called here   
	glFlush();
}

//KEY a is pressed second_window is destroyed and third_window is opened

void key1(unsigned char key, int x, int y)
{
	if (key == 'a')                                                         //Key a is pressed
	{
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1350, 695);
		glutInitWindowPosition(0, -300);
		glutDestroyWindow(id1);
		id2 = glutCreateWindow("THE LITTLE DUTCH BOY WHO SAVED THE HOLLAND");
		glutDisplayFunc(third_window);
	}
}
void tree(int t1, int t2, int s1, int s2)
{

	glPushMatrix();
	glScalef(s1, s2, 0);
	glTranslatef(t1, t2, 0);
	glShadeModel(GL_SMOOTH);

	//Leaf
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.9, 0.2);
	glVertex2f(16.5, 70);
	glVertex2f(12.5, 70);
	glVertex2f(11, 71.5);
	glVertex2f(10, 72.5);
	glColor3f(0.0, 0.85, 0.1);
	glVertex2f(10, 75);
	glVertex2f(7.5, 75);
	glVertex2f(6, 76);
	glVertex2f(5, 78.5);
	glVertex2f(5, 80);
	glVertex2f(7.5, 82.5);
	glVertex2f(5, 85);
	glVertex2f(2.7, 87);
	glVertex2f(2.75, 90);
	glColor3f(0.1, 0.6, 0.1);
	glVertex2f(2.8, 91);
	glVertex2f(3.5, 92.5);
	glVertex2f(5, 95);
	glVertex2f(7, 97.5);
	glVertex2f(10, 98);
	glVertex2f(15, 99);
	glColor3f(0.1, 0.6, 0.2);
	glVertex2f(20, 98.5);
	glVertex2f(25, 98);
	glVertex2f(30, 97.5);
	glVertex2f(30.5, 97);
	glVertex2f(30, 95);
	glVertex2f(32.5, 92.5);
	glVertex2f(34, 87.5);
	glVertex2f(35, 85);
	glVertex2f(34.5, 82.5);
	glVertex2f(34, 79);
	glVertex2f(34.5, 77.5);
	glColor3f(0.1, 0.6, 0.0);
	glVertex2f(33, 76);
	glVertex2f(32.5, 74.5);
	glVertex2f(31, 73);
	glVertex2f(30, 72.5);
	glVertex2f(27.5, 72.5);
	glVertex2f(26, 73);
	glVertex2f(25, 75);
	glEnd();

	//Trunk and Branches

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.6, 0.0);
	glVertex2f(17.5, 56);
	glVertex2f(17.0, 62.5);
	glVertex2f(17.5, 67.5);
	glVertex2f(16.5, 70.0);
	glVertex2f(16.0, 72.5);
	glVertex2f(15.5, 75.0);
	glVertex2f(15.0, 80.0);
	glVertex2f(20.0, 85.0);
	glVertex2f(21.5, 77.0);
	glVertex2f(26.0, 87.0);
	glVertex2f(30.0, 85.0);
	glVertex2f(28.0, 80.0);
	glVertex2f(25.5, 75.0);
	glVertex2f(25, 72.5);
	glVertex2f(25, 70.0);
	glVertex2f(25.0, 55.0);
	glVertex2f(25.5, 52.5);
	glVertex2f(26.0, 50.0);
	glVertex2f(26.5, 48.0);
	glVertex2f(27.0, 47.5);
	glVertex2f(28.5, 46.0);
	glVertex2f(29, 44);
	glVertex2f(30.0, 40.0);
	glVertex2f(20.0, 47.5 - 8);
	glVertex2f(17.5, 47.0 - 10);
	glVertex2f(18.0, 50.0 - 10);
	glVertex2f(17.0, 54.0 - 10);
	glVertex2f(20.0, 53.0 - 10);
	glVertex2f(17.5, 56.0 - 10);
	glEnd();

	glPopMatrix();
}



//THIRD WINDOW FUNCTION
void third_window()
{
	glClearColor(0, 1, 1, 1);                //Sky blue
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1000, 0, 1000);
	glMatrixMode(GL_MODELVIEW);



	//Drawing hill

	// Hill
	glBegin(GL_POLYGON);
	glColor3f(0, 0.6, 0);                       //dark green
	glVertex2f(0, 700 + 50);
	glVertex2f(400, 700 + 50);
	glVertex2f(200, 900);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0.6, 0);
	glVertex2f(600, 700 + 50);
	
	glVertex2f(800, 900);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0.6, 0);
	glVertex2f(350, 700 + 50);
	glVertex2f(650, 700 + 50);
	glVertex2f(500, 800 + 50);
	glEnd();

	// Grass
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);      //light green
	glVertex2f(0, 0);
	glVertex2f(0, 700 + 50);
	glVertex2f(1000, 700 + 50);
	glVertex2f(1000, 0);
	glEnd();


	//Sun

	glBegin(GL_POLYGON);
	glColor3f(1, 0.75, 0);        //orange
	gluOrtho2D(0, 1000, 0, 1000);
	for (i = 0;i < 360;i++)
	{
		
		glVertex2f(630 + 40 * cos(theta), 920 + 65 * sin(theta));
	}

	glEnd();


	//Drawing a house


	//RECTANGLE
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(100, 150);
	glVertex2f(100, 500);
	glVertex2f(300, 500);
	glVertex2f(300, 150);
	glEnd();

	//TRIANGLE
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.5, 0);
	glVertex2f(80, 500);
	glVertex2f(320, 500);
	glVertex2f(200, 650);
	glEnd();


	//DOOR
	glBegin(GL_POLYGON);
	glColor3f(0.91, 0.76, 0.65);
	glVertex2f(170, 150);
	glVertex2f(170, 350);
	glVertex2f(230, 350);
	glVertex2f(230, 150);
	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(220, 230);
	glVertex2f(220, 238);
	glVertex2f(225, 238);
	glVertex2f(225, 230);
	glEnd();


	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(170, 150);
	glVertex2f(170, 350);
	glVertex2f(230, 350);
	glVertex2f(230, 150);
	glEnd();


	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(170, 350);
	glVertex2f(230, 350);
	glEnd();


	//WINDOW LEFT
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.9, 1);
	glVertex2f(120, 300);
	glVertex2f(120, 400);
	glVertex2f(150, 400);
	glVertex2f(150, 300);
	glEnd();

	//WINDOW RIGHT
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.9, 1);
	glVertex2f(250, 300);

	glVertex2f(280, 400);
	glVertex2f(280, 300);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(120, 300);
	glVertex2f(120, 400);
	glVertex2f(150, 400);
	glVertex2f(150, 300);
	glVertex2f(250, 300);
	glVertex2f(250, 400);
	glVertex2f(280, 400);
	glVertex2f(280, 300);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(120, 300);
	glVertex2f(150, 300);
	glEnd();


	glBegin(GL_LINES);
	glVertex2f(120, 400);
	glVertex2f(150, 400);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(250, 300);
	glVertex2f(280, 300);
	glEnd();


	glBegin(GL_LINES);
	glVertex2f(250, 400);
	glVertex2f(280, 400);
	glEnd();

	//End of house

	//tree 1

	tree(130, -25, 6, 9);

	tree(130, -34, 5, 9);
	//tree2




	//ROAD
	glBegin(GL_POLYGON);
	glColor3f(0.36, 0.25, 0.20);
	glVertex2f(0, 0);
	
	glVertex2f(1000, 149);
	glVertex2f(1000, 0);
	glEnd();


	//blind woman


			//back hair
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	
	glVertex2i(192 - 100, 186);
	glVertex2i(186 - 100, 218);
	glVertex2i(155 - 100, 218);
	glEnd();





	glBegin(GL_POLYGON);
	glColor3ub(255, 191, 128);        //skin color
	gluOrtho2D(0, 1000, 0, 1000);
	for (i = 0;i < 360;i++)
	{
		theta = i * (3.142 / 180);
		glVertex2f(70 + 16 * cos(theta), 198 + 18 * sin(theta));
	}

	glEnd();


	//hair
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex2i(152 - 100, 210);
	glVertex2i(188 - 100, 210);
	glVertex2i(182 - 100, 218);
	glVertex2i(159 - 100, 218);
	glEnd();





	//skirt




	//////////////////////////////skirt
	glBegin(GL_POLYGON);
	glColor3f(1, 0.3, 0.7);
	
	glVertex2f(55, 180);
	glVertex2f(85, 180);
	glVertex2f(90, 90);
	glEnd();


	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(50, 90);
	glVertex2f(55, 180);
	glVertex2f(85, 180);
	glVertex2f(90, 90);
	glVertex2f(50, 90);
	glVertex2f(90, 90);
	glVertex2f(55, 180);
	glVertex2f(85, 180);
	glEnd();


	//shoe left
	glBegin(GL_POLYGON);
	glColor3ub(300, 10, 10);
	glVertex2i(60, 105 - 15);
	glVertex2i(60, 96 - 15);
	glVertex2i(42, 96 - 15);
	glVertex2i(50, 105 - 15);
	glEnd();

	//shoe right
	glBegin(GL_POLYGON);
	glColor3ub(300, 10, 10);
	glVertex2i(80, 105 - 15);
	glVertex2i(80, 96 - 15);
	glVertex2i(98, 96 - 15);
	glVertex2i(90, 105 - 15);
	glEnd();





	//stick
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(42, 80);
	glVertex2i(42, 147);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(43, 80);
	glVertex2i(43, 147);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(44, 80);
	glVertex2i(44, 147);
	glEnd();




	//hands
///////////////////////////////////////////////////////////////////////


	glBegin(GL_POLYGON);
	glColor3ub(240, 184, 128);
	glVertex2i(465 - 368, 170 - 10);
	glVertex2i(473 - 368, 153 - 10);
	glVertex2i(467 - 368, 154 - 10);
	glVertex2i(462 - 368, 163 - 10);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(475 - 369, 153 - 10);
	if (flag == 0)
	{
		glVertex2i(456 - 367, 138 - 10);
		glVertex2i(456 - 367, 145 - 10);
	}
	else
		if (flag == 1)
		{

			glVertex2i(456 - 367, 160 - 10);
			glVertex2i(446 - 367, 150 - 10);
		}
	glVertex2i(465 - 367, 154 - 10);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2i(415 - 374, 170 - 5);
	glVertex2i(405 - 374, 150 - 5);
	glVertex2i(413 - 374, 150 - 5);
	glVertex2i(418 - 374, 163 - 5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(405 - 374, 153 - 5);
	if (flag == 0)
	{
		glVertex2i(424 - 380, 138 - 5);
		glVertex2i(424 - 380, 145 - 5);
	}
	else
		if (flag == 1)
		{

			glVertex2i(413 - 380, 160 - 5);
			glVertex2i(413 - 380, 150 - 5);
		}
	glVertex2i(413 - 380, 154 - 5);
	glEnd();









	//left hand skirt
	glBegin(GL_POLYGON);
	
	glVertex2f(43, 150);
	glVertex2f(55, 160);
	glVertex2f(55, 180);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(40, 170);
	glVertex2f(43, 150);
	glVertex2f(55, 160);
	glVertex2f(55, 180);
	glVertex2f(40, 170);
	glVertex2f(55, 180);
	glVertex2f(55, 160);
	glVertex2f(43, 150);
	glEnd();

	//right hand skirt

	glBegin(GL_POLYGON);
	glColor3f(1, 0.3, 0.7);
	glVertex2f(100, 170);
	glVertex2f(93, 150);
	glVertex2f(85, 160);
	glVertex2f(85, 180);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(100, 170);
	glVertex2f(93, 150);
	glVertex2f(85, 160);
	glVertex2f(85, 180);
	glVertex2f(100, 170);
	glVertex2f(85, 180);
	glVertex2f(93, 150);
	glVertex2f(85, 160);
	glEnd();






	/////////////////////////////////////////////////////////////////////////////////////

		// eyes
	glBegin(GL_POLYGON);
	glVertex2i(33 + 30, 198);
	glVertex2i(35 + 30, 198);
	glVertex2i(35 + 30, 196);
	glVertex2i(33 + 30, 196);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(45 + 30, 198);
	glVertex2i(47 + 30, 198);
	glVertex2i(47 + 30, 196);
	glVertex2i(45 + 30, 196);
	glEnd();

	// mouth
	glBegin(GL_POLYGON);
	glVertex2i(35 + 30, 187);
	glVertex2i(40 + 30, 185);
	glVertex2i(45 + 30, 187);
	glVertex2i(40 + 30, 187);
	glEnd();


	////////
	glBegin(GL_LINES);
	glColor3ub(0, 0, 0);
	glVertex2i(70, 195);
	glVertex2i(70, 190); //nose
	glVertex2i(61, 200);
	glVertex2i(67, 200);//eyebrow
	glVertex2i(73, 200);
	glVertex2i(79, 200);//eyebrow
	glEnd();

	///////////


	char str35[] = "PRESS 'd' TO CONTINUE";
	glColor3f(1, 1, 1);
	glRasterPos2f(390, 30);
	for (i = 0;i < strlen(str35);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str35[i]);
	}

	boy(0);

	glutKeyboardFunc(key4);
	glFlush();

}

void key4(unsigned char key, int x, int y)
{
	if (key == 'd')                                                         //Key d is pressed
	{
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1350, 695);
		glutInitWindowPosition(0, -300);
		glutDestroyWindow(id2);
		id3 = glutCreateWindow("THE LITTLE DUTCH BOY WHO SAVED THE HOLLAND");
		glutDisplayFunc(fourth_window);
	}
}

//FOURTH WINDOW FUNCTION
void fourth_window()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1000, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	char str12[] = "Hans was so busy playing that he didn’t notice the sun setting.";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 700);
	for (i = 0;i < strlen(str12);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str12[i]);
	}

	char str13[] = "When he realized how late it was, he speedily headed for home";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 650);
	for (i = 0;i < strlen(str13);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str13[i]);
	}
	char str14[] = "On his way, though, he heard water trickling.";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 600);
	for (i = 0;i < strlen(str14);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str14[i]);
	}
	char str15[] = "There in the dike was a small hole.";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 550);
	for (i = 0;i < strlen(str15);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str15[i]);
	}

	char str16[] = "Hans knew that left untended, the hold would grow larger";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 500);
	for (i = 0;i < strlen(str16);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str16[i]);
	}

	char str17[] = "and the sea would come crashing through.";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 450);
	for (i = 0;i < strlen(str17);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str17[i]);
	}

	char str18[] = "PRESS 'b' TO CONTINUE";
	glColor3f(1, 1, 1);
	glRasterPos2f(390, 30);
	for (i = 0;i < strlen(str18);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str18[i]);
	}
	glutKeyboardFunc(key2);
	glFlush();
}

void key2(unsigned char key, int x, int y)
{
	if (key == '')                                                         //Key b is pressed
	{
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1350, 695);
		glutInitWindowPosition(0, -300);
		glutDestroyWindow(id3);
		id4 = glutCreateWindow("THE LITTLE DUTCH BOY WHO SAVED THE HOLLAND");
		glutDisplayFunc(fifth_window);
	}


}


//Timer function to switch screen
void Timer(int value)
{
	if (value == 0)
	{
		/*	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
			glutInitWindowSize(1350, 695);
			glutInitWindowPosition(0, -300);
			glutDestroyWindow(id2);
			id3 = glutCreateWindow("FOURTH");
			glutDisplayFunc(fourth_window); */



	}
	else if (value == 1)
	{
		/*	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
			glutInitWindowSize(1350, 695);
			glutInitWindowPosition(0, -300);
			glutDestroyWindow(id4);
			id5 = glutCreateWindow("SIXTH");
			glutDisplayFunc(sixth_window);  */


	}
}


void key5(unsigned char key, int x, int y)
{
	if (key == 'e')                                                         //Key e is pressed
	{
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1350, 695);
		glutInitWindowPosition(0, -300);
		glutDestroyWindow(id4);
		id5 = glutCreateWindow("THE LITTLE DUTCH BOY WHO SAVED THE HOLLAND");
		glutDisplayFunc(sixth_window);
	}


}




//fifth dam window day time window
void fifth_window()
{


	drawing_day();



	char str18[] = "PRESS 'e' TO CONTINUE";
	glColor3f(1, 1, 1);
	glRasterPos2f(390, 30);
	for (i = 0;i < strlen(str18);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str18[i]);
	}


	dike_boy(200);


	hole_in_dike();

	water_leak();


	glutKeyboardFunc(key5);


	//	glutTimerFunc(5000, Timer, 1);             

	glFlush();
}



void sixth_window()
{

	drawing_day();

	hole_in_dike();

	boy_finger(153, 210);



	//glutTimerFunc(5000, Timer, 0);             //Timer Function called here


	char str25[] = "PRESS 'c' TO CONTINUE";
	glColor3f(1, 1, 1);
	glRasterPos2f(390, 30);
	for (i = 0;i < strlen(str25);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str25[i]);
	}
	glutKeyboardFunc(key3);

	glFlush();


}


//Keyboard function to destroy sixth_window and create seventh_window
void key3(unsigned char key, int x, int y)
{
	if (key == 'c')                                                         //Key c is pressed
	{
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1350, 695);
		glutInitWindowPosition(0, -300);
		glutDestroyWindow(id5);
		id6 = glutCreateWindow("THE LITTLE DUTCH BOY WHO SAVED THE HOLLAND");
		glutDisplayFunc(seventh_window);
	}

}



//seventh window

void seventh_window()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1000, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	char str19[] = "He quickly put his finger in the dike and cried for help, but alas, no help came.";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 700);
	for (i = 0;i < strlen(str19);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str19[i]);
	}

	char str20[] = "All night long, Hans sat there with his finger in the dark.";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 650);
	for (i = 0;i < strlen(str20);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str20[i]);
	}
	char str21[] = "He was very cold and very frightened.";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 600);
	for (i = 0;i < strlen(str21);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str21[i]);
	}
	char str22[] = "In the morning, a priest came along the road and heard Hans’ moans for help.";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 550);
	for (i = 0;i < strlen(str22);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str22[i]);
	}

	char str23[] = "The priest quickly called for others to come and repair the dike and he carried the boy home.";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 500);
	for (i = 0;i < strlen(str23);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str23[i]);
	}

	char str24[] = "All the people cheered for Hans, the boy who saved Holland.";
	glColor3f(1, 1, 1);
	glRasterPos2f(250, 450);
	for (i = 0;i < strlen(str24);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str24[i]);
	}


	char str25[] = "PRESS 'f' TO CONTINUE";
	glColor3f(1, 1, 1);
	glRasterPos2f(390, 30);
	for (i = 0;i < strlen(str25);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str25[i]);
	}
	glutKeyboardFunc(key6);


	glFlush();
}

void key6(unsigned char key, int x, int y)
{
	if (key == 'f')                                                         //Key f is pressed
	{
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1350, 695);
		glutInitWindowPosition(0, -300);
		glutDestroyWindow(id6);
		id7 = glutCreateWindow("THE LITTLE DUTCH BOY WHO SAVED THE HOLLAND");
		glutDisplayFunc(eighth_window);
	}

}



void key7(unsigned char key, int x, int y)
{
	if (key == 'g')                                                         //Key g is pressed
	{
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1350, 695);
		glutDestroyWindow(id7);
		id8 = glutCreateWindow("THE LITTLE DUTCH BOY WHO SAVED THE HOLLAND");
		glutDisplayFunc(nineth_window);
	}

}




//eighth window night view dam window
void eighth_window()
{

	drawing_night();

	hole_in_dike();

	boy_finger(153, 210);

	char str25[] = "PRESS 'g' TO CONTINUE";
	glColor3f(1, 1, 1);
	glRasterPos2f(390, 30);
	for (i = 0;i < strlen(str25);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str25[i]);
	}
	glutKeyboardFunc(key7);

	//glutTimerFunc(5000, Timer, 0);             //Timer Function called here

	glFlush();
}


void nineth_window()
{




	drawing_day();

	hole_in_dike();

	char str37[] = "PRESS 'h' TO CONTINUE";
	glColor3f(1, 1, 1);
	glRasterPos2f(390, 30);
	for (i = 0;i < strlen(str37);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str37[i]);
	}



	boy_finger(153, 210);



	priest();



	glutKeyboardFunc(key8);


	glFlush();


}



void key8(unsigned char key, int x, int y)
{
	if (key == 'h')                                                         //Key g is pressed
	{
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1350, 695);
		glutInitWindowPosition(0, -300);
		glutDestroyWindow(id8);
		id9 = glutCreateWindow("THE LITTLE DUTCH BOY WHO SAVED THE HOLLAND");
		glutDisplayFunc(tenth_window);
	}

}

void key9(unsigned char key, int x, int y)
{
	if (key == 'k')                                                         //Key k is pressed
	{
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1350, 695);
		glutInitWindowPosition(0, -300);
		glutDestroyWindow(id9);
		id10 = glutCreateWindow("THE LITTLE DUTCH BOY WHO SAVED THE HOLLAND");
		glutDisplayFunc(final_window);
	}

}

void tenth_window()
{



	drawing_day();
	drawKid(450, 350, 0.6, 0.9, 4, 80, 100);

	char str38[] = "PRESS 'k' TO CONTINUE";
	glColor3f(1, 1, 1);
	glRasterPos2f(390, 30);
	for (i = 0;i < strlen(str38);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str38[i]);
	}


	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(400, 280);
	glVertex2f(400, 320);
	glVertex2f(440, 320);
	glVertex2f(440, 280);

	glEnd();


	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(400, 280);
	glVertex2f(400, 320);
	glVertex2f(440, 320);
	glVertex2f(440, 280);
	glVertex2f(400, 280);
	glVertex2f(440, 280);
	glVertex2f(400, 320);
	glVertex2f(440, 320);
	glEnd();

	//priest

	glBegin(GL_POLYGON);
	glColor3ub(255, 191, 128);        //skin color

	gluOrtho2D(0, 300, 0, 300);
	for (i = 0;i < 360;i++)
	{
		theta = i * (3.142 / 180);
		glVertex2f(222 - 170 + 250 + 20 * cos(theta), 200 + 20 * sin(theta) + 20);
	}

	glEnd();

	glColor3ub(240, 184, 128);
	glPushMatrix();
	glTranslatef(440 - 220 - 170 + 250 + 2, 195 + 20, 0); //face position
	glutSolidTorus(7, 7, 100, 90);
	glPopMatrix();


	glBegin(GL_LINES);
	glColor3ub(0, 0, 0);
	glVertex2i(440 - 220 - 170 + 250 + 2, 195 + 20);
	glVertex2i(440 - 220 - 170 + 250 + 2, 190 + 20); //nose
	glVertex2i(431 - 220 - 170 + 250 + 2, 200 + 20);
	glVertex2i(437 - 220 - 170 + 250 + 2, 200 + 20);//eyebrow
	glVertex2i(443 - 220 - 170 + 250 + 2, 200 + 20);
	glVertex2i(449 - 220 - 170 + 250 + 2, 200 + 20);//eyebrow
	glEnd();

	//ear right
	glBegin(GL_POLYGON);
	//glColor3ub(255, 191, 128);
	glColor3ub(240, 184, 128);
	glVertex2i(440 + 21 - 220 - 170 + 250 + 4, 194 + 8 + 20);
	glVertex2i(440 + 21 - 220 - 170 + 250 + 4, 190 + 8 + 20);
	glVertex2i(438 + 20.5 - 220 - 170 + 250 + 4, 189 + 8 + 20);
	glVertex2i(438 + 20.5 - 220 - 170 + 250 + 4, 195 + 8 + 20);
	glEnd();

	//ear left
	glBegin(GL_POLYGON);
	glColor3ub(240, 184, 128);

	glVertex2i(456 - 33.5 - 220 - 170 + 250, 194 + 8 + 20);
	glVertex2i(456 - 33.5 - 220 - 170 + 250, 190 + 8 + 20);
	glVertex2i(454 - 34.5 - 220 - 170 + 250, 189 + 8 + 20);
	glVertex2i(454 - 34.5 - 220 - 170 + 250, 195 + 8 + 20);

	glEnd();

	//hair
	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.1, 0.1f);
	glVertex2i(422 - 220 - 170 + 250, 180 + 20 + 30);
	glVertex2i(422 - 220 - 170 + 250, 221 + 20 + 30);
	glVertex2i(455 - 220 - 170 + 250 + 7, 221 + 20 + 30);
	glVertex2i(455 - 220 - 170 + 250 + 7, 180 + 20 + 30);
	glEnd();

	////hair
	//glBegin(GL_POLYGON);
	//glColor3ub(0, 0, 0);
	//glVertex2i(425 - 220, 203);
	//glVertex2i(453 - 220, 203);
	//glVertex2i(447 - 220, 209);
	//glVertex2i(433 - 220, 209);
	////glEnd();


	// eyes
	glBegin(GL_POLYGON);
	glVertex2i(433 - 220 - 170 + 250 + 2, 198 + 20);
	glVertex2i(435 - 220 - 170 + 250 + 2, 198 + 20);
	glVertex2i(435 - 220 - 170 + 250 + 2, 196 + 20);
	glVertex2i(433 - 220 - 170 + 250 + 2, 196 + 20);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(445 - 220 - 170 + 250 + 2, 198 + 20);
	glVertex2i(447 - 220 - 170 + 250 + 2, 198 + 20);
	glVertex2i(447 - 220 - 170 + 250 + 2, 196 + 20);
	glVertex2i(445 - 220 - 170 + 250 + 2, 196 + 20);
	glEnd();

	// mouth
	glBegin(GL_POLYGON);
	glVertex2i(435 - 220 - 170 + 250 + 2, 187 + 20);
	glVertex2i(440 - 220 - 170 + 250 + 2, 185 + 20);
	glVertex2i(445 - 220 - 170 + 250 + 2, 187 + 20);
	glVertex2i(440 - 220 - 170 + 250 + 2, 187 + 20);
	glEnd();


	//shirt
	glBegin(GL_POLYGON);
	glColor3f(0, 0.5, 0.5);
	glVertex2i(429 - 220 - 170 + 250, 180 + 20);
	glVertex2i(451 + 7 - 220 - 170 + 250, 180 + 20);
	glVertex2i(466 + 7 - 220 - 170 + 250, 169 + 20);
	glVertex2i(461 + 7 - 220 - 170 + 250, 161 + 20);
	glVertex2i(456 + 7 - 220 - 170 + 250, 165 + 20);
	glVertex2i(456 + 7 - 220 - 170 + 250, 165 + 20);
	glVertex2i(456 + 7 - 220 - 170 + 250, 145 + 20);
	glVertex2i(424 - 220 - 170 + 250, 145 + 20);
	glVertex2i(424 - 220 - 170 + 250, 165 + 20);
	glVertex2i(419 - 220 - 170 + 250, 160 + 20);
	glVertex2i(414 - 220 - 170 + 250, 169 + 20);
	glEnd();


	//hands
	glBegin(GL_POLYGON);
	glColor3ub(240, 184, 128);
	glVertex2i(465 + 7 - 220 - 170 + 250, 168 + 20);
	glVertex2i(475 + 7 - 220 - 170 + 250, 153 + 20);
	glVertex2i(467 + 7 - 220 - 170 + 250, 154 + 20);
	glVertex2i(462 + 7 - 220 - 170 + 250, 162 + 20);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(475 + 7 - 220 - 170 + 250, 153 + 20);
	if (flag == 0)
	{
		glVertex2i(456 + 7 - 220 - 170 + 250, 138 + 20);
		glVertex2i(456 + 7 - 220 - 170 + 250, 145 + 20);
	}
	else
		if (flag == 1)
		{

			glVertex2i(456 + 7 - 220 - 170 + 250, 160 + 20);
			glVertex2i(446 + 7 - 220 - 170 + 250, 150 + 20);
		}
	glVertex2i(467 + 7 - 220 - 170 + 250, 154 + 20);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(415 - 220 - 170 + 250, 168 + 20);
	glVertex2i(405 - 220 - 170 + 250, 153 + 20);
	glVertex2i(413 - 220 - 170 + 250, 154 + 20);
	glVertex2i(418 - 220 - 170 + 250, 162 + 20);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(405 - 220 - 170 + 250, 153 + 20);
	if (flag == 0)
	{
		glVertex2i(424 - 220 - 170 + 250, 138 + 20);
		glVertex2i(424 - 220 - 170 + 250, 145 + 20);
	}
	else
		if (flag == 1)
		{

			glVertex2i(424 - 220 - 170 + 250, 160 + 20);
			glVertex2i(446 - 220 - 170 + 250, 150 + 20);
		}
	glVertex2i(413 - 220 - 170 + 250, 154 + 20);
	glEnd();


	// belt
	glBegin(GL_POLYGON);
	glColor3f(0, 0.5, 0.5);
	glVertex2i(456 - 220 - 170 + 250 + 7, 145 + 20);
	glVertex2i(424 - 220 - 170 + 250, 145 + 20);
	glVertex2i(424 - 220 - 170 + 250, 140 - 15);
	glVertex2i(424 - 220 - 170 + 250, 140 - 15);
	glVertex2i(456 - 220 - 170 + 250 + 7, 140 - 15);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2i(431 - 220 - 170 + 250 + 7, 145 + 20);
	glVertex2i(424 - 220 - 170 + 250, 145 + 20);
	glVertex2i(424 - 220 - 170 + 250, 140 - 15);
	glVertex2i(424 - 220 - 170 + 250, 140 - 15);
	glVertex2i(431 - 220 - 170 + 250 + 7, 140 - 15);
	glEnd();

	//pant
	glBegin(GL_POLYGON);
	glColor3f(0, 0.5, 0.5);
	glVertex2i(455 - 220 - 170 + 250 + 7, 140 + 5);
	glVertex2i(425 - 220 - 170 + 250, 140 + 5);
	glVertex2i(420 - 220 - 170 + 250, 105 - 20);
	glVertex2i(430 - 220 - 170 + 250, 105 - 20);
	glVertex2i(433 - 220 - 170 + 250, 105 - 20);
	glVertex2i(450 - 220 - 170 + 250 + 7, 105 - 20);
	glVertex2i(460 - 220 - 170 + 250 + 7, 105 - 20);
	glEnd();

	//shoe left
	glBegin(GL_POLYGON);
	glColor3ub(100, 10, 10);
	glVertex2i(430 - 220 - 170 + 250, 105 - 20);
	glVertex2i(430 - 220 - 170 + 250, 96 - 20);
	glVertex2i(412 - 220 - 170 + 250, 96 - 20);
	glVertex2i(420 - 220 - 170 + 250, 105 - 20);
	glEnd();

	//shoe right
	glBegin(GL_POLYGON);
	glColor3ub(100, 10, 10);
	glVertex2i(450 - 220 - 170 + 250 + 7, 105 - 20);
	glVertex2i(468 - 220 - 170 + 250 + 7, 96 - 20);
	glVertex2i(460 - 220 - 170 + 250 + 7, 105 - 20);
	glEnd();


	//end of priest


	//BOY


	glBegin(GL_POLYGON);
	glColor3ub(255, 191, 128);        //skin color
	gluOrtho2D(0, 1000, 0, 1000);
	for (i = 0;i < 360;i++)
	{
		theta = i * (3.142 / 180);
		glVertex2f(240 + 13.8 * cos(theta) + 200, 195 + 13.8 * sin(theta) - 10);
	}

	glEnd();



	glColor3ub(255, 191, 128);
	glPushMatrix();
	glTranslatef(540 - 300 + 200, 195 - 10, 0);
	glutSolidTorus(7, 7, 300, 90);
	glPopMatrix();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(540 - 300 + 200, 195 - 10);
	glVertex2i(540 - 300 + 200, 190 - 10); //nose
	glVertex2i(531 - 300 + 200, 200 - 10);
	glVertex2i(537 - 300 + 200, 200 - 10);//eyebrow
	glVertex2i(543 - 300 + 200, 200 - 10);
	glVertex2i(549 - 300 + 200, 200 - 10);//eyebrow
	glEnd();

	//ear right
	glBegin(GL_POLYGON);
	glColor3ub(255, 191, 128);
	glVertex2i(540 - 14 - 300 + 200, 194 + 1 - 10);
	glVertex2i(540 - 14 - 300 + 200, 190 + 1 - 10);
	glVertex2i(538 - 14 - 300 + 200, 189 + 1 - 10);
	glVertex2i(538 - 14 - 300 + 200, 195 + 1 - 10);
	glEnd();

	//ear left
	glBegin(GL_POLYGON);
	glColor3ub(255, 191, 128);
	glVertex2i(554 - 300 + 200, 195 - 10);
	glVertex2i(556 - 300 + 200, 196 - 10);
	glVertex2i(556 - 300 + 200, 191 - 10);
	glVertex2i(554 - 300 + 200, 190 - 10);
	glEnd();

	//hair
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex2i(527 - 300 + 200, 203 - 10);
	glVertex2i(553 - 300 + 200, 203 - 10);
	glVertex2i(547 - 300 + 200, 209 - 10);
	glVertex2i(533 - 300 + 200, 209 - 10);
	glEnd();


	// eyes
	glBegin(GL_POLYGON);
	glVertex2i(533 - 300 + 200, 198 - 10);
	glVertex2i(535 - 300 + 200, 198 - 10);
	glVertex2i(535 - 300 + 200, 196 - 10);
	glVertex2i(533 - 300 + 200, 196 - 10);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(545 - 300 + 200, 198 - 10);
	glVertex2i(547 - 300 + 200, 198 - 10);
	glVertex2i(547 - 300 + 200, 196 - 10);
	glVertex2i(545 - 300 + 200, 196 - 10);
	glEnd();

	// mouth
	glBegin(GL_POLYGON);
	glVertex2i(535 - 300 + 200, 187 - 10);
	glVertex2i(540 - 300 + 200, 185 - 10);
	glVertex2i(545 - 300 + 200, 187 - 10);
	glVertex2i(540 - 300 + 200, 187 - 10);
	glEnd();


	//shirt
	glBegin(GL_POLYGON);
	glColor3f(50, 0, 0);
	glVertex2i(529 - 300 + 200, 180 - 10);
	glVertex2i(551 - 300 + 200, 180 - 10);
	glVertex2i(566 - 300 + 200, 169 - 10);
	glVertex2i(561 - 300 + 200, 161 - 10);
	glVertex2i(556 - 300 + 200, 165 - 10);
	glVertex2i(556 - 300 + 200, 145 - 10);
	glVertex2i(524 - 300 + 200, 145 - 10);
	glVertex2i(524 - 300 + 200, 165 - 10);
	glVertex2i(519 - 300 + 200, 160 - 10);
	glVertex2i(514 - 300 + 200, 169 - 10);
	glEnd();


	//hands
	glBegin(GL_POLYGON);
	glColor3ub(255, 191, 128);
	glVertex2i(565 - 300 + 200, 168 - 10);
	glVertex2i(575 - 300 + 200, 153 - 10);
	glVertex2i(567 - 300 + 200, 154 - 10);
	glVertex2i(562 - 300 + 200, 162 - 10);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(575 - 300 + 200, 153 - 10);
	if (flag == 0)
	{
		glVertex2i(556 - 300 + 200, 138 - 10);
		glVertex2i(556 - 300 + 200, 145 - 10);
	}
	else
		if (flag == 1)
		{

			glVertex2i(556 - 300 + 200, 160 - 10);
			glVertex2i(546 - 300 + 200, 150 - 10);
		}
	glVertex2i(567 - 300 + 200, 154 - 10);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(515 - 300 + 200, 168 - 10);
	glVertex2i(505 - 300 + 200, 153 - 10);
	glVertex2i(513 - 300 + 200, 154 - 10);
	glVertex2i(518 - 300 + 200, 162 - 10);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(505 - 300 + 200, 153 - 10);
	if (flag == 0)
	{
		glVertex2i(524 - 300 + 200, 138 - 10);
		glVertex2i(524 - 300 + 200, 145 - 10);
	}
	else
		if (flag == 1)
		{

			glVertex2i(524 - 300 + 200, 160 - 10);
			glVertex2i(546 - 300 + 200, 150 - 10);
		}
	glVertex2i(513 - 300 + 200, 154 - 10);
	glEnd();


	// belt
	glBegin(GL_POLYGON);
	glColor3ub(150, 12, 30);
	glVertex2i(556 - 300 + 200, 145 - 10);
	glVertex2i(524 - 300 + 200, 145 - 10);
	glVertex2i(524 - 300 + 200, 140 - 10);
	glVertex2i(524 - 300 + 200, 140 - 10);
	glVertex2i(556 - 300 + 200, 140 - 10);
	glEnd();



	//pant
	glBegin(GL_POLYGON);
	glColor3f(1, 0.270588, 0);
	glVertex2i(555 - 300 + 200, 140 - 10);
	glVertex2i(525 - 300 + 200, 140 - 10);
	glVertex2i(520 - 300 + 200, 105 - 10);
	glVertex2i(530 - 300 + 200, 105 - 10);
	glVertex2i(533 - 300 + 200, 138 - 10);
	glVertex2i(550 - 300 + 200, 105 - 10);
	glVertex2i(560 - 300 + 200, 105 - 10);
	glEnd();

	//shoe left
	glBegin(GL_POLYGON);
	glColor3ub(300, 10, 10);
	glVertex2i(530 - 300 + 200, 105 - 10);
	glVertex2i(530 - 300 + 200, 96 - 10);
	glVertex2i(512 - 300 + 200, 96 - 10);
	glVertex2i(520 - 300 + 200, 105 - 10);
	glEnd();

	//shoe right
	glBegin(GL_POLYGON);
	glColor3ub(300, 10, 10);
	glVertex2i(550 - 300 + 200, 105 - 10);
	glVertex2i(550 - 300 + 200, 96 - 10);
	glVertex2i(568 - 300 + 200, 96 - 10);
	glVertex2i(560 - 300 + 200, 105 - 10);
	glEnd();

	//End of boy



	glutKeyboardFunc(key9);


	glFlush();


}


//priest code

void priest()
{

	gluOrtho2D(0, 300, 0, 300);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (move <= 250)
	{

		move = move + 0.3;


		glBegin(GL_POLYGON);
		       //skin color

		gluOrtho2D(0, 300, 0, 300);
		for (i = 0;i < 360;i++)
		{
			theta = i * (3.142 / 180);
			glVertex2f(222 - 170 + move + 20 * cos(theta), 200 + 20 * sin(theta) + 20);
		}

		glEnd();

		glColor3ub(240, 184, 128);
		glPushMatrix();
		glTranslatef(440 - 220 - 170 + move + 2, 195 + 20, 0); //face position
		glutSolidTorus(7, 7, 100, 90);
		glPopMatrix();


		glBegin(GL_LINES);
		glColor3ub(0, 0, 0);
		glVertex2i(440 - 220 - 170 + move + 2, 195 + 20);
		glVertex2i(440 - 220 - 170 + move + 2, 190 + 20); //nose
		glVertex2i(431 - 220 - 170 + move + 2, 200 + 20);
		glVertex2i(437 - 220 - 170 + move + 2, 200 + 20);//eyebrow
		glVertex2i(443 - 220 - 170 + move + 2, 200 + 20);
		glVertex2i(449 - 220 - 170 + move + 2, 200 + 20);//eyebrow
		glEnd();

		//ear right
		glBegin(GL_POLYGON);
		//glColor3ub(255, 191, 128);
		glColor3ub(240, 184, 128);
		glVertex2i(440 + 21 - 220 - 170 + move + 4, 194 + 8 + 20);
		glVertex2i(440 + 21 - 220 - 170 + move + 4, 190 + 8 + 20);
		glVertex2i(438 + 20.5 - 220 - 170 + move + 4, 189 + 8 + 20);
		glVertex2i(438 + 20.5 - 220 - 170 + move + 4, 195 + 8 + 20);
		glEnd();

		//ear left
		glBegin(GL_POLYGON);
		glColor3ub(240, 184, 128);

		glVertex2i(456 - 33.5 - 220 - 170 + move, 194 + 8 + 20);
		glVertex2i(456 - 33.5 - 220 - 170 + move, 190 + 8 + 20);
		glVertex2i(454 - 34.5 - 220 - 170 + move, 189 + 8 + 20);
		glVertex2i(454 - 34.5 - 220 - 170 + move, 195 + 8 + 20);

		glEnd();

		//hair
		glBegin(GL_POLYGON);
		glColor3f(0.1f, 0.1, 0.1f);
		glVertex2i(422 - 220 - 170 + move, 180 + 20 + 30);
		glVertex2i(422 - 220 - 170 + move, 221 + 20 + 30);
		glVertex2i(455 - 220 - 170 + move + 7, 221 + 20 + 30);
		glVertex2i(455 - 220 - 170 + move + 7, 180 + 20 + 30);
		glEnd();

		////hair
		//glBegin(GL_POLYGON);
		//glColor3ub(0, 0, 0);
		//glVertex2i(425 - 220, 203);
		//glVertex2i(453 - 220, 203);
		//glVertex2i(447 - 220, 209);
		//glVertex2i(433 - 220, 209);
		////glEnd();


		// eyes
		glBegin(GL_POLYGON);
		glVertex2i(433 - 220 - 170 + move + 2, 198 + 20);
		glVertex2i(435 - 220 - 170 + move + 2, 198 + 20);
		glVertex2i(435 - 220 - 170 + move + 2, 196 + 20);
		glVertex2i(433 - 220 - 170 + move + 2, 196 + 20);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(445 - 220 - 170 + move + 2, 198 + 20);
		glVertex2i(447 - 220 - 170 + move + 2, 198 + 20);
		glVertex2i(447 - 220 - 170 + move + 2, 196 + 20);
		glVertex2i(445 - 220 - 170 + move + 2, 196 + 20);
		glEnd();

		// mouth
		glBegin(GL_POLYGON);
		glVertex2i(435 - 220 - 170 + move + 2, 187 + 20);
		glVertex2i(440 - 220 - 170 + move + 2, 185 + 20);
		glVertex2i(445 - 220 - 170 + move + 2, 187 + 20);
		glVertex2i(440 - 220 - 170 + move + 2, 187 + 20);
		glEnd();


		//shirt
		glBegin(GL_POLYGON);
		glColor3f(0, 0.5, 0.5);
		glVertex2i(429 - 220 - 170 + move, 180 + 20);
		glVertex2i(451 + 7 - 220 - 170 + move, 180 + 20);
		glVertex2i(466 + 7 - 220 - 170 + move, 169 + 20);
		glVertex2i(461 + 7 - 220 - 170 + move, 161 + 20);
		glVertex2i(456 + 7 - 220 - 170 + move, 165 + 20);
		glVertex2i(456 + 7 - 220 - 170 + move, 165 + 20);
		glVertex2i(456 + 7 - 220 - 170 + move, 145 + 20);
		glVertex2i(424 - 220 - 170 + move, 145 + 20);
		glVertex2i(424 - 220 - 170 + move, 165 + 20);
		glVertex2i(419 - 220 - 170 + move, 160 + 20);
		glVertex2i(414 - 220 - 170 + move, 169 + 20);
		glEnd();


		//hands
		glBegin(GL_POLYGON);
		glColor3ub(240, 184, 128);
		glVertex2i(465 + 7 - 220 - 170 + move, 168 + 20);
		glVertex2i(475 + 7 - 220 - 170 + move, 153 + 20);
		glVertex2i(462 + 7 - 220 - 170 + move, 162 + 20);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(475 + 7 - 220 - 170 + move, 153 + 20);
		if (flag == 0)
		{
			glVertex2i(456 + 7 - 220 - 170 + move, 138 + 20);
			glVertex2i(456 + 7 - 220 - 170 + move, 145 + 20);
		}
		else
			if (flag == 1)
			{

				glVertex2i(456 + 7 - 220 - 170 + move, 160 + 20);
				glVertex2i(446 + 7 - 220 - 170 + move, 150 + 20);
			}
		glVertex2i(467 + 7 - 220 - 170 + move, 154 + 20);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(415 - 220 - 170 + move, 168 + 20);
		glVertex2i(405 - 220 - 170 + move, 153 + 20);
		glVertex2i(418 - 220 - 170 + move, 162 + 20);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(405 - 220 - 170 + move, 153 + 20);
		if (flag == 0)
		{
			glVertex2i(424 - 220 - 170 + move, 138 + 20);
			glVertex2i(424 - 220 - 170 + move, 145 + 20);
		}
		else
			if (flag == 1)
			{

				glVertex2i(424 - 220 - 170 + move, 160 + 20);
				glVertex2i(446 - 220 - 170 + move, 150 + 20);
			}
		glVertex2i(413 - 220 - 170 + move, 154 + 20);
		glEnd();


		// belt
		glBegin(GL_POLYGON);
		glColor3f(0, 0.5, 0.5);
		glVertex2i(456 - 220 - 170 + move + 7, 145 + 20);
		glVertex2i(424 - 220 - 170 + move, 145 + 20);
		glVertex2i(424 - 220 - 170 + move, 140 - 15);
		glVertex2i(424 - 220 - 170 + move, 140 - 15);
		glVertex2i(456 - 220 - 170 + move + 7, 140 - 15);
		glEnd();


		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex2i(431 - 220 - 170 + move + 7, 145 + 20);
		glVertex2i(424 - 220 - 170 + move, 145 + 20);
		glVertex2i(424 - 220 - 170 + move, 140 - 15);
		glVertex2i(424 - 220 - 170 + move, 140 - 15);
		glVertex2i(431 - 220 - 170 + move + 7, 140 - 15);
		glEnd();



		//pant
		glBegin(GL_POLYGON);
		glColor3f(0, 0.5, 0.5);
		glVertex2i(455 - 220 - 170 + move + 7, 140 + 5);
		glVertex2i(425 - 220 - 170 + move, 140 + 5);
		glVertex2i(420 - 220 - 170 + move, 105 - 20);
		glVertex2i(430 - 220 - 170 + move, 105 - 20);
		glVertex2i(433 - 220 - 170 + move, 105 - 20);
		glVertex2i(460 - 220 - 170 + move + 7, 105 - 20);
		glEnd();

		//shoe left
		glBegin(GL_POLYGON);
		glColor3ub(100, 10, 10);
		glVertex2i(430 - 220 - 170 + move, 105 - 20);
		glVertex2i(430 - 220 - 170 + move, 96 - 20);
		glVertex2i(412 - 220 - 170 + move, 96 - 20);
		glVertex2i(420 - 220 - 170 + move, 105 - 20);
		glEnd();

		//shoe right
		glBegin(GL_POLYGON);
		glColor3ub(100, 10, 10);
		glVertex2i(450 - 220 - 170 + move + 7, 105 - 20);
		glVertex2i(450 - 220 - 170 + move + 7, 96 - 20);
		glVertex2i(468 - 220 - 170 + move + 7, 96 - 20);
		glVertex2i(460 - 220 - 170 + move + 7, 105 - 20);
		glEnd();





	}


	else
	{

		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);        //skin color

		gluOrtho2D(0, 300, 0, 300);
		for (i = 0;i < 360;i++)
		{
			theta = i * (3.142 / 180);
			glVertex2f(222 - 170 + 250 + 20 * cos(theta), 200 + 20 * sin(theta) + 20);
		}

		glEnd();

		glColor3ub(240, 184, 128);
		glPushMatrix();
		glTranslatef(440 - 220 - 170 + 250 + 2, 195 + 20, 0); //face position
		glutSolidTorus(7, 7, 100, 90);
		glPopMatrix();


		glBegin(GL_LINES);
		glColor3ub(0, 0, 0);
		glVertex2i(440 - 220 - 170 + 250 + 2, 195 + 20);
		glVertex2i(440 - 220 - 170 + 250 + 2, 190 + 20); //nose
		glVertex2i(431 - 220 - 170 + 250 + 2, 200 + 20);
		glVertex2i(437 - 220 - 170 + 250 + 2, 200 + 20);//eyebrow
		glVertex2i(443 - 220 - 170 + 250 + 2, 200 + 20);
		glVertex2i(449 - 220 - 170 + 250 + 2, 200 + 20);//eyebrow
		glEnd();

		//ear right
		glBegin(GL_POLYGON);
		//glColor3ub(255, 191, 128);
		glColor3ub(240, 184, 128);
		glVertex2i(440 + 21 - 220 - 170 + 250 + 4, 194 + 8 + 20);
		glVertex2i(440 + 21 - 220 - 170 + 250 + 4, 190 + 8 + 20);
		glVertex2i(438 + 20.5 - 220 - 170 + 250 + 4, 189 + 8 + 20);
		glVertex2i(438 + 20.5 - 220 - 170 + 250 + 4, 195 + 8 + 20);
		glEnd();

		//ear left
		glBegin(GL_POLYGON);
		glColor3ub(240, 184, 128);

		glVertex2i(456 - 33.5 - 220 - 170 + 250, 194 + 8 + 20);
		glVertex2i(456 - 33.5 - 220 - 170 + 250, 190 + 8 + 20);
		glVertex2i(454 - 34.5 - 220 - 170 + 250, 189 + 8 + 20);
		glVertex2i(454 - 34.5 - 220 - 170 + 250, 195 + 8 + 20);

		glEnd();

		//hair
		glBegin(GL_POLYGON);
		glColor3f(0.1f, 0.1, 0.1f);
		glVertex2i(422 - 220 - 170 + 250, 180 + 20 + 30);
		glVertex2i(422 - 220 - 170 + 250, 221 + 20 + 30);
		glVertex2i(455 - 220 - 170 + 250 + 7, 221 + 20 + 30);
		glVertex2i(455 - 220 - 170 + 250 + 7, 180 + 20 + 30);
		glEnd();

		////hair
		//glBegin(GL_POLYGON);
		//glColor3ub(0, 0, 0);
		//glVertex2i(425 - 220, 203);
		//glVertex2i(453 - 220, 203);
		//glVertex2i(447 - 220, 209);
		//glVertex2i(433 - 220, 209);
		////glEnd();


		// eyes
		glBegin(GL_POLYGON);
		glVertex2i(433 - 220 - 170 + 250 + 2, 198 + 20);
		glVertex2i(435 - 220 - 170 + 250 + 2, 198 + 20);
		glVertex2i(435 - 220 - 170 + 250 + 2, 196 + 20);
		glVertex2i(433 - 220 - 170 + 250 + 2, 196 + 20);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(445 - 220 - 170 + 250 + 2, 198 + 20);
		glVertex2i(447 - 220 - 170 + 250 + 2, 198 + 20);
		glVertex2i(447 - 220 - 170 + 250 + 2, 196 + 20);
		glVertex2i(445 - 220 - 170 + 250 + 2, 196 + 20);
		glEnd();

		// mouth
		glBegin(GL_POLYGON);
		glVertex2i(435 - 220 - 170 + 250 + 2, 187 + 20);
		glVertex2i(440 - 220 - 170 + 250 + 2, 185 + 20);
		glVertex2i(445 - 220 - 170 + 250 + 2, 187 + 20);
		glVertex2i(440 - 220 - 170 + 250 + 2, 187 + 20);
		glEnd();


		//shirt
		glBegin(GL_POLYGON);
		glColor3f(0, 0.5, 0.5);
		glVertex2i(429 - 220 - 170 + 250, 180 + 20);
		glVertex2i(451 + 7 - 220 - 170 + 250, 180 + 20);
		glVertex2i(466 + 7 - 220 - 170 + 250, 169 + 20);
		glVertex2i(461 + 7 - 220 - 170 + 250, 161 + 20);
		glVertex2i(456 + 7 - 220 - 170 + 250, 165 + 20);
		glVertex2i(456 + 7 - 220 - 170 + 250, 165 + 20);
		glVertex2i(456 + 7 - 220 - 170 + 250, 145 + 20);
		glVertex2i(424 - 220 - 170 + 250, 145 + 20);
		glVertex2i(424 - 220 - 170 + 250, 165 + 20);
		glVertex2i(419 - 220 - 170 + 250, 160 + 20);
		glVertex2i(414 - 220 - 170 + 250, 169 + 20);
		glEnd();


		//hands
		glBegin(GL_POLYGON);
		glColor3ub(240, 184, 128);
		glVertex2i(465 + 7 - 220 - 170 + 250, 168 + 20);
		glVertex2i(475 + 7 - 220 - 170 + 250, 153 + 20);
		glVertex2i(467 + 7 - 220 - 170 + 250, 154 + 20);
		glVertex2i(462 + 7 - 220 - 170 + 250, 162 + 20);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(475 + 7 - 220 - 170 + 250, 153 + 20);
		if (flag == 0)
		{
			glVertex2i(456 + 7 - 220 - 170 + 250, 138 + 20);
			glVertex2i(456 + 7 - 220 - 170 + 250, 145 + 20);
		}
		else
			if (flag == 1)
			{

				glVertex2i(456 + 7 - 220 - 170 + 250, 160 + 20);
				glVertex2i(446 + 7 - 220 - 170 + 250, 150 + 20);
			}
		glVertex2i(467 + 7 - 220 - 170 + 250, 154 + 20);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(415 - 220 - 170 + 250, 168 + 20);
		glVertex2i(405 - 220 - 170 + 250, 153 + 20);
		glVertex2i(413 - 220 - 170 + 250, 154 + 20);
		glVertex2i(418 - 220 - 170 + 250, 162 + 20);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(405 - 220 - 170 + 250, 153 + 20);
		if (flag == 0)
		{
			glVertex2i(424 - 220 - 170 + 250, 138 + 20);
			glVertex2i(424 - 220 - 170 + 250, 145 + 20);
		}
		else
			if (flag == 1)
			{

				glVertex2i(424 - 220 - 170 + 250, 160 + 20);
				glVertex2i(446 - 220 - 170 + 250, 150 + 20);
			}
		glVertex2i(413 - 220 - 170 + 250, 154 + 20);
		glEnd();


		// belt
		glBegin(GL_POLYGON);
		glColor3f(0, 0.5, 0.5);
		glVertex2i(456 - 220 - 170 + 250 + 7, 145 + 20);
		glVertex2i(424 - 220 - 170 + 250, 145 + 20);
		glVertex2i(424 - 220 - 170 + 250, 140 - 15);
		glVertex2i(424 - 220 - 170 + 250, 140 - 15);
		glVertex2i(456 - 220 - 170 + 250 + 7, 140 - 15);
		glEnd();


		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex2i(431 - 220 - 170 + 250 + 7, 145 + 20);
		glVertex2i(424 - 220 - 170 + 250, 145 + 20);
		glVertex2i(424 - 220 - 170 + 250, 140 - 15);
		glVertex2i(424 - 220 - 170 + 250, 140 - 15);
		glVertex2i(431 - 220 - 170 + 250 + 7, 140 - 15);
		glEnd();

		//pant
		glBegin(GL_POLYGON);
		glColor3f(0, 0.5, 0.5);
		glVertex2i(455 - 220 - 170 + 250 + 7, 140 + 5);
		glVertex2i(425 - 220 - 170 + 250, 140 + 5);
		glVertex2i(420 - 220 - 170 + 250, 105 - 20);
		glVertex2i(430 - 220 - 170 + 250, 105 - 20);
		glVertex2i(433 - 220 - 170 + 250, 105 - 20);
		glVertex2i(450 - 220 - 170 + 250 + 7, 105 - 20);
		glVertex2i(460 - 220 - 170 + 250 + 7, 105 - 20);
		glEnd();

		//shoe left
		glBegin(GL_POLYGON);
		glColor3ub(100, 10, 10);
		glVertex2i(430 - 220 - 170 + 250, 105 - 20);
		glVertex2i(430 - 220 - 170 + 250, 96 - 20);
		glVertex2i(412 - 220 - 170 + 250, 96 - 20);
		glVertex2i(420 - 220 - 170 + 250, 105 - 20);
		glEnd();

		//shoe right
		glBegin(GL_POLYGON);
		glColor3ub(100, 10, 10);
		glVertex2i(450 - 220 - 170 + 250 + 7, 105 - 20);
		glVertex2i(450 - 220 - 170 + 250 + 7, 96 - 20);
		glVertex2i(468 - 220 - 170 + 250 + 7, 96 - 20);
		glVertex2i(460 - 220 - 170 + 250 + 7, 105 - 20);
		glEnd();




	}

	glutPostRedisplay();

	glFlush();



}









//Hole in the dike
void hole_in_dike()
{

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(520, 360);
	glVertex2f(520, 370);
	glVertex2f(528, 370);
	glVertex2f(528, 360);
	glEnd();
}

void water_leak(void)
{

	//falling water
	temp = temp + 0.5;
	glutSwapBuffers();
	if (temp <= 500)
	{


		glBegin(GL_POLYGON);
		glColor3f(0, 0, 1);
		glVertex2f(520, 360 - temp);
		glVertex2f(520, 370 - temp);
		glVertex2f(528, 370 - temp);
		glVertex2f(528, 360 - temp);
		glEnd();


		if (temp >= 70)
		{
			temp = temp - 70;
		}
	}

	glutPostRedisplay();


	glFlush();


}

//Scenary of the dike day

void drawing_day()
{
	glClearColor(0, 1, 1, 1);                //Sky blue
//glClearColor(0, 0.5, 0.5, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1000, 0, 1000);
	glMatrixMode(GL_MODELVIEW);

	//night color ///glColor3f(0, 0.5, 0.5);


	drawing();
	sun();


}

//Scenary of the dike night

void drawing_night()
{
	//glClearColor(0, 1, 1, 1);                //Sky blue
	glClearColor(0, 0.5, 0.5, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glMatrixMode(GL_MODELVIEW);



	drawing();
	moon();


}






void sun()
{

	glBegin(GL_POLYGON);
	glColor3f(1, 0.75, 0);        //orange
	gluOrtho2D(0, 1000, 0, 1000);
	for (i = 0;i < 360;i++)
	{
		theta = i * (3.142 / 180);
		glVertex2f(630 + 40 * cos(theta), 920 + 65 * sin(theta));
	}

	glEnd();



}

void moon()
{

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	gluOrtho2D(0, 1000, 0, 1000);
	for (i = 0;i < 360;i++)
	{
		theta = i * (3.142 / 180);
		glVertex2f(630 + 40 * cos(theta), 920 + 65 * sin(theta));
	}

	glEnd();


}

void drawing()
{



	//water
	glBegin(GL_POLYGON);
	//glColor3f(0, 0.5, 0.5);
	glColor3f(0, 0, 1);
	glVertex2f(0, 0);
	glVertex2f(0, 700);
	glVertex2f(1000, 700);
	glVertex2f(1000, 0);
	glEnd();


	//Drawing dike

	glBegin(GL_POLYGON);
	glColor3f(0.9, 0, 0);
	glVertex2f(0, 0);
	glVertex2f(1, 550);
	glVertex2f(1000, 550);
	glVertex2f(1000, 0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(0, 500);
	glVertex2f(1000, 500);
	glVertex2f(0, 450);
	glVertex2f(1000, 450);
	glVertex2f(0, 400);
	glVertex2f(1000, 400);
	glVertex2f(0, 350);
	glVertex2f(1000, 350);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(50, 500);
	glVertex2f(50, 550);
	glVertex2f(150, 500);
	glVertex2f(150, 550);
	glVertex2f(250, 500);
	glVertex2f(250, 550);
	glVertex2f(350, 500);
	glVertex2f(350, 550);
	glVertex2f(450, 500);
	glVertex2f(450, 550);
	glVertex2f(550, 500);
	glVertex2f(550, 550);
	glVertex2f(650, 500);
	glVertex2f(650, 550);
	glVertex2f(750, 500);
	glVertex2f(750, 550);
	glVertex2f(850, 500);
	glVertex2f(850, 550);
	glVertex2f(950, 500);
	glVertex2f(950, 550);

	glVertex2f(50, 300);
	glVertex2f(50, 350);
	glVertex2f(150, 300);
	glVertex2f(150, 350);
	glVertex2f(250, 300);
	glVertex2f(250, 350);
	glVertex2f(350, 300);
	glVertex2f(350, 350);
	glVertex2f(450, 300);
	glVertex2f(450, 350);
	glVertex2f(550, 300);
	glVertex2f(550, 350);
	glVertex2f(650, 300);
	glVertex2f(650, 350);
	glVertex2f(750, 300);
	glVertex2f(750, 350);
	glVertex2f(850, 300);
	glVertex2f(850, 350);
	glVertex2f(950, 300);
	glVertex2f(950, 350);

	glVertex2f(50, 400);
	glVertex2f(50, 450);
	glVertex2f(150, 400);
	glVertex2f(150, 450);
	glVertex2f(250, 400);
	glVertex2f(250, 450);
	glVertex2f(350, 400);
	glVertex2f(350, 450);
	glVertex2f(450, 400);
	glVertex2f(450, 450);
	glVertex2f(550, 400);
	glVertex2f(550, 450);
	glVertex2f(650, 400);
	glVertex2f(650, 450);
	glVertex2f(750, 400);
	glVertex2f(750, 450);
	glVertex2f(850, 400);
	glVertex2f(850, 450);
	glVertex2f(950, 400);
	glVertex2f(950, 450);

	glVertex2f(100, 500);
	glVertex2f(100, 450);
	glVertex2f(200, 500);
	glVertex2f(200, 450);
	glVertex2f(300, 500);
	glVertex2f(300, 450);
	glVertex2f(400, 500);
	glVertex2f(400, 450);
	glVertex2f(500, 500);
	glVertex2f(500, 450);
	glVertex2f(600, 500);
	glVertex2f(600, 450);
	glVertex2f(700, 500);
	glVertex2f(700, 450);
	glVertex2f(800, 500);
	glVertex2f(800, 450);
	glVertex2f(900, 500);
	glVertex2f(900, 450);
	glVertex2f(1000, 500);
	glVertex2f(1000, 450);

	glVertex2f(100, 400);
	glVertex2f(100, 350);
	glVertex2f(200, 400);
	glVertex2f(200, 350);
	glVertex2f(300, 400);
	glVertex2f(300, 350);
	glVertex2f(400, 400);
	(400, 350);
	glVertex2f(500, 400);
	glVertex2f(500, 350);
	glVertex2f(600, 400);
	glVertex2f(600, 350);
	glVertex2f(700, 400);
	glVertex2f(700, 350);
	glVertex2f(800, 400);
	glVertex2f(800, 350);
	glVertex2f(900, 400);
	glVertex2f(900, 350);
	glVertex2f(1000, 400);
	glVertex2f(1000, 350);

	glEnd();




	// Grass
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);      //light green
	glVertex2f(0, 0);
	glVertex2f(0, 310);
	glVertex2f(1000, 310);
	glVertex2f(1000, 0);
	glEnd();



	//4 trees

	tree(1, -25, 5, 8);
	tree(50, -20, 3, 6);
	tree(160, -25, 5, 8);
	tree(250, -20, 3, 6);



	//ROAD
	glBegin(GL_POLYGON);
	glColor3f(0.36, 0.25, 0.20);
	glVertex2f(0, 0);
	glVertex2f(0, 149);
	glVertex2f(1000, 149);
	glVertex2f(1000, 0);
	glEnd();





}


//first window boy

void boy(int t)
{


	if (m <= 800)
	{

		m = m + 0.5;
		//face
			//	glScalef(1.2,1.2,0);

		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);        //skin color
		gluOrtho2D(0, 1000, 0, 1000);
		for (i = 0;i < 360;i++)
		{
			theta = i * (3.142 / 180);
			glVertex2f(240 + 13.8 * cos(theta) + m - t, 195 + 13.8 * sin(theta));
		}

		glEnd();



		glColor3ub(255, 191, 128);
		glPushMatrix();
		glTranslatef(540 - 300 + m - t, 195, 0);
		glutSolidTorus(7, 7, 300, 90);
		glPopMatrix();

		
		glBegin(GL_LINES);
		glVertex2i(540 - 300 + m - t, 195);
		glVertex2i(540 - 300 + m - t, 190); //nose
		glVertex2i(531 - 300 + m - t, 200);
		glVertex2i(537 - 300 + m - t, 200);//eyebrow
		glVertex2i(543 - 300 + m - t, 200);
		glVertex2i(549 - 300 + m - t, 200);//eyebrow
		glEnd();

		//ear right
		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);
		glVertex2i(540 - 14 - 300 + m - t, 194 + 1);
		glVertex2i(540 - 14 - 300 + m - t, 190 + 1);
		glVertex2i(538 - 14 - 300 + m - t, 189 + 1);
		glVertex2i(538 - 14 - 300 + m - t, 195 + 1);
		glEnd();

		//ear left
		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);
		glVertex2i(554 - 300 + m - t, 195);
		glVertex2i(556 - 300 + m - t, 196);
		glVertex2i(556 - 300 + m - t, 191);
		glVertex2i(554 - 300 + m - t, 190);
		glEnd();

		//hair
		glBegin(GL_POLYGON);
		glColor3ub(0, 0, 0);
		glVertex2i(527 - 300 + m - t, 203);
		glVertex2i(553 - 300 + m - t, 203);
		glVertex2i(547 - 300 + m - t, 209);
		glVertex2i(533 - 300 + m - t, 209);
		glEnd();


		// eyes
		glBegin(GL_POLYGON);
		glVertex2i(533 - 300 + m - t, 198);
		glVertex2i(535 - 300 + m - t, 198);
		glVertex2i(535 - 300 + m - t, 196);
		glVertex2i(533 - 300 + m - t, 196);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(545 - 300 + m - t, 198);
		glVertex2i(547 - 300 + m - t, 198);
		glVertex2i(547 - 300 + m - t, 196);
		glVertex2i(545 - 300 + m - t, 196);
		glEnd();

		// mouth
		glBegin(GL_POLYGON);
		glVertex2i(535 - 300 + m - t, 187);
		glVertex2i(540 - 300 + m - t, 185);
		glVertex2i(545 - 300 + m - t, 187);
		glVertex2i(540 - 300 + m - t, 187);
		glEnd();


		//shirt
		glBegin(GL_POLYGON);
		glColor3f(50, 0, 0);
		glVertex2i(529 - 300 + m - t, 180);
		glVertex2i(551 - 300 + m - t, 180);
		glVertex2i(566 - 300 + m - t, 169);
		glVertex2i(561 - 300 + m - t, 161);
		glVertex2i(556 - 300 + m - t, 165);
		glVertex2i(556 - 300 + m - t, 145);
		glVertex2i(524 - 300 + m - t, 145);
		glVertex2i(524 - 300 + m - t, 165);
		glVertex2i(519 - 300 + m - t, 160);
		glVertex2i(514 - 300 + m - t, 169);
		glEnd();


		//hands
		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);
		glVertex2i(565 - 300 + m - t, 168);
		glVertex2i(575 - 300 + m - t, 153);
		glVertex2i(567 - 300 + m - t, 154);
		glVertex2i(562 - 300 + m - t, 162);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(575 - 300 + m - t, 153);
		if (flag == 0)
		{
			glVertex2i(556 - 300 + m - t, 138);
			glVertex2i(556 - 300 + m - t, 145);
		}
		else
			if (flag == 1)
			{

				glVertex2i(556 - 300 + m - t, 160);
				glVertex2i(546 - 300 + m - t, 150);
			}
		glVertex2i(567 - 300 + m - t, 154);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(515 - 300 + m - t, 168);
		glVertex2i(505 - 300 + m - t, 153);
		glVertex2i(513 - 300 + m - t, 154);
		glVertex2i(518 - 300 + m - t, 162);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(505 - 300 + m - t, 153);
		if (flag == 0)
		{
			glVertex2i(524 - 300 + m - t, 138);
			glVertex2i(524 - 300 + m - t, 145);
		}
		else
			if (flag == 1)
			{

				glVertex2i(524 - 300 + m - t, 160);
				glVertex2i(546 - 300 + m - t, 150);
			}
		glVertex2i(513 - 300 + m - t, 154);
		glEnd();


		// belt
		glBegin(GL_POLYGON);
		glColor3ub(150, 12, 30);
		glVertex2i(556 - 300 + m - t, 145);
		glVertex2i(524 - 300 + m - t, 145);
		glVertex2i(524 - 300 + m - t, 140);
		glVertex2i(524 - 300 + m - t, 140);
		glVertex2i(556 - 300 + m - t, 140);
		glEnd();



		//pant
		glBegin(GL_POLYGON);
		glColor3f(1, 0.270588, 0);
		glVertex2i(555 - 300 + m - t, 140);
		glVertex2i(525 - 300 + m - t, 140);
		glVertex2i(520 - 300 + m - t, 105);
		glVertex2i(530 - 300 + m - t, 105);
		glVertex2i(533 - 300 + m - t, 138);
		glVertex2i(550 - 300 + m - t, 105);
		glVertex2i(560 - 300 + m - t, 105);
		glEnd();

		//shoe left
		glBegin(GL_POLYGON);
		glColor3ub(300, 10, 10);
		glVertex2i(530 - 300 + m - t, 105);
		glVertex2i(530 - 300 + m - t, 96);
		glVertex2i(512 - 300 + m - t, 96);
		glVertex2i(520 - 300 + m - t, 105);
		glEnd();

		//shoe right
		glBegin(GL_POLYGON);
		glColor3ub(300, 10, 10);
		glVertex2i(550 - 300 + m - t, 105);
		glVertex2i(550 - 300 + m - t, 96);
		glVertex2i(568 - 300 + m - t, 96);
		glVertex2i(560 - 300 + m - t, 105);
		glEnd();

	}
	else
	{


		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);        //skin color
		gluOrtho2D(0, 1000, 0, 1000);
		for (i = 0;i < 360;i++)
		{
			theta = i * (3.142 / 180);
			glVertex2f(240 + 13.8 * cos(theta) - t + 800, 195 + 13.8 * sin(theta));
		}

		glEnd();



		glColor3ub(255, 191, 128);
		glPushMatrix();
		glTranslatef(540 - 300 - t + 800, 195, 0);
		glutSolidTorus(7, 7, 300, 90);
		glPopMatrix();

		glColor3ub(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2i(540 - 300 - t + 800, 195);
		glVertex2i(540 - 300 - t + 800, 190); //nose
		glVertex2i(531 - 300 - t + 800, 200);
		glVertex2i(537 - 300 - t + 800, 200);//eyebrow
		glVertex2i(543 - 300 - t + 800, 200);
		glVertex2i(549 - 300 - t + 800, 200);//eyebrow
		glEnd();

		//ear right
		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);
		glVertex2i(540 - 14 - 300 - t + 800, 194 + 1);
		glVertex2i(540 - 14 - 300 - t + 800, 190 + 1);
		glVertex2i(538 - 14 - 300 - t + 800, 189 + 1);
		glVertex2i(538 - 14 - 300 - t + 800, 195 + 1);
		glEnd();

		//ear left
		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);
		glVertex2i(554 - 300 - t + 800, 195);
		glVertex2i(556 - 300 - t + 800, 196);
		glVertex2i(556 - 300 - t + 800, 191);
		glVertex2i(554 - 300 - t + 800, 190);
		glEnd();

		//hair
		glBegin(GL_POLYGON);
		glColor3ub(0, 0, 0);
		glVertex2i(527 - 300 - t + 800, 203);
		glVertex2i(553 - 300 - t + 800, 203);
		glVertex2i(547 - 300 - t + 800, 209);
		glVertex2i(533 - 300 - t + 800, 209);
		glEnd();


		// eyes
		glBegin(GL_POLYGON);
		glVertex2i(533 - 300 - t + 800, 198);
		glVertex2i(535 - 300 - t + 800, 198);
		glVertex2i(535 - 300 - t + 800, 196);
		glVertex2i(533 - 300 - t + 800, 196);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(545 - 300 - t + 800, 198);
		glVertex2i(547 - 300 - t + 800, 198);
		glVertex2i(547 - 300 - t + 800, 196);
		glVertex2i(545 - 300 - t + 800, 196);
		glEnd();

		// mouth
		glBegin(GL_POLYGON);
		glVertex2i(535 - 300 - t + 800, 187);
		glVertex2i(540 - 300 - t + 800, 185);
		glVertex2i(545 - 300 - t + 800, 187);
		glVertex2i(540 - 300 - t + 800, 187);
		glEnd();


		//shirt
		glBegin(GL_POLYGON);
		glColor3f(50, 0, 0);
		glVertex2i(529 - 300 - t + 800, 180);
		glVertex2i(551 - 300 - t + 800, 180);
		glVertex2i(566 - 300 - t + 800, 169);
		glVertex2i(561 - 300 - t + 800, 161);
		glVertex2i(556 - 300 - t + 800, 165);
		glVertex2i(556 - 300 - t + 800, 145);
		glVertex2i(524 - 300 - t + 800, 145);
		glVertex2i(524 - 300 - t + 800, 165);
		glVertex2i(519 - 300 - t + 800, 160);
		glVertex2i(514 - 300 - t + 800, 169);
		glEnd();


		//hands
		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);
		glVertex2i(565 - 300 - t + 800, 168);
		glVertex2i(575 - 300 - t + 800, 153);
		glVertex2i(567 - 300 - t + 800, 154);
		glVertex2i(562 - 300 - t + 800, 162);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(575 - 300 - t + 800, 153);
		if (flag == 0)
		{
			glVertex2i(556 - 300 - t + 800, 138);
			glVertex2i(556 - 300 - t + 800, 145);
		}
		else
			if (flag == 1)
			{

				glVertex2i(556 - 300 - t + 800, 160);
				glVertex2i(546 - 300 - t + 800, 150);
			}
		glVertex2i(567 - 300 - t + 800, 154);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(515 - 300 - t + 800, 168);
		glVertex2i(505 - 300 - t + 800, 153);
		glVertex2i(513 - 300 - t + 800, 154);
		glVertex2i(518 - 300 - t + 800, 162);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(505 - 300 - t + 800, 153);
		if (flag == 0)
		{
			glVertex2i(524 - 300 - t + 800, 138);
			glVertex2i(524 - 300 - t + 800, 145);
		}
		else
			if (flag == 1)
			{

				glVertex2i(524 - 300 - t + 800, 160);
				glVertex2i(546 - 300 - t + 800, 150);
			}
		glVertex2i(513 - 300 - t + 800, 154);
		glEnd();


		// belt
		glBegin(GL_POLYGON);
		glColor3ub(150, 12, 30);
		glVertex2i(556 - 300 - t + 800, 145);
		glVertex2i(524 - 300 - t + 800, 145);
		glVertex2i(524 - 300 - t + 800, 140);
		glVertex2i(524 - 300 - t + 800, 140);
		glVertex2i(556 - 300 - t + 800, 140);
		glEnd();



		//pant
		glBegin(GL_POLYGON);
		glColor3f(1, 0.270588, 0);
		glVertex2i(555 - 300 - t + 800, 140);
		glVertex2i(525 - 300 - t + 800, 140);
		glVertex2i(520 - 300 - t + 800, 105);
		glVertex2i(530 - 300 - t + 800, 105);
		glVertex2i(533 - 300 - t + 800, 138);
		glVertex2i(550 - 300 - t + 800, 105);
		glVertex2i(560 - 300 - t + 800, 105);
		glEnd();

		//shoe left
		glBegin(GL_POLYGON);
		glColor3ub(300, 10, 10);
		glVertex2i(530 - 300 - t + 800, 105);
		glVertex2i(530 - 300 - t + 800, 96);
		glVertex2i(512 - 300 - t + 800, 96);
		glVertex2i(520 - 300 - t + 800, 105);
		glEnd();

		//shoe right
		glBegin(GL_POLYGON);
		glColor3ub(300, 10, 10);
		glVertex2i(550 - 300 - t + 800, 105);
		glVertex2i(550 - 300 - t + 800, 96);
		glVertex2i(568 - 300 - t + 800, 96);
		glVertex2i(560 - 300 - t + 800, 105);
		glEnd();


	}






	glutPostRedisplay();
	glFlush();

}

void dike_boy(int x)
{


	if (n <= 500)
	{

		n = n + 0.5;
		//face
			//	glScalef(1.2,1.2,0);

		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);        //skin color
		gluOrtho2D(0, 1000, 0, 1000);
		for (i = 0;i < 360;i++)
		{
			theta = i * (3.142 / 180);
			glVertex2f(240 + 13.8 * cos(theta) + n - x, 195 + 13.8 * sin(theta));
		}

		glEnd();



		 
		glPushMatrix();
		glTranslatef(540 - 300 + n - x, 195, 0);
		glutSolidTorus(7, 7, 300, 90);
		glPopMatrix();

		glColor3ub(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2i(540 - 300 + n - x, 195);
		glVertex2i(540 - 300 + n - x, 190); //nose
		glVertex2i(531 - 300 + n - x, 200);
		glVertex2i(537 - 300 + n - x, 200);//eyebrow
		glVertex2i(543 - 300 + n - x, 200);
		glVertex2i(549 - 300 + n - x, 200);//eyebrow
		glEnd();

		//ear right
		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);
		glVertex2i(540 - 14 - 300 + n - x, 194 + 1);
		glVertex2i(540 - 14 - 300 + n - x, 190 + 1);
		glVertex2i(538 - 14 - 300 + n - x, 189 + 1);
		glVertex2i(538 - 14 - 300 + n - x, 195 + 1);
		glEnd();

		//ear left
		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);
		glVertex2i(554 - 300 + n - x, 195);
		glVertex2i(556 - 300 + n - x, 196);
		glVertex2i(556 - 300 + n - x, 191);
		glVertex2i(554 - 300 + n - x, 190);
		glEnd();

		//hair
		glBegin(GL_POLYGON);
		glColor3ub(0, 0, 0);
		glVertex2i(527 - 300 + n - x, 203);
		glVertex2i(553 - 300 + n - x, 203);
		glVertex2i(547 - 300 + n - x, 209);
		glVertex2i(533 - 300 + n - x, 209);
		glEnd();


		// eyes
		glBegin(GL_POLYGON);
		glVertex2i(533 - 300 + n - x, 198);
		
		glVertex2i(535 - 300 + n - x, 196);
		glVertex2i(533 - 300 + n - x, 196);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(545 - 300 + n - x, 198);
		glVertex2i(547 - 300 + n - x, 198);
		glVertex2i(547 - 300 + n - x, 196);
		glVertex2i(545 - 300 + n - x, 196);
		glEnd();

		// mouth
		glBegin(GL_POLYGON);
		glVertex2i(535 - 300 + n - x, 187);
		glVertex2i(540 - 300 + n - x, 185);
		glVertex2i(545 - 300 + n - x, 187);
		glVertex2i(540 - 300 + n - x, 187);
		glEnd();


		//shirt
		glBegin(GL_POLYGON);
		glColor3f(50, 0, 0);
		glVertex2i(529 - 300 + n - x, 180);
		glVertex2i(551 - 300 + n - x, 180);
		glVertex2i(566 - 300 + n - x, 169);
		glVertex2i(561 - 300 + n - x, 161);
		glVertex2i(556 - 300 + n - x, 165);
		glVertex2i(556 - 300 + n - x, 145);
		glVertex2i(524 - 300 + n - x, 145);
		glVertex2i(524 - 300 + n - x, 165);
		glVertex2i(519 - 300 + n - x, 160);
		glVertex2i(514 - 300 + n - x, 169);
		glEnd();


		//hands
		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);
		glVertex2i(565 - 300 + n - x, 168);
		glVertex2i(575 - 300 + n - x, 153);
		glVertex2i(567 - 300 + n - x, 154);
		glVertex2i(562 - 300 + n - x, 162);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(575 - 300 + n - x, 153);
		if (flag == 0)
		{
			glVertex2i(556 - 300 + n - x, 138);
			glVertex2i(556 - 300 + n - x, 145);
		}
		else
			if (flag == 1)
			{

				glVertex2i(556 - 300 + n - x, 160);
				glVertex2i(546 - 300 + n - x, 150);
			}
		glVertex2i(567 - 300 + n - x, 154);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(515 - 300 + n - x, 168);
		glVertex2i(505 - 300 + n - x, 153);
		glVertex2i(513 - 300 + n - x, 154);
		glVertex2i(518 - 300 + n - x, 162);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(505 - 300 + n - x, 153);
		if (flag == 0)
		{
			glVertex2i(524 - 300 + n - x, 138);
			glVertex2i(524 - 300 + n - x, 145);
		}
		else
			if (flag == 1)
			{

				glVertex2i(524 - 300 + n - x, 160);
				glVertex2i(546 - 300 + n - x, 150);
			}
		glVertex2i(513 - 300 + n - x, 154);
		glEnd();


		// belt
		glBegin(GL_POLYGON);
		glColor3ub(150, 12, 30);
		glVertex2i(556 - 300 + n - x, 145);
		glVertex2i(524 - 300 + n - x, 145);
		glVertex2i(524 - 300 + n - x, 140);
		glVertex2i(524 - 300 + n - x, 140);
		glVertex2i(556 - 300 + n - x, 140);
		glEnd();



		//pant
		glBegin(GL_POLYGON);
		glColor3f(1, 0.270588, 0);
		glVertex2i(555 - 300 + n - x, 140);
		glVertex2i(525 - 300 + n - x, 140);
		glVertex2i(520 - 300 + n - x, 105);
		glVertex2i(530 - 300 + n - x, 105);
		glVertex2i(533 - 300 + n - x, 138);
		glVertex2i(550 - 300 + n - x, 105);
		glVertex2i(560 - 300 + n - x, 105);
		glEnd();

		//shoe left
		glBegin(GL_POLYGON);
		glColor3ub(300, 10, 10);
		glVertex2i(530 - 300 + n - x, 105);
		glVertex2i(530 - 300 + n - x, 96);
		glVertex2i(512 - 300 + n - x, 96);
		glVertex2i(520 - 300 + n - x, 105);
		glEnd();

		//shoe right
		glBegin(GL_POLYGON);
		glColor3ub(300, 10, 10);
		glVertex2i(550 - 300 + n - x, 105);
		glVertex2i(550 - 300 + n - x, 96);
		glVertex2i(568 - 300 + n - x, 96);
		glVertex2i(560 - 300 + n - x, 105);
		glEnd();

	}
	else
	{



		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);        //skin color
		gluOrtho2D(0, 1000, 0, 1000);
		for (i = 0;i < 360;i++)
		{
			theta = i * (3.142 / 180);
			glVertex2f(240 + 13.8 * cos(theta) + 500 - x, 195 + 13.8 * sin(theta));
		}

		glEnd();



		glColor3ub(255, 191, 128);
		glPushMatrix();
		glTranslatef(540 - 300 + 500 - x, 195, 0);
		glutSolidTorus(7, 7, 300, 90);
		glPopMatrix();

		glColor3ub(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2i(540 - 300 + 500 - x, 195);
		glVertex2i(540 - 300 + 500 - x, 190); //nose
		glVertex2i(531 - 300 + 500 - x, 200);
		glVertex2i(537 - 300 + 500 - x, 200);//eyebrow
		glVertex2i(543 - 300 + 500 - x, 200);
		glVertex2i(549 - 300 + 500 - x, 200);//eyebrow
		glEnd();

		//ear right
		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);
		glVertex2i(540 - 14 - 300 + 500 - x, 194 + 1);
		glVertex2i(540 - 14 - 300 + 500 - x, 190 + 1);
		glVertex2i(538 - 14 - 300 + 500 - x, 189 + 1);
		glVertex2i(538 - 14 - 300 + 500 - x, 195 + 1);
		glEnd();

		//ear left
		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);
		glVertex2i(554 - 300 + 500 - x, 195);
		glVertex2i(556 - 300 + 500 - x, 196);
		glVertex2i(556 - 300 + 500 - x, 191);
		glVertex2i(554 - 300 + 500 - x, 190);
		glEnd();

		//hair
		glBegin(GL_POLYGON);
		glColor3ub(0, 0, 0);
		glVertex2i(527 - 300 + 500 - x, 203);
		glVertex2i(553 - 300 + 500 - x, 203);
		glVertex2i(547 - 300 + 500 - x, 209);
		glVertex2i(533 - 300 + 500 - x, 209);
		glEnd();


		// eyes
		glBegin(GL_POLYGON);
		glVertex2i(533 - 300 + 500 - x, 198);
		glVertex2i(535 - 300 + 500 - x, 198);
		glVertex2i(535 - 300 + 500 - x, 196);
		glVertex2i(533 - 300 + 500 - x, 196);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(545 - 300 + 500 - x, 198);
		glVertex2i(547 - 300 + 500 - x, 198);
		glVertex2i(547 - 300 + 500 - x, 196);
		glVertex2i(545 - 300 + 500 - x, 196);
		glEnd();

		// mouth
		glBegin(GL_POLYGON);
		glVertex2i(535 - 300 + 500 - x, 187);
		glVertex2i(540 - 300 + 500 - x, 185);
		glVertex2i(545 - 300 + 500 - x, 187);
		glVertex2i(540 - 300 + 500 - x, 187);
		glEnd();


		//shirt
		glBegin(GL_POLYGON);
		glColor3f(50, 0, 0);
		glVertex2i(529 - 300 + 500 - x, 180);
		glVertex2i(551 - 300 + 500 - x, 180);
		glVertex2i(566 - 300 + 500 - x, 169);
		glVertex2i(561 - 300 + 500 - x, 161);
		glVertex2i(556 - 300 + 500 - x, 165);
		glVertex2i(556 - 300 + 500 - x, 145);
		glVertex2i(524 - 300 + 500 - x, 145);
		glVertex2i(524 - 300 + 500 - x, 165);
		glVertex2i(519 - 300 + 500 - x, 160);
		glVertex2i(514 - 300 + 500 - x, 169);
		glEnd();


		//hands
		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);
		glVertex2i(565 - 300 + 500 - x, 168);
		glVertex2i(575 - 300 + 500 - x, 153);
		glVertex2i(567 - 300 + 500 - x, 154);
		glVertex2i(562 - 300 + 500 - x, 162);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(575 - 300 + 500 - x, 153);
		if (flag == 0)
		{
			glVertex2i(556 - 300 + 500 - x, 138);
			glVertex2i(556 - 300 + 500 - x, 145);
		}
		else
			if (flag == 1)
			{

				glVertex2i(556 - 300 + 500 - x, 160);
				glVertex2i(546 - 300 + 500 - x, 150);
			}
		glVertex2i(567 - 300 + 500 - x, 154);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(515 - 300 + 500 - x, 168);
		glVertex2i(505 - 300 + 500 - x, 153);
		glVertex2i(513 - 300 + 500 - x, 154);
		glVertex2i(518 - 300 + 500 - x, 162);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2i(505 - 300 + 500 - x, 153);
		if (flag == 0)
		{
			glVertex2i(524 - 300 + 500 - x, 138);
			glVertex2i(524 - 300 + 500 - x, 145);
		}
		else
			if (flag == 1)
			{

				glVertex2i(524 - 300 + 500 - x, 160);
				glVertex2i(546 - 300 + 500 - x, 150);
			}
		glVertex2i(513 - 300 + 500 - x, 154);
		glEnd();


		// belt
		glBegin(GL_POLYGON);
		glColor3ub(150, 12, 30);
		glVertex2i(556 - 300 + 500 - x, 145);
		glVertex2i(524 - 300 + 500 - x, 145);
		glVertex2i(524 - 300 + 500 - x, 140);
		glVertex2i(524 - 300 + 500 - x, 140);
		glVertex2i(556 - 300 + 500 - x, 140);
		glEnd();



		//pant
		glBegin(GL_POLYGON);
		glColor3f(1, 0.270588, 0);
		glVertex2i(555 - 300 + 500 - x, 140);
		glVertex2i(525 - 300 + 500 - x, 140);
		glVertex2i(520 - 300 + 500 - x, 105);
		glVertex2i(530 - 300 + 500 - x, 105);
		glVertex2i(533 - 300 + 500 - x, 138);
		glVertex2i(550 - 300 + 500 - x, 105);
		glVertex2i(560 - 300 + 500 - x, 105);
		glEnd();

		//shoe left
		glBegin(GL_POLYGON);
		glColor3ub(300, 10, 10);
		glVertex2i(530 - 300 + 500 - x, 105);
		glVertex2i(530 - 300 + 500 - x, 96);
		glVertex2i(512 - 300 + 500 - x, 96);
		glVertex2i(520 - 300 + 500 - x, 105);
		glEnd();

		//shoe right
		glBegin(GL_POLYGON);
		glColor3ub(300, 10, 10);
		glVertex2i(550 - 300 + 500 - x, 105);
		glVertex2i(550 - 300 + 500 - x, 96);
		glVertex2i(568 - 300 + 500 - x, 96);
		glVertex2i(560 - 300 + 500 - x, 105);
		glEnd();


	}


	glutPostRedisplay();
	glFlush();

}


//Boy finger


void boy_finger(int a, int b)
{


	//face
	glBegin(GL_POLYGON);
	glColor3ub(255, 191, 128);        //skin color
	gluOrtho2D(0, 1000, 0, 1000);
	for (i = 0;i < 360;i++)
	{
		theta = i * (3.142 / 180);
		glVertex2f(320 + 13.8 * cos(theta) + a, 195 + 13.8 * sin(theta) + b);
	}

	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(540 - 220 + a, 195 + b);
	glVertex2i(540 - 220 + a, 190 + b); //nose
	glVertex2i(531 - 220 + a, 200 + b);
	glVertex2i(537 - 220 + a, 200 + b);//eyebrow
	glVertex2i(543 - 220 + a, 200 + b);
	glVertex2i(549 - 220 + a, 200 + b);//eyebrow
	glEnd();

	//ear right
	glBegin(GL_POLYGON);
	glColor3ub(255, 191, 128);
	glVertex2i(540 - 14 - 220 + a, 194 + 1 + b);
	glVertex2i(540 - 14 - 220 + a, 190 + 1 + b);
	glVertex2i(538 - 14 - 220 + a, 189 + 1 + b);
	glVertex2i(538 - 14 - 220 + a, 195 + 1 + b);
	glEnd();

	//ear left
	glBegin(GL_POLYGON);
	glColor3ub(255, 191, 128);
	glVertex2i(554 - 220 + a, 195 + b);
	glVertex2i(556 - 220 + a, 196 + b);
	glVertex2i(556 - 220 + a, 191 + b);
	glVertex2i(554 - 220 + a, 190 + b);
	glEnd();

	//hair
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex2i(527 - 220 + a, 203 + b);
	glVertex2i(553 - 220 + a, 203 + b);
	glVertex2i(547 - 220 + a, 209 + b);
	glVertex2i(533 - 220 + a, 209 + b);
	glEnd();


	// eyes
	glBegin(GL_POLYGON);
	glVertex2i(533 - 220 + a, 198 + b);
	glVertex2i(535 - 220 + a, 198 + b);
	glVertex2i(535 - 220 + a, 196 + b);
	glVertex2i(533 - 220 + a, 196 + b);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(545 - 220 + a, 198 + b);
	glVertex2i(547 - 220 + a, 198 + b);
	glVertex2i(547 - 220 + a, 196 + b);
	glVertex2i(545 - 220 + a, 196 + b);
	glEnd();

	// mouth
	glBegin(GL_POLYGON);
	glVertex2i(535 - 220 + a, 187 + b);
	glVertex2i(540 - 220 + a, 185 + b);
	glVertex2i(545 - 220 + a, 187 + b);
	glVertex2i(540 - 220 + a, 187 + b);
	glEnd();


	//shirt
	glBegin(GL_POLYGON);
	glColor3f(50, 0, 0);
	glVertex2i(529 - 220 + a, 180 + b);
	glVertex2i(551 - 220 + a, 180 + b);
	glVertex2i(566 - 220 + a, 169 + b);
	glVertex2i(561 - 220 + a, 161 + b);
	glVertex2i(556 - 220 + a, 165 + b);
	glVertex2i(556 - 220 + a, 145 + b);
	glVertex2i(524 - 220 + a, 145 + b);
	glVertex2i(524 - 220 + a, 165 + b);
	glVertex2i(519 - 220 + a, 160 + b);
	glVertex2i(514 - 220 + a, 169 + b);
	glEnd();


	//hands

//right hand	
	glBegin(GL_POLYGON);
	glColor3ub(255, 191, 128);
	glVertex2i(565 - 220 + a, 174 - 5 + b);
	glVertex2i(575 - 220 + a, 153 - 5 + b);
	glVertex2i(567 - 220 + a, 154 - 5 + b);
	glVertex2i(562 - 220 + a, 167 - 5 + b);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 191, 128);
	glVertex2i(565 - 218 + a, 168 - 20 + b);
	glVertex2i(565 - 218 + a, 175 - 20 + b);
	glVertex2i(580 - 218 + a, 175 - 20 + b);
	glVertex2i(580 - 218 + a, 168 - 20 + b);
	glEnd();

	// hand in the dike
	glBegin(GL_POLYGON);
	glColor3ub(255, 191, 128);
	glVertex2f(271 + 92 + a, 330 - 182 + b);
	glVertex2f(269 + 92 + a, 338 - 182 + b);
	glVertex2f(280 + 92 + a, 343 - 182 + b);
	glVertex2f(283 + 92 + a, 342 - 182 + b);
	glVertex2f(283 + 92 + a, 330 - 182 + b);
	glVertex2f(280 + 92 + a, 330 - 182 + b);
	glVertex2f(269 + 92 + a, 332 - 182 + b);
	glEnd();
	//right HAND OUTLINE
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex2f(283 + 92 + a, 330 - 182 + b);
	glVertex2f(280 + 92 + a, 330 - 182 + b);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(275 + 92 + a, 329 - 182 + b);
	glVertex2f(283 + 92 + a, 329 - 182 + b);
	glVertex2f(275 + 92 + a, 332 - 182 + b);
	glVertex2f(283 + 92 + a, 332 - 182 + b);
	glVertex2f(275 + 92 + a, 335 - 182 + b);
	glVertex2f(283 + 92 + a, 335 - 182 + b);
	glVertex2f(275 + 92 + a, 338 - 182 + b);
	glVertex2f(283 + 92 + a, 338 - 182 + b);
	glEnd();

	// hand end

	//Left hand

	glBegin(GL_POLYGON);
	glColor3ub(255, 191, 128);
	glVertex2i(515 - 220 + a, 168 + b);
	glVertex2i(505 - 220 + a, 153 + b);
	glVertex2i(513 - 220 + a, 154 + b);
	glVertex2i(518 - 220 + a, 162 + b);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 191, 128);
	glVertex2i(505 - 220 + a, 153 + b);
	if (flag == 0)
	{
		glVertex2i(524 - 220 + a, 138 + b);
		glVertex2i(524 - 220 + a, 145 + b);
	}
	else
		if (flag == 1)
		{

			glVertex2i(524 - 220 + a, 160 + b);
			glVertex2i(546 - 220 + a, 150 + b);
		}
	glVertex2i(513 - 220 + a, 154 + b);
	glEnd();


	// belt
	glBegin(GL_POLYGON);
	glColor3ub(150, 12, 30);
	glVertex2i(556 - 220 + a, 145 + b);
	glVertex2i(524 - 220 + a, 145 + b);
	glVertex2i(524 - 220 + a, 140 + b);
	glVertex2i(524 - 220 + a, 140 + b);
	glVertex2i(556 - 220 + a, 140 + b);
	glEnd();



	//pant
	glBegin(GL_POLYGON);
	glColor3f(1, 0.270588, 0);
	glVertex2i(555 - 220 + a, 140 + b);
	glVertex2i(525 - 220 + a, 140 + b);
	glVertex2i(520 - 220 + a, 105 + b);
	glVertex2i(530 - 220 + a, 105 + b);
	glVertex2i(533 - 220 + a, 138 + b);
	glVertex2i(550 - 220 + a, 105 + b);
	glVertex2i(560 - 220 + a, 105 + b);
	glEnd();

	//shoe left
	glBegin(GL_POLYGON);
	glColor3ub(100, 10, 10);
	glVertex2i(530 - 220 + a, 96 + b);
	glVertex2i(512 - 220 + a, 96 + b);
	glVertex2i(520 - 220 + a, 105 + b);
	glEnd();

	//shoe right
	glBegin(GL_POLYGON);
	glColor3ub(100, 10, 10);
	glVertex2i(550 - 220 + a, 105 + b);
	glVertex2i(550 - 220 + a, 96 + b);
	glVertex2i(568 - 220 + a, 96 + b);
	glVertex2i(560 - 220 + a, 105 + b);
	glEnd();






}


void final_window()
{

	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1000, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	char str40[] = "THE END";
	glColor3f(1, 1, 1);
	glRasterPos2f(450, 650);
	for (i = 0;i < strlen(str40);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str40[i]);
	}

	glFlush();

}



void main(int argc, char ** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1350, 695);
	glutInitWindowPosition(0, -300);
	id = glutCreateWindow("THE LITTLE DUTCH BOY WHO SAVED THE HOLLAND");
	glutDisplayFunc(display);
	glutMainLoop();
}

