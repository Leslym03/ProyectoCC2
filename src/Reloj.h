#pragma once
#include "SFML/System/Clock.hpp"
namespace game {

	class Reloj {
	public:
		Reloj();
		virtual ~Reloj();

		float getSeconds();
		float getMiliseconds();
		void restart();

		// Guarda los seg obtenidos en el ultimo restart
		float elapsedSeconds;

	private:
		sf::Clock reloj;
	};

}