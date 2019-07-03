#include "EMenu.h"
#include "GameAdmin.h"
#include "EPrincipal.h"
#include "Recursos.h"

using namespace sf;
using namespace std;

EMenu EMenu::m_EMenu;

void EMenu::Iniciar() {
	avanzar = false;
	salir = false;
	
	inicio = new Entidad(RUTA_INTRO);
	inicio->setPosicion(0, 0);


	fuente1 = new Font();
	fuente1->loadFromFile(RUTA_FONT_W);
	palabras = new Text();
	palabras->setFont(*fuente1);
	palabras->setString("Presiona ENTER para comenzar");
	palabras->setCharacterSize(20);
	palabras->setPosition(50, 190);
}

void EMenu::Limpiar() {

}

void EMenu::Pausa() {

}

void EMenu::Reanudar() {

}

void EMenu::ProcesarEventos(GameAdmin* gameadm) {
	GameMotor &motor = *GameMotor::Instancia();

	Event evento;
	if (motor.ventana.pollEvent(evento)) {
		switch (evento.type) {
		case Event::Closed:
			gameadm->Salir();
			break;
		case Event::KeyPressed:
			switch (evento.key.code) {
			case Keyboard::Return:
				if (!avanzar) {
					avanzar = true;
				}
			case Keyboard::Escape:
				salir = true;
				break;
			}
		}
	}
}

void EMenu::Actualizar(GameAdmin* gameadm) {
	if (avanzar) {
		gameadm->CambiarEstado(EPrincipal::Instancia());
	}
}

void EMenu::Dibujar(GameAdmin* gameadm) {
	GameMotor &motor = *GameMotor::Instancia();
	inicio->dibujar();
	motor.ventana.draw(*palabras);
}