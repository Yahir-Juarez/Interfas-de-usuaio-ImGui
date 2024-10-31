#include "AppUI.h"

const sf::Vector2f sizeButton(600, 70);
const sf::Vector2f sizeButtonText(475, 45);
const sf::Vector2f sizeButtonSettings(350, 45);
const sf::Vector2f sizeButtonGlobalSettings(200, 40);

using std::vector;
using std::string;

App::App()
{
	Vector2u medidaVentana(window_x, window_y);
	ventana.create(VideoMode(medidaVentana), "Outlast Trials");

	ImGui::SFML::Init(ventana);

	createUI();

	ventana.setFramerateLimit(30);
	mainloop();
}

App::~App()
{

}

void App::mainloop()
{
	while (ventana.isOpen())
	{
		entrada();
		update();
		render();
	}
}

void App::entrada()
{
	// Process events
	std::optional<sf::Event> wndEvent;
	while (wndEvent = ventana.pollEvent()) {
		ImGui::SFML::ProcessEvent(ventana, *wndEvent);
	}

	switch (m_typeUI)
	{
	case UI::NONE:
		break;
	case UI::MENU_INICIO:
		m_actualUI = 1;
		m_typeUI = UI::NONE;
		break;
	case UI::ENTRAR_A_LA_INSTALACION_MURKOFF:
		m_actualUI = 7;
		m_typeUI = UI::NONE;
		break;
	case UI::VOLVER_A_JUGAR_LA_INTRODUCCION:
		m_actualUI = 8;
		m_typeUI = UI::NONE;
		break;
	case UI::SETTINGS:
		m_actualUI = 1;
		m_typeUI = UI::NONE;
		break;
	case UI::GENERAL:
		m_actualUI = 1;
		m_typeUI = UI::NONE;
		break;
	case UI::LENGUAJE:
		m_actualUI = 2;
		m_typeUI = UI::NONE;
		break;
	case UI::CONTROLS:
		m_actualUI = 3;
		m_typeUI = UI::NONE;
		break;
	case UI::GRAPHICS:
		m_actualUI = 4;
		m_typeUI = UI::NONE;
		break;
	case UI::AUDIO:
		m_actualUI = 5;
		m_typeUI = UI::NONE;
		break;
	case UI::CONEXION:
		m_actualUI = 6;
		m_typeUI = UI::NONE;
		break;
	case UI::CREDITS:
		m_actualUI = 9;
		m_typeUI = UI::NONE;
		break;
	case UI::CLASICO:
		m_actualUI = 10;
		m_typeUI = UI::NONE;
		break;
	case UI::MODERNO:
		m_actualUI = 11;
		m_typeUI = UI::NONE;
		break;
	case UI::OPCIONES_AVANZADAS:
		m_actualUI = 12;
		m_typeUI = UI::NONE;
		break;
	case UI::TACTICO:
		m_actualUI = 13;
		m_typeUI = UI::NONE;
		break;
	case UI::EXIT_TO_MENU:
		m_actualUI = 0;
		m_typeUI = UI::NONE;
		break;
	case UI::EXIT_TO_CONTROL:
		m_actualUI = 3;
		m_typeUI = UI::NONE;
		break;
	case UI::EXIT_TO_GRAPHICS:
		m_actualUI = 4;
		m_typeUI = UI::NONE;
		break;
	case UI::BRIGHT:
		m_actualUI = 14;
		m_typeUI = UI::NONE;
		break;
	case UI::EXIT_GAME:
		ventana.close();
		break;
	default:
		break;
	}

}


void App::update()
{
	ImGui::SFML::Update(ventana, deltaClock.restart());
}

void App::render()
{
	Color rgbGris(184, 184, 184);

	ventana.clear(Color(rgbGris));

	m_ui[m_actualUI]->drawUI();

	m_typeUI = m_ui[m_actualUI]->m_panel.draw(m_ui[m_actualUI]->m_buttons, m_ui[m_actualUI]->m_SliderBars);

	if (m_ui[m_actualUI]->m_Settings.size() > 0)
	{
		if (m_typeUI == UI::NONE)
		{
			m_typeUI = m_ui[m_actualUI]->m_panelSettings.drawSettings(m_ui[m_actualUI]->m_Settings);
		}
		else
		{
			m_ui[m_actualUI]->m_panelSettings.drawSettings(m_ui[m_actualUI]->m_Settings);
		}
	}
	if (m_ui[m_actualUI]->m_SettingsClose.size() > 0)
	{
		if (m_typeUI == UI::NONE)
		{
			m_typeUI = m_ui[m_actualUI]->m_panelSettingsClose.drawSettingsClose(m_ui[m_actualUI]->m_SettingsClose);
		}
		else
		{
			m_ui[m_actualUI]->m_panelSettingsClose.drawSettingsClose(m_ui[m_actualUI]->m_SettingsClose);
		}
	}

	ImGui::SFML::Render(ventana);

	ventana.display();
}

