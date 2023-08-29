#ifndef APP_H
#define APP_H

namespace core {

	class App {
	public:
		virtual void init();
		virtual void update();
		virtual void render();
		virtual void destroy();

		void setDimensions(int width, int height);

		int getWidth() const;
		int getHeight() const;
		float getAspectRatio() const;


	protected:
		int mWindowWidth, mWindowHeight;

	};

}

#endif