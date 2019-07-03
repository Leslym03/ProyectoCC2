#pragma once

#include "Reloj.h"
#include "SFML/Graphics.hpp"
using namespace sf;

class GameMotor {
public:
	static GameMotor* Instancia();
	RenderWindow ventana;
	int vAncho;
	int vAlto;
	game::Reloj reloj;

private:
	GameMotor();
	GameMotor(const GameMotor& orig);
	GameMotor &operator= (const GameMotor &);

	static GameMotor* pin;
};