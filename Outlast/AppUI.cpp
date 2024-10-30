#include "AppUI.h"

const sf::Vector2f sizeButton(600, 70);
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

}


void App::update()
{
	ImGui::SFML::Update(ventana, deltaClock.restart());
}

void App::render()
{
	Color rgbGris(184, 184, 184);

	ventana.clear(Color(rgbGris));

	m_ui.top()->drawUI();

	m_ui.top()->m_panel.draw(m_ui.top()->m_buttons, m_ui.top()->m_SliderBars);

	if (m_ui.top()->m_Settings.size() > 0)
	{
		m_ui.top()->m_panelSettings.drawSettings(m_ui.top()->m_Settings);
	}

	ImGui::SFML::Render(ventana);

	ventana.display();
}

void App::createUI()
{
	std::vector<Button> buttons = {
			Button(vector<string>{"ENTRAR A LA INSTALACION MURKOFF"}, sf::Vector2f(10, 30), sizeButton, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 0),
			Button(vector<string>{"VOLVER A JUGAR LA INTRODUCCION"}, sf::Vector2f(10, 105), sizeButton, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 1),
			Button(vector<string>{"AJUSTES"}, sf::Vector2f(10, 180), sizeButton, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 2),
			Button(vector<string>{"CREDITOS"}, sf::Vector2f(10, 255), sizeButton, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 3),
			Button(vector<string>{"SALIR DEL JUEGO"}, sf::Vector2f(10, 330), sizeButton, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 4)
	};



	Panel panel(sf::Vector2f(1200, 700), 0.0f, "Menu", sf::Vector2f(10, 650)); // Tamaño del panel, transparencia y título

	UIClass* ui = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/MenuOutlast.jpg");
	m_ui.push(ui);
	m_ui.top()->m_buttons = buttons;
	m_ui.top()->m_panel = panel;

	std::vector<Button> buttonsSettings = {
		Button(vector<string>{"GENERAL"}, sf::Vector2f(50, 40), sizeButtonGlobalSettings, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 5),
		Button(vector<string>{"IDIOMA"}, sf::Vector2f(270, 40), sizeButtonGlobalSettings, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 6),
		Button(vector<string>{"CONTROLES"}, sf::Vector2f(490, 40), sizeButtonGlobalSettings, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 7),
		Button(vector<string>{"GRAFICOS"}, sf::Vector2f(710, 40), sizeButtonGlobalSettings, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 8),
		Button(vector<string>{"AUDIO"}, sf::Vector2f(930, 40), sizeButtonGlobalSettings, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 9),
		Button(vector<string>{"CONEXION"}, sf::Vector2f(1150, 40), sizeButtonGlobalSettings, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), 10)
	};


	float posX = 600;
	ImVec4 cButtonBlack(0.0f, 0.0f, 0.0f, 0.5f);
	std::vector<Button> buttons2 = {
		Button(vector<string>{"ESTANDAR", "ACCECIBLE", "INMERSIVO", "COOPERATIVO CLASICO"},
					 Vector2f(posX, 50),
					 sizeButtonSettings,
					 cButtonBlack, 11),

		Button(vector<string>{"OCULTAR", "PERMANENTE", "NO"},
					 sf::Vector2f(posX, 175),
					 sizeButtonSettings,
					 cButtonBlack, 12),
		Button(vector<string>{"NO", "OCULTAR", "PERMANENTE"}, sf::Vector2f(posX, 230), sizeButtonSettings,
					 cButtonBlack, 13),
		Button(vector<string>{"OCULTAR", "PERMANENTE", "NO"}, sf::Vector2f(posX, 285), sizeButtonSettings,
					 cButtonBlack, 14),
		Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 340), sizeButtonSettings,
					 cButtonBlack, 15),
		Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 395), sizeButtonSettings,
					 cButtonBlack, 16),
		Button(vector<string>{"OCULTAR", "PERMANENTE"},
					 sf::Vector2f(posX, 450),
					 sizeButtonSettings,
					 cButtonBlack, 17),
		Button(vector<string>{"PERMANENTE", "OCULTAR"},
					 sf::Vector2f(posX, 505),
					 sizeButtonSettings,
					 cButtonBlack, 18),
		Button(vector<string>{"OCULTAR", "PERMANENTE", "IGUAL QUE EL OBJETIVO"}, sf::Vector2f(posX, 560), sizeButtonSettings,
					 cButtonBlack, 19),
		Button(vector<string>{"SI", "NO", "AL APUNTAR"}, sf::Vector2f(posX, 615), sizeButtonSettings,
					 cButtonBlack, 20),
		Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 670), sizeButtonSettings,
					 cButtonBlack, 21),
		Button(vector<string>{"COMPLETA", "NO", "SIMPLE"}, sf::Vector2f(posX, 725), sizeButtonSettings,
					 cButtonBlack, 22),
		Button(vector<string>{"FLECHA", "SI", "NO"}, sf::Vector2f(posX, 780), sizeButtonSettings,
					 cButtonBlack, 23),
		Button(vector<string>{"FUERA DEL JUEGO", "NO", "SIEMPRE"}, sf::Vector2f(posX, 395), sizeButtonSettings,
					 cButtonBlack, 24),

		Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 895), sizeButtonSettings,
					 cButtonBlack, 25),
		Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 950), sizeButtonSettings,
					 cButtonBlack, 26),

		Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 1075), sizeButtonSettings,
					 cButtonBlack, 27),
		Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 1130), sizeButtonSettings,
					 cButtonBlack, 28),
							Button(vector<string>{"SI", "SOLO AMISTADES", "NO"}, sf::Vector2f(posX, 1185), sizeButtonSettings,
					 cButtonBlack, 29)
	};

	Panel panel2(sf::Vector2f(1000, 900), 0.0f, "GENERAL", sf::Vector2f(100, 150)); // Tamaño del panel, transparencia y título
	Panel panelSettings(sf::Vector2f(1400, 90), 0.0f, "AJUSTES", sf::Vector2f(100, 25));
	UIClass* ui2 = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/3.jpg");
	m_ui.push(ui2);
	m_ui.top()->m_buttons = buttons2;
	m_ui.top()->m_panel = panel2;
	m_ui.top()->m_panelSettings = panelSettings;
	m_ui.top()->m_Settings = buttonsSettings;

	std::vector<Button> buttonsLenguaje = {
		Button(vector<string>{"ENGLISH", "FRANCAIS"},
					 Vector2f(posX, 50),
					 sizeButtonSettings,
					 cButtonBlack, 30),

		Button(vector<string>{"ESPANOL LATINOMARICANO", "FRANCAIS", "ITALIANO", "JAPONES", "CHINO", "POLSKI", "PORTUGUES", "RUSSO", "TURCKE", "DEUTSCH", "ENGLISH", "ESPANOL"},
					 sf::Vector2f(posX, 175),
					 sizeButtonSettings,
					 cButtonBlack, 31),
		Button(vector<string>{"NO", "OCULTAR", "PERMANENTE"}, sf::Vector2f(posX, 230), sizeButtonSettings,
					 cButtonBlack, 32),
		Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 285), sizeButtonSettings,
					 cButtonBlack, 33),
		Button(vector<string>{"MEDIA", "GRANDE", "PEQUENA"}, sf::Vector2f(posX, 340), sizeButtonSettings,
					 cButtonBlack, 34),
		Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 395), sizeButtonSettings,
					 cButtonBlack, 35),
	};

	UIClass* ui3 = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/4.jpg");
	m_ui.push(ui3);
	m_ui.top()->m_buttons = buttonsLenguaje;
	m_ui.top()->m_panel = panel2;
	m_ui.top()->m_panelSettings = panelSettings;
	m_ui.top()->m_Settings = buttonsSettings;


	///////////////////////////////////////Controles///////////////////////////////////////////

	std::vector<Button> buttonsControls = {
	Button(vector<string>{"PERSONALIZAR TECLAS"},
				 Vector2f(posX, 50),
				 sizeButtonSettings,
				 cButtonBlack, 36),
	Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 160), sizeButtonSettings,
				 cButtonBlack, 37),
	Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 215), sizeButtonSettings,
				 cButtonBlack, 38),
	Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 270), sizeButtonSettings,
				 cButtonBlack, 39),
	Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 325), sizeButtonSettings,
				 cButtonBlack, 40),
	Button(vector<string>{"PERSONALIZAR CONTROL"},
				 Vector2f(posX, 450),
				 sizeButtonSettings,
				 cButtonBlack, 41),
	
		Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 615), sizeButtonSettings,
				 cButtonBlack, 42),
	Button(vector<string>{"NO", "SI"}, sf::Vector2f(posX, 670), sizeButtonSettings,
				 cButtonBlack, 43),

	Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 725), sizeButtonSettings,
				 cButtonBlack, 44),

	Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 780), sizeButtonSettings,
				 cButtonBlack, 45),
	Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 835), sizeButtonSettings,
				 cButtonBlack, 46)
	};

	std::vector<Button> progressBar = {
			Button(vector<string>{"a"},
			   .5, 
				 sf::Vector2f(posX, 105),
				 sizeButtonSettings,
			   cButtonBlack,
				 0),
			Button(vector<string>{"b"},
				 .5,
				 sf::Vector2f(posX, 505),
				 sizeButtonSettings,
		     cButtonBlack,
				 1),
			Button(vector<string>{"c"},
				 .5,
				 sf::Vector2f(posX, 560),
				 sizeButtonSettings,
				 cButtonBlack,
				 2)
	};

	UIClass* ui4 = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/5.jpg");
	m_ui.push(ui4);
	m_ui.top()->m_buttons = buttonsControls;
	m_ui.top()->m_SliderBars = progressBar;
	m_ui.top()->m_panel = panel2;
	m_ui.top()->m_panelSettings = panelSettings;
	m_ui.top()->m_Settings = buttonsSettings;

  //////////////////////////////////////////Graficas/////////////////////////////////////////

	std::vector<Button> buttonsGraphics = {

Button(vector<string>{"GENERIC PNP MONITOR", "TYPEC"}, sf::Vector2f(posX, 325), sizeButtonSettings,
			 cButtonBlack, 51),
Button(vector<string>{"NO", "30", "40", "50", "60", "75", "90", "100", "120", "144", "160", "165", "180", "200", "240", "360", "480"},
			 Vector2f(posX, 380),
			 sizeButtonSettings,
			 cButtonBlack, 52),


	Button(vector<string>{"NO"}, sf::Vector2f(posX, 505), sizeButtonSettings,
			 cButtonBlack, 53),
Button(vector<string>{"AJUSTAR"}, sf::Vector2f(posX, 560), sizeButtonSettings,
			 cButtonBlack, 54),


Button(vector<string>{"PERSONALIZADA", "BAJA", "MEDIA", "PERSONALIZADA", "EPICA"}, sf::Vector2f(posX, 685), sizeButtonSettings,
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
Button(vector<string>{"VENTANAS SIN BORDES", "VENTANA", "PANTALLA COMPLETA"},
			 Vector2f(posX, 50),
			 sizeButtonSettings,
			 cButtonBlack, 70),
Button(vector<string>{"2560 X 1140"}, sf::Vector2f(posX, 105), sizeButtonSettings,
			 cButtonBlack, 71),
Button(vector<string>{"N/A"}, sf::Vector2f(posX, 160), sizeButtonSettings,
			 cButtonBlack, 72),
Button(vector<string>{"SI", "NO"}, sf::Vector2f(posX, 270), sizeButtonSettings,
			 cButtonBlack, 73),
	};

	UIClass* ui5 = new UIClass(ventana, "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/6.jpg");
	m_ui.push(ui5);
	m_ui.top()->m_buttons = buttonsGraphics;
	m_ui.top()->m_SliderBars = progressBar2;
	m_ui.top()->m_panel = panel2;
	m_ui.top()->m_panelSettings = panelSettings;
	m_ui.top()->m_Settings = buttonsSettings;


	//////////////////////////////////////////////////

	std::vector<Button> buttonsAudio = {

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
	m_ui.push(ui6);
	m_ui.top()->m_buttons = buttonsAudio;
	m_ui.top()->m_SliderBars = progressAudio;
	m_ui.top()->m_panel = panel2;
	m_ui.top()->m_panelSettings = panelSettings;
	m_ui.top()->m_Settings = buttonsSettings;

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
	m_ui.push(ui7);
	m_ui.top()->m_buttons = buttonsConexion;
	m_ui.top()->m_panel = panel2;
	m_ui.top()->m_panelSettings = panelSettings;
	m_ui.top()->m_Settings = buttonsSettings;
}



