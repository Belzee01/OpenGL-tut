#pragma once

#include <string>
#include <SDL\SDL.h>

class Display
{
public:
	Display(int width, int height, const std::string& title);
	virtual ~Display();

	void Clear(float, float, float, float);
	void Update();
	bool IsClosed();

	inline int& GetWidth(){ return m_width;  }
	inline int& GetHeight(){ return m_height;  }

protected:

private:

	int				m_width;
	int				m_height;

	SDL_Window*		m_window;
	SDL_GLContext	m_glContext;
	bool			m_isClosed;
};

