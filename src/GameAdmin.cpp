#include "GameAdmin.h"
#include "GameEstado.h"
#include "GameMotor.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <stdio.h>

void GameAdmin::Iniciar() {
	GameMotor &motor = *GameMotor::Instancia();
	m_funcionando = true;
}

void GameAdmin::Limpiar() {
	GameMotor &motor = *GameMotor::Instancia();

	while (estados.empty()) {
		estados.back()->Limpiar();
		estados.pop_back();
	}
	motor.ventana.close();
}

void GameAdmin::CambiarEstado(GameEstado* estado) {
	if (!estados.empty()) {
		estados.back()->Limpiar();
		estados.pop_back();
	}

	estados.push_back(estado);
	estados.back()->Iniciar();
}

void GameAdmin::PushEstado(GameEstado* estado) {
	if (!estados.empty()) {
		estados.back()->Pausa();
	}

	estados.push_back(estado);
	estados.back()->Iniciar();
}

void GameAdmin::PopEstado() {
	if (!estados.empty()) {
		estados.back()->Limpiar();
		estados.pop_back();
	}

	if (!estados.empty()) {
		estados.back()->Reanudar();
	}
}

void GameAdmin::ProcesarEventos() {
	estados.back()->ProcesarEventos(this);
}

void GameAdmin::Actualizar() {
	estados.back()->Actualizar(this);
}

void GameAdmin::Dibujar() {
	GameMotor &motor = *GameMotor::Instancia();
	motor.ventana.clear();
	motor.reloj.restart();
	estados.back()->Dibujar(this);
	motor.ventana.display();
}