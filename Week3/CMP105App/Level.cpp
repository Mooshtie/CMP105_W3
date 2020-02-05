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

	speed = 50.f;
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
		speed++;
	}
	if (input->isKeyDown(sf::Keyboard::Subtract))
	{
		speed--;
	}
	//DIRECTIONS/////////////////////////////////
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		input->setKeyUp(sf::Keyboard::Right);
		circle.move(speed * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		input->setKeyUp(sf::Keyboard::Left);
		circle.move(speed * dt, 1);
	}
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		input->setKeyUp(sf::Keyboard::Up);
		circle.move(speed * dt, 2);
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		input->setKeyUp(sf::Keyboard::Down);
		circle.move(speed * dt, 3);
	}
}

// Update game objects
void Level::update(float dt)
{
	sf::Vector2u res = window->getSize();
	//update and move circle

	circle.move(speed * dt, 0);

	if (circle.getPosition().x+15 > res.x)
	{
		speed = speed * -1;
	}
	if (circle.getPosition().x < 0)
	{
		speed = speed * -1;
	}
	if (circle.getPosition().y + 15 > res.y)
	{
		speed = speed * -1;
	}
	if (circle.getPosition().y < 0)
	{
		speed = speed * -1;
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