void App::createUI()
{
	std::vector<Button> buttons = {
			Button(vector<string>{"ENTRAR A LA INSTALACION MURKOFF"}, sf::Vector2f(10, 30), sizeButton, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 0, UI::ENTRAR_A_LA_INSTALACION_MURKOFF),
			Button(vector<string>{"VOLVER A JUGAR LA INTRODUCCION"}, sf::Vector2f(10, 105), sizeButton, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 1, UI::VOLVER_A_JUGAR_LA_INTRODUCCION),
			Button(vector<string>{"AJUSTES"}, sf::Vector2f(10, 180), sizeButton, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 2, UI::SETTINGS),
			Button(vector<string>{"CREDITOS"}, sf::Vector2f(10, 255), sizeButton, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 3, UI::CREDITS),
			Button(vector<string>{"SALIR DEL JUEGO"}, sf::Vector2f(10, 330), sizeButton, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 4, UI::EXIT_GAME)
	};



	Panel panel(sf::Vector2f(1200, 700), 0.0f, "Menu", sf::Vector2f(10, 650));


	UIClass* ui = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/MenuOutlast.jpg");
	m_ui.push_back(ui);
	m_ui[0]->m_buttons = buttons;
	m_ui[0]->m_panel = panel;

  std::vector<Button> buttonsSettings = {
    Button(vector<string>{"GENERAL"}, sf::Vector2f(50, 40), sizeButtonGlobalSettings, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 5, UI::GENERAL),
    Button(vector<string>{"IDIOMA"}, sf::Vector2f(270, 40), sizeButtonGlobalSettings, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 6, UI::LENGUAJE),
    Button(vector<string>{"CONTROLES"}, sf::Vector2f(490, 40), sizeButtonGlobalSettings, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 7, UI::CONTROLS),
    Button(vector<string>{"GRAFICOS"}, sf::Vector2f(710, 40), sizeButtonGlobalSettings, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 8, UI::GRAPHICS),
    Button(vector<string>{"AUDIO"}, sf::Vector2f(930, 40), sizeButtonGlobalSettings, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 9, UI::AUDIO),
    Button(vector<string>{"CONEXION"}, sf::Vector2f(1150, 40), sizeButtonGlobalSettings, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 10, UI::CONEXION)
  };


	float posX = 600;
	ImVec4 cButtonBlack(0.0f, 0.0f, 0.0f, 0.5f);
	std::vector<Button> buttons2 = {
		Button(vector<string>{"ESTANDAR", "ACCECIBLE", "INMERSIVO", "COOPERATIVO CLASICO"},
					 Vector2f(posX, 50),
					 sizeButtonSettings,
					 cButtonBlack, 11),
		//Text
		Button(vector<string>{"PREAJUSTE DE INTERFAZ"},
					 Vector2f(50, 50),
					 sizeButtonText,
					 cButtonBlack, 11),
		Button(vector<string>{"OCULTAR", "PERMANENTE", "NO"},
					 sf::Vector2f(posX, 175),
					 sizeButtonSettings,
					 cButtonBlack, 12),
		//Text
    Button(vector<string>{"SALUD"},
				Vector2f(50, 175),
				sizeButtonText,
				cButtonBlack, 11),
		Button(vector<string>{"NO", "OCULTAR", "PERMANENTE"}, sf::Vector2f(posX, 230), sizeButtonSettings,
					 cButtonBlack, 13),
					 //Text
		Button(vector<string>{"RESISTENCIA"},
					 Vector2f(50, 230),
					 sizeButtonText,
					 cButtonBlack, 11),
		Button(vector<string>{"OCULTAR", "PERMANENTE", "NO"}, sf::Vector2f(posX, 285), sizeButtonSettings,
					 cButtonBlack, 14),
					 //Text
Button(vector<string>{"CORDURA"},
			 Vector2f(50, 285),
			 sizeButtonText,
			 cButtonBlack, 11),
		Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 340), sizeButtonSettings,
					 cButtonBlack, 15),
					 //Text
