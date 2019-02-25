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
        template<typename Resource, typename Identifier>
        class holder;

        namespace texture {
            enum class ID {
                Buttons,
                Tileset
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
