#include <iostream>
#include <string>

 /*
  * the final object that will be created using Builder
  */
class Game
{
private:
    std::string time;
    std::string place;
    std::string player;
public:
    void setTime(const std::string& part)
    {
        time = part;
    }
    void setPlace(const std::string& part)
    {
        place = part;
    }
    void setPlayer(const std::string& part)
    {
        player = part;
    }
    std::string get()
    {
        return ("\nTime:" + time + "\nPlace:" + place + "\nPlayer:" + player);
    }

};

/*
 * Builder
 * abstract interface for creating products
 */
class Builder
{
protected:
    Game game;
public:
    virtual ~Builder() {}

    Game get()
    {
        return game;
    }

    virtual void buildTime() = 0;
    virtual void buildPlace() = 0;
    virtual void buildPlayer() = 0;

};

/*
 * Concrete Builder X and Y
 * create real products and stores them in the composite structure
 */
class SwimmingGameBuilder : public Builder
{
public:
    void buildTime()
    {
        game.setTime("11.06");
    }
    void buildPlace()
    {
        game.setPlace("SwimmingPool");
    }
    void buildPlayer()
    {
        game.setPlayer("Phelps");
    }
};

class RunningGameBuilder : public Builder
{
public:
    void buildTime()
    {
        game.setTime("11.06");
    }
    void buildPlace()
    {
        game.setPlace("TAF-Ground");
    }
    void buildPlayer()
    {
        game.setPlayer("Bolt");
    }
};

/*
 * Director
 * responsible for managing the correct sequence of object creation
 */
class Director {
public:
    Director() : builder() {}

    ~Director()
    {
        if (builder)
        {
            delete builder;
        }
    }

    void set(Builder* b)
    {
        if (builder)
        {
            delete builder;
        }
        builder = b;
    }

    Game get()
    {
        return builder->get();
    }

    void construct()
    {
        builder->buildTime();
        builder->buildPlace();
        builder->buildPlayer();
    }

private:
    Builder* builder;
};


int test_builder()
{
    Director director;
    director.set(new SwimmingGameBuilder);
    director.construct();

    Game game1 = director.get();
    std::cout << "1st game: " << game1.get() << std::endl;

    director.set(new RunningGameBuilder);
    director.construct();

    Game game2 = director.get();
    std::cout << "2nd game: " << game2.get() << std::endl;

    return 0;
}