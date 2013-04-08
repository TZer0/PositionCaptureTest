cmake_minimum_required(VERSION 2.8)
project(testproject)
add_executable(testproject render.cpp main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
	FIND_PATH( GLEW_INCLUDE_PATH GL/glew.h
/usr/include
/usr/local/include
/sw/include
/opt/local/include
DOC "The directory where GL/glew.h resides")
FIND_LIBRARY( GLEW_LIBRARY
NAMES GLEW glew
PATHS
/usr/lib64
/usr/lib
/usr/local/lib64
/usr/local/lib
/sw/lib
/opt/local/lib
DOC "The GLEW library")

IF (GLEW_INCLUDE_PATH)
SET( GLEW_FOUND 1 CACHE STRING "Set to 1 if GLEW is found, 0 otherwise")
ELSE (GLEW_INCLUDE_PATH)
SET( GLEW_FOUND 0 CACHE STRING "Set to 1 if GLEW is found, 0 otherwise")
ENDIF (GLEW_INCLUDE_PATH)

MARK_AS_ADVANCED( GLEW_FOUND )


include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} )


target_link_libraries(testproject ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY} )
