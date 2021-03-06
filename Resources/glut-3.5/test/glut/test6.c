
/* Copyright (c) Mark J. Kilgard, 1994. */

/* This program is freely distributable without licensing fees 
   and is provided without guarantee or warrantee expressed or 
   implied. This program is -not- in the public domain. */

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

void
display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
}

void
time7(int value)
{
  if (value != 7) {
    printf("FAIL: time7 expected 6\n");
    exit(1);
  }
  printf("PASS: test6\n");
  exit(0);
}

void
mstatus(int state)
{
  printf("state: %d\n", state);
}

void
mstatus2(int state, int x, int y)
{
  printf("state: %d, x=%d, y=%d\n", state, x, y);
}

void
menu2(int value)
{
  printf("menu item selected: %d\n", value);
  if (value != 46) {
    printf("FAIL: time6 expected 45\n");
    exit(1);
  }
  glutDestroyMenu(glutGetMenu());
  glutDestroyWindow(glutGetWindow());
  glutTimerFunc(1000, time7, 7);
}

void
time6(int value)
{
  if (value != 6) {
    printf("FAIL: time6 expected 6\n");
    exit(1);
  }
  glutMenuStateFunc(mstatus);
  glutMenuStatusFunc(mstatus2);
  glutCreateMenu(menu2);
  glutAddMenuEntry("name", 46);
  glutAttachMenu(GLUT_LEFT_BUTTON);
  glutAttachMenu(GLUT_MIDDLE_BUTTON);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  printf("Pop up menu with any mouse button and select the item\n");
}

int estate = 0;

void
entry(int state)
{
  printf("entry: %s\n", state == GLUT_LEFT ? "left" : "entered");
  switch (estate) {
  case 0:
    if (state == GLUT_LEFT)
      estate++;
    break;
  case 1:
    if (state == GLUT_ENTERED)
      estate++;
    glutTimerFunc(1000, time6, 6);
    glutEntryFunc(NULL);
    break;
  }
}

void
time5(int value)
{
  if (value != 5) {
    printf("FAIL: time5 expected 5\n");
    exit(1);
  }
  glutEntryFunc(entry);
  printf("In the black window, leave it, then enter it\n");
}

void
motion(int x, int y)
{
  printf("motion x=%d, y=%d\n", x, y);
  glutMotionFunc(NULL);
  glutTimerFunc(1000, time5, 5);
}

void
time4(int value)
{
  if (value != 4) {
    printf("FAIL: time4 expected 4\n");
    exit(1);
  }
  glutMotionFunc(motion);
  printf("In the black window, move mouse with some button held down\n");
}

void
passive(int x, int y)
{
  printf("passive x=%d, y=%d\n", x, y);
  glutTimerFunc(1000, time4, 4);
  glutPassiveMotionFunc(NULL);
}

void
time3(int value)
{
  if (value != 3) {
    printf("FAIL: time3 expected 3\n");
    exit(1);
  }
  glutPassiveMotionFunc(passive);
  printf("In the black window, mouse the mouse around with NO buttons down\n");
}

int mode = 0;

