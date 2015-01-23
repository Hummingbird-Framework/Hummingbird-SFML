#include "AnimatedSpriteComponent.h"
using namespace hb;


AnimatedSpriteComponent::AnimatedSpriteComponent(RenderWindowManager* render_manager):
SpriteComponent(render_manager),
m_time_left(Time::microseconds(0)),
m_frame_time(Time::microseconds(0)),
m_frame_size(Vector2d(1, 1)),
m_begin_frame(0),
m_current_frame(0),
m_end_frame(0),
m_playing(true),
m_looping(true)
{}


AnimatedSpriteComponent::~AnimatedSpriteComponent()
{}


void AnimatedSpriteComponent::setTexture(const std::string& path, const sf::IntRect& area)
{
	m_texture_id = TextureManager::instance()->loadFromFile(path, area);
	m_sprite.setTexture(TextureManager::instance()->get(m_texture_id));
}


void AnimatedSpriteComponent::setFrameInterval(int begin_frame, int end_frame)
{
	m_begin_frame = begin_frame;
	m_end_frame = end_frame;
}


void AnimatedSpriteComponent::setFrameSize(const Vector2d& frame_size)
{
	m_frame_size = frame_size;
}


bool AnimatedSpriteComponent::isLooping() const
{
	return m_looping;
}


void AnimatedSpriteComponent::loop(bool loop)
{
	m_looping = loop;
}


bool AnimatedSpriteComponent::isPlaying() const
{
	return m_playing;
}


void AnimatedSpriteComponent::play()
{
	m_playing = true;
}


void AnimatedSpriteComponent::stop()
{
	m_playing = false;
}


Vector2d AnimatedSpriteComponent::getCoords()
{
	int nx = m_sprite.getTexture()->getSize().x / m_frame_size.x;
	return Vector2d(m_current_frame % nx, m_current_frame / nx);
}
