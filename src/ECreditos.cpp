#include "ECreditos.h"
#include "GameAdmin.h"
#include "EMenu.h"
#include "Jugador.h"
#include "Recursos.h"
#include "EPrincipal.h"


using namespace sf;
using namespace std;

ECreditos ECreditos::m_ECreditos;

void ECreditos::Iniciar() {
	game::Jugador &jugador = *game::Jugador::Instancia();
	jugador.iniciar();
	jugador.setPosicion(215, 180);


	avanzar = false;
	salir = false;

	fondo = new Entidad(RUTA_CRED);
	fondo->setPosicion(0, 0);

	ifstream archivo;
	string texto;
	archivo.open("puntaje.txt", ios::in);
	while (!archivo.eof()) {
		getline(archivo, texto);
	}
	archivo.close();

	fuente1 = new Font();
	fuente1->loadFromFile(RUTA_FONT_W);
	palabras = new Text();
	palabras->setFont(*fuente1);
	palabras->setString("Puntaje total");
	palabras->setCharacterSize(20);
	palabras->setPosition(100, 230);

	obtenido = new Text();
	obtenido->setFont(*fuente1);
	obtenido->setString(texto);
	obtenido->setCharacterSize(20);
	
	obtenido->setPosition(300, 230);


}

void ECreditos::Limpiar() {
	delete fondo;
}

void ECreditos::Pausa() {

}

void ECreditos::Reanudar() {

}

void ECreditos::ProcesarEventos(GameAdmin* gameadm) {
	game::Jugador &jugador = *game::Jugador::Instancia();
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

	int grupo = 0;
	float tiempo = 500.f;
	float tiempo2 = 1000.f;

	jugador.setFrame(1, 0, 1, 1);
	if (reloj.getMiliseconds() > tiempo) {
		jugador.setFrame(1, grupo + 1, 1, 1);
	}

	if (reloj.getMiliseconds() > tiempo2) {
		jugador.setFrame(1, grupo - 1, 1, 1);
		reloj.restart();
	}
}

void ECreditos::Actualizar(GameAdmin* gameadm) {
	game::Jugador &jugador = *game::Jugador::Instancia();
	if (avanzar) {
		gameadm->CambiarEstado(EMenu::Instancia());
	}

}

void ECreditos::Dibujar(GameAdmin* gameadm) {
	GameMotor &motor = *GameMotor::Instancia();
	game::Jugador &jugador = *game::Jugador::Instancia();
	fondo->dibujar();
	motor.ventana.draw(*palabras);
	motor.ventana.draw(*obtenido);
	jugador.dibujar();
}