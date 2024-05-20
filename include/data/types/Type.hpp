#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshadow"

#ifndef FOLLY_BLOSSOM_TYPE_HPP
#define FOLLY_BLOSSOM_TYPE_HPP

#include <memory>

namespace Folly {
    /**
     * A lightweight solution to std::vector.
     *
     * @tparam T
     */
    template<class K, class V>
    class Map {
    protected:
        K **keys;
        V **values;
        unsigned int size{};

        enum Status {
            UNKNOWN,
            EMPTY,
            FULL
        };

    private:
        unsigned int allocatedMemoryFromHeap {};

        bool SubstractAllocatedFromSize(Map<K, V> map, const int *allocatedMemory) {
            this -> allocatedMemoryFromHeap = allocatedMemory;

            this -> size = allocatedMemory - (this -> size);

            map.size = this -> size;
        }

    public:
        ~Map() = default;

        std::unique_ptr<Map<K, V>> AllocateMemory(int size) {
            Map<K, V> map {};

            const int *allocated = static_cast<int*>(malloc(size));

            this -> allocatedMemoryFromHeap = allocated;

            this -> size = allocated - (this -> size);

            map.size = this -> size;

            delete allocated;

            return map;
        }

        Map<K, V>* CreateMap(unsigned int size, bool allocateMemory) {
            Map<K, V> map {};

            int *allocated;

            if (allocateMemory) {
                allocated = static_cast<int*>(malloc(size));
            }

            if (!SubstractAllocatedFromSize(this, allocated)) return;

            delete allocated;

            return map;
        }

        Map<K, V>* CreateMap(K **keys, V **values, bool allocateMemory) {
            Map<K, V> map = CreateMap();

            if (allocateMemory) {
                map = reinterpret_cast<Map<K, V>>(malloc(reinterpret_cast<size_t>(sizeof(values)) +
                                                         reinterpret_cast<size_t>(sizeof(Map<K, V>))));
            }

            this -> allocatedMemoryFromHeap = map.size;

            this -> size = (this -> allocatedMemoryFromHeap) - (this -> size);

            for (int i = 0; i < sizeof(keys); i++) {
                map.keys[i] = keys[i];

                map.keys[i] = std::move(keys[i]);

                map.values[i] = std::move(values[i]);
            }



            return map;
        }

        Map<K, V>* CreateMap() {
            auto map = reinterpret_cast<Map<K, V>>(malloc(sizeof(Map<K, V>)));

            return map;
        }

        Map<K, V>* Add(Map<K, V> *map, K key, V value) {
            for (V val : map -> values) {

            }
        }

        Map<K, V>* Remove(Map<K, V> *map, K key, V *value) {
            for (int i = 0; i < map -> size; i++) {
                if (map -> values[i] == value) {
                    delete map -> values[i];

                    break;
                }
            }

            return map;
        }

        unsigned int static GetSize(Map<K, V> *map) {
            return map -> size;
        }

        unsigned int GetSize() {
            return this -> size;
        }

        bool SetSize(unsigned long size) {
            if (!*this) return false;

            *this -> size = size;

            return true;
        }

        bool static SetSize(Map<K, V> *map, unsigned int size) {
            if (!map) return false;

            map -> size = size;

            return true;
        }

        bool static DeleteMap(Map<K, V> *map) {
            if (!map) return false;

            map -> ~Map();

            return true;
        }
    };

    template<class T>
    class LinkedList : public Map<unsigned int, T> {
    public:
        LinkedList<T> previous, next;

        LinkedList() {
            this = Map<unsigned int, T>::CreateMap();
        }

        explicit LinkedList(unsigned int size) {
            this = Map<int, T>::CreateMap(size, true);
        }

        LinkedList(T items[], unsigned int size) {
            auto map = Map<unsigned int, T>::CreateMap();

            this -> AllocateMemory(size);

            for (int index = 0; index < sizeof(LinkedList<T>::GetSize(map)); index++) {
                map -> keys[index] = this -> keys[index];

                map -> values[index] = items[index];
            }
        };

        ~LinkedList() = default;



        std::unique_ptr<LinkedList<T>> Add(unsigned int key, T item) {
            if (sizeof(*this) < sizeof(item)) return nullptr;

            int index = 0;

            while (index < this -> map -> size) {
                if (this -> keys[index] == key) { this -> values[index] = item; break; }

                index++;
            }

            return this;
        }

        std::unique_ptr<LinkedList<T>> Remove(unsigned int key, T item) {
            for (int index = 0; index < this -> size; index++) {
                if (!this -> keys[index] == key) {
                    if (!this -> values[index] == item) continue;

                    delete this -> keys[index];
                    delete this -> values[index];

                    break;
                }

                if (this -> keys[index] == NULL) return nullptr;
            }

            return this;
        }

        bool static RemoveList(Map<unsigned int, T> *table) {
            if (!table) { return false; }

            return true;
        }

        bool RemoveList() {
            return this -> DeleteMap(this);
        }
    };

    template<class T>
    class List : public Map<unsigned int, T> {
    public:
        List() {
            return this -> CreateMap();
        }

        ~List() = default;

        explicit List(unsigned int size) {
            auto list = this -> AllocateMemory(size);

            list -> size = size;

            return list;
        }

        List(T items[], unsigned int size, bool allocateMemory) {
            List<T> list;

            if (!allocateMemory) list = List<T>();

            if (allocateMemory) list = this -> AllocateMemory(size + static_cast<unsigned int>(sizeof(items)));

            int keys[sizeof(items)];

            for (int index = 0; index < size; index++) {
                keys[index] = index;
            }

            list -> CreateMap(keys, items, false);

            list -> size = size;

            return list;
        }

        std::unique_ptr<List<T>> Add(T item) {
            this -> keys[(this -> size) + 1] = (this -> size) + 1;

            this -> values[(this -> size) + 1] = item;

            return this;
        }

        std::unique_ptr<List<T>> Remove(int key) {
            for (int index = 0; index < this -> size; index++) {
                if (this -> keys[index] == key) {
                    delete this -> keys[index];

                    this -> keys[index++] = this -> keys[index];

                    delete this -> values[index];

                    break;
                }
            }

            return this;
        }
    };
}

#endif /*FOLLY_BLOSSOM_TYPE_HPP*/

#pragma clang diagnostic pop