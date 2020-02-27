#include <GL/glut.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <SDL/SDL.h>



      int   m_x,m_y;                // mouse x y
      bool  m_down = false;

      int   play = true;            //
      int   size_ = 5;              //

const int   X=240;            // 
const int   Y=120;            // 


int w =  X*size_;              //
int h =  Y*size_;              //


// this struct defines the cell, which is 
struct P
{
    bool life;
    int next;
} p [X][Y];





void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255,255,255);
    glPointSize(size_);
    glBegin(GL_POINTS);
    for (int y = 0; y < Y; ++y)
        for (int x = 0; x < X; ++x)
            if (p[x][y].life) glVertex2f(size_/2 + x*size_, size_/2 + y*size_);


    if (m_down && m_x > 0 && m_y > 0 &&  m_x < X * size_ && m_y < Y*size_)

        p[m_x/size_][m_y/size_].life = 1;

        else
                    {
                        int x = m_x/size_;  int y = m_y/size_;
                        glVertex2f(size_/2 + size_ * x ,size_/2 + size_ * y);
                    }

    glEnd();

    glutSwapBuffers(); //glFlush();

}


// this function captures the left cell values
int left (int xx)
{
    if (xx == 0 ) 
        xx = X - 1; 
    else 
        xx--;
 return xx;
}


// this function captures the right cell values
int right (int xx)
{
    if (xx == X - 1 ) 
        xx = 0; 
    else 
        xx++;
 return xx;
}

// this function captures the up cell values
int up (int yy)
{
    if (yy == 0 ) 
        yy = Y-1; 
    else 
        yy--;
 return yy;
}

// this function captures the down cell values
int down (int yy)
{
    if (yy == Y - 1 ) 
        yy = 0; 
    else 
        yy++;
 return yy;
}

// this fucntion updates each cell values in the matrix

void update()
{

      for (int y = 0; y < Y; ++y) for (int x = 0; x < X; ++x)
      {
                  int counter    = 0;

                  if (p[left(x)]    [y].life)    counter++;         //left
                  if (p[right(x)]   [y].life)    counter++;         //right
                  if (p[x]          [up(y)].life) counter++;        //up
                  if (p[x]          [down(y)].life) counter++;      //down

                  if (p[left(x)]    [up(y)].life) counter++;        //left  +  up
                  if (p[right(x)]   [up(y)].life) counter++;         //right + down

                  if (p[left(x)]    [down(y)].life) counter++;      //left + up
                  if (p[right(x)]   [down(y)].life) counter++;      //right

                  if ( p[x][y].life) if (counter != 2 && counter != 3) p[x][y].next = false; else p[x][y].next = true;
                  if (!p[x][y].life) if (counter == 3) p[x][y].next = true; else p[x][y].next = false;
      }
        for (int y = 0; y < Y; ++y) for (int x = 0; x < X; ++x)
        p[x][y].life  = p[x][y].next;


}


// Reads the imput from user in order to stop, start or clear the game
void tasten( unsigned char key, int xmouse, int ymouse)
{
    switch (key)
    {
    case '1':
        play = 1;
        break;
    
    case '2':
        play = 0;
        break;

    case '3':   for (int y = 0; y < Y; ++y) { 
                    for (int x = 0; x < X; ++x) {
                    p[x][y].next =0; 
                    p[x][y].life  = 0;
                    }
                }
        break;
    //
    default:
        break;
    }
}
// Timer function responsibility is to manage the time flux in the program
void timer(int = 0)
{
    glutKeyboardFunc(tasten);
    
    if (play) update ();

    display();
    glutTimerFunc(10, timer, 0);
}

// this function tracks the mouse position and interaction
void mouse (int button, int state, int ax, int ay)
{
    m_y=ay; //| -> position
    m_x=ax; //|
    m_down = state == GLUT_DOWN; // | -> reads if button was clicked
}

// captures the mouse motion in the scene
void motion (int ax, int ay)
{
    m_x=ax;
    m_y=ay;
}


// captures the passive mouse motion in the scene
void motionpass (int ax, int ay)
{
   m_x=ax;
   m_y=ay;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////  MAIN FUNCTION OF CONAWAY'S GAME OF LIFE ////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    /* the next nested loops create the initial state of the layout */
    for (int x = 0; x < X; x++)
        for (int y = 0; y < Y; y++)
       {

            p[x][y].life  = 0; //rand()% 2;
            p[x][y].next  = 0;
      }

      /*This statement prepare the library to run*/
      glutInit(&argc, argv);

        /*These two statements can define the display mode: 
        *
        * GLUT_SIGLE/DOUBLE -> bit mask for double or single buffered window
        * GLUT_RGB/RGBA -> color mode for the window 
        * 
        *  */
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
      //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

      /* As The function says this defines thw width and height of the window 
      *
      *     w and h are defined in lines 13 and 14 -> they depend on X and Y parameters multiplied by the cell size (size_);
      */ 
      glutInitWindowSize(w, h);
      
      /* The next function defines the initial position of the window that we are going to create
      *
      *     We must give a (X, Y) coordinates  
      */
      glutInitWindowPosition(-10, -10);

      /* Whe summon a window with the next method by giving it the name of the window as parameter */
      glutCreateWindow("Brownian motion");

      /* This statement gives the window a color by terms of RGBA ([0-1][0-1][0-1][0-1] )*/
      glClearColor(0, 0, 0, 1.0);

      /* The next fucntion applies the matrix operations to the projection of the matrix stack*/
      glMatrixMode(GL_PROJECTION);

      /* This replaces the current matrix with the identity matrix */
      glLoadIdentity();
      
      /* The next statement sets an ortographic projection (multiplies the current matrix with an ortographic matrix) */
      glOrtho (0, w, h, 0, -1, 1);

      /* The next statement "paints" the function that we are going to show. In this case we are passing the display function, which was defined before */
      glutDisplayFunc(display);



      /* We summon the timer function which allows us to manage time*/
      timer();

      /* The next fuction keeps the mouse moovement */
      glutMouseFunc(mouse);

      /* This statements reports the mouse movement while a button is pressed */
      glutMotionFunc(motion);

      /* Same as previous but without dragging*/
      glutPassiveMotionFunc(motionpass);

      glutMainLoop();

      
}




