#include "Reloj.h"

namespace game {

	game::Reloj::Reloj() {
		reloj.restart();
	}


	Reloj::~Reloj() {
	}

	float Reloj::getSeconds() {
		return reloj.getElapsedTime().asSeconds();
	}
	float Reloj::getMiliseconds() {
		return reloj.getElapsedTime().asMilliseconds();
	}
	void Reloj::restart() {
		elapsedSeconds = reloj.restart().asSeconds();
	}

}