Button(vector<string>{"INDICADOR DE RUIDO"},
			 Vector2f(50, 340),
			 sizeButtonText,
			 cButtonBlack, 11),
		Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 395), sizeButtonSettings,
					 cButtonBlack, 16),
					 //Text
Button(vector<string>{"Indicador de oscuridad"},
			 Vector2f(50, 395),
			 sizeButtonText,
			 cButtonBlack, 11),

		Button(vector<string>{"OCULTAR", "PERMANENTE"},
					 sf::Vector2f(posX, 450),
					 sizeButtonSettings,
					 cButtonBlack, 17),
					 //Text
Button(vector<string>{"Inventario"},
			 Vector2f(50, 450),
			 sizeButtonText,
			 cButtonBlack, 11),

		Button(vector<string>{"PERMANENTE", "OCULTAR"},
					 sf::Vector2f(posX, 505),
					 sizeButtonSettings,
					 cButtonBlack, 18),
					 //Text
Button(vector<string>{"Objetivo principal"},
			 Vector2f(50, 505),
			 sizeButtonText,
			 cButtonBlack, 11),

		Button(vector<string>{"OCULTAR", "PERMANENTE", "IGUAL QUE EL OBJETIVO"}, sf::Vector2f(posX, 560), sizeButtonSettings,
					 cButtonBlack, 19),
					 //Text
Button(vector<string>{"Objetivo secundario"},
			 Vector2f(50, 560),
			 sizeButtonText,
			 cButtonBlack, 11),

		Button(vector<string>{"SI", "NO", "AL APUNTAR"}, sf::Vector2f(posX, 615), sizeButtonSettings,
					 cButtonBlack, 20),
					 //Text
Button(vector<string>{"Punto de mira"},
			 Vector2f(50, 615),
			 sizeButtonText,
			 cButtonBlack, 11),

		Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 670), sizeButtonSettings,
					 cButtonBlack, 21),
					 //Text
Button(vector<string>{"Grupo"},
			 Vector2f(50, 670),
			 sizeButtonText,
			 cButtonBlack, 11),

		Button(vector<string>{"COMPLETA", "NO", "SIMPLE"}, sf::Vector2f(posX, 725), sizeButtonSettings,
					 cButtonBlack, 22),
					 //Text
