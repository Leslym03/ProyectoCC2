#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Color.hpp"
#include "EPrincipal.h"
#include "GameAdmin.h"
#include "Entidad.h"
#include "Jugador.h"
#include "Plataforma.h"
#include "Recursos.h"
#include "ECreditos.h"
#include <time.h>
#include <iostream>
#include <random>
#include <ctime>
#include <SFML\Audio.hpp>


using namespace sf;
using namespace std;

EPrincipal EPrincipal::m_EPrincipal;

void EPrincipal::Iniciar() {
	avanzar = false;
	salir = false;
	
	GameMotor &motor = *GameMotor::Instancia();
	game::Jugador &jugador = *game::Jugador::Instancia();
	fondo = new Entidad(RUTA_FONDO);
	jugador.iniciar();
	
	fuente1 = new Font();
	fuente1->loadFromFile(RUTA_FONT_W);
	scoreText = new Text();
	scoreText->setFont(*fuente1);
	scoreText->setPosition(360, 0);
	scoreText->setString(std::to_string(score));

	reloj1 = new Clock();
	tiempo1 = new Time();
	tiempo2 = 0.f;

	uniform_int_distribution<unsigned> x(30, 450 - plat->getSize().x);
	uniform_int_distribution<unsigned> y(100, 533);
	default_random_engine a(time(0));
	for (size_t i = 0; i < 6; ++i){
		plat[i].x = x(a);
		plat[i].y = y(a);
	}

}

void EPrincipal::Limpiar() {
	fondo->~Entidad();
	delete fuente1;
	delete scoreText;
	delete reloj1;
	delete tiempo1;
}

void EPrincipal::Pausa() {

}

void EPrincipal::Reanudar() {

}

void EPrincipal::ProcesarEventos(GameAdmin* gameadm) {
	GameMotor &motor = *GameMotor::Instancia();
	game::Jugador &jugador = *game::Jugador::Instancia();

	*tiempo1 = reloj1->getElapsedTime();
	tiempo2 = tiempo1->asSeconds()/6;

	Event evento;
	if (motor.ventana.pollEvent(evento)) {
		switch (evento.type) {
		case Event::Closed:
			gameadm->Salir();
			break;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		playerX += 4;
		jugador.setFrame(0, 1, 1, 1);
	}
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		playerX -= 4;
		jugador.setFrame(0, 0, 1, 1);
	}
	
	if (playerX > 450)
		playerX = 0;
	if (playerX < -30)
		playerX = motor.ventana.getSize().x - jugador.getSize().x;


	// dy = -1.60001 es la velocidad terminal que el jugador se para en la plataforma y no sube más
	// la puntuación no puede aumentar en esta situación
	if (playerY == height && dy < (-1.62)){
		score += 1;
		scoreText->setString(std::to_string(score));
	}

	// mecanismo de salto del jugador
	dy += 0.2;
	playerY += dy;

	uniform_int_distribution<unsigned> x(30, 450 - plat->getSize().x);
	uniform_int_distribution<unsigned> y(100, 533);
	default_random_engine e(time(0));

	if (playerY < height)
		for (int i = 0; i < 8; ++i){
			playerY = height;
			plat[i].y -= dy; // traslación vertical
			if (plat[i].y > 533){ // establecer nueva plataforma en la parte superior
				plat[i].y = 0;
				plat[i].x = x(e);
			}
		}

	// detectar salto en la plataforma
	for (int i = 0; i < 8; ++i){
		if ((playerX + PLAYER_RIGHT_BOUNDING_BOX > plat[i].x) && (playerX + PLAYER_LEFT_BOUNDING_BOX < plat[i].x + plat[i].getSize().x)   
			// El rango horizontal del jugador puede tocar la plataforma.
			&& (playerY + PLAYER_BOTTOM_BOUNDING_BOX > plat[i].y) && (playerY + PLAYER_BOTTOM_BOUNDING_BOX < plat[i].y + plat[i].getSize().y)  
			// El rango vertical del jugador puede tocar la plataforma.
			&& (dy > 0)){
			dy = -10;
		}
	}
	jugador.setPosicion(playerX, playerY);


	if (jugador.getPosicion().y > 560) {
		jugador.setPosicion(210, 0);
		jugador.setFrame(1, 2, 1, 1);
		jugador.caida(tiempo2);
	}
}

void EPrincipal::Actualizar(GameAdmin* gameadm) {
	GameMotor &motor = *GameMotor::Instancia();
	game::Jugador &jugador = *game::Jugador::Instancia();

	if (jugador.getPosicion().y > 560) {
		jugador.setPosicion(210, 0);
		jugador.setFrame(1, 2, 1, 1);
		jugador.caida(tiempo2);
		if (jugador.getPosicion().y > 570) {
			avanzar = true;
		}

		ofstream archivo;
		archivo.open("puntaje.txt", ios::out);
		archivo << std::to_string(score);
		archivo.close();
	}
	

	if (avanzar) {
		gameadm->CambiarEstado(ECreditos::Instancia());
	}
}

void EPrincipal::Dibujar(GameAdmin* gameadm) {
	GameMotor &motor = *GameMotor::Instancia();
	game::Jugador &jugador = *game::Jugador::Instancia();

	fondo->dibujar();	
	for (int i = 0; i < 8; i++) {
		plat->setPosicion(plat[i].x, plat[i].y);
		plat->dibujar();
	}
	jugador.dibujar();
	motor.ventana.draw(*scoreText);
}