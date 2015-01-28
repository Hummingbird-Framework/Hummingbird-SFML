#ifndef HB_CAMERA_H
#define HB_CAMERA_H
#include <queue>
#include <SFML/Graphics.hpp>

namespace hb
{
	class Camera
	{
	public:
		Camera();
		~Camera();
		sf::RenderWindow* getWindow();
		const sf::RenderWindow* getWindow() const;
		void addDrawable(std::pair<double, const sf::Drawable*> drawable);
		void draw();

		static Camera* instance();

	private:
		class Comparison
		{
		public:
			Comparison(){}
			bool operator() (const std::pair<double, const sf::Drawable*>& lhs, const std::pair<double, const sf::Drawable*>& rhs) const
			{
				return (lhs.first > rhs.first);
			}
		};

		static Camera* s_instance;

		sf::RenderWindow* m_window;
		std::priority_queue<std::pair<double, const sf::Drawable*>, std::vector<std::pair<double, const sf::Drawable*>>, Comparison> m_drawables;
	};
}
#endif