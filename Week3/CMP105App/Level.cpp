#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	
	//moving circle defined
	circle.setRadius(15);
	circle.setPosition(300, 300);
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineColor(sf::Color::Magenta);
	circle.setOutlineThickness(2.f);

	speedX = 50.f;
	speedY = 50.f;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	//SPEED//////////////////////////////////////
	if (input->isKeyDown(sf::Keyboard::Add))
	{
		speedX++;
		speedY++;
	}
	if (input->isKeyDown(sf::Keyboard::Subtract))
	{
		speedX--;
		speedY--;
	}
	//DIRECTIONS/////////////////////////////////
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		speedX = 100.f;
		speedY = 0;
		input->setKeyUp(sf::Keyboard::Right);
		circle.move(speedX * dt, speedY * dt);
	}
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		speedX = -100;
		speedY = 0;
		input->setKeyUp(sf::Keyboard::Left);
		circle.move(speedX * dt, speedY * dt);
	}
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		speedY = -100;
		speedX = 0;
		input->setKeyUp(sf::Keyboard::Up);
		circle.move(speedX * dt, speedY * dt);
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		speedY = 100;
		speedX = 0;
		input->setKeyUp(sf::Keyboard::Down);
		circle.move(speedX * dt, speedY * dt);
	}
}

// Update game objects
void Level::update(float dt)
{
	sf::Vector2u res = window->getSize();
	//update and move circle

	circle.move(speedX * dt, speedY*dt);

	if (circle.getPosition().x+15 > res.x)
	{
		speedX = speedX * -1;
	}
	if (circle.getPosition().x < 0)
	{
		speedX = speedX * -1;
	}
	if (circle.getPosition().y + 15 > res.y)
	{
		speedY = speedY * -1;
	}
	if (circle.getPosition().y < 0)
	{
		speedY = speedY * -1;
	}

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(circle);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}