Button(vector<string>{"Nombre de participantes"},
			 Vector2f(50, 725),
			 sizeButtonText,
			 cButtonBlack, 11),

		Button(vector<string>{"FLECHA", "SI", "NO"}, sf::Vector2f(posX, 780), sizeButtonSettings,
					 cButtonBlack, 23),
					 //Text
					 Button(vector<string>{"Nombre de participantes (cuando no estan a la vista)"},
					 Vector2f(50, 780),
					 sizeButtonText,
					 cButtonBlack, 11),

		Button(vector<string>{"FUERA DEL JUEGO", "NO", "SIEMPRE"}, sf::Vector2f(posX, 830), sizeButtonSettings,
					 cButtonBlack, 24),
					 //Text
			Button(vector<string>{"Capa del chat de voz"},
			Vector2f(50, 830),
			sizeButtonText,
			cButtonBlack, 11),

		Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 895), sizeButtonSettings,
					 cButtonBlack, 25),
					 //Text
					 Button(vector<string>{"Ocultar objeto tras demora"},
					 Vector2f(50, 895),
					 sizeButtonText,
					 cButtonBlack, 11),

		Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 950), sizeButtonSettings,
					 cButtonBlack, 26),
					 //Text
			Button(vector<string>{"Movimiento de cabeza"},
			Vector2f(50, 950),
			sizeButtonText,
			cButtonBlack, 11),

		Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 1075), sizeButtonSettings,
					 cButtonBlack, 27),
					 //Text
					 Button(vector<string>{"Aviso de amistad en linea"},
					 Vector2f(50, 1075),
					 sizeButtonText,
					 cButtonBlack, 11),

		Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 1130), sizeButtonSettings,
					 cButtonBlack, 28),
	//Text
	Button(vector<string>{"Solicitud de amistad"},
		Vector2f(50, 1130),
		sizeButtonText,
		cButtonBlack, 11),

							Button(vector<string>{"SI", "SOLO AMISTADES", "NO"}, sf::Vector2f(posX, 1185), sizeButtonSettings,
					 cButtonBlack, 29),
					 //Text
					 Button(vector<string>{"Solicitud de invitacion a grupo"},
					 Vector2f(50, 1185),
					 sizeButtonText,
					 cButtonBlack, 11)
	};

	std::vector<Button> buttonsSettingsExit = {
		Button(vector<string>{"VOLVER A VALORES PREDETERMINADOS"},
					 Vector2f(0, 30),
					 sf::Vector2f(500, 45),
					 cButtonBlack, 11),

		Button(vector<string>{"SALIR"},
					 sf::Vector2f(515, 30),
					 sf::Vector2f(200, 45),
					 cButtonBlack, 12, UI::EXIT_TO_MENU)
	};

	Panel panel2(sf::Vector2f(1000, 850), 0.0f, "GENERAL", sf::Vector2f(100, 150)); // Tamaño del panel, transparencia y título
	Panel panelSettings(sf::Vector2f(1400, 90), 0.0f, "AJUSTES", sf::Vector2f(100, 25));
	Panel panelClose(sf::Vector2f(700, 80), 0.0f, "SALIR", sf::Vector2f(1200, 1000));

	UIClass* ui2 = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/3.jpg");
	m_ui.push_back(ui2);
	m_ui[1]->m_buttons = buttons2;
	m_ui[1]->m_panel = panel2;
	m_ui[1]->m_panelSettings = panelSettings;
	m_ui[1]->m_Settings = buttonsSettings;
	m_ui[1]->m_panelSettingsClose = panelClose;
	m_ui[1]->m_SettingsClose = buttonsSettingsExit;

	std::vector<Button> buttonsLenguaje = {
		Button(vector<string>{"ENGLISH", "FRANCAIS"},
					 Vector2f(posX, 50),
					 sizeButtonSettings,
					 cButtonBlack, 30),
					 //Text
Button(vector<string>{"Idioma del audio"},
			 Vector2f(50, 50),
			 sizeButtonText,
			 cButtonBlack, 11),

		Button(vector<string>{"ESPANOL LATINOMARICANO", "FRANCAIS", "ITALIANO", "JAPONES", "CHINO", "POLSKI", "PORTUGUES", "RUSSO", "TURCKE", "DEUTSCH", "ENGLISH", "ESPANOL"},
					 sf::Vector2f(posX, 105),
					 sizeButtonSettings,
					 cButtonBlack, 31),
					 Button(vector<string>{"Idioma de interfaces y subtitulos"},
			 Vector2f(50, 105),
			 sizeButtonText,
			 cButtonBlack, 11),

		Button(vector<string>{"NO", "OCULTAR", "PERMANENTE"}, sf::Vector2f(posX, 160), sizeButtonSettings,
					 cButtonBlack, 32),
					 Button(vector<string>{"Subtitulos"},
			 Vector2f(50, 160),
			 sizeButtonText,
			 cButtonBlack, 11),

		Button(vector<string>{"MEDIA", "GRANDE", "PEQUENA"}, sf::Vector2f(posX, 215), sizeButtonSettings,
					 cButtonBlack, 34),
										 Button(vector<string>{"Tamano del texto de subtitulos"},
			 Vector2f(50, 215),
			 sizeButtonText,
			 cButtonBlack, 11),

		Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 270), sizeButtonSettings,
					 cButtonBlack, 35),
					 Button(vector<string>{"Fondo de subtitulos"},
			 Vector2f(50, 270),
			 sizeButtonText,
			 cButtonBlack, 11),
	};

  UIClass* ui3 = new UIClass(ventana, 
         "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/4.jpg");
  m_ui.push_back(ui3);
  m_ui[2]->m_buttons = buttonsLenguaje;
  m_ui[2]->m_panel = panel2;
  m_ui[2]->m_panelSettings = panelSettings;
  m_ui[2]->m_Settings = buttonsSettings;
  m_ui[2]->m_panelSettingsClose = panelClose;
  m_ui[2]->m_SettingsClose = buttonsSettingsExit;

	///////////////////////////////////////Controles///////////////////////////////////////////

	std::vector<Button> buttonsControls = {
	Button(vector<string>{"PERSONALIZAR TECLAS"},
				 Vector2f(posX, 50),
				 sizeButtonSettings,
				 cButtonBlack, 36),
				 //Text
 Button(vector<string>{"Combinacion de teclas"},
		 Vector2f(50, 50),
		 sizeButtonText,
		 cButtonBlack, 11),

		 //Text
Button(vector<string>{"Sensibilidad de vista"},
		Vector2f(50, 110),
		sizeButtonText,
		cButtonBlack, 11),

	Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 160), sizeButtonSettings,
				 cButtonBlack, 37),
				 //Text
 Button(vector<string>{"Invertir el eje horizontal"},
		 Vector2f(50, 160),
		 sizeButtonText,
		 cButtonBlack, 11),

	Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 215), sizeButtonSettings,
				 cButtonBlack, 38),
				 //Text
 Button(vector<string>{"Invertir el eje vertical"},
		 Vector2f(50, 215),
		 sizeButtonText,
		 cButtonBlack, 11),

	Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 270), sizeButtonSettings,
				 cButtonBlack, 39),
				 //Text
 Button(vector<string>{"Tocar para correr (teclado)"},
		 Vector2f(50, 270),
		 sizeButtonText,
		 cButtonBlack, 11),

	Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 325), sizeButtonSettings,
				 cButtonBlack, 40),
				 //Text
 Button(vector<string>{"Tocar para interactuar (teclado)"},
		 Vector2f(50, 325),
		 sizeButtonText,
		 cButtonBlack, 11),

	Button(vector<string>{"PERSONALIZAR CONTROL"},
				 Vector2f(posX, 450),
				 sizeButtonSettings,
				 cButtonBlack, 41, UI::CLASICO),
				 //Text
 Button(vector<string>{"Diseno de control"},
		 Vector2f(50, 450),
		 sizeButtonText,
		 cButtonBlack, 11),

			Button(vector<string>{"Sensibilidad de la vista horizontal"},
		 Vector2f(50, 505),
		 sizeButtonText,
		 cButtonBlack, 11),
	
		 //Text
