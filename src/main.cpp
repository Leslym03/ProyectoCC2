#include "SFML/Graphics.hpp"
#include "GameMotor.h"
#include "GameAdmin.h"
#include "EPrincipal.h"
#include "EMenu.h"
#include "Recursos.h"
#include <iostream>
#include <time.h>
using namespace sf;
using namespace std;


int main() {
	GameAdmin* gameadm = new GameAdmin();

	GameMotor &motor = *GameMotor::Instancia();

	gameadm->Iniciar();
	gameadm->CambiarEstado(EMenu::Instancia());

	while (gameadm->Funcionando()) {
		gameadm->ProcesarEventos();
		gameadm->Actualizar();
		gameadm->Dibujar();
	}

	gameadm->Limpiar();

	return 0;
}

