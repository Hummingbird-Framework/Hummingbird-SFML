#include "Camera.h"
using namespace hb;


Camera::Camera()
{
	m_window = new sf::RenderWindow();
}


Camera::~Camera()
{
	delete m_window;
}


sf::RenderWindow* Camera::getWindow()
{
	return m_window;
}


const sf::RenderWindow* Camera::getWindow() const
{
	return m_window;
}


void Camera::addDrawable(std::pair<double, const sf::Drawable*> drawable)
{
	m_drawables.push(drawable);
}


void Camera::draw()
{
	m_window->clear();
	while (not m_drawables.empty())
	{
		const sf::Drawable* d = m_drawables.top().second;
		m_drawables.pop();
		m_window->draw(*d);
	}
	m_window->display();
}