Button(vector<string>{"Sensibilidad de la vista vertical"},
		Vector2f(50, 560),
		sizeButtonText,
		cButtonBlack, 11),

		Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 615), sizeButtonSettings,
				 cButtonBlack, 42),
				 //Text
 Button(vector<string>{"Invertir el eje horizontal"},
		 Vector2f(50, 615),
		 sizeButtonText,
		 cButtonBlack, 11),

	Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 670), sizeButtonSettings,
				 cButtonBlack, 43),
				 //Text
 Button(vector<string>{"Invertir el eje vertical"},
		 Vector2f(50, 670),
		 sizeButtonText,
		 cButtonBlack, 11),

	Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 725), sizeButtonSettings,
				 cButtonBlack, 44),
				 //Text
Button(vector<string>{"Toca para correr (control)"},
		Vector2f(50, 725),
		sizeButtonText,
		cButtonBlack, 11),

	Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 780), sizeButtonSettings,
				 cButtonBlack, 45),
				 //Text
Button(vector<string>{"Toca para interactuar (control)"},
		Vector2f(50, 780),
		sizeButtonText,
		cButtonBlack, 11),

	Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 835), sizeButtonSettings,
				 cButtonBlack, 46),
				 //Text
				 Button(vector<string>{"Vibracion"},
				 Vector2f(50, 835),
				 sizeButtonText,
				 cButtonBlack, 11),
	};

	std::vector<Button> progressBar = {
			Button(vector<string>{""},
			   .5, 
				 sf::Vector2f(posX, 105),
				 sizeButtonSettings,
			   cButtonBlack,
				 0),
			Button(vector<string>{""},
				 .5,
				 sf::Vector2f(posX, 505),
				 sizeButtonSettings,
		     cButtonBlack,
				 1),
			Button(vector<string>{""},
				 .5,
				 sf::Vector2f(posX, 560),
				 sizeButtonSettings,
				 cButtonBlack,
				 2)
	};

	UIClass* ui4 = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/5.jpg");
	m_ui.push_back(ui4);
	m_ui[3]->m_buttons = buttonsControls;
	m_ui[3]->m_SliderBars = progressBar;
	m_ui[3]->m_panel = panel2;
	m_ui[3]->m_panelSettings = panelSettings;
	m_ui[3]->m_Settings = buttonsSettings;
	m_ui[3]->m_panelSettingsClose = panelClose;
	m_ui[3]->m_SettingsClose = buttonsSettingsExit;

  //////////////////////////////////////////Graficas/////////////////////////////////////////

	std::vector<Button> buttonsGraphics = {
Button(vector<string>{"GENERIC PNP MONITOR", "TYPEC"}, sf::Vector2f(posX, 325), sizeButtonSettings,
			 cButtonBlack, 51),
			 //Text
Button(vector<string>{"Modo ventana"},
		Vector2f(50, 50),
		sizeButtonText,
		cButtonBlack, 11),

Button(vector<string>{"NO", "30", "40", "50", "60", "75", "90", "100", "120", "144", "160", "165", "180", "200", "240", "360", "480"},
			 Vector2f(posX, 380),
			 sizeButtonSettings,
			 cButtonBlack, 52),
			 //Text
Button(vector<string>{"Combinacion de teclas"},
		Vector2f(50, 50),
		sizeButtonText,
		cButtonBlack, 11),

	Button(vector<string>{"NO"}, sf::Vector2f(posX, 505), sizeButtonSettings,
			 cButtonBlack, 53),
Button(vector<string>{"AJUSTAR"}, sf::Vector2f(posX, 560), sizeButtonSettings,
			 cButtonBlack, 54, UI::BRIGHT),


Button(vector<string>{"PERSONALIZADA", "BAJA", "MEDIA", "PERSONALIZADA", "EPICA"},
       sf::Vector2f(posX, 685), sizeButtonSettings,
			 cButtonBlack, 55),
Button(vector<string>{"BAJA", "MEDIA", "PERSONALIZADA", "EPICA"}, sf::Vector2f(posX, 740), sizeButtonSettings,
			 cButtonBlack, 56),
Button(vector<string>{"BAJA", "MEDIA", "PERSONALIZADA", "EPICA"}, sf::Vector2f(posX, 795), sizeButtonSettings,
			 cButtonBlack, 57),
			 Button(vector<string>{"BAJA", "MEDIA", "PERSONALIZADA", "EPICA"}, sf::Vector2f(posX, 850), sizeButtonSettings,
			 cButtonBlack, 58),
Button(vector<string>{"BAJA", "MEDIA", "PERSONALIZADA", "EPICA"}, sf::Vector2f(posX, 905), sizeButtonSettings,
			 cButtonBlack, 59),
		Button(vector<string>{"BAJA", "MEDIA", "PERSONALIZADA", "EPICA"}, sf::Vector2f(posX, 960), sizeButtonSettings,
			 cButtonBlack, 60),
Button(vector<string>{"BAJA", "MEDIA", "PERSONALIZADA", "EPICA"}, sf::Vector2f(posX, 1015), sizeButtonSettings,
			 cButtonBlack, 61),
			 Button(vector<string>{"SUAVIZADO TEMPORAL", "SUAVIZADO TEMPORAL (ALTO)", "NO", "FXAA"}, sf::Vector2f(posX, 1070), sizeButtonSettings,
			 cButtonBlack, 62),
			 Button(vector<string>{"EJECUTAR"}, sf::Vector2f(posX, 1125), sizeButtonSettings,
			 cButtonBlack, 63),
	Button(vector<string>{"DIRECTX 12", "DIRECTX 11"}, sf::Vector2f(posX, 1250), sizeButtonSettings,
			 cButtonBlack, 64),
			 Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 1305), sizeButtonSettings,
			 cButtonBlack, 65),
	Button(vector<string>{"NO", "AUTOMATICO", " CALIDAD (X1.5)", "EQUILIBRADO (X1.7)", "RENDIMIENTO (X2.0)", "ULTRARENDIMIENTO (X3.0)"}, sf::Vector2f(posX, 1200), sizeButtonSettings,
			 cButtonBlack, 66),
				Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 1360), sizeButtonSettings,
			 cButtonBlack, 67),
							Button(vector<string>{"NO"}, sf::Vector2f(posX, 1415), sizeButtonSettings,
			 cButtonBlack, 68)
	};

	std::vector<Button> progressBar2 = {
Button(vector<string>{""},
       0.5f,
			 Vector2f(posX, 50),
			 sizeButtonSettings,
			 cButtonBlack, 70),
Button(vector<string>{""}, 0.5f, sf::Vector2f(posX, 105), sizeButtonSettings,
			 cButtonBlack, 71),
Button(vector<string>{""}, 0.5f, sf::Vector2f(posX, 160), sizeButtonSettings,
			 cButtonBlack, 72),
Button(vector<string>{""}, 0.5f, sf::Vector2f(posX, 270), sizeButtonSettings,
			 cButtonBlack, 73),
	};

	UIClass* ui5 = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/6.jpg");
	m_ui.push_back(ui5);
	m_ui[4]->m_buttons = buttonsGraphics;
	m_ui[4]->m_SliderBars = progressBar2;
	m_ui[4]->m_panel = panel2;
	m_ui[4]->m_panelSettings = panelSettings;
	m_ui[4]->m_Settings = buttonsSettings;
	m_ui[4]->m_panelSettingsClose = panelClose;
	m_ui[4]->m_SettingsClose = buttonsSettingsExit;

	//////////////////////////////////////////////////

	std::vector<Button> buttonsAudio = {

		//Text
Button(vector<string>{"Combinacion de teclas"},
		Vector2f(50, 50),
		sizeButtonText,
		cButtonBlack, 11),
		//Text
Button(vector<string>{"Sensibilidad de vista"},
		Vector2f(50, 110),
		sizeButtonText,
		cButtonBlack, 11),
		//Text
Button(vector<string>{"Invertir el eje horizontal"},
		Vector2f(50, 160),
		sizeButtonText,
		cButtonBlack, 11),

Button(vector<string>{"NO", "25%", "50%", "75%", "100%"}, sf::Vector2f(posX, 215), sizeButtonSettings,
			 cButtonBlack, 74),


	Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 340), sizeButtonSettings,
			 cButtonBlack, 75),
	Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 395), sizeButtonSettings,
			 cButtonBlack, 76),


