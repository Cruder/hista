namespace hista {
    namespace resource {
        template <typename Resource, typename Identifier>
        void holder<Resource, Identifier>::load(Identifier id, const std::string& filename) {
            auto resource = std::make_unique<Resource>();

            if(!resource->load(filename)) {
                throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
            }

            _map[id] = std::move(resource);
        }

        template <typename Resource, typename Identifier>
        const Resource& holder<Resource, Identifier>::get(Identifier id) const {
            return _map[id];
        }
    }
}
