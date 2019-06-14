//
//	Autor: Dawid M³ynarczyk
//


#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Unit.h"
#include "Player.h"
#include "Obstacle.h"

int main()
{
	sf::SoundBuffer buffer1;
	buffer1.loadFromFile("Sounds/main.wav");
	sf::Sound sound1;
	sound1.setBuffer(buffer1);


	sf::SoundBuffer buffer2;
	buffer2.loadFromFile("Sounds/win.wav");
	sf::Sound sound2;
	sound2.setBuffer(buffer2);

	sf::SoundBuffer buffer3;
	buffer3.loadFromFile("Sounds/lose.wav");
	sf::Sound sound3;
	sound3.setBuffer(buffer3);
	
	sound1.play();
	sound1.setLoop(true);

	sf::RenderWindow window0(sf::VideoMode(840, 800), "Menu");
	
	
	while (window0.isOpen())
	{
		
		sf::Event event0;
	
		while (window0.pollEvent(event0))
		{
			sf::Texture menu;
			menu.loadFromFile("Images/Menu.png");
			sf::Sprite Menu(menu);
			window0.clear();
			window0.draw(Menu);
			window0.display();

			if (event0.type == sf::Event::Closed
				or (event0.type == sf::Event::KeyPressed && event0.key.code == sf::Keyboard::Escape))
			{
				window0.close();
			}
			if (Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				window0.close();
				sf::RenderWindow window(sf::VideoMode(840, 800), "Cars");

				sf::Clock clock;
				sf::Clock clock2;
				sf::Texture road_extra;
				sf::Texture finish;
				sf::Texture hp;

				hp.loadFromFile("Images/hp.png");
				finish.loadFromFile("Images/finish.png");
				road_extra.loadFromFile("Images/road_extra.png");
				sf::Sprite background1(road_extra);
				sf::Sprite background2(road_extra);
				sf::Sprite background3(road_extra);
				sf::Sprite Finish(finish);
				sf::Sprite Heart1(hp);
				sf::Sprite Heart2(hp);
				sf::Sprite Heart3(hp);


				sf::Vector2f StartPosition1(0.f, -27800.f); 
				sf::Vector2f StartPosition2(0.f, -56400.f);
				sf::Vector2f StartPosition3(0.f, -85000.f);
				sf::Vector2f FinishPosition(0.f, -35000.f);
				sf::Vector2f backgroundEndPosition(0.f, 800.f);
				
				Heart1.setPosition(0.f, 0.f);
				Heart2.setPosition(0.f, 110.f);
				Heart3.setPosition(0.f, 220.f);

				background1.setPosition(StartPosition1);
				background2.setPosition(StartPosition2);
				background3.setPosition(StartPosition3);
				Finish.setPosition(FinishPosition);


				sf::Texture car;
				car.loadFromFile("Images/car2.png");
				Player p1("Images/car7.png");

				Obstacle o1("Images/car1.png", 0);
				Obstacle o2("Images/car3.png", 1);
				Obstacle o3("Images/car4.png", 2);
				Obstacle o4("Images/car5.png", 3);
				Obstacle o5("Images/car6.png");


				window.setKeyRepeatEnabled(true);


				while (window.isOpen())
				{

		

					sf::Event event;
					if (o1 == o2 or o1 == o3 or o1 == o4 or o1 == o5 or o2 == o3 or o2 == o4 or o2 == o5 or o3 == o4 or o4 == o5)
					{
						std::cout << "blad" << std::endl;
						window.close();
					}
					while (window.pollEvent(event))
					{



						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
							p1.moveLeft();

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
							p1.moveRight();


						if (event.type == sf::Event::Closed
							or (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
						{
							window.close();
						}


					}



					if (p1.getPosition().intersects(o1.getPosition()) or
						p1.getPosition().intersects(o2.getPosition()) or
						p1.getPosition().intersects(o3.getPosition()) or
						p1.getPosition().intersects(o4.getPosition()) or
						p1.getPosition().intersects(o5.getPosition()))
					{
						if (p1.visibility() == 1)
						{
							p1.editPosition();
							p1.ImmortalTexture("Images/car7.png");
							clock2.restart();
							std::cout << "Indestructible " << std::endl;
						}
					}

					if (clock2.getElapsedTime().asSeconds() > 5.f and p1.visibility() == 0)
					{
						p1.setVisibility();
						std::cout << "Destructible" << std::endl;
						p1.ImmortalTexture("Images/car2.png");
					}



					if (Finish.getPosition().y > 600 and p1.isAlive())
					{
						std::cout << "Wygrales" << std::endl;
						sf::RenderWindow window2(sf::VideoMode(420, 400), "Endgame");
						
						sound1.stop();
						sound2.play();

						while (window2.isOpen())
						{
							

							sf::Texture Win;
							Win.loadFromFile("Images/Win.png");
							sf::Sprite Winner(Win);
							window2.clear();
							window2.draw(Winner);
							window2.display();
							sf::Event event2;

							while (window2.pollEvent(event2))
							{
								if (event2.type == sf::Event::Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
								{
									window2.close();
								}
							}
							window.close();
						}
					}

					if (p1.isAlive() == 0)
					{
						std::cout << "Przegrales" << std::endl;
						sf::RenderWindow window2(sf::VideoMode(420, 400), "Endgame");

						sound1.stop();
						sound3.play();

						while (window2.isOpen())
						{
							
							sf::Texture Lose;
							Lose.loadFromFile("Images/Lose.png");
							sf::Sprite Loser(Lose);
							window2.clear();
							window2.draw(Loser);
							window2.display();
							sf::Event event2;

							while (window2.pollEvent(event2))
							{
								if (event2.type == sf::Event::Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
								{
									window2.close();
								}
							}
							window.close();
						}
					}

					if (clock.getElapsedTime().asMicroseconds() > 1.f)
					{
						background1.move(0, (float)0.1);
						background2.move(0, (float)0.1);
						background3.move(0, (float)0.1);
						Finish.move(0, (float)0.1);
						clock.restart();
					}

					int los = std::rand() % 3;
					if (o1.ret_position_y() > 1000.f)
						o1.Reset(los);
					if (o5.ret_position_y() > 1000.f)
						o5.Reset(los);
					if (o4.ret_position_y() > 1000.f)
						o4.Reset(los);
					if (o3.ret_position_y() > 1000.f)
						o3.Reset(los);
					if (o2.ret_position_y() > 1000.f)
						o2.Reset(los);



					window.clear();
					window.draw(background1);
					window.draw(background2);
					window.draw(background3);
					window.draw(Finish);

					p1.drawPlayer(window);
					p1.update();

					o1.drawObstacle(window);
					o1.update();

					o2.drawObstacle(window);
					o2.update();

					o3.drawObstacle(window);
					o3.update();

					o4.drawObstacle(window);
					o4.update();

					o5.drawObstacle(window);
					o5.update();

					if(Player::health >= 1)
					window.draw(Heart1);				
					if(Player::health >= 2)
					window.draw(Heart2);
					if(Player::health == 3)
					window.draw(Heart3);



					window.display();


				}


			}
		}
	}



	return 0;
}