Button(vector<string>{"DISPOSITIVOS DE SISTEMA PREDETERMINADO", "DISPOSITIVOS DE COMUNICACIONES PREDETERMINADO", "AURICULARES CON AUDIFONOS", "MICROFONO", "MICROPHONE ARRAY"},
sf::Vector2f(posX, 450), sizeButtonSettings,
			 cButtonBlack, 77),
							Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 615), sizeButtonSettings,
			 cButtonBlack, 78),
	};

	std::vector<Button> progressAudio = {
Button(vector<string>{""},
			 .8f,
			 Vector2f(posX, 50),
			 sizeButtonSettings,
			 cButtonBlack, 79),
Button(vector<string>{""},
			 .8f,
			 sf::Vector2f(posX, 105),
			 sizeButtonSettings,
			 cButtonBlack, 80),
Button(vector<string>{""},
			 .8f,
			 sf::Vector2f(posX, 160),
			 sizeButtonSettings,
			 cButtonBlack, 81),

	Button(vector<string>{""},
				 .8f,
				 sf::Vector2f(posX, 505),
				 sizeButtonSettings,
			 cButtonBlack, 82),
				Button(vector<string>{""}, 0.8f, sf::Vector2f(posX, 560), sizeButtonSettings,
			 cButtonBlack, 83)
	};

	UIClass* ui6 = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/6.jpg");
	m_ui.push_back(ui6);
	m_ui[5]->m_buttons = buttonsAudio;
	m_ui[5]->m_SliderBars = progressAudio;
	m_ui[5]->m_panel = panel2;
	m_ui[5]->m_panelSettings = panelSettings;
	m_ui[5]->m_Settings = buttonsSettings;
	m_ui[5]->m_panelSettingsClose = panelClose;
	m_ui[5]->m_SettingsClose = buttonsSettingsExit;

	std::vector<Button> buttonsConexion = {
			Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 50), sizeButtonSettings,
				 cButtonBlack, 84),

	Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 175), sizeButtonSettings,
				 cButtonBlack, 85),
	Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 230), sizeButtonSettings,
				 cButtonBlack, 86),
					Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 285), sizeButtonSettings,
				 cButtonBlack, 87),
	Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 340), sizeButtonSettings,
				 cButtonBlack, 88),
					Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 395), sizeButtonSettings,
				 cButtonBlack, 89),
	Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 450), sizeButtonSettings,
				 cButtonBlack, 90),
					Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 505), sizeButtonSettings,
				 cButtonBlack, 91),
	Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 560), sizeButtonSettings,
				 cButtonBlack, 92)
	};


	UIClass* ui7 = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/6.jpg");
	m_ui.push_back(ui7);
	m_ui[6]->m_buttons = buttonsConexion;
	m_ui[6]->m_panel = panel2;
	m_ui[6]->m_panelSettings = panelSettings;
	m_ui[6]->m_Settings = buttonsSettings;
	m_ui[6]->m_panelSettingsClose = panelClose;
	m_ui[6]->m_SettingsClose = buttonsSettingsExit;

	Panel panelPlayGame(sf::Vector2f(1940, 1100), 0.0f, "a", sf::Vector2f(-20, -20));

	UIClass* ui8Inicio = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/6.jpg");
	m_ui.push_back(ui8Inicio);
	m_ui[7]->m_panel = panelPlayGame;
	m_ui[7]->m_panelSettingsClose = panelClose;
	m_ui[7]->m_SettingsClose = buttonsSettingsExit;

	UIClass* ui9tutorial = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/5.jpg");
	m_ui.push_back(ui9tutorial);
	m_ui[8]->m_panel = panelPlayGame;
	m_ui[8]->m_panelSettingsClose = panelClose;
	m_ui[8]->m_SettingsClose = buttonsSettingsExit;

	UIClass* ui10tutorial = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/5.jpg");
	m_ui.push_back(ui10tutorial);
	m_ui[9]->m_panel = panelPlayGame;
	m_ui[9]->m_panelSettingsClose = panelClose;
	m_ui[9]->m_SettingsClose = buttonsSettingsExit;




	std::vector<Button> buttonsControlExit = {
	Button(vector<string>{"VOLVER A VALORES PREDETERMINADOS"},
				 Vector2f(0, 30),
				 sf::Vector2f(500, 45),
				 cButtonBlack, 11),

	Button(vector<string>{"SALIR"},
				 sf::Vector2f(515, 30),
				 sf::Vector2f(200, 45),
				 cButtonBlack, 12, UI::EXIT_TO_CONTROL)
	};
	Panel panelControls(sf::Vector2f(1000, 110), 0.0f, "AJUSTES/DISENO DE CONTROL", sf::Vector2f(500, 100));

	std::vector<Button> buttonsControlModdificy = {
		Button(vector<string>{"CLASICO"}, sf::Vector2f(300, 50), sizeButtonSettings,
			 cButtonBlack, 84, UI::MODERNO)
	};
	UIClass* ui11 = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/Clasico.png");
	m_ui.push_back(ui11);
	m_ui[10]->m_buttons = buttonsControlModdificy;
	m_ui[10]->m_panel = panelControls;
	m_ui[10]->m_panelSettingsClose = panelClose;
	m_ui[10]->m_SettingsClose = buttonsControlExit;

	std::vector<Button> buttonsControlModdificy2 = {
	Button(vector<string>{"MODERNO"}, sf::Vector2f(300, 50), sizeButtonSettings,
		 cButtonBlack, 84, UI::OPCIONES_AVANZADAS)
	};
	UIClass* ui12 = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/Moderno.png");
	m_ui.push_back(ui12);
	m_ui[11]->m_buttons = buttonsControlModdificy2;
	m_ui[11]->m_panel = panelControls;
	m_ui[11]->m_panelSettingsClose = panelClose;
	m_ui[11]->m_SettingsClose = buttonsControlExit;

	std::vector<Button> buttonsControlModdificy3 = {
Button(vector<string>{"OPCIONES AVANZADAS"}, sf::Vector2f(300, 50), sizeButtonSettings,
	 cButtonBlack, 84, UI::TACTICO)
	};
	UIClass* ui13 = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/Opciones Avanzadas.png");
	m_ui.push_back(ui13);
	m_ui[12]->m_buttons = buttonsControlModdificy3;
	m_ui[12]->m_panel = panelControls;
	m_ui[12]->m_panelSettingsClose = panelClose;
	m_ui[12]->m_SettingsClose = buttonsControlExit;

	std::vector<Button> buttonsControlModdificy4 = {
Button(vector<string>{"TACTICO"}, sf::Vector2f(300, 50), sizeButtonSettings,
	 cButtonBlack, 84, UI::CLASICO)
	};
	UIClass* ui14 = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/Tactico.png");
	m_ui.push_back(ui14);
	m_ui[13]->m_buttons = buttonsControlModdificy4;
	m_ui[13]->m_panel = panelControls;
	m_ui[13]->m_panelSettingsClose = panelClose;
	m_ui[13]->m_SettingsClose = buttonsControlExit;




	std::vector<Button> buttonsControlExit2 = {
	Button(vector<string>{"VOLVER A VALORES PREDETERMINADOS"},
				 Vector2f(0, 30),
				 sf::Vector2f(500, 45),
				 cButtonBlack, 11),

	Button(vector<string>{"SALIR"},
				 sf::Vector2f(515, 30),
				 sf::Vector2f(200, 45),
				 cButtonBlack, 12, UI::EXIT_TO_GRAPHICS)
	};

	Panel panelBright(sf::Vector2f(1000, 110), 0.0f, "AJUSTES/BRILLO", sf::Vector2f(500, 100));

	std::vector<Button> buttonsBrightModdificy = {
		Button(vector<string>{"CLASICO"}, 0.5f, sf::Vector2f(20, 900), sizeButtonSettings,
			 cButtonBlack, 84)
	};
	UIClass* ui15 = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/Brillo.png");
	m_ui.push_back(ui15);
	m_ui[14]->m_SliderBars = buttonsBrightModdificy;
	m_ui[14]->m_panel = panelControls;
	m_ui[14]->m_panelSettingsClose = panelClose;
	m_ui[14]->m_SettingsClose = buttonsControlExit2;
}