void
mouse(int button, int state, int x, int y)
{
  printf("but=%d, state=%d, x=%d, y=%d\n", button, state, x, y);
  switch (mode) {
  case 0:
    if (button != GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      printf("FAIL: mouse left down not found\n");
      exit(1);
    }
    if (glutGetModifiers() != 0) {
      printf("FAIL: mouse expected no modifier\n");
      exit(1);
    }
    break;
  case 1:
    if (button != GLUT_LEFT_BUTTON && state == GLUT_UP) {
      printf("FAIL: mouse left up not found\n");
      exit(1);
    }
    if (glutGetModifiers() != 0) {
      printf("FAIL: mouse expected no modifier\n");
      exit(1);
    }
    break;
  case 2:
    if (button != GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
      printf("FAIL: mouse center down not found\n");
      exit(1);
    }
    if (glutGetModifiers() != 0) {
      printf("FAIL: mouse expected no modifier\n");
      exit(1);
    }
    break;
  case 3:
    if (button != GLUT_MIDDLE_BUTTON && state == GLUT_UP) {
      printf("FAIL: mouse center up not found\n");
      exit(1);
    }
    if (glutGetModifiers() != 0) {
      printf("FAIL: mouse expected no modifier\n");
      exit(1);
    }
    break;
  case 4:
    if (button != GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
      printf("FAIL: mouse right down not found\n");
      exit(1);
    }
    if (glutGetModifiers() != 0) {
      printf("FAIL: mouse expected no modifier\n");
      exit(1);
    }
    break;
  case 5:
    if (button != GLUT_RIGHT_BUTTON && state == GLUT_UP) {
      printf("FAIL: mouse right up not found\n");
      exit(1);
    }
    if (glutGetModifiers() != 0) {
      printf("FAIL: mouse expected no modifier\n");
      exit(1);
    }
    printf("In the black window, please click: Shift-left, Ctrl-left, then Alt-left (in that order)\n");
    break;
  case 6:
    if (button != GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      printf("FAIL: mouse right down not found\n");
      exit(1);
    }
    if (glutGetModifiers() != GLUT_ACTIVE_SHIFT) {
      printf("FAIL: mouse expected shift modifier\n");
      exit(1);
    }
    break;
  case 7:
    if (button != GLUT_LEFT_BUTTON && state == GLUT_UP) {
      printf("FAIL: mouse right down not found\n");
      exit(1);
    }
    if (glutGetModifiers() != GLUT_ACTIVE_SHIFT) {
      printf("FAIL: mouse expected shift modifier\n");
      exit(1);
    }
    break;
  case 8:
    if (button != GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      printf("FAIL: mouse right down not found\n");
      exit(1);
    }
    if (glutGetModifiers() != GLUT_ACTIVE_CTRL) {
      printf("FAIL: mouse expected ctrl modifier\n");
      exit(1);
    }
    break;
  case 9:
    if (button != GLUT_LEFT_BUTTON && state == GLUT_UP) {
      printf("FAIL: mouse right down not found\n");
      exit(1);
    }
    if (glutGetModifiers() != GLUT_ACTIVE_CTRL) {
      printf("FAIL: mouse expected ctrl modifier\n");
      exit(1);
    }
    break;
  case 10:
    if (button != GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      printf("FAIL: mouse right down not found\n");
      exit(1);
    }
    if (glutGetModifiers() != GLUT_ACTIVE_ALT) {
      printf("FAIL: mouse expected alt modifier\n");
      exit(1);
    }
    break;
  case 11:
    if (button != GLUT_LEFT_BUTTON && state == GLUT_UP) {
      printf("FAIL: mouse right down not found\n");
      exit(1);
    }
    if (glutGetModifiers() != GLUT_ACTIVE_ALT) {
      printf("FAIL: mouse expected alt modifier\n");
      exit(1);
    }
    glutTimerFunc(1000, time3, 3);
    glutMouseFunc(NULL);
    break;
  default:
    printf("FAIL: mouse called with bad mode: %d\n", mode);
    exit(1);
  }
  mode++;
}

/* ARGSUSED */
void
menu(int selection)
{
  printf("FAIL: menu callback should never be called\n");
  exit(1);
}

void
time2(int value)
{
  if (value != 2) {
    printf("FAIL: time2 expected 2\n");
    exit(1);
  }
  glutMouseFunc(mouse);

  /* by attaching and detaching a menu to each button, make
     sure button usage for menus does not mess up normal button 

     callback. */
  glutCreateMenu(menu);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutAttachMenu(GLUT_MIDDLE_BUTTON);
  glutAttachMenu(GLUT_LEFT_BUTTON);
  glutDetachMenu(GLUT_RIGHT_BUTTON);
  glutDetachMenu(GLUT_MIDDLE_BUTTON);
  glutDetachMenu(GLUT_LEFT_BUTTON);
  glutDestroyMenu(glutGetMenu());

  printf("In the black window, please click: left, then middle, then right buttons (in that order)\n");
}

int smode = 0;

/* XXX Warning, sometimes an X window manager will intercept
   some keystroke like Alt-F2.  Be careful about window manager
   interference when running test6. */

