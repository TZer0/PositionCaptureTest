#include "render.h"

Render::Render()
{
	mMov = 0;
	for (int i = 0; i < 9; i++) {
		mTestTria[i] = 0;
	}
	mTestTria[4] = mTestTria[5] = mTestTria[8] = 1;
}
Render::~Render()
{
	
}

void Render::init(int *argc, char **argv)
{
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Test project");
	glClearColor( 0.4, 0.4, 0.4, 0.0 );
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DOUBLE);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_NONE);
	glPushClientAttrib( GL_CLIENT_VERTEX_ARRAY_BIT );
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		std::cout << "error: " << std::endl;
		return;
	}
	glGenBuffers(1, &mVBO);
	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(mTestTria), mTestTria, GL_STATIC_DRAW);
	mShaderProg = glCreateProgram();
	
	loadShader("../shader.frag", GL_FRAGMENT_SHADER);
	loadShader("../shader.vert", GL_VERTEX_SHADER);
}

void Render::loadShader(std::string filename, GLenum sType) {
	GLuint shaderId = glCreateShader(sType);
	std::stringstream stream;
	std::ifstream f(filename.c_str());
	if (f.is_open()) {
		stream << f.rdbuf();
		const char *chars = stream.str().c_str();
		glShaderSource(shaderId, 1, &chars, NULL);
		glCompileShader(shaderId);
		GLint success;
		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
		std::cout << stream.str() << std::endl;
		f.close();
		if (!success) {
			char log[1024];
			glGetShaderInfoLog(shaderId, 1024, NULL, log);
			std::cout << log << std::endl;
		}
	}
	glAttachShader(mShaderProg, shaderId);
	glLinkProgram(mShaderProg);
	glValidateProgram(mShaderProg);
	glUseProgram(mShaderProg);
	
	
	
}

void Render::render()
{
	mMov+=0.01;
	if (mMov >= 1) {
		mMov = 0;
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2, 2, 2, mMov,0,0, 0,0,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 640./480., 0.1, 100);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	
	glColor3f(1,mMov,mMov);
	
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	glDrawArrays(GL_TRIANGLES, 0, 3);
	
	glDisableVertexAttribArray(0);
	
	
	glutSwapBuffers();
}
