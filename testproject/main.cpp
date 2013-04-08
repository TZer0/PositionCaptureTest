#include<iostream>
#include "render.h"
Render *rend;

void callback() {
	rend->render();
}

void keyboard(unsigned char c, int x, int y) {
	if (c == 27) {
		exit(0);
	} else {
		std::cout << (int)c << " " <<x<< " " << y << std::endl;
	}
}

int main(int argc, char **argv) {
	rend = new Render();
	rend->init(&argc, argv);
	glutDisplayFunc(callback);
	glutIdleFunc(callback);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	
}