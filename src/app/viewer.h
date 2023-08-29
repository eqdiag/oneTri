#ifndef VIEWER_H
#define VIEWER_H

#include <memory>
#include <chrono>


#include "core/app.h"
#include "core/shader.h"

class Viewer : public core::App {
public:

	Viewer(const char *vertexShader,const char* fragShader);
	void init() override;
	void update() override;
	void render() override;
	void destroy() override;

	void setTime(float time);
	void setMousePos(float x,float y);
	void refreshShader();


	//Input state variables
	bool mViewerOpen;
	float mMouseX;
	float mMouseY;

	//Main shader
	const char* mVertexShader;
	const char* mFragShader;
	core::Shader mShader{};
	std::chrono::steady_clock::time_point mStartTime;
	GLuint mVAO{};

private:

};


#endif