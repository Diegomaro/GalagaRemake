#include "Game.hpp"
#include <iostream>
#include <cmath>

using namespace GameConstants;

Game::Game(): window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game") {}

void Game::start(){
    loadSprites();
    createPlayer();
    createBackground();
    createEnemy({20*3, 6*3});
    createEnemy({40*3, 0*3});
    window.setVisible(true);
    while(window.isOpen()) loop();
}

void Game::loadSprites(){
    rm.loadTexture("sprites", "media/game_sprites.png");
    rm.loadTexture("background", "media/background.png");
}

void Game::createPlayer(){
    player.setTexture(rm.getTexture("sprites"));
}

void Game::createEnemy(sf::Vector2f enemyPosition){
    Enemy enemy(enemyPosition);
    enemy.setTexture(rm.getTexture("sprites"));
    enemies.insertTail(enemy);
}
void Game::createBackground(){
    background.setTexture(rm.getTexture("background"));
}


void Game::loop(){
    inputHandler();
    eventHandler();
    elapsedTime += clock.restart();
    while(elapsedTime >= TIMESTEP){
        elapsedTime -= TIMESTEP;
        updateLogic();
        if(player.shootCooldown > 0) player.shootCooldown -= 1;
        render();
    }
}

void Game::updateLogic(){
    movePlayer();
    moveBullets();
    collisionHandler();
}

void Game::collisionHandler(){
    //player
    // enemy bullets
    bool enemyIsAlive = true;
    while(enemies.hasNext()){
        Enemy *enemy = &enemies.getNextNodeData();
        enemyIsAlive = true;
        while(player.bullets.hasNext() && enemyIsAlive){
            Bullet *bullet = &player.bullets.getNextNodeData();
            sf::FloatRect bulletHitbox = bullet->getHitbox();
            sf::FloatRect enemyHitbox = enemy->getHitbox();
            if(collisionChecker(bulletHitbox, enemyHitbox)){
                std::cout << "collision detected!" << std::endl;
                    bullet->modifyHealth(-1);
                    if(bullet->getHealth() <= 0){
                        player.bullets.deleteNode(*bullet);
                    }
                    enemy->modifyHealth(-1);
                    if(enemy->getHealth() <= 0){
                        //enemy animation
                        enemies.deleteNode(*enemy);
                        enemyIsAlive = false;
                    }
            }
        }
    }
}

bool Game::collisionChecker(sf::FloatRect hitbox1, sf::FloatRect hitbox2){
    float hitbox1LowY = hitbox1.top;
    float hitbox1HighY = hitbox1.top + hitbox1.height;
    float hitbox2LowY = hitbox2.top;
    float hitboxwHighY = hitbox2.top + hitbox2.height;
    if(hitbox1LowY <= hitboxwHighY && hitbox1HighY >= hitbox2LowY){
        float hitbox1LowX = hitbox1.left;
        float hitbox1HighX = hitbox1.left + hitbox1.width;
        float hitbox2LowX = hitbox2.left;
        float hitboxwHighX = hitbox2.left + hitbox2.width;
        if(hitbox1LowX <= hitboxwHighX && hitbox1HighX >= hitbox2LowX){
            return true;
        }
    }
    return false;
}

void Game::movePlayer(){
    int playerOutOfBondsPos = player.getPosition().x + player.getHitbox().width + player.getVelocity().x;
    int playerOutOfBondsNeg = player.getPosition().x + player.getVelocity().x;
    if(playerOutOfBondsPos <= WINDOW_WIDTH && player.getVelocity().x > 0){
        player.setPosition(player.getPosition() + player.getVelocity());
    } else if(playerOutOfBondsNeg > 0 && player.getVelocity().x < 0){
        player.setPosition(player.getPosition() + player.getVelocity());
    }
}

void Game::moveBullets(){
    while(player.bullets.hasNext()){
        Bullet *bullet = &player.bullets.getNextNodeData();
        bullet->move(bullet->getVelocity());
        //player.bullets.addVelToNode({0,-BULLET_SPEED});
    }
}

//only once per event, some events cycle
void Game::eventHandler(){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
   }
}

//constatly checks, doesnt get cleaned, more consistent
void Game::inputHandler(){
    sf::Vector2f v = {0, 0};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        v.x += -PLAYER_SPEED;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        v.x += PLAYER_SPEED;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(player.shootCooldown == 0){
            player.shootCooldown += SHOOT_COOLDOWN;
            player.ShootBullet(rm.getTexture("sprites"));
        }
    }
    player.setVelocity(v);
}

void Game::render(){
    window.clear();
    renderBackground();
    renderEnemies();
    window.draw(player);
    renderBullets();
    window.display();
}

void Game::renderBullets(){
    while(player.bullets.hasNext()){
        window.draw(player.bullets.getNextNodeData());
    }
}

void Game::renderEnemies(){
    while(enemies.hasNext()){
        window.draw(enemies.getNextNodeData());
    }
}

void Game::renderBackground(){
    //background.changeFrame(); commented to protect my eyes
    window.draw(background);

}