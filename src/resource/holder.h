#ifndef HISTA_PROJECT_HOLDER_H
#define HISTA_PROJECT_HOLDER_H

#include <string>
#include <memory>
#include <map>

namespace hista {
    namespace resource {
        template<typename Resource, typename Identifier>
        class holder {
        public:
            void load(Identifier id, const std::string &filename);

            Resource &get(Identifier id) const;

        private:
            std::map<Identifier, std::unique_ptr<Resource>> _map;
        };
    }
}

#include "holder.inl"

#endif //HISTA_PROJECT_HOLDER_H
