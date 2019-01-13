#ifndef HISTA_PROJECT_IDENTIFIER_H
#define HISTA_PROJECT_IDENTIFIER_H

namespace sf {
    class Texture;
    class Font;
//    class Shader;
    class SoundBuffer;
}

namespace hista {
    namespace resource {
        template <typename Resource, typename Identifier>
        class holder;

        namespace texture {
            enum class ID {
                Buttons
            };

            typedef holder<sf::Texture, ID> holder;
        }

        namespace font {
            enum class ID {
                Main
            };

            typedef holder<sf::Font, ID> holder;
        }

//        namespace shader {
//            enum class ID {
//                Buttons
//            };
//
//            typedef holder<sf::Shader, ID> holder;
//        }

        namespace sound_effect {
            enum class ID {
                Buttons
            };

            typedef holder<sf::SoundBuffer, ID> holder;
        }
    }
}

#endif //HISTA_PROJECT_IDENTIFIER_H






























#ifndef BOOK_STATE_HPP
#define BOOK_STATE_HPP

#include <Book/StateIdentifiers.hpp>
#include <Book/ResourceIdentifiers.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include <memory>


namespace sf
{
    class RenderWindow;
}

class StateStack;
class Player;
class MusicPlayer;
class SoundPlayer;

class State
{
public:
    typedef std::unique_ptr<State> Ptr;

    struct Context
    {
        Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player,
                MusicPlayer& music, SoundPlayer& sounds);

        sf::RenderWindow*	window;
        TextureHolder*		textures;
        FontHolder*			fonts;
        Player*				player;
        MusicPlayer*		music;
        SoundPlayer*		sounds;
    };


public:
    State(StateStack& stack, Context context);
    virtual				~State();

    virtual void		draw() = 0;
    virtual bool		update(sf::Time dt) = 0;
    virtual bool		handleEvent(const sf::Event& event) = 0;


protected:
    void				requestStackPush(States::ID stateID);
    void				requestStackPop();
    void				requestStateClear();

    Context				getContext() const;


private:
    StateStack*			mStack;
    Context				mContext;
};

#endif // BOOK_STATE_HPP
