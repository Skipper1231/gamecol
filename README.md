# gamecol
Этот код представляет собой текстовую игру, в которой игрок сражается с врагом, выбирая различные действия, такие как атака или попытка убегания. Игра продолжается до тех пор, пока игрок или враг не потеряют всё здоровье

## Класс персонажа
```
class Character {
protected:
    string name;
    int health;

public:
    Character(const string& name, int health) : name(name), health(health) {}

    // Проверка на живого персонажа
    bool isAlive() const {
        return health > 0;
    }

    // Получение урона
    void takeDamage(int damage) {
        health -= damage;
        if (health < 0)
            health = 0;
    }

    // Получение текущего здоровья
    int getHealth() const {
        return health;
    }

    // Получение имени персонажа
    const string& getName() const {
        return name;
    }
};
```
