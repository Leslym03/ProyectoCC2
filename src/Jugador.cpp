#include "SFML/Graphics.hpp"
#include "Jugador.h"
#include "Recursos.h"
#include "GameMotor.h"
#include <iostream>

using namespace sf;

namespace game {

	Jugador* Jugador::pin = 0;

	Jugador* Jugador::Instancia() {
		if (pin == 0) {
			pin = new Jugador;
		}
		return pin;
	}

	Jugador::Jugador() {
		iniciar();
		setSprite(RUTA_CLOWN);
		setSize(60, 60);
		setCentro(this->getSize().x / 2, this->getSize().y / 2);
		spawn.x = 0.f;
		spawn.y = 0.f;
		setPosicion(spawn.x, spawn.y);

		velocidad.x = 0;
		velocidad.y = 0;
		aceleracion.x = 0;
		aceleracion.y = 9.81;

	}

	Jugador::Jugador(const Jugador& orig) {

	}

	Jugador::~Jugador() {

	}
	
	void Jugador::iniciar() {
		reaparecer();
	}


	void Jugador::reaparecer() {
		setFrame(0, 1, 1, 1);
		setVelocidad(0.f, 0.f);
		setPosicion(spawn.x, spawn.y);
		enSuelo = false;
		vivo = true;
	}

	IntRect Jugador::getBounds() {
		IntRect r(getPosicion().x - getSize().x / 2 + 5, getPosicion().y - getSize().y / 2, 30, getSize().y);
		return r;
	}

	void Jugador::actualizar() {
		GameMotor &motor = *GameMotor::Instancia();
	}

	void Jugador::caida(float delta_t) {
		//delta_t /= 6;
		velocidad.y += aceleracion.y * delta_t;
		setPosicion(getPosicion().x, getPosicion().y + velocidad.y * delta_t);
		vivo = false;
	}

	void Jugador::setSpawn(float x, float y) {
		this->spawn.x = x;
		this->spawn.y = y;
	}


}
