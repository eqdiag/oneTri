#ifndef VIEWER_H
#define VIEWER_H

#include <memory>
#include <chrono>


#include "core/app.h"
#include "core/shader.h"

class Viewer : public core::App {
public:

	Viewer();
	void init() override;
	void update() override;
	void render() override;
	void destroy() override;

	void setTime(float time);
	void setMousePos(float x,float y);

	//Input state variables
	bool mViewerOpen;
	float mMouseX;
	float mMouseY;

	//Main shader
	core::Shader mShader{};
	std::chrono::steady_clock::time_point mStartTime;
	GLuint mVAO{};

private:

};


#endif