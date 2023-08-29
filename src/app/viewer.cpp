#include <cassert>


#include "core/settings.h"


#include "app/viewer.h"

Viewer::Viewer(const char* vertexShader,const char* fragShader):
	App{},
	mViewerOpen{true},
	mMouseX{},
	mMouseY{},
	mVertexShader{vertexShader},
	mFragShader{ fragShader },
	mVAO{0}
{

}

void Viewer::init()
{

	mStartTime = std::chrono::high_resolution_clock::now();

	//Create graphics assets	
	mShader.init(SHADER_DIR,mVertexShader,mFragShader);

	glGenVertexArrays(1, &mVAO);
	glBindVertexArray(mVAO);

	glClearColor(0.32f, 0.32f, 0.32f, 1.0f);

	mShader.use();
	mShader.setUniformFloat("aspect", getAspectRatio());

}

void Viewer::update()
{
	auto timeElapsed = static_cast<std::chrono::duration<float>>(std::chrono::high_resolution_clock::now() - mStartTime);
	setTime(timeElapsed.count());
}

void Viewer::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Viewer::destroy()
{
	glDeleteVertexArrays(1, &mVAO);
}

void Viewer::setTime(float time)
{
	mShader.use();
	mShader.setUniformFloat("time", time);
}

void Viewer::setMousePos(float x,float y)
{
	mShader.use();
	float xnorm = x / static_cast<float>(mWindowWidth);
	float ynorm = 1.0f - (y / static_cast<float>(mWindowHeight));
	mShader.setUniformFloat2("mouse", xnorm, ynorm);
}

void Viewer::refreshShader()
{
	mShader.rebuild(SHADER_DIR, mVertexShader, mFragShader);
}
