#include "app.h"

void core::App::init() {

}

void core::App::update()
{
}

void core::App::render()
{
}

void core::App::destroy()
{
}

void core::App::setDimensions(int width, int height)
{
	mWindowWidth = width;
	mWindowHeight = height;
}

int core::App::getWidth() const
{
	return mWindowWidth;
}

int core::App::getHeight() const
{
	return mWindowHeight;
}

float core::App::getAspectRatio() const
{
	return static_cast<float>(mWindowWidth) / static_cast<float>(mWindowHeight);
}
