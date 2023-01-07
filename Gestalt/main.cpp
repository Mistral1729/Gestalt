#include "Game.h"

int main()
{
    //Background for menu
    sf::Texture bgtex;
    if (!bgtex.loadFromFile("resources\\faded_memories.png"))
        return -1;
    bgtex.setSmooth(true);

    //Background music
    sf::Music bgmus;
    if (!bgmus.openFromFile("resources\\audio\\fm.ogg"))
        return -1;

    bgmus.play();
    bgmus.setVolume(50.0f);
    bgmus.setLoop(true);

    // Load a font
    sf::Font font;
    if (!font.loadFromFile("resources\\fonts\\GOUDOS.ttf"))
        return -1;

    // Create the title text
    sf::Text titleText;
    titleText.setFont(font);
    titleText.setString("Gestalt");
    titleText.setCharacterSize(64);
    titleText.setFillColor(sf::Color::White);
    titleText.setStyle(sf::Text::Bold);
    titleText.setPosition(10, 10);

    // Create the menu items
    std::vector<sf::Text> menuItems;
    std::vector<std::string> menuStrings = { "New Game", "Load Game", "Options", "Quit" };

    for (int i = 0; i < menuStrings.size(); i++)
    {
        sf::Text menuItem;
        menuItem.setFont(font);
        menuItem.setString(menuStrings[i]);
        menuItem.setCharacterSize(32);
        menuItem.setFillColor(sf::Color::White);
        menuItem.setPosition(10, 80 + i * 40);
        menuItems.push_back(menuItem);
    }

    // Create a selector arrow
    sf::RectangleShape selector(sf::Vector2f(250, 35));
    selector.setFillColor(sf::Color::White);
    selector.setPosition(0, 80);

    // Initialize the selected item index
    int selectedItem = 0;

    // Initialize the selector's timer
    sf::Clock selectorClock;

    // Set the transition duration in seconds
    const float TRANSITION_DURATION = 1.5f;

    // Set the transition colors
    const sf::Color TRANSITION_COLOR_1 = sf::Color::White;
    const sf::Color TRANSITION_COLOR_2 = sf::Color::Transparent;

    // Initialize the transition timer
    float transitionTimer = 0.0f;

    sf::Sprite bgspr(bgtex);
    sf::RenderWindow window(sf::VideoMode(bgtex.getSize().x, bgtex.getSize().y), "Gestalt");

    //Game Loop
    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                if (selectedItem > 0)
                {
                    selectedItem--;
                    selector.setPosition(0, 80 + selectedItem * 40);
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                if (selectedItem < menuItems.size() - 1)
                {
                    selectedItem++;
                    selector.setPosition(0, 80 + selectedItem * 40);
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            {
                if (menuStrings[selectedItem] == "New Game")
                {
                    // Start a new game
                }
                else if (menuStrings[selectedItem] == "Load Game")
                {
                    // Load a saved game
                }
                else if (menuStrings[selectedItem] == "Options")
                {
                    // Show the options menu
                }
                else if (menuStrings[selectedItem] == "Quit")
                {
                    // Quit the game
                    window.close();
                }
            }
        }

        // Update the transition timer
        transitionTimer += selectorClock.restart().asSeconds();

        // Reset the transition timer if it exceeds the transition duration
        if (transitionTimer > TRANSITION_DURATION)
            transitionTimer -= TRANSITION_DURATION;

        // Calculate the transition progress (0.0-1.0)
        float transitionProgress = transitionTimer / TRANSITION_DURATION;

        // Interpolate the selector's color between the transition colors
        sf::Color selectorColor;
        selectorColor.r = (1 - transitionProgress) * TRANSITION_COLOR_1.r + transitionProgress * TRANSITION_COLOR_2.r;
        selectorColor.g = (1 - transitionProgress) * TRANSITION_COLOR_1.g + transitionProgress * TRANSITION_COLOR_2.g;
        selectorColor.b = (1 - transitionProgress) * TRANSITION_COLOR_1.b + transitionProgress * TRANSITION_COLOR_2.b;
        selectorColor.a = (1 - transitionProgress) * TRANSITION_COLOR_1.a + transitionProgress * TRANSITION_COLOR_2.a;

        // Set the selector's color
        selector.setFillColor(selectorColor);


        /**
        *
        *	DRAW BETWEEN clear() AND display()
        *
        **/
        
        window.clear();

        window.draw(bgspr);

        // Draw the menu
        window.draw(titleText);
        for (int i = 0; i < menuItems.size(); i++)
            window.draw(menuItems[i]);
        window.draw(selector);

        window.display();
    }

    return 0;
}