void
special(int key, int x, int y)
{
  printf("key=%d, x=%d, y=%d\n", key, x, y);
  switch (smode) {
  case 0:
    if (key != GLUT_KEY_F2) {
      printf("FAIL: special expected F2\n");
      exit(1);
    }
    if (glutGetModifiers() != 0) {
      printf("FAIL: special expected no modifier\n");
      exit(1);
    }
    break;
  case 1:
    if (key != GLUT_KEY_F2) {
      printf("FAIL: special expected F2\n");
      exit(1);
    }
    if (glutGetModifiers() != GLUT_ACTIVE_SHIFT) {
      printf("FAIL: special expected shift modifier\n");
      exit(1);
    }
    break;
  case 2:
    if (key != GLUT_KEY_F2) {
      printf("FAIL: special expected F2\n");
      exit(1);
    }
    if (glutGetModifiers() != GLUT_ACTIVE_CTRL) {
      printf("FAIL: special expected ctrl modifier\n");
      exit(1);
    }
    break;
  case 3:
    if (key != GLUT_KEY_F2) {
      printf("FAIL: special expected F2\n");
      exit(1);
    }
    if (glutGetModifiers() != GLUT_ACTIVE_ALT) {
      printf("FAIL: special expected alt modifier\n");
      exit(1);
    }
    glutSpecialFunc(NULL);
    glutTimerFunc(1000, time2, 2);
    break;
  default:
    printf("FAIL: special called with bad mode: %d\n", smode);
    exit(1);
  }
  smode++;
}

void
time1(int value)
{
  printf("PLEASE EXPECT TO SEE A WARNING ON THE NEXT LINE:\n");
  glutGetModifiers();
  printf("DID YOU SEE A WARNING?  IT IS AN ERROR NOT TO SEE ONE.\n");
  if (value != 1) {
    printf("FAIL: time1 expected 1\n");
    exit(1);
  }
  glutSpecialFunc(special);
  printf("In the black window, please press: F2, Shift-F2, Ctrl-F2, then Alt-F2\n");
}
int kmode = 0;

void
keyboard(unsigned char c, int x, int y)
{
  printf("char=%d, x=%d, y=%d\n", c, x, y);
  switch (kmode) {
  case 0:
    if (c != 'g') {
      printf("FAIL: keyboard expected g\n");
      exit(1);
    }
    if (glutGetModifiers() != 0) {
      printf("FAIL: keyboard expected no modifier\n");
      exit(1);
    }
    break;
  case 1:
    if (c != 'G') {
      printf("FAIL: keyboard expected G\n");
      exit(1);
    }
    if (glutGetModifiers() != GLUT_ACTIVE_SHIFT) {
      printf("FAIL: keyboard expected shift modifier\n");
      exit(1);
    }
    break;
  case 2:
    if (c != 0x7) {     /* Bell, Ctrl-g */
      printf("FAIL: keyboard expected g\n");
      exit(1);
    }
    if (glutGetModifiers() != GLUT_ACTIVE_CTRL) {
      printf("FAIL: keyboard expected ctrl modifier\n");
      exit(1);
    }
    break;
  case 3:
    if (c != 'g') {
      printf("FAIL: keyboard expected g\n");
      exit(1);
    }
    if (glutGetModifiers() != GLUT_ACTIVE_ALT) {
      printf("FAIL: keyboard expected alt modifier\n");
      exit(1);
    }
    glutKeyboardFunc(NULL);
    glutTimerFunc(1000, time1, 1);
    break;
  default:
    printf("FAIL: keyboard called with bad mode: %d\n", kmode);
    exit(1);
  }
  kmode++;
}

void
time0(int value)
{
  if (value != 0) {
    printf("FAIL: time0 expected 0\n");
    exit(1);
  }
  glutKeyboardFunc(keyboard);
  printf("In the black window, please press: g, G, Ctrl-g, then Alt-g\n");
}

int
main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutCreateWindow("test");
  glutDisplayFunc(display);
  glutTimerFunc(1000, time0, 0);
  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}
