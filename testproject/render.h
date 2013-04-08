#ifndef RENDER_H
#define RENDER_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<GL/glew.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
class Render
{
	
public:
	Render();
	virtual ~Render();
	void render();
	void init(int *argc, char **argv);
private:
	float mMov;
	float mTestTria[9];
	GLuint mVBO;
	void loadShader(std::string filename, bool fragment);
};

#endif // RENDER_H