#pragma once

#include <SFML/Graphics.hpp>
#include <stack>

#include <memory>

#include "UI.h"

using namespace std;
using namespace sf;

constexpr int window_y = 1080;
constexpr int window_x = 1920;

class App
{
public:
	/////////////////////////////////////////////
	/// <summary>
	/// Construct.
	/// </summary>
	App();
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	/// <summary>
	/// Destruct.
	/// </summary>
	~App();
	/////////////////////////////////////////////

private:
	/////////////////////////////////////////////
	/// <summary>
	/// Start the input, update and render.
	/// </summary>
	void mainloop();
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	/// <summary>
	/// Record customer entries.
	/// </summary>
	void entrada();
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	/// <summary>
	/// Updates application states.
	/// </summary>
	void update();
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	/// <summary>
	/// Draw all the objects that are in the
	/// position.
	/// </summary>
	void render();


	void createUI();

	/////////////////////////////////////////////
	sf::RenderWindow ventana;
	std::stack<UIClass*> m_ui;

	sf::Clock deltaClock;
	/////////////////////////////////////////////
};
