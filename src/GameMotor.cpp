#include "GameMotor.h"
using namespace sf;

GameMotor* GameMotor::pin = 0;

GameMotor* GameMotor::Instancia() {
	if (pin == 0) {
		pin = new GameMotor;
	}
	return pin;
}

GameMotor::GameMotor() {
	vAlto = 450;
	vAncho = 533;
	this->ventana.create(VideoMode(vAlto, vAncho, 32), "Jump");
	this->ventana.setFramerateLimit(60);
}


GameMotor::GameMotor(const GameMotor &orig) {

}