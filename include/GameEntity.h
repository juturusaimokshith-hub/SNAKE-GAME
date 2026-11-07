#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

class GameEntity {
public:
    virtual void update() = 0;
    virtual char symbol() const = 0;
    virtual ~GameEntity() = default;
};

#endif
